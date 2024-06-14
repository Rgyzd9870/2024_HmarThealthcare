################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/sw/lv_draw_sw.c \
../LVGL/src/draw/sw/lv_draw_sw_arc.c \
../LVGL/src/draw/sw/lv_draw_sw_blend.c \
../LVGL/src/draw/sw/lv_draw_sw_dither.c \
../LVGL/src/draw/sw/lv_draw_sw_gradient.c \
../LVGL/src/draw/sw/lv_draw_sw_img.c \
../LVGL/src/draw/sw/lv_draw_sw_layer.c \
../LVGL/src/draw/sw/lv_draw_sw_letter.c \
../LVGL/src/draw/sw/lv_draw_sw_line.c \
../LVGL/src/draw/sw/lv_draw_sw_polygon.c \
../LVGL/src/draw/sw/lv_draw_sw_rect.c \
../LVGL/src/draw/sw/lv_draw_sw_transform.c 

OBJS += \
./LVGL/src/draw/sw/lv_draw_sw.o \
./LVGL/src/draw/sw/lv_draw_sw_arc.o \
./LVGL/src/draw/sw/lv_draw_sw_blend.o \
./LVGL/src/draw/sw/lv_draw_sw_dither.o \
./LVGL/src/draw/sw/lv_draw_sw_gradient.o \
./LVGL/src/draw/sw/lv_draw_sw_img.o \
./LVGL/src/draw/sw/lv_draw_sw_layer.o \
./LVGL/src/draw/sw/lv_draw_sw_letter.o \
./LVGL/src/draw/sw/lv_draw_sw_line.o \
./LVGL/src/draw/sw/lv_draw_sw_polygon.o \
./LVGL/src/draw/sw/lv_draw_sw_rect.o \
./LVGL/src/draw/sw/lv_draw_sw_transform.o 

C_DEPS += \
./LVGL/src/draw/sw/lv_draw_sw.d \
./LVGL/src/draw/sw/lv_draw_sw_arc.d \
./LVGL/src/draw/sw/lv_draw_sw_blend.d \
./LVGL/src/draw/sw/lv_draw_sw_dither.d \
./LVGL/src/draw/sw/lv_draw_sw_gradient.d \
./LVGL/src/draw/sw/lv_draw_sw_img.d \
./LVGL/src/draw/sw/lv_draw_sw_layer.d \
./LVGL/src/draw/sw/lv_draw_sw_letter.d \
./LVGL/src/draw/sw/lv_draw_sw_line.d \
./LVGL/src/draw/sw/lv_draw_sw_polygon.d \
./LVGL/src/draw/sw/lv_draw_sw_rect.d \
./LVGL/src/draw/sw/lv_draw_sw_transform.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/sw/%.o: ../LVGL/src/draw/sw/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Debug" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Core" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\User" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Peripheral\inc" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\include" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\Common" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\MemMang" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\CH9141" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\CJSON" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\Droplet" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\esp8266" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\JFC103" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\KEY" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\LCD" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\my_usart8" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\LVGL\LVGL" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\LVGL\LVGL\examples" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\LVGL\examples\porting" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\LVGL\src" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\ui" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\ui\components" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\ui\fonts" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\ui\screens" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

