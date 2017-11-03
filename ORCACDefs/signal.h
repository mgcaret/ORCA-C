/****************************************************************
*
*  signal.h - signal handling
*
*  April 1990
*  Mike Westerfield
*
*  Copyright 1990
*  Byte Works, Inc.
*
****************************************************************/

#ifndef __signal__
#define __signal__

typedef int sig_atomic_t;
typedef void (*__SIG_FUNC__) (int);

#define SIG_DFL ((__SIG_FUNC__) (-3))
#define SIG_IGN ((__SIG_FUNC__) (-2))
#define SIG_ERR ((__SIG_FUNC__) (-1))

#define SIGABRT 1
#define SIGFPE  2
#define SIGILL  3
#define SIGINT  4
#define SIGSEGV 5
#define SIGTERM 6

void            (*signal(int, void (*__func) (int)))(int);
int             raise(int);

#endif
