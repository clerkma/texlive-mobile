/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.ac by autoheader.  */

/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP
   systems. This function is required for `alloca.c' support on those systems.
   */
/* #undef CRAY_STACKSEG_END */

/* Define to 1 if using `alloca.c'. */
/* #undef C_ALLOCA */

/* Define to 1 if you have `alloca', as a function or macro. */
#define HAVE_ALLOCA 1

/* Define to 1 if you have <alloca.h> and it should be used (not on Ultrix).
   */
#define HAVE_ALLOCA_H 1

/* Define if denormalized floats work. */
#define HAVE_DENORMS 1

/* Define to 1 if the system has the type `intmax_t'. */
#define HAVE_INTMAX_T 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define one of the following to 1 for the format of a `long double'.
   If your format is not among these choices, or you don't know what it is,
   then leave all undefined.
   IEEE_EXT is the 10-byte IEEE extended precision format.
   IEEE_QUAD is the 16-byte IEEE quadruple precision format.
   LITTLE or BIG is the endianness.  */
#define HAVE_LDOUBLE_IEEE_EXT_LITTLE 1
/* #undef HAVE_LDOUBLE_IEEE_QUAD_LITTLE */
/* #undef HAVE_LDOUBLE_IEEE_QUAD_BIG */

/* Define if compiler supports long long */
#define HAVE_LONG_LONG 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define if stdarg */
#define HAVE_STDARG 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#define HAVE_SYS_TIME_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if you have the `va_copy' function. */
#define HAVE_VA_COPY 1

/* Define to 1 if you have the <wchar.h> header file. */
#define HAVE_WCHAR_H 1

/* Define to 1 if you have the `__va_copy' function. */
/* #undef HAVE___VA_COPY */

/* Define if the FP division by 0 fails. */
/* #undef MPFR_ERRDIVZERO */

/* Define if you have the `fesetround' function via the <fenv.h> header file.
   */
#define MPFR_HAVE_FESETROUND 1

/* Define if you have a working INTMAX_MAX. */
#define MPFR_HAVE_INTMAX_MAX 1

/* Define if NAN == NAN. */
/* #undef MPFR_NANISNAN */

/* Charset is not consecutive */
/* #undef MPFR_NO_CONSECUTIVE_CHARSET */

/* gmp_printf cannot use `hh' length modifier */
#define NPRINTF_HH 1

/* gmp_printf cannot read intmax_t */
#define NPRINTF_J 1

/* gmp_printf cannot read long double */
#define NPRINTF_L 1

/* gmp_printf cannot read long long int */
#define NPRINTF_LL 1

/* gmp_printf cannot read ptrdiff_t */
#define NPRINTF_T 1

/* Name of package */
#define PACKAGE "mpfr--tex-live-"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "tex-k@tug.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "mpfr (TeX Live)"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "mpfr (TeX Live) 3.1.4"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "mpfr--tex-live-"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.1.4"

/* Define to `((size_t)-1)' if <stdint.h> does not define it. */
/* #undef SIZE_MAX */

/* If using the C implementation of alloca, define if you know the
   direction of stack growth for your system; otherwise it will be
   automatically deduced at runtime.
	STACK_DIRECTION > 0 => grows toward higher addresses
	STACK_DIRECTION < 0 => grows toward lower addresses
	STACK_DIRECTION = 0 => direction of growth unknown */
/* #undef STACK_DIRECTION */

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* Version number of package */
#define VERSION "3.1.4"

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */
