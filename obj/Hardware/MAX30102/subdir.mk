################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hardware/MAX30102/MAX30102.c 

OBJS += \
./Hardware/MAX30102/MAX30102.o 

C_DEPS += \
./Hardware/MAX30102/MAX30102.d 


# Each subdirectory must supply rules for building sources it contributes
Hardware/MAX30102/%.o: ../Hardware/MAX30102/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -DCH32V20x_D8W -DCLK_OSC32K=0 -I"D:\ch32\CH32V208\Central\APP\include" -I"D:\ch32\CH32V208\Central\HAL\include" -I"D:\ch32\CH32V208\Central\LIB" -I"D:\ch32\CH32V208\Central\Profile\include" -I"D:\ch32\CH32V208\Central\SRC\Core" -I"D:\ch32\CH32V208\Central\SRC\Debug" -I"D:\ch32\CH32V208\Central\SRC\Peripheral\inc" -I"D:\ch32\CH32V208\Central\SRC\Startup" -I"D:\ch32\CH32V208\Central\Hardware" -I"D:\ch32\CH32V208\Central\Hardware\algorithm" -I"D:\ch32\CH32V208\Central\Hardware\IIC" -I"D:\ch32\CH32V208\Central\Hardware\MAX30102" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

