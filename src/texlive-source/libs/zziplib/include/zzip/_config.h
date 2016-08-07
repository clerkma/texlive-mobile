#ifndef _INCLUDE_ZZIP__CONFIG_H
#define _INCLUDE_ZZIP__CONFIG_H 1
 
/* include/zzip/_config.h. Generated automatically at end of configure. */
/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* Define if pointers to integers require aligned access */
/* #undef HAVE_ALIGNED_ACCESS_REQUIRED */

/* Define to 1 if you have the <byteswap.h> header file. */
#ifndef ZZIP_HAVE_BYTESWAP_H 
#define ZZIP_HAVE_BYTESWAP_H  1 
#endif

/* Define to 1 if you have the <direct.h> header file. */
/* #undef HAVE_DIRECT_H */

/* Define to 1 if you have the <dirent.h> header file, and it defines `DIR'.
   */
#ifndef ZZIP_HAVE_DIRENT_H 
#define ZZIP_HAVE_DIRENT_H  1 
#endif

/* Define to 1 if you have the <fnmatch.h> header file. */
#ifndef ZZIP_HAVE_FNMATCH_H 
#define ZZIP_HAVE_FNMATCH_H  1 
#endif

/* Define to 1 if fseeko (and presumably ftello) exists and is declared. */
#ifndef ZZIP_HAVE_FSEEKO 
#define ZZIP_HAVE_FSEEKO  1 
#endif

/* Define to 1 if you have the <inttypes.h> header file. */
#ifndef ZZIP_HAVE_INTTYPES_H 
#define ZZIP_HAVE_INTTYPES_H  1 
#endif

/* Define to 1 if you have the <io.h> header file. */
/* #undef HAVE_IO_H */

/* Define to 1 if you have the <memory.h> header file. */
#ifndef ZZIP_HAVE_MEMORY_H 
#define ZZIP_HAVE_MEMORY_H  1 
#endif

/* Define to 1 if you have the <ndir.h> header file, and it defines `DIR'. */
/* #undef HAVE_NDIR_H */

/* Define to 1 if you have the <stdint.h> header file. */
#ifndef ZZIP_HAVE_STDINT_H 
#define ZZIP_HAVE_STDINT_H  1 
#endif

/* Define to 1 if you have the <stdlib.h> header file. */
#ifndef ZZIP_HAVE_STDLIB_H 
#define ZZIP_HAVE_STDLIB_H  1 
#endif

/* Define to 1 if you have the `strcasecmp' function. */
#ifndef ZZIP_HAVE_STRCASECMP 
#define ZZIP_HAVE_STRCASECMP  1 
#endif

/* Define to 1 if you have the <strings.h> header file. */
#ifndef ZZIP_HAVE_STRINGS_H 
#define ZZIP_HAVE_STRINGS_H  1 
#endif

/* Define to 1 if you have the <string.h> header file. */
#ifndef ZZIP_HAVE_STRING_H 
#define ZZIP_HAVE_STRING_H  1 
#endif

/* Define to 1 if you have the `strndup' function. */
#ifndef ZZIP_HAVE_STRNDUP 
#define ZZIP_HAVE_STRNDUP  1 
#endif

/* Define to 1 if you have the <sys/dir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_DIR_H */

/* Define to 1 if you have the <sys/int_types.h> header file. */
/* #undef HAVE_SYS_INT_TYPES_H */

/* Define to 1 if you have the <sys/mman.h> header file. */
#ifndef ZZIP_HAVE_SYS_MMAN_H 
#define ZZIP_HAVE_SYS_MMAN_H  1 
#endif

/* Define to 1 if you have the <sys/ndir.h> header file, and it defines `DIR'.
   */
/* #undef HAVE_SYS_NDIR_H */

/* Define to 1 if you have the <sys/param.h> header file. */
#ifndef ZZIP_HAVE_SYS_PARAM_H 
#define ZZIP_HAVE_SYS_PARAM_H  1 
#endif

/* Define to 1 if you have the <sys/stat.h> header file. */
#ifndef ZZIP_HAVE_SYS_STAT_H 
#define ZZIP_HAVE_SYS_STAT_H  1 
#endif

/* Define to 1 if you have the <sys/types.h> header file. */
#ifndef ZZIP_HAVE_SYS_TYPES_H 
#define ZZIP_HAVE_SYS_TYPES_H  1 
#endif

/* Define to 1 if you have the <unistd.h> header file. */
#ifndef ZZIP_HAVE_UNISTD_H 
#define ZZIP_HAVE_UNISTD_H  1 
#endif

/* Define to 1 if you have the <winbase.h> header file. */
/* #undef HAVE_WINBASE_H */

/* Define to 1 if you have the <windows.h> header file. */
/* #undef HAVE_WINDOWS_H */

/* Define to 1 if you have the <winnt.h> header file. */
/* #undef HAVE_WINNT_H */

/* Define to 1 if you have the <zlib.h> header file. */
#ifndef ZZIP_HAVE_ZLIB_H 
#define ZZIP_HAVE_ZLIB_H  1 
#endif

/* whether the system defaults to 32bit off_t but can do 64bit when requested
   */
/* #undef LARGEFILE_SENSITIVE */

/* Name of package */
#ifndef ZZIP_PACKAGE 
#define ZZIP_PACKAGE  "zziplib--tex-live-" 
#endif

/* Define to the address where bug reports for this package should be sent. */
#ifndef ZZIP_PACKAGE_BUGREPORT 
#define ZZIP_PACKAGE_BUGREPORT  "tex-k@tug.org" 
#endif

/* Define to the full name of this package. */
#ifndef ZZIP_PACKAGE_NAME 
#define ZZIP_PACKAGE_NAME  "zziplib (TeX Live)" 
#endif

/* Define to the full name and version of this package. */
#ifndef ZZIP_PACKAGE_STRING 
#define ZZIP_PACKAGE_STRING  "zziplib (TeX Live) 0.13.62" 
#endif

/* Define to the one symbol short name of this package. */
#ifndef ZZIP_PACKAGE_TARNAME 
#define ZZIP_PACKAGE_TARNAME  "zziplib--tex-live-" 
#endif

/* Define to the home page for this package. */
#ifndef ZZIP_PACKAGE_URL 
#define ZZIP_PACKAGE_URL  "" 
#endif

/* Define to the version of this package. */
#ifndef ZZIP_PACKAGE_VERSION 
#define ZZIP_PACKAGE_VERSION  "0.13.62" 
#endif

/* The size of `int', as computed by sizeof. */
#ifndef ZZIP_SIZEOF_INT 
#define ZZIP_SIZEOF_INT  4 
#endif

/* The size of `long', as computed by sizeof. */
#ifndef ZZIP_SIZEOF_LONG 
#define ZZIP_SIZEOF_LONG  8 
#endif

/* The size of `short', as computed by sizeof. */
#ifndef ZZIP_SIZEOF_SHORT 
#define ZZIP_SIZEOF_SHORT  2 
#endif

/* Define to 1 if you have the ANSI C header files. */
#ifndef ZZIP_STDC_HEADERS 
#define ZZIP_STDC_HEADERS  1 
#endif

/* Version number of package */
#ifndef ZZIP_VERSION 
#define ZZIP_VERSION  "0.13.62" 
#endif

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Define to 1 if <zlib.h> declares 'z_const'. */
#ifndef ZZIP_ZLIB_CONST 
#define ZZIP_ZLIB_CONST  1 
#endif

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

/* Define to `long long' if <sys/types.h> does not define. */
#ifndef ZZIP___int64 
#define ZZIP___int64  long long 
#endif

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `__inline__' or `__inline' if that's what the C compiler
   calls it, or to nothing if 'inline' is not supported under any name.  */
#ifndef __cplusplus
/* #undef inline */
#endif

/* Define to `_zzip_off_t' if <sys/types.h> does not define. */
#ifndef _zzip_off64_t 
#define _zzip_off64_t  _zzip_off_t 
#endif

/* Define to the equivalent of the C99 'restrict' keyword, or to
   nothing if this is not supported.  Do not define if restrict is
   supported directly.  */
#ifndef _zzip_restrict 
#define _zzip_restrict  __restrict 
#endif
/* Work around a bug in Sun C++: it does not support _Restrict or
   __restrict__, even though the corresponding Sun C compiler ends up with
   "#define restrict _Restrict" or "#define restrict __restrict__" in the
   previous line.  Perhaps some future version of Sun C++ will work with
   restrict; if so, hopefully it defines __RESTRICT like Sun C does.  */
#if defined __SUNPRO_CC && !defined __RESTRICT
# define _Restrict
# define __restrict__
#endif

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

/* Define to `int' if <sys/types.h> does not define. */
/* #undef ssize_t */

/* Define as empty if not declared in <zlib.h>. */
/* #undef z_const */
 
/* once: _INCLUDE_ZZIP__CONFIG_H */
#endif
