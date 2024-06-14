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
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Debug" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Core" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\User" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Peripheral\inc" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\include" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\Common" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\MemMang" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\CH9141" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\CJSON" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\Droplet" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\esp8266" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\JFC103" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\KEY" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\LCD" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\my_usart8" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\LVGL\LVGL" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\LVGL\LVGL\examples" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\LVGL\examples\porting" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\LVGL\src" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\ui" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\ui\components" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\ui\fonts" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\ui\screens" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

