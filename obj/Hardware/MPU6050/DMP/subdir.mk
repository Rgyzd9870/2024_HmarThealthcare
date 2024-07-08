################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hardware/MPU6050/DMP/inv_mpu.c \
../Hardware/MPU6050/DMP/inv_mpu_dmp_motion_driver.c 

OBJS += \
./Hardware/MPU6050/DMP/inv_mpu.o \
./Hardware/MPU6050/DMP/inv_mpu_dmp_motion_driver.o 

C_DEPS += \
./Hardware/MPU6050/DMP/inv_mpu.d \
./Hardware/MPU6050/DMP/inv_mpu_dmp_motion_driver.d 


# Each subdirectory must supply rules for building sources it contributes
Hardware/MPU6050/DMP/%.o: ../Hardware/MPU6050/DMP/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -DCH32V20x_D8W -DCLK_OSC32K=0 -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\APP\include" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\HAL\include" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\LIB" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\Profile\include" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\SRC\Core" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\SRC\Debug" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\SRC\Peripheral\inc" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\SRC\Startup" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\Hardware" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\Hardware\algorithm" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\Hardware\IIC" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\Hardware\MAX30102" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\Hardware\MPU6050" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\Hardware\MPU6050\DMP" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\Hardware\MPU6050\Fall Detection" -I"D:\oneDrie\OneDrive\桌面\智能医疗系统从机历程\Hardware\OLED" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

