################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_UPPER_SRCS += \
../src/RTT/SEGGER_RTT_ASM_ARMv7M.S 

C_SRCS += \
../src/RTT/SEGGER_RTT.c \
../src/RTT/SEGGER_RTT_printf.c 

C_DEPS += \
./src/RTT/SEGGER_RTT.d \
./src/RTT/SEGGER_RTT_printf.d 

OBJS += \
./src/RTT/SEGGER_RTT.o \
./src/RTT/SEGGER_RTT_ASM_ARMv7M.o \
./src/RTT/SEGGER_RTT_printf.o 

SREC += \
LittleFS.srec 

S_UPPER_DEPS += \
./src/RTT/SEGGER_RTT_ASM_ARMv7M.d 

MAP += \
LittleFS.map 


# Each subdirectory must supply rules for building sources it contributes
src/RTT/%.o: ../src/RTT/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM23 -I"/opt/work/workspaces/defaut/LittleFS/src" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc/api" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc/instances" -I"/opt/work/workspaces/defaut/LittleFS/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/opt/work/workspaces/defaut/LittleFS/ra_gen" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/fsp_cfg/bsp" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/fsp_cfg" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/arm/littlefs" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"
src/RTT/%.o: ../src/RTT/%.S
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -x assembler-with-cpp -D_RENESAS_RA_ -D_RA_CORE=CM23 -I"/opt/work/workspaces/defaut/LittleFS/src" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc/api" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc/instances" -I"/opt/work/workspaces/defaut/LittleFS/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/opt/work/workspaces/defaut/LittleFS/ra_gen" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/fsp_cfg/bsp" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/fsp_cfg" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/arm/littlefs" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

