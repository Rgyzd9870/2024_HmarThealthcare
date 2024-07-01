################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/draw/lv_draw.c \
../LVGL/src/draw/lv_draw_arc.c \
../LVGL/src/draw/lv_draw_img.c \
../LVGL/src/draw/lv_draw_label.c \
../LVGL/src/draw/lv_draw_layer.c \
../LVGL/src/draw/lv_draw_line.c \
../LVGL/src/draw/lv_draw_mask.c \
../LVGL/src/draw/lv_draw_rect.c \
../LVGL/src/draw/lv_draw_transform.c \
../LVGL/src/draw/lv_draw_triangle.c \
../LVGL/src/draw/lv_img_buf.c \
../LVGL/src/draw/lv_img_cache.c \
../LVGL/src/draw/lv_img_decoder.c 

OBJS += \
./LVGL/src/draw/lv_draw.o \
./LVGL/src/draw/lv_draw_arc.o \
./LVGL/src/draw/lv_draw_img.o \
./LVGL/src/draw/lv_draw_label.o \
./LVGL/src/draw/lv_draw_layer.o \
./LVGL/src/draw/lv_draw_line.o \
./LVGL/src/draw/lv_draw_mask.o \
./LVGL/src/draw/lv_draw_rect.o \
./LVGL/src/draw/lv_draw_transform.o \
./LVGL/src/draw/lv_draw_triangle.o \
./LVGL/src/draw/lv_img_buf.o \
./LVGL/src/draw/lv_img_cache.o \
./LVGL/src/draw/lv_img_decoder.o 

C_DEPS += \
./LVGL/src/draw/lv_draw.d \
./LVGL/src/draw/lv_draw_arc.d \
./LVGL/src/draw/lv_draw_img.d \
./LVGL/src/draw/lv_draw_label.d \
./LVGL/src/draw/lv_draw_layer.d \
./LVGL/src/draw/lv_draw_line.d \
./LVGL/src/draw/lv_draw_mask.d \
./LVGL/src/draw/lv_draw_rect.d \
./LVGL/src/draw/lv_draw_transform.d \
./LVGL/src/draw/lv_draw_triangle.d \
./LVGL/src/draw/lv_img_buf.d \
./LVGL/src/draw/lv_img_cache.d \
./LVGL/src/draw/lv_img_decoder.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/draw/%.o: ../LVGL/src/draw/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Debug" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Core" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\User" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Peripheral\inc" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\include" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\Common" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\MemMang" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\CH9141" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\CJSON" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\Droplet" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\esp8266" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\JFC103" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\KEY" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\LCD" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\my_usart8" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\LVGL\examples\porting" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\LVGL\src" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\components" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\fonts" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\screens" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\ap3216C" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\PWM" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\User\I2C" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\DHT11" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\motor" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

