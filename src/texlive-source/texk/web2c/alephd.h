#undef TRIP
#undef TRAP
#define STAT
#define INI
#define INITEX
#define TeX
#define Aleph
#ifdef TEXMF_DEBUG
#endif /* TEXMF_DEBUG */
#define ALEPHCOERCE
#include "texmfmp.h"
#define membot ( 0 ) 
#define fontmax ( 65535L ) 
#define hashoffset ( 514 ) 
#define trieopsize ( 15011 ) 
#define negtrieopsize ( -35111L ) 
#define mintrieop ( 0 ) 
#define maxtrieop ( 65535L ) 
#define poolname ( TEXMFPOOLNAME ) 
#define enginename ( TEXMFENGINENAME ) 
#define infmainmemory ( 2000000L ) 
#define supmainmemory ( 256000000L ) 
#define inftriesize ( 80000L ) 
#define suptriesize ( 4194303L ) 
#define infmaxstrings ( 100000L ) 
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
#define supparamsize ( 6000 ) 
#define infsavesize ( 600 ) 
#define supsavesize ( 80000L ) 
#define infstacksize ( 200 ) 
#define supstacksize ( 30000 ) 
#define infdvibufsize ( 800 ) 
#define supdvibufsize ( 65536L ) 
#define infpoolsize ( 32000 ) 
#define suppoolsize ( 40000000L ) 
#define infpoolfree ( 1000 ) 
#define suppoolfree ( suppoolsize ) 
#define infstringvacancies ( 8000 ) 
#define supstringvacancies ( suppoolsize - 23000 ) 
#define suphyphsize ( 65535L ) 
#define infhyphsize ( 610 ) 
#define supocplistsize ( 1000000L ) 
#define infocplistsize ( 1000 ) 
#define supocpbufsize ( 1000000L ) 
#define infocpbufsize ( 1000 ) 
#define supocpstacksize ( 1000000L ) 
#define infocpstacksize ( 1000 ) 
#define activememsize ( 50000L ) 
#define ocpmaxint ( 268435456L ) 
typedef unsigned short ASCIIcode  ;
typedef unsigned short eightbits  ;
typedef unsigned char realeightbits  ;
typedef text /* of  ASCIIcode */ alphafile  ;
typedef text /* of  realeightbits */ bytefile  ;
typedef integer poolpointer  ;
typedef integer strnumber  ;
typedef unsigned short packedASCIIcode  ;
typedef integer scaled  ;
typedef integer nonnegativeinteger  ;
typedef unsigned char smallnumber  ;
typedef unsigned short quarterword  ;
typedef integer halfword  ;
typedef unsigned char twochoices  ;
typedef unsigned char fourchoices  ;
#include "texmfmem.h"
#include "alephmem.h"
typedef text /* of  memoryword */ wordfile  ;
typedef unsigned char glueord  ;
typedef struct {
    short modefield ;
  halfword headfield, tailfield ;
  halfword eTeXauxfield ;
  integer pgfield, mlfield ;
  memoryword auxfield ;
  halfword dirsfield ;
  integer mathfield ;
  halfword localparfield ;
  boolean localparboolfield ;
} liststaterecord  ;
typedef unsigned char groupcode  ;
typedef struct {
    quarterword statefield, indexfield ;
  halfword startfield, locfield, limitfield, namefield, ocplstackfield ;
  halfword ocpnofield ;
} instaterecord  ;
typedef integer internalfontnumber  ;
typedef integer fontindex  ;
typedef integer activeindex  ;
typedef unsigned short internalocpnumber  ;
typedef integer ocpindex  ;
typedef unsigned short internalocplistnumber  ;
typedef integer ocplistindex  ;
typedef integer ocplstackindex  ;
typedef integer dviindex  ;
typedef integer triepointer  ;
typedef unsigned short hyphpointer  ;
typedef integer savepointer  ;
EXTERN integer bad  ;
EXTERN ASCIIcode xchr[256]  ;
EXTERN char * nameoffile  ;
EXTERN integer namelength  ;
EXTERN ASCIIcode * buffer  ;
EXTERN integer first  ;
EXTERN integer last  ;
EXTERN integer maxbufstack  ;
EXTERN halfword terminmode  ;
EXTERN halfword termintranslation  ;
#ifdef INITEX
EXTERN boolean iniversion  ;
EXTERN boolean dumpoption  ;
EXTERN boolean dumpline  ;
#endif /* INITEX */
EXTERN constcstring dumpname  ;
EXTERN integer bounddefault  ;
EXTERN constcstring boundname  ;
EXTERN integer mainmemory  ;
EXTERN integer extramembot  ;
EXTERN integer memmin  ;
EXTERN integer memtop  ;
EXTERN integer extramemtop  ;
EXTERN integer memmax  ;
EXTERN integer errorline  ;
EXTERN integer halferrorline  ;
EXTERN integer maxprintline  ;
EXTERN integer ocplistsize  ;
EXTERN integer ocpbufsize  ;
EXTERN integer ocpstacksize  ;
EXTERN integer maxstrings  ;
EXTERN integer stringsfree  ;
EXTERN integer stringvacancies  ;
EXTERN integer poolsize  ;
EXTERN integer poolfree  ;
EXTERN integer hyphsize  ;
EXTERN integer triesize  ;
EXTERN integer bufsize  ;
EXTERN integer stacksize  ;
EXTERN integer maxinopen  ;
EXTERN integer paramsize  ;
EXTERN integer nestsize  ;
EXTERN integer savesize  ;
EXTERN integer dvibufsize  ;
EXTERN boolean quotedfilename  ;
EXTERN halfword specialloc  ;
EXTERN halfword specialtoken  ;
EXTERN cinttype parsefirstlinep  ;
EXTERN cinttype filelineerrorstylep  ;
EXTERN boolean haltonerrorp  ;
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
EXTERN poolpointer * strstartar  ;
EXTERN poolpointer poolptr  ;
EXTERN strnumber strptr  ;
EXTERN poolpointer initpoolptr  ;
EXTERN strnumber initstrptr  ;
#ifdef INITEX
EXTERN alphafile poolfile  ;
#endif /* INITEX */
EXTERN alphafile logfile  ;
EXTERN halfword termoutmode  ;
EXTERN halfword termouttranslation  ;
EXTERN unsigned char selector  ;
EXTERN unsigned char dig[23]  ;
EXTERN integer tally  ;
EXTERN integer termoffset  ;
EXTERN integer fileoffset  ;
EXTERN ASCIIcode trickbuf[256]  ;
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
EXTERN halfword hashused  ;
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
EXTERN halfword * inputfilemode  ;
EXTERN halfword * inputfiletranslation  ;
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
EXTERN boolean forceeof  ;
EXTERN halfword curmark[5]  ;
EXTERN unsigned char longstate  ;
EXTERN halfword pstack[9]  ;
EXTERN integer curval  ;
EXTERN integer curval1  ;
EXTERN unsigned char curvallevel  ;
EXTERN smallnumber radix  ;
EXTERN glueord curorder  ;
EXTERN alphafile readfile[16]  ;
EXTERN halfword readfilemode[16]  ;
EXTERN halfword readfiletranslation[16]  ;
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
EXTERN char * TEXformatdefault  ;
EXTERN boolean nameinprogress  ;
EXTERN strnumber jobname  ;
EXTERN boolean logopened  ;
EXTERN bytefile dvifile  ;
EXTERN strnumber outputfilename  ;
EXTERN strnumber texmflogname  ;
EXTERN bytefile tfmfile  ;
EXTERN internalfontnumber fontptr  ;
EXTERN integer dimenfont  ;
EXTERN fourquarters nullcharacter  ;
EXTERN memoryword activeinfo[activememsize + 1]  ;
EXTERN activeindex activeminptr  ;
EXTERN activeindex activemaxptr  ;
EXTERN activeindex activereal  ;
EXTERN ocplistindex holding[activememsize + 1]  ;
EXTERN bytefile ocpfile  ;
EXTERN internalocpnumber ocpptr  ;
EXTERN memoryword * ocplistinfo  ;
EXTERN ocplistindex ocplistmemptr  ;
EXTERN ocplistindex ocplistmemrunptr  ;
EXTERN memoryword * ocplstackinfo  ;
EXTERN ocplstackindex ocplstackmemptr  ;
EXTERN ocplstackindex ocplstackmemrunptr  ;
EXTERN internalocplistnumber ocplistptr  ;
EXTERN ocplistindex * ocplistlist  ;
EXTERN integer totalpages  ;
EXTERN scaled maxv  ;
EXTERN scaled maxh  ;
EXTERN integer maxpush  ;
EXTERN integer lastbop  ;
EXTERN integer deadcycles  ;
EXTERN boolean doingleaders  ;
EXTERN quarterword c, f  ;
EXTERN integer oval, ocmd  ;
EXTERN scaled ruleht, ruledp, rulewd  ;
EXTERN halfword g  ;
EXTERN integer lq, lr  ;
EXTERN realeightbits * dvibuf  ;
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
EXTERN integer packdirection  ;
EXTERN integer specdirection  ;
EXTERN scaled totalstretch[5], totalshrink[5]  ;
EXTERN integer lastbadness  ;
EXTERN halfword adjusttail  ;
EXTERN integer packbeginline  ;
EXTERN twohalves emptyfield  ;
EXTERN fourquarters nulldelimiter  ;
EXTERN halfword curmlist  ;
EXTERN integer curstyle  ;
EXTERN integer cursize  ;
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
EXTERN integer internalpeninter  ;
EXTERN integer internalpenbroken  ;
EXTERN halfword internalleftbox  ;
EXTERN integer internalleftboxwidth  ;
EXTERN halfword initinternalleftbox  ;
EXTERN integer initinternalleftboxwidth  ;
EXTERN halfword internalrightbox  ;
EXTERN integer internalrightboxwidth  ;
EXTERN integer paragraphdir  ;
EXTERN integer linebreakdir  ;
EXTERN quarterword breakchtdp  ;
EXTERN integer tempnowhatsits  ;
EXTERN integer tempnodirs  ;
EXTERN integer temporarydir  ;
EXTERN halfword dirptr, dirtmp, dirrover  ;
EXTERN halfword passive  ;
EXTERN halfword printednode  ;
EXTERN halfword passnumber  ;
EXTERN halfword finalparglue  ;
EXTERN scaled activewidth[8]  ;
EXTERN scaled curactivewidth[8]  ;
EXTERN scaled background[8]  ;
EXTERN scaled breakwidth[8]  ;
EXTERN boolean noshrinkerroryet  ;
EXTERN halfword curp  ;
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
EXTERN integer hc[66]  ;
EXTERN smallnumber hn  ;
EXTERN halfword ha, hb  ;
EXTERN internalfontnumber hf  ;
EXTERN integer hu[64]  ;
EXTERN integer hyfchar  ;
EXTERN unsigned char curlang, initcurlang  ;
EXTERN integer lhyf, rhyf, initlhyf, initrhyf  ;
EXTERN halfword hyfbchar  ;
EXTERN integer maxhyphchar  ;
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
EXTERN twohalves * trie  ;
EXTERN smallnumber hyfdistance[trieopsize + 1]  ;
EXTERN smallnumber hyfnum[trieopsize + 1]  ;
EXTERN quarterword hyfnext[trieopsize + 1]  ;
EXTERN integer opstart[256]  ;
EXTERN strnumber * hyphword  ;
EXTERN halfword * hyphlist  ;
EXTERN hyphpointer * hyphlink  ;
EXTERN integer hyphcount  ;
EXTERN integer hyphnext  ;
#ifdef INITEX
EXTERN integer 
#define trieophash (zzzaa - (int)(negtrieopsize))
  zzzaa[trieopsize - negtrieopsize + 1]  ;
EXTERN quarterword trieused[256]  ;
EXTERN unsigned char trieoplang[trieopsize + 1]  ;
EXTERN quarterword trieopval[trieopsize + 1]  ;
EXTERN integer trieopptr  ;
#endif /* INITEX */
#ifdef INITEX
EXTERN ASCIIcode * triec  ;
EXTERN quarterword * trieo  ;
EXTERN triepointer * triel  ;
EXTERN triepointer * trier  ;
EXTERN triepointer trieptr  ;
EXTERN triepointer * triehash  ;
#endif /* INITEX */
#ifdef INITEX
EXTERN boolean * trietaken  ;
EXTERN triepointer * triemin  ;
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
EXTERN integer lastnodetype  ;
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
EXTERN boolean leftghost  ;
EXTERN boolean rightghost  ;
EXTERN boolean newleftghost  ;
EXTERN boolean newrightghost  ;
EXTERN boolean insdisc  ;
EXTERN integer kglue  ;
EXTERN halfword fontgluespec  ;
EXTERN halfword curbox  ;
EXTERN halfword aftertoken  ;
EXTERN boolean longhelpseen  ;
EXTERN strnumber formatident  ;
EXTERN wordfile fmtfile  ;
EXTERN integer readyalready  ;
EXTERN unsigned char outsidestringarray[1001]  ;
EXTERN alphafile writefile[16]  ;
EXTERN halfword writefilemode[16]  ;
EXTERN halfword writefiletranslation[16]  ;
EXTERN boolean writeopen[18]  ;
EXTERN scaled negwd  ;
EXTERN scaled poswd  ;
EXTERN scaled neght  ;
EXTERN integer dvidirection  ;
EXTERN unsigned char dirprimary[32]  ;
EXTERN unsigned char dirsecondary[32]  ;
EXTERN unsigned char dirtertiary[32]  ;
EXTERN unsigned char dirrearrange[4]  ;
EXTERN strnumber dirnames[4]  ;
EXTERN halfword textdirptr  ;
EXTERN halfword textdirtmp  ;
EXTERN halfword writeloc  ;
EXTERN unsigned char eTeXmode  ;
EXTERN boolean etexp  ;
EXTERN boolean * eofseen  ;
EXTERN halfword pseudofiles  ;
EXTERN savepointer * grpstack  ;
EXTERN halfword * ifstack  ;
EXTERN halfword maxregnum  ;
EXTERN strnumber maxreghelpline  ;
EXTERN halfword samark  ;
EXTERN halfword curptr  ;
EXTERN memoryword sanull  ;
EXTERN halfword sachain  ;
EXTERN quarterword salevel  ;
EXTERN halfword lastlinefill  ;
EXTERN boolean dolastlinefit  ;
EXTERN smallnumber activenodesize  ;
EXTERN scaled fillwidth[3]  ;
EXTERN scaled bestplshort[4]  ;
EXTERN scaled bestplglue[4]  ;
EXTERN triepointer hyphstart  ;
EXTERN triepointer hyphindex  ;
EXTERN halfword discptr[4]  ;
EXTERN poolpointer editnamestart  ;
EXTERN integer editnamelength, editline  ;
EXTERN cinttype ipcon  ;
EXTERN boolean stopatspace  ;
EXTERN strnumber savestrptr  ;
EXTERN poolpointer savepoolptr  ;
EXTERN cinttype shellenabledp  ;
EXTERN cinttype restrictedshell  ;
EXTERN char * outputcomment  ;
EXTERN unsigned short k, l  ;
EXTERN boolean debugformatfile  ;
EXTERN halfword otpinitinputstart  ;
EXTERN halfword otpinitinputlast  ;
EXTERN halfword otpinitinputend  ;
EXTERN halfword otpi  ;
EXTERN quarterword * otpinitinputbuf  ;
EXTERN halfword otpinputstart  ;
EXTERN halfword otpinputlast  ;
EXTERN halfword otpinputend  ;
EXTERN quarterword * otpinputbuf  ;
EXTERN halfword otpoutputend  ;
EXTERN quarterword * otpoutputbuf  ;
EXTERN halfword otpstackused  ;
EXTERN halfword otpstacklast  ;
EXTERN halfword otpstacknew  ;
EXTERN quarterword * otpstackbuf  ;
EXTERN halfword otppc  ;
EXTERN halfword otpcalcptr  ;
EXTERN halfword * otpcalcs  ;
EXTERN halfword otpstateptr  ;
EXTERN halfword * otpstates  ;
EXTERN halfword otpinputchar  ;
EXTERN halfword otpcalculatedchar  ;
EXTERN halfword otpnoinputchars  ;
EXTERN halfword otpinstruction  ;
EXTERN halfword otpinstr  ;
EXTERN halfword otparg  ;
EXTERN halfword otpfirstarg  ;
EXTERN halfword otpsecondarg  ;
EXTERN halfword otpinputocp  ;
EXTERN halfword otpcounter  ;
EXTERN boolean otpfinished  ;
EXTERN integer otpextstr  ;
EXTERN integer otpextstrarg  ;
EXTERN integer otpexti  ;

#include "alephcoerce.h"
