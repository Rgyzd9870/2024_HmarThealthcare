################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/central.c \
../APP/central_main.c \
../APP/ch32v20x_it.c \
../APP/system_ch32v20x.c 

OBJS += \
./APP/central.o \
./APP/central_main.o \
./APP/ch32v20x_it.o \
./APP/system_ch32v20x.o 

C_DEPS += \
./APP/central.d \
./APP/central_main.d \
./APP/ch32v20x_it.d \
./APP/system_ch32v20x.d 


# Each subdirectory must supply rules for building sources it contributes
APP/%.o: ../APP/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -DCH32V20x_D8W -DCLK_OSC32K=0 -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\APP\include" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\HAL\include" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\LIB" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\Profile\include" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\SRC\Core" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\SRC\Debug" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\SRC\Peripheral\inc" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\SRC\Startup" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\Hardware" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\Hardware\algorithm" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\Hardware\IIC" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\Hardware\MAX30102" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\Hardware\MPU6050" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\Hardware\MPU6050\DMP" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\Hardware\MPU6050\Fall Detection" -I"D:\oneDrie\OneDrive\����\����ҽ��ϵͳ�ӻ�����\Hardware\OLED" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

