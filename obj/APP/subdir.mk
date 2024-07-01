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
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -DCH32V20x_D8W -DCLK_OSC32K=0 -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\APP\include" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\HAL\include" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\LIB" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\Profile\include" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\SRC\Core" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\SRC\Debug" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\SRC\Peripheral\inc" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\SRC\Startup" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\Hardware" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\Hardware\algorithm" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\Hardware\IIC" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\Hardware\MAX30102" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\Hardware\MPU6050" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\Hardware\MPU6050\DMP" -I"C:\Users\rgyzd9870\Documents\WeChat Files\wxid_plo8ozlnxa4u22\FileStorage\File\2024-07\Central(1)\Central\Hardware\MPU6050\Fall Detection" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

