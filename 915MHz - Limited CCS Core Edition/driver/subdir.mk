################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LIB_SRCS += \
../driver/ez430_chronos_drivers.lib 

C_SRCS += \
../driver/buzzer.c \
../driver/display.c \
../driver/ports.c \
../driver/timer.c 

OBJS += \
./driver/buzzer.obj \
./driver/display.obj \
./driver/ports.obj \
./driver/timer.obj 

C_DEPS += \
./driver/buzzer.pp \
./driver/display.pp \
./driver/ports.pp \
./driver/timer.pp 

OBJS__QTD += \
".\driver\buzzer.obj" \
".\driver\display.obj" \
".\driver\ports.obj" \
".\driver\timer.obj" 

C_DEPS__QTD += \
".\driver\buzzer.pp" \
".\driver\display.pp" \
".\driver\ports.pp" \
".\driver\timer.pp" 

C_SRCS_QUOTED += \
"../driver/buzzer.c" \
"../driver/display.c" \
"../driver/ports.c" \
"../driver/timer.c" 


# Each subdirectory must supply rules for building sources it contributes
driver/buzzer.obj: ../driver/buzzer.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_US --include_path="D:/CodeComposer/ccsv4/msp430/include" --include_path="D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/driver" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/logic" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/bluerobin" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti" --diag_warning=225 --call_assumptions=0 --gen_opt_info=2 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/buzzer.pp" --obj_directory="driver" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

driver/display.obj: ../driver/display.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_US --include_path="D:/CodeComposer/ccsv4/msp430/include" --include_path="D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/driver" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/logic" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/bluerobin" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti" --diag_warning=225 --call_assumptions=0 --gen_opt_info=2 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/display.pp" --obj_directory="driver" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

driver/ports.obj: ../driver/ports.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_US --include_path="D:/CodeComposer/ccsv4/msp430/include" --include_path="D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/driver" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/logic" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/bluerobin" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti" --diag_warning=225 --call_assumptions=0 --gen_opt_info=2 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/ports.pp" --obj_directory="driver" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '

driver/timer.obj: ../driver/timer.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_US --include_path="D:/CodeComposer/ccsv4/msp430/include" --include_path="D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/driver" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/logic" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/bluerobin" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti" --diag_warning=225 --call_assumptions=0 --gen_opt_info=2 --printf_support=minimal --preproc_with_compile --preproc_dependency="driver/timer.pp" --obj_directory="driver" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


