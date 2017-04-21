/* Copyright (C) 2003 DJ Delorie, see COPYING.DJ for details */
/* Copyright (C) 1996 DJ Delorie, see COPYING.DJ for details */
/* Copyright (C) 1995 DJ Delorie, see COPYING.DJ for details */
//#include <ctype.h>

#ifndef __dj_include_sys_termios_h_
#define __dj_include_sys_termios_h_

#ifndef _TERMIOS_
#define _TERMIOS_
//ppc ansi.h
#ifndef _ANSI_H_
#define _ANSI_H_

#define _BSD_CLOCK_T_ unsigned long
#if defined(__GNUC__) && defined(__PTRDIFF_TYPE__) && defined(__SIZE__TYPE__)
#define _BSD_PTRDIFF_T_ __PTRDIFF_TYPE__
#define _BSD_SIZE_T_    __SIZE_TYPE__
#else
#define _BSD_PTRDIFF_T_ int
#define _BSD_SIZE_T_ unsigned long

#define _BSD_SSIZE_T_ int
#define _BSD_TIME_T_ long
#define _BSD_VA_LIST_ void *//need to continue adding in ppc ansi.h

#if defined(__GNUC__) && defined(__WCHAR_TYPE__)
#define _BSD_WCHAR_T_  __WCHAR_TYPE__
#define _BSD_RUNE_T_   __WCHAR_TYPE__
#else
#define _BSD_WCHAR_T_ int
#define _BSD_RUNE_T_  int
//end of ppc ansi.h

//i386 ansi.h
#ifndef _ANSI_H_
#define _ANSI_H_

#define _BSD_CLOCK_T_ unsigned long
#define	_BSD_PTRDIFF_T_	int			/* ptr1 - ptr2 */
#define	_BSD_SIZE_T_	unsigned int		/* sizeof() */
#define	_BSD_SSIZE_T_	int			/* byte count or error */
#define	_BSD_TIME_T_	long			/* time() */
#define	_BSD_VA_LIST_	char *

#define	_BSD_WCHAR_T_	int			/* wchar_t */
#define	_BSD_RUNE_T_	int			/* rune_t */
//end of i386 ansi.h

//machine ansi.h
#ifndef _MACHINE_ANSI_H_
#define _MACHINE_ANSI_H_

#if defined (__ppc__)

#elif defined (__i386__)

#else
#error architexture not supported
#endif

//end of machine ansi.h

//start of cdefs.h
#ifndef _SYS_CDEFS_H
#define _SYS_CDEFS_H

#if defined(__cplusplus)
#define __BEGIN_DECALS extern "C" {
#define __END_DECLS};
#else
#define __BEGIN_DECLS
#define __END_DECLS

#if defined(__STDC__) || defined(__cplusplus)
#define __P(protos) protos
#define __CONCAT(x,y) x ## y
#define __STRING(x) #x

#ifdef __GNUC__
#define const   __const
#define inline   __inline
#define signed   __signed
#define volatile  __volatile

#else
#define const
#define inline
#define signed
#define volatile

#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define __dead __volatile
#define __pure __const
#else
#define __dead
#define __pure


//end of cdefs.h
//start of runetype.h
#ifndef _RUNETYPE_H_
#define _RUNETYPE_H_

#ifndef _BSD_SIZE_T_DEFINED_
#define _BSD_SIZE_T_DEFINED_
typedef _BSD_SIZE_T_DEFINED_ size_t;//continue runetype.h

#ifndef _BSD_CT_RUNE_T_DEFINED_
#define _BSD_CT_RUNE_T_DEFINED_
typedef _BSD_CT_RUNE_T_ ct_rune_t;
#endif // _BSD_CT_RUNE_T_DEFINED_

#ifndef	_BSD_RUNE_T_DEFINED_
#define _BSD_RUNE_T_DEFINED_
typedef	_BSD_RUNE_T_	rune_t;
#endif

#ifndef	__cplusplus
#ifndef	_BSD_WCHAR_T_DEFINED_
#define	_BSD_WCHAR_T_DEFINED_
#ifdef	__WCHAR_TYPE__
typedef	__WCHAR_TYPE__	wchar_t;
#else	/* ! __WCHAR_TYPE__ */
typedef	_BSD_WCHAR_T_	wchar_t;
#endif	/* __WCHAR_TYPE__ */
#endif	/* _BSD_WCHAR_T_DEFINED_ */
#endif	/* __cplusplus */

#ifndef	_BSD_WINT_T_DEFINED_
#define _BSD_WINT_T_DEFINED_
typedef	_BSD_WINT_T_	wint_t;
#endif

#define	_CACHED_RUNES	(1 <<8 )	/* Must be a power of 2 */
#define	_CRMASK		(~(_CACHED_RUNES - 1))

typedef struct {
	rune_t		min;		/* First rune of the range */
	rune_t		max;		/* Last rune (inclusive) of the range */
	rune_t		map;		/* What first maps to in maps */
	unsigned long	*types;		/* Array of types in range */
} _RuneEntry;

typedef struct {
	int		nranges;	/* Number of ranges stored */
	_RuneEntry	*ranges;	/* Pointer to the ranges */
} _RuneRange;

typedef struct {
	char		magic[8];	/* Magic saying what version we are */
	char		encoding[32];	/* ASCII name of this encoding */

	rune_t		(*sgetrune)
	   (const char *, size_t, char const **);
	int		(*sputrune)
	   (rune_t, char *, size_t, char **);
	rune_t		invalid_rune;

	unsigned long	runetype[_CACHED_RUNES];
	rune_t		maplower[_CACHED_RUNES];
	rune_t		mapupper[_CACHED_RUNES];

	/*
	 * The following are to deal with Runes larger than _CACHED_RUNES - 1.
	 * Their data is actually contiguous with this structure so as to make
	 * it easier to read/write from/to disk.
	 */
	_RuneRange	runetype_ext;
	_RuneRange	maplower_ext;
	_RuneRange	mapupper_ext;

	void		*variable;	/* Data which depends on the encoding */
	int		variable_len;	/* how long that data is */
} _RuneLocale;

#define	_RUNE_MAGIC_1	"RuneMagi"	/* Indicates version 0 of RuneLocale */

__BEGIN_DECLS
extern _RuneLocale _DefaultRuneLocale;
extern _RuneLocale *_CurrentRuneLocale;
__END_DECLS













//end of runetype.h
#ifndef _CTYPE_H_
#define _CTYPE_H_

#define	_A	0x00000100L		/* Alpha */
#define	_C	0x00000200L		/* Control */
#define	_D	0x00000400L		/* Digit */
#define	_G	0x00000800L		/* Graph */
#define	_L	0x00001000L		/* Lower */
#define	_P	0x00002000L		/* Punct */
#define	_S	0x00004000L		/* Space */
#define	_U	0x00008000L		/* Upper */
#define	_X	0x00010000L		/* X digit */
#define	_B	0x00020000L		/* Blank */
#define	_R	0x00040000L		/* Print */
#define	_I	0x00080000L		/* Ideogram */
#define	_T	0x00100000L		/* Special */
#define	_Q	0x00200000L		/* Phonogram */

#define _CTYPE_A	_A
#define _CTYPE_C	_C
#define _CTYPE_D	_D
#define _CTYPE_G	_G
#define _CTYPE_L	_L
#define _CTYPE_P	_P
#define _CTYPE_S	_S
#define _CTYPE_U	_U
#define _CTYPE_X	_X
#define _CTYPE_B	_B
#define _CTYPE_R	_R
#define _CTYPE_I	_I
#define _CTYPE_T	_T
#define _CTYPE_Q	_Q

__BEGIN_DECLS
int     isalnum __P((int));
int     isalpha __P((int));
int     iscntrl __P((int));
int     isdigit __P((int));
int     isgraph __P((int));
int     islower __P((int));
int     isprint __P((int));
int     ispunct __P((int));
int     isspace __P((int));
int     isupper __P((int));
int     isxdigit __P((int));
int     tolower __P((int));
int     toupper __P((int));

#if !defined(_ANSI_SOURCE) && !defined(_POSIX_SOURCE)
int     digittoint __P((int));
int     isascii __P((int));
int     isblank __P((int));
int     ishexnumber __P((int));
int     isideogram __P((int));
int     isnumber __P((int));
int     isphonogram __P((int));
int     isrune __P((int));
int     isspecial __P((int));
int     toascii __P((int));
#endif
__END_DECLS

#define isalnum(c)      __istype((c), (_A|_D))
#define isalpha(c)      __istype((c),     _A)
#define iscntrl(c)      __istype((c),     _C)
#define isdigit(c)      __isctype((c),    _D)	/* ANSI -- locale independent */
#define isgraph(c)      __istype((c),     _G)
#define islower(c)      __istype((c),     _L)
#define isprint(c)      __istype((c),     _R)
#define ispunct(c)      __istype((c),     _P)
#define isspace(c)      __istype((c),     _S)
#define isupper(c)      __istype((c),     _U)
#define isxdigit(c)     __isctype((c),    _X)	/* ANSI -- locale independent */
#define tolower(c)      __tolower(c)
#define toupper(c)      __toupper(c)

#if !defined(_ANSI_SOURCE) && !defined(_POSIX_SOURCE)
#define	digittoint(c)	__maskrune((c), 0xFF)
#define	isascii(c)	((c & ~0x7F) == 0)
#define isblank(c)	__istype((c), _B)
#define	ishexnumber(c)	__istype((c), _X)
#define	isideogram(c)	__istype((c), _I)
#define	isnumber(c)	__istype((c), _D)
#define	isphonogram(c)	__istype((c), _T)
#define	isrune(c)	__istype((c),  0xFFFFFF00L)
#define	isspecial(c)	__istype((c), _Q)
#define toascii(c)	((c) & 0x7F)
#endif

/* See comments in <machine/ansi.h> about _BSD_RUNE_T_. */
__BEGIN_DECLS
unsigned long	___runetype __P((_BSD_CT_RUNE_T_));
_BSD_CT_RUNE_T_	___tolower __P((_BSD_CT_RUNE_T_));
_BSD_CT_RUNE_T_	___toupper __P((_BSD_CT_RUNE_T_));
__END_DECLS

#ifdef _EXTERNALIZE_CTYPE_INLINES_
#define _USE_CTYPE_INLINE_
#define static
#define __inline
#endif

#if !defined(_DONT_USE_CTYPE_INLINE_) && \
    (defined(_USE_CTYPE_INLINE_) || defined(__GNUC__) || defined(__cplusplus))

static __inline int
__maskrune(_BSD_CT_RUNE_T_ _c, unsigned long _f)
{
	return ((_c < 0 || _c >= _CACHED_RUNES) ? ___runetype(_c) :
		_CurrentRuneLocale->runetype[_c]) & _f;
}

static __inline int
__istype(_BSD_CT_RUNE_T_ c, unsigned long f)
{
	return !!(__maskrune(c, f));
}

static __inline _BSD_CT_RUNE_T_
__isctype(_BSD_CT_RUNE_T_ _c, unsigned long _f)
{
	return (_c < 0 || _c >= _CACHED_RUNES) ? 0 :
		!!(_DefaultRuneLocale.runetype[_c] & _f);
}

static __inline _BSD_CT_RUNE_T_
__toupper(_BSD_CT_RUNE_T_ _c)
{
	return (_c < 0 || _c >= _CACHED_RUNES) ? ___toupper(_c) :
		_CurrentRuneLocale->mapupper[_c];
}

static __inline _BSD_CT_RUNE_T_
__tolower(_BSD_CT_RUNE_T_ _c)
{
	return (_c < 0 || _c >= _CACHED_RUNES) ? ___tolower(_c) :
		_CurrentRuneLocale->maplower[_c];
}

#else /* not using inlines */

__BEGIN_DECLS
int             __maskrune __P((_BSD_CT_RUNE_T_, unsigned long));
int		__istype  __P((_BSD_CT_RUNE_T_, unsigned long));
int             __isctype __P((_BSD_CT_RUNE_T_, unsigned long));
_BSD_CT_RUNE_T_ __toupper __P((_BSD_CT_RUNE_T_));
_BSD_CT_RUNE_T_ __tolower __P((_BSD_CT_RUNE_T_));
__END_DECLS


















//end of ctype.h

//start of sys/cdefs.h

#ifndef _CDEFS_H_
#define _CDEFS_H_

#if defined(__cplusplus)
#define	__BEGIN_DECLS	extern "C" {
#define	__END_DECLS	};
#else
#define	__BEGIN_DECLS
#define	__END_DECLS
#endif

#if defined(__STDC__) || defined(__cplusplus)
#define	__P(protos)	protos		/* full-blown ANSI C */
#define	__CONCAT(x,y)	x ## y
#define	__STRING(x)	#x

#else	/* !(__STDC__ || __cplusplus) */
#define	__P(protos)	()		/* traditional C preprocessor */
#define	__CONCAT(x,y)	x/**/y
#define	__STRING(x)	"x"

#ifdef __GNUC__
#define	const		__const		/* GCC: ANSI C with -traditional */
#define	inline		__inline
#define	signed		__signed
#define	volatile	__volatile

#else	/* !__GNUC__ */
#define	const				/* delete ANSI C keywords */
#define	inline
#define	signed
#define	volatile

#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define __dead __volatile
#define __pure __const
#else
#define __dead
#define __pure






//end of sys/cdefs.h
//start of sdkddkver.h

#ifndef _SDKDDKVER_H
#define _SDKDDKVER_H
#pragma GCC system_header

#define OSVERSION_MASK            0xFFFF0000
#define SPVERSION_MASK            0x0000FF00
#define SUBVERSION_MASK           0x000000FF

#define OSVER(ver) ((ver) & OSVERSION_MASK)
#define SPVER(ver) (((ver) & SPVERSION_MASK) >> 8)
#define SUBVER(ver) ((ver) & SUBVERSION_MASK)
#define WINNTVER(ver) ((ver) / 0x00010000)

#define NTDDI_VERSION_FROM_WIN32_WINNT(ver) _NTDDI_VERSION_FROM_WIN32_WINNT(ver)
#define _NTDDI_VERSION_FROM_WIN32_WINNT(ver) ver##0000

#define _WIN32_WINNT_NT4          0x0400
#define _WIN32_WINNT_NT4E	  0x0401
#define _WIN32_WINNT_WIN95	  0x0400
#define _WIN32_WINNT_WIN98	  0x0410
#define _WIN32_WINNT_WINME	  0x0490
#define _WIN32_WINNT_WIN2K        0x0500
#define _WIN32_WINNT_WINXP        0x0501
#define _WIN32_WINNT_WS03         0x0502
#define _WIN32_WINNT_WIN6         0x0600
#define _WIN32_WINNT_VISTA        0x0600
#define _WIN32_WINNT_WS08         0x0600
#define _WIN32_WINNT_LONGORN      0x0600
#define _WIN32_WINNT_WIN7         0x0601

#define _WIN32_IE_IE50            0x0500
#define _WIN32_IE_IE501           0x0501
#define _WIN32_IE_IE55            0x0550
#define _WIN32_IE_IE60            0x0600
#define _WIN32_IE_IE60SP1         0x0601
#define _WIN32_IE_IE60SP2         0x0603
#define _WIN32_IE_IE70            0x0700
#define _WIN32_IE_IE80            0x0800

#define __NTDDI_WIN5               0x05000000
#define __NTDDI_WIN51              0x05010000
#define __NTDDI_WIN52              0x05020000
#define __NTDDI_WIN6               0x06000000
#define __NTDDI_WIN61              0x06010000
#define __NTDDI_SP0                0x00000000
#define __NTDDI_SP1                0x00000100
#define __NTDDI_SP2                0x00000200
#define __NTDDI_SP3                0x00000300
#define __NTDDI_SP4                0x00000400

#define NTDDI_WIN2K               __NTDDI_WIN5 + __NTDDI_SP0
#define NTDDI_WIN2KSP1            __NTDDI_WIN5 + __NTDDI_SP1
#define NTDDI_WIN2KSP2            __NTDDI_WIN5 + __NTDDI_SP2
#define NTDDI_WIN2KSP3            __NTDDI_WIN5 + __NTDDI_SP3
#define NTDDI_WIN2KSP4            __NTDDI_WIN5 + __NTDDI_SP4

#define NTDDI_WINXP               __NTDDI_WIN51 + __NTDDI_SP0
#define NTDDI_WINXPSP1            __NTDDI_WIN51 + __NTDDI_SP1
#define NTDDI_WINXPSP2            __NTDDI_WIN51 + __NTDDI_SP2
#define NTDDI_WINXPSP3            __NTDDI_WIN51 + __NTDDI_SP3

#define NTDDI_WS03                __NTDDI_WIN52 + __NTDDI_SP0
#define NTDDI_WS03SP1             __NTDDI_WIN52 + __NTDDI_SP1
#define NTDDI_WS03SP2             __NTDDI_WIN52 + __NTDDI_SP2

#define NTDDI_VISTA               __NTDDI_WIN6 + __NTDDI_SP0
#define NTDDI_VISTASP1            __NTDDI_WIN6 + __NTDDI_SP1
#define NTDDI_VISTASP2		  __NTDDI_WIN6 + __NTDDI_SP2

#define NTDDI_LONGHORN            NTDDI_VISTA

#define NTDDI_WIN6                NTDDI_VISTA
#define NTDDI_WIN6SP1             NTDDI_VISTASP1
#define NTDDI_WIN6SP2		  NTDDI_VISTASP2

#define NTDDI_WS08                __NTDDI_WIN6 + __NTDDI_SP1

#define NTDDI_WIN7                __NTDDI_WIN61 + __NTDDI_SP0

#ifdef NTDDI_VERSION
#  ifdef _WIN32_WINNT
#    if _WIN32_WINNT != OSDIR(NTDDI_VERSION)
#      error The _WIN32_WINNT value does not match NTDDI_VERSION
#    endif
#  else
#    define _WIN32_WINNT WINNTVER(NTDDI_VERSION)
#    ifndef WINVER
#      define WINVER _WIN32_WINNT
#    endif
#  endif
#endif

#ifndef _WIN32_WINNT
#  ifdef WINVER
#    define _WIN32_WINNT WINVER
#  else
#    ifdef _WARN_DEFAULTS
#      warning _WIN32_WINNT is defaulting to _WIN32_WINNT_WIN2K
#    endif
#    define _WIN32_WINNT _WIN32_WINNT_WIN2K
#  endif
#endif

#ifndef WINVER
#  define WINVER _WIN32_WINNT
#endif

#ifndef NTDDI_VERSION
#  ifdef _WARN_DEFAULTS
#    warning NTDDI_VERSION is defaulting to _WIN32_WINNT version SPK0
#  endif
#  define NTDDI_VERSION NTDDI_VERSION_FROM_WIN32_WINNT(_WIN32_WINNT)
#endif














//end of sdkddkver.h
#ifdef __cplusplus
extern "C" {
#endif

#ifndef __dj_ENFORCE_ANSI_FREESTANDING

#if (defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !defined(__STRICT_ANSI__) || defined(__cplusplus)

#endif /* (__STDC_VERSION__ >= 199901L) || !__STRICT_ANSI__ */

#ifndef __STRICT_ANSI__

#define B0	0x00000000 //00
#define B50	0x00000001
#define B75	0x00000002
#define B110	0x00000003
#define B134	0x00000004
#define B150	0x00000005
#define B200	0x00000006
#define B300	0x00000007
#define B600	0x00000008
#define B1200	0x00000009
#define B1800	0x0000000a
#define B2400	0x0000000b
#define B4800	0x0000000c
#define B9600	0x0000000d
#define B19200	0x0000000e
#define B38400	0x0000000f

#define BRKINT	0x00000100
#define ICRNL	0x00000200
#define IGNBRK	0x00000400
#define IGNCR	0x00000800
#define IGNPAR	0x00001000
#define INLCR	0x00002000
#define INPCK	0x00004000
#define ISTRIP	0x00008000
#define IXOFF	0x00010000
#define IXON	0x00020000
#define PARMRK	0x00040000

#define OPOST	0x00000100

#define CLOCAL	0x00000100
#define CREAD	0x00000200
#define CS5	0x00000000
#define CS6	0x00000400
#define CS7	0x00000800
#define CS8	0x00000c00
#define CSIZE	0x00000c00
#define CSTOPB	0x00001000
#define HUPCL	0x00002000
#define PARENB	0x00004000
#define PARODD	0x00008000

#define ECHO	0x00000100
#define ECHOE	0x00000200
#define ECHOK	0x00000400
#define ECHONL	0x00000800
#define ICANON	0x00001000
#define IEXTEN	0x00002000
#define ISIG	0x00004000
#define NOFLSH	0x00008000
#define TOSTOP	0x00010000

#define TCIFLUSH	1
#define TCOFLUSH	2
#define TCIOFLUSH	3
#define TCOOFF		1
#define TCOON		2
#define TCIOFF		3
#define TCION		4

#define TCSADRAIN	1
#define TCSAFLUSH	2
#define TCSANOW		3

#define VEOF	1
#define VEOL	2
#define VERASE	3
#define VINTR	4
#define VKILL	5
#define VMIN	6
#define VQUIT	7
#define VSTART	8
#define VSTOP	9
#define VSUSP	10
#define VTIME	11
#define NCCS	12

typedef unsigned cc_t;
typedef unsigned speed_t;
typedef unsigned tcflag_t;

namespace Termo{

class Termios {
 public:
        ~Termios();
        void box_Const();

};

Termio::box_Const(){
                    const int box0[2] {4, 30};
const int box1[4] {4, 30, 4, 32};
const int box2[4] {4, 30, 5, 32};
const int box3[6] {4, 28, 4, 30, 4, 32};
const int box4[6] {4, 28, 4, 30, 5, 30};
const int box5[6] {4, 28, 5, 30, 6, 32};
const int box6[6] {4, 30, 5, 28, 5, 32};
const int box7[8] {4, 28, 5, 30, 6, 32, 7, 34};
const int box8[8] {4, 30, 5, 28, 5, 30, 5, 32};
const int box9[8] {4, 30, 5, 28, 5, 32, 6, 30};
const int box10[8] {4, 28, 4, 30, 4, 32, 4, 34};
const int box11[8] {4, 28, 5, 28, 5, 30, 5, 32};
const int box12[8] {4, 28, 4, 30, 5, 30, 5, 32};
const int box13[8] {4, 28, 4, 30, 5, 28, 5, 30};
const int box14[8] {4, 28, 4, 34, 5, 30, 5, 32};
const int box15[10] {4, 26, 4, 28, 4, 30, 4, 32, 4, 34};
const int box16[10] {4, 30, 5, 28, 5, 30, 5, 32, 6, 30};
const int box17[10] {4, 28, 4, 32, 5, 30, 6, 28, 6, 32};
const int box18[10] {4, 28, 4, 32, 5, 28, 5, 30, 5, 32};
const int box19[10] {4, 28, 4, 30, 5, 30, 6, 30, 6, 32};
const int box20[10] {4, 28, 5, 28, 6, 28, 6, 30, 6, 32};
const int box21[10] {4, 28, 4, 30, 5, 30, 5, 32, 6, 32};
const int box22[10] {4, 26, 4, 34, 5, 28, 5, 30, 5, 32};
const int box23[10] {4, 26, 4, 34, 5, 28, 5, 32, 6, 30};
const int box24[10] {4, 26, 5, 28, 6, 30, 7, 32, 8, 34};
const int box25[10] {4, 28, 4, 32, 5, 26, 5, 30, 5, 34};
const int box26[16] {4, 28, 4, 34, 5, 30, 5, 32, 6, 30, 6, 32, 7, 28, 7, 34};
const int box27[18] {4, 30, 5, 28, 5, 32, 6, 26, 6, 30, 6, 34, 7, 28, 7, 32, 8, 30};
const int box28[26] {4, 30, 5, 28, 5, 30, 5, 32, 6, 26, 6, 28, 6, 30, 6, 32, 6, 34, 7, 28, 7, 30, 7, 32, 8, 30};
const int box29[26] {4, 30, 5, 30, 6, 28, 6, 30, 6, 32, 7, 26, 7, 30, 7, 34, 8, 30, 9, 30, 10, 30, 11, 30, 12, 30};
const int box30[34] {4, 26, 4, 28, 4, 30, 4, 34, 5, 30, 5, 34, 6, 26, 6, 28, 6, 30, 6, 32, 6, 34, 7, 26, 7, 30, 8, 26, 8, 30, 8, 32, 8, 34};
const int box31[34] {4, 30, 5, 28, 6, 26, 6, 34, 7, 28, 7, 32, 7, 36, 8, 22, 8, 30, 8, 38, 9, 24, 9, 28, 9, 32, 10, 26, 10, 34, 11, 32, 12, 30};
const int length[32] {2, 4, 4, 6, 6, 6, 6, 8, 8, 8, 8, 8, 8, 8, 8, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 16, 18, 26, 26, 34, 34};
const int* BOX[32] {box0, box1, box2, box3, box4, box5, box6, box7, box8, box9, box10, box11, box12, box13, box14, box15,
                    box16, box17, box18, box19, box20, box21, box22, box23, box24, box25, box26, box27, box28, box29, box30, box31};
const int toph = 3;
const int modw = 4;
}


struct termios {
  cc_t		c_cc[NCCS];
  tcflag_t	c_cflag;
  tcflag_t	c_iflag;
  tcflag_t	c_lflag;
  tcflag_t	c_oflag;
  speed_t	c_ispeed;
  speed_t	c_ospeed;
};

speed_t	cfgetispeed(const struct termios *_termios_p);
speed_t	cfgetospeed(const struct termios *_termios_p);
int	cfsetispeed(struct termios *_termios_p, speed_t _speed);
int	cfsetospeed(struct termios *_termios_p, speed_t _speed);
int	tcdrain(int _fildes);
int	tcflow(int _fildes, int _action);
int	tcflush(int _fildes, int _queue_selector);
int	tcgetattr(int _fildes, struct termios *_termios_p);
int	tcsendbreak(int _fildes, int _duration);
int	tcsetattr(int _fildes, int _optional_actions, const struct termios *_termios_p);

#ifndef _POSIX_SOURCE

/* Input flags */
#define IMAXBEL	0x01000000	/* ring bell on input queue full */

/* Local flags */
#define ECHOKE	0x01000000	/* visual erase for line kill */
#define ECHOCTL	0x02000000	/* echo control chars as ^x */

/* Output flags */
#define ONLCR	0x00000200	/* map NL to CRNL */
#define OCRNL	0x00000400	/* map CR to NL */
#define ONOEOT	0x00000800	/* discard EOT's (^D) on output */

/* for compatibility */
void	cfmakeraw(struct termios *_termios_p);
int	cfsetspeed(struct termios *_termios_p, speed_t _speed);
box_Const();//example of how to call our function
#endif /* !_POSIX_SOURCE */
#endif /* !__STRICT_ANSI__ */
#endif /* !__dj_ENFORCE_ANSI_FREESTANDING */

#ifndef __dj_ENFORCE_FUNCTION_CALLS
#endif /* !__dj_ENFORCE_FUNCTION_CALLS */

#ifdef __cplusplus
}
#endif

#endif /* !__dj_include_sys_termios_h_ */
#endif
#endif // __dj_include_sys_termios_h_
#endif
#endif
#endif // __dj_include_sys_termios_h_
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
#endif
