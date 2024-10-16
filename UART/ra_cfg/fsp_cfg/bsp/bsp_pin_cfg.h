/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define EN_PS_R (BSP_IO_PORT_00_PIN_02)
#define STATUS_MCU (BSP_IO_PORT_00_PIN_14)
#define LED (BSP_IO_PORT_02_PIN_06)
#define PWRKEY_R (BSP_IO_PORT_02_PIN_07)
#define RESET_R (BSP_IO_PORT_02_PIN_08)
#define PSM_IND_R (BSP_IO_PORT_02_PIN_13)
#define EN_BM (BSP_IO_PORT_04_PIN_00)
#define EN_DC_DC (BSP_IO_PORT_04_PIN_01)
#define UCR_R (BSP_IO_PORT_04_PIN_07)
#define PON_TRIG_R (BSP_IO_PORT_05_PIN_00)
extern const ioport_cfg_t g_bsp_pin_cfg; /* R7FA2L1AB2DFL.pincfg */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif /* BSP_PIN_CFG_H_ */
