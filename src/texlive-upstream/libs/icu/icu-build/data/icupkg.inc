GENCCODE_ASSEMBLY_TYPE=-a gcc
SO=so
SOBJ=so
A=a
LIBPREFIX=lib
LIB_EXT_ORDER=.57.1
COMPILE=gcc -ffunction-sections -fdata-sections -D_REENTRANT  -DU_HAVE_ELF_H=1 -DU_ENABLE_DYLOAD=0 -DU_HAVE_ATOMIC=1  -DU_ATTRIBUTE_DEPRECATED= -O2   -c
LIBFLAGS=-I/home/maqiyuan/Desktop/texlive-upstream/libs/icu/icu-src/source/common -I../common -DPIC -fPIC
GENLIB=gcc -O2   -Wl,--gc-sections  -shared -Wl,-Bsymbolic
LDICUDTFLAGS=-nodefaultlibs -nostdlib
LD_SONAME=-Wl,-soname -Wl,
RPATH_FLAGS=
BIR_LDFLAGS=-Wl,-Bsymbolic
AR=ar
ARFLAGS=r
RANLIB=ranlib
INSTALL_CMD=/usr/bin/install -c
