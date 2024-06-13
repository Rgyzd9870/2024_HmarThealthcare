################################################################################
# MRS Version: 1.9.1
# �Զ����ɵ��ļ�����Ҫ�༭��
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/font/lv_font.c \
../LVGL/src/font/lv_font_dejavu_16_persian_hebrew.c \
../LVGL/src/font/lv_font_fmt_txt.c \
../LVGL/src/font/lv_font_loader.c \
../LVGL/src/font/lv_font_montserrat_10.c \
../LVGL/src/font/lv_font_montserrat_12.c \
../LVGL/src/font/lv_font_montserrat_12_subpx.c \
../LVGL/src/font/lv_font_montserrat_14.c \
../LVGL/src/font/lv_font_montserrat_16.c \
../LVGL/src/font/lv_font_montserrat_18.c \
../LVGL/src/font/lv_font_montserrat_20.c \
../LVGL/src/font/lv_font_montserrat_22.c \
../LVGL/src/font/lv_font_montserrat_24.c \
../LVGL/src/font/lv_font_montserrat_26.c \
../LVGL/src/font/lv_font_montserrat_28.c \
../LVGL/src/font/lv_font_montserrat_28_compressed.c \
../LVGL/src/font/lv_font_montserrat_30.c \
../LVGL/src/font/lv_font_montserrat_32.c \
../LVGL/src/font/lv_font_montserrat_34.c \
../LVGL/src/font/lv_font_montserrat_36.c \
../LVGL/src/font/lv_font_montserrat_38.c \
../LVGL/src/font/lv_font_montserrat_40.c \
../LVGL/src/font/lv_font_montserrat_42.c \
../LVGL/src/font/lv_font_montserrat_44.c \
../LVGL/src/font/lv_font_montserrat_46.c \
../LVGL/src/font/lv_font_montserrat_48.c \
../LVGL/src/font/lv_font_montserrat_8.c \
../LVGL/src/font/lv_font_simsun_16_cjk.c \
../LVGL/src/font/lv_font_unscii_16.c \
../LVGL/src/font/lv_font_unscii_8.c 

OBJS += \
./LVGL/src/font/lv_font.o \
./LVGL/src/font/lv_font_dejavu_16_persian_hebrew.o \
./LVGL/src/font/lv_font_fmt_txt.o \
./LVGL/src/font/lv_font_loader.o \
./LVGL/src/font/lv_font_montserrat_10.o \
./LVGL/src/font/lv_font_montserrat_12.o \
./LVGL/src/font/lv_font_montserrat_12_subpx.o \
./LVGL/src/font/lv_font_montserrat_14.o \
./LVGL/src/font/lv_font_montserrat_16.o \
./LVGL/src/font/lv_font_montserrat_18.o \
./LVGL/src/font/lv_font_montserrat_20.o \
./LVGL/src/font/lv_font_montserrat_22.o \
./LVGL/src/font/lv_font_montserrat_24.o \
./LVGL/src/font/lv_font_montserrat_26.o \
./LVGL/src/font/lv_font_montserrat_28.o \
./LVGL/src/font/lv_font_montserrat_28_compressed.o \
./LVGL/src/font/lv_font_montserrat_30.o \
./LVGL/src/font/lv_font_montserrat_32.o \
./LVGL/src/font/lv_font_montserrat_34.o \
./LVGL/src/font/lv_font_montserrat_36.o \
./LVGL/src/font/lv_font_montserrat_38.o \
./LVGL/src/font/lv_font_montserrat_40.o \
./LVGL/src/font/lv_font_montserrat_42.o \
./LVGL/src/font/lv_font_montserrat_44.o \
./LVGL/src/font/lv_font_montserrat_46.o \
./LVGL/src/font/lv_font_montserrat_48.o \
./LVGL/src/font/lv_font_montserrat_8.o \
./LVGL/src/font/lv_font_simsun_16_cjk.o \
./LVGL/src/font/lv_font_unscii_16.o \
./LVGL/src/font/lv_font_unscii_8.o 

C_DEPS += \
./LVGL/src/font/lv_font.d \
./LVGL/src/font/lv_font_dejavu_16_persian_hebrew.d \
./LVGL/src/font/lv_font_fmt_txt.d \
./LVGL/src/font/lv_font_loader.d \
./LVGL/src/font/lv_font_montserrat_10.d \
./LVGL/src/font/lv_font_montserrat_12.d \
./LVGL/src/font/lv_font_montserrat_12_subpx.d \
./LVGL/src/font/lv_font_montserrat_14.d \
./LVGL/src/font/lv_font_montserrat_16.d \
./LVGL/src/font/lv_font_montserrat_18.d \
./LVGL/src/font/lv_font_montserrat_20.d \
./LVGL/src/font/lv_font_montserrat_22.d \
./LVGL/src/font/lv_font_montserrat_24.d \
./LVGL/src/font/lv_font_montserrat_26.d \
./LVGL/src/font/lv_font_montserrat_28.d \
./LVGL/src/font/lv_font_montserrat_28_compressed.d \
./LVGL/src/font/lv_font_montserrat_30.d \
./LVGL/src/font/lv_font_montserrat_32.d \
./LVGL/src/font/lv_font_montserrat_34.d \
./LVGL/src/font/lv_font_montserrat_36.d \
./LVGL/src/font/lv_font_montserrat_38.d \
./LVGL/src/font/lv_font_montserrat_40.d \
./LVGL/src/font/lv_font_montserrat_42.d \
./LVGL/src/font/lv_font_montserrat_44.d \
./LVGL/src/font/lv_font_montserrat_46.d \
./LVGL/src/font/lv_font_montserrat_48.d \
./LVGL/src/font/lv_font_montserrat_8.d \
./LVGL/src/font/lv_font_simsun_16_cjk.d \
./LVGL/src/font/lv_font_unscii_16.d \
./LVGL/src/font/lv_font_unscii_8.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/font/%.o: ../LVGL/src/font/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Debug" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Core" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\User" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Peripheral\inc" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\include" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\Common" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\FreeRTOS\portable\MemMang" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\CH9141" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\CJSON" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\Droplet" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\esp8266" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\JFC103" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\KEY" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\LCD" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\Hardware\my_usart8" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\LVGL\LVGL" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\LVGL\LVGL\examples" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\LVGL\examples\porting" -I"E:\������\�������ļ�\������Ŀ\2024Ƕ��ʽ����\demo\CH32V307\FreeRTOS\LVGL\src" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

