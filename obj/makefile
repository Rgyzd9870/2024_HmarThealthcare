################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include User/subdir.mk
-include Startup/subdir.mk
-include Peripheral/src/subdir.mk
-include Hardware/my_usart8/subdir.mk
-include Hardware/esp8266/subdir.mk
-include Hardware/LCD/subdir.mk
-include Hardware/KEY/subdir.mk
-include Hardware/JFC103/subdir.mk
-include Hardware/Droplet/subdir.mk
-include Hardware/CJSON/subdir.mk
-include Hardware/CH9141/subdir.mk
-include FreeRTOS/portable/MemMang/subdir.mk
-include FreeRTOS/portable/GCC/RISC-V/subdir.mk
-include FreeRTOS/subdir.mk
-include Debug/subdir.mk
-include Core/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_FLASH += \
ch32_freertosban.hex \

SECONDARY_LIST += \
ch32_freertosban.lst \

SECONDARY_SIZE += \
ch32_freertosban.siz \


# 所有目标
all: ch32_freertosban.elf secondary-outputs

# 工具调用
ch32_freertosban.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V307\FreeRTOS\Ld\Link.ld" -nostartfiles -Xlinker --gc-sections -Wl,-Map,"ch32_freertosban.map" --specs=nano.specs --specs=nosys.specs -o "ch32_freertosban.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
ch32_freertosban.hex: ch32_freertosban.elf
	@	riscv-none-embed-objcopy -O ihex "ch32_freertosban.elf"  "ch32_freertosban.hex"
	@	@
ch32_freertosban.lst: ch32_freertosban.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "ch32_freertosban.elf" > "ch32_freertosban.lst"
	@	@
ch32_freertosban.siz: ch32_freertosban.elf
	@	riscv-none-embed-size --format=berkeley "ch32_freertosban.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) ch32_freertosban.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
