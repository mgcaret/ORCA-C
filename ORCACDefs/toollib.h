/*
 *
 *  ToolLib.h - Interface file for functions contained in
 *		ToolLib library.  These functions can be used by
 *		programs that are to be operated as tools under the
 *		APW shell on the Apple IIgs.
 *
 *	Copyright Apple Computer, Inc. 1989
 *	All rights reserved
 *
 *	Author: Greg Branche
 *
 */

#ifndef	__ToolLib__
#define __ToolLib__

/************************************************************

    <<< CursorCtl - Cursor Control Routines >>>

    This file contains:
    
    InitCursorCtl(delaycount) - Init CursorCtl to set the spin delay
    RotateCursor(counter) - Sequence through cursor frames for counter mod delay
    SpinCursor(increment) - Sequence mod delay incrementing internal counter
    Hide_Cursor() - Hide the current cursor
    Show_Cursor() - Show the cursor

************************************************************/

extern pascal void InitCursorCtl(/* delaycount */);/*
unsigned long	delaycount;

	Initialize the CursorCtl unit.  This should be called once prior to calling
	any of the other CursorCtl routines.  If delaycount = 0, then the default delay
	value of 32 will be used.  Ensure that the value being passed as delaycount is
	32-bits in size (long)
*/

extern pascal void Show_Cursor();/*

	This function removes the default inverse space cursor from the screen and replaces it
	with the first frame of the animated cursor.  It then outputs a backspace so that any
	subsequent characters will automatically overwrite the cursor character.
*/

extern pascal void RotateCursor(/* counter */);/*
unsigned long	counter;

	RotateCursor is called to rotate the "I am active" "spinning wheel" cursor.  The next cursor
	("frame") is used when (counter MOD delaycount) (as specified in the InitCursorCtl call) = 0
	(counter is some kind of incrementing or decrementing index maintained by the caller).  A 
	positive counter sequences forward through the cursors (e.g., it rotates the cursor
	"clockwise"), and a negative cursor sequences through the cursors backwards (e.g., it
	rotates the cursor counterclockwise).
*/

extern pascal void SpinCursor(/* increment */);/*
unsigned short	increment;

	SpinCursor is similar in function to RotateCursor, except that instead of passing a counter,
	an increment is passed and added to a counter maintained here.  SpinCursor is provided for
	those users who do not happen to have a convenient counter handy but still want to use the
	spinning cursor.  A positive increment sequences forward through the cursors (rotating the
	cursor clockwise), and a negative increment sequences backward through the cursors (rotating
	the cursor counterclockwise).  A zero value for the increment resets the counter to zero.
	Note, it is the increment, and not the value of the counter that determines the sequencing
	direction of the cursor (and hence the spin direction of the cursor).
*/

extern pascal void Hide_Cursor();/*

	Hides the current character of the spinning cursor.  Use this routine when you wish to
	revert to the standard inverse space cursor.
*/

/************************************************************

	ErrMgr.h - //GS equivalent of the MPW Error Manager

************************************************************/

extern void InitErrMgr(/* toolErrFilename, sysErrFilename, showToolErrNbrs */);
/*	char	*toolErrFilename;
	char	*sysErrFilename;
	boolean	showToolErrNbrs;

	Initializes the error manager.  If toolErrFilename is not null, this will open the resource fork
	of that file to allow access to tool-specific error messages.  If sysErrFilename is not null,
	this will open the resource fork of that file instead of the standard APW error message file.
	If showToolErrNbrs is TRUE, then any call to GetSysErrText will show the decimal and hexadecimal
	error number in parentheses after the text of the error message.  If this is false, all that
	GetSysErrText will provide is the text of the message.
	
	To use the error manager, your tool must start up the Resource Manager prior to calling
	InitErrMgr.  This function will NOT do it for you.
*/

extern void CloseErrMgr();
/*
	This simply closes any resources files opened by InitErrMgr.  It is not absolutely required that
	you call this function prior to exiting your tool, but it is available.  If it is not called, the
	Resource Manager will automatically close any files opened.  You must shutdown the Resource
	Manager yourself.
*/

extern char *GetSysErrText(/* errNbr,errMsg */);
/*	unsigned	errNbr;
	StringPtr	errMsg;

	GetSysErrText performs a resource lookup for the supplied errNbr.  It does this by calculating
	which resource number to use from the system resource file or the tool-specific error file.  

	The function places the error message text in the buffer pointed to by errMsg, and also returns
	a pointer to a standard C string representing the error message associated with the given error
	number.  If there is message text available for the given error number, the string will have
	the following format:

		### {tool name}: {message text}
	
	If no specific message is available, the string will have the following format:

		### {tool name}: Error {decimal error number} ($xxxx)

	where $xxxx is the hexadecimal error code.
*/

/************************************************************

	gsString.h - header file for GS/OS string support functions

************************************************************/

#ifdef	__GSOS__

extern	GSString255	*c2gsstr(/* str, pathGS */);
/*	char		*str;
	GSString255	*pathGS;
	
	This function accepts a null terminated C string and copies it to a
	GS/OS-style string (length word followed by the characters of the string).
	On return, the function returns the pointer to the pathname structure
*/

extern	char *gs2cstr(/* pathGS, str */);
/*	GSString255	pathGS;
	char		*str;
	
	This function converts a GS/OS-style string (word length followed by the
	characters of the string) to a normal, null terminated C string.  On exit
	it returns a pointer to the string (which is the same as that specified
	on entry).
*/

extern void colonize(/* fileName */);
/*	char	*fileName;

	normalizes a filename string so that it contains only colons as pathname
	separators.  If there are no separators in the filename, the name is left
	unchanged.  If the filename contains no slashes, the filename is left
	unchanged.
*/
#endif

/************************************************************

	pause.h - header file for APW-compatible pause function

************************************************************/

extern int pause();
/*
	This function should be called periodically by an APW tool to check for
	a pending keypress and/or command-. (abort signal).  If the command-.
	keypress is pending, the function will return a non-zero value
	(signifying TRUE).  If any other keypress is pending, the function
	will display an hourglass character on the screen and pause until
	another key is pressed.
	
	The value returned is either non-zero (TRUE), indicating that command-.
	has been pressed and the tool should abort, or 0 (false), indicating
	that processing should proceed.
*/

extern int wait();
/*
	This function operates similarly to the pause() function, except that
	it forces a keypress prior to returning to the caller.  That is, it
	waits in a loop until a keypress occurs.  The values returned are the 
	same as described for the pause() function.
*/
#endif
