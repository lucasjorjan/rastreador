/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (4)
#endif
/* ISR prototypes */
void spi_rxi_isr(void);
void spi_txi_isr(void);
void spi_tei_isr(void);
void spi_eri_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_SPI1_RXI ((IRQn_Type) 4) /* SPI1 RXI (Receive buffer full) */
#define SPI1_RXI_IRQn          ((IRQn_Type) 4) /* SPI1 RXI (Receive buffer full) */
#define VECTOR_NUMBER_SPI1_TXI ((IRQn_Type) 5) /* SPI1 TXI (Transmit buffer empty) */
#define SPI1_TXI_IRQn          ((IRQn_Type) 5) /* SPI1 TXI (Transmit buffer empty) */
#define VECTOR_NUMBER_SPI1_TEI ((IRQn_Type) 6) /* SPI1 TEI (Transmission complete event) */
#define SPI1_TEI_IRQn          ((IRQn_Type) 6) /* SPI1 TEI (Transmission complete event) */
#define VECTOR_NUMBER_SPI1_ERI ((IRQn_Type) 7) /* SPI1 ERI (Error) */
#define SPI1_ERI_IRQn          ((IRQn_Type) 7) /* SPI1 ERI (Error) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
