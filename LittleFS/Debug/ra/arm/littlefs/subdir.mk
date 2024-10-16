################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/arm/littlefs/lfs.c \
../ra/arm/littlefs/lfs_util.c 

C_DEPS += \
./ra/arm/littlefs/lfs.d \
./ra/arm/littlefs/lfs_util.d 

OBJS += \
./ra/arm/littlefs/lfs.o \
./ra/arm/littlefs/lfs_util.o 

SREC += \
RTC_LittleFs.srec 

MAP += \
RTC_LittleFs.map 


# Each subdirectory must supply rules for building sources it contributes
ra/arm/littlefs/%.o: ../ra/arm/littlefs/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM23 -I"/opt/work/workspaces/defaut/RTC_LittleFs/src" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra/fsp/inc" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra/fsp/inc/api" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra/fsp/inc/instances" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra_gen" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra_cfg/fsp_cfg/bsp" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra_cfg/fsp_cfg" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra_cfg/arm/littlefs" -I"/opt/work/workspaces/defaut/RTC_LittleFs/ra/arm/littlefs" -std=c99 -Wno-stringop-overflow -Wno-format-truncation -w -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

