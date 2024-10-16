#include "task_uart.h"

// UART DRIVER DEFINES
#define LPUART_DATA_RX_SIZE 512
#define LPUART_DATA_TX_SIZE 512
#define TRANSFER_LENGTH 16
uint8_t  g_dest[LPUART_DATA_RX_SIZE];
uint8_t  g_src[LPUART_DATA_TX_SIZE];
uint8_t  g_out_of_band_received[TRANSFER_LENGTH];
uint32_t g_transfer_complete = 0;
uint32_t g_receive_complete  = 0;
uint32_t g_out_of_band_index = 0;

bool at_SendRaw(uint8_t *data, uint16_t len);
bool at_SendString(char *data);

bool at_SendRaw(uint8_t *data, uint16_t len) {
    if (len <= LPUART_DATA_TX_SIZE) {
        // Send the information in data through the UART
        memcpy(g_src, data, len);
        if (R_SCI_UART_Write(&g_uart0_ctrl, g_src, TRANSFER_LENGTH) == FSP_SUCCESS) {
            R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MILLISECONDS);
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

////  Send string command
////////////////////////////////////////////////////////////////
bool at_SendString(char *data) {
    return at_SendRaw((uint8_t*) data, strlen(data));
}


void task_uart_entry(void *pvParameters)
{
    FSP_PARAMETER_NOT_USED(pvParameters);
    UBaseType_t priority;
    const char *task_name = "///// TASK UART is running //////\r\n";

    /* Enable channels. */
    R_SCI_UART_Open(&g_uart0_ctrl, &g_uart0_cfg);

    R_IOPORT_PinWrite(&g_ioport_ctrl, EN_PS_R, BSP_IO_LEVEL_HIGH);
    R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS);

    R_IOPORT_PinWrite(&g_ioport_ctrl, EN_DC_DC, BSP_IO_LEVEL_HIGH);
    R_BSP_SoftwareDelay(300, BSP_DELAY_UNITS_MILLISECONDS);

    R_IOPORT_PinWrite(&g_ioport_ctrl, PWRKEY_R, BSP_IO_LEVEL_HIGH);
    R_BSP_SoftwareDelay(750, BSP_DELAY_UNITS_MILLISECONDS);
    R_IOPORT_PinWrite(&g_ioport_ctrl, PWRKEY_R, BSP_IO_LEVEL_LOW);
    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);

    while (1)
    {
        /* Print out the name of this task. */
        print_string(task_name);

        at_SendString("Teste\r\n");
        SEGGER_RTT_printf(0, "Msg de envio: %s\r\n", g_src);
        //R_SCI_UART_Write(&g_uart0_ctrl, g_src, TRANSFER_LENGTH);
        R_BSP_SoftwareDelay(200, BSP_DELAY_UNITS_MILLISECONDS);

        R_SCI_UART_Read(&g_uart0_ctrl, g_dest, TRANSFER_LENGTH);
        R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
        SEGGER_RTT_printf(0, "Msg recebida: %s\r\n", g_dest);

        priority = uxTaskPriorityGet(NULL);
        //print_string_and_number("Task UART running at priority", priority);
        vTaskPrioritySet(NULL, (priority - 2));

        /* Delay task for 2999 ms */
        //vTaskDelay(2999);
    }
}

/* Callback function */
void example_callback (uart_callback_args_t * p_args)
{
    /* Handle the UART event */
    switch (p_args->event)
    {
        /* Received a character */
        case UART_EVENT_RX_CHAR:
        {
            /* Only put the next character in the receive buffer if there is space for it */
            if (sizeof(g_out_of_band_received) > g_out_of_band_index)
            {
                /* Write either the next one or two bytes depending on the receive data size */
                if (UART_DATA_BITS_8 >= g_uart0_cfg.data_bits)
                {
                    g_out_of_band_received[g_out_of_band_index++] = (uint8_t) p_args->data;
                }
                else
                {
                    uint16_t * p_dest = (uint16_t *) &g_out_of_band_received[g_out_of_band_index];
                    *p_dest              = (uint16_t) p_args->data;
                    g_out_of_band_index += 2;
                }
            }
            break;
        }
        /* Receive complete */
        case UART_EVENT_RX_COMPLETE:
        {
            g_receive_complete = 1;
            break;
        }
        /* Transmit complete */
        case UART_EVENT_TX_COMPLETE:
        {
            g_transfer_complete = 1;
            break;
        }
        default:
        {
        }
    }
}
