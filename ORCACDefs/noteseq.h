/********************************************
*
* Note Sequencer
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

#ifndef __NOTESEQ__
#define __NOTESEQ__

/* Commands */
#define pitchBend 0x0L
#define tempo 0x00000001L
#define turnNotesOff 0x00000002L
#define jump 0x00000003L
#define setVibratoDepth 0x00000004L
#define programChange 0x00000005L
#define setRegister 0x00000006L
#define ifGo 0x00000007L
#define incRegister 0x00000008L
#define decRegister 0x00000009L
#define midiNoteOff 0x0000000AL
#define midiNoteOn 0x0000000BL
#define midiPolyKey 0x0000000CL
#define midiCtlChange 0x0000000DL
#define midiProgChange 0x0000000EL
#define midiChnlPress 0x0000000FL
#define midiPitchBend 0x00000010L
#define midiSelChnlMode 0x00000011L
#define midiSysExclusive 0x00000012L
#define midiSysCommon 0x00000013L
#define midiSysRealTime 0x00000014L
#define midiSetSysExl 0x00000015L
#define callRoutine 0x0000001EL

/* Mask Values */
#define commandMask 0x0000007FL
#define volumeMask 0x0000007FL
#define chord 0x00000080L
#define val1Mask 0x00007F00L
#define toneMask 0x00007F00L
#define noteMask 0x00008000L
#define lByte 0x00FF0000L               /* meaning depends on midi command */
#define durationMask 0x07FF0000L
#define trackMask 0x78000000L
#define delayMask 0x80000000L
#define hByte 0xFF000000L

/* Error Codes */
#define noRoomMidiErr 0x1A00
#define noCommandErr 0x1A01             /* can't understand the current SeqItem */
#define noRoomErr 0x1A02                /* sequence is more than twelve levels deep */
#define startedErr 0x1A03               /* Note Sequencer is already started */
#define noNoteErr 0x1A04                /* can't find the note to be turned off by the current SeqItem */
#define noStartErr 0x1A05               /* Note Sequencer not started yet */
#define instBndsErr 0x1A06              /* Instrument number out of Instrument boundary range */
#define nsWrongVer 0x1A07               /* incompatible versions of NoteSequencer and NoteSynthesizer */

struct LocRec {
   Word curPhraseItem;
   Word curPattItem;
   Word curLevel;
   };
typedef struct LocRec LocRec, *LocRecPtr, **LocRecHndl;

extern pascal void SeqBootInit(void) inline(0x011A,dispatcher);
extern pascal void SeqStartUp(Word, Word, Word, Word) inline(0x021A,dispatcher);
extern pascal void SeqShutDown(void) inline(0x031A,dispatcher);
extern pascal Word SeqVersion(void) inline(0x041A,dispatcher);
extern pascal void SeqReset(void) inline(0x051A,dispatcher);
extern pascal Boolean SeqStatus(void) inline(0x061A,dispatcher);
extern pascal Word ClearIncr(void) inline(0x0A1A,dispatcher);
extern LocRec GetLoc(void);
extern pascal Word GetTimer(void) inline(0x0B1A,dispatcher);
extern pascal void SeqAllNotesOff(void) inline(0x0D1A,dispatcher);
extern pascal void SetIncr(Word) inline(0x091A,dispatcher);
extern pascal void SetInstTable(Handle) inline(0x121A,dispatcher);
extern pascal void SetTrkInfo(Word, Word, Word) inline(0x0E1A,dispatcher);
extern pascal void StartInts(void) inline(0x131A,dispatcher);
extern pascal void StartSeq(Pointer, Pointer, Handle) inline(0x0F1A,dispatcher);
extern pascal void StartSeqRel(Pointer, Pointer, Handle) inline(0x151A,dispatcher);
extern pascal void StepSeq(void) inline(0x101A,dispatcher);
extern pascal void StopInts(void) inline(0x141A,dispatcher);
extern pascal void StopSeq(Boolean) inline(0x111A,dispatcher);

#endif
