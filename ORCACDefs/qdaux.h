/********************************************
*
* QuickDraw II Auxiliary
*
* Copyright Apple Computer, Inc.1986-91
* All Rights Reserved
*
* Copyright 1992, 1993, Byte Works, Inc.
*
********************************************/

#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __QDAUX__
#define __QDAUX__

/*
    PicInfo - The following picture
    opcodes are for reference only!!
*/

#define frameVerb 0x00
#define picNop 0x00
#define drawCharVerb 0x00
#define paintVerb 0x01
#define picClipRgn 0x01
#define drawTextVerb  0x01
#define eraseVerb 0x02
#define picBkPat 0x02
#define drawCStrVerb 0x02
#define invertVerb 0x03
#define picTxFont 0x03
#define fillVerb 0x04
#define picTxFace 0x04
#define picTxMode 0x05
#define picSpExtra 0x06
#define picPnSize 0x07
#define picPnMode 0x08
#define picPnPat 0x09
#define picThePat 0x0A
#define picFillPat 0x0A                 /* 10 */  /* Please use picThePat */
#define picOvSize 0x0B
#define picOrigin 0x0C
#define picTxSize 0x0D
#define picFGColor 0x0E
#define picBGColor 0x0F
#define picTxRatio 0x10
#define picVersion 0x11
#define picChExtra 0x12                 /* 18 */
#define picPnMask 0x13                  /* 19 */
#define picArcRot 0x14                  /* 20 */
#define picFontFlags 0x15               /* 21 */
#define lineNoun 0x20
#define picLine 0x20
#define picLineFrom 0x21
#define picShortL 0x22
#define picShortLine 0x22               /* 34 */
#define picShortLFrom 0x23
#define picLongText 0x28
#define picDHText 0x29
#define picDVText 0x2A
#define picDVDHText 0x2B
#define rectNoun 0x30
#define rRectNoun 0x40
#define ovalNoun 0x50
#define arcNoun 0x60
#define polyNoun 0x70
#define rgnNoun 0x80
#define mapNoun 0x90
#define picBitsRect 0x90
#define picBitsRgn 0x91
#define picPBitsRect 0x98
#define picPBitsRgn 0x99
#define picShortComment 0xA0
#define picLongComment 0xA1
#define picEnd 0xFF

/* SeedFill/CalcMask Masks */
#define resMode640PMask 0x00
#define resMode640DMask 0x01
#define resMode320Mask 0x02
#define destModeCopyMask 0x0000
#define destModeLeaveMask 0x1000
#define destModeOnesMask 0x2000
#define destModeClrToZeros 0x2000       /* 8192 */
#define destModeZerosMask 0x3000
#define destModeClrToOnes 0x3000        /* 12288 */

/* Error Codes */
#define badRectSize 0x1211
#define destModeError 0x1212
#define badPictureOpcode 0x121F
#define badGetSysIconInput 0x1230

/* GetSysIcon constants */
#define fUseOpenFolders 0x0004
#define getFileIcon 0x0000
#define getDeviceIcon 0x0001
#define getMiscIcon 0x0002
#define desktopSysIcon 0x0000
#define padlockSysIcon 0x0001
#define upArrowSysIcon 0x0002
#define downArrowSysIcon 0x0003
#define boxDownArrowSysIcon 0x0004

/* WhooshRect constants */
#define whooshOut 0x80000000L
#define whooshIn  0L
#define fLocalCoordinates 0x40000000L
#define fSilent 0x20000000L

/* Other Constants */
#define fTextJust 0x0008

/* DrawStringWidth flag values */
#define dswNoCondense 0x8000
#define dswCondense 0x0000
#define dswNoTruncate 0x0000
#define dswTruncLeft 0x2000
#define dswTruncCenter 0x4000
#define dswTruncRight 0x6000
#define dswPString 0x0000
#define dswCString 0x0004
#define dswWString 0x0008
#define dswStrIsPtr 0x0000
#define dswStrIsHandle 0x0001
#define dswStrIsResource 0x0002

/* ColorTable flag values */
#define ctUse640Colors 0x8000
#define ctNoCtlNewRes 0x4000
#define ctIncludeMenuBar 0x2000

struct QDIconRecord {
   Word iconType;
   Word iconSize;
   Word iconHeight;
   Word iconWidth;
   Byte iconImage[1];
   Byte iconMask[1];
   };
typedef struct QDIconRecord QDIconRecord, *QDIconRecordPtr, **QDIconRecordHndl;

struct Picture {
   Word picSCB;
   Rect picFrame;
   Word pVersion;                       /* Followed by picture opcodes  */
   };
typedef struct Picture Picture, *PicPtr, **PicHndl;

struct LeakTable {
   Word leakCount;
   Word leakColors[16];
   };
typedef struct LeakTable LeakTable, *LeakTablePtr;

extern pascal void QDAuxBootInit(void) inline(0x0112,dispatcher);
extern pascal void QDAuxStartUp(void) inline(0x0212,dispatcher);
extern pascal void QDAuxShutDown(void) inline(0x0312,dispatcher);
extern pascal Word QDAuxVersion(void) inline(0x0412,dispatcher);
extern pascal void QDAuxReset(void) inline(0x0512,dispatcher);
extern pascal Boolean QDAuxStatus(void) inline(0x0612,dispatcher);
extern pascal void ClosePicture(void) inline(0xB904,dispatcher);
extern pascal void CopyPixels(LocInfoPtr, LocInfoPtr, Rect *, Rect *, Word, RegionHndl) inline(0x0912,dispatcher);
extern pascal void DrawIcon(Pointer, Word, Word, Word) inline(0x0B12,dispatcher);
extern pascal void DrawPicture(Handle, Rect *) inline(0xBA04,dispatcher);
extern pascal void KillPicture(Handle) inline(0xBB04,dispatcher);
extern pascal PicHndl OpenPicture(Pointer) inline(0xB704,dispatcher);
extern pascal void PicComment(Integer, Integer, Handle) inline(0xB804,dispatcher);
extern pascal void WaitCursor(void) inline(0x0A12,dispatcher);

extern pascal void CalcMask(LocInfoPtr, Rect *, LocInfoPtr, Rect *, Word, PatternPtr, Pointer) inline(0x0E12,dispatcher);
extern pascal void SeedFill(LocInfoPtr, Rect *, LocInfoPtr, Rect *, Word, Word, Word, PatternPtr, Pointer) inline(0x0D12,dispatcher);
extern pascal void SpecialRect(Rect *, Word, Word) inline(0x0C12,dispatcher);

extern pascal QDIconRecordPtr GetSysIcon(Word, Word, Long) inline(0x0F12,dispatcher);
extern pascal void IBeamCursor(void) inline(0x1312,dispatcher);
extern pascal RegionHndl PixelMap2Rgn(LocInfoPtr, Word, Word) inline(0x1012,dispatcher);
extern pascal void WhooshRect(Long, Rect *, Rect *) inline(0x1412,dispatcher);

extern pascal void DrawStringWidth(Word, Ref, Word) inline(0x1512,dispatcher);
extern pascal Handle UseColorTable(Word, ColorTablePtr, Word) inline(0x1612,dispatcher);
extern pascal void RestoreColorTable(Handle, Word) inline(0x1712,dispatcher);

#endif
