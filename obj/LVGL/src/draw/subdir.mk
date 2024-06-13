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
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Debug" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Core" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\User" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Peripheral\inc" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\include" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\Common" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\MemMang" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\CH9141" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\CJSON" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\Droplet" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\esp8266" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\JFC103" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\KEY" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\LCD" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\my_usart8" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\LVGL\LVGL" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\LVGL\LVGL\examples" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\LVGL\examples\porting" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\LVGL\src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

