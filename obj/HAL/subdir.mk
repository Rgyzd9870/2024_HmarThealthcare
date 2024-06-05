################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
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
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -DCH32V20x_D8W -DCLK_OSC32K=0 -I"D:\ch32\CH32V208\CH32V208WBU6\APP\include" -I"D:\ch32\CH32V208\CH32V208WBU6\HAL\include" -I"D:\ch32\CH32V208\CH32V208WBU6\LIB" -I"D:\ch32\CH32V208\CH32V208WBU6\Profile\include" -I"D:\ch32\CH32V208\CH32V208WBU6\SRC\Core" -I"D:\ch32\CH32V208\CH32V208WBU6\SRC\Debug" -I"D:\ch32\CH32V208\CH32V208WBU6\SRC\Peripheral\inc" -I"D:\ch32\CH32V208\CH32V208WBU6\SRC\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

