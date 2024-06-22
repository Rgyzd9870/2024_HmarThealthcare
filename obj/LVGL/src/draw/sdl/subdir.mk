################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
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
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Debug" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Core" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\User" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Peripheral\inc" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\include" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\Common" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\MemMang" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\CH9141" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\CJSON" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\Droplet" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\esp8266" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\JFC103" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\KEY" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\LCD" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\my_usart8" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\LVGL\examples\porting" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\LVGL\src" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\components" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\screens" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\ap3216C" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\PWM" -I"C:\Users\rgyzd9870\Desktop\立心率\基于ch32的医疗系统\2024_SmartHealthcare\User\I2C" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

