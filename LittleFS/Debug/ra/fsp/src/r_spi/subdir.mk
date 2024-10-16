################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_spi/r_spi.c 

C_DEPS += \
./ra/fsp/src/r_spi/r_spi.d 

OBJS += \
./ra/fsp/src/r_spi/r_spi.o 

SREC += \
LittleFS.srec 

MAP += \
LittleFS.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_spi/%.o: ../ra/fsp/src/r_spi/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM23 -I"/opt/work/workspaces/defaut/LittleFS/src" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc/api" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc/instances" -I"/opt/work/workspaces/defaut/LittleFS/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/opt/work/workspaces/defaut/LittleFS/ra_gen" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/fsp_cfg/bsp" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/fsp_cfg" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/arm/littlefs" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

