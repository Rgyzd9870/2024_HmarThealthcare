################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Hardware/CH9141.c \
../Hardware/Droplet.c \
../Hardware/JFC103.c \
../Hardware/cJSON.c \
../Hardware/esp8266.c \
../Hardware/lcd_st7789.c \
../Hardware/my_usart8.c 

OBJS += \
./Hardware/CH9141.o \
./Hardware/Droplet.o \
./Hardware/JFC103.o \
./Hardware/cJSON.o \
./Hardware/esp8266.o \
./Hardware/lcd_st7789.o \
./Hardware/my_usart8.o 

C_DEPS += \
./Hardware/CH9141.d \
./Hardware/Droplet.d \
./Hardware/JFC103.d \
./Hardware/cJSON.d \
./Hardware/esp8266.d \
./Hardware/lcd_st7789.d \
./Hardware/my_usart8.d 


# Each subdirectory must supply rules for building sources it contributes
Hardware/%.o: ../Hardware/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Debug" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Core" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\User" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Peripheral\inc" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\include" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\Common" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\MemMang" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

