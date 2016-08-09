/* aconf.h.  Generated from aconf.h.in by configure.  */
/* aconf.h.in.  Generated from configure.ac by autoheader.  */

/*
 * aconf.h
 *
 * Copyright 2002-2003 Glyph & Cog, LLC
 */

#ifndef ACONF_H
#define ACONF_H

#include <aconf2.h>

/*
 * Enable C++ exceptions.
 */
/* #undef USE_EXCEPTIONS */

/* Use A4 paper size instead of Letter for PostScript output */
/* #undef A4_PAPER */

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#define HAVE_DIRENT_H 1

/* Define to 1 if you have the `fseek64' function. */
/* #undef HAVE_FSEEK64 */

/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
#define HAVE_FSEEKO 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `mkstemp' function. */
#define HAVE_MKSTEMP 1

/* Define to 1 if you have the `mkstemps' function. */
#define HAVE_MKSTEMPS 1

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the `popen' function. */
#define HAVE_POPEN 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/select.h> header file. */
#define HAVE_SYS_SELECT_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <time.h> header file. */
#define HAVE_TIME_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Enable multithreading support */
/* #undef MULTITHREADED */

/* Include support for OPI comments */
/* #undef OPI_SUPPORT */

/* Define to the address where bug reports for this package should be sent. */
#define XPDF_PACKAGE_BUGREPORT "tex-k@tug.org"

/* Define to the full name of this package. */
#define XPDF_PACKAGE_NAME "xpdf (TeX Live)"

/* Define to the full name and version of this package. */
#define XPDF_PACKAGE_STRING "xpdf (TeX Live) 3.04"

/* Define to the one symbol short name of this package. */
#define XPDF_PACKAGE_TARNAME "xpdf--tex-live-"

/* Define to the home page for this package. */
#define XPDF_PACKAGE_URL ""

/* Define to the version of this package. */
#define XPDF_PACKAGE_VERSION "3.04"

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Enable large inode numbers on Mac OS X 10.5.  */
#ifndef _DARWIN_USE_64_BIT_INODE
# define _DARWIN_USE_64_BIT_INODE 1
#endif

/* Number of bits in a file offset, on hosts where this is settable. */
/* #undef _FILE_OFFSET_BITS */

/* Define to 1 to make fseeko visible on some hosts (e.g. glibc 2.2). */
/* #undef _LARGEFILE_SOURCE */

/* Define for large files, on AIX-style hosts. */
/* #undef _LARGE_FILES */

#endif
