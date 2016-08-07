#ifdef TEXMF_DEBUG
#endif /* TEXMF_DEBUG */
#define UPBIBTEX
#include "uptexdir/kanji.h"
#include <setjmp.h> 
jmp_buf jmp9998, jmp32; int lab31=0;
/* 9998 31 32 9932 */ 
#define hashbase ( 1 ) 
#define quotenextfn ( hashbase - 1 ) 
#define BUFSIZE ( 20000 ) 
#define minprintline ( 3 ) 
#define maxprintline ( 79 ) 
#define auxstacksize ( 20 ) 
#define MAXBIBFILES ( 20 ) 
#define POOLSIZE ( 65000L ) 
#define MAXSTRINGS ( 4000 ) 
#define MAXCITES ( 750 ) 
#define WIZFNSPACE ( 3000 ) 
#define SINGLEFNSPACE ( 50 ) 
#define ENTSTRSIZE ( 100 ) 
#define GLOBSTRSIZE ( 1000 ) 
#define MAXGLOBSTRS ( 10 ) 
#define MAXFIELDS ( 5000 ) 
#define LITSTKSIZE ( 50 ) 
#define numbltinfns ( 38 ) 
typedef unsigned char ASCIIcode  ;
typedef unsigned char lextype  ;
typedef unsigned char idtype  ;
typedef text /* of  ASCIIcode */ alphafile  ;
typedef integer bufpointer  ;
typedef ASCIIcode * buftype  ;
typedef integer poolpointer  ;
typedef integer strnumber  ;
typedef integer hashloc  ;
typedef integer hashpointer  ;
typedef unsigned char strilk  ;
typedef unsigned char pdsloc  ;
typedef unsigned char pdslen  ;
typedef constcstring pdstype  ;
typedef integer auxnumber  ;
typedef integer bibnumber  ;
typedef integer citenumber  ;
typedef unsigned char fnclass  ;
typedef integer wizfnloc  ;
typedef integer intentloc  ;
typedef integer strentloc  ;
typedef integer strglobloc  ;
typedef integer fieldloc  ;
typedef integer hashptr2  ;
typedef integer litstkloc  ;
typedef unsigned char stktype  ;
typedef integer bltinrange  ;
text standardinput, standardoutput  ;
integer poolsize  ;
integer maxbibfiles  ;
integer maxcites  ;
integer wizfnspace  ;
integer entstrsize  ;
integer globstrsize  ;
integer maxglobstrs  ;
integer maxfields  ;
integer litstksize  ;
integer maxstrings  ;
integer hashsize  ;
integer hashprime  ;
integer hashmax  ;
integer endofdef  ;
integer undefined  ;
integer bad  ;
unsigned char history  ;
integer errcount  ;
ASCIIcode xord[256]  ;
ASCIIcode xchr[256]  ;
lextype lexclass[256]  ;
idtype idclass[256]  ;
integer charwidth[256]  ;
integer stringwidth  ;
ASCIIcode * nameoffile  ;
integer namelength  ;
integer nameptr  ;
integer bufsize  ;
buftype buffer  ;
bufpointer last  ;
buftype svbuffer  ;
bufpointer svptr1  ;
bufpointer svptr2  ;
integer tmpptr, tmpendptr  ;
ASCIIcode * strpool  ;
poolpointer * strstart  ;
poolpointer poolptr  ;
strnumber strptr  ;
strnumber strnum  ;
poolpointer pptr1, pptr2  ;
hashpointer * hashnext  ;
strnumber * hashtext  ;
strilk * hashilk  ;
integer * ilkinfo  ;
integer hashused  ;
boolean hashfound  ;
hashloc dummyloc  ;
strnumber sauxextension  ;
strnumber slogextension  ;
strnumber sbblextension  ;
strnumber sbstextension  ;
strnumber sbibextension  ;
strnumber sbstarea  ;
strnumber sbibarea  ;
hashloc predefloc  ;
integer commandnum  ;
bufpointer bufptr1  ;
bufpointer bufptr2  ;
unsigned char scanresult  ;
integer tokenvalue  ;
integer auxnamelength  ;
alphafile auxfile[auxstacksize + 1]  ;
strnumber auxlist[auxstacksize + 1]  ;
auxnumber auxptr  ;
integer auxlnstack[auxstacksize + 1]  ;
strnumber toplevstr  ;
alphafile logfile  ;
alphafile bblfile  ;
strnumber * biblist  ;
bibnumber bibptr  ;
bibnumber numbibfiles  ;
boolean bibseen  ;
alphafile * bibfile  ;
boolean bstseen  ;
strnumber bststr  ;
alphafile bstfile  ;
strnumber * citelist  ;
citenumber citeptr  ;
citenumber entryciteptr  ;
citenumber numcites  ;
citenumber oldnumcites  ;
boolean citationseen  ;
hashloc citeloc  ;
hashloc lcciteloc  ;
hashloc lcxciteloc  ;
boolean citefound  ;
boolean allentries  ;
citenumber allmarker  ;
integer bbllinenum  ;
integer bstlinenum  ;
hashloc fnloc  ;
hashloc wizloc  ;
hashloc literalloc  ;
hashloc macronameloc  ;
hashloc macrodefloc  ;
fnclass * fntype  ;
wizfnloc wizdefptr  ;
wizfnloc wizfnptr  ;
hashptr2 * wizfunctions  ;
intentloc intentptr  ;
integer * entryints  ;
intentloc numentints  ;
strentloc strentptr  ;
ASCIIcode * entrystrs  ;
strentloc numentstrs  ;
integer strglbptr  ;
strnumber * glbstrptr  ;
ASCIIcode * globalstrs  ;
integer * glbstrend  ;
integer numglbstrs  ;
fieldloc fieldptr  ;
fieldloc fieldparentptr, fieldendptr  ;
citenumber citeparentptr, citexptr  ;
strnumber * fieldinfo  ;
fieldloc numfields  ;
fieldloc numpredefinedfields  ;
fieldloc crossrefnum  ;
boolean nofields  ;
boolean entryseen  ;
boolean readseen  ;
boolean readperformed  ;
boolean readingcompleted  ;
boolean readcompleted  ;
integer implfnnum  ;
integer biblinenum  ;
hashloc entrytypeloc  ;
hashptr2 * typelist  ;
boolean typeexists  ;
boolean * entryexists  ;
boolean storeentry  ;
hashloc fieldnameloc  ;
hashloc fieldvalloc  ;
boolean storefield  ;
boolean storetoken  ;
ASCIIcode rightouterdelim  ;
ASCIIcode rightstrdelim  ;
boolean atbibcommand  ;
hashloc curmacroloc  ;
strnumber * citeinfo  ;
boolean citehashfound  ;
bibnumber preambleptr  ;
bibnumber numpreamblestrings  ;
integer bibbracelevel  ;
integer * litstack  ;
stktype * litstktype  ;
litstkloc litstkptr  ;
strnumber cmdstrptr  ;
integer entchrptr  ;
integer globchrptr  ;
buftype exbuf  ;
bufpointer exbufptr  ;
bufpointer exbuflength  ;
buftype outbuf  ;
bufpointer outbufptr  ;
bufpointer outbuflength  ;
boolean messwithentries  ;
citenumber sortciteptr  ;
strentloc sortkeynum  ;
integer bracelevel  ;
hashloc bequals  ;
hashloc bgreaterthan  ;
hashloc blessthan  ;
hashloc bplus  ;
hashloc bminus  ;
hashloc bconcatenate  ;
hashloc bgets  ;
hashloc baddperiod  ;
hashloc bcalltype  ;
hashloc bchangecase  ;
hashloc bchrtoint  ;
hashloc bcite  ;
hashloc bduplicate  ;
hashloc bempty  ;
hashloc bformatname  ;
hashloc bif  ;
hashloc binttochr  ;
hashloc binttostr  ;
hashloc bmissing  ;
hashloc bnewline  ;
hashloc bnumnames  ;
hashloc bpop  ;
hashloc bpreamble  ;
hashloc bpurify  ;
hashloc bquote  ;
hashloc bskip  ;
hashloc bstack  ;
hashloc bsubstring  ;
hashloc bswap  ;
hashloc btextlength  ;
hashloc btextprefix  ;
hashloc btopstack  ;
hashloc btype  ;
hashloc bwarning  ;
hashloc bwhile  ;
hashloc bwidth  ;
hashloc bwrite  ;
hashloc biskanjistr  ;
hashloc bdefault  ;
#ifndef NO_BIBTEX_STAT
hashloc bltinloc[numbltinfns + 1]  ;
integer executioncount[numbltinfns + 1]  ;
integer totalexcount  ;
bltinrange bltinptr  ;
#endif /* not NO_BIBTEX_STAT */
strnumber snull  ;
strnumber sdefault  ;
strnumber st  ;
strnumber sl  ;
strnumber su  ;
strnumber * spreamble  ;
integer poplit1, poplit2, poplit3  ;
stktype poptyp1, poptyp2, poptyp3  ;
poolpointer spptr  ;
poolpointer spxptr1, spxptr2  ;
poolpointer spend  ;
poolpointer splength, sp2length  ;
integer spbracelevel  ;
bufpointer exbufxptr, exbufyptr  ;
hashloc controlseqloc  ;
boolean precedingwhite  ;
boolean andfound  ;
integer numnames  ;
bufpointer namebfptr  ;
bufpointer namebfxptr, namebfyptr  ;
integer nmbracelevel  ;
bufpointer * nametok  ;
ASCIIcode * namesepchar  ;
bufpointer numtokens  ;
boolean tokenstarting  ;
boolean alphafound  ;
boolean doubleletter, endofgroup, tobewritten  ;
bufpointer firststart  ;
bufpointer firstend  ;
bufpointer lastend  ;
bufpointer vonstart  ;
bufpointer vonend  ;
bufpointer jrend  ;
bufpointer curtoken, lasttoken  ;
boolean usedefault  ;
bufpointer numcommas  ;
bufpointer comma1, comma2  ;
bufpointer numtextchars  ;
unsigned char conversiontype  ;
boolean prevcolon  ;
cinttype verbose  ;
integer mincrossrefs  ;

#include "upbibtex.h"
void 
printanewline ( void ) 
{
  putc ('\n',  logfile );
  putc ('\n',  standardoutput );
} 
void 
markwarning ( void ) 
{
  if ( ( history == 1 ) ) 
  errcount = errcount + 1 ;
  else if ( ( history == 0 ) ) 
  {
    history = 1 ;
    errcount = 1 ;
  } 
} 
void 
markerror ( void ) 
{
  if ( ( history < 2 ) ) 
  {
    history = 2 ;
    errcount = 1 ;
  } 
  else errcount = errcount + 1 ;
} 
void 
markfatal ( void ) 
{
  history = 3 ;
} 
void 
printoverflow ( void ) 
{
  {
    Fputs ( logfile ,  "Sorry---you've exceeded BibTeX's " ) ;
    Fputs ( standardoutput ,  "Sorry---you've exceeded BibTeX's " ) ;
  } 
  markfatal () ;
} 
void 
printconfusion ( void ) 
{
  {
    fprintf ( logfile , "%s\n",  "---this can't happen" ) ;
    fprintf ( standardoutput , "%s\n",  "---this can't happen" ) ;
  } 
  {
    fprintf ( logfile , "%s\n",  "*Please notify the BibTeX maintainer*" ) ;
    fprintf ( standardoutput , "%s\n",  "*Please notify the BibTeX maintainer*" ) ;
  } 
  markfatal () ;
} 
void 
bufferoverflow ( void ) 
{
  BIBXRETALLOCNOSET ( "buffer" , buffer , ASCIIcode , bufsize , bufsize + 
  BUFSIZE ) ;
  BIBXRETALLOCNOSET ( "sv_buffer" , svbuffer , ASCIIcode , bufsize , bufsize + 
  BUFSIZE ) ;
  BIBXRETALLOCNOSET ( "ex_buf" , exbuf , ASCIIcode , bufsize , bufsize + 
  BUFSIZE ) ;
  BIBXRETALLOCNOSET ( "out_buf" , outbuf , ASCIIcode , bufsize , bufsize + 
  BUFSIZE ) ;
  BIBXRETALLOCNOSET ( "name_tok" , nametok , bufpointer , bufsize , bufsize + 
  BUFSIZE ) ;
  BIBXRETALLOC ( "name_sep_char" , namesepchar , ASCIIcode , bufsize , bufsize 
  + BUFSIZE ) ;
} 
boolean 
zinputln ( alphafile f ) 
{
  /* 15 */ register boolean Result; cinttype i  ;
  last = 0 ;
  if ( ( eof ( f ) ) ) 
  Result = false ;
  else {
      
    last = inputline2 ( f , ustringcast ( buffer ) , last , bufsize , 
    addressof ( i ) ) ;
    while ( ( ! eof ( f ) ) && ( last > 0 ) && ( i != 10 ) && ( i != 13 ) ) {
	
      bufferoverflow () ;
      last = inputline2 ( f , ustringcast ( buffer ) , last , bufsize , 
      addressof ( i ) ) ;
    } 
    while ( ( last > 0 ) ) if ( ( lexclass [buffer [last - 1 ]]== 1 ) ) 
    last = last - 1 ;
    else goto lab15 ;
    lab15: Result = true ;
  } 
  return Result ;
} 
void 
zoutpoolstr ( alphafile f , strnumber s ) 
{
  poolpointer i  ;
  if ( ( ( s < 0 ) || ( s >= strptr + 3 ) || ( s >= maxstrings ) ) ) 
  {
    {
      fprintf ( logfile , "%s%ld",  "Illegal string number:" , (long)s ) ;
      fprintf ( standardoutput , "%s%ld",  "Illegal string number:" , (long)s ) ;
    } 
    printconfusion () ;
    longjmp(jmp9998,1) ;
  } 
  {register integer for_end; i = strstart [s ];for_end = strstart [s + 1 
  ]- 1 ; if ( i <= for_end) do 
    putc ( xchr [strpool [i ]],  f );
  while ( i++ < for_end ) ;} 
} 
void 
zprintapoolstr ( strnumber s ) 
{
  outpoolstr ( standardoutput , s ) ;
  outpoolstr ( logfile , s ) ;
} 
void 
pooloverflow ( void ) 
{
  BIBXRETALLOC ( "str_pool" , strpool , ASCIIcode , poolsize , poolsize + 
  POOLSIZE ) ;
} 
void 
zouttoken ( alphafile f ) 
{
  bufpointer i  ;
  i = bufptr1 ;
  while ( ( i < bufptr2 ) ) {
      
    putc ( xchr [buffer [i ]],  f );
    i = i + 1 ;
  } 
} 
void 
printatoken ( void ) 
{
  outtoken ( standardoutput ) ;
  outtoken ( logfile ) ;
} 
void 
printbadinputline ( void ) 
{
  bufpointer bfptr  ;
  {
    Fputs ( logfile ,  " : " ) ;
    Fputs ( standardoutput ,  " : " ) ;
  } 
  bfptr = 0 ;
  while ( ( bfptr < bufptr2 ) ) {
      
    if ( ( lexclass [buffer [bfptr ]]== 1 ) ) 
    {
      putc ( xchr [32 ],  logfile );
      putc ( xchr [32 ],  standardoutput );
    } 
    else {
	
      putc ( xchr [buffer [bfptr ]],  logfile );
      putc ( xchr [buffer [bfptr ]],  standardoutput );
    } 
    bfptr = bfptr + 1 ;
  } 
  printanewline () ;
  {
    Fputs ( logfile ,  " : " ) ;
    Fputs ( standardoutput ,  " : " ) ;
  } 
  bfptr = 0 ;
  while ( ( bfptr < bufptr2 ) ) {
      
    {
      putc ( xchr [32 ],  logfile );
      putc ( xchr [32 ],  standardoutput );
    } 
    bfptr = bfptr + 1 ;
  } 
  bfptr = bufptr2 ;
  while ( ( bfptr < last ) ) {
      
    if ( ( lexclass [buffer [bfptr ]]== 1 ) ) 
    {
      putc ( xchr [32 ],  logfile );
      putc ( xchr [32 ],  standardoutput );
    } 
    else {
	
      putc ( xchr [buffer [bfptr ]],  logfile );
      putc ( xchr [buffer [bfptr ]],  standardoutput );
    } 
    bfptr = bfptr + 1 ;
  } 
  printanewline () ;
  bfptr = 0 ;
  while ( ( ( bfptr < bufptr2 ) && ( lexclass [buffer [bfptr ]]== 1 ) ) ) 
  bfptr = bfptr + 1 ;
  if ( ( bfptr == bufptr2 ) ) 
  {
    fprintf ( logfile , "%s\n",  "(Error may have been on previous line)" ) ;
    fprintf ( standardoutput , "%s\n",  "(Error may have been on previous line)" ) ;
  } 
  markerror () ;
} 
void 
printskippingwhateverremains ( void ) 
{
  {
    Fputs ( logfile ,  "I'm skipping whatever remains of this " ) ;
    Fputs ( standardoutput ,  "I'm skipping whatever remains of this " ) ;
  } 
} 
void 
samtoolongfilenameprint ( void ) 
{
  Fputs ( standardoutput ,  "File name `" ) ;
  nameptr = 1 ;
  while ( ( nameptr <= auxnamelength ) ) {
      
    putc ( nameoffile [nameptr ],  standardoutput );
    nameptr = nameptr + 1 ;
  } 
  fprintf ( standardoutput , "%s\n",  "' is too long" ) ;
} 
void 
samwrongfilenameprint ( void ) 
{
  Fputs ( standardoutput ,  "I couldn't open file name `" ) ;
  nameptr = 1 ;
  while ( ( nameptr <= namelength ) ) {
      
    putc ( nameoffile [nameptr ],  standardoutput );
    nameptr = nameptr + 1 ;
  } 
  { putc ( '\'' ,  standardoutput );  putc ( '\n',  standardoutput ); }
} 
void 
printauxname ( void ) 
{
  printapoolstr ( auxlist [auxptr ]) ;
  printanewline () ;
} 
void 
logprauxname ( void ) 
{
  {
    outpoolstr ( logfile , auxlist [auxptr ]) ;
  } 
  {
    putc ('\n',  logfile );
  } 
} 
void 
auxerrprint ( void ) 
{
  {
    fprintf ( logfile , "%s%ld%s",  "---line " , (long)auxlnstack [auxptr ], " of file " ) ;
    fprintf ( standardoutput , "%s%ld%s",  "---line " , (long)auxlnstack [auxptr ], " of file "     ) ;
  } 
  printauxname () ;
  printbadinputline () ;
  printskippingwhateverremains () ;
  {
    fprintf ( logfile , "%s\n",  "command" ) ;
    fprintf ( standardoutput , "%s\n",  "command" ) ;
  } 
} 
void 
zauxerrillegalanotherprint ( integer cmdnum ) 
{
  {
    Fputs ( logfile ,  "Illegal, another \\bib" ) ;
    Fputs ( standardoutput ,  "Illegal, another \\bib" ) ;
  } 
  switch ( ( cmdnum ) ) 
  {case 0 : 
    {
      Fputs ( logfile ,  "data" ) ;
      Fputs ( standardoutput ,  "data" ) ;
    } 
    break ;
  case 1 : 
    {
      Fputs ( logfile ,  "style" ) ;
      Fputs ( standardoutput ,  "style" ) ;
    } 
    break ;
    default: 
    {
      {
	Fputs ( logfile ,  "Illegal auxiliary-file command" ) ;
	Fputs ( standardoutput ,  "Illegal auxiliary-file command" ) ;
      } 
      printconfusion () ;
      longjmp(jmp9998,1) ;
    } 
    break ;
  } 
  {
    Fputs ( logfile ,  " command" ) ;
    Fputs ( standardoutput ,  " command" ) ;
  } 
} 
void 
auxerrnorightbraceprint ( void ) 
{
  {
    fprintf ( logfile , "%s%c%c",  "No \"" , xchr [125 ], '"' ) ;
    fprintf ( standardoutput , "%s%c%c",  "No \"" , xchr [125 ], '"' ) ;
  } 
} 
void 
auxerrstuffafterrightbraceprint ( void ) 
{
  {
    fprintf ( logfile , "%s%c%c",  "Stuff after \"" , xchr [125 ], '"' ) ;
    fprintf ( standardoutput , "%s%c%c",  "Stuff after \"" , xchr [125 ], '"' ) ;
  } 
} 
void 
auxerrwhitespaceinargumentprint ( void ) 
{
  {
    Fputs ( logfile ,  "White space in argument" ) ;
    Fputs ( standardoutput ,  "White space in argument" ) ;
  } 
} 
void 
printbibname ( void ) 
{
  printapoolstr ( biblist [bibptr ]) ;
  printapoolstr ( sbibextension ) ;
  printanewline () ;
} 
void 
logprbibname ( void ) 
{
  {
    outpoolstr ( logfile , biblist [bibptr ]) ;
  } 
  {
    outpoolstr ( logfile , sbibextension ) ;
  } 
  {
    putc ('\n',  logfile );
  } 
} 
void 
printbstname ( void ) 
{
  printapoolstr ( bststr ) ;
  printapoolstr ( sbstextension ) ;
  printanewline () ;
} 
void 
logprbstname ( void ) 
{
  {
    outpoolstr ( logfile , bststr ) ;
  } 
  {
    outpoolstr ( logfile , sbstextension ) ;
  } 
  {
    putc ('\n',  logfile );
  } 
} 
void 
hashciteconfusion ( void ) 
{
  {
    {
      Fputs ( logfile ,  "Cite hash error" ) ;
      Fputs ( standardoutput ,  "Cite hash error" ) ;
    } 
    printconfusion () ;
    longjmp(jmp9998,1) ;
  } 
} 
void 
zcheckciteoverflow ( citenumber lastcite ) 
{
  if ( ( lastcite == maxcites ) ) 
  {
    BIBXRETALLOCNOSET ( "cite_list" , citelist , strnumber , maxcites , 
    maxcites + MAXCITES ) ;
    BIBXRETALLOCNOSET ( "type_list" , typelist , hashptr2 , maxcites , 
    maxcites + MAXCITES ) ;
    BIBXRETALLOCNOSET ( "entry_exists" , entryexists , boolean , maxcites , 
    maxcites + MAXCITES ) ;
    BIBXRETALLOC ( "cite_info" , citeinfo , strnumber , maxcites , maxcites + 
    MAXCITES ) ;
    while ( ( lastcite < maxcites ) ) {
	
      typelist [lastcite ]= 0 ;
      citeinfo [lastcite ]= 0 ;
      lastcite = lastcite + 1 ;
    } 
  } 
} 
void 
auxend1errprint ( void ) 
{
  {
    Fputs ( logfile ,  "I found no " ) ;
    Fputs ( standardoutput ,  "I found no " ) ;
  } 
} 
void 
auxend2errprint ( void ) 
{
  {
    Fputs ( logfile ,  "---while reading file " ) ;
    Fputs ( standardoutput ,  "---while reading file " ) ;
  } 
  printauxname () ;
  markerror () ;
} 
void 
bstlnnumprint ( void ) 
{
  {
    fprintf ( logfile , "%s%ld%s",  "--line " , (long)bstlinenum , " of file " ) ;
    fprintf ( standardoutput , "%s%ld%s",  "--line " , (long)bstlinenum , " of file " ) ;
  } 
  printbstname () ;
} 
void 
bsterrprintandlookforblankline ( void ) 
{
  {
    putc ( '-' ,  logfile );
    putc ( '-' ,  standardoutput );
  } 
  bstlnnumprint () ;
  printbadinputline () ;
  while ( ( last != 0 ) ) if ( ( ! inputln ( bstfile ) ) ) 
  longjmp(jmp32,1) ;
  else bstlinenum = bstlinenum + 1 ;
  bufptr2 = last ;
} 
void 
bstwarnprint ( void ) 
{
  bstlnnumprint () ;
  markwarning () ;
} 
void 
eatbstprint ( void ) 
{
  {
    Fputs ( logfile ,  "Illegal end of style file in command: " ) ;
    Fputs ( standardoutput ,  "Illegal end of style file in command: " ) ;
  } 
} 
void 
unknwnfunctionclassconfusion ( void ) 
{
  {
    {
      Fputs ( logfile ,  "Unknown function class" ) ;
      Fputs ( standardoutput ,  "Unknown function class" ) ;
    } 
    printconfusion () ;
    longjmp(jmp9998,1) ;
  } 
} 
void 
zprintfnclass ( hashloc fnloc ) 
{
  switch ( ( fntype [fnloc ]) ) 
  {case 0 : 
    {
      Fputs ( logfile ,  "built-in" ) ;
      Fputs ( standardoutput ,  "built-in" ) ;
    } 
    break ;
  case 1 : 
    {
      Fputs ( logfile ,  "wizard-defined" ) ;
      Fputs ( standardoutput ,  "wizard-defined" ) ;
    } 
    break ;
  case 2 : 
    {
      Fputs ( logfile ,  "integer-literal" ) ;
      Fputs ( standardoutput ,  "integer-literal" ) ;
    } 
    break ;
  case 3 : 
    {
      Fputs ( logfile ,  "string-literal" ) ;
      Fputs ( standardoutput ,  "string-literal" ) ;
    } 
    break ;
  case 4 : 
    {
      Fputs ( logfile ,  "field" ) ;
      Fputs ( standardoutput ,  "field" ) ;
    } 
    break ;
  case 5 : 
    {
      Fputs ( logfile ,  "integer-entry-variable" ) ;
      Fputs ( standardoutput ,  "integer-entry-variable" ) ;
    } 
    break ;
  case 6 : 
    {
      Fputs ( logfile ,  "string-entry-variable" ) ;
      Fputs ( standardoutput ,  "string-entry-variable" ) ;
    } 
    break ;
  case 7 : 
    {
      Fputs ( logfile ,  "integer-global-variable" ) ;
      Fputs ( standardoutput ,  "integer-global-variable" ) ;
    } 
    break ;
  case 8 : 
    {
      Fputs ( logfile ,  "string-global-variable" ) ;
      Fputs ( standardoutput ,  "string-global-variable" ) ;
    } 
    break ;
    default: 
    unknwnfunctionclassconfusion () ;
    break ;
  } 
} 
#ifdef TRACE
void 
ztraceprfnclass ( hashloc fnloc ) 
{
  switch ( ( fntype [fnloc ]) ) 
  {case 0 : 
    {
      Fputs ( logfile ,  "built-in" ) ;
    } 
    break ;
  case 1 : 
    {
      Fputs ( logfile ,  "wizard-defined" ) ;
    } 
    break ;
  case 2 : 
    {
      Fputs ( logfile ,  "integer-literal" ) ;
    } 
    break ;
  case 3 : 
    {
      Fputs ( logfile ,  "string-literal" ) ;
    } 
    break ;
  case 4 : 
    {
      Fputs ( logfile ,  "field" ) ;
    } 
    break ;
  case 5 : 
    {
      Fputs ( logfile ,  "integer-entry-variable" ) ;
    } 
    break ;
  case 6 : 
    {
      Fputs ( logfile ,  "string-entry-variable" ) ;
    } 
    break ;
  case 7 : 
    {
      Fputs ( logfile ,  "integer-global-variable" ) ;
    } 
    break ;
  case 8 : 
    {
      Fputs ( logfile ,  "string-global-variable" ) ;
    } 
    break ;
    default: 
    unknwnfunctionclassconfusion () ;
    break ;
  } 
} 
#endif /* TRACE */
void 
idscanningconfusion ( void ) 
{
  {
    {
      Fputs ( logfile ,  "Identifier scanning error" ) ;
      Fputs ( standardoutput ,  "Identifier scanning error" ) ;
    } 
    printconfusion () ;
    longjmp(jmp9998,1) ;
  } 
} 
void 
bstidprint ( void ) 
{
  if ( ( scanresult == 0 ) ) 
  {
    fprintf ( logfile , "%c%c%s",  '"' , xchr [buffer [bufptr2 ]],     "\" begins identifier, command: " ) ;
    fprintf ( standardoutput , "%c%c%s",  '"' , xchr [buffer [bufptr2 ]],     "\" begins identifier, command: " ) ;
  } 
  else if ( ( scanresult == 2 ) ) 
  {
    fprintf ( logfile , "%c%c%s",  '"' , xchr [buffer [bufptr2 ]],     "\" immediately follows identifier, command: " ) ;
    fprintf ( standardoutput , "%c%c%s",  '"' , xchr [buffer [bufptr2 ]],     "\" immediately follows identifier, command: " ) ;
  } 
  else idscanningconfusion () ;
} 
void 
bstleftbraceprint ( void ) 
{
  {
    fprintf ( logfile , "%c%c%s",  '"' , xchr [123 ], "\" is missing in command: " ) ;
    fprintf ( standardoutput , "%c%c%s",  '"' , xchr [123 ], "\" is missing in command: "     ) ;
  } 
} 
void 
bstrightbraceprint ( void ) 
{
  {
    fprintf ( logfile , "%c%c%s",  '"' , xchr [125 ], "\" is missing in command: " ) ;
    fprintf ( standardoutput , "%c%c%s",  '"' , xchr [125 ], "\" is missing in command: "     ) ;
  } 
} 
void 
zalreadyseenfunctionprint ( hashloc seenfnloc ) 
{
  /* 10 */ printapoolstr ( hashtext [seenfnloc ]) ;
  {
    Fputs ( logfile ,  " is already a type \"" ) ;
    Fputs ( standardoutput ,  " is already a type \"" ) ;
  } 
  printfnclass ( seenfnloc ) ;
  {
    fprintf ( logfile , "%s\n",  "\" function name" ) ;
    fprintf ( standardoutput , "%s\n",  "\" function name" ) ;
  } 
  {
    bsterrprintandlookforblankline () ;
    goto lab10 ;
  } 
  lab10: ;
} 
void 
biblnnumprint ( void ) 
{
  {
    fprintf ( logfile , "%s%ld%s",  "--line " , (long)biblinenum , " of file " ) ;
    fprintf ( standardoutput , "%s%ld%s",  "--line " , (long)biblinenum , " of file " ) ;
  } 
  printbibname () ;
} 
void 
biberrprint ( void ) 
{
  {
    putc ( '-' ,  logfile );
    putc ( '-' ,  standardoutput );
  } 
  biblnnumprint () ;
  printbadinputline () ;
  printskippingwhateverremains () ;
  if ( ( atbibcommand ) ) 
  {
    fprintf ( logfile , "%s\n",  "command" ) ;
    fprintf ( standardoutput , "%s\n",  "command" ) ;
  } 
  else {
      
    fprintf ( logfile , "%s\n",  "entry" ) ;
    fprintf ( standardoutput , "%s\n",  "entry" ) ;
  } 
} 
void 
bibwarnprint ( void ) 
{
  biblnnumprint () ;
  markwarning () ;
} 
void 
zcheckfieldoverflow ( integer totalfields ) 
{
  fieldloc fptr  ;
  fieldloc startfields  ;
  if ( ( totalfields > maxfields ) ) 
  {
    startfields = maxfields ;
    BIBXRETALLOC ( "field_info" , fieldinfo , strnumber , maxfields , 
    totalfields + MAXFIELDS ) ;
    {register integer for_end; fptr = startfields ;for_end = maxfields - 1 
    ; if ( fptr <= for_end) do 
      {
	fieldinfo [fptr ]= 0 ;
      } 
    while ( fptr++ < for_end ) ;} 
  } 
} 
void 
eatbibprint ( void ) 
{
  /* 10 */ {
      
    {
      Fputs ( logfile ,  "Illegal end of database file" ) ;
      Fputs ( standardoutput ,  "Illegal end of database file" ) ;
    } 
    biberrprint () ;
    goto lab10 ;
  } 
  lab10: ;
} 
void 
zbiboneoftwoprint ( ASCIIcode char1 , ASCIIcode char2 ) 
{
  /* 10 */ {
      
    {
      fprintf ( logfile , "%s%c%s%c%c",  "I was expecting a `" , xchr [char1 ], "' or a `" ,       xchr [char2 ], '\'' ) ;
      fprintf ( standardoutput , "%s%c%s%c%c",  "I was expecting a `" , xchr [char1 ],       "' or a `" , xchr [char2 ], '\'' ) ;
    } 
    biberrprint () ;
    goto lab10 ;
  } 
  lab10: ;
} 
void 
bibequalssignprint ( void ) 
{
  /* 10 */ {
      
    {
      fprintf ( logfile , "%s%c%c",  "I was expecting an \"" , xchr [61 ], '"' ) ;
      fprintf ( standardoutput , "%s%c%c",  "I was expecting an \"" , xchr [61 ], '"' ) ;
    } 
    biberrprint () ;
    goto lab10 ;
  } 
  lab10: ;
} 
void 
bibunbalancedbracesprint ( void ) 
{
  /* 10 */ {
      
    {
      Fputs ( logfile ,  "Unbalanced braces" ) ;
      Fputs ( standardoutput ,  "Unbalanced braces" ) ;
    } 
    biberrprint () ;
    goto lab10 ;
  } 
  lab10: ;
} 
void 
bibfieldtoolongprint ( void ) 
{
  /* 10 */ {
      
    {
      fprintf ( logfile , "%s%ld%s",  "Your field is more than " , (long)bufsize , " characters" ) 
      ;
      fprintf ( standardoutput , "%s%ld%s",  "Your field is more than " , (long)bufsize ,       " characters" ) ;
    } 
    biberrprint () ;
    goto lab10 ;
  } 
  lab10: ;
} 
void 
macrowarnprint ( void ) 
{
  {
    Fputs ( logfile ,  "Warning--string name \"" ) ;
    Fputs ( standardoutput ,  "Warning--string name \"" ) ;
  } 
  printatoken () ;
  {
    Fputs ( logfile ,  "\" is " ) ;
    Fputs ( standardoutput ,  "\" is " ) ;
  } 
} 
void 
bibidprint ( void ) 
{
  if ( ( scanresult == 0 ) ) 
  {
    Fputs ( logfile ,  "You're missing " ) ;
    Fputs ( standardoutput ,  "You're missing " ) ;
  } 
  else if ( ( scanresult == 2 ) ) 
  {
    fprintf ( logfile , "%c%c%s",  '"' , xchr [buffer [bufptr2 ]],     "\" immediately follows " ) ;
    fprintf ( standardoutput , "%c%c%s",  '"' , xchr [buffer [bufptr2 ]],     "\" immediately follows " ) ;
  } 
  else idscanningconfusion () ;
} 
void 
bibcmdconfusion ( void ) 
{
  {
    {
      Fputs ( logfile ,  "Unknown database-file command" ) ;
      Fputs ( standardoutput ,  "Unknown database-file command" ) ;
    } 
    printconfusion () ;
    longjmp(jmp9998,1) ;
  } 
} 
void 
citekeydisappearedconfusion ( void ) 
{
  {
    {
      Fputs ( logfile ,  "A cite key disappeared" ) ;
      Fputs ( standardoutput ,  "A cite key disappeared" ) ;
    } 
    printconfusion () ;
    longjmp(jmp9998,1) ;
  } 
} 
void 
zbadcrossreferenceprint ( strnumber s ) 
{
  {
    Fputs ( logfile ,  "--entry \"" ) ;
    Fputs ( standardoutput ,  "--entry \"" ) ;
  } 
  printapoolstr ( citelist [citeptr ]) ;
  {
    { putc ( '"' ,  logfile );  putc ( '\n',  logfile ); }
    { putc ( '"' ,  standardoutput );  putc ( '\n',  standardoutput ); }
  } 
  {
    Fputs ( logfile ,  "refers to entry \"" ) ;
    Fputs ( standardoutput ,  "refers to entry \"" ) ;
  } 
  printapoolstr ( s ) ;
} 
void 
nonexistentcrossreferenceerror ( void ) 
{
  {
    Fputs ( logfile ,  "A bad cross reference-" ) ;
    Fputs ( standardoutput ,  "A bad cross reference-" ) ;
  } 
  badcrossreferenceprint ( fieldinfo [fieldptr ]) ;
  {
    fprintf ( logfile , "%s\n",  "\", which doesn't exist" ) ;
    fprintf ( standardoutput , "%s\n",  "\", which doesn't exist" ) ;
  } 
  markerror () ;
} 
void 
zprintmissingentry ( strnumber s ) 
{
  {
    Fputs ( logfile ,  "Warning--I didn't find a database entry for \"" ) ;
    Fputs ( standardoutput ,  "Warning--I didn't find a database entry for \""     ) ;
  } 
  printapoolstr ( s ) ;
  {
    { putc ( '"' ,  logfile );  putc ( '\n',  logfile ); }
    { putc ( '"' ,  standardoutput );  putc ( '\n',  standardoutput ); }
  } 
  markwarning () ;
} 
void 
bstexwarnprint ( void ) 
{
  if ( ( messwithentries ) ) 
  {
    {
      Fputs ( logfile ,  " for entry " ) ;
      Fputs ( standardoutput ,  " for entry " ) ;
    } 
    printapoolstr ( citelist [citeptr ]) ;
  } 
  printanewline () ;
  {
    Fputs ( logfile ,  "while executing-" ) ;
    Fputs ( standardoutput ,  "while executing-" ) ;
  } 
  bstlnnumprint () ;
  markerror () ;
} 
void 
bstmildexwarnprint ( void ) 
{
  if ( ( messwithentries ) ) 
  {
    {
      Fputs ( logfile ,  " for entry " ) ;
      Fputs ( standardoutput ,  " for entry " ) ;
    } 
    printapoolstr ( citelist [citeptr ]) ;
  } 
  printanewline () ;
  {
    {
      Fputs ( logfile ,  "while executing" ) ;
      Fputs ( standardoutput ,  "while executing" ) ;
    } 
    bstwarnprint () ;
  } 
} 
void 
bstcantmesswithentriesprint ( void ) 
{
  {
    {
      Fputs ( logfile ,  "You can't mess with entries here" ) ;
      Fputs ( standardoutput ,  "You can't mess with entries here" ) ;
    } 
    bstexwarnprint () ;
  } 
} 
void 
illeglliteralconfusion ( void ) 
{
  {
    {
      Fputs ( logfile ,  "Illegal literal type" ) ;
      Fputs ( standardoutput ,  "Illegal literal type" ) ;
    } 
    printconfusion () ;
    longjmp(jmp9998,1) ;
  } 
} 
void 
unknwnliteralconfusion ( void ) 
{
  {
    {
      Fputs ( logfile ,  "Unknown literal type" ) ;
      Fputs ( standardoutput ,  "Unknown literal type" ) ;
    } 
    printconfusion () ;
    longjmp(jmp9998,1) ;
  } 
} 
void 
zprintstklit ( integer stklt , stktype stktp ) 
{
  switch ( ( stktp ) ) 
  {case 0 : 
    {
      fprintf ( logfile , "%ld%s",  (long)stklt , " is an integer literal" ) ;
      fprintf ( standardoutput , "%ld%s",  (long)stklt , " is an integer literal" ) ;
    } 
    break ;
  case 1 : 
    {
      {
	putc ( '"' ,  logfile );
	putc ( '"' ,  standardoutput );
      } 
      printapoolstr ( stklt ) ;
      {
	Fputs ( logfile ,  "\" is a string literal" ) ;
	Fputs ( standardoutput ,  "\" is a string literal" ) ;
      } 
    } 
    break ;
  case 2 : 
    {
      {
	putc ( '`' ,  logfile );
	putc ( '`' ,  standardoutput );
      } 
      printapoolstr ( hashtext [stklt ]) ;
      {
	Fputs ( logfile ,  "' is a function literal" ) ;
	Fputs ( standardoutput ,  "' is a function literal" ) ;
      } 
    } 
    break ;
  case 3 : 
    {
      {
	putc ( '`' ,  logfile );
	putc ( '`' ,  standardoutput );
      } 
      printapoolstr ( stklt ) ;
      {
	Fputs ( logfile ,  "' is a missing field" ) ;
	Fputs ( standardoutput ,  "' is a missing field" ) ;
      } 
    } 
    break ;
  case 4 : 
    illeglliteralconfusion () ;
    break ;
    default: 
    unknwnliteralconfusion () ;
    break ;
  } 
} 
void 
zprintlit ( integer stklt , stktype stktp ) 
{
  switch ( ( stktp ) ) 
  {case 0 : 
    {
      fprintf ( logfile , "%ld\n",  (long)stklt ) ;
      fprintf ( standardoutput , "%ld\n",  (long)stklt ) ;
    } 
    break ;
  case 1 : 
    {
      printapoolstr ( stklt ) ;
      printanewline () ;
    } 
    break ;
  case 2 : 
    {
      printapoolstr ( hashtext [stklt ]) ;
      printanewline () ;
    } 
    break ;
  case 3 : 
    {
      printapoolstr ( stklt ) ;
      printanewline () ;
    } 
    break ;
  case 4 : 
    illeglliteralconfusion () ;
    break ;
    default: 
    unknwnliteralconfusion () ;
    break ;
  } 
} 
void 
outputbblline ( void ) 
{
  /* 15 10 */ if ( ( outbuflength != 0 ) ) 
  {
    while ( ( outbuflength > 0 ) ) if ( ( lexclass [outbuf [outbuflength - 1 
    ]]== 1 ) ) 
    outbuflength = outbuflength - 1 ;
    else goto lab15 ;
    lab15: if ( ( outbuflength == 0 ) ) 
    goto lab10 ;
    outbufptr = 0 ;
    while ( ( outbufptr < outbuflength ) ) {
	
      putc ( xchr [outbuf [outbufptr ]],  bblfile );
      outbufptr = outbufptr + 1 ;
    } 
  } 
  putc ('\n',  bblfile );
  bbllinenum = bbllinenum + 1 ;
  outbuflength = 0 ;
  lab10: ;
} 
void 
bst1printstringsizeexceeded ( void ) 
{
  {
    Fputs ( logfile ,  "Warning--you've exceeded " ) ;
    Fputs ( standardoutput ,  "Warning--you've exceeded " ) ;
  } 
} 
void 
bst2printstringsizeexceeded ( void ) 
{
  {
    Fputs ( logfile ,  "-string-size," ) ;
    Fputs ( standardoutput ,  "-string-size," ) ;
  } 
  bstmildexwarnprint () ;
  {
    fprintf ( logfile , "%s\n",  "*Please notify the bibstyle designer*" ) ;
    fprintf ( standardoutput , "%s\n",  "*Please notify the bibstyle designer*" ) ;
  } 
} 
void 
zbracesunbalancedcomplaint ( strnumber poplitvar ) 
{
  {
    Fputs ( logfile ,  "Warning--\"" ) ;
    Fputs ( standardoutput ,  "Warning--\"" ) ;
  } 
  printapoolstr ( poplitvar ) ;
  {
    {
      Fputs ( logfile ,  "\" isn't a brace-balanced string" ) ;
      Fputs ( standardoutput ,  "\" isn't a brace-balanced string" ) ;
    } 
    bstmildexwarnprint () ;
  } 
} 
void 
caseconversionconfusion ( void ) 
{
  {
    {
      Fputs ( logfile ,  "Unknown type of case conversion" ) ;
      Fputs ( standardoutput ,  "Unknown type of case conversion" ) ;
    } 
    printconfusion () ;
    longjmp(jmp9998,1) ;
  } 
} 
void 
traceandstatprinting ( void ) 
{
  
	;
#ifdef TRACE
  {
    if ( ( numbibfiles == 1 ) ) 
    {
      fprintf ( logfile , "%s\n",  "The 1 database file is" ) ;
    } 
    else {
	
      fprintf ( logfile , "%s%ld%s\n",  "The " , (long)numbibfiles , " database files are" ) ;
    } 
    if ( ( numbibfiles == 0 ) ) 
    {
      fprintf ( logfile , "%s\n",  "   undefined" ) ;
    } 
    else {
	
      bibptr = 0 ;
      while ( ( bibptr < numbibfiles ) ) {
	  
	{
	  Fputs ( logfile ,  "   " ) ;
	} 
	{
	  outpoolstr ( logfile , biblist [bibptr ]) ;
	} 
	{
	  outpoolstr ( logfile , sbibextension ) ;
	} 
	{
	  putc ('\n',  logfile );
	} 
	bibptr = bibptr + 1 ;
      } 
    } 
    {
      Fputs ( logfile ,  "The style file is " ) ;
    } 
    if ( ( bststr == 0 ) ) 
    {
      fprintf ( logfile , "%s\n",  "undefined" ) ;
    } 
    else {
	
      {
	outpoolstr ( logfile , bststr ) ;
      } 
      {
	outpoolstr ( logfile , sbstextension ) ;
      } 
      {
	putc ('\n',  logfile );
      } 
    } 
  } 
  {
    if ( ( allentries ) ) 
    {
      fprintf ( logfile , "%s%ld%s",  "all_marker=" , (long)allmarker , ", " ) ;
    } 
    if ( ( readperformed ) ) 
    {
      fprintf ( logfile , "%s%ld\n",  "old_num_cites=" , (long)oldnumcites ) ;
    } 
    else {
	
      putc ('\n',  logfile );
    } 
    {
      fprintf ( logfile , "%s%ld",  "The " , (long)numcites ) ;
    } 
    if ( ( numcites == 1 ) ) 
    {
      fprintf ( logfile , "%s\n",  " entry:" ) ;
    } 
    else {
	
      fprintf ( logfile , "%s\n",  " entries:" ) ;
    } 
    if ( ( numcites == 0 ) ) 
    {
      fprintf ( logfile , "%s\n",  "   undefined" ) ;
    } 
    else {
	
      sortciteptr = 0 ;
      while ( ( sortciteptr < numcites ) ) {
	  
	if ( ( ! readcompleted ) ) 
	citeptr = sortciteptr ;
	else citeptr = citeinfo [sortciteptr ];
	{
	  outpoolstr ( logfile , citelist [citeptr ]) ;
	} 
	if ( ( readperformed ) ) 
	{
	  {
	    Fputs ( logfile ,  ", entry-type " ) ;
	  } 
	  if ( ( typelist [citeptr ]== undefined ) ) 
	  {
	    Fputs ( logfile ,  "unknown" ) ;
	  } 
	  else if ( ( typelist [citeptr ]== 0 ) ) 
	  {
	    Fputs ( logfile ,  "--- no type found" ) ;
	  } 
	  else {
	      
	    outpoolstr ( logfile , hashtext [typelist [citeptr ]]) ;
	  } 
	  {
	    fprintf ( logfile , "%s\n",  ", has entry strings" ) ;
	  } 
	  {
	    if ( ( numentstrs == 0 ) ) 
	    {
	      fprintf ( logfile , "%s\n",  "    undefined" ) ;
	    } 
	    else if ( ( ! readcompleted ) ) 
	    {
	      fprintf ( logfile , "%s\n",  "    uninitialized" ) ;
	    } 
	    else {
		
	      strentptr = citeptr * numentstrs ;
	      while ( ( strentptr < ( citeptr + 1 ) * numentstrs ) ) {
		  
		entchrptr = 0 ;
		{
		  Fputs ( logfile ,  "    \"" ) ;
		} 
		while ( ( entrystrs [( strentptr ) * ( entstrsize + 1 ) + ( 
		entchrptr ) ]!= 127 ) ) {
		    
		  {
		    putc ( xchr [entrystrs [( strentptr ) * (                     entstrsize + 1 ) + ( entchrptr ) ]],  logfile );
		  } 
		  entchrptr = entchrptr + 1 ;
		} 
		{
		  { putc ( '"' ,  logfile );  putc ( '\n',  logfile ); }
		} 
		strentptr = strentptr + 1 ;
	      } 
	    } 
	  } 
	  {
	    Fputs ( logfile ,  "  has entry integers" ) ;
	  } 
	  {
	    if ( ( numentints == 0 ) ) 
	    {
	      Fputs ( logfile ,  " undefined" ) ;
	    } 
	    else if ( ( ! readcompleted ) ) 
	    {
	      Fputs ( logfile ,  " uninitialized" ) ;
	    } 
	    else {
		
	      intentptr = citeptr * numentints ;
	      while ( ( intentptr < ( citeptr + 1 ) * numentints ) ) {
		  
		{
		  fprintf ( logfile , "%c%ld",  ' ' , (long)entryints [intentptr ]) ;
		} 
		intentptr = intentptr + 1 ;
	      } 
	    } 
	    {
	      putc ('\n',  logfile );
	    } 
	  } 
	  {
	    fprintf ( logfile , "%s\n",  "  and has fields" ) ;
	  } 
	  {
	    if ( ( ! readperformed ) ) 
	    {
	      fprintf ( logfile , "%s\n",  "    uninitialized" ) ;
	    } 
	    else {
		
	      fieldptr = citeptr * numfields ;
	      fieldendptr = fieldptr + numfields ;
	      if ( ( fieldendptr > maxfields ) ) 
	      {
		{
		  Fputs ( logfile ,  "field_info index is out of range" ) ;
		  Fputs ( standardoutput ,  "field_info index is out of range"                   ) ;
		} 
		printconfusion () ;
		longjmp(jmp9998,1) ;
	      } 
	      nofields = true ;
	      while ( ( fieldptr < fieldendptr ) ) {
		  
		if ( ( fieldinfo [fieldptr ]!= 0 ) ) 
		{
		  {
		    Fputs ( logfile ,  "    \"" ) ;
		  } 
		  {
		    outpoolstr ( logfile , fieldinfo [fieldptr ]) ;
		  } 
		  {
		    { putc ( '"' ,  logfile );  putc ( '\n',  logfile ); }
		  } 
		  nofields = false ;
		} 
		fieldptr = fieldptr + 1 ;
	      } 
	      if ( ( nofields ) ) 
	      {
		fprintf ( logfile , "%s\n",  "    missing" ) ;
	      } 
	    } 
	  } 
	} 
	else {
	    
	  putc ('\n',  logfile );
	} 
	sortciteptr = sortciteptr + 1 ;
      } 
    } 
  } 
  {
    {
      fprintf ( logfile , "%s\n",  "The wiz-defined functions are" ) ;
    } 
    if ( ( wizdefptr == 0 ) ) 
    {
      fprintf ( logfile , "%s\n",  "   nonexistent" ) ;
    } 
    else {
	
      wizfnptr = 0 ;
      while ( ( wizfnptr < wizdefptr ) ) {
	  
	if ( ( wizfunctions [wizfnptr ]== endofdef ) ) 
	{
	  fprintf ( logfile , "%ld%s\n",  (long)wizfnptr , "--end-of-def--" ) ;
	} 
	else if ( ( wizfunctions [wizfnptr ]== quotenextfn ) ) 
	{
	  fprintf ( logfile , "%ld%s",  (long)wizfnptr , "  quote_next_function    " ) ;
	} 
	else {
	    
	  {
	    fprintf ( logfile , "%ld%s",  (long)wizfnptr , "  `" ) ;
	  } 
	  {
	    outpoolstr ( logfile , hashtext [wizfunctions [wizfnptr ]]) ;
	  } 
	  {
	    { putc ( '\'' ,  logfile );  putc ( '\n',  logfile ); }
	  } 
	} 
	wizfnptr = wizfnptr + 1 ;
      } 
    } 
  } 
  {
    {
      fprintf ( logfile , "%s\n",  "The string pool is" ) ;
    } 
    strnum = 1 ;
    while ( ( strnum < strptr ) ) {
	
      {
	fprintf ( logfile , "%ld%ld%s",  (long)strnum , (long)strstart [strnum ], " \"" ) ;
      } 
      {
	outpoolstr ( logfile , strnum ) ;
      } 
      {
	{ putc ( '"' ,  logfile );  putc ( '\n',  logfile ); }
      } 
      strnum = strnum + 1 ;
    } 
  } 
#endif /* TRACE */
	;
#ifndef NO_BIBTEX_STAT
  {
    {
      fprintf ( logfile , "%s%ld",  "You've used " , (long)numcites ) ;
    } 
    if ( ( numcites == 1 ) ) 
    {
      fprintf ( logfile , "%s\n",  " entry," ) ;
    } 
    else {
	
      fprintf ( logfile , "%s\n",  " entries," ) ;
    } 
    {
      fprintf ( logfile , "%s%ld%s\n",  "            " , (long)wizdefptr ,       " wiz_defined-function locations," ) ;
    } 
    {
      fprintf ( logfile , "%s%ld%s%ld%s\n",  "            " , (long)strptr , " strings with " ,       (long)strstart [strptr ], " characters," ) ;
    } 
    bltinptr = 0 ;
    totalexcount = 0 ;
    while ( ( bltinptr < numbltinfns ) ) {
	
      totalexcount = totalexcount + executioncount [bltinptr ];
      bltinptr = bltinptr + 1 ;
    } 
    {
      fprintf ( logfile , "%s%ld%s\n",  "and the built_in function-call counts, " ,       (long)totalexcount , " in all, are:" ) ;
    } 
    bltinptr = 0 ;
    while ( ( bltinptr < numbltinfns ) ) {
	
      {
	outpoolstr ( logfile , hashtext [bltinloc [bltinptr ]]) ;
      } 
      {
	fprintf ( logfile , "%s%ld\n",  " -- " , (long)executioncount [bltinptr ]) ;
      } 
      bltinptr = bltinptr + 1 ;
    } 
  } 
#endif /* not NO_BIBTEX_STAT */
} 
void 
zstartname ( strnumber filename ) 
{
  poolpointer pptr  ;
  free ( nameoffile ) ;
  nameoffile = xmallocarray ( ASCIIcode , ( strstart [filename + 1 ]- 
  strstart [filename ]) + 1 ) ;
  nameptr = 1 ;
  pptr = strstart [filename ];
  while ( ( pptr < strstart [filename + 1 ]) ) {
      
    nameoffile [nameptr ]= chr ( strpool [pptr ]) ;
    nameptr = nameptr + 1 ;
    pptr = pptr + 1 ;
  } 
  namelength = ( strstart [filename + 1 ]- strstart [filename ]) ;
  nameoffile [namelength + 1 ]= 0 ;
} 
void 
zaddextension ( strnumber ext ) 
{
  poolpointer pptr  ;
  nameptr = namelength + 1 ;
  pptr = strstart [ext ];
  while ( ( pptr < strstart [ext + 1 ]) ) {
      
    nameoffile [nameptr ]= chr ( strpool [pptr ]) ;
    nameptr = nameptr + 1 ;
    pptr = pptr + 1 ;
  } 
  namelength = namelength + ( strstart [ext + 1 ]- strstart [ext ]) ;
  nameoffile [namelength + 1 ]= 0 ;
} 
strnumber 
makestring ( void ) 
{
  register strnumber Result; if ( ( strptr == maxstrings ) ) 
  {
    printoverflow () ;
    {
      fprintf ( logfile , "%s%ld\n",  "number of strings " , (long)maxstrings ) ;
      fprintf ( standardoutput , "%s%ld\n",  "number of strings " , (long)maxstrings ) ;
    } 
    longjmp(jmp9998,1) ;
  } 
  strptr = strptr + 1 ;
  strstart [strptr ]= poolptr ;
  Result = strptr - 1 ;
  return Result ;
} 
boolean 
zstreqbuf ( strnumber s , buftype buf , bufpointer bfptr , bufpointer len ) 
{
  /* 10 */ register boolean Result; bufpointer i  ;
  poolpointer j  ;
  if ( ( ( strstart [s + 1 ]- strstart [s ]) != len ) ) 
  {
    Result = false ;
    goto lab10 ;
  } 
  i = bfptr ;
  j = strstart [s ];
  while ( ( j < strstart [s + 1 ]) ) {
      
    if ( ( strpool [j ]!= buf [i ]) ) 
    {
      Result = false ;
      goto lab10 ;
    } 
    i = i + 1 ;
    j = j + 1 ;
  } 
  Result = true ;
  lab10: ;
  return Result ;
} 
boolean 
zstreqstr ( strnumber s1 , strnumber s2 ) 
{
  /* 10 */ register boolean Result; if ( ( ( strstart [s1 + 1 ]- strstart 
  [s1 ]) != ( strstart [s2 + 1 ]- strstart [s2 ]) ) ) 
  {
    Result = false ;
    goto lab10 ;
  } 
  pptr1 = strstart [s1 ];
  pptr2 = strstart [s2 ];
  while ( ( pptr1 < strstart [s1 + 1 ]) ) {
      
    if ( ( strpool [pptr1 ]!= strpool [pptr2 ]) ) 
    {
      Result = false ;
      goto lab10 ;
    } 
    pptr1 = pptr1 + 1 ;
    pptr2 = pptr2 + 1 ;
  } 
  Result = true ;
  lab10: ;
  return Result ;
} 
void 
zlowercase ( buftype buf , bufpointer bfptr , bufpointer len ) 
{
  bufpointer i  ;
  if ( ( len > 0 ) ) 
  {register integer for_end; i = bfptr ;for_end = bfptr + len - 1 ; if ( i 
  <= for_end) do 
    if ( ( ( buf [i ]>= 65 ) && ( buf [i ]<= 90 ) ) ) 
    buf [i ]= buf [i ]+ 32 ;
  while ( i++ < for_end ) ;} 
} 
void 
zuppercase ( buftype buf , bufpointer bfptr , bufpointer len ) 
{
  bufpointer i  ;
  if ( ( len > 0 ) ) 
  {register integer for_end; i = bfptr ;for_end = bfptr + len - 1 ; if ( i 
  <= for_end) do 
    if ( ( ( buf [i ]>= 97 ) && ( buf [i ]<= 122 ) ) ) 
    buf [i ]= buf [i ]- 32 ;
  while ( i++ < for_end ) ;} 
} 
hashloc 
zstrlookup ( buftype buf , bufpointer j , bufpointer l , strilk ilk , boolean 
insertit ) 
{
  /* 40 45 */ register hashloc Result; integer h  ;
  hashloc p  ;
  bufpointer k  ;
  strnumber strnum  ;
  {
    h = 0 ;
    k = j ;
    while ( ( k < j + l ) ) {
	
      h = h + h + buf [k ];
      while ( ( h >= hashprime ) ) h = h - hashprime ;
      k = k + 1 ;
    } 
  } 
  p = h + hashbase ;
  hashfound = false ;
  strnum = 0 ;
  while ( true ) {
      
    {
      if ( ( hashtext [p ]> 0 ) ) {
	  
	if ( ( streqbuf ( hashtext [p ], buf , j , l ) ) ) {
	    
	  if ( ( hashilk [p ]== ilk ) ) 
	  {
	    hashfound = true ;
	    goto lab40 ;
	  } 
	  else {
	      
	    strnum = hashtext [p ];
	  } 
	} 
      } 
    } 
    if ( ( hashnext [p ]== 0 ) ) 
    {
      if ( ( ! insertit ) ) 
      goto lab45 ;
      {
	if ( ( hashtext [p ]> 0 ) ) 
	{
	  do {
	      if ( ( ( hashused == hashbase ) ) ) 
	    {
	      printoverflow () ;
	      {
		fprintf ( logfile , "%s%ld\n",  "hash size " , (long)hashsize ) ;
		fprintf ( standardoutput , "%s%ld\n",  "hash size " , (long)hashsize ) ;
	      } 
	      longjmp(jmp9998,1) ;
	    } 
	    hashused = hashused - 1 ;
	  } while ( ! ( ( hashtext [hashused ]== 0 ) ) ) ;
	  hashnext [p ]= hashused ;
	  p = hashused ;
	} 
	if ( ( strnum > 0 ) ) 
	hashtext [p ]= strnum ;
	else {
	    
	  {
	    while ( ( poolptr + l > poolsize ) ) pooloverflow () ;
	  } 
	  k = j ;
	  while ( ( k < j + l ) ) {
	      
	    {
	      strpool [poolptr ]= buf [k ];
	      poolptr = poolptr + 1 ;
	    } 
	    k = k + 1 ;
	  } 
	  hashtext [p ]= makestring () ;
	} 
	hashilk [p ]= ilk ;
      } 
      goto lab40 ;
    } 
    p = hashnext [p ];
  } 
  lab45: ;
  lab40: Result = p ;
  return Result ;
} 
void 
zpredefine ( pdstype pds , pdslen len , strilk ilk ) 
{
  pdslen i  ;
  {register integer for_end; i = 1 ;for_end = len ; if ( i <= for_end) do 
    buffer [i ]= xord [ucharcast ( pds [i - 1 ]) ];
  while ( i++ < for_end ) ;} 
  predefloc = strlookup ( buffer , 1 , len , ilk , true ) ;
} 
void 
zzinttoASCII ( integer theint , buftype intbuf , bufpointer intbegin , 
bufpointer * intend ) 
{
  bufpointer intptr, intxptr  ;
  ASCIIcode inttmpval  ;
  intptr = intbegin ;
  if ( ( theint < 0 ) ) 
  {
    {
      if ( ( intptr == bufsize ) ) 
      bufferoverflow () ;
      intbuf [intptr ]= 45 ;
      intptr = intptr + 1 ;
    } 
    theint = - (integer) theint ;
  } 
  intxptr = intptr ;
  do {
      { 
      if ( ( intptr == bufsize ) ) 
      bufferoverflow () ;
      intbuf [intptr ]= 48 + ( theint % 10 ) ;
      intptr = intptr + 1 ;
    } 
    theint = theint / 10 ;
  } while ( ! ( ( theint == 0 ) ) ) ;
*  intend = intptr ;
  intptr = intptr - 1 ;
  while ( ( intxptr < intptr ) ) {
      
    inttmpval = intbuf [intxptr ];
    intbuf [intxptr ]= intbuf [intptr ];
    intbuf [intptr ]= inttmpval ;
    intptr = intptr - 1 ;
    intxptr = intxptr + 1 ;
  } 
} 
void 
zzadddatabasecite ( citenumber * newcite ) 
{
  checkciteoverflow ( *newcite ) ;
  checkfieldoverflow ( numfields * ( *newcite + 1 ) ) ;
  citelist [*newcite ]= hashtext [citeloc ];
  ilkinfo [citeloc ]= *newcite ;
  ilkinfo [lcciteloc ]= citeloc ;
*  newcite = *newcite + 1 ;
} 
boolean 
zfindcitelocsforthiscitekey ( strnumber citestr ) 
{
  register boolean Result; exbufptr = 0 ;
  tmpptr = strstart [citestr ];
  tmpendptr = strstart [citestr + 1 ];
  while ( ( tmpptr < tmpendptr ) ) {
      
    exbuf [exbufptr ]= strpool [tmpptr ];
    exbufptr = exbufptr + 1 ;
    tmpptr = tmpptr + 1 ;
  } 
  citeloc = strlookup ( exbuf , 0 , ( strstart [citestr + 1 ]- strstart [
  citestr ]) , 9 , false ) ;
  citehashfound = hashfound ;
  lowercase ( exbuf , 0 , ( strstart [citestr + 1 ]- strstart [citestr ]) 
  ) ;
  lcciteloc = strlookup ( exbuf , 0 , ( strstart [citestr + 1 ]- strstart [
  citestr ]) , 10 , false ) ;
  if ( ( hashfound ) ) 
  Result = true ;
  else Result = false ;
  return Result ;
} 
void 
zswap ( citenumber swap1 , citenumber swap2 ) 
{
  citenumber innocentbystander  ;
  innocentbystander = citeinfo [swap2 ];
  citeinfo [swap2 ]= citeinfo [swap1 ];
  citeinfo [swap1 ]= innocentbystander ;
} 
boolean 
zlessthan ( citenumber arg1 , citenumber arg2 ) 
{
  /* 10 */ register boolean Result; integer charptr  ;
  strentloc ptr1, ptr2  ;
  ASCIIcode char1, char2  ;
  ptr1 = arg1 * numentstrs + sortkeynum ;
  ptr2 = arg2 * numentstrs + sortkeynum ;
  charptr = 0 ;
  while ( true ) {
      
    char1 = entrystrs [( ptr1 ) * ( entstrsize + 1 ) + ( charptr ) ];
    char2 = entrystrs [( ptr2 ) * ( entstrsize + 1 ) + ( charptr ) ];
    if ( ( char1 == 127 ) ) {
	
      if ( ( char2 == 127 ) ) {
	  
	if ( ( arg1 < arg2 ) ) 
	{
	  Result = true ;
	  goto lab10 ;
	} 
	else if ( ( arg1 > arg2 ) ) 
	{
	  Result = false ;
	  goto lab10 ;
	} 
	else {
	    
	  {
	    Fputs ( logfile ,  "Duplicate sort key" ) ;
	    Fputs ( standardoutput ,  "Duplicate sort key" ) ;
	  } 
	  printconfusion () ;
	  longjmp(jmp9998,1) ;
	} 
      } 
      else {
	  
	Result = true ;
	goto lab10 ;
      } 
    } 
    else if ( ( char2 == 127 ) ) 
    {
      Result = false ;
      goto lab10 ;
    } 
    else if ( ( char1 < char2 ) ) 
    {
      Result = true ;
      goto lab10 ;
    } 
    else if ( ( char1 > char2 ) ) 
    {
      Result = false ;
      goto lab10 ;
    } 
    charptr = charptr + 1 ;
  } 
  lab10: ;
  return Result ;
} 
void 
zquicksort ( citenumber leftend , citenumber rightend ) 
{
  /* 24 */ citenumber left, right  ;
  citenumber insertptr  ;
  citenumber middle  ;
  citenumber partition  ;
	;
#ifdef TRACE
  {
    fprintf ( logfile , "%s%ld%s%ld\n",  "Sorting " , (long)leftend , " through " , (long)rightend ) ;
  } 
#endif /* TRACE */
  if ( ( rightend - leftend < 10 ) ) 
  {
    {register integer for_end; insertptr = leftend + 1 ;for_end = rightend 
    ; if ( insertptr <= for_end) do 
      {
	{register integer for_end; right = insertptr ;for_end = leftend + 1 
	; if ( right >= for_end) do 
	  {
	    if ( ( lessthan ( citeinfo [right - 1 ], citeinfo [right ]) ) 
	    ) 
	    goto lab24 ;
	    swap ( right - 1 , right ) ;
	  } 
	while ( right-- > for_end ) ;} 
	lab24: ;
      } 
    while ( insertptr++ < for_end ) ;} 
  } 
  else {
      
    {
      left = leftend + 4 ;
      middle = ( leftend + rightend ) / 2 ;
      right = rightend - 4 ;
      if ( ( lessthan ( citeinfo [left ], citeinfo [middle ]) ) ) {
	  
	if ( ( lessthan ( citeinfo [middle ], citeinfo [right ]) ) ) 
	swap ( leftend , middle ) ;
	else if ( ( lessthan ( citeinfo [left ], citeinfo [right ]) ) ) 
	swap ( leftend , right ) ;
	else swap ( leftend , left ) ;
      } 
      else if ( ( lessthan ( citeinfo [right ], citeinfo [middle ]) ) ) 
      swap ( leftend , middle ) ;
      else if ( ( lessthan ( citeinfo [right ], citeinfo [left ]) ) ) 
      swap ( leftend , right ) ;
      else swap ( leftend , left ) ;
    } 
    {
      partition = citeinfo [leftend ];
      left = leftend + 1 ;
      right = rightend ;
      do {
	  while ( ( lessthan ( citeinfo [left ], partition ) ) ) left = 
	left + 1 ;
	while ( ( lessthan ( partition , citeinfo [right ]) ) ) right = 
	right - 1 ;
	if ( ( left < right ) ) 
	{
	  swap ( left , right ) ;
	  left = left + 1 ;
	  right = right - 1 ;
	} 
      } while ( ! ( ( left == right + 1 ) ) ) ;
      swap ( leftend , right ) ;
      quicksort ( leftend , right - 1 ) ;
      quicksort ( left , rightend ) ;
    } 
  } 
} 
void 
zzbuildin ( pdstype pds , pdslen len , hashloc * fnhashloc , bltinrange 
bltinnum ) 
{
  predefine ( pds , len , 11 ) ;
*  fnhashloc = predefloc ;
  fntype [*fnhashloc ]= 0 ;
  ilkinfo [*fnhashloc ]= bltinnum ;
	;
#ifndef NO_BIBTEX_STAT
  bltinloc [bltinnum ]= *fnhashloc ;
  executioncount [bltinnum ]= 0 ;
#endif /* not NO_BIBTEX_STAT */
} 
void 
predefcertainstrings ( void ) 
{
  predefine ( ".aux        " , 4 , 7 ) ;
  sauxextension = hashtext [predefloc ];
  predefine ( ".bbl        " , 4 , 7 ) ;
  sbblextension = hashtext [predefloc ];
  predefine ( ".blg        " , 4 , 7 ) ;
  slogextension = hashtext [predefloc ];
  predefine ( ".bst        " , 4 , 7 ) ;
  sbstextension = hashtext [predefloc ];
  predefine ( ".bib        " , 4 , 7 ) ;
  sbibextension = hashtext [predefloc ];
  predefine ( "texinputs:  " , 10 , 8 ) ;
  sbstarea = hashtext [predefloc ];
  predefine ( "texbib:     " , 7 , 8 ) ;
  sbibarea = hashtext [predefloc ];
  predefine ( "\\citation   " , 9 , 2 ) ;
  ilkinfo [predefloc ]= 2 ;
  predefine ( "\\bibdata    " , 8 , 2 ) ;
  ilkinfo [predefloc ]= 0 ;
  predefine ( "\\bibstyle   " , 9 , 2 ) ;
  ilkinfo [predefloc ]= 1 ;
  predefine ( "\\@input     " , 7 , 2 ) ;
  ilkinfo [predefloc ]= 3 ;
  predefine ( "entry       " , 5 , 4 ) ;
  ilkinfo [predefloc ]= 0 ;
  predefine ( "execute     " , 7 , 4 ) ;
  ilkinfo [predefloc ]= 1 ;
  predefine ( "function    " , 8 , 4 ) ;
  ilkinfo [predefloc ]= 2 ;
  predefine ( "integers    " , 8 , 4 ) ;
  ilkinfo [predefloc ]= 3 ;
  predefine ( "iterate     " , 7 , 4 ) ;
  ilkinfo [predefloc ]= 4 ;
  predefine ( "macro       " , 5 , 4 ) ;
  ilkinfo [predefloc ]= 5 ;
  predefine ( "read        " , 4 , 4 ) ;
  ilkinfo [predefloc ]= 6 ;
  predefine ( "reverse     " , 7 , 4 ) ;
  ilkinfo [predefloc ]= 7 ;
  predefine ( "sort        " , 4 , 4 ) ;
  ilkinfo [predefloc ]= 8 ;
  predefine ( "strings     " , 7 , 4 ) ;
  ilkinfo [predefloc ]= 9 ;
  predefine ( "comment     " , 7 , 12 ) ;
  ilkinfo [predefloc ]= 0 ;
  predefine ( "preamble    " , 8 , 12 ) ;
  ilkinfo [predefloc ]= 1 ;
  predefine ( "string      " , 6 , 12 ) ;
  ilkinfo [predefloc ]= 2 ;
  buildin ( "=           " , 1 , bequals , 0 ) ;
  buildin ( ">           " , 1 , bgreaterthan , 1 ) ;
  buildin ( "<           " , 1 , blessthan , 2 ) ;
  buildin ( "+           " , 1 , bplus , 3 ) ;
  buildin ( "-           " , 1 , bminus , 4 ) ;
  buildin ( "*           " , 1 , bconcatenate , 5 ) ;
  buildin ( ":=          " , 2 , bgets , 6 ) ;
  buildin ( "add.period$ " , 11 , baddperiod , 7 ) ;
  buildin ( "call.type$  " , 10 , bcalltype , 8 ) ;
  buildin ( "change.case$" , 12 , bchangecase , 9 ) ;
  buildin ( "chr.to.int$ " , 11 , bchrtoint , 10 ) ;
  buildin ( "cite$       " , 5 , bcite , 11 ) ;
  buildin ( "duplicate$  " , 10 , bduplicate , 12 ) ;
  buildin ( "empty$      " , 6 , bempty , 13 ) ;
  buildin ( "format.name$" , 12 , bformatname , 14 ) ;
  buildin ( "if$         " , 3 , bif , 15 ) ;
  buildin ( "int.to.chr$ " , 11 , binttochr , 16 ) ;
  buildin ( "int.to.str$ " , 11 , binttostr , 17 ) ;
  buildin ( "missing$    " , 8 , bmissing , 18 ) ;
  buildin ( "newline$    " , 8 , bnewline , 19 ) ;
  buildin ( "num.names$  " , 10 , bnumnames , 20 ) ;
  buildin ( "pop$        " , 4 , bpop , 21 ) ;
  buildin ( "preamble$   " , 9 , bpreamble , 22 ) ;
  buildin ( "purify$     " , 7 , bpurify , 23 ) ;
  buildin ( "quote$      " , 6 , bquote , 24 ) ;
  buildin ( "skip$       " , 5 , bskip , 25 ) ;
  buildin ( "stack$      " , 6 , bstack , 26 ) ;
  buildin ( "substring$  " , 10 , bsubstring , 27 ) ;
  buildin ( "swap$       " , 5 , bswap , 28 ) ;
  buildin ( "text.length$" , 12 , btextlength , 29 ) ;
  buildin ( "text.prefix$" , 12 , btextprefix , 30 ) ;
  buildin ( "top$        " , 4 , btopstack , 31 ) ;
  buildin ( "type$       " , 5 , btype , 32 ) ;
  buildin ( "warning$    " , 8 , bwarning , 33 ) ;
  buildin ( "while$      " , 6 , bwhile , 34 ) ;
  buildin ( "width$      " , 6 , bwidth , 35 ) ;
  buildin ( "write$      " , 6 , bwrite , 36 ) ;
  buildin ( "is.kanji.str$" , 13 , biskanjistr , 37 ) ;
  predefine ( "            " , 0 , 0 ) ;
  snull = hashtext [predefloc ];
  fntype [predefloc ]= 3 ;
  predefine ( "default.type" , 12 , 0 ) ;
  sdefault = hashtext [predefloc ];
  fntype [predefloc ]= 3 ;
  bdefault = bskip ;
  preambleptr = 0 ;
  predefine ( "i           " , 1 , 14 ) ;
  ilkinfo [predefloc ]= 0 ;
  predefine ( "j           " , 1 , 14 ) ;
  ilkinfo [predefloc ]= 1 ;
  predefine ( "oe          " , 2 , 14 ) ;
  ilkinfo [predefloc ]= 2 ;
  predefine ( "OE          " , 2 , 14 ) ;
  ilkinfo [predefloc ]= 3 ;
  predefine ( "ae          " , 2 , 14 ) ;
  ilkinfo [predefloc ]= 4 ;
  predefine ( "AE          " , 2 , 14 ) ;
  ilkinfo [predefloc ]= 5 ;
  predefine ( "aa          " , 2 , 14 ) ;
  ilkinfo [predefloc ]= 6 ;
  predefine ( "AA          " , 2 , 14 ) ;
  ilkinfo [predefloc ]= 7 ;
  predefine ( "o           " , 1 , 14 ) ;
  ilkinfo [predefloc ]= 8 ;
  predefine ( "O           " , 1 , 14 ) ;
  ilkinfo [predefloc ]= 9 ;
  predefine ( "l           " , 1 , 14 ) ;
  ilkinfo [predefloc ]= 10 ;
  predefine ( "L           " , 1 , 14 ) ;
  ilkinfo [predefloc ]= 11 ;
  predefine ( "ss          " , 2 , 14 ) ;
  ilkinfo [predefloc ]= 12 ;
  predefine ( "crossref    " , 8 , 11 ) ;
  fntype [predefloc ]= 4 ;
  ilkinfo [predefloc ]= numfields ;
  crossrefnum = numfields ;
  numfields = numfields + 1 ;
  numpredefinedfields = numfields ;
  predefine ( "sort.key$   " , 9 , 11 ) ;
  fntype [predefloc ]= 6 ;
  ilkinfo [predefloc ]= numentstrs ;
  sortkeynum = numentstrs ;
  numentstrs = numentstrs + 1 ;
  predefine ( "entry.max$  " , 10 , 11 ) ;
  fntype [predefloc ]= 7 ;
  ilkinfo [predefloc ]= entstrsize ;
  predefine ( "global.max$ " , 11 , 11 ) ;
  fntype [predefloc ]= 7 ;
  ilkinfo [predefloc ]= globstrsize ;
} 
boolean 
zscan1 ( ASCIIcode char1 ) 
{
  register boolean Result; bufptr1 = bufptr2 ;
  while ( ( ( buffer [bufptr2 ]!= char1 ) && ( bufptr2 < last ) ) ) bufptr2 
  = bufptr2 + 1 ;
  if ( ( bufptr2 < last ) ) 
  Result = true ;
  else Result = false ;
  return Result ;
} 
boolean 
zscan1white ( ASCIIcode char1 ) 
{
  register boolean Result; bufptr1 = bufptr2 ;
  while ( ( ( lexclass [buffer [bufptr2 ]]!= 1 ) && ( buffer [bufptr2 ]
  != char1 ) && ( bufptr2 < last ) ) ) bufptr2 = bufptr2 + 1 ;
  if ( ( bufptr2 < last ) ) 
  Result = true ;
  else Result = false ;
  return Result ;
} 
boolean 
zscan2 ( ASCIIcode char1 , ASCIIcode char2 ) 
{
  register boolean Result; bufptr1 = bufptr2 ;
  while ( ( ( buffer [bufptr2 ]!= char1 ) && ( buffer [bufptr2 ]!= char2 ) 
  && ( bufptr2 < last ) ) ) bufptr2 = bufptr2 + 1 ;
  if ( ( bufptr2 < last ) ) 
  Result = true ;
  else Result = false ;
  return Result ;
} 
boolean 
zscan2white ( ASCIIcode char1 , ASCIIcode char2 ) 
{
  register boolean Result; bufptr1 = bufptr2 ;
  while ( ( ( buffer [bufptr2 ]!= char1 ) && ( buffer [bufptr2 ]!= char2 ) 
  && ( lexclass [buffer [bufptr2 ]]!= 1 ) && ( bufptr2 < last ) ) ) 
  bufptr2 = bufptr2 + 1 ;
  if ( ( bufptr2 < last ) ) 
  Result = true ;
  else Result = false ;
  return Result ;
} 
boolean 
zscan3 ( ASCIIcode char1 , ASCIIcode char2 , ASCIIcode char3 ) 
{
  register boolean Result; bufptr1 = bufptr2 ;
  while ( ( ( buffer [bufptr2 ]!= char1 ) && ( buffer [bufptr2 ]!= char2 ) 
  && ( buffer [bufptr2 ]!= char3 ) && ( bufptr2 < last ) ) ) bufptr2 = 
  bufptr2 + 1 ;
  if ( ( bufptr2 < last ) ) 
  Result = true ;
  else Result = false ;
  return Result ;
} 
boolean 
scanalpha ( void ) 
{
  register boolean Result; bufptr1 = bufptr2 ;
  while ( ( ( lexclass [buffer [bufptr2 ]]== 2 ) && ( bufptr2 < last ) ) ) 
  bufptr2 = bufptr2 + 1 ;
  if ( ( ( bufptr2 - bufptr1 ) == 0 ) ) 
  Result = false ;
  else Result = true ;
  return Result ;
} 
void 
zscanidentifier ( ASCIIcode char1 , ASCIIcode char2 , ASCIIcode char3 ) 
{
  bufptr1 = bufptr2 ;
  if ( ( lexclass [buffer [bufptr2 ]]!= 3 ) ) 
  while ( ( ( idclass [buffer [bufptr2 ]]== 1 ) && ( bufptr2 < last ) ) ) 
  bufptr2 = bufptr2 + 1 ;
  if ( ( ( bufptr2 - bufptr1 ) == 0 ) ) 
  scanresult = 0 ;
  else if ( ( ( lexclass [buffer [bufptr2 ]]== 1 ) || ( bufptr2 == last ) 
  ) ) 
  scanresult = 3 ;
  else if ( ( ( buffer [bufptr2 ]== char1 ) || ( buffer [bufptr2 ]== char2 
  ) || ( buffer [bufptr2 ]== char3 ) ) ) 
  scanresult = 1 ;
  else scanresult = 2 ;
} 
boolean 
scannonneginteger ( void ) 
{
  register boolean Result; bufptr1 = bufptr2 ;
  tokenvalue = 0 ;
  while ( ( ( lexclass [buffer [bufptr2 ]]== 3 ) && ( bufptr2 < last ) ) ) 
  {
    tokenvalue = tokenvalue * 10 + ( buffer [bufptr2 ]- 48 ) ;
    bufptr2 = bufptr2 + 1 ;
  } 
  if ( ( ( bufptr2 - bufptr1 ) == 0 ) ) 
  Result = false ;
  else Result = true ;
  return Result ;
} 
boolean 
scaninteger ( void ) 
{
  register boolean Result; unsigned char signlength  ;
  bufptr1 = bufptr2 ;
  if ( ( buffer [bufptr2 ]== 45 ) ) 
  {
    signlength = 1 ;
    bufptr2 = bufptr2 + 1 ;
  } 
  else signlength = 0 ;
  tokenvalue = 0 ;
  while ( ( ( lexclass [buffer [bufptr2 ]]== 3 ) && ( bufptr2 < last ) ) ) 
  {
    tokenvalue = tokenvalue * 10 + ( buffer [bufptr2 ]- 48 ) ;
    bufptr2 = bufptr2 + 1 ;
  } 
  if ( ( ( signlength == 1 ) ) ) 
  tokenvalue = - (integer) tokenvalue ;
  if ( ( ( bufptr2 - bufptr1 ) == signlength ) ) 
  Result = false ;
  else Result = true ;
  return Result ;
} 
boolean 
scanwhitespace ( void ) 
{
  register boolean Result; while ( ( ( lexclass [buffer [bufptr2 ]]== 1 
  ) && ( bufptr2 < last ) ) ) bufptr2 = bufptr2 + 1 ;
  if ( ( bufptr2 < last ) ) 
  Result = true ;
  else Result = false ;
  return Result ;
} 
boolean 
eatbstwhitespace ( void ) 
{
  /* 10 */ register boolean Result; while ( true ) {
      
    if ( ( scanwhitespace () ) ) {
	
      if ( ( buffer [bufptr2 ]!= 37 ) ) 
      {
	Result = true ;
	goto lab10 ;
      } 
    } 
    if ( ( ! inputln ( bstfile ) ) ) 
    {
      Result = false ;
      goto lab10 ;
    } 
    bstlinenum = bstlinenum + 1 ;
    bufptr2 = 0 ;
  } 
  lab10: ;
  return Result ;
} 
void 
skiptokenprint ( void ) 
{
  {
    putc ( '-' ,  logfile );
    putc ( '-' ,  standardoutput );
  } 
  bstlnnumprint () ;
  markerror () ;
  if ( ( scan2white ( 125 , 37 ) ) ) 
  ;
} 
void 
printrecursionillegal ( void ) 
{
  
	;
#ifdef TRACE
  {
    putc ('\n',  logfile );
  } 
#endif /* TRACE */
  {
    fprintf ( logfile , "%s\n",  "Curse you, wizard, before you recurse me:" ) ;
    fprintf ( standardoutput , "%s\n",  "Curse you, wizard, before you recurse me:" ) ;
  } 
  {
    Fputs ( logfile ,  "function " ) ;
    Fputs ( standardoutput ,  "function " ) ;
  } 
  printatoken () ;
  {
    fprintf ( logfile , "%s\n",  " is illegal in its own definition" ) ;
    fprintf ( standardoutput , "%s\n",  " is illegal in its own definition" ) ;
  } 
  skiptokenprint () ;
} 
void 
skptokenunknownfunctionprint ( void ) 
{
  printatoken () ;
  {
    Fputs ( logfile ,  " is an unknown function" ) ;
    Fputs ( standardoutput ,  " is an unknown function" ) ;
  } 
  skiptokenprint () ;
} 
void 
skipillegalstuffaftertokenprint ( void ) 
{
  {
    fprintf ( logfile , "%c%c%s",  '"' , xchr [buffer [bufptr2 ]],     "\" can't follow a literal" ) ;
    fprintf ( standardoutput , "%c%c%s",  '"' , xchr [buffer [bufptr2 ]],     "\" can't follow a literal" ) ;
  } 
  skiptokenprint () ;
} 
void 
zscanfndef ( hashloc fnhashloc ) 
{
  /* 25 10 */ typedef integer fndefloc  ;
  hashptr2 * singlfunction  ;
  integer singlefnspace  ;
  fndefloc singleptr  ;
  fndefloc copyptr  ;
  bufpointer endofnum  ;
  hashloc implfnloc  ;
  singlefnspace = SINGLEFNSPACE ;
  singlfunction = XTALLOC ( singlefnspace + 1 , hashptr2 ) ;
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "function" ) ;
	  Fputs ( standardoutput ,  "function" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  singleptr = 0 ;
  while ( ( buffer [bufptr2 ]!= 125 ) ) {
      
    switch ( ( buffer [bufptr2 ]) ) 
    {case 35 : 
      {
	bufptr2 = bufptr2 + 1 ;
	if ( ( ! scaninteger () ) ) 
	{
	  {
	    Fputs ( logfile ,  "Illegal integer in integer literal" ) ;
	    Fputs ( standardoutput ,  "Illegal integer in integer literal" ) ;
	  } 
	  skiptokenprint () ;
	  goto lab25 ;
	} 
	;
#ifdef TRACE
	{
	  putc ( '#' ,  logfile );
	} 
	{
	  outtoken ( logfile ) ;
	} 
	{
	  fprintf ( logfile , "%s%ld\n",  " is an integer literal with value " ,           (long)tokenvalue ) ;
	} 
#endif /* TRACE */
	literalloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 1 
	, true ) ;
	if ( ( ! hashfound ) ) 
	{
	  fntype [literalloc ]= 2 ;
	  ilkinfo [literalloc ]= tokenvalue ;
	} 
	if ( ( ( lexclass [buffer [bufptr2 ]]!= 1 ) && ( bufptr2 < last ) 
	&& ( buffer [bufptr2 ]!= 125 ) && ( buffer [bufptr2 ]!= 37 ) ) ) 
	{
	  skipillegalstuffaftertokenprint () ;
	  goto lab25 ;
	} 
	{
	  singlfunction [singleptr ]= literalloc ;
	  if ( ( singleptr == singlefnspace ) ) 
	  {
	    BIBXRETALLOC ( "singl_function" , singlfunction , hashptr2 , 
	    singlefnspace , singlefnspace + SINGLEFNSPACE ) ;
	  } 
	  singleptr = singleptr + 1 ;
	} 
      } 
      break ;
    case 34 : 
      {
	bufptr2 = bufptr2 + 1 ;
	if ( ( ! scan1 ( 34 ) ) ) 
	{
	  {
	    fprintf ( logfile , "%s%c%s",  "No `" , xchr [34 ], "' to end string literal"             ) ;
	    fprintf ( standardoutput , "%s%c%s",  "No `" , xchr [34 ],             "' to end string literal" ) ;
	  } 
	  skiptokenprint () ;
	  goto lab25 ;
	} 
	;
#ifdef TRACE
	{
	  putc ( '"' ,  logfile );
	} 
	{
	  outtoken ( logfile ) ;
	} 
	{
	  putc ( '"' ,  logfile );
	} 
	{
	  fprintf ( logfile , "%s\n",  " is a string literal" ) ;
	} 
#endif /* TRACE */
	literalloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 0 
	, true ) ;
	fntype [literalloc ]= 3 ;
	bufptr2 = bufptr2 + 1 ;
	if ( ( ( lexclass [buffer [bufptr2 ]]!= 1 ) && ( bufptr2 < last ) 
	&& ( buffer [bufptr2 ]!= 125 ) && ( buffer [bufptr2 ]!= 37 ) ) ) 
	{
	  skipillegalstuffaftertokenprint () ;
	  goto lab25 ;
	} 
	{
	  singlfunction [singleptr ]= literalloc ;
	  if ( ( singleptr == singlefnspace ) ) 
	  {
	    BIBXRETALLOC ( "singl_function" , singlfunction , hashptr2 , 
	    singlefnspace , singlefnspace + SINGLEFNSPACE ) ;
	  } 
	  singleptr = singleptr + 1 ;
	} 
      } 
      break ;
    case 39 : 
      {
	bufptr2 = bufptr2 + 1 ;
	if ( ( scan2white ( 125 , 37 ) ) ) 
	;
	;
#ifdef TRACE
	{
	  putc ( '\'' ,  logfile );
	} 
	{
	  outtoken ( logfile ) ;
	} 
	{
	  Fputs ( logfile ,  " is a quoted function " ) ;
	} 
#endif /* TRACE */
	lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
	fnloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 11 , 
	false ) ;
	if ( ( ! hashfound ) ) 
	{
	  skptokenunknownfunctionprint () ;
	  goto lab25 ;
	} 
	else {
	    
	  if ( ( fnloc == wizloc ) ) 
	  {
	    printrecursionillegal () ;
	    goto lab25 ;
	  } 
	  else {
	      
	;
#ifdef TRACE
	    {
	      Fputs ( logfile ,  "of type " ) ;
	    } 
	    traceprfnclass ( fnloc ) ;
	    {
	      putc ('\n',  logfile );
	    } 
#endif /* TRACE */
	    {
	      singlfunction [singleptr ]= quotenextfn ;
	      if ( ( singleptr == singlefnspace ) ) 
	      {
		BIBXRETALLOC ( "singl_function" , singlfunction , hashptr2 , 
		singlefnspace , singlefnspace + SINGLEFNSPACE ) ;
	      } 
	      singleptr = singleptr + 1 ;
	    } 
	    {
	      singlfunction [singleptr ]= fnloc ;
	      if ( ( singleptr == singlefnspace ) ) 
	      {
		BIBXRETALLOC ( "singl_function" , singlfunction , hashptr2 , 
		singlefnspace , singlefnspace + SINGLEFNSPACE ) ;
	      } 
	      singleptr = singleptr + 1 ;
	    } 
	  } 
	} 
      } 
      break ;
    case 123 : 
      {
	exbuf [0 ]= 39 ;
	inttoASCII ( implfnnum , exbuf , 1 , endofnum ) ;
	implfnloc = strlookup ( exbuf , 0 , endofnum , 11 , true ) ;
	if ( ( hashfound ) ) 
	{
	  {
	    Fputs ( logfile ,  "Already encountered implicit function" ) ;
	    Fputs ( standardoutput ,  "Already encountered implicit function" ) 
	    ;
	  } 
	  printconfusion () ;
	  longjmp(jmp9998,1) ;
	} 
	;
#ifdef TRACE
	{
	  outpoolstr ( logfile , hashtext [implfnloc ]) ;
	} 
	{
	  fprintf ( logfile , "%s\n",  " is an implicit function" ) ;
	} 
#endif /* TRACE */
	implfnnum = implfnnum + 1 ;
	fntype [implfnloc ]= 1 ;
	{
	  singlfunction [singleptr ]= quotenextfn ;
	  if ( ( singleptr == singlefnspace ) ) 
	  {
	    BIBXRETALLOC ( "singl_function" , singlfunction , hashptr2 , 
	    singlefnspace , singlefnspace + SINGLEFNSPACE ) ;
	  } 
	  singleptr = singleptr + 1 ;
	} 
	{
	  singlfunction [singleptr ]= implfnloc ;
	  if ( ( singleptr == singlefnspace ) ) 
	  {
	    BIBXRETALLOC ( "singl_function" , singlfunction , hashptr2 , 
	    singlefnspace , singlefnspace + SINGLEFNSPACE ) ;
	  } 
	  singleptr = singleptr + 1 ;
	} 
	bufptr2 = bufptr2 + 1 ;
	scanfndef ( implfnloc ) ;
      } 
      break ;
      default: 
      {
	if ( ( scan2white ( 125 , 37 ) ) ) 
	;
	;
#ifdef TRACE
	{
	  outtoken ( logfile ) ;
	} 
	{
	  Fputs ( logfile ,  " is a function " ) ;
	} 
#endif /* TRACE */
	lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
	fnloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 11 , 
	false ) ;
	if ( ( ! hashfound ) ) 
	{
	  skptokenunknownfunctionprint () ;
	  goto lab25 ;
	} 
	else if ( ( fnloc == wizloc ) ) 
	{
	  printrecursionillegal () ;
	  goto lab25 ;
	} 
	else {
	    
	;
#ifdef TRACE
	  {
	    Fputs ( logfile ,  "of type " ) ;
	  } 
	  traceprfnclass ( fnloc ) ;
	  {
	    putc ('\n',  logfile );
	  } 
#endif /* TRACE */
	  {
	    singlfunction [singleptr ]= fnloc ;
	    if ( ( singleptr == singlefnspace ) ) 
	    {
	      BIBXRETALLOC ( "singl_function" , singlfunction , hashptr2 , 
	      singlefnspace , singlefnspace + SINGLEFNSPACE ) ;
	    } 
	    singleptr = singleptr + 1 ;
	  } 
	} 
      } 
      break ;
    } 
    lab25: {
	
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "function" ) ;
	    Fputs ( standardoutput ,  "function" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
  } 
  {
    {
      singlfunction [singleptr ]= endofdef ;
      if ( ( singleptr == singlefnspace ) ) 
      {
	BIBXRETALLOC ( "singl_function" , singlfunction , hashptr2 , 
	singlefnspace , singlefnspace + SINGLEFNSPACE ) ;
      } 
      singleptr = singleptr + 1 ;
    } 
    while ( ( singleptr + wizdefptr > wizfnspace ) ) {
	
      BIBXRETALLOC ( "wiz_functions" , wizfunctions , hashptr2 , wizfnspace , 
      wizfnspace + WIZFNSPACE ) ;
    } 
    ilkinfo [fnhashloc ]= wizdefptr ;
    copyptr = 0 ;
    while ( ( copyptr < singleptr ) ) {
	
      wizfunctions [wizdefptr ]= singlfunction [copyptr ];
      copyptr = copyptr + 1 ;
      wizdefptr = wizdefptr + 1 ;
    } 
  } 
  bufptr2 = bufptr2 + 1 ;
  lab10: libcfree ( singlfunction ) ;
} 
boolean 
eatbibwhitespace ( void ) 
{
  /* 10 */ register boolean Result; while ( ( ! scanwhitespace () ) ) {
      
    if ( ( ! inputln ( bibfile [bibptr ]) ) ) 
    {
      Result = false ;
      goto lab10 ;
    } 
    biblinenum = biblinenum + 1 ;
    bufptr2 = 0 ;
  } 
  Result = true ;
  lab10: ;
  return Result ;
} 
boolean 
compressbibwhite ( void ) 
{
  /* 10 */ register boolean Result; Result = false ;
  {
    if ( ( exbufptr == bufsize ) ) 
    {
      bibfieldtoolongprint () ;
      goto lab10 ;
    } 
    else {
	
      exbuf [exbufptr ]= 32 ;
      exbufptr = exbufptr + 1 ;
    } 
  } 
  while ( ( ! scanwhitespace () ) ) {
      
    if ( ( ! inputln ( bibfile [bibptr ]) ) ) 
    {
      eatbibprint () ;
      goto lab10 ;
    } 
    biblinenum = biblinenum + 1 ;
    bufptr2 = 0 ;
  } 
  Result = true ;
  lab10: ;
  return Result ;
} 
boolean 
scanbalancedbraces ( void ) 
{
  /* 15 10 */ register boolean Result; Result = false ;
  bufptr2 = bufptr2 + 1 ;
  {
    if ( ( ( lexclass [buffer [bufptr2 ]]== 1 ) || ( bufptr2 == last ) ) ) 
    {
      if ( ( ! compressbibwhite () ) ) 
      goto lab10 ;
    } 
  } 
  if ( ( exbufptr > 1 ) ) {
      
    if ( ( exbuf [exbufptr - 1 ]== 32 ) ) {
	
      if ( ( exbuf [exbufptr - 2 ]== 32 ) ) 
      exbufptr = exbufptr - 1 ;
    } 
  } 
  bibbracelevel = 0 ;
  if ( ( storefield ) ) 
  {
    while ( ( buffer [bufptr2 ]!= rightstrdelim ) ) switch ( ( buffer [
    bufptr2 ]) ) 
    {case 123 : 
      {
	bibbracelevel = bibbracelevel + 1 ;
	{
	  if ( ( exbufptr == bufsize ) ) 
	  {
	    bibfieldtoolongprint () ;
	    goto lab10 ;
	  } 
	  else {
	      
	    exbuf [exbufptr ]= 123 ;
	    exbufptr = exbufptr + 1 ;
	  } 
	} 
	bufptr2 = bufptr2 + 1 ;
	{
	  if ( ( ( lexclass [buffer [bufptr2 ]]== 1 ) || ( bufptr2 == last 
	  ) ) ) {
	      
	    if ( ( ! compressbibwhite () ) ) 
	    goto lab10 ;
	  } 
	} 
	{
	  while ( true ) switch ( ( buffer [bufptr2 ]) ) 
	  {case 125 : 
	    {
	      bibbracelevel = bibbracelevel - 1 ;
	      {
		if ( ( exbufptr == bufsize ) ) 
		{
		  bibfieldtoolongprint () ;
		  goto lab10 ;
		} 
		else {
		    
		  exbuf [exbufptr ]= 125 ;
		  exbufptr = exbufptr + 1 ;
		} 
	      } 
	      bufptr2 = bufptr2 + 1 ;
	      {
		if ( ( ( lexclass [buffer [bufptr2 ]]== 1 ) || ( bufptr2 
		== last ) ) ) {
		    
		  if ( ( ! compressbibwhite () ) ) 
		  goto lab10 ;
		} 
	      } 
	      if ( ( bibbracelevel == 0 ) ) 
	      goto lab15 ;
	    } 
	    break ;
	  case 123 : 
	    {
	      bibbracelevel = bibbracelevel + 1 ;
	      {
		if ( ( exbufptr == bufsize ) ) 
		{
		  bibfieldtoolongprint () ;
		  goto lab10 ;
		} 
		else {
		    
		  exbuf [exbufptr ]= 123 ;
		  exbufptr = exbufptr + 1 ;
		} 
	      } 
	      bufptr2 = bufptr2 + 1 ;
	      {
		if ( ( ( lexclass [buffer [bufptr2 ]]== 1 ) || ( bufptr2 
		== last ) ) ) {
		    
		  if ( ( ! compressbibwhite () ) ) 
		  goto lab10 ;
		} 
	      } 
	    } 
	    break ;
	    default: 
	    {
	      {
		if ( ( exbufptr == bufsize ) ) 
		{
		  bibfieldtoolongprint () ;
		  goto lab10 ;
		} 
		else {
		    
		  exbuf [exbufptr ]= buffer [bufptr2 ];
		  exbufptr = exbufptr + 1 ;
		} 
	      } 
	      bufptr2 = bufptr2 + 1 ;
	      {
		if ( ( ( lexclass [buffer [bufptr2 ]]== 1 ) || ( bufptr2 
		== last ) ) ) {
		    
		  if ( ( ! compressbibwhite () ) ) 
		  goto lab10 ;
		} 
	      } 
	    } 
	    break ;
	  } 
	  lab15: ;
	} 
      } 
      break ;
    case 125 : 
      {
	bibunbalancedbracesprint () ;
	goto lab10 ;
      } 
      break ;
      default: 
      {
	{
	  if ( ( exbufptr == bufsize ) ) 
	  {
	    bibfieldtoolongprint () ;
	    goto lab10 ;
	  } 
	  else {
	      
	    exbuf [exbufptr ]= buffer [bufptr2 ];
	    exbufptr = exbufptr + 1 ;
	  } 
	} 
	bufptr2 = bufptr2 + 1 ;
	{
	  if ( ( ( lexclass [buffer [bufptr2 ]]== 1 ) || ( bufptr2 == last 
	  ) ) ) {
	      
	    if ( ( ! compressbibwhite () ) ) 
	    goto lab10 ;
	  } 
	} 
      } 
      break ;
    } 
  } 
  else {
      
    while ( ( buffer [bufptr2 ]!= rightstrdelim ) ) if ( ( buffer [bufptr2 
    ]== 123 ) ) 
    {
      bibbracelevel = bibbracelevel + 1 ;
      bufptr2 = bufptr2 + 1 ;
      {
	if ( ( ! eatbibwhitespace () ) ) 
	{
	  eatbibprint () ;
	  goto lab10 ;
	} 
      } 
      while ( ( bibbracelevel > 0 ) ) {
	  
	if ( ( buffer [bufptr2 ]== 125 ) ) 
	{
	  bibbracelevel = bibbracelevel - 1 ;
	  bufptr2 = bufptr2 + 1 ;
	  {
	    if ( ( ! eatbibwhitespace () ) ) 
	    {
	      eatbibprint () ;
	      goto lab10 ;
	    } 
	  } 
	} 
	else if ( ( buffer [bufptr2 ]== 123 ) ) 
	{
	  bibbracelevel = bibbracelevel + 1 ;
	  bufptr2 = bufptr2 + 1 ;
	  {
	    if ( ( ! eatbibwhitespace () ) ) 
	    {
	      eatbibprint () ;
	      goto lab10 ;
	    } 
	  } 
	} 
	else {
	    
	  bufptr2 = bufptr2 + 1 ;
	  if ( ( ! scan2 ( 125 , 123 ) ) ) 
	  {
	    if ( ( ! eatbibwhitespace () ) ) 
	    {
	      eatbibprint () ;
	      goto lab10 ;
	    } 
	  } 
	} 
      } 
    } 
    else if ( ( buffer [bufptr2 ]== 125 ) ) 
    {
      bibunbalancedbracesprint () ;
      goto lab10 ;
    } 
    else {
	
      bufptr2 = bufptr2 + 1 ;
      if ( ( ! scan3 ( rightstrdelim , 123 , 125 ) ) ) 
      {
	if ( ( ! eatbibwhitespace () ) ) 
	{
	  eatbibprint () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  bufptr2 = bufptr2 + 1 ;
  Result = true ;
  lab10: ;
  return Result ;
} 
boolean 
scanafieldtokenandeatwhite ( void ) 
{
  /* 10 */ register boolean Result; Result = false ;
  switch ( ( buffer [bufptr2 ]) ) 
  {case 123 : 
    {
      rightstrdelim = 125 ;
      if ( ( ! scanbalancedbraces () ) ) 
      goto lab10 ;
    } 
    break ;
  case 34 : 
    {
      rightstrdelim = 34 ;
      if ( ( ! scanbalancedbraces () ) ) 
      goto lab10 ;
    } 
    break ;
  case 48 : 
  case 49 : 
  case 50 : 
  case 51 : 
  case 52 : 
  case 53 : 
  case 54 : 
  case 55 : 
  case 56 : 
  case 57 : 
    {
      if ( ( ! scannonneginteger () ) ) 
      {
	{
	  Fputs ( logfile ,  "A digit disappeared" ) ;
	  Fputs ( standardoutput ,  "A digit disappeared" ) ;
	} 
	printconfusion () ;
	longjmp(jmp9998,1) ;
      } 
      if ( ( storefield ) ) 
      {
	tmpptr = bufptr1 ;
	while ( ( tmpptr < bufptr2 ) ) {
	    
	  {
	    if ( ( exbufptr == bufsize ) ) 
	    {
	      bibfieldtoolongprint () ;
	      goto lab10 ;
	    } 
	    else {
		
	      exbuf [exbufptr ]= buffer [tmpptr ];
	      exbufptr = exbufptr + 1 ;
	    } 
	  } 
	  tmpptr = tmpptr + 1 ;
	} 
      } 
    } 
    break ;
    default: 
    {
      scanidentifier ( 44 , rightouterdelim , 35 ) ;
      {
	if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
	;
	else {
	    
	  bibidprint () ;
	  {
	    {
	      Fputs ( logfile ,  "a field part" ) ;
	      Fputs ( standardoutput ,  "a field part" ) ;
	    } 
	    biberrprint () ;
	    goto lab10 ;
	  } 
	} 
      } 
      if ( ( storefield ) ) 
      {
	lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
	macronameloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 
	13 , false ) ;
	storetoken = true ;
	if ( ( atbibcommand ) ) {
	    
	  if ( ( commandnum == 2 ) ) {
	      
	    if ( ( macronameloc == curmacroloc ) ) 
	    {
	      storetoken = false ;
	      {
		macrowarnprint () ;
		{
		  {
		    fprintf ( logfile , "%s\n",  "used in its own definition" ) ;
		    fprintf ( standardoutput , "%s\n",  "used in its own definition" ) 
		    ;
		  } 
		  bibwarnprint () ;
		} 
	      } 
	    } 
	  } 
	} 
	if ( ( ! hashfound ) ) 
	{
	  storetoken = false ;
	  {
	    macrowarnprint () ;
	    {
	      {
		fprintf ( logfile , "%s\n",  "undefined" ) ;
		fprintf ( standardoutput , "%s\n",  "undefined" ) ;
	      } 
	      bibwarnprint () ;
	    } 
	  } 
	} 
	if ( ( storetoken ) ) 
	{
	  tmpptr = strstart [ilkinfo [macronameloc ]];
	  tmpendptr = strstart [ilkinfo [macronameloc ]+ 1 ];
	  if ( ( exbufptr == 0 ) ) {
	      
	    if ( ( ( lexclass [strpool [tmpptr ]]== 1 ) && ( tmpptr < 
	    tmpendptr ) ) ) 
	    {
	      {
		if ( ( exbufptr == bufsize ) ) 
		{
		  bibfieldtoolongprint () ;
		  goto lab10 ;
		} 
		else {
		    
		  exbuf [exbufptr ]= 32 ;
		  exbufptr = exbufptr + 1 ;
		} 
	      } 
	      tmpptr = tmpptr + 1 ;
	      while ( ( ( lexclass [strpool [tmpptr ]]== 1 ) && ( tmpptr < 
	      tmpendptr ) ) ) tmpptr = tmpptr + 1 ;
	    } 
	  } 
	  while ( ( tmpptr < tmpendptr ) ) {
	      
	    if ( ( lexclass [strpool [tmpptr ]]!= 1 ) ) 
	    {
	      if ( ( exbufptr == bufsize ) ) 
	      {
		bibfieldtoolongprint () ;
		goto lab10 ;
	      } 
	      else {
		  
		exbuf [exbufptr ]= strpool [tmpptr ];
		exbufptr = exbufptr + 1 ;
	      } 
	    } 
	    else if ( ( exbuf [exbufptr - 1 ]!= 32 ) ) 
	    {
	      if ( ( exbufptr == bufsize ) ) 
	      {
		bibfieldtoolongprint () ;
		goto lab10 ;
	      } 
	      else {
		  
		exbuf [exbufptr ]= 32 ;
		exbufptr = exbufptr + 1 ;
	      } 
	    } 
	    tmpptr = tmpptr + 1 ;
	  } 
	} 
      } 
    } 
    break ;
  } 
  {
    if ( ( ! eatbibwhitespace () ) ) 
    {
      eatbibprint () ;
      goto lab10 ;
    } 
  } 
  Result = true ;
  lab10: ;
  return Result ;
} 
boolean 
scanandstorethefieldvalueandeatwhite ( void ) 
{
  /* 10 */ register boolean Result; Result = false ;
  exbufptr = 0 ;
  if ( ( ! scanafieldtokenandeatwhite () ) ) 
  goto lab10 ;
  while ( ( buffer [bufptr2 ]== 35 ) ) {
      
    bufptr2 = bufptr2 + 1 ;
    {
      if ( ( ! eatbibwhitespace () ) ) 
      {
	eatbibprint () ;
	goto lab10 ;
      } 
    } 
    if ( ( ! scanafieldtokenandeatwhite () ) ) 
    goto lab10 ;
  } 
  if ( ( storefield ) ) 
  {
    if ( ( ! atbibcommand ) ) {
	
      if ( ( exbufptr > 0 ) ) {
	  
	if ( ( exbuf [exbufptr - 1 ]== 32 ) ) 
	exbufptr = exbufptr - 1 ;
      } 
    } 
    if ( ( ( ! atbibcommand ) && ( exbuf [0 ]== 32 ) && ( exbufptr > 0 ) ) ) 
    exbufxptr = 1 ;
    else exbufxptr = 0 ;
    fieldvalloc = strlookup ( exbuf , exbufxptr , exbufptr - exbufxptr , 0 , 
    true ) ;
    fntype [fieldvalloc ]= 3 ;
	;
#ifdef TRACE
    {
      putc ( '"' ,  logfile );
    } 
    {
      outpoolstr ( logfile , hashtext [fieldvalloc ]) ;
    } 
    {
      fprintf ( logfile , "%s\n",  "\" is a field value" ) ;
    } 
#endif /* TRACE */
    if ( ( atbibcommand ) ) 
    {
      switch ( ( commandnum ) ) 
      {case 1 : 
	{
	  spreamble [preambleptr ]= hashtext [fieldvalloc ];
	  preambleptr = preambleptr + 1 ;
	} 
	break ;
      case 2 : 
	ilkinfo [curmacroloc ]= hashtext [fieldvalloc ];
	break ;
	default: 
	bibcmdconfusion () ;
	break ;
      } 
    } 
    else {
	
      fieldptr = entryciteptr * numfields + ilkinfo [fieldnameloc ];
      if ( ( fieldptr >= maxfields ) ) 
      {
	{
	  Fputs ( logfile ,  "field_info index is out of range" ) ;
	  Fputs ( standardoutput ,  "field_info index is out of range" ) ;
	} 
	printconfusion () ;
	longjmp(jmp9998,1) ;
      } 
      if ( ( fieldinfo [fieldptr ]!= 0 ) ) 
      {
	{
	  Fputs ( logfile ,  "Warning--I'm ignoring " ) ;
	  Fputs ( standardoutput ,  "Warning--I'm ignoring " ) ;
	} 
	printapoolstr ( citelist [entryciteptr ]) ;
	{
	  Fputs ( logfile ,  "'s extra \"" ) ;
	  Fputs ( standardoutput ,  "'s extra \"" ) ;
	} 
	printapoolstr ( hashtext [fieldnameloc ]) ;
	{
	  {
	    fprintf ( logfile , "%s\n",  "\" field" ) ;
	    fprintf ( standardoutput , "%s\n",  "\" field" ) ;
	  } 
	  bibwarnprint () ;
	} 
      } 
      else {
	  
	fieldinfo [fieldptr ]= hashtext [fieldvalloc ];
	if ( ( ( ilkinfo [fieldnameloc ]== crossrefnum ) && ( ! allentries ) 
	) ) 
	{
	  tmpptr = exbufxptr ;
	  while ( ( tmpptr < exbufptr ) ) {
	      
	    outbuf [tmpptr ]= exbuf [tmpptr ];
	    tmpptr = tmpptr + 1 ;
	  } 
	  lowercase ( outbuf , exbufxptr , exbufptr - exbufxptr ) ;
	  lcciteloc = strlookup ( outbuf , exbufxptr , exbufptr - exbufxptr , 
	  10 , true ) ;
	  if ( ( hashfound ) ) 
	  {
	    citeloc = ilkinfo [lcciteloc ];
	    if ( ( ilkinfo [citeloc ]>= oldnumcites ) ) 
	    citeinfo [ilkinfo [citeloc ]]= citeinfo [ilkinfo [citeloc ]
	    ]+ 1 ;
	  } 
	  else {
	      
	    citeloc = strlookup ( exbuf , exbufxptr , exbufptr - exbufxptr , 9 
	    , true ) ;
	    if ( ( hashfound ) ) 
	    hashciteconfusion () ;
	    adddatabasecite ( citeptr ) ;
	    citeinfo [ilkinfo [citeloc ]]= 1 ;
	  } 
	} 
      } 
    } 
  } 
  Result = true ;
  lab10: ;
  return Result ;
} 
void 
zdecrbracelevel ( strnumber poplitvar ) 
{
  if ( ( bracelevel == 0 ) ) 
  bracesunbalancedcomplaint ( poplitvar ) ;
  else bracelevel = bracelevel - 1 ;
} 
void 
zcheckbracelevel ( strnumber poplitvar ) 
{
  if ( ( bracelevel > 0 ) ) 
  bracesunbalancedcomplaint ( poplitvar ) ;
} 
void 
znamescanforand ( strnumber poplitvar ) 
{
  bracelevel = 0 ;
  precedingwhite = false ;
  andfound = false ;
  while ( ( ( ! andfound ) && ( exbufptr < exbuflength ) ) ) switch ( ( exbuf 
  [exbufptr ]) ) 
  {case 97 : 
  case 65 : 
    {
      exbufptr = exbufptr + 1 ;
      if ( ( precedingwhite ) ) 
      {
	if ( ( exbufptr <= ( exbuflength - 3 ) ) ) {
	    
	  if ( ( ( exbuf [exbufptr ]== 110 ) || ( exbuf [exbufptr ]== 78 ) 
	  ) ) {
	      
	    if ( ( ( exbuf [exbufptr + 1 ]== 100 ) || ( exbuf [exbufptr + 1 
	    ]== 68 ) ) ) {
		
	      if ( ( lexclass [exbuf [exbufptr + 2 ]]== 1 ) ) 
	      {
		exbufptr = exbufptr + 2 ;
		andfound = true ;
	      } 
	    } 
	  } 
	} 
      } 
      precedingwhite = false ;
    } 
    break ;
  case 161 : 
    if ( ( isinternalEUC () ) ) 
    {
      if ( ( ( fromBUFF ( exbuf , exbuflength , exbufptr ) == 41380L ) || ( 
      fromBUFF ( exbuf , exbuflength , exbufptr ) == 41378L ) ) ) 
      {
	precedingwhite = false ;
	andfound = true ;
      } 
      else if ( ( fromBUFF ( exbuf , exbuflength , exbufptr ) == 41377L ) ) 
      {
	exbuf [exbufptr ]= 32 ;
	exbuf [exbufptr + 1 ]= 32 ;
	precedingwhite = true ;
      } 
      exbufptr = exbufptr + 2 ;
    } 
    else {
	
      exbufptr = exbufptr + multibytelen ( exbuf [exbufptr ]) ;
      precedingwhite = false ;
    } 
    break ;
  case 227 : 
  case 239 : 
    if ( ( isinternalUPTEX () ) ) 
    {
      if ( ( ( fromBUFF ( exbuf , exbuflength , exbufptr ) == 65292L ) || ( 
      fromBUFF ( exbuf , exbuflength , exbufptr ) == 12289 ) ) ) 
      {
	precedingwhite = false ;
	andfound = true ;
      } 
      else if ( ( fromBUFF ( exbuf , exbuflength , exbufptr ) == 12288 ) ) 
      {
	exbuf [exbufptr ]= 32 ;
	exbuf [exbufptr + 1 ]= 32 ;
	exbuf [exbufptr + 2 ]= 32 ;
	precedingwhite = true ;
      } 
      exbufptr = exbufptr + 3 ;
    } 
    else {
	
      exbufptr = exbufptr + multibytelen ( exbuf [exbufptr ]) ;
      precedingwhite = false ;
    } 
    break ;
  case 123 : 
    {
      bracelevel = bracelevel + 1 ;
      exbufptr = exbufptr + 1 ;
      while ( ( ( bracelevel > 0 ) && ( exbufptr < exbuflength ) ) ) {
	  
	if ( ( exbuf [exbufptr ]== 125 ) ) 
	bracelevel = bracelevel - 1 ;
	else if ( ( exbuf [exbufptr ]== 123 ) ) 
	bracelevel = bracelevel + 1 ;
	exbufptr = exbufptr + 1 ;
      } 
      precedingwhite = false ;
    } 
    break ;
  case 125 : 
    {
      decrbracelevel ( poplitvar ) ;
      exbufptr = exbufptr + 1 ;
      precedingwhite = false ;
    } 
    break ;
    default: 
    if ( ( lexclass [exbuf [exbufptr ]]== 1 ) ) 
    {
      exbufptr = exbufptr + 1 ;
      precedingwhite = true ;
    } 
    else {
	
      exbufptr = exbufptr + multibytelen ( exbuf [exbufptr ]) ;
      precedingwhite = false ;
    } 
    break ;
  } 
  checkbracelevel ( poplitvar ) ;
} 
boolean 
vontokenfound ( void ) 
{
  /* 10 */ register boolean Result; nmbracelevel = 0 ;
  Result = false ;
  while ( ( namebfptr < namebfxptr ) ) if ( ( ( svbuffer [namebfptr ]>= 65 ) 
  && ( svbuffer [namebfptr ]<= 90 ) ) ) 
  goto lab10 ;
  else if ( ( ( svbuffer [namebfptr ]>= 97 ) && ( svbuffer [namebfptr ]<= 
  122 ) ) ) 
  {
    Result = true ;
    goto lab10 ;
  } 
  else if ( ( svbuffer [namebfptr ]== 123 ) ) 
  {
    nmbracelevel = nmbracelevel + 1 ;
    namebfptr = namebfptr + 1 ;
    if ( ( ( namebfptr + 2 < namebfxptr ) && ( svbuffer [namebfptr ]== 92 ) 
    ) ) 
    {
      namebfptr = namebfptr + 1 ;
      namebfyptr = namebfptr ;
      while ( ( ( namebfptr < namebfxptr ) && ( lexclass [svbuffer [
      namebfptr ]]== 2 ) ) ) namebfptr = namebfptr + 1 ;
      controlseqloc = strlookup ( svbuffer , namebfyptr , namebfptr - 
      namebfyptr , 14 , false ) ;
      if ( ( hashfound ) ) 
      {
	switch ( ( ilkinfo [controlseqloc ]) ) 
	{case 3 : 
	case 5 : 
	case 7 : 
	case 9 : 
	case 11 : 
	  goto lab10 ;
	  break ;
	case 0 : 
	case 1 : 
	case 2 : 
	case 4 : 
	case 6 : 
	case 8 : 
	case 10 : 
	case 12 : 
	  {
	    Result = true ;
	    goto lab10 ;
	  } 
	  break ;
	  default: 
	  {
	    {
	      Fputs ( logfile ,  "Control-sequence hash error" ) ;
	      Fputs ( standardoutput ,  "Control-sequence hash error" ) ;
	    } 
	    printconfusion () ;
	    longjmp(jmp9998,1) ;
	  } 
	  break ;
	} 
      } 
      while ( ( ( namebfptr < namebfxptr ) && ( nmbracelevel > 0 ) ) ) {
	  
	if ( ( ( svbuffer [namebfptr ]>= 65 ) && ( svbuffer [namebfptr ]<= 
	90 ) ) ) 
	goto lab10 ;
	else if ( ( ( svbuffer [namebfptr ]>= 97 ) && ( svbuffer [namebfptr 
	]<= 122 ) ) ) 
	{
	  Result = true ;
	  goto lab10 ;
	} 
	else if ( ( svbuffer [namebfptr ]== 125 ) ) 
	nmbracelevel = nmbracelevel - 1 ;
	else if ( ( svbuffer [namebfptr ]== 123 ) ) 
	nmbracelevel = nmbracelevel + 1 ;
	namebfptr = namebfptr + 1 ;
      } 
      goto lab10 ;
    } 
    else while ( ( ( nmbracelevel > 0 ) && ( namebfptr < namebfxptr ) ) ) {
	
      if ( ( svbuffer [namebfptr ]== 125 ) ) 
      nmbracelevel = nmbracelevel - 1 ;
      else if ( ( svbuffer [namebfptr ]== 123 ) ) 
      nmbracelevel = nmbracelevel + 1 ;
      namebfptr = namebfptr + 1 ;
    } 
  } 
  else namebfptr = namebfptr + 1 ;
  lab10: ;
  return Result ;
} 
void 
vonnameendsandlastnamestartsstuff ( void ) 
{
  /* 10 */ vonend = lastend - 1 ;
  while ( ( vonend > vonstart ) ) {
      
    namebfptr = nametok [vonend - 1 ];
    namebfxptr = nametok [vonend ];
    if ( ( vontokenfound () ) ) 
    goto lab10 ;
    vonend = vonend - 1 ;
  } 
  lab10: ;
} 
void 
skipstuffatspbracelevelgreaterthanone ( void ) 
{
  while ( ( ( spbracelevel > 1 ) && ( spptr < spend ) ) ) {
      
    if ( ( strpool [spptr ]== 125 ) ) 
    spbracelevel = spbracelevel - 1 ;
    else if ( ( strpool [spptr ]== 123 ) ) 
    spbracelevel = spbracelevel + 1 ;
    spptr = spptr + 1 ;
  } 
} 
void 
bracelvloneletterscomplaint ( void ) 
{
  {
    Fputs ( logfile ,  "The format string \"" ) ;
    Fputs ( standardoutput ,  "The format string \"" ) ;
  } 
  printapoolstr ( poplit1 ) ;
  {
    {
      Fputs ( logfile ,  "\" has an illegal brace-level-1 letter" ) ;
      Fputs ( standardoutput ,  "\" has an illegal brace-level-1 letter" ) ;
    } 
    bstexwarnprint () ;
  } 
} 
boolean 
zenoughtextchars ( bufpointer enoughchars ) 
{
  register boolean Result; numtextchars = 0 ;
  exbufyptr = exbufxptr ;
  while ( ( ( exbufyptr < exbufptr ) && ( numtextchars < enoughchars ) ) ) {
      
    exbufyptr = exbufyptr + 1 ;
    if ( ( exbuf [exbufyptr - 1 ]== 123 ) ) 
    {
      bracelevel = bracelevel + 1 ;
      if ( ( ( bracelevel == 1 ) && ( exbufyptr < exbufptr ) ) ) {
	  
	if ( ( exbuf [exbufyptr ]== 92 ) ) 
	{
	  exbufyptr = exbufyptr + 1 ;
	  while ( ( ( exbufyptr < exbufptr ) && ( bracelevel > 0 ) ) ) {
	      
	    if ( ( exbuf [exbufyptr ]== 125 ) ) 
	    bracelevel = bracelevel - 1 ;
	    else if ( ( exbuf [exbufyptr ]== 123 ) ) 
	    bracelevel = bracelevel + 1 ;
	    exbufyptr = exbufyptr + 1 ;
	  } 
	} 
      } 
    } 
    else if ( ( exbuf [exbufyptr - 1 ]== 125 ) ) 
    bracelevel = bracelevel - 1 ;
    numtextchars = numtextchars + 1 ;
  } 
  if ( ( numtextchars < enoughchars ) ) 
  Result = false ;
  else Result = true ;
  return Result ;
} 
void 
figureouttheformattedname ( void ) 
{
  /* 15 */ {
      
    exbufptr = 0 ;
    spbracelevel = 0 ;
    spptr = strstart [poplit1 ];
    spend = strstart [poplit1 + 1 ];
    while ( ( spptr < spend ) ) if ( ( strpool [spptr ]== 123 ) ) 
    {
      spbracelevel = spbracelevel + 1 ;
      spptr = spptr + 1 ;
      {
	spxptr1 = spptr ;
	alphafound = false ;
	doubleletter = false ;
	endofgroup = false ;
	tobewritten = true ;
	while ( ( ( ! endofgroup ) && ( spptr < spend ) ) ) if ( ( lexclass [
	strpool [spptr ]]== 2 ) ) 
	{
	  spptr = spptr + 1 ;
	  {
	    if ( ( alphafound ) ) 
	    {
	      bracelvloneletterscomplaint () ;
	      tobewritten = false ;
	    } 
	    else {
		
	      switch ( ( strpool [spptr - 1 ]) ) 
	      {case 102 : 
	      case 70 : 
		{
		  curtoken = firststart ;
		  lasttoken = firstend ;
		  if ( ( curtoken == lasttoken ) ) 
		  tobewritten = false ;
		  if ( ( ( strpool [spptr ]== 102 ) || ( strpool [spptr ]
		  == 70 ) ) ) 
		  doubleletter = true ;
		} 
		break ;
	      case 118 : 
	      case 86 : 
		{
		  curtoken = vonstart ;
		  lasttoken = vonend ;
		  if ( ( curtoken == lasttoken ) ) 
		  tobewritten = false ;
		  if ( ( ( strpool [spptr ]== 118 ) || ( strpool [spptr ]
		  == 86 ) ) ) 
		  doubleletter = true ;
		} 
		break ;
	      case 108 : 
	      case 76 : 
		{
		  curtoken = vonend ;
		  lasttoken = lastend ;
		  if ( ( curtoken == lasttoken ) ) 
		  tobewritten = false ;
		  if ( ( ( strpool [spptr ]== 108 ) || ( strpool [spptr ]
		  == 76 ) ) ) 
		  doubleletter = true ;
		} 
		break ;
	      case 106 : 
	      case 74 : 
		{
		  curtoken = lastend ;
		  lasttoken = jrend ;
		  if ( ( curtoken == lasttoken ) ) 
		  tobewritten = false ;
		  if ( ( ( strpool [spptr ]== 106 ) || ( strpool [spptr ]
		  == 74 ) ) ) 
		  doubleletter = true ;
		} 
		break ;
		default: 
		{
		  bracelvloneletterscomplaint () ;
		  tobewritten = false ;
		} 
		break ;
	      } 
	      if ( ( doubleletter ) ) 
	      spptr = spptr + 1 ;
	    } 
	    alphafound = true ;
	  } 
	} 
	else if ( ( strpool [spptr ]== 125 ) ) 
	{
	  spbracelevel = spbracelevel - 1 ;
	  spptr = spptr + 1 ;
	  endofgroup = true ;
	} 
	else if ( ( strpool [spptr ]== 123 ) ) 
	{
	  spbracelevel = spbracelevel + 1 ;
	  spptr = spptr + 1 ;
	  skipstuffatspbracelevelgreaterthanone () ;
	} 
	else spptr = spptr + 1 ;
	if ( ( ( endofgroup ) && ( tobewritten ) ) ) 
	{
	  exbufxptr = exbufptr ;
	  spptr = spxptr1 ;
	  spbracelevel = 1 ;
	  while ( ( spbracelevel > 0 ) ) if ( ( ( lexclass [strpool [spptr ]
	  ]== 2 ) && ( spbracelevel == 1 ) ) ) 
	  {
	    spptr = spptr + 1 ;
	    {
	      if ( ( doubleletter ) ) 
	      spptr = spptr + 1 ;
	      usedefault = true ;
	      spxptr2 = spptr ;
	      if ( ( strpool [spptr ]== 123 ) ) 
	      {
		usedefault = false ;
		spbracelevel = spbracelevel + 1 ;
		spptr = spptr + 1 ;
		spxptr1 = spptr ;
		skipstuffatspbracelevelgreaterthanone () ;
		spxptr2 = spptr - 1 ;
	      } 
	      while ( ( curtoken < lasttoken ) ) {
		  
		if ( ( doubleletter ) ) 
		{
		  namebfptr = nametok [curtoken ];
		  namebfxptr = nametok [curtoken + 1 ];
		  if ( ( exbuflength + ( namebfxptr - namebfptr ) > bufsize ) 
		  ) 
		  bufferoverflow () ;
		  while ( ( namebfptr < namebfxptr ) ) {
		      
		    {
		      exbuf [exbufptr ]= svbuffer [namebfptr ];
		      exbufptr = exbufptr + 1 ;
		    } 
		    namebfptr = namebfptr + 1 ;
		  } 
		} 
		else {
		    
		  namebfptr = nametok [curtoken ];
		  namebfxptr = nametok [curtoken + 1 ];
		  while ( ( namebfptr < namebfxptr ) ) {
		      
		    if ( ( lexclass [svbuffer [namebfptr ]]== 2 ) ) 
		    {
		      {
			if ( ( exbufptr == bufsize ) ) 
			bufferoverflow () ;
			{
			  exbuf [exbufptr ]= svbuffer [namebfptr ];
			  exbufptr = exbufptr + 1 ;
			} 
		      } 
		      if ( multibytelen ( svbuffer [namebfptr ]) > 1 ) 
		      {
			if ( ( exbufptr == bufsize ) ) 
			bufferoverflow () ;
			{
			  exbuf [exbufptr ]= svbuffer [namebfptr + 1 ];
			  exbufptr = exbufptr + 1 ;
			} 
		      } 
		      if ( multibytelen ( svbuffer [namebfptr ]) > 2 ) 
		      {
			if ( ( exbufptr == bufsize ) ) 
			bufferoverflow () ;
			{
			  exbuf [exbufptr ]= svbuffer [namebfptr + 2 ];
			  exbufptr = exbufptr + 1 ;
			} 
		      } 
		      if ( multibytelen ( svbuffer [namebfptr ]) > 3 ) 
		      {
			if ( ( exbufptr == bufsize ) ) 
			bufferoverflow () ;
			{
			  exbuf [exbufptr ]= svbuffer [namebfptr + 3 ];
			  exbufptr = exbufptr + 1 ;
			} 
		      } 
		      namebfptr = namebfptr + multibytelen ( svbuffer [
		      namebfptr ]) - 1 ;
		      goto lab15 ;
		    } 
		    else if ( ( ( svbuffer [namebfptr ]== 123 ) && ( 
		    namebfptr + 1 < namebfxptr ) ) ) {
			
		      if ( ( svbuffer [namebfptr + 1 ]== 92 ) ) 
		      {
			if ( ( exbufptr + 2 > bufsize ) ) 
			bufferoverflow () ;
			{
			  exbuf [exbufptr ]= 123 ;
			  exbufptr = exbufptr + 1 ;
			} 
			{
			  exbuf [exbufptr ]= 92 ;
			  exbufptr = exbufptr + 1 ;
			} 
			namebfptr = namebfptr + 2 ;
			nmbracelevel = 1 ;
			while ( ( ( namebfptr < namebfxptr ) && ( nmbracelevel 
			> 0 ) ) ) {
			    
			  if ( ( svbuffer [namebfptr ]== 125 ) ) 
			  nmbracelevel = nmbracelevel - 1 ;
			  else if ( ( svbuffer [namebfptr ]== 123 ) ) 
			  nmbracelevel = nmbracelevel + 1 ;
			  {
			    if ( ( exbufptr == bufsize ) ) 
			    bufferoverflow () ;
			    {
			      exbuf [exbufptr ]= svbuffer [namebfptr ];
			      exbufptr = exbufptr + 1 ;
			    } 
			  } 
			  namebfptr = namebfptr + 1 ;
			} 
			goto lab15 ;
		      } 
		    } 
		    namebfptr = namebfptr + 1 ;
		  } 
		  lab15: ;
		} 
		curtoken = curtoken + 1 ;
		if ( ( curtoken < lasttoken ) ) 
		{
		  if ( ( usedefault ) ) 
		  {
		    if ( ( ! doubleletter ) ) 
		    {
		      if ( ( exbufptr == bufsize ) ) 
		      bufferoverflow () ;
		      {
			exbuf [exbufptr ]= 46 ;
			exbufptr = exbufptr + 1 ;
		      } 
		    } 
		    if ( ( lexclass [namesepchar [curtoken ]]== 4 ) ) 
		    {
		      if ( ( exbufptr == bufsize ) ) 
		      bufferoverflow () ;
		      {
			exbuf [exbufptr ]= namesepchar [curtoken ];
			exbufptr = exbufptr + 1 ;
		      } 
		    } 
		    else if ( ( ( curtoken == lasttoken - 1 ) || ( ! 
		    enoughtextchars ( 3 ) ) ) ) 
		    {
		      if ( ( exbufptr == bufsize ) ) 
		      bufferoverflow () ;
		      {
			exbuf [exbufptr ]= 126 ;
			exbufptr = exbufptr + 1 ;
		      } 
		    } 
		    else {
			
		      if ( ( exbufptr == bufsize ) ) 
		      bufferoverflow () ;
		      {
			exbuf [exbufptr ]= 32 ;
			exbufptr = exbufptr + 1 ;
		      } 
		    } 
		  } 
		  else {
		      
		    if ( ( exbuflength + ( spxptr2 - spxptr1 ) > bufsize ) ) 
		    bufferoverflow () ;
		    spptr = spxptr1 ;
		    while ( ( spptr < spxptr2 ) ) {
			
		      {
			exbuf [exbufptr ]= strpool [spptr ];
			exbufptr = exbufptr + 1 ;
		      } 
		      spptr = spptr + 1 ;
		    } 
		  } 
		} 
	      } 
	      if ( ( ! usedefault ) ) 
	      spptr = spxptr2 + 1 ;
	    } 
	  } 
	  else if ( ( strpool [spptr ]== 125 ) ) 
	  {
	    spbracelevel = spbracelevel - 1 ;
	    spptr = spptr + 1 ;
	    if ( ( spbracelevel > 0 ) ) 
	    {
	      if ( ( exbufptr == bufsize ) ) 
	      bufferoverflow () ;
	      {
		exbuf [exbufptr ]= 125 ;
		exbufptr = exbufptr + 1 ;
	      } 
	    } 
	  } 
	  else if ( ( strpool [spptr ]== 123 ) ) 
	  {
	    spbracelevel = spbracelevel + 1 ;
	    spptr = spptr + 1 ;
	    {
	      if ( ( exbufptr == bufsize ) ) 
	      bufferoverflow () ;
	      {
		exbuf [exbufptr ]= 123 ;
		exbufptr = exbufptr + 1 ;
	      } 
	    } 
	  } 
	  else {
	      
	    {
	      if ( ( exbufptr == bufsize ) ) 
	      bufferoverflow () ;
	      {
		exbuf [exbufptr ]= strpool [spptr ];
		exbufptr = exbufptr + 1 ;
	      } 
	    } 
	    spptr = spptr + 1 ;
	  } 
	  if ( ( exbufptr > 0 ) ) {
	      
	    if ( ( exbuf [exbufptr - 1 ]== 126 ) ) 
	    {
	      exbufptr = exbufptr - 1 ;
	      if ( ( exbuf [exbufptr - 1 ]== 126 ) ) 
	      ;
	      else if ( ( ! enoughtextchars ( 3 ) ) ) 
	      exbufptr = exbufptr + 1 ;
	      else {
		  
		exbuf [exbufptr ]= 32 ;
		exbufptr = exbufptr + 1 ;
	      } 
	    } 
	  } 
	} 
      } 
    } 
    else if ( ( strpool [spptr ]== 125 ) ) 
    {
      bracesunbalancedcomplaint ( poplit1 ) ;
      spptr = spptr + 1 ;
    } 
    else {
	
      {
	if ( ( exbufptr == bufsize ) ) 
	bufferoverflow () ;
	{
	  exbuf [exbufptr ]= strpool [spptr ];
	  exbufptr = exbufptr + 1 ;
	} 
      } 
      spptr = spptr + 1 ;
    } 
    if ( ( spbracelevel > 0 ) ) 
    bracesunbalancedcomplaint ( poplit1 ) ;
    exbuflength = exbufptr ;
  } 
} 
void 
zpushlitstk ( integer pushlt , stktype pushtype ) 
{
  
#ifdef TRACE
  litstkloc dumptr  ;
#endif /* TRACE */
  litstack [litstkptr ]= pushlt ;
  litstktype [litstkptr ]= pushtype ;
	;
#ifdef TRACE
  {register integer for_end; dumptr = 0 ;for_end = litstkptr ; if ( dumptr 
  <= for_end) do 
    {
      Fputs ( logfile ,  "  " ) ;
    } 
  while ( dumptr++ < for_end ) ;} 
  {
    Fputs ( logfile ,  "Pushing " ) ;
  } 
  switch ( ( litstktype [litstkptr ]) ) 
  {case 0 : 
    {
      fprintf ( logfile , "%ld\n",  (long)litstack [litstkptr ]) ;
    } 
    break ;
  case 1 : 
    {
      {
	putc ( '"' ,  logfile );
      } 
      {
	outpoolstr ( logfile , litstack [litstkptr ]) ;
      } 
      {
	{ putc ( '"' ,  logfile );  putc ( '\n',  logfile ); }
      } 
    } 
    break ;
  case 2 : 
    {
      {
	putc ( '`' ,  logfile );
      } 
      {
	outpoolstr ( logfile , hashtext [litstack [litstkptr ]]) ;
      } 
      {
	{ putc ( '\'' ,  logfile );  putc ( '\n',  logfile ); }
      } 
    } 
    break ;
  case 3 : 
    {
      {
	Fputs ( logfile ,  "missing field `" ) ;
      } 
      {
	outpoolstr ( logfile , litstack [litstkptr ]) ;
      } 
      {
	{ putc ( '\'' ,  logfile );  putc ( '\n',  logfile ); }
      } 
    } 
    break ;
  case 4 : 
    {
      fprintf ( logfile , "%s\n",  "a bad literal--popped from an empty stack" ) ;
    } 
    break ;
    default: 
    unknwnliteralconfusion () ;
    break ;
  } 
#endif /* TRACE */
  if ( ( litstkptr == litstksize ) ) 
  {
    BIBXRETALLOCNOSET ( "lit_stack" , litstack , integer , litstksize , 
    litstksize + LITSTKSIZE ) ;
    BIBXRETALLOC ( "lit_stk_type" , litstktype , stktype , litstksize , 
    litstksize + LITSTKSIZE ) ;
  } 
  litstkptr = litstkptr + 1 ;
} 
void 
zzpoplitstk ( integer * poplit , stktype * poptype ) 
{
  if ( ( litstkptr == 0 ) ) 
  {
    {
      {
	Fputs ( logfile ,  "You can't pop an empty literal stack" ) ;
	Fputs ( standardoutput ,  "You can't pop an empty literal stack" ) ;
      } 
      bstexwarnprint () ;
    } 
*    poptype = 4 ;
  } 
  else {
      
    litstkptr = litstkptr - 1 ;
*    poplit = litstack [litstkptr ];
*    poptype = litstktype [litstkptr ];
    if ( ( *poptype == 1 ) ) {
	
      if ( ( *poplit >= cmdstrptr ) ) 
      {
	if ( ( *poplit != strptr - 1 ) ) 
	{
	  {
	    Fputs ( logfile ,  "Nontop top of string stack" ) ;
	    Fputs ( standardoutput ,  "Nontop top of string stack" ) ;
	  } 
	  printconfusion () ;
	  longjmp(jmp9998,1) ;
	} 
	{
	  strptr = strptr - 1 ;
	  poolptr = strstart [strptr ];
	} 
      } 
    } 
  } 
} 
void 
zprintwrongstklit ( integer stklt , stktype stktp1 , stktype stktp2 ) 
{
  if ( ( stktp1 != 4 ) ) 
  {
    printstklit ( stklt , stktp1 ) ;
    switch ( ( stktp2 ) ) 
    {case 0 : 
      {
	Fputs ( logfile ,  ", not an integer," ) ;
	Fputs ( standardoutput ,  ", not an integer," ) ;
      } 
      break ;
    case 1 : 
      {
	Fputs ( logfile ,  ", not a string," ) ;
	Fputs ( standardoutput ,  ", not a string," ) ;
      } 
      break ;
    case 2 : 
      {
	Fputs ( logfile ,  ", not a function," ) ;
	Fputs ( standardoutput ,  ", not a function," ) ;
      } 
      break ;
    case 3 : 
    case 4 : 
      illeglliteralconfusion () ;
      break ;
      default: 
      unknwnliteralconfusion () ;
      break ;
    } 
    bstexwarnprint () ;
  } 
} 
void 
poptopandprint ( void ) 
{
  integer stklt  ;
  stktype stktp  ;
  poplitstk ( stklt , stktp ) ;
  if ( ( stktp == 4 ) ) 
  {
    fprintf ( logfile , "%s\n",  "Empty literal" ) ;
    fprintf ( standardoutput , "%s\n",  "Empty literal" ) ;
  } 
  else printlit ( stklt , stktp ) ;
} 
void 
popwholestack ( void ) 
{
  while ( ( litstkptr > 0 ) ) poptopandprint () ;
} 
void 
initcommandexecution ( void ) 
{
  litstkptr = 0 ;
  cmdstrptr = strptr ;
} 
void 
checkcommandexecution ( void ) 
{
  if ( ( litstkptr != 0 ) ) 
  {
    {
      fprintf ( logfile , "%s%ld%s\n",  "ptr=" , (long)litstkptr , ", stack=" ) ;
      fprintf ( standardoutput , "%s%ld%s\n",  "ptr=" , (long)litstkptr , ", stack=" ) ;
    } 
    popwholestack () ;
    {
      {
	Fputs ( logfile ,  "---the literal stack isn't empty" ) ;
	Fputs ( standardoutput ,  "---the literal stack isn't empty" ) ;
      } 
      bstexwarnprint () ;
    } 
  } 
  if ( ( cmdstrptr != strptr ) ) 
  {
	;
#ifdef TRACE
    {
      fprintf ( logfile , "%s%ld%s%ld\n",  "Pointer is " , (long)strptr , " but should be " ,       (long)cmdstrptr ) ;
      fprintf ( standardoutput , "%s%ld%s%ld\n",  "Pointer is " , (long)strptr , " but should be " ,       (long)cmdstrptr ) ;
    } 
#endif /* TRACE */
    {
      {
	Fputs ( logfile ,  "Nonempty empty string stack" ) ;
	Fputs ( standardoutput ,  "Nonempty empty string stack" ) ;
      } 
      printconfusion () ;
      longjmp(jmp9998,1) ;
    } 
  } 
} 
void 
addpoolbufandpush ( void ) 
{
  {
    while ( ( poolptr + exbuflength > poolsize ) ) pooloverflow () ;
  } 
  exbufptr = 0 ;
  while ( ( exbufptr < exbuflength ) ) {
      
    {
      strpool [poolptr ]= exbuf [exbufptr ];
      poolptr = poolptr + 1 ;
    } 
    exbufptr = exbufptr + 1 ;
  } 
  pushlitstk ( makestring () , 1 ) ;
} 
void 
zaddbufpool ( strnumber pstr ) 
{
  pptr1 = strstart [pstr ];
  pptr2 = strstart [pstr + 1 ];
  if ( ( exbuflength + ( pptr2 - pptr1 ) > bufsize ) ) 
  bufferoverflow () ;
  exbufptr = exbuflength ;
  while ( ( pptr1 < pptr2 ) ) {
      
    {
      exbuf [exbufptr ]= strpool [pptr1 ];
      exbufptr = exbufptr + 1 ;
    } 
    pptr1 = pptr1 + 1 ;
  } 
  exbuflength = exbufptr ;
} 
void 
zaddoutpool ( strnumber pstr ) 
{
  /* 16 17 */ bufpointer breakptr  ;
  bufpointer endptr  ;
  boolean breakptfound  ;
  boolean unbreakabletail  ;
  pptr1 = strstart [pstr ];
  pptr2 = strstart [pstr + 1 ];
  while ( ( outbuflength + ( pptr2 - pptr1 ) > bufsize ) ) bufferoverflow () ;
  outbufptr = outbuflength ;
  while ( ( pptr1 < pptr2 ) ) {
      
    outbuf [outbufptr ]= strpool [pptr1 ];
    pptr1 = pptr1 + 1 ;
    outbufptr = outbufptr + 1 ;
  } 
  outbuflength = outbufptr ;
  unbreakabletail = false ;
  while ( ( ( outbuflength > maxprintline ) && ( ! unbreakabletail ) ) ) {
      
    endptr = outbuflength ;
    outbufptr = maxprintline ;
    breakptfound = false ;
    while ( ( ( lexclass [outbuf [outbufptr ]]!= 1 ) && ( outbufptr >= 
    minprintline ) ) ) outbufptr = outbufptr - 1 ;
    if ( ( outbufptr == minprintline - 1 ) ) 
    {
      outbufptr = maxprintline + 1 ;
      while ( ( outbufptr < endptr ) ) if ( ( lexclass [outbuf [outbufptr ]
      ]!= 1 ) ) 
      outbufptr = outbufptr + 1 ;
      else goto lab16 ;
      lab16: if ( ( outbufptr == endptr ) ) 
      unbreakabletail = true ;
      else {
	  
	breakptfound = true ;
	while ( ( outbufptr + 1 < endptr ) ) if ( ( lexclass [outbuf [
	outbufptr + 1 ]]== 1 ) ) 
	outbufptr = outbufptr + 1 ;
	else goto lab17 ;
	lab17: ;
      } 
    } 
    else breakptfound = true ;
    if ( ( breakptfound ) ) 
    {
      outbuflength = outbufptr ;
      breakptr = outbuflength + 1 ;
      outputbblline () ;
      outbuf [0 ]= 32 ;
      outbuf [1 ]= 32 ;
      outbufptr = 2 ;
      tmpptr = breakptr ;
      while ( ( tmpptr < endptr ) ) {
	  
	outbuf [outbufptr ]= outbuf [tmpptr ];
	outbufptr = outbufptr + 1 ;
	tmpptr = tmpptr + 1 ;
      } 
      outbuflength = endptr - breakptr + 2 ;
    } 
  } 
} 
void 
xequals ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  if ( ( poptyp1 != poptyp2 ) ) 
  {
    if ( ( ( poptyp1 != 4 ) && ( poptyp2 != 4 ) ) ) 
    {
      printstklit ( poplit1 , poptyp1 ) ;
      {
	Fputs ( logfile ,  ", " ) ;
	Fputs ( standardoutput ,  ", " ) ;
      } 
      printstklit ( poplit2 , poptyp2 ) ;
      printanewline () ;
      {
	{
	  Fputs ( logfile ,  "---they aren't the same literal types" ) ;
	  Fputs ( standardoutput ,  "---they aren't the same literal types" ) ;
	} 
	bstexwarnprint () ;
      } 
    } 
    pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( ( poptyp1 != 0 ) && ( poptyp1 != 1 ) ) ) 
  {
    if ( ( poptyp1 != 4 ) ) 
    {
      printstklit ( poplit1 , poptyp1 ) ;
      {
	{
	  Fputs ( logfile ,  ", not an integer or a string," ) ;
	  Fputs ( standardoutput ,  ", not an integer or a string," ) ;
	} 
	bstexwarnprint () ;
      } 
    } 
    pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( poptyp1 == 0 ) ) {
      
    if ( ( poplit2 == poplit1 ) ) 
    pushlitstk ( 1 , 0 ) ;
    else pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( streqstr ( poplit2 , poplit1 ) ) ) 
  pushlitstk ( 1 , 0 ) ;
  else pushlitstk ( 0 , 0 ) ;
} 
void 
xgreaterthan ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  if ( ( poptyp1 != 0 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 0 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( poptyp2 != 0 ) ) 
  {
    printwrongstklit ( poplit2 , poptyp2 , 0 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( poplit2 > poplit1 ) ) 
  pushlitstk ( 1 , 0 ) ;
  else pushlitstk ( 0 , 0 ) ;
} 
void 
xlessthan ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  if ( ( poptyp1 != 0 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 0 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( poptyp2 != 0 ) ) 
  {
    printwrongstklit ( poplit2 , poptyp2 , 0 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( poplit2 < poplit1 ) ) 
  pushlitstk ( 1 , 0 ) ;
  else pushlitstk ( 0 , 0 ) ;
} 
void 
xplus ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  if ( ( poptyp1 != 0 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 0 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( poptyp2 != 0 ) ) 
  {
    printwrongstklit ( poplit2 , poptyp2 , 0 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else pushlitstk ( poplit2 + poplit1 , 0 ) ;
} 
void 
xminus ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  if ( ( poptyp1 != 0 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 0 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( poptyp2 != 0 ) ) 
  {
    printwrongstklit ( poplit2 , poptyp2 , 0 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else pushlitstk ( poplit2 - poplit1 , 0 ) ;
} 
void 
xconcatenate ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  if ( ( poptyp1 != 1 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else if ( ( poptyp2 != 1 ) ) 
  {
    printwrongstklit ( poplit2 , poptyp2 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else {
      
    if ( ( poplit2 >= cmdstrptr ) ) {
	
      if ( ( poplit1 >= cmdstrptr ) ) 
      {
	strstart [poplit1 ]= strstart [poplit1 + 1 ];
	{
	  strptr = strptr + 1 ;
	  poolptr = strstart [strptr ];
	} 
	litstkptr = litstkptr + 1 ;
      } 
      else if ( ( ( strstart [poplit2 + 1 ]- strstart [poplit2 ]) == 0 ) ) 
      pushlitstk ( poplit1 , 1 ) ;
      else {
	  
	poolptr = strstart [poplit2 + 1 ];
	{
	  while ( ( poolptr + ( strstart [poplit1 + 1 ]- strstart [poplit1 
	  ]) > poolsize ) ) pooloverflow () ;
	} 
	spptr = strstart [poplit1 ];
	spend = strstart [poplit1 + 1 ];
	while ( ( spptr < spend ) ) {
	    
	  {
	    strpool [poolptr ]= strpool [spptr ];
	    poolptr = poolptr + 1 ;
	  } 
	  spptr = spptr + 1 ;
	} 
	pushlitstk ( makestring () , 1 ) ;
      } 
    } 
    else {
	
      if ( ( poplit1 >= cmdstrptr ) ) {
	  
	if ( ( ( strstart [poplit2 + 1 ]- strstart [poplit2 ]) == 0 ) ) 
	{
	  {
	    strptr = strptr + 1 ;
	    poolptr = strstart [strptr ];
	  } 
	  litstack [litstkptr ]= poplit1 ;
	  litstkptr = litstkptr + 1 ;
	} 
	else if ( ( ( strstart [poplit1 + 1 ]- strstart [poplit1 ]) == 0 ) 
	) 
	litstkptr = litstkptr + 1 ;
	else {
	    
	  splength = ( strstart [poplit1 + 1 ]- strstart [poplit1 ]) ;
	  sp2length = ( strstart [poplit2 + 1 ]- strstart [poplit2 ]) ;
	  {
	    while ( ( poolptr + splength + sp2length > poolsize ) ) 
	    pooloverflow () ;
	  } 
	  spptr = strstart [poplit1 + 1 ];
	  spend = strstart [poplit1 ];
	  spxptr1 = spptr + sp2length ;
	  while ( ( spptr > spend ) ) {
	      
	    spptr = spptr - 1 ;
	    spxptr1 = spxptr1 - 1 ;
	    strpool [spxptr1 ]= strpool [spptr ];
	  } 
	  spptr = strstart [poplit2 ];
	  spend = strstart [poplit2 + 1 ];
	  while ( ( spptr < spend ) ) {
	      
	    {
	      strpool [poolptr ]= strpool [spptr ];
	      poolptr = poolptr + 1 ;
	    } 
	    spptr = spptr + 1 ;
	  } 
	  poolptr = poolptr + splength ;
	  pushlitstk ( makestring () , 1 ) ;
	} 
      } 
      else {
	  
	if ( ( ( strstart [poplit1 + 1 ]- strstart [poplit1 ]) == 0 ) ) 
	litstkptr = litstkptr + 1 ;
	else if ( ( ( strstart [poplit2 + 1 ]- strstart [poplit2 ]) == 0 ) 
	) 
	pushlitstk ( poplit1 , 1 ) ;
	else {
	    
	  {
	    while ( ( poolptr + ( strstart [poplit1 + 1 ]- strstart [
	    poplit1 ]) + ( strstart [poplit2 + 1 ]- strstart [poplit2 ]) 
	    > poolsize ) ) pooloverflow () ;
	  } 
	  spptr = strstart [poplit2 ];
	  spend = strstart [poplit2 + 1 ];
	  while ( ( spptr < spend ) ) {
	      
	    {
	      strpool [poolptr ]= strpool [spptr ];
	      poolptr = poolptr + 1 ;
	    } 
	    spptr = spptr + 1 ;
	  } 
	  spptr = strstart [poplit1 ];
	  spend = strstart [poplit1 + 1 ];
	  while ( ( spptr < spend ) ) {
	      
	    {
	      strpool [poolptr ]= strpool [spptr ];
	      poolptr = poolptr + 1 ;
	    } 
	    spptr = spptr + 1 ;
	  } 
	  pushlitstk ( makestring () , 1 ) ;
	} 
      } 
    } 
  } 
} 
void 
xgets ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  if ( ( poptyp1 != 2 ) ) 
  printwrongstklit ( poplit1 , poptyp1 , 2 ) ;
  else if ( ( ( ! messwithentries ) && ( ( fntype [poplit1 ]== 6 ) || ( 
  fntype [poplit1 ]== 5 ) ) ) ) 
  bstcantmesswithentriesprint () ;
  else switch ( ( fntype [poplit1 ]) ) 
  {case 5 : 
    if ( ( poptyp2 != 0 ) ) 
    printwrongstklit ( poplit2 , poptyp2 , 0 ) ;
    else entryints [citeptr * numentints + ilkinfo [poplit1 ]]= poplit2 ;
    break ;
  case 6 : 
    {
      if ( ( poptyp2 != 1 ) ) 
      printwrongstklit ( poplit2 , poptyp2 , 1 ) ;
      else {
	  
	strentptr = citeptr * numentstrs + ilkinfo [poplit1 ];
	entchrptr = 0 ;
	spptr = strstart [poplit2 ];
	spxptr1 = strstart [poplit2 + 1 ];
	if ( ( spxptr1 - spptr > entstrsize ) ) 
	{
	  {
	    bst1printstringsizeexceeded () ;
	    {
	      fprintf ( logfile , "%ld%s",  (long)entstrsize , ", the entry" ) ;
	      fprintf ( standardoutput , "%ld%s",  (long)entstrsize , ", the entry" ) ;
	    } 
	    bst2printstringsizeexceeded () ;
	  } 
	  spxptr1 = spptr + entstrsize ;
	} 
	while ( ( spptr < spxptr1 ) ) {
	    
	  entrystrs [( strentptr ) * ( entstrsize + 1 ) + ( entchrptr ) ]= 
	  strpool [spptr ];
	  entchrptr = entchrptr + 1 ;
	  spptr = spptr + 1 ;
	} 
	entrystrs [( strentptr ) * ( entstrsize + 1 ) + ( entchrptr ) ]= 127 
	;
      } 
    } 
    break ;
  case 7 : 
    if ( ( poptyp2 != 0 ) ) 
    printwrongstklit ( poplit2 , poptyp2 , 0 ) ;
    else ilkinfo [poplit1 ]= poplit2 ;
    break ;
  case 8 : 
    {
      if ( ( poptyp2 != 1 ) ) 
      printwrongstklit ( poplit2 , poptyp2 , 1 ) ;
      else {
	  
	strglbptr = ilkinfo [poplit1 ];
	if ( ( poplit2 < cmdstrptr ) ) 
	glbstrptr [strglbptr ]= poplit2 ;
	else {
	    
	  glbstrptr [strglbptr ]= 0 ;
	  globchrptr = 0 ;
	  spptr = strstart [poplit2 ];
	  spend = strstart [poplit2 + 1 ];
	  if ( ( spend - spptr > globstrsize ) ) 
	  {
	    {
	      bst1printstringsizeexceeded () ;
	      {
		fprintf ( logfile , "%ld%s",  (long)globstrsize , ", the global" ) ;
		fprintf ( standardoutput , "%ld%s",  (long)globstrsize , ", the global" ) ;
	      } 
	      bst2printstringsizeexceeded () ;
	    } 
	    spend = spptr + globstrsize ;
	  } 
	  while ( ( spptr < spend ) ) {
	      
	    globalstrs [( strglbptr ) * ( globstrsize + 1 ) + ( globchrptr ) 
	    ]= strpool [spptr ];
	    globchrptr = globchrptr + 1 ;
	    spptr = spptr + 1 ;
	  } 
	  glbstrend [strglbptr ]= globchrptr ;
	} 
      } 
    } 
    break ;
    default: 
    {
      {
	Fputs ( logfile ,  "You can't assign to type " ) ;
	Fputs ( standardoutput ,  "You can't assign to type " ) ;
      } 
      printfnclass ( poplit1 ) ;
      {
	{
	  Fputs ( logfile ,  ", a nonvariable function class" ) ;
	  Fputs ( standardoutput ,  ", a nonvariable function class" ) ;
	} 
	bstexwarnprint () ;
      } 
    } 
    break ;
  } 
} 
void 
xaddperiod ( void ) 
{
  /* 15 */ poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 1 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else if ( ( ( strstart [poplit1 + 1 ]- strstart [poplit1 ]) == 0 ) ) 
  pushlitstk ( snull , 1 ) ;
  else {
      
    spptr = strstart [poplit1 + 1 ];
    spend = strstart [poplit1 ];
    while ( ( spptr > spend ) ) {
	
      spptr = spptr - 1 ;
      if ( ( strpool [spptr ]!= 125 ) ) 
      goto lab15 ;
    } 
    lab15: switch ( ( strpool [spptr ]) ) 
    {case 46 : 
    case 63 : 
    case 33 : 
      {
	if ( ( litstack [litstkptr ]>= cmdstrptr ) ) 
	{
	  strptr = strptr + 1 ;
	  poolptr = strstart [strptr ];
	} 
	litstkptr = litstkptr + 1 ;
      } 
      break ;
      default: 
      {
	if ( ( isinternalEUC () ) ) 
	{
	  switch ( ( fromBUFF ( strpool , spptr + 1 , spptr - 1 ) ) ) 
	  {case 41379 : 
	  case 41381 : 
	  case 41385 : 
	  case 41386 : 
	    if ( ( strpool [spptr - 2 ]!= 143 ) ) 
	    {
	      if ( ( litstack [litstkptr ]>= cmdstrptr ) ) 
	      {
		strptr = strptr + 1 ;
		poolptr = strstart [strptr ];
	      } 
	      litstkptr = litstkptr + 1 ;
	    } 
	    else {
		
	      if ( ( poplit1 < cmdstrptr ) ) 
	      {
		{
		  while ( ( poolptr + ( strstart [poplit1 + 1 ]- strstart [
		  poplit1 ]) + 1 > poolsize ) ) pooloverflow () ;
		} 
		spptr = strstart [poplit1 ];
		spend = strstart [poplit1 + 1 ];
		while ( ( spptr < spend ) ) {
		    
		  {
		    strpool [poolptr ]= strpool [spptr ];
		    poolptr = poolptr + 1 ;
		  } 
		  spptr = spptr + 1 ;
		} 
	      } 
	      else {
		  
		poolptr = strstart [poplit1 + 1 ];
		{
		  while ( ( poolptr + 1 > poolsize ) ) pooloverflow () ;
		} 
	      } 
	      {
		strpool [poolptr ]= 46 ;
		poolptr = poolptr + 1 ;
	      } 
	      pushlitstk ( makestring () , 1 ) ;
	    } 
	    break ;
	    default: 
	    {
	      if ( ( poplit1 < cmdstrptr ) ) 
	      {
		{
		  while ( ( poolptr + ( strstart [poplit1 + 1 ]- strstart [
		  poplit1 ]) + 1 > poolsize ) ) pooloverflow () ;
		} 
		spptr = strstart [poplit1 ];
		spend = strstart [poplit1 + 1 ];
		while ( ( spptr < spend ) ) {
		    
		  {
		    strpool [poolptr ]= strpool [spptr ];
		    poolptr = poolptr + 1 ;
		  } 
		  spptr = spptr + 1 ;
		} 
	      } 
	      else {
		  
		poolptr = strstart [poplit1 + 1 ];
		{
		  while ( ( poolptr + 1 > poolsize ) ) pooloverflow () ;
		} 
	      } 
	      {
		strpool [poolptr ]= 46 ;
		poolptr = poolptr + 1 ;
	      } 
	      pushlitstk ( makestring () , 1 ) ;
	    } 
	    break ;
	  } 
	} 
	if ( ( isinternalUPTEX () ) ) 
	{
	  switch ( ( fromBUFF ( strpool , spptr + 1 , spptr - 2 ) ) ) 
	  {case 12290 : 
	  case 65294 : 
	  case 65311 : 
	  case 65281 : 
	  case 8263 : 
	  case 8252 : 
	  case 8264 : 
	  case 8265 : 
	    {
	      if ( ( litstack [litstkptr ]>= cmdstrptr ) ) 
	      {
		strptr = strptr + 1 ;
		poolptr = strstart [strptr ];
	      } 
	      litstkptr = litstkptr + 1 ;
	    } 
	    break ;
	    default: 
	    {
	      if ( ( poplit1 < cmdstrptr ) ) 
	      {
		{
		  while ( ( poolptr + ( strstart [poplit1 + 1 ]- strstart [
		  poplit1 ]) + 1 > poolsize ) ) pooloverflow () ;
		} 
		spptr = strstart [poplit1 ];
		spend = strstart [poplit1 + 1 ];
		while ( ( spptr < spend ) ) {
		    
		  {
		    strpool [poolptr ]= strpool [spptr ];
		    poolptr = poolptr + 1 ;
		  } 
		  spptr = spptr + 1 ;
		} 
	      } 
	      else {
		  
		poolptr = strstart [poplit1 + 1 ];
		{
		  while ( ( poolptr + 1 > poolsize ) ) pooloverflow () ;
		} 
	      } 
	      {
		strpool [poolptr ]= 46 ;
		poolptr = poolptr + 1 ;
	      } 
	      pushlitstk ( makestring () , 1 ) ;
	    } 
	    break ;
	  } 
	} 
      } 
      break ;
    } 
  } 
} 
void 
xchangecase ( void ) 
{
  /* 21 */ poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  if ( ( poptyp1 != 1 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else if ( ( poptyp2 != 1 ) ) 
  {
    printwrongstklit ( poplit2 , poptyp2 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else {
      
    {
      switch ( ( strpool [strstart [poplit1 ]]) ) 
      {case 116 : 
      case 84 : 
	conversiontype = 0 ;
	break ;
      case 108 : 
      case 76 : 
	conversiontype = 1 ;
	break ;
      case 117 : 
      case 85 : 
	conversiontype = 2 ;
	break ;
	default: 
	conversiontype = 3 ;
	break ;
      } 
      if ( ( ( ( strstart [poplit1 + 1 ]- strstart [poplit1 ]) != 1 ) || ( 
      conversiontype == 3 ) ) ) 
      {
	conversiontype = 3 ;
	printapoolstr ( poplit1 ) ;
	{
	  {
	    Fputs ( logfile ,  " is an illegal case-conversion string" ) ;
	    Fputs ( standardoutput ,  " is an illegal case-conversion string" ) 
	    ;
	  } 
	  bstexwarnprint () ;
	} 
      } 
    } 
    exbuflength = 0 ;
    addbufpool ( poplit2 ) ;
    {
      bracelevel = 0 ;
      exbufptr = 0 ;
      while ( ( exbufptr < exbuflength ) ) {
	  
	if ( ( exbuf [exbufptr ]== 123 ) ) 
	{
	  bracelevel = bracelevel + 1 ;
	  if ( ( bracelevel != 1 ) ) 
	  goto lab21 ;
	  if ( ( exbufptr + 4 > exbuflength ) ) 
	  goto lab21 ;
	  else if ( ( exbuf [exbufptr + 1 ]!= 92 ) ) 
	  goto lab21 ;
	  if ( ( conversiontype == 0 ) ) {
	      
	    if ( ( exbufptr == 0 ) ) 
	    goto lab21 ;
	    else if ( ( ( prevcolon ) && ( lexclass [exbuf [exbufptr - 1 ]]
	    == 1 ) ) ) 
	    goto lab21 ;
	  } 
	  {
	    exbufptr = exbufptr + 1 ;
	    while ( ( ( exbufptr < exbuflength ) && ( bracelevel > 0 ) ) ) {
		
	      exbufptr = exbufptr + 1 ;
	      exbufxptr = exbufptr ;
	      while ( ( ( exbufptr < exbuflength ) && ( lexclass [exbuf [
	      exbufptr ]]== 2 ) ) ) exbufptr = exbufptr + 1 ;
	      controlseqloc = strlookup ( exbuf , exbufxptr , exbufptr - 
	      exbufxptr , 14 , false ) ;
	      if ( ( hashfound ) ) 
	      {
		switch ( ( conversiontype ) ) 
		{case 0 : 
		case 1 : 
		  switch ( ( ilkinfo [controlseqloc ]) ) 
		  {case 11 : 
		  case 9 : 
		  case 3 : 
		  case 5 : 
		  case 7 : 
		    lowercase ( exbuf , exbufxptr , exbufptr - exbufxptr ) ;
		    break ;
		    default: 
		    ;
		    break ;
		  } 
		  break ;
		case 2 : 
		  switch ( ( ilkinfo [controlseqloc ]) ) 
		  {case 10 : 
		  case 8 : 
		  case 2 : 
		  case 4 : 
		  case 6 : 
		    uppercase ( exbuf , exbufxptr , exbufptr - exbufxptr ) ;
		    break ;
		  case 0 : 
		  case 1 : 
		  case 12 : 
		    {
		      uppercase ( exbuf , exbufxptr , exbufptr - exbufxptr ) ;
		      while ( ( exbufxptr < exbufptr ) ) {
			  
			exbuf [exbufxptr - 1 ]= exbuf [exbufxptr ];
			exbufxptr = exbufxptr + 1 ;
		      } 
		      exbufxptr = exbufxptr - 1 ;
		      while ( ( ( exbufptr < exbuflength ) && ( lexclass [
		      exbuf [exbufptr ]]== 1 ) ) ) exbufptr = exbufptr + 1 
		      ;
		      tmpptr = exbufptr ;
		      while ( ( tmpptr < exbuflength ) ) {
			  
			exbuf [tmpptr - ( exbufptr - exbufxptr ) ]= exbuf [
			tmpptr ];
			tmpptr = tmpptr + 1 ;
		      } 
		      exbuflength = tmpptr - ( exbufptr - exbufxptr ) ;
		      exbufptr = exbufxptr ;
		    } 
		    break ;
		    default: 
		    ;
		    break ;
		  } 
		  break ;
		case 3 : 
		  ;
		  break ;
		  default: 
		  caseconversionconfusion () ;
		  break ;
		} 
	      } 
	      exbufxptr = exbufptr ;
	      while ( ( ( exbufptr < exbuflength ) && ( bracelevel > 0 ) && ( 
	      exbuf [exbufptr ]!= 92 ) ) ) {
		  
		if ( ( exbuf [exbufptr ]== 125 ) ) 
		bracelevel = bracelevel - 1 ;
		else if ( ( exbuf [exbufptr ]== 123 ) ) 
		bracelevel = bracelevel + 1 ;
		exbufptr = exbufptr + 1 ;
	      } 
	      {
		switch ( ( conversiontype ) ) 
		{case 0 : 
		case 1 : 
		  lowercase ( exbuf , exbufxptr , exbufptr - exbufxptr ) ;
		  break ;
		case 2 : 
		  uppercase ( exbuf , exbufxptr , exbufptr - exbufxptr ) ;
		  break ;
		case 3 : 
		  ;
		  break ;
		  default: 
		  caseconversionconfusion () ;
		  break ;
		} 
	      } 
	    } 
	    exbufptr = exbufptr - 1 ;
	  } 
	  lab21: prevcolon = false ;
	} 
	else if ( ( exbuf [exbufptr ]== 125 ) ) 
	{
	  decrbracelevel ( poplit2 ) ;
	  prevcolon = false ;
	} 
	else if ( ( bracelevel == 0 ) ) 
	{
	  switch ( ( conversiontype ) ) 
	  {case 0 : 
	    {
	      if ( ( exbufptr == 0 ) ) 
	      ;
	      else if ( ( ( prevcolon ) && ( lexclass [exbuf [exbufptr - 1 ]
	      ]== 1 ) ) ) 
	      ;
	      else lowercase ( exbuf , exbufptr , 1 ) ;
	      if ( ( exbuf [exbufptr ]== 58 ) ) 
	      prevcolon = true ;
	      else if ( ( lexclass [exbuf [exbufptr ]]!= 1 ) ) 
	      prevcolon = false ;
	    } 
	    break ;
	  case 1 : 
	    lowercase ( exbuf , exbufptr , 1 ) ;
	    break ;
	  case 2 : 
	    uppercase ( exbuf , exbufptr , 1 ) ;
	    break ;
	  case 3 : 
	    ;
	    break ;
	    default: 
	    caseconversionconfusion () ;
	    break ;
	  } 
	} 
	exbufptr = exbufptr + 1 ;
      } 
      checkbracelevel ( poplit2 ) ;
    } 
    addpoolbufandpush () ;
  } 
} 
void 
xchrtoint ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 1 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( ( strstart [poplit1 + 1 ]- strstart [poplit1 ]) != 1 ) ) {
      
    if ( ( strpool [strstart [poplit1 ]]> 127 ) ) 
    pushlitstk ( strpool [strstart [poplit1 ]], 0 ) ;
    else {
	
      {
	putc ( '"' ,  logfile );
	putc ( '"' ,  standardoutput );
      } 
      printapoolstr ( poplit1 ) ;
      {
	{
	  Fputs ( logfile ,  "\" isn't a single character" ) ;
	  Fputs ( standardoutput ,  "\" isn't a single character" ) ;
	} 
	bstexwarnprint () ;
      } 
      pushlitstk ( 0 , 0 ) ;
    } 
  } 
  else pushlitstk ( strpool [strstart [poplit1 ]], 0 ) ;
} 
void 
xcite ( void ) 
{
  if ( ( ! messwithentries ) ) 
  bstcantmesswithentriesprint () ;
  else pushlitstk ( citelist [citeptr ], 1 ) ;
} 
void 
xduplicate ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 1 ) ) 
  {
    pushlitstk ( poplit1 , poptyp1 ) ;
    pushlitstk ( poplit1 , poptyp1 ) ;
  } 
  else {
      
    {
      if ( ( litstack [litstkptr ]>= cmdstrptr ) ) 
      {
	strptr = strptr + 1 ;
	poolptr = strstart [strptr ];
      } 
      litstkptr = litstkptr + 1 ;
    } 
    if ( ( poplit1 < cmdstrptr ) ) 
    pushlitstk ( poplit1 , poptyp1 ) ;
    else {
	
      {
	while ( ( poolptr + ( strstart [poplit1 + 1 ]- strstart [poplit1 ]
	) > poolsize ) ) pooloverflow () ;
      } 
      spptr = strstart [poplit1 ];
      spend = strstart [poplit1 + 1 ];
      while ( ( spptr < spend ) ) {
	  
	{
	  strpool [poolptr ]= strpool [spptr ];
	  poolptr = poolptr + 1 ;
	} 
	spptr = spptr + 1 ;
      } 
      pushlitstk ( makestring () , 1 ) ;
    } 
  } 
} 
void 
xempty ( void ) 
{
  /* 10 */ poplitstk ( poplit1 , poptyp1 ) ;
  switch ( ( poptyp1 ) ) 
  {case 1 : 
    {
      spptr = strstart [poplit1 ];
      spend = strstart [poplit1 + 1 ];
      while ( ( spptr < spend ) ) {
	  
	if ( ( lexclass [strpool [spptr ]]!= 1 ) ) 
	{
	  pushlitstk ( 0 , 0 ) ;
	  goto lab10 ;
	} 
	spptr = spptr + 1 ;
      } 
      pushlitstk ( 1 , 0 ) ;
    } 
    break ;
  case 3 : 
    pushlitstk ( 1 , 0 ) ;
    break ;
  case 4 : 
    pushlitstk ( 0 , 0 ) ;
    break ;
    default: 
    {
      printstklit ( poplit1 , poptyp1 ) ;
      {
	{
	  Fputs ( logfile ,  ", not a string or missing field," ) ;
	  Fputs ( standardoutput ,  ", not a string or missing field," ) ;
	} 
	bstexwarnprint () ;
      } 
      pushlitstk ( 0 , 0 ) ;
    } 
    break ;
  } 
  lab10: ;
} 
void 
xformatname ( void ) 
{
  /* 16 17 52 */ poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  poplitstk ( poplit3 , poptyp3 ) ;
  if ( ( poptyp1 != 1 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else if ( ( poptyp2 != 0 ) ) 
  {
    printwrongstklit ( poplit2 , poptyp2 , 0 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else if ( ( poptyp3 != 1 ) ) 
  {
    printwrongstklit ( poplit3 , poptyp3 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else {
      
    exbuflength = 0 ;
    addbufpool ( poplit3 ) ;
    {
      exbufptr = 0 ;
      numnames = 0 ;
      while ( ( ( numnames < poplit2 ) && ( exbufptr < exbuflength ) ) ) {
	  
	numnames = numnames + 1 ;
	exbufxptr = exbufptr ;
	namescanforand ( poplit3 ) ;
      } 
      if ( ( exbufptr < exbuflength ) ) 
      {
	if ( ( isinternalEUC () ) ) {
	    
	  if ( ( ( fromBUFF ( exbuf , exbuflength , exbufptr - 2 ) == 41380L ) 
	  || ( fromBUFF ( exbuf , exbuflength , exbufptr - 2 ) == 41378L ) ) ) 
	  exbufptr = exbufptr - 2 ;
	  else exbufptr = exbufptr - 4 ;
	} 
	if ( ( isinternalUPTEX () ) ) {
	    
	  if ( ( ( fromBUFF ( exbuf , exbuflength , exbufptr - 3 ) == 65292L ) 
	  || ( fromBUFF ( exbuf , exbuflength , exbufptr - 3 ) == 12289 ) ) ) 
	  exbufptr = exbufptr - 3 ;
	  else exbufptr = exbufptr - 4 ;
	} 
      } 
      if ( ( numnames < poplit2 ) ) 
      {
	if ( ( poplit2 == 1 ) ) 
	{
	  Fputs ( logfile ,  "There is no name in \"" ) ;
	  Fputs ( standardoutput ,  "There is no name in \"" ) ;
	} 
	else {
	    
	  fprintf ( logfile , "%s%ld%s",  "There aren't " , (long)poplit2 , " names in \"" ) ;
	  fprintf ( standardoutput , "%s%ld%s",  "There aren't " , (long)poplit2 , " names in \""           ) ;
	} 
	printapoolstr ( poplit3 ) ;
	{
	  {
	    putc ( '"' ,  logfile );
	    putc ( '"' ,  standardoutput );
	  } 
	  bstexwarnprint () ;
	} 
      } 
    } 
    {
      {
	while ( ( exbufptr > exbufxptr ) ) switch ( ( lexclass [exbuf [
	exbufptr - 1 ]]) ) 
	{case 1 : 
	case 4 : 
	  exbufptr = exbufptr - 1 ;
	  break ;
	  default: 
	  if ( ( exbuf [exbufptr - 1 ]== 44 ) ) 
	  {
	    {
	      fprintf ( logfile , "%s%ld%s",  "Name " , (long)poplit2 , " in \"" ) ;
	      fprintf ( standardoutput , "%s%ld%s",  "Name " , (long)poplit2 , " in \"" ) ;
	    } 
	    printapoolstr ( poplit3 ) ;
	    {
	      Fputs ( logfile ,  "\" has a comma at the end" ) ;
	      Fputs ( standardoutput ,  "\" has a comma at the end" ) ;
	    } 
	    bstexwarnprint () ;
	    exbufptr = exbufptr - 1 ;
	  } 
	  else goto lab16 ;
	  break ;
	} 
	lab16: ;
      } 
      namebfptr = 0 ;
      numcommas = 0 ;
      numtokens = 0 ;
      tokenstarting = true ;
      while ( ( exbufxptr < exbufptr ) ) switch ( ( exbuf [exbufxptr ]) ) 
      {case 44 : 
	{
	  if ( ( numcommas == 2 ) ) 
	  {
	    {
	      fprintf ( logfile , "%s%ld%s",  "Too many commas in name " , (long)poplit2 ,               " of \"" ) ;
	      fprintf ( standardoutput , "%s%ld%s",  "Too many commas in name " , (long)poplit2 ,               " of \"" ) ;
	    } 
	    printapoolstr ( poplit3 ) ;
	    {
	      putc ( '"' ,  logfile );
	      putc ( '"' ,  standardoutput );
	    } 
	    bstexwarnprint () ;
	  } 
	  else {
	      
	    numcommas = numcommas + 1 ;
	    if ( ( numcommas == 1 ) ) 
	    comma1 = numtokens ;
	    else comma2 = numtokens ;
	    namesepchar [numtokens ]= 44 ;
	  } 
	  exbufxptr = exbufxptr + 1 ;
	  tokenstarting = true ;
	} 
	break ;
      case 123 : 
	{
	  bracelevel = bracelevel + 1 ;
	  if ( ( tokenstarting ) ) 
	  {
	    nametok [numtokens ]= namebfptr ;
	    numtokens = numtokens + 1 ;
	  } 
	  svbuffer [namebfptr ]= exbuf [exbufxptr ];
	  namebfptr = namebfptr + 1 ;
	  exbufxptr = exbufxptr + 1 ;
	  while ( ( ( bracelevel > 0 ) && ( exbufxptr < exbufptr ) ) ) {
	      
	    if ( ( exbuf [exbufxptr ]== 125 ) ) 
	    bracelevel = bracelevel - 1 ;
	    else if ( ( exbuf [exbufxptr ]== 123 ) ) 
	    bracelevel = bracelevel + 1 ;
	    svbuffer [namebfptr ]= exbuf [exbufxptr ];
	    namebfptr = namebfptr + 1 ;
	    exbufxptr = exbufxptr + 1 ;
	  } 
	  tokenstarting = false ;
	} 
	break ;
      case 125 : 
	{
	  if ( ( tokenstarting ) ) 
	  {
	    nametok [numtokens ]= namebfptr ;
	    numtokens = numtokens + 1 ;
	  } 
	  {
	    fprintf ( logfile , "%s%ld%s",  "Name " , (long)poplit2 , " of \"" ) ;
	    fprintf ( standardoutput , "%s%ld%s",  "Name " , (long)poplit2 , " of \"" ) ;
	  } 
	  printapoolstr ( poplit3 ) ;
	  {
	    {
	      Fputs ( logfile ,  "\" isn't brace balanced" ) ;
	      Fputs ( standardoutput ,  "\" isn't brace balanced" ) ;
	    } 
	    bstexwarnprint () ;
	  } 
	  exbufxptr = exbufxptr + 1 ;
	  tokenstarting = false ;
	} 
	break ;
	default: 
	switch ( ( lexclass [exbuf [exbufxptr ]]) ) 
	{case 1 : 
	  {
	    if ( ( ! tokenstarting ) ) 
	    namesepchar [numtokens ]= 32 ;
	    exbufxptr = exbufxptr + 1 ;
	    tokenstarting = true ;
	  } 
	  break ;
	case 4 : 
	  {
	    if ( ( ! tokenstarting ) ) 
	    namesepchar [numtokens ]= exbuf [exbufxptr ];
	    exbufxptr = exbufxptr + 1 ;
	    tokenstarting = true ;
	  } 
	  break ;
	  default: 
	  {
	    if ( ( tokenstarting ) ) 
	    {
	      nametok [numtokens ]= namebfptr ;
	      numtokens = numtokens + 1 ;
	    } 
	    svbuffer [namebfptr ]= exbuf [exbufxptr ];
	    namebfptr = namebfptr + 1 ;
	    exbufxptr = exbufxptr + 1 ;
	    tokenstarting = false ;
	  } 
	  break ;
	} 
	break ;
      } 
      nametok [numtokens ]= namebfptr ;
    } 
    {
      if ( ( numcommas == 0 ) ) 
      {
	firststart = 0 ;
	lastend = numtokens ;
	jrend = lastend ;
	{
	  vonstart = 0 ;
	  while ( ( vonstart < lastend - 1 ) ) {
	      
	    namebfptr = nametok [vonstart ];
	    namebfxptr = nametok [vonstart + 1 ];
	    if ( ( vontokenfound () ) ) 
	    {
	      vonnameendsandlastnamestartsstuff () ;
	      goto lab52 ;
	    } 
	    vonstart = vonstart + 1 ;
	  } 
	  while ( ( vonstart > 0 ) ) {
	      
	    if ( ( ( lexclass [namesepchar [vonstart ]]!= 4 ) || ( 
	    namesepchar [vonstart ]== 126 ) ) ) 
	    goto lab17 ;
	    vonstart = vonstart - 1 ;
	  } 
	  lab17: vonend = vonstart ;
	  lab52: firstend = vonstart ;
	} 
      } 
      else if ( ( numcommas == 1 ) ) 
      {
	vonstart = 0 ;
	lastend = comma1 ;
	jrend = lastend ;
	firststart = jrend ;
	firstend = numtokens ;
	vonnameendsandlastnamestartsstuff () ;
      } 
      else if ( ( numcommas == 2 ) ) 
      {
	vonstart = 0 ;
	lastend = comma1 ;
	jrend = comma2 ;
	firststart = jrend ;
	firstend = numtokens ;
	vonnameendsandlastnamestartsstuff () ;
      } 
      else {
	  
	{
	  Fputs ( logfile ,  "Illegal number of comma,s" ) ;
	  Fputs ( standardoutput ,  "Illegal number of comma,s" ) ;
	} 
	printconfusion () ;
	longjmp(jmp9998,1) ;
      } 
    } 
    exbuflength = 0 ;
    addbufpool ( poplit1 ) ;
    figureouttheformattedname () ;
    addpoolbufandpush () ;
  } 
} 
void 
xinttochr ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 0 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 0 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else if ( ( ( poplit1 < 0 ) || ( poplit1 > 127 ) ) ) 
  {
    {
      {
	fprintf ( logfile , "%ld%s",  (long)poplit1 , " isn't valid ASCII" ) ;
	fprintf ( standardoutput , "%ld%s",  (long)poplit1 , " isn't valid ASCII" ) ;
      } 
      bstexwarnprint () ;
    } 
    pushlitstk ( snull , 1 ) ;
  } 
  else {
      
    {
      while ( ( poolptr + 1 > poolsize ) ) pooloverflow () ;
    } 
    {
      strpool [poolptr ]= poplit1 ;
      poolptr = poolptr + 1 ;
    } 
    pushlitstk ( makestring () , 1 ) ;
  } 
} 
void 
xinttostr ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 0 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 0 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else {
      
    inttoASCII ( poplit1 , exbuf , 0 , exbuflength ) ;
    addpoolbufandpush () ;
  } 
} 
void 
xmissing ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( ! messwithentries ) ) 
  bstcantmesswithentriesprint () ;
  else if ( ( ( poptyp1 != 1 ) && ( poptyp1 != 3 ) ) ) 
  {
    if ( ( poptyp1 != 4 ) ) 
    {
      printstklit ( poplit1 , poptyp1 ) ;
      {
	{
	  Fputs ( logfile ,  ", not a string or missing field," ) ;
	  Fputs ( standardoutput ,  ", not a string or missing field," ) ;
	} 
	bstexwarnprint () ;
      } 
    } 
    pushlitstk ( 0 , 0 ) ;
  } 
  else if ( ( poptyp1 == 3 ) ) 
  pushlitstk ( 1 , 0 ) ;
  else pushlitstk ( 0 , 0 ) ;
} 
void 
xnumnames ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 1 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else {
      
    exbuflength = 0 ;
    addbufpool ( poplit1 ) ;
    {
      exbufptr = 0 ;
      numnames = 0 ;
      while ( ( exbufptr < exbuflength ) ) {
	  
	namescanforand ( poplit1 ) ;
	numnames = numnames + 1 ;
      } 
    } 
    pushlitstk ( numnames , 0 ) ;
  } 
} 
void 
xpreamble ( void ) 
{
  exbuflength = 0 ;
  preambleptr = 0 ;
  while ( ( preambleptr < numpreamblestrings ) ) {
      
    addbufpool ( spreamble [preambleptr ]) ;
    preambleptr = preambleptr + 1 ;
  } 
  addpoolbufandpush () ;
} 
void 
xpurify ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 1 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else {
      
    exbuflength = 0 ;
    addbufpool ( poplit1 ) ;
    {
      bracelevel = 0 ;
      exbufxptr = 0 ;
      exbufptr = 0 ;
      while ( ( exbufptr < exbuflength ) ) {
	  
	switch ( ( lexclass [exbuf [exbufptr ]]) ) 
	{case 1 : 
	case 4 : 
	  {
	    exbuf [exbufxptr ]= 32 ;
	    exbufxptr = exbufxptr + 1 ;
	  } 
	  break ;
	case 2 : 
	case 3 : 
	  {
	    exbuf [exbufxptr ]= exbuf [exbufptr ];
	    exbufxptr = exbufxptr + 1 ;
	  } 
	  break ;
	  default: 
	  if ( ( exbuf [exbufptr ]== 123 ) ) 
	  {
	    bracelevel = bracelevel + 1 ;
	    if ( ( ( bracelevel == 1 ) && ( exbufptr + 1 < exbuflength ) ) ) {
		
	      if ( ( exbuf [exbufptr + 1 ]== 92 ) ) 
	      {
		exbufptr = exbufptr + 1 ;
		while ( ( ( exbufptr < exbuflength ) && ( bracelevel > 0 ) ) ) 
		{
		  exbufptr = exbufptr + 1 ;
		  exbufyptr = exbufptr ;
		  while ( ( ( exbufptr < exbuflength ) && ( lexclass [exbuf [
		  exbufptr ]]== 2 ) ) ) exbufptr = exbufptr + 1 ;
		  controlseqloc = strlookup ( exbuf , exbufyptr , exbufptr - 
		  exbufyptr , 14 , false ) ;
		  if ( ( hashfound ) ) 
		  {
		    exbuf [exbufxptr ]= exbuf [exbufyptr ];
		    exbufxptr = exbufxptr + 1 ;
		    switch ( ( ilkinfo [controlseqloc ]) ) 
		    {case 2 : 
		    case 3 : 
		    case 4 : 
		    case 5 : 
		    case 12 : 
		      {
			exbuf [exbufxptr ]= exbuf [exbufyptr + 1 ];
			exbufxptr = exbufxptr + 1 ;
		      } 
		      break ;
		      default: 
		      ;
		      break ;
		    } 
		  } 
		  while ( ( ( exbufptr < exbuflength ) && ( bracelevel > 0 ) 
		  && ( exbuf [exbufptr ]!= 92 ) ) ) {
		      
		    switch ( ( lexclass [exbuf [exbufptr ]]) ) 
		    {case 2 : 
		    case 3 : 
		      {
			exbuf [exbufxptr ]= exbuf [exbufptr ];
			exbufxptr = exbufxptr + 1 ;
		      } 
		      break ;
		      default: 
		      if ( ( exbuf [exbufptr ]== 125 ) ) 
		      bracelevel = bracelevel - 1 ;
		      else if ( ( exbuf [exbufptr ]== 123 ) ) 
		      bracelevel = bracelevel + 1 ;
		      break ;
		    } 
		    exbufptr = exbufptr + 1 ;
		  } 
		} 
		exbufptr = exbufptr - 1 ;
	      } 
	    } 
	  } 
	  else if ( ( exbuf [exbufptr ]== 125 ) ) {
	      
	    if ( ( bracelevel > 0 ) ) 
	    bracelevel = bracelevel - 1 ;
	  } 
	  break ;
	} 
	exbufptr = exbufptr + 1 ;
      } 
      exbuflength = exbufxptr ;
    } 
    addpoolbufandpush () ;
  } 
} 
void 
xquote ( void ) 
{
  {
    while ( ( poolptr + 1 > poolsize ) ) pooloverflow () ;
  } 
  {
    strpool [poolptr ]= 34 ;
    poolptr = poolptr + 1 ;
  } 
  pushlitstk ( makestring () , 1 ) ;
} 
void 
xsubstring ( void ) 
{
  /* 10 */ poolpointer tps, tpe  ;
  poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  poplitstk ( poplit3 , poptyp3 ) ;
  if ( ( poptyp1 != 0 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 0 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else if ( ( poptyp2 != 0 ) ) 
  {
    printwrongstklit ( poplit2 , poptyp2 , 0 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else if ( ( poptyp3 != 1 ) ) 
  {
    printwrongstklit ( poplit3 , poptyp3 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else {
      
    splength = ( strstart [poplit3 + 1 ]- strstart [poplit3 ]) ;
    if ( ( poplit1 >= splength ) ) {
	
      if ( ( ( poplit2 == 1 ) || ( poplit2 == -1 ) ) ) 
      {
	{
	  if ( ( litstack [litstkptr ]>= cmdstrptr ) ) 
	  {
	    strptr = strptr + 1 ;
	    poolptr = strstart [strptr ];
	  } 
	  litstkptr = litstkptr + 1 ;
	} 
	goto lab10 ;
      } 
    } 
    if ( ( ( poplit1 <= 0 ) || ( poplit2 == 0 ) || ( poplit2 > splength ) || ( 
    poplit2 < - (integer) splength ) ) ) 
    {
      pushlitstk ( snull , 1 ) ;
      goto lab10 ;
    } 
    else {
	
      if ( ( poplit2 > 0 ) ) 
      {
	if ( ( poplit1 > splength - ( poplit2 - 1 ) ) ) 
	poplit1 = splength - ( poplit2 - 1 ) ;
	spptr = strstart [poplit3 ]+ ( poplit2 - 1 ) ;
	spend = spptr + poplit1 ;
	if ( ( poplit2 == 1 ) ) {
	    
	  if ( ( poplit3 >= cmdstrptr ) ) 
	  {
	    strstart [poplit3 + 1 ]= spend ;
	    {
	      strptr = strptr + 1 ;
	      poolptr = strstart [strptr ];
	    } 
	    litstkptr = litstkptr + 1 ;
	    goto lab10 ;
	  } 
	} 
      } 
      else {
	  
	poplit2 = - (integer) poplit2 ;
	if ( ( poplit1 > splength - ( poplit2 - 1 ) ) ) 
	poplit1 = splength - ( poplit2 - 1 ) ;
	spend = strstart [poplit3 + 1 ]- ( poplit2 - 1 ) ;
	spptr = spend - poplit1 ;
      } 
      tps = strstart [poplit3 ];
      while ( ( tps < spptr ) ) {
	  
	tps = tps + multibytelen ( strpool [tps ]) ;
      } 
      tpe = tps ;
      while ( ( tpe < spend ) ) {
	  
	tpe = tpe + multibytelen ( strpool [tpe ]) ;
      } 
      if ( tps != spptr ) 
      {
	if ( tps > strstart [poplit3 ]) 
	spptr = spptr - 1 ;
	else spptr = spptr + 1 ;
      } 
      if ( tpe != spend ) 
      {
	if ( tpe < strstart [poplit3 + 1 ]) 
	spend = spend + 1 ;
	else spend = spend - 1 ;
      } 
      {
	while ( ( poolptr + spend - spptr > poolsize ) ) pooloverflow () ;
      } 
      while ( ( spptr < spend ) ) {
	  
	{
	  strpool [poolptr ]= strpool [spptr ];
	  poolptr = poolptr + 1 ;
	} 
	if ( multibytelen ( strpool [spptr ]) > 1 ) 
	{
	  strpool [poolptr ]= strpool [spptr + 1 ];
	  poolptr = poolptr + 1 ;
	} 
	if ( multibytelen ( strpool [spptr ]) > 2 ) 
	{
	  strpool [poolptr ]= strpool [spptr + 2 ];
	  poolptr = poolptr + 1 ;
	} 
	if ( multibytelen ( strpool [spptr ]) > 3 ) 
	{
	  strpool [poolptr ]= strpool [spptr + 3 ];
	  poolptr = poolptr + 1 ;
	} 
	if ( multibytelen ( strpool [spptr ]) > 0 ) 
	spptr = spptr + multibytelen ( strpool [spptr ]) ;
	else spptr = spptr + 1 ;
      } 
      pushlitstk ( makestring () , 1 ) ;
    } 
  } 
  lab10: ;
} 
void 
xswap ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  if ( ( ( poptyp1 != 1 ) || ( poplit1 < cmdstrptr ) ) ) 
  {
    pushlitstk ( poplit1 , poptyp1 ) ;
    if ( ( ( poptyp2 == 1 ) && ( poplit2 >= cmdstrptr ) ) ) 
    {
      strptr = strptr + 1 ;
      poolptr = strstart [strptr ];
    } 
    pushlitstk ( poplit2 , poptyp2 ) ;
  } 
  else if ( ( ( poptyp2 != 1 ) || ( poplit2 < cmdstrptr ) ) ) 
  {
    {
      strptr = strptr + 1 ;
      poolptr = strstart [strptr ];
    } 
    pushlitstk ( poplit1 , 1 ) ;
    pushlitstk ( poplit2 , poptyp2 ) ;
  } 
  else {
      
    exbuflength = 0 ;
    addbufpool ( poplit2 ) ;
    spptr = strstart [poplit1 ];
    spend = strstart [poplit1 + 1 ];
    while ( ( spptr < spend ) ) {
	
      {
	strpool [poolptr ]= strpool [spptr ];
	poolptr = poolptr + 1 ;
      } 
      spptr = spptr + 1 ;
    } 
    pushlitstk ( makestring () , 1 ) ;
    addpoolbufandpush () ;
  } 
} 
void 
xtextlength ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 1 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else {
      
    numtextchars = 0 ;
    {
      spptr = strstart [poplit1 ];
      spend = strstart [poplit1 + 1 ];
      spbracelevel = 0 ;
      while ( ( spptr < spend ) ) {
	  
	spptr = spptr + 1 ;
	if ( ( strpool [spptr - 1 ]== 123 ) ) 
	{
	  spbracelevel = spbracelevel + 1 ;
	  if ( ( ( spbracelevel == 1 ) && ( spptr < spend ) ) ) {
	      
	    if ( ( strpool [spptr ]== 92 ) ) 
	    {
	      spptr = spptr + 1 ;
	      while ( ( ( spptr < spend ) && ( spbracelevel > 0 ) ) ) {
		  
		if ( ( strpool [spptr ]== 125 ) ) 
		spbracelevel = spbracelevel - 1 ;
		else if ( ( strpool [spptr ]== 123 ) ) 
		spbracelevel = spbracelevel + 1 ;
		spptr = spptr + 1 ;
	      } 
	      numtextchars = numtextchars + 1 ;
	    } 
	  } 
	} 
	else if ( ( strpool [spptr - 1 ]== 125 ) ) 
	{
	  if ( ( spbracelevel > 0 ) ) 
	  spbracelevel = spbracelevel - 1 ;
	} 
	else numtextchars = numtextchars + 1 ;
      } 
    } 
    pushlitstk ( numtextchars , 0 ) ;
  } 
} 
void 
xtextprefix ( void ) 
{
  /* 10 */ poplitstk ( poplit1 , poptyp1 ) ;
  poplitstk ( poplit2 , poptyp2 ) ;
  if ( ( poptyp1 != 0 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 0 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else if ( ( poptyp2 != 1 ) ) 
  {
    printwrongstklit ( poplit2 , poptyp2 , 1 ) ;
    pushlitstk ( snull , 1 ) ;
  } 
  else if ( ( poplit1 <= 0 ) ) 
  {
    pushlitstk ( snull , 1 ) ;
    goto lab10 ;
  } 
  else {
      
    spptr = strstart [poplit2 ];
    spend = strstart [poplit2 + 1 ];
    {
      numtextchars = 0 ;
      spbracelevel = 0 ;
      spxptr1 = spptr ;
      while ( ( ( spxptr1 < spend ) && ( numtextchars < poplit1 ) ) ) {
	  
	spxptr1 = spxptr1 + 1 ;
	if ( ( strpool [spxptr1 - 1 ]== 123 ) ) 
	{
	  spbracelevel = spbracelevel + 1 ;
	  if ( ( ( spbracelevel == 1 ) && ( spxptr1 < spend ) ) ) {
	      
	    if ( ( strpool [spxptr1 ]== 92 ) ) 
	    {
	      spxptr1 = spxptr1 + 1 ;
	      while ( ( ( spxptr1 < spend ) && ( spbracelevel > 0 ) ) ) {
		  
		if ( ( strpool [spxptr1 ]== 125 ) ) 
		spbracelevel = spbracelevel - 1 ;
		else if ( ( strpool [spxptr1 ]== 123 ) ) 
		spbracelevel = spbracelevel + 1 ;
		spxptr1 = spxptr1 + 1 ;
	      } 
	      numtextchars = numtextchars + 1 ;
	    } 
	  } 
	} 
	else if ( ( strpool [spxptr1 - 1 ]== 125 ) ) 
	{
	  if ( ( spbracelevel > 0 ) ) 
	  spbracelevel = spbracelevel - 1 ;
	} 
	else if ( ( strpool [spxptr1 - 1 ]> 127 ) ) 
	{
	  numtextchars = numtextchars + multibytelen ( strpool [spxptr1 - 1 ]
	  ) ;
	  spxptr1 = spxptr1 - 1 + multibytelen ( strpool [spxptr1 - 1 ]) ;
	} 
	else numtextchars = numtextchars + 1 ;
      } 
      spend = spxptr1 ;
    } 
    {
      while ( ( poolptr + spbracelevel + spend - spptr > poolsize ) ) 
      pooloverflow () ;
    } 
    if ( ( poplit2 >= cmdstrptr ) ) 
    poolptr = spend ;
    else while ( ( spptr < spend ) ) {
	
      {
	strpool [poolptr ]= strpool [spptr ];
	poolptr = poolptr + 1 ;
      } 
      spptr = spptr + 1 ;
    } 
    while ( ( spbracelevel > 0 ) ) {
	
      {
	strpool [poolptr ]= 125 ;
	poolptr = poolptr + 1 ;
      } 
      spbracelevel = spbracelevel - 1 ;
    } 
    pushlitstk ( makestring () , 1 ) ;
  } 
  lab10: ;
} 
void 
xtype ( void ) 
{
  if ( ( ! messwithentries ) ) 
  bstcantmesswithentriesprint () ;
  else if ( ( ( typelist [citeptr ]== undefined ) || ( typelist [citeptr ]
  == 0 ) ) ) 
  pushlitstk ( snull , 1 ) ;
  else pushlitstk ( hashtext [typelist [citeptr ]], 1 ) ;
} 
void 
xwarning ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 1 ) ) 
  printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
  else {
      
    {
      Fputs ( logfile ,  "Warning--" ) ;
      Fputs ( standardoutput ,  "Warning--" ) ;
    } 
    printlit ( poplit1 , poptyp1 ) ;
    markwarning () ;
  } 
} 
void 
xwidth ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 1 ) ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else {
      
    exbuflength = 0 ;
    addbufpool ( poplit1 ) ;
    stringwidth = 0 ;
    {
      bracelevel = 0 ;
      exbufptr = 0 ;
      while ( ( exbufptr < exbuflength ) ) {
	  
	if ( ( exbuf [exbufptr ]== 123 ) ) 
	{
	  bracelevel = bracelevel + 1 ;
	  if ( ( ( bracelevel == 1 ) && ( exbufptr + 1 < exbuflength ) ) ) {
	      
	    if ( ( exbuf [exbufptr + 1 ]== 92 ) ) 
	    {
	      exbufptr = exbufptr + 1 ;
	      while ( ( ( exbufptr < exbuflength ) && ( bracelevel > 0 ) ) ) {
		  
		exbufptr = exbufptr + 1 ;
		exbufxptr = exbufptr ;
		while ( ( ( exbufptr < exbuflength ) && ( lexclass [exbuf [
		exbufptr ]]== 2 ) ) ) exbufptr = exbufptr + 1 ;
		if ( ( ( exbufptr < exbuflength ) && ( exbufptr == exbufxptr ) 
		) ) 
		exbufptr = exbufptr + 1 ;
		else {
		    
		  controlseqloc = strlookup ( exbuf , exbufxptr , exbufptr - 
		  exbufxptr , 14 , false ) ;
		  if ( ( hashfound ) ) 
		  {
		    switch ( ( ilkinfo [controlseqloc ]) ) 
		    {case 12 : 
		      stringwidth = stringwidth + 500 ;
		      break ;
		    case 4 : 
		      stringwidth = stringwidth + 722 ;
		      break ;
		    case 2 : 
		      stringwidth = stringwidth + 778 ;
		      break ;
		    case 5 : 
		      stringwidth = stringwidth + 903 ;
		      break ;
		    case 3 : 
		      stringwidth = stringwidth + 1014 ;
		      break ;
		      default: 
		      stringwidth = stringwidth + charwidth [exbuf [
		      exbufxptr ]];
		      break ;
		    } 
		  } 
		} 
		while ( ( ( exbufptr < exbuflength ) && ( lexclass [exbuf [
		exbufptr ]]== 1 ) ) ) exbufptr = exbufptr + 1 ;
		while ( ( ( exbufptr < exbuflength ) && ( bracelevel > 0 ) && 
		( exbuf [exbufptr ]!= 92 ) ) ) {
		    
		  if ( ( exbuf [exbufptr ]== 125 ) ) 
		  bracelevel = bracelevel - 1 ;
		  else if ( ( exbuf [exbufptr ]== 123 ) ) 
		  bracelevel = bracelevel + 1 ;
		  else stringwidth = stringwidth + charwidth [exbuf [
		  exbufptr ]];
		  exbufptr = exbufptr + 1 ;
		} 
	      } 
	      exbufptr = exbufptr - 1 ;
	    } 
	    else stringwidth = stringwidth + charwidth [123 ];
	  } 
	  else stringwidth = stringwidth + charwidth [123 ];
	} 
	else if ( ( exbuf [exbufptr ]== 125 ) ) 
	{
	  decrbracelevel ( poplit1 ) ;
	  stringwidth = stringwidth + charwidth [125 ];
	} 
	else stringwidth = stringwidth + charwidth [exbuf [exbufptr ]];
	exbufptr = exbufptr + 1 ;
      } 
      checkbracelevel ( poplit1 ) ;
    } 
    pushlitstk ( stringwidth , 0 ) ;
  } 
} 
void 
xwrite ( void ) 
{
  poplitstk ( poplit1 , poptyp1 ) ;
  if ( ( poptyp1 != 1 ) ) 
  printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
  else addoutpool ( poplit1 ) ;
} 
void 
xiskanjistr ( void ) 
{
  /* 10 */ poplitstk ( poplit1 , poptyp1 ) ;
  if ( poptyp1 != 1 ) 
  {
    printwrongstklit ( poplit1 , poptyp1 , 1 ) ;
    pushlitstk ( 0 , 0 ) ;
  } 
  else {
      
    spptr = strstart [poplit1 ];
    spend = strstart [poplit1 + 1 ];
    while ( spptr < spend ) {
	
      if ( strpool [spptr ]> 127 ) 
      {
	pushlitstk ( 1 , 0 ) ;
	goto lab10 ;
      } 
      else {
	  
	spptr = spptr + 1 ;
      } 
    } 
    pushlitstk ( 0 , 0 ) ;
  } 
  lab10: ;
} 
void 
zexecutefn ( hashloc exfnloc ) 
{
  /* 51 */ integer rpoplt1, rpoplt2  ;
  stktype rpoptp1, rpoptp2  ;
  wizfnloc wizptr  ;
	;
#ifdef TRACE
  {
    Fputs ( logfile ,  "execute_fn `" ) ;
  } 
  {
    outpoolstr ( logfile , hashtext [exfnloc ]) ;
  } 
  {
    { putc ( '\'' ,  logfile );  putc ( '\n',  logfile ); }
  } 
#endif /* TRACE */
  switch ( ( fntype [exfnloc ]) ) 
  {case 0 : 
    {
	;
#ifndef NO_BIBTEX_STAT
      executioncount [ilkinfo [exfnloc ]]= executioncount [ilkinfo [
      exfnloc ]]+ 1 ;
#endif /* not NO_BIBTEX_STAT */
      switch ( ( ilkinfo [exfnloc ]) ) 
      {case 0 : 
	xequals () ;
	break ;
      case 1 : 
	xgreaterthan () ;
	break ;
      case 2 : 
	xlessthan () ;
	break ;
      case 3 : 
	xplus () ;
	break ;
      case 4 : 
	xminus () ;
	break ;
      case 5 : 
	xconcatenate () ;
	break ;
      case 6 : 
	xgets () ;
	break ;
      case 7 : 
	xaddperiod () ;
	break ;
      case 8 : 
	{
	  if ( ( ! messwithentries ) ) 
	  bstcantmesswithentriesprint () ;
	  else if ( ( typelist [citeptr ]== undefined ) ) 
	  executefn ( bdefault ) ;
	  else if ( ( typelist [citeptr ]== 0 ) ) 
	  ;
	  else executefn ( typelist [citeptr ]) ;
	} 
	break ;
      case 9 : 
	xchangecase () ;
	break ;
      case 10 : 
	xchrtoint () ;
	break ;
      case 11 : 
	xcite () ;
	break ;
      case 12 : 
	xduplicate () ;
	break ;
      case 13 : 
	xempty () ;
	break ;
      case 14 : 
	xformatname () ;
	break ;
      case 15 : 
	{
	  poplitstk ( poplit1 , poptyp1 ) ;
	  poplitstk ( poplit2 , poptyp2 ) ;
	  poplitstk ( poplit3 , poptyp3 ) ;
	  if ( ( poptyp1 != 2 ) ) 
	  printwrongstklit ( poplit1 , poptyp1 , 2 ) ;
	  else if ( ( poptyp2 != 2 ) ) 
	  printwrongstklit ( poplit2 , poptyp2 , 2 ) ;
	  else if ( ( poptyp3 != 0 ) ) 
	  printwrongstklit ( poplit3 , poptyp3 , 0 ) ;
	  else if ( ( poplit3 > 0 ) ) 
	  executefn ( poplit2 ) ;
	  else executefn ( poplit1 ) ;
	} 
	break ;
      case 16 : 
	xinttochr () ;
	break ;
      case 17 : 
	xinttostr () ;
	break ;
      case 18 : 
	xmissing () ;
	break ;
      case 19 : 
	{
	  outputbblline () ;
	} 
	break ;
      case 20 : 
	xnumnames () ;
	break ;
      case 21 : 
	{
	  poplitstk ( poplit1 , poptyp1 ) ;
	} 
	break ;
      case 22 : 
	xpreamble () ;
	break ;
      case 23 : 
	xpurify () ;
	break ;
      case 24 : 
	xquote () ;
	break ;
      case 25 : 
	{
	  ;
	} 
	break ;
      case 26 : 
	{
	  popwholestack () ;
	} 
	break ;
      case 27 : 
	xsubstring () ;
	break ;
      case 28 : 
	xswap () ;
	break ;
      case 29 : 
	xtextlength () ;
	break ;
      case 30 : 
	xtextprefix () ;
	break ;
      case 31 : 
	{
	  poptopandprint () ;
	} 
	break ;
      case 32 : 
	xtype () ;
	break ;
      case 33 : 
	xwarning () ;
	break ;
      case 34 : 
	{
	  poplitstk ( rpoplt1 , rpoptp1 ) ;
	  poplitstk ( rpoplt2 , rpoptp2 ) ;
	  if ( ( rpoptp1 != 2 ) ) 
	  printwrongstklit ( rpoplt1 , rpoptp1 , 2 ) ;
	  else if ( ( rpoptp2 != 2 ) ) 
	  printwrongstklit ( rpoplt2 , rpoptp2 , 2 ) ;
	  else while ( true ) {
	      
	    executefn ( rpoplt2 ) ;
	    poplitstk ( poplit1 , poptyp1 ) ;
	    if ( ( poptyp1 != 0 ) ) 
	    {
	      printwrongstklit ( poplit1 , poptyp1 , 0 ) ;
	      goto lab51 ;
	    } 
	    else if ( ( poplit1 > 0 ) ) 
	    executefn ( rpoplt1 ) ;
	    else goto lab51 ;
	  } 
	  lab51: ;
	} 
	break ;
      case 35 : 
	xwidth () ;
	break ;
      case 36 : 
	xwrite () ;
	break ;
      case 37 : 
	xiskanjistr () ;
	break ;
	default: 
	{
	  {
	    Fputs ( logfile ,  "Unknown built-in function" ) ;
	    Fputs ( standardoutput ,  "Unknown built-in function" ) ;
	  } 
	  printconfusion () ;
	  longjmp(jmp9998,1) ;
	} 
	break ;
      } 
    } 
    break ;
  case 1 : 
    {
      wizptr = ilkinfo [exfnloc ];
      while ( ( wizfunctions [wizptr ]!= endofdef ) ) {
	  
	if ( ( wizfunctions [wizptr ]!= quotenextfn ) ) 
	executefn ( wizfunctions [wizptr ]) ;
	else {
	    
	  wizptr = wizptr + 1 ;
	  pushlitstk ( wizfunctions [wizptr ], 2 ) ;
	} 
	wizptr = wizptr + 1 ;
      } 
    } 
    break ;
  case 2 : 
    pushlitstk ( ilkinfo [exfnloc ], 0 ) ;
    break ;
  case 3 : 
    pushlitstk ( hashtext [exfnloc ], 1 ) ;
    break ;
  case 4 : 
    {
      if ( ( ! messwithentries ) ) 
      bstcantmesswithentriesprint () ;
      else {
	  
	fieldptr = citeptr * numfields + ilkinfo [exfnloc ];
	if ( ( fieldptr >= maxfields ) ) 
	{
	  {
	    Fputs ( logfile ,  "field_info index is out of range" ) ;
	    Fputs ( standardoutput ,  "field_info index is out of range" ) ;
	  } 
	  printconfusion () ;
	  longjmp(jmp9998,1) ;
	} 
	if ( ( fieldinfo [fieldptr ]== 0 ) ) 
	pushlitstk ( hashtext [exfnloc ], 3 ) ;
	else pushlitstk ( fieldinfo [fieldptr ], 1 ) ;
      } 
    } 
    break ;
  case 5 : 
    {
      if ( ( ! messwithentries ) ) 
      bstcantmesswithentriesprint () ;
      else pushlitstk ( entryints [citeptr * numentints + ilkinfo [exfnloc ]
      ], 0 ) ;
    } 
    break ;
  case 6 : 
    {
      if ( ( ! messwithentries ) ) 
      bstcantmesswithentriesprint () ;
      else {
	  
	strentptr = citeptr * numentstrs + ilkinfo [exfnloc ];
	exbufptr = 0 ;
	while ( ( entrystrs [( strentptr ) * ( entstrsize + 1 ) + ( exbufptr 
	) ]!= 127 ) ) {
	    
	  exbuf [exbufptr ]= entrystrs [( strentptr ) * ( entstrsize + 1 ) 
	  + ( exbufptr ) ];
	  exbufptr = exbufptr + 1 ;
	} 
	exbuflength = exbufptr ;
	addpoolbufandpush () ;
      } 
    } 
    break ;
  case 7 : 
    pushlitstk ( ilkinfo [exfnloc ], 0 ) ;
    break ;
  case 8 : 
    {
      strglbptr = ilkinfo [exfnloc ];
      if ( ( glbstrptr [strglbptr ]> 0 ) ) 
      pushlitstk ( glbstrptr [strglbptr ], 1 ) ;
      else {
	  
	{
	  while ( ( poolptr + glbstrend [strglbptr ]> poolsize ) ) 
	  pooloverflow () ;
	} 
	globchrptr = 0 ;
	while ( ( globchrptr < glbstrend [strglbptr ]) ) {
	    
	  {
	    strpool [poolptr ]= globalstrs [( strglbptr ) * ( globstrsize + 
	    1 ) + ( globchrptr ) ];
	    poolptr = poolptr + 1 ;
	  } 
	  globchrptr = globchrptr + 1 ;
	} 
	pushlitstk ( makestring () , 1 ) ;
      } 
    } 
    break ;
    default: 
    unknwnfunctionclassconfusion () ;
    break ;
  } 
} 
void 
getthetoplevelauxfilename ( void ) 
{
  /* 41 46 */ unsigned char i  ;
  if ( ( ! setencstring ( nil , "EUC" ) ) ) 
  uexit ( 1 ) ;
  initkanji () ;
  parsearguments () ;
  if ( ( isinternalUPTEX () ) ) 
  {
    {register integer for_end; i = 128 ;for_end = 191 ; if ( i <= for_end) 
    do 
      lexclass [i ]= 2 ;
    while ( i++ < for_end ) ;} 
    {register integer for_end; i = 192 ;for_end = 193 ; if ( i <= for_end) 
    do 
      lexclass [i ]= 0 ;
    while ( i++ < for_end ) ;} 
    {register integer for_end; i = 194 ;for_end = 244 ; if ( i <= for_end) 
    do 
      lexclass [i ]= 2 ;
    while ( i++ < for_end ) ;} 
    {register integer for_end; i = 245 ;for_end = 255 ; if ( i <= for_end) 
    do 
      lexclass [i ]= 0 ;
    while ( i++ < for_end ) ;} 
    {register integer for_end; i = 192 ;for_end = 193 ; if ( i <= for_end) 
    do 
      idclass [i ]= 0 ;
    while ( i++ < for_end ) ;} 
    {register integer for_end; i = 245 ;for_end = 255 ; if ( i <= for_end) 
    do 
      idclass [i ]= 0 ;
    while ( i++ < for_end ) ;} 
    {register integer for_end; i = 128 ;for_end = 191 ; if ( i <= for_end) 
    do 
      charwidth [i ]= 257 ;
    while ( i++ < for_end ) ;} 
    {register integer for_end; i = 194 ;for_end = 223 ; if ( i <= for_end) 
    do 
      charwidth [i ]= 771 ;
    while ( i++ < for_end ) ;} 
    {register integer for_end; i = 224 ;for_end = 239 ; if ( i <= for_end) 
    do 
      charwidth [i ]= 514 ;
    while ( i++ < for_end ) ;} 
    {register integer for_end; i = 240 ;for_end = 244 ; if ( i <= for_end) 
    do 
      charwidth [i ]= 257 ;
    while ( i++ < for_end ) ;} 
  } 
  else {
      
    {register integer for_end; i = 128 ;for_end = 160 ; if ( i <= for_end) 
    do 
      lexclass [i ]= 0 ;
    while ( i++ < for_end ) ;} 
    {register integer for_end; i = 161 ;for_end = 254 ; if ( i <= for_end) 
    do 
      lexclass [i ]= 2 ;
    while ( i++ < for_end ) ;} 
    lexclass [255 ]= 0 ;
    {register integer for_end; i = 128 ;for_end = 160 ; if ( i <= for_end) 
    do 
      idclass [i ]= 0 ;
    while ( i++ < for_end ) ;} 
    idclass [255 ]= 0 ;
    lexclass [27 ]= 2 ;
    lexclass [143 ]= 2 ;
    {register integer for_end; i = 161 ;for_end = 254 ; if ( i <= for_end) 
    do 
      charwidth [i ]= 514 ;
    while ( i++ < for_end ) ;} 
    charwidth [143 ]= 0 ;
  } 
  nameoffile = xmallocarray ( ASCIIcode , strlen ( cmdline ( optind ) ) + 5 ) 
  ;
  strcpy ( stringcast ( nameoffile + 1 ) , cmdline ( optind ) ) ;
  auxnamelength = strlen ( stringcast ( nameoffile + 1 ) ) ;
  {
    if ( ( ( auxnamelength + ( strstart [sauxextension + 1 ]- strstart [
    sauxextension ]) > maxint ) || ( auxnamelength + ( strstart [
    slogextension + 1 ]- strstart [slogextension ]) > maxint ) || ( 
    auxnamelength + ( strstart [sbblextension + 1 ]- strstart [
    sbblextension ]) > maxint ) ) ) 
    {
      samtoolongfilenameprint () ;
      goto lab46 ;
    } 
    {
      namelength = auxnamelength ;
      if ( ( namelength < 4 ) || ( strcmp ( stringcast ( nameoffile + 1 + 
      namelength - 4 ) , ".aux" ) != 0 ) ) 
      addextension ( sauxextension ) ;
      else auxnamelength = auxnamelength - 4 ;
      auxptr = 0 ;
      if ( ( ! kpseinnameok ( stringcast ( nameoffile + 1 ) ) || ! aopenin ( 
      auxfile [auxptr ], -1 ) ) ) 
      {
	samwrongfilenameprint () ;
	goto lab46 ;
      } 
      namelength = auxnamelength ;
      addextension ( slogextension ) ;
      if ( ( ! kpseoutnameok ( stringcast ( nameoffile + 1 ) ) || ! aopenout ( 
      logfile ) ) ) 
      {
	samwrongfilenameprint () ;
	goto lab46 ;
      } 
      namelength = auxnamelength ;
      addextension ( sbblextension ) ;
      if ( ( ! kpseoutnameok ( stringcast ( nameoffile + 1 ) ) || ! aopenout ( 
      bblfile ) ) ) 
      {
	samwrongfilenameprint () ;
	goto lab46 ;
      } 
    } 
    {
      namelength = auxnamelength ;
      addextension ( sauxextension ) ;
      nameptr = 1 ;
      while ( ( nameptr <= namelength ) ) {
	  
	buffer [nameptr ]= xord [nameoffile [nameptr ]];
	nameptr = nameptr + 1 ;
      } 
      toplevstr = hashtext [strlookup ( buffer , 1 , auxnamelength , 0 , true 
      ) ];
      auxlist [auxptr ]= hashtext [strlookup ( buffer , 1 , namelength , 3 
      , true ) ];
      if ( ( hashfound ) ) 
      {
	;
#ifdef TRACE
	printauxname () ;
#endif /* TRACE */
	{
	  {
	    Fputs ( logfile ,  "Already encountered auxiliary file" ) ;
	    Fputs ( standardoutput ,  "Already encountered auxiliary file" ) ;
	  } 
	  printconfusion () ;
	  longjmp(jmp9998,1) ;
	} 
      } 
      auxlnstack [auxptr ]= 0 ;
    } 
    goto lab41 ;
  } 
  lab46: uexit ( 1 ) ;
  lab41: ;
} 
void 
auxbibdatacommand ( void ) 
{
  /* 10 */ if ( ( bibseen ) ) 
  {
    auxerrillegalanotherprint ( 0 ) ;
    {
      auxerrprint () ;
      goto lab10 ;
    } 
  } 
  bibseen = true ;
  while ( ( buffer [bufptr2 ]!= 125 ) ) {
      
    bufptr2 = bufptr2 + 1 ;
    if ( ( ! scan2white ( 125 , 44 ) ) ) 
    {
      auxerrnorightbraceprint () ;
      {
	auxerrprint () ;
	goto lab10 ;
      } 
    } 
    if ( ( lexclass [buffer [bufptr2 ]]== 1 ) ) 
    {
      auxerrwhitespaceinargumentprint () ;
      {
	auxerrprint () ;
	goto lab10 ;
      } 
    } 
    if ( ( ( last > bufptr2 + 1 ) && ( buffer [bufptr2 ]== 125 ) ) ) 
    {
      auxerrstuffafterrightbraceprint () ;
      {
	auxerrprint () ;
	goto lab10 ;
      } 
    } 
    {
      if ( ( bibptr == maxbibfiles ) ) 
      {
	BIBXRETALLOCNOSET ( "bib_list" , biblist , strnumber , maxbibfiles , 
	maxbibfiles + MAXBIBFILES ) ;
	BIBXRETALLOCNOSET ( "bib_file" , bibfile , alphafile , maxbibfiles , 
	maxbibfiles + MAXBIBFILES ) ;
	BIBXRETALLOC ( "s_preamble" , spreamble , strnumber , maxbibfiles , 
	maxbibfiles + MAXBIBFILES ) ;
      } 
      biblist [bibptr ]= hashtext [strlookup ( buffer , bufptr1 , ( bufptr2 
      - bufptr1 ) , 6 , true ) ];
      if ( ( hashfound ) ) 
      {
	{
	  Fputs ( logfile ,  "This database file appears more than once: " ) ;
	  Fputs ( standardoutput ,            "This database file appears more than once: " ) ;
	} 
	printbibname () ;
	{
	  auxerrprint () ;
	  goto lab10 ;
	} 
      } 
      startname ( biblist [bibptr ]) ;
      if ( ( ! kpseinnameok ( stringcast ( nameoffile + 1 ) ) || ! aopenin ( 
      bibfile [bibptr ], kpsebibformat ) ) ) 
      {
	{
	  Fputs ( logfile ,  "I couldn't open database file " ) ;
	  Fputs ( standardoutput ,  "I couldn't open database file " ) ;
	} 
	printbibname () ;
	{
	  auxerrprint () ;
	  goto lab10 ;
	} 
      } 
	;
#ifdef TRACE
      {
	outpoolstr ( logfile , biblist [bibptr ]) ;
      } 
      {
	outpoolstr ( logfile , sbibextension ) ;
      } 
      {
	fprintf ( logfile , "%s\n",  " is a bibdata file" ) ;
      } 
#endif /* TRACE */
      bibptr = bibptr + 1 ;
    } 
  } 
  lab10: ;
} 
void 
auxbibstylecommand ( void ) 
{
  /* 10 */ if ( ( bstseen ) ) 
  {
    auxerrillegalanotherprint ( 1 ) ;
    {
      auxerrprint () ;
      goto lab10 ;
    } 
  } 
  bstseen = true ;
  bufptr2 = bufptr2 + 1 ;
  if ( ( ! scan1white ( 125 ) ) ) 
  {
    auxerrnorightbraceprint () ;
    {
      auxerrprint () ;
      goto lab10 ;
    } 
  } 
  if ( ( lexclass [buffer [bufptr2 ]]== 1 ) ) 
  {
    auxerrwhitespaceinargumentprint () ;
    {
      auxerrprint () ;
      goto lab10 ;
    } 
  } 
  if ( ( last > bufptr2 + 1 ) ) 
  {
    auxerrstuffafterrightbraceprint () ;
    {
      auxerrprint () ;
      goto lab10 ;
    } 
  } 
  {
    bststr = hashtext [strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 
    5 , true ) ];
    if ( ( hashfound ) ) 
    {
	;
#ifdef TRACE
      printbstname () ;
#endif /* TRACE */
      {
	{
	  Fputs ( logfile ,  "Already encountered style file" ) ;
	  Fputs ( standardoutput ,  "Already encountered style file" ) ;
	} 
	printconfusion () ;
	longjmp(jmp9998,1) ;
      } 
    } 
    startname ( bststr ) ;
    if ( ( ! kpseinnameok ( stringcast ( nameoffile + 1 ) ) || ! aopenin ( 
    bstfile , kpsebstformat ) ) ) 
    {
      {
	Fputs ( logfile ,  "I couldn't open style file " ) ;
	Fputs ( standardoutput ,  "I couldn't open style file " ) ;
      } 
      printbstname () ;
      bststr = 0 ;
      {
	auxerrprint () ;
	goto lab10 ;
      } 
    } 
    if ( verbose ) 
    {
      {
	Fputs ( logfile ,  "The style file: " ) ;
	Fputs ( standardoutput ,  "The style file: " ) ;
      } 
      printbstname () ;
    } 
    else {
	
      {
	Fputs ( logfile ,  "The style file: " ) ;
      } 
      logprbstname () ;
    } 
  } 
  lab10: ;
} 
void 
auxcitationcommand ( void ) 
{
  /* 23 10 */ citationseen = true ;
  while ( ( buffer [bufptr2 ]!= 125 ) ) {
      
    bufptr2 = bufptr2 + 1 ;
    if ( ( ! scan2white ( 125 , 44 ) ) ) 
    {
      auxerrnorightbraceprint () ;
      {
	auxerrprint () ;
	goto lab10 ;
      } 
    } 
    if ( ( lexclass [buffer [bufptr2 ]]== 1 ) ) 
    {
      auxerrwhitespaceinargumentprint () ;
      {
	auxerrprint () ;
	goto lab10 ;
      } 
    } 
    if ( ( ( last > bufptr2 + 1 ) && ( buffer [bufptr2 ]== 125 ) ) ) 
    {
      auxerrstuffafterrightbraceprint () ;
      {
	auxerrprint () ;
	goto lab10 ;
      } 
    } 
    {
	;
#ifdef TRACE
      {
	outtoken ( logfile ) ;
      } 
      {
	Fputs ( logfile ,  " cite key encountered" ) ;
      } 
#endif /* TRACE */
      {
	if ( ( ( bufptr2 - bufptr1 ) == 1 ) ) {
	    
	  if ( ( buffer [bufptr1 ]== 42 ) ) 
	  {
	;
#ifdef TRACE
	    {
	      fprintf ( logfile , "%s\n",  "---entire database to be included" ) ;
	    } 
#endif /* TRACE */
	    if ( ( allentries ) ) 
	    {
	      {
		fprintf ( logfile , "%s\n",  "Multiple inclusions of entire database" ) 
		;
		fprintf ( standardoutput , "%s\n",                  "Multiple inclusions of entire database" ) ;
	      } 
	      {
		auxerrprint () ;
		goto lab10 ;
	      } 
	    } 
	    else {
		
	      allentries = true ;
	      allmarker = citeptr ;
	      goto lab23 ;
	    } 
	  } 
	} 
      } 
      tmpptr = bufptr1 ;
      while ( ( tmpptr < bufptr2 ) ) {
	  
	exbuf [tmpptr ]= buffer [tmpptr ];
	tmpptr = tmpptr + 1 ;
      } 
      lowercase ( exbuf , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
      lcciteloc = strlookup ( exbuf , bufptr1 , ( bufptr2 - bufptr1 ) , 10 , 
      true ) ;
      if ( ( hashfound ) ) 
      {
	;
#ifdef TRACE
	{
	  fprintf ( logfile , "%s\n",  " previously" ) ;
	} 
#endif /* TRACE */
	dummyloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 9 , 
	false ) ;
	if ( ( ! hashfound ) ) 
	{
	  {
	    Fputs ( logfile ,  "Case mismatch error between cite keys " ) ;
	    Fputs ( standardoutput ,  "Case mismatch error between cite keys "             ) ;
	  } 
	  printatoken () ;
	  {
	    Fputs ( logfile ,  " and " ) ;
	    Fputs ( standardoutput ,  " and " ) ;
	  } 
	  printapoolstr ( citelist [ilkinfo [ilkinfo [lcciteloc ]]]) ;
	  printanewline () ;
	  {
	    auxerrprint () ;
	    goto lab10 ;
	  } 
	} 
      } 
      else {
	  
	;
#ifdef TRACE
	{
	  putc ('\n',  logfile );
	} 
#endif /* TRACE */
	citeloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 9 , 
	true ) ;
	if ( ( hashfound ) ) 
	hashciteconfusion () ;
	checkciteoverflow ( citeptr ) ;
	citelist [citeptr ]= hashtext [citeloc ];
	ilkinfo [citeloc ]= citeptr ;
	ilkinfo [lcciteloc ]= citeloc ;
	citeptr = citeptr + 1 ;
      } 
    } 
    lab23: ;
  } 
  lab10: ;
} 
void 
auxinputcommand ( void ) 
{
  /* 10 */ boolean auxextensionok  ;
  bufptr2 = bufptr2 + 1 ;
  if ( ( ! scan1white ( 125 ) ) ) 
  {
    auxerrnorightbraceprint () ;
    {
      auxerrprint () ;
      goto lab10 ;
    } 
  } 
  if ( ( lexclass [buffer [bufptr2 ]]== 1 ) ) 
  {
    auxerrwhitespaceinargumentprint () ;
    {
      auxerrprint () ;
      goto lab10 ;
    } 
  } 
  if ( ( last > bufptr2 + 1 ) ) 
  {
    auxerrstuffafterrightbraceprint () ;
    {
      auxerrprint () ;
      goto lab10 ;
    } 
  } 
  {
    auxptr = auxptr + 1 ;
    if ( ( auxptr == auxstacksize ) ) 
    {
      printatoken () ;
      {
	Fputs ( logfile ,  ": " ) ;
	Fputs ( standardoutput ,  ": " ) ;
      } 
      {
	printoverflow () ;
	{
	  fprintf ( logfile , "%s%ld\n",  "auxiliary file depth " , (long)auxstacksize ) ;
	  fprintf ( standardoutput , "%s%ld\n",  "auxiliary file depth " , (long)auxstacksize ) 
	  ;
	} 
	longjmp(jmp9998,1) ;
      } 
    } 
    auxextensionok = true ;
    if ( ( ( bufptr2 - bufptr1 ) < ( strstart [sauxextension + 1 ]- strstart 
    [sauxextension ]) ) ) 
    auxextensionok = false ;
    else if ( ( ! streqbuf ( sauxextension , buffer , bufptr2 - ( strstart [
    sauxextension + 1 ]- strstart [sauxextension ]) , ( strstart [
    sauxextension + 1 ]- strstart [sauxextension ]) ) ) ) 
    auxextensionok = false ;
    if ( ( ! auxextensionok ) ) 
    {
      printatoken () ;
      {
	Fputs ( logfile ,  " has a wrong extension" ) ;
	Fputs ( standardoutput ,  " has a wrong extension" ) ;
      } 
      auxptr = auxptr - 1 ;
      {
	auxerrprint () ;
	goto lab10 ;
      } 
    } 
    auxlist [auxptr ]= hashtext [strlookup ( buffer , bufptr1 , ( bufptr2 - 
    bufptr1 ) , 3 , true ) ];
    if ( ( hashfound ) ) 
    {
      {
	Fputs ( logfile ,  "Already encountered file " ) ;
	Fputs ( standardoutput ,  "Already encountered file " ) ;
      } 
      printauxname () ;
      auxptr = auxptr - 1 ;
      {
	auxerrprint () ;
	goto lab10 ;
      } 
    } 
    {
      startname ( auxlist [auxptr ]) ;
      nameptr = namelength + 1 ;
      nameoffile [nameptr ]= 0 ;
      if ( ( ! kpseinnameok ( stringcast ( nameoffile + 1 ) ) || ! aopenin ( 
      auxfile [auxptr ], -1 ) ) ) 
      {
	{
	  Fputs ( logfile ,  "I couldn't open auxiliary file " ) ;
	  Fputs ( standardoutput ,  "I couldn't open auxiliary file " ) ;
	} 
	printauxname () ;
	auxptr = auxptr - 1 ;
	{
	  auxerrprint () ;
	  goto lab10 ;
	} 
      } 
      {
	fprintf ( logfile , "%s%ld%s",  "A level-" , (long)auxptr , " auxiliary file: " ) ;
	fprintf ( standardoutput , "%s%ld%s",  "A level-" , (long)auxptr , " auxiliary file: " ) ;
      } 
      printauxname () ;
      auxlnstack [auxptr ]= 0 ;
    } 
  } 
  lab10: ;
} 
void 
poptheauxstack ( void ) 
{
  aclose ( auxfile [auxptr ]) ;
  if ( ( auxptr == 0 ) ) 
  {lab31=1; return;}
  else auxptr = auxptr - 1 ;
} 
void 
getauxcommandandprocess ( void ) 
{
  /* 10 */ bufptr2 = 0 ;
  if ( ( ! scan1 ( 123 ) ) ) 
  goto lab10 ;
  commandnum = ilkinfo [strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) 
  , 2 , false ) ];
  if ( ( hashfound ) ) 
  switch ( ( commandnum ) ) 
  {case 0 : 
    auxbibdatacommand () ;
    break ;
  case 1 : 
    auxbibstylecommand () ;
    break ;
  case 2 : 
    auxcitationcommand () ;
    break ;
  case 3 : 
    auxinputcommand () ;
    break ;
    default: 
    {
      {
	Fputs ( logfile ,  "Unknown auxiliary-file command" ) ;
	Fputs ( standardoutput ,  "Unknown auxiliary-file command" ) ;
      } 
      printconfusion () ;
      longjmp(jmp9998,1) ;
    } 
    break ;
  } 
  lab10: ;
} 
void 
lastcheckforauxerrors ( void ) 
{
  numcites = citeptr ;
  numbibfiles = bibptr ;
  if ( ( ! citationseen ) ) 
  {
    auxend1errprint () ;
    {
      Fputs ( logfile ,  "\\citation commands" ) ;
      Fputs ( standardoutput ,  "\\citation commands" ) ;
    } 
    auxend2errprint () ;
  } 
  else if ( ( ( numcites == 0 ) && ( ! allentries ) ) ) 
  {
    auxend1errprint () ;
    {
      Fputs ( logfile ,  "cite keys" ) ;
      Fputs ( standardoutput ,  "cite keys" ) ;
    } 
    auxend2errprint () ;
  } 
  if ( ( ! bibseen ) ) 
  {
    auxend1errprint () ;
    {
      Fputs ( logfile ,  "\\bibdata command" ) ;
      Fputs ( standardoutput ,  "\\bibdata command" ) ;
    } 
    auxend2errprint () ;
  } 
  else if ( ( numbibfiles == 0 ) ) 
  {
    auxend1errprint () ;
    {
      Fputs ( logfile ,  "database files" ) ;
      Fputs ( standardoutput ,  "database files" ) ;
    } 
    auxend2errprint () ;
  } 
  if ( ( ! bstseen ) ) 
  {
    auxend1errprint () ;
    {
      Fputs ( logfile ,  "\\bibstyle command" ) ;
      Fputs ( standardoutput ,  "\\bibstyle command" ) ;
    } 
    auxend2errprint () ;
  } 
  else if ( ( bststr == 0 ) ) 
  {
    auxend1errprint () ;
    {
      Fputs ( logfile ,  "style file" ) ;
      Fputs ( standardoutput ,  "style file" ) ;
    } 
    auxend2errprint () ;
  } 
} 
void 
bstentrycommand ( void ) 
{
  /* 10 */ if ( ( entryseen ) ) 
  {
    {
      Fputs ( logfile ,  "Illegal, another entry command" ) ;
      Fputs ( standardoutput ,  "Illegal, another entry command" ) ;
    } 
    {
      bsterrprintandlookforblankline () ;
      goto lab10 ;
    } 
  } 
  entryseen = true ;
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "entry" ) ;
	  Fputs ( standardoutput ,  "entry" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    {
      if ( ( buffer [bufptr2 ]!= 123 ) ) 
      {
	bstleftbraceprint () ;
	{
	  {
	    Fputs ( logfile ,  "entry" ) ;
	    Fputs ( standardoutput ,  "entry" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
      bufptr2 = bufptr2 + 1 ;
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "entry" ) ;
	    Fputs ( standardoutput ,  "entry" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    while ( ( buffer [bufptr2 ]!= 125 ) ) {
	
      {
	scanidentifier ( 125 , 37 , 37 ) ;
	if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
	;
	else {
	    
	  bstidprint () ;
	  {
	    {
	      Fputs ( logfile ,  "entry" ) ;
	      Fputs ( standardoutput ,  "entry" ) ;
	    } 
	    {
	      bsterrprintandlookforblankline () ;
	      goto lab10 ;
	    } 
	  } 
	} 
      } 
      {
	;
#ifdef TRACE
	{
	  outtoken ( logfile ) ;
	} 
	{
	  fprintf ( logfile , "%s\n",  " is a field" ) ;
	} 
#endif /* TRACE */
	lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
	fnloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 11 , 
	true ) ;
	{
	  if ( ( hashfound ) ) 
	  {
	    alreadyseenfunctionprint ( fnloc ) ;
	    goto lab10 ;
	  } 
	} 
	fntype [fnloc ]= 4 ;
	ilkinfo [fnloc ]= numfields ;
	numfields = numfields + 1 ;
      } 
      {
	if ( ( ! eatbstwhitespace () ) ) 
	{
	  eatbstprint () ;
	  {
	    {
	      Fputs ( logfile ,  "entry" ) ;
	      Fputs ( standardoutput ,  "entry" ) ;
	    } 
	    {
	      bsterrprintandlookforblankline () ;
	      goto lab10 ;
	    } 
	  } 
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "entry" ) ;
	  Fputs ( standardoutput ,  "entry" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  if ( ( numfields == numpredefinedfields ) ) 
  {
    {
      Fputs ( logfile ,  "Warning--I didn't find any fields" ) ;
      Fputs ( standardoutput ,  "Warning--I didn't find any fields" ) ;
    } 
    bstwarnprint () ;
  } 
  {
    {
      if ( ( buffer [bufptr2 ]!= 123 ) ) 
      {
	bstleftbraceprint () ;
	{
	  {
	    Fputs ( logfile ,  "entry" ) ;
	    Fputs ( standardoutput ,  "entry" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
      bufptr2 = bufptr2 + 1 ;
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "entry" ) ;
	    Fputs ( standardoutput ,  "entry" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    while ( ( buffer [bufptr2 ]!= 125 ) ) {
	
      {
	scanidentifier ( 125 , 37 , 37 ) ;
	if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
	;
	else {
	    
	  bstidprint () ;
	  {
	    {
	      Fputs ( logfile ,  "entry" ) ;
	      Fputs ( standardoutput ,  "entry" ) ;
	    } 
	    {
	      bsterrprintandlookforblankline () ;
	      goto lab10 ;
	    } 
	  } 
	} 
      } 
      {
	;
#ifdef TRACE
	{
	  outtoken ( logfile ) ;
	} 
	{
	  fprintf ( logfile , "%s\n",  " is an integer entry-variable" ) ;
	} 
#endif /* TRACE */
	lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
	fnloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 11 , 
	true ) ;
	{
	  if ( ( hashfound ) ) 
	  {
	    alreadyseenfunctionprint ( fnloc ) ;
	    goto lab10 ;
	  } 
	} 
	fntype [fnloc ]= 5 ;
	ilkinfo [fnloc ]= numentints ;
	numentints = numentints + 1 ;
      } 
      {
	if ( ( ! eatbstwhitespace () ) ) 
	{
	  eatbstprint () ;
	  {
	    {
	      Fputs ( logfile ,  "entry" ) ;
	      Fputs ( standardoutput ,  "entry" ) ;
	    } 
	    {
	      bsterrprintandlookforblankline () ;
	      goto lab10 ;
	    } 
	  } 
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "entry" ) ;
	  Fputs ( standardoutput ,  "entry" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    {
      if ( ( buffer [bufptr2 ]!= 123 ) ) 
      {
	bstleftbraceprint () ;
	{
	  {
	    Fputs ( logfile ,  "entry" ) ;
	    Fputs ( standardoutput ,  "entry" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
      bufptr2 = bufptr2 + 1 ;
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "entry" ) ;
	    Fputs ( standardoutput ,  "entry" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    while ( ( buffer [bufptr2 ]!= 125 ) ) {
	
      {
	scanidentifier ( 125 , 37 , 37 ) ;
	if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
	;
	else {
	    
	  bstidprint () ;
	  {
	    {
	      Fputs ( logfile ,  "entry" ) ;
	      Fputs ( standardoutput ,  "entry" ) ;
	    } 
	    {
	      bsterrprintandlookforblankline () ;
	      goto lab10 ;
	    } 
	  } 
	} 
      } 
      {
	;
#ifdef TRACE
	{
	  outtoken ( logfile ) ;
	} 
	{
	  fprintf ( logfile , "%s\n",  " is a string entry-variable" ) ;
	} 
#endif /* TRACE */
	lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
	fnloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 11 , 
	true ) ;
	{
	  if ( ( hashfound ) ) 
	  {
	    alreadyseenfunctionprint ( fnloc ) ;
	    goto lab10 ;
	  } 
	} 
	fntype [fnloc ]= 6 ;
	ilkinfo [fnloc ]= numentstrs ;
	numentstrs = numentstrs + 1 ;
      } 
      {
	if ( ( ! eatbstwhitespace () ) ) 
	{
	  eatbstprint () ;
	  {
	    {
	      Fputs ( logfile ,  "entry" ) ;
	      Fputs ( standardoutput ,  "entry" ) ;
	    } 
	    {
	      bsterrprintandlookforblankline () ;
	      goto lab10 ;
	    } 
	  } 
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  lab10: ;
} 
boolean 
badargumenttoken ( void ) 
{
  /* 10 */ register boolean Result; Result = true ;
  lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
  fnloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 11 , false ) 
  ;
  if ( ( ! hashfound ) ) 
  {
    printatoken () ;
    {
      {
	Fputs ( logfile ,  " is an unknown function" ) ;
	Fputs ( standardoutput ,  " is an unknown function" ) ;
      } 
      {
	bsterrprintandlookforblankline () ;
	goto lab10 ;
      } 
    } 
  } 
  else if ( ( ( fntype [fnloc ]!= 0 ) && ( fntype [fnloc ]!= 1 ) ) ) 
  {
    printatoken () ;
    {
      Fputs ( logfile ,  " has bad function type " ) ;
      Fputs ( standardoutput ,  " has bad function type " ) ;
    } 
    printfnclass ( fnloc ) ;
    {
      bsterrprintandlookforblankline () ;
      goto lab10 ;
    } 
  } 
  Result = false ;
  lab10: ;
  return Result ;
} 
void 
bstexecutecommand ( void ) 
{
  /* 10 */ if ( ( ! readseen ) ) 
  {
    {
      Fputs ( logfile ,  "Illegal, execute command before read command" ) ;
      Fputs ( standardoutput ,  "Illegal, execute command before read command"       ) ;
    } 
    {
      bsterrprintandlookforblankline () ;
      goto lab10 ;
    } 
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "execute" ) ;
	  Fputs ( standardoutput ,  "execute" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    if ( ( buffer [bufptr2 ]!= 123 ) ) 
    {
      bstleftbraceprint () ;
      {
	{
	  Fputs ( logfile ,  "execute" ) ;
	  Fputs ( standardoutput ,  "execute" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "execute" ) ;
	  Fputs ( standardoutput ,  "execute" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    scanidentifier ( 125 , 37 , 37 ) ;
    if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
    ;
    else {
	
      bstidprint () ;
      {
	{
	  Fputs ( logfile ,  "execute" ) ;
	  Fputs ( standardoutput ,  "execute" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
	;
#ifdef TRACE
    {
      outtoken ( logfile ) ;
    } 
    {
      fprintf ( logfile , "%s\n",  " is a to be executed function" ) ;
    } 
#endif /* TRACE */
    if ( ( badargumenttoken () ) ) 
    goto lab10 ;
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "execute" ) ;
	  Fputs ( standardoutput ,  "execute" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    if ( ( buffer [bufptr2 ]!= 125 ) ) 
    {
      bstrightbraceprint () ;
      {
	{
	  Fputs ( logfile ,  "execute" ) ;
	  Fputs ( standardoutput ,  "execute" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  {
    initcommandexecution () ;
    messwithentries = false ;
    executefn ( fnloc ) ;
    checkcommandexecution () ;
  } 
  lab10: ;
} 
void 
bstfunctioncommand ( void ) 
{
  /* 10 */ {
      
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "function" ) ;
	  Fputs ( standardoutput ,  "function" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    {
      if ( ( buffer [bufptr2 ]!= 123 ) ) 
      {
	bstleftbraceprint () ;
	{
	  {
	    Fputs ( logfile ,  "function" ) ;
	    Fputs ( standardoutput ,  "function" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
      bufptr2 = bufptr2 + 1 ;
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "function" ) ;
	    Fputs ( standardoutput ,  "function" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    {
      scanidentifier ( 125 , 37 , 37 ) ;
      if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
      ;
      else {
	  
	bstidprint () ;
	{
	  {
	    Fputs ( logfile ,  "function" ) ;
	    Fputs ( standardoutput ,  "function" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    {
	;
#ifdef TRACE
      {
	outtoken ( logfile ) ;
      } 
      {
	fprintf ( logfile , "%s\n",  " is a wizard-defined function" ) ;
      } 
#endif /* TRACE */
      lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
      wizloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 11 , 
      true ) ;
      {
	if ( ( hashfound ) ) 
	{
	  alreadyseenfunctionprint ( wizloc ) ;
	  goto lab10 ;
	} 
      } 
      fntype [wizloc ]= 1 ;
      if ( ( hashtext [wizloc ]== sdefault ) ) 
      bdefault = wizloc ;
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "function" ) ;
	    Fputs ( standardoutput ,  "function" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    {
      if ( ( buffer [bufptr2 ]!= 125 ) ) 
      {
	bstrightbraceprint () ;
	{
	  {
	    Fputs ( logfile ,  "function" ) ;
	    Fputs ( standardoutput ,  "function" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
      bufptr2 = bufptr2 + 1 ;
    } 
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "function" ) ;
	  Fputs ( standardoutput ,  "function" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    if ( ( buffer [bufptr2 ]!= 123 ) ) 
    {
      bstleftbraceprint () ;
      {
	{
	  Fputs ( logfile ,  "function" ) ;
	  Fputs ( standardoutput ,  "function" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  scanfndef ( wizloc ) ;
  lab10: ;
} 
void 
bstintegerscommand ( void ) 
{
  /* 10 */ {
      
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "integers" ) ;
	  Fputs ( standardoutput ,  "integers" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    if ( ( buffer [bufptr2 ]!= 123 ) ) 
    {
      bstleftbraceprint () ;
      {
	{
	  Fputs ( logfile ,  "integers" ) ;
	  Fputs ( standardoutput ,  "integers" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "integers" ) ;
	  Fputs ( standardoutput ,  "integers" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  while ( ( buffer [bufptr2 ]!= 125 ) ) {
      
    {
      scanidentifier ( 125 , 37 , 37 ) ;
      if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
      ;
      else {
	  
	bstidprint () ;
	{
	  {
	    Fputs ( logfile ,  "integers" ) ;
	    Fputs ( standardoutput ,  "integers" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    {
	;
#ifdef TRACE
      {
	outtoken ( logfile ) ;
      } 
      {
	fprintf ( logfile , "%s\n",  " is an integer global-variable" ) ;
      } 
#endif /* TRACE */
      lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
      fnloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 11 , true 
      ) ;
      {
	if ( ( hashfound ) ) 
	{
	  alreadyseenfunctionprint ( fnloc ) ;
	  goto lab10 ;
	} 
      } 
      fntype [fnloc ]= 7 ;
      ilkinfo [fnloc ]= 0 ;
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "integers" ) ;
	    Fputs ( standardoutput ,  "integers" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
  } 
  bufptr2 = bufptr2 + 1 ;
  lab10: ;
} 
void 
bstiteratecommand ( void ) 
{
  /* 10 */ if ( ( ! readseen ) ) 
  {
    {
      Fputs ( logfile ,  "Illegal, iterate command before read command" ) ;
      Fputs ( standardoutput ,  "Illegal, iterate command before read command"       ) ;
    } 
    {
      bsterrprintandlookforblankline () ;
      goto lab10 ;
    } 
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "iterate" ) ;
	  Fputs ( standardoutput ,  "iterate" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    if ( ( buffer [bufptr2 ]!= 123 ) ) 
    {
      bstleftbraceprint () ;
      {
	{
	  Fputs ( logfile ,  "iterate" ) ;
	  Fputs ( standardoutput ,  "iterate" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "iterate" ) ;
	  Fputs ( standardoutput ,  "iterate" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    scanidentifier ( 125 , 37 , 37 ) ;
    if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
    ;
    else {
	
      bstidprint () ;
      {
	{
	  Fputs ( logfile ,  "iterate" ) ;
	  Fputs ( standardoutput ,  "iterate" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
	;
#ifdef TRACE
    {
      outtoken ( logfile ) ;
    } 
    {
      fprintf ( logfile , "%s\n",  " is a to be iterated function" ) ;
    } 
#endif /* TRACE */
    if ( ( badargumenttoken () ) ) 
    goto lab10 ;
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "iterate" ) ;
	  Fputs ( standardoutput ,  "iterate" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    if ( ( buffer [bufptr2 ]!= 125 ) ) 
    {
      bstrightbraceprint () ;
      {
	{
	  Fputs ( logfile ,  "iterate" ) ;
	  Fputs ( standardoutput ,  "iterate" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  {
    initcommandexecution () ;
    messwithentries = true ;
    sortciteptr = 0 ;
    while ( ( sortciteptr < numcites ) ) {
	
      citeptr = citeinfo [sortciteptr ];
	;
#ifdef TRACE
      {
	outpoolstr ( logfile , hashtext [fnloc ]) ;
      } 
      {
	Fputs ( logfile ,  " to be iterated on " ) ;
      } 
      {
	outpoolstr ( logfile , citelist [citeptr ]) ;
      } 
      {
	putc ('\n',  logfile );
      } 
#endif /* TRACE */
      executefn ( fnloc ) ;
      checkcommandexecution () ;
      sortciteptr = sortciteptr + 1 ;
    } 
  } 
  lab10: ;
} 
void 
bstmacrocommand ( void ) 
{
  /* 10 */ if ( ( readseen ) ) 
  {
    {
      Fputs ( logfile ,  "Illegal, macro command after read command" ) ;
      Fputs ( standardoutput ,  "Illegal, macro command after read command" ) ;
    } 
    {
      bsterrprintandlookforblankline () ;
      goto lab10 ;
    } 
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "macro" ) ;
	  Fputs ( standardoutput ,  "macro" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    {
      if ( ( buffer [bufptr2 ]!= 123 ) ) 
      {
	bstleftbraceprint () ;
	{
	  {
	    Fputs ( logfile ,  "macro" ) ;
	    Fputs ( standardoutput ,  "macro" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
      bufptr2 = bufptr2 + 1 ;
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "macro" ) ;
	    Fputs ( standardoutput ,  "macro" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    {
      scanidentifier ( 125 , 37 , 37 ) ;
      if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
      ;
      else {
	  
	bstidprint () ;
	{
	  {
	    Fputs ( logfile ,  "macro" ) ;
	    Fputs ( standardoutput ,  "macro" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    {
	;
#ifdef TRACE
      {
	outtoken ( logfile ) ;
      } 
      {
	fprintf ( logfile , "%s\n",  " is a macro" ) ;
      } 
#endif /* TRACE */
      lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
      macronameloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 13 
      , true ) ;
      if ( ( hashfound ) ) 
      {
	printatoken () ;
	{
	  {
	    Fputs ( logfile ,  " is already defined as a macro" ) ;
	    Fputs ( standardoutput ,  " is already defined as a macro" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
      ilkinfo [macronameloc ]= hashtext [macronameloc ];
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "macro" ) ;
	    Fputs ( standardoutput ,  "macro" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    {
      if ( ( buffer [bufptr2 ]!= 125 ) ) 
      {
	bstrightbraceprint () ;
	{
	  {
	    Fputs ( logfile ,  "macro" ) ;
	    Fputs ( standardoutput ,  "macro" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
      bufptr2 = bufptr2 + 1 ;
    } 
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "macro" ) ;
	  Fputs ( standardoutput ,  "macro" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    {
      if ( ( buffer [bufptr2 ]!= 123 ) ) 
      {
	bstleftbraceprint () ;
	{
	  {
	    Fputs ( logfile ,  "macro" ) ;
	    Fputs ( standardoutput ,  "macro" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
      bufptr2 = bufptr2 + 1 ;
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "macro" ) ;
	    Fputs ( standardoutput ,  "macro" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    if ( ( buffer [bufptr2 ]!= 34 ) ) 
    {
      {
	fprintf ( logfile , "%s%c%s",  "A macro definition must be " , xchr [34 ],         "-delimited" ) ;
	fprintf ( standardoutput , "%s%c%s",  "A macro definition must be " , xchr [34 ],         "-delimited" ) ;
      } 
      {
	bsterrprintandlookforblankline () ;
	goto lab10 ;
      } 
    } 
    {
      bufptr2 = bufptr2 + 1 ;
      if ( ( ! scan1 ( 34 ) ) ) 
      {
	{
	  fprintf ( logfile , "%s%c%s",  "There's no `" , xchr [34 ],           "' to end macro definition" ) ;
	  fprintf ( standardoutput , "%s%c%s",  "There's no `" , xchr [34 ],           "' to end macro definition" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
	;
#ifdef TRACE
      {
	putc ( '"' ,  logfile );
      } 
      {
	outtoken ( logfile ) ;
      } 
      {
	putc ( '"' ,  logfile );
      } 
      {
	fprintf ( logfile , "%s\n",  " is a macro string" ) ;
      } 
#endif /* TRACE */
      macrodefloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 0 , 
      true ) ;
      fntype [macrodefloc ]= 3 ;
      ilkinfo [macronameloc ]= hashtext [macrodefloc ];
      bufptr2 = bufptr2 + 1 ;
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "macro" ) ;
	    Fputs ( standardoutput ,  "macro" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    {
      if ( ( buffer [bufptr2 ]!= 125 ) ) 
      {
	bstrightbraceprint () ;
	{
	  {
	    Fputs ( logfile ,  "macro" ) ;
	    Fputs ( standardoutput ,  "macro" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
      bufptr2 = bufptr2 + 1 ;
    } 
  } 
  lab10: ;
} 
void 
getbibcommandorentryandprocess ( void ) 
{
  /* 22 26 15 10 */ atbibcommand = false ;
  while ( ( ! scan1 ( 64 ) ) ) {
      
    if ( ( ! inputln ( bibfile [bibptr ]) ) ) 
    goto lab10 ;
    biblinenum = biblinenum + 1 ;
    bufptr2 = 0 ;
  } 
  {
    if ( ( buffer [bufptr2 ]!= 64 ) ) 
    {
      {
	fprintf ( logfile , "%s%c%s",  "An \"" , xchr [64 ], "\" disappeared" ) ;
	fprintf ( standardoutput , "%s%c%s",  "An \"" , xchr [64 ], "\" disappeared" ) ;
      } 
      printconfusion () ;
      longjmp(jmp9998,1) ;
    } 
    bufptr2 = bufptr2 + 1 ;
    {
      if ( ( ! eatbibwhitespace () ) ) 
      {
	eatbibprint () ;
	goto lab10 ;
      } 
    } 
    scanidentifier ( 123 , 40 , 40 ) ;
    {
      if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
      ;
      else {
	  
	bibidprint () ;
	{
	  {
	    Fputs ( logfile ,  "an entry type" ) ;
	    Fputs ( standardoutput ,  "an entry type" ) ;
	  } 
	  biberrprint () ;
	  goto lab10 ;
	} 
      } 
    } 
	;
#ifdef TRACE
    {
      outtoken ( logfile ) ;
    } 
    {
      fprintf ( logfile , "%s\n",  " is an entry type or a database-file command" ) ;
    } 
#endif /* TRACE */
    lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
    commandnum = ilkinfo [strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 
    ) , 12 , false ) ];
    if ( ( hashfound ) ) 
    {
      atbibcommand = true ;
      switch ( ( commandnum ) ) 
      {case 0 : 
	{
	  goto lab10 ;
	} 
	break ;
      case 1 : 
	{
	  if ( ( preambleptr == maxbibfiles ) ) 
	  {
	    BIBXRETALLOCNOSET ( "bib_list" , biblist , strnumber , maxbibfiles 
	    , maxbibfiles + MAXBIBFILES ) ;
	    BIBXRETALLOCNOSET ( "bib_file" , bibfile , alphafile , maxbibfiles 
	    , maxbibfiles + MAXBIBFILES ) ;
	    BIBXRETALLOC ( "s_preamble" , spreamble , strnumber , maxbibfiles 
	    , maxbibfiles + MAXBIBFILES ) ;
	  } 
	  {
	    if ( ( ! eatbibwhitespace () ) ) 
	    {
	      eatbibprint () ;
	      goto lab10 ;
	    } 
	  } 
	  if ( ( buffer [bufptr2 ]== 123 ) ) 
	  rightouterdelim = 125 ;
	  else if ( ( buffer [bufptr2 ]== 40 ) ) 
	  rightouterdelim = 41 ;
	  else {
	      
	    biboneoftwoprint ( 123 , 40 ) ;
	    goto lab10 ;
	  } 
	  bufptr2 = bufptr2 + 1 ;
	  {
	    if ( ( ! eatbibwhitespace () ) ) 
	    {
	      eatbibprint () ;
	      goto lab10 ;
	    } 
	  } 
	  storefield = true ;
	  if ( ( ! scanandstorethefieldvalueandeatwhite () ) ) 
	  goto lab10 ;
	  if ( ( buffer [bufptr2 ]!= rightouterdelim ) ) 
	  {
	    {
	      fprintf ( logfile , "%s%c%s",  "Missing \"" , xchr [rightouterdelim ],               "\" in preamble command" ) ;
	      fprintf ( standardoutput , "%s%c%s",  "Missing \"" , xchr [rightouterdelim ]              , "\" in preamble command" ) ;
	    } 
	    biberrprint () ;
	    goto lab10 ;
	  } 
	  bufptr2 = bufptr2 + 1 ;
	  goto lab10 ;
	} 
	break ;
      case 2 : 
	{
	  {
	    if ( ( ! eatbibwhitespace () ) ) 
	    {
	      eatbibprint () ;
	      goto lab10 ;
	    } 
	  } 
	  {
	    if ( ( buffer [bufptr2 ]== 123 ) ) 
	    rightouterdelim = 125 ;
	    else if ( ( buffer [bufptr2 ]== 40 ) ) 
	    rightouterdelim = 41 ;
	    else {
		
	      biboneoftwoprint ( 123 , 40 ) ;
	      goto lab10 ;
	    } 
	    bufptr2 = bufptr2 + 1 ;
	    {
	      if ( ( ! eatbibwhitespace () ) ) 
	      {
		eatbibprint () ;
		goto lab10 ;
	      } 
	    } 
	    scanidentifier ( 61 , 61 , 61 ) ;
	    {
	      if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
	      ;
	      else {
		  
		bibidprint () ;
		{
		  {
		    Fputs ( logfile ,  "a string name" ) ;
		    Fputs ( standardoutput ,  "a string name" ) ;
		  } 
		  biberrprint () ;
		  goto lab10 ;
		} 
	      } 
	    } 
	    {
	;
#ifdef TRACE
	      {
		outtoken ( logfile ) ;
	      } 
	      {
		fprintf ( logfile , "%s\n",  " is a database-defined macro" ) ;
	      } 
#endif /* TRACE */
	      lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
	      curmacroloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 
	      ) , 13 , true ) ;
	      ilkinfo [curmacroloc ]= hashtext [curmacroloc ];
	    } 
	  } 
	  {
	    if ( ( ! eatbibwhitespace () ) ) 
	    {
	      eatbibprint () ;
	      goto lab10 ;
	    } 
	  } 
	  {
	    if ( ( buffer [bufptr2 ]!= 61 ) ) 
	    {
	      bibequalssignprint () ;
	      goto lab10 ;
	    } 
	    bufptr2 = bufptr2 + 1 ;
	    {
	      if ( ( ! eatbibwhitespace () ) ) 
	      {
		eatbibprint () ;
		goto lab10 ;
	      } 
	    } 
	    storefield = true ;
	    if ( ( ! scanandstorethefieldvalueandeatwhite () ) ) 
	    goto lab10 ;
	    if ( ( buffer [bufptr2 ]!= rightouterdelim ) ) 
	    {
	      {
		fprintf ( logfile , "%s%c%s",  "Missing \"" , xchr [rightouterdelim ],                 "\" in string command" ) ;
		fprintf ( standardoutput , "%s%c%s",  "Missing \"" , xchr [rightouterdelim                 ], "\" in string command" ) ;
	      } 
	      biberrprint () ;
	      goto lab10 ;
	    } 
	    bufptr2 = bufptr2 + 1 ;
	  } 
	  goto lab10 ;
	} 
	break ;
	default: 
	bibcmdconfusion () ;
	break ;
      } 
    } 
    else {
	
      entrytypeloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 11 
      , false ) ;
      if ( ( ( ! hashfound ) || ( fntype [entrytypeloc ]!= 1 ) ) ) 
      typeexists = false ;
      else typeexists = true ;
    } 
  } 
  {
    if ( ( ! eatbibwhitespace () ) ) 
    {
      eatbibprint () ;
      goto lab10 ;
    } 
  } 
  {
    if ( ( buffer [bufptr2 ]== 123 ) ) 
    rightouterdelim = 125 ;
    else if ( ( buffer [bufptr2 ]== 40 ) ) 
    rightouterdelim = 41 ;
    else {
	
      biboneoftwoprint ( 123 , 40 ) ;
      goto lab10 ;
    } 
    bufptr2 = bufptr2 + 1 ;
    {
      if ( ( ! eatbibwhitespace () ) ) 
      {
	eatbibprint () ;
	goto lab10 ;
      } 
    } 
    if ( ( rightouterdelim == 41 ) ) 
    {
      if ( ( scan1white ( 44 ) ) ) 
      ;
    } 
    else if ( ( scan2white ( 44 , 125 ) ) ) 
    ;
    {
	;
#ifdef TRACE
      {
	outtoken ( logfile ) ;
      } 
      {
	fprintf ( logfile , "%s\n",  " is a database key" ) ;
      } 
#endif /* TRACE */
      tmpptr = bufptr1 ;
      while ( ( tmpptr < bufptr2 ) ) {
	  
	exbuf [tmpptr ]= buffer [tmpptr ];
	tmpptr = tmpptr + 1 ;
      } 
      lowercase ( exbuf , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
      if ( ( allentries ) ) 
      lcciteloc = strlookup ( exbuf , bufptr1 , ( bufptr2 - bufptr1 ) , 10 , 
      true ) ;
      else lcciteloc = strlookup ( exbuf , bufptr1 , ( bufptr2 - bufptr1 ) , 
      10 , false ) ;
      if ( ( hashfound ) ) 
      {
	entryciteptr = ilkinfo [ilkinfo [lcciteloc ]];
	{
	  if ( ( ( ! allentries ) || ( entryciteptr < allmarker ) || ( 
	  entryciteptr >= oldnumcites ) ) ) 
	  {
	    if ( ( typelist [entryciteptr ]== 0 ) ) 
	    {
	      {
		if ( ( ( ! allentries ) && ( entryciteptr >= oldnumcites ) ) ) 
		{
		  citeloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 
		  ) , 9 , true ) ;
		  if ( ( ! hashfound ) ) 
		  {
		    ilkinfo [lcciteloc ]= citeloc ;
		    ilkinfo [citeloc ]= entryciteptr ;
		    citelist [entryciteptr ]= hashtext [citeloc ];
		    hashfound = true ;
		  } 
		} 
	      } 
	      goto lab26 ;
	    } 
	  } 
	  else if ( ( ! entryexists [entryciteptr ]) ) 
	  {
	    {
	      exbufptr = 0 ;
	      tmpptr = strstart [citeinfo [entryciteptr ]];
	      tmpendptr = strstart [citeinfo [entryciteptr ]+ 1 ];
	      while ( ( tmpptr < tmpendptr ) ) {
		  
		exbuf [exbufptr ]= strpool [tmpptr ];
		exbufptr = exbufptr + 1 ;
		tmpptr = tmpptr + 1 ;
	      } 
	      lowercase ( exbuf , 0 , ( strstart [citeinfo [entryciteptr ]+ 
	      1 ]- strstart [citeinfo [entryciteptr ]]) ) ;
	      lcxciteloc = strlookup ( exbuf , 0 , ( strstart [citeinfo [
	      entryciteptr ]+ 1 ]- strstart [citeinfo [entryciteptr ]]) 
	      , 10 , false ) ;
	      if ( ( ! hashfound ) ) 
	      citekeydisappearedconfusion () ;
	    } 
	    if ( ( lcxciteloc == lcciteloc ) ) 
	    goto lab26 ;
	  } 
	  if ( ( typelist [entryciteptr ]== 0 ) ) 
	  {
	    {
	      Fputs ( logfile ,  "The cite list is messed up" ) ;
	      Fputs ( standardoutput ,  "The cite list is messed up" ) ;
	    } 
	    printconfusion () ;
	    longjmp(jmp9998,1) ;
	  } 
	  {
	    {
	      Fputs ( logfile ,  "Repeated entry" ) ;
	      Fputs ( standardoutput ,  "Repeated entry" ) ;
	    } 
	    biberrprint () ;
	    goto lab10 ;
	  } 
	  lab26: ;
	} 
      } 
      storeentry = true ;
      if ( ( allentries ) ) 
      {
	if ( ( hashfound ) ) 
	{
	  if ( ( entryciteptr < allmarker ) ) 
	  goto lab22 ;
	  else {
	      
	    entryexists [entryciteptr ]= true ;
	    citeloc = ilkinfo [lcciteloc ];
	  } 
	} 
	else {
	    
	  citeloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 9 , 
	  true ) ;
	  if ( ( hashfound ) ) 
	  hashciteconfusion () ;
	} 
	entryciteptr = citeptr ;
	adddatabasecite ( citeptr ) ;
	lab22: ;
      } 
      else if ( ( ! hashfound ) ) 
      storeentry = false ;
      if ( ( storeentry ) ) 
      {
	if ( ( typeexists ) ) 
	typelist [entryciteptr ]= entrytypeloc ;
	else {
	    
	  typelist [entryciteptr ]= undefined ;
	  {
	    Fputs ( logfile ,  "Warning--entry type for \"" ) ;
	    Fputs ( standardoutput ,  "Warning--entry type for \"" ) ;
	  } 
	  printatoken () ;
	  {
	    {
	      fprintf ( logfile , "%s\n",  "\" isn't style-file defined" ) ;
	      fprintf ( standardoutput , "%s\n",  "\" isn't style-file defined" ) ;
	    } 
	    bibwarnprint () ;
	  } 
	} 
      } 
    } 
  } 
  {
    if ( ( ! eatbibwhitespace () ) ) 
    {
      eatbibprint () ;
      goto lab10 ;
    } 
  } 
  {
    while ( ( buffer [bufptr2 ]!= rightouterdelim ) ) {
	
      if ( ( buffer [bufptr2 ]!= 44 ) ) 
      {
	biboneoftwoprint ( 44 , rightouterdelim ) ;
	goto lab10 ;
      } 
      bufptr2 = bufptr2 + 1 ;
      {
	if ( ( ! eatbibwhitespace () ) ) 
	{
	  eatbibprint () ;
	  goto lab10 ;
	} 
      } 
      if ( ( buffer [bufptr2 ]== rightouterdelim ) ) 
      goto lab15 ;
      {
	scanidentifier ( 61 , 61 , 61 ) ;
	{
	  if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
	  ;
	  else {
	      
	    bibidprint () ;
	    {
	      {
		Fputs ( logfile ,  "a field name" ) ;
		Fputs ( standardoutput ,  "a field name" ) ;
	      } 
	      biberrprint () ;
	      goto lab10 ;
	    } 
	  } 
	} 
	;
#ifdef TRACE
	{
	  outtoken ( logfile ) ;
	} 
	{
	  fprintf ( logfile , "%s\n",  " is a field name" ) ;
	} 
#endif /* TRACE */
	storefield = false ;
	if ( ( storeentry ) ) 
	{
	  lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
	  fieldnameloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) 
	  , 11 , false ) ;
	  if ( ( hashfound ) ) {
	      
	    if ( ( fntype [fieldnameloc ]== 4 ) ) 
	    storefield = true ;
	  } 
	} 
	{
	  if ( ( ! eatbibwhitespace () ) ) 
	  {
	    eatbibprint () ;
	    goto lab10 ;
	  } 
	} 
	if ( ( buffer [bufptr2 ]!= 61 ) ) 
	{
	  bibequalssignprint () ;
	  goto lab10 ;
	} 
	bufptr2 = bufptr2 + 1 ;
      } 
      {
	if ( ( ! eatbibwhitespace () ) ) 
	{
	  eatbibprint () ;
	  goto lab10 ;
	} 
      } 
      if ( ( ! scanandstorethefieldvalueandeatwhite () ) ) 
      goto lab10 ;
    } 
    lab15: bufptr2 = bufptr2 + 1 ;
  } 
  lab10: ;
} 
void 
bstreadcommand ( void ) 
{
  /* 10 */ if ( ( readseen ) ) 
  {
    {
      Fputs ( logfile ,  "Illegal, another read command" ) ;
      Fputs ( standardoutput ,  "Illegal, another read command" ) ;
    } 
    {
      bsterrprintandlookforblankline () ;
      goto lab10 ;
    } 
  } 
  readseen = true ;
  if ( ( ! entryseen ) ) 
  {
    {
      Fputs ( logfile ,  "Illegal, read command before entry command" ) ;
      Fputs ( standardoutput ,  "Illegal, read command before entry command" ) 
      ;
    } 
    {
      bsterrprintandlookforblankline () ;
      goto lab10 ;
    } 
  } 
  svptr1 = bufptr2 ;
  svptr2 = last ;
  tmpptr = svptr1 ;
  while ( ( tmpptr < svptr2 ) ) {
      
    svbuffer [tmpptr ]= buffer [tmpptr ];
    tmpptr = tmpptr + 1 ;
  } 
  {
    {
      {
	checkfieldoverflow ( numfields * numcites ) ;
	fieldptr = 0 ;
	while ( ( fieldptr < maxfields ) ) {
	    
	  fieldinfo [fieldptr ]= 0 ;
	  fieldptr = fieldptr + 1 ;
	} 
      } 
      {
	citeptr = 0 ;
	while ( ( citeptr < maxcites ) ) {
	    
	  typelist [citeptr ]= 0 ;
	  citeinfo [citeptr ]= 0 ;
	  citeptr = citeptr + 1 ;
	} 
	oldnumcites = numcites ;
	if ( ( allentries ) ) 
	{
	  citeptr = allmarker ;
	  while ( ( citeptr < oldnumcites ) ) {
	      
	    citeinfo [citeptr ]= citelist [citeptr ];
	    entryexists [citeptr ]= false ;
	    citeptr = citeptr + 1 ;
	  } 
	  citeptr = allmarker ;
	} 
	else {
	    
	  citeptr = numcites ;
	  allmarker = 0 ;
	} 
      } 
    } 
    readperformed = true ;
    bibptr = 0 ;
    while ( ( bibptr < numbibfiles ) ) {
	
      if ( verbose ) 
      {
	{
	  fprintf ( logfile , "%s%ld%s",  "Database file #" , (long)bibptr + 1 , ": " ) ;
	  fprintf ( standardoutput , "%s%ld%s",  "Database file #" , (long)bibptr + 1 , ": " ) ;
	} 
	printbibname () ;
      } 
      else {
	  
	{
	  fprintf ( logfile , "%s%ld%s",  "Database file #" , (long)bibptr + 1 , ": " ) ;
	} 
	logprbibname () ;
      } 
      biblinenum = 0 ;
      bufptr2 = last ;
      while ( ( ! eof ( bibfile [bibptr ]) ) ) 
      getbibcommandorentryandprocess () ;
      aclose ( bibfile [bibptr ]) ;
      bibptr = bibptr + 1 ;
    } 
    readingcompleted = true ;
	;
#ifdef TRACE
    {
      fprintf ( logfile , "%s\n",  "Finished reading the database file(s)" ) ;
    } 
#endif /* TRACE */
    {
      numcites = citeptr ;
      numpreamblestrings = preambleptr ;
      {
	if ( ( ( numcites - 1 ) * numfields + crossrefnum >= maxfields ) ) 
	{
	  {
	    Fputs ( logfile ,  "field_info index is out of range" ) ;
	    Fputs ( standardoutput ,  "field_info index is out of range" ) ;
	  } 
	  printconfusion () ;
	  longjmp(jmp9998,1) ;
	} 
	citeptr = 0 ;
	while ( ( citeptr < numcites ) ) {
	    
	  fieldptr = citeptr * numfields + crossrefnum ;
	  if ( ( fieldinfo [fieldptr ]!= 0 ) ) {
	      
	    if ( ( findcitelocsforthiscitekey ( fieldinfo [fieldptr ]) ) ) 
	    {
	      citeloc = ilkinfo [lcciteloc ];
	      fieldinfo [fieldptr ]= hashtext [citeloc ];
	      citeparentptr = ilkinfo [citeloc ];
	      fieldptr = citeptr * numfields + numpredefinedfields ;
	      fieldendptr = fieldptr - numpredefinedfields + numfields ;
	      fieldparentptr = citeparentptr * numfields + numpredefinedfields 
	      ;
	      while ( ( fieldptr < fieldendptr ) ) {
		  
		if ( ( fieldinfo [fieldptr ]== 0 ) ) 
		fieldinfo [fieldptr ]= fieldinfo [fieldparentptr ];
		fieldptr = fieldptr + 1 ;
		fieldparentptr = fieldparentptr + 1 ;
	      } 
	    } 
	  } 
	  citeptr = citeptr + 1 ;
	} 
      } 
      {
	if ( ( ( numcites - 1 ) * numfields + crossrefnum >= maxfields ) ) 
	{
	  {
	    Fputs ( logfile ,  "field_info index is out of range" ) ;
	    Fputs ( standardoutput ,  "field_info index is out of range" ) ;
	  } 
	  printconfusion () ;
	  longjmp(jmp9998,1) ;
	} 
	citeptr = 0 ;
	while ( ( citeptr < numcites ) ) {
	    
	  fieldptr = citeptr * numfields + crossrefnum ;
	  if ( ( fieldinfo [fieldptr ]!= 0 ) ) {
	      
	    if ( ( ! findcitelocsforthiscitekey ( fieldinfo [fieldptr ]) ) ) 
	    {
	      if ( ( citehashfound ) ) 
	      hashciteconfusion () ;
	      nonexistentcrossreferenceerror () ;
	      fieldinfo [fieldptr ]= 0 ;
	    } 
	    else {
		
	      if ( ( citeloc != ilkinfo [lcciteloc ]) ) 
	      hashciteconfusion () ;
	      citeparentptr = ilkinfo [citeloc ];
	      if ( ( typelist [citeparentptr ]== 0 ) ) 
	      {
		nonexistentcrossreferenceerror () ;
		fieldinfo [fieldptr ]= 0 ;
	      } 
	      else {
		  
		fieldparentptr = citeparentptr * numfields + crossrefnum ;
		if ( ( fieldinfo [fieldparentptr ]!= 0 ) ) 
		{
		  {
		    Fputs ( logfile ,                      "Warning--you've nested cross references" ) ;
		    Fputs ( standardoutput ,                      "Warning--you've nested cross references" ) ;
		  } 
		  badcrossreferenceprint ( citelist [citeparentptr ]) ;
		  {
		    fprintf ( logfile , "%s\n",  "\", which also refers to something" ) 
		    ;
		    fprintf ( standardoutput , "%s\n",                      "\", which also refers to something" ) ;
		  } 
		  markwarning () ;
		} 
		if ( ( ( ! allentries ) && ( citeparentptr >= oldnumcites ) && 
		( citeinfo [citeparentptr ]< mincrossrefs ) ) ) 
		fieldinfo [fieldptr ]= 0 ;
	      } 
	    } 
	  } 
	  citeptr = citeptr + 1 ;
	} 
      } 
      {
	citeptr = 0 ;
	while ( ( citeptr < numcites ) ) {
	    
	  if ( ( typelist [citeptr ]== 0 ) ) 
	  printmissingentry ( citelist [citeptr ]) ;
	  else if ( ( ( allentries ) || ( citeptr < oldnumcites ) || ( 
	  citeinfo [citeptr ]>= mincrossrefs ) ) ) 
	  {
	    if ( ( citeptr > citexptr ) ) 
	    {
	      if ( ( ( citexptr + 1 ) * numfields > maxfields ) ) 
	      {
		{
		  Fputs ( logfile ,  "field_info index is out of range" ) ;
		  Fputs ( standardoutput ,  "field_info index is out of range"                   ) ;
		} 
		printconfusion () ;
		longjmp(jmp9998,1) ;
	      } 
	      citelist [citexptr ]= citelist [citeptr ];
	      typelist [citexptr ]= typelist [citeptr ];
	      if ( ( ! findcitelocsforthiscitekey ( citelist [citeptr ]) ) ) 
	      citekeydisappearedconfusion () ;
	      if ( ( ( ! citehashfound ) || ( citeloc != ilkinfo [lcciteloc ]
	      ) ) ) 
	      hashciteconfusion () ;
	      ilkinfo [citeloc ]= citexptr ;
	      fieldptr = citexptr * numfields ;
	      fieldendptr = fieldptr + numfields ;
	      tmpptr = citeptr * numfields ;
	      while ( ( fieldptr < fieldendptr ) ) {
		  
		fieldinfo [fieldptr ]= fieldinfo [tmpptr ];
		fieldptr = fieldptr + 1 ;
		tmpptr = tmpptr + 1 ;
	      } 
	    } 
	    citexptr = citexptr + 1 ;
	  } 
	  citeptr = citeptr + 1 ;
	} 
	numcites = citexptr ;
	if ( ( allentries ) ) 
	{
	  citeptr = allmarker ;
	  while ( ( citeptr < oldnumcites ) ) {
	      
	    if ( ( ! entryexists [citeptr ]) ) 
	    printmissingentry ( citeinfo [citeptr ]) ;
	    citeptr = citeptr + 1 ;
	  } 
	} 
      } 
      {
	entryints = XTALLOC ( ( numentints + 1 ) * ( numcites + 1 ) , integer 
	) ;
	intentptr = 0 ;
	while ( ( intentptr < numentints * numcites ) ) {
	    
	  entryints [intentptr ]= 0 ;
	  intentptr = intentptr + 1 ;
	} 
      } 
      {
	entrystrs = XTALLOC ( ( numentstrs + 1 ) * ( numcites + 1 ) * ( 
	entstrsize + 1 ) , ASCIIcode ) ;
	strentptr = 0 ;
	while ( ( strentptr < numentstrs * numcites ) ) {
	    
	  entrystrs [( strentptr ) * ( entstrsize + 1 ) + ( 0 ) ]= 127 ;
	  strentptr = strentptr + 1 ;
	} 
      } 
      {
	citeptr = 0 ;
	while ( ( citeptr < numcites ) ) {
	    
	  citeinfo [citeptr ]= citeptr ;
	  citeptr = citeptr + 1 ;
	} 
      } 
    } 
    readcompleted = true ;
  } 
  bufptr2 = svptr1 ;
  last = svptr2 ;
  tmpptr = bufptr2 ;
  while ( ( tmpptr < last ) ) {
      
    buffer [tmpptr ]= svbuffer [tmpptr ];
    tmpptr = tmpptr + 1 ;
  } 
  lab10: ;
} 
void 
bstreversecommand ( void ) 
{
  /* 10 */ if ( ( ! readseen ) ) 
  {
    {
      Fputs ( logfile ,  "Illegal, reverse command before read command" ) ;
      Fputs ( standardoutput ,  "Illegal, reverse command before read command"       ) ;
    } 
    {
      bsterrprintandlookforblankline () ;
      goto lab10 ;
    } 
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "reverse" ) ;
	  Fputs ( standardoutput ,  "reverse" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    if ( ( buffer [bufptr2 ]!= 123 ) ) 
    {
      bstleftbraceprint () ;
      {
	{
	  Fputs ( logfile ,  "reverse" ) ;
	  Fputs ( standardoutput ,  "reverse" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "reverse" ) ;
	  Fputs ( standardoutput ,  "reverse" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    scanidentifier ( 125 , 37 , 37 ) ;
    if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
    ;
    else {
	
      bstidprint () ;
      {
	{
	  Fputs ( logfile ,  "reverse" ) ;
	  Fputs ( standardoutput ,  "reverse" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
	;
#ifdef TRACE
    {
      outtoken ( logfile ) ;
    } 
    {
      fprintf ( logfile , "%s\n",  " is a to be iterated in reverse function" ) ;
    } 
#endif /* TRACE */
    if ( ( badargumenttoken () ) ) 
    goto lab10 ;
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "reverse" ) ;
	  Fputs ( standardoutput ,  "reverse" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    if ( ( buffer [bufptr2 ]!= 125 ) ) 
    {
      bstrightbraceprint () ;
      {
	{
	  Fputs ( logfile ,  "reverse" ) ;
	  Fputs ( standardoutput ,  "reverse" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  {
    initcommandexecution () ;
    messwithentries = true ;
    if ( ( numcites > 0 ) ) 
    {
      sortciteptr = numcites ;
      do {
	  sortciteptr = sortciteptr - 1 ;
	citeptr = citeinfo [sortciteptr ];
	;
#ifdef TRACE
	{
	  outpoolstr ( logfile , hashtext [fnloc ]) ;
	} 
	{
	  Fputs ( logfile ,  " to be iterated in reverse on " ) ;
	} 
	{
	  outpoolstr ( logfile , citelist [citeptr ]) ;
	} 
	{
	  putc ('\n',  logfile );
	} 
#endif /* TRACE */
	executefn ( fnloc ) ;
	checkcommandexecution () ;
      } while ( ! ( ( sortciteptr == 0 ) ) ) ;
    } 
  } 
  lab10: ;
} 
void 
bstsortcommand ( void ) 
{
  /* 10 */ if ( ( ! readseen ) ) 
  {
    {
      Fputs ( logfile ,  "Illegal, sort command before read command" ) ;
      Fputs ( standardoutput ,  "Illegal, sort command before read command" ) ;
    } 
    {
      bsterrprintandlookforblankline () ;
      goto lab10 ;
    } 
  } 
  {
	;
#ifdef TRACE
    {
      fprintf ( logfile , "%s\n",  "Sorting the entries" ) ;
    } 
#endif /* TRACE */
    if ( ( numcites > 1 ) ) 
    quicksort ( 0 , numcites - 1 ) ;
	;
#ifdef TRACE
    {
      fprintf ( logfile , "%s\n",  "Done sorting" ) ;
    } 
#endif /* TRACE */
  } 
  lab10: ;
} 
void 
bststringscommand ( void ) 
{
  /* 10 */ {
      
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "strings" ) ;
	  Fputs ( standardoutput ,  "strings" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  {
    if ( ( buffer [bufptr2 ]!= 123 ) ) 
    {
      bstleftbraceprint () ;
      {
	{
	  Fputs ( logfile ,  "strings" ) ;
	  Fputs ( standardoutput ,  "strings" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
    bufptr2 = bufptr2 + 1 ;
  } 
  {
    if ( ( ! eatbstwhitespace () ) ) 
    {
      eatbstprint () ;
      {
	{
	  Fputs ( logfile ,  "strings" ) ;
	  Fputs ( standardoutput ,  "strings" ) ;
	} 
	{
	  bsterrprintandlookforblankline () ;
	  goto lab10 ;
	} 
      } 
    } 
  } 
  while ( ( buffer [bufptr2 ]!= 125 ) ) {
      
    {
      scanidentifier ( 125 , 37 , 37 ) ;
      if ( ( ( scanresult == 3 ) || ( scanresult == 1 ) ) ) 
      ;
      else {
	  
	bstidprint () ;
	{
	  {
	    Fputs ( logfile ,  "strings" ) ;
	    Fputs ( standardoutput ,  "strings" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
    {
	;
#ifdef TRACE
      {
	outtoken ( logfile ) ;
      } 
      {
	fprintf ( logfile , "%s\n",  " is a string global-variable" ) ;
      } 
#endif /* TRACE */
      lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
      fnloc = strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) , 11 , true 
      ) ;
      {
	if ( ( hashfound ) ) 
	{
	  alreadyseenfunctionprint ( fnloc ) ;
	  goto lab10 ;
	} 
      } 
      fntype [fnloc ]= 8 ;
      ilkinfo [fnloc ]= numglbstrs ;
      if ( ( numglbstrs == maxglobstrs ) ) 
      {
	BIBXRETALLOCNOSET ( "glb_str_ptr" , glbstrptr , strnumber , 
	maxglobstrs , maxglobstrs + MAXGLOBSTRS ) ;
	BIBXRETALLOCSTRING ( "global_strs" , globalstrs , globstrsize , 
	maxglobstrs , maxglobstrs + MAXGLOBSTRS ) ;
	BIBXRETALLOC ( "glb_str_end" , glbstrend , integer , maxglobstrs , 
	maxglobstrs + MAXGLOBSTRS ) ;
	strglbptr = numglbstrs ;
	while ( ( strglbptr < maxglobstrs ) ) {
	    
	  glbstrptr [strglbptr ]= 0 ;
	  glbstrend [strglbptr ]= 0 ;
	  strglbptr = strglbptr + 1 ;
	} 
      } 
      numglbstrs = numglbstrs + 1 ;
    } 
    {
      if ( ( ! eatbstwhitespace () ) ) 
      {
	eatbstprint () ;
	{
	  {
	    Fputs ( logfile ,  "strings" ) ;
	    Fputs ( standardoutput ,  "strings" ) ;
	  } 
	  {
	    bsterrprintandlookforblankline () ;
	    goto lab10 ;
	  } 
	} 
      } 
    } 
  } 
  bufptr2 = bufptr2 + 1 ;
  lab10: ;
} 
void 
getbstcommandandprocess ( void ) 
{
  /* 10 */ if ( ( ! scanalpha () ) ) 
  {
    {
      fprintf ( logfile , "%c%c%s",  '"' , xchr [buffer [bufptr2 ]],       "\" can't start a style-file command" ) ;
      fprintf ( standardoutput , "%c%c%s",  '"' , xchr [buffer [bufptr2 ]],       "\" can't start a style-file command" ) ;
    } 
    {
      bsterrprintandlookforblankline () ;
      goto lab10 ;
    } 
  } 
  lowercase ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) ) ;
  commandnum = ilkinfo [strlookup ( buffer , bufptr1 , ( bufptr2 - bufptr1 ) 
  , 4 , false ) ];
  if ( ( ! hashfound ) ) 
  {
    printatoken () ;
    {
      {
	Fputs ( logfile ,  " is an illegal style-file command" ) ;
	Fputs ( standardoutput ,  " is an illegal style-file command" ) ;
      } 
      {
	bsterrprintandlookforblankline () ;
	goto lab10 ;
      } 
    } 
  } 
  switch ( ( commandnum ) ) 
  {case 0 : 
    bstentrycommand () ;
    break ;
  case 1 : 
    bstexecutecommand () ;
    break ;
  case 2 : 
    bstfunctioncommand () ;
    break ;
  case 3 : 
    bstintegerscommand () ;
    break ;
  case 4 : 
    bstiteratecommand () ;
    break ;
  case 5 : 
    bstmacrocommand () ;
    break ;
  case 6 : 
    bstreadcommand () ;
    break ;
  case 7 : 
    bstreversecommand () ;
    break ;
  case 8 : 
    bstsortcommand () ;
    break ;
  case 9 : 
    bststringscommand () ;
    break ;
    default: 
    {
      {
	Fputs ( logfile ,  "Unknown style-file command" ) ;
	Fputs ( standardoutput ,  "Unknown style-file command" ) ;
      } 
      printconfusion () ;
      longjmp(jmp9998,1) ;
    } 
    break ;
  } 
  lab10: ;
} 
void 
setupparams ( void ) 
{
  integer bounddefault  ;
  constcstring boundname  ;
  kpsesetprogramname ( argv [0 ], "pbibtex" ) ;
  bounddefault = ENTSTRSIZE ;
  boundname = "ent_str_size" ;
  setupboundvariable ( addressof ( entstrsize ) , boundname , bounddefault ) ;
  if ( entstrsize < bounddefault ) 
  entstrsize = bounddefault ;
  bounddefault = GLOBSTRSIZE ;
  boundname = "glob_str_size" ;
  setupboundvariable ( addressof ( globstrsize ) , boundname , bounddefault ) 
  ;
  if ( globstrsize < bounddefault ) 
  globstrsize = bounddefault ;
  bounddefault = MAXSTRINGS ;
  boundname = "max_strings" ;
  setupboundvariable ( addressof ( maxstrings ) , boundname , bounddefault ) ;
  if ( maxstrings < bounddefault ) 
  maxstrings = bounddefault ;
  hashsize = maxstrings ;
  if ( hashsize < 5000 ) 
  hashsize = 5000 ;
  hashmax = hashsize + hashbase - 1 ;
  endofdef = hashmax + 1 ;
  undefined = hashmax + 1 ;
} 
void 
computehashprime ( void ) 
{
  integer hashwant  ;
  integer k  ;
  integer j  ;
  integer o  ;
  integer square  ;
  integer n  ;
  boolean jprime  ;
  hashwant = ( hashsize / 20 ) * 17 ;
  j = 1 ;
  k = 1 ;
  hashprime = 2 ;
  hashnext [k ]= hashprime ;
  o = 2 ;
  square = 9 ;
  while ( hashprime < hashwant ) {
      
    do {
	j = j + 2 ;
      if ( j == square ) 
      {
	hashtext [o ]= j ;
	j = j + 2 ;
	o = o + 1 ;
	square = hashnext [o ]* hashnext [o ];
      } 
      n = 2 ;
      jprime = true ;
      while ( ( n < o ) && jprime ) {
	  
	while ( hashtext [n ]< j ) hashtext [n ]= hashtext [n ]+ 2 * 
	hashnext [n ];
	if ( hashtext [n ]== j ) 
	jprime = false ;
	n = n + 1 ;
      } 
    } while ( ! ( jprime ) ) ;
    k = k + 1 ;
    hashprime = j ;
    hashnext [k ]= hashprime ;
  } 
} 
void 
initialize ( void ) 
{
  integer i  ;
  hashloc k  ;
  bad = 0 ;
  if ( ( minprintline < 3 ) ) 
  bad = 1 ;
  if ( ( maxprintline <= minprintline ) ) 
  bad = 10 * bad + 2 ;
  if ( ( maxprintline >= bufsize ) ) 
  bad = 10 * bad + 3 ;
  if ( ( hashprime < 128 ) ) 
  bad = 10 * bad + 4 ;
  if ( ( hashprime > hashsize ) ) 
  bad = 10 * bad + 5 ;
  if ( ( hashbase != 1 ) ) 
  bad = 10 * bad + 6 ;
  if ( ( maxstrings > hashsize ) ) 
  bad = 10 * bad + 7 ;
  if ( ( maxcites > maxstrings ) ) 
  bad = 10 * bad + 8 ;
  if ( ( 10 < 2 * 4 + 2 ) ) 
  bad = 100 * bad + 22 ;
  if ( ( bad > 0 ) ) 
  {
    fprintf ( standardoutput , "%ld%s\n",  (long)bad , " is a bad bad" ) ;
    uexit ( 1 ) ;
  } 
  history = 0 ;
  xchr [32 ]= ' ' ;
  xchr [33 ]= '!' ;
  xchr [34 ]= '"' ;
  xchr [35 ]= '#' ;
  xchr [36 ]= '$' ;
  xchr [37 ]= '%' ;
  xchr [38 ]= '&' ;
  xchr [39 ]= '\'' ;
  xchr [40 ]= '(' ;
  xchr [41 ]= ')' ;
  xchr [42 ]= '*' ;
  xchr [43 ]= '+' ;
  xchr [44 ]= ',' ;
  xchr [45 ]= '-' ;
  xchr [46 ]= '.' ;
  xchr [47 ]= '/' ;
  xchr [48 ]= '0' ;
  xchr [49 ]= '1' ;
  xchr [50 ]= '2' ;
  xchr [51 ]= '3' ;
  xchr [52 ]= '4' ;
  xchr [53 ]= '5' ;
  xchr [54 ]= '6' ;
  xchr [55 ]= '7' ;
  xchr [56 ]= '8' ;
  xchr [57 ]= '9' ;
  xchr [58 ]= ':' ;
  xchr [59 ]= ';' ;
  xchr [60 ]= '<' ;
  xchr [61 ]= '=' ;
  xchr [62 ]= '>' ;
  xchr [63 ]= '?' ;
  xchr [64 ]= '@' ;
  xchr [65 ]= 'A' ;
  xchr [66 ]= 'B' ;
  xchr [67 ]= 'C' ;
  xchr [68 ]= 'D' ;
  xchr [69 ]= 'E' ;
  xchr [70 ]= 'F' ;
  xchr [71 ]= 'G' ;
  xchr [72 ]= 'H' ;
  xchr [73 ]= 'I' ;
  xchr [74 ]= 'J' ;
  xchr [75 ]= 'K' ;
  xchr [76 ]= 'L' ;
  xchr [77 ]= 'M' ;
  xchr [78 ]= 'N' ;
  xchr [79 ]= 'O' ;
  xchr [80 ]= 'P' ;
  xchr [81 ]= 'Q' ;
  xchr [82 ]= 'R' ;
  xchr [83 ]= 'S' ;
  xchr [84 ]= 'T' ;
  xchr [85 ]= 'U' ;
  xchr [86 ]= 'V' ;
  xchr [87 ]= 'W' ;
  xchr [88 ]= 'X' ;
  xchr [89 ]= 'Y' ;
  xchr [90 ]= 'Z' ;
  xchr [91 ]= '[' ;
  xchr [92 ]= '\\' ;
  xchr [93 ]= ']' ;
  xchr [94 ]= '^' ;
  xchr [95 ]= '_' ;
  xchr [96 ]= '`' ;
  xchr [97 ]= 'a' ;
  xchr [98 ]= 'b' ;
  xchr [99 ]= 'c' ;
  xchr [100 ]= 'd' ;
  xchr [101 ]= 'e' ;
  xchr [102 ]= 'f' ;
  xchr [103 ]= 'g' ;
  xchr [104 ]= 'h' ;
  xchr [105 ]= 'i' ;
  xchr [106 ]= 'j' ;
  xchr [107 ]= 'k' ;
  xchr [108 ]= 'l' ;
  xchr [109 ]= 'm' ;
  xchr [110 ]= 'n' ;
  xchr [111 ]= 'o' ;
  xchr [112 ]= 'p' ;
  xchr [113 ]= 'q' ;
  xchr [114 ]= 'r' ;
  xchr [115 ]= 's' ;
  xchr [116 ]= 't' ;
  xchr [117 ]= 'u' ;
  xchr [118 ]= 'v' ;
  xchr [119 ]= 'w' ;
  xchr [120 ]= 'x' ;
  xchr [121 ]= 'y' ;
  xchr [122 ]= 'z' ;
  xchr [123 ]= '{' ;
  xchr [124 ]= '|' ;
  xchr [125 ]= '}' ;
  xchr [126 ]= '~' ;
  xchr [0 ]= ' ' ;
  xchr [127 ]= ' ' ;
  {register integer for_end; i = 1 ;for_end = 31 ; if ( i <= for_end) do 
    xchr [i ]= ' ' ;
  while ( i++ < for_end ) ;} 
  xchr [9 ]= chr ( 9 ) ;
  {register integer for_end; i = 128 ;for_end = 255 ; if ( i <= for_end) do 
    xchr [i ]= chr ( i ) ;
  while ( i++ < for_end ) ;} 
  xchr [27 ]= chr ( 27 ) ;
  {register integer for_end; i = 0 ;for_end = 255 ; if ( i <= for_end) do 
    xord [i ]= 127 ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 1 ;for_end = 126 ; if ( i <= for_end) do 
    xord [i ]= i ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 128 ;for_end = 255 ; if ( i <= for_end) do 
    xord [i ]= i ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 0 ;for_end = 255 ; if ( i <= for_end) do 
    lexclass [i ]= 5 ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 0 ;for_end = 31 ; if ( i <= for_end) do 
    lexclass [i ]= 0 ;
  while ( i++ < for_end ) ;} 
  lexclass [127 ]= 0 ;
  lexclass [9 ]= 1 ;
  lexclass [13 ]= 1 ;
  lexclass [32 ]= 1 ;
  lexclass [126 ]= 4 ;
  lexclass [45 ]= 4 ;
  {register integer for_end; i = 48 ;for_end = 57 ; if ( i <= for_end) do 
    lexclass [i ]= 3 ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 65 ;for_end = 90 ; if ( i <= for_end) do 
    lexclass [i ]= 2 ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 97 ;for_end = 122 ; if ( i <= for_end) do 
    lexclass [i ]= 2 ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 0 ;for_end = 255 ; if ( i <= for_end) do 
    idclass [i ]= 1 ;
  while ( i++ < for_end ) ;} 
  {register integer for_end; i = 0 ;for_end = 31 ; if ( i <= for_end) do 
    idclass [i ]= 0 ;
  while ( i++ < for_end ) ;} 
  idclass [27 ]= 1 ;
  idclass [32 ]= 0 ;
  idclass [9 ]= 0 ;
  idclass [34 ]= 0 ;
  idclass [35 ]= 0 ;
  idclass [37 ]= 0 ;
  idclass [39 ]= 0 ;
  idclass [40 ]= 0 ;
  idclass [41 ]= 0 ;
  idclass [44 ]= 0 ;
  idclass [61 ]= 0 ;
  idclass [123 ]= 0 ;
  idclass [125 ]= 0 ;
  {register integer for_end; i = 0 ;for_end = 127 ; if ( i <= for_end) do 
    charwidth [i ]= 0 ;
  while ( i++ < for_end ) ;} 
  charwidth [32 ]= 278 ;
  charwidth [33 ]= 278 ;
  charwidth [34 ]= 500 ;
  charwidth [35 ]= 833 ;
  charwidth [36 ]= 500 ;
  charwidth [37 ]= 833 ;
  charwidth [38 ]= 778 ;
  charwidth [39 ]= 278 ;
  charwidth [40 ]= 389 ;
  charwidth [41 ]= 389 ;
  charwidth [42 ]= 500 ;
  charwidth [43 ]= 778 ;
  charwidth [44 ]= 278 ;
  charwidth [45 ]= 333 ;
  charwidth [46 ]= 278 ;
  charwidth [47 ]= 500 ;
  charwidth [48 ]= 500 ;
  charwidth [49 ]= 500 ;
  charwidth [50 ]= 500 ;
  charwidth [51 ]= 500 ;
  charwidth [52 ]= 500 ;
  charwidth [53 ]= 500 ;
  charwidth [54 ]= 500 ;
  charwidth [55 ]= 500 ;
  charwidth [56 ]= 500 ;
  charwidth [57 ]= 500 ;
  charwidth [58 ]= 278 ;
  charwidth [59 ]= 278 ;
  charwidth [60 ]= 278 ;
  charwidth [61 ]= 778 ;
  charwidth [62 ]= 472 ;
  charwidth [63 ]= 472 ;
  charwidth [64 ]= 778 ;
  charwidth [65 ]= 750 ;
  charwidth [66 ]= 708 ;
  charwidth [67 ]= 722 ;
  charwidth [68 ]= 764 ;
  charwidth [69 ]= 681 ;
  charwidth [70 ]= 653 ;
  charwidth [71 ]= 785 ;
  charwidth [72 ]= 750 ;
  charwidth [73 ]= 361 ;
  charwidth [74 ]= 514 ;
  charwidth [75 ]= 778 ;
  charwidth [76 ]= 625 ;
  charwidth [77 ]= 917 ;
  charwidth [78 ]= 750 ;
  charwidth [79 ]= 778 ;
  charwidth [80 ]= 681 ;
  charwidth [81 ]= 778 ;
  charwidth [82 ]= 736 ;
  charwidth [83 ]= 556 ;
  charwidth [84 ]= 722 ;
  charwidth [85 ]= 750 ;
  charwidth [86 ]= 750 ;
  charwidth [87 ]= 1028 ;
  charwidth [88 ]= 750 ;
  charwidth [89 ]= 750 ;
  charwidth [90 ]= 611 ;
  charwidth [91 ]= 278 ;
  charwidth [92 ]= 500 ;
  charwidth [93 ]= 278 ;
  charwidth [94 ]= 500 ;
  charwidth [95 ]= 278 ;
  charwidth [96 ]= 278 ;
  charwidth [97 ]= 500 ;
  charwidth [98 ]= 556 ;
  charwidth [99 ]= 444 ;
  charwidth [100 ]= 556 ;
  charwidth [101 ]= 444 ;
  charwidth [102 ]= 306 ;
  charwidth [103 ]= 500 ;
  charwidth [104 ]= 556 ;
  charwidth [105 ]= 278 ;
  charwidth [106 ]= 306 ;
  charwidth [107 ]= 528 ;
  charwidth [108 ]= 278 ;
  charwidth [109 ]= 833 ;
  charwidth [110 ]= 556 ;
  charwidth [111 ]= 500 ;
  charwidth [112 ]= 556 ;
  charwidth [113 ]= 528 ;
  charwidth [114 ]= 392 ;
  charwidth [115 ]= 394 ;
  charwidth [116 ]= 389 ;
  charwidth [117 ]= 556 ;
  charwidth [118 ]= 528 ;
  charwidth [119 ]= 722 ;
  charwidth [120 ]= 528 ;
  charwidth [121 ]= 528 ;
  charwidth [122 ]= 444 ;
  charwidth [123 ]= 500 ;
  charwidth [124 ]= 1000 ;
  charwidth [125 ]= 500 ;
  charwidth [126 ]= 500 ;
  {register integer for_end; k = hashbase ;for_end = hashmax ; if ( k <= 
  for_end) do 
    {
      hashnext [k ]= 0 ;
      hashtext [k ]= 0 ;
    } 
  while ( k++ < for_end ) ;} 
  hashused = hashmax + 1 ;
  poolptr = 0 ;
  strptr = 1 ;
  strstart [strptr ]= poolptr ;
  bibptr = 0 ;
  bibseen = false ;
  bststr = 0 ;
  bstseen = false ;
  citeptr = 0 ;
  citationseen = false ;
  allentries = false ;
  wizdefptr = 0 ;
  numentints = 0 ;
  numentstrs = 0 ;
  numfields = 0 ;
  strglbptr = 0 ;
  while ( ( strglbptr < maxglobstrs ) ) {
      
    glbstrptr [strglbptr ]= 0 ;
    glbstrend [strglbptr ]= 0 ;
    strglbptr = strglbptr + 1 ;
  } 
  numglbstrs = 0 ;
  entryseen = false ;
  readseen = false ;
  readperformed = false ;
  readingcompleted = false ;
  readcompleted = false ;
  implfnnum = 0 ;
  outbuflength = 0 ;
  predefcertainstrings () ;
  getthetoplevelauxfilename () ;
} 
void 
parsearguments ( void ) 
{
  
#define noptions ( 7 ) 
  getoptstruct longoptions[noptions + 1]  ;
  integer getoptreturnval  ;
  cinttype optionindex  ;
  integer currentoption  ;
  verbose = true ;
  mincrossrefs = 2 ;
  currentoption = 0 ;
  longoptions [0 ].name = "terse" ;
  longoptions [0 ].hasarg = 0 ;
  longoptions [0 ].flag = addressof ( verbose ) ;
  longoptions [0 ].val = 0 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = "min-crossrefs" ;
  longoptions [currentoption ].hasarg = 1 ;
  longoptions [currentoption ].flag = 0 ;
  longoptions [currentoption ].val = 0 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = "help" ;
  longoptions [currentoption ].hasarg = 0 ;
  longoptions [currentoption ].flag = 0 ;
  longoptions [currentoption ].val = 0 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = "version" ;
  longoptions [currentoption ].hasarg = 0 ;
  longoptions [currentoption ].flag = 0 ;
  longoptions [currentoption ].val = 0 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = "sjis-terminal" ;
  longoptions [currentoption ].hasarg = 0 ;
  longoptions [currentoption ].flag = addressof ( sjisterminal ) ;
  longoptions [currentoption ].val = 1 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = "kanji" ;
  longoptions [currentoption ].hasarg = 1 ;
  longoptions [currentoption ].flag = 0 ;
  longoptions [currentoption ].val = 0 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = "kanji-internal" ;
  longoptions [currentoption ].hasarg = 1 ;
  longoptions [currentoption ].flag = 0 ;
  longoptions [currentoption ].val = 0 ;
  currentoption = currentoption + 1 ;
  longoptions [currentoption ].name = 0 ;
  longoptions [currentoption ].hasarg = 0 ;
  longoptions [currentoption ].flag = 0 ;
  longoptions [currentoption ].val = 0 ;
  do {
      getoptreturnval = getoptlongonly ( argc , argv , "" , longoptions , 
    addressof ( optionindex ) ) ;
    if ( getoptreturnval == -1 ) 
    {
      ;
    } 
    else if ( getoptreturnval == 63 ) 
    {
      usage ( "upbibtex" ) ;
    } 
    else if ( ( strcmp ( longoptions [optionindex ].name , "min-crossrefs" ) 
    == 0 ) ) 
    {
      mincrossrefs = atoi ( optarg ) ;
    } 
    else if ( ( strcmp ( longoptions [optionindex ].name , "help" ) == 0 ) ) 
    {
      usagehelp ( UPBIBTEXHELP , nil ) ;
    } 
    else if ( ( strcmp ( longoptions [optionindex ].name , "version" ) == 0 
    ) ) 
    {
      printversionandexit ( "This is upBibTeX, Version 0.99d-j0.33-u1.20" , 
      "Oren Patashnik" , nil , nil ) ;
    } 
    else if ( ( strcmp ( longoptions [optionindex ].name , "kanji" ) == 0 ) 
    ) 
    {
      if ( ( ! setencstring ( optarg , nil ) ) ) 
      fprintf (stdout, "%s%s%s\n", "Bad kanji encoding \"" , stringcast ( optarg ) , "\"." ) ;
    } 
    else if ( ( strcmp ( longoptions [optionindex ].name , "kanji-internal" 
    ) == 0 ) ) 
    {
      if ( ( ! ( setencstring ( nil , optarg ) && ( isinternalEUC () || 
      isinternalUPTEX () ) ) ) ) 
      fprintf (stdout, "%s%s%s\n", "Bad internal kanji encoding \"" , stringcast ( optarg ) ,       "\"." ) ;
    } 
  } while ( ! ( getoptreturnval == -1 ) ) ;
  if ( ( optind + 1 != argc ) ) 
  {
    fprintf ( stderr , "%s%s\n",  "upbibtex" , ": Need exactly one file argument." ) ;
    usage ( "upbibtex" ) ;
  } 
} 
void mainbody( void ) {
    
  standardinput = stdin ;
  standardoutput = stdout ;
  poolsize = POOLSIZE ;
  bufsize = BUFSIZE ;
  maxbibfiles = MAXBIBFILES ;
  maxglobstrs = MAXGLOBSTRS ;
  maxfields = MAXFIELDS ;
  maxcites = MAXCITES ;
  wizfnspace = WIZFNSPACE ;
  litstksize = LITSTKSIZE ;
  setupparams () ;
  bibfile = XTALLOC ( maxbibfiles + 1 , alphafile ) ;
  biblist = XTALLOC ( maxbibfiles + 1 , strnumber ) ;
  entryints = nil ;
  entrystrs = nil ;
  wizfunctions = XTALLOC ( wizfnspace + 1 , hashptr2 ) ;
  fieldinfo = XTALLOC ( maxfields + 1 , strnumber ) ;
  spreamble = XTALLOC ( maxbibfiles + 1 , strnumber ) ;
  strpool = XTALLOC ( poolsize + 1 , ASCIIcode ) ;
  buffer = XTALLOC ( bufsize + 1 , ASCIIcode ) ;
  svbuffer = XTALLOC ( bufsize + 1 , ASCIIcode ) ;
  exbuf = XTALLOC ( bufsize + 1 , ASCIIcode ) ;
  outbuf = XTALLOC ( bufsize + 1 , ASCIIcode ) ;
  nametok = XTALLOC ( bufsize + 1 , bufpointer ) ;
  namesepchar = XTALLOC ( bufsize + 1 , ASCIIcode ) ;
  glbstrptr = XTALLOC ( maxglobstrs , strnumber ) ;
  globalstrs = XTALLOC ( maxglobstrs * ( globstrsize + 1 ) , ASCIIcode ) ;
  glbstrend = XTALLOC ( maxglobstrs , integer ) ;
  citelist = XTALLOC ( maxcites + 1 , strnumber ) ;
  typelist = XTALLOC ( maxcites + 1 , hashptr2 ) ;
  entryexists = XTALLOC ( maxcites + 1 , boolean ) ;
  citeinfo = XTALLOC ( maxcites + 1 , strnumber ) ;
  strstart = XTALLOC ( maxstrings + 1 , poolpointer ) ;
  hashnext = XTALLOC ( hashmax + 1 , hashpointer ) ;
  hashtext = XTALLOC ( hashmax + 1 , strnumber ) ;
  hashilk = XTALLOC ( hashmax + 1 , strilk ) ;
  ilkinfo = XTALLOC ( hashmax + 1 , integer ) ;
  fntype = XTALLOC ( hashmax + 1 , fnclass ) ;
  litstack = XTALLOC ( litstksize + 1 , integer ) ;
  litstktype = XTALLOC ( litstksize + 1 , stktype ) ;
  computehashprime () ;
  initialize () ;
  if(setjmp(jmp9998)==1) goto lab9998;
  if ( verbose ) 
  {
    {
      Fputs ( logfile ,  "This is upBibTeX, Version 0.99d-j0.33-u1.20" ) ;
      Fputs ( standardoutput ,  "This is upBibTeX, Version 0.99d-j0.33-u1.20" ) 
      ;
    } 
    {
      fprintf ( logfile , "%s%s%c",  " (" , conststringcast ( getencstring () ) , ')' ) ;
      fprintf ( standardoutput , "%s%s%c",  " (" , conststringcast ( getencstring () ) ,       ')' ) ;
    } 
    {
      fprintf ( logfile , "%s\n",  versionstring ) ;
      fprintf ( standardoutput , "%s\n",  versionstring ) ;
    } 
  } 
  else {
      
    {
      Fputs ( logfile ,  "This is upBibTeX, Version 0.99d-j0.33-u1.20" ) ;
    } 
    {
      fprintf ( logfile , "%s\n",  versionstring ) ;
    } 
  } 
  {
    fprintf ( logfile , "%s%ld%s%ld%s%ld\n",  "Capacity: max_strings=" , (long)maxstrings , ", hash_size="     , (long)hashsize , ", hash_prime=" , (long)hashprime ) ;
  } 
  if ( verbose ) 
  {
    {
      Fputs ( logfile ,  "The top-level auxiliary file: " ) ;
      Fputs ( standardoutput ,  "The top-level auxiliary file: " ) ;
    } 
    printauxname () ;
  } 
  else {
      
    {
      Fputs ( logfile ,  "The top-level auxiliary file: " ) ;
    } 
    logprauxname () ;
  } 
  while (lab31==0 ) {
      
    auxlnstack [auxptr ]= auxlnstack [auxptr ]+ 1 ;
    if ( ( ! inputln ( auxfile [auxptr ]) ) ) 
    poptheauxstack () ;
    else getauxcommandandprocess () ;
  } 
#ifdef TRACE
  {
    fprintf ( logfile , "%s\n",  "Finished reading the auxiliary file(s)" ) ;
  } 
#endif /* TRACE */
   lastcheckforauxerrors () ;
  if ( ( bststr == 0 ) ) 
  goto lab9932 ;
  bstlinenum = 0 ;
  bbllinenum = 1 ;
  bufptr2 = last ;
  if(setjmp(jmp32)==0)for(;;)
  {
    if ( ( ! eatbstwhitespace () ) ) 
    break ;
    getbstcommandandprocess () ;
  } 
   aclose ( bstfile ) ;
  lab9932: aclose ( bblfile ) ;
  lab9998: {
      
    if ( ( ( readperformed ) && ( ! readingcompleted ) ) ) 
    {
      {
	fprintf ( logfile , "%s%ld%s",  "Aborted at line " , (long)biblinenum , " of file " ) ;
	fprintf ( standardoutput , "%s%ld%s",  "Aborted at line " , (long)biblinenum , " of file "         ) ;
      } 
      printbibname () ;
    } 
    traceandstatprinting () ;
    switch ( ( history ) ) 
    {case 0 : 
      ;
      break ;
    case 1 : 
      {
	if ( ( errcount == 1 ) ) 
	{
	  fprintf ( logfile , "%s\n",  "(There was 1 warning)" ) ;
	  fprintf ( standardoutput , "%s\n",  "(There was 1 warning)" ) ;
	} 
	else {
	    
	  fprintf ( logfile , "%s%ld%s\n",  "(There were " , (long)errcount , " warnings)" ) ;
	  fprintf ( standardoutput , "%s%ld%s\n",  "(There were " , (long)errcount , " warnings)"           ) ;
	} 
      } 
      break ;
    case 2 : 
      {
	if ( ( errcount == 1 ) ) 
	{
	  fprintf ( logfile , "%s\n",  "(There was 1 error message)" ) ;
	  fprintf ( standardoutput , "%s\n",  "(There was 1 error message)" ) ;
	} 
	else {
	    
	  fprintf ( logfile , "%s%ld%s\n",  "(There were " , (long)errcount , " error messages)" ) 
	  ;
	  fprintf ( standardoutput , "%s%ld%s\n",  "(There were " , (long)errcount ,           " error messages)" ) ;
	} 
      } 
      break ;
    case 3 : 
      {
	fprintf ( logfile , "%s\n",  "(That was a fatal error)" ) ;
	fprintf ( standardoutput , "%s\n",  "(That was a fatal error)" ) ;
      } 
      break ;
      default: 
      {
	{
	  Fputs ( logfile ,  "History is bunk" ) ;
	  Fputs ( standardoutput ,  "History is bunk" ) ;
	} 
	printconfusion () ;
      } 
      break ;
    } 
    aclose ( logfile ) ;
  } 
  if ( ( history > 1 ) ) 
  uexit ( history ) ;
} 
