################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/hal/lv_hal_disp.c \
../LVGL/src/hal/lv_hal_indev.c \
../LVGL/src/hal/lv_hal_tick.c 

OBJS += \
./LVGL/src/hal/lv_hal_disp.o \
./LVGL/src/hal/lv_hal_indev.o \
./LVGL/src/hal/lv_hal_tick.o 

C_DEPS += \
./LVGL/src/hal/lv_hal_disp.d \
./LVGL/src/hal/lv_hal_indev.d \
./LVGL/src/hal/lv_hal_tick.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/hal/%.o: ../LVGL/src/hal/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Debug" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Core" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\User" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Peripheral\inc" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\include" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\Common" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\FreeRTOS\portable\MemMang" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\CH9141" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\CJSON" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\Droplet" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\esp8266" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\JFC103" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\KEY" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\LCD" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Hardware\my_usart8" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\LVGL\examples\porting" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\LVGL\src" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\ui" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\ui\components" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\ui\fonts" -I"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\ui\screens" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

