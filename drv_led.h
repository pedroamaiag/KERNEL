#ifndef DRV_LED_H
#define DRV_LED_H

#ifdef __cplusplus
extern "C" {
#endif

#include "dd_types.h"

char ledInit(void * parameters);
char ledSet(void * parameters);
char ledFlip(void * parameters);

#ifdef __cplusplus
}
#endif

#endif