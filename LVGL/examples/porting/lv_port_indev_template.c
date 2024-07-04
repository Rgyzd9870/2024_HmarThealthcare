
#if 1


#include "lv_port_indev_template.h"
#include "../../lvgl.h"
#include "ch32v30x_gpio.h"
#include "ui.h"

static void keypad_init(void);
static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);
static uint32_t keypad_get_key(void);


lv_group_t * group1 = NULL;
lv_group_t * group2 = NULL;
lv_group_t * group3 = NULL;
lv_indev_t * indev_keypad = NULL;

lv_indev_t * indev_keypad;



void lv_port_indev_init(void)
{

    static lv_indev_drv_t indev_drv;

    keypad_init();

    /*Register a keypad input device*/
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_KEYPAD;
    indev_drv.read_cb = keypad_read;
    indev_keypad = lv_indev_drv_register(&indev_drv);



    group1 = lv_group_create();
    group2 = lv_group_create();
    group3 = lv_group_create();
    // 设置输入设备的默认组为group1
    lv_indev_set_group(indev_keypad, group1);

}

// 切换焦点组的函数
void switch_focus_group(lv_group_t * group) {
    lv_indev_set_group(indev_keypad, group);
}
static void keypad_init(void)
{
    GPIO_InitTypeDef i;
    i.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    i.GPIO_Speed=GPIO_Speed_50MHz;
    i.GPIO_Pin=GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5;
    GPIO_Init(GPIOE,&i);
    i.GPIO_Pin=GPIO_Pin_13|GPIO_Pin_6;
    GPIO_Init(GPIOD,&i);
}

static void keypad_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
    static uint32_t last_key = 0;

    /*Get whether the a key is pressed and save the pressed key*/
    uint32_t act_key = keypad_get_key();
    if(act_key != 0) {
        data->state = LV_INDEV_STATE_PR;

        /*Translate the keys to LVGL control characters according to your key definitions*/
        switch(act_key) {
            case 1:
                act_key = LV_KEY_NEXT;
                Delay_Ms(20);
                break;
            case 2:
                act_key = LV_KEY_PREV;
                break;
            case 3:
                act_key = LV_KEY_LEFT;
                break;
            case 4:
                act_key = LV_KEY_RIGHT;
                break;
            case 5:
                act_key = LV_KEY_ENTER;
                break;
            case 6:
                act_key = LV_KEY_UP;
                break;
            case 7:
                act_key = LV_KEY_DOWN;
                break;
        }

        last_key = act_key;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }

    data->key = last_key;
}

/*Get the currently being pressed key.  0 if no key is pressed*/
static uint32_t keypad_get_key(void)
{
    /*Your code comes here*/
    if (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_1)==0){Delay_Ms(100);return 2;}
    else if (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_5)==0)return 7;
    else if (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4)==0)return 6;
    else if (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_2)==0){ Delay_Ms(60);return 1;}
    else if (GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_3)==0)return 4;
    else if (GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_6)==0)return 3;
    else if (GPIO_ReadInputDataBit(GPIOD,GPIO_Pin_13)==0)return 5;
    return 0;
}


#else /*Enable this file at the top*/

/*This dummy typedef exists purely to silence -Wpedantic.*/
typedef int keep_pedantic_happy;
#endif
