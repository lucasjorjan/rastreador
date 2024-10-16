/* generated vector header file - do not edit */
#ifndef VECTOR_DATA_H
#define VECTOR_DATA_H
#ifdef __cplusplus
        extern "C" {
        #endif
/* Number of interrupts allocated */
#ifndef VECTOR_DATA_IRQ_COUNT
#define VECTOR_DATA_IRQ_COUNT    (6)
#endif
/* ISR prototypes */
void sci_uart_txi_isr(void);
void sci_uart_eri_isr(void);
void adc_scan_end_isr(void);
void adc_window_compare_isr(void);
void sci_uart_rxi_isr(void);
void sci_uart_tei_isr(void);

/* Vector table allocations */
#define VECTOR_NUMBER_SCI3_TXI ((IRQn_Type) 1) /* SCI3 TXI (Transmit data empty) */
#define SCI3_TXI_IRQn          ((IRQn_Type) 1) /* SCI3 TXI (Transmit data empty) */
#define VECTOR_NUMBER_SCI3_ERI ((IRQn_Type) 3) /* SCI3 ERI (Receive error) */
#define SCI3_ERI_IRQn          ((IRQn_Type) 3) /* SCI3 ERI (Receive error) */
#define VECTOR_NUMBER_ADC0_SCAN_END ((IRQn_Type) 4) /* ADC0 SCAN END (A/D scan end interrupt) */
#define ADC0_SCAN_END_IRQn          ((IRQn_Type) 4) /* ADC0 SCAN END (A/D scan end interrupt) */
#define VECTOR_NUMBER_ADC0_WINDOW_A ((IRQn_Type) 6) /* ADC0 WINDOW A (Window A Compare match) */
#define ADC0_WINDOW_A_IRQn          ((IRQn_Type) 6) /* ADC0 WINDOW A (Window A Compare match) */
#define VECTOR_NUMBER_SCI3_RXI ((IRQn_Type) 8) /* SCI3 RXI (Receive data full) */
#define SCI3_RXI_IRQn          ((IRQn_Type) 8) /* SCI3 RXI (Receive data full) */
#define VECTOR_NUMBER_SCI3_TEI ((IRQn_Type) 10) /* SCI3 TEI (Transmit end) */
#define SCI3_TEI_IRQn          ((IRQn_Type) 10) /* SCI3 TEI (Transmit end) */
#ifdef __cplusplus
        }
        #endif
#endif /* VECTOR_DATA_H */
