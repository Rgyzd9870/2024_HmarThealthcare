################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../SRC/Debug/debug.c 

OBJS += \
./SRC/Debug/debug.o 

C_DEPS += \
./SRC/Debug/debug.d 


# Each subdirectory must supply rules for building sources it contributes
SRC/Debug/%.o: ../SRC/Debug/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -DCH32V20x_D8W -DCLK_OSC32K=0 -I"C:\Users\rgyzd9870\Desktop\Central\Central\APP\include" -I"C:\Users\rgyzd9870\Desktop\Central\Central\HAL\include" -I"C:\Users\rgyzd9870\Desktop\Central\Central\LIB" -I"C:\Users\rgyzd9870\Desktop\Central\Central\Profile\include" -I"C:\Users\rgyzd9870\Desktop\Central\Central\SRC\Core" -I"C:\Users\rgyzd9870\Desktop\Central\Central\SRC\Debug" -I"C:\Users\rgyzd9870\Desktop\Central\Central\SRC\Peripheral\inc" -I"C:\Users\rgyzd9870\Desktop\Central\Central\SRC\Startup" -I"C:\Users\rgyzd9870\Desktop\Central\Central\Hardware" -I"C:\Users\rgyzd9870\Desktop\Central\Central\Hardware\algorithm" -I"C:\Users\rgyzd9870\Desktop\Central\Central\Hardware\IIC" -I"C:\Users\rgyzd9870\Desktop\Central\Central\Hardware\MAX30102" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

