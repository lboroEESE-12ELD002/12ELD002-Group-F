################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

EMPTY := 
SPACE := $(EMPTY) $(EMPTY)

ORDERED_OBJS += \
$(GEN_CMDS_QUOTED) \
"./driver/timer.obj" \
"./driver/ports.obj" \
"./driver/display.obj" \
"./driver/buzzer.obj" \
"./logic/user.obj" \
"./logic/test.obj" \
"./logic/temperature.obj" \
"./logic/stopwatch.obj" \
"./logic/rfsimpliciti.obj" \
"./logic/rfbsl.obj" \
"./logic/menu.obj" \
"./logic/date.obj" \
"./logic/clock.obj" \
"./logic/bluerobin.obj" \
"./logic/battery.obj" \
"./logic/altitude.obj" \
"./logic/alarm.obj" \
"./logic/acceleration.obj" \
"./main.obj" \
-l"rts430x.lib" \
"../simpliciti/CC430_End_Device_915MHz.lib" \
"../lnk_cc430f6137.cmd" \
"../driver/ez430_chronos_drivers.lib" \
"../bluerobin/BlueRobin_RX_915MHz.lib" \

-include ../makefile.init

RM := DEL /F

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include simpliciti/subdir.mk
-include logic/subdir.mk
-include driver/subdir.mk
-include bluerobin/subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ez430_chronos_915MHz.out

# Tool invocations
ez430_chronos_915MHz.out: $(GEN_CMDS) $(CMD_SRCS) $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Linker'
	"D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_US --diag_warning=225 --call_assumptions=0 --gen_opt_info=2 --printf_support=minimal -z -m"ez430_chronos.map" --stack_size=80 --heap_size=80 --use_hw_mpy=F5 --warn_sections -i"D:/CodeComposer/ccsv4/msp430/include" -i"D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/lib" -i"D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --reread_libs --rom_model -o "ez430_chronos_915MHz.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(MSP430_EXECUTABLE_OUTPUTS__QTD) "ez430_chronos_915MHz.out"
	-$(RM) ".\main.obj" ".\logic\acceleration.obj" ".\logic\alarm.obj" ".\logic\altitude.obj" ".\logic\battery.obj" ".\logic\bluerobin.obj" ".\logic\clock.obj" ".\logic\date.obj" ".\logic\menu.obj" ".\logic\rfbsl.obj" ".\logic\rfsimpliciti.obj" ".\logic\stopwatch.obj" ".\logic\temperature.obj" ".\logic\test.obj" ".\logic\user.obj" ".\driver\buzzer.obj" ".\driver\display.obj" ".\driver\ports.obj" ".\driver\timer.obj" 
	-$(RM) ".\main.pp" ".\logic\acceleration.pp" ".\logic\alarm.pp" ".\logic\altitude.pp" ".\logic\battery.pp" ".\logic\bluerobin.pp" ".\logic\clock.pp" ".\logic\date.pp" ".\logic\menu.pp" ".\logic\rfbsl.pp" ".\logic\rfsimpliciti.pp" ".\logic\stopwatch.pp" ".\logic\temperature.pp" ".\logic\test.pp" ".\logic\user.pp" ".\driver\buzzer.pp" ".\driver\display.pp" ".\driver\ports.pp" ".\driver\timer.pp" 
	-@echo ' '

post-build:
	-@echo 'Create flash image: TI-TXT'
	-"D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/hex430.exe" --ti_txt "ez430_chronos_915MHz.out" -o "ez430_chronos_915MHz.txt" -order MS -romwidth 16
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
