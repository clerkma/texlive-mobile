s/^#undef  *\([ABCDEFGHIJKLMNOPQRSTUVWXYZ_]\)/#undef ZZIP_\1/
s/^#undef  *\([abcdefghijklmnopqrstuvwxyz]\)/#undef _zzip_\1/
s/^#define  *\([ABCDEFGHIJKLMNOPQRSTUVWXYZ_][abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_]*\)\(.*\)/#ifndef ZZIP_\1 \
#define ZZIP_\1 \2 \
#endif/
s/^#define  *\([abcdefghijklmnopqrstuvwxyz][abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_]*\)\(.*\)/#ifndef _zzip_\1 \
#define _zzip_\1 \2 \
#endif/
