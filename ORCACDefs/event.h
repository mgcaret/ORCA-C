/********************************************
*
* Event Manager
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

#ifndef __EVENT__
#define __EVENT__

/* Error Codes */
#define emDupStrtUpErr 0x0601           /* duplicate EMStartup Call */
#define emResetErr 0x0602               /* can't reset error the Event Manager */
#define emNotActErr 0x0603              /* event manager not active */
#define emBadEvtCodeErr 0x0604          /* illegal event code */
#define emBadBttnNoErr 0x0605           /* illegal button number */
#define emQSiz2LrgErr 0x0606            /* queue size too large */
#define emNoMemQueueErr 0x0607          /* not enough memory for queue */
#define emBadEvtQErr 0x0681             /* fatal sys error - event queue damaged */
#define emBadQHndlErr 0x0682            /* fatal sys error - queue handle damaged */

/* Event Codes */
#define nullEvt 0x0000
#define mouseDownEvt 0x0001
#define mouseUpEvt 0x0002
#define keyDownEvt 0x0003
#define autoKeyEvt 0x0005
#define updateEvt 0x0006
#define activateEvt 0x0008
#define switchEvt 0x0009
#define deskAccEvt 0x000A
#define driverEvt 0x000B
#define app1Evt 0x000C
#define app2Evt 0x000D
#define app3Evt 0x000E
#define app4Evt 0x000F

/* Event Masks */
#define mDownMask 0x0002
#define mUpMask 0x0004
#define keyDownMask 0x0008
#define autoKeyMask 0x0020
#define updateMask 0x0040
#define activeMask 0x0100
#define switchMask 0x0200
#define deskAccMask 0x0400
#define driverMask 0x0800
#define app1Mask 0x1000
#define app2Mask 0x2000
#define app3Mask 0x4000
#define app4Mask 0x8000
#define everyEvent 0xFFFF

/* Journal Codes */
#define jcTickCount 0x00                /* TickCount call */
#define jcGetMouse 0x01                 /* GetMouse call */
#define jcButton 0x02                   /* Button call */
#define jcEvent 0x04                    /* GetNextEvent and EventAvail calls */

/* Modifiers Flags */
#define activeFlag 0x0001               /* set if window being activated */
#define changeFlag 0x0002               /* set if active wind. changed state */
#define btn1State 0x0040                /* set if button 1 up */
#define btn0State 0x0080                /* set if button 0 up */
#define appleKey 0x0100                 /* set if Apple key down */
#define shiftKey 0x0200                 /* set if shift key down */
#define capsLock 0x0400                 /* set if caps lock key down */
#define optionKey 0x0800                /* set if option key down */
#define controlKey 0x1000               /* set if Control key down */
#define keyPad 0x2000                   /* set if keypress from key pad */

/* kTransID */
#define keyboardTransIIGS 0x0000        /* use old-style Apple IIGS mapping */
#define keyboardTransMac 0x00FF         /* use Macintosh mapping */

struct EventJournalRec {
   Word statusMode;
   Word yLocation;
   Word xLocation;
   };
typedef struct EventJournalRec EventJournalRec, *EventJournalRecPtr, **EventJournalRecHndl;

extern pascal void EMBootInit(void) inline(0x0106,dispatcher);
extern pascal void EMStartUp(Word, Word, Integer, Integer, Integer, Integer, Word) inline(0x0206,dispatcher);
extern pascal void EMShutDown(void) inline(0x0306,dispatcher);
extern pascal Word EMVersion(void) inline(0x0406,dispatcher);
extern pascal void EMReset(void) inline(0x0506,dispatcher);
extern pascal Boolean EMStatus(void) inline(0x0606,dispatcher);
extern pascal Boolean Button(Word) inline(0x0D06,dispatcher);
extern pascal Word DoWindows(void) inline(0x0906,dispatcher);
extern pascal Boolean EventAvail(Word, EventRecordPtr) inline(0x0B06,dispatcher);
extern pascal void FakeMouse(Word, Word, Integer, Integer, Word) inline(0x1906,dispatcher);
extern pascal Word FlushEvents(Word, Word) inline(0x1506,dispatcher);
extern pascal LongWord GetCaretTime(void) inline(0x1206,dispatcher);
extern pascal LongWord GetDblTime(void) inline(0x1106,dispatcher);
extern pascal void GetMouse(Point *) inline(0x0C06,dispatcher);
extern pascal Boolean GetNextEvent(Word, EventRecordPtr) inline(0x0A06,dispatcher);
extern pascal Boolean GetOSEvent(Word, EventRecordPtr) inline(0x1606,dispatcher);
extern pascal Boolean OSEventAvail(Word, EventRecordPtr) inline(0x1706,dispatcher);
extern pascal Word PostEvent(Word, LongWord) inline(0x1406,dispatcher);
extern pascal void SetEventMask(Word) inline(0x1806,dispatcher);
extern pascal void SetSwitch(void) inline(0x1306,dispatcher);
extern pascal Boolean StillDown(Word) inline(0x0E06,dispatcher);
extern pascal LongWord TickCount(void) inline(0x1006,dispatcher);
extern pascal Boolean WaitMouseUp(Word) inline(0x0F06,dispatcher);

extern pascal Word GetKeyTranslation(void) inline(0x1B06,dispatcher);
extern pascal void SetAutoKeyLimit(Word) inline(0x1A06,dispatcher);
extern pascal void SetKeyTranslation(Word) inline(0x1C06,dispatcher);

#endif
