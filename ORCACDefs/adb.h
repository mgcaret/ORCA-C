/********************************************
*
* Apple Desktop Bus Tool Set
*
* Copyright Apple Computer, Inc.1986-90
* All Rights Reserved
*
* Copyright 1992, Byte Works, Inc.
*
********************************************/

#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __ADB__
#define __ADB__

/* Error Codes */
#define cmndIncomplete 0x0910           /* Command not completed. */
#define cantSync 0x0911                 /* Can't synchronize */
#define adbBusy 0x0982                  /* Busy (command pending) */
#define devNotAtAddr 0x0983             /* Device not present at address */
#define srqListFull 0x0984              /* List full */

/* ReadKeyMicroData Codes */
#define readModes 0x000A
#define readConfig 0x000B
#define readADBError 0x000C
#define readVersionNum 0x000D
#define readAvailCharSet 0x000E
#define readAvailLayout 0x000F

/* SendInfo Commands */
#define abortKbd 0x0001
#define resetKbd 0x0002
#define flushKbd 0x0003
#define setModes 0x0004                 /* 2nd param is pointer to mode byte */
#define clearModes 0x0005               /* 2nd param is pointer to mode Byte */
#define setConfig 0x0006                /* 2nd param is pointer to SetConfigRec */
#define synch 0x0007                    /* 2nd param is pointer to SynchRec */
#define writeMicroMem 0x0008            /* 2nd param is pointer to MicroControlMemRec */
#define resetSys 0x0010
#define keyCode 0x0011                  /* 2nd param is pointer to key code byte. */
#define resetADB 0x0040
#define transmitADBBytes 0x0047         /* add number of bytes to this  */
#define enableSRQ 0x0050                /* ADB address in low nibble */
#define flushADBDevBuf 0x0060           /* ADB address in low nibble */
#define disableSRQ 0x0070               /* ADB address in low nibble */
#define transmit2ADBBytes 0x0080        /* add ADB address to this */
#define listen 0x0080                   /* adbCommand = listen + ( 16 * reg) + (adb address) */
#define talk 0x00C0                     /* adbCommand = talk + ( 16 * reg) + (adb address) */

/* Other Constants */
#define readMicroMem 0x0009

struct ReadConfigRec {
   Byte rcADBAddr;                      /* Output Byte: ADB address - keyboard and mouse */
   Byte rcLayoutOrLang;                 /* Output Byte: Layout / Language */
   Byte rcRepeatDelay;                  /* Output Byte: Repeat / Delay */
   };
typedef struct ReadConfigRec ReadConfigRec, *ReadConfigRecPtr;

struct SetConfigRec {
   Byte scADBAddr;                      /* keyboard and mouse */
   Byte scLayoutOrLang;
   Byte scRepeatDelay;
   };
typedef struct SetConfigRec SetConfigRec, *SetConfigRecPtr;

struct SynchRec {
   Byte synchMode;
   Byte synchKybdMouseAddr;
   Byte synchLayoutOrLang;
   Byte synchRepeatDelay;
   };
typedef struct SynchRec SynchRec, *SynchRecPtr;

struct ScaleRec {
   Word xDivide;
   Word yDivide;
   Word xOffset;
   Word yOffset;
   Word xMultiply;
   Word yMultiply;
} ;
typedef struct ScaleRec ScaleRec, *ScaleRecPtr;

extern pascal void ADBBootInit(void) inline(0x0109,dispatcher);
extern pascal void ADBStartUp(void) inline(0x0209,dispatcher);
extern pascal void ADBShutDown(void) inline(0x0309,dispatcher);
extern pascal Word ADBVersion(void) inline(0x0409,dispatcher);
extern pascal void ADBReset(void) inline(0x0509,dispatcher);
extern pascal Boolean ADBStatus(void) inline(0x0609,dispatcher);
extern pascal void AbsOn(void) inline(0x0F09,dispatcher);
extern pascal void AbsOff(void) inline(0x1009,dispatcher);
extern pascal void AsyncADBReceive(Pointer, Word) inline(0x0D09,dispatcher);
extern pascal void ClearSRQTable(void) inline(0x1609,dispatcher);
extern pascal void GetAbsScale(ScaleRecPtr) inline(0x1309,dispatcher);
extern pascal Word ReadAbs(void) inline(0x1109,dispatcher);
extern pascal void ReadKeyMicroData(Word, Pointer, Word) inline(0x0A09,dispatcher);
extern pascal void ReadKeyMicroMemory(Pointer, Pointer, Word) inline(0x0B09,dispatcher);
extern pascal void SendInfo(Word, Pointer, Word) inline(0x0909,dispatcher);
extern pascal void SetAbsScale(ScaleRecPtr) inline(0x1209,dispatcher);
extern pascal void SRQPoll(Pointer, Word) inline(0x1409,dispatcher);
extern pascal void SRQRemove(Word) inline(0x1509,dispatcher);
extern pascal void SyncADBReceive(Word, Pointer, Word) inline(0x0E09,dispatcher);

#endif
