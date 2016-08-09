/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

#ifndef T1UTILS_CONFIG_H
#define T1UTILS_CONFIG_H

/* Define if intXX_t types are not available. */
/* #undef HAVE_FAKE_INT_TYPES */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strtoul' function. */
#define HAVE_STRTOUL 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if the system has the type `uintptr_t'. */
#define HAVE_UINTPTR_T 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define if you have u_intXX_t types but not uintXX_t types. */
/* #undef HAVE_U_INT_TYPES */

/* Name of package */
#define PACKAGE "t1utils--tex-live-"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "tex-k@tug.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "t1utils (TeX Live)"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "t1utils (TeX Live) 1.39"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "t1utils--tex-live-"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.39"

/* The size of `unsigned int', as computed by sizeof. */
#define SIZEOF_UNSIGNED_INT 4

/* The size of `unsigned long', as computed by sizeof. */
#define SIZEOF_UNSIGNED_LONG 8

/* The size of `void *', as computed by sizeof. */
#define SIZEOF_VOID_P 8

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Version number of package */
#define VERSION "1.39"

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

#include <lcdf/inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Prototype strerror if we don't have it. */
#if !HAVE_STRERROR
char *strerror(int errno);
#endif

#ifdef __cplusplus
}
#endif

#endif /* T1UTILS_CONFIG_H */
