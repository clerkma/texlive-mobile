void initialize (void);
#define initialize_regmem register memoryword *mem=zmem;
void println (void);
#define println_regmem
void zprintchar (ASCIIcode s);
#define printchar(s) zprintchar((ASCIIcode) (s))
#define printchar_regmem
void zprint (integer s);
#define print(s) zprint((integer) (s))
#define print_regmem
void zprintnl (strnumber s);
#define printnl(s) zprintnl((strnumber) (s))
#define printnl_regmem
void zomegaprint (strnumber s);
#define omegaprint(s) zomegaprint((strnumber) (s))
#define omegaprint_regmem
void zslowprint (integer s);
#define slowprint(s) zslowprint((integer) (s))
#define slowprint_regmem
void zprintesc (strnumber s);
#define printesc(s) zprintesc((strnumber) (s))
#define printesc_regmem
void zprintthedigs (eightbits k);
#define printthedigs(k) zprintthedigs((eightbits) (k))
#define printthedigs_regmem
void zprintint (integer n);
#define printint(n) zprintint((integer) (n))
#define printint_regmem
void zprintcs (integer p);
#define printcs(p) zprintcs((integer) (p))
#define printcs_regmem
void zsprintcs (halfword p);
#define sprintcs(p) zsprintcs((halfword) (p))
#define sprintcs_regmem
void zprintfilename (integer n,integer a,integer e);
#define printfilename(n, a, e) zprintfilename((integer) (n), (integer) (a), (integer) (e))
#define printfilename_regmem
void zprintsize (integer s);
#define printsize(s) zprintsize((integer) (s))
#define printsize_regmem
void zprintwritewhatsit (strnumber s,halfword p);
#define printwritewhatsit(s, p) zprintwritewhatsit((strnumber) (s), (halfword) (p))
#define printwritewhatsit_regmem register memoryword *mem=zmem;
void zprintsanum (halfword q);
#define printsanum(q) zprintsanum((halfword) (q))
#define printsanum_regmem register memoryword *mem=zmem;
void zprintcsnames (integer hstart,integer hfinish);
#define printcsnames(hstart, hfinish) zprintcsnames((integer) (hstart), (integer) (hfinish))
#define printcsnames_regmem
void printfileline (void);
#define printfileline_regmem
void jumpout (void);
#define jumpout_regmem
void error (void);
#define error_regmem
void zfatalerror (strnumber s);
#define fatalerror(s) zfatalerror((strnumber) (s))
#define fatalerror_regmem
void zoverflow (strnumber s,integer n);
#define overflow(s, n) zoverflow((strnumber) (s), (integer) (n))
#define overflow_regmem
void overflowocpbufsize (void);
#define overflowocpbufsize_regmem
void overflowocpstacksize (void);
#define overflowocpstacksize_regmem
void zconfusion (strnumber s);
#define confusion(s) zconfusion((strnumber) (s))
#define confusion_regmem
boolean initterminal (void);
#define initterminal_regmem
integer zlength (strnumber s);
#define length(s) zlength((strnumber) (s))
#define length_regmem
strnumber makestring (void);
#define makestring_regmem
boolean zstreqbuf (strnumber s,integer k);
#define streqbuf(s, k) zstreqbuf((strnumber) (s), (integer) (k))
#define streqbuf_regmem
boolean zstreqstr (strnumber s,strnumber t);
#define streqstr(s, t) zstreqstr((strnumber) (s), (strnumber) (t))
#define streqstr_regmem
strnumber zsearchstring (strnumber search);
#define searchstring(search) zsearchstring((strnumber) (search))
#define searchstring_regmem
strnumber slowmakestring (void);
#define slowmakestring_regmem
boolean getstringsstarted (void);
#define getstringsstarted_regmem
void zprinttwo (integer n);
#define printtwo(n) zprinttwo((integer) (n))
#define printtwo_regmem
void zprinthex (integer n);
#define printhex(n) zprinthex((integer) (n))
#define printhex_regmem
void zprintromanint (integer n);
#define printromanint(n) zprintromanint((integer) (n))
#define printromanint_regmem
void printcurrentstring (void);
#define printcurrentstring_regmem
void terminput (void);
#define terminput_regmem
void zinterror (integer n);
#define interror(n) zinterror((integer) (n))
#define interror_regmem
void normalizeselector (void);
#define normalizeselector_regmem
void pauseforinstructions (void);
#define pauseforinstructions_regmem
integer zhalf (integer x);
#define half(x) zhalf((integer) (x))
#define half_regmem
scaled zrounddecimals (smallnumber k);
#define rounddecimals(k) zrounddecimals((smallnumber) (k))
#define rounddecimals_regmem
void zprintscaled (scaled s);
#define printscaled(s) zprintscaled((scaled) (s))
#define printscaled_regmem
scaled zmultandadd (integer n,scaled x,scaled y,scaled maxanswer);
#define multandadd(n, x, y, maxanswer) zmultandadd((integer) (n), (scaled) (x), (scaled) (y), (scaled) (maxanswer))
#define multandadd_regmem
scaled zxovern (scaled x,integer n);
#define xovern(x, n) zxovern((scaled) (x), (integer) (n))
#define xovern_regmem
scaled zxnoverd (scaled x,integer n,integer d);
#define xnoverd(x, n, d) zxnoverd((scaled) (x), (integer) (n), (integer) (d))
#define xnoverd_regmem
halfword zbadness (scaled t,scaled s);
#define badness(t, s) zbadness((scaled) (t), (scaled) (s))
#define badness_regmem
void zprintword (memoryword w);
#define printword(w) zprintword((memoryword) (w))
#define printword_regmem
void zshowtokenlist (integer p,integer q,integer l);
#define showtokenlist(p, q, l) zshowtokenlist((integer) (p), (integer) (q), (integer) (l))
#define showtokenlist_regmem register memoryword *mem=zmem;
void runaway (void);
#define runaway_regmem register memoryword *mem=zmem;
halfword getavail (void);
#define getavail_regmem register memoryword *mem=zmem;
void zflushlist (halfword p);
#define flushlist(p) zflushlist((halfword) (p))
#define flushlist_regmem register memoryword *mem=zmem;
halfword zgetnode (integer s);
#define getnode(s) zgetnode((integer) (s))
#define getnode_regmem register memoryword *mem=zmem;
void zfreenode (halfword p,halfword s);
#define freenode(p, s) zfreenode((halfword) (p), (halfword) (s))
#define freenode_regmem register memoryword *mem=zmem;
void sortavail (void);
#define sortavail_regmem register memoryword *mem=zmem;
halfword newnullbox (void);
#define newnullbox_regmem register memoryword *mem=zmem;
halfword newrule (void);
#define newrule_regmem register memoryword *mem=zmem;
halfword znewligature (quarterword f,quarterword c,halfword q);
#define newligature(f, c, q) znewligature((quarterword) (f), (quarterword) (c), (halfword) (q))
#define newligature_regmem register memoryword *mem=zmem;
halfword znewligitem (quarterword c);
#define newligitem(c) znewligitem((quarterword) (c))
#define newligitem_regmem register memoryword *mem=zmem;
halfword newdisc (void);
#define newdisc_regmem register memoryword *mem=zmem;
halfword znewmath (scaled w,smallnumber s);
#define newmath(w, s) znewmath((scaled) (w), (smallnumber) (s))
#define newmath_regmem register memoryword *mem=zmem;
halfword znewspec (halfword p);
#define newspec(p) znewspec((halfword) (p))
#define newspec_regmem register memoryword *mem=zmem;
halfword znewparamglue (smallnumber n);
#define newparamglue(n) znewparamglue((smallnumber) (n))
#define newparamglue_regmem register memoryword *mem=zmem;
halfword znewglue (halfword q);
#define newglue(q) znewglue((halfword) (q))
#define newglue_regmem register memoryword *mem=zmem;
halfword znewskipparam (smallnumber n);
#define newskipparam(n) znewskipparam((smallnumber) (n))
#define newskipparam_regmem register memoryword *mem=zmem;
halfword znewkern (scaled w);
#define newkern(w) znewkern((scaled) (w))
#define newkern_regmem register memoryword *mem=zmem;
halfword znewpenalty (integer m);
#define newpenalty(m) znewpenalty((integer) (m))
#define newpenalty_regmem register memoryword *mem=zmem;
void zcheckmem (boolean printlocs);
#define checkmem(printlocs) zcheckmem((boolean) (printlocs))
#define checkmem_regmem register memoryword *mem=zmem;
void zsearchmem (halfword p);
#define searchmem(p) zsearchmem((halfword) (p))
#define searchmem_regmem register memoryword *mem=zmem;
void zshortdisplay (integer p);
#define shortdisplay(p) zshortdisplay((integer) (p))
#define shortdisplay_regmem register memoryword *mem=zmem;
void zprintfontandchar (integer p);
#define printfontandchar(p) zprintfontandchar((integer) (p))
#define printfontandchar_regmem register memoryword *mem=zmem;
void zprintmark (integer p);
#define printmark(p) zprintmark((integer) (p))
#define printmark_regmem register memoryword *mem=zmem;
void zprintruledimen (scaled d);
#define printruledimen(d) zprintruledimen((scaled) (d))
#define printruledimen_regmem
void zprintdir (integer d);
#define printdir(d) zprintdir((integer) (d))
#define printdir_regmem
void zprintglue (scaled d,integer order,strnumber s);
#define printglue(d, order, s) zprintglue((scaled) (d), (integer) (order), (strnumber) (s))
#define printglue_regmem
void zprintspec (integer p,strnumber s);
#define printspec(p, s) zprintspec((integer) (p), (strnumber) (s))
#define printspec_regmem register memoryword *mem=zmem;
void zprintfamandchar (halfword p);
#define printfamandchar(p) zprintfamandchar((halfword) (p))
#define printfamandchar_regmem register memoryword *mem=zmem;
void zprintdelimiter (halfword p);
#define printdelimiter(p) zprintdelimiter((halfword) (p))
#define printdelimiter_regmem register memoryword *mem=zmem;
void zprintsubsidiarydata (halfword p,ASCIIcode c);
#define printsubsidiarydata(p, c) zprintsubsidiarydata((halfword) (p), (ASCIIcode) (c))
#define printsubsidiarydata_regmem register memoryword *mem=zmem;
void zprintstyle (integer c);
#define printstyle(c) zprintstyle((integer) (c))
#define printstyle_regmem
void zprintskipparam (integer n);
#define printskipparam(n) zprintskipparam((integer) (n))
#define printskipparam_regmem
void zshownodelist (integer p);
#define shownodelist(p) zshownodelist((integer) (p))
#define shownodelist_regmem register memoryword *mem=zmem;
void zshowbox (halfword p);
#define showbox(p) zshowbox((halfword) (p))
#define showbox_regmem
void zdeletetokenref (halfword p);
#define deletetokenref(p) zdeletetokenref((halfword) (p))
#define deletetokenref_regmem register memoryword *mem=zmem;
void zdeleteglueref (halfword p);
#define deleteglueref(p) zdeleteglueref((halfword) (p))
#define deleteglueref_regmem register memoryword *mem=zmem;
void zflushnodelist (halfword p);
#define flushnodelist(p) zflushnodelist((halfword) (p))
#define flushnodelist_regmem register memoryword *mem=zmem;
halfword zcopynodelist (halfword p);
#define copynodelist(p) zcopynodelist((halfword) (p))
#define copynodelist_regmem register memoryword *mem=zmem;
void zprintmode (integer m);
#define printmode(m) zprintmode((integer) (m))
#define printmode_regmem
halfword makelocalparnode (void);
#define makelocalparnode_regmem register memoryword *mem=zmem;
halfword znewdir (smallnumber s);
#define newdir(s) znewdir((smallnumber) (s))
#define newdir_regmem register memoryword *mem=zmem;
void pushnest (void);
#define pushnest_regmem
void popnest (void);
#define popnest_regmem register memoryword *mem=zmem;
void showactivities (void);
#define showactivities_regmem register memoryword *mem=zmem;
void zprintparam (integer n);
#define printparam(n) zprintparam((integer) (n))
#define printparam_regmem
void begindiagnostic (void);
#define begindiagnostic_regmem
void zenddiagnostic (boolean blankline);
#define enddiagnostic(blankline) zenddiagnostic((boolean) (blankline))
#define enddiagnostic_regmem
void zprintlengthparam (integer n);
#define printlengthparam(n) zprintlengthparam((integer) (n))
#define printlengthparam_regmem
memoryword ziniteqtbentry (halfword p);
#define initeqtbentry(p) ziniteqtbentry((halfword) (p))
#define initeqtbentry_regmem
void zprintcmdchr (quarterword cmd,halfword chrcode);
#define printcmdchr(cmd, chrcode) zprintcmdchr((quarterword) (cmd), (halfword) (chrcode))
#define printcmdchr_regmem register memoryword *mem=zmem;
void zshoweqtb (halfword n);
#define showeqtb(n) zshoweqtb((halfword) (n))
#define showeqtb_regmem register memoryword *mem=zmem;
halfword zidlookup (integer j,integer l);
#define idlookup(j, l) zidlookup((integer) (j), (integer) (l))
#define idlookup_regmem
void zprimitive (strnumber s,quarterword c,halfword o);
#define primitive(s, c, o) zprimitive((strnumber) (s), (quarterword) (c), (halfword) (o))
#define primitive_regmem
void zrestoretrace (halfword p,strnumber s);
#define restoretrace(p, s) zrestoretrace((halfword) (p), (strnumber) (s))
#define restoretrace_regmem
void zprintgroup (boolean e);
#define printgroup(e) zprintgroup((boolean) (e))
#define printgroup_regmem
void zgrouptrace (boolean e);
#define grouptrace(e) zgrouptrace((boolean) (e))
#define grouptrace_regmem
boolean pseudoinput (void);
#define pseudoinput_regmem register memoryword *mem=zmem;
void pseudoclose (void);
#define pseudoclose_regmem register memoryword *mem=zmem;
void groupwarning (void);
#define groupwarning_regmem
void ifwarning (void);
#define ifwarning_regmem register memoryword *mem=zmem;
void filewarning (void);
#define filewarning_regmem register memoryword *mem=zmem;
void zdeletesaref (halfword q);
#define deletesaref(q) zdeletesaref((halfword) (q))
#define deletesaref_regmem register memoryword *mem=zmem;
void zshowsa (halfword p,strnumber s);
#define showsa(p, s) zshowsa((halfword) (p), (strnumber) (s))
#define showsa_regmem
void zsasave (halfword p);
#define sasave(p) zsasave((halfword) (p))
#define sasave_regmem register memoryword *mem=zmem;
void zsadestroy (halfword p);
#define sadestroy(p) zsadestroy((halfword) (p))
#define sadestroy_regmem register memoryword *mem=zmem;
void zsadef (halfword p,halfword e);
#define sadef(p, e) zsadef((halfword) (p), (halfword) (e))
#define sadef_regmem register memoryword *mem=zmem;
void zsawdef (halfword p,integer w);
#define sawdef(p, w) zsawdef((halfword) (p), (integer) (w))
#define sawdef_regmem register memoryword *mem=zmem;
void zgsadef (halfword p,halfword e);
#define gsadef(p, e) zgsadef((halfword) (p), (halfword) (e))
#define gsadef_regmem register memoryword *mem=zmem;
void zgsawdef (halfword p,integer w);
#define gsawdef(p, w) zgsawdef((halfword) (p), (integer) (w))
#define gsawdef_regmem register memoryword *mem=zmem;
void sarestore (void);
#define sarestore_regmem register memoryword *mem=zmem;
void znewsavelevel (groupcode c);
#define newsavelevel(c) znewsavelevel((groupcode) (c))
#define newsavelevel_regmem
void zeqdestroy (memoryword w);
#define eqdestroy(w) zeqdestroy((memoryword) (w))
#define eqdestroy_regmem register memoryword *mem=zmem;
void zeqsave (halfword p,quarterword l);
#define eqsave(p, l) zeqsave((halfword) (p), (quarterword) (l))
#define eqsave_regmem
void zeqdefine (halfword p,quarterword t,halfword e);
#define eqdefine(p, t, e) zeqdefine((halfword) (p), (quarterword) (t), (halfword) (e))
#define eqdefine_regmem
void zeqworddefine (halfword p,integer w);
#define eqworddefine(p, w) zeqworddefine((halfword) (p), (integer) (w))
#define eqworddefine_regmem
void zdeleqworddefine (halfword p,integer w,integer wone);
#define deleqworddefine(p, w, wone) zdeleqworddefine((halfword) (p), (integer) (w), (integer) (wone))
#define deleqworddefine_regmem
void zgeqdefine (halfword p,quarterword t,halfword e);
#define geqdefine(p, t, e) zgeqdefine((halfword) (p), (quarterword) (t), (halfword) (e))
#define geqdefine_regmem
void zgeqworddefine (halfword p,integer w);
#define geqworddefine(p, w) zgeqworddefine((halfword) (p), (integer) (w))
#define geqworddefine_regmem
void zdelgeqworddefine (halfword p,integer w,integer wone);
#define delgeqworddefine(p, w, wone) zdelgeqworddefine((halfword) (p), (integer) (w), (integer) (wone))
#define delgeqworddefine_regmem
void zsaveforafter (halfword t);
#define saveforafter(t) zsaveforafter((halfword) (t))
#define saveforafter_regmem
void unsave (void);
#define unsave_regmem register memoryword *mem=zmem;
void preparemag (void);
#define preparemag_regmem
void ztokenshow (halfword p);
#define tokenshow(p) ztokenshow((halfword) (p))
#define tokenshow_regmem register memoryword *mem=zmem;
void printmeaning (void);
#define printmeaning_regmem
void showcurcmdchr (void);
#define showcurcmdchr_regmem register memoryword *mem=zmem;
void showcontext (void);
#define showcontext_regmem register memoryword *mem=zmem;
void zbegintokenlist (halfword p,quarterword t);
#define begintokenlist(p, t) zbegintokenlist((halfword) (p), (quarterword) (t))
#define begintokenlist_regmem register memoryword *mem=zmem;
void endtokenlist (void);
#define endtokenlist_regmem
void backinput (void);
#define backinput_regmem register memoryword *mem=zmem;
void backerror (void);
#define backerror_regmem
void inserror (void);
#define inserror_regmem
void beginfilereading (void);
#define beginfilereading_regmem
void endfilereading (void);
#define endfilereading_regmem
void clearforerrorprompt (void);
#define clearforerrorprompt_regmem
void checkoutervalidity (void);
#define checkoutervalidity_regmem register memoryword *mem=zmem;
void getnext (void);
#define getnext_regmem register memoryword *mem=zmem;
void firmuptheline (void);
#define firmuptheline_regmem
void gettoken (void);
#define gettoken_regmem
void macrocall (void);
#define macrocall_regmem register memoryword *mem=zmem;
void insertrelax (void);
#define insertrelax_regmem
void znewindex (quarterword i,halfword q);
#define newindex(i, q) znewindex((quarterword) (i), (halfword) (q))
#define newindex_regmem register memoryword *mem=zmem;
void zfindsaelement (smallnumber t,halfword n,boolean w);
#define findsaelement(t, n, w) zfindsaelement((smallnumber) (t), (halfword) (n), (boolean) (w))
#define findsaelement_regmem register memoryword *mem=zmem;
void expand (void);
#define expand_regmem register memoryword *mem=zmem;
void getxtoken (void);
#define getxtoken_regmem
void xtoken (void);
#define xtoken_regmem
void scanleftbrace (void);
#define scanleftbrace_regmem
void scanrightbrace (void);
#define scanrightbrace_regmem
void scanoptionalequals (void);
#define scanoptionalequals_regmem
boolean zscankeyword (strnumber s);
#define scankeyword(s) zscankeyword((strnumber) (s))
#define scankeyword_regmem register memoryword *mem=zmem;
void muerror (void);
#define muerror_regmem
void scandir (void);
#define scandir_regmem
void scaneightbitint (void);
#define scaneightbitint_regmem
void scancharnum (void);
#define scancharnum_regmem
void scanfourbitint (void);
#define scanfourbitint_regmem
void scanbigfourbitint (void);
#define scanbigfourbitint_regmem
void scanrealfifteenbitint (void);
#define scanrealfifteenbitint_regmem
void scanfifteenbitint (void);
#define scanfifteenbitint_regmem
void scanbigfifteenbitint (void);
#define scanbigfifteenbitint_regmem
void scantwentysevenbitint (void);
#define scantwentysevenbitint_regmem
void scanfiftyonebitint (void);
#define scanfiftyonebitint_regmem
void scanstringargument (void);
#define scanstringargument_regmem
void scanregisternum (void);
#define scanregisternum_regmem
void scanfourbitintor18 (void);
#define scanfourbitintor18_regmem
void getxorprotected (void);
#define getxorprotected_regmem register memoryword *mem=zmem;
void scanfontident (void);
#define scanfontident_regmem
void zfindfontdimen (boolean writing);
#define findfontdimen(writing) zfindfontdimen((boolean) (writing))
#define findfontdimen_regmem
void scanocpident (void);
#define scanocpident_regmem
void zscansomethinginternal (smallnumber level,boolean negative);
#define scansomethinginternal(level, negative) zscansomethinginternal((smallnumber) (level), (boolean) (negative))
#define scansomethinginternal_regmem register memoryword *mem=zmem;
void scanint (void);
#define scanint_regmem
void zscandimen (boolean mu,boolean inf,boolean shortcut);
#define scandimen(mu, inf, shortcut) zscandimen((boolean) (mu), (boolean) (inf), (boolean) (shortcut))
#define scandimen_regmem register memoryword *mem=zmem;
void zscanglue (smallnumber level);
#define scanglue(level) zscanglue((smallnumber) (level))
#define scanglue_regmem register memoryword *mem=zmem;
integer zaddorsub (integer x,integer y,integer maxanswer,boolean negative);
#define addorsub(x, y, maxanswer, negative) zaddorsub((integer) (x), (integer) (y), (integer) (maxanswer), (boolean) (negative))
#define addorsub_regmem
integer zquotient (integer n,integer d);
#define quotient(n, d) zquotient((integer) (n), (integer) (d))
#define quotient_regmem
integer zfract (integer x,integer n,integer d,integer maxanswer);
#define fract(x, n, d, maxanswer) zfract((integer) (x), (integer) (n), (integer) (d), (integer) (maxanswer))
#define fract_regmem
void scanexpr (void);
#define scanexpr_regmem register memoryword *mem=zmem;
void scannormalglue (void);
#define scannormalglue_regmem
void scanmuglue (void);
#define scanmuglue_regmem
halfword scanrulespec (void);
#define scanrulespec_regmem register memoryword *mem=zmem;
void scangeneraltext (void);
#define scangeneraltext_regmem register memoryword *mem=zmem;
void pseudostart (void);
#define pseudostart_regmem register memoryword *mem=zmem;
halfword zstrtoks (poolpointer b);
#define strtoks(b) zstrtoks((poolpointer) (b))
#define strtoks_regmem register memoryword *mem=zmem;
halfword thetoks (void);
#define thetoks_regmem register memoryword *mem=zmem;
void insthetoks (void);
#define insthetoks_regmem register memoryword *mem=zmem;
void convtoks (void);
#define convtoks_regmem register memoryword *mem=zmem;
halfword zscantoks (boolean macrodef,boolean xpand);
#define scantoks(macrodef, xpand) zscantoks((boolean) (macrodef), (boolean) (xpand))
#define scantoks_regmem register memoryword *mem=zmem;
void zreadtoks (integer n,halfword r,halfword j);
#define readtoks(n, r, j) zreadtoks((integer) (n), (halfword) (r), (halfword) (j))
#define readtoks_regmem register memoryword *mem=zmem;
void passtext (void);
#define passtext_regmem
void zchangeiflimit (smallnumber l,halfword p);
#define changeiflimit(l, p) zchangeiflimit((smallnumber) (l), (halfword) (p))
#define changeiflimit_regmem register memoryword *mem=zmem;
void conditional (void);
#define conditional_regmem register memoryword *mem=zmem;
void beginname (void);
#define beginname_regmem
boolean zmorename (ASCIIcode c);
#define morename(c) zmorename((ASCIIcode) (c))
#define morename_regmem
void endname (void);
#define endname_regmem
void zpackfilename (strnumber n,strnumber a,strnumber e);
#define packfilename(n, a, e) zpackfilename((strnumber) (n), (strnumber) (a), (strnumber) (e))
#define packfilename_regmem
void zpackbufferedname (smallnumber n,integer a,integer b);
#define packbufferedname(n, a, b) zpackbufferedname((smallnumber) (n), (integer) (a), (integer) (b))
#define packbufferedname_regmem
strnumber makenamestring (void);
#define makenamestring_regmem
strnumber zamakenamestring (alphafile f);
#define amakenamestring(f) zamakenamestring((alphafile) (f))
#define amakenamestring_regmem
strnumber zbmakenamestring (bytefile f);
#define bmakenamestring(f) zbmakenamestring((bytefile) (f))
#define bmakenamestring_regmem
strnumber zwmakenamestring (wordfile f);
#define wmakenamestring(f) zwmakenamestring((wordfile) (f))
#define wmakenamestring_regmem
void scanfilename (void);
#define scanfilename_regmem
void zpackjobname (strnumber s);
#define packjobname(s) zpackjobname((strnumber) (s))
#define packjobname_regmem
void zpromptfilename (strnumber s,strnumber e);
#define promptfilename(s, e) zpromptfilename((strnumber) (s), (strnumber) (e))
#define promptfilename_regmem
void openlogfile (void);
#define openlogfile_regmem
void startinput (void);
#define startinput_regmem
internalfontnumber zreadfontinfo (halfword u,strnumber nom,strnumber aire,scaled s,quarterword offset,integer naturaldir);
#define readfontinfo(u, nom, aire, s, offset, naturaldir) zreadfontinfo((halfword) (u), (strnumber) (nom), (strnumber) (aire), (scaled) (s), (quarterword) (offset), (integer) (naturaldir))
#define readfontinfo_regmem
void zcharwarning (internalfontnumber f,eightbits c);
#define charwarning(f, c) zcharwarning((internalfontnumber) (f), (eightbits) (c))
#define charwarning_regmem
halfword znewcharacter (internalfontnumber f,eightbits c);
#define newcharacter(f, c) znewcharacter((internalfontnumber) (f), (eightbits) (c))
#define newcharacter_regmem register memoryword *mem=zmem;
integer zislastocp (scaled llstackno,integer counter);
#define islastocp(llstackno, counter) zislastocp((scaled) (llstackno), (integer) (counter))
#define islastocp_regmem
void printactiveocps (void);
#define printactiveocps_regmem
void zaddocpstack (integer minindex,scaled minvalue);
#define addocpstack(minindex, minvalue) zaddocpstack((integer) (minindex), (scaled) (minvalue))
#define addocpstack_regmem
void activecompile (void);
#define activecompile_regmem
internalocpnumber zreadocpinfo (halfword u,strnumber nom,strnumber aire,strnumber ext,boolean externalocp);
#define readocpinfo(u, nom, aire, ext, externalocp) zreadocpinfo((halfword) (u), (strnumber) (nom), (strnumber) (aire), (strnumber) (ext), (boolean) (externalocp))
#define readocpinfo_regmem
ocplistindex zmakeocplistnode (ocplstackindex llstack,scaled llstackno,ocplistindex llnext);
#define makeocplistnode(llstack, llstackno, llnext) zmakeocplistnode((ocplstackindex) (llstack), (scaled) (llstackno), (ocplistindex) (llnext))
#define makeocplistnode_regmem
ocplstackindex zmakeocplstacknode (internalocpnumber locp,ocplstackindex llnext);
#define makeocplstacknode(locp, llnext) zmakeocplstacknode((internalocpnumber) (locp), (ocplstackindex) (llnext))
#define makeocplstacknode_regmem
ocplstackindex zcopyocplstack (ocplstackindex llstack);
#define copyocplstack(llstack) zcopyocplstack((ocplstackindex) (llstack))
#define copyocplstack_regmem
ocplistindex zcopyocplist (ocplistindex list);
#define copyocplist(list) zcopyocplist((ocplistindex) (list))
#define copyocplist_regmem
ocplistindex zocpensurelstack (ocplistindex list,scaled llstackno);
#define ocpensurelstack(list, llstackno) zocpensurelstack((ocplistindex) (list), (scaled) (llstackno))
#define ocpensurelstack_regmem
void zocpapplyadd (ocplistindex listentry,boolean lbefore,internalocpnumber locp);
#define ocpapplyadd(listentry, lbefore, locp) zocpapplyadd((ocplistindex) (listentry), (boolean) (lbefore), (internalocpnumber) (locp))
#define ocpapplyadd_regmem
void zocpapplyremove (ocplistindex listentry,boolean lbefore);
#define ocpapplyremove(listentry, lbefore) zocpapplyremove((ocplistindex) (listentry), (boolean) (lbefore))
#define ocpapplyremove_regmem
void scanscaled (void);
#define scanscaled_regmem register memoryword *mem=zmem;
void zprintocplstack (ocplstackindex lstackentry);
#define printocplstack(lstackentry) zprintocplstack((ocplstackindex) (lstackentry))
#define printocplstack_regmem
void zprintocplist (ocplistindex listentry);
#define printocplist(listentry) zprintocplist((ocplistindex) (listentry))
#define printocplist_regmem
ocplistindex scanocplist (void);
#define scanocplist_regmem
internalocplistnumber readocplist (void);
#define readocplist_regmem
void scanocplistident (void);
#define scanocplistident_regmem
void dviswap (void);
#define dviswap_regmem
void zdvifour (integer x);
#define dvifour(x) zdvifour((integer) (x))
#define dvifour_regmem
void zdvipop (integer l);
#define dvipop(l) zdvipop((integer) (l))
#define dvipop_regmem
void zdvifontdef (internalfontnumber f);
#define dvifontdef(f) zdvifontdef((internalfontnumber) (f))
#define dvifontdef_regmem
void zmovement (scaled w,eightbits o);
#define movement(w, o) zmovement((scaled) (w), (eightbits) (o))
#define movement_regmem register memoryword *mem=zmem;
void zprunemovements (integer l);
#define prunemovements(l) zprunemovements((integer) (l))
#define prunemovements_regmem register memoryword *mem=zmem;
void zspecialout (halfword p);
#define specialout(p) zspecialout((halfword) (p))
#define specialout_regmem register memoryword *mem=zmem;
void zwriteout (halfword p);
#define writeout(p) zwriteout((halfword) (p))
#define writeout_regmem register memoryword *mem=zmem;
void zoutwhat (halfword p);
#define outwhat(p) zoutwhat((halfword) (p))
#define outwhat_regmem register memoryword *mem=zmem;
void hlistout (void);
#define hlistout_regmem register memoryword *mem=zmem;
void vlistout (void);
#define vlistout_regmem register memoryword *mem=zmem;
void zshipout (halfword p);
#define shipout(p) zshipout((halfword) (p))
#define shipout_regmem register memoryword *mem=zmem;
void zscanspec (groupcode c,boolean threecodes);
#define scanspec(c, threecodes) zscanspec((groupcode) (c), (boolean) (threecodes))
#define scanspec_regmem
halfword zhpack (halfword p,scaled w,smallnumber m);
#define hpack(p, w, m) zhpack((halfword) (p), (scaled) (w), (smallnumber) (m))
#define hpack_regmem register memoryword *mem=zmem;
halfword zvpackage (halfword p,scaled h,smallnumber m,scaled l);
#define vpackage(p, h, m, l) zvpackage((halfword) (p), (scaled) (h), (smallnumber) (m), (scaled) (l))
#define vpackage_regmem register memoryword *mem=zmem;
void zappendtovlist (halfword b);
#define appendtovlist(b) zappendtovlist((halfword) (b))
#define appendtovlist_regmem register memoryword *mem=zmem;
halfword newnoad (void);
#define newnoad_regmem register memoryword *mem=zmem;
halfword znewstyle (smallnumber s);
#define newstyle(s) znewstyle((smallnumber) (s))
#define newstyle_regmem register memoryword *mem=zmem;
halfword newchoice (void);
#define newchoice_regmem register memoryword *mem=zmem;
void showinfo (void);
#define showinfo_regmem register memoryword *mem=zmem;
halfword zfractionrule (scaled t);
#define fractionrule(t) zfractionrule((scaled) (t))
#define fractionrule_regmem register memoryword *mem=zmem;
halfword zoverbar (halfword b,scaled k,scaled t);
#define overbar(b, k, t) zoverbar((halfword) (b), (scaled) (k), (scaled) (t))
#define overbar_regmem register memoryword *mem=zmem;
halfword zcharbox (internalfontnumber f,quarterword c);
#define charbox(f, c) zcharbox((internalfontnumber) (f), (quarterword) (c))
#define charbox_regmem register memoryword *mem=zmem;
void zstackintobox (halfword b,internalfontnumber f,quarterword c);
#define stackintobox(b, f, c) zstackintobox((halfword) (b), (internalfontnumber) (f), (quarterword) (c))
#define stackintobox_regmem register memoryword *mem=zmem;
scaled zheightplusdepth (internalfontnumber f,quarterword c);
#define heightplusdepth(f, c) zheightplusdepth((internalfontnumber) (f), (quarterword) (c))
#define heightplusdepth_regmem
halfword zvardelimiter (halfword d,integer s,scaled v);
#define vardelimiter(d, s, v) zvardelimiter((halfword) (d), (integer) (s), (scaled) (v))
#define vardelimiter_regmem register memoryword *mem=zmem;
halfword zrebox (halfword b,scaled w);
#define rebox(b, w) zrebox((halfword) (b), (scaled) (w))
#define rebox_regmem register memoryword *mem=zmem;
halfword zmathglue (halfword g,scaled m);
#define mathglue(g, m) zmathglue((halfword) (g), (scaled) (m))
#define mathglue_regmem register memoryword *mem=zmem;
void zmathkern (halfword p,scaled m);
#define mathkern(p, m) zmathkern((halfword) (p), (scaled) (m))
#define mathkern_regmem register memoryword *mem=zmem;
void flushmath (void);
#define flushmath_regmem register memoryword *mem=zmem;
halfword zcleanbox (halfword p,integer s);
#define cleanbox(p, s) zcleanbox((halfword) (p), (integer) (s))
#define cleanbox_regmem register memoryword *mem=zmem;
void zfetch (halfword a);
#define fetch(a) zfetch((halfword) (a))
#define fetch_regmem register memoryword *mem=zmem;
void zmakeover (halfword q);
#define makeover(q) zmakeover((halfword) (q))
#define makeover_regmem register memoryword *mem=zmem;
void zmakeunder (halfword q);
#define makeunder(q) zmakeunder((halfword) (q))
#define makeunder_regmem register memoryword *mem=zmem;
void zmakevcenter (halfword q);
#define makevcenter(q) zmakevcenter((halfword) (q))
#define makevcenter_regmem register memoryword *mem=zmem;
void zmakeradical (halfword q);
#define makeradical(q) zmakeradical((halfword) (q))
#define makeradical_regmem register memoryword *mem=zmem;
void zmakemathaccent (halfword q);
#define makemathaccent(q) zmakemathaccent((halfword) (q))
#define makemathaccent_regmem register memoryword *mem=zmem;
void zmakefraction (halfword q);
#define makefraction(q) zmakefraction((halfword) (q))
#define makefraction_regmem register memoryword *mem=zmem;
scaled zmakeop (halfword q);
#define makeop(q) zmakeop((halfword) (q))
#define makeop_regmem register memoryword *mem=zmem;
void zmakeord (halfword q);
#define makeord(q) zmakeord((halfword) (q))
#define makeord_regmem register memoryword *mem=zmem;
void zmakescripts (halfword q,scaled delta);
#define makescripts(q, delta) zmakescripts((halfword) (q), (scaled) (delta))
#define makescripts_regmem register memoryword *mem=zmem;
integer zmakeleftright (halfword q,integer style,scaled maxd,scaled maxh);
#define makeleftright(q, style, maxd, maxh) zmakeleftright((halfword) (q), (integer) (style), (scaled) (maxd), (scaled) (maxh))
#define makeleftright_regmem register memoryword *mem=zmem;
void mlisttohlist (void);
#define mlisttohlist_regmem register memoryword *mem=zmem;
void pushalignment (void);
#define pushalignment_regmem register memoryword *mem=zmem;
void popalignment (void);
#define popalignment_regmem register memoryword *mem=zmem;
void getpreambletoken (void);
#define getpreambletoken_regmem
void initalign (void);
#define initalign_regmem register memoryword *mem=zmem;
void zinitspan (halfword p);
#define initspan(p) zinitspan((halfword) (p))
#define initspan_regmem
void initrow (void);
#define initrow_regmem register memoryword *mem=zmem;
void initcol (void);
#define initcol_regmem register memoryword *mem=zmem;
boolean fincol (void);
#define fincol_regmem register memoryword *mem=zmem;
void finrow (void);
#define finrow_regmem register memoryword *mem=zmem;
void finalign (void);
#define finalign_regmem register memoryword *mem=zmem;
void alignpeek (void);
#define alignpeek_regmem
halfword zfiniteshrink (halfword p);
#define finiteshrink(p) zfiniteshrink((halfword) (p))
#define finiteshrink_regmem register memoryword *mem=zmem;
void ztrybreak (integer pi,smallnumber breaktype);
#define trybreak(pi, breaktype) ztrybreak((integer) (pi), (smallnumber) (breaktype))
#define trybreak_regmem register memoryword *mem=zmem;
void zpostlinebreak (boolean d);
#define postlinebreak(d) zpostlinebreak((boolean) (d))
#define postlinebreak_regmem register memoryword *mem=zmem;
smallnumber zreconstitute (smallnumber j,smallnumber n,halfword bchar,halfword hchar);
#define reconstitute(j, n, bchar, hchar) zreconstitute((smallnumber) (j), (smallnumber) (n), (halfword) (bchar), (halfword) (hchar))
#define reconstitute_regmem register memoryword *mem=zmem;
void hyphenate (void);
#define hyphenate_regmem register memoryword *mem=zmem;
quarterword znewtrieop (smallnumber d,smallnumber n,quarterword v);
#define newtrieop(d, n, v) znewtrieop((smallnumber) (d), (smallnumber) (n), (quarterword) (v))
#define newtrieop_regmem
triepointer ztrienode (triepointer p);
#define trienode(p) ztrienode((triepointer) (p))
#define trienode_regmem
triepointer zcompresstrie (triepointer p);
#define compresstrie(p) zcompresstrie((triepointer) (p))
#define compresstrie_regmem
void zfirstfit (triepointer p);
#define firstfit(p) zfirstfit((triepointer) (p))
#define firstfit_regmem
void ztriepack (triepointer p);
#define triepack(p) ztriepack((triepointer) (p))
#define triepack_regmem
void ztriefix (triepointer p);
#define triefix(p) ztriefix((triepointer) (p))
#define triefix_regmem
void newpatterns (void);
#define newpatterns_regmem register memoryword *mem=zmem;
void inittrie (void);
#define inittrie_regmem
void zlinebreak (boolean d);
#define linebreak(d) zlinebreak((boolean) (d))
#define linebreak_regmem register memoryword *mem=zmem;
boolean zeTeXenabled (boolean b,quarterword j,halfword k);
#define eTeXenabled(b, j, k) zeTeXenabled((boolean) (b), (quarterword) (j), (halfword) (k))
#define eTeXenabled_regmem
void showsavegroups (void);
#define showsavegroups_regmem register memoryword *mem=zmem;
void newhyphexceptions (void);
#define newhyphexceptions_regmem register memoryword *mem=zmem;
halfword zprunepagetop (halfword p,boolean s);
#define prunepagetop(p, s) zprunepagetop((halfword) (p), (boolean) (s))
#define prunepagetop_regmem register memoryword *mem=zmem;
halfword zvertbreak (halfword p,scaled h,scaled d);
#define vertbreak(p, h, d) zvertbreak((halfword) (p), (scaled) (h), (scaled) (d))
#define vertbreak_regmem register memoryword *mem=zmem;
boolean zdomarks (smallnumber a,smallnumber l,halfword q);
#define domarks(a, l, q) zdomarks((smallnumber) (a), (smallnumber) (l), (halfword) (q))
#define domarks_regmem register memoryword *mem=zmem;
halfword zvsplit (halfword n,scaled h);
#define vsplit(n, h) zvsplit((halfword) (n), (scaled) (h))
#define vsplit_regmem register memoryword *mem=zmem;
void printtotals (void);
#define printtotals_regmem
void zfreezepagespecs (smallnumber s);
#define freezepagespecs(s) zfreezepagespecs((smallnumber) (s))
#define freezepagespecs_regmem
void zboxerror (eightbits n);
#define boxerror(n) zboxerror((eightbits) (n))
#define boxerror_regmem
void zensurevbox (eightbits n);
#define ensurevbox(n) zensurevbox((eightbits) (n))
#define ensurevbox_regmem register memoryword *mem=zmem;
void zfireup (halfword c);
#define fireup(c) zfireup((halfword) (c))
#define fireup_regmem register memoryword *mem=zmem;
void buildpage (void);
#define buildpage_regmem register memoryword *mem=zmem;
void appspace (void);
#define appspace_regmem register memoryword *mem=zmem;
void insertdollarsign (void);
#define insertdollarsign_regmem
void youcant (void);
#define youcant_regmem
void reportillegalcase (void);
#define reportillegalcase_regmem
boolean privileged (void);
#define privileged_regmem
boolean itsallover (void);
#define itsallover_regmem register memoryword *mem=zmem;
void appendglue (void);
#define appendglue_regmem register memoryword *mem=zmem;
void appendkern (void);
#define appendkern_regmem register memoryword *mem=zmem;
void offsave (void);
#define offsave_regmem register memoryword *mem=zmem;
void extrarightbrace (void);
#define extrarightbrace_regmem
void normalparagraph (void);
#define normalparagraph_regmem
void zboxend (integer boxcontext);
#define boxend(boxcontext) zboxend((integer) (boxcontext))
#define boxend_regmem register memoryword *mem=zmem;
void zbeginbox (integer boxcontext);
#define beginbox(boxcontext) zbeginbox((integer) (boxcontext))
#define beginbox_regmem register memoryword *mem=zmem;
void zscanbox (integer boxcontext);
#define scanbox(boxcontext) zscanbox((integer) (boxcontext))
#define scanbox_regmem
void zpackage (smallnumber c);
#define package(c) zpackage((smallnumber) (c))
#define package_regmem register memoryword *mem=zmem;
smallnumber znormmin (integer h);
#define normmin(h) znormmin((integer) (h))
#define normmin_regmem
void znewgraf (boolean indented);
#define newgraf(indented) znewgraf((boolean) (indented))
#define newgraf_regmem register memoryword *mem=zmem;
void indentinhmode (void);
#define indentinhmode_regmem register memoryword *mem=zmem;
void headforvmode (void);
#define headforvmode_regmem
void endgraf (void);
#define endgraf_regmem register memoryword *mem=zmem;
void begininsertoradjust (void);
#define begininsertoradjust_regmem
void makemark (void);
#define makemark_regmem register memoryword *mem=zmem;
void appendpenalty (void);
#define appendpenalty_regmem register memoryword *mem=zmem;
void deletelast (void);
#define deletelast_regmem register memoryword *mem=zmem;
void unpackage (void);
#define unpackage_regmem register memoryword *mem=zmem;
void appenditaliccorrection (void);
#define appenditaliccorrection_regmem register memoryword *mem=zmem;
void zappendlocalbox (integer kind);
#define appendlocalbox(kind) zappendlocalbox((integer) (kind))
#define appendlocalbox_regmem
void appenddiscretionary (void);
#define appenddiscretionary_regmem register memoryword *mem=zmem;
void buildlocalbox (void);
#define buildlocalbox_regmem register memoryword *mem=zmem;
void builddiscretionary (void);
#define builddiscretionary_regmem register memoryword *mem=zmem;
void makeaccent (void);
#define makeaccent_regmem register memoryword *mem=zmem;
void alignerror (void);
#define alignerror_regmem
void noalignerror (void);
#define noalignerror_regmem
void omiterror (void);
#define omiterror_regmem
void doendv (void);
#define doendv_regmem
void cserror (void);
#define cserror_regmem
void zpushmath (groupcode c);
#define pushmath(c) zpushmath((groupcode) (c))
#define pushmath_regmem
void initmath (void);
#define initmath_regmem register memoryword *mem=zmem;
void starteqno (void);
#define starteqno_regmem
halfword zfinmlist (halfword p);
#define finmlist(p) zfinmlist((halfword) (p))
#define finmlist_regmem register memoryword *mem=zmem;
void zscanmath (halfword p);
#define scanmath(p) zscanmath((halfword) (p))
#define scanmath_regmem register memoryword *mem=zmem;
void zsetmathchar (integer c);
#define setmathchar(c) zsetmathchar((integer) (c))
#define setmathchar_regmem register memoryword *mem=zmem;
void mathlimitswitch (void);
#define mathlimitswitch_regmem register memoryword *mem=zmem;
void zscandelimiter (halfword p,integer r);
#define scandelimiter(p, r) zscandelimiter((halfword) (p), (integer) (r))
#define scandelimiter_regmem register memoryword *mem=zmem;
void mathradical (void);
#define mathradical_regmem register memoryword *mem=zmem;
void mathac (void);
#define mathac_regmem register memoryword *mem=zmem;
void appendchoices (void);
#define appendchoices_regmem register memoryword *mem=zmem;
void buildchoices (void);
#define buildchoices_regmem register memoryword *mem=zmem;
void subsup (void);
#define subsup_regmem register memoryword *mem=zmem;
void mathfraction (void);
#define mathfraction_regmem register memoryword *mem=zmem;
void mathleftright (void);
#define mathleftright_regmem register memoryword *mem=zmem;
void aftermath (void);
#define aftermath_regmem register memoryword *mem=zmem;
void resumeafterdisplay (void);
#define resumeafterdisplay_regmem register memoryword *mem=zmem;
void getrtoken (void);
#define getrtoken_regmem
void trapzeroglue (void);
#define trapzeroglue_regmem register memoryword *mem=zmem;
void zdoregistercommand (smallnumber a);
#define doregistercommand(a) zdoregistercommand((smallnumber) (a))
#define doregistercommand_regmem register memoryword *mem=zmem;
void alteraux (void);
#define alteraux_regmem
void alterprevgraf (void);
#define alterprevgraf_regmem
void alterpagesofar (void);
#define alterpagesofar_regmem
void alterinteger (void);
#define alterinteger_regmem
void alterboxdimen (void);
#define alterboxdimen_regmem register memoryword *mem=zmem;
void znewfont (smallnumber a);
#define newfont(a) znewfont((smallnumber) (a))
#define newfont_regmem
void newinteraction (void);
#define newinteraction_regmem
void scanfilereferrent (void);
#define scanfilereferrent_regmem
void scanmode (void);
#define scanmode_regmem
void dochartranslation (void);
#define dochartranslation_regmem
void docharmode (void);
#define docharmode_regmem
boolean zpnewinputln (alphafile f,halfword themode,halfword translation,boolean bypasseoln);
#define pnewinputln(f, themode, translation, bypasseoln) zpnewinputln((alphafile) (f), (halfword) (themode), (halfword) (translation), (boolean) (bypasseoln))
#define pnewinputln_regmem
void znewocp (smallnumber a);
#define newocp(a) znewocp((smallnumber) (a))
#define newocp_regmem
void znewocplist (smallnumber a);
#define newocplist(a) znewocplist((smallnumber) (a))
#define newocplist_regmem
void zdopushocplist (smallnumber a);
#define dopushocplist(a) zdopushocplist((smallnumber) (a))
#define dopushocplist_regmem
void zdopopocplist (smallnumber a);
#define dopopocplist(a) zdopopocplist((smallnumber) (a))
#define dopopocplist_regmem
void zdoclearocplists (smallnumber a);
#define doclearocplists(a) zdoclearocplists((smallnumber) (a))
#define doclearocplists_regmem
void prefixedcommand (void);
#define prefixedcommand_regmem register memoryword *mem=zmem;
void doassignments (void);
#define doassignments_regmem
void openorclosein (void);
#define openorclosein_regmem
void issuemessage (void);
#define issuemessage_regmem register memoryword *mem=zmem;
void shiftcase (void);
#define shiftcase_regmem register memoryword *mem=zmem;
void showwhatever (void);
#define showwhatever_regmem register memoryword *mem=zmem;
void storefmtfile (void);
#define storefmtfile_regmem register memoryword *mem=zmem;
void znewwhatsit (smallnumber s,smallnumber w);
#define newwhatsit(s, w) znewwhatsit((smallnumber) (s), (smallnumber) (w))
#define newwhatsit_regmem register memoryword *mem=zmem;
void znewwritewhatsit (smallnumber w);
#define newwritewhatsit(w) znewwritewhatsit((smallnumber) (w))
#define newwritewhatsit_regmem register memoryword *mem=zmem;
void doextension (void);
#define doextension_regmem register memoryword *mem=zmem;
void fixlanguage (void);
#define fixlanguage_regmem register memoryword *mem=zmem;
void insertsrcspecial (void);
#define insertsrcspecial_regmem register memoryword *mem=zmem;
void appendsrcspecial (void);
#define appendsrcspecial_regmem register memoryword *mem=zmem;
void handlerightbrace (void);
#define handlerightbrace_regmem register memoryword *mem=zmem;
void maincontrol (void);
#define maincontrol_regmem register memoryword *mem=zmem;
void giveerrhelp (void);
#define giveerrhelp_regmem
boolean openfmtfile (void);
#define openfmtfile_regmem
boolean loadfmtfile (void);
#define loadfmtfile_regmem register memoryword *mem=zmem;
void closefilesandterminate (void);
#define closefilesandterminate_regmem
void finalcleanup (void);
#define finalcleanup_regmem register memoryword *mem=zmem;
void initprim (void);
#define initprim_regmem
void debughelp (void);
#define debughelp_regmem register memoryword *mem=zmem;
void mainbody (void);
#define mainbody_regmem
strnumber getnullstr (void);
#define getnullstr_regmem
/* Some definitions that get appended to the `coerce.h' file that web2c
   outputs.  */
/* $Id: coerce.h 37504 2015-06-12 08:45:07Z peter $ */

/* The C compiler ignores most unnecessary casts (i.e., casts of
   something to its own type).  However, for structures, it doesn't.
   Therefore, we have to redefine these macros so they don't cast
   their argument (of type memoryword or fourquarters, respectively).  */

#ifdef	printword
#undef	printword
#define	printword(x)	zprintword (x)
#endif

#ifdef	tfmqqqq
#undef	tfmqqqq
#define tfmqqqq(x)	ztfmqqqq (x)
#endif

#ifdef	eqdestroy
#undef	eqdestroy
#define	eqdestroy(x)	zeqdestroy(x)
#endif

/* And we use the opportunity to declare a few functions that could not be
   declared in texmfmp.h, because they need typedefs not yet known at that
   point.  */
extern strnumber getjobname (strnumber);

#ifdef XeTeX
/* XeTeX redefines "ASCII" types.... */
typedef packedUTF16code packedASCIIcode;
#endif
extern void calledit (packedASCIIcode *, poolpointer, integer, integer);

#ifdef MF
extern void blankrectangle (screencol, screencol, screenrow, screenrow);
extern void paintrow (screenrow, pixelcolor, transspec, screencol);
#if defined(MFLua) || defined(MFLuaJIT)
#include <mfluadir/mfluac.h>
#endif
#endif

extern strnumber makefullnamestring(void);

#ifdef TeX
extern string gettexstring (strnumber);
/* Prototypes for source-specials functions... */
extern boolean isnewsource (strnumber, int);
extern poolpointer makesrcspecial (strnumber, int);
extern void remembersourceinfo (strnumber, int);

#ifdef pdfTeX
#include <pdftexdir/pdftex.h>
#endif /* pdfTeX */

#ifdef XeTeX
#include <xetexdir/xetex.h>
#endif /* XeTeX */

#ifdef __SyncTeX__
#include <synctexdir/synctex.h>
#endif
#endif /* TeX */
