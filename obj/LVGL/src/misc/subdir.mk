################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/misc/lv_anim.c \
../LVGL/src/misc/lv_anim_timeline.c \
../LVGL/src/misc/lv_area.c \
../LVGL/src/misc/lv_async.c \
../LVGL/src/misc/lv_bidi.c \
../LVGL/src/misc/lv_color.c \
../LVGL/src/misc/lv_fs.c \
../LVGL/src/misc/lv_gc.c \
../LVGL/src/misc/lv_ll.c \
../LVGL/src/misc/lv_log.c \
../LVGL/src/misc/lv_lru.c \
../LVGL/src/misc/lv_math.c \
../LVGL/src/misc/lv_mem.c \
../LVGL/src/misc/lv_printf.c \
../LVGL/src/misc/lv_style.c \
../LVGL/src/misc/lv_style_gen.c \
../LVGL/src/misc/lv_templ.c \
../LVGL/src/misc/lv_timer.c \
../LVGL/src/misc/lv_tlsf.c \
../LVGL/src/misc/lv_txt.c \
../LVGL/src/misc/lv_txt_ap.c \
../LVGL/src/misc/lv_utils.c 

OBJS += \
./LVGL/src/misc/lv_anim.o \
./LVGL/src/misc/lv_anim_timeline.o \
./LVGL/src/misc/lv_area.o \
./LVGL/src/misc/lv_async.o \
./LVGL/src/misc/lv_bidi.o \
./LVGL/src/misc/lv_color.o \
./LVGL/src/misc/lv_fs.o \
./LVGL/src/misc/lv_gc.o \
./LVGL/src/misc/lv_ll.o \
./LVGL/src/misc/lv_log.o \
./LVGL/src/misc/lv_lru.o \
./LVGL/src/misc/lv_math.o \
./LVGL/src/misc/lv_mem.o \
./LVGL/src/misc/lv_printf.o \
./LVGL/src/misc/lv_style.o \
./LVGL/src/misc/lv_style_gen.o \
./LVGL/src/misc/lv_templ.o \
./LVGL/src/misc/lv_timer.o \
./LVGL/src/misc/lv_tlsf.o \
./LVGL/src/misc/lv_txt.o \
./LVGL/src/misc/lv_txt_ap.o \
./LVGL/src/misc/lv_utils.o 

C_DEPS += \
./LVGL/src/misc/lv_anim.d \
./LVGL/src/misc/lv_anim_timeline.d \
./LVGL/src/misc/lv_area.d \
./LVGL/src/misc/lv_async.d \
./LVGL/src/misc/lv_bidi.d \
./LVGL/src/misc/lv_color.d \
./LVGL/src/misc/lv_fs.d \
./LVGL/src/misc/lv_gc.d \
./LVGL/src/misc/lv_ll.d \
./LVGL/src/misc/lv_log.d \
./LVGL/src/misc/lv_lru.d \
./LVGL/src/misc/lv_math.d \
./LVGL/src/misc/lv_mem.d \
./LVGL/src/misc/lv_printf.d \
./LVGL/src/misc/lv_style.d \
./LVGL/src/misc/lv_style_gen.d \
./LVGL/src/misc/lv_templ.d \
./LVGL/src/misc/lv_timer.d \
./LVGL/src/misc/lv_tlsf.d \
./LVGL/src/misc/lv_txt.d \
./LVGL/src/misc/lv_txt_ap.d \
./LVGL/src/misc/lv_utils.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/misc/%.o: ../LVGL/src/misc/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Debug" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Core" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\User" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Peripheral\inc" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\include" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\Common" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\MemMang" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\CH9141" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\CJSON" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\Droplet" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\esp8266" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\JFC103" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\KEY" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\LCD" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\my_usart8" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\LVGL\examples\porting" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\LVGL\src" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\components" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\fonts" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\screens" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\ap3216C" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\PWM" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\User\I2C" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\DHT11" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\motor" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

