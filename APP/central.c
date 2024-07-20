/********************************** (C) COPYRIGHT *******************************
 * File Name          : central.c
 * Author             : WCH
 * Version            : V1.1
 * Date               : 2020/08/06
 * Description        : The master routine actively scans the surrounding devices, 
 *                      connects to the given slave device address, looks for custom 
 *                      services and characteristics, and executes read and write commands.
 *                      It needs to be used in conjunction with the slave routine, 
 *                      and the slave device address is modified to the routine target address, 
 *                      the default is (84:C2:E4:03:02:02)
 *********************************************************************************
 * Copyright (c) 2021 Nanjing Qinheng Microelectronics Co., Ltd.
 * Attention: This software (modified or not) and binary are used for 
 * microcontroller manufactured by Nanjing Qinheng Microelectronics.
 *******************************************************************************/

/*********************************************************************
 * INCLUDES
 */
#include "CONFIG.h"
#include "gattprofile.h"
#include "central.h"
#include "lcd.h"
#include "Dis_Picture.h"
#include "Text.h"
#include "GBK_LibDrive.h"
/*********************************************************************
 * MACROS
 */

// Length of bd addr as a string
#define B_ADDR_STR_LEN                      15

/*********************************************************************
 * CONSTANTS
 */
// Maximum number of scan responses
#define DEFAULT_MAX_SCAN_RES                80

// Scan duration in 0.625ms
#define DEFAULT_SCAN_DURATION               2400

// Connection min interval in 1.25ms
#define DEFAULT_MIN_CONNECTION_INTERVAL     20

// Connection max interval in 1.25ms
#define DEFAULT_MAX_CONNECTION_INTERVAL     60

// Connection supervision timeout in 10ms
#define DEFAULT_CONNECTION_TIMEOUT          100

// Discovey mode (limited, general, all)
#define DEFAULT_DISCOVERY_MODE              DEVDISC_MODE_ALL

// TRUE to use active scan
#define DEFAULT_DISCOVERY_ACTIVE_SCAN       TRUE

// TRUE to use white list during discovery
#define DEFAULT_DISCOVERY_WHITE_LIST        FALSE

// TRUE to use high scan duty cycle when creating link
#define DEFAULT_LINK_HIGH_DUTY_CYCLE        FALSE

// TRUE to use white list when creating link
#define DEFAULT_LINK_WHITE_LIST             FALSE

// Default read RSSI period in 0.625ms
#define DEFAULT_RSSI_PERIOD                 2400

// Minimum connection interval (units of 1.25ms)
#define DEFAULT_UPDATE_MIN_CONN_INTERVAL    20

// Maximum connection interval (units of 1.25ms)
#define DEFAULT_UPDATE_MAX_CONN_INTERVAL    100

// Slave latency to use parameter update
#define DEFAULT_UPDATE_SLAVE_LATENCY        0

// Supervision timeout value (units of 10ms)
#define DEFAULT_UPDATE_CONN_TIMEOUT         600

// Default passcode
#define DEFAULT_PASSCODE                    0

// Default GAP pairing mode
#define DEFAULT_PAIRING_MODE                GAPBOND_PAIRING_MODE_WAIT_FOR_REQ

// Default MITM mode (TRUE to require passcode or OOB when pairing)
#define DEFAULT_MITM_MODE                   TRUE

// Default bonding mode, TRUE to bond, max bonding 6 devices
#define DEFAULT_BONDING_MODE                TRUE

// Default GAP bonding I/O capabilities
#define DEFAULT_IO_CAPABILITIES             GAPBOND_IO_CAP_NO_INPUT_NO_OUTPUT

// Default service discovery timer delay in 0.625ms
#define DEFAULT_SVC_DISCOVERY_DELAY         1800

// Default parameter update delay in 0.625ms
#define DEFAULT_PARAM_UPDATE_DELAY          3200

// Default phy update delay in 0.625ms
#define DEFAULT_PHY_UPDATE_DELAY            2400

// Default read or write timer delay in 0.625ms
#define DEFAULT_READ_OR_WRITE_DELAY         1600

// Default write CCCD delay in 0.625ms
#define DEFAULT_WRITE_CCCD_DELAY            1600

// Establish link timeout in 0.625ms
#define ESTABLISH_LINK_TIMEOUT              3200

// Application states
enum
{
    BLE_STATE_IDLE,
    BLE_STATE_CONNECTING,
    BLE_STATE_CONNECTED,
    BLE_STATE_DISCONNECTING
};

// Discovery states
enum
{
    BLE_DISC_STATE_IDLE, // Idle
    BLE_DISC_STATE_SVC,  // Service discovery
    BLE_DISC_STATE_CHAR, // Characteristic discovery
    BLE_DISC_STATE_CCCD  // client characteristic configuration discovery
};
/*********************************************************************
 * TYPEDEFS
 */

/*********************************************************************
 * GLOBAL VARIABLES
 */

/*********************************************************************
 * EXTERNAL VARIABLES
 */
extern int32_t n_sp02;
extern int32_t n_heart_rate;
extern uint8_t MAX30102_ReadEnable;
extern int32_t mpu6050_res;
extern uint8_t flag;

/*********************************************************************
 * EXTERNAL FUNCTIONS
 */

/*********************************************************************
 * LOCAL VARIABLES
 */

// Task ID for internal task/event processing
uint8_t centralTaskId;

// Number of scan results
static uint8_t centralScanRes;

// Scan result list
static gapDevRec_t centralDevList[DEFAULT_MAX_SCAN_RES];

// Peer device address
static uint8_t PeerAddrDef[B_ADDR_LEN] = {0x01, 0x55, 0x5C, 0x26, 0x3B, 0x38};      //大端模式

// RSSI polling state
static uint8_t centralRssi = TRUE;

// Parameter update state
static uint8_t centralParamUpdate = TRUE;

// Phy update state
static uint8_t centralPhyUpdate = FALSE;

// Connection handle of current connection
static uint16_t centralConnHandle = GAP_CONNHANDLE_INIT;

// Application state
static uint8_t centralState = BLE_STATE_IDLE;

// Discovery state
static uint8_t centralDiscState = BLE_DISC_STATE_IDLE;

// Discovered service start and end handle
static uint16_t centralSvcStartHdl = 0;
static uint16_t centralSvcEndHdl = 0;

// Discovered characteristic handle
static uint16_t centralCharHdl = 0;

// Discovered Client Characteristic Configuration handle
static uint16_t centralCCCDHdl = 0;

// Value read/write toggle
static uint8_t centralDoWrite = TRUE;

// GATT read/write procedure state
static uint8_t centralProcedureInProgress = FALSE;
/*********************************************************************
 * LOCAL FUNCTIONS
 */
static void centralProcessGATTMsg(gattMsgEvent_t *pMsg);
static void centralRssiCB(uint16_t connHandle, int8_t rssi);
static void centralEventCB(gapRoleEvent_t *pEvent);
static void centralHciMTUChangeCB(uint16_t connHandle, uint16_t maxTxOctets, uint16_t maxRxOctets);
static void centralPasscodeCB(uint8_t *deviceAddr, uint16_t connectionHandle,
                              uint8_t uiInputs, uint8_t uiOutputs);
static void centralPairStateCB(uint16_t connHandle, uint8_t state, uint8_t status);
static void central_ProcessTMOSMsg(tmos_event_hdr_t *pMsg);
static void centralGATTDiscoveryEvent(gattMsgEvent_t *pMsg);
static void centralStartDiscovery(void);
static void centralAddDeviceInfo(uint8_t *pAddr, uint8_t addrType);
/*********************************************************************
 * PROFILE CALLBACKS
 */

// GAP Role Callbacks
static gapCentralRoleCB_t centralRoleCB = {
    centralRssiCB,        // RSSI callback
    centralEventCB,       // Event callback
    centralHciMTUChangeCB // MTU change callback
};

// Bond Manager Callbacks
static gapBondCBs_t centralBondCB = {
    centralPasscodeCB,
    centralPairStateCB
};

/*********************************************************************
 * PUBLIC FUNCTIONS
 */

/*********************************************************************
 * @fn      Central_Init
 *
 * @brief   Initialization function for the Central App Task.
 *          This is called during initialization and should contain
 *          any application specific initialization (ie. hardware
 *          initialization/setup, table initialization, power up
 *          notification).
 *
 * @param   task_id - the ID assigned by TMOS.  This ID should be
 *                    used to send messages and set timers.
 *
 * @return  none
 */
void Central_Init()
{
    centralTaskId = TMOS_ProcessEventRegister(Central_ProcessEvent);

    // Setup GAP
    GAP_SetParamValue(TGAP_DISC_SCAN, DEFAULT_SCAN_DURATION);                       //执行扫描的最小时间
    GAP_SetParamValue(TGAP_CONN_EST_INT_MIN, DEFAULT_MIN_CONNECTION_INTERVAL);      //最小链路层连接间隔
    GAP_SetParamValue(TGAP_CONN_EST_INT_MAX, DEFAULT_MAX_CONNECTION_INTERVAL);      //最大链路层连接间隔
    GAP_SetParamValue(TGAP_CONN_EST_SUPERV_TIMEOUT, DEFAULT_CONNECTION_TIMEOUT);    //链路层连接监督超时

    // Setup the GAP Bond Manager
    {
        uint32_t passkey = DEFAULT_PASSCODE;
        uint8_t  pairMode = DEFAULT_PAIRING_MODE;
        uint8_t  mitm = DEFAULT_MITM_MODE;
        uint8_t  ioCap = DEFAULT_IO_CAPABILITIES;
        uint8_t  bonding = DEFAULT_BONDING_MODE;

        GAPBondMgr_SetParameter(GAPBOND_CENT_DEFAULT_PASSCODE, sizeof(uint32_t), &passkey);     //主机配对密码
        GAPBondMgr_SetParameter(GAPBOND_CENT_PAIRING_MODE, sizeof(uint8_t), &pairMode);         //主机配对请求
        GAPBondMgr_SetParameter(GAPBOND_CENT_MITM_PROTECTION, sizeof(uint8_t), &mitm);          //防止中间人攻击
        GAPBondMgr_SetParameter(GAPBOND_CENT_IO_CAPABILITIES, sizeof(uint8_t), &ioCap);         //主机输入密码方式
        GAPBondMgr_SetParameter(GAPBOND_CENT_BONDING_ENABLED, sizeof(uint8_t), &bonding);       //绑定信息存储使能
    }
    // Initialize GATT Client
    GATT_InitClient();
    // Register to receive incoming ATT Indications/Notifications
    GATT_RegisterForInd(centralTaskId);
    // Setup a delayed profile startup
    tmos_set_event(centralTaskId, START_DEVICE_EVT);
}

/*********************************************************************
 * @fn      Central_ProcessEvent
 *
 * @brief   Central Application Task event processor.  This function
 *          is called to process all events for the task.  Events
 *          include timers, messages and any other user defined events.
 *
 * @param   task_id  - The TMOS assigned task ID.
 * @param   events - events to process.  This is a bit map and can
 *                   contain more than one event.
 *
 * @return  events not processed
 */
uint16_t Central_ProcessEvent(uint8_t task_id, uint16_t events)
{
    if(events & SYS_EVENT_MSG)      //消息事件
    {
        uint8_t *pMsg;

        if((pMsg = tmos_msg_receive(centralTaskId)) != NULL)
        {
            central_ProcessTMOSMsg((tmos_event_hdr_t *)pMsg);
            // Release the TMOS message
            tmos_msg_deallocate(pMsg);
        }
        // return unprocessed events
        return (events ^ SYS_EVENT_MSG);
    }

    if(events & START_DEVICE_EVT)   //开始工作
    {
        // Start the Device
        GAPRole_CentralStartDevice(centralTaskId, &centralBondCB, &centralRoleCB);
        return (events ^ START_DEVICE_EVT);
    }

    if(events & ESTABLISH_LINK_TIMEOUT_EVT)     //建立连接超时
    {
        GAPRole_TerminateLink(INVALID_CONNHANDLE);
        return (events ^ ESTABLISH_LINK_TIMEOUT_EVT);
    }

    if(events & START_SVC_DISCOVERY_EVT)        //开始设备扫描
    {
        // start service discovery
        centralStartDiscovery();
        return (events ^ START_SVC_DISCOVERY_EVT);
    }

    if(events & START_PARAM_UPDATE_EVT)         //连接参数更新
    {
        // start connect parameter update
        GAPRole_UpdateLink(centralConnHandle,
                           DEFAULT_UPDATE_MIN_CONN_INTERVAL,
                           DEFAULT_UPDATE_MAX_CONN_INTERVAL,
                           DEFAULT_UPDATE_SLAVE_LATENCY,
                           DEFAULT_UPDATE_CONN_TIMEOUT);
        return (events ^ START_PARAM_UPDATE_EVT);
    }

    if(events & START_PHY_UPDATE_EVT)           //更新PHY速率
    {
        // start phy update
        PRINT("PHY Update %x...\n", GAPRole_UpdatePHY(centralConnHandle, 0, GAP_PHY_BIT_LE_2M,
                                                      GAP_PHY_BIT_LE_2M, 0));

        return (events ^ START_PHY_UPDATE_EVT);
    }

    if(events & START_READ_OR_WRITE_EVT)        //读写事件
    {
        if(centralProcedureInProgress == FALSE)
        {
            if(centralDoWrite)
            {
                // Do a write
                attWriteReq_t req;

                req.cmd = FALSE;
                req.sig = FALSE;
                req.handle = centralCharHdl;
                req.len = 3;
                req.pValue = GATT_bm_alloc(centralConnHandle, ATT_WRITE_REQ, req.len, NULL, 0);
                if(req.pValue != NULL)
                {
                    req.pValue[0] = n_sp02;
                    req.pValue[1] = n_heart_rate;
                    req.pValue[2] = mpu6050_res;


                    if(GATT_WriteCharValue(centralConnHandle, &req, centralTaskId) == SUCCESS)   //如果成功发送给从机
                    {
                        mpu6050_res = 0;flag =0;

//                        printf("req.pValue[2]:%d  mpu6050:%d  \r\n",req.pValue[2],mpu6050_res);
                        centralProcedureInProgress = TRUE;
//                        centralDoWrite = !centralDoWrite;
//                        tmos_start_task(centralTaskId, START_READ_OR_WRITE_EVT, DEFAULT_READ_OR_WRITE_DELAY);
                    }
                    else
                    {
                        GATT_bm_free((gattMsg_t *)&req, ATT_WRITE_REQ);
                    }
                }
            }
            else
            {
                // Do a read
                attReadReq_t req;

                req.handle = centralCharHdl;
                if(GATT_ReadCharValue(centralConnHandle, &req, centralTaskId) == SUCCESS)
                {
                    centralProcedureInProgress = TRUE;
                    centralDoWrite = !centralDoWrite;
                }
            }
        }
        return (events ^ START_READ_OR_WRITE_EVT);
    }

    if(events & START_WRITE_CCCD_EVT)       //主机使能notify事件
    {
        if(centralProcedureInProgress == FALSE)
        {
            // Do a write
            attWriteReq_t req;

            req.cmd = FALSE;
            req.sig = FALSE;
            req.handle = centralCCCDHdl;
            req.len = 2;
            req.pValue = GATT_bm_alloc(centralConnHandle, ATT_WRITE_REQ, req.len, NULL, 0);
            if(req.pValue != NULL)
            {
                req.pValue[0] = 1;
                req.pValue[1] = 0;

                if(GATT_WriteCharValue(centralConnHandle, &req, centralTaskId) == SUCCESS)
                {
                    centralProcedureInProgress = TRUE;
                }
                else
                {
                    GATT_bm_free((gattMsg_t *)&req, ATT_WRITE_REQ);
                }
            }
        }
        return (events ^ START_WRITE_CCCD_EVT);
    }

    if(events & START_READ_RSSI_EVT)        //获取信号强度RSSI
    {
        GAPRole_ReadRssiCmd(centralConnHandle);
        tmos_start_task(centralTaskId, START_READ_RSSI_EVT, DEFAULT_RSSI_PERIOD);
        return (events ^ START_READ_RSSI_EVT);
    }

    // Discard unknown events
    return 0;
}

/*********************************************************************
 * @fn      central_ProcessTMOSMsg
 *
 * @brief   Process an incoming task message.
 *
 * @param   pMsg - message to process
 *
 * @return  none
 */
static void central_ProcessTMOSMsg(tmos_event_hdr_t *pMsg)
{
    switch(pMsg->event)
    {
        case GATT_MSG_EVENT:
            centralProcessGATTMsg((gattMsgEvent_t *)pMsg);
            break;
    }
}

/*********************************************************************
 * @fn      centralProcessGATTMsg
 *
 * @brief   Process GATT messages
 *
 * @return  none
 */
static void centralProcessGATTMsg(gattMsgEvent_t *pMsg)
{
    if(centralState != BLE_STATE_CONNECTED)
    {
        // In case a GATT message came after a connection has dropped,
        // ignore the message
        GATT_bm_free(&pMsg->msg, pMsg->method);
        return;
    }

    if((pMsg->method == ATT_EXCHANGE_MTU_RSP) ||
       ((pMsg->method == ATT_ERROR_RSP) &&
        (pMsg->msg.errorRsp.reqOpcode == ATT_EXCHANGE_MTU_REQ)))
    {
        if(pMsg->method == ATT_ERROR_RSP)
        {
            uint8_t status = pMsg->msg.errorRsp.errCode;

            PRINT("Exchange MTU Error: %x\n", status);
        }
        centralProcedureInProgress = FALSE;
    }

    if(pMsg->method == ATT_MTU_UPDATED_EVENT)
    {
        PRINT("MTU: %d\n", pMsg->msg.mtuEvt.MTU);
    }

    if((pMsg->method == ATT_READ_RSP) ||
       ((pMsg->method == ATT_ERROR_RSP) &&
        (pMsg->msg.errorRsp.reqOpcode == ATT_READ_REQ)))
    {
        if(pMsg->method == ATT_ERROR_RSP)
        {
            uint8_t status = pMsg->msg.errorRsp.errCode;

            PRINT("Read Error: %x\n", status);
        }
        else
        {
            // After a successful read, display the read value
            PRINT("Read rsp: %x\n", *pMsg->msg.readRsp.pValue);
        }
        centralProcedureInProgress = FALSE;
    }
    else if((pMsg->method == ATT_WRITE_RSP) ||
            ((pMsg->method == ATT_ERROR_RSP) &&
             (pMsg->msg.errorRsp.reqOpcode == ATT_WRITE_REQ)))
    {
        if(pMsg->method == ATT_ERROR_RSP)
        {
            uint8_t status = pMsg->msg.errorRsp.errCode;

            PRINT("Write Error: %x\n", status);
        }
        else
        {
            // Write success
            PRINT("Write success \n");
        }

        centralProcedureInProgress = FALSE;
    }
    else if(pMsg->method == ATT_HANDLE_VALUE_NOTI)
    {
        PRINT("Receive noti: %x\n", *pMsg->msg.handleValueNoti.pValue);     //接收到notify
    }
    else if(centralDiscState != BLE_DISC_STATE_IDLE)
    {
        centralGATTDiscoveryEvent(pMsg);        //从机发现句柄应答数据的处理函数
    }
    GATT_bm_free(&pMsg->msg, pMsg->method);
}

/*********************************************************************
 * @fn      centralRssiCB
 *
 * @brief   RSSI callback.
 *
 * @param   connHandle - connection handle
 * @param   rssi - RSSI
 *
 * @return  none
 */
static void centralRssiCB(uint16_t connHandle, int8_t rssi)
{
//    PRINT("RSSI : -%d dB \n", -rssi);
}

/*********************************************************************
 * @fn      centralHciMTUChangeCB
 *
 * @brief   MTU changed callback.
 *
 * @param   maxTxOctets - Max tx octets
 * @param   maxRxOctets - Max rx octets
 *
 * @return  none
 */
static void centralHciMTUChangeCB(uint16_t connHandle, uint16_t maxTxOctets, uint16_t maxRxOctets)
{
    PRINT(" HCI data length changed, Tx: %d, Rx: %d\n", maxTxOctets, maxRxOctets);
    centralProcedureInProgress = TRUE;
}

/*********************************************************************
 * @fn      centralEventCB
 *
 * @brief   Central event callback function.
 *
 * @param   pEvent - pointer to event structure
 *
 * @return  none
 */
static void centralEventCB(gapRoleEvent_t *pEvent)
{
    switch(pEvent->gap.opcode)
    {
        case GAP_DEVICE_INIT_DONE_EVENT:        //初始化完成
        {
            PRINT("Discovering...\n");
            //主机开始扫描
            GAPRole_CentralStartDiscovery(DEFAULT_DISCOVERY_MODE,
                                          DEFAULT_DISCOVERY_ACTIVE_SCAN,
                                          DEFAULT_DISCOVERY_WHITE_LIST);
        }
        break;

        case GAP_DEVICE_INFO_EVENT:             //扫描到新设备
        {
            // Add device to list
            centralAddDeviceInfo(pEvent->deviceInfo.addr, pEvent->deviceInfo.addrType);     //把扫描到的设备信息存到centralDevList
        }
        break;

        case GAP_DEVICE_DISCOVERY_EVENT:        //扫描完成
        {
            uint8_t i;

            // See if peer device has been discovered
            for(i = 0; i < centralScanRes; i++)
            {
                //轮询 centralDevList 是否有要连接的 mac 地址 PeerAddrDef
                if(tmos_memcmp(PeerAddrDef, centralDevList[i].addr, B_ADDR_LEN))
                    break;
            }

            // Peer device not found
            if(i == centralScanRes)
            {
                PRINT("Device not found...\n");
                centralScanRes = 0;
                GAPRole_CentralStartDiscovery(DEFAULT_DISCOVERY_MODE,
                                              DEFAULT_DISCOVERY_ACTIVE_SCAN,
                                              DEFAULT_DISCOVERY_WHITE_LIST);
                PRINT("Discovering...\n");
            }

            // Peer device found
            else
            {
                PRINT("Device found...\n");
                //发起连接请求
                GAPRole_CentralEstablishLink(DEFAULT_LINK_HIGH_DUTY_CYCLE,
                                             DEFAULT_LINK_WHITE_LIST,
                                             centralDevList[i].addrType,
                                             centralDevList[i].addr);

                // Start establish link timeout event
                tmos_start_task(centralTaskId, ESTABLISH_LINK_TIMEOUT_EVT, ESTABLISH_LINK_TIMEOUT);
                PRINT("Connecting...\n");
            }
        }
        break;

        case GAP_LINK_ESTABLISHED_EVENT:        //建立连接完成
        {
            tmos_stop_task(centralTaskId, ESTABLISH_LINK_TIMEOUT_EVT);
            if(pEvent->gap.hdr.status == SUCCESS)
            {
                centralState = BLE_STATE_CONNECTED;
                centralConnHandle = pEvent->linkCmpl.connectionHandle;
                centralProcedureInProgress = TRUE;
               
                // Update MTU
                attExchangeMTUReq_t req = {
                    .clientRxMTU = BLE_BUFF_MAX_LEN - 4,
                };

                GATT_ExchangeMTU(centralConnHandle, &req, centralTaskId);

                // Initiate service discovery
                tmos_start_task(centralTaskId, START_SVC_DISCOVERY_EVT, DEFAULT_SVC_DISCOVERY_DELAY);

                // See if initiate connect parameter update
                if(centralParamUpdate)
                {
                    tmos_start_task(centralTaskId, START_PARAM_UPDATE_EVT, DEFAULT_PARAM_UPDATE_DELAY);
                }
                // See if initiate PHY update
                if(centralPhyUpdate)
                {
                    tmos_start_task(centralTaskId, START_PHY_UPDATE_EVT, DEFAULT_PHY_UPDATE_DELAY);
                }
                // See if start RSSI polling
                if(centralRssi)
                {
                    tmos_start_task(centralTaskId, START_READ_RSSI_EVT, DEFAULT_RSSI_PERIOD);
                }

                PRINT("Connected...\n");
            }
            else
            {
                PRINT("Connect Failed...Reason:%X\n", pEvent->gap.hdr.status);
                PRINT("Discovering...\n");
                centralScanRes = 0;
                GAPRole_CentralStartDiscovery(DEFAULT_DISCOVERY_MODE,
                                              DEFAULT_DISCOVERY_ACTIVE_SCAN,
                                              DEFAULT_DISCOVERY_WHITE_LIST);
            }
        }
        break;

        case GAP_LINK_TERMINATED_EVENT:     //连接断开
        {
            centralState = BLE_STATE_IDLE;
            centralConnHandle = GAP_CONNHANDLE_INIT;
            centralDiscState = BLE_DISC_STATE_IDLE;
            centralCharHdl = 0;
            centralScanRes = 0;
            centralProcedureInProgress = FALSE;
            tmos_stop_task(centralTaskId, START_READ_RSSI_EVT);
            PRINT("Disconnected...Reason:%x\n", pEvent->linkTerminate.reason);
            PRINT("Discovering...\n");
            GAPRole_CentralStartDiscovery(DEFAULT_DISCOVERY_MODE,
                                          DEFAULT_DISCOVERY_ACTIVE_SCAN,
                                          DEFAULT_DISCOVERY_WHITE_LIST);
        }
        break;

        case GAP_LINK_PARAM_UPDATE_EVENT:       //连接参数更新
        {
            PRINT("Param Update...\n");
        }
        break;

        case GAP_PHY_UPDATE_EVENT:              //PHY速率更新
        {
            PRINT("PHY Update...\n");
        }
        break;

        case GAP_EXT_ADV_DEVICE_INFO_EVENT:     //扩展广播事件更新
        {
            // Display device addr
            PRINT("Recv ext adv \n");
            // Add device to list
            centralAddDeviceInfo(pEvent->deviceExtAdvInfo.addr, pEvent->deviceExtAdvInfo.addrType);
        }
        break;

        case GAP_DIRECT_DEVICE_INFO_EVENT:      //接收到定向广播
        {
            // Display device addr
            PRINT("Recv direct adv \n");
            // Add device to list
            centralAddDeviceInfo(pEvent->deviceDirectInfo.addr, pEvent->deviceDirectInfo.addrType);
        }
        break;

        default:
            break;
    }
}

/*********************************************************************
 * @fn      pairStateCB
 *
 * @brief   Pairing state callback.
 *
 * @return  none
 */
static void centralPairStateCB(uint16_t connHandle, uint8_t state, uint8_t status)
{
    if(state == GAPBOND_PAIRING_STATE_STARTED)
    {
        PRINT("Pairing started:%d\n", status);
    }
    else if(state == GAPBOND_PAIRING_STATE_COMPLETE)
    {
        if(status == SUCCESS)
        {
            PRINT("Pairing success\n");
        }
        else
        {
            PRINT("Pairing fail\n");
        }
    }
    else if(state == GAPBOND_PAIRING_STATE_BONDED)
    {
        if(status == SUCCESS)
        {
            PRINT("Bonding success\n");
        }
    }
    else if(state == GAPBOND_PAIRING_STATE_BOND_SAVED)
    {
        if(status == SUCCESS)
        {
            PRINT("Bond save success\n");
        }
        else
        {
            PRINT("Bond save failed: %d\n", status);
        }
    }
}

/*********************************************************************
 * @fn      centralPasscodeCB
 *
 * @brief   Passcode callback.
 *
 * @return  none
 */
static void centralPasscodeCB(uint8_t *deviceAddr, uint16_t connectionHandle,
                              uint8_t uiInputs, uint8_t uiOutputs)
{
    uint32_t passcode;

    // Create random passcode
    passcode = tmos_rand();
    passcode %= 1000000;
    // Display passcode to user
    if(uiOutputs != 0)
    {
        PRINT("Passcode:%06d\n", (int)passcode);
    }
    // Send passcode response
    GAPBondMgr_PasscodeRsp(connectionHandle, SUCCESS, passcode);
}

/*********************************************************************
 * @fn      centralStartDiscovery
 *
 * @brief   Start service discovery.
 *
 * @return  none
 */
static void centralStartDiscovery(void)
{
    centralSvcStartHdl = centralSvcEndHdl = centralCharHdl = 0;
    centralDiscState = BLE_DISC_STATE_SVC;

    uint8_t ret = 0;
    ret = GATT_DiscAllPrimaryServices(centralConnHandle, centralTaskId);
    printf("GATT_DiscAllPrimaryServices ret = %x\n", ret);
}

/*********************************************************************
 * @fn      centralGATTDiscoveryEvent
 *
 * @brief   Process GATT discovery event
 *
 * @return  none
 */
static void centralGATTDiscoveryEvent(gattMsgEvent_t *pMsg)
{
    attReadByTypeReq_t req;
    if(centralDiscState == BLE_DISC_STATE_SVC)
    {
        // Service found, store handles
        if(pMsg->method == ATT_READ_BY_GRP_TYPE_RSP &&//ATT_FIND_BY_TYPE_VALUE_RSP &&
           pMsg->msg.findByTypeValueRsp.numInfo > 0)
        {
#if 0
            for(uint16_t i = 0; i < pMsg->msg.readByGrpTypeRsp.numGrps; i++)
            {
              // uuid
              printf("uuid = %x", BUILD_UINT16(
                  pMsg->msg.readByGrpTypeRsp.pDataList[pMsg->msg.readByGrpTypeRsp.len * i +4], \
                  pMsg->msg.readByGrpTypeRsp.pDataList[pMsg->msg.readByGrpTypeRsp.len * i +5]));

              //Primary Service UUID Length
              printf("%02d bit x",pMsg->msg.readByGrpTypeRsp.len - 4);

              // printf("att len = %d\n", pMsg->msg.readByGrpTypeRsp.len);
              printf("start handle:%04x",BUILD_UINT16(
                          pMsg->msg.readByGrpTypeRsp.pDataList[pMsg->msg.readByGrpTypeRsp.len * i],\
                          pMsg->msg.readByGrpTypeRsp.pDataList[pMsg->msg.readByGrpTypeRsp.len * i +1]));
              // Attribute End Group Handle
              printf("end handle:%04x\r\n",BUILD_UINT16(
                          pMsg->msg.readByGrpTypeRsp.pDataList[pMsg->msg.readByGrpTypeRsp.len * i +2], \
                          pMsg->msg.readByGrpTypeRsp.pDataList[pMsg->msg.readByGrpTypeRsp.len * i +3]));
            }
#endif
        }

        if((pMsg->method == ATT_READ_BY_GRP_TYPE_RSP &&
            pMsg->hdr.status == bleProcedureComplete) ||
           (pMsg->method == ATT_ERROR_RSP))
        {
            // Discover characteristic
            centralDiscState = BLE_DISC_STATE_CHAR;
            uint8_t ret = GATT_DiscAllChars(centralConnHandle,0x01,0xFFFF,centralTaskId);
            PRINT("GATT_DiscAllChars:%02x\r\n",ret);
        }
    }
    else if(centralDiscState == BLE_DISC_STATE_CHAR)
    {
        // Characteristic found, store handle
        if(pMsg->method == ATT_READ_BY_TYPE_RSP &&
           pMsg->msg.readByTypeRsp.numPairs > 0)
        {
            for(unsigned char i = 0; i < pMsg->msg.readByTypeRsp.numPairs ; i++) {

                //characteristic properties
                uint8_t char_properties = pMsg->msg.readByTypeRsp.pDataList[pMsg->msg.readByTypeRsp.len * i + 2];
                uint16_t char_value_handle = BUILD_UINT16(pMsg->msg.readByTypeRsp.pDataList[pMsg->msg.readByTypeRsp.len * i+3], \
                                             pMsg->msg.readByTypeRsp.pDataList[pMsg->msg.readByTypeRsp.len * i + 4]);
                //characteristic uuid length
                uint8_t char_uuid_length = pMsg->msg.readByGrpTypeRsp.len - 5;
                //uuid
                uint8_t *char_uuid = &(pMsg->msg.readByGrpTypeRsp.pDataList[pMsg->msg.readByGrpTypeRsp.len * i + 5]);
                PRINT("______________________________\n");
                PRINT("char_uuid        :");
                for(uint8_t i = 0; i < char_uuid_length; i++ ){
                  printf("%02x ", char_uuid[i]);
                }printf("\n");
//                PRINT("char_properties  :%02x,%s\r\n",char_properties,(char_properties&(GATT_PROP_WRITE|GATT_PROP_WRITE_NO_RSP))?"wite handle":"");
                PRINT("char_value_handle:%04x\r\n",char_value_handle);
                PRINT("char_uuid        :%02d bit\r\n",char_uuid_length);

                if(char_properties&(GATT_PROP_WRITE|GATT_PROP_WRITE_NO_RSP)) {
                    centralCharHdl = char_value_handle;
                    PRINT("\r\nWrite handle:%04x\r\n",char_value_handle);
                    MAX30102_ReadEnable=1;
                }
                if(char_properties&GATT_PROP_NOTIFY) {
                    centralCCCDHdl = char_value_handle+1;                //通过GATT_DiscAllChars或者handle，noti/indi的handle值需要+1
                    PRINT("Notify handle:%04x\r\n",char_value_handle);
                    tmos_start_task(centralTaskId, START_WRITE_CCCD_EVT, 16000);
               }
                if(char_properties&GATT_PROP_INDICATE) {
                    centralCCCDHdl = char_value_handle+1;                //通过GATT_DiscAllChars或者handle，noti/indi的handle值需要+1
                    PRINT("Indicate handle:%04x\r\n",char_value_handle);
                    tmos_start_task(centralTaskId, START_WRITE_CCCD_EVT, 800);
               }
            }
        }
    }
}

/*********************************************************************
 * @fn      centralAddDeviceInfo
 *
 * @brief   Add a device to the device discovery result list
 *
 * @return  none
 */
static void centralAddDeviceInfo(uint8_t *pAddr, uint8_t addrType)
{
    uint8_t i;

    // If result count not at max
    if(centralScanRes < DEFAULT_MAX_SCAN_RES)
    {
        // Check if device is already in scan results
        for(i = 0; i < centralScanRes; i++)
        {
            if(tmos_memcmp(pAddr, centralDevList[i].addr, B_ADDR_LEN))
            {
                return;
            }
        }
        // Add addr to scan result list
        tmos_memcpy(centralDevList[centralScanRes].addr, pAddr, B_ADDR_LEN);
        centralDevList[centralScanRes].addrType = addrType;
        // Increment scan result count
        centralScanRes++;
        // Display device addr
        PRINT("Device %d - Addr %x %x %x %x %x %x \n", centralScanRes,
              centralDevList[centralScanRes - 1].addr[0],
              centralDevList[centralScanRes - 1].addr[1],
              centralDevList[centralScanRes - 1].addr[2],
              centralDevList[centralScanRes - 1].addr[3],
              centralDevList[centralScanRes - 1].addr[4],
              centralDevList[centralScanRes - 1].addr[5]);
    }
}

/************************ endfile @ central **************************/
