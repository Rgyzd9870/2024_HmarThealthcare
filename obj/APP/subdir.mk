################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
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
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -DCH32V20x_D8W -DCLK_OSC32K=0 -I"D:\ch32\CH32V208\CH32V208WBU6\APP\include" -I"D:\ch32\CH32V208\CH32V208WBU6\HAL\include" -I"D:\ch32\CH32V208\CH32V208WBU6\LIB" -I"D:\ch32\CH32V208\CH32V208WBU6\Profile\include" -I"D:\ch32\CH32V208\CH32V208WBU6\SRC\Core" -I"D:\ch32\CH32V208\CH32V208WBU6\SRC\Debug" -I"D:\ch32\CH32V208\CH32V208WBU6\SRC\Peripheral\inc" -I"D:\ch32\CH32V208\CH32V208WBU6\SRC\Startup" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

