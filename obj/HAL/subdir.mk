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
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -DCH32V20x_D8W -DCLK_OSC32K=0 -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\APP\include" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\HAL\include" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\LIB" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\Profile\include" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\SRC\Core" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\SRC\Debug" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\SRC\Peripheral\inc" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\SRC\Startup" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\Hardware" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\Hardware\algorithm" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\Hardware\IIC" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V208\Central\Hardware\MAX30102" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

