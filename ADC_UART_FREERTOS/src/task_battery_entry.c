#include "hal_data.h"
#include "task_battery.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../src/RTT/SEGGER_RTT.h"

#define V_ref (1.8f)
#define ADC_12_BIT (4096u)
#define SIZE_64 (64U)

extern TaskHandle_t task_uart;

static uint16_t channel0_conversion_result;
char volt_str[5]= {0x00};
float adc_volt = {0x00};
fsp_err_t err = FSP_SUCCESS;     // Error status
volatile bool scan_complete_flag = false;

void adc_callback (adc_callback_args_t * p_args)
{
    FSP_PARAMETER_NOT_USED(p_args);
    scan_complete_flag = true;
}

void floatToCharArray(float value, char *str, int precision) {
    int intPart = (int)value;
    int intLength = 0;
    if (intPart == 0) {
        str[intLength++] = '0';
    } else {
        while (intPart > 0) {
            int digit = intPart % 10;
            str[intLength++] = digit + '0';
            intPart /= 10;
        }
    }

    // Reverse the integer part in the string
    for (int i = 0; i < intLength / 2; i++) {
        char temp = str[i];
        str[i] = str[intLength - i - 1];
        str[intLength - i - 1] = temp;
    }

    // Add the decimal point
    str[intLength] = '.';
    intLength++;

    float fractionalPart = value - (int)value;
    for (int i = 0; i < precision; i++) {
        fractionalPart *= 10;
        int digit = (int)fractionalPart;
        str[intLength++] = digit + '0';
        fractionalPart -= digit;
    }

    // Null-terminate the string
    str[intLength] = '\0';
}

void task_battery_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);
    UBaseType_t priority;
    const char *task_name = "\r\n//// TASK BATTERY is running //////\r";

    /* LED de indicação */
    R_IOPORT_PinWrite(&g_ioport_ctrl, LED, BSP_IO_LEVEL_HIGH);

    /* Enable channel */
    R_ADC_Open(&g_adc0_ctrl, &g_adc0_cfg);

    R_IOPORT_PinWrite(&g_ioport_ctrl, EN_BM, BSP_IO_LEVEL_HIGH);

    while (1)
    {
        /* Print out the name of this task. */
        print_string(task_name);

        err = R_ADC_ScanCfg(&g_adc0_ctrl, &g_adc0_channel_cfg);
            if (FSP_SUCCESS != err)
                    {
                        /* ADC Failure message */
                    print_string("** R_ADC_ScanCfg API failed ** \r\n");
                    }

        print_string("\rADC Started Scan\r");
        err = R_ADC_ScanStart(&g_adc0_ctrl);
        R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS);
            /* handle error */
           if (FSP_SUCCESS != err)
           {
               /* ADC Failure message */
               print_string("** R_ADC_ScanStart API failed ** \r");
           }

       /* Read converted data. */
       print_string("\rRead converted data\r");
       err = R_ADC_Read(&g_adc0_ctrl, ADC_CHANNEL_0, &channel0_conversion_result);
       if (FSP_SUCCESS != err)
            {
                /* ADC Failure message */
                print_string("** R_ADC_Read API failed ** \r\n");
            }

       adc_volt = (float)((channel0_conversion_result*V_ref)/ADC_12_BIT);
       floatToCharArray(adc_volt , volt_str, 2);

       SEGGER_RTT_printf(0, "\rADC input voltage: %s\r\n", volt_str);

       //R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
       /* Delay task for 353 ms */
       //vTaskDelay(353);

       priority = uxTaskPriorityGet(NULL);
       //print_string_and_number("\ntask battery is running at priority", priority);
       SEGGER_RTT_printf(0, "\r\n");
       vTaskPrioritySet(task_uart, (priority + 1));
    }
}
