################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../simpliciti/Components/bsp/bsp.c 

OBJS += \
./simpliciti/Components/bsp/bsp.obj 

C_DEPS += \
./simpliciti/Components/bsp/bsp.pp 

OBJS__QTD += \
".\simpliciti\Components\bsp\bsp.obj" 

C_DEPS__QTD += \
".\simpliciti\Components\bsp\bsp.pp" 

C_SRCS_QUOTED += \
"../simpliciti/Components/bsp/bsp.c" 


# Each subdirectory must supply rules for building sources it contributes
simpliciti/Components/bsp/bsp.obj: ../simpliciti/Components/bsp/bsp.c $(GEN_OPTS)
	@echo 'Building file: $<'
	@echo 'Invoking: Compiler'
	$(shell echo --cmd_file="C:\Users\Luke Ellis\Documents\New Work\Electronicsyear3\workspace2\ez430_chronos\simpliciti\Applications\configuration\smpl_nwk_config.dat" --cmd_file="C:\Users\Luke Ellis\Documents\New Work\Electronicsyear3\workspace2\ez430_chronos\simpliciti\Applications\configuration\End Device\smpl_config.dat" > "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo --silicon_version=mspx >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo -g >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo -O3 >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo --define=__CCE__ --define=ISM_EU --define=__CC430F6137__ --define=MRFI_CC430 >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo --include_path="D:/CodeComposer/ccsv4/msp430/include" --include_path="D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/include" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/driver" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/logic" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/bluerobin" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Applications/application/End Device" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/bsp" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/bsp/boards" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/bsp/boards/CC430EM" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/bsp/boards/CC430EM/bsp_external" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/bsp/drivers" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/bsp/drivers/code" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/bsp/mcus" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/mrfi" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/mrfi/radios" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/mrfi/radios/family5" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/mrfi/smartrf" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/nwk" --include_path="C:/Users/Luke Ellis/Documents/New Work/Electronicsyear3/workspace2/ez430_chronos/simpliciti/Components/nwk_applications" >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo --diag_warning=225 >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo --call_assumptions=0 >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo --gen_opt_info=2 >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo --printf_support=minimal >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo --preproc_with_compile >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo --preproc_dependency="simpliciti/Components/bsp/bsp.pp" >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(shell echo --obj_directory="simpliciti/Components/bsp" >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt")
	$(if $(strip $(GEN_OPTS_QUOTED)), $(shell echo $(GEN_OPTS_QUOTED) >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt"))
	$(if $(strip $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#")), $(shell echo $(subst #,$(wildcard $(subst $(SPACE),\$(SPACE),$<)),"#") >> "simpliciti/Components/bsp/bsp_ccsCompiler.opt"))
	"D:/CodeComposer/ccsv4/tools/compiler/MSP430 Code Generation Tools 3.2.3/bin/cl430" -@"simpliciti/Components/bsp/bsp_ccsCompiler.opt"
	@echo 'Finished building: $<'
	@echo ' '


