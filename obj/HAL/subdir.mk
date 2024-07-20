################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/KEY.c \
../HAL/LED.c \
../HAL/MCU.c \
../HAL/RTC.c \
../HAL/SLEEP.c 

OBJS += \
./HAL/KEY.o \
./HAL/LED.o \
./HAL/MCU.o \
./HAL/RTC.o \
./HAL/SLEEP.o 

C_DEPS += \
./HAL/KEY.d \
./HAL/LED.d \
./HAL/MCU.d \
./HAL/RTC.d \
./HAL/SLEEP.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -DCH32V20x_D8W -DCLK_OSC32K=0 -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\APP\include" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\HAL\include" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\LIB" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Profile\include" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\SRC\Core" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\SRC\Debug" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\SRC\Peripheral\inc" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\SRC\Startup" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Hardware" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Hardware\algorithm" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Hardware\IIC" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Hardware\MAX30102" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Hardware\MPU6050" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Hardware\MPU6050\DMP" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Hardware\MPU6050\Fall Detection" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Hardware\OLED" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Hardware\GBK_LibDrive" -I"C:\Users\rgyzd9870\Desktop\�����ļ�\�����ļ���ȫ�����ã�\����ҽ��ϵͳ�ӻ�����\Hardware\LCD" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

