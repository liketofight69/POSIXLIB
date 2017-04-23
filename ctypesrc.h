/* Copyright (C) 2003 DJ Delorie, see COPYING.DJ for details */
/* Copyright (C) 1996 DJ Delorie, see COPYING.DJ for details */
/* Copyright (C) 1995 DJ Delorie, see COPYING.DJ for details */
//#include <ctype.h>
//start of custom_file.h
#ifndef __CUSTOM_FILE_H__
#define __CUSTOM_FILE_H__ 1
/*
 * Cell SPE support
 */
struct __sFILE_spu {
  int _fp; /* pseudo FILE pointer on PPE */
};
typedef struct __sFILE_spu __FILE;
#endif /* __CUSTOM_FILE_H__ */



//end of custom_file
//start of aio.h

#ifndef _AIO_H
#define _AIO_H	1













//start of aio.h
#ifndef _AIO_H
	#include <rt/aio.h>

	#ifndef _ISOMAC
	/* Now define the internal interfaces.  */
	extern void __aio_init (const struct aioinit *__init);

	/* Flag to signal we need to be compatible with glibc < 2.4 in
	   lio_listio and we do not issue events for each individual list
	   element.  */
	#define LIO_NO_INDIVIDUAL_EVENT        128
	#endif

	#endif









//end of aio.h
//start of assert.h
#ifndef _ASSERT_H
 #define _ASSERT_H

 #ifdef NDEBUG
 # define assert(EX)
 #else
 # define assert(EX) (void)((EX) || (__assert (#EX, __FILE__, __LINE__),0))
 #endif

 #ifdef __cplusplus
 extern "C" {
 #endif

 extern void __assert (const char *msg, const char *file, int line);

 #ifdef __cplusplus
 };
 #endif
 #endif








//end of assert.h
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
	int aio_fildes;
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
//start of _types.h

#ifndef _SYS__TYPES_H_
 #define _SYS__TYPES_H_

#ifndef _SIZE_T_DECLARED

#ifndef __size_t

typedef size_t __size_t;

#define _SIZE_T_DECLARED

typedef long __int32_t;
typedef long long __int64_t;
typedef short __int16_t;
typedef signed char __int8_t;

typedef unsigned long __uint32_t;
typedef unsigned long long __uint64_t;
typedef unsigned short __uint16_t;
typedef unsigned char __uint8_t;
typedef unsigned long u_int32_t;

typedef __int32_t       __clockid_t;
typedef __uint32_t      __fflags_t;     /* file flags */
 typedef __uint64_t      __fsblkcnt_t;
 typedef __uint64_t      __fsfilcnt_t;
 typedef __uint32_t      __gid_t;
 typedef __int64_t       __id_t;         /* can hold a gid_t, pid_t, or uid_t */
 typedef __uint32_t      __ino_t;        /* inode number */
 typedef long            __key_t;        /* IPC key (for Sys V IPC) */
 typedef __uint16_t      __mode_t;       /* permissions */
 typedef int             __nl_item;
 typedef __uint16_t      __nlink_t;      /* link count */
 typedef __int64_t       __off_t;        /* file offset */
 typedef __int32_t       __pid_t;        /* process [group] */
 typedef __int64_t       __rlim_t;       /* resource limit (XXX not unsigned) */
 typedef __uint8_t       __sa_family_t;
 typedef __uint32_t      __socklen_t;
 typedef long            __suseconds_t;  /* microseconds (signed) */
 typedef __int32_t       __timer_t;      /* timer_gettime()... */
 typedef __uint32_t      __udev_t;       /* device number */
 typedef __uint32_t      __uid_t;
 typedef unsigned int    __useconds_t;   /* microseconds (unsigned) */

typedef int             __ct_rune_t;
 typedef __ct_rune_t     __rune_t;
 typedef __ct_rune_t     __wchar_t;
 typedef __ct_rune_t     __wint_t;

#ifdef _KERNEL
 struct cdev;
 typedef struct cdev     *__dev_t;
 #else
 typedef __udev_t        __dev_t;                /* device number */
 #endif

typedef union {
         char            __mbstate8[128];
        __int64_t       _mbstateL;              /* for alignment */
 } __mbstate_t;














//end of _types.h
//start of stddef.h

#ifndef __STDDEF_H__
#define __STDDEF_H__

#ifndef _PTRDIFF_T_DECLARED
typedef	__osx_ptrdiff_t	ptrdiff_t;
#define _PTRDIFF_T_DECLARED
#endif

#ifndef	_BSD_SIZE_T_DEFINED_
#define	_BSD_SIZE_T_DEFINED_
typedef	__osx_size_t	size_t;
#endif

#ifndef	__cplusplus
#ifndef	_BSD_WCHAR_T_DEFINED_
#define	_BSD_WCHAR_T_DEFINED_
typedef	__osx_wchar_t	wchar_t;
#endif	/* _BSD_WCHAR_T_DEFINED_ */
#endif	/* __cplusplus */

#ifndef NULL
#define NULL __OSX_NULL
#endif /* ! NULL */

#ifndef __offsetof	/* Deprecated: for source compatability only */
#define __offsetof(type, field) ((size_t)(&((type *)0)->field))
#endif
#define offsetof(type, field) ((size_t)(&((type *)0)->field))









//end of stddef.h
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
//start of _mingw.h

#ifndef _MINGW_H
#define _MINGW_H
#pragma GCC system_header

#define __MINGW_VERSION             4.0
#define __MINGW_MAJOR_VERSION       4
#define __MINGW_MINOR_VERSION       0
#define __MINGW_PATCHLEVEL          0

#define __MINGW32_VERSION           3.20
#define __MINGW32_MAJOR_VERSION     3
#define __MINGW32_MINOR_VERSION     20
#define __MINGW32_PATCHLEVEL        0

#ifndef __GNUC__
#error ERROR: You must use a GNU Compiler.
#endif

#if (__GNUC__ < 3 || !defined(__GNUC_MINOR__) || (__GNUC__ == 3 && __GNUC_MINOR__ < 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4 && __GNUC_PATCHLEVEL__ < 5))
#error ERROR: You must use a GNU Compiler version >= 3.4.5.
#endif

#define __MINGW_ANSI_STDIO__		0x0000000000000001ULL

#define __MINGW_LC_EXTENSIONS__ 	0x0000000000000050ULL
#define __MINGW_LC_MESSAGES__		0x0000000000000010ULL
#define __MINGW_LC_ENVVARS__		0x0000000000000040ULL

#undef __attribute__

#ifndef __MINGW_IMPORT
  /* Note the extern. This is needed to work around GCC's
     limitations in handling dllimport attribute.  */
# define __MINGW_IMPORT  extern __attribute__ ((__dllimport__))
#endif
#ifndef _CRTIMP
# ifdef __USE_CRTIMP
#  define _CRTIMP  __attribute__ ((dllimport))
# else
#  define _CRTIMP
# endif
#endif

#ifndef __int64
# define __int64 long long
#endif
#ifndef __int32
# define __int32 long
#endif
#ifndef __int16
# define __int16 short
#endif
#ifndef __int8
# define __int8 char
#endif
#ifndef __small
# define __small char
#endif
#ifndef __hyper
# define __hyper long long
#endif

#define __MINGW_GNUC_PREREQ(major, minor) \
  (__GNUC__ > (major) \
   || (__GNUC__ == (major) && __GNUC_MINOR__ >= (minor)))

#ifdef __cplusplus
# define __CRT_INLINE inline
#else
# if __GNUC_STDC_INLINE__
#  define __CRT_INLINE extern inline __attribute__((__gnu_inline__))
# else
#  define __CRT_INLINE extern __inline__
# endif
#endif

#define _CRTALIAS __CRT_INLINE __attribute__ ((__always_inline__))

#ifdef __cplusplus
# define __UNUSED_PARAM(x)
#else
# define __UNUSED_PARAM(x) x __attribute__ ((__unused__))
#endif

#define __MINGW_ATTRIB_NORETURN __attribute__ ((__noreturn__))
#define __MINGW_ATTRIB_CONST __attribute__ ((__const__))
#define __MINGW_ATTRIB_MALLOC __attribute__ ((__malloc__))
#define __MINGW_ATTRIB_PURE __attribute__ ((__pure__))
#define __MINGW_ATTRIB_NONNULL(arg) __attribute__ ((__nonnull__ (arg)))
#define __MINGW_ATTRIB_DEPRECATED __attribute__ ((__deprecated__))
#define __MINGW_NOTHROW __attribute__ ((__nothrow__))

#ifndef __MSVCRT_VERSION__
/*  High byte is the major version, low byte is the minor. */
# define __MSVCRT_VERSION__ 0x0600
#endif

#ifndef __USE_MINGW_ANSI_STDIO

# if   defined __STRICT_ANSI__  ||  defined _ISOC99_SOURCE \
   ||  defined _POSIX_SOURCE    ||  defined _POSIX_C_SOURCE \
   ||  defined _XOPEN_SOURCE    ||  defined _XOPEN_SOURCE_EXTENDED \
   ||  defined _GNU_SOURCE      ||  defined _BSD_SOURCE \
   ||  defined _SVID_SOURCE

#  define __USE_MINGW_ANSI_STDIO    1
# else
   /*
    * otherwise use whatever __MINGW_FEATURES__ specifies...
    */
#  define __USE_MINGW_ANSI_STDIO    (__MINGW_FEATURES__ & __MINGW_ANSI_STDIO__)

struct threadlocalinfostruct;
struct threadmbinfostruct;
typedef struct threadlocalinfostruct *pthreadlocinfo;
typedef struct threadmbcinfostruct *pthreadmbcinfo;

typedef struct localeinfo_struct {
  pthreadlocinfo locinfo;
  pthreadmbcinfo mbcinfo;
} _locale_tstruct, *_locale_t;

#define __AW__(AW, AW_) AW ## AW_
#if ( \
 (!defined(_ODBCINST_H) && defined(UNICODE)) || \
 (!defined(_ODBCINST_H) && defined(_UNICODE)) || \
 defined(FORCE_UNICODE) \
 (defined _ODBCINST_H && !defined(SQL_NOUNICODEMAP) && defined(UNICODE)) \
)
#define __AW(AW) __AW__(AW, W)
#define __STR(AW) __AW__(L, AW)
#else
#define __AW(AW) __AW__(AW, A)
#define __STR(AW) __AW__(, AW)
#endif













//end of _mingw.h
//start of reent.h

#ifndef _SYS_REENT_H_
#ifdef __cplusplus
extern "C" {
#endif

#define _SYS_REENT_H_
#define _NULL 0
#ifndef __Long
#if __LONG_MAX__ == 2147483647L
#define __Long long
typedef unsigned __Long __ULong;
#elif __INT_MAX__ == 2147483647
#define __Long int
typedef unsigned __Long __ULong;
#endif
#endif
#if !defined( __Long)
#endif
#ifndef __Long
#define __Long __int32_t
typedef __uint32_t __ULong;
#endif

struct _reent;
/*
 * If _REENT_SMALL is defined, we make struct _reent as small as possible,
 * by having nearly everything possible allocated at first use.
 */
struct _Bigint
{
  struct _Bigint *_next;
  int _k, _maxwds, _sign, _wds;
  __ULong _x[1];
};

struct __tm
{
  int   __tm_sec;
  int   __tm_min;
  int   __tm_hour;
  int   __tm_mday;
  int   __tm_mon;
  int   __tm_year;
  int   __tm_wday;
  int   __tm_yday;
  int   __tm_isdst;
};
/*
 * atexit() support.
 */
#define	_ATEXIT_SIZE 32	/* must be at least 32 to guarantee ANSI conformance */
struct _on_exit_args {
	void *  _fnargs[_ATEXIT_SIZE];	        /* user fn args */
	void *	_dso_handle[_ATEXIT_SIZE];
	/* Bitmask is set if user function takes arguments.  */
	__ULong _fntypes;           	        /* type of exit routine -
				   Must have at least _ATEXIT_SIZE bits */
	/* Bitmask is set if function was registered via __cxa_atexit.  */
	__ULong _is_cxa;
};

#ifdef _REENT_SMALL
struct _atexit {
	struct	_atexit *_next;			/* next in list */
	int	_ind;				/* next index in this table */
	void	(*_fns[_ATEXIT_SIZE])(void);	/* the table itself */
        struct _on_exit_args * _on_exit_args_ptr;
};

# define _ATEXIT_INIT {_NULL, 0, {_NULL}, _NULL}
#else
struct _atexit {
	struct	_atexit *_next;			/* next in list */
	int	_ind;				/* next index in this table */
	/* Some entries may already have been called, and will be NULL.  */
	void	(*_fns[_ATEXIT_SIZE])(void);	/* the table itself */
        struct _on_exit_args _on_exit_args;
};

# define _ATEXIT_INIT {_NULL, 0, {_NULL}, {{_NULL}, {_NULL}, 0, 0}}
#endif
#ifdef _REENT_GLOBAL_ATEXIT
# define _REENT_INIT_ATEXIT
#else
# define _REENT_INIT_ATEXIT \
  _NULL, _ATEXIT_INIT,

struct __sbuf {
	unsigned char *_base;
	int	_size;
};

#ifdef _REENT_SMALL

struct __sFILE_fake {
  unsigned char *_p;	/* current position in (some) buffer */
  int	_r;		/* read space left for getc() */
  int	_w;		/* write space left for putc() */
  short	_flags;		/* flags, below; this FILE is free if 0 */
  short	_file;		/* fileno, if Unix descriptor, else -1 */
  struct __sbuf _bf;	/* the buffer (at least 1 byte, if !NULL) */
  int	_lbfsize;	/* 0 or -_bf._size, for inline putc */
  struct _reent *_data;
};

extern _VOID   _EXFUN(__sinit,(struct _reent *));
# define _REENT_SMALL_CHECK_INIT(ptr)		\
  do						\
    {						\
      if ((ptr) && !(ptr)->__sdidinit)		\
	__sinit (ptr);				\
    }						\
  while (0)
#else
# define _REENT_SMALL_CHECK_INIT(ptr) /* nothing */

struct __sFILE {
  unsigned char *_p;	/* current position in (some) buffer */
  int	_r;		/* read space left for getc() */
  int	_w;		/* write space left for putc() */
  short	_flags;		/* flags, below; this FILE is free if 0 */
  short	_file;		/* fileno, if Unix descriptor, else -1 */
  struct __sbuf _bf;	/* the buffer (at least 1 byte, if !NULL) */
  int	_lbfsize;	/* 0 or -_bf._size, for inline putc */
#ifdef _REENT_SMALL
  struct _reent *_data;
#endif

_PTR	_cookie;	/* cookie passed to io functions */
  _READ_WRITE_RETURN_TYPE _EXFNPTR(_read, (struct _reent *, _PTR,
					   char *, int));
  _READ_WRITE_RETURN_TYPE _EXFNPTR(_write, (struct _reent *, _PTR,
					    const char *, int));
  _fpos_t _EXFNPTR(_seek, (struct _reent *, _PTR, _fpos_t, int));
  int _EXFNPTR(_close, (struct _reent *, _PTR));
  /* separate buffer for long sequences of ungetc() */
  struct __sbuf _ub;	/* ungetc buffer */
  unsigned char *_up;	/* saved _p when _p is doing ungetc data */
  int	_ur;		/* saved _r when _r is counting ungetc data */

unsigned char _ubuf[3];	/* guarantee an ungetc() buffer */
  unsigned char _nbuf[1];	/* guarantee a getc() buffer */
  /* separate buffer for fgetline() when line crosses buffer boundary */
  struct __sbuf _lb;	/* buffer for fgetline() */
  /* Unix stdio files get aligned to block boundaries on fseek() */
  int	_blksize;	/* stat.st_blksize (may be != _bf._size) */
  _off_t _offset;	/* current lseek offset */
#ifndef _REENT_SMALL
  struct _reent *_data;	/* Here for binary compatibility? Remove? */
#endif

#ifndef __SINGLE_THREAD__
  _flock_t _lock;	/* for thread-safety locking */
#endif
  _mbstate_t _mbstate;	/* for wide char stdio functions. */
  int   _flags2;        /* for future use */
};

#ifdef __CUSTOM_FILE_IO__

#else /* !__CUSTOM_FILE_IO__ */
#ifdef __LARGE64_FILES
struct __sFILE64 {
  unsigned char *_p;	/* current position in (some) buffer */
  int	_r;		/* read space left for getc() */
  int	_w;		/* write space left for putc() */
  short	_flags;		/* flags, below; this FILE is free if 0 */
  short	_file;		/* fileno, if Unix descriptor, else -1 */
  struct __sbuf _bf;	/* the buffer (at least 1 byte, if !NULL) */
  int	_lbfsize;	/* 0 or -_bf._size, for inline putc */
  struct _reent *_data;

_PTR	_cookie;	/* cookie passed to io functions */
  _READ_WRITE_RETURN_TYPE _EXFNPTR(_read, (struct _reent *, _PTR,
					   char *, int));
  _READ_WRITE_RETURN_TYPE _EXFNPTR(_write, (struct _reent *, _PTR,
					    const char *, int));
  _fpos_t _EXFNPTR(_seek, (struct _reent *, _PTR, _fpos_t, int));
  int _EXFNPTR(_close, (struct _reent *, _PTR));

struct __sbuf _ub;	/* ungetc buffer */
  unsigned char *_up;	/* saved _p when _p is doing ungetc data */
  int	_ur;		/* saved _r when _r is counting ungetc data */
  /* tricks to meet minimum requirements even when malloc() fails */
  unsigned char _ubuf[3];	/* guarantee an ungetc() buffer */
  unsigned char _nbuf[1];	/* guarantee a getc() buffer */
  /* separate buffer for fgetline() when line crosses buffer boundary */
  struct __sbuf _lb;	/* buffer for fgetline() */
  /* Unix stdio files get aligned to block boundaries on fseek() */
  int	_blksize;	/* stat.st_blksize (may be != _bf._size) */
  int   _flags2;        /* for future use */
  _off64_t _offset;     /* current lseek offset */
  _fpos64_t _EXFNPTR(_seek64, (struct _reent *, _PTR, _fpos64_t, int));
#ifndef __SINGLE_THREAD__
_flock_t _lock;
_mbstate_t _mbstate;	/* for wide char stdio functions. */
};

typedef struct __sFILE64 __FILE;
#else
typedef struct __sFILE   __FILE;

struct _glue
{
  struct _glue *_next;
  int _niobs;
  __FILE *_iobs;
};

#define        _RAND48_SEED_0  (0x330e)
#define        _RAND48_SEED_1  (0xabcd)
#define        _RAND48_SEED_2  (0x1234)
#define        _RAND48_MULT_0  (0xe66d)
#define        _RAND48_MULT_1  (0xdeec)
#define        _RAND48_MULT_2  (0x0005)
#define        _RAND48_ADD     (0x000b)
struct _rand48 {
  unsigned short _seed[3];
  unsigned short _mult[3];
  unsigned short _add;

#ifdef _REENT_SMALL
  /* Put this in here as well, for good luck.  */
  __extension__ unsigned long long _rand_next;
#endif
};

#define _REENT_EMERGENCY_SIZE 25
#define _REENT_ASCTIME_SIZE 26
#define _REENT_SIGNAL_SIZE 24

#ifdef _REENT_SMALL

struct _mprec
{
  /* used by mprec routines */
  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;
};

struct _misc_reent
{
  /* miscellaneous reentrant data */
  char *_strtok_last;
  _mbstate_t _mblen_state;
  _mbstate_t _wctomb_state;
  _mbstate_t _mbtowc_state;
  char _l64a_buf[8];
  int _getdate_err;
  _mbstate_t _mbrlen_state;
  _mbstate_t _mbrtowc_state;
  _mbstate_t _mbsrtowcs_state;
  _mbstate_t _wcrtomb_state;
  _mbstate_t _wcsrtombs_state;
};

struct _reent
{
  /* As an exception to the above put _errno first for binary
     compatibility with non _REENT_SMALL targets.  */
  int _errno;			/* local copy of errno */
  /* FILE is a big struct and may change over time.  To try to achieve binary
     compatibility with future versions, put stdin,stdout,stderr here.
     These are pointers into member __sf defined below.  */
  __FILE *_stdin, *_stdout, *_stderr;	/* XXX */
  int  _inc;			/* used by tmpnam */
  char *_emergency;
  int __sdidinit;		/* 1 means stdio has been init'd */
  int _current_category;	/* unused */
  _CONST char *_current_locale;	/* unused */
  struct _mprec *_mp;
  void _EXFNPTR(__cleanup, (struct _reent *));
  int _gamma_signgam;
  /* used by some fp conversion routines */
  int _cvtlen;			/* should be size_t */
  char *_cvtbuf;
  struct _rand48 *_r48;
  struct __tm *_localtime_buf;
  char *_asctime_buf;

/* signal info */
  void (**(_sig_func))(int);
# ifndef _REENT_GLOBAL_ATEXIT
  /* atexit stuff */
  struct _atexit *_atexit;
  struct _atexit _atexit0;
# endif
  struct _glue __sglue;			/* root of glue chain */
  __FILE *__sf;			        /* file descriptors */
  struct _misc_reent *_misc;            /* strtok, multibyte states */
  char *_signal_buf;                    /* strsignal */
};

extern const struct __sFILE_fake __sf_fake_stdin;
extern const struct __sFILE_fake __sf_fake_stdout;
extern const struct __sFILE_fake __sf_fake_stderr;
# define _REENT_INIT(var) \
  { 0, \
    (__FILE *)&__sf_fake_stdin, \
    (__FILE *)&__sf_fake_stdout, \
    (__FILE *)&__sf_fake_stderr, \
    0, \
    _NULL, \
    0, \
    0, \
    "C", \
    _NULL, \
    _NULL, \
    0, \
    0, \
    _NULL, \
    _NULL, \
    _NULL, \
    _NULL, \
    _NULL, \
    _REENT_INIT_ATEXIT \
    {_NULL, 0, _NULL}, \
    _NULL, \
    _NULL, \
    _NULL \
  }

#define _REENT_INIT_PTR(var) \
  { memset((var), 0, sizeof(*(var))); \
    (var)->_stdin = (__FILE *)&__sf_fake_stdin; \
    (var)->_stdout = (__FILE *)&__sf_fake_stdout; \
    (var)->_stderr = (__FILE *)&__sf_fake_stderr; \
    (var)->_current_locale = "C"; \
  }

#if DEBUG
#define __reent_assert(x) assert(x)
#else
#define __reent_assert(x) ((void)0)

#ifdef __CUSTOM_FILE_IO__
#error Custom FILE I/O and _REENT_SMALL not currently supported.
#endif

#define _REENT_CHECK(var, what, type, size, init) do { \
  struct _reent *_r = (var); \
  if (_r->what == NULL) { \
    _r->what = (type)malloc(size); \
    __reent_assert(_r->what); \
    init; \
  } \
} while (0)
#define _REENT_CHECK_TM(var) \
  _REENT_CHECK(var, _localtime_buf, struct __tm *, sizeof *((var)->_localtime_buf), \
    /* nothing */)
#define _REENT_CHECK_ASCTIME_BUF(var) \
  _REENT_CHECK(var, _asctime_buf, char *, _REENT_ASCTIME_SIZE, \
    memset((var)->_asctime_buf, 0, _REENT_ASCTIME_SIZE))

#define _REENT_INIT_RAND48(var) do { \
  struct _reent *_r = (var); \
  _r->_r48->_seed[0] = _RAND48_SEED_0; \
  _r->_r48->_seed[1] = _RAND48_SEED_1; \
  _r->_r48->_seed[2] = _RAND48_SEED_2; \
  _r->_r48->_mult[0] = _RAND48_MULT_0; \
  _r->_r48->_mult[1] = _RAND48_MULT_1; \
  _r->_r48->_mult[2] = _RAND48_MULT_2; \
  _r->_r48->_add = _RAND48_ADD; \
  _r->_r48->_rand_next = 1; \
} while (0)
#define _REENT_CHECK_RAND48(var) \
  _REENT_CHECK(var, _r48, struct _rand48 *, sizeof *((var)->_r48), _REENT_INIT_RAND48((var)))
#define _REENT_INIT_MP(var) do { \
  struct _reent *_r = (var); \
  _r->_mp->_result_k = 0; \
  _r->_mp->_result = _r->_mp->_p5s = _NULL; \
  _r->_mp->_freelist = _NULL; \

} while (0)
#define _REENT_CHECK_MP(var) \
  _REENT_CHECK(var, _mp, struct _mprec *, sizeof *((var)->_mp), _REENT_INIT_MP(var))
#define _REENT_CHECK_EMERGENCY(var) \
  _REENT_CHECK(var, _emergency, char *, _REENT_EMERGENCY_SIZE, /* nothing */)
#define _REENT_INIT_MISC(var) do { \
  struct _reent *_r = (var); \
  _r->_misc->_strtok_last = _NULL; \
  _r->_misc->_mblen_state.__count = 0; \
  _r->_misc->_mblen_state.__value.__wch = 0; \
  _r->_misc->_wctomb_state.__count = 0; \
  _r->_misc->_wctomb_state.__value.__wch = 0; \
  _r->_misc->_mbtowc_state.__count = 0; \
  _r->_misc->_mbtowc_state.__value.__wch = 0; \
  _r->_misc->_mbrlen_state.__count = 0; \
  _r->_misc->_mbrlen_state.__value.__wch = 0; \
  _r->_misc->_mbrtowc_state.__count = 0; \
  _r->_misc->_mbrtowc_state.__value.__wch = 0; \
  _r->_misc->_mbsrtowcs_state.__count = 0; \
  _r->_misc->_mbsrtowcs_state.__value.__wch = 0; \
  _r->_misc->_wcrtomb_state.__count = 0; \
  _r->_misc->_wcrtomb_state.__value.__wch = 0; \
  _r->_misc->_wcsrtombs_state.__count = 0; \
  _r->_misc->_wcsrtombs_state.__value.__wch = 0; \
  _r->_misc->_l64a_buf[0] = '\0'; \
  _r->_misc->_getdate_err = 0; \
} while (0)
#define _REENT_CHECK_MISC(var) \
  _REENT_CHECK(var, _misc, struct _misc_reent *, sizeof *((var)->_misc), _REENT_INIT_MISC(var))
#define _REENT_CHECK_SIGNAL_BUF(var) \
  _REENT_CHECK(var, _signal_buf, char *, _REENT_SIGNAL_SIZE, /* nothing */)
#define _REENT_SIGNGAM(ptr)	((ptr)->_gamma_signgam)
#define _REENT_RAND_NEXT(ptr)	((ptr)->_r48->_rand_next)
#define _REENT_RAND48_SEED(ptr)	((ptr)->_r48->_seed)
#define _REENT_RAND48_MULT(ptr)	((ptr)->_r48->_mult)
#define _REENT_RAND48_ADD(ptr)	((ptr)->_r48->_add)
#define _REENT_MP_RESULT(ptr)	((ptr)->_mp->_result)
#define _REENT_MP_RESULT_K(ptr)	((ptr)->_mp->_result_k)
#define _REENT_MP_P5S(ptr)	((ptr)->_mp->_p5s)
#define _REENT_MP_FREELIST(ptr)	((ptr)->_mp->_freelist)
#define _REENT_ASCTIME_BUF(ptr)	((ptr)->_asctime_buf)
#define _REENT_TM(ptr)		((ptr)->_localtime_buf)
#define _REENT_EMERGENCY(ptr)	((ptr)->_emergency)
#define _REENT_STRTOK_LAST(ptr)	((ptr)->_misc->_strtok_last)
#define _REENT_MBLEN_STATE(ptr)	((ptr)->_misc->_mblen_state)
#define _REENT_MBTOWC_STATE(ptr)((ptr)->_misc->_mbtowc_state)
#define _REENT_WCTOMB_STATE(ptr)((ptr)->_misc->_wctomb_state)
#define _REENT_MBRLEN_STATE(ptr) ((ptr)->_misc->_mbrlen_state)
#define _REENT_MBRTOWC_STATE(ptr) ((ptr)->_misc->_mbrtowc_state)
#define _REENT_MBSRTOWCS_STATE(ptr) ((ptr)->_misc->_mbsrtowcs_state)
#define _REENT_WCRTOMB_STATE(ptr) ((ptr)->_misc->_wcrtomb_state)
#define _REENT_WCSRTOMBS_STATE(ptr) ((ptr)->_misc->_wcsrtombs_state)
#define _REENT_L64A_BUF(ptr)    ((ptr)->_misc->_l64a_buf)
#define _REENT_GETDATE_ERR_P(ptr) (&((ptr)->_misc->_getdate_err))
#define _REENT_SIGNAL_BUF(ptr)  ((ptr)->_signal_buf)
//#else /* !_REENT_SMALL */
struct _reent
{
  int _errno;			/* local copy of errno */
  /* FILE is a big struct and may change over time.  To try to achieve binary
     compatibility with future versions, put stdin,stdout,stderr here.
     These are pointers into member __sf defined below.  */
  __FILE *_stdin, *_stdout, *_stderr;
  int  _inc;			/* used by tmpnam */
  char _emergency[_REENT_EMERGENCY_SIZE];
  int _current_category;	/* used by setlocale */
  _CONST char *_current_locale;
  int __sdidinit;		/* 1 means stdio has been init'd */
  void _EXFNPTR(__cleanup, (struct _reent *));
  /* used by mprec routines */
  struct _Bigint *_result;
  int _result_k;
  struct _Bigint *_p5s;
  struct _Bigint **_freelist;
  /* used by some fp conversion routines */
  int _cvtlen;			/* should be size_t */
  char *_cvtbuf;
  union
    {
      struct
        {
          unsigned int _unused_rand;
          char * _strtok_last;
          char _asctime_buf[_REENT_ASCTIME_SIZE];
          struct __tm _localtime_buf;
          int _gamma_signgam;
          __extension__ unsigned long long _rand_next;
          struct _rand48 _r48;
          _mbstate_t _mblen_state;
          _mbstate_t _mbtowc_state;
          _mbstate_t _wctomb_state;
          char _l64a_buf[8];
          char _signal_buf[_REENT_SIGNAL_SIZE];
          int _getdate_err;
          _mbstate_t _mbrlen_state;
          _mbstate_t _mbrtowc_state;
          _mbstate_t _mbsrtowcs_state;
          _mbstate_t _wcrtomb_state;
          _mbstate_t _wcsrtombs_state;
	  int _h_errno;
        } _reent;
  /* Two next two fields were once used by malloc.  They are no longer
     used. They are used to preserve the space used before so as to
     allow addition of new reent fields and keep binary compatibility.   */
      struct
        {
#define _N_LISTS 30
          unsigned char * _nextf[_N_LISTS];
          unsigned int _nmalloc[_N_LISTS];
        } _unused;
    } _new;

# ifndef _REENT_GLOBAL_ATEXIT
  /* atexit stuff */
  struct _atexit *_atexit;	/* points to head of LIFO stack */
  struct _atexit _atexit0;	/* one guaranteed table, required by ANSI */
# endif
  /* signal info */
  void (**(_sig_func))(int);
  /* These are here last so that __FILE can grow without changing the offsets
     of the above members (on the off chance that future binary compatibility
     would be broken otherwise).  */
  struct _glue __sglue;		/* root of glue chain */
  __FILE __sf[3];  		/* first three file descriptors */
};

#define _REENT_INIT(var) \
  { 0, \
    &(var).__sf[0], \
    &(var).__sf[1], \
    &(var).__sf[2], \
    0, \
    "", \
    0, \
    "C", \
    0, \
    _NULL, \
    _NULL, \
    0, \
    _NULL, \
    _NULL, \
    0, \
    _NULL, \
    { \
      { \
        0, \
        _NULL, \
        "", \
        {0, 0, 0, 0, 0, 0, 0, 0, 0}, \
        0, \
        1, \
        { \
          {_RAND48_SEED_0, _RAND48_SEED_1, _RAND48_SEED_2}, \
          {_RAND48_MULT_0, _RAND48_MULT_1, _RAND48_MULT_2}, \
          _RAND48_ADD \
        }, \
        {0, {0}}, \
        {0, {0}}, \
        {0, {0}}, \
        "", \
        "", \
        0, \
        {0, {0}}, \
        {0, {0}}, \
        {0, {0}}, \
        {0, {0}}, \
        {0, {0}} \
      } \
    }, \
    _REENT_INIT_ATEXIT \
    _NULL, \
    {_NULL, 0, _NULL} \
  }

#define _REENT_INIT_PTR(var) \
  { memset((var), 0, sizeof(*(var))); \
    (var)->_stdin = &(var)->__sf[0]; \
    (var)->_stdout = &(var)->__sf[1]; \
    (var)->_stderr = &(var)->__sf[2]; \
    (var)->_current_locale = "C"; \
    (var)->_new._reent._rand_next = 1; \
    (var)->_new._reent._r48._seed[0] = _RAND48_SEED_0; \
    (var)->_new._reent._r48._seed[1] = _RAND48_SEED_1; \
    (var)->_new._reent._r48._seed[2] = _RAND48_SEED_2; \
    (var)->_new._reent._r48._mult[0] = _RAND48_MULT_0; \
    (var)->_new._reent._r48._mult[1] = _RAND48_MULT_1; \
    (var)->_new._reent._r48._mult[2] = _RAND48_MULT_2; \
    (var)->_new._reent._r48._add = _RAND48_ADD; \
  }
#define _REENT_CHECK_RAND48(pt
#define _REENT_CHECK_MP(ptr)		/* nothing */
#define _REENT_CHECK_TM(ptr)		/* nothing */
#define _REENT_CHECK_ASCTIME_BUF(ptr)	/* nothing */
#define _REENT_CHECK_EMERGENCY(ptr)	/* nothing */
#define _REENT_CHECK_MISC(ptr)	        /* nothing */
#define _REENT_CHECK_SIGNAL_BUF(ptr)	/* nothing */
#define _REENT_SIGNGAM(ptr)	((ptr)->_new._reent._gamma_signgam)
#define _REENT_RAND_NEXT(ptr)	((ptr)->_new._reent._rand_next)
#define _REENT_RAND48_SEED(ptr)	((ptr)->_new._reent._r48._seed)
#define _REENT_RAND48_MULT(ptr)	((ptr)->_new._reent._r48._mult)
#define _REENT_RAND48_ADD(ptr)	((ptr)->_new._reent._r48._add)
#define _REENT_MP_RESULT(ptr)	((ptr)->_result)
#define _REENT_MP_RESULT_K(ptr)	((ptr)->_result_k)
#define _REENT_MP_P5S(ptr)	((ptr)->_p5s)
#define _REENT_MP_FREELIST(ptr)	((ptr)->_freelist)
#define _REENT_ASCTIME_BUF(ptr)	((ptr)->_new._reent._asctime_buf)
#define _REENT_TM(ptr)		(&(ptr)->_new._reent._localtime_buf)
#define _REENT_EMERGENCY(ptr)	((ptr)->_emergency)
#define _REENT_STRTOK_LAST(ptr)	((ptr)->_new._reent._strtok_last)
#define _REENT_MBLEN_STATE(ptr)	((ptr)->_new._reent._mblen_state)
#define _REENT_MBTOWC_STATE(ptr)((ptr)->_new._reent._mbtowc_state)
#define _REENT_WCTOMB_STATE(ptr)((ptr)->_new._reent._wctomb_state)
#define _REENT_MBRLEN_STATE(ptr)((ptr)->_new._reent._mbrlen_state)
#define _REENT_MBRTOWC_STATE(ptr)((ptr)->_new._reent._mbrtowc_state)
#define _REENT_MBSRTOWCS_STATE(ptr)((ptr)->_new._reent._mbsrtowcs_state)
#define _REENT_WCRTOMB_STATE(ptr)((ptr)->_new._reent._wcrtomb_state)
#define _REENT_WCSRTOMBS_STATE(ptr)((ptr)->_new._reent._wcsrtombs_state)
#define _REENT_L64A_BUF(ptr)    ((ptr)->_new._reent._l64a_buf)
#define _REENT_SIGNAL_BUF(ptr)  ((ptr)->_new._reent._signal_buf)
#define _REENT_GETDATE_ERR_P(ptr) (&((ptr)->_new._reent._getdate_err))

#define _Kmax (sizeof (size_t) << 3)
/*
 * All references to struct _reent are via this pointer.
 * Internally, newlib routines that need to reference it should use _REENT.
 */
#ifndef __ATTRIBUTE_IMPURE_PTR__
#define __ATTRIBUTE_IMPURE_PTR__
#endif

extern __thread struct _reent *_impure_ptr __ATTRIBUTE_IMPURE_PTR__;
extern struct _reent *_CONST _global_impure_ptr __ATTRIBUTE_IMPURE_PTR__;
void _reclaim_reent _PARAMS ((struct _reent *));
/* #define _REENT_ONLY define this to get only reentrant routines */
#if defined(__DYNAMIC_REENT__) && !defined(__SINGLE_THREAD__)
#ifndef __getreent
  struct _reent * _EXFUN(__getreent, (void));
#endif
# define _REENT (__getreent())
#else /* __SINGLE_THREAD__ || !__DYNAMIC_REENT__ */
# define _REENT _impure_ptr
#define _GLOBAL_REENT _global_impure_ptr
#ifdef _REENT_GLOBAL_ATEXIT
extern struct _atexit *_global_atexit; /* points to head of LIFO stack */
# define _GLOBAL_ATEXIT _global_atexit
#else
# define _GLOBAL_ATEXIT (_GLOBAL_REENT->_atexit)
#endif
#ifdef __cplusplus
}
#endif



































//end of reent.h
//starts of stdarg.h

#ifndef _STDARG_H_
#define _STDARG_H_

#ifndef RC_INVOKED

/*
 * I was told that Win NT likes this.
 */
#ifndef _VA_LIST_DEFINED
#define _VA_LIST_DEFINED
#endif

#ifndef	_VA_LIST
#define _VA_LIST
#if defined __GNUC__ && __GNUC__ >= 3
typedef __builtin_va_list va_list;
#else
typedef char* va_list;
#endif

#define __va_argsiz(t)	\
	(((sizeof(t) + sizeof(int) - 1) / sizeof(int)) * sizeof(int))

#ifdef	__GNUC__

#define va_start(ap, pN)	\
	((ap) = ((va_list) __builtin_next_arg(pN)))
#else

#define va_end(ap)	((void)0)

#define va_arg(ap, t)					\
	 (((ap) = (ap) + __va_argsiz(t)),		\
	  *((t*) (void*) ((ap) - __va_argsiz(t))))









//end of stdarg.h
//start of stdio.h

#ifndef _STDIO_H_
 #ifdef __cplusplus
 extern "C" {
 #endif
 #define _STDIO_H_

#define _FSTDIO

#define __need_size_t

#define __need___va_list

struct __sFile
 {
   int unused;
 };

typedef struct __sFILE FILE;

#define __SLBF  0x0001          /* line buffered */
 #define __SNBF  0x0002          /* unbuffered */
 #define __SRD   0x0004          /* OK to read */
 #define __SWR   0x0008          /* OK to write */
         /* RD and WR are never simultaneously asserted */
 #define __SRW   0x0010          /* open for reading & writing */
 #define __SEOF  0x0020          /* found EOF */
 #define __SERR  0x0040          /* found error */
 #define __SMBF  0x0080          /* _buf is from malloc */
 #define __SAPP  0x0100          /* fdopen()ed in append mode - so must  write to end */
 #define __SSTR  0x0200          /* this is an sprintf/snprintf string */
 #define __SOPT  0x0400          /* do fseek() optimisation */
 #define __SNPT  0x0800          /* do not do fseek() optimisation */
 #define __SOFF  0x1000          /* set iff _offset is in fact correct */
 #define __SMOD  0x2000          /* true => fgetline modified _p text */

#if defined(__CYGWIN__) || defined(__CYGWIN__)
 #define __SCLE        0x4000
#endif

#define _IOFBF  0               /* setvbuf should set fully buffered */
 #define _IOLBF  1               /* setvbuf should set line buffered */
 #define _IONBF  2               /* setvbuf should set unbuffered */

 #ifndef NULL
 #define NULL    0
 #endif

#define BUFSIZ  1024
 #define EOF     (-1)

#define FOPEN_MAX       20      /* must be <= OPEN_MAX <sys/syslimits.h> */
 #define FILENAME_MAX    1024    /* must be <= PATH_MAX <sys/syslimits.h> */
 #define L_tmpnam        1024    /* XXX must be == PATH_MAX */
 #ifndef __STRICT_ANSI__
 #define P_tmpdir        "/tmp"
 #endif

#ifndef SEEK_SET
 #define SEEK_SET        0       /* set file offset to offset */
 #endif
 #ifndef SEEK_CUR
 #define SEEK_CUR        1       /* set file offset to current plus offset */
 #endif
 #ifndef SEEK_END
 #define SEEK_END        2       /* set file offset to EOF plus offset */
 #endif

#define TMP_MAX         26

 #define stdin   (_impure_ptr->_stdin)
 #define stdout  (_impure_ptr->_stdout)
 #define stderr  (_impure_ptr->_stderr)

 #define _stdin_r(x)     ((x)->_stdin)
 #define _stdout_r(x)    ((x)->_stdout)
 #define _stderr_r(x)    ((x)->_stderr)

#ifdef __GNUC__
 #define __VALIST __gnuc_va_list
 #else
 #define __VALIST char*
 #endif

#ifndef _EXFUN
 # define _EXFUN(N,P) N P
 #endif

extern int     (printf, (const char *__restrict __format, ...));
int     _EXFUN(scanf, (const char *, ...));
 int     _EXFUN(sscanf, (const char *, const char *, ...));
 int     _EXFUN(vfprintf, (FILE *, const char *, __VALIST));
 int     _EXFUN(vprintf, (const char *, __VALIST));
 int     _EXFUN(vsprintf, (char *, const char *, __VALIST));
 int     _EXFUN(vsnprintf, (char *, size_t, const char *, __VALIST));
 int     _EXFUN(fgetc, (FILE *));
 char *  _EXFUN(fgets, (char *, int, FILE *));
 int     _EXFUN(fputc, (int, FILE *));
 int     _EXFUN(fputs, (const char *, FILE *));
 int     _EXFUN(getc, (FILE *));
 int     _EXFUN(getchar, (void));
 char *  _EXFUN(gets, (char *));
 int     _EXFUN(putc, (int, FILE *));
 int     _EXFUN(putchar, (int));
 int     _EXFUN(puts, (const char *));
 int     _EXFUN(ungetc, (int, FILE *));
 size_t  _EXFUN(fread, (void *, size_t _size, size_t _n, FILE *));
 size_t  _EXFUN(fwrite, (const void *, size_t _size, size_t _n, FILE *));

int     _EXFUN(sprintf, (char *, const char *, ...));
 int     _EXFUN(snprintf, (char *, size_t, const char *, ...));

#ifdef __cplusplus
 }
 #endif































//end of stdio.h
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
#endif
#endif
#endif
#endif
#endif
#endif
