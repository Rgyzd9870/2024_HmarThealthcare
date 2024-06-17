################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/widgets/lv_arc.c \
../LVGL/src/widgets/lv_bar.c \
../LVGL/src/widgets/lv_btn.c \
../LVGL/src/widgets/lv_btnmatrix.c \
../LVGL/src/widgets/lv_canvas.c \
../LVGL/src/widgets/lv_checkbox.c \
../LVGL/src/widgets/lv_dropdown.c \
../LVGL/src/widgets/lv_img.c \
../LVGL/src/widgets/lv_label.c \
../LVGL/src/widgets/lv_line.c \
../LVGL/src/widgets/lv_objx_templ.c \
../LVGL/src/widgets/lv_roller.c \
../LVGL/src/widgets/lv_slider.c \
../LVGL/src/widgets/lv_switch.c \
../LVGL/src/widgets/lv_table.c \
../LVGL/src/widgets/lv_textarea.c 

OBJS += \
./LVGL/src/widgets/lv_arc.o \
./LVGL/src/widgets/lv_bar.o \
./LVGL/src/widgets/lv_btn.o \
./LVGL/src/widgets/lv_btnmatrix.o \
./LVGL/src/widgets/lv_canvas.o \
./LVGL/src/widgets/lv_checkbox.o \
./LVGL/src/widgets/lv_dropdown.o \
./LVGL/src/widgets/lv_img.o \
./LVGL/src/widgets/lv_label.o \
./LVGL/src/widgets/lv_line.o \
./LVGL/src/widgets/lv_objx_templ.o \
./LVGL/src/widgets/lv_roller.o \
./LVGL/src/widgets/lv_slider.o \
./LVGL/src/widgets/lv_switch.o \
./LVGL/src/widgets/lv_table.o \
./LVGL/src/widgets/lv_textarea.o 

C_DEPS += \
./LVGL/src/widgets/lv_arc.d \
./LVGL/src/widgets/lv_bar.d \
./LVGL/src/widgets/lv_btn.d \
./LVGL/src/widgets/lv_btnmatrix.d \
./LVGL/src/widgets/lv_canvas.d \
./LVGL/src/widgets/lv_checkbox.d \
./LVGL/src/widgets/lv_dropdown.d \
./LVGL/src/widgets/lv_img.d \
./LVGL/src/widgets/lv_label.d \
./LVGL/src/widgets/lv_line.d \
./LVGL/src/widgets/lv_objx_templ.d \
./LVGL/src/widgets/lv_roller.d \
./LVGL/src/widgets/lv_slider.d \
./LVGL/src/widgets/lv_switch.d \
./LVGL/src/widgets/lv_table.d \
./LVGL/src/widgets/lv_textarea.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/widgets/%.o: ../LVGL/src/widgets/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Debug" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Core" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\User" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Peripheral\inc" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\FreeRTOS" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\FreeRTOS\include" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\FreeRTOS\portable\Common" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\FreeRTOS\portable\MemMang" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware\CH9141" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware\CJSON" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware\Droplet" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware\esp8266" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware\JFC103" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware\KEY" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware\LCD" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware\my_usart8" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\LVGL\examples\porting" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\LVGL\src" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\ui" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\ui\components" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\ui\screens" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware\ap3216C" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\Hardware\PWM" -I"C:\Users\rgyzd9870\Desktop\临时\2024_SmartHealthcare\User\I2C" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

