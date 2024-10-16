################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hal_entry.c \
../src/lfs.c \
../src/lfs_util.c \
../src/nor.c \
../src/nor_ids.c 

C_DEPS += \
./src/hal_entry.d \
./src/lfs.d \
./src/lfs_util.d \
./src/nor.d \
./src/nor_ids.d 

OBJS += \
./src/hal_entry.o \
./src/lfs.o \
./src/lfs_util.o \
./src/nor.o \
./src/nor_ids.o 

SREC += \
LittleFS.srec 

MAP += \
LittleFS.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM23 -I"/opt/work/workspaces/defaut/LittleFS/src" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc/api" -I"/opt/work/workspaces/defaut/LittleFS/ra/fsp/inc/instances" -I"/opt/work/workspaces/defaut/LittleFS/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/opt/work/workspaces/defaut/LittleFS/ra_gen" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/fsp_cfg/bsp" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/fsp_cfg" -I"/opt/work/workspaces/defaut/LittleFS/ra_cfg/arm/littlefs" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

