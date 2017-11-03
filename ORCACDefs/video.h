/********************************************
*
* Video Overlay Tool Set
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

#ifndef __VIDEO__
#define __VIDEO__

#define vdVideoOverlay 0x01
#define vdFrameGrabber 0x02
#define vdInVStandards 0x03
#define vdOutVStandards 0x04
#define vdKeyDissLevels 0x05
#define vdNKeyDissLevels 0x06
#define vdAdjSideEffect 0x07
#define vdKeyColorBits 0x08
#define vdInHueAdj 0x09
#define vdInSatAdj 0x0A
#define vdInContrastAdj 0x0B
#define vdInBrightAdj 0x0C
#define vdOutSetup 0x0D
#define vdOutChromaFltr 0x0E
#define vdOutExtBlank 0x0F
#define vdKeyEnhDiss 0x10
#define vdLineInterrupt 0x11
#define vdGGBus 0x12
#define vdDualOut 0x13
#define vdTextMonoOver 0x14
#define vdGenlock 0x32
#define vdVideoDetect 0x33
#define vdGenlocked 0x34
#define vdAdjInc 0x50
#define vdAdjDec 0x51
#define vdAdjSave 0x52
#define vdAvail 0x01
#define vdNotAvail 0x00
#define vdYes 0x01
#define vdNo 0x00
#define vdOn 0x01
#define vdOff 0x00
#define vdNil 0x00
#define vdFalse 0x00
#define vdTrue 0x01
#define vdKColorEnable 0x64
#define vdVerticalBlank 0x82
#define vdMainPageLin 0xC8
#define vdRAMPageSel 0xC9
#define vdVBLInterrupt 0xCA
#define vdInterlaceMode 0xCB
#define vdClearVBLInt 0xCC
#define vdClearLineInt 0xCD
#define vdDisplayField 0xCE
#define vdVBLIntRequest 0xCF
#define vdLineIntRequest 0xD0
#define vdNone 0x00
#define vdNTSC 0x01
#define vdPAL 0x02
#define vdSECAM 0x04
#define vdSNTSC 0x08
#define vdSPAL 0x10
#define vdSSECAM 0x20
#define vdRGB60 0x40
#define vdRGB50 0x80
#define vdAux 0x00
#define vdMain 0x10
#define vdInterlace 0x30
#define vdField1 0x01
#define vdField0 0x00
#define vdEnable 0x01
#define vdDisable 0x00
#define vdExternal 0x00
#define vdGraphics 0x01
#define vdVBlank 0x01
#define vdActiveVideo 0x00

/* Error Codes */
#define vdNoVideoDevice 0x2110          /* no video device was found */
#define vdAlreadyStarted 0x2111         /* Video tool set already started */
#define vdInvalidSelector 0x2112        /* an invalid selector was specified */
#define vdInvalidParam 0x2113           /* an invalid parameter was specified */
#define vdUnImplemented 0x21FF          /* an unimplemented tool set routine was called */

extern pascal void VDBootInit(void) inline(0x0121,dispatcher);
extern pascal void VDStartUp(void) inline(0x0221,dispatcher);
extern pascal void VDShutDown(void) inline(0x0321,dispatcher);
extern pascal Word VDVersion(void) inline(0x0421,dispatcher);
extern pascal void VDReset(void) inline(0x0521,dispatcher);
extern pascal Boolean VDStatus(void) inline(0x0621,dispatcher);
extern pascal Word VDGetFeatures(Word) inline(0x1B21,dispatcher);
extern pascal void VDGGControl(Word, Word) inline(0x1D21,dispatcher);
extern pascal Word VDGGStatus(Word) inline(0x1E21,dispatcher);
extern pascal void VDInControl(Word, Word) inline(0x1C21,dispatcher);
extern pascal void VDInConvAdj(Word, Word) inline(0x0C21,dispatcher);
extern pascal Word VDInGetStd(void) inline(0x0B21,dispatcher);
extern pascal void VDInSetStd(Word) inline(0x0A21,dispatcher);
extern pascal Word VDInStatus(Word) inline(0x0921,dispatcher);
extern pascal void VDKeyControl(Word, Word) inline(0x0D21,dispatcher);
extern pascal Word VDKeyGetKBCol(void) inline(0x1221,dispatcher);
extern pascal Word VDKeyGetKDiss(void) inline(0x1421,dispatcher);
extern pascal Word VDKeyGetKGCol(void) inline(0x1121,dispatcher);
extern pascal Word VDKeyGetKRCol(void) inline(0x1021,dispatcher);
extern pascal Word VDKeyGetNKDiss(void) inline(0x1621,dispatcher);
extern pascal void VDKeySetKCol(Word, Word, Word) inline(0x0F21,dispatcher);
extern pascal void VDKeySetKDiss(Word) inline(0x1321,dispatcher);
extern pascal void VDKeySetNKDiss(Word) inline(0x1521,dispatcher);
extern pascal Word VDKeyStatus(Word) inline(0x0E21,dispatcher);
extern pascal void VDOutControl(Word, Word) inline(0x1921,dispatcher);
extern pascal Word VDOutGetStd(void) inline(0x1821,dispatcher);
extern pascal void VDOutSetStd(Word) inline(0x1721,dispatcher);
extern pascal Word VDOutStatus(Word) inline(0x1A21,dispatcher);

#endif
