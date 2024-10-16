################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_flash_hp/r_flash_hp.c 

C_DEPS += \
./ra/fsp/src/r_flash_hp/r_flash_hp.d 

OBJS += \
./ra/fsp/src/r_flash_hp/r_flash_hp.o 

SREC += \
RTC_LittleFs.srec 

MAP += \
RTC_LittleFs.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_flash_hp/%.o: ../ra/fsp/src/r_flash_hp/%.c
	$(file > $@.in,-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM4 -I"/opt/work/workspaces/defaut/RTC_LittleFs/src" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra/fsp/inc" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra/fsp/inc/api" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra/fsp/inc/instances" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra_gen" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra_cfg/fsp_cfg/bsp" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra_cfg/fsp_cfg" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra_cfg/arm/littlefs" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra/arm/littlefs" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

