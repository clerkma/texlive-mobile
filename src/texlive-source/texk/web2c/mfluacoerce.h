void initialize (void);
void println (void);
void zprintchar (ASCIIcode s);
#define printchar(s) zprintchar((ASCIIcode) (s))
void zprint (integer s);
#define print(s) zprint((integer) (s))
void zslowprint (integer s);
#define slowprint(s) zslowprint((integer) (s))
void zprintnl (strnumber s);
#define printnl(s) zprintnl((strnumber) (s))
void zprintthedigs (eightbits k);
#define printthedigs(k) zprintthedigs((eightbits) (k))
void zprintint (integer n);
#define printint(n) zprintint((integer) (n))
void zprintscaled (scaled s);
#define printscaled(s) zprintscaled((scaled) (s))
void zprinttwo (scaled x,scaled y);
#define printtwo(x, y) zprinttwo((scaled) (x), (scaled) (y))
void zprinttype (smallnumber t);
#define printtype(t) zprinttype((smallnumber) (t))
void begindiagnostic (void);
void zenddiagnostic (boolean blankline);
#define enddiagnostic(blankline) zenddiagnostic((boolean) (blankline))
void zprintdiagnostic (strnumber s,strnumber t,boolean nuline);
#define printdiagnostic(s, t, nuline) zprintdiagnostic((strnumber) (s), (strnumber) (t), (boolean) (nuline))
void zprintfilename (integer n,integer a,integer e);
#define printfilename(n, a, e) zprintfilename((integer) (n), (integer) (a), (integer) (e))
void zflushstring (strnumber s);
#define flushstring(s) zflushstring((strnumber) (s))
WEB2C_NORETURN void jumpout (void);
void error (void);
WEB2C_NORETURN void zfatalerror (strnumber s);
#define fatalerror(s) zfatalerror((strnumber) (s))
WEB2C_NORETURN void zoverflow (strnumber s,integer n);
#define overflow(s, n) zoverflow((strnumber) (s), (integer) (n))
WEB2C_NORETURN void zconfusion (strnumber s);
#define confusion(s) zconfusion((strnumber) (s))
boolean initterminal (void);
strnumber makestring (void);
boolean zstreqbuf (strnumber s,integer k);
#define streqbuf(s, k) zstreqbuf((strnumber) (s), (integer) (k))
integer zstrvsstr (strnumber s,strnumber t);
#define strvsstr(s, t) zstrvsstr((strnumber) (s), (strnumber) (t))
boolean getstringsstarted (void);
void zprintdd (integer n);
#define printdd(n) zprintdd((integer) (n))
void terminput (void);
void normalizeselector (void);
void pauseforinstructions (void);
void zmissingerr (strnumber s);
#define missingerr(s) zmissingerr((strnumber) (s))
void cleararith (void);
integer zslowadd (integer x,integer y);
#define slowadd(x, y) zslowadd((integer) (x), (integer) (y))
scaled zrounddecimals (smallnumber k);
#define rounddecimals(k) zrounddecimals((smallnumber) (k))
fraction zmakefraction (integer p,integer q);
#define makefraction(p, q) zmakefraction((integer) (p), (integer) (q))
integer ztakefraction (integer q,fraction f);
#define takefraction(q, f) ztakefraction((integer) (q), (fraction) (f))
integer ztakescaled (integer q,scaled f);
#define takescaled(q, f) ztakescaled((integer) (q), (scaled) (f))
scaled zmakescaled (integer p,integer q);
#define makescaled(p, q) zmakescaled((integer) (p), (integer) (q))
fraction zvelocity (fraction st,fraction ct,fraction sf,fraction cf,scaled t);
#define velocity(st, ct, sf, cf, t) zvelocity((fraction) (st), (fraction) (ct), (fraction) (sf), (fraction) (cf), (scaled) (t))
integer zabvscd (integer a,integer b,integer c,integer d);
#define abvscd(a, b, c, d) zabvscd((integer) (a), (integer) (b), (integer) (c), (integer) (d))
scaled zsquarert (scaled x);
#define squarert(x) zsquarert((scaled) (x))
integer zpythadd (integer a,integer b);
#define pythadd(a, b) zpythadd((integer) (a), (integer) (b))
integer zpythsub (integer a,integer b);
#define pythsub(a, b) zpythsub((integer) (a), (integer) (b))
scaled zmlog (scaled x);
#define mlog(x) zmlog((scaled) (x))
scaled zmexp (scaled x);
#define mexp(x) zmexp((scaled) (x))
angle znarg (integer x,integer y);
#define narg(x, y) znarg((integer) (x), (integer) (y))
void znsincos (angle z);
#define nsincos(z) znsincos((angle) (z))
void newrandoms (void);
void zinitrandoms (scaled seed);
#define initrandoms(seed) zinitrandoms((scaled) (seed))
scaled zunifrand (scaled x);
#define unifrand(x) zunifrand((scaled) (x))
scaled normrand (void);
void zprintword (memoryword w);
#define printword(w) zprintword((memoryword) (w))
void zshowtokenlist (integer p,integer q,integer l,integer nulltally);
#define showtokenlist(p, q, l, nulltally) zshowtokenlist((integer) (p), (integer) (q), (integer) (l), (integer) (nulltally))
void runaway (void);
halfword getavail (void);
halfword zgetnode (integer s);
#define getnode(s) zgetnode((integer) (s))
void zfreenode (halfword p,halfword s);
#define freenode(p, s) zfreenode((halfword) (p), (halfword) (s))
void sortavail (void);
void zflushlist (halfword p);
#define flushlist(p) zflushlist((halfword) (p))
void zflushnodelist (halfword p);
#define flushnodelist(p) zflushnodelist((halfword) (p))
void zcheckmem (boolean printlocs);
#define checkmem(printlocs) zcheckmem((boolean) (printlocs))
void zsearchmem (halfword p);
#define searchmem(p) zsearchmem((halfword) (p))
void zprintop (quarterword c);
#define printop(c) zprintop((quarterword) (c))
void fixdateandtime (void);
halfword zidlookup (integer j,integer l);
#define idlookup(j, l) zidlookup((integer) (j), (integer) (l))
void zprimitive (strnumber s,halfword c,halfword o);
#define primitive(s, c, o) zprimitive((strnumber) (s), (halfword) (c), (halfword) (o))
halfword znewnumtok (scaled v);
#define newnumtok(v) znewnumtok((scaled) (v))
void zflushtokenlist (halfword p);
#define flushtokenlist(p) zflushtokenlist((halfword) (p))
void zdeletemacref (halfword p);
#define deletemacref(p) zdeletemacref((halfword) (p))
void zprintcmdmod (integer c,integer m);
#define printcmdmod(c, m) zprintcmdmod((integer) (c), (integer) (m))
void zshowmacro (halfword p,integer q,integer l);
#define showmacro(p, q, l) zshowmacro((halfword) (p), (integer) (q), (integer) (l))
void zinitbignode (halfword p);
#define initbignode(p) zinitbignode((halfword) (p))
halfword idtransform (void);
void znewroot (halfword x);
#define newroot(x) znewroot((halfword) (x))
void zprintvariablename (halfword p);
#define printvariablename(p) zprintvariablename((halfword) (p))
boolean zinteresting (halfword p);
#define interesting(p) zinteresting((halfword) (p))
halfword znewstructure (halfword p);
#define newstructure(p) znewstructure((halfword) (p))
halfword zfindvariable (halfword t);
#define findvariable(t) zfindvariable((halfword) (t))
void zprintpath (halfword h,strnumber s,boolean nuline);
#define printpath(h, s, nuline) zprintpath((halfword) (h), (strnumber) (s), (boolean) (nuline))
void zprintweight (halfword q,integer xoff);
#define printweight(q, xoff) zprintweight((halfword) (q), (integer) (xoff))
void zprintedges (strnumber s,boolean nuline,integer xoff,integer yoff);
#define printedges(s, nuline, xoff, yoff) zprintedges((strnumber) (s), (boolean) (nuline), (integer) (xoff), (integer) (yoff))
void zunskew (scaled x,scaled y,smallnumber octant);
#define unskew(x, y, octant) zunskew((scaled) (x), (scaled) (y), (smallnumber) (octant))
void zprintpen (halfword p,strnumber s,boolean nuline);
#define printpen(p, s, nuline) zprintpen((halfword) (p), (strnumber) (s), (boolean) (nuline))
void zprintdependency (halfword p,smallnumber t);
#define printdependency(p, t) zprintdependency((halfword) (p), (smallnumber) (t))
void zprintdp (smallnumber t,halfword p,smallnumber verbosity);
#define printdp(t, p, verbosity) zprintdp((smallnumber) (t), (halfword) (p), (smallnumber) (verbosity))
halfword stashcurexp (void);
void zunstashcurexp (halfword p);
#define unstashcurexp(p) zunstashcurexp((halfword) (p))
void zprintexp (halfword p,smallnumber verbosity);
#define printexp(p, verbosity) zprintexp((halfword) (p), (smallnumber) (verbosity))
void zdisperr (halfword p,strnumber s);
#define disperr(p, s) zdisperr((halfword) (p), (strnumber) (s))
halfword zpplusfq (halfword p,integer f,halfword q,smallnumber t,smallnumber tt);
#define pplusfq(p, f, q, t, tt) zpplusfq((halfword) (p), (integer) (f), (halfword) (q), (smallnumber) (t), (smallnumber) (tt))
halfword zpoverv (halfword p,scaled v,smallnumber t0,smallnumber t1);
#define poverv(p, v, t0, t1) zpoverv((halfword) (p), (scaled) (v), (smallnumber) (t0), (smallnumber) (t1))
void zvaltoobig (scaled x);
#define valtoobig(x) zvaltoobig((scaled) (x))
void zmakeknown (halfword p,halfword q);
#define makeknown(p, q) zmakeknown((halfword) (p), (halfword) (q))
void fixdependencies (void);
void ztossknotlist (halfword p);
#define tossknotlist(p) ztossknotlist((halfword) (p))
void ztossedges (halfword h);
#define tossedges(h) ztossedges((halfword) (h))
void ztosspen (halfword p);
#define tosspen(p) ztosspen((halfword) (p))
void zringdelete (halfword p);
#define ringdelete(p) zringdelete((halfword) (p))
void zrecyclevalue (halfword p);
#define recyclevalue(p) zrecyclevalue((halfword) (p))
void zflushcurexp (scaled v);
#define flushcurexp(v) zflushcurexp((scaled) (v))
void zflusherror (scaled v);
#define flusherror(v) zflusherror((scaled) (v))
void putgeterror (void);
void zputgetflusherror (scaled v);
#define putgetflusherror(v) zputgetflusherror((scaled) (v))
void zflushbelowvariable (halfword p);
#define flushbelowvariable(p) zflushbelowvariable((halfword) (p))
void zflushvariable (halfword p,halfword t,boolean discardsuffixes);
#define flushvariable(p, t, discardsuffixes) zflushvariable((halfword) (p), (halfword) (t), (boolean) (discardsuffixes))
smallnumber zundtype (halfword p);
#define undtype(p) zundtype((halfword) (p))
void zclearsymbol (halfword p,boolean saving);
#define clearsymbol(p, saving) zclearsymbol((halfword) (p), (boolean) (saving))
void zsavevariable (halfword q);
#define savevariable(q) zsavevariable((halfword) (q))
void zsaveinternal (halfword q);
#define saveinternal(q) zsaveinternal((halfword) (q))
void unsave (void);
halfword zcopyknot (halfword p);
#define copyknot(p) zcopyknot((halfword) (p))
halfword zcopypath (halfword p);
#define copypath(p) zcopypath((halfword) (p))
halfword zhtapypoc (halfword p);
#define htapypoc(p) zhtapypoc((halfword) (p))
fraction zcurlratio (scaled gamma,scaled atension,scaled btension);
#define curlratio(gamma, atension, btension) zcurlratio((scaled) (gamma), (scaled) (atension), (scaled) (btension))
void zsetcontrols (halfword p,halfword q,integer k);
#define setcontrols(p, q, k) zsetcontrols((halfword) (p), (halfword) (q), (integer) (k))
void zsolvechoices (halfword p,halfword q,halfword n);
#define solvechoices(p, q, n) zsolvechoices((halfword) (p), (halfword) (q), (halfword) (n))
void zmakechoices (halfword knots);
#define makechoices(knots) zmakechoices((halfword) (knots))
void zmakemoves (scaled xx0,scaled xx1,scaled xx2,scaled xx3,scaled yy0,scaled yy1,scaled yy2,scaled yy3,smallnumber xicorr,smallnumber etacorr);
#define makemoves(xx0, xx1, xx2, xx3, yy0, yy1, yy2, yy3, xicorr, etacorr) zmakemoves((scaled) (xx0), (scaled) (xx1), (scaled) (xx2), (scaled) (xx3), (scaled) (yy0), (scaled) (yy1), (scaled) (yy2), (scaled) (yy3), (smallnumber) (xicorr), (smallnumber) (etacorr))
void zsmoothmoves (integer b,integer t);
#define smoothmoves(b, t) zsmoothmoves((integer) (b), (integer) (t))
void zinitedges (halfword h);
#define initedges(h) zinitedges((halfword) (h))
void fixoffset (void);
void zedgeprep (integer ml,integer mr,integer nl,integer nr);
#define edgeprep(ml, mr, nl, nr) zedgeprep((integer) (ml), (integer) (mr), (integer) (nl), (integer) (nr))
halfword zcopyedges (halfword h);
#define copyedges(h) zcopyedges((halfword) (h))
void yreflectedges (void);
void xreflectedges (void);
void zyscaleedges (integer s);
#define yscaleedges(s) zyscaleedges((integer) (s))
void zxscaleedges (integer s);
#define xscaleedges(s) zxscaleedges((integer) (s))
void znegateedges (halfword h);
#define negateedges(h) znegateedges((halfword) (h))
void zsortedges (halfword h);
#define sortedges(h) zsortedges((halfword) (h))
void zculledges (integer wlo,integer whi,integer wout,integer win);
#define culledges(wlo, whi, wout, win) zculledges((integer) (wlo), (integer) (whi), (integer) (wout), (integer) (win))
void xyswapedges (void);
void zmergeedges (halfword h);
#define mergeedges(h) zmergeedges((halfword) (h))
integer ztotalweight (halfword h);
#define totalweight(h) ztotalweight((halfword) (h))
void beginedgetracing (void);
void traceacorner (void);
void endedgetracing (void);
void ztracenewedge (halfword r,integer n);
#define tracenewedge(r, n) ztracenewedge((halfword) (r), (integer) (n))
void zlineedges (scaled x0,scaled y0,scaled x1,scaled y1);
#define lineedges(x0, y0, x1, y1) zlineedges((scaled) (x0), (scaled) (y0), (scaled) (x1), (scaled) (y1))
void zmovetoedges (integer m0,integer n0,integer m1,integer n1);
#define movetoedges(m0, n0, m1, n1) zmovetoedges((integer) (m0), (integer) (n0), (integer) (m1), (integer) (n1))
void zskew (scaled x,scaled y,smallnumber octant);
#define skew(x, y, octant) zskew((scaled) (x), (scaled) (y), (smallnumber) (octant))
void zabnegate (scaled x,scaled y,smallnumber octantbefore,smallnumber octantafter);
#define abnegate(x, y, octantbefore, octantafter) zabnegate((scaled) (x), (scaled) (y), (smallnumber) (octantbefore), (smallnumber) (octantafter))
fraction zcrossingpoint (integer a,integer b,integer c);
#define crossingpoint(a, b, c) zcrossingpoint((integer) (a), (integer) (b), (integer) (c))
void zprintspec (strnumber s);
#define printspec(s) zprintspec((strnumber) (s))
void zprintstrange (strnumber s);
#define printstrange(s) zprintstrange((strnumber) (s))
void zremovecubic (halfword p);
#define removecubic(p) zremovecubic((halfword) (p))
void zsplitcubic (halfword p,fraction t,scaled xq,scaled yq);
#define splitcubic(p, t, xq, yq) zsplitcubic((halfword) (p), (fraction) (t), (scaled) (xq), (scaled) (yq))
void quadrantsubdivide (void);
void octantsubdivide (void);
void makesafe (void);
void zbeforeandafter (scaled b,scaled a,halfword p);
#define beforeandafter(b, a, p) zbeforeandafter((scaled) (b), (scaled) (a), (halfword) (p))
scaled zgoodval (scaled b,scaled o);
#define goodval(b, o) zgoodval((scaled) (b), (scaled) (o))
scaled zcompromise (scaled u,scaled v);
#define compromise(u, v) zcompromise((scaled) (u), (scaled) (v))
void xyround (void);
void diaground (void);
void znewboundary (halfword p,smallnumber octant);
#define newboundary(p, octant) znewboundary((halfword) (p), (smallnumber) (octant))
halfword zmakespec (halfword h,scaled safetymargin,integer tracing);
#define makespec(h, safetymargin, tracing) zmakespec((halfword) (h), (scaled) (safetymargin), (integer) (tracing))
void zendround (scaled x,scaled y);
#define endround(x, y) zendround((scaled) (x), (scaled) (y))
void zfillspec (halfword h);
#define fillspec(h) zfillspec((halfword) (h))
void zdupoffset (halfword w);
#define dupoffset(w) zdupoffset((halfword) (w))
halfword zmakepen (halfword h);
#define makepen(h) zmakepen((halfword) (h))
halfword ztrivialknot (scaled x,scaled y);
#define trivialknot(x, y) ztrivialknot((scaled) (x), (scaled) (y))
halfword zmakepath (halfword penhead);
#define makepath(penhead) zmakepath((halfword) (penhead))
void zfindoffset (scaled x,scaled y,halfword p);
#define findoffset(x, y, p) zfindoffset((scaled) (x), (scaled) (y), (halfword) (p))
void zsplitforoffset (halfword p,fraction t);
#define splitforoffset(p, t) zsplitforoffset((halfword) (p), (fraction) (t))
void zfinoffsetprep (halfword p,halfword k,halfword w,integer x0,integer x1,integer x2,integer y0,integer y1,integer y2,boolean rising,integer n);
#define finoffsetprep(p, k, w, x0, x1, x2, y0, y1, y2, rising, n) zfinoffsetprep((halfword) (p), (halfword) (k), (halfword) (w), (integer) (x0), (integer) (x1), (integer) (x2), (integer) (y0), (integer) (y1), (integer) (y2), (boolean) (rising), (integer) (n))
void zoffsetprep (halfword c,halfword h);
#define offsetprep(c, h) zoffsetprep((halfword) (c), (halfword) (h))
void zskewlineedges (halfword p,halfword w,halfword ww);
#define skewlineedges(p, w, ww) zskewlineedges((halfword) (p), (halfword) (w), (halfword) (ww))
void zdualmoves (halfword h,halfword p,halfword q);
#define dualmoves(h, p, q) zdualmoves((halfword) (h), (halfword) (p), (halfword) (q))
void zfillenvelope (halfword spechead);
#define fillenvelope(spechead) zfillenvelope((halfword) (spechead))
halfword zmakeellipse (scaled majoraxis,scaled minoraxis,angle theta);
#define makeellipse(majoraxis, minoraxis, theta) zmakeellipse((scaled) (majoraxis), (scaled) (minoraxis), (angle) (theta))
scaled zfinddirectiontime (scaled x,scaled y,halfword h);
#define finddirectiontime(x, y, h) zfinddirectiontime((scaled) (x), (scaled) (y), (halfword) (h))
void zcubicintersection (halfword p,halfword pp);
#define cubicintersection(p, pp) zcubicintersection((halfword) (p), (halfword) (pp))
void zpathintersection (halfword h,halfword hh);
#define pathintersection(h, hh) zpathintersection((halfword) (h), (halfword) (hh))
void zopenawindow (windownumber k,scaled r0,scaled c0,scaled r1,scaled c1,scaled x,scaled y);
#define openawindow(k, r0, c0, r1, c1, x, y) zopenawindow((windownumber) (k), (scaled) (r0), (scaled) (c0), (scaled) (r1), (scaled) (c1), (scaled) (x), (scaled) (y))
void zdispedges (windownumber k);
#define dispedges(k) zdispedges((windownumber) (k))
fraction zmaxcoef (halfword p);
#define maxcoef(p) zmaxcoef((halfword) (p))
halfword zpplusq (halfword p,halfword q,smallnumber t);
#define pplusq(p, q, t) zpplusq((halfword) (p), (halfword) (q), (smallnumber) (t))
halfword zptimesv (halfword p,integer v,smallnumber t0,smallnumber t1,boolean visscaled);
#define ptimesv(p, v, t0, t1, visscaled) zptimesv((halfword) (p), (integer) (v), (smallnumber) (t0), (smallnumber) (t1), (boolean) (visscaled))
halfword zpwithxbecomingq (halfword p,halfword x,halfword q,smallnumber t);
#define pwithxbecomingq(p, x, q, t) zpwithxbecomingq((halfword) (p), (halfword) (x), (halfword) (q), (smallnumber) (t))
void znewdep (halfword q,halfword p);
#define newdep(q, p) znewdep((halfword) (q), (halfword) (p))
halfword zconstdependency (scaled v);
#define constdependency(v) zconstdependency((scaled) (v))
halfword zsingledependency (halfword p);
#define singledependency(p) zsingledependency((halfword) (p))
halfword zcopydeplist (halfword p);
#define copydeplist(p) zcopydeplist((halfword) (p))
void zlineareq (halfword p,smallnumber t);
#define lineareq(p, t) zlineareq((halfword) (p), (smallnumber) (t))
halfword znewringentry (halfword p);
#define newringentry(p) znewringentry((halfword) (p))
void znonlineareq (integer v,halfword p,boolean flushp);
#define nonlineareq(v, p, flushp) znonlineareq((integer) (v), (halfword) (p), (boolean) (flushp))
void zringmerge (halfword p,halfword q);
#define ringmerge(p, q) zringmerge((halfword) (p), (halfword) (q))
void zshowcmdmod (integer c,integer m);
#define showcmdmod(c, m) zshowcmdmod((integer) (c), (integer) (m))
void showcontext (void);
void zbegintokenlist (halfword p,quarterword t);
#define begintokenlist(p, t) zbegintokenlist((halfword) (p), (quarterword) (t))
void endtokenlist (void);
void zencapsulate (halfword p);
#define encapsulate(p) zencapsulate((halfword) (p))
void zinstall (halfword r,halfword q);
#define install(r, q) zinstall((halfword) (r), (halfword) (q))
void zmakeexpcopy (halfword p);
#define makeexpcopy(p) zmakeexpcopy((halfword) (p))
halfword curtok (void);
void backinput (void);
void backerror (void);
void inserror (void);
void beginfilereading (void);
void endfilereading (void);
void clearforerrorprompt (void);
boolean checkoutervalidity (void);
void getnext (void);
void firmuptheline (void);
halfword zscantoks (commandcode terminator,halfword substlist,halfword tailend,smallnumber suffixcount);
#define scantoks(terminator, substlist, tailend, suffixcount) zscantoks((commandcode) (terminator), (halfword) (substlist), (halfword) (tailend), (smallnumber) (suffixcount))
void getsymbol (void);
void getclearsymbol (void);
void checkequals (void);
void makeopdef (void);
void zcheckdelimiter (halfword ldelim,halfword rdelim);
#define checkdelimiter(ldelim, rdelim) zcheckdelimiter((halfword) (ldelim), (halfword) (rdelim))
halfword scandeclaredvariable (void);
void scandef (void);
void zprintmacroname (halfword a,halfword n);
#define printmacroname(a, n) zprintmacroname((halfword) (a), (halfword) (n))
void zprintarg (halfword q,integer n,halfword b);
#define printarg(q, n, b) zprintarg((halfword) (q), (integer) (n), (halfword) (b))
void zscantextarg (halfword ldelim,halfword rdelim);
#define scantextarg(ldelim, rdelim) zscantextarg((halfword) (ldelim), (halfword) (rdelim))
void zmacrocall (halfword defref,halfword arglist,halfword macroname);
#define macrocall(defref, arglist, macroname) zmacrocall((halfword) (defref), (halfword) (arglist), (halfword) (macroname))
void expand (void);
void getxnext (void);
void zstackargument (halfword p);
#define stackargument(p) zstackargument((halfword) (p))
void passtext (void);
void zchangeiflimit (smallnumber l,halfword p);
#define changeiflimit(l, p) zchangeiflimit((smallnumber) (l), (halfword) (p))
void checkcolon (void);
void conditional (void);
void zbadfor (strnumber s);
#define badfor(s) zbadfor((strnumber) (s))
void beginiteration (void);
void resumeiteration (void);
void stopiteration (void);
void beginname (void);
boolean zmorename (ASCIIcode c);
#define morename(c) zmorename((ASCIIcode) (c))
void endname (void);
void zpackfilename (strnumber n,strnumber a,strnumber e);
#define packfilename(n, a, e) zpackfilename((strnumber) (n), (strnumber) (a), (strnumber) (e))
void zpackbufferedname (smallnumber n,integer a,integer b);
#define packbufferedname(n, a, b) zpackbufferedname((smallnumber) (n), (integer) (a), (integer) (b))
strnumber makenamestring (void);
strnumber zamakenamestring (alphafile f);
#define amakenamestring(f) zamakenamestring((alphafile) (f))
strnumber zbmakenamestring (bytefile f);
#define bmakenamestring(f) zbmakenamestring((bytefile) (f))
strnumber zwmakenamestring (wordfile f);
#define wmakenamestring(f) zwmakenamestring((wordfile) (f))
void scanfilename (void);
void zpackjobname (strnumber s);
#define packjobname(s) zpackjobname((strnumber) (s))
void zpromptfilename (strnumber s,strnumber e);
#define promptfilename(s, e) zpromptfilename((strnumber) (s), (strnumber) (e))
void openlogfile (void);
void startinput (void);
void zbadexp (strnumber s);
#define badexp(s) zbadexp((strnumber) (s))
void zstashin (halfword p);
#define stashin(p) zstashin((halfword) (p))
void backexpr (void);
void badsubscript (void);
void zobliterated (halfword q);
#define obliterated(q) zobliterated((halfword) (q))
void zbinarymac (halfword p,halfword c,halfword n);
#define binarymac(p, c, n) zbinarymac((halfword) (p), (halfword) (c), (halfword) (n))
void materializepen (void);
void knownpair (void);
halfword newknot (void);
smallnumber scandirection (void);
void zdonullary (quarterword c);
#define donullary(c) zdonullary((quarterword) (c))
boolean znicepair (integer p,quarterword t);
#define nicepair(p, t) znicepair((integer) (p), (quarterword) (t))
void zprintknownorunknowntype (smallnumber t,integer v);
#define printknownorunknowntype(t, v) zprintknownorunknowntype((smallnumber) (t), (integer) (v))
void zbadunary (quarterword c);
#define badunary(c) zbadunary((quarterword) (c))
void znegatedeplist (halfword p);
#define negatedeplist(p) znegatedeplist((halfword) (p))
void pairtopath (void);
void ztakepart (quarterword c);
#define takepart(c) ztakepart((quarterword) (c))
void zstrtonum (quarterword c);
#define strtonum(c) zstrtonum((quarterword) (c))
scaled pathlength (void);
void ztestknown (quarterword c);
#define testknown(c) ztestknown((quarterword) (c))
void zdounary (quarterword c);
#define dounary(c) zdounary((quarterword) (c))
void zbadbinary (halfword p,quarterword c);
#define badbinary(p, c) zbadbinary((halfword) (p), (quarterword) (c))
halfword ztarnished (halfword p);
#define tarnished(p) ztarnished((halfword) (p))
void zdepfinish (halfword v,halfword q,smallnumber t);
#define depfinish(v, q, t) zdepfinish((halfword) (v), (halfword) (q), (smallnumber) (t))
void zaddorsubtract (halfword p,halfword q,quarterword c);
#define addorsubtract(p, q, c) zaddorsubtract((halfword) (p), (halfword) (q), (quarterword) (c))
void zdepmult (halfword p,integer v,boolean visscaled);
#define depmult(p, v, visscaled) zdepmult((halfword) (p), (integer) (v), (boolean) (visscaled))
void zhardtimes (halfword p);
#define hardtimes(p) zhardtimes((halfword) (p))
void zdepdiv (halfword p,scaled v);
#define depdiv(p, v) zdepdiv((halfword) (p), (scaled) (v))
void zsetuptrans (quarterword c);
#define setuptrans(c) zsetuptrans((quarterword) (c))
void zsetupknowntrans (quarterword c);
#define setupknowntrans(c) zsetupknowntrans((quarterword) (c))
void ztrans (halfword p,halfword q);
#define trans(p, q) ztrans((halfword) (p), (halfword) (q))
void zpathtrans (halfword p,quarterword c);
#define pathtrans(p, c) zpathtrans((halfword) (p), (quarterword) (c))
void zedgestrans (halfword p,quarterword c);
#define edgestrans(p, c) zedgestrans((halfword) (p), (quarterword) (c))
void zbilin1 (halfword p,scaled t,halfword q,scaled u,scaled delta);
#define bilin1(p, t, q, u, delta) zbilin1((halfword) (p), (scaled) (t), (halfword) (q), (scaled) (u), (scaled) (delta))
void zaddmultdep (halfword p,scaled v,halfword r);
#define addmultdep(p, v, r) zaddmultdep((halfword) (p), (scaled) (v), (halfword) (r))
void zbilin2 (halfword p,halfword t,scaled v,halfword u,halfword q);
#define bilin2(p, t, v, u, q) zbilin2((halfword) (p), (halfword) (t), (scaled) (v), (halfword) (u), (halfword) (q))
void zbilin3 (halfword p,scaled t,scaled v,scaled u,scaled delta);
#define bilin3(p, t, v, u, delta) zbilin3((halfword) (p), (scaled) (t), (scaled) (v), (scaled) (u), (scaled) (delta))
void zbigtrans (halfword p,quarterword c);
#define bigtrans(p, c) zbigtrans((halfword) (p), (quarterword) (c))
void zcat (halfword p);
#define cat(p) zcat((halfword) (p))
void zchopstring (halfword p);
#define chopstring(p) zchopstring((halfword) (p))
void zchoppath (halfword p);
#define choppath(p) zchoppath((halfword) (p))
void zpairvalue (scaled x,scaled y);
#define pairvalue(x, y) zpairvalue((scaled) (x), (scaled) (y))
void zsetupoffset (halfword p);
#define setupoffset(p) zsetupoffset((halfword) (p))
void zsetupdirectiontime (halfword p);
#define setupdirectiontime(p) zsetupdirectiontime((halfword) (p))
void zfindpoint (scaled v,quarterword c);
#define findpoint(v, c) zfindpoint((scaled) (v), (quarterword) (c))
void zdobinary (halfword p,quarterword c);
#define dobinary(p, c) zdobinary((halfword) (p), (quarterword) (c))
void zfracmult (scaled n,scaled d);
#define fracmult(n, d) zfracmult((scaled) (n), (scaled) (d))
void gfswap (void);
void zgffour (integer x);
#define gffour(x) zgffour((integer) (x))
void zgftwo (integer x);
#define gftwo(x) zgftwo((integer) (x))
void zgfthree (integer x);
#define gfthree(x) zgfthree((integer) (x))
void zgfpaint (integer d);
#define gfpaint(d) zgfpaint((integer) (d))
void zgfstring (strnumber s,strnumber t);
#define gfstring(s, t) zgfstring((strnumber) (s), (strnumber) (t))
void zgfboc (integer minm,integer maxm,integer minn,integer maxn);
#define gfboc(minm, maxm, minn, maxn) zgfboc((integer) (minm), (integer) (maxm), (integer) (minn), (integer) (maxn))
void initgf (void);
void zshipout (eightbits c);
#define shipout(c) zshipout((eightbits) (c))
void ztryeq (halfword l,halfword r);
#define tryeq(l, r) ztryeq((halfword) (l), (halfword) (r))
void zmakeeq (halfword lhs);
#define makeeq(lhs) zmakeeq((halfword) (lhs))
void doequation (void);
void doassignment (void);
void dotypedeclaration (void);
void dorandomseed (void);
void doprotection (void);
void defdelims (void);
void dointerim (void);
void dolet (void);
void donewinternal (void);
void doshow (void);
void disptoken (void);
void doshowtoken (void);
void doshowstats (void);
void zdispvar (halfword p);
#define dispvar(p) zdispvar((halfword) (p))
void doshowvar (void);
void doshowdependencies (void);
void doshowwhatever (void);
boolean scanwith (void);
void zfindedgesvar (halfword t);
#define findedgesvar(t) zfindedgesvar((halfword) (t))
void doaddto (void);
scaled ztfmcheck (smallnumber m);
#define tfmcheck(m) ztfmcheck((smallnumber) (m))
void doshipout (void);
void dodisplay (void);
boolean zgetpair (commandcode c);
#define getpair(c) zgetpair((commandcode) (c))
void doopenwindow (void);
void docull (void);
void domessage (void);
eightbits getcode (void);
void zsettag (halfword c,smallnumber t,halfword r);
#define settag(c, t, r) zsettag((halfword) (c), (smallnumber) (t), (halfword) (r))
void dotfmcommand (void);
void dospecial (void);
void storebasefile (void);
void dostatement (void);
void maincontrol (void);
halfword zsortin (scaled v);
#define sortin(v) zsortin((scaled) (v))
integer zmincover (scaled d);
#define mincover(d) zmincover((scaled) (d))
scaled zthresholdfn (integer m);
#define thresholdfn(m) zthresholdfn((integer) (m))
integer zskimp (integer m);
#define skimp(m) zskimp((integer) (m))
void ztfmwarning (smallnumber m);
#define tfmwarning(m) ztfmwarning((smallnumber) (m))
void fixdesignsize (void);
integer zdimenout (scaled x);
#define dimenout(x) zdimenout((scaled) (x))
void fixchecksum (void);
void ztfmqqqq (fourquarters x);
#define tfmqqqq(x) ztfmqqqq((fourquarters) (x))
boolean openbasefile (void);
boolean loadbasefile (void);
void scanprimary (void);
void scansuffix (void);
void scansecondary (void);
void scantertiary (void);
void scanexpression (void);
void getboolean (void);
void printcapsule (void);
void tokenrecycle (void);
void closefilesandterminate (void);
void finalcleanup (void);
void initprim (void);
void inittab (void);
void debughelp (void);
/* Some definitions that get appended to the `coerce.h' file that web2c
   outputs.  */
/* $Id$ */

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
