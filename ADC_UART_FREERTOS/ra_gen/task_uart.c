/* generated thread source file - do not edit */
#include "task_uart.h"

#if 1
static StaticTask_t task_uart_memory;
#if defined(__ARMCC_VERSION)           /* AC6 compiler */
                static uint8_t task_uart_stack[1024] BSP_PLACE_IN_SECTION(BSP_UNINIT_SECTION_PREFIX ".stack.thread") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
                #else
static uint8_t task_uart_stack[1024] BSP_PLACE_IN_SECTION(BSP_UNINIT_SECTION_PREFIX ".stack.task_uart") BSP_ALIGN_VARIABLE(BSP_STACK_ALIGNMENT);
#endif
#endif
TaskHandle_t task_uart;
void task_uart_create(void);
static void task_uart_func(void *pvParameters);
void rtos_startup_err_callback(void *p_instance, void *p_data);
void rtos_startup_common_init(void);
extern uint32_t g_fsp_common_thread_count;

const rm_freertos_port_parameters_t task_uart_parameters =
{ .p_context = (void*) NULL, };

void task_uart_create(void)
{
    /* Increment count so we will know the number of threads created in the RA Configuration editor. */
    g_fsp_common_thread_count++;

    /* Initialize each kernel object. */

#if 1
    task_uart = xTaskCreateStatic (
#else
                    BaseType_t task_uart_create_err = xTaskCreate(
                    #endif
                                   task_uart_func,
                                   (const char*) "task_uart", 1024 / 4, // In words, not bytes
                                   (void*) &task_uart_parameters, //pvParameters
                                   1,
#if 1
                                   (StackType_t*) &task_uart_stack,
                                   (StaticTask_t*) &task_uart_memory
#else
                        & task_uart
                        #endif
                                   );

#if 1
    if (NULL == task_uart)
    {
        rtos_startup_err_callback (task_uart, 0);
    }
#else
                    if (pdPASS != task_uart_create_err)
                    {
                        rtos_startup_err_callback(task_uart, 0);
                    }
                    #endif
}
static void task_uart_func(void *pvParameters)
{
    /* Initialize common components */
    rtos_startup_common_init ();

    /* Initialize each module instance. */

#if (1 == BSP_TZ_NONSECURE_BUILD) && (1 == 1)
                    /* When FreeRTOS is used in a non-secure TrustZone application, portALLOCATE_SECURE_CONTEXT must be called prior
                     * to calling any non-secure callable function in a thread. The parameter is unused in the FSP implementation.
                     * If no slots are available then configASSERT() will be called from vPortSVCHandler_C(). If this occurs, the
                     * application will need to either increase the value of the "Process Stack Slots" Property in the rm_tz_context
                     * module in the secure project or decrease the number of threads in the non-secure project that are allocating
                     * a secure context. Users can control which threads allocate a secure context via the Properties tab when
                     * selecting each thread. Note that the idle thread in FreeRTOS requires a secure context so the application
                     * will need at least 1 secure context even if no user threads make secure calls. */
                     portALLOCATE_SECURE_CONTEXT(0);
                    #endif

    /* Enter user code for this thread. Pass task handle. */
    task_uart_entry (pvParameters);
}
