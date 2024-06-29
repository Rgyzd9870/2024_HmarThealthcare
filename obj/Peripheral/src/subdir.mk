################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Peripheral/src/ch32v30x_adc.c \
../Peripheral/src/ch32v30x_bkp.c \
../Peripheral/src/ch32v30x_can.c \
../Peripheral/src/ch32v30x_crc.c \
../Peripheral/src/ch32v30x_dac.c \
../Peripheral/src/ch32v30x_dbgmcu.c \
../Peripheral/src/ch32v30x_dma.c \
../Peripheral/src/ch32v30x_dvp.c \
../Peripheral/src/ch32v30x_eth.c \
../Peripheral/src/ch32v30x_exti.c \
../Peripheral/src/ch32v30x_flash.c \
../Peripheral/src/ch32v30x_fsmc.c \
../Peripheral/src/ch32v30x_gpio.c \
../Peripheral/src/ch32v30x_i2c.c \
../Peripheral/src/ch32v30x_iwdg.c \
../Peripheral/src/ch32v30x_misc.c \
../Peripheral/src/ch32v30x_opa.c \
../Peripheral/src/ch32v30x_pwr.c \
../Peripheral/src/ch32v30x_rcc.c \
../Peripheral/src/ch32v30x_rng.c \
../Peripheral/src/ch32v30x_rtc.c \
../Peripheral/src/ch32v30x_sdio.c \
../Peripheral/src/ch32v30x_spi.c \
../Peripheral/src/ch32v30x_tim.c \
../Peripheral/src/ch32v30x_usart.c \
../Peripheral/src/ch32v30x_wwdg.c 

OBJS += \
./Peripheral/src/ch32v30x_adc.o \
./Peripheral/src/ch32v30x_bkp.o \
./Peripheral/src/ch32v30x_can.o \
./Peripheral/src/ch32v30x_crc.o \
./Peripheral/src/ch32v30x_dac.o \
./Peripheral/src/ch32v30x_dbgmcu.o \
./Peripheral/src/ch32v30x_dma.o \
./Peripheral/src/ch32v30x_dvp.o \
./Peripheral/src/ch32v30x_eth.o \
./Peripheral/src/ch32v30x_exti.o \
./Peripheral/src/ch32v30x_flash.o \
./Peripheral/src/ch32v30x_fsmc.o \
./Peripheral/src/ch32v30x_gpio.o \
./Peripheral/src/ch32v30x_i2c.o \
./Peripheral/src/ch32v30x_iwdg.o \
./Peripheral/src/ch32v30x_misc.o \
./Peripheral/src/ch32v30x_opa.o \
./Peripheral/src/ch32v30x_pwr.o \
./Peripheral/src/ch32v30x_rcc.o \
./Peripheral/src/ch32v30x_rng.o \
./Peripheral/src/ch32v30x_rtc.o \
./Peripheral/src/ch32v30x_sdio.o \
./Peripheral/src/ch32v30x_spi.o \
./Peripheral/src/ch32v30x_tim.o \
./Peripheral/src/ch32v30x_usart.o \
./Peripheral/src/ch32v30x_wwdg.o 

C_DEPS += \
./Peripheral/src/ch32v30x_adc.d \
./Peripheral/src/ch32v30x_bkp.d \
./Peripheral/src/ch32v30x_can.d \
./Peripheral/src/ch32v30x_crc.d \
./Peripheral/src/ch32v30x_dac.d \
./Peripheral/src/ch32v30x_dbgmcu.d \
./Peripheral/src/ch32v30x_dma.d \
./Peripheral/src/ch32v30x_dvp.d \
./Peripheral/src/ch32v30x_eth.d \
./Peripheral/src/ch32v30x_exti.d \
./Peripheral/src/ch32v30x_flash.d \
./Peripheral/src/ch32v30x_fsmc.d \
./Peripheral/src/ch32v30x_gpio.d \
./Peripheral/src/ch32v30x_i2c.d \
./Peripheral/src/ch32v30x_iwdg.d \
./Peripheral/src/ch32v30x_misc.d \
./Peripheral/src/ch32v30x_opa.d \
./Peripheral/src/ch32v30x_pwr.d \
./Peripheral/src/ch32v30x_rcc.d \
./Peripheral/src/ch32v30x_rng.d \
./Peripheral/src/ch32v30x_rtc.d \
./Peripheral/src/ch32v30x_sdio.d \
./Peripheral/src/ch32v30x_spi.d \
./Peripheral/src/ch32v30x_tim.d \
./Peripheral/src/ch32v30x_usart.d \
./Peripheral/src/ch32v30x_wwdg.d 


# Each subdirectory must supply rules for building sources it contributes
Peripheral/src/%.o: ../Peripheral/src/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Debug" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Core" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\User" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Peripheral\inc" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\FreeRTOS" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\FreeRTOS\include" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\FreeRTOS\portable\Common" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\FreeRTOS\portable\MemMang" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\CH9141" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\CJSON" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\Droplet" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\esp8266" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\JFC103" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\KEY" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\LCD" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\my_usart8" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\LVGL\examples\porting" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\LVGL\src" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\ui" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\ui\components" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\ui\screens" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\ap3216C" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\PWM" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\User\I2C" -I"C:\Users\rgyzd9870\Desktop\onenetͼƬ\������\����ch32��ҽ��ϵͳ\2024_SmartHealthcare\Hardware\DHT11" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

