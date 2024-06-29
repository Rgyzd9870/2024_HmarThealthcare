################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
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
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Debug" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Core" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\User" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Peripheral\inc" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\include" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\Common" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\MemMang" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\CH9141" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\CJSON" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\Droplet" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\esp8266" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\JFC103" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\KEY" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\LCD" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\my_usart8" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\LVGL\examples\porting" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\LVGL\src" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\components" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\screens" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\ap3216C" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\PWM" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\User\I2C" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\DHT11" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

