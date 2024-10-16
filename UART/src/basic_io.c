#include "basic_io.h"
#include "../src/RTT/SEGGER_RTT.h"

void print_string(const char *string)
{
	{
	    SEGGER_RTT_printf(0, "%s", string);
	}
}
/*-----------------------------------------------------------*/

void print_string_and_number(const char *string, unsigned long value)
{
	{
	    SEGGER_RTT_printf(0, "%s %lu\r\n", string, value);
	}
}
/*-----------------------------------------------------------*/

void print_stats(const char *string)
{
    {
        SEGGER_RTT_Init();
        SEGGER_RTT_printf(0, "\r\n******** RUN TIME STATS ********\r\n");
        SEGGER_RTT_printf(0, "%s", string);
        SEGGER_RTT_printf(0, "\r\n");
    }
}
/*-----------------------------------------------------------*/
