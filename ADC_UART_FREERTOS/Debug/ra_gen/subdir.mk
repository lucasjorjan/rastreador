################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ra_gen/common_data.c \
../ra_gen/hal_data.c \
../ra_gen/main.c \
../ra_gen/pin_data.c \
../ra_gen/task_battery.c \
../ra_gen/task_uart.c \
../ra_gen/vector_data.c 

C_DEPS += \
./ra_gen/common_data.d \
./ra_gen/hal_data.d \
./ra_gen/main.d \
./ra_gen/pin_data.d \
./ra_gen/task_battery.d \
./ra_gen/task_uart.d \
./ra_gen/vector_data.d 

OBJS += \
./ra_gen/common_data.o \
./ra_gen/hal_data.o \
./ra_gen/main.o \
./ra_gen/pin_data.o \
./ra_gen/task_battery.o \
./ra_gen/task_uart.o \
./ra_gen/vector_data.o 

SREC += \
ADC_UART_FREERTOS.srec 

MAP += \
ADC_UART_FREERTOS.map 


# Each subdirectory must supply rules for building sources it contributes
ra_gen/%.o: ../ra_gen/%.c
	$(file > $@.in,-mcpu=cortex-m23 -mthumb -O2 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Wlogical-op -Waggregate-return -Wfloat-equal  -g -gdwarf-4 -D_RENESAS_RA_ -D_RA_CORE=CM23 -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/src" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/fsp/inc" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/fsp/inc/api" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/fsp/inc/instances" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/fsp/src/rm_freertos_port" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/aws/FreeRTOS/FreeRTOS/Source/include" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra/arm/CMSIS_5/CMSIS/Core/Include" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra_gen" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra_cfg/fsp_cfg/bsp" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra_cfg/fsp_cfg" -I"/opt/work/workspaces/defaut/ADC_UART_FREERTOS/ra_cfg/aws" -std=c99 -Wno-stringop-overflow -Wno-format-truncation --param=min-pagesize=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" -x c "$<")
	@echo Building file: $< && arm-none-eabi-gcc @"$@.in"

