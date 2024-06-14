################################################################################
# MRS Version: 1.9.1
# 自动生成的文件。不要编辑！
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include SRC/Startup/subdir.mk
-include SRC/Peripheral/src/subdir.mk
-include SRC/Debug/subdir.mk
-include SRC/Core/subdir.mk
-include LIB/subdir.mk
-include Hardware/algorithm/subdir.mk
-include Hardware/MAX30102/subdir.mk
-include Hardware/IIC/subdir.mk
-include Hardware/subdir.mk
-include HAL/subdir.mk
-include APP/subdir.mk
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
CH32V208WBU6.hex \

SECONDARY_LIST += \
CH32V208WBU6.lst \

SECONDARY_SIZE += \
CH32V208WBU6.siz \


# 所有目标
all: CH32V208WBU6.elf secondary-outputs

# 工具调用
CH32V208WBU6.elf: $(OBJS) $(USER_OBJS)
	@	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized  -g -T "E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V208\Central\HAL\Link.ld" -nostartfiles -Xlinker --gc-sections -L"E:\新桌面\做过的文件\比赛项目\2024嵌入式大赛\demo\CH32V208\Central\LIB" -Xlinker --print-memory-usage -Wl,-Map,"CH32V208WBU6.map" --specs=nano.specs --specs=nosys.specs -o "CH32V208WBU6.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@	@
CH32V208WBU6.hex: CH32V208WBU6.elf
	@	riscv-none-embed-objcopy -O ihex "CH32V208WBU6.elf"  "CH32V208WBU6.hex"
	@	@
CH32V208WBU6.lst: CH32V208WBU6.elf
	@	riscv-none-embed-objdump --all-headers --demangle --disassemble -M xw "CH32V208WBU6.elf" > "CH32V208WBU6.lst"
	@	@
CH32V208WBU6.siz: CH32V208WBU6.elf
	@	riscv-none-embed-size --format=berkeley "CH32V208WBU6.elf"
	@	@
# 其他目标
clean:
	-$(RM) $(ASM_UPPER_DEPS)$(OBJS)$(SECONDARY_FLASH)$(SECONDARY_LIST)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_DEPS)$(S_UPPER_DEPS)$(C_DEPS) CH32V208WBU6.elf
	-@
secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_LIST) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
