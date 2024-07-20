################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hardware/LCD/Dis_Picture.c \
../Hardware/LCD/FONT.c \
../Hardware/LCD/Picture.c \
../Hardware/LCD/Text.c \
../Hardware/LCD/lcd.c 

OBJS += \
./Hardware/LCD/Dis_Picture.o \
./Hardware/LCD/FONT.o \
./Hardware/LCD/Picture.o \
./Hardware/LCD/Text.o \
./Hardware/LCD/lcd.o 

C_DEPS += \
./Hardware/LCD/Dis_Picture.d \
./Hardware/LCD/FONT.d \
./Hardware/LCD/Picture.d \
./Hardware/LCD/Text.d \
./Hardware/LCD/lcd.d 


# Each subdirectory must supply rules for building sources it contributes
Hardware/LCD/%.o: ../Hardware/LCD/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -DCH32V20x_D8W -DCLK_OSC32K=0 -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\APP\include" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\HAL\include" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\LIB" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Profile\include" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\SRC\Core" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\SRC\Debug" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\SRC\Peripheral\inc" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\SRC\Startup" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Hardware" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Hardware\algorithm" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Hardware\IIC" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Hardware\MAX30102" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Hardware\MPU6050" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Hardware\MPU6050\DMP" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Hardware\MPU6050\Fall Detection" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Hardware\OLED" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Hardware\GBK_LibDrive" -I"C:\Users\rgyzd9870\Desktop\比赛文件\比赛文件（全部能用）\智能医疗系统从机历程\Hardware\LCD" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

