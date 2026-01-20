#ifndef DRV_UART_H
#define DRV_UART_H
#include "dd_types.h"

char uartInit(void * parameters);
char uartReadChar(void * parameters);
char uartSendChar(void * parameters);

#endif