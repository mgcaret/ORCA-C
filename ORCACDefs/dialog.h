/********************************************
*
* Dialog Manager
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

#ifndef __DIALOG__
#define __DIALOG__

/* Error Codes */
#define badItemType 0x150A
#define newItemFailed 0x150B
#define itemNotFound 0x150C
#define notModalDialog 0x150D

/* Command Codes */
#define getInitView 0x0001
#define getInitTotal 0x0002
#define getInitValue 0x0003
#define scrollLineUp 0x0004
#define scrollLineDown 0x0005
#define scrollPageUp 0x0006
#define scrollPageDown 0x0007
#define scrollThumb 0x0008

/* Item Type Codes */
#define buttonItem 0x000A
#define checkItem 0x000B
#define radioItem 0x000C
#define scrollBarItem 0x000D
#define userCtlItem 0x000E
#define statText 0x000F
#define longStatText 0x0010
#define editLine 0x0011
#define iconItem 0x0012
#define picItem 0x0013
#define userItem 0x0014
#define userCtlItem2 0x0015
#define longStatText2 0x0016
#define itemDisable 0x8000

/* Item Type Ranges */
#define minItemType 0x000A
#define maxItemType 0x0016

/* ItemID Codes */
#define ok 0x0001
#define cancel 0x0002

/* Part Codes */
#define inButton 0x0002
#define inCheckBox 0x0003
#define inRadioButton 0x0004
#define inUpArrow 0x0005
#define inDownArrow 0x0006
#define inPageUp 0x0007
#define inPageDown 0x0008
#define inStatText 0x0009
#define inGrow 0x000A
#define inEditLine 0x000B
#define inUserItem 0x000C
#define inLongStatText 0x000D
#define inIconItem 0x000E
#define inLongStatText2 0x000F
#define inThumb 0x0081

/* Stage Bit Vectors */
#define okDefault 0x0000
#define cancelDefault 0x0040
#define alertDrawn 0x0080

/* Other Constants */
#ifndef atItemListLength                /* AlertTemplate - Default number of Item Templates */
#define atItemListLength 0x0005
#endif
#ifndef dtItemListLength                /* DialogTemplate - Default number of Item Templates */
#define dtItemListLength 0x0008
#endif

typedef GrafPortPtr DialogPtr;

struct ItemTemplate {
   Word itemID;
   Rect itemRect;
   Word itemType;
   Pointer itemDescr;
   Word itemValue;
   Word itemFlag;
   Pointer itemColor;                   /* pointer to appropriate type of color table */
   };
typedef struct ItemTemplate ItemTemplate, *ItemTempPtr, **ItemTempHndl;

struct AlertTemplate {
   Rect atBoundsRect;
   Word atAlertID;
   Byte atStage1;
   Byte atStage2;
   Byte atStage3;
   Byte atStage4;
   ItemTempPtr atItemList[atItemListLength]; /* Null terminated array */
   };
typedef struct AlertTemplate AlertTemplate, *AlertTempPtr, **AlertTempHndl;

struct DialogTemplate {
   Rect dtBoundsRect;
   Boolean dtVisible;
   Longint dtRefCon;
   ItemTempPtr dtItemList[dtItemListLength]; /* Null terminated array */
   };
typedef struct DialogTemplate DialogTemplate, *DlgTempPtr, **DlgTempHndl;

struct UserCtlItemPB {
   LongProcPtr defProcParm;
   Pointer titleParm;
   Word param2;
   Word param1;
   };
typedef struct UserCtlItemPB UserCtlItemPB, *UserCtlItemPBPtr, **UserCtlItemPBHndl;

extern pascal void DialogBootInit(void) inline(0x0115,dispatcher);
extern pascal void DialogStartUp(Word) inline(0x0215,dispatcher);
extern pascal void DialogShutDown(void) inline(0x0315,dispatcher);
extern pascal Word DialogVersion(void) inline(0x0415,dispatcher);
extern pascal void DialogReset(void) inline(0x0515,dispatcher);
extern pascal Boolean DialogStatus(void) inline(0x0615,dispatcher);
extern pascal Word Alert(AlertTempPtr, WordProcPtr) inline(0x1715,dispatcher);
extern pascal Word CautionAlert(AlertTempPtr, WordProcPtr) inline(0x1A15,dispatcher);
extern pascal void CloseDialog(GrafPortPtr) inline(0x0C15,dispatcher);
extern pascal Boolean DefaultFilter(GrafPortPtr, EventRecordPtr, Word *) inline(0x3615,dispatcher);
extern pascal Boolean DialogSelect(EventRecordPtr, GrafPortPtr *, Word *) inline(0x1115,dispatcher);
extern pascal void DisableDItem(GrafPortPtr, Word) inline(0x3915,dispatcher);
extern pascal void DlgCopy(GrafPortPtr) inline(0x1315,dispatcher);
extern pascal void DlgCut(GrafPortPtr) inline(0x1215,dispatcher);
extern pascal void DlgDelete(GrafPortPtr) inline(0x1515,dispatcher);
extern pascal void DlgPaste(GrafPortPtr) inline(0x1415,dispatcher);
extern pascal void DrawDialog(GrafPortPtr) inline(0x1615,dispatcher);
extern pascal void EnableDItem(GrafPortPtr, Word) inline(0x3A15,dispatcher);
extern pascal void ErrorSound(VoidProcPtr) inline(0x0915,dispatcher);
extern pascal Word FindDItem(GrafPortPtr, Point) inline(0x2415,dispatcher);
extern pascal Word GetAlertStage(void) inline(0x3415,dispatcher);
extern pascal CtlRecHndl GetControlDItem(GrafPortPtr, Word) inline(0x1E15,dispatcher);
extern pascal Word GetDefButton(GrafPortPtr) inline(0x3715,dispatcher);
extern pascal void GetDItemBox(GrafPortPtr, Word, Rect *) inline(0x2815,dispatcher);
extern pascal Word GetDItemType(GrafPortPtr, Word) inline(0x2615,dispatcher);
extern pascal Word GetDItemValue(GrafPortPtr, Word) inline(0x2E15,dispatcher);
extern pascal Word GetFirstDItem(GrafPortPtr) inline(0x2A15,dispatcher);
extern pascal void GetIText(GrafPortPtr, Word, Pointer) inline(0x1F15,dispatcher);
extern pascal void GetNewDItem(GrafPortPtr, ItemTempPtr) inline(0x3315,dispatcher);
extern pascal DialogPtr GetNewModalDialog(DlgTempPtr) inline(0x3215,dispatcher);
extern pascal Word GetNextDItem(GrafPortPtr, Word) inline(0x2B15,dispatcher);
extern pascal void HideDItem(GrafPortPtr, Word) inline(0x2215,dispatcher);
extern pascal Boolean IsDialogEvent(EventRecordPtr) inline(0x1015,dispatcher);
extern pascal Word ModalDialog(WordProcPtr) inline(0x0F15,dispatcher);
extern pascal LongWord ModalDialog2(WordProcPtr) inline(0x2C15,dispatcher);
extern pascal void NewDItem(GrafPortPtr, Word, Rect *, Word, Pointer, Word, Word, Pointer) inline(0x0D15,dispatcher);
extern pascal DialogPtr NewModalDialog(Rect *, Boolean, LongWord) inline(0x0A15,dispatcher);
extern pascal DialogPtr NewModelessDialog(Rect *, Pointer, GrafPortPtr, Word, LongWord, Rect *) inline(0x0B15,dispatcher);
extern pascal Word NoteAlert(AlertTempPtr, WordProcPtr) inline(0x1915,dispatcher);
extern pascal void ParamText(Pointer, Pointer, Pointer, Pointer) inline(0x1B15,dispatcher);
extern pascal void RemoveDItem(GrafPortPtr, Word) inline(0x0E15,dispatcher);
extern pascal void ResetAlertStage(void) inline(0x3515,dispatcher);
extern pascal void SelectIText(GrafPortPtr, Word, Word, Word) inline(0x2115,dispatcher);
extern pascal void SelIText(GrafPortPtr, Word, Word, Word) inline(0x2115,dispatcher);
extern pascal void SetDAFont(FontHndl) inline(0x1C15,dispatcher);
extern pascal void SetDefButton(Word, GrafPortPtr) inline(0x3815,dispatcher);
extern pascal void SetDItemBox(GrafPortPtr, Word, Rect *) inline(0x2915,dispatcher);
extern pascal void SetDItemType(Word, GrafPortPtr, Word) inline(0x2715,dispatcher);
extern pascal void SetDItemValue(Word, GrafPortPtr, Word) inline(0x2F15,dispatcher);
extern pascal void SetIText(GrafPortPtr, Word, Pointer) inline(0x2015,dispatcher);
extern pascal void ShowDItem(GrafPortPtr, Word) inline(0x2315,dispatcher);
extern pascal Word StopAlert(AlertTempPtr, WordProcPtr) inline(0x1815,dispatcher);
extern pascal void UpdateDialog(GrafPortPtr, Handle) inline(0x2515,dispatcher);

#endif
