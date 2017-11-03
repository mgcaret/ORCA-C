/********************************************
; File: SANE.h
;
;
; Copyright Apple Computer, Inc.1986-90
; All Rights Reserved
;
********************************************/
#ifndef __TYPES__
#include <TYPES.h>
#endif

#ifndef __SANE__
#define __SANE__


/* Decimal Representation Constants */
#define SIGDIGLEN 0x001C
#define DECSTROUTLEN 0x0050

/* IEEE defualt environment constant */
#define IEEEDEFAULTENV 0x0000

/* Decimal formatting styles */
#define FLOATDECIMAL 0x0000
#define FIXEDDECIMAL 0x0001

/* Exceptions */
#define INVALID 0x0001
#define UNDERFLOW 0x0002
#define OVERFLOW 0x0004
#define DIVBYZERO 0x0008
#define INEXACT 0x0010

/* Ordering relations */
#define GREATERTHAN 0
#define LESSTHAN 1
#define EQUALTO 2
#define UNORDERED 3
typedef short relop ;


/* Inquiry classes */
#define SNAN 0
#define QNAN 1
#define INFINITE 2
#define ZERONUM 3
#define NORMALNUM 4
#define DENORMALNUM 5
typedef short numclass ;


/* Environmental control */

/* Rounding directions */
#define TONEAREST 0
#define UPWARD 1
#define DOWNWARD 2
#define TOWARDZERO 3
typedef short rounddir ;


/* Rounding precisions */
#define EXTPRECISION 0
#define DBLPRECISION 1
#define FLOATPRECISION 2
typedef short roundpre ;

typedef short exception;
typedef short environment;
typedef struct decimal {
   short sgn;             /* sign 0 for +, 1 for - */
   short exp;             /* decimal exponent */
   struct {
           unsigned char length, text[SIGDIGLEN], unused;
        } sig;                 /* significant digits */
} decimal, Decimal;

struct decform {
   short style; /* FLOATDECIMAL or FIXEDDECIMAL  */
   short digits;
} ;
typedef struct decform decform;
typedef struct decform DecForm;
typedef void (*haltvector)(void);

Extended  fabs (Extended  x) ;



/* Conversions between binary and decimal */
void  num2dec (DecForm  *f,extended  x,Decimal  *d) ;
/* d <-- x according to format f */

Extended  dec2num (Decimal  *d) ;
/* Dec2Num <-- d as Extended */


/* Conversions between decimal formats */
void str2dec (char *s,short *index,Decimal *d,short *validPrefix) ;
/* On input Index is starting index into s.
On output Index is one greater than index of last character of longest numeric substring.
d <-- Decimal rep of longest numeric substring;
validPrefix <-- s, beginning at Index, contains valid numeric string or valid prefix of some numeric string */
void  dec2str (DecForm  *f,Decimal  *d,char  *s) ;
/* s <-- d according to format f */


/* Arithmetic, auxiliary and elementary functions */
Extended  remainder (Extended  x,Extended  y,short  *quo) ;
/* Remainder <-- x rem y; */
/* quo <-- 7 low-order bits of integer quotient x/y */
/* where -127 < quo < 127 */

Extended  sqrt (Extended  x) ;
/* square root */

Extended  rint (Extended  x) ;
/* round to integral value */

Extended  scalb (short  n,Extended x) ;
/* scale binary; scalb <-- x * 2^n */

Extended  logb (Extended  x) ;
/* binary log: binary exponent of normalized x */

Extended  copysign (Extended  x,Extended  y) ;
/* CopySign <-- y with sign of x */

Extended  nextfloat (Extended  x,Extended  y) ;
/* next float rep after (float) x in direction of (float) y */

Extended  nextdouble (Extended  x,Extended  y) ;
/* next Double rep after (Double) x in direction of (Double) y */

Extended  nextextended (Extended  x,Extended  y) ;
/* next extended representation after x in direction of y */

Extended  log2 (Extended  x) ;
/* base-2 logarithm */

Extended  log (Extended  x) ;
/* base-e logarithm */

Extended  log1 (Extended  x) ;
/* log(1 + x) */

Extended  exp2 (Extended  x) ;
/* base-2 exponential */

Extended  exp (Extended  x) ;
/* base-e exponential */

Extended  exp1 (Extended  x) ;
/* exp(x) - 1 */

Extended  power (Extended  x,Extended  y) ;
/* general exponential: x ^ y */

Extended  ipower (Extended  x,short  i) ;
/* integer exponential: x ^ i */

Extended  compound (Extended  r,Extended  n) ;
/* compound: (1 + r) ^ n */

Extended  annuity (Extended  r,Extended  n) ;
/* Annuity <-- (1 - (1+r)^(-n)) / r */

Extended  tan (Extended  x) ;
/* tangent */

Extended  sin (Extended  x) ;
/* Sine */

Extended  cos (Extended  x) ;
/* Cosine */

Extended  atan (Extended  x) ;
/* Arctangent */

Extended  randomx (Extended  *x) ;
/* returns next random number; updates x; */
/* x must be integral, 1 <= x <= 2^31 - 2 */


/* Inquiry Routines */
numclass  classfloat (Extended  x) ;
/* class of (float) x */

numclass  classdouble (Extended  x) ;
/* class of (Double) x */

numclass  classcomp (Extended  x) ;
/* class of (Comp) x */

numclass  classextended (Extended  x) ;
/* class of x */

LongWord  signnum (Extended  x) ;
/* 0 if sign bit clear, 1 if sign bit set */


/* Environment access routines */
void  setexception (exception  e,long  b) ;
/* clears e flags if b is 0, sets e flags otherwise; may cause halt */

long  testexception (exception  e) ;
/* return true if any e flag is set, return false otherwise */

void  sethalt (exception  e,long  b) ;
/* set e halt enables if b is true, clear e halt enables otherwise */

long  testhalt (exception  e) ;
/* return true if any e halt is enabled, return false otherwise */

void  setround (rounddir  r) ;
/* set rounding direction to r */

rounddir  getround (void) ;
/* return rounding direction */

void  setprecision (roundpre  p) ;
/* sets rnd'n precision to p */

roundpre  getprecision (void) ;


void  setenvironment (environment  e) ;
/* sets SANE environment to e */

void  getenvironment (environment  *e) ;
/* e <-- SANE environment */

void  procentry (environment  *e) ;
/* e <-- environment;  environment <-- IEEE default env */

void  procexit (environment  e) ;
/* temp <-- current exceptions; */
/* SANE environment <-- e; */
/* signals exceptions in temp */

haltvector  gethaltvector (void) ;
/* return SANE halt vector */

void  sethaltvector (haltvector  v) ;
/* halt vector <-- v */


/* Comparison routine */
relop  relation (Extended  x,Extended  y) ;
/* return Relation such that "x Relation y" is true */


/* NaNs and Special Constants */
extended nan( unsigned char c );   /* returns NaN with code c */

Extended  inf (void) ;
/* returns infinity */

Extended  pi (void) ;
/* returns pi */

extern pascal void SANEBootInit() inline(0x010A,dispatcher);
extern pascal void SANEStartUp() inline(0x020A,dispatcher);
extern pascal void SANEShutDown() inline(0x030A,dispatcher);
extern pascal Word SANEVersion() inline(0x040A,dispatcher);
extern pascal void SANEReset() inline(0x050A,dispatcher);
extern pascal Word SANEStatus() inline(0x060A,dispatcher);
extern pascal void SANEFP816() inline(0x090A,dispatcher);
extern pascal void SANEDecStr816() inline(0x0A0A,dispatcher);
extern pascal void SANEElems816() inline(0x0B0A,dispatcher);
#endif
