/********************************************
; File: GSBug.h
;
;
; Copyright Apple Computer, Inc. 1991
; All Rights Reserved
;
********************************************/

#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __GSBUG__
#define __GSBUG__

#define dgiProgramCounter 0  /* for DebugGetInfo */

extern pascal Word DebugVersion() inline(0x04FF,dispatcher);
extern pascal Word DebugStatus() inline(0x06FF,dispatcher);
extern pascal void DebugStr() inline(0x09FF,dispatcher);
extern pascal void SetMileStone() inline(0x0AFF,dispatcher);
extern pascal void DebugSetHook() inline(0x0BFF,dispatcher);
extern pascal LongWord DebugGetInfo() inline(0x0CFF,dispatcher);

#endif
