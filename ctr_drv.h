#ifndef CTR_DRV_H
#define CTR_DRV_H

#ifdef __cplusplus
extern "C" {
#endif

#include "dd_types.h"

void initCtrDrv(void);
char initDriver(char driverID);
char callDriver(char driverID, char command, void * args);

#ifdef __cplusplus
}
#endif

#endif