################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../LVGL/src/extra/others/monkey/lv_monkey.c 

OBJS += \
./LVGL/src/extra/others/monkey/lv_monkey.o 

C_DEPS += \
./LVGL/src/extra/others/monkey/lv_monkey.d 


# Each subdirectory must supply rules for building sources it contributes
LVGL/src/extra/others/monkey/%.o: ../LVGL/src/extra/others/monkey/%.c
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Debug" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Core" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\User" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Peripheral\inc" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\include" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\Common" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\GCC\RISC-V\chip_specific_extensions\RV32I_PFIC_no_extensions" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\FreeRTOS\portable\MemMang" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\CH9141" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\CJSON" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\Droplet" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\esp8266" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\JFC103" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\KEY" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\LCD" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\my_usart8" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\LVGL\examples\porting" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\LVGL\src" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\components" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\ui\screens" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\ap3216C" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\PWM" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\User\I2C" -I"C:\Users\rgyzd9870\Desktop\onenet图片\立心率\基于ch32的医疗系统\2024_SmartHealthcare\Hardware\DHT11" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@	@

