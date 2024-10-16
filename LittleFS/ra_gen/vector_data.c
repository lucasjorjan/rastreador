/* generated vector source file - do not edit */
#include "bsp_api.h"
/* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
#if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [4] = spi_rxi_isr, /* SPI1 RXI (Receive buffer full) */
            [5] = spi_txi_isr, /* SPI1 TXI (Transmit buffer empty) */
            [6] = spi_tei_isr, /* SPI1 TEI (Transmission complete event) */
            [7] = spi_eri_isr, /* SPI1 ERI (Error) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [4] = BSP_PRV_IELS_ENUM(EVENT_SPI1_RXI), /* SPI1 RXI (Receive buffer full) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_SPI1_TXI), /* SPI1 TXI (Transmit buffer empty) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SPI1_TEI), /* SPI1 TEI (Transmission complete event) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_SPI1_ERI), /* SPI1 ERI (Error) */
        };
        #endif
