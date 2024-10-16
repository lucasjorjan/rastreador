################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/basic_io.c \
../src/hal_entry.c \
../src/task_battery_entry.c \
../src/task_uart_entry.c 

C_DEPS += \
./src/basic_io.d \
./src/hal_entry.d \
./src/task_battery_entry.d \
./src/task_uart_entry.d 

OBJS += \
./src/basic_io.o \
./src/hal_entry.o \
./src/task_battery_entry.o \
./src/task_uart_entry.o 

SREC += \
ADC_UART_FREERTOS.srec 

MAP += \
ADC_UART_FREERTOS.map 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM23 -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/src" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/fsp/inc" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/fsp/inc/api" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/fsp/inc/instances" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/fsp/src/rm_freertos_port" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra_gen" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra_cfg/fsp_cfg/bsp" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra_cfg/fsp_cfg" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra_cfg/aws" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

