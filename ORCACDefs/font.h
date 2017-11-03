/********************************************
*
* Font Manager
*
* Copyright Apple Computer, Inc. 1986-91
* All Rights Reserved
*
* Copyright 1992, Byte Works, Inc.
*
********************************************/

#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __FONT__
#define __FONT__

/* Error Codes */
#define fmDupStartUpErr 0x1B01          /* duplicate FMStartUp call */
#define fmResetErr 0x1B02               /* can't reset the Font Manager */
#define fmNotActiveErr 0x1B03           /* Font Manager not active */
#define fmFamNotFndErr 0x1B04           /* family not found */
#define fmFontNtFndErr 0x1B05           /* font not found */
#define fmFontMemErr 0x1B06             /* font not in memory */
#define fmSysFontErr 0x1B07             /* system font cannot be purgeable */
#define fmBadFamNumErr 0x1B08           /* illegal family number */
#define fmBadSizeErr 0x1B09             /* illegal size */
#define fmBadNameErr 0x1B0A             /* illegal name length */
#define fmMenuErr 0x1B0B                /* fix font menu never called */
#define fmScaleSizeErr 0x1B0C           /* scaled size of font exeeds limits */
#define fmBadParmErr 0x1B0D

/* Font Family Numbers */
#define chicago 0xFFFD
#define shaston 0xFFFE
#define systemFont0 0x0000
#define systemFont1 0x0001
#define newYork 0x0002
#define geneva 0x0003
#define monaco 0x0004
#define venice 0x0005
#define london 0x0006
#define athens 0x0007
#define sanFrancisco 0x0008
#define toronto 0x0009
#define cairo 0x000B
#define losAngeles 0x000C
#define zapfDingbats 0x000D
#define bookman 0x000E
#define helveticaNarrow 0x000F
#define palatino 0x0010
#define zapfChancery 0x0012
#define times 0x0014
#define helvetica 0x0015
#define courier 0x0016
#define symbol 0x0017
#define taliesin 0x0018
#define avanteGarde 0x0021
#define newCenturySchoolbook 0x0022
#define baseOnlyBit 0x0020              /* FamSpecBits */
#define notBaseBit 0x0020               /* FamStatBits */
#define memOnlyBit 0x0001               /* FontSpecBits */
#define realOnlyBit 0x0002              /* FontSpecBits */
#define anyFamBit 0x0004                /* FontSpecBits */
#define anyStyleBit 0x0008              /* FontSpecBits */
#define anySizeBit 0x0010               /* FontSpecBits */
#define memBit 0x0001                   /* FontStatBits */
#define unrealBit 0x0002                /* FontStatBits */
#define apFamBit 0x0004                 /* FontStatBits */
#define apVarBit 0x0008                 /* FontStatBits */
#define purgeBit 0x0010                 /* FontStatBits */
#define notDiskBit 0x0020               /* FontStatBits */
#define notFoundBit 0x8000              /* FontStatBits */
#define dontScaleBit 0x0001             /* Scale Word */

struct FontStatRec {
   FontID resultID;
   Word resultStats;
   };
typedef struct FontStatRec FontStatRec, *FontStatRecPtr, **FontStatRecHndl;

extern pascal void FMBootInit(void) inline(0x011B,dispatcher);
extern pascal void FMStartUp(Word, Word) inline(0x021B,dispatcher);
extern pascal void FMShutDown(void) inline(0x031B,dispatcher);
extern pascal Word FMVersion(void) inline(0x041B,dispatcher);
extern pascal void FMReset(void) inline(0x051B,dispatcher);
extern pascal Boolean FMStatus(void) inline(0x061B,dispatcher);
extern pascal void AddFamily(Word, Pointer) inline(0x0D1B,dispatcher);
extern pascal void AddFontVar(FontHndl, Word) inline(0x141B,dispatcher);
extern pascal LongWord ChooseFont(FontID, Word) inline(0x161B,dispatcher);
extern pascal Word CountFamilies(Word) inline(0x091B,dispatcher);
extern pascal Word CountFonts(FontID, Word) inline(0x101B,dispatcher);
extern pascal Word FamNum2ItemID(Word) inline(0x1B1B,dispatcher);
extern pascal Word FindFamily(Word, Word, Pointer) inline(0x0A1B,dispatcher);
extern pascal void FindFontStats(FontID, Word, Word, FontStatRecPtr) inline(0x111B,dispatcher);
extern pascal void FixFontMenu(Word, Word, Word) inline(0x151B,dispatcher);
extern pascal LongWord FMGetCurFID(void) inline(0x1A1B,dispatcher);
extern pascal LongWord FMGetSysFID(void) inline(0x191B,dispatcher);
extern pascal void FMSetSysFont(FontID) inline(0x181B,dispatcher);
extern pascal Word GetFamInfo(Word, Pointer) inline(0x0B1B,dispatcher);
extern pascal Word GetFamNum(Pointer) inline(0x0C1B,dispatcher);
extern pascal void InstallFont(FontID, Word) inline(0x0E1B,dispatcher);
extern pascal Word ItemID2FamNum(Word) inline(0x171B,dispatcher);
extern pascal void LoadFont(FontID, Word, Word, FontStatRecPtr) inline(0x121B,dispatcher);
extern pascal void LoadSysFont(void) inline(0x131B,dispatcher);
extern pascal void SetPurgeStat(FontID, Word) inline(0x0F1B,dispatcher);

extern pascal void InstallWithStats(FontID, Word, Pointer) inline(0x1C1B,dispatcher);

#endif
