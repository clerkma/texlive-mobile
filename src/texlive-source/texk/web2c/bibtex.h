void printanewline (void);
void markwarning (void);
void markerror (void);
void markfatal (void);
void printoverflow (void);
void printconfusion (void);
void bufferoverflow (void);
boolean zinputln (alphafile f);
#define inputln(f) zinputln((alphafile) (f))
void zoutpoolstr (alphafile f,strnumber s);
#define outpoolstr(f, s) zoutpoolstr((alphafile) (f), (strnumber) (s))
void zprintapoolstr (strnumber s);
#define printapoolstr(s) zprintapoolstr((strnumber) (s))
void pooloverflow (void);
void zouttoken (alphafile f);
#define outtoken(f) zouttoken((alphafile) (f))
void printatoken (void);
void printbadinputline (void);
void printskippingwhateverremains (void);
void samtoolongfilenameprint (void);
void samwrongfilenameprint (void);
void printauxname (void);
void logprauxname (void);
void auxerrprint (void);
void zauxerrillegalanotherprint (integer cmdnum);
#define auxerrillegalanotherprint(cmdnum) zauxerrillegalanotherprint((integer) (cmdnum))
void auxerrnorightbraceprint (void);
void auxerrstuffafterrightbraceprint (void);
void auxerrwhitespaceinargumentprint (void);
void printbibname (void);
void logprbibname (void);
void printbstname (void);
void logprbstname (void);
void hashciteconfusion (void);
void zcheckciteoverflow (citenumber lastcite);
#define checkciteoverflow(lastcite) zcheckciteoverflow((citenumber) (lastcite))
void auxend1errprint (void);
void auxend2errprint (void);
void bstlnnumprint (void);
void bsterrprintandlookforblankline (void);
void bstwarnprint (void);
void eatbstprint (void);
void unknwnfunctionclassconfusion (void);
void zprintfnclass (hashloc fnloc);
#define printfnclass(fnloc) zprintfnclass((hashloc) (fnloc))
void ztraceprfnclass (hashloc fnloc);
#define traceprfnclass(fnloc) ztraceprfnclass((hashloc) (fnloc))
void idscanningconfusion (void);
void bstidprint (void);
void bstleftbraceprint (void);
void bstrightbraceprint (void);
void zalreadyseenfunctionprint (hashloc seenfnloc);
#define alreadyseenfunctionprint(seenfnloc) zalreadyseenfunctionprint((hashloc) (seenfnloc))
void biblnnumprint (void);
void biberrprint (void);
void bibwarnprint (void);
void zcheckfieldoverflow (integer totalfields);
#define checkfieldoverflow(totalfields) zcheckfieldoverflow((integer) (totalfields))
void eatbibprint (void);
void zbiboneoftwoprint (ASCIIcode char1,ASCIIcode char2);
#define biboneoftwoprint(char1, char2) zbiboneoftwoprint((ASCIIcode) (char1), (ASCIIcode) (char2))
void bibequalssignprint (void);
void bibunbalancedbracesprint (void);
void bibfieldtoolongprint (void);
void macrowarnprint (void);
void bibidprint (void);
void bibcmdconfusion (void);
void citekeydisappearedconfusion (void);
void zbadcrossreferenceprint (strnumber s);
#define badcrossreferenceprint(s) zbadcrossreferenceprint((strnumber) (s))
void nonexistentcrossreferenceerror (void);
void zprintmissingentry (strnumber s);
#define printmissingentry(s) zprintmissingentry((strnumber) (s))
void bstexwarnprint (void);
void bstmildexwarnprint (void);
void bstcantmesswithentriesprint (void);
void illeglliteralconfusion (void);
void unknwnliteralconfusion (void);
void zprintstklit (integer stklt,stktype stktp);
#define printstklit(stklt, stktp) zprintstklit((integer) (stklt), (stktype) (stktp))
void zprintlit (integer stklt,stktype stktp);
#define printlit(stklt, stktp) zprintlit((integer) (stklt), (stktype) (stktp))
void outputbblline (void);
void bst1printstringsizeexceeded (void);
void bst2printstringsizeexceeded (void);
void zbracesunbalancedcomplaint (strnumber poplitvar);
#define bracesunbalancedcomplaint(poplitvar) zbracesunbalancedcomplaint((strnumber) (poplitvar))
void caseconversionconfusion (void);
void traceandstatprinting (void);
void zstartname (strnumber filename);
#define startname(filename) zstartname((strnumber) (filename))
void zaddextension (strnumber ext);
#define addextension(ext) zaddextension((strnumber) (ext))
strnumber makestring (void);
boolean zstreqbuf (strnumber s,buftype buf,bufpointer bfptr,bufpointer len);
#define streqbuf(s, buf, bfptr, len) zstreqbuf((strnumber) (s),  (buf), (bufpointer) (bfptr), (bufpointer) (len))
boolean zstreqstr (strnumber s1,strnumber s2);
#define streqstr(s1, s2) zstreqstr((strnumber) (s1), (strnumber) (s2))
void zlowercase (buftype buf,bufpointer bfptr,bufpointer len);
#define lowercase(buf, bfptr, len) zlowercase( (buf), (bufpointer) (bfptr), (bufpointer) (len))
void zuppercase (buftype buf,bufpointer bfptr,bufpointer len);
#define uppercase(buf, bfptr, len) zuppercase( (buf), (bufpointer) (bfptr), (bufpointer) (len))
hashloc zstrlookup (buftype buf,bufpointer j,bufpointer l,strilk ilk,boolean insertit);
#define strlookup(buf, j, l, ilk, insertit) zstrlookup( (buf), (bufpointer) (j), (bufpointer) (l), (strilk) (ilk), (boolean) (insertit))
void zpredefine (pdstype pds,pdslen len,strilk ilk);
#define predefine(pds, len, ilk) zpredefine( (pds), (pdslen) (len), (strilk) (ilk))
void zzinttoASCII (integer theint,buftype intbuf,bufpointer intbegin,bufpointer * intend);
#define inttoASCII(theint, intbuf, intbegin, intend) zzinttoASCII((integer) (theint),  (intbuf), (bufpointer) (intbegin), (bufpointer *) &(intend))
void zzadddatabasecite (citenumber * newcite);
#define adddatabasecite(newcite) zzadddatabasecite((citenumber *) &(newcite))
boolean zfindcitelocsforthiscitekey (strnumber citestr);
#define findcitelocsforthiscitekey(citestr) zfindcitelocsforthiscitekey((strnumber) (citestr))
void zswap (citenumber swap1,citenumber swap2);
#define swap(swap1, swap2) zswap((citenumber) (swap1), (citenumber) (swap2))
boolean zlessthan (citenumber arg1,citenumber arg2);
#define lessthan(arg1, arg2) zlessthan((citenumber) (arg1), (citenumber) (arg2))
void zquicksort (citenumber leftend,citenumber rightend);
#define quicksort(leftend, rightend) zquicksort((citenumber) (leftend), (citenumber) (rightend))
void zzbuildin (pdstype pds,pdslen len,hashloc * fnhashloc,bltinrange bltinnum);
#define buildin(pds, len, fnhashloc, bltinnum) zzbuildin( (pds), (pdslen) (len), (hashloc *) &(fnhashloc), (bltinrange) (bltinnum))
void predefcertainstrings (void);
boolean zscan1 (ASCIIcode char1);
#define scan1(char1) zscan1((ASCIIcode) (char1))
boolean zscan1white (ASCIIcode char1);
#define scan1white(char1) zscan1white((ASCIIcode) (char1))
boolean zscan2 (ASCIIcode char1,ASCIIcode char2);
#define scan2(char1, char2) zscan2((ASCIIcode) (char1), (ASCIIcode) (char2))
boolean zscan2white (ASCIIcode char1,ASCIIcode char2);
#define scan2white(char1, char2) zscan2white((ASCIIcode) (char1), (ASCIIcode) (char2))
boolean zscan3 (ASCIIcode char1,ASCIIcode char2,ASCIIcode char3);
#define scan3(char1, char2, char3) zscan3((ASCIIcode) (char1), (ASCIIcode) (char2), (ASCIIcode) (char3))
boolean scanalpha (void);
void zscanidentifier (ASCIIcode char1,ASCIIcode char2,ASCIIcode char3);
#define scanidentifier(char1, char2, char3) zscanidentifier((ASCIIcode) (char1), (ASCIIcode) (char2), (ASCIIcode) (char3))
boolean scannonneginteger (void);
boolean scaninteger (void);
boolean scanwhitespace (void);
boolean eatbstwhitespace (void);
void skiptokenprint (void);
void printrecursionillegal (void);
void skptokenunknownfunctionprint (void);
void skipillegalstuffaftertokenprint (void);
void zscanfndef (hashloc fnhashloc);
#define scanfndef(fnhashloc) zscanfndef((hashloc) (fnhashloc))
boolean eatbibwhitespace (void);
boolean compressbibwhite (void);
boolean scanbalancedbraces (void);
boolean scanafieldtokenandeatwhite (void);
boolean scanandstorethefieldvalueandeatwhite (void);
void zdecrbracelevel (strnumber poplitvar);
#define decrbracelevel(poplitvar) zdecrbracelevel((strnumber) (poplitvar))
void zcheckbracelevel (strnumber poplitvar);
#define checkbracelevel(poplitvar) zcheckbracelevel((strnumber) (poplitvar))
void znamescanforand (strnumber poplitvar);
#define namescanforand(poplitvar) znamescanforand((strnumber) (poplitvar))
boolean vontokenfound (void);
void vonnameendsandlastnamestartsstuff (void);
void skipstuffatspbracelevelgreaterthanone (void);
void bracelvloneletterscomplaint (void);
boolean zenoughtextchars (bufpointer enoughchars);
#define enoughtextchars(enoughchars) zenoughtextchars((bufpointer) (enoughchars))
void figureouttheformattedname (void);
void zpushlitstk (integer pushlt,stktype pushtype);
#define pushlitstk(pushlt, pushtype) zpushlitstk((integer) (pushlt), (stktype) (pushtype))
void zzpoplitstk (integer * poplit,stktype * poptype);
#define poplitstk(poplit, poptype) zzpoplitstk((integer *) &(poplit), (stktype *) &(poptype))
void zprintwrongstklit (integer stklt,stktype stktp1,stktype stktp2);
#define printwrongstklit(stklt, stktp1, stktp2) zprintwrongstklit((integer) (stklt), (stktype) (stktp1), (stktype) (stktp2))
void poptopandprint (void);
void popwholestack (void);
void initcommandexecution (void);
void checkcommandexecution (void);
void addpoolbufandpush (void);
void zaddbufpool (strnumber pstr);
#define addbufpool(pstr) zaddbufpool((strnumber) (pstr))
void zaddoutpool (strnumber pstr);
#define addoutpool(pstr) zaddoutpool((strnumber) (pstr))
void xequals (void);
void xgreaterthan (void);
void xlessthan (void);
void xplus (void);
void xminus (void);
void xconcatenate (void);
void xgets (void);
void xaddperiod (void);
void xchangecase (void);
void xchrtoint (void);
void xcite (void);
void xduplicate (void);
void xempty (void);
void xformatname (void);
void xinttochr (void);
void xinttostr (void);
void xmissing (void);
void xnumnames (void);
void xpreamble (void);
void xpurify (void);
void xquote (void);
void xsubstring (void);
void xswap (void);
void xtextlength (void);
void xtextprefix (void);
void xtype (void);
void xwarning (void);
void xwidth (void);
void xwrite (void);
void zexecutefn (hashloc exfnloc);
#define executefn(exfnloc) zexecutefn((hashloc) (exfnloc))
void getthetoplevelauxfilename (void);
void auxbibdatacommand (void);
void auxbibstylecommand (void);
void auxcitationcommand (void);
void auxinputcommand (void);
void poptheauxstack (void);
void getauxcommandandprocess (void);
void lastcheckforauxerrors (void);
void bstentrycommand (void);
boolean badargumenttoken (void);
void bstexecutecommand (void);
void bstfunctioncommand (void);
void bstintegerscommand (void);
void bstiteratecommand (void);
void bstmacrocommand (void);
void getbibcommandorentryandprocess (void);
void bstreadcommand (void);
void bstreversecommand (void);
void bstsortcommand (void);
void bststringscommand (void);
void getbstcommandandprocess (void);
void setupparams (void);
void computehashprime (void);
void initialize (void);
void parsearguments (void);
