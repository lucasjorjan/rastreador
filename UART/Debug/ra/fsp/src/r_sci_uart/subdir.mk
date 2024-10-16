################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra/fsp/src/r_sci_uart/r_sci_uart.c 

C_DEPS += \
./ra/fsp/src/r_sci_uart/r_sci_uart.d 

OBJS += \
./ra/fsp/src/r_sci_uart/r_sci_uart.o 

SREC += \
UART.srec 

MAP += \
UART.map 


# Each subdirectory must supply rules for building sources it contributes
ra/fsp/src/r_sci_uart/%.o: ../ra/fsp/src/r_sci_uart/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM23 -I"/opt/work/e2_studio/workspace/UART/src" -I"/opt/work/e2_studio/workspace/UART/ra/fsp/inc" -I"/opt/work/e2_studio/workspace/UART/ra/fsp/inc/api" -I"/opt/work/e2_studio/workspace/UART/ra/fsp/inc/instances" -I"/opt/work/e2_studio/workspace/UART/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/opt/work/e2_studio/workspace/UART/ra_gen" -I"/opt/work/e2_studio/workspace/UART/ra_cfg/fsp_cfg/bsp" -I"/opt/work/e2_studio/workspace/UART/ra_cfg/fsp_cfg" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

