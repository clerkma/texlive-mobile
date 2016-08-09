/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to 1 if alloca() works (via gmp-impl.h). */
/* #undef HAVE_ALLOCA */

/* Define to 1 if you have <alloca.h> and it should be used (not on Ultrix).
   */
#define HAVE_ALLOCA_H 1

/* Define to 1 if the compiler accepts gcc style __attribute__ ((const)) */
#define HAVE_ATTRIBUTE_CONST 1

/* Define to 1 if the compiler accepts gcc style __attribute__ ((malloc)) */
#define HAVE_ATTRIBUTE_MALLOC 1

/* Define to 1 if the compiler accepts gcc style __attribute__ ((mode (XX)))
   */
#define HAVE_ATTRIBUTE_MODE 1

/* Define to 1 if the compiler accepts gcc style __attribute__ ((noreturn)) */
#define HAVE_ATTRIBUTE_NORETURN 1

/* Define one of the following to 1 for the format of a `double'.
   If your format is not among these choices, or you don't know what it is,
   then leave all undefined.
   IEEE_LITTLE_SWAPPED means little endian, but with the two 4-byte halves
   swapped, as used by ARM CPUs in little endian mode.  */
/* #undef HAVE_DOUBLE_IEEE_BIG_ENDIAN */
#define HAVE_DOUBLE_IEEE_LITTLE_ENDIAN 1
/* #undef HAVE_DOUBLE_IEEE_LITTLE_SWAPPED */
/* #undef HAVE_DOUBLE_VAX_D */
/* #undef HAVE_DOUBLE_VAX_G */
/* #undef HAVE_DOUBLE_CRAY_CFP */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

/* Define to 1 if you have the `raise' function. */
#define HAVE_RAISE 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Name of package */
#define PACKAGE "gmp--tex-live-"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "tex-k@tug.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "gmp (TeX Live)"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "gmp (TeX Live) 6.1.1"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "gmp--tex-live-"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "6.1.1"

/* The size of `mp_limb_t', as computed by sizeof. */
#define SIZEOF_MP_LIMB_T 8

/* The size of `unsigned', as computed by sizeof. */
#define SIZEOF_UNSIGNED 4

/* The size of `unsigned long', as computed by sizeof. */
#define SIZEOF_UNSIGNED_LONG 8

/* The size of `unsigned long long', as computed by sizeof. */
#define SIZEOF_UNSIGNED_LONG_LONG 8

/* The size of `unsigned short', as computed by sizeof. */
#define SIZEOF_UNSIGNED_SHORT 2

/* The size of `void *', as computed by sizeof. */
#define SIZEOF_VOID_P 8

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "6.1.1"

/* Define one of these to 1 for the temporary memory allocation method. */
/* #undef WANT_TMP_ALLOCA */
#define WANT_TMP_REENTRANT 1

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif
