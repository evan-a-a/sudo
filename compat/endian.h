#ifndef _COMPAT_ENDIAN_H
#define _COMPAT_ENDIAN_H

#ifndef BYTE_ORDER
# undef LITTLE_ENDIAN
# define LITTLE_ENDIAN	1234
# undef BIG_ENDIAN
# define BIG_ENDIAN	4321
# undef UNKNOWN_ENDIAN
# define UNKNOWN_ENDIAN	0

/*
 * Attempt to guess endianness.
 * Solaris may define _LITTLE_ENDIAN and _BIG_ENDIAN to 1
 * HP-UX may define __LITTLE_ENDIAN__ and __BIG_ENDIAN__ to 1
 * Otherwise, check for cpu-specific cpp defines.
 * Note that some CPUs are bi-endian, including: arm, powerpc, alpha,
 * sparc64, mips, hppa, sh4 and ia64.
 * We just check for the most common uses.
 */

# if defined(__BYTE_ORDER)
#  define BYTE_ORDER	__BYTE_ORDER
# elif defined(_BYTE_ORDER)
#  define BYTE_ORDER	_BYTE_ORDER
# elif defined(_LITTLE_ENDIAN) || defined(__LITTLE_ENDIAN__)
#  define BYTE_ORDER	LITTLE_ENDIAN
# elif defined(_BIG_ENDIAN) || defined(__BIG_ENDIAN__)
#  define BYTE_ORDER	BIG_ENDIAN
# elif defined(__alpha__) || defined(__alpha) || defined(__amd64) || \
       defined(BIT_ZERO_ON_RIGHT) || defined(i386) || defined(__i386) || \
       defined(MIPSEL) || defined(_MIPSEL) || defined(ns32000) || \
       defined(__ns3200) || defined(sun386) || defined(vax) || \
       defined(__vax) || defined(__x86__) || \
       (defined(sun) && defined(__powerpc)) || \
       (!defined(__hpux) && defined(__ia64))
#  define BYTE_ORDER	LITTLE_ENDIAN
# elif defined(__68k__) || defined(apollo) || defined(BIT_ZERO_ON_LEFT) || \
       defined(__convex__) || defined(_CRAY) || defined(DGUX) || \
       defined(__hppa) || defined(__hp9000) || defined(__hp9000s300) || \
       defined(__hp9000s700) || defined(__hp3000s900) || \
       defined(ibm032) || defined(ibm370) || defined(_IBMR2) || \
       defined(is68k) || defined(mc68000) || defined(m68k) || \
       defined(__m68k) || defined(m88k) || defined(__m88k) || \
       defined(MIPSEB) || defined(_MIPSEB) || defined(MPE) || \
       defined(pyr) || defined(__powerpc) || defined(__powerpc__) || \
       defined(sel) || defined(__sparc) || defined(__sparc__) || \
       defined(tahoe) || (defined(__hpux) && defined(__ia64)) || \
       (defined(sun) && defined(__powerpc))
#  define BYTE_ORDER	BIG_ENDIAN
# else
#  define BYTE_ORDER	UNKNOWN_ENDIAN
# endif
#endif /* BYTE_ORDER */

#endif /* _COMPAT_ENDIAN_H */