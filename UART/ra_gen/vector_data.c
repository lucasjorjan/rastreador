/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [1] = sci_uart_txi_isr, /* SCI3 TXI (Transmit data empty) */
            [3] = sci_uart_eri_isr, /* SCI3 ERI (Receive error) */
            [4] = adc_scan_end_isr, /* ADC0 SCAN END (A/D scan end interrupt) */
            [6] = adc_window_compare_isr, /* ADC0 WINDOW A (Window A Compare match) */
            [8] = sci_uart_rxi_isr, /* SCI3 RXI (Receive data full) */
            [10] = sci_uart_tei_isr, /* SCI3 TEI (Transmit end) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [1] = BSP_PRV_IELS_ENUM(EVENT_SCI3_TXI), /* SCI3 TXI (Transmit data empty) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_SCI3_ERI), /* SCI3 ERI (Receive error) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_ADC0_SCAN_END), /* ADC0 SCAN END (A/D scan end interrupt) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_ADC0_WINDOW_A), /* ADC0 WINDOW A (Window A Compare match) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_SCI3_RXI), /* SCI3 RXI (Receive data full) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_SCI3_TEI), /* SCI3 TEI (Transmit end) */
        };
        #endif
