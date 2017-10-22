/****************************************************************
*
*  limits.h - limits on the size of numbers
*
*  April 1989
*  Mike Westerfield
*
*  Copyright 1989
*  Byte Works, Inc.
*
****************************************************************/

#ifndef __limits__
#define __limits__

#define CHAR_BIT        8
#define CHAR_MAX        255u
#define CHAR_MIN        0
#define SHRT_MAX        32767
#define SHRT_MIN        (-32767-1)
#define INT_MAX         32767
#define INT_MIN         (-32767-1)
#define LONG_MAX        2147483647
#define LONG_MIN        (-2147483647-1)
#define MB_LEN_MAX      1
#define SCHAR_MAX       127
#define SCHAR_MIN       (-128)
#define UCHAR_MAX       255u
#define UINT_MAX        65535u
#define ULONG_MAX       4294967295u
#define USHRT_MAX       65535u

#endif