/* generated configuration header file - do not edit */
#ifndef BSP_PIN_CFG_H_
#define BSP_PIN_CFG_H_
#include "r_ioport.h"

/* Common macro for FSP header files. There is also a corresponding FSP_FOOTER macro at the end of this file. */
FSP_HEADER

#define EM_CS (BSP_IO_PORT_03_PIN_01)
#define EM_RST (BSP_IO_PORT_03_PIN_02)
#define IRQ0 (BSP_IO_PORT_04_PIN_00)
extern const ioport_cfg_t g_bsp_pin_cfg; /* R7FA2L1AB2DFL.pincfg */

void BSP_PinConfigSecurityInit();

/* Common macro for FSP header files. There is also a corresponding FSP_HEADER macro at the top of this file. */
FSP_FOOTER

#endif /* BSP_PIN_CFG_H_ */
