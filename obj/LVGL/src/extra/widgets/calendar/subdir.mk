################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/extra/widgets/calendar/lv_calendar.c \
../LVGL/src/extra/widgets/calendar/lv_calendar_header_arrow.c \
../LVGL/src/extra/widgets/calendar/lv_calendar_header_dropdown.c 

OBJS += \
./LVGL/src/extra/widgets/calendar/lv_calendar.o \
./LVGL/src/extra/widgets/calendar/lv_calendar_header_arrow.o \
./LVGL/src/extra/widgets/calendar/lv_calendar_header_dropdown.o 

C_DEPS += \
./LVGL/src/extra/widgets/calendar/lv_calendar.d \
./LVGL/src/extra/widgets/calendar/lv_calendar_header_arrow.d \
./LVGL/src/extra/widgets/calendar/lv_calendar_header_dropdown.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/extra/widgets/calendar/%.o: ../LVGL/src/extra/widgets/calendar/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Debug" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Core" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\User" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Peripheral\inc" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\include" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\Common" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\MemMang" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\CH9141" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\CJSON" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\Droplet" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\esp8266" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\JFC103" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\KEY" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\LCD" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\my_usart8" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\LVGL\LVGL" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\LVGL\LVGL\examples" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\LVGL\examples\porting" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\LVGL\src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

