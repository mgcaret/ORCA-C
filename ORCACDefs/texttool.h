/********************************************
*
* Text Tool Set
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

#ifndef __TEXTTOOL__
#define __TEXTTOOL__

/* Error Codes */
#define badDevType 0x0C01               /* not implemented */
#define badDevNum 0x0C02                /* Illegal device number. */
#define badMode 0x0C03                  /* Bad mode: illegal operation. */
#define unDefHW 0x0C04                  /* Undefined hardware error */
#define lostDev 0x0C05                  /* Lost device: Device no longer on line */
#define lostFile 0x0C06                 /* File no longer in diskette directory */
#define badTitle 0x0C07                 /* Illegal Filename */
#define noRoom 0x0C08                   /* Insufficient space on specified diskette */
#define noDevice 0x0C09                 /* Volume not online */
#define noFile 0x0C0A                   /* File not in specifiled directory */
#define dupFile 0x0C0B                  /* Filename already exists */
#define notClosed 0x0C0C                /* Attempt to open an open file */
#define notOpen 0x0C0D                  /* Attempt to close closed file */
#define badFormat 0x0C0E                /* error reading real or integer */
#define ringBuffOFlo 0x0C0F             /* Chars arriving too fast */
#define writeProtected 0x0C10
#define devErr 0x0C40                   /* Read or Write failed */

/* deviceNum Codes */
#define input 0x0000
#define output 0x0001
#define errorOutput 0x0002

/* deviceType Codes */
#define basicType 0x0000
#define pascalType 0x0001
#define ramBased 0x0002

/* echoFlag Codes */
#define noEcho 0x0000
#define echo 0x0001

struct DeviceRec {
   LongWord ptrOrSlot;                  /* slot number or jump table ptr */
   Word deviceType;                     /* type of input device */
   };
typedef struct DeviceRec DeviceRec, *DeviceRecPtr, **DeviceRecHndl;

struct TxtMaskRec {
   Word orMask;
   Word andMask;
   };
typedef struct TxtMaskRec TxtMaskRec, *TxtMaskRecPtr, **TxtMaskRecHndl;

extern pascal void TextBootInit(void) inline(0x010C,dispatcher);
extern pascal void TextStartUp(void) inline(0x020C,dispatcher);
extern pascal void TextShutDown(void) inline(0x030C,dispatcher);
extern pascal Word TextVersion(void) inline(0x040C,dispatcher);
extern pascal void TextReset(void) inline(0x050C,dispatcher);
extern pascal Boolean TextStatus(void) inline(0x060C,dispatcher);
extern pascal void CtlTextDev(Word, Word) inline(0x160C,dispatcher);
extern pascal void ErrWriteBlock(Pointer, Word, Word) inline(0x1F0C,dispatcher);
extern pascal void ErrWriteChar(Word) inline(0x190C,dispatcher);
extern pascal void ErrWriteCString(Pointer) inline(0x210C,dispatcher);
extern pascal void ErrWriteLine(Pointer) inline(0x1B0C,dispatcher);
extern pascal void ErrWriteString(Pointer) inline(0x1D0C,dispatcher);
extern pascal Long GetErrGlobals(void) inline(0x0E0C,dispatcher);
extern DeviceRec GetErrorDevice(void);
extern pascal Long GetInGlobals(void) inline(0x0C0C,dispatcher);
extern DeviceRec GetInputDevice(void);
extern pascal Long GetOutGlobals (void) inline(0x0D0C,dispatcher);
extern DeviceRec GetOutputDevice(void);
extern pascal void InitTextDev(Word) inline(0x150C,dispatcher);
extern pascal Word ReadChar(Word) inline(0x220C,dispatcher);
extern pascal Word ReadLine(Pointer, Word, Word, Word) inline(0x240C,dispatcher);
extern pascal void SetErrGlobals(Word, Word) inline(0x0B0C,dispatcher);
extern pascal void SetErrorDevice(Word, LongWord) inline(0x110C,dispatcher);
extern pascal void SetInGlobals(Word, Word) inline(0x090C,dispatcher);
extern pascal void SetInputDevice(Word, LongWord) inline(0x0F0C,dispatcher);
extern pascal void SetOutGlobals(Word, Word) inline(0x0A0C,dispatcher);
extern pascal void SetOutputDevice(Word, LongWord) inline(0x100C,dispatcher);
extern pascal void StatusTextDev(Word, Word) inline(0x170C,dispatcher);
extern pascal void TextReadBlock(Pointer, Word, Word, Word) inline(0x230C,dispatcher);
extern pascal void TextWriteBlock(Pointer, Word, Word) inline(0x1E0C,dispatcher);
extern pascal void WriteChar(Word) inline(0x180C,dispatcher);
extern pascal void WriteCString(Pointer) inline(0x200C,dispatcher);
extern pascal void WriteLine(Pointer) inline(0x1A0C,dispatcher);
extern pascal void WriteString(Pointer) inline(0x1C0C,dispatcher);

#endif
