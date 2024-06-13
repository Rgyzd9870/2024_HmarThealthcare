################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/sdl/lv_draw_sdl.c \
../LVGL/src/draw/sdl/lv_draw_sdl_arc.c \
../LVGL/src/draw/sdl/lv_draw_sdl_bg.c \
../LVGL/src/draw/sdl/lv_draw_sdl_composite.c \
../LVGL/src/draw/sdl/lv_draw_sdl_img.c \
../LVGL/src/draw/sdl/lv_draw_sdl_label.c \
../LVGL/src/draw/sdl/lv_draw_sdl_layer.c \
../LVGL/src/draw/sdl/lv_draw_sdl_line.c \
../LVGL/src/draw/sdl/lv_draw_sdl_mask.c \
../LVGL/src/draw/sdl/lv_draw_sdl_polygon.c \
../LVGL/src/draw/sdl/lv_draw_sdl_rect.c \
../LVGL/src/draw/sdl/lv_draw_sdl_stack_blur.c \
../LVGL/src/draw/sdl/lv_draw_sdl_texture_cache.c \
../LVGL/src/draw/sdl/lv_draw_sdl_utils.c 

OBJS += \
./LVGL/src/draw/sdl/lv_draw_sdl.o \
./LVGL/src/draw/sdl/lv_draw_sdl_arc.o \
./LVGL/src/draw/sdl/lv_draw_sdl_bg.o \
./LVGL/src/draw/sdl/lv_draw_sdl_composite.o \
./LVGL/src/draw/sdl/lv_draw_sdl_img.o \
./LVGL/src/draw/sdl/lv_draw_sdl_label.o \
./LVGL/src/draw/sdl/lv_draw_sdl_layer.o \
./LVGL/src/draw/sdl/lv_draw_sdl_line.o \
./LVGL/src/draw/sdl/lv_draw_sdl_mask.o \
./LVGL/src/draw/sdl/lv_draw_sdl_polygon.o \
./LVGL/src/draw/sdl/lv_draw_sdl_rect.o \
./LVGL/src/draw/sdl/lv_draw_sdl_stack_blur.o \
./LVGL/src/draw/sdl/lv_draw_sdl_texture_cache.o \
./LVGL/src/draw/sdl/lv_draw_sdl_utils.o 

C_DEPS += \
./LVGL/src/draw/sdl/lv_draw_sdl.d \
./LVGL/src/draw/sdl/lv_draw_sdl_arc.d \
./LVGL/src/draw/sdl/lv_draw_sdl_bg.d \
./LVGL/src/draw/sdl/lv_draw_sdl_composite.d \
./LVGL/src/draw/sdl/lv_draw_sdl_img.d \
./LVGL/src/draw/sdl/lv_draw_sdl_label.d \
./LVGL/src/draw/sdl/lv_draw_sdl_layer.d \
./LVGL/src/draw/sdl/lv_draw_sdl_line.d \
./LVGL/src/draw/sdl/lv_draw_sdl_mask.d \
./LVGL/src/draw/sdl/lv_draw_sdl_polygon.d \
./LVGL/src/draw/sdl/lv_draw_sdl_rect.d \
./LVGL/src/draw/sdl/lv_draw_sdl_stack_blur.d \
./LVGL/src/draw/sdl/lv_draw_sdl_texture_cache.d \
./LVGL/src/draw/sdl/lv_draw_sdl_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/sdl/%.o: ../LVGL/src/draw/sdl/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Debug" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Core" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\User" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Peripheral\inc" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\include" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\Common" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\MemMang" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\CH9141" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\CJSON" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\Droplet" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\esp8266" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\JFC103" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\KEY" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\LCD" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\my_usart8" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\LVGL\LVGL" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\LVGL\LVGL\examples" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\LVGL\examples\porting" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\LVGL\src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

