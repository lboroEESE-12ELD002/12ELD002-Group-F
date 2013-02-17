################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c 

CMD_SRCS += \
../lnk_cc430f6137.cmd 

OBJS += \
./main.obj 

C_DEPS += \
./main.pp 

OBJS__QTD += \
".\main.obj" 

C_DEPS__QTD += \
".\main.pp" 

C_SRCS_QUOTED += \
"../main.c" 


# Each subdirectory must supply rules for building sources it contributes
main.obj: ../main.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	"D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" --silicon_version=mspx -g -O2 --define=__CCE__ --define=ISM_US --include_path="D:/CodeComposer/ccsv4/msp430/include" --include_path="D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/driver" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/logic" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/bluerobin" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti" --diag_warning=225 --call_assumptions=0 --gen_opt_info=2 --printf_support=minimal --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS_QUOTED) $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")
	@echo 'Finished building: $<'
	@echo ' '


