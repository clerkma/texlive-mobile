#undef TRIP
#undef TRAP
#define STAT
#define INI
#define INITEX
#define TeX
#define upTeX
#ifdef TEXMF_DEBUG
#endif /* TEXMF_DEBUG */
#define UPTEXCOERCE
#include "texmfmp.h"
#define hashoffset ( 514 ) 
#define trieopsize ( 35111L ) 
#define negtrieopsize ( -35111L ) 
#define mintrieop ( 0 ) 
#define maxtrieop ( 65535L ) 
#define poolname ( TEXMFPOOLNAME ) 
#define enginename ( TEXMFENGINENAME ) 
#define infmembot ( 0 ) 
#define supmembot ( 1 ) 
#define infmainmemory ( 3000 ) 
#define supmainmemory ( 256000000L ) 
#define inftriesize ( 8000 ) 
#define suptriesize ( 4194303L ) 
#define infmaxstrings ( 3000 ) 
#define supmaxstrings ( 2097151L ) 
#define infstringsfree ( 100 ) 
#define supstringsfree ( supmaxstrings ) 
#define infbufsize ( 500 ) 
#define supbufsize ( 30000000L ) 
#define infnestsize ( 40 ) 
#define supnestsize ( 4000 ) 
#define infmaxinopen ( 6 ) 
#define supmaxinopen ( 127 ) 
#define infparamsize ( 60 ) 
#define supparamsize ( 32767 ) 
#define infsavesize ( 600 ) 
#define supsavesize ( 80000L ) 
#define infstacksize ( 200 ) 
#define supstacksize ( 30000 ) 
#define infdvibufsize ( 800 ) 
#define supdvibufsize ( 65536L ) 
#define inffontmemsize ( 20000 ) 
#define supfontmemsize ( 147483647L ) 
#define supfontmax ( 9000 ) 
#define inffontmax ( 50 ) 
#define infpoolsize ( 32000 ) 
#define suppoolsize ( 40000000L ) 
#define infpoolfree ( 1000 ) 
#define suppoolfree ( suppoolsize ) 
#define infstringvacancies ( 8000 ) 
#define supstringvacancies ( suppoolsize - 23000 ) 
#define suphashextra ( supmaxstrings ) 
#define infhashextra ( 0 ) 
#define suphyphsize ( 65535L ) 
#define infhyphsize ( 610 ) 
#define infexpanddepth ( 10 ) 
#define supexpanddepth ( 10000000L ) 
typedef unsigned char ASCIIcode  ;
typedef integer KANJIcode  ;
typedef unsigned char eightbits  ;
typedef unsigned short sixteenbits  ;
typedef text /* of  ASCIIcode */ alphafile  ;
typedef text /* of  eightbits */ bytefile  ;
typedef integer poolpointer  ;
typedef integer strnumber  ;
typedef unsigned char packedASCIIcode  ;
typedef integer scaled  ;
typedef integer nonnegativeinteger  ;
typedef unsigned char smallnumber  ;
typedef unsigned short quarterword  ;
typedef integer halfword  ;
typedef unsigned char twochoices  ;
typedef unsigned char fourchoices  ;
#include "texmfmem.h"
typedef text /* of  memoryword */ wordfile  ;
typedef unsigned char glueord  ;
typedef struct {
    short modefield ;
  schar dirfield, adjdirfield ;
  scaled pdispfield ;
  halfword headfield, tailfield, pnodefield, lastjchrfield ;
  integer pgfield, mlfield ;
  memoryword auxfield ;
} liststaterecord  ;
typedef unsigned char groupcode  ;
typedef struct {
    quarterword statefield, indexfield ;
  halfword startfield, locfield, limitfield, namefield ;
  integer synctextagfield ;
} instaterecord  ;
typedef integer internalfontnumber  ;
typedef integer fontindex  ;
typedef short ninebits  ;
typedef integer dviindex  ;
typedef integer triepointer  ;
typedef unsigned short trieopcode  ;
typedef unsigned short hyphpointer  ;
EXTERN integer bad  ;
EXTERN ASCIIcode xord[256]  ;
EXTERN ASCIIcode xchr[256]  ;
EXTERN ASCIIcode xprn[256]  ;
EXTERN ASCIIcode * nameoffile  ;
EXTERN integer namelength  ;
EXTERN ASCIIcode * buffer  ;
EXTERN integer first  ;
EXTERN integer last  ;
EXTERN integer maxbufstack  ;
#ifdef INITEX
EXTERN boolean iniversion  ;
EXTERN boolean dumpoption  ;
EXTERN boolean dumpline  ;
#endif /* INITEX */
EXTERN constcstring dumpname  ;
EXTERN integer bounddefault  ;
EXTERN constcstring boundname  ;
EXTERN integer membot  ;
EXTERN integer mainmemory  ;
EXTERN integer extramembot  ;
EXTERN integer memmin  ;
EXTERN integer memtop  ;
EXTERN integer extramemtop  ;
EXTERN integer memmax  ;
EXTERN integer errorline  ;
EXTERN integer halferrorline  ;
EXTERN integer maxprintline  ;
EXTERN integer maxstrings  ;
EXTERN integer stringsfree  ;
EXTERN integer stringvacancies  ;
EXTERN integer poolsize  ;
EXTERN integer poolfree  ;
EXTERN integer fontmemsize  ;
EXTERN integer fontmax  ;
EXTERN integer fontk  ;
EXTERN integer hyphsize  ;
EXTERN integer triesize  ;
EXTERN integer bufsize  ;
EXTERN integer stacksize  ;
EXTERN integer maxinopen  ;
EXTERN integer paramsize  ;
EXTERN integer nestsize  ;
EXTERN integer savesize  ;
EXTERN integer dvibufsize  ;
EXTERN integer expanddepth  ;
EXTERN cinttype parsefirstlinep  ;
EXTERN cinttype filelineerrorstylep  ;
EXTERN cinttype eightbitp  ;
EXTERN cinttype haltonerrorp  ;
EXTERN boolean quotedfilename  ;
EXTERN boolean srcspecialsp  ;
EXTERN boolean insertsrcspecialauto  ;
EXTERN boolean insertsrcspecialeverypar  ;
EXTERN boolean insertsrcspecialeveryparend  ;
EXTERN boolean insertsrcspecialeverycr  ;
EXTERN boolean insertsrcspecialeverymath  ;
EXTERN boolean insertsrcspecialeveryhbox  ;
EXTERN boolean insertsrcspecialeveryvbox  ;
EXTERN boolean insertsrcspecialeverydisplay  ;
EXTERN packedASCIIcode * strpool  ;
EXTERN poolpointer * strstart  ;
EXTERN poolpointer poolptr  ;
EXTERN strnumber strptr  ;
EXTERN poolpointer initpoolptr  ;
EXTERN strnumber initstrptr  ;
#ifdef INITEX
EXTERN alphafile poolfile  ;
#endif /* INITEX */
EXTERN alphafile logfile  ;
EXTERN unsigned char selector  ;
EXTERN unsigned char dig[23]  ;
EXTERN integer tally  ;
EXTERN integer termoffset  ;
EXTERN integer fileoffset  ;
EXTERN ASCIIcode trickbuf[256]  ;
EXTERN unsigned char trickbuf2[256]  ;
EXTERN unsigned char kcodepos  ;
EXTERN unsigned char kcp  ;
EXTERN ASCIIcode prevchar  ;
EXTERN integer trickcount  ;
EXTERN integer firstcount  ;
EXTERN unsigned char interaction  ;
EXTERN unsigned char interactionoption  ;
EXTERN boolean deletionsallowed  ;
EXTERN boolean setboxallowed  ;
EXTERN unsigned char history  ;
EXTERN schar errorcount  ;
EXTERN strnumber helpline[6]  ;
EXTERN unsigned char helpptr  ;
EXTERN boolean useerrhelp  ;
EXTERN integer interrupt  ;
EXTERN boolean OKtointerrupt  ;
EXTERN boolean aritherror  ;
EXTERN scaled texremainder  ;
EXTERN halfword tempptr  ;
EXTERN memoryword * yzmem  ;
EXTERN memoryword * zmem  ;
EXTERN halfword lomemmax  ;
EXTERN halfword himemmin  ;
EXTERN integer varused, dynused  ;
EXTERN halfword avail  ;
EXTERN halfword memend  ;
EXTERN halfword rover  ;
#ifdef TEXMF_DEBUG
EXTERN boolean freearr[10]  ;
EXTERN boolean wasfree[10]  ;
EXTERN halfword wasmemend, waslomax, washimin  ;
EXTERN boolean panicking  ;
#endif /* TEXMF_DEBUG */
EXTERN integer fontinshortdisplay  ;
EXTERN integer depththreshold  ;
EXTERN integer breadthmax  ;
EXTERN liststaterecord * nest  ;
EXTERN integer nestptr  ;
EXTERN integer maxneststack  ;
EXTERN liststaterecord curlist  ;
EXTERN short shownmode  ;
EXTERN unsigned char oldsetting  ;
EXTERN memoryword * zeqtb  ;
EXTERN quarterword 
#define xeqlevel (zzzaa -28462)
  zzzaa[1111]  ;
EXTERN twohalves * hash  ;
EXTERN twohalves * yhash  ;
EXTERN halfword hashused  ;
EXTERN halfword hashextra  ;
EXTERN halfword hashtop  ;
EXTERN halfword eqtbtop  ;
EXTERN halfword hashhigh  ;
EXTERN boolean nonewcontrolsequence  ;
EXTERN integer cscount  ;
EXTERN memoryword * savestack  ;
EXTERN integer saveptr  ;
EXTERN integer maxsavestack  ;
EXTERN quarterword curlevel  ;
EXTERN groupcode curgroup  ;
EXTERN integer curboundary  ;
EXTERN integer magset  ;
EXTERN eightbits curcmd  ;
EXTERN halfword curchr  ;
EXTERN halfword curcs  ;
EXTERN halfword curtok  ;
EXTERN instaterecord * inputstack  ;
EXTERN integer inputptr  ;
EXTERN integer maxinstack  ;
EXTERN instaterecord curinput  ;
EXTERN integer inopen  ;
EXTERN integer openparens  ;
EXTERN alphafile * inputfile  ;
EXTERN integer line  ;
EXTERN integer * linestack  ;
EXTERN strnumber * sourcefilenamestack  ;
EXTERN strnumber * fullsourcefilenamestack  ;
EXTERN unsigned char scannerstatus  ;
EXTERN halfword warningindex  ;
EXTERN halfword defref  ;
EXTERN halfword * paramstack  ;
EXTERN integer paramptr  ;
EXTERN integer maxparamstack  ;
EXTERN integer alignstate  ;
EXTERN integer baseptr  ;
EXTERN halfword parloc  ;
EXTERN halfword partoken  ;
EXTERN boolean skipmode  ;
EXTERN boolean forceeof  ;
EXTERN integer expanddepthcount  ;
EXTERN halfword curmark[5]  ;
EXTERN unsigned char longstate  ;
EXTERN halfword pstack[9]  ;
EXTERN integer curval  ;
EXTERN unsigned char curvallevel  ;
EXTERN smallnumber radix  ;
EXTERN glueord curorder  ;
EXTERN alphafile readfile[16]  ;
EXTERN unsigned char readopen[17]  ;
EXTERN halfword condptr  ;
EXTERN unsigned char iflimit  ;
EXTERN smallnumber curif  ;
EXTERN integer ifline  ;
EXTERN integer skipline  ;
EXTERN strnumber curname  ;
EXTERN strnumber curarea  ;
EXTERN strnumber curext  ;
EXTERN poolpointer areadelimiter  ;
EXTERN poolpointer extdelimiter  ;
EXTERN integer formatdefaultlength  ;
EXTERN cstring TEXformatdefault  ;
EXTERN boolean nameinprogress  ;
EXTERN strnumber jobname  ;
EXTERN boolean logopened  ;
EXTERN bytefile dvifile  ;
EXTERN strnumber outputfilename  ;
EXTERN strnumber texmflogname  ;
EXTERN bytefile tfmfile  ;
EXTERN memoryword * fontinfo  ;
EXTERN eightbits * fontdir  ;
EXTERN integer * fontnumext  ;
EXTERN fontindex fmemptr  ;
EXTERN internalfontnumber fontptr  ;
EXTERN fourquarters * fontcheck  ;
EXTERN scaled * fontsize  ;
EXTERN scaled * fontdsize  ;
EXTERN fontindex * fontparams  ;
EXTERN strnumber * fontname  ;
EXTERN strnumber * fontarea  ;
EXTERN eightbits * fontbc  ;
EXTERN eightbits * fontec  ;
EXTERN halfword * fontglue  ;
EXTERN boolean * fontused  ;
EXTERN integer * hyphenchar  ;
EXTERN integer * skewchar  ;
EXTERN fontindex * bcharlabel  ;
EXTERN ninebits * fontbchar  ;
EXTERN ninebits * fontfalsebchar  ;
EXTERN integer * charbase  ;
EXTERN integer * ctypebase  ;
EXTERN integer * widthbase  ;
EXTERN integer * heightbase  ;
EXTERN integer * depthbase  ;
EXTERN integer * italicbase  ;
EXTERN integer * ligkernbase  ;
EXTERN integer * kernbase  ;
EXTERN integer * extenbase  ;
EXTERN integer * parambase  ;
EXTERN fourquarters nullcharacter  ;
EXTERN integer totalpages  ;
EXTERN scaled maxv  ;
EXTERN scaled maxh  ;
EXTERN integer maxpush  ;
EXTERN integer lastbop  ;
EXTERN integer deadcycles  ;
EXTERN boolean doingleaders  ;
EXTERN quarterword c  ;
EXTERN internalfontnumber f  ;
EXTERN boolean dirused  ;
EXTERN scaled ruleht, ruledp, rulewd  ;
EXTERN halfword g  ;
EXTERN integer lq, lr  ;
EXTERN eightbits * dvibuf  ;
EXTERN integer halfbuf  ;
EXTERN integer dvilimit  ;
EXTERN integer dviptr  ;
EXTERN integer dvioffset  ;
EXTERN integer dvigone  ;
EXTERN halfword downptr, rightptr  ;
EXTERN scaled dvih, dviv  ;
EXTERN scaled curh, curv  ;
EXTERN internalfontnumber dvif  ;
EXTERN integer curs  ;
EXTERN scaled totalstretch[4], totalshrink[4]  ;
EXTERN integer lastbadness  ;
EXTERN halfword adjusttail  ;
EXTERN scaled lastdisp  ;
EXTERN halfword curkanjiskip  ;
EXTERN halfword curxkanjiskip  ;
EXTERN integer packbeginline  ;
EXTERN twohalves emptyfield  ;
EXTERN fourquarters nulldelimiter  ;
EXTERN halfword curmlist  ;
EXTERN smallnumber curstyle  ;
EXTERN smallnumber cursize  ;
EXTERN scaled curmu  ;
EXTERN boolean mlistpenalties  ;
EXTERN internalfontnumber curf  ;
EXTERN quarterword curc  ;
EXTERN fourquarters curi  ;
EXTERN integer magicoffset  ;
EXTERN halfword curalign  ;
EXTERN halfword curspan  ;
EXTERN halfword curloop  ;
EXTERN halfword alignptr  ;
EXTERN halfword curhead, curtail  ;
EXTERN halfword justbox  ;
EXTERN halfword passive  ;
EXTERN halfword printednode  ;
EXTERN halfword passnumber  ;
EXTERN scaled activewidth[7]  ;
EXTERN scaled curactivewidth[7]  ;
EXTERN scaled background[7]  ;
EXTERN scaled breakwidth[7]  ;
EXTERN boolean noshrinkerroryet  ;
EXTERN halfword curp  ;
EXTERN boolean chain  ;
EXTERN boolean secondpass  ;
EXTERN boolean finalpass  ;
EXTERN integer threshold  ;
EXTERN integer minimaldemerits[4]  ;
EXTERN integer minimumdemerits  ;
EXTERN halfword bestplace[4]  ;
EXTERN halfword bestplline[4]  ;
EXTERN scaled discwidth  ;
EXTERN halfword easyline  ;
EXTERN halfword lastspecialline  ;
EXTERN scaled firstwidth  ;
EXTERN scaled secondwidth  ;
EXTERN scaled firstindent  ;
EXTERN scaled secondindent  ;
EXTERN halfword bestbet  ;
EXTERN integer fewestdemerits  ;
EXTERN halfword bestline  ;
EXTERN integer actuallooseness  ;
EXTERN integer linediff  ;
EXTERN short hc[66]  ;
EXTERN smallnumber hn  ;
EXTERN halfword ha, hb  ;
EXTERN internalfontnumber hf  ;
EXTERN short hu[64]  ;
EXTERN integer hyfchar  ;
EXTERN ASCIIcode curlang, initcurlang  ;
EXTERN integer lhyf, rhyf, initlhyf, initrhyf  ;
EXTERN halfword hyfbchar  ;
EXTERN unsigned char hyf[65]  ;
EXTERN halfword initlist  ;
EXTERN boolean initlig  ;
EXTERN boolean initlft  ;
EXTERN smallnumber hyphenpassed  ;
EXTERN halfword curl, curr  ;
EXTERN halfword curq  ;
EXTERN halfword ligstack  ;
EXTERN boolean ligaturepresent  ;
EXTERN boolean lfthit, rthit  ;
EXTERN triepointer * trietrl  ;
EXTERN triepointer * trietro  ;
EXTERN quarterword * trietrc  ;
EXTERN smallnumber hyfdistance[trieopsize + 1]  ;
EXTERN smallnumber hyfnum[trieopsize + 1]  ;
EXTERN trieopcode hyfnext[trieopsize + 1]  ;
EXTERN integer opstart[256]  ;
EXTERN strnumber * hyphword  ;
EXTERN halfword * hyphlist  ;
EXTERN hyphpointer * hyphlink  ;
EXTERN integer hyphcount  ;
EXTERN integer hyphnext  ;
#ifdef INITEX
EXTERN integer 
#define trieophash (zzzab - (int)(negtrieopsize))
  zzzab[trieopsize - negtrieopsize + 1]  ;
EXTERN trieopcode trieused[256]  ;
EXTERN ASCIIcode trieoplang[trieopsize + 1]  ;
EXTERN trieopcode trieopval[trieopsize + 1]  ;
EXTERN integer trieopptr  ;
#endif /* INITEX */
EXTERN trieopcode maxopused  ;
EXTERN boolean smallop  ;
#ifdef INITEX
EXTERN packedASCIIcode * triec  ;
EXTERN trieopcode * trieo  ;
EXTERN triepointer * triel  ;
EXTERN triepointer * trier  ;
EXTERN triepointer trieptr  ;
EXTERN triepointer * triehash  ;
#endif /* INITEX */
#ifdef INITEX
EXTERN boolean * trietaken  ;
EXTERN triepointer triemin[256]  ;
EXTERN triepointer triemax  ;
EXTERN boolean trienotready  ;
#endif /* INITEX */
EXTERN scaled bestheightplusdepth  ;
EXTERN halfword pagetail  ;
EXTERN unsigned char pagecontents  ;
EXTERN scaled pagemaxdepth  ;
EXTERN halfword bestpagebreak  ;
EXTERN integer leastpagecost  ;
EXTERN scaled bestsize  ;
EXTERN scaled pagesofar[8]  ;
EXTERN halfword lastglue  ;
EXTERN integer lastpenalty  ;
EXTERN scaled lastkern  ;
EXTERN integer insertpenalties  ;
EXTERN boolean outputactive  ;
EXTERN internalfontnumber mainf  ;
EXTERN fourquarters maini  ;
EXTERN fourquarters mainj  ;
EXTERN fontindex maink  ;
EXTERN halfword mainp  ;
EXTERN integer mains  ;
EXTERN halfword bchar  ;
EXTERN halfword falsebchar  ;
EXTERN boolean cancelboundary  ;
EXTERN boolean insdisc  ;
EXTERN halfword curbox  ;
EXTERN halfword aftertoken  ;
EXTERN boolean longhelpseen  ;
EXTERN strnumber formatident  ;
EXTERN wordfile fmtfile  ;
EXTERN integer readyalready  ;
EXTERN alphafile writefile[16]  ;
EXTERN boolean writeopen[18]  ;
EXTERN halfword writeloc  ;
EXTERN poolpointer editnamestart  ;
EXTERN integer editnamelength, editline  ;
EXTERN cinttype ipcon  ;
EXTERN boolean stopatspace  ;
EXTERN strnumber savestrptr  ;
EXTERN poolpointer savepoolptr  ;
EXTERN cinttype shellenabledp  ;
EXTERN cinttype restrictedshell  ;
EXTERN char * outputcomment  ;
EXTERN unsigned char k, l  ;
EXTERN boolean debugformatfile  ;
EXTERN boolean mltexp  ;
EXTERN boolean mltexenabledp  ;
EXTERN integer accentc, basec, replacec  ;
EXTERN fourquarters iac, ibc  ;
EXTERN real baseslant, accentslant  ;
EXTERN scaled basexheight  ;
EXTERN scaled basewidth, baseheight  ;
EXTERN scaled accentwidth, accentheight  ;
EXTERN scaled delta  ;
EXTERN integer synctexoption  ;
EXTERN integer synctexoffset  ;
EXTERN boolean inhibitglueflag  ;
EXTERN integer dvidir  ;
EXTERN integer curdirhv  ;
EXTERN eightbits pagedir  ;
EXTERN halfword firstchar  ;
EXTERN halfword lastchar  ;
EXTERN boolean findfirstchar  ;

#include "uptexcoerce.h"
