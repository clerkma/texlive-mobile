{4:}{9:}{$C-,A+,D-}ifdef('TEXMF_DEBUG'){$C+,D+}
endif('TEXMF_DEBUG'){:9}program PDFTEX;const{11:}hashoffset=514;
trieopsize=35111;negtrieopsize=-35111;mintrieop=0;maxtrieop=65535;
poolname=TEXMFPOOLNAME;enginename=TEXMFENGINENAME;infmembot=0;
supmembot=1;infmainmemory=3000;supmainmemory=256000000;inftriesize=8000;
suptriesize=4194303;infmaxstrings=3000;supmaxstrings=2097151;
infstringsfree=100;supstringsfree=supmaxstrings;infbufsize=500;
supbufsize=30000000;infnestsize=40;supnestsize=4000;infmaxinopen=6;
supmaxinopen=127;infparamsize=60;supparamsize=32767;infsavesize=600;
supsavesize=80000;infstacksize=200;supstacksize=30000;infdvibufsize=800;
supdvibufsize=65536;inffontmemsize=20000;supfontmemsize=147483647;
supfontmax=9000;inffontmax=50;infpoolsize=32000;suppoolsize=40000000;
infpoolfree=1000;suppoolfree=suppoolsize;infstringvacancies=8000;
supstringvacancies=suppoolsize-23000;suphashextra=supmaxstrings;
infhashextra=0;suphyphsize=65535;infhyphsize=610;infexpanddepth=10;
supexpanddepth=10000000;{:11}{678:}infpdfmemsize=10000;
suppdfmemsize=10000000;{:678}{682:}pdfopbufsize=16384;infpdfosbufsize=1;
suppdfosbufsize=5000000;pdfosmaxobjs=100;{:682}{698:}infobjtabsize=1000;
supobjtabsize=8388607;infdestnamessize=1000;supdestnamessize=500000;
infpkdpi=72;suppkdpi=8000;pdfobjtypemax=9;{:698}{724:}vfmaxrecursion=10;
vfstacksize=100;{:724}{1629:}pdfmaxlinklevel=10;
{:1629}type{18:}ASCIIcode=0..255;{:18}{25:}eightbits=0..255;
alphafile=packed file of ASCIIcode;bytefile=packed file of eightbits;
{:25}{38:}poolpointer=integer;strnumber=0..2097151;
packedASCIIcode=0..255;{:38}{101:}scaled=integer;
nonnegativeinteger=0..2147483647;smallnumber=0..63;
{:101}{109:}{:109}{131:}quarterword=0..255;
halfword=-268435455..268435455;twochoices=1..2;fourchoices=1..4;
#include "texmfmem.h";wordfile=file of memoryword;
{:131}{168:}glueord=0..3;
{:168}{230:}liststaterecord=record modefield:-207..207;
headfield,tailfield:halfword;eTeXauxfield:halfword;
pgfield,mlfield:integer;auxfield:memoryword;end;
{:230}{291:}groupcode=0..16;
{:291}{322:}instaterecord=record statefield,indexfield:quarterword;
startfield,locfield,limitfield,namefield:halfword;
synctextagfield:integer;end;{:322}{577:}internalfontnumber=integer;
fontindex=integer;ninebits=0..256;{:577}{624:}dviindex=0..dvibufsize;
{:624}{697:}objentry=record int0,int1:integer;int2:longinteger;
int3,int4:integer;end;
{:697}{710:}charusedarray=array[0..31]of eightbits;
charmaparray=array[0..32]of eightbits;fmentryptr=^integer;
{:710}{725:}vfstackindex=0..vfstacksize;
vfstackrecord=record stackh,stackv,stackw,stackx,stacky,stackz:scaled;
end;{:725}{1098:}triepointer=0..4194303;trieopcode=0..65535;
{:1098}{1103:}hyphpointer=0..65535;
{:1103}{1625:}destnameentry=record objname:strnumber;objnum:integer;end;
{:1625}{1630:}pdflinkstackrecord=record nestinglevel:integer;
linknode:halfword;reflinknode:halfword;end;
{:1630}{1676:}savepointer=0..savesize;{:1676}var{13:}bad:integer;
{:13}{20:}xord:array[ASCIIcode]of ASCIIcode;
xchr:array[ASCIIcode]of ASCIIcode;xprn:array[ASCIIcode]of ASCIIcode;
mubyteread:array[ASCIIcode]of halfword;
mubytewrite:array[ASCIIcode]of strnumber;
mubytecswrite:array[0..127]of halfword;mubyteskip:integer;
mubytekeep:integer;mubyteskeep:integer;mubyteprefix:integer;
mubytetablein:boolean;mubytetableout:boolean;mubyterelax:boolean;
mubytestart:boolean;mubytesstart:boolean;mubytetoken:halfword;
mubytestoken:halfword;mubytesout:integer;mubyteslog:integer;
specsout:integer;noconvert:boolean;activenoconvert:boolean;
writenoexpanding:boolean;csconverting:boolean;specialprinting:boolean;
messageprinting:boolean;{:20}{26:}nameoffile:^ASCIIcode;
namelength:0..maxint;{:26}{30:}buffer:^ASCIIcode;first:0..bufsize;
last:0..bufsize;maxbufstack:0..bufsize;
{:30}{32:}ifdef('INITEX')iniversion:boolean;dumpoption:boolean;
dumpline:boolean;endif('INITEX')dumpname:constcstring;
bounddefault:integer;boundname:constcstring;membot:integer;
mainmemory:integer;extramembot:integer;memmin:integer;memtop:integer;
extramemtop:integer;memmax:integer;errorline:integer;
halferrorline:integer;maxprintline:integer;maxstrings:integer;
stringsfree:integer;stringvacancies:integer;poolsize:integer;
poolfree:integer;fontmemsize:integer;fontmax:integer;fontk:integer;
hyphsize:integer;triesize:integer;bufsize:integer;stacksize:integer;
maxinopen:integer;paramsize:integer;nestsize:integer;savesize:integer;
dvibufsize:integer;expanddepth:integer;parsefirstlinep:cinttype;
filelineerrorstylep:cinttype;eightbitp:cinttype;haltonerrorp:cinttype;
quotedfilename:boolean;srcspecialsp:boolean;
insertsrcspecialauto:boolean;insertsrcspecialeverypar:boolean;
insertsrcspecialeveryparend:boolean;insertsrcspecialeverycr:boolean;
insertsrcspecialeverymath:boolean;insertsrcspecialeveryhbox:boolean;
insertsrcspecialeveryvbox:boolean;insertsrcspecialeverydisplay:boolean;
{:32}{39:}strpool:^packedASCIIcode;strstart:^poolpointer;
poolptr:poolpointer;strptr:strnumber;initpoolptr:poolpointer;
initstrptr:strnumber;{:39}{50:}ifdef('INITEX')poolfile:alphafile;
endif('INITEX'){:50}{54:}logfile:alphafile;selector:0..21;
dig:array[0..22]of 0..15;tally:integer;termoffset:0..maxprintline;
fileoffset:0..maxprintline;trickbuf:array[0..255]of ASCIIcode;
trickcount:integer;firstcount:integer;{:54}{73:}interaction:0..3;
interactionoption:0..4;{:73}{76:}deletionsallowed:boolean;
setboxallowed:boolean;history:0..3;errorcount:-1..100;
{:76}{79:}helpline:array[0..5]of strnumber;helpptr:0..6;
useerrhelp:boolean;{:79}{96:}interrupt:integer;OKtointerrupt:boolean;
{:96}{104:}aritherror:boolean;texremainder:scaled;
{:104}{110:}randoms:array[0..54]of integer;jrandom:0..54;
randomseed:scaled;{:110}{117:}twotothe:array[0..30]of integer;
speclog:array[1..28]of integer;{:117}{133:}tempptr:halfword;
{:133}{134:}yzmem:^memoryword;zmem:^memoryword;lomemmax:halfword;
himemmin:halfword;{:134}{135:}varused,dynused:integer;
{:135}{136:}avail:halfword;memend:halfword;{:136}{142:}rover:halfword;
{:142}{183:}ifdef('TEXMF_DEBUG')freearr:packed array[0..9]of boolean;
wasfree:packed array[0..9]of boolean;
wasmemend,waslomax,washimin:halfword;panicking:boolean;
endif('TEXMF_DEBUG'){:183}{191:}fontinshortdisplay:integer;
{:191}{199:}depththreshold:integer;breadthmax:integer;
{:199}{231:}nest:^liststaterecord;nestptr:0..nestsize;
maxneststack:0..nestsize;curlist:liststaterecord;shownmode:-207..207;
savetail:halfword;{:231}{264:}oldsetting:0..21;
{:264}{271:}zeqtb:^memoryword;
xeqlevel:array[27177..28082]of quarterword;{:271}{274:}hash:^twohalves;
yhash:^twohalves;hashused:halfword;hashextra:halfword;hashtop:halfword;
eqtbtop:halfword;hashhigh:halfword;nonewcontrolsequence:boolean;
cscount:integer;{:274}{275:}prim:array[0..2100]of twohalves;
primused:halfword;primeqtb:array[0..2100]of memoryword;
{:275}{293:}savestack:^memoryword;saveptr:0..savesize;
maxsavestack:0..savesize;curlevel:quarterword;curgroup:groupcode;
curboundary:0..savesize;{:293}{308:}magset:integer;
{:308}{319:}curcmd:eightbits;curchr:halfword;curcs:halfword;
curtok:halfword;{:319}{323:}inputstack:^instaterecord;
inputptr:0..stacksize;maxinstack:0..stacksize;curinput:instaterecord;
{:323}{326:}inopen:0..maxinopen;openparens:0..maxinopen;
inputfile:^alphafile;line:integer;linestack:^integer;
sourcefilenamestack:^strnumber;fullsourcefilenamestack:^strnumber;
{:326}{327:}scannerstatus:0..5;warningindex:halfword;defref:halfword;
{:327}{330:}paramstack:^halfword;paramptr:0..paramsize;
maxparamstack:integer;{:330}{331:}alignstate:integer;
{:331}{332:}baseptr:0..stacksize;{:332}{355:}parloc:halfword;
partoken:halfword;{:355}{383:}forceeof:boolean;
{:383}{389:}expanddepthcount:integer;{:389}{392:}isincsname:boolean;
{:392}{411:}curmark:array[0..4]of halfword;
{:411}{416:}longstate:113..116;
{:416}{417:}pstack:array[0..8]of halfword;{:417}{439:}curval:integer;
curvallevel:0..5;{:439}{467:}radix:smallnumber;
{:467}{476:}curorder:glueord;
{:476}{509:}readfile:array[0..15]of alphafile;
readopen:array[0..16]of 0..2;{:509}{518:}condptr:halfword;iflimit:0..4;
curif:smallnumber;ifline:integer;{:518}{522:}skipline:integer;
{:522}{541:}curname:strnumber;curarea:strnumber;curext:strnumber;
{:541}{542:}areadelimiter:poolpointer;extdelimiter:poolpointer;
{:542}{549:}formatdefaultlength:integer;TEXformatdefault:cstring;
{:549}{556:}nameinprogress:boolean;jobname:strnumber;logopened:boolean;
{:556}{561:}dvifile:bytefile;outputfilename:strnumber;
texmflogname:strnumber;{:561}{568:}tfmfile:bytefile;
{:568}{578:}fontinfo:^fmemoryword;fmemptr:fontindex;
fontptr:internalfontnumber;fontcheck:^fourquarters;fontsize:^scaled;
fontdsize:^scaled;fontparams:^fontindex;fontname:^strnumber;
fontarea:^strnumber;fontbc:^eightbits;fontec:^eightbits;
fontglue:^halfword;fontused:^boolean;hyphenchar:^integer;
skewchar:^integer;bcharlabel:^fontindex;fontbchar:^ninebits;
fontfalsebchar:^ninebits;{:578}{579:}charbase:^integer;
widthbase:^integer;heightbase:^integer;depthbase:^integer;
italicbase:^integer;ligkernbase:^integer;kernbase:^integer;
extenbase:^integer;parambase:^integer;
{:579}{584:}nullcharacter:fourquarters;{:584}{622:}totalpages:integer;
maxv:scaled;maxh:scaled;maxpush:integer;lastbop:integer;
deadcycles:integer;doingleaders:boolean;c:quarterword;
f:internalfontnumber;ruleht,ruledp,rulewd:scaled;g:halfword;
lq,lr:integer;{:622}{625:}dvibuf:^eightbits;halfbuf:integer;
dvilimit:integer;dviptr:integer;dvioffset:integer;dvigone:integer;
{:625}{635:}downptr,rightptr:halfword;{:635}{646:}dvih,dviv:scaled;
curh,curv:scaled;dvif:internalfontnumber;curs:integer;
{:646}{679:}pdfmemsize:integer;pdfmem:^integer;pdfmemptr:integer;
{:679}{683:}pdffile:bytefile;pdfbuf:^eightbits;pdfbufsize:integer;
pdfptr:integer;pdfopbuf:^eightbits;pdfosbuf:^eightbits;
pdfosbufsize:integer;pdfosobjnum:^integer;pdfosobjoff:^integer;
pdfosobjidx:halfword;pdfoscntr:integer;pdfopptr:integer;
pdfosptr:integer;pdfosmode:boolean;pdfosenable:boolean;
pdfoscurobjnum:integer;pdfgone:longinteger;pdfsaveoffset:longinteger;
zipwritestate:integer;fixedpdfminorversion:integer;
fixedpdfobjcompresslevel:integer;pdfminorversionwritten:boolean;
fixedpdfoutput:integer;fixedpdfoutputset:boolean;fixedgamma:integer;
fixedimagegamma:integer;fixedimagehicolor:boolean;
fixedimageapplygamma:integer;epochseconds:integer;microseconds:integer;
fixedpdfdraftmode:integer;fixedpdfdraftmodeset:boolean;
pdfpagegroupval:integer;{:683}{690:}onebp:scaled;onehundredbp:scaled;
onehundredinch:scaled;tenpow:array[0..9]of integer;scaledout:integer;
initpdfoutput:boolean;{:690}{694:}pdff:internalfontnumber;pdfh:scaled;
pdfv:scaled;pdftjstarth:scaled;curdeltah:scaled;pdfdeltah:scaled;
pdforiginh:scaled;pdforiginv:scaled;pdfdoingstring:boolean;
pdfdoingtext:boolean;minbpval:scaled;minfontval:scaled;
fixedpkresolution:integer;fixeddecimaldigits:integer;
fixedgentounicode:integer;fixedinclusioncopyfont:integer;
pkscalefactor:integer;pdfoutputoption:integer;pdfoutputvalue:integer;
pdfdraftmodeoption:integer;pdfdraftmodevalue:integer;pdfcurTma:integer;
pdflastf:internalfontnumber;pdflastfs:internalfontnumber;
pdfdummyfont:internalfontnumber;{:694}{699:}objtabsize:integer;
objtab:^objentry;headtab:array[1..9]of integer;pagestail:integer;
objptr:integer;sysobjptr:integer;pdflastpages:integer;
pdflastpage:integer;pdflaststream:integer;pdfstreamlength:longinteger;
pdfstreamlengthoffset:longinteger;pdfseekwritelength:boolean;
pdflastbyte:eightbits;pdfappendlistarg:integer;ff:integer;
pdfboxspecmedia:integer;pdfboxspeccrop:integer;pdfboxspecbleed:integer;
pdfboxspectrim:integer;pdfboxspecart:integer;
{:699}{704:}pdfimageprocset:integer;pdftextprocset:boolean;
{:704}{707:}pdffonttype:^eightbits;pdffontattr:^strnumber;
pdffontnobuiltintounicode:^boolean;
{:707}{711:}pdfcharused:^charusedarray;pdffontsize:^scaled;
pdffontnum:^integer;pdffontmap:^fmentryptr;pdffontlist:halfword;
pdfresnameprefix:strnumber;lasttokensstring:strnumber;
{:711}{713:}vfpacketbase:^integer;vfdefaultfont:^internalfontnumber;
vflocalfontnum:^internalfontnumber;vfpacketlength:integer;
vffile:bytefile;vfnf:internalfontnumber;vfefnts:^integer;
vfifnts:^internalfontnumber;tmpw:memoryword;
{:713}{726:}vfcurs:0..vfmaxrecursion;
vfstack:array[vfstackindex]of vfstackrecord;vfstackptr:vfstackindex;
{:726}{812:}pdftexbanner:strnumber;
{:812}{819:}totalstretch,totalshrink:array[glueord]of scaled;
lastbadness:integer;{:819}{820:}adjusttail:halfword;
{:820}{822:}pdffontblink:^internalfontnumber;
pdffontelink:^internalfontnumber;pdffontstretch:^integer;
pdffontshrink:^integer;pdffontstep:^integer;pdffontexpandratio:^integer;
pdffontautoexpand:^boolean;pdffontlpbase:^integer;
pdffontrpbase:^integer;pdffontefbase:^integer;pdffontknbsbase:^integer;
pdffontstbsbase:^integer;pdffontshbsbase:^integer;
pdffontknbcbase:^integer;pdffontknacbase:^integer;
fontexpandratio:integer;lastleftmostchar:halfword;
lastrightmostchar:halfword;hliststack:array[0..512]of halfword;
hliststacklevel:0..512;{:822}{830:}preadjusttail:halfword;
{:830}{838:}packbeginline:integer;{:838}{861:}emptyfield:twohalves;
nulldelimiter:fourquarters;{:861}{896:}curmlist:halfword;
curstyle:smallnumber;cursize:smallnumber;curmu:scaled;
mlistpenalties:boolean;{:896}{901:}curf:internalfontnumber;
curc:quarterword;curi:fourquarters;{:901}{941:}magicoffset:integer;
{:941}{947:}curalign:halfword;curspan:halfword;curloop:halfword;
alignptr:halfword;curhead,curtail:halfword;
curprehead,curpretail:halfword;{:947}{991:}justbox:halfword;
{:991}{998:}passive:halfword;printednode:halfword;passnumber:halfword;
{:998}{1000:}activewidth:array[1..8]of scaled;
curactivewidth:array[1..8]of scaled;background:array[1..8]of scaled;
breakwidth:array[1..8]of scaled;autobreaking:boolean;prevp:halfword;
firstp:halfword;prevcharp:halfword;nextcharp:halfword;
tryprevbreak:boolean;prevlegal:halfword;prevprevlegal:halfword;
prevautobreaking:boolean;prevactivewidth:array[1..8]of scaled;
rejectedcurp:halfword;beforerejectedcurp:boolean;
maxstretchratio:integer;maxshrinkratio:integer;curfontstep:integer;
{:1000}{1002:}noshrinkerroryet:boolean;{:1002}{1005:}curp:halfword;
secondpass:boolean;finalpass:boolean;threshold:integer;
{:1005}{1010:}minimaldemerits:array[0..3]of integer;
minimumdemerits:integer;bestplace:array[0..3]of halfword;
bestplline:array[0..3]of halfword;
{:1010}{1016:}discwidth:array[1..8]of scaled;
{:1016}{1024:}easyline:halfword;lastspecialline:halfword;
firstwidth:scaled;secondwidth:scaled;firstindent:scaled;
secondindent:scaled;{:1024}{1049:}bestbet:halfword;
fewestdemerits:integer;bestline:halfword;actuallooseness:integer;
linediff:integer;{:1049}{1070:}hc:array[0..65]of 0..256;hn:smallnumber;
ha,hb:halfword;hf:internalfontnumber;hu:array[0..63]of 0..256;
hyfchar:integer;curlang,initcurlang:ASCIIcode;
lhyf,rhyf,initlhyf,initrhyf:integer;hyfbchar:halfword;
{:1070}{1078:}hyf:array[0..64]of 0..9;initlist:halfword;initlig:boolean;
initlft:boolean;{:1078}{1083:}hyphenpassed:smallnumber;
{:1083}{1085:}curl,curr:halfword;curq:halfword;ligstack:halfword;
ligaturepresent:boolean;lfthit,rthit:boolean;
{:1085}{1099:}trietrl:^triepointer;trietro:^triepointer;
trietrc:^quarterword;hyfdistance:array[1..trieopsize]of smallnumber;
hyfnum:array[1..trieopsize]of smallnumber;
hyfnext:array[1..trieopsize]of trieopcode;
opstart:array[ASCIIcode]of 0..trieopsize;
{:1099}{1104:}hyphword:^strnumber;hyphlist:^halfword;
hyphlink:^hyphpointer;hyphcount:integer;hyphnext:integer;
{:1104}{1121:}ifdef('INITEX')trieophash:array[negtrieopsize..trieopsize]
of 0..trieopsize;trieused:array[ASCIIcode]of trieopcode;
trieoplang:array[1..trieopsize]of ASCIIcode;
trieopval:array[1..trieopsize]of trieopcode;trieopptr:0..trieopsize;
endif('INITEX')maxopused:trieopcode;smallop:boolean;
{:1121}{1125:}ifdef('INITEX')triec:^packedASCIIcode;trieo:^trieopcode;
triel:^triepointer;trier:^triepointer;trieptr:triepointer;
triehash:^triepointer;
endif('INITEX'){:1125}{1128:}ifdef('INITEX')trietaken:^boolean;
triemin:array[ASCIIcode]of triepointer;triemax:triepointer;
trienotready:boolean;
endif('INITEX'){:1128}{1149:}bestheightplusdepth:scaled;
{:1149}{1158:}pagetail:halfword;pagecontents:0..2;pagemaxdepth:scaled;
bestpagebreak:halfword;leastpagecost:integer;bestsize:scaled;
{:1158}{1160:}pagesofar:array[0..7]of scaled;lastglue:halfword;
lastpenalty:integer;lastkern:scaled;lastnodetype:integer;
insertpenalties:integer;{:1160}{1167:}outputactive:boolean;
{:1167}{1210:}mainf:internalfontnumber;maini:fourquarters;
mainj:fourquarters;maink:fontindex;mainp:halfword;mains:integer;
bchar:halfword;falsebchar:halfword;cancelboundary:boolean;
insdisc:boolean;{:1210}{1253:}curbox:halfword;
{:1253}{1445:}aftertoken:halfword;{:1445}{1460:}longhelpseen:boolean;
{:1460}{1478:}formatident:strnumber;{:1478}{1484:}fmtfile:wordfile;
{:1484}{1512:}readyalready:integer;
{:1512}{1523:}writefile:array[0..15]of alphafile;
writeopen:array[0..17]of boolean;{:1523}{1526:}writeloc:halfword;
{:1526}{1544:}pdflastobj:integer;{:1544}{1548:}pdflastxform:integer;
{:1548}{1551:}pdflastximage:integer;pdflastximagepages:integer;
pdflastximagecolordepth:integer;altrule:halfword;warnpdfpagebox:boolean;
{:1551}{1558:}pdflastannot:integer;{:1558}{1560:}pdflastlink:integer;
{:1560}{1571:}pdflastxpos:integer;pdflastypos:integer;
pdfsnapxrefpos:integer;pdfsnapyrefpos:integer;countdosnapy:integer;
{:1571}{1584:}pdfretval:integer;{:1584}{1626:}curpagewidth:scaled;
curpageheight:scaled;curhoffset:scaled;curvoffset:scaled;
pdfobjlist:halfword;pdfxformlist:halfword;pdfximagelist:halfword;
lastthread:halfword;pdfthreadht,pdfthreaddp,pdfthreadwd:scaled;
pdflastthreadid:halfword;pdflastthreadnamedid:boolean;
pdfthreadlevel:integer;pdfannotlist:halfword;pdflinklist:halfword;
pdfdestlist:halfword;pdfbeadlist:halfword;pdfobjcount:integer;
pdfxformcount:integer;pdfximagecount:integer;pdfcurform:integer;
pdffirstoutline,pdflastoutline,pdfparentoutline:integer;
pdfxformwidth,pdfxformheight,pdfxformdepth:scaled;pdfinfotoks:halfword;
pdfcatalogtoks:halfword;pdfcatalogopenaction:integer;
pdfnamestoks:halfword;pdfdestnamesptr:integer;destnamessize:integer;
destnames:^destnameentry;pkdpi:integer;imageorigx,imageorigy:integer;
pdftrailertoks:halfword;pdftraileridtoks:halfword;
genfakedinterwordspace:boolean;
{:1626}{1631:}pdflinkstack:array[1..pdfmaxlinklevel]of
pdflinkstackrecord;pdflinkstackptr:smallnumber;
{:1631}{1638:}isshippingpage:boolean;{:1638}{1650:}eTeXmode:0..1;
etexp:boolean;{:1650}{1658:}eofseen:^boolean;
{:1658}{1703:}LRptr:halfword;LRproblems:integer;curdir:smallnumber;
{:1703}{1748:}pseudofiles:halfword;{:1748}{1771:}grpstack:^savepointer;
ifstack:^halfword;{:1771}{1812:}maxregnum:halfword;
maxreghelpline:strnumber;{:1812}{1814:}saroot:array[0..6]of halfword;
curptr:halfword;sanull:memoryword;{:1814}{1833:}sachain:halfword;
salevel:quarterword;{:1833}{1840:}lastlinefill:halfword;
dolastlinefit:boolean;activenodesize:smallnumber;
fillwidth:array[0..2]of scaled;bestplshort:array[0..3]of scaled;
bestplglue:array[0..3]of scaled;{:1840}{1856:}hyphstart:triepointer;
hyphindex:triepointer;{:1856}{1857:}discptr:array[1..3]of halfword;
{:1857}{1865:}editnamestart:poolpointer;editnamelength,editline:integer;
ipcon:cinttype;stopatspace:boolean;{:1865}{1867:}savestrptr:strnumber;
savepoolptr:poolpointer;shellenabledp:cinttype;restrictedshell:cinttype;
outputcomment:^char;k,l:0..255;{:1867}{1869:}debugformatfile:boolean;
{:1869}{1876:}mltexp:boolean;{:1876}{1877:}mltexenabledp:boolean;
{:1877}{1882:}accentc,basec,replacec:integer;iac,ibc:fourquarters;
baseslant,accentslant:real;basexheight:scaled;
basewidth,baseheight:scaled;accentwidth,accentheight:scaled;
delta:scaled;{:1882}{1889:}enctexp:boolean;
{:1889}{1890:}enctexenabledp:boolean;
{:1890}{1899:}synctexoption:integer;{:1899}{1904:}synctexoffset:integer;
{:1904}procedure initialize;var{19:}i:integer;{:19}{181:}k:integer;
{:181}{1105:}z:hyphpointer;{:1105}begin{8:}{21:}xchr[32]:=' ';
xchr[33]:='!';xchr[34]:='"';xchr[35]:='#';xchr[36]:='$';xchr[37]:='%';
xchr[38]:='&';xchr[39]:='''';xchr[40]:='(';xchr[41]:=')';xchr[42]:='*';
xchr[43]:='+';xchr[44]:=',';xchr[45]:='-';xchr[46]:='.';xchr[47]:='/';
xchr[48]:='0';xchr[49]:='1';xchr[50]:='2';xchr[51]:='3';xchr[52]:='4';
xchr[53]:='5';xchr[54]:='6';xchr[55]:='7';xchr[56]:='8';xchr[57]:='9';
xchr[58]:=':';xchr[59]:=';';xchr[60]:='<';xchr[61]:='=';xchr[62]:='>';
xchr[63]:='?';xchr[64]:='@';xchr[65]:='A';xchr[66]:='B';xchr[67]:='C';
xchr[68]:='D';xchr[69]:='E';xchr[70]:='F';xchr[71]:='G';xchr[72]:='H';
xchr[73]:='I';xchr[74]:='J';xchr[75]:='K';xchr[76]:='L';xchr[77]:='M';
xchr[78]:='N';xchr[79]:='O';xchr[80]:='P';xchr[81]:='Q';xchr[82]:='R';
xchr[83]:='S';xchr[84]:='T';xchr[85]:='U';xchr[86]:='V';xchr[87]:='W';
xchr[88]:='X';xchr[89]:='Y';xchr[90]:='Z';xchr[91]:='[';xchr[92]:='\';
xchr[93]:=']';xchr[94]:='^';xchr[95]:='_';xchr[96]:='`';xchr[97]:='a';
xchr[98]:='b';xchr[99]:='c';xchr[100]:='d';xchr[101]:='e';
xchr[102]:='f';xchr[103]:='g';xchr[104]:='h';xchr[105]:='i';
xchr[106]:='j';xchr[107]:='k';xchr[108]:='l';xchr[109]:='m';
xchr[110]:='n';xchr[111]:='o';xchr[112]:='p';xchr[113]:='q';
xchr[114]:='r';xchr[115]:='s';xchr[116]:='t';xchr[117]:='u';
xchr[118]:='v';xchr[119]:='w';xchr[120]:='x';xchr[121]:='y';
xchr[122]:='z';xchr[123]:='{';xchr[124]:='|';xchr[125]:='}';
xchr[126]:='~';{:21}{23:}for i:=0 to 31 do xchr[i]:=i;
for i:=127 to 255 do xchr[i]:=i;
for i:=0 to 255 do mubyteread[i]:=-268435455;
for i:=0 to 255 do mubytewrite[i]:=0;
for i:=0 to 127 do mubytecswrite[i]:=-268435455;mubytekeep:=0;
mubytestart:=false;writenoexpanding:=false;csconverting:=false;
specialprinting:=false;messageprinting:=false;noconvert:=false;
activenoconvert:=false;{:23}{24:}for i:=0 to 255 do xord[chr(i)]:=127;
for i:=128 to 255 do xord[xchr[i]]:=i;
for i:=0 to 126 do xord[xchr[i]]:=i;
for i:=0 to 255 do xprn[i]:=(eightbitp or((i>=32)and(i<=126)));
if translatefilename then readtcxfile;
{:24}{74:}if interactionoption=4 then interaction:=3 else interaction:=
interactionoption;{:74}{77:}deletionsallowed:=true;setboxallowed:=true;
errorcount:=0;{:77}{80:}helpptr:=0;useerrhelp:=false;
{:80}{97:}interrupt:=0;OKtointerrupt:=true;{:97}{118:}twotothe[0]:=1;
for k:=1 to 30 do twotothe[k]:=2*twotothe[k-1];speclog[1]:=93032640;
speclog[2]:=38612034;speclog[3]:=17922280;speclog[4]:=8662214;
speclog[5]:=4261238;speclog[6]:=2113709;speclog[7]:=1052693;
speclog[8]:=525315;speclog[9]:=262400;speclog[10]:=131136;
speclog[11]:=65552;speclog[12]:=32772;speclog[13]:=16385;
for k:=14 to 27 do speclog[k]:=twotothe[27-k];speclog[28]:=1;
{:118}{184:}ifdef('TEXMF_DEBUG')wasmemend:=memmin;waslomax:=memmin;
washimin:=memmax;panicking:=false;
endif('TEXMF_DEBUG'){:184}{233:}nestptr:=0;maxneststack:=0;
curlist.modefield:=1;curlist.headfield:=memtop-1;
curlist.tailfield:=memtop-1;curlist.eTeXauxfield:=-268435455;
curlist.auxfield.int:=-65536000;curlist.mlfield:=0;curlist.pgfield:=0;
shownmode:=0;pagecontents:=0;pagetail:=memtop-2;lastglue:=268435455;
lastpenalty:=0;lastkern:=0;pagesofar[7]:=0;pagemaxdepth:=0;
{:233}{272:}for k:=27177 to 28082 do xeqlevel[k]:=1;
{:272}{276:}nonewcontrolsequence:=true;prim[0].lh:=0;prim[0].rh:=0;
for k:=1 to 2100 do prim[k]:=prim[0];primeqtb[0].hh.b1:=0;
primeqtb[0].hh.b0:=103;primeqtb[0].hh.rh:=-268435455;
for k:=1 to 2100 do primeqtb[k]:=primeqtb[0];{:276}{294:}saveptr:=0;
curlevel:=1;curgroup:=0;curboundary:=0;maxsavestack:=0;
{:294}{309:}magset:=0;{:309}{390:}expanddepthcount:=0;
{:390}{393:}isincsname:=false;{:393}{412:}curmark[0]:=-268435455;
curmark[1]:=-268435455;curmark[2]:=-268435455;curmark[3]:=-268435455;
curmark[4]:=-268435455;{:412}{468:}curval:=0;curvallevel:=0;radix:=0;
curorder:=0;{:468}{510:}for k:=0 to 16 do readopen[k]:=2;
{:510}{519:}condptr:=-268435455;iflimit:=0;curif:=0;ifline:=0;
{:519}{580:}{:580}{585:}nullcharacter.b0:=0;nullcharacter.b1:=0;
nullcharacter.b2:=0;nullcharacter.b3:=0;{:585}{623:}totalpages:=0;
maxv:=0;maxh:=0;maxpush:=0;lastbop:=-1;doingleaders:=false;
deadcycles:=0;curs:=-1;{:623}{626:}halfbuf:=dvibufsize div 2;
dvilimit:=dvibufsize;dviptr:=0;dvioffset:=0;dvigone:=0;
{:626}{636:}downptr:=-268435455;rightptr:=-268435455;
{:636}{680:}pdfmemptr:=1;pdfmemsize:=infpdfmemsize;
{:680}{684:}pdfgone:=0;pdfosmode:=false;pdfptr:=0;pdfopptr:=0;
pdfosptr:=0;pdfoscurobjnum:=0;pdfoscntr:=0;pdfbufsize:=pdfopbufsize;
pdfosbufsize:=infpdfosbufsize;pdfbuf:=pdfopbuf;
pdfseekwritelength:=false;zipwritestate:=0;
pdfminorversionwritten:=false;fixedpdfoutputset:=false;
fixedpdfdraftmodeset:=false;{:684}{691:}onebp:=65782;
onehundredbp:=6578176;onehundredinch:=473628672;tenpow[0]:=1;
for i:=1 to 9 do tenpow[i]:=10*tenpow[i-1];initpdfoutput:=false;
{:691}{700:}objptr:=0;sysobjptr:=0;objtabsize:=infobjtabsize;
destnamessize:=infdestnamessize;for k:=1 to 9 do headtab[k]:=0;
pdfboxspecmedia:=1;pdfboxspeccrop:=2;pdfboxspecbleed:=3;
pdfboxspectrim:=4;pdfboxspecart:=5;pdfdummyfont:=0;
{:700}{712:}pdfresnameprefix:=0;lasttokensstring:=0;{:712}{714:}vfnf:=0;
{:714}{727:}vfcurs:=0;vfstackptr:=0;{:727}{821:}adjusttail:=-268435455;
lastbadness:=0;{:821}{831:}preadjusttail:=-268435455;
{:831}{839:}packbeginline:=0;{:839}{862:}emptyfield.rh:=0;
emptyfield.lh:=-268435455;nulldelimiter.b0:=0;nulldelimiter.b1:=0;
nulldelimiter.b2:=0;nulldelimiter.b3:=0;
{:862}{948:}alignptr:=-268435455;curalign:=-268435455;
curspan:=-268435455;curloop:=-268435455;curhead:=-268435455;
curtail:=-268435455;curprehead:=-268435455;curpretail:=-268435455;
{:948}{1106:}for z:=0 to hyphsize do begin hyphword[z]:=0;
hyphlist[z]:=-268435455;hyphlink[z]:=0;end;hyphcount:=0;hyphnext:=608;
if hyphnext>hyphsize then hyphnext:=607;
{:1106}{1168:}outputactive:=false;insertpenalties:=0;
{:1168}{1211:}ligaturepresent:=false;cancelboundary:=false;
lfthit:=false;rthit:=false;insdisc:=false;{:1211}{1446:}aftertoken:=0;
{:1446}{1461:}longhelpseen:=false;{:1461}{1479:}formatident:=0;
{:1479}{1524:}for k:=0 to 17 do writeopen[k]:=false;
{:1524}{1552:}altrule:=-268435455;warnpdfpagebox:=true;
{:1552}{1572:}countdosnapy:=0;
{:1572}{1585:}secondsandmicros(epochseconds,microseconds);initstarttime;
{:1585}{1627:}pdffirstoutline:=0;pdflastoutline:=0;pdfparentoutline:=0;
pdfobjcount:=0;pdfxformcount:=0;pdfximagecount:=0;pdfdestnamesptr:=0;
pdfinfotoks:=-268435455;pdfcatalogtoks:=-268435455;
pdfnamestoks:=-268435455;pdfcatalogopenaction:=0;
pdftrailertoks:=-268435455;pdftraileridtoks:=-268435455;
genfakedinterwordspace:=false;{:1627}{1632:}pdflinkstackptr:=0;
{:1632}{1704:}LRptr:=-268435455;LRproblems:=0;curdir:=0;
{:1704}{1749:}pseudofiles:=-268435455;
{:1749}{1815:}saroot[6]:=-268435455;sanull.hh.lh:=-268435455;
sanull.hh.rh:=-268435455;{:1815}{1834:}sachain:=-268435455;salevel:=0;
{:1834}{1858:}discptr[2]:=-268435455;discptr[3]:=-268435455;
{:1858}{1866:}editnamestart:=0;stopatspace:=true;
{:1866}{1878:}mltexenabledp:=false;{:1878}{1891:}enctexenabledp:=false;
{:1891}ifdef('INITEX')if iniversion then begin{182:}for k:=membot+1 to
membot+19 do mem[k].int:=0;k:=membot;
while k<=membot+19 do begin mem[k].hh.rh:=-268435454;mem[k].hh.b0:=0;
mem[k].hh.b1:=0;k:=k+4;end;mem[membot+6].int:=65536;
mem[membot+4].hh.b0:=1;mem[membot+10].int:=65536;mem[membot+8].hh.b0:=2;
mem[membot+14].int:=65536;mem[membot+12].hh.b0:=1;
mem[membot+15].int:=65536;mem[membot+12].hh.b1:=1;
mem[membot+18].int:=-65536;mem[membot+16].hh.b0:=1;rover:=membot+20;
mem[rover].hh.rh:=268435455;mem[rover].hh.lh:=1000;
mem[rover+1].hh.lh:=rover;mem[rover+1].hh.rh:=rover;
lomemmax:=rover+1000;mem[lomemmax].hh.rh:=-268435455;
mem[lomemmax].hh.lh:=-268435455;
for k:=memtop-14 to memtop do mem[k]:=mem[lomemmax];
{967:}mem[memtop-10].hh.lh:=19614;{:967}{974:}mem[memtop-9].hh.rh:=256;
mem[memtop-9].hh.lh:=-268435455;{:974}{997:}mem[memtop-7].hh.b0:=1;
mem[memtop-6].hh.lh:=268435455;mem[memtop-7].hh.b1:=0;
{:997}{1159:}mem[memtop].hh.b1:=255;mem[memtop].hh.b0:=1;
mem[memtop].hh.rh:=memtop;{:1159}{1166:}mem[memtop-2].hh.b0:=10;
mem[memtop-2].hh.b1:=0;{:1166};avail:=-268435455;memend:=memtop;
himemmin:=memtop-14;varused:=membot+20-membot;dynused:=15;
{:182}{240:}eqtb[24527].hh.b0:=103;eqtb[24527].hh.rh:=-268435455;
eqtb[24527].hh.b1:=0;for k:=1 to eqtbtop do eqtb[k]:=eqtb[24527];
{:240}{246:}eqtb[24528].hh.rh:=membot;eqtb[24528].hh.b1:=1;
eqtb[24528].hh.b0:=119;for k:=24529 to 25057 do eqtb[k]:=eqtb[24528];
mem[membot].hh.rh:=mem[membot].hh.rh+530;
{:246}{250:}eqtb[25058].hh.rh:=-268435455;eqtb[25058].hh.b0:=120;
eqtb[25058].hh.b1:=1;for k:=25329 to 25332 do eqtb[k]:=eqtb[25058];
for k:=25059 to 25328 do eqtb[k]:=eqtb[24527];
eqtb[25333].hh.rh:=-268435455;eqtb[25333].hh.b0:=121;
eqtb[25333].hh.b1:=1;for k:=25334 to 25588 do eqtb[k]:=eqtb[25333];
eqtb[25589].hh.rh:=0;eqtb[25589].hh.b0:=122;eqtb[25589].hh.b1:=1;
for k:=25593 to 25640 do eqtb[k]:=eqtb[25589];eqtb[25641].hh.rh:=0;
eqtb[25641].hh.b0:=122;eqtb[25641].hh.b1:=1;
for k:=25642 to 27176 do eqtb[k]:=eqtb[25641];
for k:=0 to 255 do begin eqtb[25641+k].hh.rh:=12;eqtb[26665+k].hh.rh:=k;
eqtb[26409+k].hh.rh:=1000;end;eqtb[25654].hh.rh:=5;
eqtb[25673].hh.rh:=10;eqtb[25733].hh.rh:=0;eqtb[25678].hh.rh:=14;
eqtb[25768].hh.rh:=15;eqtb[25641].hh.rh:=9;
for k:=48 to 57 do eqtb[26665+k].hh.rh:=k+28672;
for k:=65 to 90 do begin eqtb[25641+k].hh.rh:=11;
eqtb[25641+k+32].hh.rh:=11;eqtb[26665+k].hh.rh:=k+28928;
eqtb[26665+k+32].hh.rh:=k+28960;eqtb[25897+k].hh.rh:=k+32;
eqtb[25897+k+32].hh.rh:=k+32;eqtb[26153+k].hh.rh:=k;
eqtb[26153+k+32].hh.rh:=k;eqtb[26409+k].hh.rh:=999;end;
{:250}{258:}for k:=27177 to 27536 do eqtb[k].int:=0;
eqtb[27232].int:=256;eqtb[27233].int:=-1;eqtb[27194].int:=1000;
eqtb[27178].int:=10000;eqtb[27218].int:=1;eqtb[27217].int:=25;
eqtb[27222].int:=92;eqtb[27225].int:=13;
for k:=0 to 255 do eqtb[27537+k].int:=-1;eqtb[27583].int:=0;
{:258}{268:}for k:=27793 to 28082 do eqtb[k].int:=0;
{:268}{277:}primused:=2100;hashused:=15514;hashhigh:=0;cscount:=0;
eqtb[15523].hh.b0:=118;hash[15523].rh:=574;eqtb[15525].hh.b0:=39;
eqtb[15525].hh.rh:=1;eqtb[15525].hh.b1:=1;hash[15525].rh:=575;
{:277}{581:}{:581}{675:}eqtb[27814].int:=(onehundredinch+50)div 100;
eqtb[27815].int:=(onehundredinch+50)div 100;eqtb[27240].int:=9;
eqtb[27259].int:=0;eqtb[27241].int:=3;eqtb[27243].int:=72;
eqtb[27248].int:=4;eqtb[27252].int:=1000;eqtb[27253].int:=2200;
eqtb[27254].int:=1;eqtb[27255].int:=0;eqtb[27826].int:=onebp;
eqtb[27264].int:=0;{:675}{1065:}eqtb[27825].int:=-65536000;
eqtb[27823].int:=eqtb[27825].int;eqtb[27824].int:=eqtb[27825].int;
eqtb[27821].int:=eqtb[27825].int;eqtb[27822].int:=eqtb[27825].int;
{:1065}{1124:}for k:=-trieopsize to trieopsize do trieophash[k]:=0;
for k:=0 to 255 do trieused[k]:=mintrieop;maxopused:=mintrieop;
trieopptr:=0;{:1124}{1129:}trienotready:=true;
{:1129}{1395:}hash[15514].rh:=1600;
{:1395}{1480:}if iniversion then formatident:=1687;
{:1480}{1614:}hash[15522].rh:=1899;eqtb[15522].hh.b1:=1;
eqtb[15522].hh.b0:=115;eqtb[15522].hh.rh:=-268435455;
{:1614}{1651:}eTeXmode:=0;{1810:}maxregnum:=255;maxreghelpline:=790;
{:1810}{:1651}{1816:}for i:=0 to 5 do saroot[i]:=-268435455;
{:1816}{1852:}{:1852}end;endif('INITEX'){:8}{1905:}synctexoffset:=27280;
{:1905}end;{57:}procedure println;
begin case selector of 19:begin writeln(stdout);writeln(logfile);
termoffset:=0;fileoffset:=0;end;18:begin writeln(logfile);fileoffset:=0;
end;17:begin writeln(stdout);termoffset:=0;end;16,20,21:;
others:writeln(writefile[selector])end;end;
{:57}{58:}procedure printchar(s:ASCIIcode);label 10;
begin if{262:}s=eqtb[27226].int{:262}then if selector<20 then begin
println;goto 10;end;case selector of 19:begin write(stdout,xchr[s]);
write(logfile,xchr[s]);incr(termoffset);incr(fileoffset);
if termoffset=maxprintline then begin writeln(stdout);termoffset:=0;end;
if fileoffset=maxprintline then begin writeln(logfile);fileoffset:=0;
end;end;18:begin write(logfile,xchr[s]);incr(fileoffset);
if fileoffset=maxprintline then println;end;
17:begin write(stdout,xchr[s]);incr(termoffset);
if termoffset=maxprintline then println;end;16:;
20:if tally<trickcount then trickbuf[tally mod errorline]:=s;
21:begin if poolptr<poolsize then begin strpool[poolptr]:=s;
incr(poolptr);end;end;others:write(writefile[selector],xchr[s])end;
incr(tally);10:end;{:58}{59:}procedure print(s:integer);label 10;
var j:poolpointer;nl:integer;
begin if s>=strptr then s:=261 else if s<256 then if s<0 then s:=261
else begin if(selector>20)and(not specialprinting)and(not
messageprinting)then begin printchar(s);goto 10;end;
if({262:}s=eqtb[27226].int{:262})then if selector<20 then begin println;
noconvert:=false;goto 10;
end else if messageprinting then begin printchar(s);noconvert:=false;
goto 10;end;
if(eqtb[27237].int>0)and(not noconvert)and(mubytewrite[s]>0)then s:=
mubytewrite[s]else if xprn[s]or specialprinting then begin printchar(s);
noconvert:=false;goto 10;end;noconvert:=false;nl:=eqtb[27226].int;
eqtb[27226].int:=-1;j:=strstart[s];
while j<strstart[s+1]do begin printchar(strpool[j]);incr(j);end;
eqtb[27226].int:=nl;goto 10;end;j:=strstart[s];
while j<strstart[s+1]do begin printchar(strpool[j]);incr(j);end;10:end;
{:59}{60:}procedure slowprint(s:integer);var j:poolpointer;
begin if(s>=strptr)or(s<256)then print(s)else begin j:=strstart[s];
while j<strstart[s+1]do begin print(strpool[j]);incr(j);end;end;end;
{:60}{62:}procedure printnl(s:strnumber);
begin if((termoffset>0)and(odd(selector)))or((fileoffset>0)and(selector
>=18))then println;print(s);end;
{:62}{63:}procedure printesc(s:strnumber);var c:integer;
begin{261:}c:=eqtb[27222].int{:261};if c>=0 then if c<256 then print(c);
slowprint(s);end;{:63}{64:}procedure printthedigs(k:eightbits);
begin while k>0 do begin decr(k);
if dig[k]<10 then printchar(48+dig[k])else printchar(55+dig[k]);end;end;
{:64}{65:}procedure printint(n:longinteger);var k:0..23;m:longinteger;
begin k:=0;if n<0 then begin printchar(45);
if n>-100000000 then n:=-n else begin m:=-1-n;n:=m div 10;
m:=(m mod 10)+1;k:=1;if m<10 then dig[0]:=m else begin dig[0]:=0;
incr(n);end;end;end;repeat dig[k]:=n mod 10;n:=n div 10;incr(k);
until n=0;printthedigs(k);end;{:65}{284:}procedure printcs(p:integer);
var q:halfword;s:strnumber;
begin if activenoconvert and(not noconvert)and(eqtb[p].hh.b0=94)and(eqtb
[p].hh.rh=11)then begin noconvert:=true;goto 10;end;s:=0;
if csconverting and(not noconvert)then begin q:=mubytecswrite[p mod 128]
;
while q<>-268435455 do if mem[q].hh.lh=p then begin s:=mem[mem[q].hh.rh]
.hh.lh;q:=-268435455;end else q:=mem[mem[q].hh.rh].hh.rh;end;
noconvert:=false;
if s>0 then print(s)else if p<514 then if p>=257 then if p=513 then
begin printesc(578);printesc(579);printchar(32);
end else begin printesc(p-257);
if eqtb[25641+p-257].hh.rh=11 then printchar(32);
end else if p<1 then printesc(580)else print(p-1)else if((p>=24527)and(p
<=28082))or(p>eqtbtop)then printesc(580)else if(hash[p].rh>=strptr)then
printesc(581)else begin printesc(hash[p].rh);printchar(32);end;10:end;
{:284}{285:}procedure sprintcs(p:halfword);
begin if p<514 then if p<257 then print(p-1)else if p<513 then printesc(
p-257)else begin printesc(578);printesc(579);
end else printesc(hash[p].rh);end;
{:285}{547:}procedure printfilename(n,a,e:integer);
var mustquote:boolean;j:poolpointer;begin mustquote:=false;
if a<>0 then begin j:=strstart[a];
while(not mustquote)and(j<strstart[a+1])do begin mustquote:=strpool[j]=
32;incr(j);end;end;if n<>0 then begin j:=strstart[n];
while(not mustquote)and(j<strstart[n+1])do begin mustquote:=strpool[j]=
32;incr(j);end;end;if e<>0 then begin j:=strstart[e];
while(not mustquote)and(j<strstart[e+1])do begin mustquote:=strpool[j]=
32;incr(j);end;end;if mustquote then printchar(34);
if a<>0 then for j:=strstart[a]to strstart[a+1]-1 do if strpool[j]<>34
then print(strpool[j]);
if n<>0 then for j:=strstart[n]to strstart[n+1]-1 do if strpool[j]<>34
then print(strpool[j]);
if e<>0 then for j:=strstart[e]to strstart[e+1]-1 do if strpool[j]<>34
then print(strpool[j]);if mustquote then printchar(34);end;
{:547}{876:}procedure printsize(s:integer);
begin if s=0 then printesc(432)else if s=16 then printesc(433)else
printesc(434);end;{:876}{1600:}procedure printwritewhatsit(s:strnumber;
p:halfword);begin printesc(s);
if mem[p+1].hh.b0<16 then printint(mem[p+1].hh.b0)else if mem[p+1].hh.b0
=16 then printchar(42)else printchar(45);
if(s=676)and(mem[p+1].hh.b1<>64)then begin printchar(60);
printint(mem[p+1].hh.b1-64);printchar(62);end;end;
{:1600}{1820:}procedure printsanum(q:halfword);var n:halfword;
begin if mem[q].hh.b0<32 then n:=mem[q+1].hh.rh else begin n:=mem[q].hh.
b0 mod 16;q:=mem[q].hh.rh;n:=n+16*mem[q].hh.b0;q:=mem[q].hh.rh;
n:=n+256*(mem[q].hh.b0+16*mem[mem[q].hh.rh].hh.b0);end;printint(n);end;
{:1820}{1868:}procedure printcsnames(hstart:integer;hfinish:integer);
var c,h:integer;
begin writeln(stderr,'fmtdebug:csnames from ',hstart,' to ',hfinish,':')
;for h:=hstart to hfinish do begin if hash[h].rh>0 then begin for c:=
strstart[hash[h].rh]to strstart[hash[h].rh+1]-1 do begin putbyte(strpool
[c],stderr);end;writeln(stderr,'|');end;end;end;
{:1868}{1870:}procedure printfileline;var level:0..maxinopen;
begin level:=inopen;
while(level>0)and(fullsourcefilenamestack[level]=0)do decr(level);
if level=0 then printnl(264)else begin printnl(345);
print(fullsourcefilenamestack[level]);print(58);
if level=inopen then printint(line)else printint(linestack[level+1]);
print(649);end;end;
{:1870}{1892:}function readbuffer(var i:integer):ASCIIcode;
var p:halfword;lastfound:integer;lasttype:integer;begin mubyteskip:=0;
mubytetoken:=0;readbuffer:=buffer[i];
if eqtb[27235].int=0 then begin if mubytekeep>0 then mubytekeep:=0;
goto 10;end;lastfound:=-2;
if(i=curinput.startfield)and(not mubytestart)then begin mubytekeep:=0;
if(eqtb[27225].int>=0)and(eqtb[27225].int<256)then if mubyteread[eqtb[
27225].int]<>-268435455 then begin mubytestart:=true;mubyteskip:=-1;
p:=mubyteread[eqtb[27225].int];goto 22;end;end;20:mubytestart:=false;
if(mubyteread[buffer[i]]=-268435455)or(mubytekeep>0)then begin if
mubytekeep>0 then decr(mubytekeep);goto 10;end;p:=mubyteread[buffer[i]];
22:if mem[p].hh.b0>=64 then begin lasttype:=mem[p].hh.b0-64;
p:=mem[p].hh.rh;mubytetoken:=mem[p].hh.lh;lastfound:=mubyteskip;
end else if mem[p].hh.b0>0 then begin lasttype:=mem[p].hh.b0;
mubytetoken:=mem[p].hh.rh;goto 40;end;incr(mubyteskip);
if i+mubyteskip>curinput.limitfield then begin mubyteskip:=0;
if mubytestart then goto 20;goto 10;end;repeat p:=mem[p].hh.rh;
if mem[mem[p].hh.lh].hh.b1=buffer[i+mubyteskip]then begin p:=mem[p].hh.
lh;goto 22;end;until mem[p].hh.rh=-268435455;mubyteskip:=0;
if mubytestart then goto 20;if lastfound=-2 then goto 10;
mubyteskip:=lastfound;
40:if mubytetoken<256 then begin readbuffer:=mubytetoken;mubytetoken:=0;
i:=i+mubyteskip;
if mubytestart and(i>=curinput.startfield)then mubytestart:=false;
goto 10;end else begin readbuffer:=0;
if lasttype=60 then i:=i+mubyteskip else begin decr(i);
mubytekeep:=lasttype;if i<curinput.startfield then mubytestart:=true;
if lasttype=52 then mubytekeep:=10000;
if lasttype=51 then mubytekeep:=mubyteskip+1;mubyteskip:=-1;end;
if mubytestart and(i>=curinput.startfield)then mubytestart:=false;
goto 10;end;10:end;{:1892}{1894:}procedure printbuffer(var i:integer);
var c:ASCIIcode;
begin if eqtb[27235].int=0 then print(buffer[i])else if eqtb[27237].int>
0 then printchar(buffer[i])else begin c:=readbuffer(i);
if mubytetoken>0 then printcs(mubytetoken-4095)else print(c);end;
incr(i);end;{:1894}{78:}procedure normalizeselector;forward;
procedure gettoken;forward;procedure terminput;forward;
procedure showcontext;forward;procedure beginfilereading;forward;
procedure openlogfile;forward;procedure closefilesandterminate;forward;
procedure clearforerrorprompt;forward;procedure giveerrhelp;forward;
ifdef('TEXMF_DEBUG')procedure debughelp;forward;
endif('TEXMF_DEBUG'){:78}{81:}noreturn procedure jumpout;
begin closefilesandterminate;begin fflush(stdout);readyalready:=0;
if(history<>0)and(history<>1)then uexit(1)else uexit(0);end;end;
{:81}{82:}procedure error;label 22,10;var c:ASCIIcode;
s1,s2,s3,s4:integer;begin if history<2 then history:=2;printchar(46);
showcontext;if(haltonerrorp)then begin history:=3;jumpout;end;
if interaction=3 then{83:}while true do begin 22:clearforerrorprompt;
begin;print(266);terminput;end;if last=first then goto 10;
c:=buffer[first];if c>=97 then c:=c-32;
{84:}case c of 48,49,50,51,52,53,54,55,56,57:if deletionsallowed then
{88:}begin s1:=curtok;s2:=curcmd;s3:=curchr;s4:=alignstate;
alignstate:=1000000;OKtointerrupt:=false;
if(last>first+1)and(buffer[first+1]>=48)and(buffer[first+1]<=57)then c:=
c*10+buffer[first+1]-48*11 else c:=c-48;while c>0 do begin gettoken;
decr(c);end;curtok:=s1;curcmd:=s2;curchr:=s3;alignstate:=s4;
OKtointerrupt:=true;begin helpptr:=2;helpline[1]:=279;helpline[0]:=280;
end;showcontext;goto 22;end{:88};ifdef('TEXMF_DEBUG')68:begin debughelp;
goto 22;end;
endif('TEXMF_DEBUG')69:if baseptr>0 then begin editnamestart:=strstart[
inputstack[baseptr].namefield];
editnamelength:=strstart[inputstack[baseptr].namefield+1]-strstart[
inputstack[baseptr].namefield];editline:=line;jumpout;end;
72:{89:}begin if useerrhelp then begin giveerrhelp;useerrhelp:=false;
end else begin if helpptr=0 then begin helpptr:=2;helpline[1]:=281;
helpline[0]:=282;end;repeat decr(helpptr);print(helpline[helpptr]);
println;until helpptr=0;end;begin helpptr:=4;helpline[3]:=283;
helpline[2]:=282;helpline[1]:=284;helpline[0]:=285;end;goto 22;end{:89};
73:{87:}begin beginfilereading;
if last>first+1 then begin curinput.locfield:=first+1;buffer[first]:=32;
end else begin begin;print(278);terminput;end;curinput.locfield:=first;
end;first:=last;curinput.limitfield:=last-1;goto 10;end{:87};
81,82,83:{86:}begin errorcount:=0;interaction:=0+c-81;print(273);
case c of 81:begin printesc(274);decr(selector);end;82:printesc(275);
83:printesc(276);end;print(277);println;fflush(stdout);goto 10;end{:86};
88:begin interaction:=2;jumpout;end;others:end;{85:}begin print(267);
printnl(268);printnl(269);if baseptr>0 then print(270);
if deletionsallowed then printnl(271);printnl(272);end{:85}{:84};
end{:83};incr(errorcount);if errorcount=100 then begin printnl(265);
history:=3;jumpout;end;{90:}if interaction>0 then decr(selector);
if useerrhelp then begin println;giveerrhelp;
end else while helpptr>0 do begin decr(helpptr);
printnl(helpline[helpptr]);end;println;
if interaction>0 then incr(selector);println{:90};10:end;
{:82}{93:}noreturn procedure fatalerror(s:strnumber);
begin normalizeselector;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(287);
end;begin helpptr:=1;helpline[0]:=s;end;
begin if interaction=3 then interaction:=2;if logopened then error;
ifdef('TEXMF_DEBUG')if interaction>0 then debughelp;
endif('TEXMF_DEBUG')history:=3;jumpout;end;end;
{:93}{94:}noreturn procedure overflow(s:strnumber;n:integer);
begin normalizeselector;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(288);
end;print(s);printchar(61);printint(n);printchar(93);begin helpptr:=2;
helpline[1]:=289;helpline[0]:=290;end;
begin if interaction=3 then interaction:=2;if logopened then error;
ifdef('TEXMF_DEBUG')if interaction>0 then debughelp;
endif('TEXMF_DEBUG')history:=3;jumpout;end;end;
{:94}{95:}noreturn procedure confusion(s:strnumber);
begin normalizeselector;
if history<2 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(291);
end;print(s);printchar(41);begin helpptr:=1;helpline[0]:=292;end;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(293);
end;begin helpptr:=2;helpline[1]:=294;helpline[0]:=295;end;end;
begin if interaction=3 then interaction:=2;if logopened then error;
ifdef('TEXMF_DEBUG')if interaction>0 then debughelp;
endif('TEXMF_DEBUG')history:=3;jumpout;end;end;
{:95}{:4}{31:}{[35:]begin curinput.locfield:=first;
curinput.limitfield:=last-1;overflow(258,bufsize);end[:35]}
{:31}{37:}function initterminal:boolean;label 10;begin topenin;
if last>first then begin curinput.locfield:=first;
while(curinput.locfield<last)and(buffer[curinput.locfield]=' ')do incr(
curinput.locfield);
if curinput.locfield<last then begin initterminal:=true;goto 10;end;end;
while true do begin;write(stdout,'**');fflush(stdout);
if not inputln(stdin,true)then begin writeln(stdout);
writeln(stdout,'! End of file on the terminal... why?');
initterminal:=false;goto 10;end;curinput.locfield:=first;
while(curinput.locfield<last)and(buffer[curinput.locfield]=32)do incr(
curinput.locfield);
if curinput.locfield<last then begin initterminal:=true;goto 10;end;
writeln(stdout,'Please type the name of your input file.');end;10:end;
{:37}{43:}function makestring:strnumber;
begin if strptr=maxstrings then overflow(260,maxstrings-initstrptr);
incr(strptr);strstart[strptr]:=poolptr;makestring:=strptr-1;end;
{:43}{45:}function streqbuf(s:strnumber;k:integer):boolean;label 45;
var j:poolpointer;result:boolean;begin j:=strstart[s];
while j<strstart[s+1]do begin if strpool[j]<>buffer[k]then begin result
:=false;goto 45;end;incr(j);incr(k);end;result:=true;
45:streqbuf:=result;end;
{:45}{46:}function streqstr(s,t:strnumber):boolean;label 45;
var j,k:poolpointer;result:boolean;begin result:=false;
if(strstart[s+1]-strstart[s])<>(strstart[t+1]-strstart[t])then goto 45;
j:=strstart[s];k:=strstart[t];
while j<strstart[s+1]do begin if strpool[j]<>strpool[k]then goto 45;
incr(j);incr(k);end;result:=true;45:streqstr:=result;end;
{:46}{47:}{1874:}function searchstring(search:strnumber):strnumber;
label 40;var result:strnumber;s:strnumber;len:integer;begin result:=0;
len:=(strstart[search+1]-strstart[search]);
if len=0 then begin result:=345;goto 40;end else begin s:=search-1;
while s>255 do begin if(strstart[s+1]-strstart[s])=len then if streqstr(
s,search)then begin result:=s;goto 40;end;decr(s);end;end;
40:searchstring:=result;end;
{:1874}{1875:}function slowmakestring:strnumber;label 10;
var s:strnumber;t:strnumber;begin t:=makestring;s:=searchstring(t);
if s>0 then begin begin decr(strptr);poolptr:=strstart[strptr];end;
slowmakestring:=s;goto 10;end;slowmakestring:=t;10:end;
{:1875}ifdef('INITEX')function getstringsstarted:boolean;label 30,10;
var k,l:0..255;g:strnumber;begin poolptr:=0;strptr:=0;strstart[0]:=0;
{48:}for k:=0 to 255 do begin if({49:}(k<32)or(k>126){:49})then begin
begin strpool[poolptr]:=94;incr(poolptr);end;begin strpool[poolptr]:=94;
incr(poolptr);end;if k<64 then begin strpool[poolptr]:=k+64;
incr(poolptr);end else if k<128 then begin strpool[poolptr]:=k-64;
incr(poolptr);end else begin l:=k div 16;
if l<10 then begin strpool[poolptr]:=l+48;incr(poolptr);
end else begin strpool[poolptr]:=l+87;incr(poolptr);end;l:=k mod 16;
if l<10 then begin strpool[poolptr]:=l+48;incr(poolptr);
end else begin strpool[poolptr]:=l+87;incr(poolptr);end;end;
end else begin strpool[poolptr]:=k;incr(poolptr);end;g:=makestring;
end{:48};{51:}g:=loadpoolstrings((poolsize-stringvacancies));
if g=0 then begin;writeln(stdout,'! You have to increase POOLSIZE.');
getstringsstarted:=false;goto 10;end;getstringsstarted:=true;{:51};
10:end;endif('INITEX'){:47}{66:}procedure printtwo(n:integer);
begin n:=abs(n)mod 100;printchar(48+(n div 10));
printchar(48+(n mod 10));end;{:66}{67:}procedure printhex(n:integer);
var k:0..22;begin k:=0;printchar(34);repeat dig[k]:=n mod 16;
n:=n div 16;incr(k);until n=0;printthedigs(k);end;
{:67}{69:}procedure printromanint(n:integer);label 10;
var j,k:poolpointer;u,v:nonnegativeinteger;begin j:=strstart[262];
v:=1000;while true do begin while n>=v do begin printchar(strpool[j]);
n:=n-v;end;if n<=0 then goto 10;k:=j+2;u:=v div(strpool[k-1]-48);
if strpool[k-1]=50 then begin k:=k+2;u:=u div(strpool[k-1]-48);end;
if n+u>=v then begin printchar(strpool[k]);n:=n+u;end else begin j:=j+2;
v:=v div(strpool[j-1]-48);end;end;10:end;
{:69}{70:}procedure printcurrentstring;var j:poolpointer;
begin j:=strstart[strptr];
while j<poolptr do begin printchar(strpool[j]);incr(j);end;end;
{:70}{71:}procedure terminput;var k:0..bufsize;begin fflush(stdout);
if not inputln(stdin,true)then fatalerror(263);termoffset:=0;
decr(selector);k:=first;while k<last do begin printbuffer(k)end;println;
incr(selector);end;{:71}{91:}procedure interror(n:integer);
begin print(286);printint(n);printchar(41);error;end;
{:91}{92:}procedure normalizeselector;
begin if logopened then selector:=19 else selector:=17;
if jobname=0 then openlogfile;if interaction=0 then decr(selector);end;
{:92}{98:}procedure pauseforinstructions;
begin if OKtointerrupt then begin interaction:=3;
if(selector=18)or(selector=16)then incr(selector);
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(296);
end;begin helpptr:=3;helpline[2]:=297;helpline[1]:=298;helpline[0]:=299;
end;deletionsallowed:=false;error;deletionsallowed:=true;interrupt:=0;
end;end;{:98}{100:}function half(x:integer):integer;
begin if odd(x)then half:=(x+1)div 2 else half:=x div 2;end;
{:100}{102:}function rounddecimals(k:smallnumber):scaled;var a:integer;
begin a:=0;while k>0 do begin decr(k);a:=(a+dig[k]*131072)div 10;end;
rounddecimals:=(a+1)div 2;end;
{:102}{103:}procedure printscaled(s:scaled);var delta:scaled;
begin if s<0 then begin printchar(45);s:=-s;end;printint(s div 65536);
printchar(46);s:=10*(s mod 65536)+5;delta:=10;
repeat if delta>65536 then s:=s-17232;printchar(48+(s div 65536));
s:=10*(s mod 65536);delta:=delta*10;until s<=delta;end;
{:103}{105:}function multandadd(n:integer;x,y,maxanswer:scaled):scaled;
begin if n<0 then begin x:=-x;n:=-n;end;
if n=0 then multandadd:=y else if((x<=(maxanswer-y)div n)and(-x<=(
maxanswer+y)div n))then multandadd:=n*x+y else begin aritherror:=true;
multandadd:=0;end;end;{:105}{106:}function xovern(x:scaled;
n:integer):scaled;var negative:boolean;begin negative:=false;
if n=0 then begin aritherror:=true;xovern:=0;texremainder:=x;
end else begin if n<0 then begin x:=-x;n:=-n;negative:=true;end;
if x>=0 then begin xovern:=x div n;texremainder:=x mod n;
end else begin xovern:=-((-x)div n);texremainder:=-((-x)mod n);end;end;
if negative then texremainder:=-texremainder;end;
{:106}{107:}function xnoverd(x:scaled;n,d:integer):scaled;
var positive:boolean;t,u,v:nonnegativeinteger;
begin if x>=0 then positive:=true else begin x:=-x;positive:=false;end;
t:=(x mod 32768)*n;u:=(x div 32768)*n+(t div 32768);
v:=(u mod d)*32768+(t mod 32768);
if u div d>=32768 then aritherror:=true else u:=32768*(u div d)+(v div d
);if positive then begin xnoverd:=u;texremainder:=v mod d;
end else begin xnoverd:=-u;texremainder:=-(v mod d);end;end;
{:107}{108:}function badness(t,s:scaled):halfword;var r:integer;
begin if t=0 then badness:=0 else if s<=0 then badness:=10000 else begin
if t<=7230584 then r:=(t*297)div s else if s>=1663497 then r:=t div(s
div 297)else r:=t;
if r>1290 then badness:=10000 else badness:=(r*r*r+131072)div 262144;
end;end;{:108}{112:}function makefrac(p,q:integer):integer;
var f:integer;n:integer;negative:boolean;becareful:integer;
begin if p>=0 then negative:=false else begin p:=-p;negative:=true;end;
if q<=0 then begin ifdef('TEXMF_DEBUG')if q=0 then confusion(47);
endif('TEXMF_DEBUG')q:=-q;negative:=not negative;end;n:=p div q;
p:=p mod q;if n>=8 then begin aritherror:=true;
if negative then makefrac:=-2147483647 else makefrac:=2147483647;
end else begin n:=(n-1)*268435456;{113:}f:=1;repeat becareful:=p-q;
p:=becareful+p;if p>=0 then f:=f+f+1 else begin f:=f+f;p:=p+q;end;
until f>=268435456;becareful:=p-q;if becareful+p>=0 then incr(f){:113};
if negative then makefrac:=-(f+n)else makefrac:=f+n;end;end;
{:112}{114:}function takefrac(q:integer;f:integer):integer;
var p:integer;negative:boolean;n:integer;becareful:integer;
begin{115:}if f>=0 then negative:=false else begin f:=-f;negative:=true;
end;if q<0 then begin q:=-q;negative:=not negative;end;{:115};
if f<268435456 then n:=0 else begin n:=f div 268435456;
f:=f mod 268435456;
if q<=2147483647 div n then n:=n*q else begin aritherror:=true;
n:=2147483647;end;end;f:=f+268435456;{116:}p:=134217728;
if q<1073741824 then repeat if odd(f)then p:=(p+q)div 2 else p:=(p)div 2
;f:=(f)div 2;
until f=1 else repeat if odd(f)then p:=p+(q-p)div 2 else p:=(p)div 2;
f:=(f)div 2;until f=1{:116};becareful:=n-2147483647;
if becareful+p>0 then begin aritherror:=true;n:=2147483647-p;end;
if negative then takefrac:=-(n+p)else takefrac:=n+p;end;
{:114}{119:}function mlog(x:integer):integer;var y,z:integer;k:integer;
begin if x<=0 then{121:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(300);
end;printscaled(x);print(301);begin helpptr:=2;helpline[1]:=302;
helpline[0]:=303;end;error;mlog:=0;end{:121}else begin y:=1302456860;
z:=6581195;while x<1073741824 do begin x:=x+x;y:=y-93032639;z:=z-48782;
end;y:=y+(z div 65536);k:=2;
while x>1073741828 do{120:}begin z:=((x-1)div twotothe[k])+1;
while x<1073741824+z do begin z:=(z+1)div 2;k:=k+1;end;y:=y+speclog[k];
x:=x-z;end{:120};mlog:=y div 8;end;end;
{:119}{122:}function abvscd(a,b,c,d:integer):integer;label 10;
var q,r:integer;begin{123:}if a<0 then begin a:=-a;b:=-b;end;
if c<0 then begin c:=-c;d:=-d;end;
if d<=0 then begin if b>=0 then if((a=0)or(b=0))and((c=0)or(d=0))then
begin abvscd:=0;goto 10;end else begin abvscd:=1;goto 10;end;
if d=0 then if a=0 then begin abvscd:=0;goto 10;
end else begin abvscd:=-1;goto 10;end;q:=a;a:=c;c:=q;q:=-b;b:=-d;d:=q;
end else if b<=0 then begin if b<0 then if a>0 then begin abvscd:=-1;
goto 10;end;if c=0 then begin abvscd:=0;goto 10;
end else begin abvscd:=-1;goto 10;end;end{:123};
while true do begin q:=a div d;r:=c div b;
if q<>r then if q>r then begin abvscd:=1;goto 10;
end else begin abvscd:=-1;goto 10;end;q:=a mod d;r:=c mod b;
if r=0 then if q=0 then begin abvscd:=0;goto 10;
end else begin abvscd:=1;goto 10;end;if q=0 then begin abvscd:=-1;
goto 10;end;a:=b;b:=q;c:=d;d:=r;end;10:end;
{:122}{124:}procedure newrandoms;var k:0..54;x:integer;
begin for k:=0 to 23 do begin x:=randoms[k]-randoms[k+31];
if x<0 then x:=x+268435456;randoms[k]:=x;end;
for k:=24 to 54 do begin x:=randoms[k]-randoms[k-24];
if x<0 then x:=x+268435456;randoms[k]:=x;end;jrandom:=54;end;
{:124}{125:}procedure initrandoms(seed:integer);var j,jj,k:integer;
i:0..54;begin j:=abs(seed);while j>=268435456 do j:=(j)div 2;k:=1;
for i:=0 to 54 do begin jj:=k;k:=j-k;j:=jj;if k<0 then k:=k+268435456;
randoms[(i*21)mod 55]:=j;end;newrandoms;newrandoms;newrandoms;end;
{:125}{126:}function unifrand(x:integer):integer;var y:integer;
begin if jrandom=0 then newrandoms else decr(jrandom);
y:=takefrac(abs(x),randoms[jrandom]);
if y=abs(x)then unifrand:=0 else if x>0 then unifrand:=y else unifrand:=
-y;end;{:126}{127:}function normrand:integer;var x,u,l:integer;
begin repeat repeat if jrandom=0 then newrandoms else decr(jrandom);
x:=takefrac(112429,randoms[jrandom]-134217728);
if jrandom=0 then newrandoms else decr(jrandom);u:=randoms[jrandom];
until abs(x)<u;x:=makefrac(x,u);l:=139548960-mlog(u);
until abvscd(1024,l,x,x)>=0;normrand:=x;end;
{:127}{132:}ifdef('TEXMF_DEBUG')procedure printword(w:memoryword);
begin printint(w.int);printchar(32);printscaled(w.int);printchar(32);
printscaled(round(65536*w.gr));println;printint(w.hh.lh);printchar(61);
printint(w.hh.b0);printchar(58);printint(w.hh.b1);printchar(59);
printint(w.hh.rh);printchar(32);printint(w.qqqq.b0);printchar(58);
printint(w.qqqq.b1);printchar(58);printint(w.qqqq.b2);printchar(58);
printint(w.qqqq.b3);end;
endif('TEXMF_DEBUG'){:132}{137:}{314:}procedure showtokenlist(p,q:
integer;l:integer);label 10;var m,c:integer;matchchr:ASCIIcode;
n:ASCIIcode;begin matchchr:=35;n:=48;tally:=0;
while(p<>-268435455)and(tally<l)do begin if p=q then{342:}begin
firstcount:=tally;trickcount:=tally+1+errorline-halferrorline;
if trickcount<errorline then trickcount:=errorline;end{:342};
{315:}if(p<himemmin)or(p>memend)then begin printesc(314);goto 10;end;
if mem[p].hh.lh>=4095 then printcs(mem[p].hh.lh-4095)else begin m:=mem[p
].hh.lh div 256;c:=mem[p].hh.lh mod 256;
if mem[p].hh.lh<0 then printesc(636)else{316:}case m of 1,2,3,4,7,8,10,
11,12:print(c);6:begin print(c);print(c);end;5:begin print(matchchr);
if c<=9 then printchar(c+48)else begin printchar(33);goto 10;end;end;
13:begin matchchr:=c;print(c);incr(n);printchar(n);if n>57 then goto 10;
end;14:if c=0 then print(637);others:printesc(636)end{:316};end{:315};
p:=mem[p].hh.rh;end;if p<>-268435455 then printesc(428);10:end;
{:314}{328:}procedure runaway;var p:halfword;
begin if scannerstatus>1 then begin case scannerstatus of 2:begin
printnl(651);p:=defref;end;3:begin printnl(652);p:=memtop-3;end;
4:begin printnl(653);p:=memtop-4;end;5:begin printnl(654);p:=defref;end;
end;printchar(63);println;
showtokenlist(mem[p].hh.rh,-268435455,errorline-10);end;end;
{:328}{:137}{138:}function getavail:halfword;var p:halfword;
begin p:=avail;
if p<>-268435455 then avail:=mem[avail].hh.rh else if memend<memmax then
begin incr(memend);p:=memend;end else begin decr(himemmin);p:=himemmin;
if himemmin<=lomemmax then begin runaway;overflow(304,memmax+1-memmin);
end;end;mem[p].hh.rh:=-268435455;ifdef('STAT')incr(dynused);
endif('STAT')getavail:=p;end;
{:138}{141:}procedure flushlist(p:halfword);var q,r:halfword;
begin if p<>-268435455 then begin r:=p;repeat q:=r;r:=mem[r].hh.rh;
ifdef('STAT')decr(dynused);endif('STAT')until r=-268435455;
mem[q].hh.rh:=avail;avail:=p;end;end;
{:141}{143:}function getnode(s:integer):halfword;label 40,10,20;
var p:halfword;q:halfword;r:integer;t:integer;begin 20:p:=rover;
repeat{145:}q:=p+mem[p].hh.lh;
while(mem[q].hh.rh=268435455)do begin t:=mem[q+1].hh.rh;
if q=rover then rover:=t;mem[t+1].hh.lh:=mem[q+1].hh.lh;
mem[mem[q+1].hh.lh+1].hh.rh:=t;q:=q+mem[q].hh.lh;end;r:=q-s;
if r>p+1 then{146:}begin mem[p].hh.lh:=r-p;rover:=p;goto 40;end{:146};
if r=p then if mem[p+1].hh.rh<>p then{147:}begin rover:=mem[p+1].hh.rh;
t:=mem[p+1].hh.lh;mem[rover+1].hh.lh:=t;mem[t+1].hh.rh:=rover;goto 40;
end{:147};mem[p].hh.lh:=q-p{:145};p:=mem[p+1].hh.rh;until p=rover;
if s=1073741824 then begin getnode:=268435455;goto 10;end;
if lomemmax+2<himemmin then if lomemmax+2<=membot+268435455 then{144:}
begin if himemmin-lomemmax>=1998 then t:=lomemmax+1000 else t:=lomemmax
+1+(himemmin-lomemmax)div 2;p:=mem[rover+1].hh.lh;q:=lomemmax;
mem[p+1].hh.rh:=q;mem[rover+1].hh.lh:=q;
if t>membot+268435455 then t:=membot+268435455;mem[q+1].hh.rh:=rover;
mem[q+1].hh.lh:=p;mem[q].hh.rh:=268435455;mem[q].hh.lh:=t-lomemmax;
lomemmax:=t;mem[lomemmax].hh.rh:=-268435455;
mem[lomemmax].hh.lh:=-268435455;rover:=q;goto 20;end{:144};
overflow(304,memmax+1-memmin);40:mem[r].hh.rh:=-268435455;
ifdef('STAT')varused:=varused+s;
endif('STAT'){1909:}if s>=4 then begin mem[r+s-2].int:=curinput.
synctextagfield;mem[r+s-1].int:=line;end;{:1909};getnode:=r;10:end;
{:143}{148:}procedure freenode(p:halfword;s:halfword);var q:halfword;
begin mem[p].hh.lh:=s;mem[p].hh.rh:=268435455;q:=mem[rover+1].hh.lh;
mem[p+1].hh.lh:=q;mem[p+1].hh.rh:=rover;mem[rover+1].hh.lh:=p;
mem[q+1].hh.rh:=p;ifdef('STAT')varused:=varused-s;endif('STAT')end;
{:148}{149:}ifdef('INITEX')procedure sortavail;var p,q,r:halfword;
oldrover:halfword;begin p:=getnode(1073741824);p:=mem[rover+1].hh.rh;
mem[rover+1].hh.rh:=268435455;oldrover:=rover;
while p<>oldrover do{150:}if p<rover then begin q:=p;p:=mem[q+1].hh.rh;
mem[q+1].hh.rh:=rover;rover:=q;end else begin q:=rover;
while mem[q+1].hh.rh<p do q:=mem[q+1].hh.rh;r:=mem[p+1].hh.rh;
mem[p+1].hh.rh:=mem[q+1].hh.rh;mem[q+1].hh.rh:=p;p:=r;end{:150};
p:=rover;
while mem[p+1].hh.rh<>268435455 do begin mem[mem[p+1].hh.rh+1].hh.lh:=p;
p:=mem[p+1].hh.rh;end;mem[p+1].hh.rh:=rover;mem[rover+1].hh.lh:=p;end;
endif('INITEX'){:149}{154:}function newnullbox:halfword;var p:halfword;
begin p:=getnode(9);mem[p].hh.b0:=0;mem[p].hh.b1:=0;mem[p+1].int:=0;
mem[p+2].int:=0;mem[p+3].int:=0;mem[p+4].int:=0;
mem[p+5].hh.rh:=-268435455;mem[p+5].hh.b0:=0;mem[p+5].hh.b1:=0;
mem[p+6].gr:=0.0;newnullbox:=p;end;
{:154}{157:}function newrule:halfword;var p:halfword;
begin p:=getnode(6);mem[p].hh.b0:=2;mem[p].hh.b1:=0;
mem[p+1].int:=-1073741824;mem[p+2].int:=-1073741824;
mem[p+3].int:=-1073741824;newrule:=p;end;
{:157}{162:}function newligature(f:internalfontnumber;c:quarterword;
q:halfword):halfword;var p:halfword;begin p:=getnode(2);mem[p].hh.b0:=6;
mem[p+1].hh.b0:=f;mem[p+1].hh.b1:=c;mem[p+1].hh.rh:=q;mem[p].hh.b1:=0;
newligature:=p;end;function newligitem(c:quarterword):halfword;
var p:halfword;begin p:=getnode(2);mem[p].hh.b1:=c;
mem[p+1].hh.rh:=-268435455;newligitem:=p;end;
{:162}{163:}function newdisc:halfword;var p:halfword;
begin p:=getnode(2);mem[p].hh.b0:=7;mem[p].hh.b1:=0;
mem[p+1].hh.lh:=-268435455;mem[p+1].hh.rh:=-268435455;newdisc:=p;end;
{:163}{165:}function newmath(w:scaled;s:smallnumber):halfword;
var p:halfword;begin p:=getnode(4);mem[p].hh.b0:=9;mem[p].hh.b1:=s;
mem[p+1].int:=w;newmath:=p;end;
{:165}{169:}function newspec(p:halfword):halfword;var q:halfword;
begin q:=getnode(4);mem[q]:=mem[p];mem[q].hh.rh:=-268435455;
mem[q+1].int:=mem[p+1].int;mem[q+2].int:=mem[p+2].int;
mem[q+3].int:=mem[p+3].int;newspec:=q;end;
{:169}{170:}function newparamglue(n:smallnumber):halfword;
var p:halfword;q:halfword;begin p:=getnode(4);mem[p].hh.b0:=10;
mem[p].hh.b1:=n+1;mem[p+1].hh.rh:=-268435455;
q:={242:}eqtb[24528+n].hh.rh{:242};mem[p+1].hh.lh:=q;incr(mem[q].hh.rh);
newparamglue:=p;end;{:170}{171:}function newglue(q:halfword):halfword;
var p:halfword;begin p:=getnode(4);mem[p].hh.b0:=10;mem[p].hh.b1:=0;
mem[p+1].hh.rh:=-268435455;mem[p+1].hh.lh:=q;incr(mem[q].hh.rh);
newglue:=p;end;
{:171}{172:}function newskipparam(n:smallnumber):halfword;
var p:halfword;begin tempptr:=newspec({242:}eqtb[24528+n].hh.rh{:242});
p:=newglue(tempptr);mem[tempptr].hh.rh:=-268435455;mem[p].hh.b1:=n+1;
newskipparam:=p;end;{:172}{174:}function newkern(w:scaled):halfword;
var p:halfword;begin p:=getnode(4);mem[p].hh.b0:=11;mem[p].hh.b1:=0;
mem[p+1].int:=w;newkern:=p;end;
{:174}{176:}function newpenalty(m:integer):halfword;var p:halfword;
begin p:=getnode(4);mem[p].hh.b0:=12;mem[p].hh.b1:=0;mem[p+1].int:=m;
newpenalty:=p;end;
{:176}{185:}ifdef('TEXMF_DEBUG')procedure checkmem(printlocs:boolean);
label 31,32;var p,q:halfword;clobbered:boolean;
begin for p:=memmin to lomemmax do freearr[p]:=false;
for p:=himemmin to memend do freearr[p]:=false;{186:}p:=avail;
q:=-268435455;clobbered:=false;
while p<>-268435455 do begin if(p>memend)or(p<himemmin)then clobbered:=
true else if freearr[p]then clobbered:=true;
if clobbered then begin printnl(305);printint(q);goto 31;end;
freearr[p]:=true;q:=p;p:=mem[q].hh.rh;end;31:{:186};{187:}p:=rover;
q:=-268435455;clobbered:=false;
repeat if(p>=lomemmax)or(p<memmin)then clobbered:=true else if(mem[p+1].
hh.rh>=lomemmax)or(mem[p+1].hh.rh<memmin)then clobbered:=true else if
not((mem[p].hh.rh=268435455))or(mem[p].hh.lh<2)or(p+mem[p].hh.lh>
lomemmax)or(mem[mem[p+1].hh.rh+1].hh.lh<>p)then clobbered:=true;
if clobbered then begin printnl(306);printint(q);goto 32;end;
for q:=p to p+mem[p].hh.lh-1 do begin if freearr[q]then begin printnl(
307);printint(q);goto 32;end;freearr[q]:=true;end;q:=p;
p:=mem[p+1].hh.rh;until p=rover;32:{:187};{188:}p:=memmin;
while p<=lomemmax do begin if(mem[p].hh.rh=268435455)then begin printnl(
308);printint(p);end;while(p<=lomemmax)and not freearr[p]do incr(p);
while(p<=lomemmax)and freearr[p]do incr(p);end{:188};
if printlocs then{189:}begin printnl(309);
for p:=memmin to lomemmax do if not freearr[p]and((p>waslomax)or wasfree
[p])then begin printchar(32);printint(p);end;
for p:=himemmin to memend do if not freearr[p]and((p<washimin)or(p>
wasmemend)or wasfree[p])then begin printchar(32);printint(p);end;
end{:189};for p:=memmin to lomemmax do wasfree[p]:=freearr[p];
for p:=himemmin to memend do wasfree[p]:=freearr[p];wasmemend:=memend;
waslomax:=lomemmax;washimin:=himemmin;end;
endif('TEXMF_DEBUG'){:185}{190:}ifdef('TEXMF_DEBUG')procedure searchmem(
p:halfword);var q:integer;
begin for q:=memmin to lomemmax do begin if mem[q].hh.rh=p then begin
printnl(310);printint(q);printchar(41);end;
if mem[q].hh.lh=p then begin printnl(311);printint(q);printchar(41);end;
end;
for q:=himemmin to memend do begin if mem[q].hh.rh=p then begin printnl(
310);printint(q);printchar(41);end;
if mem[q].hh.lh=p then begin printnl(311);printint(q);printchar(41);end;
end;
{273:}for q:=1 to 25588 do begin if eqtb[q].hh.rh=p then begin printnl(
573);printint(q);printchar(41);end;end{:273};
{307:}if saveptr>0 then for q:=0 to saveptr-1 do begin if savestack[q].
hh.rh=p then begin printnl(628);printint(q);printchar(41);end;end{:307};
{1111:}for q:=0 to hyphsize do begin if hyphlist[q]=p then begin printnl
(1343);printint(q);printchar(41);end;end{:1111};end;
endif('TEXMF_DEBUG'){689:}procedure pdferror(t,p:strnumber);
begin normalizeselector;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1021);
end;if t<>0 then begin print(286);print(t);print(41);end;print(649);
print(p);begin if interaction=3 then interaction:=2;
if logopened then error;
ifdef('TEXMF_DEBUG')if interaction>0 then debughelp;
endif('TEXMF_DEBUG')history:=3;jumpout;end;end;
procedure pdfwarning(t,p:strnumber;prependnl,appendnl:boolean);
begin if interaction=3 then;if prependnl then println;print(1022);
if t<>0 then begin print(286);print(t);print(41);end;print(649);
print(p);if appendnl then println;if history=0 then history:=1;end;
procedure pdfosgetosbuf(s:integer);var a:integer;
begin if s>suppdfosbufsize-pdfptr then overflow(1023,pdfosbufsize);
if pdfptr+s>pdfosbufsize then begin a:=0.2*pdfosbufsize;
if pdfptr+s>pdfosbufsize+a then pdfosbufsize:=pdfptr+s else if
pdfosbufsize<suppdfosbufsize-a then pdfosbufsize:=pdfosbufsize+a else
pdfosbufsize:=suppdfosbufsize;
pdfosbuf:=xreallocarray(pdfosbuf,eightbits,pdfosbufsize);
pdfbuf:=pdfosbuf;pdfbufsize:=pdfosbufsize;end;end;
procedure removelastspace;
begin if(pdfptr>0)and(pdfbuf[pdfptr-1]=32)then decr(pdfptr);end;
procedure pdfprintoctal(n:integer);var k:0..23;begin k:=0;
repeat dig[k]:=n mod 8;n:=n div 8;incr(k);until n=0;
if k=1 then begin begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=48;incr(pdfptr);end;end;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=48;incr(pdfptr);end;end;end;
if k=2 then begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=48;incr(pdfptr);end;end;
while k>0 do begin decr(k);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=48+dig[k];incr(pdfptr);end;end;end;end;
procedure pdfprintchar(f:internalfontnumber;c:integer);
begin pdfmarkchar(f,c);
if(c<=32)or(c=92)or(c=40)or(c=41)or(c>127)then begin begin begin if
pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)else if not
pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)else if not
pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=92;incr(pdfptr);end;end;pdfprintoctal(c);
end else begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=c;incr(pdfptr);end;end;end;
procedure pdfprint(s:strnumber);var j:poolpointer;c:integer;
begin j:=strstart[s];while j<strstart[s+1]do begin c:=strpool[j];
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=c;incr(pdfptr);end;end;incr(j);end;end;
function strinstr(s,r:strnumber;i:integer):boolean;label 45;
var j,k:poolpointer;begin strinstr:=false;
if(strstart[s+1]-strstart[s])<i+(strstart[r+1]-strstart[r])then goto 10;
j:=i+strstart[s];k:=strstart[r];
while(j<strstart[s+1])and(k<strstart[r+1])do begin if strpool[j]<>
strpool[k]then goto 10;incr(j);incr(k);end;strinstr:=true;end;
procedure pdfprintint(n:longinteger);var k:integer;m:longinteger;
begin k:=0;
if n<0 then begin begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=45;incr(pdfptr);end;end;
if n>-100000000 then n:=-n else begin m:=-1-n;n:=m div 10;
m:=(m mod 10)+1;k:=1;if m<10 then dig[0]:=m else begin dig[0]:=0;
incr(n);end;end;end;repeat dig[k]:=n mod 10;n:=n div 10;incr(k);
until n=0;
begin if pdfosmode and(k+pdfptr>pdfbufsize)then pdfosgetosbuf(k)else if
not pdfosmode and(k>pdfbufsize)then overflow(1004,pdfopbufsize)else if
not pdfosmode and(k+pdfptr>pdfbufsize)then pdfflush;end;
while k>0 do begin decr(k);begin pdfbuf[pdfptr]:=48+dig[k];incr(pdfptr);
end;end;end;procedure pdfprinttwo(n:integer);begin n:=abs(n)mod 100;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=48+(n div 10);incr(pdfptr);end;end;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=48+(n mod 10);incr(pdfptr);end;end;end;
function tokenstostring(p:halfword):strnumber;
begin if selector=21 then pdferror(1024,1025);oldsetting:=selector;
selector:=21;showtokenlist(mem[p].hh.rh,-268435455,poolsize-poolptr);
selector:=oldsetting;lasttokensstring:=makestring;
tokenstostring:=lasttokensstring;end;
{:689}{692:}function dividescaled(s,m:scaled;dd:integer):scaled;
var q,r:scaled;sign,i:integer;begin sign:=1;
if s<0 then begin sign:=-sign;s:=-s;end;if m<0 then begin sign:=-sign;
m:=-m;end;
if m=0 then pdferror(1026,1027)else if m>=(2147483647 div 10)then
pdferror(1026,1028);q:=s div m;r:=s mod m;
for i:=1 to dd do begin q:=10*q+(10*r)div m;r:=(10*r)mod m;end;
if 2*r>=m then begin incr(q);r:=r-m;end;
scaledout:=sign*(s-(r div tenpow[dd]));dividescaled:=sign*q;end;
function roundxnoverd(x:scaled;n,d:integer):scaled;var positive:boolean;
t,u,v:nonnegativeinteger;
begin if x>=0 then positive:=true else begin x:=-x;positive:=false;end;
t:=(x mod 32768)*n;u:=(x div 32768)*n+(t div 32768);
v:=(u mod d)*32768+(t mod 32768);
if u div d>=32768 then aritherror:=true else u:=32768*(u div d)+(v div d
);v:=v mod d;if 2*v>=d then incr(u);
if positive then roundxnoverd:=u else roundxnoverd:=-u;end;
{:692}{701:}procedure appenddestname(s:strnumber;n:integer);
var a:integer;
begin if pdfdestnamesptr=supdestnamessize then overflow(1061,
destnamessize);
if pdfdestnamesptr=destnamessize then begin a:=0.2*destnamessize;
if destnamessize<supdestnamessize-a then destnamessize:=destnamessize+a
else destnamessize:=supdestnamessize;
destnames:=xreallocarray(destnames,destnameentry,destnamessize);end;
destnames[pdfdestnamesptr].objname:=s;
destnames[pdfdestnamesptr].objnum:=n;incr(pdfdestnamesptr);end;
procedure pdfcreateobj(t,i:integer);label 30;var a,p,q:integer;
begin if sysobjptr=supobjtabsize then overflow(1062,objtabsize);
if sysobjptr=objtabsize then begin a:=0.2*objtabsize;
if objtabsize<supobjtabsize-a then objtabsize:=objtabsize+a else
objtabsize:=supobjtabsize;
objtab:=xreallocarray(objtab,objentry,objtabsize);end;incr(sysobjptr);
objptr:=sysobjptr;objtab[objptr].int0:=i;objtab[objptr].int2:=-2;
objtab[objptr].int4:=0;avlputobj(objptr,t);
if t=1 then begin p:=headtab[t];
if(p=0)or(objtab[p].int0<i)then begin objtab[objptr].int1:=p;
headtab[t]:=objptr;
end else begin while p<>0 do begin if objtab[p].int0<i then goto 30;
q:=p;p:=objtab[p].int1;end;30:objtab[q].int1:=objptr;
objtab[objptr].int1:=p;end;
end else if t<>0 then begin objtab[objptr].int1:=headtab[t];
headtab[t]:=objptr;
if(t=5)and(i<0)then appenddestname(-objtab[objptr].int0,objptr);end;end;
function pdfnewobjnum:integer;begin pdfcreateobj(0,0);
pdfnewobjnum:=objptr;end;procedure pdfosswitch(pdfos:boolean);
begin if pdfos and pdfosenable then begin if not pdfosmode then begin
pdfopptr:=pdfptr;pdfptr:=pdfosptr;pdfbuf:=pdfosbuf;
pdfbufsize:=pdfosbufsize;pdfosmode:=true;end;
end else begin if pdfosmode then begin pdfosptr:=pdfptr;
pdfptr:=pdfopptr;pdfbuf:=pdfopbuf;pdfbufsize:=pdfopbufsize;
pdfosmode:=false;end;end;end;procedure pdfosprepareobj(i:integer;
pdfoslevel:integer);
begin pdfosswitch((pdfoslevel>0)and(fixedpdfobjcompresslevel>=pdfoslevel
));
if pdfosmode then begin if pdfoscurobjnum=0 then begin pdfoscurobjnum:=
pdfnewobjnum;decr(objptr);incr(pdfoscntr);pdfosobjidx:=0;pdfptr:=0;
end else incr(pdfosobjidx);objtab[i].int3:=pdfosobjidx;
objtab[i].int2:=pdfoscurobjnum;pdfosobjnum[pdfosobjidx]:=i;
pdfosobjoff[pdfosobjidx]:=pdfptr;
end else begin objtab[i].int2:=(pdfgone+pdfptr);objtab[i].int3:=-1;end;
end;procedure pdfbeginobj(i:integer;pdfoslevel:integer);
begin checkpdfminorversion;pdfosprepareobj(i,pdfoslevel);
if not pdfosmode then begin pdfprintint(i);begin pdfprint(1063);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
end else if eqtb[27240].int=0 then begin pdfprint(1064);pdfprintint(i);
begin pdfprint(1063);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;end;
procedure pdfnewobj(t,i:integer;pdfos:integer);begin pdfcreateobj(t,i);
pdfbeginobj(objptr,pdfos);end;procedure pdfendobj;
begin if pdfosmode then begin if pdfosobjidx=pdfosmaxobjs-1 then
pdfoswriteobjstream;end else begin pdfprint(1065);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
procedure pdfbegindict(i:integer;pdfoslevel:integer);
begin checkpdfminorversion;pdfosprepareobj(i,pdfoslevel);
if not pdfosmode then begin pdfprintint(i);begin pdfprint(1063);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
end else if eqtb[27240].int=0 then begin pdfprint(1064);pdfprintint(i);
begin pdfprint(1063);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
begin pdfprint(1066);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
procedure pdfnewdict(t,i:integer;pdfos:integer);begin pdfcreateobj(t,i);
pdfbegindict(objptr,pdfos);end;procedure pdfenddict;
begin if pdfosmode then begin begin pdfprint(1018);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if pdfosobjidx=pdfosmaxobjs-1 then pdfoswriteobjstream;
end else begin begin pdfprint(1018);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;begin pdfprint(1065);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;end;
{:701}{702:}procedure pdfoswriteobjstream;var i,j,p,q:halfword;
begin if pdfoscurobjnum=0 then goto 10;p:=pdfptr;i:=0;j:=0;
while i<=pdfosobjidx do begin pdfprintint(pdfosobjnum[i]);pdfprint(32);
pdfprintint(pdfosobjoff[i]);
if j=9 then begin begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;j:=0;
end else begin pdfprint(32);incr(j);end;incr(i);end;
pdfbuf[pdfptr-1]:=10;q:=pdfptr;pdfbegindict(pdfoscurobjnum,0);
begin pdfprint(1067);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfprint(1068);
begin pdfprintint(pdfosobjidx+1);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfprint(1069);
begin pdfprintint(q-p);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfbeginstream;
begin if pdfosmode and(q-p+pdfptr>pdfbufsize)then pdfosgetosbuf(q-p)else
if not pdfosmode and(q-p>pdfbufsize)then overflow(1004,pdfopbufsize)else
if not pdfosmode and(q-p+pdfptr>pdfbufsize)then pdfflush;end;i:=p;
while i<q do begin begin pdfbuf[pdfptr]:=pdfosbuf[i];incr(pdfptr);end;
incr(i);end;i:=0;while i<p do begin q:=i+pdfbufsize;if q>p then q:=p;
begin if pdfosmode and(q-i+pdfptr>pdfbufsize)then pdfosgetosbuf(q-i)else
if not pdfosmode and(q-i>pdfbufsize)then overflow(1004,pdfopbufsize)else
if not pdfosmode and(q-i+pdfptr>pdfbufsize)then pdfflush;end;
while i<q do begin begin pdfbuf[pdfptr]:=pdfosbuf[i];incr(pdfptr);end;
incr(i);end;end;pdfendstream;pdfoscurobjnum:=0;end;
{:702}{703:}function appendptr(p:halfword;i:integer):halfword;
var q:halfword;begin appendptr:=p;begin q:=avail;
if q=-268435455 then q:=getavail else begin avail:=mem[q].hh.rh;
mem[q].hh.rh:=-268435455;ifdef('STAT')incr(dynused);endif('STAT')end;
end;mem[q].hh.lh:=i;mem[q].hh.rh:=-268435455;
if p=-268435455 then begin appendptr:=q;goto 10;end;
while mem[p].hh.rh<>-268435455 do p:=mem[p].hh.rh;mem[p].hh.rh:=q;end;
function pdflookuplist(p:halfword;i:integer):halfword;
begin pdflookuplist:=-268435455;
while p<>-268435455 do begin if mem[p].hh.lh=i then begin pdflookuplist
:=p;goto 10;end;p:=mem[p].hh.rh;end;end;
{:703}{706:}procedure pdfcheckvfcurval;forward;
procedure pdfinitfontcurval;forward;procedure scanpdfexttoks;forward;
{:706}{1546:}function prevrightmost(s,e:halfword):halfword;
var p:halfword;begin prevrightmost:=-268435455;p:=s;
if p=-268435455 then goto 10;
while mem[p].hh.rh<>e do begin p:=mem[p].hh.rh;
if p=-268435455 then goto 10;end;prevrightmost:=p;end;
procedure pdfcheckobj(t,n:integer);var k:integer;begin k:=headtab[t];
while(k<>0)and(k<>n)do k:=objtab[k].int1;
if k=0 then pdferror(1766,1792);end;
{:1546}{1556:}function findobj(t,i:integer;byname:boolean):integer;
begin findobj:=avlfindobj(t,i,byname);end;
procedure flushstr(s:strnumber);
begin if(s=strptr-1)then begin decr(strptr);poolptr:=strstart[strptr];
end;end;function getobj(t,i:integer;byname:boolean):integer;
var r:integer;s:strnumber;
begin if byname>0 then begin s:=tokenstostring(i);r:=findobj(t,s,true);
end else begin s:=0;r:=findobj(t,i,false);end;
if r=0 then begin if byname>0 then begin pdfcreateobj(t,-s);s:=0;
end else pdfcreateobj(t,i);r:=objptr;
if t=5 then objtab[r].int4:=-268435455;end;if s<>0 then flushstr(s);
getobj:=r;end;function getmicrointerval:integer;var s,m:integer;
begin secondsandmicros(s,m);
if(s-epochseconds)>32767 then getmicrointerval:=2147483647 else if(
microseconds>m)then getmicrointerval:=((s-1-epochseconds)*65536)+(((m
+1000000-microseconds)/100)*65536)/10000 else getmicrointerval:=((s-
epochseconds)*65536)+(((m-microseconds)/100)*65536)/10000;end;
{:1556}{:190}{192:}procedure printfontidentifier(f:internalfontnumber);
begin if pdffontblink[f]=0 then printesc(hash[15526+f].rh)else printesc(
hash[15526+pdffontblink[f]].rh);
if eqtb[27258].int>0 then begin print(286);print(fontname[f]);
if fontsize[f]<>fontdsize[f]then begin print(64);
printscaled(fontsize[f]);print(312);end;print(41);
end else if pdffontexpandratio[f]<>0 then begin print(286);
if pdffontexpandratio[f]>0 then print(43);
printint(pdffontexpandratio[f]);print(41);end;end;
procedure shortdisplay(p:integer);var n:integer;
begin while p>memmin do begin if(p>=himemmin)then begin if p<=memend
then begin if mem[p].hh.b0<>fontinshortdisplay then begin if(mem[p].hh.
b0>fontmax)then printchar(42)else printfontidentifier(mem[p].hh.b0);
printchar(32);fontinshortdisplay:=mem[p].hh.b0;end;print(mem[p].hh.b1);
end;end else{193:}case mem[p].hh.b0 of 0,1,3,8,4,5,13:print(313);
2:printchar(124);10:if mem[p+1].hh.lh<>membot then printchar(32);
9:if mem[p].hh.b1>=4 then print(313)else printchar(36);
6:shortdisplay(mem[p+1].hh.rh);7:begin shortdisplay(mem[p+1].hh.lh);
shortdisplay(mem[p+1].hh.rh);n:=mem[p].hh.b1;
while n>0 do begin if mem[p].hh.rh<>-268435455 then p:=mem[p].hh.rh;
decr(n);end;end;others:end{:193};p:=mem[p].hh.rh;end;end;
{:192}{194:}procedure printfontandchar(p:integer);
begin if p>memend then printesc(314)else begin if(mem[p].hh.b0>fontmax)
then printchar(42)else printfontidentifier(mem[p].hh.b0);printchar(32);
print(mem[p].hh.b1);end;end;procedure printmark(p:integer);
begin printchar(123);
if(p<himemmin)or(p>memend)then printesc(314)else showtokenlist(mem[p].hh
.rh,-268435455,maxprintline-10);printchar(125);end;
procedure printruledimen(d:scaled);
begin if(d=-1073741824)then printchar(42)else printscaled(d);end;
{:194}{195:}procedure printglue(d:scaled;order:integer;s:strnumber);
begin printscaled(d);
if(order<0)or(order>3)then print(315)else if order>0 then begin print(
316);while order>1 do begin printchar(108);decr(order);end;
end else if s<>0 then print(s);end;
{:195}{196:}procedure printspec(p:integer;s:strnumber);
begin if(p<memmin)or(p>=lomemmax)then printchar(42)else begin
printscaled(mem[p+1].int);if s<>0 then print(s);
if mem[p+2].int<>0 then begin print(317);
printglue(mem[p+2].int,mem[p].hh.b0,s);end;
if mem[p+3].int<>0 then begin print(318);
printglue(mem[p+3].int,mem[p].hh.b1,s);end;end;end;
{:196}{197:}{868:}procedure printfamandchar(p:halfword);
begin printesc(484);printint(mem[p].hh.b0);printchar(32);
print(mem[p].hh.b1);end;procedure printdelimiter(p:halfword);
var a:integer;begin a:=mem[p].qqqq.b0*256+mem[p].qqqq.b1;
a:=a*4096+mem[p].qqqq.b2*256+mem[p].qqqq.b3;
if a<0 then printint(a)else printhex(a);end;
{:868}{869:}procedure showinfo;forward;
procedure printsubsidiarydata(p:halfword;c:ASCIIcode);
begin if(poolptr-strstart[strptr])>=depththreshold then begin if mem[p].
hh.rh<>0 then print(319);end else begin begin strpool[poolptr]:=c;
incr(poolptr);end;tempptr:=p;case mem[p].hh.rh of 1:begin println;
printcurrentstring;printfamandchar(p);end;2:showinfo;
3:if mem[p].hh.lh=-268435455 then begin println;printcurrentstring;
print(1258);end else showinfo;others:end;decr(poolptr);end;end;
{:869}{871:}procedure printstyle(c:integer);
begin case c div 2 of 0:printesc(1259);1:printesc(1260);
2:printesc(1261);3:printesc(1262);others:print(1263)end;end;
{:871}{243:}procedure printskipparam(n:integer);
begin case n of 0:printesc(393);1:printesc(394);2:printesc(395);
3:printesc(396);4:printesc(397);5:printesc(398);6:printesc(399);
7:printesc(400);8:printesc(401);9:printesc(402);10:printesc(403);
11:printesc(404);12:printesc(405);13:printesc(406);14:printesc(407);
15:printesc(408);16:printesc(409);17:printesc(410);others:print(411)end;
end;{:243}{:197}{200:}procedure shownodelist(p:integer);label 10;
var n:integer;g:real;
begin if(poolptr-strstart[strptr])>depththreshold then begin if p>
-268435455 then print(319);goto 10;end;n:=0;
while p>memmin do begin println;printcurrentstring;
if p>memend then begin print(320);goto 10;end;incr(n);
if n>breadthmax then begin print(321);goto 10;end;
{201:}if(p>=himemmin)then printfontandchar(p)else case mem[p].hh.b0 of 0
,1,13:{202:}begin if mem[p].hh.b0=0 then printesc(104)else if mem[p].hh.
b0=1 then printesc(118)else printesc(326);print(327);
printscaled(mem[p+3].int);printchar(43);printscaled(mem[p+2].int);
print(328);printscaled(mem[p+1].int);
if mem[p].hh.b0=13 then{203:}begin if mem[p].hh.b1<>0 then begin print(
286);printint(mem[p].hh.b1+1);print(330);end;
if mem[p+6].int<>0 then begin print(331);
printglue(mem[p+6].int,mem[p+5].hh.b1,0);end;
if mem[p+4].int<>0 then begin print(332);
printglue(mem[p+4].int,mem[p+5].hh.b0,0);end;
end{:203}else begin{204:}g:=mem[p+6].gr;
if(g<>0.0)and(mem[p+5].hh.b0<>0)then begin print(333);
if mem[p+5].hh.b0=2 then print(334);
if fabs(g)>20000.0 then begin if g>0.0 then printchar(62)else print(335)
;printglue(20000*65536,mem[p+5].hh.b1,0);
end else printglue(round(65536*g),mem[p+5].hh.b1,0);end{:204};
if mem[p+4].int<>0 then begin print(329);printscaled(mem[p+4].int);end;
if(eTeXmode=1)then{1702:}if(mem[p].hh.b0=0)and((mem[p].hh.b1)=2)then
print(2014){:1702};end;begin begin strpool[poolptr]:=46;incr(poolptr);
end;shownodelist(mem[p+5].hh.rh);decr(poolptr);end;end{:202};
2:{205:}begin printesc(336);printruledimen(mem[p+3].int);printchar(43);
printruledimen(mem[p+2].int);print(328);printruledimen(mem[p+1].int);
end{:205};3:{206:}begin printesc(337);printint(mem[p].hh.b1);print(338);
printscaled(mem[p+3].int);print(339);printspec(mem[p+4].hh.rh,0);
printchar(44);printscaled(mem[p+2].int);print(340);
printint(mem[p+1].int);begin begin strpool[poolptr]:=46;incr(poolptr);
end;shownodelist(mem[p+4].hh.lh);decr(poolptr);end;end{:206};
8:{1601:}case mem[p].hh.b1 of 0:begin printwritewhatsit(1721,p);
printchar(61);
printfilename(mem[p+1].hh.rh,mem[p+2].hh.lh,mem[p+2].hh.rh);end;
1:begin printwritewhatsit(676,p);printmark(mem[p+1].hh.rh);end;
2:printwritewhatsit(1722,p);3:begin printesc(1723);
if mem[p+1].hh.b0<>64 then begin printchar(60);
printint(mem[p+1].hh.b0-64);
if(mem[p+1].hh.b0-64=2)or(mem[p+1].hh.b0-64=3)then begin printchar(58);
printint(mem[p+1].hh.b1-64);end;printchar(62);end;
printmark(mem[p+1].hh.rh);end;4:begin printesc(1725);
printint(mem[p+1].hh.rh);print(1873);printint(mem[p+1].hh.b0);
printchar(44);printint(mem[p+1].hh.b1);printchar(41);end;
6:begin printesc(1726);case mem[p+1].hh.lh of 0:;1:print(999);
2:print(1874);others:confusion(1875)end;printmark(mem[p+1].hh.rh);end;
38:begin printesc(1876);printint(mem[p+1].hh.rh);
case mem[p+1].hh.lh of 0:print(1877);1:print(1878);2:print(1879);
3:print(1880);others:confusion(1126)end;
if mem[p+1].hh.lh<=1 then printmark(mem[p+2].hh.rh);end;
39:begin printesc(1727);printmark(mem[p+1].hh.rh);end;
40:begin printesc(1728);end;41:begin printesc(1729);end;
8:begin printesc(1731);
if pdfmem[objtab[mem[p+1].hh.lh].int4+1]>0 then begin if pdfmem[objtab[
mem[p+1].hh.lh].int4+2]<>-268435455 then begin print(1881);
printmark(pdfmem[objtab[mem[p+1].hh.lh].int4+2]);end;print(1882);end;
if pdfmem[objtab[mem[p+1].hh.lh].int4+3]>0 then print(1883);
printmark(pdfmem[objtab[mem[p+1].hh.lh].int4+0]);end;
10:begin printesc(1733);print(40);
printscaled(pdfmem[objtab[mem[p+4].hh.lh].int4+1]);printchar(43);
printscaled(pdfmem[objtab[mem[p+4].hh.lh].int4+2]);print(328);
printscaled(pdfmem[objtab[mem[p+4].hh.lh].int4+0]);end;
12:begin printesc(1735);print(40);
printscaled(pdfmem[objtab[mem[p+4].hh.lh].int4+1]);printchar(43);
printscaled(pdfmem[objtab[mem[p+4].hh.lh].int4+2]);print(328);
printscaled(pdfmem[objtab[mem[p+4].hh.lh].int4+0]);end;
13:begin printesc(1736);{1599:}print(40);printruledimen(mem[p+2].int);
printchar(43);printruledimen(mem[p+3].int);print(328);
printruledimen(mem[p+1].int){:1599};printmark(mem[p+5].hh.lh);end;
14:begin printesc(1737);{1599:}print(40);printruledimen(mem[p+2].int);
printchar(43);printruledimen(mem[p+3].int);print(328);
printruledimen(mem[p+1].int){:1599};
if mem[p+5].hh.lh<>-268435455 then begin print(1881);
printmark(mem[p+5].hh.lh);end;print(1884);
if mem[mem[p+5].hh.rh].hh.b0=3 then begin print(1885);
printmark(mem[mem[p+5].hh.rh+2].hh.lh);
end else begin if mem[mem[p+5].hh.rh+1].hh.lh<>-268435455 then begin
print(1883);printmark(mem[mem[p+5].hh.rh+1].hh.lh);end;
case mem[mem[p+5].hh.rh].hh.b0 of 1:begin if mem[mem[p+5].hh.rh].hh.b1>0
then begin print(1886);printmark(mem[mem[p+5].hh.rh].hh.rh);
end else begin print(1887);printint(mem[mem[p+5].hh.rh].hh.rh)end;end;
0:begin print(999);printint(mem[mem[p+5].hh.rh].hh.rh);
printmark(mem[mem[p+5].hh.rh+2].hh.lh);end;
2:begin if mem[mem[p+5].hh.rh].hh.b1>0 then begin print(1888);
printmark(mem[mem[p+5].hh.rh].hh.rh);end else begin print(1889);
printint(mem[mem[p+5].hh.rh].hh.rh);end;end;others:pdferror(1890,1891);
end;end end;15:printesc(1738);17:begin printesc(1740);
if mem[p+5].hh.b1>0 then begin print(1892);printmark(mem[p+5].hh.rh);
end else begin print(1893);printint(mem[p+5].hh.rh);end;print(32);
case mem[p+5].hh.b0 of 0:begin print(1836);
if mem[p+6].hh.lh<>-268435455 then begin print(1894);
printint(mem[p+6].hh.lh);end;end;5:print(1838);6:print(1839);
4:print(1840);2:print(1841);3:print(1842);7:begin print(1843);
{1599:}print(40);printruledimen(mem[p+2].int);printchar(43);
printruledimen(mem[p+3].int);print(328);
printruledimen(mem[p+1].int){:1599};end;1:print(1844);
others:print(1895);end;end;
18,19:begin if mem[p].hh.b1=18 then printesc(1741)else printesc(1742);
print(40);printruledimen(mem[p+2].int);printchar(43);
printruledimen(mem[p+3].int);print(328);printruledimen(mem[p+1].int);
if mem[p+6].hh.lh<>-268435455 then begin print(1881);
printmark(mem[p+6].hh.lh);end;
if mem[p+5].hh.b1>0 then begin print(1892);printmark(mem[p+5].hh.rh);
end else begin print(1893);printint(mem[p+5].hh.rh);end;end;
20:printesc(1743);21:printesc(1744);34:printesc(1745);
35:begin printesc(1746);printchar(32);printspec(mem[p+1].hh.lh,0);
printchar(32);printspec(mem[p+2].int,0);end;36:begin printesc(1747);
printchar(32);printint(mem[p+1].int);end;43:printesc(1762);
44:printesc(1763);45:printesc(1764);others:print(1896)end{:1601};
10:{207:}if mem[p].hh.b1>=100 then{208:}begin printesc(345);
if mem[p].hh.b1=101 then printchar(99)else if mem[p].hh.b1=102 then
printchar(120);print(346);printspec(mem[p+1].hh.lh,0);
begin begin strpool[poolptr]:=46;incr(poolptr);end;
shownodelist(mem[p+1].hh.rh);decr(poolptr);end;
end{:208}else begin printesc(341);
if mem[p].hh.b1<>0 then begin printchar(40);
if mem[p].hh.b1<98 then printskipparam(mem[p].hh.b1-1)else if mem[p].hh.
b1=98 then printesc(342)else printesc(343);printchar(41);end;
if mem[p].hh.b1<>98 then begin printchar(32);
if mem[p].hh.b1<98 then printspec(mem[p+1].hh.lh,0)else printspec(mem[p
+1].hh.lh,344);end;end{:207};40:begin printesc(322);
printscaled(mem[p+1].int);
if mem[p].hh.b1=0 then print(323)else print(324);end;
11:{209:}if mem[p].hh.b1<>99 then begin printesc(322);
if mem[p].hh.b1<>0 then printchar(32);printscaled(mem[p+1].int);
if mem[p].hh.b1=2 then print(347);end else begin printesc(348);
printscaled(mem[p+1].int);print(344);end{:209};
9:{210:}if mem[p].hh.b1>1 then begin if odd(mem[p].hh.b1)then printesc(
349)else printesc(350);
if mem[p].hh.b1>8 then printchar(82)else if mem[p].hh.b1>4 then
printchar(76)else printchar(77);end else begin printesc(351);
if mem[p].hh.b1=0 then print(352)else print(353);
if mem[p+1].int<>0 then begin print(354);printscaled(mem[p+1].int);end;
end{:210};6:{211:}begin printfontandchar(p+1);print(355);
if mem[p].hh.b1>1 then printchar(124);
fontinshortdisplay:=mem[p+1].hh.b0;shortdisplay(mem[p+1].hh.rh);
if odd(mem[p].hh.b1)then printchar(124);printchar(41);end{:211};
12:{212:}begin printesc(356);printint(mem[p+1].int);end{:212};
7:{213:}begin printesc(357);if mem[p].hh.b1>0 then begin print(358);
printint(mem[p].hh.b1);end;begin begin strpool[poolptr]:=46;
incr(poolptr);end;shownodelist(mem[p+1].hh.lh);decr(poolptr);end;
begin strpool[poolptr]:=124;incr(poolptr);end;
shownodelist(mem[p+1].hh.rh);decr(poolptr);end{:213};
4:{214:}begin printesc(359);
if mem[p+1].hh.lh<>0 then begin printchar(115);printint(mem[p+1].hh.lh);
end;printmark(mem[p+1].hh.rh);end{:214};5:{215:}begin printesc(360);
if mem[p].hh.b1<>0 then print(361);begin begin strpool[poolptr]:=46;
incr(poolptr);end;shownodelist(mem[p+1].int);decr(poolptr);end;
end{:215};{867:}14:printstyle(mem[p].hh.b1);
15:{872:}begin printesc(602);begin strpool[poolptr]:=68;incr(poolptr);
end;shownodelist(mem[p+1].hh.lh);decr(poolptr);
begin strpool[poolptr]:=84;incr(poolptr);end;
shownodelist(mem[p+1].hh.rh);decr(poolptr);begin strpool[poolptr]:=83;
incr(poolptr);end;shownodelist(mem[p+2].hh.lh);decr(poolptr);
begin strpool[poolptr]:=115;incr(poolptr);end;
shownodelist(mem[p+2].hh.rh);decr(poolptr);end{:872};
16,17,18,19,20,21,22,23,24,27,26,29,28,30,31:{873:}begin case mem[p].hh.
b0 of 16:printesc(1264);17:printesc(1265);18:printesc(1266);
19:printesc(1267);20:printesc(1268);21:printesc(1269);22:printesc(1270);
23:printesc(1271);27:printesc(1272);26:printesc(1273);29:printesc(617);
24:begin printesc(611);printdelimiter(p+4);end;28:begin printesc(582);
printfamandchar(p+4);end;30:begin printesc(1274);printdelimiter(p+1);
end;31:begin if mem[p].hh.b1=0 then printesc(1275)else printesc(1276);
printdelimiter(p+1);end;end;
if mem[p].hh.b0<30 then begin if mem[p].hh.b1<>0 then if mem[p].hh.b1=1
then printesc(1277)else printesc(1278);printsubsidiarydata(p+1,46);end;
printsubsidiarydata(p+2,94);printsubsidiarydata(p+3,95);end{:873};
25:{874:}begin printesc(1279);
if mem[p+1].int=1073741824 then print(1280)else printscaled(mem[p+1].int
);
if(mem[p+4].qqqq.b0<>0)or(mem[p+4].qqqq.b1<>0)or(mem[p+4].qqqq.b2<>0)or(
mem[p+4].qqqq.b3<>0)then begin print(1281);printdelimiter(p+4);end;
if(mem[p+5].qqqq.b0<>0)or(mem[p+5].qqqq.b1<>0)or(mem[p+5].qqqq.b2<>0)or(
mem[p+5].qqqq.b3<>0)then begin print(1282);printdelimiter(p+5);end;
printsubsidiarydata(p+2,92);printsubsidiarydata(p+3,47);end{:874};
{:867}others:print(325)end{:201};p:=mem[p].hh.rh;end;10:end;
{:200}{216:}procedure showbox(p:halfword);
begin{254:}depththreshold:=eqtb[27202].int;
breadthmax:=eqtb[27201].int{:254};if breadthmax<=0 then breadthmax:=5;
if poolptr+depththreshold>=poolsize then depththreshold:=poolsize-
poolptr-1;shownodelist(p);println;end;
{:216}{218:}procedure deletetokenref(p:halfword);
begin if mem[p].hh.lh=-268435455 then flushlist(p)else decr(mem[p].hh.lh
);end;{:218}{219:}procedure deleteglueref(p:halfword);
begin if mem[p].hh.rh=-268435455 then freenode(p,4)else decr(mem[p].hh.
rh);end;{:219}{220:}procedure flushnodelist(p:halfword);label 30;
var q:halfword;begin while p<>-268435455 do begin q:=mem[p].hh.rh;
if(p>=himemmin)then begin mem[p].hh.rh:=avail;avail:=p;
ifdef('STAT')decr(dynused);
endif('STAT')end else begin case mem[p].hh.b0 of 0,1,13:begin
flushnodelist(mem[p+5].hh.rh);freenode(p,9);goto 30;end;
2:begin freenode(p,6);goto 30;end;3:begin flushnodelist(mem[p+4].hh.lh);
deleteglueref(mem[p+4].hh.rh);freenode(p,5);goto 30;end;
8:{1603:}begin case mem[p].hh.b1 of 0:freenode(p,3);
1,3:begin deletetokenref(mem[p+1].hh.rh);freenode(p,2);goto 30;end;
2,4:freenode(p,2);6:begin deletetokenref(mem[p+1].hh.rh);freenode(p,2);
end;
38:begin if mem[p+1].hh.lh<=1 then begin deletetokenref(mem[p+2].hh.rh);
freenode(p,3);end else freenode(p,2);end;
39:begin deletetokenref(mem[p+1].hh.rh);freenode(p,2);end;
40:begin freenode(p,2);end;41:begin freenode(p,2);end;8:freenode(p,2);
10:freenode(p,5);12:freenode(p,5);
13:begin deletetokenref(mem[p+5].hh.lh);freenode(p,7);end;
14:begin if mem[p+5].hh.lh<>-268435455 then deletetokenref(mem[p+5].hh.
lh);
begin if mem[mem[p+5].hh.rh+2].hh.rh=-268435455 then begin if mem[mem[p
+5].hh.rh].hh.b0=3 then deletetokenref(mem[mem[p+5].hh.rh+2].hh.lh)else
begin if mem[mem[p+5].hh.rh+1].hh.lh<>-268435455 then deletetokenref(mem
[mem[p+5].hh.rh+1].hh.lh);
if mem[mem[p+5].hh.rh].hh.b0=0 then deletetokenref(mem[mem[p+5].hh.rh+2]
.hh.lh)else if mem[mem[p+5].hh.rh].hh.b1>0 then deletetokenref(mem[mem[p
+5].hh.rh].hh.rh);end;freenode(mem[p+5].hh.rh,3);
end else decr(mem[mem[p+5].hh.rh+2].hh.rh);end;freenode(p,7);end;
15:freenode(p,2);
17:begin if mem[p+5].hh.b1>0 then deletetokenref(mem[p+5].hh.rh);
freenode(p,7);end;
18,19:begin if mem[p+5].hh.b1>0 then deletetokenref(mem[p+5].hh.rh);
if mem[p+6].hh.lh<>-268435455 then deletetokenref(mem[p+6].hh.lh);
freenode(p,7);end;20:freenode(p,2);21:freenode(p,2);34:freenode(p,2);
35:begin deleteglueref(mem[p+1].hh.lh);freenode(p,3);end;
36:freenode(p,2);43:freenode(p,2);44:freenode(p,2);45:freenode(p,2);
others:confusion(1898)end;goto 30;end{:1603};
10:begin begin if mem[mem[p+1].hh.lh].hh.rh=-268435455 then freenode(mem
[p+1].hh.lh,4)else decr(mem[mem[p+1].hh.lh].hh.rh);end;
if mem[p+1].hh.rh<>-268435455 then flushnodelist(mem[p+1].hh.rh);
freenode(p,4);goto 30;end;11,9,12:begin freenode(p,4);goto 30;end;
40:begin begin mem[mem[p+2].hh.lh].hh.rh:=avail;avail:=mem[p+2].hh.lh;
ifdef('STAT')decr(dynused);endif('STAT')end;freenode(p,3);goto 30;end;
6:flushnodelist(mem[p+1].hh.rh);4:deletetokenref(mem[p+1].hh.rh);
7:begin flushnodelist(mem[p+1].hh.lh);flushnodelist(mem[p+1].hh.rh);end;
5:flushnodelist(mem[p+1].int);{875:}14:begin freenode(p,3);goto 30;end;
15:begin flushnodelist(mem[p+1].hh.lh);flushnodelist(mem[p+1].hh.rh);
flushnodelist(mem[p+2].hh.lh);flushnodelist(mem[p+2].hh.rh);
freenode(p,3);goto 30;end;
16,17,18,19,20,21,22,23,24,27,26,29,28:begin if mem[p+1].hh.rh>=2 then
flushnodelist(mem[p+1].hh.lh);
if mem[p+2].hh.rh>=2 then flushnodelist(mem[p+2].hh.lh);
if mem[p+3].hh.rh>=2 then flushnodelist(mem[p+3].hh.lh);
if mem[p].hh.b0=24 then freenode(p,5)else if mem[p].hh.b0=28 then
freenode(p,5)else freenode(p,4);goto 30;end;30,31:begin freenode(p,4);
goto 30;end;25:begin flushnodelist(mem[p+2].hh.lh);
flushnodelist(mem[p+3].hh.lh);freenode(p,6);goto 30;end;
{:875}others:confusion(362)end;freenode(p,2);30:end;p:=q;end;end;
{:220}{222:}function copynodelist(p:halfword):halfword;var h:halfword;
q:halfword;r:halfword;words:0..5;begin h:=getavail;q:=h;
while p<>-268435455 do begin{223:}words:=1;
if(p>=himemmin)then r:=getavail else{224:}case mem[p].hh.b0 of 0,1,13:
begin r:=getnode(9);{1928:}mem[r+7].int:=mem[p+7].int;
mem[r+8].int:=mem[p+8].int;{:1928};mem[r+6]:=mem[p+6];
mem[r+5]:=mem[p+5];mem[r+5].hh.rh:=copynodelist(mem[p+5].hh.rh);
words:=5;end;2:begin r:=getnode(6);words:=4;{1929:}{:1929};end;
3:begin r:=getnode(5);mem[r+4]:=mem[p+4];
incr(mem[mem[p+4].hh.rh].hh.rh);
mem[r+4].hh.lh:=copynodelist(mem[p+4].hh.lh);words:=4;end;
8:{1602:}case mem[p].hh.b1 of 0:begin r:=getnode(3);words:=3;end;
1,3:begin r:=getnode(2);incr(mem[mem[p+1].hh.rh].hh.lh);words:=2;end;
2,4:begin r:=getnode(2);words:=2;end;6:begin r:=getnode(2);
incr(mem[mem[p+1].hh.rh].hh.lh);words:=2;end;
38:begin if mem[p+1].hh.lh<=1 then begin r:=getnode(3);
incr(mem[mem[p+2].hh.rh].hh.lh);words:=3;end else begin r:=getnode(2);
words:=2;end;end;39:begin r:=getnode(2);incr(mem[mem[p+1].hh.rh].hh.lh);
words:=2;end;40:begin r:=getnode(2);words:=2;end;41:begin r:=getnode(2);
words:=2;end;8:begin r:=getnode(2);words:=2;end;10:begin r:=getnode(5);
words:=5;end;12:begin r:=getnode(5);words:=5;end;13:begin r:=getnode(7);
incr(mem[mem[p+5].hh.lh].hh.lh);words:=7;end;14:begin r:=getnode(7);
mem[r+2].int:=mem[p+2].int;mem[r+3].int:=mem[p+3].int;
mem[r+1].int:=mem[p+1].int;mem[r+5].hh.lh:=mem[p+5].hh.lh;
if mem[r+5].hh.lh<>-268435455 then incr(mem[mem[r+5].hh.lh].hh.lh);
mem[r+5].hh.rh:=mem[p+5].hh.rh;incr(mem[mem[r+5].hh.rh+2].hh.rh);
mem[r+6].int:=mem[p+6].int;end;15:r:=getnode(2);17:begin r:=getnode(7);
if mem[p+5].hh.b1>0 then incr(mem[mem[p+5].hh.rh].hh.lh);words:=7;end;
18,19:begin r:=getnode(7);
if mem[p+5].hh.b1>0 then incr(mem[mem[p+5].hh.rh].hh.lh);
if mem[p+6].hh.lh<>-268435455 then incr(mem[mem[p+6].hh.lh].hh.lh);
words:=7;end;20:r:=getnode(2);21:r:=getnode(2);34:r:=getnode(2);
35:begin incr(mem[mem[p+1].hh.lh].hh.rh);r:=getnode(3);words:=3;end;
36:r:=getnode(2);43:r:=getnode(2);44:r:=getnode(2);45:r:=getnode(2);
others:confusion(1897)end{:1602};10:begin r:=getnode(4);
incr(mem[mem[p+1].hh.lh].hh.rh);{1930:}mem[r+2].int:=mem[p+2].int;
mem[r+3].int:=mem[p+3].int;{:1930};mem[r+1].hh.lh:=mem[p+1].hh.lh;
mem[r+1].hh.rh:=copynodelist(mem[p+1].hh.rh);end;
11,9,12:begin r:=getnode(4);words:=4;end;40:begin r:=getnode(3);
begin mem[r+2].hh.lh:=avail;
if mem[r+2].hh.lh=-268435455 then mem[r+2].hh.lh:=getavail else begin
avail:=mem[mem[r+2].hh.lh].hh.rh;mem[mem[r+2].hh.lh].hh.rh:=-268435455;
ifdef('STAT')incr(dynused);endif('STAT')end;end;
mem[mem[r+2].hh.lh].hh.b0:=mem[mem[p+2].hh.lh].hh.b0;
mem[mem[r+2].hh.lh].hh.b1:=mem[mem[p+2].hh.lh].hh.b1;words:=2;end;
6:begin r:=getnode(2);mem[r+1]:=mem[p+1];
mem[r+1].hh.rh:=copynodelist(mem[p+1].hh.rh);end;7:begin r:=getnode(2);
mem[r+1].hh.lh:=copynodelist(mem[p+1].hh.lh);
mem[r+1].hh.rh:=copynodelist(mem[p+1].hh.rh);end;4:begin r:=getnode(2);
incr(mem[mem[p+1].hh.rh].hh.lh);words:=2;end;5:begin r:=getnode(2);
mem[r+1].int:=copynodelist(mem[p+1].int);end;
others:confusion(363)end{:224};while words>0 do begin decr(words);
mem[r+words]:=mem[p+words];end{:223};mem[q].hh.rh:=r;q:=r;
p:=mem[p].hh.rh;end;mem[q].hh.rh:=-268435455;q:=mem[h].hh.rh;
begin mem[h].hh.rh:=avail;avail:=h;ifdef('STAT')decr(dynused);
endif('STAT')end;copynodelist:=q;end;
{:222}{229:}procedure printmode(m:integer);
begin if m>0 then case m div(103)of 0:print(364);1:print(365);
2:print(366);
end else if m=0 then print(367)else case(-m)div(103)of 0:print(368);
1:print(369);2:print(370);end;end;procedure printinmode(m:integer);
begin if m>0 then case m div(103)of 0:print(371);1:print(372);
2:print(373);
end else if m=0 then print(374)else case(-m)div(103)of 0:print(375);
1:print(376);2:print(377);end;end;{:229}{234:}procedure pushnest;
begin if nestptr>maxneststack then begin maxneststack:=nestptr;
if nestptr=nestsize then overflow(378,nestsize);end;
nest[nestptr]:=curlist;incr(nestptr);curlist.headfield:=getavail;
curlist.tailfield:=curlist.headfield;curlist.pgfield:=0;
curlist.mlfield:=line;curlist.eTeXauxfield:=-268435455;end;
{:234}{235:}procedure popnest;
begin begin mem[curlist.headfield].hh.rh:=avail;
avail:=curlist.headfield;ifdef('STAT')decr(dynused);endif('STAT')end;
decr(nestptr);curlist:=nest[nestptr];end;
{:235}{236:}procedure printtotals;forward;procedure showactivities;
var p:0..nestsize;m:-207..207;a:memoryword;q,r:halfword;t:integer;
begin nest[nestptr]:=curlist;printnl(345);println;
for p:=nestptr downto 0 do begin m:=nest[p].modefield;
a:=nest[p].auxfield;printnl(379);printmode(m);print(380);
printint(abs(nest[p].mlfield));
if m=104 then if nest[p].pgfield<>8585216 then begin print(381);
printint(nest[p].pgfield mod 65536);print(382);
printint(nest[p].pgfield div 4194304);printchar(44);
printint((nest[p].pgfield div 65536)mod 64);printchar(41);end;
if nest[p].mlfield<0 then print(383);
if p=0 then begin{1164:}if memtop-2<>pagetail then begin printnl(1385);
if outputactive then print(1386);showbox(mem[memtop-2].hh.rh);
if pagecontents>0 then begin printnl(1387);printtotals;printnl(1388);
printscaled(pagesofar[0]);r:=mem[memtop].hh.rh;
while r<>memtop do begin println;printesc(337);t:=mem[r].hh.b1;
printint(t);print(1389);
if eqtb[27281+t].int=1000 then t:=mem[r+3].int else t:=xovern(mem[r+3].
int,1000)*eqtb[27281+t].int;printscaled(t);
if mem[r].hh.b0=1 then begin q:=memtop-2;t:=0;repeat q:=mem[q].hh.rh;
if(mem[q].hh.b0=3)and(mem[q].hh.b1=mem[r].hh.b1)then incr(t);
until q=mem[r+1].hh.lh;print(1390);printint(t);print(1391);end;
r:=mem[r].hh.rh;end;end;end{:1164};
if mem[memtop-1].hh.rh<>-268435455 then printnl(384);end;
showbox(mem[nest[p].headfield].hh.rh);
{237:}case abs(m)div(103)of 0:begin printnl(385);
if a.int<=eqtb[27825].int then print(386)else printscaled(a.int);
if nest[p].pgfield<>0 then begin print(387);printint(nest[p].pgfield);
if nest[p].pgfield<>1 then print(388)else print(389);end;end;
1:begin printnl(390);printint(a.hh.lh);
if m>0 then if a.hh.rh>0 then begin print(391);printint(a.hh.rh);end;
end;2:if a.int<>-268435455 then begin print(392);showbox(a.int);end;
end{:237};end;end;{:236}{255:}procedure printparam(n:integer);
begin case n of 0:printesc(440);1:printesc(441);2:printesc(442);
3:printesc(443);4:printesc(444);5:printesc(445);6:printesc(446);
7:printesc(447);8:printesc(448);9:printesc(449);10:printesc(450);
11:printesc(451);12:printesc(452);13:printesc(453);14:printesc(454);
15:printesc(455);16:printesc(456);17:printesc(457);18:printesc(458);
19:printesc(459);20:printesc(460);21:printesc(461);22:printesc(462);
23:printesc(463);24:printesc(464);25:printesc(465);26:printesc(466);
27:printesc(467);28:printesc(468);29:printesc(469);30:printesc(470);
31:printesc(471);32:printesc(472);33:printesc(473);34:printesc(474);
35:printesc(475);36:printesc(476);37:printesc(477);38:printesc(478);
39:printesc(479);40:printesc(480);41:printesc(481);42:printesc(482);
43:printesc(483);44:printesc(484);45:printesc(485);46:printesc(486);
47:printesc(487);48:printesc(488);49:printesc(489);50:printesc(490);
51:printesc(491);52:printesc(492);53:printesc(493);54:printesc(494);
55:printesc(495);56:printesc(496);57:printesc(497);58:printesc(498);
59:printesc(499);60:printesc(500);61:printesc(501);62:printesc(502);
63:printesc(503);82:printesc(504);64:printesc(505);65:printesc(506);
66:printesc(507);67:printesc(508);68:printesc(509);69:printesc(510);
70:printesc(511);71:printesc(512);72:printesc(513);73:printesc(514);
74:printesc(515);75:printesc(516);76:printesc(517);77:printesc(518);
78:printesc(519);79:printesc(520);80:printesc(521);81:printesc(522);
83:printesc(523);84:printesc(524);85:printesc(525);86:printesc(526);
87:printesc(527);88:printesc(528);89:printesc(529);90:printesc(530);
91:printesc(531);92:printesc(532);{1902:}103:printesc(2067);
{:1902}{1657:}93:printesc(1961);94:printesc(1962);95:printesc(1963);
96:printesc(1964);97:printesc(1965);98:printesc(1966);99:printesc(1967);
100:printesc(1968);101:printesc(1969);{:1657}{1698:}102:printesc(2009);
{:1698}others:print(533)end;end;{:255}{263:}procedure begindiagnostic;
begin oldsetting:=selector;
if(eqtb[27206].int<=0)and(selector=19)then begin decr(selector);
if history=0 then history:=1;end;end;
procedure enddiagnostic(blankline:boolean);begin printnl(345);
if blankline then println;selector:=oldsetting;end;
{:263}{265:}procedure printlengthparam(n:integer);
begin case n of 0:printesc(537);1:printesc(538);2:printesc(539);
3:printesc(540);4:printesc(541);5:printesc(542);6:printesc(543);
7:printesc(544);8:printesc(545);9:printesc(546);10:printesc(547);
11:printesc(548);12:printesc(549);13:printesc(550);14:printesc(551);
15:printesc(552);16:printesc(553);17:printesc(554);18:printesc(555);
19:printesc(556);20:printesc(557);21:printesc(558);22:printesc(559);
23:printesc(560);24:printesc(561);25:printesc(562);26:printesc(563);
27:printesc(564);28:printesc(565);29:printesc(566);30:printesc(567);
31:printesc(568);32:printesc(569);33:printesc(570);others:print(571)end;
end;{:265}{270:}{320:}procedure printcmdchr(cmd:quarterword;
chrcode:halfword);var n:integer;begin case cmd of 1:begin print(638);
print(chrcode);end;2:begin print(639);print(chrcode);end;
3:begin print(640);print(chrcode);end;6:begin print(641);print(chrcode);
end;7:begin print(642);print(chrcode);end;8:begin print(643);
print(chrcode);end;9:print(644);10:begin print(645);print(chrcode);end;
11:begin print(646);print(chrcode);end;12:begin print(647);
print(chrcode);end;
{245:}75,76:if chrcode<24546 then printskipparam(chrcode-24528)else if
chrcode<24802 then begin printesc(412);printint(chrcode-24546);
end else begin printesc(413);printint(chrcode-24802);end;
{:245}{249:}72:if chrcode>=25073 then begin printesc(427);
printint(chrcode-25073);end else case chrcode of 25059:printesc(414);
25060:printesc(415);25061:printesc(416);25062:printesc(417);
25063:printesc(418);25064:printesc(419);25065:printesc(420);
25066:printesc(421);{1656:}25072:printesc(1960);
{:1656}25068:printesc(423);25069:printesc(424);25070:printesc(425);
25071:printesc(426);others:printesc(422)end;
{:249}{257:}73:if chrcode<27281 then printparam(chrcode-27177)else begin
printesc(535);printint(chrcode-27281);end;
{:257}{267:}74:if chrcode<27827 then printlengthparam(chrcode-27793)else
begin printesc(572);printint(chrcode-27827);end;
{:267}{288:}45:printesc(582);90:printesc(583);40:printesc(584);
41:printesc(585);77:printesc(596);61:printesc(586);42:printesc(609);
16:printesc(587);109:printesc(578);88:printesc(593);101:printesc(594);
102:printesc(595);15:printesc(588);92:printesc(589);
67:if chrcode=10 then printesc(590)else printesc(579);62:printesc(591);
64:printesc(32);
104:if chrcode=0 then printesc(592){1761:}else printesc(928){:1761};
32:printesc(597);36:printesc(598);
39:if chrcode=0 then printesc(599)else printesc(575);37:printesc(337);
44:printesc(47);18:begin printesc(359);if chrcode>0 then printchar(115);
end;46:printesc(600);17:printesc(601);54:printesc(602);91:printesc(603);
34:printesc(604);65:printesc(605);
105:if chrcode=0 then printesc(606)else printesc(575);55:printesc(342);
63:printesc(607);66:printesc(611);
96:if chrcode=0 then printesc(612){1758:}else printesc(2024){:1758};
0:printesc(613);98:printesc(614);80:printesc(610);
84:case chrcode of 25058:printesc(608);{1863:}25329:printesc(2060);
25330:printesc(2061);25331:printesc(2062);25332:printesc(2063);
{:1863}end;
111:if chrcode=0 then printesc(615){1685:}else if chrcode=1 then
printesc(1999)else printesc(2000){:1685};71:{1831:}begin printesc(427);
if chrcode<>membot then printsanum(chrcode);end{:1831};38:printesc(360);
33:if chrcode=0 then printesc(616){1700:}else case chrcode of 6:printesc
(2010);7:printesc(2011);10:printesc(2012);
others:printesc(2013)end{:1700};56:printesc(617);35:printesc(618);
{:288}{357:}13:printesc(679);
{:357}{406:}106:if chrcode=0 then printesc(717){1746:}else if chrcode=2
then printesc(2022){:1746}else printesc(718);
{:406}{414:}112:begin case(chrcode mod 5)of 1:printesc(720);
2:printesc(721);3:printesc(722);4:printesc(723);others:printesc(719)end;
if chrcode>=5 then printchar(115);end;
{:414}{441:}89:{1830:}begin if(chrcode<membot)or(chrcode>membot+19)then
cmd:=(mem[chrcode].hh.b0 div 16)else begin cmd:=chrcode-membot;
chrcode:=-268435455;end;
if cmd=0 then printesc(535)else if cmd=1 then printesc(572)else if cmd=2
then printesc(412)else printesc(413);
if chrcode<>-268435455 then printsanum(chrcode);end{:1830};
{:441}{446:}79:if chrcode=1 then printesc(757)else printesc(756);
82:if chrcode=0 then printesc(758){1691:}else if chrcode=2 then printesc
(2005){:1691}else printesc(759);
83:if chrcode=1 then printesc(760)else if chrcode=3 then printesc(761)
else printesc(762);70:case chrcode of 0:printesc(763);1:printesc(764);
2:printesc(765);4:printesc(766);{1648:}3:printesc(1957);
20:printesc(1958);{:1648}{1662:}21:printesc(1984);22:printesc(1985);
{:1662}{1665:}23:printesc(1986);24:printesc(1987);25:printesc(1988);
{:1665}{1668:}28:printesc(1989);29:printesc(1990);30:printesc(1991);
31:printesc(1992);{:1668}{1671:}32:printesc(1993);33:printesc(1994);
34:printesc(1995);{:1671}{1777:}39:printesc(2036);40:printesc(2037);
41:printesc(2038);42:printesc(2039);{:1777}{1800:}26:printesc(2043);
27:printesc(2044);35:printesc(2045);36:printesc(2046);
{:1800}{1804:}37:printesc(2047);38:printesc(2048);
{:1804}6:printesc(768);7:printesc(769);8:printesc(770);9:printesc(771);
10:printesc(772);11:printesc(773);12:printesc(774);13:printesc(775);
14:printesc(776);15:printesc(777);16:printesc(778);17:printesc(779);
18:printesc(780);19:printesc(781);others:printesc(767)end;
{:446}{498:}110:case chrcode of 0:printesc(840);1:printesc(841);
2:printesc(842);3:printesc(843);4:printesc(844);5:printesc(872);
6:printesc(845);7:printesc(846);8:printesc(847);9:printesc(848);
10:printesc(849);11:printesc(850);15:printesc(851);16:printesc(852);
12:printesc(853);13:printesc(854);14:printesc(855);19:printesc(856);
20:printesc(857);21:printesc(858);22:printesc(859);23:printesc(860);
24:printesc(861);25:printesc(862);26:printesc(863);27:printesc(864);
17:printesc(865);18:printesc(866);28:printesc(867);29:printesc(868);
30:printesc(870);31:printesc(871);others:printesc(869)end;
{:498}{517:}107:begin if chrcode>=32 then printesc(928);
case chrcode mod 32 of 1:printesc(911);2:printesc(912);3:printesc(913);
4:printesc(914);5:printesc(915);6:printesc(916);7:printesc(917);
8:printesc(918);9:printesc(919);10:printesc(920);11:printesc(921);
12:printesc(922);13:printesc(923);14:printesc(924);15:printesc(925);
16:printesc(926);21:printesc(927);{1762:}17:printesc(2025);
18:printesc(2026);19:printesc(2027);20:printesc(2028);22:printesc(2029);
23:printesc(2030);{:1762}others:printesc(910)end;end;
{:517}{521:}108:if chrcode=2 then printesc(929)else if chrcode=4 then
printesc(930)else printesc(931);
{:521}{958:}4:if chrcode=256 then printesc(1297)else begin print(1301);
print(chrcode);end;
5:if chrcode=257 then printesc(1298)else printesc(1299);
{:958}{1162:}81:case chrcode of 0:printesc(1375);1:printesc(1376);
2:printesc(1377);3:printesc(1378);4:printesc(1379);5:printesc(1380);
6:printesc(1381);others:printesc(1382)end;
{:1162}{1232:}14:if chrcode=1 then printesc(1428)else printesc(349);
{:1232}{1238:}26:case chrcode of 4:printesc(1429);0:printesc(1430);
1:printesc(1431);2:printesc(1432);others:printesc(1433)end;
27:case chrcode of 4:printesc(1434);0:printesc(1435);1:printesc(1436);
2:printesc(1437);others:printesc(1438)end;28:printesc(343);
29:printesc(322);30:printesc(348);
{:1238}{1251:}21:if chrcode=1 then printesc(1456)else printesc(1457);
22:if chrcode=1 then printesc(1458)else printesc(1459);
20:case chrcode of 0:printesc(429);1:printesc(1460);2:printesc(1461);
3:printesc(1370);4:printesc(1462);5:printesc(1372);
others:printesc(1463)end;
31:if chrcode=100 then printesc(1465)else if chrcode=101 then printesc(
1466)else if chrcode=102 then printesc(1467)else printesc(1464);
{:1251}{1268:}43:if chrcode=0 then printesc(1484)else if chrcode=1 then
printesc(1483)else printesc(1485);
{:1268}{1287:}25:if chrcode=10 then printesc(1497)else if chrcode=11
then printesc(1496)else printesc(1495);
23:if chrcode=1 then printesc(1499)else printesc(1498);
24:if chrcode=1 then printesc(1501){1860:}else if chrcode=2 then
printesc(2058)else if chrcode=3 then printesc(2059){:1860}else printesc(
1500);{:1287}{1294:}47:if chrcode=1 then printesc(45)else printesc(357);
{:1294}{1322:}48:if chrcode=1 then printesc(1534)else printesc(1533);
{:1322}{1336:}50:case chrcode of 16:printesc(1264);17:printesc(1265);
18:printesc(1266);19:printesc(1267);20:printesc(1268);21:printesc(1269);
22:printesc(1270);23:printesc(1271);26:printesc(1273);
others:printesc(1272)end;
51:if chrcode=1 then printesc(1277)else if chrcode=2 then printesc(1278)
else printesc(1535);{:1336}{1349:}53:printstyle(chrcode);
{:1349}{1358:}52:case chrcode of 1:printesc(1554);2:printesc(1555);
3:printesc(1556);4:printesc(1557);5:printesc(1558);
others:printesc(1553)end;
{:1358}{1368:}49:if chrcode=30 then printesc(1274){1696:}else if chrcode
=1 then printesc(1276){:1696}else printesc(1275);
{:1368}{1388:}93:if chrcode=1 then printesc(1578)else if chrcode=2 then
printesc(1579){1769:}else if chrcode=8 then printesc(1592){:1769}else
printesc(1580);
97:if chrcode=0 then printesc(1581)else if chrcode=1 then printesc(1582)
else if chrcode=2 then printesc(1583)else printesc(1584);
{:1388}{1399:}94:if chrcode<>0 then if chrcode=10 then printesc(1603)
else if chrcode=11 then printesc(1604)else printesc(1602)else printesc(
1601);{:1399}{1402:}95:case chrcode of 0:printesc(1610);
1:printesc(1611);2:printesc(1612);3:printesc(1613);4:printesc(1614);
5:printesc(1615);7:printesc(1617);others:printesc(1616)end;
68:begin printesc(587);printhex(chrcode);end;69:begin printesc(601);
printhex(chrcode);end;
{:1402}{1410:}85:if chrcode=25590 then printesc(1622)else if chrcode=
25591 then printesc(1623)else if chrcode=25592 then printesc(1624)else
if chrcode=25641 then printesc(435)else if chrcode=26665 then printesc(
439)else if chrcode=25897 then printesc(436)else if chrcode=26153 then
printesc(437)else if chrcode=26409 then printesc(438)else printesc(536);
86:printsize(chrcode-25593);
{:1410}{1430:}99:if chrcode=1 then printesc(1356)else printesc(1344);
{:1430}{1434:}78:case chrcode of 0:printesc(1640);1:printesc(1641);
2:printesc(1642);3:printesc(1643);4:printesc(1644);5:printesc(1645);
7:printesc(1646);8:printesc(1647);9:printesc(1648);10:printesc(1649);
11:printesc(1650);6:printesc(1651);end;
{:1434}{1440:}87:begin print(1658);slowprint(fontname[chrcode]);
if fontsize[chrcode]<>fontdsize[chrcode]then begin print(895);
printscaled(fontsize[chrcode]);print(312);end;end;
{:1440}{1442:}100:case chrcode of 0:printesc(274);1:printesc(275);
2:printesc(276);others:printesc(1659)end;
{:1442}{1452:}60:if chrcode=0 then printesc(1661)else printesc(1660);
{:1452}{1457:}58:if chrcode=0 then printesc(1662)else printesc(1663);
{:1457}{1466:}57:if chrcode=25897 then printesc(1669)else printesc(1670)
;{:1466}{1471:}19:case chrcode of 1:printesc(1672);2:printesc(1673);
3:printesc(1674);{1674:}4:printesc(1996);{:1674}{1683:}5:printesc(1998);
{:1683}{1688:}6:printesc(2001);{:1688}others:printesc(1671)end;
{:1471}{1474:}103:print(1681);113,114,115,116:begin n:=cmd-113;
if mem[mem[chrcode].hh.rh].hh.lh=3585 then n:=n+4;
if odd(n div 4)then printesc(1592);if odd(n)then printesc(1578);
if odd(n div 2)then printesc(1579);if n>0 then printchar(32);
print(1682);end;117:printesc(1683);
{:1474}{1527:}59:case chrcode of 0:printesc(1721);1:printesc(676);
2:printesc(1722);3:printesc(1723);4:printesc(1724);5:printesc(1725);
13:printesc(1736);23:printesc(1749);17:printesc(1740);15:printesc(1738);
20:printesc(1743);25:printesc(1752);32:printesc(1759);26:printesc(1751);
22:printesc(1748);6:printesc(1726);38:printesc(1126);39:printesc(1727);
40:printesc(1728);41:printesc(1729);27:printesc(1753);28:printesc(1754);
24:printesc(1750);7:printesc(1730);16:printesc(1739);8:printesc(1731);
10:printesc(1733);12:printesc(1735);21:printesc(1744);34:printesc(1745);
36:printesc(1747);35:printesc(1746);14:printesc(1737);19:printesc(1742);
18:printesc(1741);29:printesc(1755);30:printesc(1756);9:printesc(1732);
11:printesc(1734);31:printesc(1757);33:printesc(1758);42:printesc(1761);
37:printesc(1760);43:printesc(1762);44:printesc(1763);45:printesc(1764);
others:print(1765)end;{:1527}others:print(648)end;end;
{:320}ifdef('STAT')procedure showeqtb(n:halfword);
begin if n<1 then printchar(63)else if(n<24528)or((n>28082)and(n<=
eqtbtop))then{241:}begin sprintcs(n);printchar(61);
printcmdchr(eqtb[n].hh.b0,eqtb[n].hh.rh);
if eqtb[n].hh.b0>=113 then begin printchar(58);
showtokenlist(mem[eqtb[n].hh.rh].hh.rh,-268435455,32);end;
end{:241}else if n<25058 then{247:}if n<24546 then begin printskipparam(
n-24528);printchar(61);
if n<24543 then printspec(eqtb[n].hh.rh,312)else printspec(eqtb[n].hh.rh
,344);end else if n<24802 then begin printesc(412);printint(n-24546);
printchar(61);printspec(eqtb[n].hh.rh,312);end else begin printesc(413);
printint(n-24802);printchar(61);printspec(eqtb[n].hh.rh,344);
end{:247}else if n<27177 then{251:}if(n=25058)or((n>=25329)and(n<25333))
then begin printcmdchr(84,n);printchar(61);
if eqtb[n].hh.rh=-268435455 then printchar(48)else if n>25058 then begin
printint(mem[eqtb[n].hh.rh+1].int);printchar(32);
printint(mem[eqtb[n].hh.rh+2].int);
if mem[eqtb[n].hh.rh+1].int>1 then printesc(428);
end else printint(mem[eqtb[25058].hh.rh].hh.lh);
end else if n<25073 then begin printcmdchr(72,n);printchar(61);
if eqtb[n].hh.rh<>-268435455 then showtokenlist(mem[eqtb[n].hh.rh].hh.rh
,-268435455,32);end else if n<25333 then begin printesc(427);
printint(n-25073);printchar(61);
if eqtb[n].hh.rh<>-268435455 then showtokenlist(mem[eqtb[n].hh.rh].hh.rh
,-268435455,32);end else if n<25589 then begin printesc(429);
printint(n-25333);printchar(61);
if eqtb[n].hh.rh=-268435455 then print(430)else begin depththreshold:=0;
breadthmax:=1;shownodelist(eqtb[n].hh.rh);end;
end else if n<25641 then{252:}begin if n=25589 then print(431)else if n<
25609 then begin printesc(432);printint(n-25593);
end else if n<25625 then begin printesc(433);printint(n-25609);
end else begin printesc(434);printint(n-25625);end;printchar(61);
printesc(hash[15526+eqtb[n].hh.rh].rh);
end{:252}else{253:}if n<26665 then begin if n<25897 then begin printesc(
435);printint(n-25641);end else if n<26153 then begin printesc(436);
printint(n-25897);end else if n<26409 then begin printesc(437);
printint(n-26153);end else begin printesc(438);printint(n-26409);end;
printchar(61);printint(eqtb[n].hh.rh);end else begin printesc(439);
printint(n-26665);printchar(61);printint(eqtb[n].hh.rh);
end{:253}{:251}else if n<27793 then{260:}begin if n<27281 then
printparam(n-27177)else if n<27537 then begin printesc(535);
printint(n-27281);end else begin printesc(536);printint(n-27537);end;
printchar(61);printint(eqtb[n].int);
end{:260}else if n<=28082 then{269:}begin if n<27827 then
printlengthparam(n-27793)else begin printesc(572);printint(n-27827);end;
printchar(61);printscaled(eqtb[n].int);print(312);
end{:269}else printchar(63);end;
endif('STAT'){:270}{278:}function idlookup(j,l:integer):halfword;
label 40;var h:integer;d:integer;p:halfword;k:halfword;
begin{280:}h:=buffer[j];for k:=j+1 to j+l-1 do begin h:=h+h+buffer[k];
while h>=8501 do h:=h-8501;end{:280};p:=h+514;
while true do begin if hash[p].rh>0 then if(strstart[hash[p].rh+1]-
strstart[hash[p].rh])=l then if streqbuf(hash[p].rh,j)then goto 40;
if hash[p].lh=0 then begin if nonewcontrolsequence then p:=24527 else
{279:}begin if hash[p].rh>0 then begin if hashhigh<hashextra then begin
incr(hashhigh);hash[p].lh:=hashhigh+28082;p:=hashhigh+28082;
end else begin repeat if(hashused=514)then overflow(576,15000+hashextra)
;decr(hashused);until hash[hashused].rh=0;hash[p].lh:=hashused;
p:=hashused;end;end;
begin if poolptr+l>poolsize then overflow(259,poolsize-initpoolptr);end;
d:=(poolptr-strstart[strptr]);
while poolptr>strstart[strptr]do begin decr(poolptr);
strpool[poolptr+l]:=strpool[poolptr];end;
for k:=j to j+l-1 do begin strpool[poolptr]:=buffer[k];incr(poolptr);
end;hash[p].rh:=makestring;poolptr:=poolptr+d;
ifdef('STAT')incr(cscount);endif('STAT')end{:279};goto 40;end;
p:=hash[p].lh;end;40:idlookup:=p;end;
{:278}{281:}function primlookup(s:strnumber):halfword;label 40;
var h:integer;p:halfword;k:halfword;j,l:integer;
begin if s<256 then begin p:=s;if(p<0)or(primeqtb[p].hh.b1<>1)then p:=0;
end else begin j:=strstart[s];
if s=strptr then l:=(poolptr-strstart[strptr])else l:=(strstart[s+1]-
strstart[s]);{283:}h:=strpool[j];
for k:=j+1 to j+l-1 do begin h:=h+h+strpool[k];
while h>=1777 do h:=h-1777;end{:283};p:=h+1;
while true do begin if prim[p].rh>0 then if(strstart[prim[p].rh+1]-
strstart[prim[p].rh])=l then if streqstr(prim[p].rh,s)then goto 40;
if prim[p].lh=0 then begin if nonewcontrolsequence then p:=0 else{282:}
begin if prim[p].rh>0 then begin repeat if(primused=1)then overflow(577,
2100);decr(primused);until prim[primused].rh=0;prim[p].lh:=primused;
p:=primused;end;prim[p].rh:=s;end{:282};goto 40;end;p:=prim[p].lh;end;
end;40:primlookup:=p;end;
{:281}{286:}ifdef('INITEX')procedure primitive(s:strnumber;
c:quarterword;o:halfword);var k:poolpointer;j:0..bufsize;l:smallnumber;
primval:integer;begin if s<256 then begin curval:=s+257;primval:=s;
end else begin k:=strstart[s];l:=strstart[s+1]-k;
if first+l>bufsize+1 then overflow(258,bufsize);
for j:=0 to l-1 do buffer[first+j]:=strpool[k+j];
curval:=idlookup(first,l);begin decr(strptr);poolptr:=strstart[strptr];
end;hash[curval].rh:=s;primval:=primlookup(s);end;eqtb[curval].hh.b1:=1;
eqtb[curval].hh.b0:=c;eqtb[curval].hh.rh:=o;primeqtb[primval].hh.b1:=1;
primeqtb[primval].hh.b0:=c;primeqtb[primval].hh.rh:=o;end;
endif('INITEX'){:286}{290:}{306:}ifdef('STAT')procedure restoretrace(p:
halfword;s:strnumber);begin begindiagnostic;printchar(123);print(s);
printchar(32);showeqtb(p);printchar(125);enddiagnostic(false);end;
endif('STAT'){:306}{1659:}procedure printgroup(e:boolean);label 10;
begin case curgroup of 0:begin print(1970);goto 10;end;
1,14:begin if curgroup=14 then print(1971);print(1972);end;
2,3:begin if curgroup=3 then print(1973);print(1463);end;4:print(1372);
5:print(1462);6,7:begin if curgroup=7 then print(1974);print(1975);end;
8:print(414);10:print(1976);11:print(337);12:print(617);
9,13,15,16:begin print(351);
if curgroup=13 then print(1977)else if curgroup=15 then print(1978)else
if curgroup=16 then print(1979);end;end;print(1980);printint(curlevel);
printchar(41);
if savestack[saveptr-1].int<>0 then begin if e then print(380)else print
(1981);printint(savestack[saveptr-1].int);end;10:end;
{:1659}{1660:}ifdef('STAT')procedure grouptrace(e:boolean);
begin begindiagnostic;printchar(123);
if e then print(1982)else print(1983);printgroup(e);printchar(125);
enddiagnostic(false);end;
endif('STAT'){:1660}{1754:}function pseudoinput:boolean;var p:halfword;
sz:integer;w:fourquarters;r:halfword;begin last:=first;
p:=mem[pseudofiles].hh.lh;
if p=-268435455 then pseudoinput:=false else begin mem[pseudofiles].hh.
lh:=mem[p].hh.rh;sz:=mem[p].hh.lh;
if 4*sz-3>=bufsize-last then{35:}begin curinput.locfield:=first;
curinput.limitfield:=last-1;overflow(258,bufsize);end{:35};last:=first;
for r:=p+1 to p+sz-1 do begin w:=mem[r].qqqq;buffer[last]:=w.b0;
buffer[last+1]:=w.b1;buffer[last+2]:=w.b2;buffer[last+3]:=w.b3;
last:=last+4;end;if last>=maxbufstack then maxbufstack:=last+1;
while(last>first)and(buffer[last-1]=32)do decr(last);freenode(p,sz);
pseudoinput:=true;end;end;{:1754}{1755:}procedure pseudoclose;
var p,q:halfword;begin p:=mem[pseudofiles].hh.rh;
q:=mem[pseudofiles].hh.lh;begin mem[pseudofiles].hh.rh:=avail;
avail:=pseudofiles;ifdef('STAT')decr(dynused);endif('STAT')end;
pseudofiles:=p;while q<>-268435455 do begin p:=q;q:=mem[p].hh.rh;
freenode(p,mem[p].hh.lh);end;end;{:1755}{1772:}procedure groupwarning;
var i:0..maxinopen;w:boolean;begin baseptr:=inputptr;
inputstack[baseptr]:=curinput;i:=inopen;w:=false;
while(grpstack[i]=curboundary)and(i>0)do begin{1773:}if eqtb[27274].int>
0 then begin while(inputstack[baseptr].statefield=0)or(inputstack[
baseptr].indexfield>i)do decr(baseptr);
if inputstack[baseptr].namefield>17 then w:=true;end{:1773};
grpstack[i]:=savestack[saveptr].hh.rh;decr(i);end;
if w then begin printnl(2032);printgroup(true);print(2033);println;
if eqtb[27274].int>1 then showcontext;if history=0 then history:=1;end;
end;{:1772}{1774:}procedure ifwarning;var i:0..maxinopen;w:boolean;
begin baseptr:=inputptr;inputstack[baseptr]:=curinput;i:=inopen;
w:=false;
while ifstack[i]=condptr do begin{1773:}if eqtb[27274].int>0 then begin
while(inputstack[baseptr].statefield=0)or(inputstack[baseptr].indexfield
>i)do decr(baseptr);if inputstack[baseptr].namefield>17 then w:=true;
end{:1773};ifstack[i]:=mem[condptr].hh.rh;decr(i);end;
if w then begin printnl(2032);printcmdchr(107,curif);
if ifline<>0 then begin print(2002);printint(ifline);end;print(2033);
println;if eqtb[27274].int>1 then showcontext;
if history=0 then history:=1;end;end;
{:1774}{1775:}procedure filewarning;var p:halfword;l:quarterword;
c:quarterword;i:integer;begin p:=saveptr;l:=curlevel;c:=curgroup;
saveptr:=curboundary;
while grpstack[inopen]<>saveptr do begin decr(curlevel);printnl(2034);
printgroup(true);print(2035);curgroup:=savestack[saveptr].hh.b1;
saveptr:=savestack[saveptr].hh.rh end;saveptr:=p;curlevel:=l;
curgroup:=c;p:=condptr;l:=iflimit;c:=curif;i:=ifline;
while ifstack[inopen]<>condptr do begin printnl(2034);
printcmdchr(107,curif);if iflimit=2 then printesc(931);
if ifline<>0 then begin print(2002);printint(ifline);end;print(2035);
ifline:=mem[condptr+1].int;curif:=mem[condptr].hh.b1;
iflimit:=mem[condptr].hh.b0;condptr:=mem[condptr].hh.rh;end;condptr:=p;
iflimit:=l;curif:=c;ifline:=i;println;
if eqtb[27274].int>1 then showcontext;if history=0 then history:=1;end;
{:1775}{1819:}procedure deletesaref(q:halfword);label 10;var p:halfword;
i:smallnumber;s:smallnumber;begin decr(mem[q+1].hh.lh);
if mem[q+1].hh.lh<>-268435455 then goto 10;
if mem[q].hh.b0<32 then if mem[q+2].int=0 then s:=3 else goto 10 else
begin if mem[q].hh.b0<64 then if mem[q+1].hh.rh=membot then
deleteglueref(membot)else goto 10 else if mem[q+1].hh.rh<>-268435455
then goto 10;s:=2;end;repeat i:=mem[q].hh.b0 mod 16;p:=q;
q:=mem[p].hh.rh;freenode(p,s);
if q=-268435455 then begin saroot[i]:=-268435455;goto 10;end;
begin if odd(i)then mem[q+(i div 2)+1].hh.rh:=-268435455 else mem[q+(i
div 2)+1].hh.lh:=-268435455;decr(mem[q].hh.b1);end;s:=9;
until mem[q].hh.b1>0;10:end;
{:1819}{1821:}ifdef('STAT')procedure showsa(p:halfword;s:strnumber);
var t:smallnumber;begin begindiagnostic;printchar(123);print(s);
printchar(32);
if p=-268435455 then printchar(63)else begin t:=(mem[p].hh.b0 div 16);
if t<4 then printcmdchr(89,p)else if t=4 then begin printesc(429);
printsanum(p);end else if t=5 then printcmdchr(71,p)else printchar(63);
printchar(61);
if t=0 then printint(mem[p+2].int)else if t=1 then begin printscaled(mem
[p+2].int);print(312);end else begin p:=mem[p+1].hh.rh;
if t=2 then printspec(p,312)else if t=3 then printspec(p,344)else if t=4
then if p=-268435455 then print(430)else begin depththreshold:=0;
breadthmax:=1;shownodelist(p);
end else if t=5 then begin if p<>-268435455 then showtokenlist(mem[p].hh
.rh,-268435455,32);end else printchar(63);end;end;printchar(125);
enddiagnostic(false);end;
endif('STAT'){:1821}{1835:}procedure sasave(p:halfword);var q:halfword;
i:quarterword;
begin if curlevel<>salevel then begin if saveptr>maxsavestack then begin
maxsavestack:=saveptr;
if maxsavestack>savesize-7 then overflow(619,savesize);end;
savestack[saveptr].hh.b0:=4;savestack[saveptr].hh.b1:=salevel;
savestack[saveptr].hh.rh:=sachain;incr(saveptr);sachain:=-268435455;
salevel:=curlevel;end;i:=mem[p].hh.b0;
if i<32 then begin if mem[p+2].int=0 then begin q:=getnode(2);i:=96;
end else begin q:=getnode(3);mem[q+2].int:=mem[p+2].int;end;
mem[q+1].hh.rh:=-268435455;end else begin q:=getnode(2);
mem[q+1].hh.rh:=mem[p+1].hh.rh;end;mem[q+1].hh.lh:=p;mem[q].hh.b0:=i;
mem[q].hh.b1:=mem[p].hh.b1;mem[q].hh.rh:=sachain;sachain:=q;
incr(mem[p+1].hh.lh);end;{:1835}{1836:}procedure sadestroy(p:halfword);
begin if mem[p].hh.b0<64 then deleteglueref(mem[p+1].hh.rh)else if mem[p
+1].hh.rh<>-268435455 then if mem[p].hh.b0<80 then flushnodelist(mem[p+1
].hh.rh)else deletetokenref(mem[p+1].hh.rh);end;
{:1836}{1837:}procedure sadef(p:halfword;e:halfword);
begin incr(mem[p+1].hh.lh);
if mem[p+1].hh.rh=e then begin ifdef('STAT')if eqtb[27270].int>0 then
showsa(p,621);endif('STAT')sadestroy(p);
end else begin ifdef('STAT')if eqtb[27270].int>0 then showsa(p,622);
endif('STAT')if mem[p].hh.b1=curlevel then sadestroy(p)else sasave(p);
mem[p].hh.b1:=curlevel;mem[p+1].hh.rh:=e;
ifdef('STAT')if eqtb[27270].int>0 then showsa(p,623);endif('STAT')end;
deletesaref(p);end;procedure sawdef(p:halfword;w:integer);
begin incr(mem[p+1].hh.lh);
if mem[p+2].int=w then begin ifdef('STAT')if eqtb[27270].int>0 then
showsa(p,621);
endif('STAT')end else begin ifdef('STAT')if eqtb[27270].int>0 then
showsa(p,622);endif('STAT')if mem[p].hh.b1<>curlevel then sasave(p);
mem[p].hh.b1:=curlevel;mem[p+2].int:=w;
ifdef('STAT')if eqtb[27270].int>0 then showsa(p,623);endif('STAT')end;
deletesaref(p);end;{:1837}{1838:}procedure gsadef(p:halfword;
e:halfword);begin incr(mem[p+1].hh.lh);
ifdef('STAT')if eqtb[27270].int>0 then showsa(p,624);
endif('STAT')sadestroy(p);mem[p].hh.b1:=1;mem[p+1].hh.rh:=e;
ifdef('STAT')if eqtb[27270].int>0 then showsa(p,623);
endif('STAT')deletesaref(p);end;procedure gsawdef(p:halfword;w:integer);
begin incr(mem[p+1].hh.lh);
ifdef('STAT')if eqtb[27270].int>0 then showsa(p,624);
endif('STAT')mem[p].hh.b1:=1;mem[p+2].int:=w;
ifdef('STAT')if eqtb[27270].int>0 then showsa(p,623);
endif('STAT')deletesaref(p);end;{:1838}{1839:}procedure sarestore;
var p:halfword;begin repeat p:=mem[sachain+1].hh.lh;
if mem[p].hh.b1=1 then begin if mem[p].hh.b0>=32 then sadestroy(sachain)
;ifdef('STAT')if eqtb[27214].int>0 then showsa(p,626);
endif('STAT')end else begin if mem[p].hh.b0<32 then if mem[sachain].hh.
b0<32 then mem[p+2].int:=mem[sachain+2].int else mem[p+2].int:=0 else
begin sadestroy(p);mem[p+1].hh.rh:=mem[sachain+1].hh.rh;end;
mem[p].hh.b1:=mem[sachain].hh.b1;
ifdef('STAT')if eqtb[27214].int>0 then showsa(p,627);endif('STAT')end;
deletesaref(p);p:=sachain;sachain:=mem[p].hh.rh;
if mem[p].hh.b0<32 then freenode(p,3)else freenode(p,2);
until sachain=-268435455;end;
{:1839}{:290}{296:}procedure newsavelevel(c:groupcode);
begin if saveptr>maxsavestack then begin maxsavestack:=saveptr;
if maxsavestack>savesize-7 then overflow(619,savesize);end;
if(eTeXmode=1)then begin savestack[saveptr+0].int:=line;incr(saveptr);
end;savestack[saveptr].hh.b0:=3;savestack[saveptr].hh.b1:=curgroup;
savestack[saveptr].hh.rh:=curboundary;
if curlevel=255 then overflow(620,255);curboundary:=saveptr;curgroup:=c;
ifdef('STAT')if eqtb[27271].int>0 then grouptrace(false);
endif('STAT')incr(curlevel);incr(saveptr);end;
{:296}{297:}procedure eqdestroy(w:memoryword);var q:halfword;
begin case w.hh.b0 of 113,114,115,116:deletetokenref(w.hh.rh);
119:deleteglueref(w.hh.rh);120:begin q:=w.hh.rh;
if q<>-268435455 then freenode(q,mem[q].hh.lh+mem[q].hh.lh+1);end;
121:flushnodelist(w.hh.rh);
{1832:}71,89:if(w.hh.rh<membot)or(w.hh.rh>membot+19)then deletesaref(w.
hh.rh);{:1832}others:end;end;{:297}{298:}procedure eqsave(p:halfword;
l:quarterword);
begin if saveptr>maxsavestack then begin maxsavestack:=saveptr;
if maxsavestack>savesize-7 then overflow(619,savesize);end;
if l=0 then savestack[saveptr].hh.b0:=1 else begin savestack[saveptr]:=
eqtb[p];incr(saveptr);savestack[saveptr].hh.b0:=0;end;
savestack[saveptr].hh.b1:=l;savestack[saveptr].hh.rh:=p;incr(saveptr);
end;{:298}{299:}procedure eqdefine(p:halfword;t:quarterword;e:halfword);
label 10;
begin if(eTeXmode=1)and(eqtb[p].hh.b0=t)and(eqtb[p].hh.rh=e)then begin
ifdef('STAT')if eqtb[27270].int>0 then restoretrace(p,621);
endif('STAT')eqdestroy(eqtb[p]);goto 10;end;
ifdef('STAT')if eqtb[27270].int>0 then restoretrace(p,622);
endif('STAT')if eqtb[p].hh.b1=curlevel then eqdestroy(eqtb[p])else if
curlevel>1 then eqsave(p,eqtb[p].hh.b1);eqtb[p].hh.b1:=curlevel;
eqtb[p].hh.b0:=t;eqtb[p].hh.rh:=e;
ifdef('STAT')if eqtb[27270].int>0 then restoretrace(p,623);
endif('STAT')10:end;{:299}{300:}procedure eqworddefine(p:halfword;
w:integer);label 10;
begin if(eTeXmode=1)and(eqtb[p].int=w)then begin ifdef('STAT')if eqtb[
27270].int>0 then restoretrace(p,621);endif('STAT')goto 10;end;
ifdef('STAT')if eqtb[27270].int>0 then restoretrace(p,622);
endif('STAT')if xeqlevel[p]<>curlevel then begin eqsave(p,xeqlevel[p]);
xeqlevel[p]:=curlevel;end;eqtb[p].int:=w;
ifdef('STAT')if eqtb[27270].int>0 then restoretrace(p,623);
endif('STAT')10:end;{:300}{301:}procedure geqdefine(p:halfword;
t:quarterword;e:halfword);
begin ifdef('STAT')if eqtb[27270].int>0 then restoretrace(p,624);
endif('STAT')begin eqdestroy(eqtb[p]);eqtb[p].hh.b1:=1;eqtb[p].hh.b0:=t;
eqtb[p].hh.rh:=e;end;
ifdef('STAT')if eqtb[27270].int>0 then restoretrace(p,623);
endif('STAT')end;procedure geqworddefine(p:halfword;w:integer);
begin ifdef('STAT')if eqtb[27270].int>0 then restoretrace(p,624);
endif('STAT')begin eqtb[p].int:=w;xeqlevel[p]:=1;end;
ifdef('STAT')if eqtb[27270].int>0 then restoretrace(p,623);
endif('STAT')end;{:301}{302:}procedure saveforafter(t:halfword);
begin if curlevel>1 then begin if saveptr>maxsavestack then begin
maxsavestack:=saveptr;
if maxsavestack>savesize-7 then overflow(619,savesize);end;
savestack[saveptr].hh.b0:=2;savestack[saveptr].hh.b1:=0;
savestack[saveptr].hh.rh:=t;incr(saveptr);end;end;
{:302}{303:}procedure backinput;forward;procedure unsave;label 30;
var p:halfword;l:quarterword;t:halfword;a:boolean;begin a:=false;
if curlevel>1 then begin decr(curlevel);
{304:}while true do begin decr(saveptr);
if savestack[saveptr].hh.b0=3 then goto 30;p:=savestack[saveptr].hh.rh;
if savestack[saveptr].hh.b0=2 then{348:}begin t:=curtok;curtok:=p;
if a then begin p:=getavail;mem[p].hh.lh:=curtok;
mem[p].hh.rh:=curinput.locfield;curinput.locfield:=p;
curinput.startfield:=p;
if curtok<768 then if curtok<512 then decr(alignstate)else incr(
alignstate);end else begin backinput;a:=(eTeXmode=1);end;curtok:=t;
end{:348}else if savestack[saveptr].hh.b0=4 then begin sarestore;
sachain:=p;salevel:=savestack[saveptr].hh.b1;
end else begin if savestack[saveptr].hh.b0=0 then begin l:=savestack[
saveptr].hh.b1;decr(saveptr);end else savestack[saveptr]:=eqtb[24527];
{305:}if(p<27177)or(p>28082)then if eqtb[p].hh.b1=1 then begin eqdestroy
(savestack[saveptr]);
ifdef('STAT')if eqtb[27214].int>0 then restoretrace(p,626);
endif('STAT')end else begin eqdestroy(eqtb[p]);
eqtb[p]:=savestack[saveptr];
ifdef('STAT')if eqtb[27214].int>0 then restoretrace(p,627);
endif('STAT')end else if xeqlevel[p]<>1 then begin eqtb[p]:=savestack[
saveptr];xeqlevel[p]:=l;
ifdef('STAT')if eqtb[27214].int>0 then restoretrace(p,627);
endif('STAT')end else begin ifdef('STAT')if eqtb[27214].int>0 then
restoretrace(p,626);endif('STAT')end{:305};end;end;
30:ifdef('STAT')if eqtb[27271].int>0 then grouptrace(true);
endif('STAT')if grpstack[inopen]=curboundary then groupwarning;
curgroup:=savestack[saveptr].hh.b1;
curboundary:=savestack[saveptr].hh.rh;
if(eTeXmode=1)then decr(saveptr){:304};end else confusion(625);end;
{:303}{310:}procedure preparemag;
begin if(magset>0)and(eqtb[27194].int<>magset)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(629);
end;printint(eqtb[27194].int);print(630);printnl(631);begin helpptr:=2;
helpline[1]:=632;helpline[0]:=633;end;interror(magset);
geqworddefine(27194,magset);end;
if(eqtb[27194].int<=0)or(eqtb[27194].int>32768)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(634);
end;begin helpptr:=1;helpline[0]:=635;end;interror(eqtb[27194].int);
geqworddefine(27194,1000);end;magset:=eqtb[27194].int;end;
{:310}{317:}procedure tokenshow(p:halfword);
begin if p<>-268435455 then showtokenlist(mem[p].hh.rh,-268435455,
10000000);end;{:317}{318:}procedure printmeaning;
begin printcmdchr(curcmd,curchr);
if curcmd>=113 then begin printchar(58);println;tokenshow(curchr);
end else if(curcmd=112)and(curchr<5)then begin printchar(58);println;
tokenshow(curmark[curchr]);end;end;{:318}{321:}procedure showcurcmdchr;
var n:integer;l:integer;p:halfword;begin begindiagnostic;printnl(123);
if curlist.modefield<>shownmode then begin printmode(curlist.modefield);
print(649);shownmode:=curlist.modefield;end;printcmdchr(curcmd,curchr);
if eqtb[27272].int>0 then if curcmd>=107 then if curcmd<=108 then begin
print(649);if curcmd=108 then begin printcmdchr(107,curif);
printchar(32);n:=0;l:=ifline;end else begin n:=1;l:=line;end;p:=condptr;
while p<>-268435455 do begin incr(n);p:=mem[p].hh.rh;end;print(650);
printint(n);printchar(41);if l<>0 then begin print(2002);printint(l);
end;end;printchar(125);enddiagnostic(false);end;
{:321}{333:}procedure showcontext;label 30;var oldsetting:0..21;
nn:integer;bottomline:boolean;{337:}i:0..bufsize;j:0..bufsize;
l:0..halferrorline;m:integer;n:0..errorline;p:integer;q:integer;
{:337}begin baseptr:=inputptr;inputstack[baseptr]:=curinput;nn:=-1;
bottomline:=false;while true do begin curinput:=inputstack[baseptr];
if(curinput.statefield<>0)then if(curinput.namefield>19)or(baseptr=0)
then bottomline:=true;
if(baseptr=inputptr)or bottomline or(nn<eqtb[27231].int)then{334:}begin
if(baseptr=inputptr)or(curinput.statefield<>0)or(curinput.indexfield<>3)
or(curinput.locfield<>-268435455)then begin tally:=0;
oldsetting:=selector;
if curinput.statefield<>0 then begin{335:}if curinput.namefield<=17 then
if(curinput.namefield=0)then if baseptr=0 then printnl(655)else printnl(
656)else begin printnl(657);
if curinput.namefield=17 then printchar(42)else printint(curinput.
namefield-1);printchar(62);
end else if curinput.indexfield<>inopen then begin printnl(658);
printint(linestack[curinput.indexfield+1]);end else begin printnl(658);
printint(line);end;printchar(32){:335};{340:}begin l:=tally;tally:=0;
selector:=20;trickcount:=1000000;end;
if buffer[curinput.limitfield]=eqtb[27225].int then j:=curinput.
limitfield else j:=curinput.limitfield+1;i:=curinput.startfield;
mubyteskeep:=mubytekeep;mubytesstart:=mubytestart;mubytestart:=false;
if j>0 then while i<j do begin if i=curinput.locfield then begin
firstcount:=tally;trickcount:=tally+1+errorline-halferrorline;
if trickcount<errorline then trickcount:=errorline;end;printbuffer(i);
end;mubytekeep:=mubyteskeep;mubytestart:=mubytesstart{:340};
end else begin{336:}case curinput.indexfield of 0:printnl(659);
1,2:printnl(660);
3:if curinput.locfield=-268435455 then printnl(661)else printnl(662);
4:printnl(663);5:begin println;printcs(curinput.namefield);end;
6:printnl(664);7:printnl(665);8:printnl(666);9:printnl(667);
10:printnl(668);11:printnl(669);12:printnl(670);13:printnl(671);
14:printnl(672);19:printnl(673);20:printnl(674);
others:printnl(63)end{:336};{341:}begin l:=tally;tally:=0;selector:=20;
trickcount:=1000000;end;
if curinput.indexfield<5 then showtokenlist(curinput.startfield,curinput
.locfield,100000)else showtokenlist(mem[curinput.startfield].hh.rh,
curinput.locfield,100000){:341};end;selector:=oldsetting;
{339:}if trickcount=1000000 then begin firstcount:=tally;
trickcount:=tally+1+errorline-halferrorline;
if trickcount<errorline then trickcount:=errorline;end;
if tally<trickcount then m:=tally-firstcount else m:=trickcount-
firstcount;if l+firstcount<=halferrorline then begin p:=0;
n:=l+firstcount;end else begin print(277);
p:=l+firstcount-halferrorline+3;n:=halferrorline;end;
for q:=p to firstcount-1 do printchar(trickbuf[q mod errorline]);
println;for q:=1 to n do printchar(32);
if m+n<=errorline then p:=firstcount+m else p:=firstcount+(errorline-n-3
);for q:=firstcount to p-1 do printchar(trickbuf[q mod errorline]);
if m+n>errorline then print(277){:339};incr(nn);end;
end{:334}else if nn=eqtb[27231].int then begin printnl(277);incr(nn);
end;if bottomline then goto 30;decr(baseptr);end;
30:curinput:=inputstack[inputptr];end;
{:333}{345:}procedure begintokenlist(p:halfword;t:quarterword);
begin begin if inputptr>maxinstack then begin maxinstack:=inputptr;
if inputptr=stacksize then overflow(675,stacksize);end;
inputstack[inputptr]:=curinput;incr(inputptr);end;
curinput.statefield:=0;curinput.startfield:=p;curinput.indexfield:=t;
if t>=5 then begin incr(mem[p].hh.lh);
if t=5 then curinput.limitfield:=paramptr else begin curinput.locfield:=
mem[p].hh.rh;if eqtb[27207].int>1 then begin begindiagnostic;
printnl(345);case t of 14:printesc(359);20:printesc(676);
others:printcmdchr(72,t+25053)end;print(637);tokenshow(p);
enddiagnostic(false);end;end;end else curinput.locfield:=p;end;
{:345}{346:}procedure endtokenlist;
begin if curinput.indexfield>=3 then begin if curinput.indexfield<=4
then flushlist(curinput.startfield)else begin deletetokenref(curinput.
startfield);
if curinput.indexfield=5 then while paramptr>curinput.limitfield do
begin decr(paramptr);flushlist(paramstack[paramptr]);end;end;
end else if curinput.indexfield=1 then if alignstate>500000 then
alignstate:=0 else fatalerror(677);begin decr(inputptr);
curinput:=inputstack[inputptr];end;
begin if interrupt<>0 then pauseforinstructions;end;end;
{:346}{347:}procedure backinput;var p:halfword;
begin while(curinput.statefield=0)and(curinput.locfield=-268435455)and(
curinput.indexfield<>2)do endtokenlist;p:=getavail;mem[p].hh.lh:=curtok;
if curtok<768 then if curtok<512 then decr(alignstate)else incr(
alignstate);
begin if inputptr>maxinstack then begin maxinstack:=inputptr;
if inputptr=stacksize then overflow(675,stacksize);end;
inputstack[inputptr]:=curinput;incr(inputptr);end;
curinput.statefield:=0;curinput.startfield:=p;curinput.indexfield:=3;
curinput.locfield:=p;end;{:347}{349:}procedure backerror;
begin OKtointerrupt:=false;backinput;OKtointerrupt:=true;error;end;
procedure inserror;begin OKtointerrupt:=false;backinput;
curinput.indexfield:=4;OKtointerrupt:=true;error;end;
{:349}{350:}procedure beginfilereading;
begin if inopen=maxinopen then overflow(678,maxinopen);
if first=bufsize then overflow(258,bufsize);incr(inopen);
begin if inputptr>maxinstack then begin maxinstack:=inputptr;
if inputptr=stacksize then overflow(675,stacksize);end;
inputstack[inputptr]:=curinput;incr(inputptr);end;
curinput.indexfield:=inopen;sourcefilenamestack[curinput.indexfield]:=0;
fullsourcefilenamestack[curinput.indexfield]:=0;
eofseen[curinput.indexfield]:=false;
grpstack[curinput.indexfield]:=curboundary;
ifstack[curinput.indexfield]:=condptr;
linestack[curinput.indexfield]:=line;curinput.startfield:=first;
curinput.statefield:=1;curinput.namefield:=0;
{1912:}curinput.synctextagfield:=0;{:1912};end;
{:350}{351:}procedure endfilereading;begin first:=curinput.startfield;
line:=linestack[curinput.indexfield];
if(curinput.namefield=18)or(curinput.namefield=19)then pseudoclose else
if curinput.namefield>17 then aclose(inputfile[curinput.indexfield]);
begin decr(inputptr);curinput:=inputstack[inputptr];end;decr(inopen);
end;{:351}{352:}procedure clearforerrorprompt;
begin while(curinput.statefield<>0)and(curinput.namefield=0)and(inputptr
>0)and(curinput.locfield>curinput.limitfield)do endfilereading;println;;
end;{:352}{354:}{1893:}procedure mubyteupdate;var j:poolpointer;
p:halfword;q:halfword;inmutree:integer;begin j:=strstart[strptr];
if mubyteread[strpool[j]]=-268435455 then begin inmutree:=0;p:=getavail;
mubyteread[strpool[j]]:=p;mem[p].hh.b1:=strpool[j];mem[p].hh.b0:=0;
end else begin inmutree:=1;p:=mubyteread[strpool[j]];end;incr(j);
while j<poolptr do begin if inmutree=0 then begin mem[p].hh.rh:=getavail
;p:=mem[p].hh.rh;mem[p].hh.lh:=getavail;p:=mem[p].hh.lh;
mem[p].hh.b1:=strpool[j];mem[p].hh.b0:=0;
end else if(mem[p].hh.b0>0)and(mem[p].hh.b0<64)then begin mem[p].hh.b0:=
mem[p].hh.b0+64;q:=mem[p].hh.rh;mem[p].hh.rh:=getavail;p:=mem[p].hh.rh;
mem[p].hh.lh:=q;mem[p].hh.rh:=getavail;p:=mem[p].hh.rh;
mem[p].hh.lh:=getavail;p:=mem[p].hh.lh;mem[p].hh.b1:=strpool[j];
mem[p].hh.b0:=0;inmutree:=0;
end else begin if mem[p].hh.b0>=64 then p:=mem[p].hh.rh;
repeat p:=mem[p].hh.rh;
if mem[mem[p].hh.lh].hh.b1=strpool[j]then begin p:=mem[p].hh.lh;goto 22;
end;until mem[p].hh.rh=-268435455;mem[p].hh.rh:=getavail;
p:=mem[p].hh.rh;mem[p].hh.lh:=getavail;p:=mem[p].hh.lh;
mem[p].hh.b1:=strpool[j];mem[p].hh.b0:=0;inmutree:=0;end;22:incr(j);end;
if inmutree=1 then begin if mem[p].hh.b0=0 then begin mem[p].hh.b0:=
mubyteprefix+64;q:=mem[p].hh.rh;mem[p].hh.rh:=getavail;p:=mem[p].hh.rh;
mem[p].hh.rh:=q;mem[p].hh.lh:=mubytestoken;goto 10;end;
if mem[p].hh.b0>=64 then begin mem[p].hh.b0:=mubyteprefix+64;
p:=mem[p].hh.rh;mem[p].hh.lh:=mubytestoken;goto 10;end;end;
mem[p].hh.b0:=mubyteprefix;mem[p].hh.rh:=mubytestoken;10:end;
procedure disposemunode(p:halfword);var q:halfword;
begin if(mem[p].hh.b0>0)and(mem[p].hh.b0<64)then begin mem[p].hh.rh:=
avail;avail:=p;ifdef('STAT')decr(dynused);
endif('STAT')end else begin if mem[p].hh.b0>=64 then begin q:=mem[p].hh.
rh;begin mem[p].hh.rh:=avail;avail:=p;ifdef('STAT')decr(dynused);
endif('STAT')end;p:=q;end;q:=mem[p].hh.rh;begin mem[p].hh.rh:=avail;
avail:=p;ifdef('STAT')decr(dynused);endif('STAT')end;p:=q;
while p<>-268435455 do begin disposemunode(mem[p].hh.lh);
q:=mem[p].hh.rh;begin mem[p].hh.rh:=avail;avail:=p;
ifdef('STAT')decr(dynused);endif('STAT')end;p:=q;end;end;end;
procedure disposemutableout(cs:halfword);var p,q,r:halfword;
begin p:=mubytecswrite[cs mod 128];r:=-268435455;
while p<>-268435455 do if mem[p].hh.lh=cs then begin if r<>-268435455
then mem[r].hh.rh:=mem[mem[p].hh.rh].hh.rh else mubytecswrite[cs mod 128
]:=mem[mem[p].hh.rh].hh.rh;q:=mem[mem[p].hh.rh].hh.rh;
begin mem[mem[p].hh.rh].hh.rh:=avail;avail:=mem[p].hh.rh;
ifdef('STAT')decr(dynused);endif('STAT')end;begin mem[p].hh.rh:=avail;
avail:=p;ifdef('STAT')decr(dynused);endif('STAT')end;p:=q;
end else begin r:=mem[p].hh.rh;p:=mem[r].hh.rh;end;end;
{:1893}{:354}{358:}procedure checkoutervalidity;var p:halfword;
q:halfword;begin if scannerstatus<>0 then begin deletionsallowed:=false;
{359:}if curcs<>0 then begin if(curinput.statefield=0)or(curinput.
namefield<1)or(curinput.namefield>17)then begin p:=getavail;
mem[p].hh.lh:=4095+curcs;begintokenlist(p,3);end;curcmd:=10;curchr:=32;
end{:359};if scannerstatus>1 then{360:}begin runaway;
if curcs=0 then begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(686);
end else begin curcs:=0;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(687);
end;end;{361:}p:=getavail;case scannerstatus of 2:begin print(693);
mem[p].hh.lh:=637;end;3:begin print(694);mem[p].hh.lh:=partoken;
longstate:=115;end;4:begin print(695);mem[p].hh.lh:=637;q:=p;
p:=getavail;mem[p].hh.rh:=q;mem[p].hh.lh:=19610;alignstate:=-1000000;
end;5:begin print(696);mem[p].hh.lh:=637;end;end;
begintokenlist(p,4){:361};print(688);sprintcs(warningindex);
begin helpptr:=4;helpline[3]:=689;helpline[2]:=690;helpline[1]:=691;
helpline[0]:=692;end;error;
end{:360}else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(680);
end;printcmdchr(107,curif);print(681);printint(skipline);
begin helpptr:=3;helpline[2]:=682;helpline[1]:=683;helpline[0]:=684;end;
if curcs<>0 then curcs:=0 else helpline[2]:=685;curtok:=19613;inserror;
end;deletionsallowed:=true;end;end;{:358}{362:}procedure firmuptheline;
forward;{:362}{363:}procedure getnext;label 20,25,21,26,40,10;
var k:0..bufsize;t:halfword;i,j:0..bufsize;mubyteincs:boolean;
p:halfword;cat:0..15;c,cc:ASCIIcode;d:2..3;begin 20:curcs:=0;
if curinput.statefield<>0 then{365:}begin 25:if curinput.locfield<=
curinput.limitfield then begin k:=curinput.locfield;
curchr:=readbuffer(k);curinput.locfield:=k;incr(curinput.locfield);
if(mubytetoken>0)then begin curinput.statefield:=1;
curcs:=mubytetoken-4095;goto 40;end;21:curcmd:=eqtb[25641+curchr].hh.rh;
{366:}case curinput.statefield+curcmd of{367:}10,26,42,27,43{:367}:goto
25;
1,17,33:{376:}begin if curinput.locfield>curinput.limitfield then curcs
:=513 else begin 26:mubyteincs:=false;k:=curinput.locfield;
mubyteskeep:=mubytekeep;curchr:=readbuffer(k);
cat:=eqtb[25641+curchr].hh.rh;
if(eqtb[27235].int>0)and(not mubyteincs)and((mubyteskip>0)or(curchr<>
buffer[k]))then mubyteincs:=true;incr(k);
if mubytetoken>0 then begin curinput.statefield:=1;
curcs:=mubytetoken-4095;goto 40;end;
if cat=11 then curinput.statefield:=17 else if cat=10 then curinput.
statefield:=17 else curinput.statefield:=1;
if(cat=11)and(k<=curinput.limitfield)then{378:}begin repeat curchr:=
readbuffer(k);cat:=eqtb[25641+curchr].hh.rh;
if mubytetoken>0 then cat:=0;
if(eqtb[27235].int>0)and(not mubyteincs)and(cat=11)and((mubyteskip>0)or(
curchr<>buffer[k]))then mubyteincs:=true;incr(k);
until(cat<>11)or(k>curinput.limitfield);
{377:}begin if buffer[k]=curchr then if cat=7 then if k<curinput.
limitfield then begin c:=buffer[k+1];if c<128 then begin d:=2;
if(((c>=48)and(c<=57))or((c>=97)and(c<=102)))then if k+2<=curinput.
limitfield then begin cc:=buffer[k+2];
if(((cc>=48)and(cc<=57))or((cc>=97)and(cc<=102)))then incr(d);end;
if d>2 then begin if c<=57 then curchr:=c-48 else curchr:=c-87;
if cc<=57 then curchr:=16*curchr+cc-48 else curchr:=16*curchr+cc-87;
buffer[k-1]:=curchr;
end else if c<64 then buffer[k-1]:=c+64 else buffer[k-1]:=c-64;
curinput.limitfield:=curinput.limitfield-d;first:=first-d;
if eqtb[27235].int>0 then mubytekeep:=k-curinput.locfield;
while k<=curinput.limitfield do begin buffer[k]:=buffer[k+d];incr(k);
end;goto 26;end;end;end{:377};if cat<>11 then begin decr(k);
k:=k-mubyteskip;end;
if k>curinput.locfield+1 then begin if mubyteincs then begin i:=curinput
.locfield;j:=first;mubytekeep:=mubyteskeep;
if j-curinput.locfield+k>maxbufstack then begin maxbufstack:=j-curinput.
locfield+k;if maxbufstack>=bufsize then begin maxbufstack:=bufsize;
overflow(258,bufsize);end;end;
while i<k do begin buffer[j]:=readbuffer(i);incr(i);incr(j);end;
if j=first+1 then curcs:=257+buffer[first]else curcs:=idlookup(first,j-
first);end else curcs:=idlookup(curinput.locfield,k-curinput.locfield);
curinput.locfield:=k;goto 40;end;
end{:378}else{377:}begin if buffer[k]=curchr then if cat=7 then if k<
curinput.limitfield then begin c:=buffer[k+1];if c<128 then begin d:=2;
if(((c>=48)and(c<=57))or((c>=97)and(c<=102)))then if k+2<=curinput.
limitfield then begin cc:=buffer[k+2];
if(((cc>=48)and(cc<=57))or((cc>=97)and(cc<=102)))then incr(d);end;
if d>2 then begin if c<=57 then curchr:=c-48 else curchr:=c-87;
if cc<=57 then curchr:=16*curchr+cc-48 else curchr:=16*curchr+cc-87;
buffer[k-1]:=curchr;
end else if c<64 then buffer[k-1]:=c+64 else buffer[k-1]:=c-64;
curinput.limitfield:=curinput.limitfield-d;first:=first-d;
if eqtb[27235].int>0 then mubytekeep:=k-curinput.locfield;
while k<=curinput.limitfield do begin buffer[k]:=buffer[k+d];incr(k);
end;goto 26;end;end;end{:377};mubytekeep:=mubyteskeep;
curcs:=257+readbuffer(curinput.locfield);incr(curinput.locfield);end;
40:curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;
if curcmd>=115 then checkoutervalidity;
if writenoexpanding then begin p:=mubytecswrite[curcs mod 128];
while p<>-268435455 do if mem[p].hh.lh=curcs then begin curcmd:=0;
curchr:=256;p:=-268435455;end else p:=mem[mem[p].hh.rh].hh.rh;end;
end{:376};14,30,46:{375:}begin curcs:=curchr+1;
curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;
curinput.statefield:=1;if curcmd>=115 then checkoutervalidity;end{:375};
8,24,40:{374:}begin if curchr=buffer[curinput.locfield]then if curinput.
locfield<curinput.limitfield then begin c:=buffer[curinput.locfield+1];
if c<128 then begin curinput.locfield:=curinput.locfield+2;
if(((c>=48)and(c<=57))or((c>=97)and(c<=102)))then if curinput.locfield<=
curinput.limitfield then begin cc:=buffer[curinput.locfield];
if(((cc>=48)and(cc<=57))or((cc>=97)and(cc<=102)))then begin incr(
curinput.locfield);if c<=57 then curchr:=c-48 else curchr:=c-87;
if cc<=57 then curchr:=16*curchr+cc-48 else curchr:=16*curchr+cc-87;
goto 21;end;end;if c<64 then curchr:=c+64 else curchr:=c-64;goto 21;end;
end;curinput.statefield:=1;end{:374};
16,32,48:{368:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(697);
end;begin helpptr:=2;helpline[1]:=698;helpline[0]:=699;end;
deletionsallowed:=false;error;deletionsallowed:=true;goto 20;end{:368};
{369:}11:{371:}begin curinput.statefield:=17;curchr:=32;end{:371};
6:{370:}begin curinput.locfield:=curinput.limitfield+1;curcmd:=10;
curchr:=32;end{:370};
22,15,31,47:{372:}begin curinput.locfield:=curinput.limitfield+1;
goto 25;end{:372};
38:{373:}begin curinput.locfield:=curinput.limitfield+1;curcs:=parloc;
curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;
if curcmd>=115 then checkoutervalidity;end{:373};2:incr(alignstate);
18,34:begin curinput.statefield:=1;incr(alignstate);end;
3:decr(alignstate);19,35:begin curinput.statefield:=1;decr(alignstate);
end;20,21,23,25,28,29,36,37,39,41,44,45:curinput.statefield:=1;
{:369}others:end{:366};end else begin curinput.statefield:=33;
{382:}if curinput.namefield>17 then{384:}begin incr(line);
first:=curinput.startfield;
if not forceeof then if curinput.namefield<=19 then begin if pseudoinput
then firmuptheline else if(eqtb[25072].hh.rh<>-268435455)and not eofseen
[curinput.indexfield]then begin curinput.limitfield:=first-1;
eofseen[curinput.indexfield]:=true;begintokenlist(eqtb[25072].hh.rh,19);
goto 20;end else forceeof:=true;
end else begin if inputln(inputfile[curinput.indexfield],true)then
firmuptheline else if(eqtb[25072].hh.rh<>-268435455)and not eofseen[
curinput.indexfield]then begin curinput.limitfield:=first-1;
eofseen[curinput.indexfield]:=true;begintokenlist(eqtb[25072].hh.rh,19);
goto 20;end else forceeof:=true;end;
if forceeof then begin if eqtb[27274].int>0 then if(grpstack[inopen]<>
curboundary)or(ifstack[inopen]<>condptr)then filewarning;
if curinput.namefield>=19 then begin printchar(41);decr(openparens);
fflush(stdout);end;forceeof:=false;endfilereading;checkoutervalidity;
goto 20;end;
if(eqtb[27225].int<0)or(eqtb[27225].int>255)then decr(curinput.
limitfield)else buffer[curinput.limitfield]:=eqtb[27225].int;
first:=curinput.limitfield+1;curinput.locfield:=curinput.startfield;
end{:384}else begin if not(curinput.namefield=0)then begin curcmd:=0;
curchr:=0;goto 10;end;if inputptr>0 then begin endfilereading;goto 20;
end;if selector<18 then openlogfile;
if interaction>1 then begin if(eqtb[27225].int<0)or(eqtb[27225].int>255)
then incr(curinput.limitfield);
if curinput.limitfield=curinput.startfield then printnl(700);println;
first:=curinput.startfield;begin;print(42);terminput;end;
curinput.limitfield:=last;
if(eqtb[27225].int<0)or(eqtb[27225].int>255)then decr(curinput.
limitfield)else buffer[curinput.limitfield]:=eqtb[27225].int;
first:=curinput.limitfield+1;curinput.locfield:=curinput.startfield;
end else fatalerror(701);end{:382};
begin if interrupt<>0 then pauseforinstructions;end;goto 25;end;
end{:365}else{379:}if curinput.locfield<>-268435455 then begin t:=mem[
curinput.locfield].hh.lh;
curinput.locfield:=mem[curinput.locfield].hh.rh;
if t>=4095 then begin curcs:=t-4095;curcmd:=eqtb[curcs].hh.b0;
curchr:=eqtb[curcs].hh.rh;
if curcmd>=115 then if curcmd=118 then{380:}begin curcs:=mem[curinput.
locfield].hh.lh-4095;curinput.locfield:=-268435455;
curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;
if curcmd>102 then begin curcmd:=0;curchr:=257;end;
end{:380}else checkoutervalidity;
if writenoexpanding then begin p:=mubytecswrite[curcs mod 128];
while p<>-268435455 do if mem[p].hh.lh=curcs then begin curcmd:=0;
curchr:=256;p:=-268435455;end else p:=mem[mem[p].hh.rh].hh.rh;end;
end else begin curcmd:=t div 256;curchr:=t mod 256;
case curcmd of 1:incr(alignstate);2:decr(alignstate);
5:{381:}begin begintokenlist(paramstack[curinput.limitfield+curchr-1],0)
;goto 20;end{:381};others:end;end;end else begin endtokenlist;goto 20;
end{:379};
{364:}if curcmd<=5 then if curcmd>=4 then if alignstate=0 then{966:}
begin if(scannerstatus=4)or(curalign=-268435455)then fatalerror(677);
curcmd:=mem[curalign+5].hh.lh;mem[curalign+5].hh.lh:=curchr;
if curcmd=63 then begintokenlist(memtop-10,2)else begintokenlist(mem[
curalign+2].int,2);alignstate:=1000000;goto 20;end{:966}{:364};10:end;
{:363}{385:}procedure firmuptheline;var k:0..bufsize;
begin curinput.limitfield:=last;
if eqtb[27205].int>0 then if interaction>1 then begin;println;
k:=curinput.startfield;
while k<curinput.limitfield do begin printbuffer(k)end;
first:=curinput.limitfield;begin;print(702);terminput;end;
if last>first then begin for k:=first to last-1 do buffer[k+curinput.
startfield-first]:=buffer[k];
curinput.limitfield:=curinput.startfield+last-first;end;end;end;
{:385}{387:}procedure gettoken;begin nonewcontrolsequence:=false;
getnext;nonewcontrolsequence:=true;
if curcs=0 then curtok:=(curcmd*256)+curchr else curtok:=4095+curcs;end;
{:387}{391:}{418:}procedure macrocall;label 10,22,30,31,40;
var r:halfword;p:halfword;q:halfword;s:halfword;t:halfword;u,v:halfword;
rbraceptr:halfword;n:smallnumber;unbalance:halfword;m:halfword;
refcount:halfword;savescannerstatus:smallnumber;
savewarningindex:halfword;matchchr:ASCIIcode;
begin savescannerstatus:=scannerstatus;savewarningindex:=warningindex;
warningindex:=curcs;refcount:=curchr;r:=mem[refcount].hh.rh;n:=0;
if eqtb[27207].int>0 then{430:}begin begindiagnostic;println;
printcs(warningindex);tokenshow(refcount);enddiagnostic(false);
end{:430};if mem[r].hh.lh=3585 then r:=mem[r].hh.rh;
if mem[r].hh.lh<>3584 then{420:}begin scannerstatus:=3;unbalance:=0;
longstate:=eqtb[curcs].hh.b0;
if longstate>=115 then longstate:=longstate-2;
repeat mem[memtop-3].hh.rh:=-268435455;
if(mem[r].hh.lh>3583)or(mem[r].hh.lh<3328)then s:=-268435455 else begin
matchchr:=mem[r].hh.lh-3328;s:=mem[r].hh.rh;r:=s;p:=memtop-3;m:=0;end;
{421:}22:gettoken;
if curtok=mem[r].hh.lh then{423:}begin r:=mem[r].hh.rh;
if(mem[r].hh.lh>=3328)and(mem[r].hh.lh<=3584)then begin if curtok<512
then decr(alignstate);goto 40;end else goto 22;end{:423};
{426:}if s<>r then if s=-268435455 then{427:}begin begin if interaction=
3 then;if filelineerrorstylep then printfileline else printnl(264);
print(738);end;sprintcs(warningindex);print(739);begin helpptr:=4;
helpline[3]:=740;helpline[2]:=741;helpline[1]:=742;helpline[0]:=743;end;
error;goto 10;end{:427}else begin t:=s;repeat begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=mem[t].hh.lh;p:=q;end;incr(m);
u:=mem[t].hh.rh;v:=s;
while true do begin if u=r then if curtok<>mem[v].hh.lh then goto 30
else begin r:=mem[v].hh.rh;goto 22;end;
if mem[u].hh.lh<>mem[v].hh.lh then goto 30;u:=mem[u].hh.rh;
v:=mem[v].hh.rh;end;30:t:=mem[t].hh.rh;until t=r;r:=s;end{:426};
if curtok=partoken then if longstate<>114 then{425:}begin if longstate=
113 then begin runaway;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(733);
end;sprintcs(warningindex);print(734);begin helpptr:=3;helpline[2]:=735;
helpline[1]:=736;helpline[0]:=737;end;backerror;end;
pstack[n]:=mem[memtop-3].hh.rh;alignstate:=alignstate-unbalance;
for m:=0 to n do flushlist(pstack[m]);goto 10;end{:425};
if curtok<768 then if curtok<512 then{428:}begin unbalance:=1;
while true do begin begin begin q:=avail;
if q=-268435455 then q:=getavail else begin avail:=mem[q].hh.rh;
mem[q].hh.rh:=-268435455;ifdef('STAT')incr(dynused);endif('STAT')end;
end;mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;gettoken;
if curtok=partoken then if longstate<>114 then{425:}begin if longstate=
113 then begin runaway;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(733);
end;sprintcs(warningindex);print(734);begin helpptr:=3;helpline[2]:=735;
helpline[1]:=736;helpline[0]:=737;end;backerror;end;
pstack[n]:=mem[memtop-3].hh.rh;alignstate:=alignstate-unbalance;
for m:=0 to n do flushlist(pstack[m]);goto 10;end{:425};
if curtok<768 then if curtok<512 then incr(unbalance)else begin decr(
unbalance);if unbalance=0 then goto 31;end;end;31:rbraceptr:=p;
begin q:=getavail;mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;
end{:428}else{424:}begin backinput;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(725);
end;sprintcs(warningindex);print(726);begin helpptr:=6;helpline[5]:=727;
helpline[4]:=728;helpline[3]:=729;helpline[2]:=730;helpline[1]:=731;
helpline[0]:=732;end;incr(alignstate);longstate:=113;curtok:=partoken;
inserror;goto 22;
end{:424}else{422:}begin if curtok=2592 then if mem[r].hh.lh<=3584 then
if mem[r].hh.lh>=3328 then goto 22;begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=curtok;p:=q;end;end{:422};incr(m);
if mem[r].hh.lh>3584 then goto 22;if mem[r].hh.lh<3328 then goto 22;
40:if s<>-268435455 then{429:}begin if(m=1)and(mem[p].hh.lh<768)and(p<>
memtop-3)then begin mem[rbraceptr].hh.rh:=-268435455;
begin mem[p].hh.rh:=avail;avail:=p;ifdef('STAT')decr(dynused);
endif('STAT')end;p:=mem[memtop-3].hh.rh;pstack[n]:=mem[p].hh.rh;
begin mem[p].hh.rh:=avail;avail:=p;ifdef('STAT')decr(dynused);
endif('STAT')end;end else pstack[n]:=mem[memtop-3].hh.rh;incr(n);
if eqtb[27207].int>0 then begin begindiagnostic;printnl(matchchr);
printint(n);print(744);showtokenlist(pstack[n-1],-268435455,1000);
enddiagnostic(false);end;end{:429}{:421};until mem[r].hh.lh=3584;
end{:420};
{419:}while(curinput.statefield=0)and(curinput.locfield=-268435455)and(
curinput.indexfield<>2)do endtokenlist;begintokenlist(refcount,5);
curinput.namefield:=warningindex;curinput.locfield:=mem[r].hh.rh;
if n>0 then begin if paramptr+n>maxparamstack then begin maxparamstack:=
paramptr+n;if maxparamstack>paramsize then overflow(724,paramsize);end;
for m:=0 to n-1 do paramstack[paramptr+m]:=pstack[m];
paramptr:=paramptr+n;end{:419};10:scannerstatus:=savescannerstatus;
warningindex:=savewarningindex;end;{:418}{408:}procedure insertrelax;
begin curtok:=4095+curcs;backinput;curtok:=19616;backinput;
curinput.indexfield:=4;end;{:408}{1750:}procedure pseudostart;forward;
{:1750}{1808:}procedure scanregisternum;forward;
{:1808}{1813:}procedure newindex(i:quarterword;q:halfword);
var k:smallnumber;begin curptr:=getnode(9);mem[curptr].hh.b0:=i;
mem[curptr].hh.b1:=0;mem[curptr].hh.rh:=q;
for k:=1 to 8 do mem[curptr+k]:=sanull;end;
{:1813}{1817:}procedure findsaelement(t:smallnumber;n:halfword;
w:boolean);label 45,46,47,48,49,10;var q:halfword;i:smallnumber;
begin curptr:=saroot[t];
begin if curptr=-268435455 then if w then goto 45 else goto 10;end;
q:=curptr;i:=n div 4096;
if odd(i)then curptr:=mem[q+(i div 2)+1].hh.rh else curptr:=mem[q+(i div
2)+1].hh.lh;
begin if curptr=-268435455 then if w then goto 46 else goto 10;end;
q:=curptr;i:=(n div 256)mod 16;
if odd(i)then curptr:=mem[q+(i div 2)+1].hh.rh else curptr:=mem[q+(i div
2)+1].hh.lh;
begin if curptr=-268435455 then if w then goto 47 else goto 10;end;
q:=curptr;i:=(n div 16)mod 16;
if odd(i)then curptr:=mem[q+(i div 2)+1].hh.rh else curptr:=mem[q+(i div
2)+1].hh.lh;
begin if curptr=-268435455 then if w then goto 48 else goto 10;end;
q:=curptr;i:=n mod 16;
if odd(i)then curptr:=mem[q+(i div 2)+1].hh.rh else curptr:=mem[q+(i div
2)+1].hh.lh;if(curptr=-268435455)and w then goto 49;goto 10;
45:newindex(t,-268435455);saroot[t]:=curptr;q:=curptr;i:=n div 4096;
46:newindex(i,q);
begin if odd(i)then mem[q+(i div 2)+1].hh.rh:=curptr else mem[q+(i div 2
)+1].hh.lh:=curptr;incr(mem[q].hh.b1);end;q:=curptr;
i:=(n div 256)mod 16;47:newindex(i,q);
begin if odd(i)then mem[q+(i div 2)+1].hh.rh:=curptr else mem[q+(i div 2
)+1].hh.lh:=curptr;incr(mem[q].hh.b1);end;q:=curptr;i:=(n div 16)mod 16;
48:newindex(i,q);
begin if odd(i)then mem[q+(i div 2)+1].hh.rh:=curptr else mem[q+(i div 2
)+1].hh.lh:=curptr;incr(mem[q].hh.b1);end;q:=curptr;i:=n mod 16;
49:{1818:}if t=6 then begin curptr:=getnode(4);mem[curptr+1]:=sanull;
mem[curptr+2]:=sanull;mem[curptr+3]:=sanull;
end else begin if t<=1 then begin curptr:=getnode(3);
mem[curptr+2].int:=0;mem[curptr+1].hh.rh:=n;
end else begin curptr:=getnode(2);
if t<=3 then begin mem[curptr+1].hh.rh:=membot;incr(mem[membot].hh.rh);
end else mem[curptr+1].hh.rh:=-268435455;end;
mem[curptr+1].hh.lh:=-268435455;end;mem[curptr].hh.b0:=16*t+i;
mem[curptr].hh.b1:=1{:1818};mem[curptr].hh.rh:=q;
begin if odd(i)then mem[q+(i div 2)+1].hh.rh:=curptr else mem[q+(i div 2
)+1].hh.lh:=curptr;incr(mem[q].hh.b1);end;10:end;
{:1817}procedure passtext;forward;procedure startinput;forward;
procedure conditional;forward;procedure getxtoken;forward;
procedure convtoks;forward;procedure insthetoks;forward;
procedure expand;label 21;var t:halfword;b:boolean;p,q,r:halfword;
j:0..bufsize;cvbackup:integer;
cvlbackup,radixbackup,cobackup:smallnumber;backupbackup:halfword;
savescannerstatus:smallnumber;begin incr(expanddepthcount);
if expanddepthcount>=expanddepth then overflow(703,expanddepth);
cvbackup:=curval;cvlbackup:=curvallevel;radixbackup:=radix;
cobackup:=curorder;backupbackup:=mem[memtop-13].hh.rh;
21:if curcmd<113 then{394:}begin if eqtb[27213].int>1 then showcurcmdchr
;case curcmd of 112:{415:}begin t:=curchr mod 5;
if curchr>=5 then scanregisternum else curval:=0;
if curval=0 then curptr:=curmark[t]else{1822:}begin findsaelement(6,
curval,false);
if curptr<>-268435455 then if odd(t)then curptr:=mem[curptr+(t div 2)+1]
.hh.rh else curptr:=mem[curptr+(t div 2)+1].hh.lh;end{:1822};
if curptr<>-268435455 then begintokenlist(curptr,14);end{:415};
104:if curchr=0 then{395:}begin gettoken;t:=curtok;gettoken;
if curcmd>102 then expand else backinput;curtok:=t;backinput;
end{:395}else{1763:}begin gettoken;
if(curcmd=107)and(curchr<>16)then begin curchr:=curchr+32;goto 21;end;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(787);
end;printesc(928);print(2031);printcmdchr(curcmd,curchr);printchar(39);
begin helpptr:=1;helpline[0]:=699;end;backerror;end{:1763};
105:if curchr=0 then{396:}begin savescannerstatus:=scannerstatus;
scannerstatus:=0;gettoken;scannerstatus:=savescannerstatus;t:=curtok;
backinput;if t>=4095 then begin p:=getavail;mem[p].hh.lh:=19618;
mem[p].hh.rh:=curinput.locfield;curinput.startfield:=p;
curinput.locfield:=p;end;
end{:396}else{397:}begin savescannerstatus:=scannerstatus;
scannerstatus:=0;gettoken;scannerstatus:=savescannerstatus;
if curcs<514 then curcs:=primlookup(curcs-257)else curcs:=primlookup(
hash[curcs].rh);if curcs<>0 then begin t:=primeqtb[curcs].hh.b0;
if t>102 then begin curcmd:=t;curchr:=primeqtb[curcs].hh.rh;
curtok:=(curcmd*256)+curchr;curcs:=0;goto 21;end else begin backinput;
p:=getavail;mem[p].hh.lh:=19620;mem[p].hh.rh:=curinput.locfield;
curinput.locfield:=p;curinput.startfield:=p;end;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(704);
end;begin helpptr:=2;helpline[1]:=705;helpline[0]:=706;end;backerror;
end;end{:397};109:{401:}begin r:=getavail;p:=r;b:=isincsname;
isincsname:=true;repeat getxtoken;if curcs=0 then begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;until curcs<>0;
if(curcmd<>67)or(curchr<>0)then{402:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(713);
end;printesc(579);print(714);begin helpptr:=2;helpline[1]:=715;
helpline[0]:=716;end;backerror;end{:402};isincsname:=b;{403:}j:=first;
p:=mem[r].hh.rh;
while p<>-268435455 do begin if j>=maxbufstack then begin maxbufstack:=j
+1;if maxbufstack=bufsize then overflow(258,bufsize);end;
buffer[j]:=mem[p].hh.lh mod 256;incr(j);p:=mem[p].hh.rh;end;
if j>first+1 then begin nonewcontrolsequence:=false;
curcs:=idlookup(first,j-first);nonewcontrolsequence:=true;
end else if j=first then curcs:=513 else curcs:=257+buffer[first]{:403};
flushlist(r);if eqtb[curcs].hh.b0=103 then begin eqdefine(curcs,0,256);
end;curtok:=curcs+4095;backinput;end{:401};110:convtoks;111:insthetoks;
107:conditional;
108:{539:}begin if eqtb[27272].int>0 then if eqtb[27213].int<=1 then
showcurcmdchr;
if curchr>iflimit then if iflimit=1 then insertrelax else begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(932);
end;printcmdchr(108,curchr);begin helpptr:=1;helpline[0]:=933;end;error;
end else begin while curchr<>2 do passtext;
{525:}begin if ifstack[inopen]=condptr then ifwarning;p:=condptr;
ifline:=mem[p+1].int;curif:=mem[p].hh.b1;iflimit:=mem[p].hh.b0;
condptr:=mem[p].hh.rh;freenode(p,2);end{:525};end;end{:539};
106:{407:}if curchr=1 then forceeof:=true{1747:}else if curchr=2 then
pseudostart{:1747}else if nameinprogress then insertrelax else
startinput{:407};others:{399:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(707);
end;begin helpptr:=5;helpline[4]:=708;helpline[3]:=709;helpline[2]:=710;
helpline[1]:=711;helpline[0]:=712;end;error;end{:399}end;
end{:394}else if curcmd<117 then macrocall else{404:}begin curtok:=19615
;backinput;end{:404};curval:=cvbackup;curvallevel:=cvlbackup;
radix:=radixbackup;curorder:=cobackup;
mem[memtop-13].hh.rh:=backupbackup;decr(expanddepthcount);end;
{:391}{409:}procedure getxtoken;label 20,30;begin 20:getnext;
if curcmd<=102 then goto 30;
if curcmd>=113 then if curcmd<117 then macrocall else begin curcs:=15520
;curcmd:=9;goto 30;end else expand;goto 20;
30:if curcs=0 then curtok:=(curcmd*256)+curchr else curtok:=4095+curcs;
end;{:409}{410:}procedure xtoken;begin while curcmd>102 do begin expand;
getnext;end;
if curcs=0 then curtok:=(curcmd*256)+curchr else curtok:=4095+curcs;end;
{:410}{432:}procedure scanleftbrace;begin{433:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:433};
if curcmd<>1 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(745);
end;begin helpptr:=4;helpline[3]:=746;helpline[2]:=747;helpline[1]:=748;
helpline[0]:=749;end;backerror;curtok:=379;curcmd:=1;curchr:=123;
incr(alignstate);end;end;{:432}{434:}procedure scanoptionalequals;
begin{435:}repeat getxtoken;until curcmd<>10{:435};
if curtok<>3133 then backinput;end;
{:434}{436:}function scankeyword(s:strnumber):boolean;label 10;
var p:halfword;q:halfword;k:poolpointer;savecurcs:halfword;
begin p:=memtop-13;mem[p].hh.rh:=-268435455;k:=strstart[s];
savecurcs:=curcs;while k<strstart[s+1]do begin getxtoken;
if(curcs=0)and((curchr=strpool[k])or(curchr=strpool[k]-32))then begin
begin q:=getavail;mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;incr(k);
end else if(curcmd<>10)or(p<>memtop-13)then begin backinput;
if p<>memtop-13 then begintokenlist(mem[memtop-13].hh.rh,3);
curcs:=savecurcs;scankeyword:=false;goto 10;end;end;
flushlist(mem[memtop-13].hh.rh);scankeyword:=true;10:end;
{:436}{437:}procedure muerror;begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(750);
end;begin helpptr:=1;helpline[0]:=751;end;error;end;
{:437}{438:}procedure scanint;forward;{462:}procedure scaneightbitint;
begin scanint;
if(curval<0)or(curval>255)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(789);
end;begin helpptr:=2;helpline[1]:=790;helpline[0]:=791;end;
interror(curval);curval:=0;end;end;{:462}{463:}procedure scancharnum;
begin scanint;
if(curval<0)or(curval>255)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(792);
end;begin helpptr:=2;helpline[1]:=793;helpline[0]:=791;end;
interror(curval);curval:=0;end;end;{:463}{464:}procedure scanfourbitint;
begin scanint;
if(curval<0)or(curval>15)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(794);
end;begin helpptr:=2;helpline[1]:=795;helpline[0]:=791;end;
interror(curval);curval:=0;end;end;
{:464}{465:}procedure scanfifteenbitint;begin scanint;
if(curval<0)or(curval>32767)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(796);
end;begin helpptr:=2;helpline[1]:=797;helpline[0]:=791;end;
interror(curval);curval:=0;end;end;
{:465}{466:}procedure scantwentysevenbitint;begin scanint;
if(curval<0)or(curval>134217727)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(798);
end;begin helpptr:=2;helpline[1]:=799;helpline[0]:=791;end;
interror(curval);curval:=0;end;end;
{:466}{1809:}procedure scanregisternum;begin scanint;
if(curval<0)or(curval>maxregnum)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(789);
end;begin helpptr:=2;helpline[1]:=maxreghelpline;helpline[0]:=791;end;
interror(curval);curval:=0;end;end;
{:1809}{1871:}procedure scanfourbitintor18;begin scanint;
if(curval<0)or((curval>15)and(curval<>18))then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(794);
end;begin helpptr:=2;helpline[1]:=795;helpline[0]:=791;end;
interror(curval);curval:=0;end;end;
{:1871}{1680:}procedure scangeneraltext;forward;
{:1680}{1770:}procedure getxorprotected;label 10;
begin while true do begin gettoken;if curcmd<=102 then goto 10;
if(curcmd>=113)and(curcmd<117)then if mem[mem[curchr].hh.rh].hh.lh=3585
then goto 10;expand;end;10:end;{:1770}{1779:}procedure scanexpr;forward;
{:1779}{1784:}procedure scannormalglue;forward;procedure scanmuglue;
forward;{:1784}{1879:}function effectivechar(errp:boolean;
f:internalfontnumber;c:quarterword):integer;label 40;var basec:integer;
result:integer;begin result:=c;if not mltexenabledp then goto 40;
if fontec[f]>=c then if fontbc[f]<=c then if(fontinfo[charbase[f]+c].
qqqq.b0>0)then goto 40;
if c>=eqtb[27232].int then if c<=eqtb[27233].int then if(eqtb[26921+c].
hh.rh>0)then begin basec:=(eqtb[26921+c].hh.rh mod 256);result:=basec;
if not errp then goto 40;
if fontec[f]>=basec then if fontbc[f]<=basec then if(fontinfo[charbase[f
]+basec].qqqq.b0>0)then goto 40;end;if errp then begin begindiagnostic;
printnl(983);print(2064);print(c);print(984);slowprint(fontname[f]);
printchar(33);enddiagnostic(false);result:=fontbc[f];end;
40:effectivechar:=result;end;
{:1879}{607:}function testnoligatures(f:internalfontnumber):integer;
label 10;var c:integer;begin testnoligatures:=1;
for c:=fontbc[f]to fontec[f]do if(fontinfo[charbase[f]+c].qqqq.b0>0)then
if odd(((fontinfo[charbase[f]+c].qqqq.b2)mod 4))then begin
testnoligatures:=0;goto 10;end;10:end;
function gettagcode(f:internalfontnumber;c:eightbits):integer;
var i:smallnumber;
begin if((fontbc[f]<=c)and(c<=fontec[f])and(fontinfo[charbase[f]+c].qqqq
.b0>0))then begin i:=((fontinfo[charbase[f]+c].qqqq.b2)mod 4);
if i=1 then gettagcode:=1 else if i=2 then gettagcode:=2 else if i=3
then gettagcode:=4 else gettagcode:=0;end else gettagcode:=-1;end;
procedure scanfontident;var f:internalfontnumber;m:halfword;
begin{435:}repeat getxtoken;until curcmd<>10{:435};
if(curcmd=88)or(curcmd=101)or(curcmd=102)then f:=eqtb[25589].hh.rh else
if curcmd=87 then f:=curchr else if curcmd=86 then begin m:=curchr;
scanfourbitint;f:=eqtb[m+curval].hh.rh;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(975);
end;begin helpptr:=2;helpline[1]:=976;helpline[0]:=977;end;backerror;
f:=0;end;curval:=f;end;
{:607}{608:}procedure findfontdimen(writing:boolean);
var f:internalfontnumber;n:integer;begin scanint;n:=curval;
scanfontident;f:=curval;
if n<=0 then curval:=fmemptr else begin if writing and(n<=4)and(n>=2)and
(fontglue[f]<>-268435455)then begin deleteglueref(fontglue[f]);
fontglue[f]:=-268435455;end;
if n>fontparams[f]then if f<fontptr then curval:=fmemptr else{610:}begin
repeat if fmemptr=fontmemsize then overflow(982,fontmemsize);
fontinfo[fmemptr].int:=0;incr(fmemptr);incr(fontparams[f]);
until n=fontparams[f];curval:=fmemptr-1;
end{:610}else curval:=n+parambase[f];end;
{609:}if curval=fmemptr then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(957);
end;printesc(hash[15526+f].rh);print(978);printint(fontparams[f]);
print(979);begin helpptr:=2;helpline[1]:=980;helpline[0]:=981;end;error;
end{:609};end;
{:608}{:438}{442:}procedure scansomethinginternal(level:smallnumber;
negative:boolean);label 10,20;var m:halfword;n,k:integer;q,r:halfword;
tx:halfword;i:fourquarters;p:0..nestsize;begin 20:m:=curchr;
case curcmd of 85:{443:}begin scancharnum;
if m=25590 then begin curval:=xord[curval];curvallevel:=0;
end else if m=25591 then begin curval:=xchr[curval];curvallevel:=0;
end else if m=25592 then begin curval:=xprn[curval];curvallevel:=0;
end else if m=26665 then begin curval:=eqtb[26665+curval].hh.rh;
curvallevel:=0;
end else if m<26665 then begin curval:=eqtb[m+curval].hh.rh;
curvallevel:=0;end else begin curval:=eqtb[m+curval].int;curvallevel:=0;
end;end{:443};
71,72,86,87,88,101,102:{444:}if level<>5 then begin begin if interaction
=3 then;if filelineerrorstylep then printfileline else printnl(264);
print(752);end;begin helpptr:=3;helpline[2]:=753;helpline[1]:=754;
helpline[0]:=755;end;backerror;begin curval:=0;curvallevel:=1;end;
end else if curcmd<=72 then begin if curcmd<72 then if m=membot then
begin scanregisternum;
if curval<256 then curval:=eqtb[25073+curval].hh.rh else begin
findsaelement(5,curval,false);
if curptr=-268435455 then curval:=-268435455 else curval:=mem[curptr+1].
hh.rh;end;end else curval:=mem[m+1].hh.rh else curval:=eqtb[m].hh.rh;
curvallevel:=5;end else begin backinput;scanfontident;
begin curval:=15526+curval;curvallevel:=4;end;end{:444};
73:begin curval:=eqtb[m].int;curvallevel:=0;end;
74:begin curval:=eqtb[m].int;curvallevel:=1;end;
75:begin curval:=eqtb[m].hh.rh;curvallevel:=2;end;
76:begin curval:=eqtb[m].hh.rh;curvallevel:=3;end;
79:{447:}if abs(curlist.modefield)<>m then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(264);
print(782);end;printcmdchr(79,m);begin helpptr:=4;helpline[3]:=783;
helpline[2]:=784;helpline[1]:=785;helpline[0]:=786;end;error;
if level<>5 then begin curval:=0;curvallevel:=1;
end else begin curval:=0;curvallevel:=0;end;
end else if m=1 then begin curval:=curlist.auxfield.int;curvallevel:=1;
end else begin curval:=curlist.auxfield.hh.lh;curvallevel:=0;end{:447};
80:{451:}if curlist.modefield=0 then begin curval:=0;curvallevel:=0;
end else begin nest[nestptr]:=curlist;p:=nestptr;
while abs(nest[p].modefield)<>1 do decr(p);
begin curval:=nest[p].pgfield;curvallevel:=0;end;end{:451};
82:{448:}begin if m=0 then curval:=deadcycles{1692:}else if m=2 then
curval:=interaction{:1692}else curval:=insertpenalties;curvallevel:=0;
end{:448};
81:{450:}begin if(pagecontents=0)and(not outputactive)then if m=0 then
curval:=1073741823 else curval:=0 else curval:=pagesofar[m];
curvallevel:=1;end{:450};
84:{452:}begin if m>25058 then{1864:}begin scanint;
if(eqtb[m].hh.rh=-268435455)or(curval<0)then curval:=0 else begin if
curval>mem[eqtb[m].hh.rh+1].int then curval:=mem[eqtb[m].hh.rh+1].int;
curval:=mem[eqtb[m].hh.rh+curval+1].int;end;
end{:1864}else if eqtb[25058].hh.rh=-268435455 then curval:=0 else
curval:=mem[eqtb[25058].hh.rh].hh.lh;curvallevel:=0;end{:452};
83:{449:}begin scanregisternum;
if curval<256 then q:=eqtb[25333+curval].hh.rh else begin findsaelement(
4,curval,false);
if curptr=-268435455 then q:=-268435455 else q:=mem[curptr+1].hh.rh;end;
if q=-268435455 then curval:=0 else curval:=mem[q+m].int;curvallevel:=1;
end{:449};68,69:begin curval:=curchr;curvallevel:=0;end;
77:{454:}begin findfontdimen(false);fontinfo[fmemptr].int:=0;
begin curval:=fontinfo[curval].int;curvallevel:=1;end;end{:454};
78:{455:}begin scanfontident;
if m=0 then begin curval:=hyphenchar[curval];curvallevel:=0;
end else if m=1 then begin curval:=skewchar[curval];curvallevel:=0;
end else if m=6 then begin curval:=testnoligatures(curval);
curvallevel:=0;end else begin n:=curval;scancharnum;k:=curval;
case m of 2:begin curval:=getlpcode(n,k);curvallevel:=0;end;
3:begin curval:=getrpcode(n,k);curvallevel:=0;end;
4:begin curval:=getefcode(n,k);curvallevel:=0;end;
5:begin curval:=gettagcode(n,k);curvallevel:=0;end;
7:begin curval:=getknbscode(n,k);curvallevel:=0;end;
8:begin curval:=getstbscode(n,k);curvallevel:=0;end;
9:begin curval:=getshbscode(n,k);curvallevel:=0;end;
10:begin curval:=getknbccode(n,k);curvallevel:=0;end;
11:begin curval:=getknaccode(n,k);curvallevel:=0;end;end;end;end{:455};
89:{456:}begin if(m<membot)or(m>membot+19)then begin curvallevel:=(mem[m
].hh.b0 div 16);
if curvallevel<2 then curval:=mem[m+2].int else curval:=mem[m+1].hh.rh;
end else begin scanregisternum;curvallevel:=m-membot;
if curval>255 then begin findsaelement(curvallevel,curval,false);
if curptr=-268435455 then if curvallevel<2 then curval:=0 else curval:=
membot else if curvallevel<2 then curval:=mem[curptr+2].int else curval
:=mem[curptr+1].hh.rh;
end else case curvallevel of 0:curval:=eqtb[27281+curval].int;
1:curval:=eqtb[27827+curval].int;2:curval:=eqtb[24546+curval].hh.rh;
3:curval:=eqtb[24802+curval].hh.rh;end;end;end{:456};
70:{453:}if m>=4 then if m>=37 then{1778:}begin if m<38 then begin case
m of{1805:}37:scanmuglue;{:1805}end;curvallevel:=2;
end else if m<39 then begin case m of{1806:}38:scannormalglue;
{:1806}end;curvallevel:=3;end else begin curvallevel:=m-39;scanexpr;end;
while curvallevel>level do begin if curvallevel=2 then begin m:=curval;
curval:=mem[m+1].int;deleteglueref(m);
end else if curvallevel=3 then muerror;decr(curvallevel);end;
if negative then if curvallevel>=2 then begin m:=curval;
curval:=newspec(m);deleteglueref(m);
{460:}begin mem[curval+1].int:=-mem[curval+1].int;
mem[curval+2].int:=-mem[curval+2].int;
mem[curval+3].int:=-mem[curval+3].int;end{:460};
end else curval:=-curval;goto 10;
end{:1778}else if m>=28 then begin case m of{1669:}28,29,30,31:begin
scanfontident;q:=curval;scancharnum;
if(fontbc[q]<=curval)and(fontec[q]>=curval)then begin i:=fontinfo[
charbase[q]+effectivechar(true,q,curval)].qqqq;
case m of 28:curval:=fontinfo[widthbase[q]+i.b0].int;
29:curval:=fontinfo[heightbase[q]+(i.b1)div 16].int;
30:curval:=fontinfo[depthbase[q]+(i.b1)mod 16].int;
31:curval:=fontinfo[italicbase[q]+(i.b2)div 4].int;end;
end else curval:=0;end;{:1669}{1672:}32,33,34:begin q:=curchr-32;
scanint;
if(eqtb[25058].hh.rh=-268435455)or(curval<=0)then curval:=0 else begin
if q=2 then begin q:=curval mod 2;curval:=(curval+q)div 2;end;
if curval>mem[eqtb[25058].hh.rh].hh.lh then curval:=mem[eqtb[25058].hh.
rh].hh.lh;curval:=mem[eqtb[25058].hh.rh+2*curval-q].int;end;
curvallevel:=1;end;{:1672}{1802:}35,36:begin scannormalglue;q:=curval;
if m=35 then curval:=mem[q+2].int else curval:=mem[q+3].int;
deleteglueref(q);end;{:1802}end;curvallevel:=1;
end else begin case m of 4:curval:=line;5:curval:=lastbadness;
6:curval:=140;7:curval:=pdflastobj;8:curval:=pdflastxform;
9:curval:=pdflastximage;10:curval:=pdflastximagepages;
11:curval:=pdflastannot;12:curval:=pdflastxpos;13:curval:=pdflastypos;
14:curval:=pdfretval;15:curval:=pdflastximagecolordepth;
16:curval:=getmicrointerval;18:curval:=randomseed;
17:begin if shellenabledp then begin if restrictedshell then curval:=2
else curval:=1;end else curval:=0;end;19:curval:=pdflastlink;
{1649:}20:curval:=2;{:1649}{1663:}21:curval:=curlevel-1;
22:curval:=curgroup;{:1663}{1666:}23:begin q:=condptr;curval:=0;
while q<>-268435455 do begin incr(curval);q:=mem[q].hh.rh;end;end;
24:if condptr=-268435455 then curval:=0 else if curif<32 then curval:=
curif+1 else curval:=-(curif-31);
25:if(iflimit=4)or(iflimit=3)then curval:=1 else if iflimit=2 then
curval:=-1 else curval:=0;{:1666}{1801:}26,27:begin scannormalglue;
q:=curval;if m=26 then curval:=mem[q].hh.b0 else curval:=mem[q].hh.b1;
deleteglueref(q);end;{:1801}end;curvallevel:=0;
end else begin if curchr=2 then curval:=membot else curval:=0;
tx:=curlist.tailfield;
if not(tx>=himemmin)then if(mem[tx].hh.b0=9)and(mem[tx].hh.b1=3)then
begin r:=curlist.headfield;repeat q:=r;r:=mem[q].hh.rh;until r=tx;tx:=q;
end;if curchr=3 then begin curvallevel:=0;
if(tx=curlist.headfield)or(curlist.modefield=0)then curval:=-1;
end else curvallevel:=curchr;
if not(tx>=himemmin)and(curlist.modefield<>0)then case curchr of 0:if
mem[tx].hh.b0=12 then curval:=mem[tx+1].int;
1:if mem[tx].hh.b0=11 then curval:=mem[tx+1].int;
2:if mem[tx].hh.b0=10 then begin curval:=mem[tx+1].hh.lh;
if mem[tx].hh.b1=99 then curvallevel:=3;end;
3:if mem[tx].hh.b0<=13 then curval:=mem[tx].hh.b0+1 else curval:=15;
end else if(curlist.modefield=1)and(tx=curlist.headfield)then case
curchr of 0:curval:=lastpenalty;1:curval:=lastkern;
2:if lastglue<>268435455 then curval:=lastglue;3:curval:=lastnodetype;
end;end{:453};39:if curchr=1 then{398:}begin gettoken;
curcs:=primlookup(hash[curcs].rh);
if curcs<>0 then begin curcmd:=primeqtb[curcs].hh.b0;
curchr:=primeqtb[curcs].hh.rh;curtok:=(curcmd*256)+curchr;
end else begin curcmd:=0;curchr:=0;curtok:=19616;curcs:=15521;end;
goto 20;end{:398};others:{457:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(787);
end;printcmdchr(curcmd,curchr);print(788);printesc(615);
begin helpptr:=1;helpline[0]:=786;end;error;
if level<>5 then begin curval:=0;curvallevel:=1;
end else begin curval:=0;curvallevel:=0;end;end{:457}end;
while curvallevel>level do{458:}begin if curvallevel=2 then curval:=mem[
curval+1].int else if curvallevel=3 then muerror;decr(curvallevel);
end{:458};
{459:}if negative then if curvallevel>=2 then begin curval:=newspec(
curval);{460:}begin mem[curval+1].int:=-mem[curval+1].int;
mem[curval+2].int:=-mem[curval+2].int;
mem[curval+3].int:=-mem[curval+3].int;end{:460};
end else curval:=-curval else if(curvallevel>=2)and(curvallevel<=3)then
incr(mem[curval].hh.rh){:459};10:end;{:442}{469:}procedure scanint;
label 30,20;var negative:boolean;m:integer;d:smallnumber;
vacuous:boolean;OKsofar:boolean;begin radix:=0;OKsofar:=true;
{470:}negative:=false;repeat{435:}repeat getxtoken;
until curcmd<>10{:435};if curtok=3117 then begin negative:=not negative;
curtok:=3115;end;until curtok<>3115{:470};
20:if curtok=3168 then{471:}begin gettoken;
if curtok<4095 then begin curval:=curchr;
if curcmd<=2 then if curcmd=2 then incr(alignstate)else decr(alignstate)
;end else if curtok<4352 then curval:=curtok-4096 else curval:=curtok
-4352;if curval>255 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(800);
end;begin helpptr:=2;helpline[1]:=801;helpline[0]:=802;end;curval:=48;
backerror;end else{472:}begin getxtoken;if curcmd<>10 then backinput;
end{:472};end{:471}else if curtok=19620 then{398:}begin gettoken;
curcs:=primlookup(hash[curcs].rh);
if curcs<>0 then begin curcmd:=primeqtb[curcs].hh.b0;
curchr:=primeqtb[curcs].hh.rh;curtok:=(curcmd*256)+curchr;
end else begin curcmd:=0;curchr:=0;curtok:=19616;curcs:=15521;end;
goto 20;
end{:398}else if(curcmd>=68)and(curcmd<=89)then scansomethinginternal(0,
false)else{473:}begin radix:=10;m:=214748364;
if curtok=3111 then begin radix:=8;m:=268435456;getxtoken;
end else if curtok=3106 then begin radix:=16;m:=134217728;getxtoken;end;
vacuous:=true;curval:=0;
{474:}while true do begin if(curtok<3120+radix)and(curtok>=3120)and(
curtok<=3129)then d:=curtok-3120 else if radix=16 then if(curtok<=2886)
and(curtok>=2881)then d:=curtok-2871 else if(curtok<=3142)and(curtok>=
3137)then d:=curtok-3127 else goto 30 else goto 30;vacuous:=false;
if(curval>=m)and((curval>m)or(d>7)or(radix<>10))then begin if OKsofar
then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(803);
end;begin helpptr:=2;helpline[1]:=804;helpline[0]:=805;end;error;
curval:=2147483647;OKsofar:=false;end;end else curval:=curval*radix+d;
getxtoken;end;30:{:474};
if vacuous then{475:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(752);
end;begin helpptr:=3;helpline[2]:=753;helpline[1]:=754;helpline[0]:=755;
end;backerror;end{:475}else if curcmd<>10 then backinput;end{:473};
if negative then curval:=-curval;end;
{:469}{477:}procedure scandimen(mu,inf,shortcut:boolean);
label 30,31,32,40,45,88,89;var negative:boolean;f:integer;
{479:}num,denom:1..65536;k,kk:smallnumber;p,q:halfword;v:scaled;
savecurval:integer;{:479}begin f:=0;aritherror:=false;curorder:=0;
negative:=false;if not shortcut then begin{470:}negative:=false;
repeat{435:}repeat getxtoken;until curcmd<>10{:435};
if curtok=3117 then begin negative:=not negative;curtok:=3115;end;
until curtok<>3115{:470};
if(curcmd>=68)and(curcmd<=89)then{478:}if mu then begin
scansomethinginternal(3,false);
{480:}if curvallevel>=2 then begin v:=mem[curval+1].int;
deleteglueref(curval);curval:=v;end{:480};if curvallevel=3 then goto 89;
if curvallevel<>0 then muerror;
end else begin scansomethinginternal(1,false);
if curvallevel=1 then goto 89;end{:478}else begin backinput;
if curtok=3116 then curtok:=3118;
if curtok<>3118 then scanint else begin radix:=10;curval:=0;end;
if curtok=3116 then curtok:=3118;
if(radix=10)and(curtok=3118)then{481:}begin k:=0;p:=-268435455;gettoken;
while true do begin getxtoken;
if(curtok>3129)or(curtok<3120)then goto 31;
if k<17 then begin q:=getavail;mem[q].hh.rh:=p;
mem[q].hh.lh:=curtok-3120;p:=q;incr(k);end;end;
31:for kk:=k downto 1 do begin dig[kk-1]:=mem[p].hh.lh;q:=p;
p:=mem[p].hh.rh;begin mem[q].hh.rh:=avail;avail:=q;
ifdef('STAT')decr(dynused);endif('STAT')end;end;f:=rounddecimals(k);
if curcmd<>10 then backinput;end{:481};end;end;
if curval<0 then begin negative:=not negative;curval:=-curval;end;
{482:}if inf then{483:}if scankeyword(316)then begin curorder:=1;
while scankeyword(108)do begin if curorder=3 then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(807);
end;print(808);begin helpptr:=1;helpline[0]:=809;end;error;
end else incr(curorder);end;goto 88;end{:483};{484:}savecurval:=curval;
{435:}repeat getxtoken;until curcmd<>10{:435};
if(curcmd<68)or(curcmd>89)then backinput else begin if mu then begin
scansomethinginternal(3,false);
{480:}if curvallevel>=2 then begin v:=mem[curval+1].int;
deleteglueref(curval);curval:=v;end{:480};
if curvallevel<>3 then muerror;end else scansomethinginternal(1,false);
v:=curval;goto 40;end;if mu then goto 45;
if scankeyword(810)then v:=({587:}fontinfo[6+parambase[eqtb[25589].hh.rh
]].int{:587})else if scankeyword(811)then v:=({588:}fontinfo[5+parambase
[eqtb[25589].hh.rh]].int{:588})else if scankeyword(812)then v:=eqtb[
27826].int else goto 45;{472:}begin getxtoken;
if curcmd<>10 then backinput;end{:472};
40:curval:=multandadd(savecurval,v,xnoverd(v,f,65536),1073741823);
goto 89;45:{:484};
if mu then{485:}if scankeyword(344)then goto 88 else begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(807);
end;print(813);begin helpptr:=4;helpline[3]:=814;helpline[2]:=815;
helpline[1]:=816;helpline[0]:=817;end;error;goto 88;end{:485};
if scankeyword(806)then{486:}begin preparemag;
if eqtb[27194].int<>1000 then begin curval:=xnoverd(curval,1000,eqtb[
27194].int);f:=(1000*f+65536*texremainder)div eqtb[27194].int;
curval:=curval+(f div 65536);f:=f mod 65536;end;end{:486};
if scankeyword(312)then goto 88;
{487:}if scankeyword(818)then begin num:=7227;denom:=100;
end else if scankeyword(819)then begin num:=12;denom:=1;
end else if scankeyword(820)then begin num:=7227;denom:=254;
end else if scankeyword(821)then begin num:=7227;denom:=2540;
end else if scankeyword(822)then begin num:=7227;denom:=7200;
end else if scankeyword(823)then begin num:=1238;denom:=1157;
end else if scankeyword(824)then begin num:=14856;denom:=1157;
end else if scankeyword(825)then begin num:=685;denom:=642;
end else if scankeyword(826)then begin num:=1370;denom:=107;
end else if scankeyword(827)then goto 30 else{488:}begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(807);
end;print(828);begin helpptr:=6;helpline[5]:=829;helpline[4]:=830;
helpline[3]:=831;helpline[2]:=815;helpline[1]:=816;helpline[0]:=817;end;
error;goto 32;end{:488};curval:=xnoverd(curval,num,denom);
f:=(num*f+65536*texremainder)div denom;curval:=curval+(f div 65536);
f:=f mod 65536;32:{:487};
88:if curval>=16384 then aritherror:=true else curval:=curval*65536+f;
30:{:482};{472:}begin getxtoken;if curcmd<>10 then backinput;end{:472};
89:if aritherror or(abs(curval)>=1073741824)then{489:}begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(832);
end;begin helpptr:=2;helpline[1]:=833;helpline[0]:=834;end;error;
curval:=1073741823;aritherror:=false;end{:489};
if negative then curval:=-curval;end;
{:477}{490:}procedure scanglue(level:smallnumber);label 10;
var negative:boolean;q:halfword;mu:boolean;begin mu:=(level=3);
{470:}negative:=false;repeat{435:}repeat getxtoken;
until curcmd<>10{:435};if curtok=3117 then begin negative:=not negative;
curtok:=3115;end;until curtok<>3115{:470};
if(curcmd>=68)and(curcmd<=89)then begin scansomethinginternal(level,
negative);
if curvallevel>=2 then begin if curvallevel<>level then muerror;goto 10;
end;if curvallevel=0 then scandimen(mu,false,true)else if level=3 then
muerror;end else begin backinput;scandimen(mu,false,false);
if negative then curval:=-curval;end;{491:}q:=newspec(membot);
mem[q+1].int:=curval;
if scankeyword(835)then begin scandimen(mu,true,false);
mem[q+2].int:=curval;mem[q].hh.b0:=curorder;end;
if scankeyword(836)then begin scandimen(mu,true,false);
mem[q+3].int:=curval;mem[q].hh.b1:=curorder;end;curval:=q{:491};10:end;
{1780:}{1791:}function addorsub(x,y,maxanswer:integer;
negative:boolean):integer;var a:integer;begin if negative then y:=-y;
if x>=0 then if y<=maxanswer-x then a:=x+y else begin aritherror:=true;
a:=0;
end else if y>=-maxanswer-x then a:=x+y else begin aritherror:=true;
a:=0;end;addorsub:=a;end;
{:1791}{1795:}function quotient(n,d:integer):integer;
var negative:boolean;a:integer;begin if d=0 then begin aritherror:=true;
a:=0;end else begin if d>0 then negative:=false else begin d:=-d;
negative:=true;end;if n<0 then begin n:=-n;negative:=not negative;end;
a:=n div d;n:=n-a*d;d:=n-d;if d+n>=0 then incr(a);
if negative then a:=-a;end;quotient:=a;end;
{:1795}{1797:}function fract(x,n,d,maxanswer:integer):integer;
label 40,41,88,30;var negative:boolean;a:integer;f:integer;h:integer;
r:integer;t:integer;begin if d=0 then goto 88;a:=0;
if d>0 then negative:=false else begin d:=-d;negative:=true;end;
if x<0 then begin x:=-x;negative:=not negative;
end else if x=0 then goto 30;if n<0 then begin n:=-n;
negative:=not negative;end;t:=n div d;if t>maxanswer div x then goto 88;
a:=t*x;n:=n-t*d;if n=0 then goto 40;t:=x div d;
if t>(maxanswer-a)div n then goto 88;a:=a+t*n;x:=x-t*d;
if x=0 then goto 40;if x<n then begin t:=x;x:=n;n:=t;end;{1798:}f:=0;
r:=(d div 2)-d;h:=-r;while true do begin if odd(n)then begin r:=r+x;
if r>=0 then begin r:=r-d;incr(f);end;end;n:=n div 2;
if n=0 then goto 41;if x<h then x:=x+x else begin t:=x-d;x:=t+x;f:=f+n;
if x<n then begin if x=0 then goto 41;t:=x;x:=n;n:=t;end;end;end;
41:{:1798}if f>(maxanswer-a)then goto 88;a:=a+f;
40:if negative then a:=-a;goto 30;88:begin aritherror:=true;a:=0;end;
30:fract:=a;end;{:1797}procedure scanexpr;label 20,22,40;
var a,b:boolean;l:smallnumber;r:smallnumber;s:smallnumber;o:smallnumber;
e:integer;t:integer;f:integer;n:integer;p:halfword;q:halfword;
begin l:=curvallevel;a:=aritherror;b:=false;p:=-268435455;
{1781:}20:r:=0;e:=0;s:=0;t:=0;n:=0;22:if s=0 then o:=l else o:=0;
{1783:}{435:}repeat getxtoken;until curcmd<>10{:435};
if curtok=3112 then{1786:}begin q:=getnode(4);mem[q].hh.rh:=p;
mem[q].hh.b0:=l;mem[q].hh.b1:=4*s+r;mem[q+1].int:=e;mem[q+2].int:=t;
mem[q+3].int:=n;p:=q;l:=o;goto 20;end{:1786};backinput;
if o=0 then scanint else if o=1 then scandimen(false,false,false)else if
o=2 then scannormalglue else scanmuglue;f:=curval{:1783};
40:{1782:}{435:}repeat getxtoken;until curcmd<>10{:435};
if curtok=3115 then o:=1 else if curtok=3117 then o:=2 else if curtok=
3114 then o:=3 else if curtok=3119 then o:=4 else begin o:=0;
if p=-268435455 then begin if curcmd<>0 then backinput;
end else if curtok<>3113 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(2041);
end;begin helpptr:=1;helpline[0]:=2042;end;backerror;end;end{:1782};
aritherror:=b;
{1788:}if(l=0)or(s>2)then begin if(f>2147483647)or(f<-2147483647)then
begin aritherror:=true;f:=0;end;
end else if l=1 then begin if abs(f)>1073741823 then begin aritherror:=
true;f:=0;end;
end else begin if(abs(mem[f+1].int)>1073741823)or(abs(mem[f+2].int)>
1073741823)or(abs(mem[f+3].int)>1073741823)then begin aritherror:=true;
deleteglueref(f);f:=newspec(membot);end;end{:1788};
case s of{1789:}0:if(l>=2)and(o<>0)then begin t:=newspec(f);
deleteglueref(f);if mem[t+2].int=0 then mem[t].hh.b0:=0;
if mem[t+3].int=0 then mem[t].hh.b1:=0;end else t:=f;
{:1789}{1793:}3:if o=4 then begin n:=f;o:=5;
end else if l=0 then t:=multandadd(t,f,0,2147483647)else if l=1 then t:=
multandadd(t,f,0,1073741823)else begin mem[t+1].int:=multandadd(mem[t+1]
.int,f,0,1073741823);
mem[t+2].int:=multandadd(mem[t+2].int,f,0,1073741823);
mem[t+3].int:=multandadd(mem[t+3].int,f,0,1073741823);end;
{:1793}{1794:}4:if l<2 then t:=quotient(t,f)else begin mem[t+1].int:=
quotient(mem[t+1].int,f);mem[t+2].int:=quotient(mem[t+2].int,f);
mem[t+3].int:=quotient(mem[t+3].int,f);end;
{:1794}{1796:}5:if l=0 then t:=fract(t,n,f,2147483647)else if l=1 then t
:=fract(t,n,f,1073741823)else begin mem[t+1].int:=fract(mem[t+1].int,n,f
,1073741823);mem[t+2].int:=fract(mem[t+2].int,n,f,1073741823);
mem[t+3].int:=fract(mem[t+3].int,n,f,1073741823);end;{:1796}end;
if o>2 then s:=o else{1790:}begin s:=0;
if r=0 then e:=t else if l=0 then e:=addorsub(e,t,2147483647,r=2)else if
l=1 then e:=addorsub(e,t,1073741823,r=2)else{1792:}begin mem[e+1].int:=
addorsub(mem[e+1].int,mem[t+1].int,1073741823,r=2);
if mem[e].hh.b0=mem[t].hh.b0 then mem[e+2].int:=addorsub(mem[e+2].int,
mem[t+2].int,1073741823,r=2)else if(mem[e].hh.b0<mem[t].hh.b0)and(mem[t
+2].int<>0)then begin mem[e+2].int:=mem[t+2].int;
mem[e].hh.b0:=mem[t].hh.b0;end;
if mem[e].hh.b1=mem[t].hh.b1 then mem[e+3].int:=addorsub(mem[e+3].int,
mem[t+3].int,1073741823,r=2)else if(mem[e].hh.b1<mem[t].hh.b1)and(mem[t
+3].int<>0)then begin mem[e+3].int:=mem[t+3].int;
mem[e].hh.b1:=mem[t].hh.b1;end;deleteglueref(t);
if mem[e+2].int=0 then mem[e].hh.b0:=0;
if mem[e+3].int=0 then mem[e].hh.b1:=0;end{:1792};r:=o;end{:1790};
b:=aritherror;if o<>0 then goto 22;
if p<>-268435455 then{1787:}begin f:=e;q:=p;e:=mem[q+1].int;
t:=mem[q+2].int;n:=mem[q+3].int;s:=mem[q].hh.b1 div 4;
r:=mem[q].hh.b1 mod 4;l:=mem[q].hh.b0;p:=mem[q].hh.rh;freenode(q,4);
goto 40;end{:1787}{:1781};if b then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1630);
end;begin helpptr:=2;helpline[1]:=2040;helpline[0]:=1632;end;error;
if l>=2 then begin deleteglueref(e);e:=membot;incr(mem[e].hh.rh);
end else e:=0;end;aritherror:=a;curval:=e;curvallevel:=l;end;
{:1780}{1785:}procedure scannormalglue;begin scanglue(2);end;
procedure scanmuglue;begin scanglue(3);end;
{:1785}{:490}{492:}function scanrulespec:halfword;label 21;
var q:halfword;begin q:=newrule;
if curcmd=35 then mem[q+1].int:=26214 else begin mem[q+3].int:=26214;
mem[q+2].int:=0;end;
21:if scankeyword(837)then begin scandimen(false,false,false);
mem[q+1].int:=curval;goto 21;end;
if scankeyword(838)then begin scandimen(false,false,false);
mem[q+3].int:=curval;goto 21;end;
if scankeyword(839)then begin scandimen(false,false,false);
mem[q+2].int:=curval;goto 21;end;scanrulespec:=q;end;
{:492}{493:}{1681:}procedure scangeneraltext;label 40;var s:0..5;
w:halfword;d:halfword;p:halfword;q:halfword;unbalance:halfword;
begin s:=scannerstatus;w:=warningindex;d:=defref;scannerstatus:=5;
warningindex:=curcs;defref:=getavail;mem[defref].hh.lh:=-268435455;
p:=defref;scanleftbrace;unbalance:=1;while true do begin gettoken;
if curtok<768 then if curcmd<2 then incr(unbalance)else begin decr(
unbalance);if unbalance=0 then goto 40;end;begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;end;
40:q:=mem[defref].hh.rh;begin mem[defref].hh.rh:=avail;avail:=defref;
ifdef('STAT')decr(dynused);endif('STAT')end;
if q=-268435455 then curval:=memtop-3 else curval:=p;
mem[memtop-3].hh.rh:=q;scannerstatus:=s;warningindex:=w;defref:=d;end;
{:1681}{1751:}procedure pseudostart;var oldsetting:0..21;s:strnumber;
l,m:poolpointer;p,q,r:halfword;w:fourquarters;nl,sz:integer;
begin scangeneraltext;oldsetting:=selector;selector:=21;
tokenshow(memtop-3);selector:=oldsetting;flushlist(mem[memtop-3].hh.rh);
begin if poolptr+1>poolsize then overflow(259,poolsize-initpoolptr);end;
s:=makestring;{1752:}strpool[poolptr]:=32;l:=strstart[s];
nl:=eqtb[27226].int;p:=getavail;q:=p;while l<poolptr do begin m:=l;
while(l<poolptr)and(strpool[l]<>nl)do incr(l);sz:=(l-m+7)div 4;
if sz=1 then sz:=2;r:=getnode(sz);mem[q].hh.rh:=r;q:=r;mem[q].hh.lh:=sz;
while sz>2 do begin decr(sz);incr(r);w.b0:=strpool[m];
w.b1:=strpool[m+1];w.b2:=strpool[m+2];w.b3:=strpool[m+3];mem[r].qqqq:=w;
m:=m+4;end;w.b0:=32;w.b1:=32;w.b2:=32;w.b3:=32;
if l>m then begin w.b0:=strpool[m];
if l>m+1 then begin w.b1:=strpool[m+1];
if l>m+2 then begin w.b2:=strpool[m+2];if l>m+3 then w.b3:=strpool[m+3];
end;end;end;mem[r+1].qqqq:=w;if strpool[l]=nl then incr(l);end;
mem[p].hh.lh:=mem[p].hh.rh;mem[p].hh.rh:=pseudofiles;
pseudofiles:=p{:1752};begin decr(strptr);poolptr:=strstart[strptr];end;
{1753:}beginfilereading;line:=0;
curinput.limitfield:=curinput.startfield;
curinput.locfield:=curinput.limitfield+1;
if eqtb[27273].int>0 then begin if termoffset>maxprintline-3 then
println else if(termoffset>0)or(fileoffset>0)then printchar(32);
curinput.namefield:=19;print(2023);incr(openparens);fflush(stdout);
end else begin curinput.namefield:=18;
{1913:}curinput.synctextagfield:=0;{:1913};end{:1753};end;
{:1751}function strtoks(b:poolpointer):halfword;var p:halfword;
q:halfword;t:halfword;k:poolpointer;
begin begin if poolptr+1>poolsize then overflow(259,poolsize-initpoolptr
);end;p:=memtop-3;mem[p].hh.rh:=-268435455;k:=b;
while k<poolptr do begin t:=strpool[k];
if t=32 then t:=2592 else t:=3072+t;begin begin q:=avail;
if q=-268435455 then q:=getavail else begin avail:=mem[q].hh.rh;
mem[q].hh.rh:=-268435455;ifdef('STAT')incr(dynused);endif('STAT')end;
end;mem[p].hh.rh:=q;mem[q].hh.lh:=t;p:=q;end;incr(k);end;poolptr:=b;
strtoks:=p;end;{:493}{494:}function thetoks:halfword;label 10;
var oldsetting:0..21;p,q,r:halfword;b:poolpointer;c:smallnumber;
begin{1686:}if odd(curchr)then begin c:=curchr;scangeneraltext;
if c=1 then thetoks:=curval else begin oldsetting:=selector;
selector:=21;b:=poolptr;p:=getavail;mem[p].hh.rh:=mem[memtop-3].hh.rh;
tokenshow(p);flushlist(p);selector:=oldsetting;thetoks:=strtoks(b);end;
goto 10;end{:1686};getxtoken;scansomethinginternal(5,false);
if curvallevel>=4 then{495:}begin p:=memtop-3;mem[p].hh.rh:=-268435455;
if curvallevel=4 then begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=4095+curval;p:=q;
end else if curval<>-268435455 then begin r:=mem[curval].hh.rh;
while r<>-268435455 do begin begin begin q:=avail;
if q=-268435455 then q:=getavail else begin avail:=mem[q].hh.rh;
mem[q].hh.rh:=-268435455;ifdef('STAT')incr(dynused);endif('STAT')end;
end;mem[p].hh.rh:=q;mem[q].hh.lh:=mem[r].hh.lh;p:=q;end;r:=mem[r].hh.rh;
end;end;thetoks:=p;end{:495}else begin oldsetting:=selector;
selector:=21;b:=poolptr;case curvallevel of 0:printint(curval);
1:begin printscaled(curval);print(312);end;
2:begin printspec(curval,312);deleteglueref(curval);end;
3:begin printspec(curval,344);deleteglueref(curval);end;end;
selector:=oldsetting;thetoks:=strtoks(b);end;10:end;
{:494}{496:}procedure insthetoks;begin mem[memtop-12].hh.rh:=thetoks;
begintokenlist(mem[memtop-3].hh.rh,4);end;
{:496}{499:}procedure convtoks;label 10;var oldsetting:0..21;
p,q:halfword;c:0..32;savescannerstatus:smallnumber;savedefref:halfword;
savewarningindex:halfword;bool:boolean;i:integer;j:integer;
b:poolpointer;s:strnumber;t:strnumber;u:strnumber;begin c:=curchr;u:=0;
{500:}case c of 0,1:scanint;2,3:begin savescannerstatus:=scannerstatus;
scannerstatus:=0;gettoken;scannerstatus:=savescannerstatus;end;
4:scanfontident;5:;6:;7:;8,9,10:begin scanfontident;
if curval=0 then pdferror(593,873);if c<>10 then begin pdfcheckvfcurval;
if not fontused[curval]then pdfinitfontcurval;end;end;11:begin scanint;
if curval<=0 then pdferror(874,875);end;15,16:begin scanregisternum;
if curval<256 then p:=eqtb[25333+curval].hh.rh else begin findsaelement(
4,curval,false);
if curptr=-268435455 then p:=-268435455 else p:=mem[curptr+1].hh.rh;end;
if(p=-268435455)or(mem[p].hh.b0<>0)then pdferror(876,877)end;
12:begin scanint;pdfcheckobj(7,curval);end;
13:begin savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;scanpdfexttoks;
s:=tokenstostring(defref);deletetokenref(defref);defref:=savedefref;
warningindex:=savewarningindex;scannerstatus:=savescannerstatus;
b:=poolptr;escapestring(strstart[s]);mem[memtop-12].hh.rh:=strtoks(b);
flushstr(s);begintokenlist(mem[memtop-3].hh.rh,4);
if u<>0 then begin decr(strptr);u:=0;end;goto 10;end;
14:begin savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;scanpdfexttoks;
s:=tokenstostring(defref);deletetokenref(defref);defref:=savedefref;
warningindex:=savewarningindex;scannerstatus:=savescannerstatus;
b:=poolptr;escapename(strstart[s]);mem[memtop-12].hh.rh:=strtoks(b);
flushstr(s);begintokenlist(mem[memtop-3].hh.rh,4);
if u<>0 then begin decr(strptr);u:=0;end;goto 10;end;
19:begin savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;scanpdfexttoks;
s:=tokenstostring(defref);deletetokenref(defref);defref:=savedefref;
warningindex:=savewarningindex;scannerstatus:=savescannerstatus;
b:=poolptr;escapehex(strstart[s]);mem[memtop-12].hh.rh:=strtoks(b);
flushstr(s);begintokenlist(mem[memtop-3].hh.rh,4);
if u<>0 then begin decr(strptr);u:=0;end;goto 10;end;
20:begin savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;scanpdfexttoks;
s:=tokenstostring(defref);deletetokenref(defref);defref:=savedefref;
warningindex:=savewarningindex;scannerstatus:=savescannerstatus;
b:=poolptr;unescapehex(strstart[s]);mem[memtop-12].hh.rh:=strtoks(b);
flushstr(s);begintokenlist(mem[memtop-3].hh.rh,4);
if u<>0 then begin decr(strptr);u:=0;end;goto 10;end;
21:begin b:=poolptr;getcreationdate;mem[memtop-12].hh.rh:=strtoks(b);
begintokenlist(mem[memtop-3].hh.rh,4);goto 10;end;
22:begin savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;scanpdfexttoks;
s:=tokenstostring(defref);deletetokenref(defref);defref:=savedefref;
warningindex:=savewarningindex;scannerstatus:=savescannerstatus;
b:=poolptr;getfilemoddate(s);mem[memtop-12].hh.rh:=strtoks(b);
flushstr(s);begintokenlist(mem[memtop-3].hh.rh,4);
if u<>0 then begin decr(strptr);u:=0;end;goto 10;end;
23:begin savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;scanpdfexttoks;
s:=tokenstostring(defref);deletetokenref(defref);defref:=savedefref;
warningindex:=savewarningindex;scannerstatus:=savescannerstatus;
b:=poolptr;getfilesize(s);mem[memtop-12].hh.rh:=strtoks(b);flushstr(s);
begintokenlist(mem[memtop-3].hh.rh,4);if u<>0 then begin decr(strptr);
u:=0;end;goto 10;end;24:begin savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;bool:=scankeyword(878);
scanpdfexttoks;s:=tokenstostring(defref);deletetokenref(defref);
defref:=savedefref;warningindex:=savewarningindex;
scannerstatus:=savescannerstatus;b:=poolptr;getmd5sum(s,bool);
mem[memtop-12].hh.rh:=strtoks(b);flushstr(s);
begintokenlist(mem[memtop-3].hh.rh,4);if u<>0 then begin decr(strptr);
u:=0;end;goto 10;end;25:begin savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;curval:=0;
if(scankeyword(879))then begin scanint;
if(curval<0)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(880);
end;begin helpptr:=2;helpline[1]:=881;helpline[0]:=791;end;
interror(curval);curval:=0;end;end;i:=curval;curval:=0;
if(scankeyword(882))then begin scanint;
if(curval<0)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(883);
end;begin helpptr:=2;helpline[1]:=884;helpline[0]:=791;end;
interror(curval);curval:=0;end;end;j:=curval;scanpdfexttoks;
s:=tokenstostring(defref);deletetokenref(defref);defref:=savedefref;
warningindex:=savewarningindex;scannerstatus:=savescannerstatus;
b:=poolptr;getfiledump(s,i,j);mem[memtop-12].hh.rh:=strtoks(b);
flushstr(s);begintokenlist(mem[memtop-3].hh.rh,4);
if u<>0 then begin decr(strptr);u:=0;end;goto 10;end;
26:begin savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;bool:=scankeyword(885);
i:=-1;if scankeyword(886)then begin scanint;i:=curval;end;
scanpdfexttoks;s:=tokenstostring(defref);deletetokenref(defref);
scanpdfexttoks;t:=tokenstostring(defref);deletetokenref(defref);
defref:=savedefref;warningindex:=savewarningindex;
scannerstatus:=savescannerstatus;b:=poolptr;matchstrings(s,t,i,bool);
mem[memtop-12].hh.rh:=strtoks(b);flushstr(t);flushstr(s);
begintokenlist(mem[memtop-3].hh.rh,4);if u<>0 then begin decr(strptr);
u:=0;end;goto 10;end;27:begin scanint;
if curval<0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(887);
end;begin helpptr:=2;helpline[1]:=888;helpline[0]:=791;end;
interror(curval);curval:=0;end;b:=poolptr;getmatch(curval);
mem[memtop-12].hh.rh:=strtoks(b);begintokenlist(mem[memtop-3].hh.rh,4);
goto 10;end;17:begin savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;comparestrings;
defref:=savedefref;warningindex:=savewarningindex;
scannerstatus:=savescannerstatus;if u<>0 then begin decr(strptr);u:=0;
end;end;18:begin bool:=scankeyword(889);
if scankeyword(890)then curval:=2 else if scankeyword(889)then curval:=1
else curval:=0;savescannerstatus:=scannerstatus;
savewarningindex:=warningindex;savedefref:=defref;
if strstart[strptr]<poolptr then u:=makestring;scanpdfexttoks;
s:=tokenstostring(defref);deletetokenref(defref);defref:=savedefref;
warningindex:=savewarningindex;scannerstatus:=savescannerstatus;
curval:=newcolorstack(s,curval,bool);flushstr(s);curvallevel:=0;
if curval<0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(891);
end;begin helpptr:=2;helpline[1]:=892;helpline[0]:=893;end;error;
curval:=0;if u<>0 then begin decr(strptr);u:=0;end;end;end;
32:if jobname=0 then openlogfile;28:scanint;29:;30:scanregisternum;
31:begin scanint;pdfcheckobj(8,curval);i:=pdfmem[objtab[curval].int4+4];
scanint;j:=curval;if(j<1)or(j>4)then pdferror(871,894);end;end{:500};
oldsetting:=selector;selector:=21;b:=poolptr;
{501:}case c of 0:printint(curval);1:printromanint(curval);
2:if curcs<>0 then sprintcs(curcs)else printchar(curchr);3:printmeaning;
4:begin print(fontname[curval]);
if fontsize[curval]<>fontdsize[curval]then begin print(895);
printscaled(fontsize[curval]);print(312);end;end;5:print(256);
6:print(257);7:print(pdftexbanner);
8,9:begin begin if pdffontnum[curval]<0 then ff:=-pdffontnum[curval]else
ff:=curval;end;
if c=8 then printint(objtab[pdffontnum[ff]].int0)else printint(
pdffontnum[ff]);end;10:begin printscaled(fontsize[curval]);print(312);
end;11:printint(getobj(1,curval,false));15:begin p:=mem[p+5].hh.rh;
while(p<>-268435455)and((not(p>=himemmin)and((mem[p].hh.b0=3)or(mem[p].
hh.b0=4)or(mem[p].hh.b0=5)or(mem[p].hh.b0=12)or((mem[p].hh.b0=8)and(mem[
p].hh.b1<>12)and(mem[p].hh.b1<>10))or((mem[p].hh.b0=7)and(mem[p+1].hh.lh
=-268435455)and(mem[p+1].hh.rh=-268435455)and(mem[p].hh.b1=0))or((mem[p]
.hh.b0=9)and(mem[p+1].int=0))or((mem[p].hh.b0=11)and((mem[p+1].int=0)or(
mem[p].hh.b1=0)))or((mem[p].hh.b0=10)and(mem[p+1].hh.lh=membot))or((mem[
p].hh.b0=0)and(mem[p+1].int=0)and(mem[p+3].int=0)and(mem[p+2].int=0)and(
mem[p+5].hh.rh=-268435455))))or((not(p>=himemmin))and(mem[p].hh.b0=10)
and(mem[p].hh.b1=8)))do p:=mem[p].hh.rh;
if(p<>-268435455)and(not(p>=himemmin))and(mem[p].hh.b0=40)and(mem[p].hh.
b1=0)then printscaled(mem[p+1].int)else print(48);print(312);end;
16:begin q:=mem[p+5].hh.rh;p:=prevrightmost(q,-268435455);
while(p<>-268435455)and((not(p>=himemmin)and((mem[p].hh.b0=3)or(mem[p].
hh.b0=4)or(mem[p].hh.b0=5)or(mem[p].hh.b0=12)or((mem[p].hh.b0=8)and(mem[
p].hh.b1<>12)and(mem[p].hh.b1<>10))or((mem[p].hh.b0=7)and(mem[p+1].hh.lh
=-268435455)and(mem[p+1].hh.rh=-268435455)and(mem[p].hh.b1=0))or((mem[p]
.hh.b0=9)and(mem[p+1].int=0))or((mem[p].hh.b0=11)and((mem[p+1].int=0)or(
mem[p].hh.b1=0)))or((mem[p].hh.b0=10)and(mem[p+1].hh.lh=membot))or((mem[
p].hh.b0=0)and(mem[p+1].int=0)and(mem[p+3].int=0)and(mem[p+2].int=0)and(
mem[p+5].hh.rh=-268435455))))or((not(p>=himemmin))and(mem[p].hh.b0=10)
and(mem[p].hh.b1=9)))do p:=prevrightmost(q,p);
if(p<>-268435455)and(not(p>=himemmin))and(mem[p].hh.b0=40)and(mem[p].hh.
b1=1)then printscaled(mem[p+1].int)else print(48);print(312);end;
12:printint(objtab[curval].int0);17:printint(curval);
18:printint(curval);28:printint(unifrand(curval));29:printint(normrand);
30:begin i:=curval;p:=memtop;
while i>=mem[mem[p].hh.rh].hh.b1 do p:=mem[p].hh.rh;
if mem[p].hh.b1=i then printscaled(mem[p+3].int)else print(48);
print(312);end;
31:begin if ispdfimage(i)then begin case j of 1:printscaled(epdforigx(i)
);2:printscaled(epdforigy(i));3:printscaled(epdforigx(i)+imagewidth(i));
4:printscaled(epdforigy(i)+imageheight(i));end;end else printscaled(0);
print(312);end;32:print(jobname);end{:501};selector:=oldsetting;
mem[memtop-12].hh.rh:=strtoks(b);begintokenlist(mem[memtop-3].hh.rh,4);
10:end;{:499}{502:}function scantoks(macrodef,xpand:boolean):halfword;
label 40,30,31,32;var t:halfword;s:halfword;p:halfword;q:halfword;
unbalance:halfword;hashbrace:halfword;
begin if macrodef then scannerstatus:=2 else scannerstatus:=5;
warningindex:=curcs;defref:=getavail;mem[defref].hh.lh:=-268435455;
p:=defref;hashbrace:=0;t:=3120;
if macrodef then{503:}begin while true do begin gettoken;
if curtok<768 then goto 31;if curcmd=6 then{505:}begin s:=3328+curchr;
gettoken;if curcmd=1 then begin hashbrace:=curtok;begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=3584;p:=q;end;goto 30;end;
if t=3129 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(898);
end;begin helpptr:=1;helpline[0]:=899;end;error;end else begin incr(t);
if curtok<>t then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(900);
end;begin helpptr:=2;helpline[1]:=901;helpline[0]:=902;end;backerror;
end;curtok:=s;end;end{:505};begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=curtok;p:=q;end;end;31:begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=3584;p:=q;end;
if curcmd=2 then{504:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(745);
end;incr(alignstate);begin helpptr:=2;helpline[1]:=896;helpline[0]:=897;
end;error;goto 40;end{:504};30:end{:503}else scanleftbrace;
{506:}unbalance:=1;
while true do begin if xpand then{507:}begin while true do begin getnext
;if curcmd>=113 then if mem[mem[curchr].hh.rh].hh.lh=3585 then begin
curcmd:=0;curchr:=257;end;if curcmd<=102 then goto 32;
if curcmd<>111 then expand else begin q:=thetoks;
if mem[memtop-3].hh.rh<>-268435455 then begin mem[p].hh.rh:=mem[memtop-3
].hh.rh;p:=q;end;end;end;32:xtoken end{:507}else gettoken;
if curtok<768 then if curcmd<2 then incr(unbalance)else begin decr(
unbalance);if unbalance=0 then goto 40;
end else if curcmd=6 then if macrodef then{508:}begin s:=curtok;
if xpand then getxtoken else gettoken;
if curcmd<>6 then if(curtok<=3120)or(curtok>t)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(903);
end;sprintcs(warningindex);begin helpptr:=3;helpline[2]:=904;
helpline[1]:=905;helpline[0]:=906;end;backerror;curtok:=s;
end else curtok:=1232+curchr;end{:508};begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;end{:506};
40:scannerstatus:=0;if hashbrace<>0 then begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=hashbrace;p:=q;end;scantoks:=p;end;
{:502}{511:}procedure readtoks(n:integer;r:halfword;j:halfword);
label 30;var p:halfword;q:halfword;s:integer;m:smallnumber;
begin scannerstatus:=2;warningindex:=r;defref:=getavail;
mem[defref].hh.lh:=-268435455;p:=defref;begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=3584;p:=q;end;
if(n<0)or(n>15)then m:=16 else m:=n;s:=alignstate;alignstate:=1000000;
repeat{512:}beginfilereading;curinput.namefield:=m+1;
if readopen[m]=2 then{513:}if interaction>1 then if n<0 then begin;
print(345);terminput;end else begin;println;sprintcs(r);begin;print(61);
terminput;end;n:=-1;
end else fatalerror(907){:513}else if readopen[m]=1 then{514:}if inputln
(readfile[m],false)then readopen[m]:=0 else begin aclose(readfile[m]);
readopen[m]:=2;
end{:514}else{515:}begin if not inputln(readfile[m],true)then begin
aclose(readfile[m]);readopen[m]:=2;
if alignstate<>1000000 then begin runaway;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(908);
end;printesc(612);begin helpptr:=1;helpline[0]:=909;end;
alignstate:=1000000;error;end;end;end{:515};curinput.limitfield:=last;
if(eqtb[27225].int<0)or(eqtb[27225].int>255)then decr(curinput.
limitfield)else buffer[curinput.limitfield]:=eqtb[27225].int;
first:=curinput.limitfield+1;curinput.locfield:=curinput.startfield;
curinput.statefield:=33;
{1759:}if j=1 then begin while curinput.locfield<=curinput.limitfield do
begin curchr:=buffer[curinput.locfield];incr(curinput.locfield);
if curchr=32 then curtok:=2592 else curtok:=curchr+3072;
begin q:=getavail;mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;end;
goto 30;end{:1759};while true do begin gettoken;
if curtok=0 then goto 30;
if alignstate<1000000 then begin repeat gettoken;until curtok=0;
alignstate:=1000000;goto 30;end;begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=curtok;p:=q;end;end;30:endfilereading{:512};
until alignstate=1000000;curval:=defref;scannerstatus:=0;alignstate:=s;
end;{:511}{523:}procedure passtext;label 30;var l:integer;
savescannerstatus:smallnumber;begin savescannerstatus:=scannerstatus;
scannerstatus:=1;l:=0;skipline:=line;while true do begin getnext;
if curcmd=108 then begin if l=0 then goto 30;if curchr=2 then decr(l);
end else if curcmd=107 then incr(l);end;
30:scannerstatus:=savescannerstatus;
if eqtb[27272].int>0 then showcurcmdchr;end;
{:523}{526:}procedure changeiflimit(l:smallnumber;p:halfword);label 10;
var q:halfword;begin if p=condptr then iflimit:=l else begin q:=condptr;
while true do begin if q=-268435455 then confusion(910);
if mem[q].hh.rh=p then begin mem[q].hh.b0:=l;goto 10;end;
q:=mem[q].hh.rh;end;end;10:end;{:526}{527:}procedure conditional;
label 10,50;var b:boolean;e:boolean;r:60..62;m,n:integer;p,q:halfword;
savescannerstatus:smallnumber;savecondptr:halfword;thisif:smallnumber;
isunless:boolean;
begin if eqtb[27272].int>0 then if eqtb[27213].int<=1 then showcurcmdchr
;{524:}begin p:=getnode(2);mem[p].hh.rh:=condptr;mem[p].hh.b0:=iflimit;
mem[p].hh.b1:=curif;mem[p+1].int:=ifline;condptr:=p;curif:=curchr;
iflimit:=1;ifline:=line;end{:524};savecondptr:=condptr;
isunless:=(curchr>=32);thisif:=curchr mod 32;
{530:}case thisif of 0,1:{535:}begin begin getxtoken;
if curcmd=0 then if curchr=257 then begin curcmd:=13;
curchr:=curtok-4096;end;end;if(curcmd>13)or(curchr>255)then begin m:=0;
n:=256;end else begin m:=curcmd;n:=curchr;end;begin getxtoken;
if curcmd=0 then if curchr=257 then begin curcmd:=13;
curchr:=curtok-4096;end;end;
if(curcmd>13)or(curchr>255)then begin curcmd:=0;curchr:=256;end;
if thisif=0 then b:=(n=curchr)else b:=(m=curcmd);end{:535};
2,3:{532:}begin if thisif=2 then scanint else scandimen(false,false,
false);n:=curval;{435:}repeat getxtoken;until curcmd<>10{:435};
if(curtok>=3132)and(curtok<=3134)then r:=curtok-3072 else begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(936);
end;printcmdchr(107,thisif);begin helpptr:=1;helpline[0]:=937;end;
backerror;r:=61;end;
if thisif=2 then scanint else scandimen(false,false,false);
case r of 60:b:=(n<curval);61:b:=(n=curval);62:b:=(n>curval);end;
end{:532};4:{533:}begin scanint;b:=odd(curval);end{:533};
5:b:=(abs(curlist.modefield)=1);6:b:=(abs(curlist.modefield)=104);
7:b:=(abs(curlist.modefield)=207);8:b:=(curlist.modefield<0);
9,10,11:{534:}begin scanregisternum;
if curval<256 then p:=eqtb[25333+curval].hh.rh else begin findsaelement(
4,curval,false);
if curptr=-268435455 then p:=-268435455 else p:=mem[curptr+1].hh.rh;end;
if thisif=9 then b:=(p=-268435455)else if p=-268435455 then b:=false
else if thisif=10 then b:=(mem[p].hh.b0=0)else b:=(mem[p].hh.b0=1);
end{:534};12:{536:}begin savescannerstatus:=scannerstatus;
scannerstatus:=0;getnext;n:=curcs;p:=curcmd;q:=curchr;getnext;
if curcmd<>p then b:=false else if curcmd<113 then b:=(curchr=q)else
{537:}begin p:=mem[curchr].hh.rh;q:=mem[eqtb[n].hh.rh].hh.rh;
if p=q then b:=true else begin while(p<>-268435455)and(q<>-268435455)do
if mem[p].hh.lh<>mem[q].hh.lh then p:=-268435455 else begin p:=mem[p].hh
.rh;q:=mem[q].hh.rh;end;b:=((p=-268435455)and(q=-268435455));end;
end{:537};scannerstatus:=savescannerstatus;end{:536};
13:begin scanfourbitintor18;
if curval=18 then b:=not shellenabledp else b:=(readopen[curval]=2);end;
14:b:=true;15:b:=false;{1764:}17:begin savescannerstatus:=scannerstatus;
scannerstatus:=0;getnext;b:=(curcmd<>103);
scannerstatus:=savescannerstatus;end;{:1764}{1765:}18:begin n:=getavail;
p:=n;e:=isincsname;isincsname:=true;repeat getxtoken;
if curcs=0 then begin q:=getavail;mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;
p:=q;end;until curcs<>0;
if curcmd<>67 then{402:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(713);
end;printesc(579);print(714);begin helpptr:=2;helpline[1]:=715;
helpline[0]:=716;end;backerror;end{:402};{1766:}m:=first;
p:=mem[n].hh.rh;
while p<>-268435455 do begin if m>=maxbufstack then begin maxbufstack:=m
+1;if maxbufstack=bufsize then overflow(258,bufsize);end;
buffer[m]:=mem[p].hh.lh mod 256;incr(m);p:=mem[p].hh.rh;end;
if m>first+1 then curcs:=idlookup(first,m-first)else if m=first then
curcs:=513 else curcs:=257+buffer[first]{:1766};flushlist(n);
b:=(eqtb[curcs].hh.b0<>103);isincsname:=e;end;
{:1765}{1767:}20:b:=isincsname;
23,22:begin if thisif=22 then scanint else scandimen(false,false,false);
n:=curval;if n<0 then n:=-n;{435:}repeat getxtoken;
until curcmd<>10{:435};
if(curtok>=3132)and(curtok<=3134)then r:=curtok-3072 else begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(936);
end;printcmdchr(107,thisif);begin helpptr:=1;helpline[0]:=937;end;
backerror;r:=61;end;
if thisif=22 then scanint else scandimen(false,false,false);
if curval<0 then curval:=-curval;case r of 60:b:=(n<curval);
61:b:=(n=curval);62:b:=(n>curval);end;end;19:begin scanfontident;
n:=curval;scancharnum;
if(fontbc[n]<=curval)and(fontec[n]>=curval)then b:=(fontinfo[charbase[n]
+effectivechar(true,n,curval)].qqqq.b0>0)else b:=false;end;
{:1767}16:{538:}begin scanint;n:=curval;
if eqtb[27213].int>1 then begin begindiagnostic;print(938);printint(n);
printchar(125);enddiagnostic(false);end;while n<>0 do begin passtext;
if condptr=savecondptr then if curchr=4 then decr(n)else goto 50 else if
curchr=2 then{525:}begin if ifstack[inopen]=condptr then ifwarning;
p:=condptr;ifline:=mem[p+1].int;curif:=mem[p].hh.b1;
iflimit:=mem[p].hh.b0;condptr:=mem[p].hh.rh;freenode(p,2);end{:525};end;
changeiflimit(4,savecondptr);goto 10;end{:538};
21:begin savescannerstatus:=scannerstatus;scannerstatus:=0;getnext;
scannerstatus:=savescannerstatus;
if curcs<514 then m:=primlookup(curcs-257)else m:=primlookup(hash[curcs]
.rh);b:=((curcmd<>103)and(m<>0)and(curcmd=primeqtb[m].hh.b0)and(curchr=
primeqtb[m].hh.rh));end;end{:530};if isunless then b:=not b;
if eqtb[27213].int>1 then{531:}begin begindiagnostic;
if b then print(934)else print(935);enddiagnostic(false);end{:531};
if b then begin changeiflimit(3,savecondptr);goto 10;end;
{529:}while true do begin passtext;
if condptr=savecondptr then begin if curchr<>4 then goto 50;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(932);
end;printesc(930);begin helpptr:=1;helpline[0]:=933;end;error;
end else if curchr=2 then{525:}begin if ifstack[inopen]=condptr then
ifwarning;p:=condptr;ifline:=mem[p+1].int;curif:=mem[p].hh.b1;
iflimit:=mem[p].hh.b0;condptr:=mem[p].hh.rh;freenode(p,2);end{:525};
end{:529};
50:if curchr=2 then{525:}begin if ifstack[inopen]=condptr then ifwarning
;p:=condptr;ifline:=mem[p+1].int;curif:=mem[p].hh.b1;
iflimit:=mem[p].hh.b0;condptr:=mem[p].hh.rh;freenode(p,2);
end{:525}else iflimit:=2;10:end;{:527}{544:}procedure beginname;
begin areadelimiter:=0;extdelimiter:=0;quotedfilename:=false;end;
{:544}{545:}function morename(c:ASCIIcode):boolean;
begin if(c=32)and stopatspace and(not quotedfilename)then morename:=
false else if c=34 then begin quotedfilename:=not quotedfilename;
morename:=true;
end else begin begin if poolptr+1>poolsize then overflow(259,poolsize-
initpoolptr);end;begin strpool[poolptr]:=c;incr(poolptr);end;
if ISDIRSEP(c)then begin areadelimiter:=(poolptr-strstart[strptr]);
extdelimiter:=0;
end else if c=46 then extdelimiter:=(poolptr-strstart[strptr]);
morename:=true;end;end;{:545}{546:}procedure endname;
var tempstr:strnumber;j,s,t:poolpointer;mustquote:boolean;
begin if strptr+3>maxstrings then overflow(260,maxstrings-initstrptr);
begin if poolptr+6>poolsize then overflow(259,poolsize-initpoolptr);end;
if areadelimiter<>0 then begin mustquote:=false;s:=strstart[strptr];
t:=strstart[strptr]+areadelimiter;j:=s;
while(not mustquote)and(j<t)do begin mustquote:=strpool[j]=32;incr(j);
end;if mustquote then begin for j:=poolptr-1 downto t do strpool[j+2]:=
strpool[j];strpool[t+1]:=34;
for j:=t-1 downto s do strpool[j+1]:=strpool[j];strpool[s]:=34;
if extdelimiter<>0 then extdelimiter:=extdelimiter+2;
areadelimiter:=areadelimiter+2;poolptr:=poolptr+2;end;end;
s:=strstart[strptr]+areadelimiter;
if extdelimiter=0 then t:=poolptr else t:=strstart[strptr]+extdelimiter
-1;mustquote:=false;j:=s;
while(not mustquote)and(j<t)do begin mustquote:=strpool[j]=32;incr(j);
end;if mustquote then begin for j:=poolptr-1 downto t do strpool[j+2]:=
strpool[j];strpool[t+1]:=34;
for j:=t-1 downto s do strpool[j+1]:=strpool[j];strpool[s]:=34;
if extdelimiter<>0 then extdelimiter:=extdelimiter+2;poolptr:=poolptr+2;
end;if extdelimiter<>0 then begin s:=strstart[strptr]+extdelimiter-1;
t:=poolptr;mustquote:=false;j:=s;
while(not mustquote)and(j<t)do begin mustquote:=strpool[j]=32;incr(j);
end;if mustquote then begin strpool[t+1]:=34;
for j:=t-1 downto s do strpool[j+1]:=strpool[j];strpool[s]:=34;
poolptr:=poolptr+2;end;end;
if areadelimiter=0 then curarea:=345 else begin curarea:=strptr;
strstart[strptr+1]:=strstart[strptr]+areadelimiter;incr(strptr);
tempstr:=searchstring(curarea);if tempstr>0 then begin curarea:=tempstr;
decr(strptr);
for j:=strstart[strptr+1]to poolptr-1 do begin strpool[j-areadelimiter]
:=strpool[j];end;poolptr:=poolptr-areadelimiter;end;end;
if extdelimiter=0 then begin curext:=345;curname:=slowmakestring;
end else begin curname:=strptr;
strstart[strptr+1]:=strstart[strptr]+extdelimiter-areadelimiter-1;
incr(strptr);curext:=makestring;decr(strptr);
tempstr:=searchstring(curname);if tempstr>0 then begin curname:=tempstr;
decr(strptr);
for j:=strstart[strptr+1]to poolptr-1 do begin strpool[j-extdelimiter+
areadelimiter+1]:=strpool[j];end;
poolptr:=poolptr-extdelimiter+areadelimiter+1;end;
curext:=slowmakestring;end;end;
{:546}{548:}procedure packfilename(n,a,e:strnumber);var k:integer;
c:ASCIIcode;j:poolpointer;begin k:=0;
if nameoffile then libcfree(nameoffile);
nameoffile:=xmallocarray(ASCIIcode,(strstart[a+1]-strstart[a])+(strstart
[n+1]-strstart[n])+(strstart[e+1]-strstart[e])+1);
for j:=strstart[a]to strstart[a+1]-1 do begin c:=strpool[j];
if not(c=34)then begin incr(k);if k<=maxint then nameoffile[k]:=xchr[c];
end end;for j:=strstart[n]to strstart[n+1]-1 do begin c:=strpool[j];
if not(c=34)then begin incr(k);if k<=maxint then nameoffile[k]:=xchr[c];
end end;for j:=strstart[e]to strstart[e+1]-1 do begin c:=strpool[j];
if not(c=34)then begin incr(k);if k<=maxint then nameoffile[k]:=xchr[c];
end end;if k<=maxint then namelength:=k else namelength:=maxint;
nameoffile[namelength+1]:=0;end;
{:548}{552:}procedure packbufferedname(n:smallnumber;a,b:integer);
var k:integer;c:ASCIIcode;j:integer;
begin if n+b-a+5>maxint then b:=a+maxint-n-5;k:=0;
if nameoffile then libcfree(nameoffile);
nameoffile:=xmallocarray(ASCIIcode,n+(b-a+1)+5);
for j:=1 to n do begin c:=xord[ucharcast(TEXformatdefault[j])];
if not(c=34)then begin incr(k);if k<=maxint then nameoffile[k]:=xchr[c];
end end;for j:=a to b do begin c:=buffer[j];
if not(c=34)then begin incr(k);if k<=maxint then nameoffile[k]:=xchr[c];
end end;
for j:=formatdefaultlength-3 to formatdefaultlength do begin c:=xord[
ucharcast(TEXformatdefault[j])];if not(c=34)then begin incr(k);
if k<=maxint then nameoffile[k]:=xchr[c];end end;
if k<=maxint then namelength:=k else namelength:=maxint;
nameoffile[namelength+1]:=0;end;
{:552}{554:}function makenamestring:strnumber;var k:1..maxint;
saveareadelimiter,saveextdelimiter:poolpointer;
savenameinprogress,savestopatspace:boolean;
begin if(poolptr+namelength>poolsize)or(strptr=maxstrings)or((poolptr-
strstart[strptr])>0)then makenamestring:=63 else begin for k:=1 to
namelength do begin strpool[poolptr]:=xord[nameoffile[k]];incr(poolptr);
end;makenamestring:=makestring;saveareadelimiter:=areadelimiter;
saveextdelimiter:=extdelimiter;savenameinprogress:=nameinprogress;
savestopatspace:=stopatspace;nameinprogress:=true;beginname;
stopatspace:=false;k:=1;
while(k<=namelength)and(morename(nameoffile[k]))do incr(k);
stopatspace:=savestopatspace;endname;nameinprogress:=savenameinprogress;
areadelimiter:=saveareadelimiter;extdelimiter:=saveextdelimiter;end;end;
function amakenamestring(var f:alphafile):strnumber;
begin amakenamestring:=makenamestring;end;
function bmakenamestring(var f:bytefile):strnumber;
begin bmakenamestring:=makenamestring;end;
function wmakenamestring(var f:wordfile):strnumber;
begin wmakenamestring:=makenamestring;end;
{:554}{555:}procedure scanfilename;label 30;begin nameinprogress:=true;
beginname;{435:}repeat getxtoken;until curcmd<>10{:435};
while true do begin if(curcmd>12)or(curchr>255)then begin backinput;
goto 30;end;
if(curchr=32)and(curinput.statefield<>0)and(curinput.locfield>curinput.
limitfield)then goto 30;if not morename(curchr)then goto 30;getxtoken;
end;30:endname;nameinprogress:=false;end;
{:555}{558:}procedure packjobname(s:strnumber);begin curarea:=345;
curext:=s;curname:=jobname;packfilename(curname,curarea,curext);end;
{:558}{559:}procedure promptfilename(s,e:strnumber);label 30;
var k:0..bufsize;savedcurname:strnumber;savedcurext:strnumber;
savedcurarea:strnumber;begin if interaction=2 then;
if s=940 then begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(941);
end else begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(942);
end;printfilename(curname,curarea,curext);print(943);
if(e=944)or(e=345)then showcontext;println;
printcstring(promptfilenamehelpmsg);if(e<>345)then begin print(945);
print(e);print(39);end;print(41);println;printnl(946);print(s);
if interaction<2 then fatalerror(947);savedcurname:=curname;
savedcurext:=curext;savedcurarea:=curarea;;begin;print(649);terminput;
end;{560:}begin beginname;k:=first;
while(buffer[k]=32)and(k<last)do incr(k);
while true do begin if k=last then goto 30;
if not morename(buffer[k])then goto 30;incr(k);end;30:endname;end{:560};
if((strstart[curname+1]-strstart[curname])=0)and(curext=345)and(curarea=
345)then begin curname:=savedcurname;curext:=savedcurext;
curarea:=savedcurarea;end else if curext=345 then curext:=e;
packfilename(curname,curarea,curext);end;
{:559}{563:}procedure openlogfile;var oldsetting:0..21;k:0..bufsize;
l:0..bufsize;months:constcstring;begin oldsetting:=selector;
if jobname=0 then jobname:=getjobname(950);packjobname(951);
recorderchangefilename(stringcast(nameoffile+1));packjobname(952);
while not aopenout(logfile)do{564:}begin selector:=17;
promptfilename(954,952);end{:564};
texmflogname:=amakenamestring(logfile);selector:=18;logopened:=true;
{565:}begin if srcspecialsp or filelineerrorstylep or parsefirstlinep
then write(logfile,'This is pdfTeX, Version 3.14159265','-2.6',
'-1.40.16')else write(logfile,'This is pdfTeX, Version 3.14159265',
'-2.6','-1.40.16');write(logfile,versionstring);slowprint(formatident);
print(955);printint(eqtb[27198].int);printchar(32);
months:=' JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC';
for k:=3*eqtb[27199].int-2 to 3*eqtb[27199].int do write(logfile,months[
k]);printchar(32);printint(eqtb[27200].int);printchar(32);
printtwo(eqtb[27197].int div 60);printchar(58);
printtwo(eqtb[27197].int mod 60);if(eTeXmode=1)then begin;
writeln(logfile);write(logfile,'entering extended mode');end;
if shellenabledp then begin writeln(logfile);write(logfile,' ');
if restrictedshell then begin write(logfile,'restricted ');end;
write(logfile,'\write18 enabled.')end;
if srcspecialsp then begin writeln(logfile);
write(logfile,' Source specials enabled.')end;
if filelineerrorstylep then begin writeln(logfile);
write(logfile,' file:line:error style messages enabled.')end;
if parsefirstlinep then begin writeln(logfile);
write(logfile,' %&-line parsing enabled.');end;
if translatefilename then begin writeln(logfile);write(logfile,' (');
fputs(translatefilename,logfile);write(logfile,')');end;end{:565};
if mltexenabledp then begin writeln(logfile);
write(logfile,'MLTeX v2.2 enabled');end;
if enctexenabledp then begin writeln(logfile);
write(logfile,' encTeX v. Jun. 2004');
write(logfile,', reencoding enabled');
if translatefilename then begin writeln(logfile);
write(logfile,' (\xordcode, \xchrcode, \xprncode overridden by TCX)');
end;end;inputstack[inputptr]:=curinput;printnl(953);
l:=inputstack[0].limitfield;if buffer[l]=eqtb[27225].int then decr(l);
for k:=1 to l do print(buffer[k]);println;selector:=oldsetting+2;end;
{:563}{566:}procedure startinput;label 30;var tempstr:strnumber;
begin scanfilename;packfilename(curname,curarea,curext);
while true do begin beginfilereading;texinputtype:=1;
if kpseinnameok(stringcast(nameoffile+1))and aopenin(inputfile[curinput.
indexfield],kpsetexformat)then goto 30;endfilereading;
promptfilename(940,345);end;
30:curinput.namefield:=amakenamestring(inputfile[curinput.indexfield]);
sourcefilenamestack[inopen]:=curinput.namefield;
fullsourcefilenamestack[inopen]:=makefullnamestring;
if curinput.namefield=strptr-1 then begin tempstr:=searchstring(curinput
.namefield);if tempstr>0 then begin curinput.namefield:=tempstr;
begin decr(strptr);poolptr:=strstart[strptr];end;end;end;
if jobname=0 then begin jobname:=getjobname(curname);openlogfile;end;
if termoffset+(strstart[fullsourcefilenamestack[inopen]+1]-strstart[
fullsourcefilenamestack[inopen]])>maxprintline-2 then println else if(
termoffset>0)or(fileoffset>0)then printchar(32);printchar(40);
incr(openparens);slowprint(fullsourcefilenamestack[inopen]);
fflush(stdout);curinput.statefield:=33;{1911:}synctexstartinput;{:1911};
{567:}begin line:=1;
if inputln(inputfile[curinput.indexfield],false)then;firmuptheline;
if(eqtb[27225].int<0)or(eqtb[27225].int>255)then decr(curinput.
limitfield)else buffer[curinput.limitfield]:=eqtb[27225].int;
first:=curinput.limitfield+1;curinput.locfield:=curinput.startfield;
end{:567};end;
{:566}{589:}{1880:}function effectivecharinfo(f:internalfontnumber;
c:quarterword):fourquarters;label 10;var ci:fourquarters;basec:integer;
begin if not mltexenabledp then begin effectivecharinfo:=fontinfo[
charbase[f]+c].qqqq;goto 10;end;
if fontec[f]>=c then if fontbc[f]<=c then begin ci:=fontinfo[charbase[f]
+c].qqqq;if(ci.b0>0)then begin effectivecharinfo:=ci;goto 10;end;end;
if c>=eqtb[27232].int then if c<=eqtb[27233].int then if(eqtb[26921+c].
hh.rh>0)then begin basec:=(eqtb[26921+c].hh.rh mod 256);
if fontec[f]>=basec then if fontbc[f]<=basec then begin ci:=fontinfo[
charbase[f]+basec].qqqq;if(ci.b0>0)then begin effectivecharinfo:=ci;
goto 10;end;end;end;effectivecharinfo:=nullcharacter;10:end;
{:1880}function readfontinfo(u:halfword;nom,aire:strnumber;
s:scaled):internalfontnumber;label 30,11,45;var k:fontindex;
nametoolong:boolean;fileopened:boolean;
lf,lh,bc,ec,nw,nh,nd,ni,nl,nk,ne,np:halfword;f:internalfontnumber;
g:internalfontnumber;a,b,c,d:eightbits;qw:fourquarters;sw:scaled;
bchlabel:integer;bchar:0..256;z:scaled;alpha:integer;beta:1..16;
begin g:=0;{591:}{592:}fileopened:=false;
nametoolong:=((strstart[nom+1]-strstart[nom])>255)or((strstart[aire+1]-
strstart[aire])>255);if nametoolong then goto 11;
packfilename(nom,aire,345);if not bopenin(tfmfile)then goto 11;
fileopened:=true{:592};{594:}begin begin lf:=tfmtemp;
if lf>127 then goto 11;tfmtemp:=getc(tfmfile);lf:=lf*256+tfmtemp;end;
tfmtemp:=getc(tfmfile);begin lh:=tfmtemp;if lh>127 then goto 11;
tfmtemp:=getc(tfmfile);lh:=lh*256+tfmtemp;end;tfmtemp:=getc(tfmfile);
begin bc:=tfmtemp;if bc>127 then goto 11;tfmtemp:=getc(tfmfile);
bc:=bc*256+tfmtemp;end;tfmtemp:=getc(tfmfile);begin ec:=tfmtemp;
if ec>127 then goto 11;tfmtemp:=getc(tfmfile);ec:=ec*256+tfmtemp;end;
if(bc>ec+1)or(ec>255)then goto 11;if bc>255 then begin bc:=1;ec:=0;end;
tfmtemp:=getc(tfmfile);begin nw:=tfmtemp;if nw>127 then goto 11;
tfmtemp:=getc(tfmfile);nw:=nw*256+tfmtemp;end;tfmtemp:=getc(tfmfile);
begin nh:=tfmtemp;if nh>127 then goto 11;tfmtemp:=getc(tfmfile);
nh:=nh*256+tfmtemp;end;tfmtemp:=getc(tfmfile);begin nd:=tfmtemp;
if nd>127 then goto 11;tfmtemp:=getc(tfmfile);nd:=nd*256+tfmtemp;end;
tfmtemp:=getc(tfmfile);begin ni:=tfmtemp;if ni>127 then goto 11;
tfmtemp:=getc(tfmfile);ni:=ni*256+tfmtemp;end;tfmtemp:=getc(tfmfile);
begin nl:=tfmtemp;if nl>127 then goto 11;tfmtemp:=getc(tfmfile);
nl:=nl*256+tfmtemp;end;tfmtemp:=getc(tfmfile);begin nk:=tfmtemp;
if nk>127 then goto 11;tfmtemp:=getc(tfmfile);nk:=nk*256+tfmtemp;end;
tfmtemp:=getc(tfmfile);begin ne:=tfmtemp;if ne>127 then goto 11;
tfmtemp:=getc(tfmfile);ne:=ne*256+tfmtemp;end;tfmtemp:=getc(tfmfile);
begin np:=tfmtemp;if np>127 then goto 11;tfmtemp:=getc(tfmfile);
np:=np*256+tfmtemp;end;
if lf<>6+lh+(ec-bc+1)+nw+nh+nd+ni+nl+nk+ne+np then goto 11;
if(nw=0)or(nh=0)or(nd=0)or(ni=0)then goto 11;end{:594};
{595:}lf:=lf-6-lh;if np<7 then lf:=lf+7-np;
if(fontptr=fontmax)or(fmemptr+lf>fontmemsize)then{596:}begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(957);
end;sprintcs(u);printchar(61);printfilename(nom,aire,345);
if s>=0 then begin print(895);printscaled(s);print(312);
end else if s<>-1000 then begin print(958);printint(-s);end;print(967);
begin helpptr:=4;helpline[3]:=968;helpline[2]:=969;helpline[1]:=970;
helpline[0]:=971;end;error;goto 30;end{:596};f:=fontptr+1;
charbase[f]:=fmemptr-bc;widthbase[f]:=charbase[f]+ec+1;
heightbase[f]:=widthbase[f]+nw;depthbase[f]:=heightbase[f]+nh;
italicbase[f]:=depthbase[f]+nd;ligkernbase[f]:=italicbase[f]+ni;
kernbase[f]:=ligkernbase[f]+nl-256*(128);
extenbase[f]:=kernbase[f]+256*(128)+nk;
parambase[f]:=extenbase[f]+ne{:595};{597:}begin if lh<2 then goto 11;
begin tfmtemp:=getc(tfmfile);a:=tfmtemp;qw.b0:=a;tfmtemp:=getc(tfmfile);
b:=tfmtemp;qw.b1:=b;tfmtemp:=getc(tfmfile);c:=tfmtemp;qw.b2:=c;
tfmtemp:=getc(tfmfile);d:=tfmtemp;qw.b3:=d;fontcheck[f]:=qw;end;
tfmtemp:=getc(tfmfile);begin z:=tfmtemp;if z>127 then goto 11;
tfmtemp:=getc(tfmfile);z:=z*256+tfmtemp;end;tfmtemp:=getc(tfmfile);
z:=z*256+tfmtemp;tfmtemp:=getc(tfmfile);z:=(z*16)+(tfmtemp div 16);
if z<65536 then goto 11;while lh>2 do begin tfmtemp:=getc(tfmfile);
tfmtemp:=getc(tfmfile);tfmtemp:=getc(tfmfile);tfmtemp:=getc(tfmfile);
decr(lh);end;fontdsize[f]:=z;
if s<>-1000 then if s>=0 then z:=s else z:=xnoverd(z,-s,1000);
fontsize[f]:=z;end{:597};
{598:}for k:=fmemptr to widthbase[f]-1 do begin begin tfmtemp:=getc(
tfmfile);a:=tfmtemp;qw.b0:=a;tfmtemp:=getc(tfmfile);b:=tfmtemp;qw.b1:=b;
tfmtemp:=getc(tfmfile);c:=tfmtemp;qw.b2:=c;tfmtemp:=getc(tfmfile);
d:=tfmtemp;qw.b3:=d;fontinfo[k].qqqq:=qw;end;
if(a>=nw)or(b div 16>=nh)or(b mod 16>=nd)or(c div 4>=ni)then goto 11;
case c mod 4 of 1:if d>=nl then goto 11;3:if d>=ne then goto 11;
2:{599:}begin begin if(d<bc)or(d>ec)then goto 11 end;
while d<k+bc-fmemptr do begin qw:=fontinfo[charbase[f]+d].qqqq;
if((qw.b2)mod 4)<>2 then goto 45;d:=qw.b3;end;
if d=k+bc-fmemptr then goto 11;45:end{:599};others:end;end{:598};
{601:}begin{602:}begin alpha:=16;if z>=134217728 then pdferror(593,972);
while z>=8388608 do begin z:=z div 2;alpha:=alpha+alpha;end;
beta:=256 div alpha;alpha:=alpha*z;end{:602};
for k:=widthbase[f]to ligkernbase[f]-1 do begin tfmtemp:=getc(tfmfile);
a:=tfmtemp;tfmtemp:=getc(tfmfile);b:=tfmtemp;tfmtemp:=getc(tfmfile);
c:=tfmtemp;tfmtemp:=getc(tfmfile);d:=tfmtemp;
sw:=(((((d*z)div 256)+(c*z))div 256)+(b*z))div beta;
if a=0 then fontinfo[k].int:=sw else if a=255 then fontinfo[k].int:=sw-
alpha else goto 11;end;if fontinfo[widthbase[f]].int<>0 then goto 11;
if fontinfo[heightbase[f]].int<>0 then goto 11;
if fontinfo[depthbase[f]].int<>0 then goto 11;
if fontinfo[italicbase[f]].int<>0 then goto 11;end{:601};
{603:}bchlabel:=32767;bchar:=256;
if nl>0 then begin for k:=ligkernbase[f]to kernbase[f]+256*(128)-1 do
begin begin tfmtemp:=getc(tfmfile);a:=tfmtemp;qw.b0:=a;
tfmtemp:=getc(tfmfile);b:=tfmtemp;qw.b1:=b;tfmtemp:=getc(tfmfile);
c:=tfmtemp;qw.b2:=c;tfmtemp:=getc(tfmfile);d:=tfmtemp;qw.b3:=d;
fontinfo[k].qqqq:=qw;end;
if a>128 then begin if 256*c+d>=nl then goto 11;
if a=255 then if k=ligkernbase[f]then bchar:=b;
end else begin if b<>bchar then begin begin if(b<bc)or(b>ec)then goto 11
end;qw:=fontinfo[charbase[f]+b].qqqq;if not(qw.b0>0)then goto 11;end;
if c<128 then begin begin if(d<bc)or(d>ec)then goto 11 end;
qw:=fontinfo[charbase[f]+d].qqqq;if not(qw.b0>0)then goto 11;
end else if 256*(c-128)+d>=nk then goto 11;
if a<128 then if k-ligkernbase[f]+a+1>=nl then goto 11;end;end;
if a=255 then bchlabel:=256*c+d;end;
for k:=kernbase[f]+256*(128)to extenbase[f]-1 do begin tfmtemp:=getc(
tfmfile);a:=tfmtemp;tfmtemp:=getc(tfmfile);b:=tfmtemp;
tfmtemp:=getc(tfmfile);c:=tfmtemp;tfmtemp:=getc(tfmfile);d:=tfmtemp;
sw:=(((((d*z)div 256)+(c*z))div 256)+(b*z))div beta;
if a=0 then fontinfo[k].int:=sw else if a=255 then fontinfo[k].int:=sw-
alpha else goto 11;end;{:603};
{604:}for k:=extenbase[f]to parambase[f]-1 do begin begin tfmtemp:=getc(
tfmfile);a:=tfmtemp;qw.b0:=a;tfmtemp:=getc(tfmfile);b:=tfmtemp;qw.b1:=b;
tfmtemp:=getc(tfmfile);c:=tfmtemp;qw.b2:=c;tfmtemp:=getc(tfmfile);
d:=tfmtemp;qw.b3:=d;fontinfo[k].qqqq:=qw;end;
if a<>0 then begin begin if(a<bc)or(a>ec)then goto 11 end;
qw:=fontinfo[charbase[f]+a].qqqq;if not(qw.b0>0)then goto 11;end;
if b<>0 then begin begin if(b<bc)or(b>ec)then goto 11 end;
qw:=fontinfo[charbase[f]+b].qqqq;if not(qw.b0>0)then goto 11;end;
if c<>0 then begin begin if(c<bc)or(c>ec)then goto 11 end;
qw:=fontinfo[charbase[f]+c].qqqq;if not(qw.b0>0)then goto 11;end;
begin begin if(d<bc)or(d>ec)then goto 11 end;
qw:=fontinfo[charbase[f]+d].qqqq;if not(qw.b0>0)then goto 11;end;
end{:604};
{605:}begin for k:=1 to np do if k=1 then begin tfmtemp:=getc(tfmfile);
sw:=tfmtemp;if sw>127 then sw:=sw-256;tfmtemp:=getc(tfmfile);
sw:=sw*256+tfmtemp;tfmtemp:=getc(tfmfile);sw:=sw*256+tfmtemp;
tfmtemp:=getc(tfmfile);
fontinfo[parambase[f]].int:=(sw*16)+(tfmtemp div 16);
end else begin tfmtemp:=getc(tfmfile);a:=tfmtemp;tfmtemp:=getc(tfmfile);
b:=tfmtemp;tfmtemp:=getc(tfmfile);c:=tfmtemp;tfmtemp:=getc(tfmfile);
d:=tfmtemp;sw:=(((((d*z)div 256)+(c*z))div 256)+(b*z))div beta;
if a=0 then fontinfo[parambase[f]+k-1].int:=sw else if a=255 then
fontinfo[parambase[f]+k-1].int:=sw-alpha else goto 11;end;
if feof(tfmfile)then goto 11;
for k:=np+1 to 7 do fontinfo[parambase[f]+k-1].int:=0;end{:605};
{606:}if np>=7 then fontparams[f]:=np else fontparams[f]:=7;
hyphenchar[f]:=eqtb[27223].int;skewchar[f]:=eqtb[27224].int;
if bchlabel<nl then bcharlabel[f]:=bchlabel+ligkernbase[f]else
bcharlabel[f]:=0;fontbchar[f]:=bchar;fontfalsebchar[f]:=bchar;
if bchar<=ec then if bchar>=bc then begin qw:=fontinfo[charbase[f]+bchar
].qqqq;if(qw.b0>0)then fontfalsebchar[f]:=256;end;fontname[f]:=nom;
fontarea[f]:=aire;fontbc[f]:=bc;fontec[f]:=ec;fontglue[f]:=-268435455;
charbase[f]:=charbase[f];widthbase[f]:=widthbase[f];
ligkernbase[f]:=ligkernbase[f];kernbase[f]:=kernbase[f];
extenbase[f]:=extenbase[f];decr(parambase[f]);fmemptr:=fmemptr+lf;
fontptr:=f;g:=f;goto 30{:606}{:591};
11:{590:}begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(957);
end;sprintcs(u);printchar(61);printfilename(nom,aire,345);
if s>=0 then begin print(895);printscaled(s);print(312);
end else if s<>-1000 then begin print(958);printint(-s);end;
if fileopened then print(959)else if nametoolong then print(960)else
print(961);begin helpptr:=5;helpline[4]:=962;helpline[3]:=963;
helpline[2]:=964;helpline[1]:=965;helpline[0]:=966;end;error{:590};
30:if fileopened then bclose(tfmfile);readfontinfo:=g;end;
{:589}{600:}function storescaledf(sq,z:scaled):scaled;
var a,b,c,d:eightbits;sw:scaled;alpha:integer;beta:1..16;
begin alpha:=16;if z>=134217728 then pdferror(593,972);
while z>=8388608 do begin z:=z div 2;alpha:=alpha+alpha;end;
beta:=256 div alpha;alpha:=alpha*z;if sq>=0 then begin d:=sq mod 256;
sq:=sq div 256;c:=sq mod 256;sq:=sq div 256;b:=sq mod 256;
sq:=sq div 256;a:=sq mod 256;
end else begin sq:=(sq+1073741824)+1073741824;d:=sq mod 256;
sq:=sq div 256;c:=sq mod 256;sq:=sq div 256;b:=sq mod 256;
sq:=sq div 256;a:=(sq+128)mod 256;end;
sw:=(((((d*z)div 256)+(c*z))div 256)+(b*z))div beta;
if a=0 then storescaledf:=sw else if a=255 then storescaledf:=sw-alpha
else pdferror(973,974);end;
{:600}{611:}procedure charwarning(f:internalfontnumber;c:eightbits);
var oldsetting:integer;
begin if eqtb[27212].int>0 then begin oldsetting:=eqtb[27206].int;
if(eTeXmode=1)and(eqtb[27212].int>1)then eqtb[27206].int:=1;
begin begindiagnostic;printnl(983);print(c);print(984);
slowprint(fontname[f]);printchar(33);enddiagnostic(false);end;
eqtb[27206].int:=oldsetting;end;end;
{:611}{612:}function newcharacter(f:internalfontnumber;
c:eightbits):halfword;label 10;var p:halfword;ec:quarterword;
begin ec:=effectivechar(false,f,c);
if fontbc[f]<=ec then if fontec[f]>=ec then if(fontinfo[charbase[f]+ec].
qqqq.b0>0)then begin p:=getavail;mem[p].hh.b0:=f;mem[p].hh.b1:=c;
newcharacter:=p;goto 10;end;charwarning(f,c);newcharacter:=-268435455;
10:end;{:612}{628:}procedure dviswap;
begin if dviptr>(2147483647-dvioffset)then begin curs:=-2;
fatalerror(985);end;
if dvilimit=dvibufsize then begin writedvi(0,halfbuf-1);
dvilimit:=halfbuf;dvioffset:=dvioffset+dvibufsize;dviptr:=0;
end else begin writedvi(halfbuf,dvibufsize-1);dvilimit:=dvibufsize;end;
dvigone:=dvigone+halfbuf;end;{:628}{630:}procedure dvifour(x:integer);
begin if x>=0 then begin dvibuf[dviptr]:=x div 16777216;incr(dviptr);
if dviptr=dvilimit then dviswap;end else begin x:=x+1073741824;
x:=x+1073741824;begin dvibuf[dviptr]:=(x div 16777216)+128;incr(dviptr);
if dviptr=dvilimit then dviswap;end;end;x:=x mod 16777216;
begin dvibuf[dviptr]:=x div 65536;incr(dviptr);
if dviptr=dvilimit then dviswap;end;x:=x mod 65536;
begin dvibuf[dviptr]:=x div 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=x mod 256;
incr(dviptr);if dviptr=dvilimit then dviswap;end;end;
{:630}{631:}procedure dvipop(l:integer);
begin if(l=dvioffset+dviptr)and(dviptr>0)then decr(dviptr)else begin
dvibuf[dviptr]:=142;incr(dviptr);if dviptr=dvilimit then dviswap;end;
end;{:631}{632:}procedure dvifontdef(f:internalfontnumber);
var k:poolpointer;begin if f<=256 then begin begin dvibuf[dviptr]:=243;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=f-1;incr(dviptr);if dviptr=dvilimit then dviswap;
end;end else begin begin dvibuf[dviptr]:=244;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=(f-1)div 256;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=(f-1)mod 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;end;
begin dvibuf[dviptr]:=fontcheck[f].b0;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=fontcheck[f].b1;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=fontcheck[f].b2;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=fontcheck[f].b3;incr(dviptr);
if dviptr=dvilimit then dviswap;end;dvifour(fontsize[f]);
dvifour(fontdsize[f]);
begin dvibuf[dviptr]:=(strstart[fontarea[f]+1]-strstart[fontarea[f]]);
incr(dviptr);if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=(strstart[fontname[f]+1]-strstart[fontname[f]]);
incr(dviptr);if dviptr=dvilimit then dviswap;end;
{633:}for k:=strstart[fontarea[f]]to strstart[fontarea[f]+1]-1 do begin
dvibuf[dviptr]:=strpool[k];incr(dviptr);if dviptr=dvilimit then dviswap;
end;
for k:=strstart[fontname[f]]to strstart[fontname[f]+1]-1 do begin dvibuf
[dviptr]:=strpool[k];incr(dviptr);if dviptr=dvilimit then dviswap;
end{:633};end;{:632}{637:}procedure movement(w:scaled;o:eightbits);
label 10,40,45,2,1;var mstate:smallnumber;p,q:halfword;k:integer;
begin q:=getnode(3);mem[q+1].int:=w;mem[q+2].int:=dvioffset+dviptr;
if o=157 then begin mem[q].hh.rh:=downptr;downptr:=q;
end else begin mem[q].hh.rh:=rightptr;rightptr:=q;end;
{641:}p:=mem[q].hh.rh;mstate:=0;
while p<>-268435455 do begin if mem[p+1].int=w then{642:}case mstate+mem
[p].hh.lh of 3,4,15,16:if mem[p+2].int<dvigone then goto 45 else{643:}
begin k:=mem[p+2].int-dvioffset;if k<0 then k:=k+dvibufsize;
dvibuf[k]:=dvibuf[k]+5;mem[p].hh.lh:=1;goto 40;end{:643};
5,9,11:if mem[p+2].int<dvigone then goto 45 else{644:}begin k:=mem[p+2].
int-dvioffset;if k<0 then k:=k+dvibufsize;dvibuf[k]:=dvibuf[k]+10;
mem[p].hh.lh:=2;goto 40;end{:644};1,2,8,13:goto 40;
others:end{:642}else case mstate+mem[p].hh.lh of 1:mstate:=6;
2:mstate:=12;8,13:goto 45;others:end;p:=mem[p].hh.rh;end;45:{:641};
{640:}mem[q].hh.lh:=3;
if abs(w)>=8388608 then begin begin dvibuf[dviptr]:=o+3;incr(dviptr);
if dviptr=dvilimit then dviswap;end;dvifour(w);goto 10;end;
if abs(w)>=32768 then begin begin dvibuf[dviptr]:=o+2;incr(dviptr);
if dviptr=dvilimit then dviswap;end;if w<0 then w:=w+16777216;
begin dvibuf[dviptr]:=w div 65536;incr(dviptr);
if dviptr=dvilimit then dviswap;end;w:=w mod 65536;goto 2;end;
if abs(w)>=128 then begin begin dvibuf[dviptr]:=o+1;incr(dviptr);
if dviptr=dvilimit then dviswap;end;if w<0 then w:=w+65536;goto 2;end;
begin dvibuf[dviptr]:=o;incr(dviptr);if dviptr=dvilimit then dviswap;
end;if w<0 then w:=w+256;goto 1;2:begin dvibuf[dviptr]:=w div 256;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
1:begin dvibuf[dviptr]:=w mod 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;goto 10{:640};
40:{639:}mem[q].hh.lh:=mem[p].hh.lh;
if mem[q].hh.lh=1 then begin begin dvibuf[dviptr]:=o+4;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
while mem[q].hh.rh<>p do begin q:=mem[q].hh.rh;
case mem[q].hh.lh of 3:mem[q].hh.lh:=5;4:mem[q].hh.lh:=6;others:end;end;
end else begin begin dvibuf[dviptr]:=o+9;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
while mem[q].hh.rh<>p do begin q:=mem[q].hh.rh;
case mem[q].hh.lh of 3:mem[q].hh.lh:=4;5:mem[q].hh.lh:=6;others:end;end;
end{:639};10:end;{:637}{645:}procedure prunemovements(l:integer);
label 30,10;var p:halfword;
begin while downptr<>-268435455 do begin if mem[downptr+2].int<l then
goto 30;p:=downptr;downptr:=mem[p].hh.rh;freenode(p,3);end;
30:while rightptr<>-268435455 do begin if mem[rightptr+2].int<l then
goto 10;p:=rightptr;rightptr:=mem[p].hh.rh;freenode(p,3);end;10:end;
{:645}{649:}procedure vlistout;forward;
{:649}{650:}{1613:}procedure specialout(p:halfword);
var oldsetting:0..21;k:poolpointer;
begin if curh<>dvih then begin movement(curh-dvih,143);dvih:=curh;end;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
oldsetting:=selector;selector:=21;specsout:=eqtb[27238].int;
eqtb[27238].int:=mem[p+1].hh.b0-64;mubytesout:=eqtb[27236].int;
eqtb[27236].int:=mem[p+1].hh.b1-64;activenoconvert:=true;
mubyteslog:=eqtb[27237].int;eqtb[27237].int:=0;
if(eqtb[27236].int>0)or(eqtb[27236].int=-1)then eqtb[27237].int:=1;
if(eqtb[27238].int=2)or(eqtb[27238].int=3)then begin if(eqtb[27236].int>
0)or(eqtb[27236].int=-1)then begin specialprinting:=true;
eqtb[27237].int:=1;end;if eqtb[27236].int>1 then csconverting:=true;end;
showtokenlist(mem[mem[p+1].hh.rh].hh.rh,-268435455,poolsize-poolptr);
selector:=oldsetting;
begin if poolptr+1>poolsize then overflow(259,poolsize-initpoolptr);end;
if(poolptr-strstart[strptr])<256 then begin begin dvibuf[dviptr]:=239;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=(poolptr-strstart[strptr]);incr(dviptr);
if dviptr=dvilimit then dviswap;end;
end else begin begin dvibuf[dviptr]:=242;incr(dviptr);
if dviptr=dvilimit then dviswap;end;dvifour((poolptr-strstart[strptr]));
end;
if(eqtb[27238].int=1)or(eqtb[27238].int=3)then for k:=strstart[strptr]to
poolptr-1 do strpool[k]:=xchr[strpool[k]];
for k:=strstart[strptr]to poolptr-1 do begin dvibuf[dviptr]:=strpool[k];
incr(dviptr);if dviptr=dvilimit then dviswap;end;
eqtb[27238].int:=specsout;eqtb[27236].int:=mubytesout;
eqtb[27237].int:=mubyteslog;specialprinting:=false;csconverting:=false;
activenoconvert:=false;poolptr:=strstart[strptr];end;
{:1613}{1615:}procedure writeout(p:halfword);var oldsetting:0..21;
oldmode:integer;j:smallnumber;q,r:halfword;d:integer;clobbered:boolean;
runsystemret:integer;begin mubytesout:=eqtb[27236].int;
eqtb[27236].int:=mem[p+1].hh.b1-64;
if(eqtb[27236].int>2)or(eqtb[27236].int=-1)or(eqtb[27236].int=-2)then
writenoexpanding:=true;{1616:}q:=getavail;mem[q].hh.lh:=637;r:=getavail;
mem[q].hh.rh:=r;mem[r].hh.lh:=19617;begintokenlist(q,4);
begintokenlist(mem[p+1].hh.rh,20);q:=getavail;mem[q].hh.lh:=379;
begintokenlist(q,4);oldmode:=curlist.modefield;curlist.modefield:=0;
curcs:=writeloc;q:=scantoks(false,true);gettoken;
if curtok<>19617 then{1617:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1908);
end;begin helpptr:=2;helpline[1]:=1909;helpline[0]:=1416;end;error;
repeat gettoken;until curtok=19617;end{:1617};
curlist.modefield:=oldmode;endtokenlist{:1616};oldsetting:=selector;
j:=mem[p+1].hh.b0;
if j=18 then selector:=21 else if writeopen[j]then selector:=j else
begin if(j=17)and(selector=19)then selector:=18;printnl(345);end;
activenoconvert:=true;if eqtb[27236].int>1 then csconverting:=true;
mubyteslog:=eqtb[27237].int;
if(eqtb[27236].int>0)or(eqtb[27236].int=-1)then eqtb[27237].int:=1 else
eqtb[27237].int:=0;tokenshow(defref);println;csconverting:=false;
writenoexpanding:=false;activenoconvert:=false;
eqtb[27236].int:=mubytesout;eqtb[27237].int:=mubyteslog;
flushlist(defref);
if j=18 then begin if(eqtb[27206].int<=0)then selector:=18 else selector
:=19;if not logopened then selector:=17;printnl(1900);
for d:=0 to(poolptr-strstart[strptr])-1 do begin print(strpool[strstart[
strptr]+d]);end;print(1901);
if shellenabledp then begin begin if poolptr+1>poolsize then overflow(
259,poolsize-initpoolptr);end;begin strpool[poolptr]:=0;incr(poolptr);
end;clobbered:=false;
for d:=0 to(poolptr-strstart[strptr])-1 do begin strpool[strstart[strptr
]+d]:=xchr[strpool[strstart[strptr]+d]];
if(strpool[strstart[strptr]+d]=0)and(d<(poolptr-strstart[strptr])-1)then
clobbered:=true;end;
if clobbered then print(1902)else begin runsystemret:=runsystem(
conststringcast(addressof(strpool[strstart[strptr]])));
if runsystemret=-1 then print(1903)else if runsystemret=0 then print(
1904)else if runsystemret=1 then print(1905)else if runsystemret=2 then
print(1906)end;end else begin print(1907);end;printchar(46);
printnl(345);println;poolptr:=strstart[strptr];end;selector:=oldsetting;
end;{:1615}{1618:}procedure outwhat(p:halfword);var j:smallnumber;
oldsetting:0..21;
begin case mem[p].hh.b1 of 0,1,2:{1620:}if not doingleaders then begin j
:=mem[p+1].hh.b0;
if mem[p].hh.b1=1 then writeout(p)else begin if writeopen[j]then aclose(
writefile[j]);
if mem[p].hh.b1=2 then writeopen[j]:=false else if j<16 then begin
curname:=mem[p+1].hh.rh;curarea:=mem[p+2].hh.lh;curext:=mem[p+2].hh.rh;
if curext=345 then curext:=944;packfilename(curname,curarea,curext);
while not kpseoutnameok(stringcast(nameoffile+1))or not aopenout(
writefile[j])do promptfilename(1911,944);writeopen[j]:=true;
if logopened then begin oldsetting:=selector;
if(eqtb[27206].int<=0)then selector:=18 else selector:=19;printnl(1912);
printint(j);print(1913);printfilename(curname,curarea,curext);
print(943);printnl(345);println;selector:=oldsetting;end;end;end;
end{:1620};3:specialout(p);4:;21:{1619:}begin pdflastxpos:=curh+4736286;
pdflastypos:=curpageheight-curv-4736286;end{:1619};
others:begin if(6<=mem[p].hh.b1)and(mem[p].hh.b1<=45)then pdferror(1846,
1910)else confusion(1846)end;end;end;
{:1618}{1717:}function newedge(s:smallnumber;w:scaled):halfword;
var p:halfword;begin p:=getnode(3);mem[p].hh.b0:=14;mem[p].hh.b1:=s;
mem[p+1].int:=w;mem[p+2].int:=0;newedge:=p;end;
{:1717}{1721:}function reverse(thisbox,t:halfword;var curg:scaled;
var curglue:real):halfword;label 21,15,30;var l:halfword;p:halfword;
q:halfword;gorder:glueord;gsign:0..2;gluetemp:real;m,n:halfword;
begin gorder:=mem[thisbox+5].hh.b1;gsign:=mem[thisbox+5].hh.b0;l:=t;
p:=tempptr;m:=-268435455;n:=-268435455;
while true do begin while p<>-268435455 do{1722:}21:if(p>=himemmin)then
repeat f:=mem[p].hh.b0;c:=mem[p].hh.b1;
curh:=curh+fontinfo[widthbase[f]+fontinfo[charbase[f]+effectivechar(true
,f,c)].qqqq.b0].int;q:=mem[p].hh.rh;mem[p].hh.rh:=l;l:=p;p:=q;
until not(p>=himemmin)else{1723:}begin q:=mem[p].hh.rh;
case mem[p].hh.b0 of 0,1,2,11:rulewd:=mem[p+1].int;
{1724:}10:begin g:=mem[p+1].hh.lh;rulewd:=mem[g+1].int-curg;
if gsign<>0 then begin if gsign=1 then begin if mem[g].hh.b0=gorder then
begin curglue:=curglue+mem[g+2].int;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end else if mem[g].hh.b1=gorder then begin curglue:=curglue-mem[g+3].int
;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end;rulewd:=rulewd+curg;
{1697:}if(((gsign=1)and(mem[g].hh.b0=gorder))or((gsign=2)and(mem[g].hh.
b1=gorder)))then begin begin if mem[g].hh.rh=-268435455 then freenode(g,
4)else decr(mem[g].hh.rh);end;
if mem[p].hh.b1<100 then begin mem[p].hh.b0:=11;mem[p+1].int:=rulewd;
end else begin g:=getnode(4);mem[g].hh.b0:=4;mem[g].hh.b1:=4;
mem[g+1].int:=rulewd;mem[g+2].int:=0;mem[g+3].int:=0;mem[p+1].hh.lh:=g;
end;end{:1697};end;{:1724}{1725:}6:begin flushnodelist(mem[p+1].hh.rh);
tempptr:=p;p:=getavail;mem[p]:=mem[tempptr+1];mem[p].hh.rh:=q;
freenode(tempptr,2);goto 21;end;
{:1725}{1726:}9:begin rulewd:=mem[p+1].int;
if odd(mem[p].hh.b1)then if mem[LRptr].hh.lh<>(4*(mem[p].hh.b1 div 4)+3)
then begin mem[p].hh.b0:=11;incr(LRproblems);
end else begin begin tempptr:=LRptr;LRptr:=mem[tempptr].hh.rh;
begin mem[tempptr].hh.rh:=avail;avail:=tempptr;
ifdef('STAT')decr(dynused);endif('STAT')end;end;
if n>-268435455 then begin decr(n);decr(mem[p].hh.b1);
end else begin mem[p].hh.b0:=11;
if m>-268435455 then decr(m)else{1727:}begin freenode(p,4);
mem[t].hh.rh:=q;mem[t+1].int:=rulewd;mem[t+2].int:=-curh-rulewd;goto 30;
end{:1727};end;end else begin begin tempptr:=getavail;
mem[tempptr].hh.lh:=(4*(mem[p].hh.b1 div 4)+3);
mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;end;
if(n>-268435455)or((mem[p].hh.b1 div 8)<>curdir)then begin incr(n);
incr(mem[p].hh.b1);end else begin mem[p].hh.b0:=11;incr(m);end;end;end;
{:1726}14:confusion(2019);others:goto 15 end;curh:=curh+rulewd;
15:mem[p].hh.rh:=l;
if mem[p].hh.b0=11 then if(rulewd=0)or(l=-268435455)then begin freenode(
p,4);p:=l;end;l:=p;p:=q;end{:1723}{:1722};
if(t=-268435455)and(m=-268435455)and(n=-268435455)then goto 30;
p:=newmath(0,mem[LRptr].hh.lh);LRproblems:=LRproblems+10000;end;
30:reverse:=l;end;{:1721}procedure hlistout;label 21,13,14,15,22,40;
var baseline:scaled;leftedge:scaled;saveh,savev:scaled;thisbox:halfword;
gorder:glueord;gsign:0..2;p:halfword;saveloc:integer;leaderbox:halfword;
leaderwd:scaled;lx:scaled;outerdoingleaders:boolean;edge:scaled;
prevp:halfword;gluetemp:real;curglue:real;curg:scaled;begin curg:=0;
curglue:=0.0;thisbox:=tempptr;gorder:=mem[thisbox+5].hh.b1;
gsign:=mem[thisbox+5].hh.b0;p:=mem[thisbox+5].hh.rh;incr(curs);
if curs>0 then begin dvibuf[dviptr]:=141;incr(dviptr);
if dviptr=dvilimit then dviswap;end;if curs>maxpush then maxpush:=curs;
saveloc:=dvioffset+dviptr;baseline:=curv;prevp:=thisbox+5;
{1712:}if(eTeXmode=1)then begin{1708:}begin tempptr:=getavail;
mem[tempptr].hh.lh:=0;mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;
end{:1708};
if(mem[thisbox].hh.b1)=2 then if curdir=1 then begin curdir:=0;
curh:=curh-mem[thisbox+1].int;end else mem[thisbox].hh.b1:=0;
if(curdir=1)and((mem[thisbox].hh.b1)<>1)then{1719:}begin saveh:=curh;
tempptr:=p;p:=newkern(0);mem[p+2].int:=0;mem[prevp].hh.rh:=p;curh:=0;
mem[p].hh.rh:=reverse(thisbox,-268435455,curg,curglue);
mem[p+1].int:=-curh;curh:=saveh;mem[thisbox].hh.b1:=1;end{:1719};
end{:1712};leftedge:=curh;{1920:}synctexhlist(thisbox);{:1920};
while p<>-268435455 do{651:}21:if(p>=himemmin)then begin if curh<>dvih
then begin movement(curh-dvih,143);dvih:=curh;end;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
repeat f:=mem[p].hh.b0;c:=mem[p].hh.b1;
if f<>dvif then{652:}begin if not fontused[f]then begin dvifontdef(f);
fontused[f]:=true;end;if f<=64 then begin dvibuf[dviptr]:=f+170;
incr(dviptr);if dviptr=dvilimit then dviswap;
end else if f<=256 then begin begin dvibuf[dviptr]:=235;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=f-1;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
end else begin begin dvibuf[dviptr]:=236;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=(f-1)div 256;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=(f-1)mod 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;end;dvif:=f;end{:652};
if fontec[f]>=c then if fontbc[f]<=c then if(fontinfo[charbase[f]+c].
qqqq.b0>0)then begin if c>=128 then begin dvibuf[dviptr]:=128;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=c;incr(dviptr);if dviptr=dvilimit then dviswap;
end;
curh:=curh+fontinfo[widthbase[f]+fontinfo[charbase[f]+c].qqqq.b0].int;
goto 22;end;
if mltexenabledp then{1881:}begin{1883:}if c>=eqtb[27232].int then if c
<=eqtb[27233].int then if(eqtb[26921+c].hh.rh>0)then begin basec:=(eqtb[
26921+c].hh.rh mod 256);accentc:=(eqtb[26921+c].hh.rh div 256);
if(fontec[f]>=basec)then if(fontbc[f]<=basec)then if(fontec[f]>=accentc)
then if(fontbc[f]<=accentc)then begin iac:=fontinfo[charbase[f]+
effectivechar(true,f,accentc)].qqqq;
ibc:=fontinfo[charbase[f]+effectivechar(true,f,basec)].qqqq;
if(ibc.b0>0)then if(iac.b0>0)then goto 40;end;begindiagnostic;
printnl(2065);print(c);print(1619);print(accentc);print(32);
print(basec);print(984);slowprint(fontname[f]);printchar(33);
enddiagnostic(false);goto 22;end;begindiagnostic;printnl(983);
print(2064);print(c);print(984);slowprint(fontname[f]);printchar(33);
enddiagnostic(false);goto 22{:1883};
40:{1884:}if eqtb[27212].int>99 then begin begindiagnostic;
printnl(2066);print(c);print(1619);print(accentc);print(32);
print(basec);print(984);slowprint(fontname[f]);printchar(46);
enddiagnostic(false);end{:1884};
{1885:}basexheight:=fontinfo[5+parambase[f]].int;
baseslant:=fontinfo[1+parambase[f]].int/65536.0;accentslant:=baseslant;
basewidth:=fontinfo[widthbase[f]+ibc.b0].int;
baseheight:=fontinfo[heightbase[f]+(ibc.b1)div 16].int;
accentwidth:=fontinfo[widthbase[f]+iac.b0].int;
accentheight:=fontinfo[heightbase[f]+(iac.b1)div 16].int;
delta:=round((basewidth-accentwidth)/2.0+baseheight*baseslant-
basexheight*accentslant);dvih:=curh;curh:=curh+delta;
if curh<>dvih then begin movement(curh-dvih,143);dvih:=curh;end;
if((baseheight<>basexheight)and(accentheight>0))then begin curv:=
baseline+(basexheight-baseheight);
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
if accentc>=128 then begin dvibuf[dviptr]:=128;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=accentc;
incr(dviptr);if dviptr=dvilimit then dviswap;end;curv:=baseline;
end else begin if curv<>dviv then begin movement(curv-dviv,157);
dviv:=curv;end;if accentc>=128 then begin dvibuf[dviptr]:=128;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=accentc;incr(dviptr);
if dviptr=dvilimit then dviswap;end;end;curh:=curh+accentwidth;
dvih:=curh;curh:=curh+(-accentwidth-delta);
if curh<>dvih then begin movement(curh-dvih,143);dvih:=curh;end;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
if basec>=128 then begin dvibuf[dviptr]:=128;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=basec;
incr(dviptr);if dviptr=dvilimit then dviswap;end;curh:=curh+basewidth;
dvih:=curh{:1885};end{:1881};22:prevp:=mem[prevp].hh.rh;p:=mem[p].hh.rh;
until not(p>=himemmin);{1923:}synctexcurrent;{:1923};dvih:=curh;
end else{653:}begin case mem[p].hh.b0 of 0,1:{654:}if mem[p+5].hh.rh=
-268435455 then begin{1922:}if mem[p].hh.b0=1 then begin
synctexvoidvlist(p,thisbox);end else begin synctexvoidhlist(p,thisbox);
end;{:1922};curh:=curh+mem[p+1].int;end else begin saveh:=dvih;
savev:=dviv;curv:=baseline+mem[p+4].int;tempptr:=p;
edge:=curh+mem[p+1].int;if curdir=1 then curh:=edge;
if mem[p].hh.b0=1 then vlistout else hlistout;dvih:=saveh;dviv:=savev;
curh:=edge;curv:=baseline;end{:654};2:begin ruleht:=mem[p+3].int;
ruledp:=mem[p+2].int;rulewd:=mem[p+1].int;goto 14;end;
8:{1612:}outwhat(p){:1612};10:{656:}begin g:=mem[p+1].hh.lh;
rulewd:=mem[g+1].int-curg;
if gsign<>0 then begin if gsign=1 then begin if mem[g].hh.b0=gorder then
begin curglue:=curglue+mem[g+2].int;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end else if mem[g].hh.b1=gorder then begin curglue:=curglue-mem[g+3].int
;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end;rulewd:=rulewd+curg;
if(eTeXmode=1)then{1697:}if(((gsign=1)and(mem[g].hh.b0=gorder))or((gsign
=2)and(mem[g].hh.b1=gorder)))then begin begin if mem[g].hh.rh=-268435455
then freenode(g,4)else decr(mem[g].hh.rh);end;
if mem[p].hh.b1<100 then begin mem[p].hh.b0:=11;mem[p+1].int:=rulewd;
end else begin g:=getnode(4);mem[g].hh.b0:=4;mem[g].hh.b1:=4;
mem[g+1].int:=rulewd;mem[g+2].int:=0;mem[g+3].int:=0;mem[p+1].hh.lh:=g;
end;end{:1697};
if mem[p].hh.b1>=100 then{657:}begin leaderbox:=mem[p+1].hh.rh;
if mem[leaderbox].hh.b0=2 then begin ruleht:=mem[leaderbox+3].int;
ruledp:=mem[leaderbox+2].int;goto 14;end;leaderwd:=mem[leaderbox+1].int;
if(leaderwd>0)and(rulewd>0)then begin rulewd:=rulewd+10;
if curdir=1 then curh:=curh-10;edge:=curh+rulewd;lx:=0;
{658:}if mem[p].hh.b1=100 then begin saveh:=curh;
curh:=leftedge+leaderwd*((curh-leftedge)div leaderwd);
if curh<saveh then curh:=curh+leaderwd;
end else begin lq:=rulewd div leaderwd;lr:=rulewd mod leaderwd;
if mem[p].hh.b1=101 then curh:=curh+(lr div 2)else begin lx:=lr div(lq+1
);curh:=curh+((lr-(lq-1)*lx)div 2);end;end{:658};
while curh+leaderwd<=edge do{659:}begin curv:=baseline+mem[leaderbox+4].
int;if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
savev:=dviv;if curh<>dvih then begin movement(curh-dvih,143);dvih:=curh;
end;saveh:=dvih;tempptr:=leaderbox;if curdir=1 then curh:=curh+leaderwd;
outerdoingleaders:=doingleaders;doingleaders:=true;
if mem[leaderbox].hh.b0=1 then vlistout else hlistout;
doingleaders:=outerdoingleaders;dviv:=savev;dvih:=saveh;curv:=baseline;
curh:=saveh+leaderwd+lx;end{:659};
if curdir=1 then curh:=edge else curh:=edge-10;goto 15;end;end{:657};
goto 13;end{:656};40:curh:=curh+mem[p+1].int;
11:begin{1925:}synctexkern(p,thisbox);{:1925};curh:=curh+mem[p+1].int;
end;9:begin{1926:}synctexmath(p,thisbox);{:1926};
{1714:}begin if(eTeXmode=1)then{1715:}begin if odd(mem[p].hh.b1)then if
mem[LRptr].hh.lh=(4*(mem[p].hh.b1 div 4)+3)then begin tempptr:=LRptr;
LRptr:=mem[tempptr].hh.rh;begin mem[tempptr].hh.rh:=avail;
avail:=tempptr;ifdef('STAT')decr(dynused);endif('STAT')end;
end else begin if mem[p].hh.b1>4 then incr(LRproblems);
end else begin begin tempptr:=getavail;
mem[tempptr].hh.lh:=(4*(mem[p].hh.b1 div 4)+3);
mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;end;
if(mem[p].hh.b1 div 8)<>curdir then{1720:}begin saveh:=curh;
tempptr:=mem[p].hh.rh;rulewd:=mem[p+1].int;freenode(p,4);
curdir:=1-curdir;p:=newedge(curdir,rulewd);mem[prevp].hh.rh:=p;
curh:=curh-leftedge+rulewd;
mem[p].hh.rh:=reverse(thisbox,newedge(1-curdir,0),curg,curglue);
mem[p+2].int:=curh;curdir:=1-curdir;curh:=saveh;goto 21;end{:1720};end;
mem[p].hh.b0:=11;end{:1715};curh:=curh+mem[p+1].int;end{:1714};end;
6:{827:}begin mem[memtop-12]:=mem[p+1];
mem[memtop-12].hh.rh:=mem[p].hh.rh;p:=memtop-12;goto 21;end{:827};
{1718:}14:begin curh:=curh+mem[p+1].int;leftedge:=curh+mem[p+2].int;
curdir:=mem[p].hh.b1;end;{:1718}others:end;goto 15;
14:{655:}if(ruleht=-1073741824)then ruleht:=mem[thisbox+3].int;
if(ruledp=-1073741824)then ruledp:=mem[thisbox+2].int;
ruleht:=ruleht+ruledp;
if(ruleht>0)and(rulewd>0)then begin if curh<>dvih then begin movement(
curh-dvih,143);dvih:=curh;end;curv:=baseline+ruledp;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
begin dvibuf[dviptr]:=132;incr(dviptr);if dviptr=dvilimit then dviswap;
end;dvifour(ruleht);dvifour(rulewd);curv:=baseline;dvih:=dvih+rulewd;
end{:655};13:begin curh:=curh+rulewd;
{1924:}synctexhorizontalruleorglue(p,thisbox);{:1924};end;15:prevp:=p;
p:=mem[p].hh.rh;end{:653}{:651};{1921:}synctextsilh(thisbox);{:1921};
{1713:}if(eTeXmode=1)then begin{1716:}begin while mem[LRptr].hh.lh<>0 do
begin if mem[LRptr].hh.lh>4 then LRproblems:=LRproblems+10000;
begin tempptr:=LRptr;LRptr:=mem[tempptr].hh.rh;
begin mem[tempptr].hh.rh:=avail;avail:=tempptr;
ifdef('STAT')decr(dynused);endif('STAT')end;end;end;
begin tempptr:=LRptr;LRptr:=mem[tempptr].hh.rh;
begin mem[tempptr].hh.rh:=avail;avail:=tempptr;
ifdef('STAT')decr(dynused);endif('STAT')end;end;end{:1716};
if(mem[thisbox].hh.b1)=2 then curdir:=1;end{:1713};
prunemovements(saveloc);if curs>0 then dvipop(saveloc);decr(curs);end;
{:650}{660:}procedure vlistout;label 13,14,15;var leftedge:scaled;
topedge:scaled;saveh,savev:scaled;thisbox:halfword;gorder:glueord;
gsign:0..2;p:halfword;saveloc:integer;leaderbox:halfword;
leaderht:scaled;lx:scaled;outerdoingleaders:boolean;edge:scaled;
gluetemp:real;curglue:real;curg:scaled;begin curg:=0;curglue:=0.0;
thisbox:=tempptr;gorder:=mem[thisbox+5].hh.b1;
gsign:=mem[thisbox+5].hh.b0;p:=mem[thisbox+5].hh.rh;incr(curs);
if curs>0 then begin dvibuf[dviptr]:=141;incr(dviptr);
if dviptr=dvilimit then dviswap;end;if curs>maxpush then maxpush:=curs;
saveloc:=dvioffset+dviptr;leftedge:=curh;{1918:}synctexvlist(thisbox);
{:1918};curv:=curv-mem[thisbox+3].int;topedge:=curv;
while p<>-268435455 do{661:}begin if(p>=himemmin)then confusion(987)else
{662:}begin case mem[p].hh.b0 of 0,1:{663:}if mem[p+5].hh.rh=-268435455
then begin curv:=curv+mem[p+3].int;
{1922:}if mem[p].hh.b0=1 then begin synctexvoidvlist(p,thisbox);
end else begin synctexvoidhlist(p,thisbox);end;{:1922};
curv:=curv+mem[p+2].int;end else begin curv:=curv+mem[p+3].int;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
saveh:=dvih;savev:=dviv;
if curdir=1 then curh:=leftedge-mem[p+4].int else curh:=leftedge+mem[p+4
].int;tempptr:=p;if mem[p].hh.b0=1 then vlistout else hlistout;
dvih:=saveh;dviv:=savev;curv:=savev+mem[p+2].int;curh:=leftedge;
end{:663};2:begin ruleht:=mem[p+3].int;ruledp:=mem[p+2].int;
rulewd:=mem[p+1].int;goto 14;end;8:{1611:}outwhat(p){:1611};
10:{665:}begin g:=mem[p+1].hh.lh;ruleht:=mem[g+1].int-curg;
if gsign<>0 then begin if gsign=1 then begin if mem[g].hh.b0=gorder then
begin curglue:=curglue+mem[g+2].int;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end else if mem[g].hh.b1=gorder then begin curglue:=curglue-mem[g+3].int
;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end;ruleht:=ruleht+curg;
if mem[p].hh.b1>=100 then{666:}begin leaderbox:=mem[p+1].hh.rh;
if mem[leaderbox].hh.b0=2 then begin rulewd:=mem[leaderbox+1].int;
ruledp:=0;goto 14;end;
leaderht:=mem[leaderbox+3].int+mem[leaderbox+2].int;
if(leaderht>0)and(ruleht>0)then begin ruleht:=ruleht+10;
edge:=curv+ruleht;lx:=0;
{667:}if mem[p].hh.b1=100 then begin savev:=curv;
curv:=topedge+leaderht*((curv-topedge)div leaderht);
if curv<savev then curv:=curv+leaderht;
end else begin lq:=ruleht div leaderht;lr:=ruleht mod leaderht;
if mem[p].hh.b1=101 then curv:=curv+(lr div 2)else begin lx:=lr div(lq+1
);curv:=curv+((lr-(lq-1)*lx)div 2);end;end{:667};
while curv+leaderht<=edge do{668:}begin if curdir=1 then curh:=leftedge-
mem[leaderbox+4].int else curh:=leftedge+mem[leaderbox+4].int;
if curh<>dvih then begin movement(curh-dvih,143);dvih:=curh;end;
saveh:=dvih;curv:=curv+mem[leaderbox+3].int;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
savev:=dviv;tempptr:=leaderbox;outerdoingleaders:=doingleaders;
doingleaders:=true;
if mem[leaderbox].hh.b0=1 then vlistout else hlistout;
doingleaders:=outerdoingleaders;dviv:=savev;dvih:=saveh;curh:=leftedge;
curv:=savev-mem[leaderbox+3].int+leaderht+lx;end{:668};curv:=edge-10;
goto 15;end;end{:666};goto 13;end{:665};11:curv:=curv+mem[p+1].int;
others:end;goto 15;
14:{664:}if(rulewd=-1073741824)then rulewd:=mem[thisbox+1].int;
ruleht:=ruleht+ruledp;curv:=curv+ruleht;
if(ruleht>0)and(rulewd>0)then begin if curdir=1 then curh:=curh-rulewd;
if curh<>dvih then begin movement(curh-dvih,143);dvih:=curh;end;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
begin dvibuf[dviptr]:=137;incr(dviptr);if dviptr=dvilimit then dviswap;
end;dvifour(ruleht);dvifour(rulewd);curh:=leftedge;end;goto 15{:664};
13:curv:=curv+ruleht;end{:662};15:p:=mem[p].hh.rh;end{:661};
{1919:}synctextsilv(thisbox);{:1919};prunemovements(saveloc);
if curs>0 then dvipop(saveloc);decr(curs);end;
{:660}{669:}procedure dvishipout(p:halfword);label 30;
var pageloc:integer;j,k:0..9;s:poolpointer;oldsetting:0..21;
begin{1916:}pdfoutputvalue:=eqtb[27239].int;
synctexsheet(eqtb[27194].int);{:1916};
begin if eqtb[27211].int>0 then begin printnl(345);println;print(988);
end;if termoffset>maxprintline-9 then println else if(termoffset>0)or(
fileoffset>0)then printchar(32);printchar(91);j:=9;
while(eqtb[27281+j].int=0)and(j>0)do decr(j);
for k:=0 to j do begin printint(eqtb[27281+k].int);
if k<j then printchar(46);end;fflush(stdout);
if eqtb[27211].int>0 then begin printchar(93);begindiagnostic;
showbox(p);enddiagnostic(true);end;
{671:}{672:}if(mem[p+3].int>1073741823)or(mem[p+2].int>1073741823)or(mem
[p+3].int+mem[p+2].int+eqtb[27812].int>1073741823)or(mem[p+1].int+eqtb[
27811].int>1073741823)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(992);
end;begin helpptr:=2;helpline[1]:=993;helpline[0]:=994;end;error;
if eqtb[27211].int<=0 then begin begindiagnostic;printnl(995);
showbox(p);enddiagnostic(true);end;goto 30;end;
if mem[p+3].int+mem[p+2].int+eqtb[27812].int>maxv then maxv:=mem[p+3].
int+mem[p+2].int+eqtb[27812].int;
if mem[p+1].int+eqtb[27811].int>maxh then maxh:=mem[p+1].int+eqtb[27811]
.int{:672};{648:}dvih:=0;dviv:=0;curh:=eqtb[27811].int;dvif:=0;
{647:}curhoffset:=eqtb[27811].int;curvoffset:=eqtb[27812].int;
if eqtb[27816].int<>0 then curpagewidth:=eqtb[27816].int else
curpagewidth:=mem[p+1].int+2*curhoffset+2*4736286;
if eqtb[27817].int<>0 then curpageheight:=eqtb[27817].int else
curpageheight:=mem[p+3].int+mem[p+2].int+2*curvoffset+2*4736286{:647};
if outputfilename=0 then begin if jobname=0 then openlogfile;
packjobname(948);while not bopenout(dvifile)do promptfilename(949,948);
outputfilename:=bmakenamestring(dvifile);end;
if totalpages=0 then begin begin dvibuf[dviptr]:=247;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=2;
incr(dviptr);if dviptr=dvilimit then dviswap;end;dvifour(25400000);
dvifour(473628672);preparemag;dvifour(eqtb[27194].int);
if outputcomment then begin l:=strlen(outputcomment);
begin dvibuf[dviptr]:=l;incr(dviptr);if dviptr=dvilimit then dviswap;
end;for s:=0 to l-1 do begin dvibuf[dviptr]:=outputcomment[s];
incr(dviptr);if dviptr=dvilimit then dviswap;end;
end else begin oldsetting:=selector;selector:=21;print(986);
printint(eqtb[27200].int);printchar(46);printtwo(eqtb[27199].int);
printchar(46);printtwo(eqtb[27198].int);printchar(58);
printtwo(eqtb[27197].int div 60);printtwo(eqtb[27197].int mod 60);
selector:=oldsetting;begin dvibuf[dviptr]:=(poolptr-strstart[strptr]);
incr(dviptr);if dviptr=dvilimit then dviswap;end;
for s:=strstart[strptr]to poolptr-1 do begin dvibuf[dviptr]:=strpool[s];
incr(dviptr);if dviptr=dvilimit then dviswap;end;
poolptr:=strstart[strptr];end;end{:648};pageloc:=dvioffset+dviptr;
begin dvibuf[dviptr]:=139;incr(dviptr);if dviptr=dvilimit then dviswap;
end;for k:=0 to 9 do dvifour(eqtb[27281+k].int);dvifour(lastbop);
lastbop:=pageloc;curv:=mem[p+3].int+eqtb[27812].int;tempptr:=p;
if mem[p].hh.b0=1 then vlistout else hlistout;begin dvibuf[dviptr]:=140;
incr(dviptr);if dviptr=dvilimit then dviswap;end;incr(totalpages);
curs:=-1;
ifdef('IPC')if ipcon>0 then begin if dvilimit=halfbuf then begin
writedvi(halfbuf,dvibufsize-1);flushdvi;dvigone:=dvigone+halfbuf;end;
if dviptr>(2147483647-dvioffset)then begin curs:=-2;fatalerror(985);end;
if dviptr>0 then begin writedvi(0,dviptr-1);flushdvi;
dvioffset:=dvioffset+dviptr;dvigone:=dvigone+dviptr;end;dviptr:=0;
dvilimit:=dvibufsize;ipcpage(dvigone);end;endif('IPC');30:{:671};
if(eTeXmode=1)then{1728:}begin if LRproblems>0 then begin{1711:}begin
println;printnl(2016);printint(LRproblems div 10000);print(2017);
printint(LRproblems mod 10000);print(2018);LRproblems:=0;end{:1711};
printchar(41);println;end;
if(LRptr<>-268435455)or(curdir<>0)then confusion(2020);end{:1728};
if eqtb[27211].int<=0 then printchar(93);deadcycles:=0;fflush(stdout);
{670:}ifdef('STAT')if eqtb[27208].int>1 then begin printnl(989);
printint(varused);printchar(38);printint(dynused);printchar(59);end;
endif('STAT')flushnodelist(p);
ifdef('STAT')if eqtb[27208].int>1 then begin print(990);
printint(varused);printchar(38);printint(dynused);print(991);
printint(himemmin-lomemmax-1);println;end;endif('STAT'){:670};end;
{1917:}synctexteehs;{:1917};end;
{:669}{676:}function getpdfcompresslevel:integer;
begin getpdfcompresslevel:=eqtb[27240].int;end;
function getpdfsuppresswarningdupmap:integer;
begin getpdfsuppresswarningdupmap:=eqtb[27267].int;end;
function getpdfsuppresswarningpagegroup:integer;
begin getpdfsuppresswarningpagegroup:=eqtb[27268].int;end;
function getnullfont:internalfontnumber;begin getnullfont:=0;end;
function getfontbase:internalfontnumber;begin getfontbase:=0;end;
function getnullcs:halfword;begin getnullcs:=513;end;
function getnullptr:halfword;begin getnullptr:=-268435455;end;
function gettexint(code:integer):integer;
begin gettexint:=eqtb[27177+code].int;end;
function gettexdimen(code:integer):scaled;
begin gettexdimen:=eqtb[27793+code].int;end;
function getxheight(f:internalfontnumber):scaled;
begin getxheight:=fontinfo[5+parambase[f]].int;end;
function getcharwidth(f:internalfontnumber;c:eightbits):scaled;
begin if((fontbc[f]<=c)and(c<=fontec[f])and(fontinfo[charbase[f]+c].qqqq
.b0>0))then getcharwidth:=fontinfo[widthbase[f]+fontinfo[charbase[f]+c].
qqqq.b0].int else getcharwidth:=0;end;
function getcharheight(f:internalfontnumber;c:eightbits):scaled;
begin if((fontbc[f]<=c)and(c<=fontec[f])and(fontinfo[charbase[f]+c].qqqq
.b0>0))then getcharheight:=fontinfo[heightbase[f]+(fontinfo[charbase[f]+
c].qqqq.b1)div 16].int else getcharheight:=0;end;
function getchardepth(f:internalfontnumber;c:eightbits):scaled;
begin if((fontbc[f]<=c)and(c<=fontec[f])and(fontinfo[charbase[f]+c].qqqq
.b0>0))then getchardepth:=fontinfo[depthbase[f]+(fontinfo[charbase[f]+c]
.qqqq.b1)mod 16].int else getchardepth:=0;end;
function getquad(f:internalfontnumber):scaled;
begin getquad:=fontinfo[6+parambase[f]].int;end;
function getslant(f:internalfontnumber):scaled;
begin getslant:=fontinfo[1+parambase[f]].int;end;
function newdummyfont:internalfontnumber;
begin newdummyfont:=readfontinfo(513,1002,345,-1000);end;
{:676}{677:}procedure shortdisplayn(p,m:integer);var n:integer;
i:integer;begin i:=0;fontinshortdisplay:=0;if p=-268435455 then goto 10;
while p>memmin do begin if(p>=himemmin)then begin if p<=memend then
begin if mem[p].hh.b0<>fontinshortdisplay then begin if(mem[p].hh.b0<0)
or(mem[p].hh.b0>fontmax)then printchar(42)else printfontidentifier(mem[p
].hh.b0);printchar(32);fontinshortdisplay:=mem[p].hh.b0;end;
print(mem[p].hh.b1);end;
end else begin if(mem[p].hh.b0=10)or(mem[p].hh.b0=7)or(mem[p].hh.b0=12)
or((mem[p].hh.b0=11)and(mem[p].hh.b1=1))then incr(i);
if i>=m then goto 10;if(mem[p].hh.b0=7)then begin print(124);
shortdisplay(mem[p+1].hh.lh);print(124);shortdisplay(mem[p+1].hh.rh);
print(124);n:=mem[p].hh.b1;
while n>0 do begin if mem[p].hh.rh<>-268435455 then p:=mem[p].hh.rh;
decr(n);end;
end else{193:}case mem[p].hh.b0 of 0,1,3,8,4,5,13:print(313);
2:printchar(124);10:if mem[p+1].hh.lh<>membot then printchar(32);
9:if mem[p].hh.b1>=4 then print(313)else printchar(36);
6:shortdisplay(mem[p+1].hh.rh);7:begin shortdisplay(mem[p+1].hh.lh);
shortdisplay(mem[p+1].hh.rh);n:=mem[p].hh.b1;
while n>0 do begin if mem[p].hh.rh<>-268435455 then p:=mem[p].hh.rh;
decr(n);end;end;others:end{:193};end;p:=mem[p].hh.rh;
if p=-268435455 then goto 10;end;fflush(stdout);end;
{:677}{681:}function pdfgetmem(s:integer):integer;var a:integer;
begin if s>suppdfmemsize-pdfmemptr then overflow(1003,pdfmemsize);
if pdfmemptr+s>pdfmemsize then begin a:=0.2*pdfmemsize;
if pdfmemptr+s>pdfmemsize+a then pdfmemsize:=pdfmemptr+s else if
pdfmemsize<suppdfmemsize-a then pdfmemsize:=pdfmemsize+a else pdfmemsize
:=suppdfmemsize;pdfmem:=xreallocarray(pdfmem,integer,pdfmemsize);end;
pdfgetmem:=pdfmemptr;pdfmemptr:=pdfmemptr+s;end;
{:681}{685:}function fixint(val,min,max:integer):integer;
begin if val<min then fixint:=min else if val>max then fixint:=max else
fixint:=val;end;{:685}{686:}procedure checkpdfminorversion;
begin if not pdfminorversionwritten then begin pdfminorversionwritten:=
true;if(eqtb[27248].int<0)or(eqtb[27248].int>9)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1005);
end;println;begin helpptr:=2;helpline[1]:=1006;helpline[0]:=1007;end;
interror(eqtb[27248].int);eqtb[27248].int:=4;end;
fixedpdfminorversion:=eqtb[27248].int;
fixedgamma:=fixint(eqtb[27252].int,0,1000000);
fixedimagegamma:=fixint(eqtb[27253].int,0,1000000);
fixedimagehicolor:=fixint(eqtb[27254].int,0,1);
fixedimageapplygamma:=fixint(eqtb[27255].int,0,1);
fixedpdfobjcompresslevel:=fixint(eqtb[27259].int,0,3);
fixedpdfdraftmode:=fixint(eqtb[27264].int,0,1);
fixedinclusioncopyfont:=fixint(eqtb[27265].int,0,1);
if(fixedpdfminorversion>=5)and(fixedpdfobjcompresslevel>0)then
pdfosenable:=true else begin if fixedpdfobjcompresslevel>0 then begin
pdfwarning(1008,1009,true,true);fixedpdfobjcompresslevel:=0;end;
pdfosenable:=false;end;ensurepdfopen;fixpdfoutput;pdfprint(1010);
begin pdfprintint(fixedpdfminorversion);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfprint(37);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=208;incr(pdfptr);end;end;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=212;incr(pdfptr);end;end;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=197;incr(pdfptr);end;end;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=216;incr(pdfptr);end;end;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;
end else begin if fixedpdfminorversion<>eqtb[27248].int then pdferror(
1011,1012);end;end;{:686}{687:}procedure ensurepdfopen;
begin if outputfilename<>0 then goto 10;if jobname=0 then openlogfile;
packjobname(1013);
if fixedpdfdraftmode=0 then while not bopenout(pdffile)do promptfilename
(949,1013);outputfilename:=bmakenamestring(pdffile);end;
{:687}{688:}procedure pdfflush;var savedpdfgone:longinteger;
begin if not pdfosmode then begin savedpdfgone:=pdfgone;
case zipwritestate of 0:if pdfptr>0 then begin if fixedpdfdraftmode=0
then writepdf(0,pdfptr-1);pdfgone:=pdfgone+pdfptr;
pdflastbyte:=pdfbuf[pdfptr-1];end;
1:if fixedpdfdraftmode=0 then writezip(false);
2:begin if fixedpdfdraftmode=0 then writezip(true);zipwritestate:=0;end;
end;pdfptr:=0;if savedpdfgone>pdfgone then pdferror(1014,1015);end;end;
procedure pdfbeginstream;begin begin pdfprint(1016);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfseekwritelength:=true;pdfstreamlengthoffset:=(pdfgone+pdfptr)-11;
pdfstreamlength:=0;pdflastbyte:=0;
if eqtb[27240].int>0 then begin begin pdfprint(1017);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;begin pdfprint(1018);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;begin pdfprint(1019);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfflush;
zipwritestate:=1;end else begin begin pdfprint(1018);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;begin pdfprint(1019);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfsaveoffset:=(pdfgone+pdfptr);end;end;procedure pdfendstream;
begin if zipwritestate=1 then zipwritestate:=2 else pdfstreamlength:=(
pdfgone+pdfptr)-pdfsaveoffset;pdfflush;
if pdfseekwritelength then writestreamlength(pdfstreamlength,
pdfstreamlengthoffset);pdfseekwritelength:=false;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;begin pdfprint(1020);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfendobj;end;
{:688}{693:}procedure advcharwidth(f:internalfontnumber;c:eightbits);
var w,sout:scaled;s:integer;
begin w:=fontinfo[widthbase[f]+fontinfo[charbase[f]+effectivechar(true,f
,c)].qqqq.b0].int;
if hasfmentry(f)then begin if pdfcurTma=0 then begin begin if
dividescaled(w,pdffontsize[f],4)<>0 then end;
pdfdeltah:=pdfdeltah+scaledout;
end else begin s:=dividescaled(roundxnoverd(w,1000,1000+pdfcurTma),
pdffontsize[f],4);
sout:=roundxnoverd(roundxnoverd(pdffontsize[f],abs(s),10000),1000+
pdfcurTma,1000);if s<0 then sout:=-sout;pdfdeltah:=pdfdeltah+sout;end;
end else pdfdeltah:=pdfdeltah+getpkcharwidth(f,w);end;
procedure pdfprintreal(m,d:integer);
begin if m<0 then begin begin begin if pdfosmode and(1+pdfptr>pdfbufsize
)then pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then
overflow(1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize
)then pdfflush;end;begin pdfbuf[pdfptr]:=45;incr(pdfptr);end;end;m:=-m;
end;pdfprintint(m div tenpow[d]);m:=m mod tenpow[d];
if m>0 then begin begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=46;incr(pdfptr);end;end;decr(d);
while m<tenpow[d]do begin begin begin if pdfosmode and(1+pdfptr>
pdfbufsize)then pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)
then overflow(1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>
pdfbufsize)then pdfflush;end;begin pdfbuf[pdfptr]:=48;incr(pdfptr);end;
end;decr(d);end;while m mod 10=0 do m:=m div 10;pdfprintint(m);end;end;
procedure pdfprintbp(s:scaled);
begin pdfprintreal(dividescaled(s,onehundredbp,fixeddecimaldigits+2),
fixeddecimaldigits);end;procedure pdfprintmagbp(s:scaled);
begin preparemag;
if eqtb[27194].int<>1000 then s:=roundxnoverd(s,eqtb[27194].int,1000);
pdfprintbp(s);end;{:693}{695:}procedure pdfsetorigin(h,v:scaled);
begin if(abs(h-pdforiginh)>=minbpval)or(abs(v-pdforiginv)>=minbpval)then
begin pdfprint(1029);pdfprintbp(h-pdforiginh);
pdforiginh:=pdforiginh+scaledout;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;pdfprintbp(pdforiginv-v);
pdforiginv:=pdforiginv-scaledout;begin pdfprint(1030);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;pdfh:=pdforiginh;
pdftjstarth:=pdfh;pdfv:=pdforiginv;end;
procedure pdfsetorigintemp(h,v:scaled);
begin if(abs(h-pdforiginh)>=minbpval)or(abs(v-pdforiginv)>=minbpval)then
begin pdfprint(1029);pdfprintbp(h-pdforiginh);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;pdfprintbp(pdforiginv-v);
begin pdfprint(1030);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;end;
procedure pdfendstring;
begin if pdfdoingstring then begin pdfprint(1031);pdfdoingstring:=false;
end;end;procedure pdfendstringnl;
begin if pdfdoingstring then begin begin pdfprint(1031);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfdoingstring:=false;
end;end;procedure pdfsettextmatrix(v,vout:scaled;f:internalfontnumber);
var pdfnewTma:integer;
begin begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
if f=pdff then pdfnewTma:=pdfcurTma else if not pdffontautoexpand[f]then
pdfnewTma:=0 else pdfnewTma:=pdffontexpandratio[f];
if(pdfnewTma<>0)or((pdfnewTma=0)and(pdfcurTma<>0))then begin
pdfprintreal(1000+pdfnewTma,3);pdfprint(1032);
pdfprintbp(curh-pdforiginh);pdfh:=pdforiginh+scaledout;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintbp(pdforiginv-curv);pdfv:=pdforiginv-scaledout;pdfprint(1033);
pdfcurTma:=pdfnewTma;pdfassert(pdfcurTma>-1000);
end else begin pdfprintbp(curh-pdftjstarth);pdfh:=pdftjstarth+scaledout;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintreal(v,fixeddecimaldigits);pdfv:=pdfv-vout;pdfprint(1034);end;
pdftjstarth:=pdfh;pdfdeltah:=0;end;
procedure pdfusefont(f:internalfontnumber;fontnum:integer);
begin begin if dividescaled(fontsize[f],onehundredbp,6)<>0 then end;
pdffontsize[f]:=scaledout;fontused[f]:=true;
pdfassert((fontnum>0)or((fontnum<0)and(pdffontnum[-fontnum]>0)));
pdffontnum[f]:=fontnum;
if eqtb[27242].int>0 then begin pdfwarning(0,1035,true,true);
eqtb[27242].int:=0;end;end;
{:695}{696:}procedure pdfinitfont(f:internalfontnumber);
var k,b:internalfontnumber;i:integer;begin pdfassert(not fontused[f]);
if pdffontautoexpand[f]and(pdffontblink[f]<>0)then begin b:=pdffontblink
[f];if not hasfmentry(b)then pdferror(1036,1037);
if not fontused[b]then pdfinitfont(b);pdffontmap[f]:=pdffontmap[b];end;
if hasfmentry(f)then begin i:=headtab[3];
while i<>0 do begin k:=objtab[i].int0;
if hasfmentry(k)and(pdffontmap[k]=pdffontmap[f])and(streqstr(fontname[k]
,fontname[f])or(pdffontautoexpand[f]and(pdffontblink[f]<>0)and streqstr(
fontname[k],fontname[pdffontblink[f]])))then begin pdfassert(pdffontnum[
k]<>0);
if pdffontnum[k]<0 then pdfusefont(f,pdffontnum[k])else pdfusefont(f,-k)
;goto 10;end;i:=objtab[i].int1;end;end;pdfcreateobj(3,f);
pdfusefont(f,objptr);end;procedure pdfinitfontcurval;
begin pdfinitfont(curval);end;
procedure pdfsetfont(f:internalfontnumber);label 40,41;var p:halfword;
k:internalfontnumber;begin if not fontused[f]then pdfinitfont(f);
begin if pdffontnum[f]<0 then ff:=-pdffontnum[f]else ff:=f;end;k:=ff;
p:=pdffontlist;
while p<>-268435455 do begin begin if pdffontnum[mem[p].hh.lh]<0 then ff
:=-pdffontnum[mem[p].hh.lh]else ff:=mem[p].hh.lh;end;
if ff=k then goto 40;p:=mem[p].hh.rh;end;begin pdfappendlistarg:=f;
pdffontlist:=appendptr(pdffontlist,pdfappendlistarg);end;
40:if(k=pdflastf)and(fontsize[f]=pdflastfs)then goto 10;pdfprint(1038);
pdfprintint(k);if pdfresnameprefix<>0 then pdfprint(pdfresnameprefix);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintreal(dividescaled(fontsize[f],onehundredbp,6),4);pdfprint(1039);
pdflastf:=k;pdflastfs:=fontsize[f];end;procedure pdfbegintext;
begin pdfsetorigin(0,curpageheight);begin pdfprint(1040);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfdoingtext:=true;
pdff:=0;pdflastf:=0;pdflastfs:=0;pdfdoingstring:=false;pdfcurTma:=0;end;
procedure pdfreaddummyfont;
begin if pdfdummyfont=0 then begin pdfdummyfont:=readfontinfo(513,1041,
345,onebp);pdfmarkchar(pdfdummyfont,32);end;end;
procedure pdfinsertinterwordspace;begin pdfreaddummyfont;
pdfsetfont(pdfdummyfont);pdfprint(1042);end;
procedure pdfbeginstring(f:internalfontnumber);var sout,v,vout:scaled;
s:integer;mustendstring:boolean;mustinsertspace:boolean;
begin if not pdfdoingtext then pdfbegintext;
if f<>pdff then begin pdfendstring;pdfsetfont(f);end;
if pdfcurTma=0 then begin s:=dividescaled(curh-(pdftjstarth+pdfdeltah),
pdffontsize[f],3);sout:=scaledout;
end else begin s:=dividescaled(roundxnoverd(curh-(pdftjstarth+pdfdeltah)
,1000,1000+pdfcurTma),pdffontsize[f],3);
if abs(s)<32768 then begin sout:=roundxnoverd(roundxnoverd(pdffontsize[f
],abs(s),1000),1000+pdfcurTma,1000);if s<0 then sout:=-sout;end;end;
if abs(curv-pdfv)>=minbpval then begin v:=dividescaled(pdfv-curv,
onehundredbp,fixeddecimaldigits+2);vout:=scaledout;end else begin v:=0;
vout:=0;end;mustinsertspace:=false;mustendstring:=false;
if genfakedinterwordspace and((abs(vout)>2*fontinfo[5+parambase[f]].int)
or(sout>fontinfo[2+parambase[f]].int-fontinfo[4+parambase[f]].int)or((f
<>pdff)and(v=0)))then begin mustinsertspace:=true;end;
if(f<>pdff)or(v<>0)or(abs(s)>=32768)or mustinsertspace then begin
mustendstring:=true;end;if mustendstring then begin pdfendstring;
if mustinsertspace then begin pdfinsertinterwordspace;pdfsetfont(f);end;
pdfsettextmatrix(v,vout,f);pdff:=f;s:=0;end;
if not pdfdoingstring then begin pdfprint(1043);
if s=0 then begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=40;incr(pdfptr);end;end;end;
if s<>0 then begin if pdfdoingstring then begin begin if pdfosmode and(
1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)else if not pdfosmode and(1>
pdfbufsize)then overflow(1004,pdfopbufsize)else if not pdfosmode and(1+
pdfptr>pdfbufsize)then pdfflush;end;begin pdfbuf[pdfptr]:=41;
incr(pdfptr);end;end;pdfprintint(-s);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=40;incr(pdfptr);end;end;pdfdeltah:=pdfdeltah+sout;
end;pdfdoingstring:=true;end;procedure pdfinsertfakespace;var s:integer;
begin s:=genfakedinterwordspace;genfakedinterwordspace:=0;
pdfreaddummyfont;pdfbeginstring(pdfdummyfont);pdfprint(32);
pdfendstringnl;genfakedinterwordspace:=s;end;procedure pdfendtext;
begin if pdfdoingtext then begin pdfendstringnl;begin pdfprint(1044);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfdoingtext:=false;
end;end;procedure pdfsetrule(x,y,w,h:scaled);begin pdfendtext;
begin pdfprint(113);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if h<=onebp then begin pdfsetorigintemp(x,y-(h+1)/2);pdfprint(1045);
pdfprintbp(h);pdfprint(1046);pdfprintbp(w);begin pdfprint(1047);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
end else if w<=onebp then begin pdfsetorigintemp(x+(w+1)/2,y);
pdfprint(1045);pdfprintbp(w);pdfprint(1048);pdfprintbp(h);
begin pdfprint(1049);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
end else begin pdfsetorigintemp(x,y);pdfprint(1050);pdfprintbp(w);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;pdfprintbp(h);
begin pdfprint(1051);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
begin pdfprint(81);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
procedure pdfrectangle(left,top,right,bottom:scaled);begin preparemag;
pdfprint(1052);pdfprintmagbp(((left)-pdforiginh));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintmagbp((pdforiginv-(bottom)));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintmagbp(((right)-pdforiginh));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintmagbp((pdforiginv-(top)));begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
procedure literal(s:strnumber;literalmode:integer;warn:boolean);
var j:poolpointer;begin j:=strstart[s];
if literalmode=3 then begin if not(strinstr(s,1053,0)or strinstr(s,1054,
0))then begin if warn and not(strinstr(s,1055,0)or strinstr(s,1056,0)or(
(strstart[s+1]-strstart[s])=0))then printnl(1057);goto 10;end;
j:=j+(strstart[1054]-strstart[1053]);
if strinstr(s,1058,(strstart[1054]-strstart[1053]))then begin j:=j+(
strstart[1059]-strstart[1058]);literalmode:=2;
end else if strinstr(s,1059,(strstart[1054]-strstart[1053]))then begin j
:=j+(strstart[1060]-strstart[1059]);literalmode:=1;
end else literalmode:=0;end;case literalmode of 0:begin pdfendtext;
pdfsetorigin(curh,curv);end;1:pdfendtext;2:pdfendstringnl;
others:confusion(1060)end;
while j<strstart[s+1]do begin begin begin if pdfosmode and(1+pdfptr>
pdfbufsize)then pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)
then overflow(1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>
pdfbufsize)then pdfflush;end;begin pdfbuf[pdfptr]:=strpool[j];
incr(pdfptr);end;end;incr(j);end;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
{:696}{705:}procedure pdfprintfwint(n:longinteger;w:integer);
var k:integer;begin k:=0;repeat dig[k]:=n mod 10;n:=n div 10;incr(k);
until k=w;
begin if pdfosmode and(k+pdfptr>pdfbufsize)then pdfosgetosbuf(k)else if
not pdfosmode and(k>pdfbufsize)then overflow(1004,pdfopbufsize)else if
not pdfosmode and(k+pdfptr>pdfbufsize)then pdfflush;end;
while k>0 do begin decr(k);begin pdfbuf[pdfptr]:=48+dig[k];incr(pdfptr);
end;end;end;procedure pdfoutbytes(n:longinteger;w:integer);
var k:integer;byte:array[0..7]of integer;begin k:=0;
repeat byte[k]:=n mod 256;n:=n div 256;incr(k);until k=w;
begin if pdfosmode and(k+pdfptr>pdfbufsize)then pdfosgetosbuf(k)else if
not pdfosmode and(k>pdfbufsize)then overflow(1004,pdfopbufsize)else if
not pdfosmode and(k+pdfptr>pdfbufsize)then pdfflush;end;
while k>0 do begin decr(k);begin pdfbuf[pdfptr]:=byte[k];incr(pdfptr);
end;end;end;procedure pdfintentry(s:strnumber;v:integer);
begin begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=47;incr(pdfptr);end;end;pdfprint(s);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;pdfprintint(v);end;
procedure pdfintentryln(s:strnumber;v:integer);begin pdfintentry(s,v);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
procedure pdfindirect(s:strnumber;o:integer);
begin begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=47;incr(pdfptr);end;end;pdfprint(s);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;pdfprintint(o);
pdfprint(1070);end;procedure pdfindirectln(s:strnumber;o:integer);
begin pdfindirect(s,o);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
procedure pdfprintstr(s:strnumber);label 30;var i,j:poolpointer;
ishexstring:boolean;begin i:=strstart[s];
j:=i+(strstart[s+1]-strstart[s])-1;if i>j then begin pdfprint(1071);
goto 10;end;if(strpool[i]='(')and(strpool[j]=')')then begin pdfprint(s);
goto 10;end;ishexstring:=false;
if(strpool[i]<>'<')or(strpool[j]<>'>')or odd((strstart[s+1]-strstart[s])
)then goto 30;incr(i);decr(j);
while i<j do begin if(((strpool[i]>='0')and(strpool[i]<='9'))or((strpool
[i]>='A')and(strpool[i]<='F'))or((strpool[i]>='a')and(strpool[i]<='f')))
and(((strpool[i+1]>='0')and(strpool[i+1]<='9'))or((strpool[i+1]>='A')and
(strpool[i+1]<='F'))or((strpool[i+1]>='a')and(strpool[i+1]<='f')))then i
:=i+2 else goto 30;end;ishexstring:=true;
30:if ishexstring then pdfprint(s)else begin begin begin if pdfosmode
and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)else if not pdfosmode and(1
>pdfbufsize)then overflow(1004,pdfopbufsize)else if not pdfosmode and(1+
pdfptr>pdfbufsize)then pdfflush;end;begin pdfbuf[pdfptr]:=40;
incr(pdfptr);end;end;pdfprint(s);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=41;incr(pdfptr);end;end;end;end;
procedure pdfprintstrln(s:strnumber);begin pdfprintstr(s);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
procedure pdfstrentry(s,v:strnumber);begin if v=0 then goto 10;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=47;incr(pdfptr);end;end;pdfprint(s);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;pdfprintstr(v);end;
procedure pdfstrentryln(s,v:strnumber);begin if v=0 then goto 10;
pdfstrentry(s,v);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
{:705}{708:}procedure settagcode(f:internalfontnumber;c:eightbits;
i:integer);var fixedi:integer;
begin if((fontbc[f]<=c)and(c<=fontec[f])and(fontinfo[charbase[f]+c].qqqq
.b0>0))then begin fixedi:=abs(fixint(i,-7,0));
if fixedi>=4 then begin if((fontinfo[charbase[f]+effectivechar(true,f,c)
].qqqq.b2)mod 4)=3 then fontinfo[charbase[f]+effectivechar(true,f,c)].
qqqq.b2:=(fontinfo[charbase[f]+effectivechar(true,f,c)].qqqq.b2)-3;
fixedi:=fixedi-4;end;
if fixedi>=2 then begin if((fontinfo[charbase[f]+effectivechar(true,f,c)
].qqqq.b2)mod 4)=2 then fontinfo[charbase[f]+effectivechar(true,f,c)].
qqqq.b2:=(fontinfo[charbase[f]+effectivechar(true,f,c)].qqqq.b2)-2;
fixedi:=fixedi-2;end;
if fixedi>=1 then begin if((fontinfo[charbase[f]+effectivechar(true,f,c)
].qqqq.b2)mod 4)=1 then fontinfo[charbase[f]+effectivechar(true,f,c)].
qqqq.b2:=(fontinfo[charbase[f]+effectivechar(true,f,c)].qqqq.b2)-1;end;
end;end;procedure setnoligatures(f:internalfontnumber);var c:integer;
begin for c:=fontbc[f]to fontec[f]do if(fontinfo[charbase[f]+c].qqqq.b0>
0)then if((fontinfo[charbase[f]+c].qqqq.b2)mod 4)=1 then fontinfo[
charbase[f]+c].qqqq.b2:=(fontinfo[charbase[f]+c].qqqq.b2)-1;end;
function initfontbase(v:integer):integer;var i,j:integer;
begin i:=pdfgetmem(256);for j:=0 to 255 do pdfmem[i+j]:=v;
initfontbase:=i;end;procedure setlpcode(f:internalfontnumber;
c:eightbits;i:integer);
begin if pdffontlpbase[f]=0 then pdffontlpbase[f]:=initfontbase(0);
pdfmem[pdffontlpbase[f]+c]:=fixint(i,-1000,1000);end;
procedure setrpcode(f:internalfontnumber;c:eightbits;i:integer);
begin if pdffontrpbase[f]=0 then pdffontrpbase[f]:=initfontbase(0);
pdfmem[pdffontrpbase[f]+c]:=fixint(i,-1000,1000);end;
procedure setefcode(f:internalfontnumber;c:eightbits;i:integer);
begin if pdffontefbase[f]=0 then pdffontefbase[f]:=initfontbase(1000);
pdfmem[pdffontefbase[f]+c]:=fixint(i,0,1000);end;
procedure setknbscode(f:internalfontnumber;c:eightbits;i:integer);
begin if pdffontknbsbase[f]=0 then pdffontknbsbase[f]:=initfontbase(0);
pdfmem[pdffontknbsbase[f]+c]:=fixint(i,-1000,1000);end;
procedure setstbscode(f:internalfontnumber;c:eightbits;i:integer);
begin if pdffontstbsbase[f]=0 then pdffontstbsbase[f]:=initfontbase(0);
pdfmem[pdffontstbsbase[f]+c]:=fixint(i,-1000,1000);end;
procedure setshbscode(f:internalfontnumber;c:eightbits;i:integer);
begin if pdffontshbsbase[f]=0 then pdffontshbsbase[f]:=initfontbase(0);
pdfmem[pdffontshbsbase[f]+c]:=fixint(i,-1000,1000);end;
procedure setknbccode(f:internalfontnumber;c:eightbits;i:integer);
begin if pdffontknbcbase[f]=0 then pdffontknbcbase[f]:=initfontbase(0);
pdfmem[pdffontknbcbase[f]+c]:=fixint(i,-1000,1000);end;
procedure setknaccode(f:internalfontnumber;c:eightbits;i:integer);
begin if pdffontknacbase[f]=0 then pdffontknacbase[f]:=initfontbase(0);
pdfmem[pdffontknacbase[f]+c]:=fixint(i,-1000,1000);end;
procedure adjustinterwordglue(p,g:halfword);var kn,st,sh:scaled;
q,r:halfword;c:halfword;f:internalfontnumber;
begin if not(not(g>=himemmin)and mem[g].hh.b0=10)then begin pdfwarning(
1073,1074,false,false);goto 10;end;c:=256;
if(p>=himemmin)then begin c:=mem[p].hh.b1;f:=mem[p].hh.b0;
end else if mem[p].hh.b0=6 then begin c:=mem[p+1].hh.b1;
f:=mem[p+1].hh.b0;
end else if(mem[p].hh.b0=11)and(mem[p].hh.b1=1)and(savetail<>-268435455)
then begin r:=savetail;
while(mem[r].hh.rh<>-268435455)and(mem[r].hh.rh<>p)do r:=mem[r].hh.rh;
if(mem[r].hh.rh=p)then if(r>=himemmin)then begin c:=mem[r].hh.b1;
f:=mem[r].hh.b0;end else if mem[r].hh.b0=6 then begin c:=mem[r+1].hh.b1;
f:=mem[r+1].hh.b0;end;end;if(c=256)then goto 10;kn:=getknbscode(f,c);
st:=getstbscode(f,c);sh:=getshbscode(f,c);
if(kn<>0)or(st<>0)or(sh<>0)then begin q:=newspec(mem[g+1].hh.lh);
deleteglueref(mem[g+1].hh.lh);
mem[q+1].int:=mem[q+1].int+roundxnoverd(fontinfo[6+parambase[f]].int,kn,
1000);
mem[q+2].int:=mem[q+2].int+roundxnoverd(fontinfo[6+parambase[f]].int,st,
1000);
mem[q+3].int:=mem[q+3].int+roundxnoverd(fontinfo[6+parambase[f]].int,sh,
1000);mem[g+1].hh.lh:=q;end;end;
function getautokern(f:internalfontnumber;l,r:halfword):halfword;
var tmpw:scaled;k:integer;p:halfword;begin pdfassert((l>=0)and(r>=0));
getautokern:=-268435455;
if(eqtb[27262].int<=0)and(eqtb[27261].int<=0)then goto 10;tmpw:=0;
if(eqtb[27262].int>0)and(l<256)then begin k:=getknaccode(f,l);
if k<>0 then tmpw:=roundxnoverd(fontinfo[6+parambase[f]].int,k,1000);
end;if(eqtb[27261].int>0)and(r<256)then begin k:=getknbccode(f,r);
if k<>0 then tmpw:=tmpw+roundxnoverd(fontinfo[6+parambase[f]].int,k,1000
);end;if tmpw<>0 then begin p:=newkern(tmpw);mem[p].hh.b1:=1;
getautokern:=p;end;end;function expandfontname(f:internalfontnumber;
e:integer):strnumber;var oldsetting:0..21;begin oldsetting:=selector;
selector:=21;print(fontname[f]);if e>0 then print(43);printint(e);
selector:=oldsetting;expandfontname:=makestring;end;
function autoexpandfont(f:internalfontnumber;
e:integer):internalfontnumber;var k:internalfontnumber;
nw,nk,ni,i:integer;begin k:=fontptr+1;incr(fontptr);
if(fontptr>=fontmax)then overflow(1075,fontmax);
fontname[k]:=expandfontname(f,e);fontarea[k]:=fontarea[f];
hash[15526+k].rh:=hash[15526+f].rh;hyphenchar[k]:=hyphenchar[f];
skewchar[k]:=skewchar[f];fontbchar[k]:=fontbchar[f];
fontfalsebchar[k]:=fontfalsebchar[f];fontbc[k]:=fontbc[f];
fontec[k]:=fontec[f];fontsize[k]:=fontsize[f];
fontdsize[k]:=fontdsize[f];fontparams[k]:=fontparams[f];
fontglue[k]:=fontglue[f];bcharlabel[k]:=bcharlabel[f];
charbase[k]:=charbase[f];heightbase[k]:=heightbase[f];
depthbase[k]:=depthbase[f];ligkernbase[k]:=ligkernbase[f];
extenbase[k]:=extenbase[f];parambase[k]:=parambase[f];
nw:=heightbase[f]-widthbase[f];ni:=ligkernbase[f]-italicbase[f];
nk:=extenbase[f]-(kernbase[f]+256*(128));
if(fmemptr+nw+ni+nk>=fontmemsize)then overflow(1076,fontmemsize);
widthbase[k]:=fmemptr;italicbase[k]:=widthbase[k]+nw;
kernbase[k]:=italicbase[k]+ni-256*(128);fmemptr:=fmemptr+nw+ni+nk;
for i:=0 to nw-1 do fontinfo[widthbase[k]+i].int:=roundxnoverd(fontinfo[
widthbase[f]+i].int,1000+e,1000);
for i:=0 to ni-1 do fontinfo[italicbase[k]+i].int:=roundxnoverd(fontinfo
[italicbase[f]+i].int,1000+e,1000);
for i:=0 to nk-1 do fontinfo[kernbase[k]+256*(128)+i].int:=roundxnoverd(
fontinfo[kernbase[f]+256*(128)+i].int,1000+e,1000);autoexpandfont:=k;
end;procedure copyexpandparams(k,f:internalfontnumber;e:integer);
begin if pdffontrpbase[f]=0 then pdffontrpbase[f]:=initfontbase(0);
if pdffontlpbase[f]=0 then pdffontlpbase[f]:=initfontbase(0);
if pdffontefbase[f]=0 then pdffontefbase[f]:=initfontbase(1000);
pdffontexpandratio[k]:=e;pdffontstep[k]:=pdffontstep[f];
pdffontautoexpand[k]:=pdffontautoexpand[f];pdffontblink[k]:=f;
pdffontlpbase[k]:=pdffontlpbase[f];pdffontrpbase[k]:=pdffontrpbase[f];
pdffontefbase[k]:=pdffontefbase[f];
if pdffontknbsbase[f]=0 then pdffontknbsbase[f]:=initfontbase(0);
if pdffontstbsbase[f]=0 then pdffontstbsbase[f]:=initfontbase(0);
if pdffontshbsbase[f]=0 then pdffontshbsbase[f]:=initfontbase(0);
if pdffontknbcbase[f]=0 then pdffontknbcbase[f]:=initfontbase(0);
if pdffontknacbase[f]=0 then pdffontknacbase[f]:=initfontbase(0);
pdffontknbsbase[k]:=pdffontknbsbase[f];
pdffontstbsbase[k]:=pdffontstbsbase[f];
pdffontshbsbase[k]:=pdffontshbsbase[f];
pdffontknbcbase[k]:=pdffontknbcbase[f];
pdffontknacbase[k]:=pdffontknacbase[f];end;
function tfmlookup(s:strnumber;fs:scaled):internalfontnumber;
var k:internalfontnumber;
begin if fs<>0 then begin for k:=1 to fontptr do if(fontarea[k]<>1072)
and streqstr(fontname[k],s)and(fontsize[k]=fs)then begin flushstr(s);
tfmlookup:=k;goto 10;end;
end else begin for k:=1 to fontptr do if(fontarea[k]<>1072)and streqstr(
fontname[k],s)then begin flushstr(s);tfmlookup:=k;goto 10;end;end;
tfmlookup:=0;end;function loadexpandfont(f:internalfontnumber;
e:integer):internalfontnumber;label 40;var s:strnumber;
k:internalfontnumber;begin s:=expandfontname(f,e);
k:=tfmlookup(s,fontsize[f]);
if k=0 then begin if pdffontautoexpand[f]then k:=autoexpandfont(f,e)else
k:=readfontinfo(513,s,345,fontsize[f]);end;copyexpandparams(k,f,e);
loadexpandfont:=k;end;function fixexpandvalue(f:internalfontnumber;
e:integer):integer;var step:integer;maxexpand:integer;neg:boolean;
begin fixexpandvalue:=0;if e=0 then goto 10;if e<0 then begin e:=-e;
neg:=true;maxexpand:=-pdffontexpandratio[pdffontshrink[f]];
end else begin neg:=false;
maxexpand:=pdffontexpandratio[pdffontstretch[f]];end;
if e>maxexpand then e:=maxexpand else begin step:=pdffontstep[f];
if e mod step>0 then e:=step*roundxnoverd(e,1,step);end;
if neg then e:=-e;fixexpandvalue:=e;end;
function getexpandfont(f:internalfontnumber;
e:integer):internalfontnumber;var k:internalfontnumber;
begin k:=pdffontelink[f];
while k<>0 do begin if pdffontexpandratio[k]=e then begin getexpandfont
:=k;goto 10;end;k:=pdffontelink[k];end;k:=loadexpandfont(f,e);
pdffontelink[k]:=pdffontelink[f];pdffontelink[f]:=k;getexpandfont:=k;
end;function expandfont(f:internalfontnumber;
e:integer):internalfontnumber;begin expandfont:=f;if e=0 then goto 10;
e:=fixexpandvalue(f,e);if e=0 then goto 10;
if pdffontelink[f]=0 then pdferror(1036,1077);
expandfont:=getexpandfont(f,e);end;
procedure setexpandparams(f:internalfontnumber;autoexpand:boolean;
stretchlimit,shrinklimit,fontstep,expandratio:integer);
begin pdffontstep[f]:=fontstep;pdffontautoexpand[f]:=autoexpand;
if stretchlimit>0 then pdffontstretch[f]:=getexpandfont(f,stretchlimit);
if shrinklimit>0 then pdffontshrink[f]:=getexpandfont(f,-shrinklimit);
if expandratio<>0 then pdffontexpandratio[f]:=expandratio;end;
procedure vfexpandlocalfonts(f:internalfontnumber);
var lf:internalfontnumber;k:integer;begin pdfassert(pdffonttype[f]=1);
for k:=0 to vflocalfontnum[f]-1 do begin lf:=vfifnts[vfdefaultfont[f]+k]
;setexpandparams(lf,pdffontautoexpand[f],pdffontexpandratio[
pdffontstretch[f]],-pdffontexpandratio[pdffontshrink[f]],pdffontstep[f],
pdffontexpandratio[f]);if pdffonttype[lf]=1 then vfexpandlocalfonts(lf);
end;end;procedure readexpandfont;
var shrinklimit,stretchlimit,fontstep:integer;f:internalfontnumber;
autoexpand:boolean;begin scanfontident;f:=curval;
if f=0 then pdferror(1036,873);
if pdffontblink[f]<>0 then pdferror(1036,1078);scanoptionalequals;
scanint;stretchlimit:=fixint(curval,0,1000);scanint;
shrinklimit:=fixint(curval,0,500);scanint;
fontstep:=fixint(curval,0,100);if fontstep=0 then pdferror(1036,1079);
stretchlimit:=stretchlimit-stretchlimit mod fontstep;
if stretchlimit<0 then stretchlimit:=0;
shrinklimit:=shrinklimit-shrinklimit mod fontstep;
if shrinklimit<0 then shrinklimit:=0;
if(stretchlimit=0)and(shrinklimit=0)then pdferror(1036,1080);
autoexpand:=false;if scankeyword(1081)then begin autoexpand:=true;
{472:}begin getxtoken;if curcmd<>10 then backinput;end{:472};end;
if(pdffontexpandratio[f]<>0)then pdferror(1036,1082);
if(pdffontstep[f]<>0)then begin if pdffontstep[f]<>fontstep then
pdferror(1036,1083);
if((pdffontstretch[f]=0)and(stretchlimit<>0))or((pdffontstretch[f]<>0)
and(pdffontexpandratio[pdffontstretch[f]]<>stretchlimit))then pdferror(
1036,1084);
if((pdffontshrink[f]=0)and(shrinklimit<>0))or((pdffontshrink[f]<>0)and(-
pdffontexpandratio[pdffontshrink[f]]<>shrinklimit))then pdferror(1036,
1085);if pdffontautoexpand[f]<>autoexpand then pdferror(1036,1086);
end else begin if(pdffonttype[f]<>0)and(pdffonttype[f]<>1)then
pdfwarning(1036,1087,true,true);
setexpandparams(f,autoexpand,stretchlimit,shrinklimit,fontstep,0);
if pdffonttype[f]=1 then vfexpandlocalfonts(f);end;end;
{:708}{709:}function letterspacefont(u:halfword;f:internalfontnumber;
e:integer):internalfontnumber;var k:internalfontnumber;w,r:scaled;
s:strnumber;i,nw:integer;oldsetting:0..21;vfz:integer;vfalpha:integer;
vfbeta:1..16;begin k:=readfontinfo(u,fontname[f],345,fontsize[f]);
if scankeyword(1088)then setnoligatures(k);
nw:=heightbase[k]-widthbase[k];
for i:=0 to nw-1 do fontinfo[widthbase[k]+i].int:=fontinfo[widthbase[k]+
i].int+roundxnoverd(fontinfo[6+parambase[k]].int,e,1000);
flushstr(fontname[k]);
begin if poolptr+(strstart[fontname[k]+1]-strstart[fontname[k]])+7>
poolsize then overflow(259,poolsize-initpoolptr);end;
oldsetting:=selector;selector:=21;print(fontname[k]);
if e>0 then print(43);printint(e);print(1089);selector:=oldsetting;
fontname[k]:=makestring;allocvffnts;vfefnts[vfnf]:=0;vfifnts[vfnf]:=f;
incr(vfnf);vflocalfontnum[k]:=1;vfdefaultfont[k]:=vfnf-1;
pdffonttype[k]:=1;vfz:=fontsize[f];begin vfalpha:=16;
while vfz>=8388608 do begin vfz:=vfz div 2;vfalpha:=vfalpha+vfalpha;end;
vfbeta:=256 div vfalpha;vfalpha:=vfalpha*vfz;end;
w:=roundxnoverd(fontinfo[6+parambase[f]].int,e,2000);
if w>=0 then tmpw.qqqq.b0:=0 else begin tmpw.qqqq.b0:=255;w:=vfalpha+w;
end;r:=w*vfbeta;tmpw.qqqq.b1:=r div vfz;r:=r mod vfz;
if r=0 then tmpw.qqqq.b2:=0 else begin r:=r*256;tmpw.qqqq.b2:=r div vfz;
r:=r mod vfz;end;if r=0 then tmpw.qqqq.b3:=0 else begin r:=r*256;
tmpw.qqqq.b3:=r div vfz;end;vfpacketbase[k]:=newvfpacket(k);
for c:=fontbc[k]to fontec[k]do begin begin if poolptr+12>poolsize then
overflow(259,poolsize-initpoolptr);end;begin strpool[poolptr]:=146;
incr(poolptr);end;begin strpool[poolptr]:=tmpw.qqqq.b0;incr(poolptr);
end;begin strpool[poolptr]:=tmpw.qqqq.b1;incr(poolptr);end;
begin strpool[poolptr]:=tmpw.qqqq.b2;incr(poolptr);end;
begin strpool[poolptr]:=tmpw.qqqq.b3;incr(poolptr);end;
if c<128 then begin strpool[poolptr]:=c;incr(poolptr);
end else begin begin strpool[poolptr]:=128;incr(poolptr);end;
begin strpool[poolptr]:=c;incr(poolptr);end;end;
begin strpool[poolptr]:=146;incr(poolptr);end;
begin strpool[poolptr]:=tmpw.qqqq.b0;incr(poolptr);end;
begin strpool[poolptr]:=tmpw.qqqq.b1;incr(poolptr);end;
begin strpool[poolptr]:=tmpw.qqqq.b2;incr(poolptr);end;
begin strpool[poolptr]:=tmpw.qqqq.b3;incr(poolptr);end;s:=makestring;
storepacket(k,c,s);flushstr(s);end;letterspacefont:=k;end;
procedure newletterspacedfont(a:smallnumber);var u:halfword;t:strnumber;
oldsetting:0..21;f,k:internalfontnumber;begin getrtoken;u:=curcs;
if u>=514 then t:=hash[u].rh else if u>=257 then if u=513 then t:=1090
else t:=u-257 else begin oldsetting:=selector;selector:=21;print(1090);
print(u-1);selector:=oldsetting;
begin if poolptr+1>poolsize then overflow(259,poolsize-initpoolptr);end;
t:=makestring;end;if(a>=4)then geqdefine(u,87,0)else eqdefine(u,87,0);
scanoptionalequals;scanfontident;k:=curval;scanint;
f:=letterspacefont(u,k,fixint(curval,-1000,1000));eqtb[u].hh.rh:=f;
eqtb[15526+f]:=eqtb[u];hash[15526+f].rh:=t;end;
function isletterspacedfont(f:internalfontnumber):boolean;label 30;
var i,j:poolpointer;begin isletterspacedfont:=false;
if pdffonttype[f]<>1 then goto 10;i:=strstart[fontname[f]+1]-1;
j:=strstart[fontname[f]];
if(strpool[i-1]<>'l')or(strpool[i]<>'s')then goto 10;i:=i-2;
while i>=j do begin if(strpool[i]<'0')or(strpool[i]>'9')then goto 30;
i:=i-1;end;30:if i<j then goto 10;
if(strpool[i]<>'+')and(strpool[i]<>'-')then goto 10;
isletterspacedfont:=true;end;
function copyfontinfo(f:internalfontnumber):internalfontnumber;
var lf,bc,ec,i:halfword;k:internalfontnumber;
begin if(pdffontexpandratio[f]<>0)or(pdffontstep[f]<>0)then pdferror(
1091,1092);if isletterspacedfont(f)then pdferror(1091,1093);
k:=fontptr+1;incr(fontptr);
if(fontptr>=fontmax)then overflow(1075,fontmax);
fontname[k]:=fontname[f];fontarea[k]:=1072;hyphenchar[k]:=hyphenchar[f];
skewchar[k]:=skewchar[f];fontbchar[k]:=fontbchar[f];
fontfalsebchar[k]:=fontfalsebchar[f];fontbc[k]:=fontbc[f];
fontec[k]:=fontec[f];fontsize[k]:=fontsize[f];
fontdsize[k]:=fontdsize[f];fontparams[k]:=fontparams[f];
fontglue[k]:=fontglue[f];bcharlabel[k]:=bcharlabel[f];bc:=fontbc[f];
ec:=fontec[f];charbase[k]:=fmemptr-bc;widthbase[k]:=charbase[k]+ec+1;
heightbase[k]:=widthbase[k]+(heightbase[f]-widthbase[f]);
depthbase[k]:=heightbase[k]+(depthbase[f]-heightbase[f]);
italicbase[k]:=depthbase[k]+(italicbase[f]-depthbase[f]);
ligkernbase[k]:=italicbase[k]+(ligkernbase[f]-italicbase[f]);
kernbase[k]:=ligkernbase[k]+(kernbase[f]-ligkernbase[f]);
extenbase[k]:=kernbase[k]+(extenbase[f]-kernbase[f]);
parambase[k]:=extenbase[k]+(parambase[f]-extenbase[f]);
lf:=(parambase[f]-charbase[f])+fontparams[f]+1;
if(fmemptr+lf>=fontmemsize)then overflow(1076,fontmemsize);
for i:=0 to lf-1 do fontinfo[charbase[k]+bc+i]:=fontinfo[charbase[f]+bc+
i];fmemptr:=fmemptr+lf;copyfontinfo:=k;end;
procedure makefontcopy(a:smallnumber);var u:halfword;t:strnumber;
oldsetting:0..21;f,k:internalfontnumber;begin getrtoken;u:=curcs;
if u>=514 then t:=hash[u].rh else if u>=257 then if u=513 then t:=1090
else t:=u-257 else begin oldsetting:=selector;selector:=21;print(1090);
print(u-1);selector:=oldsetting;
begin if poolptr+1>poolsize then overflow(259,poolsize-initpoolptr);end;
t:=makestring;end;if(a>=4)then geqdefine(u,87,0)else eqdefine(u,87,0);
scanoptionalequals;scanfontident;k:=curval;f:=copyfontinfo(k);
eqtb[u].hh.rh:=f;eqtb[15526+f]:=eqtb[u];hash[15526+f].rh:=t;end;
{:709}{715:}procedure vferror(filename,msg:strnumber);
var oldsetting:0..21;s:strnumber;
begin begin if poolptr+(strstart[filename+1]-strstart[filename])+3>
poolsize then overflow(259,poolsize-initpoolptr);end;
oldsetting:=selector;selector:=21;print(filename);print(1094);
s:=makestring;selector:=oldsetting;pdferror(s,msg);end;
function vfbyte:eightbits;var i:integer;begin i:=getc(vffile);
if i<0 then pdferror(1095,1096);vfbyte:=i;end;
function vfreadsigned(k:integer):integer;var i:integer;
begin pdfassert((k>0)and(k<=4));i:=vfbyte;if i>=128 then i:=i-256;
decr(k);while k>0 do begin i:=i*256+vfbyte;decr(k);end;vfreadsigned:=i;
end;function vfreadunsigned(k:integer):integer;var i:integer;
begin pdfassert((k>0)and(k<=4));i:=vfbyte;
if(k=4)and(i>=128)then vferror(fontname[f],1028);decr(k);
while k>0 do begin i:=i*256+vfbyte;decr(k);end;vfreadunsigned:=i;end;
procedure vflocalfontwarning(f,k:internalfontnumber;s:strnumber);
begin printnl(s);print(1097);print(fontname[k]);print(1098);
print(fontname[f]);print(1099);end;
function vfdeffont(f:internalfontnumber):internalfontnumber;
var k:internalfontnumber;s:strnumber;ds,fs:scaled;cs:fourquarters;
begin cs.b0:=vfbyte;cs.b1:=vfbyte;cs.b2:=vfbyte;cs.b3:=vfbyte;
fs:=storescaledf(vfreadsigned(4),fontsize[f]);ds:=vfreadsigned(4)div 16;
tmpw.qqqq.b0:=vfbyte;tmpw.qqqq.b1:=vfbyte;
while tmpw.qqqq.b0>0 do begin decr(tmpw.qqqq.b0);
begin if vfbyte<>0 then end;end;
begin if poolptr+tmpw.qqqq.b1>poolsize then overflow(259,poolsize-
initpoolptr);end;while tmpw.qqqq.b1>0 do begin decr(tmpw.qqqq.b1);
begin strpool[poolptr]:=vfbyte;incr(poolptr);end;end;s:=makestring;
k:=tfmlookup(s,fs);if k=0 then k:=readfontinfo(513,s,345,fs);
if k<>0 then begin if((cs.b0<>0)or(cs.b1<>0)or(cs.b2<>0)or(cs.b3<>0))and
((fontcheck[k].b0<>0)or(fontcheck[k].b1<>0)or(fontcheck[k].b2<>0)or(
fontcheck[k].b3<>0))and((cs.b0<>fontcheck[k].b0)or(cs.b1<>fontcheck[k].
b1)or(cs.b2<>fontcheck[k].b2)or(cs.b3<>fontcheck[k].b3))then
vflocalfontwarning(f,k,1100);
if ds<>fontdsize[k]then vflocalfontwarning(f,k,1101);end;
if(pdffontstep[f]<>0)then setexpandparams(k,pdffontautoexpand[f],
pdffontexpandratio[pdffontstretch[f]],-pdffontexpandratio[pdffontshrink[
f]],pdffontstep[f],pdffontexpandratio[f]);vfdeffont:=k;end;
procedure dovf(f:internalfontnumber);var cmd,k,n:integer;
cc,cmdlength,packetlength:integer;tfmwidth:scaled;s:strnumber;
stacklevel:vfstackindex;savevfnf:internalfontnumber;
begin pdffonttype[f]:=2;if autoexpandvf(f)then goto 10;stacklevel:=0;
{716:}packfilename(fontname[f],345,1094);
if not vfbopenin(vffile)then goto 10{:716};
{717:}if vfbyte<>247 then vferror(fontname[f],1103);
if vfbyte<>202 then vferror(fontname[f],1104);cmdlength:=vfbyte;
for k:=1 to cmdlength do begin if vfbyte<>0 then end;
tmpw.qqqq.b0:=vfbyte;tmpw.qqqq.b1:=vfbyte;tmpw.qqqq.b2:=vfbyte;
tmpw.qqqq.b3:=vfbyte;
if((tmpw.qqqq.b0<>0)or(tmpw.qqqq.b1<>0)or(tmpw.qqqq.b2<>0)or(tmpw.qqqq.
b3<>0))and((fontcheck[f].b0<>0)or(fontcheck[f].b1<>0)or(fontcheck[f].b2
<>0)or(fontcheck[f].b3<>0))and((tmpw.qqqq.b0<>fontcheck[f].b0)or(tmpw.
qqqq.b1<>fontcheck[f].b1)or(tmpw.qqqq.b2<>fontcheck[f].b2)or(tmpw.qqqq.
b3<>fontcheck[f].b3))then begin printnl(1105);print(fontname[f]);
print(1106);end;
if vfreadsigned(4)div 16<>fontdsize[f]then begin printnl(1107);
print(fontname[f]);print(1106);end;fflush(stdout){:717};
{718:}cmd:=vfbyte;savevfnf:=vfnf;
while(cmd>=243)and(cmd<=246)do begin allocvffnts;
vfefnts[vfnf]:=vfreadunsigned(cmd-242);vfifnts[vfnf]:=vfdeffont(f);
incr(vfnf);cmd:=vfbyte;end;vfdefaultfont[f]:=savevfnf;
vflocalfontnum[f]:=vfnf-savevfnf;{:718};
{719:}vfpacketbase[f]:=newvfpacket(f){:719};
while cmd<=242 do begin{720:}if cmd=242 then begin packetlength:=
vfreadunsigned(4);cc:=vfreadunsigned(4);
if not((fontbc[f]<=cc)and(cc<=fontec[f])and(fontinfo[charbase[f]+cc].
qqqq.b0>0))then vferror(fontname[f],1108);
tfmwidth:=storescaledf(vfreadsigned(4),fontsize[f]);
end else begin packetlength:=cmd;cc:=vfbyte;
if not((fontbc[f]<=cc)and(cc<=fontec[f])and(fontinfo[charbase[f]+cc].
qqqq.b0>0))then vferror(fontname[f],1108);
tfmwidth:=storescaledf(vfreadunsigned(3),fontsize[f]);end;
if packetlength<0 then vferror(fontname[f],1109);
if packetlength>10000 then vferror(fontname[f],1110);
if tfmwidth<>fontinfo[widthbase[f]+fontinfo[charbase[f]+effectivechar(
true,f,cc)].qqqq.b0].int then begin printnl(1111);print(fontname[f]);
print(1106);end;
begin if poolptr+packetlength>poolsize then overflow(259,poolsize-
initpoolptr);end;while packetlength>0 do begin cmd:=vfbyte;
decr(packetlength);
{722:}if(cmd>=0)and(cmd<=127)then cmdlength:=0 else if((171<=cmd)and(cmd
<=234))or((235<=cmd)and(cmd<=238))then begin if cmd>=235 then begin k:=
vfreadunsigned(cmd-234);packetlength:=packetlength-(cmd-234);
end else k:=cmd-171;if k>=256 then vferror(fontname[f],1114);n:=0;
while(n<vflocalfontnum[f])and(vfefnts[vfdefaultfont[f]+n]<>k)do incr(n);
if n=vflocalfontnum[f]then vferror(fontname[f],1115);
if k<=63 then begin strpool[poolptr]:=171+k;incr(poolptr);
end else begin begin strpool[poolptr]:=235;incr(poolptr);end;
begin strpool[poolptr]:=k;incr(poolptr);end;end;cmdlength:=0;cmd:=138;
end else case cmd of 132,137:cmdlength:=8;
128,129,130,131:cmdlength:=cmd-127;133,134,135,136:cmdlength:=cmd-132;
143,144,145,146:cmdlength:=cmd-142;148,149,150,151:cmdlength:=cmd-147;
153,154,155,156:cmdlength:=cmd-152;157,158,159,160:cmdlength:=cmd-156;
162,163,164,165:cmdlength:=cmd-161;167,168,169,170:cmdlength:=cmd-166;
239,240,241,242:begin cmdlength:=vfreadunsigned(cmd-238);
packetlength:=packetlength-(cmd-238);
if cmdlength>10000 then vferror(fontname[f],1110);
if cmdlength<0 then vferror(fontname[f],1116);
begin strpool[poolptr]:=239;incr(poolptr);end;
begin strpool[poolptr]:=cmdlength;incr(poolptr);end;cmd:=138;end;
147,152,161,166,138:cmdlength:=0;141,142:begin cmdlength:=0;
if cmd=141 then if stacklevel=vfstacksize then overflow(1117,vfstacksize
)else incr(stacklevel)else if stacklevel=0 then vferror(fontname[f],1118
)else decr(stacklevel);end;others:vferror(fontname[f],1119);end{:722};
if cmd<>138 then begin strpool[poolptr]:=cmd;incr(poolptr);end;
packetlength:=packetlength-cmdlength;
while cmdlength>0 do begin decr(cmdlength);
begin strpool[poolptr]:=vfbyte;incr(poolptr);end;end;end;
if stacklevel<>0 then vferror(fontname[f],1112);
if packetlength<>0 then vferror(fontname[f],1113);{721:}s:=makestring;
storepacket(f,cc,s);flushstr(s){:721};cmd:=vfbyte{:720};end;
if cmd<>248 then vferror(fontname[f],1102);bclose(vffile);
pdffonttype[f]:=1;end;{:715}{723:}procedure pdfcheckvfcurval;
var f:internalfontnumber;begin f:=curval;dovf(f);
if pdffonttype[f]=1 then pdferror(593,1120);end;
function autoexpandvf(f:internalfontnumber):boolean;
var bf,lf:internalfontnumber;e,k:integer;begin autoexpandvf:=false;
if(not pdffontautoexpand[f])or(pdffontblink[f]=0)then goto 10;
bf:=pdffontblink[f];if pdffonttype[bf]=0 then dovf(bf);
if pdffonttype[bf]<>1 then goto 10;e:=pdffontexpandratio[f];
for k:=0 to vflocalfontnum[bf]-1 do begin lf:=vfdefaultfont[bf]+k;
allocvffnts;vfefnts[vfnf]:=vfefnts[lf];
vfifnts[vfnf]:=autoexpandfont(vfifnts[lf],e);
copyexpandparams(vfifnts[vfnf],vfifnts[lf],e);incr(vfnf);end;
vfpacketbase[f]:=vfpacketbase[bf];vflocalfontnum[f]:=vflocalfontnum[bf];
vfdefaultfont[f]:=vfnf-vflocalfontnum[f];pdffonttype[f]:=1;
autoexpandvf:=true;end;
{:723}{728:}function packetreadsigned(k:integer):integer;var i:integer;
begin pdfassert((k>0)and(k<=4));i:=packetbyte;if i>=128 then i:=i-256;
decr(k);while k>0 do begin i:=i*256+packetbyte;decr(k);end;
packetreadsigned:=i;end;function packetreadunsigned(k:integer):integer;
var i:integer;begin pdfassert((k>0)and(k<=4));i:=packetbyte;
if(k=4)and(i>=128)then vferror(fontname[f],1028);decr(k);
while k>0 do begin i:=i*256+packetbyte;decr(k);end;
packetreadunsigned:=i;end;function packetscaled(k:integer;
fs:scaled):scaled;
begin packetscaled:=storescaledf(packetreadsigned(k),fs);end;
procedure dovfpacket(vff:internalfontnumber;c:eightbits);label 70,22;
var f,k,n:internalfontnumber;savecurh,savecurv:scaled;cmd:integer;
charmove:boolean;w,x,y,z:scaled;s:strnumber;begin incr(vfcurs);
if vfcurs>vfmaxrecursion then overflow(1121,vfmaxrecursion);
savecurv:=curv;savecurh:=curh;pushpacketstate;startpacket(vff,c);
f:=vfifnts[vfdefaultfont[vff]];w:=0;x:=0;y:=0;z:=0;
while vfpacketlength>0 do begin cmd:=packetbyte;
{729:}if(cmd>=0)and(cmd<=127)then begin if not((fontbc[f]<=cmd)and(cmd<=
fontec[f])and(fontinfo[charbase[f]+cmd].qqqq.b0>0))then begin
charwarning(f,cmd);goto 22;end;c:=cmd;charmove:=true;goto 70;
end else if((171<=cmd)and(cmd<=234))or(cmd=235)then begin if cmd=235
then k:=packetbyte else k:=cmd-171;n:=0;
while(n<vflocalfontnum[vff])and(vfefnts[vfdefaultfont[vff]+n]<>k)do incr
(n);if(n=vflocalfontnum[vff])then pdferror(1095,1122)else f:=vfifnts[
vfdefaultfont[vff]+n];
end else case cmd of 141:begin vfstack[vfstackptr].stackh:=curh;
vfstack[vfstackptr].stackv:=curv;vfstack[vfstackptr].stackw:=w;
vfstack[vfstackptr].stackx:=x;vfstack[vfstackptr].stacky:=y;
vfstack[vfstackptr].stackz:=z;incr(vfstackptr);end;
142:begin decr(vfstackptr);curh:=vfstack[vfstackptr].stackh;
curv:=vfstack[vfstackptr].stackv;w:=vfstack[vfstackptr].stackw;
x:=vfstack[vfstackptr].stackx;y:=vfstack[vfstackptr].stacky;
z:=vfstack[vfstackptr].stackz;end;
128,129,130,131,133,134,135,136:begin if(128<=cmd)and(cmd<=131)then
begin tmpw.int:=packetreadunsigned(cmd-127);charmove:=true;
end else begin tmpw.int:=packetreadunsigned(cmd-132);charmove:=false;
end;if not((fontbc[f]<=tmpw.int)and(tmpw.int<=fontec[f])and(fontinfo[
charbase[f]+tmpw.int].qqqq.b0>0))then begin charwarning(f,tmpw.int);
goto 22;end;c:=tmpw.int;goto 70;end;
132,137:begin ruleht:=packetscaled(4,fontsize[vff]);
rulewd:=packetscaled(4,fontsize[vff]);
if(rulewd>0)and(ruleht>0)then begin pdfsetrule(curh,curv,rulewd,ruleht);
if cmd=132 then curh:=curh+rulewd;end;end;
143,144,145,146:curh:=curh+packetscaled(cmd-142,fontsize[vff]);
147,148,149,150,151:begin if cmd>147 then w:=packetscaled(cmd-147,
fontsize[vff]);curh:=curh+w;end;
152,153,154,155,156:begin if cmd>152 then x:=packetscaled(cmd-152,
fontsize[vff]);curh:=curh+x;end;
157,158,159,160:curv:=curv+packetscaled(cmd-156,fontsize[vff]);
161,162,163,164,165:begin if cmd>161 then y:=packetscaled(cmd-161,
fontsize[vff]);curv:=curv+y;end;
166,167,168,169,170:begin if cmd>166 then z:=packetscaled(cmd-166,
fontsize[vff]);curv:=curv+z;end;
239,240,241,242:begin tmpw.int:=packetreadunsigned(cmd-238);
begin if poolptr+tmpw.int>poolsize then overflow(259,poolsize-
initpoolptr);end;while tmpw.int>0 do begin decr(tmpw.int);
begin strpool[poolptr]:=packetbyte;incr(poolptr);end;end;s:=makestring;
literal(s,3,false);flushstr(s);end;others:pdferror(1095,1123);end;
goto 22;
70:if((fontbc[f]<=c)and(c<=fontec[f])and(fontinfo[charbase[f]+c].qqqq.b0
>0))then begin if pdffonttype[f]=0 then dovf(f);
if pdffonttype[f]=1 then dovfpacket(f,c)else begin pdfbeginstring(f);
pdfprintchar(f,c);advcharwidth(f,c);end;end else charwarning(f,c);
if charmove then curh:=curh+fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,c)].qqqq.b0].int{:729};22:end;poppacketstate;
curv:=savecurv;curh:=savecurh;decr(vfcurs);end;
{:728}{731:}procedure pdfvlistout;forward;
{:731}{732:}{730:}procedure pdfoutliteral(p:halfword);
var oldsetting:0..21;s:strnumber;begin oldsetting:=selector;
selector:=21;
showtokenlist(mem[mem[p+1].hh.rh].hh.rh,-268435455,poolsize-poolptr);
selector:=oldsetting;s:=makestring;literal(s,mem[p+1].hh.lh,false);
flushstr(s);end;procedure pdfoutcolorstack(p:halfword);
var oldsetting:0..21;s:strnumber;cmd:integer;stackno:integer;
literalmode:integer;begin cmd:=mem[p+1].hh.lh;stackno:=mem[p+1].hh.rh;
if stackno>=colorstackused then begin printnl(345);print(1124);
printint(stackno);print(1125);printnl(345);goto 10;end;
case cmd of 0,1:begin oldsetting:=selector;selector:=21;
showtokenlist(mem[mem[p+2].hh.rh].hh.rh,-268435455,poolsize-poolptr);
selector:=oldsetting;s:=makestring;
if cmd=0 then literalmode:=colorstackset(stackno,s)else literalmode:=
colorstackpush(stackno,s);
if(strstart[s+1]-strstart[s])>0 then literal(s,literalmode,false);
flushstr(s);goto 10;end;2:literalmode:=colorstackpop(stackno);
3:literalmode:=colorstackcurrent(stackno);others:confusion(1126)end;
if(poolptr-strstart[strptr])>0 then begin s:=makestring;
literal(s,literalmode,false);flushstr(s);end end;
procedure pdfoutcolorstackstartpage;var i:integer;max:integer;
startstatus:integer;literalmode:integer;s:strnumber;begin i:=0;
max:=colorstackused;
while i<max do begin startstatus:=colorstackskippagestart(i);
if startstatus=0 then begin literalmode:=colorstackcurrent(i);
if(poolptr-strstart[strptr])>0 then begin s:=makestring;
literal(s,literalmode,false);flushstr(s);end;end;incr(i);end;end;
procedure pdfoutsetmatrix(p:halfword);var oldsetting:0..21;s:strnumber;
begin oldsetting:=selector;selector:=21;
showtokenlist(mem[mem[p+1].hh.rh].hh.rh,-268435455,poolsize-poolptr);
selector:=oldsetting;
begin if poolptr+7>poolsize then overflow(259,poolsize-initpoolptr);end;
strpool[poolptr]:=0;
if pdfsetmatrix(strstart[strptr],curh,curpageheight-curv)=1 then begin
begin if poolptr+7>poolsize then overflow(259,poolsize-initpoolptr);end;
begin strpool[poolptr]:=32;incr(poolptr);end;begin strpool[poolptr]:=48;
incr(poolptr);end;begin strpool[poolptr]:=32;incr(poolptr);end;
begin strpool[poolptr]:=48;incr(poolptr);end;begin strpool[poolptr]:=32;
incr(poolptr);end;begin strpool[poolptr]:=99;incr(poolptr);end;
begin strpool[poolptr]:=109;incr(poolptr);end;s:=makestring;
literal(s,0,false);end else begin pdferror(1127,1128);end;flushstr(s);
end;procedure pdfoutsave(p:halfword);begin checkpdfsave(curh,curv);
literal(113,0,false);end;procedure pdfoutrestore(p:halfword);
begin checkpdfrestore(curh,curv);literal(81,0,false);end;
procedure pdfspecial(p:halfword);var oldsetting:0..21;s:strnumber;
begin oldsetting:=selector;selector:=21;
showtokenlist(mem[mem[p+1].hh.rh].hh.rh,-268435455,poolsize-poolptr);
selector:=oldsetting;s:=makestring;literal(s,3,true);flushstr(s);end;
procedure pdfprinttoks(p:halfword);var s:strnumber;
begin s:=tokenstostring(p);
if(strstart[s+1]-strstart[s])>0 then pdfprint(s);flushstr(s);end;
procedure pdfprinttoksln(p:halfword);var s:strnumber;
begin s:=tokenstostring(p);
if(strstart[s+1]-strstart[s])>0 then begin begin pdfprint(s);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;flushstr(s);end;
{:730}{776:}procedure pdfwriteobj(n:integer);var s:strnumber;f:bytefile;
begin s:=tokenstostring(pdfmem[objtab[n].int4+0]);
begin deletetokenref(pdfmem[objtab[n].int4+0]);
pdfmem[objtab[n].int4+0]:=-268435455;end;
if pdfmem[objtab[n].int4+1]>0 then begin pdfbegindict(n,0);
if pdfmem[objtab[n].int4+2]<>-268435455 then begin pdfprinttoksln(pdfmem
[objtab[n].int4+2]);begin deletetokenref(pdfmem[objtab[n].int4+2]);
pdfmem[objtab[n].int4+2]:=-268435455;end;end;pdfbeginstream;
end else pdfbeginobj(n,1);
if pdfmem[objtab[n].int4+3]>0 then begin curname:=s;curarea:=345;
curext:=345;packfilename(curname,curarea,curext);
if not texbopenin(f)then pdferror(1158,1159);print(1066);print(s);
if not eof(f)then begin while not eof(f)do begin begin if pdfosmode and(
1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)else if not pdfosmode and(1>
pdfbufsize)then overflow(1004,pdfopbufsize)else if not pdfosmode and(1+
pdfptr>pdfbufsize)then pdfflush;end;begin pdfbuf[pdfptr]:=getc(f);
incr(pdfptr);end;end;
if(not pdfmem[objtab[n].int4+1])and(pdfptr>0)and(pdfbuf[pdfptr-1]<>10)
then begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf
(1)else if not pdfosmode and(1>pdfbufsize)then overflow(1004,
pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush
;end;begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;print(1018);
bclose(f);
end else if pdfmem[objtab[n].int4+1]>0 then pdfprint(s)else begin
pdfprint(s);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if pdfmem[objtab[n].int4+1]>0 then pdfendstream else pdfendobj;
flushstr(s);end;procedure flushwhatsitnode(p:halfword;s:smallnumber);
begin mem[p].hh.b0:=8;mem[p].hh.b1:=s;
if mem[p].hh.rh<>-268435455 then pdferror(1160,1161);flushnodelist(p);
end;{:776}{781:}procedure pdfwriteimage(n:integer);
begin pdfbegindict(n,0);
if pdfmem[objtab[n].int4+3]<>-268435455 then begin pdfprinttoksln(pdfmem
[objtab[n].int4+3]);begin deletetokenref(pdfmem[objtab[n].int4+3]);
pdfmem[objtab[n].int4+3]:=-268435455;end;end;
if fixedpdfdraftmode=0 then writeimage(pdfmem[objtab[n].int4+4]);
deleteimage(pdfmem[objtab[n].int4+4]);end;
{:781}{788:}procedure pdfprintrectspec(r:halfword);
begin pdfprintmagbp(((mem[r+1].int)-pdforiginh));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintmagbp((pdforiginv-(mem[r+4].int)));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintmagbp(((mem[r+3].int)-pdforiginh));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintmagbp((pdforiginv-(mem[r+2].int)));end;
{:788}{1565:}procedure warndestdup(id:integer;byname:smallnumber;
s1,s2:strnumber);begin if eqtb[27266].int>0 then goto 10;
pdfwarning(s1,1833,false,false);if byname>0 then begin print(1819);
printmark(id);end else begin print(1187);printint(id);end;print(1834);
print(s2);println;showcontext;end;
{:1565}{1628:}procedure writeaction(p:halfword);var s:strnumber;
d:integer;
begin if mem[p].hh.b0=3 then begin pdfprinttoksln(mem[p+2].hh.lh);
goto 10;end;pdfprint(1230);
if mem[p+1].hh.lh<>-268435455 then begin pdfprint(1915);
s:=tokenstostring(mem[p+1].hh.lh);
if(strpool[strstart[s]]=40)and(strpool[strstart[s]+(strstart[s+1]-
strstart[s])-1]=41)then pdfprint(s)else begin pdfprintstr(s);end;
flushstr(s);pdfprint(32);if mem[p+1].hh.rh>0 then begin pdfprint(1916);
if mem[p+1].hh.rh=1 then pdfprint(1917)else pdfprint(1918);end;end;
case mem[p].hh.b0 of 0:begin if mem[p+1].hh.lh=-268435455 then begin
pdfprint(1919);pdfprintint(getobj(1,mem[p].hh.rh,false));pdfprint(1070);
end else begin pdfprint(1920);pdfprintint(mem[p].hh.rh-1);end;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprint(tokenstostring(mem[p+2].hh.lh));flushstr(lasttokensstring);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=93;incr(pdfptr);end;end;end;
1:begin if mem[p+1].hh.lh=-268435455 then begin pdfprint(1921);
d:=getobj(5,mem[p].hh.rh,mem[p].hh.b1);end else pdfprint(1922);
if mem[p].hh.b1>0 then begin pdfstrentry(68,tokenstostring(mem[p].hh.rh)
);flushstr(lasttokensstring);
end else if mem[p+1].hh.lh=-268435455 then pdfindirect(68,d)else
pdferror(1846,1820);end;2:begin pdfprint(1923);
if mem[p+1].hh.lh=-268435455 then d:=getobj(9,mem[p].hh.rh,mem[p].hh.b1)
;
if mem[p].hh.b1>0 then begin pdfstrentry(68,tokenstostring(mem[p].hh.rh)
);flushstr(lasttokensstring);
end else if mem[p+1].hh.lh=-268435455 then pdfindirect(68,d)else
pdfintentry(68,mem[p].hh.rh);end;end;begin pdfprint(1231);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
procedure setrectdimens(p,parentbox:halfword;x,y,w,h,d,margin:scaled);
begin mem[p+1].int:=curh;
if(w=-1073741824)then mem[p+3].int:=x+mem[parentbox+1].int else mem[p+3]
.int:=curh+w;
if(h=-1073741824)then mem[p+2].int:=y-mem[parentbox+3].int else mem[p+2]
.int:=curv-h;
if(d=-1073741824)then mem[p+4].int:=y+mem[parentbox+2].int else mem[p+4]
.int:=curv+d;
if isshippingpage and matrixused then begin matrixtransformrect(mem[p+1]
.int,curpageheight-mem[p+4].int,mem[p+3].int,curpageheight-mem[p+2].int)
;mem[p+1].int:=getllx;mem[p+4].int:=curpageheight-getlly;
mem[p+3].int:=geturx;mem[p+2].int:=curpageheight-getury;end;
mem[p+1].int:=mem[p+1].int-margin;mem[p+2].int:=mem[p+2].int-margin;
mem[p+3].int:=mem[p+3].int+margin;mem[p+4].int:=mem[p+4].int+margin;end;
procedure doannot(p,parentbox:halfword;x,y:scaled);
begin if not isshippingpage then pdferror(1846,1924);
if doingleaders then goto 10;
if(objtab[mem[p+6].int].int2>-2)then mem[p+6].int:=pdfnewobjnum;
setrectdimens(p,parentbox,x,y,mem[p+1].int,mem[p+2].int,mem[p+3].int,0);
objtab[mem[p+6].int].int4:=p;begin pdfappendlistarg:=mem[p+6].int;
pdfannotlist:=appendptr(pdfannotlist,pdfappendlistarg);end;
if objtab[mem[p+6].int].int2=-2 then objtab[mem[p+6].int].int2:=-1;end;
{:1628}{1633:}procedure pushlinklevel(p:halfword);
begin if pdflinkstackptr>=pdfmaxlinklevel then overflow(1925,
pdfmaxlinklevel);pdfassert((mem[p].hh.b0=8)and(mem[p].hh.b1=14));
incr(pdflinkstackptr);pdflinkstack[pdflinkstackptr].nestinglevel:=curs;
pdflinkstack[pdflinkstackptr].linknode:=copynodelist(p);
pdflinkstack[pdflinkstackptr].reflinknode:=p;end;procedure poplinklevel;
begin pdfassert(pdflinkstackptr>0);
flushnodelist(pdflinkstack[pdflinkstackptr].linknode);
decr(pdflinkstackptr);end;procedure dolink(p,parentbox:halfword;
x,y:scaled);begin if not isshippingpage then pdferror(1846,1926);
pdfassert(mem[parentbox].hh.b0=0);
if(objtab[mem[p+6].int].int2>-2)then mem[p+6].int:=pdfnewobjnum;
pushlinklevel(p);
setrectdimens(p,parentbox,x,y,mem[p+1].int,mem[p+2].int,mem[p+3].int,
eqtb[27818].int);objtab[mem[p+6].int].int4:=p;
begin pdfappendlistarg:=mem[p+6].int;
pdflinklist:=appendptr(pdflinklist,pdfappendlistarg);end;
if objtab[mem[p+6].int].int2=-2 then objtab[mem[p+6].int].int2:=-1;end;
procedure endlink;var p:halfword;
begin if pdflinkstackptr<1 then pdferror(1846,1927);
if pdflinkstack[pdflinkstackptr].nestinglevel<>curs then pdferror(1846,
1928);
if(mem[pdflinkstack[pdflinkstackptr].linknode+1].int=-1073741824)then
begin p:=pdflinkstack[pdflinkstackptr].reflinknode;
if isshippingpage and matrixused then begin matrixrecalculate(curh+eqtb[
27818].int);mem[p+1].int:=getllx-eqtb[27818].int;
mem[p+2].int:=curpageheight-getury-eqtb[27818].int;
mem[p+3].int:=geturx+eqtb[27818].int;
mem[p+4].int:=curpageheight-getlly+eqtb[27818].int;
end else mem[p+3].int:=curh+eqtb[27818].int;end;poplinklevel;end;
{:1633}{1634:}procedure appendlink(parentbox:halfword;x,y:scaled;
i:smallnumber);var p:halfword;begin pdfassert(mem[parentbox].hh.b0=0);
p:=copynodelist(pdflinkstack[i].linknode);
pdflinkstack[i].reflinknode:=p;mem[p].hh.lh:=268435455;
mem[p].hh.rh:=-268435455;
setrectdimens(p,parentbox,x,y,mem[p+1].int,mem[p+2].int,mem[p+3].int,
eqtb[27818].int);pdfcreateobj(0,0);objtab[objptr].int4:=p;
begin pdfappendlistarg:=objptr;
pdflinklist:=appendptr(pdflinklist,pdfappendlistarg);end;end;
{:1634}{1635:}procedure appendbead(p:halfword);var a,b,c,t:integer;
begin if not isshippingpage then pdferror(1846,1929);
t:=getobj(9,mem[p+5].hh.rh,mem[p+5].hh.b1);b:=pdfnewobjnum;
objtab[b].int4:=pdfgetmem(5);pdfmem[objtab[b].int4+1]:=pdflastpage;
pdfmem[objtab[b].int4]:=p;
if mem[p+6].hh.lh<>-268435455 then pdfmem[objtab[b].int4+4]:=
tokenstostring(mem[p+6].hh.lh)else pdfmem[objtab[b].int4+4]:=0;
if objtab[t].int4=0 then begin objtab[t].int4:=b;
pdfmem[objtab[b].int4+2]:=b;pdfmem[objtab[b].int4+3]:=b;
end else begin a:=objtab[t].int4;c:=pdfmem[objtab[a].int4+3];
pdfmem[objtab[b].int4+3]:=c;pdfmem[objtab[b].int4+2]:=a;
pdfmem[objtab[a].int4+3]:=b;pdfmem[objtab[c].int4+2]:=b;end;
begin pdfappendlistarg:=b;
pdfbeadlist:=appendptr(pdfbeadlist,pdfappendlistarg);end;end;
procedure dothread(p,parentbox:halfword;x,y:scaled);
begin if doingleaders then goto 10;
if mem[p].hh.b1=19 then begin pdfthreadwd:=mem[p+1].int;
pdfthreadht:=mem[p+2].int;pdfthreaddp:=mem[p+3].int;
pdflastthreadid:=mem[p+5].hh.rh;
pdflastthreadnamedid:=(mem[p+5].hh.b1>0);
if pdflastthreadnamedid then incr(mem[mem[p+5].hh.rh].hh.lh);
pdfthreadlevel:=curs;end;
setrectdimens(p,parentbox,x,y,mem[p+1].int,mem[p+2].int,mem[p+3].int,
eqtb[27820].int);appendbead(p);lastthread:=p;end;
procedure appendthread(parentbox:halfword;x,y:scaled);var p:halfword;
begin p:=getnode(7);mem[p].hh.lh:=268435455;mem[p].hh.rh:=-268435455;
mem[p+1].int:=pdfthreadwd;mem[p+2].int:=pdfthreadht;
mem[p+3].int:=pdfthreaddp;mem[p+6].hh.lh:=-268435455;
mem[p+5].hh.rh:=pdflastthreadid;
if pdflastthreadnamedid then begin incr(mem[mem[p+5].hh.rh].hh.lh);
mem[p+5].hh.b1:=1;end else mem[p+5].hh.b1:=0;
setrectdimens(p,parentbox,x,y,mem[p+1].int,mem[p+2].int,mem[p+3].int,
eqtb[27820].int);appendbead(p);lastthread:=p;end;procedure endthread;
begin if pdfthreadlevel<>curs then pdferror(1846,1930);
if(pdfthreaddp=-1073741824)and(lastthread<>-268435455)then mem[
lastthread+4].int:=curv+eqtb[27820].int;
if pdflastthreadnamedid then deletetokenref(pdflastthreadid);
lastthread:=-268435455;end;function opensubentries(p:halfword):integer;
var k,c:integer;l,r:integer;begin k:=0;
if pdfmem[objtab[p].int4+4]<>0 then begin l:=pdfmem[objtab[p].int4+4];
repeat incr(k);c:=opensubentries(l);if objtab[l].int0>0 then k:=k+c;
pdfmem[objtab[l].int4+1]:=p;r:=pdfmem[objtab[l].int4+3];
if r=0 then pdfmem[objtab[p].int4+5]:=l;l:=r;until l=0;end;
if objtab[p].int0>0 then objtab[p].int0:=k else objtab[p].int0:=-k;
opensubentries:=k;end;procedure dodest(p,parentbox:halfword;x,y:scaled);
var k:integer;begin if not isshippingpage then pdferror(1846,1931);
if doingleaders then goto 10;k:=getobj(5,mem[p+5].hh.rh,mem[p+5].hh.b1);
if objtab[k].int4<>-268435455 then begin warndestdup(mem[p+5].hh.rh,mem[
p+5].hh.b1,1846,1847);goto 10;end;objtab[k].int4:=p;
begin pdfappendlistarg:=k;
pdfdestlist:=appendptr(pdfdestlist,pdfappendlistarg);end;
case mem[p+5].hh.b0 of 0:if matrixused then setrectdimens(p,parentbox,x,
y,mem[p+1].int,mem[p+2].int,mem[p+3].int,eqtb[27819].int)else begin mem[
p+1].int:=curh;mem[p+2].int:=curv;end;
2,5:if matrixused then setrectdimens(p,parentbox,x,y,mem[p+1].int,mem[p
+2].int,mem[p+3].int,eqtb[27819].int)else mem[p+2].int:=curv;
3,6:if matrixused then setrectdimens(p,parentbox,x,y,mem[p+1].int,mem[p
+2].int,mem[p+3].int,eqtb[27819].int)else mem[p+1].int:=curh;1,4:;
7:setrectdimens(p,parentbox,x,y,mem[p+1].int,mem[p+2].int,mem[p+3].int,
eqtb[27819].int);end;end;procedure outform(p:halfword);begin pdfendtext;
begin pdfprint(113);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if pdflookuplist(pdfxformlist,mem[p+4].hh.lh)=-268435455 then begin
pdfappendlistarg:=mem[p+4].hh.lh;
pdfxformlist:=appendptr(pdfxformlist,pdfappendlistarg);end;
curv:=curv+pdfmem[objtab[mem[p+4].hh.lh].int4+2];pdfprint(1029);
pdfprintbp(((curh)-pdforiginh));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintbp((pdforiginv-(curv)));begin pdfprint(1030);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfprint(1143);
pdfprintint(objtab[mem[p+4].hh.lh].int0);
if pdfresnameprefix<>0 then pdfprint(pdfresnameprefix);
begin pdfprint(1932);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;begin pdfprint(81);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
procedure outimage(p:halfword);var image,groupref:integer;
imgw,imgh:integer;begin image:=pdfmem[objtab[mem[p+4].hh.lh].int4+4];
if(imagerotate(image)=90)or(imagerotate(image)=270)then begin imgh:=
imagewidth(image);imgw:=imageheight(image);
end else begin imgw:=imagewidth(image);imgh:=imageheight(image);end;
pdfendtext;begin pdfprint(113);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if pdflookuplist(pdfximagelist,mem[p+4].hh.lh)=-268435455 then begin
pdfappendlistarg:=mem[p+4].hh.lh;
pdfximagelist:=appendptr(pdfximagelist,pdfappendlistarg);end;
if not ispdfimage(image)then begin if ispngimage(image)then begin
groupref:=getimagegroupref(image);
if(groupref>0)and(pdfpagegroupval=0)then pdfpagegroupval:=groupref;end;
pdfprintreal(extxnoverd(mem[p+1].int,tenpow[6],onehundredbp),4);
pdfprint(1138);
pdfprintreal(extxnoverd(mem[p+2].int+mem[p+3].int,tenpow[6],onehundredbp
),4);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintbp(((curh)-pdforiginh));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintbp((pdforiginv-(curv)));
end else begin groupref:=getimagegroupref(image);
if(groupref<>0)and(pdfpagegroupval=0)then begin if groupref=-1 then
begin pdfpagegroupval:=pdfnewobjnum;
setimagegroupref(image,pdfpagegroupval);
end else pdfpagegroupval:=groupref;end;
pdfprintreal(extxnoverd(mem[p+1].int,tenpow[6],imgw),6);pdfprint(1138);
pdfprintreal(extxnoverd(mem[p+2].int+mem[p+3].int,tenpow[6],imgh),6);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintbp(((curh)-pdforiginh)-extxnoverd(mem[p+1].int,epdforigx(image),
imgw));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintbp((pdforiginv-(curv))-extxnoverd(mem[p+2].int+mem[p+3].int,
epdforigy(image),imgh));end;begin pdfprint(1030);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfprint(1144);
pdfprintint(objtab[mem[p+4].hh.lh].int0);
if pdfresnameprefix<>0 then pdfprint(pdfresnameprefix);
begin pdfprint(1932);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;begin pdfprint(81);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
function gapamount(p:halfword;curpos:scaled):scaled;
var snapunit,stretchamount,shrinkamount:scaled;
lastpos,nextpos,g,g2:scaled;begin snapunit:=mem[mem[p+1].hh.lh+1].int;
if mem[mem[p+1].hh.lh].hh.b0>0 then stretchamount:=1073741823 else
stretchamount:=mem[mem[p+1].hh.lh+2].int;
if mem[mem[p+1].hh.lh].hh.b1>0 then shrinkamount:=1073741823 else
shrinkamount:=mem[mem[p+1].hh.lh+3].int;
if mem[p].hh.b1=35 then lastpos:=pdfsnapyrefpos+snapunit*((curpos-
pdfsnapyrefpos)div snapunit)else pdferror(1933,1934);
nextpos:=lastpos+snapunit;{printnl(1935);printscaled(pdfsnapyrefpos);
printnl(1936);printspec(mem[p+1].hh.lh,0);printnl(1937);
printscaled(snapunit);printnl(1938);printscaled(stretchamount);
printnl(1939);printscaled(shrinkamount);printnl(1940);
printscaled(lastpos);printnl(1941);printscaled(curpos);printnl(1942);
printscaled(nextpos);}g:=1073741823;g2:=1073741823;gapamount:=0;
if curpos-lastpos<shrinkamount then g:=curpos-lastpos;
if(nextpos-curpos<stretchamount)then g2:=nextpos-curpos;
if(g=1073741823)and(g2=1073741823)then goto 10;
if g2<=g then gapamount:=g2 else gapamount:=-g;end;
function getvpos(p,q,b:halfword):halfword;var tmpv:scaled;
gorder:glueord;gsign:0..2;gluetemp:real;curglue:real;curg:scaled;
thisbox:halfword;begin tmpv:=curv;thisbox:=b;curg:=0;curglue:=0.0;
gorder:=mem[thisbox+5].hh.b1;gsign:=mem[thisbox+5].hh.b0;
while(p<>q)and(p<>-268435455)do begin if(p>=himemmin)then confusion(1943
)else begin case mem[p].hh.b0 of 0,1,2:tmpv:=tmpv+mem[p+3].int+mem[p+2].
int;
8:if(mem[p].hh.b1=10)or(mem[p].hh.b1=12)then tmpv:=tmpv+mem[p+2].int+mem
[p+3].int;10:begin{1636:}begin g:=mem[p+1].hh.lh;
ruleht:=mem[g+1].int-curg;
if gsign<>0 then begin if gsign=1 then begin if mem[g].hh.b0=gorder then
begin curglue:=curglue+mem[g+2].int;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end else if mem[g].hh.b1=gorder then begin curglue:=curglue-mem[g+3].int
;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end;ruleht:=ruleht+curg;end{:1636};tmpv:=tmpv+ruleht;end;
11:tmpv:=tmpv+mem[p+1].int;others:;end;end;p:=mem[p].hh.rh;end;
getvpos:=tmpv;end;procedure dosnapycomp(p,b:halfword);var q:halfword;
tmpv,g,g2:scaled;
begin if not(not(p>=himemmin)and(mem[p].hh.b0=8)and(mem[p].hh.b1=36))
then pdferror(1933,1944);q:=p;
while(q<>-268435455)do begin if not(q>=himemmin)and(mem[q].hh.b0=8)and(
mem[q].hh.b1=35)then begin tmpv:=getvpos(p,q,b);g:=gapamount(q,tmpv);
g2:=roundxnoverd(g,mem[p+1].int,1000);{printnl(1945);printscaled(tmpv);
printnl(1946);printscaled(curv);printnl(1947);printscaled(g);
printnl(1948);printscaled(g2);}curv:=curv+g2;mem[q+2].int:=g-g2;
if mem[q+2].int=0 then mem[q+2].int:=1;goto 10;end;q:=mem[q].hh.rh;end;
end;procedure dosnapy(p:halfword);begin incr(countdosnapy);
{printnl(1949);printint(countdosnapy);printnl(1950);printscaled(curv);
printnl(1951);printscaled(mem[p+2].int);}
if mem[p+2].int<>0 then curv:=curv+mem[p+2].int else curv:=curv+
gapamount(p,curv);{printnl(1952);printscaled(curv);}end;
{:1635}procedure pdfhlistout;label 21,13,14,15,40,22;
var baseline:scaled;leftedge:scaled;saveh:scaled;thisbox:halfword;
gorder:glueord;gsign:0..2;p:halfword;leaderbox:halfword;leaderwd:scaled;
lx:scaled;outerdoingleaders:boolean;edge:scaled;prevp:halfword;
gluetemp:real;curglue:real;curg:scaled;i:smallnumber;begin curg:=0;
curglue:=0.0;thisbox:=tempptr;gorder:=mem[thisbox+5].hh.b1;
gsign:=mem[thisbox+5].hh.b0;p:=mem[thisbox+5].hh.rh;incr(curs);
baseline:=curv;prevp:=thisbox+5;
{1712:}if(eTeXmode=1)then begin{1708:}begin tempptr:=getavail;
mem[tempptr].hh.lh:=0;mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;
end{:1708};
if(mem[thisbox].hh.b1)=2 then if curdir=1 then begin curdir:=0;
curh:=curh-mem[thisbox+1].int;end else mem[thisbox].hh.b1:=0;
if(curdir=1)and((mem[thisbox].hh.b1)<>1)then{1719:}begin saveh:=curh;
tempptr:=p;p:=newkern(0);mem[p+2].int:=0;mem[prevp].hh.rh:=p;curh:=0;
mem[p].hh.rh:=reverse(thisbox,-268435455,curg,curglue);
mem[p+1].int:=-curh;curh:=saveh;mem[thisbox].hh.b1:=1;end{:1719};
end{:1712};leftedge:=curh;
{733:}for i:=1 to pdflinkstackptr do begin pdfassert((mem[pdflinkstack[i
].linknode+1].int=-1073741824));
if(pdflinkstack[i].nestinglevel=curs)then appendlink(thisbox,leftedge,
baseline,i);end{:733};{1920:}synctexhlist(thisbox);{:1920};
while p<>-268435455 do{734:}21:if(p>=himemmin)then begin repeat f:=mem[p
].hh.b0;c:=mem[p].hh.b1;
if((fontbc[f]<=c)and(c<=fontec[f])and(fontinfo[charbase[f]+c].qqqq.b0>0)
)then begin begin if pdffonttype[f]=0 then dovf(f);
if pdffonttype[f]=1 then dovfpacket(f,c)else begin pdfbeginstring(f);
pdfprintchar(f,c);advcharwidth(f,c);end;end;
curh:=curh+fontinfo[widthbase[f]+fontinfo[charbase[f]+effectivechar(true
,f,c)].qqqq.b0].int;goto 22;end;
if mltexenabledp then{741:}begin{1883:}if c>=eqtb[27232].int then if c<=
eqtb[27233].int then if(eqtb[26921+c].hh.rh>0)then begin basec:=(eqtb[
26921+c].hh.rh mod 256);accentc:=(eqtb[26921+c].hh.rh div 256);
if(fontec[f]>=basec)then if(fontbc[f]<=basec)then if(fontec[f]>=accentc)
then if(fontbc[f]<=accentc)then begin iac:=fontinfo[charbase[f]+
effectivechar(true,f,accentc)].qqqq;
ibc:=fontinfo[charbase[f]+effectivechar(true,f,basec)].qqqq;
if(ibc.b0>0)then if(iac.b0>0)then goto 40;end;begindiagnostic;
printnl(2065);print(c);print(1619);print(accentc);print(32);
print(basec);print(984);slowprint(fontname[f]);printchar(33);
enddiagnostic(false);goto 22;end;begindiagnostic;printnl(983);
print(2064);print(c);print(984);slowprint(fontname[f]);printchar(33);
enddiagnostic(false);goto 22{:1883};
40:{1884:}if eqtb[27212].int>99 then begin begindiagnostic;
printnl(2066);print(c);print(1619);print(accentc);print(32);
print(basec);print(984);slowprint(fontname[f]);printchar(46);
enddiagnostic(false);end{:1884};
{742:}basexheight:=fontinfo[5+parambase[f]].int;
baseslant:=fontinfo[1+parambase[f]].int/65536.0;accentslant:=baseslant;
basewidth:=fontinfo[widthbase[f]+ibc.b0].int;
baseheight:=fontinfo[heightbase[f]+(ibc.b1)div 16].int;
accentwidth:=fontinfo[widthbase[f]+iac.b0].int;
accentheight:=fontinfo[heightbase[f]+(iac.b1)div 16].int;
delta:=round((basewidth-accentwidth)/2.0+baseheight*baseslant-
basexheight*accentslant);curh:=curh+delta;
if((baseheight<>basexheight)and(accentheight>0))then begin curv:=
baseline+(basexheight-baseheight);
begin if pdffonttype[f]=0 then dovf(f);
if pdffonttype[f]=1 then dovfpacket(f,accentc)else begin pdfbeginstring(
f);pdfprintchar(f,accentc);advcharwidth(f,accentc);end;end;
curv:=baseline;end else begin begin if pdffonttype[f]=0 then dovf(f);
if pdffonttype[f]=1 then dovfpacket(f,accentc)else begin pdfbeginstring(
f);pdfprintchar(f,accentc);advcharwidth(f,accentc);end;end;end;
curh:=curh+accentwidth;curh:=curh+(-accentwidth-delta);
begin if pdffonttype[f]=0 then dovf(f);
if pdffonttype[f]=1 then dovfpacket(f,basec)else begin pdfbeginstring(f)
;pdfprintchar(f,basec);advcharwidth(f,basec);end;end;
curh:=curh+basewidth;{:742};end{:741};22:prevp:=mem[prevp].hh.rh;
p:=mem[p].hh.rh;until not(p>=himemmin);{1923:}synctexcurrent;{:1923};
end else{735:}begin case mem[p].hh.b0 of 0,1:{736:}if mem[p+5].hh.rh=
-268435455 then begin{1922:}if mem[p].hh.b0=1 then begin
synctexvoidvlist(p,thisbox);end else begin synctexvoidhlist(p,thisbox);
end;{:1922};curh:=curh+mem[p+1].int;
end else begin curv:=baseline+mem[p+4].int;tempptr:=p;
edge:=curh+mem[p+1].int;if curdir=1 then curh:=edge;
if mem[p].hh.b0=1 then pdfvlistout else pdfhlistout;curh:=edge;
curv:=baseline;end{:736};2:begin ruleht:=mem[p+3].int;
ruledp:=mem[p+2].int;rulewd:=mem[p+1].int;goto 14;end;
8:{1643:}case mem[p].hh.b1 of 6:pdfoutliteral(p);38:pdfoutcolorstack(p);
39:pdfoutsetmatrix(p);40:pdfoutsave(p);41:pdfoutrestore(p);
8:begin pdfappendlistarg:=mem[p+1].hh.lh;
pdfobjlist:=appendptr(pdfobjlist,pdfappendlistarg);end;
10:{1645:}begin curv:=baseline;edge:=curh;outform(p);
curh:=edge+mem[p+1].int;curv:=baseline;end{:1645};
12:{1644:}begin curv:=baseline+mem[p+3].int;edge:=curh;outimage(p);
curh:=edge+mem[p+1].int;curv:=baseline;end{:1644};
13:doannot(p,thisbox,leftedge,baseline);
14:dolink(p,thisbox,leftedge,baseline);15:endlink;
17:dodest(p,thisbox,leftedge,baseline);
18:dothread(p,thisbox,leftedge,baseline);19:pdferror(1846,1955);
20:pdferror(1846,1956);21:{1639:}begin pdflastxpos:=curh;
if isshippingpage then pdflastypos:=curpageheight-curv else pdflastypos
:=pdfxformheight+pdfxformdepth-curv;end{:1639};3:pdfspecial(p);
34:{1640:}begin pdfsnapxrefpos:=curh;pdfsnapyrefpos:=curv;end{:1640};
36,35:;43:genfakedinterwordspace:=true;44:genfakedinterwordspace:=false;
45:pdfinsertfakespace;others:outwhat(p);end{:1643};
10:{738:}begin g:=mem[p+1].hh.lh;rulewd:=mem[g+1].int-curg;
if gsign<>0 then begin if gsign=1 then begin if mem[g].hh.b0=gorder then
begin curglue:=curglue+mem[g+2].int;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end else if mem[g].hh.b1=gorder then begin curglue:=curglue-mem[g+3].int
;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end;rulewd:=rulewd+curg;
if(eTeXmode=1)then{1697:}if(((gsign=1)and(mem[g].hh.b0=gorder))or((gsign
=2)and(mem[g].hh.b1=gorder)))then begin begin if mem[g].hh.rh=-268435455
then freenode(g,4)else decr(mem[g].hh.rh);end;
if mem[p].hh.b1<100 then begin mem[p].hh.b0:=11;mem[p+1].int:=rulewd;
end else begin g:=getnode(4);mem[g].hh.b0:=4;mem[g].hh.b1:=4;
mem[g+1].int:=rulewd;mem[g+2].int:=0;mem[g+3].int:=0;mem[p+1].hh.lh:=g;
end;end{:1697};
if mem[p].hh.b1>=100 then{739:}begin leaderbox:=mem[p+1].hh.rh;
if mem[leaderbox].hh.b0=2 then begin ruleht:=mem[leaderbox+3].int;
ruledp:=mem[leaderbox+2].int;goto 14;end;leaderwd:=mem[leaderbox+1].int;
if(leaderwd>0)and(rulewd>0)then begin rulewd:=rulewd+10;
if curdir=1 then curh:=curh-10;edge:=curh+rulewd;lx:=0;
{658:}if mem[p].hh.b1=100 then begin saveh:=curh;
curh:=leftedge+leaderwd*((curh-leftedge)div leaderwd);
if curh<saveh then curh:=curh+leaderwd;
end else begin lq:=rulewd div leaderwd;lr:=rulewd mod leaderwd;
if mem[p].hh.b1=101 then curh:=curh+(lr div 2)else begin lx:=lr div(lq+1
);curh:=curh+((lr-(lq-1)*lx)div 2);end;end{:658};
while curh+leaderwd<=edge do{740:}begin curv:=baseline+mem[leaderbox+4].
int;saveh:=curh;tempptr:=leaderbox;if curdir=1 then curh:=curh+leaderwd;
outerdoingleaders:=doingleaders;doingleaders:=true;
if mem[leaderbox].hh.b0=1 then pdfvlistout else pdfhlistout;
doingleaders:=outerdoingleaders;curv:=baseline;curh:=saveh+leaderwd+lx;
end{:740};if curdir=1 then curh:=edge else curh:=edge-10;goto 15;end;
end{:739};goto 13;end{:738};40:curh:=curh+mem[p+1].int;
11:begin{1925:}synctexkern(p,thisbox);{:1925};curh:=curh+mem[p+1].int;
end;9:begin{1926:}synctexmath(p,thisbox);{:1926};
{1714:}begin if(eTeXmode=1)then{1715:}begin if odd(mem[p].hh.b1)then if
mem[LRptr].hh.lh=(4*(mem[p].hh.b1 div 4)+3)then begin tempptr:=LRptr;
LRptr:=mem[tempptr].hh.rh;begin mem[tempptr].hh.rh:=avail;
avail:=tempptr;ifdef('STAT')decr(dynused);endif('STAT')end;
end else begin if mem[p].hh.b1>4 then incr(LRproblems);
end else begin begin tempptr:=getavail;
mem[tempptr].hh.lh:=(4*(mem[p].hh.b1 div 4)+3);
mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;end;
if(mem[p].hh.b1 div 8)<>curdir then{1720:}begin saveh:=curh;
tempptr:=mem[p].hh.rh;rulewd:=mem[p+1].int;freenode(p,4);
curdir:=1-curdir;p:=newedge(curdir,rulewd);mem[prevp].hh.rh:=p;
curh:=curh-leftedge+rulewd;
mem[p].hh.rh:=reverse(thisbox,newedge(1-curdir,0),curg,curglue);
mem[p+2].int:=curh;curdir:=1-curdir;curh:=saveh;goto 21;end{:1720};end;
mem[p].hh.b0:=11;end{:1715};curh:=curh+mem[p+1].int;end{:1714};end;
6:{827:}begin mem[memtop-12]:=mem[p+1];
mem[memtop-12].hh.rh:=mem[p].hh.rh;p:=memtop-12;goto 21;end{:827};
{1718:}14:begin curh:=curh+mem[p+1].int;leftedge:=curh+mem[p+2].int;
curdir:=mem[p].hh.b1;end;{:1718}others:end;goto 15;
14:{737:}if(ruleht=-1073741824)then ruleht:=mem[thisbox+3].int;
if(ruledp=-1073741824)then ruledp:=mem[thisbox+2].int;
ruleht:=ruleht+ruledp;
if(ruleht>0)and(rulewd>0)then begin curv:=baseline+ruledp;
pdfsetrule(curh,curv,rulewd,ruleht);curv:=baseline;end{:737};
13:begin curh:=curh+rulewd;
{1924:}synctexhorizontalruleorglue(p,thisbox);{:1924};end;15:prevp:=p;
p:=mem[p].hh.rh;end{:735}{:734};{1921:}synctextsilh(thisbox);{:1921};
{1713:}if(eTeXmode=1)then begin{1716:}begin while mem[LRptr].hh.lh<>0 do
begin if mem[LRptr].hh.lh>4 then LRproblems:=LRproblems+10000;
begin tempptr:=LRptr;LRptr:=mem[tempptr].hh.rh;
begin mem[tempptr].hh.rh:=avail;avail:=tempptr;
ifdef('STAT')decr(dynused);endif('STAT')end;end;end;
begin tempptr:=LRptr;LRptr:=mem[tempptr].hh.rh;
begin mem[tempptr].hh.rh:=avail;avail:=tempptr;
ifdef('STAT')decr(dynused);endif('STAT')end;end;end{:1716};
if(mem[thisbox].hh.b1)=2 then curdir:=1;end{:1713};decr(curs);end;
{:732}{743:}procedure pdfvlistout;label 13,14,15;var leftedge:scaled;
topedge:scaled;savev:scaled;thisbox:halfword;gorder:glueord;gsign:0..2;
p:halfword;leaderbox:halfword;leaderht:scaled;lx:scaled;
outerdoingleaders:boolean;edge:scaled;gluetemp:real;curglue:real;
curg:scaled;begin curg:=0;curglue:=0.0;thisbox:=tempptr;
gorder:=mem[thisbox+5].hh.b1;gsign:=mem[thisbox+5].hh.b0;
p:=mem[thisbox+5].hh.rh;incr(curs);leftedge:=curh;
{1918:}synctexvlist(thisbox);{:1918};curv:=curv-mem[thisbox+3].int;
topedge:=curv;
{744:}if(lastthread<>-268435455)and(pdfthreaddp=-1073741824)and(
pdfthreadlevel=curs)then appendthread(thisbox,leftedge,topedge+mem[
thisbox+3].int){:744};
while p<>-268435455 do{745:}begin if(p>=himemmin)then confusion(1129)
else{746:}begin case mem[p].hh.b0 of 0,1:{747:}if mem[p+5].hh.rh=
-268435455 then begin curv:=curv+mem[p+3].int;
{1922:}if mem[p].hh.b0=1 then begin synctexvoidvlist(p,thisbox);
end else begin synctexvoidhlist(p,thisbox);end;{:1922};
curv:=curv+mem[p+2].int;end else begin curv:=curv+mem[p+3].int;
savev:=curv;
if curdir=1 then curh:=leftedge-mem[p+4].int else curh:=leftedge+mem[p+4
].int;tempptr:=p;if mem[p].hh.b0=1 then pdfvlistout else pdfhlistout;
curv:=savev+mem[p+2].int;curh:=leftedge;end{:747};
2:begin ruleht:=mem[p+3].int;ruledp:=mem[p+2].int;rulewd:=mem[p+1].int;
goto 14;end;8:{1637:}case mem[p].hh.b1 of 6:pdfoutliteral(p);
38:pdfoutcolorstack(p);39:pdfoutsetmatrix(p);40:pdfoutsave(p);
41:pdfoutrestore(p);8:begin pdfappendlistarg:=mem[p+1].hh.lh;
pdfobjlist:=appendptr(pdfobjlist,pdfappendlistarg);end;
10:{1642:}begin curv:=curv+mem[p+2].int;savev:=curv;curh:=leftedge;
outform(p);curv:=savev+mem[p+3].int;curh:=leftedge;end{:1642};
12:{1641:}begin curv:=curv+mem[p+2].int+mem[p+3].int;savev:=curv;
curh:=leftedge;outimage(p);curv:=savev;curh:=leftedge;end{:1641};
13:doannot(p,thisbox,leftedge,topedge+mem[thisbox+3].int);
14:pdferror(1846,1953);15:pdferror(1846,1954);
17:dodest(p,thisbox,leftedge,topedge+mem[thisbox+3].int);
18,19:dothread(p,thisbox,leftedge,topedge+mem[thisbox+3].int);
20:endthread;21:{1639:}begin pdflastxpos:=curh;
if isshippingpage then pdflastypos:=curpageheight-curv else pdflastypos
:=pdfxformheight+pdfxformdepth-curv;end{:1639};3:pdfspecial(p);
34:{1640:}begin pdfsnapxrefpos:=curh;pdfsnapyrefpos:=curv;end{:1640};
36:dosnapycomp(p,thisbox);35:dosnapy(p);43:genfakedinterwordspace:=true;
44:genfakedinterwordspace:=false;45:pdfinsertfakespace;
others:outwhat(p);end{:1637};10:{749:}begin g:=mem[p+1].hh.lh;
ruleht:=mem[g+1].int-curg;
if gsign<>0 then begin if gsign=1 then begin if mem[g].hh.b0=gorder then
begin curglue:=curglue+mem[g+2].int;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end else if mem[g].hh.b1=gorder then begin curglue:=curglue-mem[g+3].int
;gluetemp:=mem[thisbox+6].gr*curglue;
if gluetemp>1000000000.0 then gluetemp:=1000000000.0 else if gluetemp<
-1000000000.0 then gluetemp:=-1000000000.0;curg:=round(gluetemp);end;
end;ruleht:=ruleht+curg;
if mem[p].hh.b1>=100 then{750:}begin leaderbox:=mem[p+1].hh.rh;
if mem[leaderbox].hh.b0=2 then begin rulewd:=mem[leaderbox+1].int;
ruledp:=0;goto 14;end;
leaderht:=mem[leaderbox+3].int+mem[leaderbox+2].int;
if(leaderht>0)and(ruleht>0)then begin ruleht:=ruleht+10;
edge:=curv+ruleht;lx:=0;
{667:}if mem[p].hh.b1=100 then begin savev:=curv;
curv:=topedge+leaderht*((curv-topedge)div leaderht);
if curv<savev then curv:=curv+leaderht;
end else begin lq:=ruleht div leaderht;lr:=ruleht mod leaderht;
if mem[p].hh.b1=101 then curv:=curv+(lr div 2)else begin lx:=lr div(lq+1
);curv:=curv+((lr-(lq-1)*lx)div 2);end;end{:667};
while curv+leaderht<=edge do{751:}begin if curdir=1 then curh:=leftedge-
mem[leaderbox+4].int else curh:=leftedge+mem[leaderbox+4].int;
curv:=curv+mem[leaderbox+3].int;savev:=curv;tempptr:=leaderbox;
outerdoingleaders:=doingleaders;doingleaders:=true;
if mem[leaderbox].hh.b0=1 then pdfvlistout else pdfhlistout;
doingleaders:=outerdoingleaders;curh:=leftedge;
curv:=savev-mem[leaderbox+3].int+leaderht+lx;end{:751};curv:=edge-10;
goto 15;end;end{:750};goto 13;end{:749};11:curv:=curv+mem[p+1].int;
others:end;goto 15;
14:{748:}if(rulewd=-1073741824)then rulewd:=mem[thisbox+1].int;
ruleht:=ruleht+ruledp;curv:=curv+ruleht;
if(ruleht>0)and(rulewd>0)then begin if curdir=1 then curh:=curh-rulewd;
pdfsetrule(curh,curv,rulewd,ruleht);curh:=leftedge;end;goto 15{:748};
13:curv:=curv+ruleht;end{:746};15:p:=mem[p].hh.rh;end{:745};
{1919:}synctextsilv(thisbox);{:1919};decr(curs);end;
{:743}{752:}procedure fixpdfoutput;
begin if not fixedpdfoutputset then begin fixedpdfoutput:=eqtb[27239].
int;fixedpdfoutputset:=true;
end else if fixedpdfoutput<>eqtb[27239].int then pdferror(1011,1130);
if fixedpdfoutputset then fixpdfdraftmode;end;
{:752}{753:}procedure fixpdfdraftmode;
begin if not fixedpdfdraftmodeset then begin fixedpdfdraftmode:=eqtb[
27264].int;fixedpdfdraftmodeset:=true;
end else if fixedpdfdraftmode<>eqtb[27264].int then pdferror(1011,1131);
if fixedpdfdraftmodeset and fixedpdfdraftmode>0 then begin
fixedpdfdraftmodeset:=true;eqtb[27240].int:=0;
fixedpdfobjcompresslevel:=0;end;end;
{:753}{754:}procedure pdfshipout(p:halfword;shippingpage:boolean);
label 30,31;var i,j,k:integer;savefontlist:halfword;
saveobjlist:halfword;saveximagelist:halfword;savexformlist:halfword;
saveimageprocset:integer;savetextprocset:integer;
pdflastresources:integer;begin{1916:}pdfoutputvalue:=eqtb[27239].int;
synctexsheet(eqtb[27194].int);{:1916};
begin if eqtb[27211].int>0 then begin printnl(345);println;print(988);
end;if not initpdfoutput then begin{795:}checkpdfminorversion;
preparemag;fixeddecimaldigits:=fixint(eqtb[27241].int,0,4);
minbpval:=dividescaled(onehundredbp,tenpow[fixeddecimaldigits+2],0);
if eqtb[27244].int=0 then eqtb[27244].int:=pkdpi;
fixedpkresolution:=fixint(eqtb[27244].int,72,8000);
pkscalefactor:=dividescaled(72,fixedpkresolution,5+fixeddecimaldigits);
if eqtb[25071].hh.rh<>-268435455 then begin kpseinitprog('PDFTEX',
fixedpkresolution,makecstring(tokenstostring(eqtb[25071].hh.rh)),nil);
begin decr(strptr);poolptr:=strstart[strptr];end;
end else kpseinitprog('PDFTEX',fixedpkresolution,nil,nil);
kpsesetprogramenabled(kpsepkformat,1,kpsesrccompile);
setjobid(eqtb[27200].int,eqtb[27199].int,eqtb[27198].int,eqtb[27197].int
);if(eqtb[27245].int>0)and(pdfresnameprefix=0)then pdfresnameprefix:=
getresnameprefix{:795};initpdfoutput:=true;end;
isshippingpage:=shippingpage;
if shippingpage then begin if termoffset>maxprintline-9 then println
else if(termoffset>0)or(fileoffset>0)then printchar(32);printchar(91);
j:=9;while(eqtb[27281+j].int=0)and(j>0)do decr(j);
for k:=0 to j do begin printint(eqtb[27281+k].int);
if k<j then printchar(46);end;fflush(stdout);end;
if eqtb[27211].int>0 then begin if shippingpage then printchar(93);
begindiagnostic;showbox(p);enddiagnostic(true);end;
{755:}{672:}if(mem[p+3].int>1073741823)or(mem[p+2].int>1073741823)or(mem
[p+3].int+mem[p+2].int+eqtb[27812].int>1073741823)or(mem[p+1].int+eqtb[
27811].int>1073741823)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(992);
end;begin helpptr:=2;helpline[1]:=993;helpline[0]:=994;end;error;
if eqtb[27211].int<=0 then begin begindiagnostic;printnl(995);
showbox(p);enddiagnostic(true);end;goto 30;end;
if mem[p+3].int+mem[p+2].int+eqtb[27812].int>maxv then maxv:=mem[p+3].
int+mem[p+2].int+eqtb[27812].int;
if mem[p+1].int+eqtb[27811].int>maxh then maxh:=mem[p+1].int+eqtb[27811]
.int{:672};{756:}fixpdfoutput;tempptr:=p;preparemag;
pdflastresources:=pdfnewobjnum;pdfpagegroupval:=0;
{757:}pdffontlist:=-268435455;pdfobjlist:=-268435455;
pdfxformlist:=-268435455;pdfximagelist:=-268435455;
pdftextprocset:=false;pdfimageprocset:=0{:757};
if not shippingpage then begin pdfxformwidth:=mem[p+1].int;
pdfxformheight:=mem[p+3].int;pdfxformdepth:=mem[p+2].int;
pdfbegindict(pdfcurform,0);pdflaststream:=pdfcurform;curv:=mem[p+3].int;
curh:=0;pdforiginh:=0;pdforiginv:=pdfxformheight+pdfxformdepth;
end else begin{759:}curhoffset:=eqtb[27814].int+eqtb[27811].int;
curvoffset:=eqtb[27815].int+eqtb[27812].int;
if eqtb[27816].int<>0 then curpagewidth:=eqtb[27816].int else
curpagewidth:=mem[p+1].int+2*curhoffset;
if eqtb[27817].int<>0 then curpageheight:=eqtb[27817].int else
curpageheight:=mem[p+3].int+mem[p+2].int+2*curvoffset{:759};
pdflastpage:=getobj(1,totalpages+1,0);objtab[pdflastpage].int4:=1;
pdfnewdict(0,0,0);pdflaststream:=objptr;curh:=curhoffset;
curv:=mem[p+3].int+curvoffset;pdforiginh:=0;pdforiginv:=curpageheight;
{758:}pdfannotlist:=-268435455;pdflinklist:=-268435455;
pdfdestlist:=-268435455;pdfbeadlist:=-268435455;
lastthread:=-268435455{:758};end;
if not shippingpage then begin{760:}begin pdfprint(1132);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;begin pdfprint(1133);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if pdfmem[objtab[pdfcurform].int4+4]<>-268435455 then begin
pdfprinttoksln(pdfmem[objtab[pdfcurform].int4+4]);
begin deletetokenref(pdfmem[objtab[pdfcurform].int4+4]);
pdfmem[objtab[pdfcurform].int4+4]:=-268435455;end;end;pdfprint(1134);
pdfprint(1050);pdfprintbp(pdfxformwidth);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintbp(pdfxformheight+pdfxformdepth);begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;begin pdfprint(1135);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;begin pdfprint(1136);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfindirectln(1137,pdflastresources){:760};end;{761:}pdfbeginstream;
if shippingpage then begin{762:}preparemag;
if eqtb[27194].int<>1000 then begin pdfprintreal(eqtb[27194].int,3);
pdfprint(1138);pdfprintreal(eqtb[27194].int,3);begin pdfprint(1139);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end{:762};end;
pdfshipoutbegin(shippingpage);
if shippingpage then pdfoutcolorstackstartpage;{:761}{:756};
if mem[p].hh.b0=1 then pdfvlistout else pdfhlistout;
if shippingpage then incr(totalpages);curs:=-1;{763:}{764:}pdfendtext;
pdfshipoutend(shippingpage);pdfendstream{:764};
if shippingpage then begin{773:}pdfbegindict(pdflastpage,1);
begin pdfprint(1151);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfindirectln(1152,pdflaststream);pdfindirectln(1137,pdflastresources);
pdfprint(1153);pdfprintmagbp(curpagewidth);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintmagbp(curpageheight);begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if eqtb[25069].hh.rh<>-268435455 then pdfprinttoksln(eqtb[25069].hh.rh);
{774:}if totalpages mod 6=1 then begin pdfcreateobj(2,6);
pdflastpages:=objptr;end;pdfindirectln(1155,pdflastpages){:774};
if pdfpagegroupval>0 then begin pdfprint(1154);
pdfprintint(pdfpagegroupval);begin pdfprint(1070);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
{775:}if(pdfannotlist<>-268435455)or(pdflinklist<>-268435455)then begin
pdfprint(1156);k:=pdfannotlist;
while k<>-268435455 do begin pdfprintint(mem[k].hh.lh);pdfprint(1141);
k:=mem[k].hh.rh;end;k:=pdflinklist;
while k<>-268435455 do begin pdfprintint(mem[k].hh.lh);pdfprint(1141);
k:=mem[k].hh.rh;end;begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
if pdfbeadlist<>-268435455 then begin k:=pdfbeadlist;pdfprint(1157);
while k<>-268435455 do begin pdfprintint(mem[k].hh.lh);pdfprint(1141);
k:=mem[k].hh.rh;end;begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end{:775};
pdfenddict{:773};end;
{765:}{777:}if pdfobjlist<>-268435455 then begin k:=pdfobjlist;
while k<>-268435455 do begin if not(objtab[mem[k].hh.lh].int2>-1)then
pdfwriteobj(mem[k].hh.lh);k:=mem[k].hh.rh;end;end{:777};
{778:}if pdfxformlist<>-268435455 then begin k:=pdfxformlist;
while k<>-268435455 do begin if not(objtab[mem[k].hh.lh].int2>-1)then
begin pdfcurform:=mem[k].hh.lh;{779:}savefontlist:=pdffontlist;
saveobjlist:=pdfobjlist;savexformlist:=pdfxformlist;
saveximagelist:=pdfximagelist;savetextprocset:=pdftextprocset;
saveimageprocset:=pdfimageprocset{:779};{757:}pdffontlist:=-268435455;
pdfobjlist:=-268435455;pdfxformlist:=-268435455;
pdfximagelist:=-268435455;pdftextprocset:=false;
pdfimageprocset:=0{:757};
pdfshipout(pdfmem[objtab[pdfcurform].int4+3],false);
{780:}pdffontlist:=savefontlist;pdfobjlist:=saveobjlist;
pdfxformlist:=savexformlist;pdfximagelist:=saveximagelist;
pdftextprocset:=savetextprocset;pdfimageprocset:=saveimageprocset{:780};
end;k:=mem[k].hh.rh;end;end{:778};
{782:}if pdfximagelist<>-268435455 then begin k:=pdfximagelist;
while k<>-268435455 do begin if not(objtab[mem[k].hh.lh].int2>-1)then
pdfwriteimage(mem[k].hh.lh);k:=mem[k].hh.rh;end;end{:782}{:765};
if shippingpage then begin{783:}pdforiginh:=0;pdforiginv:=curpageheight;
{784:}if pdfannotlist<>-268435455 then begin k:=pdfannotlist;
while k<>-268435455 do begin i:=objtab[mem[k].hh.lh].int4;
pdfbegindict(mem[k].hh.lh,1);begin pdfprint(1162);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfprinttoksln(mem[i+5].hh.lh);
pdfrectangle(mem[i+1].int,mem[i+2].int,mem[i+3].int,mem[i+4].int);
pdfenddict;k:=mem[k].hh.rh;end;end{:784};
{785:}if pdflinklist<>-268435455 then begin k:=pdflinklist;
while k<>-268435455 do begin i:=objtab[mem[k].hh.lh].int4;
pdfbegindict(mem[k].hh.lh,1);begin pdfprint(1162);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if mem[mem[i+5].hh.rh].hh.b0<>3 then begin pdfprint(1163);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if mem[i+5].hh.lh<>-268435455 then pdfprinttoksln(mem[i+5].hh.lh);
pdfrectangle(mem[i+1].int,mem[i+2].int,mem[i+3].int,mem[i+4].int);
if mem[mem[i+5].hh.rh].hh.b0<>3 then pdfprint(1164);
writeaction(mem[i+5].hh.rh);pdfenddict;k:=mem[k].hh.rh;end;
{786:}k:=pdflinklist;
while k<>-268435455 do begin i:=objtab[mem[k].hh.lh].int4;
if mem[i].hh.lh=268435455 then flushwhatsitnode(i,14);k:=mem[k].hh.rh;
end{:786};end{:785};
{787:}if pdfdestlist<>-268435455 then begin k:=pdfdestlist;
while k<>-268435455 do begin if(objtab[mem[k].hh.lh].int2>-1)then
pdferror(1158,1165)else begin i:=objtab[mem[k].hh.lh].int4;
if mem[i+5].hh.b1>0 then begin pdfbegindict(mem[k].hh.lh,1);
pdfprint(1166);end else pdfbeginobj(mem[k].hh.lh,1);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=91;incr(pdfptr);end;end;pdfprintint(pdflastpage);
pdfprint(1141);case mem[i+5].hh.b0 of 0:begin pdfprint(1167);
pdfprintmagbp(((mem[i+1].int)-pdforiginh));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintmagbp((pdforiginv-(mem[i+2].int)));
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
if mem[i+6].hh.lh=-268435455 then pdfprint(1168)else begin pdfprintint(
mem[i+6].hh.lh div 1000);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=46;incr(pdfptr);end;end;
pdfprintint((mem[i+6].hh.lh mod 1000));end;end;1:pdfprint(1169);
2:begin pdfprint(1170);pdfprintmagbp((pdforiginv-(mem[i+2].int)));end;
3:begin pdfprint(1171);pdfprintmagbp(((mem[i+1].int)-pdforiginh));end;
4:pdfprint(1172);5:begin pdfprint(1173);
pdfprintmagbp((pdforiginv-(mem[i+2].int)));end;6:begin pdfprint(1174);
pdfprintmagbp(((mem[i+1].int)-pdforiginh));end;7:begin pdfprint(1175);
pdfprintrectspec(i);end;others:pdferror(1158,1176);end;
begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if mem[i+5].hh.b1>0 then pdfenddict else pdfendobj;end;k:=mem[k].hh.rh;
end;end{:787};
{789:}if pdfbeadlist<>-268435455 then begin k:=pdfbeadlist;
while k<>-268435455 do begin pdfnewobj(0,0,1);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=91;incr(pdfptr);end;end;
i:=pdfmem[objtab[mem[k].hh.lh].int4];pdfprintrectspec(i);
if mem[i].hh.lh=268435455 then flushwhatsitnode(i,19);
begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfmem[objtab[mem[k].hh.lh].int4]:=objptr;pdfendobj;k:=mem[k].hh.rh;end;
end{:789}{:783};end;{766:}pdfbegindict(pdflastresources,1);
{767:}if shippingpage then begin if eqtb[25070].hh.rh<>-268435455 then
pdfprinttoksln(eqtb[25070].hh.rh);
end else begin if pdfmem[objtab[pdfcurform].int4+5]<>-268435455 then
begin pdfprinttoksln(pdfmem[objtab[pdfcurform].int4+5]);
begin deletetokenref(pdfmem[objtab[pdfcurform].int4+5]);
pdfmem[objtab[pdfcurform].int4+5]:=-268435455;end;end;end{:767};
{770:}if pdffontlist<>-268435455 then begin pdfprint(1140);
k:=pdffontlist;while k<>-268435455 do begin pdfprint(1038);
begin if pdffontnum[mem[k].hh.lh]<0 then ff:=-pdffontnum[mem[k].hh.lh]
else ff:=mem[k].hh.lh;end;pdfprintint(ff);
if pdfresnameprefix<>0 then pdfprint(pdfresnameprefix);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintint(pdffontnum[ff]);pdfprint(1141);k:=mem[k].hh.rh;end;
begin pdfprint(1018);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdftextprocset:=true;
end{:770};
{771:}if(pdfxformlist<>-268435455)or(pdfximagelist<>-268435455)then
begin pdfprint(1142);k:=pdfxformlist;
while k<>-268435455 do begin pdfprint(1143);
pdfprintint(objtab[mem[k].hh.lh].int0);
if pdfresnameprefix<>0 then pdfprint(pdfresnameprefix);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;pdfprintint(mem[k].hh.lh);
pdfprint(1141);k:=mem[k].hh.rh;end;k:=pdfximagelist;
while k<>-268435455 do begin pdfprint(1144);
pdfprintint(objtab[mem[k].hh.lh].int0);
if pdfresnameprefix<>0 then pdfprint(pdfresnameprefix);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;pdfprintint(mem[k].hh.lh);
pdfprint(1141);updateimageprocset(pdfmem[objtab[mem[k].hh.lh].int4+4]);
k:=mem[k].hh.rh;end;begin pdfprint(1018);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end{:771};
{772:}pdfprint(1145);if pdftextprocset then pdfprint(1146);
if checkimageb(pdfimageprocset)then pdfprint(1147);
if checkimagec(pdfimageprocset)then pdfprint(1148);
if checkimagei(pdfimageprocset)then pdfprint(1149);begin pdfprint(1150);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end{:772};
pdfenddict{:766};{768:}flushlist(pdffontlist);flushlist(pdfobjlist);
flushlist(pdfxformlist);flushlist(pdfximagelist){:768};
if shippingpage then begin{769:}flushlist(pdfannotlist);
flushlist(pdflinklist);flushlist(pdfdestlist);
flushlist(pdfbeadlist){:769};end{:763};30:{:755};
if(eTeXmode=1)then{1728:}begin if LRproblems>0 then begin{1711:}begin
println;printnl(2016);printint(LRproblems div 10000);print(2017);
printint(LRproblems mod 10000);print(2018);LRproblems:=0;end{:1711};
printchar(41);println;end;
if(LRptr<>-268435455)or(curdir<>0)then confusion(2020);end{:1728};
if(eqtb[27211].int<=0)and shippingpage then printchar(93);deadcycles:=0;
fflush(stdout);
{670:}ifdef('STAT')if eqtb[27208].int>1 then begin printnl(989);
printint(varused);printchar(38);printint(dynused);printchar(59);end;
endif('STAT')flushnodelist(p);
ifdef('STAT')if eqtb[27208].int>1 then begin print(990);
printint(varused);printchar(38);printint(dynused);print(991);
printint(himemmin-lomemmax-1);println;end;endif('STAT'){:670};end;
{1917:}synctexteehs;{:1917};end;
{:754}{794:}procedure shipout(p:halfword);begin fixpdfoutput;
if eqtb[27239].int>0 then pdfshipout(p,true)else dvishipout(p);end;
{:794}{796:}function strlessstr(s1,s2:strnumber):boolean;
var j1,j2,e1,e2:poolpointer;c1,c2:packedASCIIcode;
begin j1:=strstart[s1];j2:=strstart[s2];
e1:=j1+(strstart[s1+1]-strstart[s1]);
e2:=j2+(strstart[s2+1]-strstart[s2]);
while(j1<e1)and(j2<e2)do begin c1:=strpool[j1];incr(j1);
if(c1=92)and(j1<e1)then begin c1:=strpool[j1];incr(j1);
if(c1>=48)and(c1<=55)then begin c1:=c1-48;
if(j1<e1)and(strpool[j1]>=48)and(strpool[j1]<=55)then begin c1:=8*c1+
strpool[j1]-48;incr(j1);
if(j1<e1)and(strpool[j1]>=48)and(strpool[j1]<=55)and(c1<32)then begin c1
:=8*c1+strpool[j1]-48;incr(j1);end;end;
end else begin case c1 of 98:c1:=8;102:c1:=12;110:c1:=10;114:c1:=13;
116:c1:=9;others:end;end;end;c2:=strpool[j2];incr(j2);
if(c2=92)and(j2<e2)then begin c2:=strpool[j2];incr(j2);
if(c2>=48)and(c2<=55)then begin c2:=c2-48;
if(j2<e2)and(strpool[j2]>=48)and(strpool[j2]<=55)then begin c2:=8*c2+
strpool[j2]-48;incr(j2);
if(j2<e2)and(strpool[j2]>=48)and(strpool[j2]<=55)and(c2<32)then begin c2
:=8*c2+strpool[j2]-48;incr(j2);end;end;
end else begin case c2 of 98:c2:=8;102:c2:=12;110:c2:=10;114:c2:=13;
116:c2:=9;others:end;end;end;if c1<c2 then begin strlessstr:=true;
goto 10;end else if c1>c2 then begin strlessstr:=false;goto 10;end;end;
if(j1>=e1)and(j2<e2)then strlessstr:=true else strlessstr:=false;10:end;
procedure sortdestnames(l,r:integer);var i,j:integer;s:strnumber;
e:destnameentry;begin i:=l;j:=r;s:=destnames[(l+r)div 2].objname;
repeat while strlessstr(destnames[i].objname,s)do incr(i);
while strlessstr(s,destnames[j].objname)do decr(j);
if i<=j then begin e:=destnames[i];destnames[i]:=destnames[j];
destnames[j]:=e;incr(i);decr(j);end;until i>j;
if l<j then sortdestnames(l,j);if i<r then sortdestnames(i,r);end;
{:796}{798:}procedure pdffixdest(k:integer);
begin if objtab[k].int4<>-268435455 then goto 10;
pdfwarning(1185,345,false,false);
if objtab[k].int0<0 then begin print(1186);print(-objtab[k].int0);
print(125);end else begin print(1187);printint(objtab[k].int0);end;
print(1188);println;println;pdfbeginobj(k,1);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=91;incr(pdfptr);end;end;pdfprintint(headtab[1]);
begin pdfprint(1189);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfendobj;end;
{:798}{808:}function substrofstr(s,t:strnumber):boolean;label 22,10;
var j,k,kk:poolpointer;begin k:=strstart[t];
while(k<strstart[t+1]-(strstart[s+1]-strstart[s]))do begin j:=strstart[s
];kk:=k;
while(j<strstart[s+1])do begin if strpool[j]<>strpool[kk]then goto 22;
incr(j);incr(kk);end;substrofstr:=true;goto 10;22:incr(k);end;
substrofstr:=false;end;procedure pdfprintinfo;var s:strnumber;
creatorgiven,producergiven,creationdategiven,moddategiven,trappedgiven:
boolean;begin pdfnewdict(0,0,3);creatorgiven:=false;
producergiven:=false;creationdategiven:=false;moddategiven:=false;
trappedgiven:=false;
if pdfinfotoks<>-268435455 then begin s:=tokenstostring(pdfinfotoks);
creatorgiven:=substrofstr(1207,s);producergiven:=substrofstr(1208,s);
creationdategiven:=substrofstr(1209,s);
moddategiven:=substrofstr(1210,s);trappedgiven:=substrofstr(1211,s);end;
if not producergiven then begin{809:}pdfprint(1216);
pdfprintint(140 div 100);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=46;incr(pdfptr);end;end;pdfprintint(140 mod 100);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=46;incr(pdfptr);end;end;pdfprint(257);
begin pdfprint(41);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end{:809};end;
if pdfinfotoks<>-268435455 then begin if(strstart[s+1]-strstart[s])>0
then begin begin pdfprint(s);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;flushstr(s);
begin deletetokenref(pdfinfotoks);pdfinfotoks:=-268435455;end;end;
if not creatorgiven then pdfstrentryln(1212,1213);
if eqtb[27269].int=0 then begin if not creationdategiven then begin
{810:}printcreationdate;{:810};end;
if not moddategiven then begin{811:}printmoddate;{:811};end;end;
if not trappedgiven then begin begin pdfprint(1214);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
pdfstrentryln(1215,pdftexbanner);pdfenddict;end;
{:808}{818:}procedure scanspec(c:groupcode;threecodes:boolean);label 40;
var s:integer;speccode:0..1;
begin if threecodes then s:=savestack[saveptr+0].int;
if scankeyword(1234)then speccode:=0 else if scankeyword(1235)then
speccode:=1 else begin speccode:=1;curval:=0;goto 40;end;
scandimen(false,false,false);
40:if threecodes then begin savestack[saveptr+0].int:=s;incr(saveptr);
end;savestack[saveptr+0].int:=speccode;savestack[saveptr+1].int:=curval;
saveptr:=saveptr+2;newsavelevel(c);scanleftbrace;end;
{:818}{824:}function checkexpandpars(f:internalfontnumber):boolean;
var k:internalfontnumber;begin checkexpandpars:=false;
if(pdffontstep[f]=0)or((pdffontstretch[f]=0)and(pdffontshrink[f]=0))then
goto 10;
if curfontstep<0 then curfontstep:=pdffontstep[f]else if curfontstep<>
pdffontstep[f]then pdferror(1036,1236);k:=pdffontstretch[f];
if k<>0 then begin if maxstretchratio<0 then maxstretchratio:=
pdffontexpandratio[k]else if maxstretchratio<>pdffontexpandratio[k]then
pdferror(1036,1237);end;k:=pdffontshrink[f];
if k<>0 then begin if maxshrinkratio<0 then maxshrinkratio:=-
pdffontexpandratio[k]else if maxshrinkratio<>-pdffontexpandratio[k]then
pdferror(1036,1237);end;checkexpandpars:=true;end;
function charstretch(f:internalfontnumber;c:eightbits):scaled;
var k:internalfontnumber;dw:scaled;ef:integer;begin charstretch:=0;
k:=pdffontstretch[f];ef:=getefcode(f,c);
if(k<>0)and(ef>0)then begin dw:=fontinfo[widthbase[k]+fontinfo[charbase[
k]+effectivechar(true,k,c)].qqqq.b0].int-fontinfo[widthbase[f]+fontinfo[
charbase[f]+effectivechar(true,f,c)].qqqq.b0].int;
if dw>0 then charstretch:=roundxnoverd(dw,ef,1000);end;end;
function charshrink(f:internalfontnumber;c:eightbits):scaled;
var k:internalfontnumber;dw:scaled;ef:integer;begin charshrink:=0;
k:=pdffontshrink[f];ef:=getefcode(f,c);
if(k<>0)and(ef>0)then begin dw:=fontinfo[widthbase[f]+fontinfo[charbase[
f]+effectivechar(true,f,c)].qqqq.b0].int-fontinfo[widthbase[k]+fontinfo[
charbase[k]+effectivechar(true,k,c)].qqqq.b0].int;
if dw>0 then charshrink:=roundxnoverd(dw,ef,1000);end;end;
function getkern(f:internalfontnumber;lc,rc:eightbits):scaled;label 22;
var i:fourquarters;j:fourquarters;k:fontindex;begin getkern:=0;
i:=fontinfo[charbase[f]+effectivechar(true,f,lc)].qqqq;
if((i.b2)mod 4)<>1 then goto 10;k:=ligkernbase[f]+i.b3;
j:=fontinfo[k].qqqq;if j.b0<=128 then goto 23;
k:=ligkernbase[f]+256*j.b2+j.b3+32768-256*(128);22:j:=fontinfo[k].qqqq;
23:if(j.b1=rc)and(j.b0<=128)and(j.b2>=128)then begin getkern:=fontinfo[
kernbase[f]+256*j.b2+j.b3].int;goto 10;end;
if j.b0=0 then incr(k)else begin if j.b0>=128 then goto 10;k:=k+j.b0+1;
end;goto 22;end;function kernstretch(p:halfword):scaled;
var l,r:halfword;d:scaled;begin kernstretch:=0;
if(prevcharp=-268435455)or(mem[prevcharp].hh.rh<>p)or(mem[p].hh.rh=
-268435455)then goto 10;l:=prevcharp;r:=mem[p].hh.rh;
if not(l>=himemmin)then if mem[l].hh.b0=6 then l:=l+1 else goto 10;
if not(r>=himemmin)then if mem[r].hh.b0=6 then r:=r+1 else goto 10;
if not((mem[l].hh.b0=mem[r].hh.b0)and(pdffontstretch[mem[l].hh.b0]<>0))
then goto 10;
d:=getkern(pdffontstretch[mem[l].hh.b0],mem[l].hh.b1,mem[r].hh.b1);
kernstretch:=roundxnoverd(d-mem[p+1].int,getefcode(mem[l].hh.b0,mem[l].
hh.b1),1000);end;function kernshrink(p:halfword):scaled;
var l,r:halfword;d:scaled;begin kernshrink:=0;
if(prevcharp=-268435455)or(mem[prevcharp].hh.rh<>p)or(mem[p].hh.rh=
-268435455)then goto 10;l:=prevcharp;r:=mem[p].hh.rh;
if not(l>=himemmin)then if mem[l].hh.b0=6 then l:=l+1 else goto 10;
if not(r>=himemmin)then if mem[r].hh.b0=6 then r:=r+1 else goto 10;
if not((mem[l].hh.b0=mem[r].hh.b0)and(pdffontshrink[mem[l].hh.b0]<>0))
then goto 10;
d:=getkern(pdffontshrink[mem[l].hh.b0],mem[l].hh.b1,mem[r].hh.b1);
kernshrink:=roundxnoverd(mem[p+1].int-d,getefcode(mem[l].hh.b0,mem[l].hh
.b1),1000);end;procedure dosubstfont(p:halfword;exratio:integer);
var f,k:internalfontnumber;r:halfword;ef:integer;
begin if not(p>=himemmin)and(mem[p].hh.b0=7)then begin r:=mem[p+1].hh.lh
;while r<>-268435455 do begin if(r>=himemmin)or(mem[r].hh.b0=6)then
dosubstfont(r,exratio);r:=mem[r].hh.rh;end;r:=mem[p+1].hh.rh;
while r<>-268435455 do begin if(r>=himemmin)or(mem[r].hh.b0=6)then
dosubstfont(r,exratio);r:=mem[r].hh.rh;end;goto 10;end;
if(p>=himemmin)then r:=p else if mem[p].hh.b0=6 then r:=p+1 else begin
pdferror(1036,1238);end;f:=mem[r].hh.b0;ef:=getefcode(f,mem[r].hh.b1);
if ef=0 then goto 10;
if(pdffontstretch[f]<>0)and(exratio>0)then k:=expandfont(f,extxnoverd(
exratio*ef,pdffontexpandratio[pdffontstretch[f]],1000000))else if(
pdffontshrink[f]<>0)and(exratio<0)then k:=expandfont(f,extxnoverd(
exratio*ef,-pdffontexpandratio[pdffontshrink[f]],1000000))else k:=f;
if k<>f then begin mem[r].hh.b0:=k;
if not(p>=himemmin)then begin r:=mem[p+1].hh.rh;
while r<>-268435455 do begin mem[r].hh.b0:=k;r:=mem[r].hh.rh;end;end;
end;end;function charpw(p:halfword;side:smallnumber):scaled;
var f:internalfontnumber;c:integer;begin charpw:=0;
if side=0 then lastleftmostchar:=-268435455 else lastrightmostchar:=
-268435455;if p=-268435455 then goto 10;
if not(p>=himemmin)then begin if mem[p].hh.b0=6 then p:=p+1 else goto 10
;end;f:=mem[p].hh.b0;if side=0 then begin c:=getlpcode(f,mem[p].hh.b1);
lastleftmostchar:=p;end else begin c:=getrpcode(f,mem[p].hh.b1);
lastrightmostchar:=p;end;if c=0 then goto 10;
charpw:=roundxnoverd(fontinfo[6+parambase[f]].int,c,1000);end;
function newmarginkern(w:scaled;p:halfword;side:smallnumber):halfword;
var k:halfword;begin k:=getnode(3);mem[k].hh.b0:=40;mem[k].hh.b1:=side;
mem[k+1].int:=w;if p=-268435455 then pdferror(1239,1240);
begin mem[k+2].hh.lh:=avail;
if mem[k+2].hh.lh=-268435455 then mem[k+2].hh.lh:=getavail else begin
avail:=mem[mem[k+2].hh.lh].hh.rh;mem[mem[k+2].hh.lh].hh.rh:=-268435455;
ifdef('STAT')incr(dynused);endif('STAT')end;end;
mem[mem[k+2].hh.lh].hh.b1:=mem[p].hh.b1;
mem[mem[k+2].hh.lh].hh.b0:=mem[p].hh.b0;newmarginkern:=k;end;
function hpack(p:halfword;w:scaled;m:smallnumber):halfword;
label 21,50,10;var r:halfword;q:halfword;h,d,x:scaled;s:scaled;
g:halfword;o:glueord;f:internalfontnumber;i:fourquarters;hd:eightbits;
fontstretch:scaled;fontshrink:scaled;k:scaled;begin lastbadness:=0;
r:=getnode(9);mem[r].hh.b0:=0;mem[r].hh.b1:=0;mem[r+4].int:=0;q:=r+5;
mem[q].hh.rh:=p;if m=2 then begin prevcharp:=-268435455;fontstretch:=0;
fontshrink:=0;fontexpandratio:=0;end;h:=0;{825:}d:=0;x:=0;
totalstretch[0]:=0;totalshrink[0]:=0;totalstretch[1]:=0;
totalshrink[1]:=0;totalstretch[2]:=0;totalshrink[2]:=0;
totalstretch[3]:=0;totalshrink[3]:=0{:825};
if(eqtb[27279].int>0)then{1708:}begin tempptr:=getavail;
mem[tempptr].hh.lh:=0;mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;
end{:1708};
while p<>-268435455 do{826:}begin 21:while(p>=himemmin)do{829:}begin if
m>=2 then begin prevcharp:=p;case m of 2:begin f:=mem[p].hh.b0;
fontstretch:=fontstretch+charstretch(f,mem[p].hh.b1);
fontshrink:=fontshrink+charshrink(f,mem[p].hh.b1);end;
3:dosubstfont(p,fontexpandratio);end;end;f:=mem[p].hh.b0;
i:=fontinfo[charbase[f]+effectivechar(true,f,mem[p].hh.b1)].qqqq;
hd:=i.b1;x:=x+fontinfo[widthbase[f]+i.b0].int;
s:=fontinfo[heightbase[f]+(hd)div 16].int;if s>h then h:=s;
s:=fontinfo[depthbase[f]+(hd)mod 16].int;if s>d then d:=s;
p:=mem[p].hh.rh;end{:829};
if p<>-268435455 then begin case mem[p].hh.b0 of 0,1,2,13:{828:}begin x
:=x+mem[p+1].int;if mem[p].hh.b0>=2 then s:=0 else s:=mem[p+4].int;
if mem[p+3].int-s>h then h:=mem[p+3].int-s;
if mem[p+2].int+s>d then d:=mem[p+2].int+s;end{:828};
3,4,5:if(adjusttail<>-268435455)or(preadjusttail<>-268435455)then{832:}
begin while mem[q].hh.rh<>p do q:=mem[q].hh.rh;
if mem[p].hh.b0=5 then begin if mem[p].hh.b1<>0 then begin if
preadjusttail=-268435455 then confusion(1241);
mem[preadjusttail].hh.rh:=mem[p+1].int;
while mem[preadjusttail].hh.rh<>-268435455 do preadjusttail:=mem[
preadjusttail].hh.rh;
end else begin if adjusttail=-268435455 then confusion(1241);
mem[adjusttail].hh.rh:=mem[p+1].int;
while mem[adjusttail].hh.rh<>-268435455 do adjusttail:=mem[adjusttail].
hh.rh;end;p:=mem[p].hh.rh;freenode(mem[q].hh.rh,2);
end else begin mem[adjusttail].hh.rh:=p;adjusttail:=p;p:=mem[p].hh.rh;
end;mem[q].hh.rh:=p;p:=q;end{:832};
8:{1605:}if(mem[p].hh.b1=10)or(mem[p].hh.b1=12)then begin x:=x+mem[p+1].
int;s:=0;if mem[p+2].int-s>h then h:=mem[p+2].int-s;
if mem[p+3].int+s>d then d:=mem[p+3].int+s;end{:1605};
10:{833:}begin g:=mem[p+1].hh.lh;x:=x+mem[g+1].int;o:=mem[g].hh.b0;
totalstretch[o]:=totalstretch[o]+mem[g+2].int;o:=mem[g].hh.b1;
totalshrink[o]:=totalshrink[o]+mem[g+3].int;
if mem[p].hh.b1>=100 then begin g:=mem[p+1].hh.rh;
if mem[g+3].int>h then h:=mem[g+3].int;
if mem[g+2].int>d then d:=mem[g+2].int;end;end{:833};
40:begin if m=2 then begin f:=mem[mem[p+2].hh.lh].hh.b0;
dosubstfont(mem[p+2].hh.lh,1000);
if f<>mem[mem[p+2].hh.lh].hh.b0 then fontstretch:=fontstretch-mem[p+1].
int-charpw(mem[p+2].hh.lh,mem[p].hh.b1);mem[mem[p+2].hh.lh].hh.b0:=f;
dosubstfont(mem[p+2].hh.lh,-1000);
if f<>mem[mem[p+2].hh.lh].hh.b0 then fontshrink:=fontshrink-mem[p+1].int
-charpw(mem[p+2].hh.lh,mem[p].hh.b1);mem[mem[p+2].hh.lh].hh.b0:=f;
end else if m=3 then begin dosubstfont(mem[p+2].hh.lh,fontexpandratio);
mem[p+1].int:=-charpw(mem[p+2].hh.lh,mem[p].hh.b1);end;
x:=x+mem[p+1].int;end;
11:begin if mem[p].hh.b1=0 then begin if m=2 then begin fontstretch:=
fontstretch+kernstretch(p);fontshrink:=fontshrink+kernshrink(p);
end else if m=3 then begin if fontexpandratio>0 then k:=kernstretch(p)
else if fontexpandratio<0 then k:=kernshrink(p)else pdfassert(0);
if k<>0 then begin if(mem[p].hh.rh>=himemmin)then mem[p+1].int:=getkern(
mem[prevcharp].hh.b0,mem[prevcharp].hh.b1,mem[mem[p].hh.rh].hh.b1)else
if mem[mem[p].hh.rh].hh.b0=6 then mem[p+1].int:=getkern(mem[prevcharp].
hh.b0,mem[prevcharp].hh.b1,mem[mem[p].hh.rh+1].hh.b1);end;end;end;
x:=x+mem[p+1].int;end;9:begin x:=x+mem[p+1].int;
if(eqtb[27279].int>0)then{1709:}if odd(mem[p].hh.b1)then if mem[LRptr].
hh.lh=(4*(mem[p].hh.b1 div 4)+3)then begin tempptr:=LRptr;
LRptr:=mem[tempptr].hh.rh;begin mem[tempptr].hh.rh:=avail;
avail:=tempptr;ifdef('STAT')decr(dynused);endif('STAT')end;
end else begin incr(LRproblems);mem[p].hh.b0:=11;mem[p].hh.b1:=1;
end else begin tempptr:=getavail;
mem[tempptr].hh.lh:=(4*(mem[p].hh.b1 div 4)+3);
mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;end{:1709};end;
6:begin if m=3 then dosubstfont(p,fontexpandratio);
{827:}begin mem[memtop-12]:=mem[p+1];mem[memtop-12].hh.rh:=mem[p].hh.rh;
p:=memtop-12;goto 21;end{:827};end;
7:if m=3 then dosubstfont(p,fontexpandratio);others:end;p:=mem[p].hh.rh;
end;end{:826};
if adjusttail<>-268435455 then mem[adjusttail].hh.rh:=-268435455;
if preadjusttail<>-268435455 then mem[preadjusttail].hh.rh:=-268435455;
mem[r+3].int:=h;mem[r+2].int:=d;{834:}if m=1 then w:=x+w;
mem[r+1].int:=w;x:=w-x;if x=0 then begin mem[r+5].hh.b0:=0;
mem[r+5].hh.b1:=0;mem[r+6].gr:=0.0;goto 10;
end else if x>0 then{835:}begin{836:}if totalstretch[3]<>0 then o:=3
else if totalstretch[2]<>0 then o:=2 else if totalstretch[1]<>0 then o:=
1 else o:=0{:836};
if(m=2)and(o=0)and(fontstretch>0)then begin fontexpandratio:=
dividescaled(x,fontstretch,3);goto 10;end;mem[r+5].hh.b1:=o;
mem[r+5].hh.b0:=1;
if totalstretch[o]<>0 then mem[r+6].gr:=x/totalstretch[o]else begin mem[
r+5].hh.b0:=0;mem[r+6].gr:=0.0;end;
if o=0 then if mem[r+5].hh.rh<>-268435455 then{837:}begin lastbadness:=
badness(x,totalstretch[0]);
if lastbadness>eqtb[27203].int then begin println;
if lastbadness>100 then printnl(1242)else printnl(1243);print(1244);
printint(lastbadness);goto 50;end;end{:837};goto 10;
end{:835}else{841:}begin{842:}if totalshrink[3]<>0 then o:=3 else if
totalshrink[2]<>0 then o:=2 else if totalshrink[1]<>0 then o:=1 else o:=
0{:842};
if(m=2)and(o=0)and(fontshrink>0)then begin fontexpandratio:=dividescaled
(x,fontshrink,3);goto 10;end;mem[r+5].hh.b1:=o;mem[r+5].hh.b0:=2;
if totalshrink[o]<>0 then mem[r+6].gr:=(-x)/totalshrink[o]else begin mem
[r+5].hh.b0:=0;mem[r+6].gr:=0.0;end;
if(totalshrink[o]<-x)and(o=0)and(mem[r+5].hh.rh<>-268435455)then begin
lastbadness:=1000000;mem[r+6].gr:=1.0;
{843:}if(-x-totalshrink[0]>eqtb[27801].int)or(eqtb[27203].int<100)then
begin if(eqtb[27809].int>0)and(-x-totalshrink[0]>eqtb[27801].int)then
begin while mem[q].hh.rh<>-268435455 do q:=mem[q].hh.rh;
mem[q].hh.rh:=newrule;mem[mem[q].hh.rh+1].int:=eqtb[27809].int;end;
println;printnl(1250);printscaled(-x-totalshrink[0]);print(1251);
goto 50;end{:843};
end else if o=0 then if mem[r+5].hh.rh<>-268435455 then{844:}begin
lastbadness:=badness(-x,totalshrink[0]);
if lastbadness>eqtb[27203].int then begin println;printnl(1252);
printint(lastbadness);goto 50;end;end{:844};goto 10;end{:841}{:834};
50:{840:}if outputactive then print(1245)else begin if packbeginline<>0
then begin if packbeginline>0 then print(1246)else print(1247);
printint(abs(packbeginline));print(1248);end else print(1249);
printint(line);end;println;fontinshortdisplay:=0;
shortdisplay(mem[r+5].hh.rh);println;begindiagnostic;showbox(r);
enddiagnostic(true){:840};
10:if(eqtb[27279].int>0)then{1710:}begin if mem[LRptr].hh.lh<>0 then
begin while mem[q].hh.rh<>-268435455 do q:=mem[q].hh.rh;
repeat tempptr:=q;q:=newmath(0,mem[LRptr].hh.lh);mem[tempptr].hh.rh:=q;
LRproblems:=LRproblems+10000;begin tempptr:=LRptr;
LRptr:=mem[tempptr].hh.rh;begin mem[tempptr].hh.rh:=avail;
avail:=tempptr;ifdef('STAT')decr(dynused);endif('STAT')end;end;
until mem[LRptr].hh.lh=0;end;
if LRproblems>0 then begin{1711:}begin println;printnl(2016);
printint(LRproblems div 10000);print(2017);
printint(LRproblems mod 10000);print(2018);LRproblems:=0;end{:1711};
goto 50;end;begin tempptr:=LRptr;LRptr:=mem[tempptr].hh.rh;
begin mem[tempptr].hh.rh:=avail;avail:=tempptr;
ifdef('STAT')decr(dynused);endif('STAT')end;end;
if LRptr<>-268435455 then confusion(2015);end{:1710};
if(m=2)and(fontexpandratio<>0)then begin fontexpandratio:=fixint(
fontexpandratio,-1000,1000);q:=mem[r+5].hh.rh;freenode(r,9);
r:=hpack(q,w,3);end;hpack:=r;end;
{:824}{845:}function vpackage(p:halfword;h:scaled;m:smallnumber;
l:scaled):halfword;label 50,10;var r:halfword;w,d,x:scaled;s:scaled;
g:halfword;o:glueord;begin lastbadness:=0;r:=getnode(9);mem[r].hh.b0:=1;
mem[r].hh.b1:=0;mem[r+4].int:=0;mem[r+5].hh.rh:=p;w:=0;{825:}d:=0;x:=0;
totalstretch[0]:=0;totalshrink[0]:=0;totalstretch[1]:=0;
totalshrink[1]:=0;totalstretch[2]:=0;totalshrink[2]:=0;
totalstretch[3]:=0;totalshrink[3]:=0{:825};
while p<>-268435455 do{846:}begin if(p>=himemmin)then confusion(1253)
else case mem[p].hh.b0 of 0,1,2,13:{847:}begin x:=x+d+mem[p+3].int;
d:=mem[p+2].int;if mem[p].hh.b0>=2 then s:=0 else s:=mem[p+4].int;
if mem[p+1].int+s>w then w:=mem[p+1].int+s;end{:847};
8:{1604:}if(mem[p].hh.b1=10)or(mem[p].hh.b1=12)then begin x:=x+d+mem[p+2
].int;d:=mem[p+3].int;s:=0;if mem[p+1].int+s>w then w:=mem[p+1].int+s;
end{:1604};10:{848:}begin x:=x+d;d:=0;g:=mem[p+1].hh.lh;
x:=x+mem[g+1].int;o:=mem[g].hh.b0;
totalstretch[o]:=totalstretch[o]+mem[g+2].int;o:=mem[g].hh.b1;
totalshrink[o]:=totalshrink[o]+mem[g+3].int;
if mem[p].hh.b1>=100 then begin g:=mem[p+1].hh.rh;
if mem[g+1].int>w then w:=mem[g+1].int;end;end{:848};
11:begin x:=x+d+mem[p+1].int;d:=0;end;others:end;p:=mem[p].hh.rh;
end{:846};mem[r+1].int:=w;if d>l then begin x:=x+d-l;mem[r+2].int:=l;
end else mem[r+2].int:=d;{849:}if m=1 then h:=x+h;mem[r+3].int:=h;
x:=h-x;if x=0 then begin mem[r+5].hh.b0:=0;mem[r+5].hh.b1:=0;
mem[r+6].gr:=0.0;goto 10;
end else if x>0 then{850:}begin{836:}if totalstretch[3]<>0 then o:=3
else if totalstretch[2]<>0 then o:=2 else if totalstretch[1]<>0 then o:=
1 else o:=0{:836};mem[r+5].hh.b1:=o;mem[r+5].hh.b0:=1;
if totalstretch[o]<>0 then mem[r+6].gr:=x/totalstretch[o]else begin mem[
r+5].hh.b0:=0;mem[r+6].gr:=0.0;end;
if o=0 then if mem[r+5].hh.rh<>-268435455 then{851:}begin lastbadness:=
badness(x,totalstretch[0]);
if lastbadness>eqtb[27204].int then begin println;
if lastbadness>100 then printnl(1242)else printnl(1243);print(1254);
printint(lastbadness);goto 50;end;end{:851};goto 10;
end{:850}else{853:}begin{842:}if totalshrink[3]<>0 then o:=3 else if
totalshrink[2]<>0 then o:=2 else if totalshrink[1]<>0 then o:=1 else o:=
0{:842};mem[r+5].hh.b1:=o;mem[r+5].hh.b0:=2;
if totalshrink[o]<>0 then mem[r+6].gr:=(-x)/totalshrink[o]else begin mem
[r+5].hh.b0:=0;mem[r+6].gr:=0.0;end;
if(totalshrink[o]<-x)and(o=0)and(mem[r+5].hh.rh<>-268435455)then begin
lastbadness:=1000000;mem[r+6].gr:=1.0;
{854:}if(-x-totalshrink[0]>eqtb[27802].int)or(eqtb[27204].int<100)then
begin println;printnl(1255);printscaled(-x-totalshrink[0]);print(1256);
goto 50;end{:854};
end else if o=0 then if mem[r+5].hh.rh<>-268435455 then{855:}begin
lastbadness:=badness(-x,totalshrink[0]);
if lastbadness>eqtb[27204].int then begin println;printnl(1257);
printint(lastbadness);goto 50;end;end{:855};goto 10;end{:853}{:849};
50:{852:}if outputactive then print(1245)else begin if packbeginline<>0
then begin print(1247);printint(abs(packbeginline));print(1248);
end else print(1249);printint(line);println;end;begindiagnostic;
showbox(r);enddiagnostic(true){:852};10:vpackage:=r;end;
{:845}{856:}procedure appendtovlist(b:halfword);var d:scaled;p:halfword;
begin if curlist.auxfield.int>eqtb[27825].int then begin d:=mem[eqtb[
24529].hh.rh+1].int-curlist.auxfield.int-mem[b+3].int;
if d<eqtb[27795].int then p:=newparamglue(0)else begin p:=newskipparam(1
);mem[tempptr+1].int:=d;end;mem[curlist.tailfield].hh.rh:=p;
curlist.tailfield:=p;end;mem[curlist.tailfield].hh.rh:=b;
curlist.tailfield:=b;curlist.auxfield.int:=mem[b+2].int;end;
{:856}{863:}function newnoad:halfword;var p:halfword;
begin p:=getnode(4);mem[p].hh.b0:=16;mem[p].hh.b1:=0;
mem[p+1].hh:=emptyfield;mem[p+3].hh:=emptyfield;mem[p+2].hh:=emptyfield;
newnoad:=p;end;{:863}{865:}function newstyle(s:smallnumber):halfword;
var p:halfword;begin p:=getnode(3);mem[p].hh.b0:=14;mem[p].hh.b1:=s;
mem[p+1].int:=0;mem[p+2].int:=0;newstyle:=p;end;
{:865}{866:}function newchoice:halfword;var p:halfword;
begin p:=getnode(3);mem[p].hh.b0:=15;mem[p].hh.b1:=0;
mem[p+1].hh.lh:=-268435455;mem[p+1].hh.rh:=-268435455;
mem[p+2].hh.lh:=-268435455;mem[p+2].hh.rh:=-268435455;newchoice:=p;end;
{:866}{870:}procedure showinfo;begin shownodelist(mem[tempptr].hh.lh);
end;{:870}{881:}function fractionrule(t:scaled):halfword;var p:halfword;
begin p:=newrule;mem[p+3].int:=t;mem[p+2].int:=0;fractionrule:=p;end;
{:881}{882:}function overbar(b:halfword;k,t:scaled):halfword;
var p,q:halfword;begin p:=newkern(k);mem[p].hh.rh:=b;q:=fractionrule(t);
mem[q].hh.rh:=p;p:=newkern(t);mem[p].hh.rh:=q;
overbar:=vpackage(p,0,1,1073741823);end;
{:882}{883:}{886:}function charbox(f:internalfontnumber;
c:quarterword):halfword;var q:fourquarters;hd:eightbits;b,p:halfword;
begin q:=fontinfo[charbase[f]+effectivechar(true,f,c)].qqqq;hd:=q.b1;
b:=newnullbox;
mem[b+1].int:=fontinfo[widthbase[f]+q.b0].int+fontinfo[italicbase[f]+(q.
b2)div 4].int;mem[b+3].int:=fontinfo[heightbase[f]+(hd)div 16].int;
mem[b+2].int:=fontinfo[depthbase[f]+(hd)mod 16].int;p:=getavail;
mem[p].hh.b1:=c;mem[p].hh.b0:=f;mem[b+5].hh.rh:=p;charbox:=b;end;
{:886}{888:}procedure stackintobox(b:halfword;f:internalfontnumber;
c:quarterword);var p:halfword;begin p:=charbox(f,c);
mem[p].hh.rh:=mem[b+5].hh.rh;mem[b+5].hh.rh:=p;
mem[b+3].int:=mem[p+3].int;end;
{:888}{889:}function heightplusdepth(f:internalfontnumber;
c:quarterword):scaled;var q:fourquarters;hd:eightbits;
begin q:=fontinfo[charbase[f]+effectivechar(true,f,c)].qqqq;hd:=q.b1;
heightplusdepth:=fontinfo[heightbase[f]+(hd)div 16].int+fontinfo[
depthbase[f]+(hd)mod 16].int;end;{:889}function vardelimiter(d:halfword;
s:smallnumber;v:scaled):halfword;label 40,22;var b:halfword;
f,g:internalfontnumber;c,x,y:quarterword;m,n:integer;u:scaled;w:scaled;
q:fourquarters;hd:eightbits;r:fourquarters;z:smallnumber;
largeattempt:boolean;begin f:=0;w:=0;largeattempt:=false;
z:=mem[d].qqqq.b0;x:=mem[d].qqqq.b1;
while true do begin{884:}if(z<>0)or(x<>0)then begin z:=z+s+16;
repeat z:=z-16;g:=eqtb[25593+z].hh.rh;if g<>0 then{885:}begin y:=x;
if(y>=fontbc[g])and(y<=fontec[g])then begin 22:q:=fontinfo[charbase[g]+y
].qqqq;if(q.b0>0)then begin if((q.b2)mod 4)=3 then begin f:=g;c:=y;
goto 40;end;hd:=q.b1;
u:=fontinfo[heightbase[g]+(hd)div 16].int+fontinfo[depthbase[g]+(hd)mod
16].int;if u>w then begin f:=g;c:=y;w:=u;if u>=v then goto 40;end;
if((q.b2)mod 4)=2 then begin y:=q.b3;goto 22;end;end;end;end{:885};
until z<16;end{:884};if largeattempt then goto 40;largeattempt:=true;
z:=mem[d].qqqq.b2;x:=mem[d].qqqq.b3;end;
40:if f<>0 then{887:}if((q.b2)mod 4)=3 then{890:}begin b:=newnullbox;
mem[b].hh.b0:=1;r:=fontinfo[extenbase[f]+q.b3].qqqq;{891:}c:=r.b3;
u:=heightplusdepth(f,c);w:=0;
q:=fontinfo[charbase[f]+effectivechar(true,f,c)].qqqq;
mem[b+1].int:=fontinfo[widthbase[f]+q.b0].int+fontinfo[italicbase[f]+(q.
b2)div 4].int;c:=r.b2;if c<>0 then w:=w+heightplusdepth(f,c);c:=r.b1;
if c<>0 then w:=w+heightplusdepth(f,c);c:=r.b0;
if c<>0 then w:=w+heightplusdepth(f,c);n:=0;
if u>0 then while w<v do begin w:=w+u;incr(n);if r.b1<>0 then w:=w+u;
end{:891};c:=r.b2;if c<>0 then stackintobox(b,f,c);c:=r.b3;
for m:=1 to n do stackintobox(b,f,c);c:=r.b1;
if c<>0 then begin stackintobox(b,f,c);c:=r.b3;
for m:=1 to n do stackintobox(b,f,c);end;c:=r.b0;
if c<>0 then stackintobox(b,f,c);mem[b+2].int:=w-mem[b+3].int;
end{:890}else b:=charbox(f,c){:887}else begin b:=newnullbox;
mem[b+1].int:=eqtb[27804].int;end;
mem[b+4].int:=half(mem[b+3].int-mem[b+2].int)-fontinfo[22+parambase[eqtb
[25595+s].hh.rh]].int;vardelimiter:=b;end;
{:883}{892:}function rebox(b:halfword;w:scaled):halfword;var p:halfword;
f:internalfontnumber;v:scaled;
begin if(mem[b+1].int<>w)and(mem[b+5].hh.rh<>-268435455)then begin if
mem[b].hh.b0=1 then b:=hpack(b,0,1);p:=mem[b+5].hh.rh;
if((p>=himemmin))and(mem[p].hh.rh=-268435455)then begin f:=mem[p].hh.b0;
v:=fontinfo[widthbase[f]+fontinfo[charbase[f]+effectivechar(true,f,mem[p
].hh.b1)].qqqq.b0].int;
if v<>mem[b+1].int then mem[p].hh.rh:=newkern(mem[b+1].int-v);end;
freenode(b,9);b:=newglue(membot+12);mem[b].hh.rh:=p;
while mem[p].hh.rh<>-268435455 do p:=mem[p].hh.rh;
mem[p].hh.rh:=newglue(membot+12);rebox:=hpack(b,w,0);
end else begin mem[b+1].int:=w;rebox:=b;end;end;
{:892}{893:}function mathglue(g:halfword;m:scaled):halfword;
var p:halfword;n:integer;f:scaled;begin n:=xovern(m,65536);
f:=texremainder;if f<0 then begin decr(n);f:=f+65536;end;p:=getnode(4);
mem[p+1].int:=multandadd(n,mem[g+1].int,xnoverd(mem[g+1].int,f,65536),
1073741823);mem[p].hh.b0:=mem[g].hh.b0;
if mem[p].hh.b0=0 then mem[p+2].int:=multandadd(n,mem[g+2].int,xnoverd(
mem[g+2].int,f,65536),1073741823)else mem[p+2].int:=mem[g+2].int;
mem[p].hh.b1:=mem[g].hh.b1;
if mem[p].hh.b1=0 then mem[p+3].int:=multandadd(n,mem[g+3].int,xnoverd(
mem[g+3].int,f,65536),1073741823)else mem[p+3].int:=mem[g+3].int;
mathglue:=p;end;{:893}{894:}procedure mathkern(p:halfword;m:scaled);
var n:integer;f:scaled;
begin if mem[p].hh.b1=99 then begin n:=xovern(m,65536);f:=texremainder;
if f<0 then begin decr(n);f:=f+65536;end;
mem[p+1].int:=multandadd(n,mem[p+1].int,xnoverd(mem[p+1].int,f,65536),
1073741823);mem[p].hh.b1:=1;end;end;{:894}{895:}procedure flushmath;
begin flushnodelist(mem[curlist.headfield].hh.rh);
flushnodelist(curlist.auxfield.int);
mem[curlist.headfield].hh.rh:=-268435455;
curlist.tailfield:=curlist.headfield;curlist.auxfield.int:=-268435455;
end;{:895}{897:}procedure mlisttohlist;forward;
function cleanbox(p:halfword;s:smallnumber):halfword;label 40;
var q:halfword;savestyle:smallnumber;x:halfword;r:halfword;
begin case mem[p].hh.rh of 1:begin curmlist:=newnoad;
mem[curmlist+1]:=mem[p];end;2:begin q:=mem[p].hh.lh;goto 40;end;
3:curmlist:=mem[p].hh.lh;others:begin q:=newnullbox;goto 40;end end;
savestyle:=curstyle;curstyle:=s;mlistpenalties:=false;mlisttohlist;
q:=mem[memtop-3].hh.rh;curstyle:=savestyle;
{880:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25595+cursize].hh.rh]].int,18);
end{:880};
40:if(q>=himemmin)or(q=-268435455)then x:=hpack(q,0,1)else if(mem[q].hh.
rh=-268435455)and(mem[q].hh.b0<=1)and(mem[q+4].int=0)then x:=q else x:=
hpack(q,0,1);{898:}q:=mem[x+5].hh.rh;
if(q>=himemmin)then begin r:=mem[q].hh.rh;
if r<>-268435455 then if mem[r].hh.rh=-268435455 then if not(r>=himemmin
)then if mem[r].hh.b0=11 then begin freenode(r,4);
mem[q].hh.rh:=-268435455;end;end{:898};cleanbox:=x;end;
{:897}{899:}procedure fetch(a:halfword);begin curc:=mem[a].hh.b1;
curf:=eqtb[25593+mem[a].hh.b0+cursize].hh.rh;
if curf=0 then{900:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(345);
end;printsize(cursize);printchar(32);printint(mem[a].hh.b0);print(1283);
print(curc);printchar(41);begin helpptr:=4;helpline[3]:=1284;
helpline[2]:=1285;helpline[1]:=1286;helpline[0]:=1287;end;error;
curi:=nullcharacter;mem[a].hh.rh:=0;
end{:900}else begin if(curc>=fontbc[curf])and(curc<=fontec[curf])then
curi:=fontinfo[charbase[curf]+curc].qqqq else curi:=nullcharacter;
if not((curi.b0>0))then begin charwarning(curf,curc);mem[a].hh.rh:=0;
end;end;end;{:899}{903:}{911:}procedure makeover(q:halfword);
begin mem[q+1].hh.lh:=overbar(cleanbox(q+1,2*(curstyle div 2)+1),3*
fontinfo[8+parambase[eqtb[25596+cursize].hh.rh]].int,fontinfo[8+
parambase[eqtb[25596+cursize].hh.rh]].int);mem[q+1].hh.rh:=2;end;
{:911}{912:}procedure makeunder(q:halfword);var p,x,y:halfword;
delta:scaled;begin x:=cleanbox(q+1,curstyle);
p:=newkern(3*fontinfo[8+parambase[eqtb[25596+cursize].hh.rh]].int);
mem[x].hh.rh:=p;
mem[p].hh.rh:=fractionrule(fontinfo[8+parambase[eqtb[25596+cursize].hh.
rh]].int);y:=vpackage(x,0,1,1073741823);
delta:=mem[y+3].int+mem[y+2].int+fontinfo[8+parambase[eqtb[25596+cursize
].hh.rh]].int;mem[y+3].int:=mem[x+3].int;
mem[y+2].int:=delta-mem[y+3].int;mem[q+1].hh.lh:=y;mem[q+1].hh.rh:=2;
end;{:912}{913:}procedure makevcenter(q:halfword);var v:halfword;
delta:scaled;begin v:=mem[q+1].hh.lh;
if mem[v].hh.b0<>1 then confusion(617);delta:=mem[v+3].int+mem[v+2].int;
mem[v+3].int:=fontinfo[22+parambase[eqtb[25595+cursize].hh.rh]].int+half
(delta);mem[v+2].int:=delta-mem[v+3].int;end;
{:913}{914:}procedure makeradical(q:halfword);var x,y:halfword;
delta,clr:scaled;begin x:=cleanbox(q+1,2*(curstyle div 2)+1);
if curstyle<2 then clr:=fontinfo[8+parambase[eqtb[25596+cursize].hh.rh]]
.int+(abs(fontinfo[5+parambase[eqtb[25595+cursize].hh.rh]].int)div 4)
else begin clr:=fontinfo[8+parambase[eqtb[25596+cursize].hh.rh]].int;
clr:=clr+(abs(clr)div 4);end;
y:=vardelimiter(q+4,cursize,mem[x+3].int+mem[x+2].int+clr+fontinfo[8+
parambase[eqtb[25596+cursize].hh.rh]].int);
delta:=mem[y+2].int-(mem[x+3].int+mem[x+2].int+clr);
if delta>0 then clr:=clr+half(delta);mem[y+4].int:=-(mem[x+3].int+clr);
mem[y].hh.rh:=overbar(x,clr,mem[y+3].int);mem[q+1].hh.lh:=hpack(y,0,1);
mem[q+1].hh.rh:=2;end;{:914}{915:}procedure makemathaccent(q:halfword);
label 30,31;var p,x,y:halfword;a:integer;c:quarterword;
f:internalfontnumber;i:fourquarters;s:scaled;h:scaled;delta:scaled;
w:scaled;begin fetch(q+4);if(curi.b0>0)then begin i:=curi;c:=curc;
f:=curf;{918:}s:=0;if mem[q+1].hh.rh=1 then begin fetch(q+1);
if((curi.b2)mod 4)=1 then begin a:=ligkernbase[curf]+curi.b3;
curi:=fontinfo[a].qqqq;
if curi.b0>128 then begin a:=ligkernbase[curf]+256*curi.b2+curi.b3
+32768-256*(128);curi:=fontinfo[a].qqqq;end;
while true do begin if curi.b1=skewchar[curf]then begin if curi.b2>=128
then if curi.b0<=128 then s:=fontinfo[kernbase[curf]+256*curi.b2+curi.b3
].int;goto 31;end;if curi.b0>=128 then goto 31;a:=a+curi.b0+1;
curi:=fontinfo[a].qqqq;end;end;end;31:{:918};
x:=cleanbox(q+1,2*(curstyle div 2)+1);w:=mem[x+1].int;h:=mem[x+3].int;
{917:}while true do begin if((i.b2)mod 4)<>2 then goto 30;y:=i.b3;
i:=fontinfo[charbase[f]+y].qqqq;if not(i.b0>0)then goto 30;
if fontinfo[widthbase[f]+i.b0].int>w then goto 30;c:=y;end;30:{:917};
if h<fontinfo[5+parambase[f]].int then delta:=h else delta:=fontinfo[5+
parambase[f]].int;
if(mem[q+2].hh.rh<>0)or(mem[q+3].hh.rh<>0)then if mem[q+1].hh.rh=1 then
{919:}begin flushnodelist(x);x:=newnoad;mem[x+1]:=mem[q+1];
mem[x+2]:=mem[q+2];mem[x+3]:=mem[q+3];mem[q+2].hh:=emptyfield;
mem[q+3].hh:=emptyfield;mem[q+1].hh.rh:=3;mem[q+1].hh.lh:=x;
x:=cleanbox(q+1,curstyle);delta:=delta+mem[x+3].int-h;h:=mem[x+3].int;
end{:919};y:=charbox(f,c);mem[y+4].int:=s+half(w-mem[y+1].int);
mem[y+1].int:=0;p:=newkern(-delta);mem[p].hh.rh:=x;mem[y].hh.rh:=p;
y:=vpackage(y,0,1,1073741823);mem[y+1].int:=mem[x+1].int;
if mem[y+3].int<h then{916:}begin p:=newkern(h-mem[y+3].int);
mem[p].hh.rh:=mem[y+5].hh.rh;mem[y+5].hh.rh:=p;mem[y+3].int:=h;
end{:916};mem[q+1].hh.lh:=y;mem[q+1].hh.rh:=2;end;end;
{:915}{920:}procedure makefraction(q:halfword);var p,v,x,y,z:halfword;
delta,delta1,delta2,shiftup,shiftdown,clr:scaled;
begin if mem[q+1].int=1073741824 then mem[q+1].int:=fontinfo[8+parambase
[eqtb[25596+cursize].hh.rh]].int;
{921:}x:=cleanbox(q+2,curstyle+2-2*(curstyle div 6));
z:=cleanbox(q+3,2*(curstyle div 2)+3-2*(curstyle div 6));
if mem[x+1].int<mem[z+1].int then x:=rebox(x,mem[z+1].int)else z:=rebox(
z,mem[x+1].int);
if curstyle<2 then begin shiftup:=fontinfo[8+parambase[eqtb[25595+
cursize].hh.rh]].int;
shiftdown:=fontinfo[11+parambase[eqtb[25595+cursize].hh.rh]].int;
end else begin shiftdown:=fontinfo[12+parambase[eqtb[25595+cursize].hh.
rh]].int;
if mem[q+1].int<>0 then shiftup:=fontinfo[9+parambase[eqtb[25595+cursize
].hh.rh]].int else shiftup:=fontinfo[10+parambase[eqtb[25595+cursize].hh
.rh]].int;end{:921};
if mem[q+1].int=0 then{922:}begin if curstyle<2 then clr:=7*fontinfo[8+
parambase[eqtb[25596+cursize].hh.rh]].int else clr:=3*fontinfo[8+
parambase[eqtb[25596+cursize].hh.rh]].int;
delta:=half(clr-((shiftup-mem[x+2].int)-(mem[z+3].int-shiftdown)));
if delta>0 then begin shiftup:=shiftup+delta;shiftdown:=shiftdown+delta;
end;
end{:922}else{923:}begin if curstyle<2 then clr:=3*mem[q+1].int else clr
:=mem[q+1].int;delta:=half(mem[q+1].int);
delta1:=clr-((shiftup-mem[x+2].int)-(fontinfo[22+parambase[eqtb[25595+
cursize].hh.rh]].int+delta));
delta2:=clr-((fontinfo[22+parambase[eqtb[25595+cursize].hh.rh]].int-
delta)-(mem[z+3].int-shiftdown));
if delta1>0 then shiftup:=shiftup+delta1;
if delta2>0 then shiftdown:=shiftdown+delta2;end{:923};
{924:}v:=newnullbox;mem[v].hh.b0:=1;mem[v+3].int:=shiftup+mem[x+3].int;
mem[v+2].int:=mem[z+2].int+shiftdown;mem[v+1].int:=mem[x+1].int;
if mem[q+1].int=0 then begin p:=newkern((shiftup-mem[x+2].int)-(mem[z+3]
.int-shiftdown));mem[p].hh.rh:=z;
end else begin y:=fractionrule(mem[q+1].int);
p:=newkern((fontinfo[22+parambase[eqtb[25595+cursize].hh.rh]].int-delta)
-(mem[z+3].int-shiftdown));mem[y].hh.rh:=p;mem[p].hh.rh:=z;
p:=newkern((shiftup-mem[x+2].int)-(fontinfo[22+parambase[eqtb[25595+
cursize].hh.rh]].int+delta));mem[p].hh.rh:=y;end;mem[x].hh.rh:=p;
mem[v+5].hh.rh:=x{:924};
{925:}if curstyle<2 then delta:=fontinfo[20+parambase[eqtb[25595+cursize
].hh.rh]].int else delta:=fontinfo[21+parambase[eqtb[25595+cursize].hh.
rh]].int;x:=vardelimiter(q+4,cursize,delta);mem[x].hh.rh:=v;
z:=vardelimiter(q+5,cursize,delta);mem[v].hh.rh:=z;
mem[q+1].int:=hpack(x,0,1){:925};end;
{:920}{926:}function makeop(q:halfword):scaled;var delta:scaled;
p,v,x,y,z:halfword;c:quarterword;i:fourquarters;
shiftup,shiftdown:scaled;
begin if(mem[q].hh.b1=0)and(curstyle<2)then mem[q].hh.b1:=1;
if mem[q+1].hh.rh=1 then begin fetch(q+1);
if(curstyle<2)and(((curi.b2)mod 4)=2)then begin c:=curi.b3;
i:=fontinfo[charbase[curf]+c].qqqq;if(i.b0>0)then begin curc:=c;curi:=i;
mem[q+1].hh.b1:=c;end;end;
delta:=fontinfo[italicbase[curf]+(curi.b2)div 4].int;
x:=cleanbox(q+1,curstyle);
if(mem[q+3].hh.rh<>0)and(mem[q].hh.b1<>1)then mem[x+1].int:=mem[x+1].int
-delta;
mem[x+4].int:=half(mem[x+3].int-mem[x+2].int)-fontinfo[22+parambase[eqtb
[25595+cursize].hh.rh]].int;mem[q+1].hh.rh:=2;mem[q+1].hh.lh:=x;
end else delta:=0;
if mem[q].hh.b1=1 then{927:}begin x:=cleanbox(q+2,2*(curstyle div 4)+4+(
curstyle mod 2));y:=cleanbox(q+1,curstyle);
z:=cleanbox(q+3,2*(curstyle div 4)+5);v:=newnullbox;mem[v].hh.b0:=1;
mem[v+1].int:=mem[y+1].int;
if mem[x+1].int>mem[v+1].int then mem[v+1].int:=mem[x+1].int;
if mem[z+1].int>mem[v+1].int then mem[v+1].int:=mem[z+1].int;
x:=rebox(x,mem[v+1].int);y:=rebox(y,mem[v+1].int);
z:=rebox(z,mem[v+1].int);mem[x+4].int:=half(delta);
mem[z+4].int:=-mem[x+4].int;mem[v+3].int:=mem[y+3].int;
mem[v+2].int:=mem[y+2].int;
{928:}if mem[q+2].hh.rh=0 then begin freenode(x,9);mem[v+5].hh.rh:=y;
end else begin shiftup:=fontinfo[11+parambase[eqtb[25596+cursize].hh.rh]
].int-mem[x+2].int;
if shiftup<fontinfo[9+parambase[eqtb[25596+cursize].hh.rh]].int then
shiftup:=fontinfo[9+parambase[eqtb[25596+cursize].hh.rh]].int;
p:=newkern(shiftup);mem[p].hh.rh:=y;mem[x].hh.rh:=p;
p:=newkern(fontinfo[13+parambase[eqtb[25596+cursize].hh.rh]].int);
mem[p].hh.rh:=x;mem[v+5].hh.rh:=p;
mem[v+3].int:=mem[v+3].int+fontinfo[13+parambase[eqtb[25596+cursize].hh.
rh]].int+mem[x+3].int+mem[x+2].int+shiftup;end;
if mem[q+3].hh.rh=0 then freenode(z,9)else begin shiftdown:=fontinfo[12+
parambase[eqtb[25596+cursize].hh.rh]].int-mem[z+3].int;
if shiftdown<fontinfo[10+parambase[eqtb[25596+cursize].hh.rh]].int then
shiftdown:=fontinfo[10+parambase[eqtb[25596+cursize].hh.rh]].int;
p:=newkern(shiftdown);mem[y].hh.rh:=p;mem[p].hh.rh:=z;
p:=newkern(fontinfo[13+parambase[eqtb[25596+cursize].hh.rh]].int);
mem[z].hh.rh:=p;
mem[v+2].int:=mem[v+2].int+fontinfo[13+parambase[eqtb[25596+cursize].hh.
rh]].int+mem[z+3].int+mem[z+2].int+shiftdown;end{:928};mem[q+1].int:=v;
end{:927};makeop:=delta;end;{:926}{929:}procedure makeord(q:halfword);
label 20,10;var a:integer;p,r:halfword;
begin 20:if mem[q+3].hh.rh=0 then if mem[q+2].hh.rh=0 then if mem[q+1].
hh.rh=1 then begin p:=mem[q].hh.rh;
if p<>-268435455 then if(mem[p].hh.b0>=16)and(mem[p].hh.b0<=22)then if
mem[p+1].hh.rh=1 then if mem[p+1].hh.b0=mem[q+1].hh.b0 then begin mem[q
+1].hh.rh:=4;fetch(q+1);
if((curi.b2)mod 4)=1 then begin a:=ligkernbase[curf]+curi.b3;
curc:=mem[p+1].hh.b1;curi:=fontinfo[a].qqqq;
if curi.b0>128 then begin a:=ligkernbase[curf]+256*curi.b2+curi.b3
+32768-256*(128);curi:=fontinfo[a].qqqq;end;
while true do begin{930:}if curi.b1=curc then if curi.b0<=128 then if
curi.b2>=128 then begin p:=newkern(fontinfo[kernbase[curf]+256*curi.b2+
curi.b3].int);mem[p].hh.rh:=mem[q].hh.rh;mem[q].hh.rh:=p;goto 10;
end else begin begin if interrupt<>0 then pauseforinstructions;end;
case curi.b2 of 1,5:mem[q+1].hh.b1:=curi.b3;2,6:mem[p+1].hh.b1:=curi.b3;
3,7,11:begin r:=newnoad;mem[r+1].hh.b1:=curi.b3;
mem[r+1].hh.b0:=mem[q+1].hh.b0;mem[q].hh.rh:=r;mem[r].hh.rh:=p;
if curi.b2<11 then mem[r+1].hh.rh:=1 else mem[r+1].hh.rh:=4;end;
others:begin mem[q].hh.rh:=mem[p].hh.rh;mem[q+1].hh.b1:=curi.b3;
mem[q+3]:=mem[p+3];mem[q+2]:=mem[p+2];freenode(p,4);end end;
if curi.b2>3 then goto 10;mem[q+1].hh.rh:=1;goto 20;end{:930};
if curi.b0>=128 then goto 10;a:=a+curi.b0+1;curi:=fontinfo[a].qqqq;end;
end;end;end;10:end;{:929}{933:}procedure makescripts(q:halfword;
delta:scaled);var p,x,y,z:halfword;shiftup,shiftdown,clr:scaled;
t:smallnumber;begin p:=mem[q+1].int;
if(p>=himemmin)then begin shiftup:=0;shiftdown:=0;
end else begin z:=hpack(p,0,1);if curstyle<4 then t:=16 else t:=32;
shiftup:=mem[z+3].int-fontinfo[18+parambase[eqtb[25595+t].hh.rh]].int;
shiftdown:=mem[z+2].int+fontinfo[19+parambase[eqtb[25595+t].hh.rh]].int;
freenode(z,9);end;
if mem[q+2].hh.rh=0 then{934:}begin x:=cleanbox(q+3,2*(curstyle div 4)+5
);mem[x+1].int:=mem[x+1].int+eqtb[27805].int;
if shiftdown<fontinfo[16+parambase[eqtb[25595+cursize].hh.rh]].int then
shiftdown:=fontinfo[16+parambase[eqtb[25595+cursize].hh.rh]].int;
clr:=mem[x+3].int-(abs(fontinfo[5+parambase[eqtb[25595+cursize].hh.rh]].
int*4)div 5);if shiftdown<clr then shiftdown:=clr;
mem[x+4].int:=shiftdown;
end{:934}else begin{935:}begin x:=cleanbox(q+2,2*(curstyle div 4)+4+(
curstyle mod 2));mem[x+1].int:=mem[x+1].int+eqtb[27805].int;
if odd(curstyle)then clr:=fontinfo[15+parambase[eqtb[25595+cursize].hh.
rh]].int else if curstyle<2 then clr:=fontinfo[13+parambase[eqtb[25595+
cursize].hh.rh]].int else clr:=fontinfo[14+parambase[eqtb[25595+cursize]
.hh.rh]].int;if shiftup<clr then shiftup:=clr;
clr:=mem[x+2].int+(abs(fontinfo[5+parambase[eqtb[25595+cursize].hh.rh]].
int)div 4);if shiftup<clr then shiftup:=clr;end{:935};
if mem[q+3].hh.rh=0 then mem[x+4].int:=-shiftup else{936:}begin y:=
cleanbox(q+3,2*(curstyle div 4)+5);
mem[y+1].int:=mem[y+1].int+eqtb[27805].int;
if shiftdown<fontinfo[17+parambase[eqtb[25595+cursize].hh.rh]].int then
shiftdown:=fontinfo[17+parambase[eqtb[25595+cursize].hh.rh]].int;
clr:=4*fontinfo[8+parambase[eqtb[25596+cursize].hh.rh]].int-((shiftup-
mem[x+2].int)-(mem[y+3].int-shiftdown));
if clr>0 then begin shiftdown:=shiftdown+clr;
clr:=(abs(fontinfo[5+parambase[eqtb[25595+cursize].hh.rh]].int*4)div 5)-
(shiftup-mem[x+2].int);if clr>0 then begin shiftup:=shiftup+clr;
shiftdown:=shiftdown-clr;end;end;mem[x+4].int:=delta;
p:=newkern((shiftup-mem[x+2].int)-(mem[y+3].int-shiftdown));
mem[x].hh.rh:=p;mem[p].hh.rh:=y;x:=vpackage(x,0,1,1073741823);
mem[x+4].int:=shiftdown;end{:936};end;
if mem[q+1].int=-268435455 then mem[q+1].int:=x else begin p:=mem[q+1].
int;while mem[p].hh.rh<>-268435455 do p:=mem[p].hh.rh;mem[p].hh.rh:=x;
end;end;{:933}{939:}function makeleftright(q:halfword;style:smallnumber;
maxd,maxh:scaled):smallnumber;var delta,delta1,delta2:scaled;
begin curstyle:=style;
{880:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25595+cursize].hh.rh]].int,18);
end{:880};
delta2:=maxd+fontinfo[22+parambase[eqtb[25595+cursize].hh.rh]].int;
delta1:=maxh+maxd-delta2;if delta2>delta1 then delta1:=delta2;
delta:=(delta1 div 500)*eqtb[27195].int;
delta2:=delta1+delta1-eqtb[27803].int;
if delta<delta2 then delta:=delta2;
mem[q+1].int:=vardelimiter(q+1,cursize,delta);
makeleftright:=mem[q].hh.b0-(10);end;{:939}procedure mlisttohlist;
label 21,82,80,81,83,30;var mlist:halfword;penalties:boolean;
style:smallnumber;savestyle:smallnumber;q:halfword;r:halfword;
rtype:smallnumber;t:smallnumber;p,x,y,z:halfword;pen:integer;
s:smallnumber;maxh,maxd:scaled;delta:scaled;begin mlist:=curmlist;
penalties:=mlistpenalties;style:=curstyle;q:=mlist;r:=-268435455;
rtype:=17;maxh:=0;maxd:=0;
{880:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25595+cursize].hh.rh]].int,18);
end{:880};while q<>-268435455 do{904:}begin{905:}21:delta:=0;
case mem[q].hh.b0 of 18:case rtype of 18,17,19,20,22,30:begin mem[q].hh.
b0:=16;goto 21;end;others:end;
19,21,22,31:begin{906:}if rtype=18 then mem[r].hh.b0:=16{:906};
if mem[q].hh.b0=31 then goto 80;end;{910:}30:goto 80;
25:begin makefraction(q);goto 82;end;17:begin delta:=makeop(q);
if mem[q].hh.b1=1 then goto 82;end;16:makeord(q);20,23:;
24:makeradical(q);27:makeover(q);26:makeunder(q);28:makemathaccent(q);
29:makevcenter(q);{:910}{907:}14:begin curstyle:=mem[q].hh.b1;
{880:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25595+cursize].hh.rh]].int,18);
end{:880};goto 81;end;
15:{908:}begin case curstyle div 2 of 0:begin p:=mem[q+1].hh.lh;
mem[q+1].hh.lh:=-268435455;end;1:begin p:=mem[q+1].hh.rh;
mem[q+1].hh.rh:=-268435455;end;2:begin p:=mem[q+2].hh.lh;
mem[q+2].hh.lh:=-268435455;end;3:begin p:=mem[q+2].hh.rh;
mem[q+2].hh.rh:=-268435455;end;end;flushnodelist(mem[q+1].hh.lh);
flushnodelist(mem[q+1].hh.rh);flushnodelist(mem[q+2].hh.lh);
flushnodelist(mem[q+2].hh.rh);mem[q].hh.b0:=14;mem[q].hh.b1:=curstyle;
mem[q+1].int:=0;mem[q+2].int:=0;
if p<>-268435455 then begin z:=mem[q].hh.rh;mem[q].hh.rh:=p;
while mem[p].hh.rh<>-268435455 do p:=mem[p].hh.rh;mem[p].hh.rh:=z;end;
goto 81;end{:908};3,4,5,8,12,7:goto 81;
2:begin if mem[q+3].int>maxh then maxh:=mem[q+3].int;
if mem[q+2].int>maxd then maxd:=mem[q+2].int;goto 81;end;
10:begin{909:}if mem[q].hh.b1=99 then begin x:=mem[q+1].hh.lh;
y:=mathglue(x,curmu);deleteglueref(x);mem[q+1].hh.lh:=y;mem[q].hh.b1:=0;
end else if(cursize<>0)and(mem[q].hh.b1=98)then begin p:=mem[q].hh.rh;
if p<>-268435455 then if(mem[p].hh.b0=10)or(mem[p].hh.b0=11)then begin
mem[q].hh.rh:=mem[p].hh.rh;mem[p].hh.rh:=-268435455;flushnodelist(p);
end;end{:909};goto 81;end;11:begin mathkern(q,curmu);goto 81;end;
{:907}others:confusion(1288)end;
{931:}case mem[q+1].hh.rh of 1,4:{932:}begin fetch(q+1);
if(curi.b0>0)then begin delta:=fontinfo[italicbase[curf]+(curi.b2)div 4]
.int;p:=newcharacter(curf,curc);
if(mem[q+1].hh.rh=4)and(fontinfo[2+parambase[curf]].int<>0)then delta:=0
;
if(mem[q+3].hh.rh=0)and(delta<>0)then begin mem[p].hh.rh:=newkern(delta)
;delta:=0;end;end else p:=-268435455;end{:932};0:p:=-268435455;
2:p:=mem[q+1].hh.lh;3:begin curmlist:=mem[q+1].hh.lh;
savestyle:=curstyle;mlistpenalties:=false;mlisttohlist;
curstyle:=savestyle;
{880:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25595+cursize].hh.rh]].int,18);
end{:880};p:=hpack(mem[memtop-3].hh.rh,0,1);end;
others:confusion(1289)end;mem[q+1].int:=p;
if(mem[q+3].hh.rh=0)and(mem[q+2].hh.rh=0)then goto 82;
makescripts(q,delta){:931}{:905};82:z:=hpack(mem[q+1].int,0,1);
if mem[z+3].int>maxh then maxh:=mem[z+3].int;
if mem[z+2].int>maxd then maxd:=mem[z+2].int;freenode(z,9);80:r:=q;
rtype:=mem[r].hh.b0;if rtype=31 then begin rtype:=30;curstyle:=style;
{880:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25595+cursize].hh.rh]].int,18);
end{:880};end;81:q:=mem[q].hh.rh;end{:904};
{906:}if rtype=18 then mem[r].hh.b0:=16{:906};{937:}p:=memtop-3;
mem[p].hh.rh:=-268435455;q:=mlist;rtype:=0;curstyle:=style;
{880:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25595+cursize].hh.rh]].int,18);
end{:880};while q<>-268435455 do begin{938:}t:=16;s:=4;pen:=10000;
case mem[q].hh.b0 of 17,20,21,22,23:t:=mem[q].hh.b0;18:begin t:=18;
pen:=eqtb[27186].int;end;19:begin t:=19;pen:=eqtb[27187].int;end;
16,29,27,26:;24:s:=5;28:s:=5;25:begin t:=23;s:=6;end;
30,31:t:=makeleftright(q,style,maxd,maxh);
14:{940:}begin curstyle:=mem[q].hh.b1;s:=3;
{880:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25595+cursize].hh.rh]].int,18);
end{:880};goto 83;end{:940};8,12,2,7,5,3,4,10,11:begin mem[p].hh.rh:=q;
p:=q;q:=mem[q].hh.rh;mem[p].hh.rh:=-268435455;goto 30;end;
others:confusion(1290)end{:938};
{943:}if rtype>0 then begin case strpool[rtype*8+t+magicoffset]of 48:x:=
0;49:if curstyle<4 then x:=15 else x:=0;50:x:=15;
51:if curstyle<4 then x:=16 else x:=0;
52:if curstyle<4 then x:=17 else x:=0;others:confusion(1292)end;
if x<>0 then begin y:=mathglue(eqtb[24528+x].hh.rh,curmu);z:=newglue(y);
mem[y].hh.rh:=-268435455;mem[p].hh.rh:=z;p:=z;mem[z].hh.b1:=x+1;end;
end{:943};
{944:}if mem[q+1].int<>-268435455 then begin mem[p].hh.rh:=mem[q+1].int;
repeat p:=mem[p].hh.rh;until mem[p].hh.rh=-268435455;end;
if penalties then if mem[q].hh.rh<>-268435455 then if pen<10000 then
begin rtype:=mem[mem[q].hh.rh].hh.b0;
if rtype<>12 then if rtype<>19 then begin z:=newpenalty(pen);
mem[p].hh.rh:=z;p:=z;end;end{:944};if mem[q].hh.b0=31 then t:=20;
rtype:=t;83:r:=q;q:=mem[q].hh.rh;freenode(r,s);30:end{:937};end;
{:903}{949:}procedure pushalignment;var p:halfword;begin p:=getnode(6);
mem[p].hh.rh:=alignptr;mem[p].hh.lh:=curalign;
mem[p+1].hh.lh:=mem[memtop-8].hh.rh;mem[p+1].hh.rh:=curspan;
mem[p+2].int:=curloop;mem[p+3].int:=alignstate;mem[p+4].hh.lh:=curhead;
mem[p+4].hh.rh:=curtail;mem[p+5].hh.lh:=curprehead;
mem[p+5].hh.rh:=curpretail;alignptr:=p;curhead:=getavail;
curprehead:=getavail;end;procedure popalignment;var p:halfword;
begin begin mem[curhead].hh.rh:=avail;avail:=curhead;
ifdef('STAT')decr(dynused);endif('STAT')end;
begin mem[curprehead].hh.rh:=avail;avail:=curprehead;
ifdef('STAT')decr(dynused);endif('STAT')end;p:=alignptr;
curtail:=mem[p+4].hh.rh;curhead:=mem[p+4].hh.lh;
curpretail:=mem[p+5].hh.rh;curprehead:=mem[p+5].hh.lh;
alignstate:=mem[p+3].int;curloop:=mem[p+2].int;curspan:=mem[p+1].hh.rh;
mem[memtop-8].hh.rh:=mem[p+1].hh.lh;curalign:=mem[p].hh.lh;
alignptr:=mem[p].hh.rh;freenode(p,6);end;
{:949}{951:}{959:}procedure getpreambletoken;label 20;begin 20:gettoken;
while(curchr=256)and(curcmd=4)do begin gettoken;
if curcmd>102 then begin expand;gettoken;end;end;
if curcmd=9 then fatalerror(677);
if(curcmd=75)and(curchr=24539)then begin scanoptionalequals;scanglue(2);
if eqtb[27220].int>0 then geqdefine(24539,119,curval)else eqdefine(24539
,119,curval);goto 20;end;end;{:959}procedure alignpeek;forward;
procedure normalparagraph;forward;procedure initalign;label 30,31,32,22;
var savecsptr:halfword;p:halfword;begin savecsptr:=curcs;pushalignment;
alignstate:=-1000000;
{953:}if(curlist.modefield=207)and((curlist.tailfield<>curlist.headfield
)or(curlist.auxfield.int<>-268435455))then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(264);
print(782);end;printesc(597);print(1293);begin helpptr:=3;
helpline[2]:=1294;helpline[1]:=1295;helpline[0]:=1296;end;error;
flushmath;end{:953};pushnest;
{952:}if curlist.modefield=207 then begin curlist.modefield:=-1;
curlist.auxfield.int:=nest[nestptr-2].auxfield.int;
end else if curlist.modefield>0 then curlist.modefield:=-curlist.
modefield{:952};scanspec(6,false);{954:}mem[memtop-8].hh.rh:=-268435455;
curalign:=memtop-8;curloop:=-268435455;scannerstatus:=4;
warningindex:=savecsptr;alignstate:=-1000000;
while true do begin{955:}mem[curalign].hh.rh:=newparamglue(11);
curalign:=mem[curalign].hh.rh{:955};if curcmd=5 then goto 30;
{956:}{960:}p:=memtop-4;mem[p].hh.rh:=-268435455;
while true do begin getpreambletoken;if curcmd=6 then goto 31;
if(curcmd<=5)and(curcmd>=4)and(alignstate=-1000000)then if(p=memtop-4)
and(curloop=-268435455)and(curcmd=4)then curloop:=curalign else begin
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1302);
end;begin helpptr:=3;helpline[2]:=1303;helpline[1]:=1304;
helpline[0]:=1305;end;backerror;goto 31;
end else if(curcmd<>10)or(p<>memtop-4)then begin mem[p].hh.rh:=getavail;
p:=mem[p].hh.rh;mem[p].hh.lh:=curtok;end;end;31:{:960};
mem[curalign].hh.rh:=newnullbox;curalign:=mem[curalign].hh.rh;
mem[curalign].hh.lh:=memtop-9;mem[curalign+1].int:=-1073741824;
mem[curalign+3].int:=mem[memtop-4].hh.rh;{961:}p:=memtop-4;
mem[p].hh.rh:=-268435455;while true do begin 22:getpreambletoken;
if(curcmd<=5)and(curcmd>=4)and(alignstate=-1000000)then goto 32;
if curcmd=6 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1306);
end;begin helpptr:=3;helpline[2]:=1303;helpline[1]:=1304;
helpline[0]:=1307;end;error;goto 22;end;mem[p].hh.rh:=getavail;
p:=mem[p].hh.rh;mem[p].hh.lh:=curtok;end;32:mem[p].hh.rh:=getavail;
p:=mem[p].hh.rh;mem[p].hh.lh:=19614{:961};
mem[curalign+2].int:=mem[memtop-4].hh.rh{:956};end;
30:scannerstatus:=0{:954};newsavelevel(6);
if eqtb[25066].hh.rh<>-268435455 then begintokenlist(eqtb[25066].hh.rh,
13);alignpeek;end;{:951}{963:}{964:}procedure initspan(p:halfword);
begin pushnest;
if curlist.modefield=-104 then curlist.auxfield.hh.lh:=1000 else begin
curlist.auxfield.int:=eqtb[27825].int;normalparagraph;end;curspan:=p;
end;{:964}procedure initrow;begin pushnest;
curlist.modefield:=(-105)-curlist.modefield;
if curlist.modefield=-104 then curlist.auxfield.hh.lh:=0 else curlist.
auxfield.int:=0;
begin mem[curlist.tailfield].hh.rh:=newglue(mem[mem[memtop-8].hh.rh+1].
hh.lh);curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b1:=12;
curalign:=mem[mem[memtop-8].hh.rh].hh.rh;curtail:=curhead;
curpretail:=curprehead;initspan(curalign);end;
{:963}{965:}procedure initcol;begin mem[curalign+5].hh.lh:=curcmd;
if curcmd=63 then alignstate:=0 else begin backinput;
begintokenlist(mem[curalign+3].int,1);end;end;
{:965}{968:}function fincol:boolean;label 10;var p:halfword;
q,r:halfword;s:halfword;u:halfword;w:scaled;o:glueord;n:halfword;
begin if curalign=-268435455 then confusion(1308);
q:=mem[curalign].hh.rh;if q=-268435455 then confusion(1308);
if alignstate<500000 then fatalerror(677);p:=mem[q].hh.rh;
{969:}if(p=-268435455)and(mem[curalign+5].hh.lh<257)then if curloop<>
-268435455 then{970:}begin mem[q].hh.rh:=newnullbox;p:=mem[q].hh.rh;
mem[p].hh.lh:=memtop-9;mem[p+1].int:=-1073741824;
curloop:=mem[curloop].hh.rh;{971:}q:=memtop-4;r:=mem[curloop+3].int;
while r<>-268435455 do begin mem[q].hh.rh:=getavail;q:=mem[q].hh.rh;
mem[q].hh.lh:=mem[r].hh.lh;r:=mem[r].hh.rh;end;mem[q].hh.rh:=-268435455;
mem[p+3].int:=mem[memtop-4].hh.rh;q:=memtop-4;r:=mem[curloop+2].int;
while r<>-268435455 do begin mem[q].hh.rh:=getavail;q:=mem[q].hh.rh;
mem[q].hh.lh:=mem[r].hh.lh;r:=mem[r].hh.rh;end;mem[q].hh.rh:=-268435455;
mem[p+2].int:=mem[memtop-4].hh.rh{:971};curloop:=mem[curloop].hh.rh;
mem[p].hh.rh:=newglue(mem[curloop+1].hh.lh);
end{:970}else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1309);
end;printesc(1298);begin helpptr:=3;helpline[2]:=1310;helpline[1]:=1311;
helpline[0]:=1312;end;mem[curalign+5].hh.lh:=257;error;end{:969};
if mem[curalign+5].hh.lh<>256 then begin unsave;newsavelevel(6);
{973:}begin if curlist.modefield=-104 then begin adjusttail:=curtail;
preadjusttail:=curpretail;u:=hpack(mem[curlist.headfield].hh.rh,0,1);
w:=mem[u+1].int;curtail:=adjusttail;adjusttail:=-268435455;
curpretail:=preadjusttail;preadjusttail:=-268435455;
end else begin u:=vpackage(mem[curlist.headfield].hh.rh,0,1,0);
w:=mem[u+3].int;end;n:=0;
if curspan<>curalign then{975:}begin q:=curspan;repeat incr(n);
q:=mem[mem[q].hh.rh].hh.rh;until q=curalign;
if n>255 then confusion(1313);q:=curspan;
while mem[mem[q].hh.lh].hh.rh<n do q:=mem[q].hh.lh;
if mem[mem[q].hh.lh].hh.rh>n then begin s:=getnode(2);
mem[s].hh.lh:=mem[q].hh.lh;mem[s].hh.rh:=n;mem[q].hh.lh:=s;
mem[s+1].int:=w;
end else if mem[mem[q].hh.lh+1].int<w then mem[mem[q].hh.lh+1].int:=w;
end{:975}else if w>mem[curalign+1].int then mem[curalign+1].int:=w;
mem[u].hh.b0:=13;mem[u].hh.b1:=n;
{836:}if totalstretch[3]<>0 then o:=3 else if totalstretch[2]<>0 then o
:=2 else if totalstretch[1]<>0 then o:=1 else o:=0{:836};
mem[u+5].hh.b1:=o;mem[u+6].int:=totalstretch[o];
{842:}if totalshrink[3]<>0 then o:=3 else if totalshrink[2]<>0 then o:=2
else if totalshrink[1]<>0 then o:=1 else o:=0{:842};mem[u+5].hh.b0:=o;
mem[u+4].int:=totalshrink[o];popnest;mem[curlist.tailfield].hh.rh:=u;
curlist.tailfield:=u;end{:973};
{972:}begin mem[curlist.tailfield].hh.rh:=newglue(mem[mem[curalign].hh.
rh+1].hh.lh);curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b1:=12{:972};
if mem[curalign+5].hh.lh>=257 then begin fincol:=true;goto 10;end;
initspan(p);end;alignstate:=1000000;repeat getxorprotected;
until curcmd<>10;curalign:=p;initcol;fincol:=false;10:end;
{:968}{976:}procedure finrow;var p:halfword;
begin if curlist.modefield=-104 then begin p:=hpack(mem[curlist.
headfield].hh.rh,0,1);popnest;
if curprehead<>curpretail then begin mem[curlist.tailfield].hh.rh:=mem[
curprehead].hh.rh;curlist.tailfield:=curpretail;end;appendtovlist(p);
if curhead<>curtail then begin mem[curlist.tailfield].hh.rh:=mem[curhead
].hh.rh;curlist.tailfield:=curtail;end;
end else begin p:=vpackage(mem[curlist.headfield].hh.rh,0,1,1073741823);
popnest;mem[curlist.tailfield].hh.rh:=p;curlist.tailfield:=p;
curlist.auxfield.hh.lh:=1000;end;mem[p].hh.b0:=13;mem[p+6].int:=0;
if eqtb[25066].hh.rh<>-268435455 then begintokenlist(eqtb[25066].hh.rh,
13);alignpeek;end;{:976}{977:}procedure doassignments;forward;
procedure resumeafterdisplay;forward;procedure buildpage;forward;
procedure finalign;var p,q,r,s,u,v:halfword;t,w:scaled;o:scaled;
n:halfword;rulesave:scaled;auxsave:memoryword;
begin if curgroup<>6 then confusion(1314);unsave;
if curgroup<>6 then confusion(1315);unsave;
if nest[nestptr-1].modefield=207 then o:=eqtb[27808].int else o:=0;
{978:}q:=mem[mem[memtop-8].hh.rh].hh.rh;repeat flushlist(mem[q+3].int);
flushlist(mem[q+2].int);p:=mem[mem[q].hh.rh].hh.rh;
if mem[q+1].int=-1073741824 then{979:}begin mem[q+1].int:=0;
r:=mem[q].hh.rh;s:=mem[r+1].hh.lh;
if s<>membot then begin incr(mem[membot].hh.rh);deleteglueref(s);
mem[r+1].hh.lh:=membot;end;end{:979};
if mem[q].hh.lh<>memtop-9 then{980:}begin t:=mem[q+1].int+mem[mem[mem[q]
.hh.rh+1].hh.lh+1].int;r:=mem[q].hh.lh;s:=memtop-9;mem[s].hh.lh:=p;n:=1;
repeat mem[r+1].int:=mem[r+1].int-t;u:=mem[r].hh.lh;
while mem[r].hh.rh>n do begin s:=mem[s].hh.lh;
n:=mem[mem[s].hh.lh].hh.rh+1;end;
if mem[r].hh.rh<n then begin mem[r].hh.lh:=mem[s].hh.lh;mem[s].hh.lh:=r;
decr(mem[r].hh.rh);s:=r;
end else begin if mem[r+1].int>mem[mem[s].hh.lh+1].int then mem[mem[s].
hh.lh+1].int:=mem[r+1].int;freenode(r,2);end;r:=u;until r=memtop-9;
end{:980};mem[q].hh.b0:=13;mem[q].hh.b1:=0;mem[q+3].int:=0;
mem[q+2].int:=0;mem[q+5].hh.b1:=0;mem[q+5].hh.b0:=0;mem[q+6].int:=0;
mem[q+4].int:=0;q:=p;until q=-268435455{:978};{981:}saveptr:=saveptr-2;
packbeginline:=-curlist.mlfield;
if curlist.modefield=-1 then begin rulesave:=eqtb[27809].int;
eqtb[27809].int:=0;
p:=hpack(mem[memtop-8].hh.rh,savestack[saveptr+1].int,savestack[saveptr
+0].int);eqtb[27809].int:=rulesave;
end else begin q:=mem[mem[memtop-8].hh.rh].hh.rh;
repeat mem[q+3].int:=mem[q+1].int;mem[q+1].int:=0;
q:=mem[mem[q].hh.rh].hh.rh;until q=-268435455;
p:=vpackage(mem[memtop-8].hh.rh,savestack[saveptr+1].int,savestack[
saveptr+0].int,1073741823);q:=mem[mem[memtop-8].hh.rh].hh.rh;
repeat mem[q+1].int:=mem[q+3].int;mem[q+3].int:=0;
q:=mem[mem[q].hh.rh].hh.rh;until q=-268435455;end;
packbeginline:=0{:981};{982:}q:=mem[curlist.headfield].hh.rh;
s:=curlist.headfield;
while q<>-268435455 do begin if not(q>=himemmin)then if mem[q].hh.b0=13
then{984:}begin if curlist.modefield=-1 then begin mem[q].hh.b0:=0;
mem[q+1].int:=mem[p+1].int;
if nest[nestptr-1].modefield=207 then mem[q].hh.b1:=2;
end else begin mem[q].hh.b0:=1;mem[q+3].int:=mem[p+3].int;end;
mem[q+5].hh.b1:=mem[p+5].hh.b1;mem[q+5].hh.b0:=mem[p+5].hh.b0;
mem[q+6].gr:=mem[p+6].gr;mem[q+4].int:=o;r:=mem[mem[q+5].hh.rh].hh.rh;
s:=mem[mem[p+5].hh.rh].hh.rh;repeat{985:}n:=mem[r].hh.b1;
t:=mem[s+1].int;w:=t;u:=memtop-4;mem[r].hh.b1:=0;
while n>0 do begin decr(n);{986:}s:=mem[s].hh.rh;v:=mem[s+1].hh.lh;
mem[u].hh.rh:=newglue(v);u:=mem[u].hh.rh;mem[u].hh.b1:=12;
t:=t+mem[v+1].int;
if mem[p+5].hh.b0=1 then begin if mem[v].hh.b0=mem[p+5].hh.b1 then t:=t+
round(mem[p+6].gr*mem[v+2].int);
end else if mem[p+5].hh.b0=2 then begin if mem[v].hh.b1=mem[p+5].hh.b1
then t:=t-round(mem[p+6].gr*mem[v+3].int);end;s:=mem[s].hh.rh;
mem[u].hh.rh:=newnullbox;u:=mem[u].hh.rh;t:=t+mem[s+1].int;
if curlist.modefield=-1 then mem[u+1].int:=mem[s+1].int else begin mem[u
].hh.b0:=1;mem[u+3].int:=mem[s+1].int;end{:986};end;
if curlist.modefield=-1 then{987:}begin mem[r+3].int:=mem[q+3].int;
mem[r+2].int:=mem[q+2].int;
if t=mem[r+1].int then begin mem[r+5].hh.b0:=0;mem[r+5].hh.b1:=0;
mem[r+6].gr:=0.0;
end else if t>mem[r+1].int then begin mem[r+5].hh.b0:=1;
if mem[r+6].int=0 then mem[r+6].gr:=0.0 else mem[r+6].gr:=(t-mem[r+1].
int)/mem[r+6].int;end else begin mem[r+5].hh.b1:=mem[r+5].hh.b0;
mem[r+5].hh.b0:=2;
if mem[r+4].int=0 then mem[r+6].gr:=0.0 else if(mem[r+5].hh.b1=0)and(mem
[r+1].int-t>mem[r+4].int)then mem[r+6].gr:=1.0 else mem[r+6].gr:=(mem[r
+1].int-t)/mem[r+4].int;end;mem[r+1].int:=w;mem[r].hh.b0:=0;
end{:987}else{988:}begin mem[r+1].int:=mem[q+1].int;
if t=mem[r+3].int then begin mem[r+5].hh.b0:=0;mem[r+5].hh.b1:=0;
mem[r+6].gr:=0.0;
end else if t>mem[r+3].int then begin mem[r+5].hh.b0:=1;
if mem[r+6].int=0 then mem[r+6].gr:=0.0 else mem[r+6].gr:=(t-mem[r+3].
int)/mem[r+6].int;end else begin mem[r+5].hh.b1:=mem[r+5].hh.b0;
mem[r+5].hh.b0:=2;
if mem[r+4].int=0 then mem[r+6].gr:=0.0 else if(mem[r+5].hh.b1=0)and(mem
[r+3].int-t>mem[r+4].int)then mem[r+6].gr:=1.0 else mem[r+6].gr:=(mem[r
+3].int-t)/mem[r+4].int;end;mem[r+3].int:=w;mem[r].hh.b0:=1;end{:988};
mem[r+4].int:=0;if u<>memtop-4 then begin mem[u].hh.rh:=mem[r].hh.rh;
mem[r].hh.rh:=mem[memtop-4].hh.rh;r:=u;end{:985};
r:=mem[mem[r].hh.rh].hh.rh;s:=mem[mem[s].hh.rh].hh.rh;
until r=-268435455;
end{:984}else if mem[q].hh.b0=2 then{983:}begin if(mem[q+1].int=
-1073741824)then mem[q+1].int:=mem[p+1].int;
if(mem[q+3].int=-1073741824)then mem[q+3].int:=mem[p+3].int;
if(mem[q+2].int=-1073741824)then mem[q+2].int:=mem[p+2].int;
if o<>0 then begin r:=mem[q].hh.rh;mem[q].hh.rh:=-268435455;
q:=hpack(q,0,1);mem[q+4].int:=o;mem[q].hh.rh:=r;mem[s].hh.rh:=q;end;
end{:983};s:=q;q:=mem[q].hh.rh;end{:982};flushnodelist(p);popalignment;
{989:}auxsave:=curlist.auxfield;p:=mem[curlist.headfield].hh.rh;
q:=curlist.tailfield;popnest;
if curlist.modefield=207 then{1385:}begin doassignments;
if curcmd<>3 then{1386:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1577);
end;begin helpptr:=2;helpline[1]:=1294;helpline[0]:=1295;end;backerror;
end{:1386}else{1376:}begin getxtoken;
if curcmd<>3 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1573);
end;begin helpptr:=2;helpline[1]:=1574;helpline[0]:=1575;end;backerror;
end;end{:1376};flushnodelist(curlist.eTeXauxfield);popnest;
begin mem[curlist.tailfield].hh.rh:=newpenalty(eqtb[27188].int);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
begin mem[curlist.tailfield].hh.rh:=newparamglue(3);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.rh:=p;
if p<>-268435455 then curlist.tailfield:=q;
begin mem[curlist.tailfield].hh.rh:=newpenalty(eqtb[27189].int);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
begin mem[curlist.tailfield].hh.rh:=newparamglue(4);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
curlist.auxfield.int:=auxsave.int;resumeafterdisplay;
end{:1385}else begin curlist.auxfield:=auxsave;
mem[curlist.tailfield].hh.rh:=p;
if p<>-268435455 then curlist.tailfield:=q;
if curlist.modefield=1 then buildpage;end{:989};end;
{962:}procedure alignpeek;label 20;begin 20:alignstate:=1000000;
repeat getxorprotected;until curcmd<>10;
if curcmd=34 then begin scanleftbrace;newsavelevel(7);
if curlist.modefield=-1 then normalparagraph;
end else if curcmd=2 then finalign else if(curcmd=5)and(curchr=258)then
goto 20 else begin initrow;initcol;end;end;
{:962}{:977}{992:}{1003:}function finiteshrink(p:halfword):halfword;
var q:halfword;
begin if noshrinkerroryet then begin noshrinkerroryet:=false;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1316);
end;begin helpptr:=5;helpline[4]:=1317;helpline[3]:=1318;
helpline[2]:=1319;helpline[1]:=1320;helpline[0]:=1321;end;error;end;
q:=newspec(p);mem[q].hh.b1:=0;deleteglueref(p);finiteshrink:=q;end;
{:1003}{1006:}procedure pushnode(p:halfword);
begin if hliststacklevel>512 then pdferror(1322,1323);
hliststack[hliststacklevel]:=p;hliststacklevel:=hliststacklevel+1;end;
function popnode:halfword;begin hliststacklevel:=hliststacklevel-1;
if hliststacklevel<0 then pdferror(1324,1325);
popnode:=hliststack[hliststacklevel];end;
function findprotcharleft(l:halfword;d:boolean):halfword;var t:halfword;
run:boolean;
begin if(mem[l].hh.rh<>-268435455)and(mem[l].hh.b0=0)and(mem[l+1].int=0)
and(mem[l+3].int=0)and(mem[l+2].int=0)and(mem[l+5].hh.rh=-268435455)then
l:=mem[l].hh.rh else if d then while(mem[l].hh.rh<>-268435455)and(not((l
>=himemmin)or(mem[l].hh.b0<9)))do l:=mem[l].hh.rh;hliststacklevel:=0;
run:=true;repeat t:=l;
while run and(mem[l].hh.b0=0)and(mem[l+5].hh.rh<>-268435455)do begin
pushnode(l);l:=mem[l+5].hh.rh;end;
while run and(not(l>=himemmin)and((mem[l].hh.b0=3)or(mem[l].hh.b0=4)or(
mem[l].hh.b0=5)or(mem[l].hh.b0=12)or((mem[l].hh.b0=8)and(mem[l].hh.b1<>
12)and(mem[l].hh.b1<>10))or((mem[l].hh.b0=7)and(mem[l+1].hh.lh=
-268435455)and(mem[l+1].hh.rh=-268435455)and(mem[l].hh.b1=0))or((mem[l].
hh.b0=9)and(mem[l+1].int=0))or((mem[l].hh.b0=11)and((mem[l+1].int=0)or(
mem[l].hh.b1=0)))or((mem[l].hh.b0=10)and(mem[l+1].hh.lh=membot))or((mem[
l].hh.b0=0)and(mem[l+1].int=0)and(mem[l+3].int=0)and(mem[l+2].int=0)and(
mem[l+5].hh.rh=-268435455))))do begin while(mem[l].hh.rh=-268435455)and(
hliststacklevel>0)do begin l:=popnode;end;
if mem[l].hh.rh<>-268435455 then l:=mem[l].hh.rh else if hliststacklevel
=0 then run:=false end;until t=l;findprotcharleft:=l;end;
function findprotcharright(l,r:halfword):halfword;var t:halfword;
run:boolean;begin findprotcharright:=-268435455;
if r=-268435455 then goto 10;hliststacklevel:=0;run:=true;repeat t:=r;
while run and(mem[r].hh.b0=0)and(mem[r+5].hh.rh<>-268435455)do begin
pushnode(l);pushnode(r);l:=mem[r+5].hh.rh;r:=l;
while mem[r].hh.rh<>-268435455 do r:=mem[r].hh.rh;end;
while run and(not(r>=himemmin)and((mem[r].hh.b0=3)or(mem[r].hh.b0=4)or(
mem[r].hh.b0=5)or(mem[r].hh.b0=12)or((mem[r].hh.b0=8)and(mem[r].hh.b1<>
12)and(mem[r].hh.b1<>10))or((mem[r].hh.b0=7)and(mem[r+1].hh.lh=
-268435455)and(mem[r+1].hh.rh=-268435455)and(mem[r].hh.b1=0))or((mem[r].
hh.b0=9)and(mem[r+1].int=0))or((mem[r].hh.b0=11)and((mem[r+1].int=0)or(
mem[r].hh.b1=0)))or((mem[r].hh.b0=10)and(mem[r+1].hh.lh=membot))or((mem[
r].hh.b0=0)and(mem[r+1].int=0)and(mem[r+3].int=0)and(mem[r+2].int=0)and(
mem[r+5].hh.rh=-268435455))))do begin while(r=l)and(hliststacklevel>0)do
begin r:=popnode;l:=popnode;end;
if(r<>l)and(r<>-268435455)then r:=prevrightmost(l,r)else if(r=l)and(
hliststacklevel=0)then run:=false end;until t=r;findprotcharright:=r;
end;function totalpw(q,p:halfword):scaled;var l,r:halfword;n:integer;
begin if mem[q+1].hh.rh=-268435455 then l:=firstp else l:=mem[mem[q+1].
hh.rh+1].hh.rh;r:=prevrightmost(prevp,p);{shortdisplayn(r,2);print(38);
shortdisplayn(p,2);println;}
if(p<>-268435455)and(mem[p].hh.b0=7)and(mem[p+1].hh.lh<>-268435455)then
begin r:=mem[p+1].hh.lh;
while mem[r].hh.rh<>-268435455 do r:=mem[r].hh.rh;
end else r:=findprotcharright(l,r);{shortdisplayn(l,2);println;
breadthmax:=10;depththreshold:=2;shownodelist(l);println;}
if(l<>-268435455)and(mem[l].hh.b0=7)then begin if mem[l+1].hh.rh<>
-268435455 then begin l:=mem[l+1].hh.rh;goto 30;
end else begin n:=mem[l].hh.b1;l:=mem[l].hh.rh;
while n>0 do begin if mem[l].hh.rh<>-268435455 then l:=mem[l].hh.rh;
decr(n);end;end;end;l:=findprotcharleft(l,true);
30:totalpw:=charpw(l,0)+charpw(r,1);end;procedure trybreak(pi:integer;
breaktype:smallnumber);label 10,30,31,22,60,40,45;var r:halfword;
marginkernstretch:scaled;marginkernshrink:scaled;lp,rp,cp:halfword;
prevr:halfword;oldl:halfword;nobreakyet:boolean;
{1007:}prevprevr:halfword;s:halfword;q:halfword;v:halfword;t:integer;
f:internalfontnumber;l:halfword;noderstaysactive:boolean;
linewidth:scaled;fitclass:0..3;b:halfword;d:integer;
artificialdemerits:boolean;savelink:halfword;shortfall:scaled;
{:1007}{1842:}g:scaled;
{:1842}begin{1008:}if abs(pi)>=10000 then if pi>0 then goto 10 else pi:=
-10000{:1008};nobreakyet:=true;prevr:=memtop-7;oldl:=0;
curactivewidth[1]:=activewidth[1];curactivewidth[2]:=activewidth[2];
curactivewidth[3]:=activewidth[3];curactivewidth[4]:=activewidth[4];
curactivewidth[5]:=activewidth[5];curactivewidth[6]:=activewidth[6];
if eqtb[27256].int>1 then begin curactivewidth[7]:=activewidth[7];
curactivewidth[8]:=activewidth[8];end;
while true do begin 22:r:=mem[prevr].hh.rh;
{1009:}if mem[r].hh.b0=2 then begin curactivewidth[1]:=curactivewidth[1]
+mem[r+1].int;curactivewidth[2]:=curactivewidth[2]+mem[r+2].int;
curactivewidth[3]:=curactivewidth[3]+mem[r+3].int;
curactivewidth[4]:=curactivewidth[4]+mem[r+4].int;
curactivewidth[5]:=curactivewidth[5]+mem[r+5].int;
curactivewidth[6]:=curactivewidth[6]+mem[r+6].int;
if eqtb[27256].int>1 then begin curactivewidth[7]:=curactivewidth[7]+mem
[r+7].int;curactivewidth[8]:=curactivewidth[8]+mem[r+8].int;end;
prevprevr:=prevr;prevr:=r;goto 22;end{:1009};
{1012:}begin l:=mem[r+1].hh.lh;
if l>oldl then begin if(minimumdemerits<1073741823)and((oldl<>easyline)
or(r=memtop-7))then{1013:}begin if nobreakyet then{1014:}begin
nobreakyet:=false;breakwidth[1]:=background[1];
breakwidth[2]:=background[2];breakwidth[3]:=background[3];
breakwidth[4]:=background[4];breakwidth[5]:=background[5];
breakwidth[6]:=background[6];
if eqtb[27256].int>1 then begin breakwidth[7]:=background[7];
breakwidth[8]:=background[8];end;s:=curp;
if breaktype>0 then if curp<>-268435455 then{1017:}begin t:=mem[curp].hh
.b1;v:=curp;s:=mem[curp+1].hh.rh;while t>0 do begin decr(t);
v:=mem[v].hh.rh;{1018:}if(v>=himemmin)then begin f:=mem[v].hh.b0;
breakwidth[1]:=breakwidth[1]-fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[v].hh.b1)].qqqq.b0].int;
if(eqtb[27256].int>1)and checkexpandpars(f)then begin prevcharp:=v;
breakwidth[7]:=breakwidth[7]-charstretch(f,mem[v].hh.b1);
breakwidth[8]:=breakwidth[8]-charshrink(f,mem[v].hh.b1);end;
end else case mem[v].hh.b0 of 6:begin f:=mem[v+1].hh.b0;
breakwidth[1]:=breakwidth[1]-fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[v+1].hh.b1)].qqqq.b0].int;
if(eqtb[27256].int>1)and checkexpandpars(f)then begin prevcharp:=v;
breakwidth[7]:=breakwidth[7]-charstretch(f,mem[v+1].hh.b1);
breakwidth[8]:=breakwidth[8]-charshrink(f,mem[v+1].hh.b1);end;end;
0,1,2,11:begin breakwidth[1]:=breakwidth[1]-mem[v+1].int;
if(mem[v].hh.b0=11)and(eqtb[27256].int>1)and(mem[v].hh.b1=0)then begin
breakwidth[7]:=breakwidth[7]-kernstretch(v);
breakwidth[8]:=breakwidth[8]-kernshrink(v);end;end;
others:confusion(1326)end{:1018};end;
while s<>-268435455 do begin{1019:}if(s>=himemmin)then begin f:=mem[s].
hh.b0;
breakwidth[1]:=breakwidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[s].hh.b1)].qqqq.b0].int;
if(eqtb[27256].int>1)and checkexpandpars(f)then begin prevcharp:=s;
breakwidth[7]:=breakwidth[7]+charstretch(f,mem[s].hh.b1);
breakwidth[8]:=breakwidth[8]+charshrink(f,mem[s].hh.b1);end;
end else case mem[s].hh.b0 of 6:begin f:=mem[s+1].hh.b0;
breakwidth[1]:=breakwidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[s+1].hh.b1)].qqqq.b0].int;
if(eqtb[27256].int>1)and checkexpandpars(f)then begin prevcharp:=s;
breakwidth[7]:=breakwidth[7]+charstretch(f,mem[s+1].hh.b1);
breakwidth[8]:=breakwidth[8]+charshrink(f,mem[s+1].hh.b1);end;end;
0,1,2,11:begin breakwidth[1]:=breakwidth[1]+mem[s+1].int;
if(mem[s].hh.b0=11)and(eqtb[27256].int>1)and(mem[s].hh.b1=0)then begin
breakwidth[7]:=breakwidth[7]+kernstretch(s);
breakwidth[8]:=breakwidth[8]+kernshrink(s);end;end;
others:confusion(1327)end{:1019};s:=mem[s].hh.rh;end;
breakwidth[1]:=breakwidth[1]+discwidth[1];
if eqtb[27256].int>1 then begin breakwidth[7]:=breakwidth[7]+discwidth[7
];breakwidth[8]:=breakwidth[8]+discwidth[8];end;
if mem[curp+1].hh.rh=-268435455 then s:=mem[v].hh.rh;end{:1017};
while s<>-268435455 do begin if(s>=himemmin)then goto 30;
case mem[s].hh.b0 of 10:{1015:}begin v:=mem[s+1].hh.lh;
breakwidth[1]:=breakwidth[1]-mem[v+1].int;
breakwidth[2+mem[v].hh.b0]:=breakwidth[2+mem[v].hh.b0]-mem[v+2].int;
breakwidth[6]:=breakwidth[6]-mem[v+3].int;end{:1015};12:;
9:breakwidth[1]:=breakwidth[1]-mem[s+1].int;
11:if mem[s].hh.b1<>1 then goto 30 else breakwidth[1]:=breakwidth[1]-mem
[s+1].int;others:goto 30 end;s:=mem[s].hh.rh;end;30:end{:1014};
{1020:}if mem[prevr].hh.b0=2 then begin mem[prevr+1].int:=mem[prevr+1].
int-curactivewidth[1]+breakwidth[1];
mem[prevr+2].int:=mem[prevr+2].int-curactivewidth[2]+breakwidth[2];
mem[prevr+3].int:=mem[prevr+3].int-curactivewidth[3]+breakwidth[3];
mem[prevr+4].int:=mem[prevr+4].int-curactivewidth[4]+breakwidth[4];
mem[prevr+5].int:=mem[prevr+5].int-curactivewidth[5]+breakwidth[5];
mem[prevr+6].int:=mem[prevr+6].int-curactivewidth[6]+breakwidth[6];
if eqtb[27256].int>1 then begin mem[prevr+7].int:=mem[prevr+7].int-
curactivewidth[7]+breakwidth[7];
mem[prevr+8].int:=mem[prevr+8].int-curactivewidth[8]+breakwidth[8];end;
end else if prevr=memtop-7 then begin activewidth[1]:=breakwidth[1];
activewidth[2]:=breakwidth[2];activewidth[3]:=breakwidth[3];
activewidth[4]:=breakwidth[4];activewidth[5]:=breakwidth[5];
activewidth[6]:=breakwidth[6];
if eqtb[27256].int>1 then begin activewidth[7]:=breakwidth[7];
activewidth[8]:=breakwidth[8];end;end else begin q:=getnode(9);
mem[q].hh.rh:=r;mem[q].hh.b0:=2;mem[q].hh.b1:=0;
mem[q+1].int:=breakwidth[1]-curactivewidth[1];
mem[q+2].int:=breakwidth[2]-curactivewidth[2];
mem[q+3].int:=breakwidth[3]-curactivewidth[3];
mem[q+4].int:=breakwidth[4]-curactivewidth[4];
mem[q+5].int:=breakwidth[5]-curactivewidth[5];
mem[q+6].int:=breakwidth[6]-curactivewidth[6];
if eqtb[27256].int>1 then begin mem[q+7].int:=breakwidth[7]-
curactivewidth[7];mem[q+8].int:=breakwidth[8]-curactivewidth[8];end;
mem[prevr].hh.rh:=q;prevprevr:=prevr;prevr:=q;end{:1020};
if abs(eqtb[27193].int)>=1073741823-minimumdemerits then minimumdemerits
:=1073741822 else minimumdemerits:=minimumdemerits+abs(eqtb[27193].int);
for fitclass:=0 to 3 do begin if minimaldemerits[fitclass]<=
minimumdemerits then{1022:}begin q:=getnode(2);mem[q].hh.rh:=passive;
passive:=q;mem[q+1].hh.rh:=curp;ifdef('STAT')incr(passnumber);
mem[q].hh.lh:=passnumber;
endif('STAT')mem[q+1].hh.lh:=bestplace[fitclass];
q:=getnode(activenodesize);mem[q+1].hh.rh:=passive;
mem[q+1].hh.lh:=bestplline[fitclass]+1;mem[q].hh.b1:=fitclass;
mem[q].hh.b0:=breaktype;mem[q+2].int:=minimaldemerits[fitclass];
if dolastlinefit then{1849:}begin mem[q+3].int:=bestplshort[fitclass];
mem[q+4].int:=bestplglue[fitclass];end{:1849};mem[q].hh.rh:=r;
mem[prevr].hh.rh:=q;prevr:=q;
ifdef('STAT')if eqtb[27209].int>0 then{1023:}begin printnl(1328);
printint(mem[passive].hh.lh);print(1329);printint(mem[q+1].hh.lh-1);
printchar(46);printint(fitclass);if breaktype=1 then printchar(45);
print(1330);printint(mem[q+2].int);
if dolastlinefit then{1850:}begin print(2056);printscaled(mem[q+3].int);
if curp=-268435455 then print(2057)else print(1400);
printscaled(mem[q+4].int);end{:1850};print(1331);
if mem[passive+1].hh.lh=-268435455 then printchar(48)else printint(mem[
mem[passive+1].hh.lh].hh.lh);end{:1023};endif('STAT')end{:1022};
minimaldemerits[fitclass]:=1073741823;end;minimumdemerits:=1073741823;
{1021:}if r<>memtop-7 then begin q:=getnode(9);mem[q].hh.rh:=r;
mem[q].hh.b0:=2;mem[q].hh.b1:=0;
mem[q+1].int:=curactivewidth[1]-breakwidth[1];
mem[q+2].int:=curactivewidth[2]-breakwidth[2];
mem[q+3].int:=curactivewidth[3]-breakwidth[3];
mem[q+4].int:=curactivewidth[4]-breakwidth[4];
mem[q+5].int:=curactivewidth[5]-breakwidth[5];
mem[q+6].int:=curactivewidth[6]-breakwidth[6];
if eqtb[27256].int>1 then begin mem[q+7].int:=curactivewidth[7]-
breakwidth[7];mem[q+8].int:=curactivewidth[8]-breakwidth[8];end;
mem[prevr].hh.rh:=q;prevprevr:=prevr;prevr:=q;end{:1021};end{:1013};
if r=memtop-7 then goto 10;
{1027:}if l>easyline then begin linewidth:=secondwidth;oldl:=268435454;
end else begin oldl:=l;
if l>lastspecialline then linewidth:=secondwidth else if eqtb[25058].hh.
rh=-268435455 then linewidth:=firstwidth else linewidth:=mem[eqtb[25058]
.hh.rh+2*l].int;end{:1027};end;end{:1012};
{1028:}begin artificialdemerits:=false;
shortfall:=linewidth-curactivewidth[1];
{if eqtb[27239].int>2 then begin println;
if(r<>-268435455)and(mem[r+1].hh.rh<>-268435455)then shortdisplayn(mem[
mem[r+1].hh.rh+1].hh.rh,5);println;shortdisplayn(curp,5);println;end;}
if eqtb[27257].int>1 then shortfall:=shortfall+totalpw(r,curp);
if(eqtb[27256].int>1)and(shortfall<>0)then begin marginkernstretch:=0;
marginkernshrink:=0;
if eqtb[27257].int>1 then{823:}begin lp:=lastleftmostchar;
rp:=lastrightmostchar;begin cp:=avail;
if cp=-268435455 then cp:=getavail else begin avail:=mem[cp].hh.rh;
mem[cp].hh.rh:=-268435455;ifdef('STAT')incr(dynused);endif('STAT')end;
end;if lp<>-268435455 then begin mem[cp].hh.b1:=mem[lp].hh.b1;
mem[cp].hh.b0:=mem[lp].hh.b0;dosubstfont(cp,1000);
if mem[cp].hh.b0<>mem[lp].hh.b0 then marginkernstretch:=
marginkernstretch+charpw(lp,0)-charpw(cp,0);
mem[cp].hh.b0:=mem[lp].hh.b0;dosubstfont(cp,-1000);
if mem[cp].hh.b0<>mem[lp].hh.b0 then marginkernshrink:=marginkernshrink+
charpw(cp,0)-charpw(lp,0);end;
if rp<>-268435455 then begin mem[cp].hh.b1:=mem[rp].hh.b1;
mem[cp].hh.b0:=mem[rp].hh.b0;dosubstfont(cp,1000);
if mem[cp].hh.b0<>mem[rp].hh.b0 then marginkernstretch:=
marginkernstretch+charpw(rp,0)-charpw(cp,0);
mem[cp].hh.b0:=mem[rp].hh.b0;dosubstfont(cp,-1000);
if mem[cp].hh.b0<>mem[rp].hh.b0 then marginkernshrink:=marginkernshrink+
charpw(cp,0)-charpw(rp,0);end;begin mem[cp].hh.rh:=avail;avail:=cp;
ifdef('STAT')decr(dynused);endif('STAT')end;end{:823};
if(shortfall>0)and((curactivewidth[7]+marginkernstretch)>0)then begin if
(curactivewidth[7]+marginkernstretch)>shortfall then shortfall:=((
curactivewidth[7]+marginkernstretch)div(maxstretchratio div curfontstep)
)div 2 else shortfall:=shortfall-(curactivewidth[7]+marginkernstretch);
end else if(shortfall<0)and((curactivewidth[8]+marginkernshrink)>0)then
begin if(curactivewidth[8]+marginkernshrink)>-shortfall then shortfall:=
-((curactivewidth[8]+marginkernshrink)div(maxshrinkratio div curfontstep
))div 2 else shortfall:=shortfall+(curactivewidth[8]+marginkernshrink);
end;end;
if shortfall>0 then{1029:}if(curactivewidth[3]<>0)or(curactivewidth[4]<>
0)or(curactivewidth[5]<>0)then begin if dolastlinefit then begin if curp
=-268435455 then{1844:}begin if(mem[r+3].int=0)or(mem[r+4].int<=0)then
goto 45;
if(curactivewidth[3]<>fillwidth[0])or(curactivewidth[4]<>fillwidth[1])or
(curactivewidth[5]<>fillwidth[2])then goto 45;
if mem[r+3].int>0 then g:=curactivewidth[2]else g:=curactivewidth[6];
if g<=0 then goto 45;aritherror:=false;
g:=fract(g,mem[r+3].int,mem[r+4].int,1073741823);
if eqtb[27276].int<1000 then g:=fract(g,eqtb[27276].int,1000,1073741823)
;if aritherror then if mem[r+3].int>0 then g:=1073741823 else g:=
-1073741823;if g>0 then{1845:}begin if g>shortfall then g:=shortfall;
if g>7230584 then if curactivewidth[2]<1663497 then begin b:=10000;
fitclass:=0;goto 40;end;b:=badness(g,curactivewidth[2]);
if b>12 then if b>99 then fitclass:=0 else fitclass:=1 else fitclass:=2;
goto 40;
end{:1845}else if g<0 then{1846:}begin if-g>curactivewidth[6]then g:=-
curactivewidth[6];b:=badness(-g,curactivewidth[6]);
if b>12 then fitclass:=3 else fitclass:=2;goto 40;end{:1846};
45:end{:1844};shortfall:=0;end;b:=0;fitclass:=2;
end else begin if shortfall>7230584 then if curactivewidth[2]<1663497
then begin b:=10000;fitclass:=0;goto 31;end;
b:=badness(shortfall,curactivewidth[2]);
if b>12 then if b>99 then fitclass:=0 else fitclass:=1 else fitclass:=2;
31:end{:1029}else{1030:}begin if-shortfall>curactivewidth[6]then b:=
10001 else b:=badness(-shortfall,curactivewidth[6]);
if b>12 then fitclass:=3 else fitclass:=2;end{:1030};
if dolastlinefit then{1847:}begin if curp=-268435455 then shortfall:=0;
if shortfall>0 then g:=curactivewidth[2]else if shortfall<0 then g:=
curactivewidth[6]else g:=0;end{:1847};
40:if(b>10000)or(pi=-10000)then{1031:}begin if finalpass and(
minimumdemerits=1073741823)and(mem[r].hh.rh=memtop-7)and(prevr=memtop-7)
then artificialdemerits:=true else if b>threshold then goto 60;
noderstaysactive:=false;end{:1031}else begin prevr:=r;
if b>threshold then goto 22;noderstaysactive:=true;end;
{1032:}if artificialdemerits then d:=0 else{1036:}begin d:=eqtb[27179].
int+b;if abs(d)>=10000 then d:=100000000 else d:=d*d;
if pi<>0 then if pi>0 then d:=d+pi*pi else if pi>-10000 then d:=d-pi*pi;
if(breaktype=1)and(mem[r].hh.b0=1)then if curp<>-268435455 then d:=d+
eqtb[27191].int else d:=d+eqtb[27192].int;
if abs(fitclass-mem[r].hh.b1)>1 then d:=d+eqtb[27193].int;end{:1036};
ifdef('STAT')if eqtb[27209].int>0 then{1033:}begin if printednode<>curp
then{1034:}begin printnl(345);
if curp=-268435455 then shortdisplay(mem[printednode].hh.rh)else begin
savelink:=mem[curp].hh.rh;mem[curp].hh.rh:=-268435455;printnl(345);
shortdisplay(mem[printednode].hh.rh);mem[curp].hh.rh:=savelink;end;
printednode:=curp;end{:1034};printnl(64);
if curp=-268435455 then printesc(679)else if mem[curp].hh.b0<>10 then
begin if mem[curp].hh.b0=12 then printesc(609)else if mem[curp].hh.b0=7
then printesc(357)else if mem[curp].hh.b0=11 then printesc(322)else
printesc(351);end;print(1332);
if mem[r+1].hh.rh=-268435455 then printchar(48)else printint(mem[mem[r+1
].hh.rh].hh.lh);print(1333);
if b>10000 then printchar(42)else printint(b);print(1334);printint(pi);
print(1335);if artificialdemerits then printchar(42)else printint(d);
end{:1033};endif('STAT')d:=d+mem[r+2].int;
if d<=minimaldemerits[fitclass]then begin minimaldemerits[fitclass]:=d;
bestplace[fitclass]:=mem[r+1].hh.rh;bestplline[fitclass]:=l;
if dolastlinefit then{1848:}begin bestplshort[fitclass]:=shortfall;
bestplglue[fitclass]:=g;end{:1848};
if d<minimumdemerits then minimumdemerits:=d;end{:1032};
if noderstaysactive then goto 22;
60:{1037:}mem[prevr].hh.rh:=mem[r].hh.rh;freenode(r,activenodesize);
if prevr=memtop-7 then{1038:}begin r:=mem[memtop-7].hh.rh;
if mem[r].hh.b0=2 then begin activewidth[1]:=activewidth[1]+mem[r+1].int
;activewidth[2]:=activewidth[2]+mem[r+2].int;
activewidth[3]:=activewidth[3]+mem[r+3].int;
activewidth[4]:=activewidth[4]+mem[r+4].int;
activewidth[5]:=activewidth[5]+mem[r+5].int;
activewidth[6]:=activewidth[6]+mem[r+6].int;
if eqtb[27256].int>1 then begin activewidth[7]:=activewidth[7]+mem[r+7].
int;activewidth[8]:=activewidth[8]+mem[r+8].int;end;
curactivewidth[1]:=activewidth[1];curactivewidth[2]:=activewidth[2];
curactivewidth[3]:=activewidth[3];curactivewidth[4]:=activewidth[4];
curactivewidth[5]:=activewidth[5];curactivewidth[6]:=activewidth[6];
if eqtb[27256].int>1 then begin curactivewidth[7]:=activewidth[7];
curactivewidth[8]:=activewidth[8];end;mem[memtop-7].hh.rh:=mem[r].hh.rh;
freenode(r,9);end;
end{:1038}else if mem[prevr].hh.b0=2 then begin r:=mem[prevr].hh.rh;
if r=memtop-7 then begin curactivewidth[1]:=curactivewidth[1]-mem[prevr
+1].int;curactivewidth[2]:=curactivewidth[2]-mem[prevr+2].int;
curactivewidth[3]:=curactivewidth[3]-mem[prevr+3].int;
curactivewidth[4]:=curactivewidth[4]-mem[prevr+4].int;
curactivewidth[5]:=curactivewidth[5]-mem[prevr+5].int;
curactivewidth[6]:=curactivewidth[6]-mem[prevr+6].int;
if eqtb[27256].int>1 then begin curactivewidth[7]:=curactivewidth[7]-mem
[prevr+7].int;curactivewidth[8]:=curactivewidth[8]-mem[prevr+8].int;end;
mem[prevprevr].hh.rh:=memtop-7;freenode(prevr,9);prevr:=prevprevr;
end else if mem[r].hh.b0=2 then begin curactivewidth[1]:=curactivewidth[
1]+mem[r+1].int;curactivewidth[2]:=curactivewidth[2]+mem[r+2].int;
curactivewidth[3]:=curactivewidth[3]+mem[r+3].int;
curactivewidth[4]:=curactivewidth[4]+mem[r+4].int;
curactivewidth[5]:=curactivewidth[5]+mem[r+5].int;
curactivewidth[6]:=curactivewidth[6]+mem[r+6].int;
if eqtb[27256].int>1 then begin curactivewidth[7]:=curactivewidth[7]+mem
[r+7].int;curactivewidth[8]:=curactivewidth[8]+mem[r+8].int;end;
mem[prevr+1].int:=mem[prevr+1].int+mem[r+1].int;
mem[prevr+2].int:=mem[prevr+2].int+mem[r+2].int;
mem[prevr+3].int:=mem[prevr+3].int+mem[r+3].int;
mem[prevr+4].int:=mem[prevr+4].int+mem[r+4].int;
mem[prevr+5].int:=mem[prevr+5].int+mem[r+5].int;
mem[prevr+6].int:=mem[prevr+6].int+mem[r+6].int;
if eqtb[27256].int>1 then begin mem[prevr+7].int:=mem[prevr+7].int+mem[r
+7].int;mem[prevr+8].int:=mem[prevr+8].int+mem[r+8].int;end;
mem[prevr].hh.rh:=mem[r].hh.rh;freenode(r,9);end;end{:1037};end{:1028};
end;
10:ifdef('STAT'){1035:}if curp=printednode then if curp<>-268435455 then
if mem[curp].hh.b0=7 then begin t:=mem[curp].hh.b1;
while t>0 do begin decr(t);printednode:=mem[printednode].hh.rh;end;
end{:1035}endif('STAT')end;
{:1006}{1054:}procedure postlinebreak(d:boolean);label 30,31;
var q,r,s:halfword;p,k:halfword;w:scaled;gluebreak:boolean;
ptmp:halfword;discbreak:boolean;postdiscbreak:boolean;curwidth:scaled;
curindent:scaled;t:quarterword;pen:integer;curline:halfword;
LRptr:halfword;begin LRptr:=curlist.eTeXauxfield;
{1055:}q:=mem[bestbet+1].hh.rh;curp:=-268435455;repeat r:=q;
q:=mem[q+1].hh.lh;mem[r+1].hh.lh:=curp;curp:=r;
until q=-268435455{:1055};curline:=curlist.pgfield+1;
repeat{1057:}if(eqtb[27279].int>0)then{1705:}begin q:=mem[memtop-3].hh.
rh;if LRptr<>-268435455 then begin tempptr:=LRptr;r:=q;
repeat s:=newmath(0,(mem[tempptr].hh.lh-1));mem[s].hh.rh:=r;r:=s;
tempptr:=mem[tempptr].hh.rh;until tempptr=-268435455;
mem[memtop-3].hh.rh:=r;end;
while q<>mem[curp+1].hh.rh do begin if not(q>=himemmin)then if mem[q].hh
.b0=9 then{1706:}if odd(mem[q].hh.b1)then begin if LRptr<>-268435455
then if mem[LRptr].hh.lh=(4*(mem[q].hh.b1 div 4)+3)then begin tempptr:=
LRptr;LRptr:=mem[tempptr].hh.rh;begin mem[tempptr].hh.rh:=avail;
avail:=tempptr;ifdef('STAT')decr(dynused);endif('STAT')end;end;
end else begin tempptr:=getavail;
mem[tempptr].hh.lh:=(4*(mem[q].hh.b1 div 4)+3);
mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;end{:1706};q:=mem[q].hh.rh;end;
end{:1705};{1058:}q:=mem[curp+1].hh.rh;discbreak:=false;
postdiscbreak:=false;gluebreak:=false;
if q<>-268435455 then if mem[q].hh.b0=10 then begin deleteglueref(mem[q
+1].hh.lh);mem[q+1].hh.lh:=eqtb[24536].hh.rh;mem[q].hh.b1:=9;
incr(mem[eqtb[24536].hh.rh].hh.rh);gluebreak:=true;goto 30;
end else begin if mem[q].hh.b0=7 then{1059:}begin t:=mem[q].hh.b1;
{1060:}if t=0 then r:=mem[q].hh.rh else begin r:=q;
while t>1 do begin r:=mem[r].hh.rh;decr(t);end;s:=mem[r].hh.rh;
r:=mem[s].hh.rh;mem[s].hh.rh:=-268435455;flushnodelist(mem[q].hh.rh);
mem[q].hh.b1:=0;end{:1060};
if mem[q+1].hh.rh<>-268435455 then{1061:}begin s:=mem[q+1].hh.rh;
while mem[s].hh.rh<>-268435455 do s:=mem[s].hh.rh;mem[s].hh.rh:=r;
r:=mem[q+1].hh.rh;mem[q+1].hh.rh:=-268435455;postdiscbreak:=true;
end{:1061};
if mem[q+1].hh.lh<>-268435455 then{1062:}begin s:=mem[q+1].hh.lh;
mem[q].hh.rh:=s;while mem[s].hh.rh<>-268435455 do s:=mem[s].hh.rh;
mem[q+1].hh.lh:=-268435455;q:=s;end{:1062};mem[q].hh.rh:=r;
discbreak:=true;
end{:1059}else if mem[q].hh.b0=11 then mem[q+1].int:=0 else if mem[q].hh
.b0=9 then begin mem[q+1].int:=0;
if(eqtb[27279].int>0)then{1706:}if odd(mem[q].hh.b1)then begin if LRptr
<>-268435455 then if mem[LRptr].hh.lh=(4*(mem[q].hh.b1 div 4)+3)then
begin tempptr:=LRptr;LRptr:=mem[tempptr].hh.rh;
begin mem[tempptr].hh.rh:=avail;avail:=tempptr;
ifdef('STAT')decr(dynused);endif('STAT')end;end;
end else begin tempptr:=getavail;
mem[tempptr].hh.lh:=(4*(mem[q].hh.b1 div 4)+3);
mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;end{:1706};end;
end else begin q:=memtop-3;
while mem[q].hh.rh<>-268435455 do q:=mem[q].hh.rh;end;
30:if eqtb[27257].int>0 then begin if discbreak and((q>=himemmin)or(mem[
q].hh.b0<>7))then begin p:=q;ptmp:=p;
end else begin p:=prevrightmost(mem[memtop-3].hh.rh,q);ptmp:=p;
p:=findprotcharright(mem[memtop-3].hh.rh,p);end;{shortdisplayn(p,1);
println;}w:=charpw(p,1);
if w<>0 then begin k:=newmarginkern(-w,lastrightmostchar,1);
mem[k].hh.rh:=mem[ptmp].hh.rh;mem[ptmp].hh.rh:=k;
if(ptmp=q)then q:=mem[q].hh.rh;end;end;
if not gluebreak then begin{1063:}r:=newparamglue(8);
mem[r].hh.rh:=mem[q].hh.rh;mem[q].hh.rh:=r;q:=r{:1063};end;{:1058};
if(eqtb[27279].int>0)then{1707:}if LRptr<>-268435455 then begin s:=
memtop-3;r:=mem[s].hh.rh;while r<>q do begin s:=r;r:=mem[s].hh.rh;end;
r:=LRptr;while r<>-268435455 do begin tempptr:=newmath(0,mem[r].hh.lh);
mem[s].hh.rh:=tempptr;s:=tempptr;r:=mem[r].hh.rh;end;mem[s].hh.rh:=q;
end{:1707};{1064:}r:=mem[q].hh.rh;mem[q].hh.rh:=-268435455;
q:=mem[memtop-3].hh.rh;mem[memtop-3].hh.rh:=r;
if eqtb[27257].int>0 then begin p:=q;p:=findprotcharleft(p,false);
w:=charpw(p,0);
if w<>0 then begin k:=newmarginkern(-w,lastleftmostchar,0);
mem[k].hh.rh:=q;q:=k;end;end;
if eqtb[24535].hh.rh<>membot then begin r:=newparamglue(7);
mem[r].hh.rh:=q;q:=r;end{:1064};
{1067:}if curline>lastspecialline then begin curwidth:=secondwidth;
curindent:=secondindent;
end else if eqtb[25058].hh.rh=-268435455 then begin curwidth:=firstwidth
;curindent:=firstindent;
end else begin curwidth:=mem[eqtb[25058].hh.rh+2*curline].int;
curindent:=mem[eqtb[25058].hh.rh+2*curline-1].int;end;
adjusttail:=memtop-5;preadjusttail:=memtop-14;
if eqtb[27256].int>0 then justbox:=hpack(q,curwidth,2)else justbox:=
hpack(q,curwidth,0);mem[justbox+4].int:=curindent{:1067};
{1066:}if eqtb[27823].int<>eqtb[27825].int then mem[justbox+3].int:=eqtb
[27823].int;
if eqtb[27824].int<>eqtb[27825].int then mem[justbox+2].int:=eqtb[27824]
.int;
if(eqtb[27821].int<>eqtb[27825].int)and(curline=curlist.pgfield+1)then
mem[justbox+3].int:=eqtb[27821].int;
if(eqtb[27822].int<>eqtb[27825].int)and(curline+1=bestline)then mem[
justbox+2].int:=eqtb[27822].int;
if memtop-14<>preadjusttail then begin mem[curlist.tailfield].hh.rh:=mem
[memtop-14].hh.rh;curlist.tailfield:=preadjusttail;end;
preadjusttail:=-268435455;appendtovlist(justbox);
if memtop-5<>adjusttail then begin mem[curlist.tailfield].hh.rh:=mem[
memtop-5].hh.rh;curlist.tailfield:=adjusttail;end;
adjusttail:=-268435455{:1066};
{1068:}if curline+1<>bestline then begin q:=eqtb[25329].hh.rh;
if q<>-268435455 then begin r:=curline;
if r>mem[q+1].int then r:=mem[q+1].int;pen:=mem[q+r+1].int;
end else pen:=eqtb[27190].int;q:=eqtb[25330].hh.rh;
if q<>-268435455 then begin r:=curline-curlist.pgfield;
if r>mem[q+1].int then r:=mem[q+1].int;pen:=pen+mem[q+r+1].int;
end else if curline=curlist.pgfield+1 then pen:=pen+eqtb[27182].int;
if d then q:=eqtb[25332].hh.rh else q:=eqtb[25331].hh.rh;
if q<>-268435455 then begin r:=bestline-curline-1;
if r>mem[q+1].int then r:=mem[q+1].int;pen:=pen+mem[q+r+1].int;
end else if curline+2=bestline then if d then pen:=pen+eqtb[27184].int
else pen:=pen+eqtb[27183].int;
if discbreak then pen:=pen+eqtb[27185].int;
if pen<>0 then begin r:=newpenalty(pen);mem[curlist.tailfield].hh.rh:=r;
curlist.tailfield:=r;end;end{:1068}{:1057};incr(curline);
curp:=mem[curp+1].hh.lh;
if curp<>-268435455 then if not postdiscbreak then{1056:}begin r:=memtop
-3;while true do begin q:=mem[r].hh.rh;
if q=mem[curp+1].hh.rh then goto 31;if(q>=himemmin)then goto 31;
if(mem[q].hh.b0<9)then goto 31;
if mem[q].hh.b0=11 then if mem[q].hh.b1<>1 then goto 31;r:=q;
if mem[q].hh.b0=9 then if(eqtb[27279].int>0)then{1706:}if odd(mem[q].hh.
b1)then begin if LRptr<>-268435455 then if mem[LRptr].hh.lh=(4*(mem[q].
hh.b1 div 4)+3)then begin tempptr:=LRptr;LRptr:=mem[tempptr].hh.rh;
begin mem[tempptr].hh.rh:=avail;avail:=tempptr;
ifdef('STAT')decr(dynused);endif('STAT')end;end;
end else begin tempptr:=getavail;
mem[tempptr].hh.lh:=(4*(mem[q].hh.b1 div 4)+3);
mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;end{:1706};end;
31:if r<>memtop-3 then begin mem[r].hh.rh:=-268435455;
flushnodelist(mem[memtop-3].hh.rh);mem[memtop-3].hh.rh:=q;end;
end{:1056};until curp=-268435455;
if(curline<>bestline)or(mem[memtop-3].hh.rh<>-268435455)then confusion(
1342);curlist.pgfield:=bestline-1;curlist.eTeXauxfield:=LRptr;end;
{:1054}{1073:}{1084:}function reconstitute(j,n:smallnumber;
bchar,hchar:halfword):smallnumber;label 22,30;var p:halfword;t:halfword;
q:fourquarters;currh:halfword;testchar:halfword;w:scaled;k:fontindex;
begin hyphenpassed:=0;t:=memtop-4;w:=0;mem[memtop-4].hh.rh:=-268435455;
{1086:}curl:=hu[j];curq:=t;if j=0 then begin ligaturepresent:=initlig;
p:=initlist;if ligaturepresent then lfthit:=initlft;
while p>-268435455 do begin begin mem[t].hh.rh:=getavail;
t:=mem[t].hh.rh;mem[t].hh.b0:=hf;mem[t].hh.b1:=mem[p].hh.b1;end;
p:=mem[p].hh.rh;end;
end else if curl<256 then begin mem[t].hh.rh:=getavail;t:=mem[t].hh.rh;
mem[t].hh.b0:=hf;mem[t].hh.b1:=curl;end;ligstack:=-268435455;
begin if j<n then curr:=hu[j+1]else curr:=bchar;
if odd(hyf[j])then currh:=hchar else currh:=256;end{:1086};
22:{1087:}if curl=256 then begin k:=bcharlabel[hf];
if k=0 then goto 30 else q:=fontinfo[k].qqqq;
end else begin q:=fontinfo[charbase[hf]+effectivechar(true,hf,curl)].
qqqq;if((q.b2)mod 4)<>1 then goto 30;k:=ligkernbase[hf]+q.b3;
q:=fontinfo[k].qqqq;
if q.b0>128 then begin k:=ligkernbase[hf]+256*q.b2+q.b3+32768-256*(128);
q:=fontinfo[k].qqqq;end;end;
if currh<256 then testchar:=currh else testchar:=curr;
while true do begin if q.b1=testchar then if q.b0<=128 then if currh<256
then begin hyphenpassed:=j;hchar:=256;currh:=256;goto 22;
end else begin if hchar<256 then if odd(hyf[j])then begin hyphenpassed:=
j;hchar:=256;end;
if q.b2<128 then{1089:}begin if curl=256 then lfthit:=true;
if j=n then if ligstack=-268435455 then rthit:=true;
begin if interrupt<>0 then pauseforinstructions;end;
case q.b2 of 1,5:begin curl:=q.b3;ligaturepresent:=true;end;
2,6:begin curr:=q.b3;
if ligstack>-268435455 then mem[ligstack].hh.b1:=curr else begin
ligstack:=newligitem(curr);
if j=n then bchar:=256 else begin p:=getavail;mem[ligstack+1].hh.rh:=p;
mem[p].hh.b1:=hu[j+1];mem[p].hh.b0:=hf;end;end;end;3:begin curr:=q.b3;
p:=ligstack;ligstack:=newligitem(curr);mem[ligstack].hh.rh:=p;end;
7,11:begin if ligaturepresent then begin p:=newligature(hf,curl,mem[curq
].hh.rh);if lfthit then begin mem[p].hh.b1:=2;lfthit:=false;end;
if false then if ligstack=-268435455 then begin incr(mem[p].hh.b1);
rthit:=false;end;mem[curq].hh.rh:=p;t:=p;ligaturepresent:=false;end;
curq:=t;curl:=q.b3;ligaturepresent:=true;end;others:begin curl:=q.b3;
ligaturepresent:=true;
if ligstack>-268435455 then begin if mem[ligstack+1].hh.rh>-268435455
then begin mem[t].hh.rh:=mem[ligstack+1].hh.rh;t:=mem[t].hh.rh;incr(j);
end;p:=ligstack;ligstack:=mem[p].hh.rh;freenode(p,2);
if ligstack=-268435455 then begin if j<n then curr:=hu[j+1]else curr:=
bchar;if odd(hyf[j])then currh:=hchar else currh:=256;
end else curr:=mem[ligstack].hh.b1;
end else if j=n then goto 30 else begin begin mem[t].hh.rh:=getavail;
t:=mem[t].hh.rh;mem[t].hh.b0:=hf;mem[t].hh.b1:=curr;end;incr(j);
begin if j<n then curr:=hu[j+1]else curr:=bchar;
if odd(hyf[j])then currh:=hchar else currh:=256;end;end;end end;
if q.b2>4 then if q.b2<>7 then goto 30;goto 22;end{:1089};
w:=fontinfo[kernbase[hf]+256*q.b2+q.b3].int;goto 30;end;
if q.b0>=128 then if currh=256 then goto 30 else begin currh:=256;
goto 22;end;k:=k+q.b0+1;q:=fontinfo[k].qqqq;end;30:{:1087};
{1088:}if ligaturepresent then begin p:=newligature(hf,curl,mem[curq].hh
.rh);if lfthit then begin mem[p].hh.b1:=2;lfthit:=false;end;
if rthit then if ligstack=-268435455 then begin incr(mem[p].hh.b1);
rthit:=false;end;mem[curq].hh.rh:=p;t:=p;ligaturepresent:=false;end;
if w<>0 then begin mem[t].hh.rh:=newkern(w);t:=mem[t].hh.rh;w:=0;
mem[t+2].int:=0;end;if ligstack>-268435455 then begin curq:=t;
curl:=mem[ligstack].hh.b1;ligaturepresent:=true;
begin if mem[ligstack+1].hh.rh>-268435455 then begin mem[t].hh.rh:=mem[
ligstack+1].hh.rh;t:=mem[t].hh.rh;incr(j);end;p:=ligstack;
ligstack:=mem[p].hh.rh;freenode(p,2);
if ligstack=-268435455 then begin if j<n then curr:=hu[j+1]else curr:=
bchar;if odd(hyf[j])then currh:=hchar else currh:=256;
end else curr:=mem[ligstack].hh.b1;end;goto 22;end{:1088};
reconstitute:=j;end;{:1084}procedure hyphenate;
label 50,30,40,41,42,45,10;var{1079:}i,j,l:0..65;q,r,s:halfword;
bchar:halfword;{:1079}{1090:}majortail,minortail:halfword;c:ASCIIcode;
cloc:0..63;rcount:integer;hyfnode:halfword;{:1090}{1100:}z:triepointer;
v:integer;{:1100}{1107:}h:hyphpointer;k:strnumber;u:poolpointer;
{:1107}begin{1101:}for j:=0 to hn do hyf[j]:=0;{1108:}h:=hc[1];incr(hn);
hc[hn]:=curlang;for j:=2 to hn do h:=(h+h+hc[j])mod 607;
while true do begin{1109:}k:=hyphword[h];if k=0 then goto 45;
if(strstart[k+1]-strstart[k])=hn then begin j:=1;u:=strstart[k];
repeat if strpool[u]<>hc[j]then goto 30;incr(j);incr(u);until j>hn;
{1110:}s:=hyphlist[h];while s<>-268435455 do begin hyf[mem[s].hh.lh]:=1;
s:=mem[s].hh.rh;end{:1110};decr(hn);goto 40;end;30:{:1109};
h:=hyphlink[h];if h=0 then goto 45;decr(h);end;45:decr(hn){:1108};
if trietrc[curlang+1]<>curlang then goto 10;hc[0]:=0;hc[hn+1]:=0;
hc[hn+2]:=256;
for j:=0 to hn-rhyf+1 do begin z:=trietrl[curlang+1]+hc[j];l:=j;
while hc[l]=trietrc[z]do begin if trietro[z]<>mintrieop then{1102:}begin
v:=trietro[z];repeat v:=v+opstart[curlang];i:=l-hyfdistance[v];
if hyfnum[v]>hyf[i]then hyf[i]:=hyfnum[v];v:=hyfnext[v];
until v=mintrieop;end{:1102};incr(l);z:=trietrl[z]+hc[l];end;end;
40:for j:=0 to lhyf-1 do hyf[j]:=0;
for j:=0 to rhyf-1 do hyf[hn-j]:=0{:1101};
{1080:}for j:=lhyf to hn-rhyf do if odd(hyf[j])then goto 41;goto 10;
41:{:1080};{1081:}q:=mem[hb].hh.rh;mem[hb].hh.rh:=-268435455;
r:=mem[ha].hh.rh;mem[ha].hh.rh:=-268435455;bchar:=hyfbchar;
if(ha>=himemmin)then if mem[ha].hh.b0<>hf then goto 42 else begin
initlist:=ha;initlig:=false;hu[0]:=mem[ha].hh.b1;
end else if mem[ha].hh.b0=6 then if mem[ha+1].hh.b0<>hf then goto 42
else begin initlist:=mem[ha+1].hh.rh;initlig:=true;
initlft:=(mem[ha].hh.b1>1);hu[0]:=mem[ha+1].hh.b1;
if initlist=-268435455 then if initlft then begin hu[0]:=256;
initlig:=false;end;freenode(ha,2);
end else begin if not(r>=himemmin)then if mem[r].hh.b0=6 then if mem[r].
hh.b1>1 then goto 42;j:=1;s:=ha;initlist:=-268435455;goto 50;end;
s:=curp;while mem[s].hh.rh<>ha do s:=mem[s].hh.rh;j:=0;goto 50;42:s:=ha;
j:=0;hu[0]:=256;initlig:=false;initlist:=-268435455;50:flushnodelist(r);
{1091:}repeat l:=j;j:=reconstitute(j,hn,bchar,hyfchar)+1;
if hyphenpassed=0 then begin mem[s].hh.rh:=mem[memtop-4].hh.rh;
while mem[s].hh.rh>-268435455 do s:=mem[s].hh.rh;
if odd(hyf[j-1])then begin l:=j;hyphenpassed:=j-1;
mem[memtop-4].hh.rh:=-268435455;end;end;
if hyphenpassed>0 then{1092:}repeat r:=getnode(2);
mem[r].hh.rh:=mem[memtop-4].hh.rh;mem[r].hh.b0:=7;majortail:=r;
rcount:=0;
while mem[majortail].hh.rh>-268435455 do begin majortail:=mem[majortail]
.hh.rh;incr(rcount);end;i:=hyphenpassed;hyf[i]:=0;
{1093:}minortail:=-268435455;mem[r+1].hh.lh:=-268435455;
hyfnode:=newcharacter(hf,hyfchar);
if hyfnode<>-268435455 then begin incr(i);c:=hu[i];hu[i]:=hyfchar;
begin mem[hyfnode].hh.rh:=avail;avail:=hyfnode;
ifdef('STAT')decr(dynused);endif('STAT')end;end;
while l<=i do begin l:=reconstitute(l,i,fontbchar[hf],256)+1;
if mem[memtop-4].hh.rh>-268435455 then begin if minortail=-268435455
then mem[r+1].hh.lh:=mem[memtop-4].hh.rh else mem[minortail].hh.rh:=mem[
memtop-4].hh.rh;minortail:=mem[memtop-4].hh.rh;
while mem[minortail].hh.rh>-268435455 do minortail:=mem[minortail].hh.rh
;end;end;if hyfnode<>-268435455 then begin hu[i]:=c;l:=i;decr(i);
end{:1093};{1094:}minortail:=-268435455;mem[r+1].hh.rh:=-268435455;
cloc:=0;if bcharlabel[hf]<>0 then begin decr(l);c:=hu[l];cloc:=l;
hu[l]:=256;end;
while l<j do begin repeat l:=reconstitute(l,hn,bchar,256)+1;
if cloc>0 then begin hu[cloc]:=c;cloc:=0;end;
if mem[memtop-4].hh.rh>-268435455 then begin if minortail=-268435455
then mem[r+1].hh.rh:=mem[memtop-4].hh.rh else mem[minortail].hh.rh:=mem[
memtop-4].hh.rh;minortail:=mem[memtop-4].hh.rh;
while mem[minortail].hh.rh>-268435455 do minortail:=mem[minortail].hh.rh
;end;until l>=j;
while l>j do{1095:}begin j:=reconstitute(j,hn,bchar,256)+1;
mem[majortail].hh.rh:=mem[memtop-4].hh.rh;
while mem[majortail].hh.rh>-268435455 do begin majortail:=mem[majortail]
.hh.rh;incr(rcount);end;end{:1095};end{:1094};
{1096:}if rcount>127 then begin mem[s].hh.rh:=mem[r].hh.rh;
mem[r].hh.rh:=-268435455;flushnodelist(r);
end else begin mem[s].hh.rh:=r;mem[r].hh.b1:=rcount;end;
s:=majortail{:1096};hyphenpassed:=j-1;mem[memtop-4].hh.rh:=-268435455;
until not odd(hyf[j-1]){:1092};until j>hn;mem[s].hh.rh:=q{:1091};
flushlist(initlist){:1081};10:end;
{:1073}{1120:}ifdef('INITEX'){1122:}function newtrieop(d,n:smallnumber;
v:trieopcode):trieopcode;label 10;var h:negtrieopsize..trieopsize;
u:trieopcode;l:0..trieopsize;
begin h:=abs(n+313*d+361*v+1009*curlang)mod(trieopsize-negtrieopsize)+
negtrieopsize;while true do begin l:=trieophash[h];
if l=0 then begin if trieopptr=trieopsize then overflow(1352,trieopsize)
;u:=trieused[curlang];
if u=maxtrieop then overflow(1353,maxtrieop-mintrieop);incr(trieopptr);
incr(u);trieused[curlang]:=u;if u>maxopused then maxopused:=u;
hyfdistance[trieopptr]:=d;hyfnum[trieopptr]:=n;hyfnext[trieopptr]:=v;
trieoplang[trieopptr]:=curlang;trieophash[h]:=trieopptr;
trieopval[trieopptr]:=u;newtrieop:=u;goto 10;end;
if(hyfdistance[l]=d)and(hyfnum[l]=n)and(hyfnext[l]=v)and(trieoplang[l]=
curlang)then begin newtrieop:=trieopval[l];goto 10;end;
if h>-trieopsize then decr(h)else h:=trieopsize;end;10:end;
{:1122}{1126:}function trienode(p:triepointer):triepointer;label 10;
var h:triepointer;q:triepointer;
begin h:=abs(triec[p]+1009*trieo[p]+2718*triel[p]+3142*trier[p])mod
triesize;while true do begin q:=triehash[h];
if q=0 then begin triehash[h]:=p;trienode:=p;goto 10;end;
if(triec[q]=triec[p])and(trieo[q]=trieo[p])and(triel[q]=triel[p])and(
trier[q]=trier[p])then begin trienode:=q;goto 10;end;
if h>0 then decr(h)else h:=triesize;end;10:end;
{:1126}{1127:}function compresstrie(p:triepointer):triepointer;
begin if p=0 then compresstrie:=0 else begin triel[p]:=compresstrie(
triel[p]);trier[p]:=compresstrie(trier[p]);compresstrie:=trienode(p);
end;end;{:1127}{1131:}procedure firstfit(p:triepointer);label 45,40;
var h:triepointer;z:triepointer;q:triepointer;c:ASCIIcode;
l,r:triepointer;ll:1..256;begin c:=triec[p];z:=triemin[c];
while true do begin h:=z-c;
{1132:}if triemax<h+256 then begin if triesize<=h+256 then overflow(1354
,triesize);repeat incr(triemax);trietaken[triemax]:=false;
trietrl[triemax]:=triemax+1;trietro[triemax]:=triemax-1;
until triemax=h+256;end{:1132};if trietaken[h]then goto 45;
{1133:}q:=trier[p];
while q>0 do begin if trietrl[h+triec[q]]=0 then goto 45;q:=trier[q];
end;goto 40{:1133};45:z:=trietrl[z];end;40:{1134:}trietaken[h]:=true;
triehash[p]:=h;q:=p;repeat z:=h+triec[q];l:=trietro[z];r:=trietrl[z];
trietro[r]:=l;trietrl[l]:=r;trietrl[z]:=0;
if l<256 then begin if z<256 then ll:=z else ll:=256;
repeat triemin[l]:=r;incr(l);until l=ll;end;q:=trier[q];
until q=0{:1134};end;{:1131}{1135:}procedure triepack(p:triepointer);
var q:triepointer;begin repeat q:=triel[p];
if(q>0)and(triehash[q]=0)then begin firstfit(q);triepack(q);end;
p:=trier[p];until p=0;end;
{:1135}{1137:}procedure triefix(p:triepointer);var q:triepointer;
c:ASCIIcode;z:triepointer;begin z:=triehash[p];repeat q:=triel[p];
c:=triec[p];trietrl[z+c]:=triehash[q];trietrc[z+c]:=c;
trietro[z+c]:=trieo[p];if q>0 then triefix(q);p:=trier[p];until p=0;end;
{:1137}{1138:}procedure newpatterns;label 30,31;var k,l:0..64;
digitsensed:boolean;v:trieopcode;p,q:triepointer;firstchild:boolean;
c:ASCIIcode;
begin if trienotready then begin if eqtb[27227].int<=0 then curlang:=0
else if eqtb[27227].int>255 then curlang:=0 else curlang:=eqtb[27227].
int;scanleftbrace;{1139:}k:=0;hyf[0]:=0;digitsensed:=false;
while true do begin getxtoken;
case curcmd of 11,12:{1140:}if digitsensed or(curchr<48)or(curchr>57)
then begin if curchr=46 then curchr:=0 else begin curchr:=eqtb[25897+
curchr].hh.rh;if curchr=0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1360);
end;begin helpptr:=1;helpline[0]:=1359;end;error;end;end;
if k<63 then begin incr(k);hc[k]:=curchr;hyf[k]:=0;digitsensed:=false;
end;end else if k<63 then begin hyf[k]:=curchr-48;digitsensed:=true;
end{:1140};
10,2:begin if k>0 then{1141:}begin{1143:}if hc[1]=0 then hyf[0]:=0;
if hc[k]=0 then hyf[k]:=0;l:=k;v:=mintrieop;
while true do begin if hyf[l]<>0 then v:=newtrieop(k-l,hyf[l],v);
if l>0 then decr(l)else goto 31;end;31:{:1143};q:=0;hc[0]:=curlang;
while l<=k do begin c:=hc[l];incr(l);p:=triel[q];firstchild:=true;
while(p>0)and(c>triec[p])do begin q:=p;p:=trier[q];firstchild:=false;
end;
if(p=0)or(c<triec[p])then{1142:}begin if trieptr=triesize then overflow(
1354,triesize);incr(trieptr);trier[trieptr]:=p;p:=trieptr;triel[p]:=0;
if firstchild then triel[q]:=p else trier[q]:=p;triec[p]:=c;
trieo[p]:=mintrieop;end{:1142};q:=p;end;
if trieo[q]<>mintrieop then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1361);
end;begin helpptr:=1;helpline[0]:=1359;end;error;end;trieo[q]:=v;
end{:1141};if curcmd=2 then goto 30;k:=0;hyf[0]:=0;digitsensed:=false;
end;others:begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1358);
end;printesc(1356);begin helpptr:=1;helpline[0]:=1359;end;error;end end;
end;30:{:1139};if eqtb[27278].int>0 then{1853:}begin c:=curlang;
firstchild:=false;p:=0;repeat q:=p;p:=trier[q];
until(p=0)or(c<=triec[p]);
if(p=0)or(c<triec[p])then{1142:}begin if trieptr=triesize then overflow(
1354,triesize);incr(trieptr);trier[trieptr]:=p;p:=trieptr;triel[p]:=0;
if firstchild then triel[q]:=p else trier[q]:=p;triec[p]:=c;
trieo[p]:=mintrieop;end{:1142};q:=p;{1854:}p:=triel[q];firstchild:=true;
for c:=0 to 255 do if(eqtb[25897+c].hh.rh>0)or((c=255)and firstchild)
then begin if p=0 then{1142:}begin if trieptr=triesize then overflow(
1354,triesize);incr(trieptr);trier[trieptr]:=p;p:=trieptr;triel[p]:=0;
if firstchild then triel[q]:=p else trier[q]:=p;triec[p]:=c;
trieo[p]:=mintrieop;end{:1142}else triec[p]:=c;
trieo[p]:=eqtb[25897+c].hh.rh;q:=p;p:=trier[q];firstchild:=false;end;
if firstchild then triel[q]:=0 else trier[q]:=0{:1854};end{:1853};
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1355);
end;printesc(1356);begin helpptr:=1;helpline[0]:=1357;end;error;
mem[memtop-12].hh.rh:=scantoks(false,false);flushlist(defref);end;end;
{:1138}{1144:}procedure inittrie;var p:triepointer;j,k,t:integer;
r,s:triepointer;begin{1130:}{1123:}opstart[0]:=-mintrieop;
for j:=1 to 255 do opstart[j]:=opstart[j-1]+trieused[j-1];
for j:=1 to trieopptr do trieophash[j]:=opstart[trieoplang[j]]+trieopval
[j];
for j:=1 to trieopptr do while trieophash[j]>j do begin k:=trieophash[j]
;t:=hyfdistance[k];hyfdistance[k]:=hyfdistance[j];hyfdistance[j]:=t;
t:=hyfnum[k];hyfnum[k]:=hyfnum[j];hyfnum[j]:=t;t:=hyfnext[k];
hyfnext[k]:=hyfnext[j];hyfnext[j]:=t;trieophash[j]:=trieophash[k];
trieophash[k]:=k;end{:1123};for p:=0 to triesize do triehash[p]:=0;
trier[0]:=compresstrie(trier[0]);triel[0]:=compresstrie(triel[0]);
for p:=0 to trieptr do triehash[p]:=0;
for p:=0 to 255 do triemin[p]:=p+1;trietrl[0]:=1;triemax:=0{:1130};
if triel[0]<>0 then begin firstfit(triel[0]);triepack(triel[0]);end;
if trier[0]<>0 then{1855:}begin if triel[0]=0 then for p:=0 to 255 do
triemin[p]:=p+2;firstfit(trier[0]);triepack(trier[0]);
hyphstart:=triehash[trier[0]];end{:1855};
{1136:}if triemax=0 then begin for r:=0 to 256 do begin trietrl[r]:=0;
trietro[r]:=mintrieop;trietrc[r]:=0;end;triemax:=256;
end else begin if trier[0]>0 then triefix(trier[0]);
if triel[0]>0 then triefix(triel[0]);r:=0;repeat s:=trietrl[r];
begin trietrl[r]:=0;trietro[r]:=mintrieop;trietrc[r]:=0;end;r:=s;
until r>triemax;end;trietrc[0]:=63;{:1136};trienotready:=false;end;
{:1144}endif('INITEX'){:1120}procedure linebreak(d:boolean);
label 30,31,32,33,34,35,22;var{1039:}q,r,s,prevs:halfword;
f:internalfontnumber;{:1039}{1071:}j:smallnumber;c:0..255;
{:1071}begin packbeginline:=curlist.mlfield;
{993:}mem[memtop-3].hh.rh:=mem[curlist.headfield].hh.rh;
if(curlist.tailfield>=himemmin)then begin mem[curlist.tailfield].hh.rh:=
newpenalty(10000);curlist.tailfield:=mem[curlist.tailfield].hh.rh;
end else if mem[curlist.tailfield].hh.b0<>10 then begin mem[curlist.
tailfield].hh.rh:=newpenalty(10000);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;
end else begin mem[curlist.tailfield].hh.b0:=12;
deleteglueref(mem[curlist.tailfield+1].hh.lh);
flushnodelist(mem[curlist.tailfield+1].hh.rh);
mem[curlist.tailfield+1].int:=10000;end;
mem[curlist.tailfield].hh.rh:=newparamglue(14);
lastlinefill:=mem[curlist.tailfield].hh.rh;
initcurlang:=curlist.pgfield mod 65536;
initlhyf:=curlist.pgfield div 4194304;
initrhyf:=(curlist.pgfield div 65536)mod 64;popnest;
{:993}{1004:}noshrinkerroryet:=true;
if(mem[eqtb[24535].hh.rh].hh.b1<>0)and(mem[eqtb[24535].hh.rh+3].int<>0)
then begin eqtb[24535].hh.rh:=finiteshrink(eqtb[24535].hh.rh);end;
if(mem[eqtb[24536].hh.rh].hh.b1<>0)and(mem[eqtb[24536].hh.rh+3].int<>0)
then begin eqtb[24536].hh.rh:=finiteshrink(eqtb[24536].hh.rh);end;
q:=eqtb[24535].hh.rh;r:=eqtb[24536].hh.rh;
background[1]:=mem[q+1].int+mem[r+1].int;background[2]:=0;
background[3]:=0;background[4]:=0;background[5]:=0;
background[2+mem[q].hh.b0]:=mem[q+2].int;
background[2+mem[r].hh.b0]:=background[2+mem[r].hh.b0]+mem[r+2].int;
background[6]:=mem[q+3].int+mem[r+3].int;
if eqtb[27256].int>1 then begin background[7]:=0;background[8]:=0;
maxstretchratio:=-1;maxshrinkratio:=-1;curfontstep:=-1;
prevcharp:=-268435455;end;{1841:}dolastlinefit:=false;activenodesize:=3;
if eqtb[27276].int>0 then begin q:=mem[lastlinefill+1].hh.lh;
if(mem[q+2].int>0)and(mem[q].hh.b0>0)then if(background[3]=0)and(
background[4]=0)and(background[5]=0)then begin dolastlinefit:=true;
activenodesize:=5;fillwidth[0]:=0;fillwidth[1]:=0;fillwidth[2]:=0;
fillwidth[mem[q].hh.b0-1]:=mem[q+2].int;end;end{:1841};
{:1004}{1011:}minimumdemerits:=1073741823;
minimaldemerits[3]:=1073741823;minimaldemerits[2]:=1073741823;
minimaldemerits[1]:=1073741823;minimaldemerits[0]:=1073741823;
{:1011}{1025:}if eqtb[25058].hh.rh=-268435455 then if eqtb[27810].int=0
then begin lastspecialline:=0;secondwidth:=eqtb[27796].int;
secondindent:=0;
end else{1026:}begin lastspecialline:=abs(eqtb[27218].int);
if eqtb[27218].int<0 then begin firstwidth:=eqtb[27796].int-abs(eqtb[
27810].int);
if eqtb[27810].int>=0 then firstindent:=eqtb[27810].int else firstindent
:=0;secondwidth:=eqtb[27796].int;secondindent:=0;
end else begin firstwidth:=eqtb[27796].int;firstindent:=0;
secondwidth:=eqtb[27796].int-abs(eqtb[27810].int);
if eqtb[27810].int>=0 then secondindent:=eqtb[27810].int else
secondindent:=0;end;
end{:1026}else begin lastspecialline:=mem[eqtb[25058].hh.rh].hh.lh-1;
secondwidth:=mem[eqtb[25058].hh.rh+2*(lastspecialline+1)].int;
secondindent:=mem[eqtb[25058].hh.rh+2*lastspecialline+1].int;end;
if eqtb[27196].int=0 then easyline:=lastspecialline else easyline:=
268435455{:1025};{1040:}threshold:=eqtb[27177].int;
if threshold>=0 then begin ifdef('STAT')if eqtb[27209].int>0 then begin
begindiagnostic;printnl(1336);end;endif('STAT')secondpass:=false;
finalpass:=false;end else begin threshold:=eqtb[27178].int;
secondpass:=true;finalpass:=(eqtb[27813].int<=0);
ifdef('STAT')if eqtb[27209].int>0 then begindiagnostic;endif('STAT')end;
while true do begin if threshold>10000 then threshold:=10000;
if secondpass then{1069:}begin ifdef('INITEX')if trienotready then
inittrie;endif('INITEX')curlang:=initcurlang;lhyf:=initlhyf;
rhyf:=initrhyf;
if trietrc[hyphstart+curlang]<>curlang then hyphindex:=0 else hyphindex
:=trietrl[hyphstart+curlang];end{:1069};
{1041:}q:=getnode(activenodesize);mem[q].hh.b0:=0;mem[q].hh.b1:=2;
mem[q].hh.rh:=memtop-7;mem[q+1].hh.rh:=-268435455;
mem[q+1].hh.lh:=curlist.pgfield+1;mem[q+2].int:=0;
mem[memtop-7].hh.rh:=q;
if dolastlinefit then{1843:}begin mem[q+3].int:=0;mem[q+4].int:=0;
end{:1843};activewidth[1]:=background[1];activewidth[2]:=background[2];
activewidth[3]:=background[3];activewidth[4]:=background[4];
activewidth[5]:=background[5];activewidth[6]:=background[6];
if eqtb[27256].int>1 then begin activewidth[7]:=background[7];
activewidth[8]:=background[8];end;passive:=-268435455;
printednode:=memtop-3;passnumber:=0;fontinshortdisplay:=0{:1041};
curp:=mem[memtop-3].hh.rh;autobreaking:=true;prevp:=curp;
prevcharp:=-268435455;prevlegal:=-268435455;rejectedcurp:=-268435455;
tryprevbreak:=false;beforerejectedcurp:=false;firstp:=curp;
while(curp<>-268435455)and(mem[memtop-7].hh.rh<>memtop-7)do{1043:}begin
if(curp>=himemmin)then{1044:}begin prevp:=curp;
repeat f:=mem[curp].hh.b0;
activewidth[1]:=activewidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f
]+effectivechar(true,f,mem[curp].hh.b1)].qqqq.b0].int;
if(eqtb[27256].int>1)and checkexpandpars(f)then begin prevcharp:=curp;
activewidth[7]:=activewidth[7]+charstretch(f,mem[curp].hh.b1);
activewidth[8]:=activewidth[8]+charshrink(f,mem[curp].hh.b1);end;
curp:=mem[curp].hh.rh;until not(curp>=himemmin);end{:1044};
case mem[curp].hh.b0 of 0,1,2:activewidth[1]:=activewidth[1]+mem[curp+1]
.int;
8:{1607:}begin if mem[curp].hh.b1=4 then begin curlang:=mem[curp+1].hh.
rh;lhyf:=mem[curp+1].hh.b0;rhyf:=mem[curp+1].hh.b1;end;
if(mem[curp].hh.b1=10)or(mem[curp].hh.b1=12)then activewidth[1]:=
activewidth[1]+mem[curp+1].int;end{:1607};
10:begin{1045:}if autobreaking then begin if(prevp>=himemmin)then
trybreak(0,0)else if(mem[prevp].hh.b0<9)then trybreak(0,0)else if(mem[
prevp].hh.b0=11)and(mem[prevp].hh.b1<>1)then trybreak(0,0);end;
if(mem[mem[curp+1].hh.lh].hh.b1<>0)and(mem[mem[curp+1].hh.lh+3].int<>0)
then begin mem[curp+1].hh.lh:=finiteshrink(mem[curp+1].hh.lh);end;
q:=mem[curp+1].hh.lh;activewidth[1]:=activewidth[1]+mem[q+1].int;
activewidth[2+mem[q].hh.b0]:=activewidth[2+mem[q].hh.b0]+mem[q+2].int;
activewidth[6]:=activewidth[6]+mem[q+3].int{:1045};
if secondpass and autobreaking then{1072:}begin prevs:=curp;
s:=mem[prevs].hh.rh;
if s<>-268435455 then begin{1074:}while true do begin if(s>=himemmin)
then begin c:=mem[s].hh.b1;hf:=mem[s].hh.b0;
end else if mem[s].hh.b0=6 then if mem[s+1].hh.rh=-268435455 then goto
22 else begin q:=mem[s+1].hh.rh;c:=mem[q].hh.b1;hf:=mem[q].hh.b0;
end else if(mem[s].hh.b0=11)and(mem[s].hh.b1=0)then goto 22 else if(mem[
s].hh.b0=9)and(mem[s].hh.b1>=4)then goto 22 else if mem[s].hh.b0=8 then
begin{1608:}if mem[s].hh.b1=4 then begin curlang:=mem[s+1].hh.rh;
lhyf:=mem[s+1].hh.b0;rhyf:=mem[s+1].hh.b1;
if trietrc[hyphstart+curlang]<>curlang then hyphindex:=0 else hyphindex
:=trietrl[hyphstart+curlang];end{:1608};goto 22;end else goto 31;
if hyphindex=0 then hc[0]:=eqtb[25897+c].hh.rh else if trietrc[hyphindex
+c]<>c then hc[0]:=0 else hc[0]:=trietro[hyphindex+c];
if hc[0]<>0 then if(hc[0]=c)or(eqtb[27215].int>0)then goto 32 else goto
31;22:prevs:=s;s:=mem[prevs].hh.rh;end;32:hyfchar:=hyphenchar[hf];
if hyfchar<0 then goto 31;if hyfchar>255 then goto 31;ha:=prevs{:1074};
if lhyf+rhyf>63 then goto 31;{1075:}hn:=0;
while true do begin if(s>=himemmin)then begin if mem[s].hh.b0<>hf then
goto 33;hyfbchar:=mem[s].hh.b1;c:=hyfbchar;
if hyphindex=0 then hc[0]:=eqtb[25897+c].hh.rh else if trietrc[hyphindex
+c]<>c then hc[0]:=0 else hc[0]:=trietro[hyphindex+c];
if hc[0]=0 then goto 33;if hn=63 then goto 33;hb:=s;incr(hn);hu[hn]:=c;
hc[hn]:=hc[0];hyfbchar:=256;
end else if mem[s].hh.b0=6 then{1076:}begin if mem[s+1].hh.b0<>hf then
goto 33;j:=hn;q:=mem[s+1].hh.rh;
if q>-268435455 then hyfbchar:=mem[q].hh.b1;
while q>-268435455 do begin c:=mem[q].hh.b1;
if hyphindex=0 then hc[0]:=eqtb[25897+c].hh.rh else if trietrc[hyphindex
+c]<>c then hc[0]:=0 else hc[0]:=trietro[hyphindex+c];
if hc[0]=0 then goto 33;if j=63 then goto 33;incr(j);hu[j]:=c;
hc[j]:=hc[0];q:=mem[q].hh.rh;end;hb:=s;hn:=j;
if odd(mem[s].hh.b1)then hyfbchar:=fontbchar[hf]else hyfbchar:=256;
end{:1076}else if(mem[s].hh.b0=11)and(mem[s].hh.b1=0)then begin hb:=s;
hyfbchar:=fontbchar[hf];end else goto 33;s:=mem[s].hh.rh;end;33:{:1075};
{1077:}if hn<lhyf+rhyf then goto 31;
while true do begin if not((s>=himemmin))then case mem[s].hh.b0 of 6:;
11:if mem[s].hh.b1<>0 then goto 34;8,10,12,3,5,4:goto 34;
9:if mem[s].hh.b1>=4 then goto 34 else goto 31;others:goto 31 end;
s:=mem[s].hh.rh;end;34:{:1077};hyphenate;end;31:end{:1072};end;
11:if mem[curp].hh.b1=1 then begin if not(mem[curp].hh.rh>=himemmin)and
autobreaking then if mem[mem[curp].hh.rh].hh.b0=10 then trybreak(0,0);
activewidth[1]:=activewidth[1]+mem[curp+1].int;
end else begin activewidth[1]:=activewidth[1]+mem[curp+1].int;
if(eqtb[27256].int>1)and(mem[curp].hh.b1=0)then begin activewidth[7]:=
activewidth[7]+kernstretch(curp);
activewidth[8]:=activewidth[8]+kernshrink(curp);end;end;
6:begin f:=mem[curp+1].hh.b0;
activewidth[1]:=activewidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f
]+effectivechar(true,f,mem[curp+1].hh.b1)].qqqq.b0].int;
if(eqtb[27256].int>1)and checkexpandpars(f)then begin prevcharp:=curp;
activewidth[7]:=activewidth[7]+charstretch(f,mem[curp+1].hh.b1);
activewidth[8]:=activewidth[8]+charshrink(f,mem[curp+1].hh.b1);end;end;
7:{1046:}begin s:=mem[curp+1].hh.lh;discwidth[1]:=0;
if eqtb[27256].int>1 then begin discwidth[7]:=0;discwidth[8]:=0;end;
if s=-268435455 then trybreak(eqtb[27181].int,1)else begin repeat{1047:}
if(s>=himemmin)then begin f:=mem[s].hh.b0;
discwidth[1]:=discwidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[s].hh.b1)].qqqq.b0].int;
if(eqtb[27256].int>1)and checkexpandpars(f)then begin prevcharp:=s;
discwidth[7]:=discwidth[7]+charstretch(f,mem[s].hh.b1);
discwidth[8]:=discwidth[8]+charshrink(f,mem[s].hh.b1);end;
end else case mem[s].hh.b0 of 6:begin f:=mem[s+1].hh.b0;
discwidth[1]:=discwidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[s+1].hh.b1)].qqqq.b0].int;
if(eqtb[27256].int>1)and checkexpandpars(f)then begin prevcharp:=s;
discwidth[7]:=discwidth[7]+charstretch(f,mem[s+1].hh.b1);
discwidth[8]:=discwidth[8]+charshrink(f,mem[s+1].hh.b1);end;end;
0,1,2,11:begin discwidth[1]:=discwidth[1]+mem[s+1].int;
if(mem[s].hh.b0=11)and(eqtb[27256].int>1)and(mem[s].hh.b1=0)then begin
discwidth[7]:=discwidth[7]+kernstretch(s);
discwidth[8]:=discwidth[8]+kernshrink(s);end;end;
others:confusion(1340)end{:1047};s:=mem[s].hh.rh;until s=-268435455;
activewidth[1]:=activewidth[1]+discwidth[1];
if eqtb[27256].int>1 then begin activewidth[7]:=activewidth[7]+discwidth
[7];activewidth[8]:=activewidth[8]+discwidth[8];end;
trybreak(eqtb[27180].int,1);activewidth[1]:=activewidth[1]-discwidth[1];
if eqtb[27256].int>1 then begin activewidth[7]:=activewidth[7]-discwidth
[7];activewidth[8]:=activewidth[8]-discwidth[8];end;end;
r:=mem[curp].hh.b1;s:=mem[curp].hh.rh;
while r>0 do begin{1048:}if(s>=himemmin)then begin f:=mem[s].hh.b0;
activewidth[1]:=activewidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f
]+effectivechar(true,f,mem[s].hh.b1)].qqqq.b0].int;
if(eqtb[27256].int>1)and checkexpandpars(f)then begin prevcharp:=s;
activewidth[7]:=activewidth[7]+charstretch(f,mem[s].hh.b1);
activewidth[8]:=activewidth[8]+charshrink(f,mem[s].hh.b1);end;
end else case mem[s].hh.b0 of 6:begin f:=mem[s+1].hh.b0;
activewidth[1]:=activewidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f
]+effectivechar(true,f,mem[s+1].hh.b1)].qqqq.b0].int;
if(eqtb[27256].int>1)and checkexpandpars(f)then begin prevcharp:=s;
activewidth[7]:=activewidth[7]+charstretch(f,mem[s+1].hh.b1);
activewidth[8]:=activewidth[8]+charshrink(f,mem[s+1].hh.b1);end;end;
0,1,2,11:begin activewidth[1]:=activewidth[1]+mem[s+1].int;
if(mem[s].hh.b0=11)and(eqtb[27256].int>1)and(mem[s].hh.b1=0)then begin
activewidth[7]:=activewidth[7]+kernstretch(s);
activewidth[8]:=activewidth[8]+kernshrink(s);end;end;
others:confusion(1341)end{:1048};decr(r);s:=mem[s].hh.rh;end;
prevp:=curp;curp:=s;goto 35;end{:1046};
9:begin if mem[curp].hh.b1<4 then autobreaking:=odd(mem[curp].hh.b1);
begin if not(mem[curp].hh.rh>=himemmin)and autobreaking then if mem[mem[
curp].hh.rh].hh.b0=10 then trybreak(0,0);
activewidth[1]:=activewidth[1]+mem[curp+1].int;end;end;
12:trybreak(mem[curp+1].int,0);4,3,5:;others:confusion(1339)end;
prevp:=curp;curp:=mem[curp].hh.rh;35:end{:1043};
if curp=-268435455 then{1050:}begin trybreak(-10000,1);
if mem[memtop-7].hh.rh<>memtop-7 then begin{1051:}r:=mem[memtop-7].hh.rh
;fewestdemerits:=1073741823;
repeat if mem[r].hh.b0<>2 then if mem[r+2].int<fewestdemerits then begin
fewestdemerits:=mem[r+2].int;bestbet:=r;end;r:=mem[r].hh.rh;
until r=memtop-7;bestline:=mem[bestbet+1].hh.lh{:1051};
if eqtb[27196].int=0 then goto 30;{1052:}begin r:=mem[memtop-7].hh.rh;
actuallooseness:=0;
repeat if mem[r].hh.b0<>2 then begin linediff:=mem[r+1].hh.lh-bestline;
if((linediff<actuallooseness)and(eqtb[27196].int<=linediff))or((linediff
>actuallooseness)and(eqtb[27196].int>=linediff))then begin bestbet:=r;
actuallooseness:=linediff;fewestdemerits:=mem[r+2].int;
end else if(linediff=actuallooseness)and(mem[r+2].int<fewestdemerits)
then begin bestbet:=r;fewestdemerits:=mem[r+2].int;end;end;
r:=mem[r].hh.rh;until r=memtop-7;bestline:=mem[bestbet+1].hh.lh;
end{:1052};if(actuallooseness=eqtb[27196].int)or finalpass then goto 30;
end;end{:1050};{1042:}q:=mem[memtop-7].hh.rh;
while q<>memtop-7 do begin curp:=mem[q].hh.rh;
if mem[q].hh.b0=2 then freenode(q,9)else freenode(q,activenodesize);
q:=curp;end;q:=passive;while q<>-268435455 do begin curp:=mem[q].hh.rh;
freenode(q,2);q:=curp;end{:1042};
if not secondpass then begin ifdef('STAT')if eqtb[27209].int>0 then
printnl(1337);endif('STAT')threshold:=eqtb[27178].int;secondpass:=true;
finalpass:=(eqtb[27813].int<=0);
end else begin ifdef('STAT')if eqtb[27209].int>0 then printnl(1338);
endif('STAT')background[2]:=background[2]+eqtb[27813].int;
finalpass:=true;end;end;
30:ifdef('STAT')if eqtb[27209].int>0 then begin enddiagnostic(true);
normalizeselector;end;
endif('STAT')if dolastlinefit then{1851:}if mem[bestbet+3].int=0 then
dolastlinefit:=false else begin q:=newspec(mem[lastlinefill+1].hh.lh);
deleteglueref(mem[lastlinefill+1].hh.lh);
mem[q+1].int:=mem[q+1].int+mem[bestbet+3].int-mem[bestbet+4].int;
mem[q+2].int:=0;mem[lastlinefill+1].hh.lh:=q;end{:1851};{:1040};
{1053:}postlinebreak(d){:1053};{1042:}q:=mem[memtop-7].hh.rh;
while q<>memtop-7 do begin curp:=mem[q].hh.rh;
if mem[q].hh.b0=2 then freenode(q,9)else freenode(q,activenodesize);
q:=curp;end;q:=passive;while q<>-268435455 do begin curp:=mem[q].hh.rh;
freenode(q,2);q:=curp;end{:1042};packbeginline:=0;end;
{1654:}function eTeXenabled(b:boolean;j:quarterword;k:halfword):boolean;
begin if not b then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(782);
end;printcmdchr(j,k);begin helpptr:=1;helpline[0]:=1959;end;error;end;
eTeXenabled:=b;end;{:1654}{1677:}procedure showsavegroups;
label 41,42,40,30;var p:0..nestsize;m:-207..207;v:savepointer;
l:quarterword;c:groupcode;a:-1..1;i:integer;j:quarterword;s:strnumber;
begin p:=nestptr;nest[p]:=curlist;v:=saveptr;l:=curlevel;c:=curgroup;
saveptr:=curboundary;decr(curlevel);a:=1;printnl(345);println;
while true do begin printnl(379);printgroup(true);
if curgroup=0 then goto 30;repeat m:=nest[p].modefield;
if p>0 then decr(p)else m:=1;until m<>104;print(286);
case curgroup of 1:begin incr(p);goto 42;end;2,3:s:=1463;4:s:=1372;
5:s:=1462;6:if a=0 then begin if m=-1 then s:=597 else s:=616;a:=1;
goto 41;end else begin if a=1 then print(1997)else printesc(1298);
if p>=a then p:=p-a;a:=0;goto 40;end;7:begin incr(p);a:=-1;
printesc(604);goto 42;end;8:begin printesc(414);goto 40;end;9:goto 42;
10,13:begin if curgroup=10 then printesc(357)else printesc(602);
for i:=1 to 3 do if i<=savestack[saveptr-2].int then print(1258);
goto 42;end;
11:begin if savestack[saveptr-2].int=255 then printesc(360)else begin
printesc(337);printint(savestack[saveptr-2].int);end;goto 42;end;
12:begin s:=617;goto 41;end;14:begin incr(p);printesc(586);goto 40;end;
15:begin if m=207 then printchar(36)else if nest[p].modefield=207 then
begin printcmdchr(48,savestack[saveptr-2].int);goto 40;end;
printchar(36);goto 40;end;
16:begin if mem[nest[p+1].eTeXauxfield].hh.b0=30 then printesc(1274)else
printesc(1276);goto 40;end;end;{1679:}i:=savestack[saveptr-4].int;
if i<>0 then if i<1073741824 then begin if abs(nest[p].modefield)=1 then
j:=21 else j:=22;if i>0 then printcmdchr(j,0)else printcmdchr(j,1);
printscaled(abs(i));print(312);
end else if i<1073807360 then begin if i>=1073774592 then begin printesc
(1580);i:=i-(32768);end;printesc(614);printint(i-1073741824);
printchar(61);end else printcmdchr(31,i-(1073807261)){:1679};
41:printesc(s);
{1678:}if savestack[saveptr-2].int<>0 then begin printchar(32);
if savestack[saveptr-3].int=0 then print(1234)else print(1235);
printscaled(savestack[saveptr-2].int);print(312);end{:1678};
42:printchar(123);40:printchar(41);decr(curlevel);
curgroup:=savestack[saveptr].hh.b1;
saveptr:=savestack[saveptr].hh.rh end;30:saveptr:=v;curlevel:=l;
curgroup:=c;end;{:1677}{1693:}procedure newinteraction;forward;
{:1693}{:992}{1112:}procedure newhyphexceptions;label 21,10,40,45,46;
var n:0..64;j:0..64;h:hyphpointer;k:strnumber;p:halfword;q:halfword;
s:strnumber;u,v:poolpointer;begin scanleftbrace;
if eqtb[27227].int<=0 then curlang:=0 else if eqtb[27227].int>255 then
curlang:=0 else curlang:=eqtb[27227].int;
ifdef('INITEX')if trienotready then begin hyphindex:=0;goto 46;end;
endif('INITEX')if trietrc[hyphstart+curlang]<>curlang then hyphindex:=0
else hyphindex:=trietrl[hyphstart+curlang];46:{1113:}n:=0;p:=-268435455;
while true do begin getxtoken;
21:case curcmd of 11,12,68:{1115:}if curchr=45 then{1116:}begin if n<63
then begin q:=getavail;mem[q].hh.rh:=p;mem[q].hh.lh:=n;p:=q;end;
end{:1116}else begin if hyphindex=0 then hc[0]:=eqtb[25897+curchr].hh.rh
else if trietrc[hyphindex+curchr]<>curchr then hc[0]:=0 else hc[0]:=
trietro[hyphindex+curchr];
if hc[0]=0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1348);
end;begin helpptr:=2;helpline[1]:=1349;helpline[0]:=1350;end;error;
end else if n<63 then begin incr(n);hc[n]:=hc[0];end;end{:1115};
16:begin scancharnum;curchr:=curval;curcmd:=68;goto 21;end;
10,2:begin if n>1 then{1117:}begin incr(n);hc[n]:=curlang;
begin if poolptr+n>poolsize then overflow(259,poolsize-initpoolptr);end;
h:=0;for j:=1 to n do begin h:=(h+h+hc[j])mod 607;
begin strpool[poolptr]:=hc[j];incr(poolptr);end;end;s:=makestring;
{1118:}if hyphnext<=607 then while(hyphnext>0)and(hyphword[hyphnext-1]>0
)do decr(hyphnext);
if(hyphcount=hyphsize)or(hyphnext=0)then overflow(1351,hyphsize);
incr(hyphcount);while hyphword[h]<>0 do begin{1119:}k:=hyphword[h];
if(strstart[k+1]-strstart[k])<>(strstart[s+1]-strstart[s])then goto 45;
u:=strstart[k];v:=strstart[s];
repeat if strpool[u]<>strpool[v]then goto 45;incr(u);incr(v);
until u=strstart[k+1];begin decr(strptr);poolptr:=strstart[strptr];end;
s:=hyphword[h];decr(hyphcount);goto 40;45:{:1119};
if hyphlink[h]=0 then begin hyphlink[h]:=hyphnext;
if hyphnext>=hyphsize then hyphnext:=607;
if hyphnext>607 then incr(hyphnext);end;h:=hyphlink[h]-1;end;
40:hyphword[h]:=s;hyphlist[h]:=p{:1118};end{:1117};
if curcmd=2 then goto 10;n:=0;p:=-268435455;end;
others:{1114:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(782);
end;printesc(1344);print(1345);begin helpptr:=2;helpline[1]:=1346;
helpline[0]:=1347;end;error;end{:1114}end;end{:1113};10:end;
{:1112}{1146:}function prunepagetop(p:halfword;s:boolean):halfword;
label 60;var prevp:halfword;q,r:halfword;begin prevp:=memtop-3;
mem[memtop-3].hh.rh:=p;
while p<>-268435455 do case mem[p].hh.b0 of 0,1,2:{1147:}begin q:=
newskipparam(10);mem[prevp].hh.rh:=q;mem[q].hh.rh:=p;
if mem[tempptr+1].int>mem[p+3].int then mem[tempptr+1].int:=mem[tempptr
+1].int-mem[p+3].int else mem[tempptr+1].int:=0;p:=-268435455;
end{:1147};
8,4,3:begin if(mem[p].hh.b0=8)and((mem[p].hh.b1=35)or(mem[p].hh.b1=36))
then begin print(1362);goto 60;end;prevp:=p;p:=mem[prevp].hh.rh;end;
10,11,12:begin 60:{print(1363);shownodelist(p);println;}q:=p;
p:=mem[q].hh.rh;mem[q].hh.rh:=-268435455;mem[prevp].hh.rh:=p;
if s then begin if discptr[3]=-268435455 then discptr[3]:=q else mem[r].
hh.rh:=q;r:=q;end else flushnodelist(q);end;others:confusion(1364)end;
prunepagetop:=mem[memtop-3].hh.rh;end;
{:1146}{1148:}function vertbreak(p:halfword;h,d:scaled):halfword;
label 30,45,90;var prevp:halfword;q,r:halfword;pi:integer;b:integer;
leastcost:integer;bestplace:halfword;prevdp:scaled;t:smallnumber;
begin prevp:=p;leastcost:=1073741823;activewidth[1]:=0;
activewidth[2]:=0;activewidth[3]:=0;activewidth[4]:=0;activewidth[5]:=0;
activewidth[6]:=0;prevdp:=0;
while true do begin{1150:}if p=-268435455 then pi:=-10000 else{1151:}
case mem[p].hh.b0 of 0,1,2:begin activewidth[1]:=activewidth[1]+prevdp+
mem[p+3].int;prevdp:=mem[p+2].int;goto 45;end;
8:{1610:}begin if(mem[p].hh.b1=10)or(mem[p].hh.b1=12)then begin
activewidth[1]:=activewidth[1]+prevdp+mem[p+2].int;prevdp:=mem[p+3].int;
end;goto 45;end{:1610};10:if(mem[prevp].hh.b0<9)then pi:=0 else goto 90;
11:begin if mem[p].hh.rh=-268435455 then t:=12 else t:=mem[mem[p].hh.rh]
.hh.b0;if t=10 then pi:=0 else goto 90;end;12:pi:=mem[p+1].int;
4,3:goto 45;others:confusion(1365)end{:1151};
{1152:}if pi<10000 then begin{1153:}if activewidth[1]<h then if(
activewidth[3]<>0)or(activewidth[4]<>0)or(activewidth[5]<>0)then b:=0
else b:=badness(h-activewidth[1],activewidth[2])else if activewidth[1]-h
>activewidth[6]then b:=1073741823 else b:=badness(activewidth[1]-h,
activewidth[6]){:1153};
if b<1073741823 then if pi<=-10000 then b:=pi else if b<10000 then b:=b+
pi else b:=100000;if b<=leastcost then begin bestplace:=p;leastcost:=b;
bestheightplusdepth:=activewidth[1]+prevdp;end;
if(b=1073741823)or(pi<=-10000)then goto 30;end{:1152};
if(mem[p].hh.b0<10)or(mem[p].hh.b0>11)then goto 45;
90:{1154:}if mem[p].hh.b0=11 then q:=p else begin q:=mem[p+1].hh.lh;
activewidth[2+mem[q].hh.b0]:=activewidth[2+mem[q].hh.b0]+mem[q+2].int;
activewidth[6]:=activewidth[6]+mem[q+3].int;
if(mem[q].hh.b1<>0)and(mem[q+3].int<>0)then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(264);
print(1366);end;begin helpptr:=4;helpline[3]:=1367;helpline[2]:=1368;
helpline[1]:=1369;helpline[0]:=1321;end;error;r:=newspec(q);
mem[r].hh.b1:=0;deleteglueref(q);mem[p+1].hh.lh:=r;q:=r;end;end;
activewidth[1]:=activewidth[1]+prevdp+mem[q+1].int;prevdp:=0{:1154};
45:if prevdp>d then begin activewidth[1]:=activewidth[1]+prevdp-d;
prevdp:=d;end;{:1150};prevp:=p;p:=mem[prevp].hh.rh;end;
30:vertbreak:=bestplace;end;
{:1148}{1155:}{1823:}function domarks(a,l:smallnumber;
q:halfword):boolean;var i:smallnumber;
begin if l<4 then begin for i:=0 to 15 do begin if odd(i)then curptr:=
mem[q+(i div 2)+1].hh.rh else curptr:=mem[q+(i div 2)+1].hh.lh;
if curptr<>-268435455 then if domarks(a,l+1,curptr)then begin if odd(i)
then mem[q+(i div 2)+1].hh.rh:=-268435455 else mem[q+(i div 2)+1].hh.lh
:=-268435455;decr(mem[q].hh.b1);end;end;
if mem[q].hh.b1=0 then begin freenode(q,9);q:=-268435455;end;
end else begin case a of{1824:}0:if mem[q+2].hh.rh<>-268435455 then
begin deletetokenref(mem[q+2].hh.rh);mem[q+2].hh.rh:=-268435455;
deletetokenref(mem[q+3].hh.lh);mem[q+3].hh.lh:=-268435455;end;
{:1824}{1826:}1:if mem[q+2].hh.lh<>-268435455 then begin if mem[q+1].hh.
lh<>-268435455 then deletetokenref(mem[q+1].hh.lh);
deletetokenref(mem[q+1].hh.rh);mem[q+1].hh.rh:=-268435455;
if mem[mem[q+2].hh.lh].hh.rh=-268435455 then begin deletetokenref(mem[q
+2].hh.lh);mem[q+2].hh.lh:=-268435455;
end else incr(mem[mem[q+2].hh.lh].hh.lh);mem[q+1].hh.lh:=mem[q+2].hh.lh;
end;{:1826}{1827:}2:if(mem[q+1].hh.lh<>-268435455)and(mem[q+1].hh.rh=
-268435455)then begin mem[q+1].hh.rh:=mem[q+1].hh.lh;
incr(mem[mem[q+1].hh.lh].hh.lh);end;
{:1827}{1829:}ifdef('INITEX')3:for i:=0 to 4 do begin if odd(i)then
curptr:=mem[q+(i div 2)+1].hh.rh else curptr:=mem[q+(i div 2)+1].hh.lh;
if curptr<>-268435455 then begin deletetokenref(curptr);
if odd(i)then mem[q+(i div 2)+1].hh.rh:=-268435455 else mem[q+(i div 2)
+1].hh.lh:=-268435455;end;end;endif('INITEX'){:1829}end;
if mem[q+2].hh.lh=-268435455 then if mem[q+3].hh.lh=-268435455 then
begin freenode(q,4);q:=-268435455;end;end;domarks:=(q=-268435455);end;
{:1823}function vsplit(n:halfword;h:scaled):halfword;label 10,30;
var v:halfword;p:halfword;q:halfword;begin curval:=n;
if curval<256 then v:=eqtb[25333+curval].hh.rh else begin findsaelement(
4,curval,false);
if curptr=-268435455 then v:=-268435455 else v:=mem[curptr+1].hh.rh;end;
flushnodelist(discptr[3]);discptr[3]:=-268435455;
if saroot[6]<>-268435455 then if domarks(0,0,saroot[6])then saroot[6]:=
-268435455;
if curmark[3]<>-268435455 then begin deletetokenref(curmark[3]);
curmark[3]:=-268435455;deletetokenref(curmark[4]);
curmark[4]:=-268435455;end;
{1156:}if v=-268435455 then begin vsplit:=-268435455;goto 10;end;
if mem[v].hh.b0<>1 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(345);
end;printesc(1370);print(1371);printesc(1372);begin helpptr:=2;
helpline[1]:=1373;helpline[0]:=1374;end;error;vsplit:=-268435455;
goto 10;end{:1156};q:=vertbreak(mem[v+5].hh.rh,h,eqtb[27799].int);
{1157:}p:=mem[v+5].hh.rh;
if p=q then mem[v+5].hh.rh:=-268435455 else while true do begin if mem[p
].hh.b0=4 then if mem[p+1].hh.lh<>0 then{1825:}begin findsaelement(6,mem
[p+1].hh.lh,true);
if mem[curptr+2].hh.rh=-268435455 then begin mem[curptr+2].hh.rh:=mem[p
+1].hh.rh;incr(mem[mem[p+1].hh.rh].hh.lh);
end else deletetokenref(mem[curptr+3].hh.lh);
mem[curptr+3].hh.lh:=mem[p+1].hh.rh;incr(mem[mem[p+1].hh.rh].hh.lh);
end{:1825}else if curmark[3]=-268435455 then begin curmark[3]:=mem[p+1].
hh.rh;curmark[4]:=curmark[3];
mem[curmark[3]].hh.lh:=mem[curmark[3]].hh.lh+2;
end else begin deletetokenref(curmark[4]);curmark[4]:=mem[p+1].hh.rh;
incr(mem[curmark[4]].hh.lh);end;
if mem[p].hh.rh=q then begin mem[p].hh.rh:=-268435455;goto 30;end;
p:=mem[p].hh.rh;end;30:{:1157};q:=prunepagetop(q,eqtb[27277].int>0);
p:=mem[v+5].hh.rh;freenode(v,9);
if q<>-268435455 then q:=vpackage(q,0,1,1073741823);
if curval<256 then eqtb[25333+curval].hh.rh:=q else begin findsaelement(
4,curval,false);if curptr<>-268435455 then begin mem[curptr+1].hh.rh:=q;
incr(mem[curptr+1].hh.lh);deletesaref(curptr);end;end;
vsplit:=vpackage(p,h,0,eqtb[27799].int);10:end;
{:1155}{1163:}procedure printtotals;begin printscaled(pagesofar[1]);
if pagesofar[2]<>0 then begin print(317);printscaled(pagesofar[2]);
print(345);end;if pagesofar[3]<>0 then begin print(317);
printscaled(pagesofar[3]);print(316);end;
if pagesofar[4]<>0 then begin print(317);printscaled(pagesofar[4]);
print(1383);end;if pagesofar[5]<>0 then begin print(317);
printscaled(pagesofar[5]);print(1384);end;
if pagesofar[6]<>0 then begin print(318);printscaled(pagesofar[6]);end;
end;{:1163}{1165:}procedure freezepagespecs(s:smallnumber);
begin pagecontents:=s;pagesofar[0]:=eqtb[27797].int;
pagemaxdepth:=eqtb[27798].int;pagesofar[7]:=0;pagesofar[1]:=0;
pagesofar[2]:=0;pagesofar[3]:=0;pagesofar[4]:=0;pagesofar[5]:=0;
pagesofar[6]:=0;leastpagecost:=1073741823;
ifdef('STAT')if eqtb[27210].int>0 then begin begindiagnostic;
printnl(1392);printscaled(pagesofar[0]);print(1393);
printscaled(pagemaxdepth);enddiagnostic(false);end;endif('STAT')end;
{:1165}{1170:}procedure boxerror(n:eightbits);begin error;
begindiagnostic;printnl(995);showbox(eqtb[25333+n].hh.rh);
enddiagnostic(true);flushnodelist(eqtb[25333+n].hh.rh);
eqtb[25333+n].hh.rh:=-268435455;end;
{:1170}{1171:}procedure ensurevbox(n:eightbits);var p:halfword;
begin p:=eqtb[25333+n].hh.rh;
if p<>-268435455 then if mem[p].hh.b0=0 then begin begin if interaction=
3 then;if filelineerrorstylep then printfileline else printnl(264);
print(1394);end;begin helpptr:=3;helpline[2]:=1395;helpline[1]:=1396;
helpline[0]:=1397;end;boxerror(n);end;end;
{:1171}{1172:}{1190:}procedure fireup(c:halfword);label 10;
var p,q,r,s:halfword;prevp:halfword;n:0..255;wait:boolean;
savevbadness:integer;savevfuzz:scaled;savesplittopskip:halfword;
begin{1191:}if mem[bestpagebreak].hh.b0=12 then begin geqworddefine(
27216,mem[bestpagebreak+1].int);mem[bestpagebreak+1].int:=10000;
end else geqworddefine(27216,10000){:1191};
if saroot[6]<>-268435455 then if domarks(1,0,saroot[6])then saroot[6]:=
-268435455;
if curmark[2]<>-268435455 then begin if curmark[0]<>-268435455 then
deletetokenref(curmark[0]);curmark[0]:=curmark[2];
incr(mem[curmark[0]].hh.lh);deletetokenref(curmark[1]);
curmark[1]:=-268435455;end;
{1192:}if c=bestpagebreak then bestpagebreak:=-268435455;
{1193:}if eqtb[25588].hh.rh<>-268435455 then begin begin if interaction=
3 then;if filelineerrorstylep then printfileline else printnl(264);
print(345);end;printesc(429);print(1407);begin helpptr:=2;
helpline[1]:=1408;helpline[0]:=1397;end;boxerror(255);end{:1193};
insertpenalties:=0;savesplittopskip:=eqtb[24538].hh.rh;
if eqtb[27230].int<=0 then{1196:}begin r:=mem[memtop].hh.rh;
while r<>memtop do begin if mem[r+2].hh.lh<>-268435455 then begin n:=mem
[r].hh.b1;ensurevbox(n);
if eqtb[25333+n].hh.rh=-268435455 then eqtb[25333+n].hh.rh:=newnullbox;
p:=eqtb[25333+n].hh.rh+5;
while mem[p].hh.rh<>-268435455 do p:=mem[p].hh.rh;mem[r+2].hh.rh:=p;end;
r:=mem[r].hh.rh;end;end{:1196};q:=memtop-4;mem[q].hh.rh:=-268435455;
prevp:=memtop-2;p:=mem[prevp].hh.rh;
while p<>bestpagebreak do begin if mem[p].hh.b0=3 then begin if eqtb[
27230].int<=0 then{1198:}begin r:=mem[memtop].hh.rh;
while mem[r].hh.b1<>mem[p].hh.b1 do r:=mem[r].hh.rh;
if mem[r+2].hh.lh=-268435455 then wait:=true else begin wait:=false;
s:=mem[r+2].hh.rh;mem[s].hh.rh:=mem[p+4].hh.lh;
if mem[r+2].hh.lh=p then{1199:}begin if mem[r].hh.b0=1 then if(mem[r+1].
hh.lh=p)and(mem[r+1].hh.rh<>-268435455)then begin while mem[s].hh.rh<>
mem[r+1].hh.rh do s:=mem[s].hh.rh;mem[s].hh.rh:=-268435455;
eqtb[24538].hh.rh:=mem[p+4].hh.rh;
mem[p+4].hh.lh:=prunepagetop(mem[r+1].hh.rh,false);
if mem[p+4].hh.lh<>-268435455 then begin tempptr:=vpackage(mem[p+4].hh.
lh,0,1,1073741823);mem[p+3].int:=mem[tempptr+3].int+mem[tempptr+2].int;
freenode(tempptr,9);wait:=true;end;end;mem[r+2].hh.lh:=-268435455;
n:=mem[r].hh.b1;tempptr:=mem[eqtb[25333+n].hh.rh+5].hh.rh;
freenode(eqtb[25333+n].hh.rh,9);
eqtb[25333+n].hh.rh:=vpackage(tempptr,0,1,1073741823);
end{:1199}else begin while mem[s].hh.rh<>-268435455 do s:=mem[s].hh.rh;
mem[r+2].hh.rh:=s;end;end;{1200:}mem[prevp].hh.rh:=mem[p].hh.rh;
mem[p].hh.rh:=-268435455;if wait then begin mem[q].hh.rh:=p;q:=p;
incr(insertpenalties);end else begin deleteglueref(mem[p+4].hh.rh);
freenode(p,5);end;p:=prevp{:1200};end{:1198};
end else if mem[p].hh.b0=4 then if mem[p+1].hh.lh<>0 then{1828:}begin
findsaelement(6,mem[p+1].hh.lh,true);
if mem[curptr+1].hh.rh=-268435455 then begin mem[curptr+1].hh.rh:=mem[p
+1].hh.rh;incr(mem[mem[p+1].hh.rh].hh.lh);end;
if mem[curptr+2].hh.lh<>-268435455 then deletetokenref(mem[curptr+2].hh.
lh);mem[curptr+2].hh.lh:=mem[p+1].hh.rh;incr(mem[mem[p+1].hh.rh].hh.lh);
end{:1828}else{1194:}begin if curmark[1]=-268435455 then begin curmark[1
]:=mem[p+1].hh.rh;incr(mem[curmark[1]].hh.lh);end;
if curmark[2]<>-268435455 then deletetokenref(curmark[2]);
curmark[2]:=mem[p+1].hh.rh;incr(mem[curmark[2]].hh.lh);end{:1194};
prevp:=p;p:=mem[prevp].hh.rh;end;eqtb[24538].hh.rh:=savesplittopskip;
{1195:}if p<>-268435455 then begin if mem[memtop-1].hh.rh=-268435455
then if nestptr=0 then curlist.tailfield:=pagetail else nest[0].
tailfield:=pagetail;mem[pagetail].hh.rh:=mem[memtop-1].hh.rh;
mem[memtop-1].hh.rh:=p;mem[prevp].hh.rh:=-268435455;end;
savevbadness:=eqtb[27204].int;eqtb[27204].int:=10000;
savevfuzz:=eqtb[27802].int;eqtb[27802].int:=1073741823;
eqtb[25588].hh.rh:=vpackage(mem[memtop-2].hh.rh,bestsize,0,pagemaxdepth)
;eqtb[27204].int:=savevbadness;eqtb[27802].int:=savevfuzz;
if lastglue<>268435455 then deleteglueref(lastglue);
{1169:}pagecontents:=0;pagetail:=memtop-2;
mem[memtop-2].hh.rh:=-268435455;lastglue:=268435455;lastpenalty:=0;
lastkern:=0;lastnodetype:=-1;pagesofar[7]:=0;pagemaxdepth:=0{:1169};
if q<>memtop-4 then begin mem[memtop-2].hh.rh:=mem[memtop-4].hh.rh;
pagetail:=q;end{:1195};{1197:}r:=mem[memtop].hh.rh;
while r<>memtop do begin q:=mem[r].hh.rh;freenode(r,4);r:=q;end;
mem[memtop].hh.rh:=memtop{:1197}{:1192};
if saroot[6]<>-268435455 then if domarks(2,0,saroot[6])then saroot[6]:=
-268435455;
if(curmark[0]<>-268435455)and(curmark[1]=-268435455)then begin curmark[1
]:=curmark[0];incr(mem[curmark[0]].hh.lh);end;
if eqtb[25059].hh.rh<>-268435455 then if deadcycles>=eqtb[27217].int
then{1202:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1409);
end;printint(deadcycles);print(1410);begin helpptr:=3;helpline[2]:=1411;
helpline[1]:=1412;helpline[0]:=1413;end;error;
end{:1202}else{1203:}begin outputactive:=true;incr(deadcycles);pushnest;
curlist.modefield:=-1;curlist.auxfield.int:=eqtb[27825].int;
curlist.mlfield:=-line;begintokenlist(eqtb[25059].hh.rh,6);
newsavelevel(8);normalparagraph;scanleftbrace;goto 10;end{:1203};
{1201:}begin if mem[memtop-2].hh.rh<>-268435455 then begin if mem[memtop
-1].hh.rh=-268435455 then if nestptr=0 then curlist.tailfield:=pagetail
else nest[0].tailfield:=pagetail else mem[pagetail].hh.rh:=mem[memtop-1]
.hh.rh;mem[memtop-1].hh.rh:=mem[memtop-2].hh.rh;
mem[memtop-2].hh.rh:=-268435455;pagetail:=memtop-2;end;
flushnodelist(discptr[2]);discptr[2]:=-268435455;
shipout(eqtb[25588].hh.rh);eqtb[25588].hh.rh:=-268435455;end{:1201};
10:end;{:1190}procedure buildpage;label 10,30,31,22,80,90;
var p:halfword;q,r:halfword;b,c:integer;pi:integer;n:0..255;
delta,h,w:scaled;
begin if(mem[memtop-1].hh.rh=-268435455)or outputactive then goto 10;
repeat 22:p:=mem[memtop-1].hh.rh;
{1174:}if lastglue<>268435455 then deleteglueref(lastglue);
lastpenalty:=0;lastkern:=0;lastnodetype:=mem[p].hh.b0+1;
if mem[p].hh.b0=10 then begin lastglue:=mem[p+1].hh.lh;
incr(mem[lastglue].hh.rh);end else begin lastglue:=268435455;
if mem[p].hh.b0=12 then lastpenalty:=mem[p+1].int else if mem[p].hh.b0=
11 then lastkern:=mem[p+1].int;end{:1174};
{1175:}{1178:}case mem[p].hh.b0 of 0,1,2:if pagecontents<2 then{1179:}
begin if pagecontents=0 then freezepagespecs(2)else pagecontents:=2;
q:=newskipparam(9);
if mem[tempptr+1].int>mem[p+3].int then mem[tempptr+1].int:=mem[tempptr
+1].int-mem[p+3].int else mem[tempptr+1].int:=0;mem[q].hh.rh:=p;
mem[memtop-1].hh.rh:=q;goto 22;
end{:1179}else{1180:}begin pagesofar[1]:=pagesofar[1]+pagesofar[7]+mem[p
+3].int;pagesofar[7]:=mem[p+2].int;goto 80;end{:1180};
8:if(pagecontents<2)and((mem[p].hh.b1=35)or(mem[p].hh.b1=36))then begin
print(1362);goto 31;
end else{1609:}begin if(mem[p].hh.b1=10)or(mem[p].hh.b1=12)then begin
pagesofar[1]:=pagesofar[1]+pagesofar[7]+mem[p+2].int;
pagesofar[7]:=mem[p+3].int;end;goto 80;end{:1609};
10:if pagecontents<2 then goto 31 else if(mem[pagetail].hh.b0<9)then pi
:=0 else goto 90;
11:if pagecontents<2 then goto 31 else if mem[p].hh.rh=-268435455 then
goto 10 else if mem[mem[p].hh.rh].hh.b0=10 then pi:=0 else goto 90;
12:if pagecontents<2 then goto 31 else pi:=mem[p+1].int;4:goto 80;
3:{1186:}begin if pagecontents=0 then freezepagespecs(1);
n:=mem[p].hh.b1;r:=memtop;
while n>=mem[mem[r].hh.rh].hh.b1 do r:=mem[r].hh.rh;n:=n;
if mem[r].hh.b1<>n then{1187:}begin q:=getnode(4);
mem[q].hh.rh:=mem[r].hh.rh;mem[r].hh.rh:=q;r:=q;mem[r].hh.b1:=n;
mem[r].hh.b0:=0;ensurevbox(n);
if eqtb[25333+n].hh.rh=-268435455 then mem[r+3].int:=0 else mem[r+3].int
:=mem[eqtb[25333+n].hh.rh+3].int+mem[eqtb[25333+n].hh.rh+2].int;
mem[r+2].hh.lh:=-268435455;q:=eqtb[24546+n].hh.rh;
if eqtb[27281+n].int=1000 then h:=mem[r+3].int else h:=xovern(mem[r+3].
int,1000)*eqtb[27281+n].int;pagesofar[0]:=pagesofar[0]-h-mem[q+1].int;
pagesofar[2+mem[q].hh.b0]:=pagesofar[2+mem[q].hh.b0]+mem[q+2].int;
pagesofar[6]:=pagesofar[6]+mem[q+3].int;
if(mem[q].hh.b1<>0)and(mem[q+3].int<>0)then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(264);
print(1402);end;printesc(412);printint(n);begin helpptr:=3;
helpline[2]:=1403;helpline[1]:=1404;helpline[0]:=1321;end;error;end;
end{:1187};
if mem[r].hh.b0=1 then insertpenalties:=insertpenalties+mem[p+1].int
else begin mem[r+2].hh.rh:=p;
delta:=pagesofar[0]-pagesofar[1]-pagesofar[7]+pagesofar[6];
if eqtb[27281+n].int=1000 then h:=mem[p+3].int else h:=xovern(mem[p+3].
int,1000)*eqtb[27281+n].int;
if((h<=0)or(h<=delta))and(mem[p+3].int+mem[r+3].int<=eqtb[27827+n].int)
then begin pagesofar[0]:=pagesofar[0]-h;
mem[r+3].int:=mem[r+3].int+mem[p+3].int;
end else{1188:}begin if eqtb[27281+n].int<=0 then w:=1073741823 else
begin w:=pagesofar[0]-pagesofar[1]-pagesofar[7];
if eqtb[27281+n].int<>1000 then w:=xovern(w,eqtb[27281+n].int)*1000;end;
if w>eqtb[27827+n].int-mem[r+3].int then w:=eqtb[27827+n].int-mem[r+3].
int;q:=vertbreak(mem[p+4].hh.lh,w,mem[p+2].int);
mem[r+3].int:=mem[r+3].int+bestheightplusdepth;
ifdef('STAT')if eqtb[27210].int>0 then{1189:}begin begindiagnostic;
printnl(1405);printint(n);print(1406);printscaled(w);printchar(44);
printscaled(bestheightplusdepth);print(1334);
if q=-268435455 then printint(-10000)else if mem[q].hh.b0=12 then
printint(mem[q+1].int)else printchar(48);enddiagnostic(false);
end{:1189};
endif('STAT')if eqtb[27281+n].int<>1000 then bestheightplusdepth:=xovern
(bestheightplusdepth,1000)*eqtb[27281+n].int;
pagesofar[0]:=pagesofar[0]-bestheightplusdepth;mem[r].hh.b0:=1;
mem[r+1].hh.rh:=q;mem[r+1].hh.lh:=p;
if q=-268435455 then insertpenalties:=insertpenalties-10000 else if mem[
q].hh.b0=12 then insertpenalties:=insertpenalties+mem[q+1].int;
end{:1188};end;goto 80;end{:1186};others:confusion(889)end{:1178};
{1183:}if pi<10000 then begin{1185:}if pagesofar[1]<pagesofar[0]then if(
pagesofar[3]<>0)or(pagesofar[4]<>0)or(pagesofar[5]<>0)then b:=0 else b:=
badness(pagesofar[0]-pagesofar[1],pagesofar[2])else if pagesofar[1]-
pagesofar[0]>pagesofar[6]then b:=1073741823 else b:=badness(pagesofar[1]
-pagesofar[0],pagesofar[6]){:1185};
if b<1073741823 then if pi<=-10000 then c:=pi else if b<10000 then c:=b+
pi+insertpenalties else c:=100000 else c:=b;
if insertpenalties>=10000 then c:=1073741823;
ifdef('STAT')if eqtb[27210].int>0 then{1184:}begin begindiagnostic;
printnl(37);print(1330);printtotals;print(1400);
printscaled(pagesofar[0]);print(1333);
if b=1073741823 then printchar(42)else printint(b);print(1334);
printint(pi);print(1401);
if c=1073741823 then printchar(42)else printint(c);
if c<=leastpagecost then printchar(35);enddiagnostic(false);end{:1184};
endif('STAT')if c<=leastpagecost then begin bestpagebreak:=p;
bestsize:=pagesofar[0];leastpagecost:=c;r:=mem[memtop].hh.rh;
while r<>memtop do begin mem[r+2].hh.lh:=mem[r+2].hh.rh;r:=mem[r].hh.rh;
end;end;if(c=1073741823)or(pi<=-10000)then begin fireup(p);
if outputactive then goto 10;goto 30;end;end{:1183};
if(mem[p].hh.b0<10)or(mem[p].hh.b0>11)then goto 80;
90:{1182:}if mem[p].hh.b0=11 then q:=p else begin q:=mem[p+1].hh.lh;
pagesofar[2+mem[q].hh.b0]:=pagesofar[2+mem[q].hh.b0]+mem[q+2].int;
pagesofar[6]:=pagesofar[6]+mem[q+3].int;
if(mem[q].hh.b1<>0)and(mem[q+3].int<>0)then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(264);
print(1398);end;begin helpptr:=4;helpline[3]:=1399;helpline[2]:=1368;
helpline[1]:=1369;helpline[0]:=1321;end;error;r:=newspec(q);
mem[r].hh.b1:=0;deleteglueref(q);mem[p+1].hh.lh:=r;q:=r;end;end;
pagesofar[1]:=pagesofar[1]+pagesofar[7]+mem[q+1].int;
pagesofar[7]:=0{:1182};
80:{1181:}if pagesofar[7]>pagemaxdepth then begin pagesofar[1]:=
pagesofar[1]+pagesofar[7]-pagemaxdepth;pagesofar[7]:=pagemaxdepth;end;
{:1181};{1176:}mem[pagetail].hh.rh:=p;pagetail:=p;
mem[memtop-1].hh.rh:=mem[p].hh.rh;mem[p].hh.rh:=-268435455;
goto 30{:1176};31:{1177:}mem[memtop-1].hh.rh:=mem[p].hh.rh;
mem[p].hh.rh:=-268435455;
if eqtb[27277].int>0 then begin if discptr[2]=-268435455 then discptr[2]
:=p else mem[discptr[1]].hh.rh:=p;discptr[1]:=p;
end else flushnodelist(p){:1177};30:{:1175};
until mem[memtop-1].hh.rh=-268435455;
{1173:}if nestptr=0 then curlist.tailfield:=memtop-1 else nest[0].
tailfield:=memtop-1{:1173};10:end;
{:1172}{1208:}{1222:}procedure appspace;var q:halfword;
begin if(curlist.auxfield.hh.lh>=2000)and(eqtb[24541].hh.rh<>membot)then
q:=newparamglue(13)else begin if eqtb[24540].hh.rh<>membot then mainp:=
eqtb[24540].hh.rh else{1221:}begin mainp:=fontglue[eqtb[25589].hh.rh];
if mainp=-268435455 then begin mainp:=newspec(membot);
maink:=parambase[eqtb[25589].hh.rh]+2;
mem[mainp+1].int:=fontinfo[maink].int;
mem[mainp+2].int:=fontinfo[maink+1].int;
mem[mainp+3].int:=fontinfo[maink+2].int;
fontglue[eqtb[25589].hh.rh]:=mainp;end;end{:1221};mainp:=newspec(mainp);
{1223:}if curlist.auxfield.hh.lh>=2000 then mem[mainp+1].int:=mem[mainp
+1].int+fontinfo[7+parambase[eqtb[25589].hh.rh]].int;
mem[mainp+2].int:=xnoverd(mem[mainp+2].int,curlist.auxfield.hh.lh,1000);
mem[mainp+3].int:=xnoverd(mem[mainp+3].int,1000,curlist.auxfield.hh.lh)
{:1223};q:=newglue(mainp);mem[mainp].hh.rh:=-268435455;end;
mem[curlist.tailfield].hh.rh:=q;curlist.tailfield:=q;end;
{:1222}{1226:}procedure insertdollarsign;begin backinput;curtok:=804;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1421);
end;begin helpptr:=2;helpline[1]:=1422;helpline[0]:=1423;end;inserror;
end;{:1226}{1228:}procedure youcant;begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(787);
end;printcmdchr(curcmd,curchr);printinmode(curlist.modefield);end;
{:1228}{1229:}procedure reportillegalcase;begin youcant;
begin helpptr:=4;helpline[3]:=1424;helpline[2]:=1425;helpline[1]:=1426;
helpline[0]:=1427;end;error;end;
{:1229}{1230:}function privileged:boolean;
begin if curlist.modefield>0 then privileged:=true else begin
reportillegalcase;privileged:=false;end;end;
{:1230}{1233:}function itsallover:boolean;label 10;
begin if privileged then begin if(memtop-2=pagetail)and(curlist.
headfield=curlist.tailfield)and(deadcycles=0)then begin itsallover:=true
;goto 10;end;backinput;begin mem[curlist.tailfield].hh.rh:=newnullbox;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield+1].int:=eqtb[27796].int;
begin mem[curlist.tailfield].hh.rh:=newglue(membot+8);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
begin mem[curlist.tailfield].hh.rh:=newpenalty(-1073741824);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;buildpage;end;
itsallover:=false;10:end;{:1233}{1239:}procedure appendglue;
var s:smallnumber;begin s:=curchr;case s of 0:curval:=membot+4;
1:curval:=membot+8;2:curval:=membot+12;3:curval:=membot+16;
4:scanglue(2);5:scanglue(3);end;
begin mem[curlist.tailfield].hh.rh:=newglue(curval);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if s>=4 then begin decr(mem[curval].hh.rh);
if s>4 then mem[curlist.tailfield].hh.b1:=99;end;end;
{:1239}{1240:}procedure appendkern;var s:quarterword;begin s:=curchr;
scandimen(s=99,false,false);
begin mem[curlist.tailfield].hh.rh:=newkern(curval);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b1:=s;end;{:1240}{1243:}procedure offsave;
var p:halfword;
begin if curgroup=0 then{1245:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(932);
end;printcmdchr(curcmd,curchr);begin helpptr:=1;helpline[0]:=1445;end;
error;end{:1245}else begin backinput;p:=getavail;mem[memtop-3].hh.rh:=p;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(713);
end;{1244:}case curgroup of 14:begin mem[p].hh.lh:=19611;printesc(591);
end;15:begin mem[p].hh.lh:=804;printchar(36);end;
16:begin mem[p].hh.lh:=19612;mem[p].hh.rh:=getavail;p:=mem[p].hh.rh;
mem[p].hh.lh:=3118;printesc(1444);end;others:begin mem[p].hh.lh:=637;
printchar(125);end end{:1244};print(714);
begintokenlist(mem[memtop-3].hh.rh,4);begin helpptr:=5;
helpline[4]:=1439;helpline[3]:=1440;helpline[2]:=1441;helpline[1]:=1442;
helpline[0]:=1443;end;error;end;end;
{:1243}{1248:}procedure extrarightbrace;
begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1450);
end;case curgroup of 14:printesc(591);15:printchar(36);
16:printesc(1275);end;begin helpptr:=5;helpline[4]:=1451;
helpline[3]:=1452;helpline[2]:=1453;helpline[1]:=1454;helpline[0]:=1455;
end;error;incr(alignstate);end;{:1248}{1249:}procedure normalparagraph;
begin if eqtb[27196].int<>0 then eqworddefine(27196,0);
if eqtb[27810].int<>0 then eqworddefine(27810,0);
if eqtb[27218].int<>1 then eqworddefine(27218,1);
if eqtb[25058].hh.rh<>-268435455 then eqdefine(25058,120,-268435455);
if eqtb[25329].hh.rh<>-268435455 then eqdefine(25329,120,-268435455);
end;{:1249}{1254:}procedure boxend(boxcontext:integer);var p:halfword;
a:smallnumber;
begin if boxcontext<1073741824 then{1255:}begin if curbox<>-268435455
then begin mem[curbox+4].int:=boxcontext;
if abs(curlist.modefield)=1 then begin if preadjusttail<>-268435455 then
begin if memtop-14<>preadjusttail then begin mem[curlist.tailfield].hh.
rh:=mem[memtop-14].hh.rh;curlist.tailfield:=preadjusttail;end;
preadjusttail:=-268435455;end;appendtovlist(curbox);
if adjusttail<>-268435455 then begin if memtop-5<>adjusttail then begin
mem[curlist.tailfield].hh.rh:=mem[memtop-5].hh.rh;
curlist.tailfield:=adjusttail;end;adjusttail:=-268435455;end;
if curlist.modefield>0 then buildpage;
end else begin if abs(curlist.modefield)=104 then curlist.auxfield.hh.lh
:=1000 else begin p:=newnoad;mem[p+1].hh.rh:=2;mem[p+1].hh.lh:=curbox;
curbox:=p;end;mem[curlist.tailfield].hh.rh:=curbox;
curlist.tailfield:=curbox;end;end;
end{:1255}else if boxcontext<1073807360 then{1256:}begin if boxcontext<
1073774592 then begin curval:=boxcontext-1073741824;a:=0;
end else begin curval:=boxcontext-1073774592;a:=4;end;
if curval<256 then if(a>=4)then geqdefine(25333+curval,121,curbox)else
eqdefine(25333+curval,121,curbox)else begin findsaelement(4,curval,true)
;if(a>=4)then gsadef(curptr,curbox)else sadef(curptr,curbox);end;
end{:1256}else if curbox<>-268435455 then if boxcontext>1073807360 then
{1257:}begin{433:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:433};
if((curcmd=26)and(abs(curlist.modefield)<>1))or((curcmd=27)and(abs(
curlist.modefield)=1))then begin appendglue;
mem[curlist.tailfield].hh.b1:=boxcontext-(1073807261);
mem[curlist.tailfield+1].hh.rh:=curbox;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1468);
end;begin helpptr:=3;helpline[2]:=1469;helpline[1]:=1470;
helpline[0]:=1471;end;backerror;flushnodelist(curbox);end;
end{:1257}else shipout(curbox);end;
{:1254}{1258:}procedure beginbox(boxcontext:integer);label 10,30;
var p,q:halfword;r:halfword;fm:boolean;tx:halfword;m:quarterword;
k:halfword;n:halfword;begin case curchr of 0:begin scanregisternum;
if curval<256 then curbox:=eqtb[25333+curval].hh.rh else begin
findsaelement(4,curval,false);
if curptr=-268435455 then curbox:=-268435455 else curbox:=mem[curptr+1].
hh.rh;end;
if curval<256 then eqtb[25333+curval].hh.rh:=-268435455 else begin
findsaelement(4,curval,false);
if curptr<>-268435455 then begin mem[curptr+1].hh.rh:=-268435455;
incr(mem[curptr+1].hh.lh);deletesaref(curptr);end;end;end;
1:begin scanregisternum;
if curval<256 then q:=eqtb[25333+curval].hh.rh else begin findsaelement(
4,curval,false);
if curptr=-268435455 then q:=-268435455 else q:=mem[curptr+1].hh.rh;end;
curbox:=copynodelist(q);end;2:{1259:}begin curbox:=-268435455;
if abs(curlist.modefield)=207 then begin youcant;begin helpptr:=1;
helpline[0]:=1473;end;error;
end else if(curlist.modefield=1)and(curlist.headfield=curlist.tailfield)
then begin youcant;begin helpptr:=2;helpline[1]:=1474;helpline[0]:=1475;
end;error;end else begin tx:=curlist.tailfield;
if not(tx>=himemmin)then if(mem[tx].hh.b0=9)and(mem[tx].hh.b1=3)then
begin r:=curlist.headfield;repeat q:=r;r:=mem[q].hh.rh;until r=tx;tx:=q;
end;if not(tx>=himemmin)then if(mem[tx].hh.b0=0)or(mem[tx].hh.b0=1)then
{1260:}begin q:=curlist.headfield;p:=-268435455;repeat r:=p;p:=q;
fm:=false;
if not(q>=himemmin)then if mem[q].hh.b0=7 then begin for m:=1 to mem[q].
hh.b1 do p:=mem[p].hh.rh;if p=tx then goto 30;
end else if(mem[q].hh.b0=9)and(mem[q].hh.b1=2)then fm:=true;
q:=mem[p].hh.rh;until q=tx;q:=mem[tx].hh.rh;mem[p].hh.rh:=q;
mem[tx].hh.rh:=-268435455;
if q=-268435455 then if fm then confusion(1472)else curlist.tailfield:=p
else if fm then begin curlist.tailfield:=r;mem[r].hh.rh:=-268435455;
flushnodelist(p);end;curbox:=tx;mem[curbox+4].int:=0;end{:1260};30:end;
end{:1259};3:{1261:}begin scanregisternum;n:=curval;
if not scankeyword(1234)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1476);
end;begin helpptr:=2;helpline[1]:=1477;helpline[0]:=1478;end;error;end;
scandimen(false,false,false);curbox:=vsplit(n,curval);end{:1261};
others:{1262:}begin k:=curchr-4;savestack[saveptr+0].int:=boxcontext;
if k=104 then if(boxcontext<1073741824)and(abs(curlist.modefield)=1)then
scanspec(3,true)else scanspec(2,true)else begin if k=1 then scanspec(4,
true)else begin scanspec(5,true);k:=1;end;normalparagraph;end;pushnest;
curlist.modefield:=-k;
if k=1 then begin curlist.auxfield.int:=eqtb[27825].int;
if eqtb[25064].hh.rh<>-268435455 then begintokenlist(eqtb[25064].hh.rh,
11);end else begin curlist.auxfield.hh.lh:=1000;
if eqtb[25063].hh.rh<>-268435455 then begintokenlist(eqtb[25063].hh.rh,
10);end;goto 10;end{:1262}end;boxend(boxcontext);10:end;
{:1258}{1263:}procedure scanbox(boxcontext:integer);
begin{433:}repeat getxtoken;until(curcmd<>10)and(curcmd<>0){:433};
if curcmd=20 then beginbox(boxcontext)else if(boxcontext>=1073807361)and
((curcmd=36)or(curcmd=35))then begin curbox:=scanrulespec;
boxend(boxcontext);end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1479);
end;begin helpptr:=3;helpline[2]:=1480;helpline[1]:=1481;
helpline[0]:=1482;end;backerror;end;end;
{:1263}{1265:}procedure package(c:smallnumber);var h:scaled;p:halfword;
d:scaled;begin d:=eqtb[27800].int;unsave;saveptr:=saveptr-3;
if curlist.modefield=-104 then curbox:=hpack(mem[curlist.headfield].hh.
rh,savestack[saveptr+2].int,savestack[saveptr+1].int)else begin curbox:=
vpackage(mem[curlist.headfield].hh.rh,savestack[saveptr+2].int,savestack
[saveptr+1].int,d);if c=4 then{1266:}begin h:=0;p:=mem[curbox+5].hh.rh;
if p<>-268435455 then if mem[p].hh.b0<=2 then h:=mem[p+3].int;
mem[curbox+2].int:=mem[curbox+2].int-h+mem[curbox+3].int;
mem[curbox+3].int:=h;end{:1266};end;popnest;
boxend(savestack[saveptr+0].int);end;
{:1265}{1270:}function normmin(h:integer):smallnumber;
begin if h<=0 then normmin:=1 else if h>=63 then normmin:=63 else
normmin:=h;end;procedure newgraf(indented:boolean);
begin curlist.pgfield:=0;
if(curlist.modefield=1)or(curlist.headfield<>curlist.tailfield)then
begin mem[curlist.tailfield].hh.rh:=newparamglue(2);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;pushnest;
curlist.modefield:=104;curlist.auxfield.hh.lh:=1000;
if eqtb[27227].int<=0 then curlang:=0 else if eqtb[27227].int>255 then
curlang:=0 else curlang:=eqtb[27227].int;
curlist.auxfield.hh.rh:=curlang;
curlist.pgfield:=(normmin(eqtb[27228].int)*64+normmin(eqtb[27229].int))
*65536+curlang;if indented then begin curlist.tailfield:=newnullbox;
mem[curlist.headfield].hh.rh:=curlist.tailfield;
mem[curlist.tailfield+1].int:=eqtb[27793].int;
if(insertsrcspecialeverypar)then insertsrcspecial;end;
if eqtb[25060].hh.rh<>-268435455 then begintokenlist(eqtb[25060].hh.rh,7
);if nestptr=1 then buildpage;end;{:1270}{1272:}procedure indentinhmode;
var p,q:halfword;begin if curchr>0 then begin p:=newnullbox;
mem[p+1].int:=eqtb[27793].int;
if abs(curlist.modefield)=104 then curlist.auxfield.hh.lh:=1000 else
begin q:=newnoad;mem[q+1].hh.rh:=2;mem[q+1].hh.lh:=p;p:=q;end;
begin mem[curlist.tailfield].hh.rh:=p;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;end;end;
{:1272}{1274:}procedure headforvmode;
begin if curlist.modefield<0 then if curcmd<>36 then offsave else begin
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(787);
end;printesc(598);print(1486);begin helpptr:=2;helpline[1]:=1487;
helpline[0]:=1488;end;error;end else begin backinput;curtok:=partoken;
backinput;curinput.indexfield:=4;end;end;
{:1274}{1275:}procedure endgraf;
begin if curlist.modefield=104 then begin if curlist.headfield=curlist.
tailfield then popnest else linebreak(false);
if curlist.eTeXauxfield<>-268435455 then begin flushlist(curlist.
eTeXauxfield);curlist.eTeXauxfield:=-268435455;end;normalparagraph;
errorcount:=0;end;end;{:1275}{1278:}procedure begininsertoradjust;
begin if curcmd=38 then curval:=255 else begin scaneightbitint;
if curval=255 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1489);
end;printesc(337);printint(255);begin helpptr:=1;helpline[0]:=1490;end;
error;curval:=0;end;end;savestack[saveptr+0].int:=curval;
if(curcmd=38)and scankeyword(1491)then savestack[saveptr+1].int:=1 else
savestack[saveptr+1].int:=0;saveptr:=saveptr+2;newsavelevel(11);
scanleftbrace;normalparagraph;pushnest;curlist.modefield:=-1;
curlist.auxfield.int:=eqtb[27825].int;end;
{:1278}{1280:}procedure makemark;var p:halfword;c:halfword;
begin if curchr=0 then c:=0 else begin scanregisternum;c:=curval;end;
p:=scantoks(false,true);p:=getnode(2);mem[p+1].hh.lh:=c;mem[p].hh.b0:=4;
mem[p].hh.b1:=0;mem[p+1].hh.rh:=defref;mem[curlist.tailfield].hh.rh:=p;
curlist.tailfield:=p;end;{:1280}{1282:}procedure appendpenalty;
begin scanint;begin mem[curlist.tailfield].hh.rh:=newpenalty(curval);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if curlist.modefield=1 then buildpage;end;
{:1282}{1284:}procedure deletelast;label 10;var p,q:halfword;r:halfword;
fm:boolean;tx:halfword;m:quarterword;
begin if(curlist.modefield=1)and(curlist.tailfield=curlist.headfield)
then{1285:}begin if(curchr<>10)or(lastglue<>268435455)then begin youcant
;begin helpptr:=2;helpline[1]:=1474;helpline[0]:=1492;end;
if curchr=11 then helpline[0]:=(1493)else if curchr<>10 then helpline[0]
:=(1494);error;end;end{:1285}else begin tx:=curlist.tailfield;
if not(tx>=himemmin)then if(mem[tx].hh.b0=9)and(mem[tx].hh.b1=3)then
begin r:=curlist.headfield;repeat q:=r;r:=mem[q].hh.rh;until r=tx;tx:=q;
end;
if not(tx>=himemmin)then if mem[tx].hh.b0=curchr then begin q:=curlist.
headfield;p:=-268435455;repeat r:=p;p:=q;fm:=false;
if not(q>=himemmin)then if mem[q].hh.b0=7 then begin for m:=1 to mem[q].
hh.b1 do p:=mem[p].hh.rh;if p=tx then goto 10;
end else if(mem[q].hh.b0=9)and(mem[q].hh.b1=2)then fm:=true;
q:=mem[p].hh.rh;until q=tx;q:=mem[tx].hh.rh;mem[p].hh.rh:=q;
mem[tx].hh.rh:=-268435455;
if q=-268435455 then if fm then confusion(1472)else curlist.tailfield:=p
else if fm then begin curlist.tailfield:=r;mem[r].hh.rh:=-268435455;
flushnodelist(p);end;flushnodelist(tx);end;end;10:end;
{:1284}{1289:}procedure unpackage;label 30,10;var p:halfword;r:halfword;
c:0..1;
begin if curchr>1 then{1861:}begin mem[curlist.tailfield].hh.rh:=discptr
[curchr];discptr[curchr]:=-268435455;goto 30;end{:1861};c:=curchr;
scanregisternum;
if curval<256 then p:=eqtb[25333+curval].hh.rh else begin findsaelement(
4,curval,false);
if curptr=-268435455 then p:=-268435455 else p:=mem[curptr+1].hh.rh;end;
if p=-268435455 then goto 10;
if(abs(curlist.modefield)=207)or((abs(curlist.modefield)=1)and(mem[p].hh
.b0<>1))or((abs(curlist.modefield)=104)and(mem[p].hh.b0<>0))then begin
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1502);
end;begin helpptr:=3;helpline[2]:=1503;helpline[1]:=1504;
helpline[0]:=1505;end;error;goto 10;end;
if c=1 then mem[curlist.tailfield].hh.rh:=copynodelist(mem[p+5].hh.rh)
else begin mem[curlist.tailfield].hh.rh:=mem[p+5].hh.rh;
if curval<256 then eqtb[25333+curval].hh.rh:=-268435455 else begin
findsaelement(4,curval,false);
if curptr<>-268435455 then begin mem[curptr+1].hh.rh:=-268435455;
incr(mem[curptr+1].hh.lh);deletesaref(curptr);end;end;freenode(p,9);end;
30:while mem[curlist.tailfield].hh.rh<>-268435455 do begin r:=mem[
curlist.tailfield].hh.rh;
if not(r>=himemmin)and(mem[r].hh.b0=40)then begin mem[curlist.tailfield]
.hh.rh:=mem[r].hh.rh;begin mem[mem[r+2].hh.lh].hh.rh:=avail;
avail:=mem[r+2].hh.lh;ifdef('STAT')decr(dynused);endif('STAT')end;
freenode(r,3);end;curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
10:end;{:1289}{1292:}procedure appenditaliccorrection;label 10;
var p:halfword;f:internalfontnumber;
begin if curlist.tailfield<>curlist.headfield then begin if(curlist.
tailfield>=himemmin)then p:=curlist.tailfield else if mem[curlist.
tailfield].hh.b0=6 then p:=curlist.tailfield+1 else goto 10;
f:=mem[p].hh.b0;
begin mem[curlist.tailfield].hh.rh:=newkern(fontinfo[italicbase[f]+(
fontinfo[charbase[f]+effectivechar(true,f,mem[p].hh.b1)].qqqq.b2)div 4].
int);curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b1:=1;end;10:end;
{:1292}{1296:}procedure appenddiscretionary;var c:integer;
begin begin mem[curlist.tailfield].hh.rh:=newdisc;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if curchr=1 then begin c:=hyphenchar[eqtb[25589].hh.rh];
if c>=0 then if c<256 then mem[curlist.tailfield+1].hh.lh:=newcharacter(
eqtb[25589].hh.rh,c);end else begin incr(saveptr);
savestack[saveptr-1].int:=0;newsavelevel(10);scanleftbrace;pushnest;
curlist.modefield:=-104;curlist.auxfield.hh.lh:=1000;end;end;
{:1296}{1298:}procedure builddiscretionary;label 30,10;var p,q:halfword;
n:integer;begin unsave;{1300:}q:=curlist.headfield;p:=mem[q].hh.rh;n:=0;
while p<>-268435455 do begin if not(p>=himemmin)then if mem[p].hh.b0>2
then if mem[p].hh.b0<>11 then if mem[p].hh.b0<>6 then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1512);
end;begin helpptr:=1;helpline[0]:=1513;end;error;begindiagnostic;
printnl(1514);showbox(p);enddiagnostic(true);flushnodelist(p);
mem[q].hh.rh:=-268435455;goto 30;end;q:=p;p:=mem[q].hh.rh;incr(n);end;
30:{:1300};p:=mem[curlist.headfield].hh.rh;popnest;
case savestack[saveptr-1].int of 0:mem[curlist.tailfield+1].hh.lh:=p;
1:mem[curlist.tailfield+1].hh.rh:=p;
2:{1299:}begin if(n>0)and(abs(curlist.modefield)=207)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1506);
end;printesc(357);begin helpptr:=2;helpline[1]:=1507;helpline[0]:=1508;
end;flushnodelist(p);n:=0;error;
end else mem[curlist.tailfield].hh.rh:=p;
if n<=255 then mem[curlist.tailfield].hh.b1:=n else begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1509);
end;begin helpptr:=2;helpline[1]:=1510;helpline[0]:=1511;end;error;end;
if n>0 then curlist.tailfield:=q;decr(saveptr);goto 10;end{:1299};end;
incr(savestack[saveptr-1].int);newsavelevel(10);scanleftbrace;pushnest;
curlist.modefield:=-104;curlist.auxfield.hh.lh:=1000;10:end;
{:1298}{1302:}procedure makeaccent;var s,t:real;p,q,r:halfword;
f:internalfontnumber;a,h,x,w,delta:scaled;i:fourquarters;
begin scancharnum;f:=eqtb[25589].hh.rh;p:=newcharacter(f,curval);
if p<>-268435455 then begin x:=fontinfo[5+parambase[f]].int;
s:=fontinfo[1+parambase[f]].int/65536.0;
a:=fontinfo[widthbase[f]+fontinfo[charbase[f]+effectivechar(true,f,mem[p
].hh.b1)].qqqq.b0].int;doassignments;{1303:}q:=-268435455;
f:=eqtb[25589].hh.rh;
if(curcmd=11)or(curcmd=12)or(curcmd=68)then q:=newcharacter(f,curchr)
else if curcmd=16 then begin scancharnum;q:=newcharacter(f,curval);
end else backinput{:1303};
if q<>-268435455 then{1304:}begin t:=fontinfo[1+parambase[f]].int
/65536.0;
i:=fontinfo[charbase[f]+effectivechar(true,f,mem[q].hh.b1)].qqqq;
w:=fontinfo[widthbase[f]+i.b0].int;
h:=fontinfo[heightbase[f]+(i.b1)div 16].int;
if h<>x then begin p:=hpack(p,0,1);mem[p+4].int:=x-h;end;
delta:=round((w-a)/2.0+h*t-x*s);r:=newkern(delta);mem[r].hh.b1:=2;
mem[curlist.tailfield].hh.rh:=r;mem[r].hh.rh:=p;
curlist.tailfield:=newkern(-a-delta);mem[curlist.tailfield].hh.b1:=2;
mem[p].hh.rh:=curlist.tailfield;p:=q;end{:1304};
mem[curlist.tailfield].hh.rh:=p;curlist.tailfield:=p;
curlist.auxfield.hh.lh:=1000;end;end;{:1302}{1306:}procedure alignerror;
begin if abs(alignstate)>2 then{1307:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1519);
end;printcmdchr(curcmd,curchr);
if curtok=1062 then begin begin helpptr:=6;helpline[5]:=1520;
helpline[4]:=1521;helpline[3]:=1522;helpline[2]:=1523;helpline[1]:=1524;
helpline[0]:=1525;end;end else begin begin helpptr:=5;helpline[4]:=1520;
helpline[3]:=1526;helpline[2]:=1523;helpline[1]:=1524;helpline[0]:=1525;
end;end;error;end{:1307}else begin backinput;
if alignstate<0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(745);
end;incr(alignstate);curtok:=379;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1515);
end;decr(alignstate);curtok:=637;end;begin helpptr:=3;helpline[2]:=1516;
helpline[1]:=1517;helpline[0]:=1518;end;inserror;end;end;
{:1306}{1308:}procedure noalignerror;begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1519);
end;printesc(604);begin helpptr:=2;helpline[1]:=1527;helpline[0]:=1528;
end;error;end;procedure omiterror;begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1519);
end;printesc(607);begin helpptr:=2;helpline[1]:=1529;helpline[0]:=1528;
end;error;end;{:1308}{1310:}procedure doendv;begin baseptr:=inputptr;
inputstack[baseptr]:=curinput;
while(inputstack[baseptr].indexfield<>2)and(inputstack[baseptr].locfield
=-268435455)and(inputstack[baseptr].statefield=0)do decr(baseptr);
if(inputstack[baseptr].indexfield<>2)or(inputstack[baseptr].locfield<>
-268435455)or(inputstack[baseptr].statefield<>0)then fatalerror(677);
if curgroup=6 then begin endgraf;if fincol then finrow;end else offsave;
end;{:1310}{1314:}procedure cserror;
begin if curchr=10 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(932);
end;printesc(590);begin helpptr:=1;helpline[0]:=1531;end;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(932);
end;printesc(579);begin helpptr:=1;helpline[0]:=1532;end;end;error;end;
{:1314}{1315:}procedure pushmath(c:groupcode);begin pushnest;
curlist.modefield:=-207;curlist.auxfield.int:=-268435455;
newsavelevel(c);end;
{:1315}{1317:}{1731:}procedure justcopy(p,h,t:halfword);label 40,45;
var r:halfword;words:0..5;begin while p<>-268435455 do begin words:=1;
if(p>=himemmin)then r:=getavail else case mem[p].hh.b0 of 0,1:begin r:=
getnode(9);{1928:}mem[r+7].int:=mem[p+7].int;mem[r+8].int:=mem[p+8].int;
{:1928};mem[r+6]:=mem[p+6];mem[r+5]:=mem[p+5];words:=5;
mem[r+5].hh.rh:=-268435455;end;2:begin r:=getnode(6);words:=6;end;
6:begin r:=getavail;mem[r]:=mem[p+1];goto 40;end;11,9:begin words:=4;
r:=getnode(words);end;10:begin r:=getnode(4);
incr(mem[mem[p+1].hh.lh].hh.rh);{1930:}mem[r+2].int:=mem[p+2].int;
mem[r+3].int:=mem[p+3].int;{:1930};mem[r+1].hh.lh:=mem[p+1].hh.lh;
mem[r+1].hh.rh:=-268435455;end;
8:{1602:}case mem[p].hh.b1 of 0:begin r:=getnode(3);words:=3;end;
1,3:begin r:=getnode(2);incr(mem[mem[p+1].hh.rh].hh.lh);words:=2;end;
2,4:begin r:=getnode(2);words:=2;end;6:begin r:=getnode(2);
incr(mem[mem[p+1].hh.rh].hh.lh);words:=2;end;
38:begin if mem[p+1].hh.lh<=1 then begin r:=getnode(3);
incr(mem[mem[p+2].hh.rh].hh.lh);words:=3;end else begin r:=getnode(2);
words:=2;end;end;39:begin r:=getnode(2);incr(mem[mem[p+1].hh.rh].hh.lh);
words:=2;end;40:begin r:=getnode(2);words:=2;end;41:begin r:=getnode(2);
words:=2;end;8:begin r:=getnode(2);words:=2;end;10:begin r:=getnode(5);
words:=5;end;12:begin r:=getnode(5);words:=5;end;13:begin r:=getnode(7);
incr(mem[mem[p+5].hh.lh].hh.lh);words:=7;end;14:begin r:=getnode(7);
mem[r+2].int:=mem[p+2].int;mem[r+3].int:=mem[p+3].int;
mem[r+1].int:=mem[p+1].int;mem[r+5].hh.lh:=mem[p+5].hh.lh;
if mem[r+5].hh.lh<>-268435455 then incr(mem[mem[r+5].hh.lh].hh.lh);
mem[r+5].hh.rh:=mem[p+5].hh.rh;incr(mem[mem[r+5].hh.rh+2].hh.rh);
mem[r+6].int:=mem[p+6].int;end;15:r:=getnode(2);17:begin r:=getnode(7);
if mem[p+5].hh.b1>0 then incr(mem[mem[p+5].hh.rh].hh.lh);words:=7;end;
18,19:begin r:=getnode(7);
if mem[p+5].hh.b1>0 then incr(mem[mem[p+5].hh.rh].hh.lh);
if mem[p+6].hh.lh<>-268435455 then incr(mem[mem[p+6].hh.lh].hh.lh);
words:=7;end;20:r:=getnode(2);21:r:=getnode(2);34:r:=getnode(2);
35:begin incr(mem[mem[p+1].hh.lh].hh.rh);r:=getnode(3);words:=3;end;
36:r:=getnode(2);43:r:=getnode(2);44:r:=getnode(2);45:r:=getnode(2);
others:confusion(1897)end{:1602};others:goto 45 end;
while words>0 do begin decr(words);mem[r+words]:=mem[p+words];end;
40:mem[h].hh.rh:=r;h:=r;45:p:=mem[p].hh.rh;end;mem[h].hh.rh:=t;end;
{:1731}{1736:}procedure justreverse(p:halfword);label 30;var l:halfword;
t:halfword;q:halfword;m,n:halfword;begin m:=-268435455;n:=-268435455;
if mem[memtop-3].hh.rh=-268435455 then begin justcopy(mem[p].hh.rh,
memtop-3,-268435455);q:=mem[memtop-3].hh.rh;
end else begin q:=mem[p].hh.rh;mem[p].hh.rh:=-268435455;
flushnodelist(mem[memtop-3].hh.rh);end;t:=newedge(curdir,0);l:=t;
curdir:=1-curdir;while q<>-268435455 do if(q>=himemmin)then repeat p:=q;
q:=mem[p].hh.rh;mem[p].hh.rh:=l;l:=p;
until not(q>=himemmin)else begin p:=q;q:=mem[p].hh.rh;
if mem[p].hh.b0=9 then{1737:}if odd(mem[p].hh.b1)then if mem[LRptr].hh.
lh<>(4*(mem[p].hh.b1 div 4)+3)then begin mem[p].hh.b0:=11;
incr(LRproblems);end else begin begin tempptr:=LRptr;
LRptr:=mem[tempptr].hh.rh;begin mem[tempptr].hh.rh:=avail;
avail:=tempptr;ifdef('STAT')decr(dynused);endif('STAT')end;end;
if n>-268435455 then begin decr(n);decr(mem[p].hh.b1);
end else begin if m>-268435455 then decr(m)else begin mem[t+1].int:=mem[
p+1].int;mem[t].hh.rh:=q;freenode(p,4);goto 30;end;mem[p].hh.b0:=11;end;
end else begin begin tempptr:=getavail;
mem[tempptr].hh.lh:=(4*(mem[p].hh.b1 div 4)+3);
mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;end;
if(n>-268435455)or((mem[p].hh.b1 div 8)<>curdir)then begin incr(n);
incr(mem[p].hh.b1);end else begin mem[p].hh.b0:=11;incr(m);end;
end{:1737};mem[p].hh.rh:=l;l:=p;end;goto 30;mem[t+1].int:=mem[p+1].int;
mem[t].hh.rh:=q;freenode(p,2);30:mem[memtop-3].hh.rh:=l;end;
{:1736}procedure initmath;label 21,40,45,30;var w:scaled;j:halfword;
x:integer;l:scaled;s:scaled;p:halfword;q:halfword;f:internalfontnumber;
n:integer;v:scaled;d:scaled;begin gettoken;
if(curcmd=3)and(curlist.modefield>0)then{1324:}begin j:=-268435455;
w:=-1073741823;
if curlist.headfield=curlist.tailfield then{1730:}begin popnest;
{1729:}if curlist.eTeXauxfield=-268435455 then x:=0 else if mem[curlist.
eTeXauxfield].hh.lh>=8 then x:=-1 else x:=1{:1729};
end{:1730}else begin linebreak(true);
{1325:}{1732:}if(eTeXmode=1)then{1738:}begin if eqtb[24536].hh.rh=membot
then j:=newkern(0)else j:=newparamglue(8);
if eqtb[24535].hh.rh=membot then p:=newkern(0)else p:=newparamglue(7);
mem[p].hh.rh:=j;j:=newnullbox;mem[j+1].int:=mem[justbox+1].int;
mem[j+4].int:=mem[justbox+4].int;mem[j+5].hh.rh:=p;
mem[j+5].hh.b1:=mem[justbox+5].hh.b1;
mem[j+5].hh.b0:=mem[justbox+5].hh.b0;mem[j+6].gr:=mem[justbox+6].gr;
end{:1738};v:=mem[justbox+4].int;
{1729:}if curlist.eTeXauxfield=-268435455 then x:=0 else if mem[curlist.
eTeXauxfield].hh.lh>=8 then x:=-1 else x:=1{:1729};
if x>=0 then begin p:=mem[justbox+5].hh.rh;
mem[memtop-3].hh.rh:=-268435455;end else begin v:=-v-mem[justbox+1].int;
p:=newmath(0,6);mem[memtop-3].hh.rh:=p;
justcopy(mem[justbox+5].hh.rh,p,newmath(0,7));curdir:=1;end;
v:=v+2*fontinfo[6+parambase[eqtb[25589].hh.rh]].int;
if(eqtb[27279].int>0)then{1708:}begin tempptr:=getavail;
mem[tempptr].hh.lh:=0;mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;
end{:1708}{:1732};
while p<>-268435455 do begin{1326:}21:if(p>=himemmin)then begin f:=mem[p
].hh.b0;
d:=fontinfo[widthbase[f]+fontinfo[charbase[f]+effectivechar(true,f,mem[p
].hh.b1)].qqqq.b0].int;goto 40;end;
case mem[p].hh.b0 of 0,1,2:begin d:=mem[p+1].int;goto 40;end;
6:{827:}begin mem[memtop-12]:=mem[p+1];
mem[memtop-12].hh.rh:=mem[p].hh.rh;p:=memtop-12;goto 21;end{:827};
40:d:=mem[p+1].int;11:d:=mem[p+1].int;{1734:}9:begin d:=mem[p+1].int;
if(eqtb[27279].int>0)then{1735:}if odd(mem[p].hh.b1)then begin if mem[
LRptr].hh.lh=(4*(mem[p].hh.b1 div 4)+3)then begin tempptr:=LRptr;
LRptr:=mem[tempptr].hh.rh;begin mem[tempptr].hh.rh:=avail;
avail:=tempptr;ifdef('STAT')decr(dynused);endif('STAT')end;
end else if mem[p].hh.b1>4 then begin w:=1073741823;goto 30;
end end else begin begin tempptr:=getavail;
mem[tempptr].hh.lh:=(4*(mem[p].hh.b1 div 4)+3);
mem[tempptr].hh.rh:=LRptr;LRptr:=tempptr;end;
if(mem[p].hh.b1 div 8)<>curdir then begin justreverse(p);p:=memtop-3;
end;end{:1735}else if mem[p].hh.b1>=4 then begin w:=1073741823;goto 30;
end;end;14:begin d:=mem[p+1].int;curdir:=mem[p].hh.b1;end;
{:1734}10:{1327:}begin q:=mem[p+1].hh.lh;d:=mem[q+1].int;
if mem[justbox+5].hh.b0=1 then begin if(mem[justbox+5].hh.b1=mem[q].hh.
b0)and(mem[q+2].int<>0)then v:=1073741823;
end else if mem[justbox+5].hh.b0=2 then begin if(mem[justbox+5].hh.b1=
mem[q].hh.b1)and(mem[q+3].int<>0)then v:=1073741823;end;
if mem[p].hh.b1>=100 then goto 40;end{:1327};
8:{1606:}if(mem[p].hh.b1=10)or(mem[p].hh.b1=12)then d:=mem[p+1].int else
d:=0{:1606};others:d:=0 end{:1326};if v<1073741823 then v:=v+d;goto 45;
40:if v<1073741823 then begin v:=v+d;w:=v;end else begin w:=1073741823;
goto 30;end;45:p:=mem[p].hh.rh;end;
30:{1733:}if(eqtb[27279].int>0)then begin while LRptr<>-268435455 do
begin tempptr:=LRptr;LRptr:=mem[tempptr].hh.rh;
begin mem[tempptr].hh.rh:=avail;avail:=tempptr;
ifdef('STAT')decr(dynused);endif('STAT')end;end;
if LRproblems<>0 then begin w:=1073741823;LRproblems:=0;end;end;
curdir:=0;flushnodelist(mem[memtop-3].hh.rh){:1733}{:1325};end;
{1328:}if eqtb[25058].hh.rh=-268435455 then if(eqtb[27810].int<>0)and(((
eqtb[27218].int>=0)and(curlist.pgfield+2>eqtb[27218].int))or(curlist.
pgfield+1<-eqtb[27218].int))then begin l:=eqtb[27796].int-abs(eqtb[27810
].int);if eqtb[27810].int>0 then s:=eqtb[27810].int else s:=0;
end else begin l:=eqtb[27796].int;s:=0;
end else begin n:=mem[eqtb[25058].hh.rh].hh.lh;
if curlist.pgfield+2>=n then p:=eqtb[25058].hh.rh+2*n else p:=eqtb[25058
].hh.rh+2*(curlist.pgfield+2);s:=mem[p-1].int;l:=mem[p].int;end{:1328};
pushmath(15);curlist.modefield:=207;eqworddefine(27221,-1);
eqworddefine(27806,w);curlist.eTeXauxfield:=j;
if(eTeXmode=1)then eqworddefine(27275,x);eqworddefine(27807,l);
eqworddefine(27808,s);
if eqtb[25062].hh.rh<>-268435455 then begintokenlist(eqtb[25062].hh.rh,9
);if nestptr=1 then buildpage;end{:1324}else begin backinput;
{1318:}begin pushmath(15);eqworddefine(27221,-1);
if(insertsrcspecialeverymath)then insertsrcspecial;
if eqtb[25061].hh.rh<>-268435455 then begintokenlist(eqtb[25061].hh.rh,8
);end{:1318};end;end;{:1317}{1321:}procedure starteqno;
begin savestack[saveptr+0].int:=curchr;incr(saveptr);
{1318:}begin pushmath(15);eqworddefine(27221,-1);
if(insertsrcspecialeverymath)then insertsrcspecial;
if eqtb[25061].hh.rh<>-268435455 then begintokenlist(eqtb[25061].hh.rh,8
);end{:1318};end;{:1321}{1330:}procedure scanmath(p:halfword);
label 20,21,10;var c:integer;begin 20:{433:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:433};
21:case curcmd of 11,12,68:begin c:=eqtb[26665+curchr].hh.rh;
if c=32768 then begin{1331:}begin curcs:=curchr+1;
curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;xtoken;backinput;
end{:1331};goto 20;end;end;16:begin scancharnum;curchr:=curval;
curcmd:=68;goto 21;end;17:begin scanfifteenbitint;c:=curval;end;
69:c:=curchr;15:begin scantwentysevenbitint;c:=curval div 4096;end;
others:{1332:}begin backinput;scanleftbrace;savestack[saveptr+0].int:=p;
incr(saveptr);pushmath(9);goto 10;end{:1332}end;mem[p].hh.rh:=1;
mem[p].hh.b1:=c mod 256;
if(c>=28672)and((eqtb[27221].int>=0)and(eqtb[27221].int<16))then mem[p].
hh.b0:=eqtb[27221].int else mem[p].hh.b0:=(c div 256)mod 16;10:end;
{:1330}{1334:}procedure setmathchar(c:integer);var p:halfword;
begin if c>=32768 then{1331:}begin curcs:=curchr+1;
curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;xtoken;backinput;
end{:1331}else begin p:=newnoad;mem[p+1].hh.rh:=1;
mem[p+1].hh.b1:=c mod 256;mem[p+1].hh.b0:=(c div 256)mod 16;
if c>=28672 then begin if((eqtb[27221].int>=0)and(eqtb[27221].int<16))
then mem[p+1].hh.b0:=eqtb[27221].int;mem[p].hh.b0:=16;
end else mem[p].hh.b0:=16+(c div 4096);mem[curlist.tailfield].hh.rh:=p;
curlist.tailfield:=p;end;end;{:1334}{1338:}procedure mathlimitswitch;
label 10;
begin if curlist.headfield<>curlist.tailfield then if mem[curlist.
tailfield].hh.b0=17 then begin mem[curlist.tailfield].hh.b1:=curchr;
goto 10;end;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1536);
end;begin helpptr:=1;helpline[0]:=1537;end;error;10:end;
{:1338}{1339:}procedure scandelimiter(p:halfword;r:boolean);
begin if r then scantwentysevenbitint else begin{433:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:433};
case curcmd of 11,12:curval:=eqtb[27537+curchr].int;
15:scantwentysevenbitint;others:curval:=-1 end;end;
if curval<0 then{1340:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1538);
end;begin helpptr:=6;helpline[5]:=1539;helpline[4]:=1540;
helpline[3]:=1541;helpline[2]:=1542;helpline[1]:=1543;helpline[0]:=1544;
end;backerror;curval:=0;end{:1340};
mem[p].qqqq.b0:=(curval div 1048576)mod 16;
mem[p].qqqq.b1:=(curval div 4096)mod 256;
mem[p].qqqq.b2:=(curval div 256)mod 16;mem[p].qqqq.b3:=curval mod 256;
end;{:1339}{1342:}procedure mathradical;
begin begin mem[curlist.tailfield].hh.rh:=getnode(5);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=24;mem[curlist.tailfield].hh.b1:=0;
mem[curlist.tailfield+1].hh:=emptyfield;
mem[curlist.tailfield+3].hh:=emptyfield;
mem[curlist.tailfield+2].hh:=emptyfield;
scandelimiter(curlist.tailfield+4,true);scanmath(curlist.tailfield+1);
end;{:1342}{1344:}procedure mathac;
begin if curcmd=45 then{1345:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1545);
end;printesc(600);print(1546);begin helpptr:=2;helpline[1]:=1547;
helpline[0]:=1548;end;error;end{:1345};
begin mem[curlist.tailfield].hh.rh:=getnode(5);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=28;mem[curlist.tailfield].hh.b1:=0;
mem[curlist.tailfield+1].hh:=emptyfield;
mem[curlist.tailfield+3].hh:=emptyfield;
mem[curlist.tailfield+2].hh:=emptyfield;
mem[curlist.tailfield+4].hh.rh:=1;scanfifteenbitint;
mem[curlist.tailfield+4].hh.b1:=curval mod 256;
if(curval>=28672)and((eqtb[27221].int>=0)and(eqtb[27221].int<16))then
mem[curlist.tailfield+4].hh.b0:=eqtb[27221].int else mem[curlist.
tailfield+4].hh.b0:=(curval div 256)mod 16;
scanmath(curlist.tailfield+1);end;{:1344}{1351:}procedure appendchoices;
begin begin mem[curlist.tailfield].hh.rh:=newchoice;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;incr(saveptr);
savestack[saveptr-1].int:=0;pushmath(13);scanleftbrace;end;
{:1351}{1353:}{1363:}function finmlist(p:halfword):halfword;
var q:halfword;
begin if curlist.auxfield.int<>-268435455 then{1364:}begin mem[curlist.
auxfield.int+3].hh.rh:=3;
mem[curlist.auxfield.int+3].hh.lh:=mem[curlist.headfield].hh.rh;
if p=-268435455 then q:=curlist.auxfield.int else begin q:=mem[curlist.
auxfield.int+2].hh.lh;
if(mem[q].hh.b0<>30)or(curlist.eTeXauxfield=-268435455)then confusion(
1275);
mem[curlist.auxfield.int+2].hh.lh:=mem[curlist.eTeXauxfield].hh.rh;
mem[curlist.eTeXauxfield].hh.rh:=curlist.auxfield.int;
mem[curlist.auxfield.int].hh.rh:=p;end;
end{:1364}else begin mem[curlist.tailfield].hh.rh:=p;
q:=mem[curlist.headfield].hh.rh;end;popnest;finmlist:=q;end;
{:1363}procedure buildchoices;label 10;var p:halfword;begin unsave;
p:=finmlist(-268435455);
case savestack[saveptr-1].int of 0:mem[curlist.tailfield+1].hh.lh:=p;
1:mem[curlist.tailfield+1].hh.rh:=p;2:mem[curlist.tailfield+2].hh.lh:=p;
3:begin mem[curlist.tailfield+2].hh.rh:=p;decr(saveptr);goto 10;end;end;
incr(savestack[saveptr-1].int);pushmath(13);scanleftbrace;10:end;
{:1353}{1355:}procedure subsup;var t:smallnumber;p:halfword;begin t:=0;
p:=-268435455;
if curlist.tailfield<>curlist.headfield then if(mem[curlist.tailfield].
hh.b0>=16)and(mem[curlist.tailfield].hh.b0<30)then begin p:=curlist.
tailfield+2+curcmd-7;t:=mem[p].hh.rh;end;
if(p=-268435455)or(t<>0)then{1356:}begin begin mem[curlist.tailfield].hh
.rh:=newnoad;curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
p:=curlist.tailfield+2+curcmd-7;
if t<>0 then begin if curcmd=7 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1549);
end;begin helpptr:=1;helpline[0]:=1550;end;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1551);
end;begin helpptr:=1;helpline[0]:=1552;end;end;error;end;end{:1356};
scanmath(p);end;{:1355}{1360:}procedure mathfraction;var c:smallnumber;
begin c:=curchr;
if curlist.auxfield.int<>-268435455 then{1362:}begin if c>=3 then begin
scandelimiter(memtop-12,false);scandelimiter(memtop-12,false);end;
if c mod 3=0 then scandimen(false,false,false);
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1559);
end;begin helpptr:=3;helpline[2]:=1560;helpline[1]:=1561;
helpline[0]:=1562;end;error;
end{:1362}else begin curlist.auxfield.int:=getnode(6);
mem[curlist.auxfield.int].hh.b0:=25;mem[curlist.auxfield.int].hh.b1:=0;
mem[curlist.auxfield.int+2].hh.rh:=3;
mem[curlist.auxfield.int+2].hh.lh:=mem[curlist.headfield].hh.rh;
mem[curlist.auxfield.int+3].hh:=emptyfield;
mem[curlist.auxfield.int+4].qqqq:=nulldelimiter;
mem[curlist.auxfield.int+5].qqqq:=nulldelimiter;
mem[curlist.headfield].hh.rh:=-268435455;
curlist.tailfield:=curlist.headfield;
{1361:}if c>=3 then begin scandelimiter(curlist.auxfield.int+4,false);
scandelimiter(curlist.auxfield.int+5,false);end;
case c mod 3 of 0:begin scandimen(false,false,false);
mem[curlist.auxfield.int+1].int:=curval;end;
1:mem[curlist.auxfield.int+1].int:=1073741824;
2:mem[curlist.auxfield.int+1].int:=0;end{:1361};end;end;
{:1360}{1370:}procedure mathleftright;var t:smallnumber;p:halfword;
q:halfword;begin t:=curchr;
if(t<>30)and(curgroup<>16)then{1371:}begin if curgroup=15 then begin
scandelimiter(memtop-12,false);begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(932);
end;if t=1 then begin printesc(1276);begin helpptr:=1;helpline[0]:=1563;
end;end else begin printesc(1275);begin helpptr:=1;helpline[0]:=1564;
end;end;error;end else offsave;end{:1371}else begin p:=newnoad;
mem[p].hh.b0:=t;scandelimiter(p+1,false);
if t=1 then begin mem[p].hh.b0:=31;mem[p].hh.b1:=1;end;
if t=30 then q:=p else begin q:=finmlist(p);unsave;end;
if t<>31 then begin pushmath(16);mem[curlist.headfield].hh.rh:=q;
curlist.tailfield:=p;curlist.eTeXauxfield:=p;
end else begin begin mem[curlist.tailfield].hh.rh:=newnoad;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=23;mem[curlist.tailfield+1].hh.rh:=3;
mem[curlist.tailfield+1].hh.lh:=q;end;end;end;
{:1370}{1373:}{1742:}procedure appdisplay(j,b:halfword;d:scaled);
var z:scaled;s:scaled;e:scaled;x:integer;p,q,r,t,u:halfword;
begin s:=eqtb[27808].int;x:=eqtb[27275].int;
if x=0 then mem[b+4].int:=s+d else begin z:=eqtb[27807].int;p:=b;
{1743:}if x>0 then e:=z-d-mem[p+1].int else begin e:=d;
d:=z-e-mem[p+1].int;end;if j<>-268435455 then begin b:=copynodelist(j);
mem[b+3].int:=mem[p+3].int;mem[b+2].int:=mem[p+2].int;s:=s-mem[b+4].int;
d:=d+s;e:=e+mem[b+1].int-z-s;end;
if(mem[p].hh.b1)=2 then q:=p else begin r:=mem[p+5].hh.rh;freenode(p,9);
if r=-268435455 then confusion(2021);if x>0 then begin p:=r;repeat q:=r;
r:=mem[r].hh.rh;until r=-268435455;end else begin p:=-268435455;q:=r;
repeat t:=mem[r].hh.rh;mem[r].hh.rh:=p;p:=r;r:=t;until r=-268435455;end;
end{:1743};{1744:}if j=-268435455 then begin r:=newkern(0);
t:=newkern(0);end else begin r:=mem[b+5].hh.rh;t:=mem[r].hh.rh;end;
u:=newmath(0,3);if mem[t].hh.b0=10 then begin j:=newskipparam(8);
mem[q].hh.rh:=j;mem[j].hh.rh:=u;j:=mem[t+1].hh.lh;
mem[tempptr].hh.b0:=mem[j].hh.b0;mem[tempptr].hh.b1:=mem[j].hh.b1;
mem[tempptr+1].int:=e-mem[j+1].int;mem[tempptr+2].int:=-mem[j+2].int;
mem[tempptr+3].int:=-mem[j+3].int;mem[u].hh.rh:=t;
end else begin mem[t+1].int:=e;mem[t].hh.rh:=u;mem[q].hh.rh:=t;end;
u:=newmath(0,2);if mem[r].hh.b0=10 then begin j:=newskipparam(7);
mem[u].hh.rh:=j;mem[j].hh.rh:=p;j:=mem[r+1].hh.lh;
mem[tempptr].hh.b0:=mem[j].hh.b0;mem[tempptr].hh.b1:=mem[j].hh.b1;
mem[tempptr+1].int:=d-mem[j+1].int;mem[tempptr+2].int:=-mem[j+2].int;
mem[tempptr+3].int:=-mem[j+3].int;mem[r].hh.rh:=u;
end else begin mem[r+1].int:=d;mem[r].hh.rh:=p;mem[u].hh.rh:=r;
if j=-268435455 then begin b:=hpack(u,0,1);mem[b+4].int:=s;
end else mem[b+5].hh.rh:=u;end{:1744};end;appendtovlist(b);end;
{:1742}procedure aftermath;var l:boolean;danger:boolean;m:integer;
p:halfword;a:halfword;{1377:}b:halfword;w:scaled;z:scaled;e:scaled;
q:scaled;d:scaled;s:scaled;g1,g2:smallnumber;r:halfword;t:halfword;
pret:halfword;{:1377}{1739:}j:halfword;{:1739}begin danger:=false;
{1740:}if curlist.modefield=207 then j:=curlist.eTeXauxfield{:1740};
{1374:}if(fontparams[eqtb[25595].hh.rh]<22)or(fontparams[eqtb[25611].hh.
rh]<22)or(fontparams[eqtb[25627].hh.rh]<22)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1565);
end;begin helpptr:=3;helpline[2]:=1566;helpline[1]:=1567;
helpline[0]:=1568;end;error;flushmath;danger:=true;
end else if(fontparams[eqtb[25596].hh.rh]<13)or(fontparams[eqtb[25612].
hh.rh]<13)or(fontparams[eqtb[25628].hh.rh]<13)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1569);
end;begin helpptr:=3;helpline[2]:=1570;helpline[1]:=1571;
helpline[0]:=1572;end;error;flushmath;danger:=true;end{:1374};
m:=curlist.modefield;l:=false;p:=finmlist(-268435455);
if curlist.modefield=-m then begin{1376:}begin getxtoken;
if curcmd<>3 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1573);
end;begin helpptr:=2;helpline[1]:=1574;helpline[0]:=1575;end;backerror;
end;end{:1376};curmlist:=p;curstyle:=2;mlistpenalties:=false;
mlisttohlist;a:=hpack(mem[memtop-3].hh.rh,0,1);mem[a].hh.b1:=2;unsave;
decr(saveptr);if savestack[saveptr+0].int=1 then l:=true;danger:=false;
{1740:}if curlist.modefield=207 then j:=curlist.eTeXauxfield{:1740};
{1374:}if(fontparams[eqtb[25595].hh.rh]<22)or(fontparams[eqtb[25611].hh.
rh]<22)or(fontparams[eqtb[25627].hh.rh]<22)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1565);
end;begin helpptr:=3;helpline[2]:=1566;helpline[1]:=1567;
helpline[0]:=1568;end;error;flushmath;danger:=true;
end else if(fontparams[eqtb[25596].hh.rh]<13)or(fontparams[eqtb[25612].
hh.rh]<13)or(fontparams[eqtb[25628].hh.rh]<13)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1569);
end;begin helpptr:=3;helpline[2]:=1570;helpline[1]:=1571;
helpline[0]:=1572;end;error;flushmath;danger:=true;end{:1374};
m:=curlist.modefield;p:=finmlist(-268435455);end else a:=-268435455;
if m<0 then{1375:}begin begin mem[curlist.tailfield].hh.rh:=newmath(eqtb
[27794].int,0);curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
curmlist:=p;curstyle:=2;mlistpenalties:=(curlist.modefield>0);
mlisttohlist;mem[curlist.tailfield].hh.rh:=mem[memtop-3].hh.rh;
while mem[curlist.tailfield].hh.rh<>-268435455 do curlist.tailfield:=mem
[curlist.tailfield].hh.rh;
begin mem[curlist.tailfield].hh.rh:=newmath(eqtb[27794].int,1);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
curlist.auxfield.hh.lh:=1000;unsave;
end{:1375}else begin if a=-268435455 then{1376:}begin getxtoken;
if curcmd<>3 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1573);
end;begin helpptr:=2;helpline[1]:=1574;helpline[0]:=1575;end;backerror;
end;end{:1376};{1378:}curmlist:=p;curstyle:=0;mlistpenalties:=false;
mlisttohlist;p:=mem[memtop-3].hh.rh;adjusttail:=memtop-5;
preadjusttail:=memtop-14;b:=hpack(p,0,1);p:=mem[b+5].hh.rh;
t:=adjusttail;adjusttail:=-268435455;pret:=preadjusttail;
preadjusttail:=-268435455;w:=mem[b+1].int;z:=eqtb[27807].int;
s:=eqtb[27808].int;if eqtb[27275].int<0 then s:=-s-z;
if(a=-268435455)or danger then begin e:=0;q:=0;
end else begin e:=mem[a+1].int;
q:=e+fontinfo[6+parambase[eqtb[25595].hh.rh]].int;end;
if w+q>z then{1380:}begin if(e<>0)and((w-totalshrink[0]+q<=z)or(
totalshrink[1]<>0)or(totalshrink[2]<>0)or(totalshrink[3]<>0))then begin
freenode(b,9);b:=hpack(p,z-q,0);end else begin e:=0;
if w>z then begin freenode(b,9);b:=hpack(p,z,0);end;end;w:=mem[b+1].int;
end{:1380};{1381:}mem[b].hh.b1:=2;d:=half(z-w);
if(e>0)and(d<2*e)then begin d:=half(z-w-e);
if p<>-268435455 then if not(p>=himemmin)then if mem[p].hh.b0=10 then d
:=0;end{:1381};
{1382:}begin mem[curlist.tailfield].hh.rh:=newpenalty(eqtb[27188].int);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if(d+s<=eqtb[27806].int)or l then begin g1:=3;g2:=4;
end else begin g1:=5;g2:=6;end;
if l and(e=0)then begin appdisplay(j,a,0);
begin mem[curlist.tailfield].hh.rh:=newpenalty(10000);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
end else begin mem[curlist.tailfield].hh.rh:=newparamglue(g1);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end{:1382};
{1383:}if e<>0 then begin r:=newkern(z-w-e-d);
if l then begin mem[a].hh.rh:=r;mem[r].hh.rh:=b;b:=a;d:=0;
end else begin mem[b].hh.rh:=r;mem[r].hh.rh:=a;end;b:=hpack(b,0,1);end;
appdisplay(j,b,d){:1383};
{1384:}if(a<>-268435455)and(e=0)and not l then begin begin mem[curlist.
tailfield].hh.rh:=newpenalty(10000);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
appdisplay(j,a,z-mem[a+1].int);g2:=0;end;
if t<>memtop-5 then begin mem[curlist.tailfield].hh.rh:=mem[memtop-5].hh
.rh;curlist.tailfield:=t;end;
if pret<>memtop-14 then begin mem[curlist.tailfield].hh.rh:=mem[memtop
-14].hh.rh;curlist.tailfield:=pret;end;
begin mem[curlist.tailfield].hh.rh:=newpenalty(eqtb[27189].int);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if g2>0 then begin mem[curlist.tailfield].hh.rh:=newparamglue(g2);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end{:1384};
{1741:}flushnodelist(j){:1741};resumeafterdisplay{:1378};end;end;
{:1373}{1379:}procedure resumeafterdisplay;
begin if curgroup<>15 then confusion(1576);unsave;
curlist.pgfield:=curlist.pgfield+3;pushnest;curlist.modefield:=104;
curlist.auxfield.hh.lh:=1000;
if eqtb[27227].int<=0 then curlang:=0 else if eqtb[27227].int>255 then
curlang:=0 else curlang:=eqtb[27227].int;
curlist.auxfield.hh.rh:=curlang;
curlist.pgfield:=(normmin(eqtb[27228].int)*64+normmin(eqtb[27229].int))
*65536+curlang;{472:}begin getxtoken;if curcmd<>10 then backinput;
end{:472};if nestptr=1 then buildpage;end;
{:1379}{1390:}{1394:}procedure getrtoken;label 20;
begin 20:repeat gettoken;until curtok<>2592;
if(curcs=0)or(curcs>eqtbtop)or((curcs>15514)and(curcs<=28082))then begin
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1594);
end;begin helpptr:=5;helpline[4]:=1595;helpline[3]:=1596;
helpline[2]:=1597;helpline[1]:=1598;helpline[0]:=1599;end;
if curcs=0 then backinput;curtok:=19609;inserror;goto 20;end;end;
{:1394}{1408:}procedure trapzeroglue;
begin if(mem[curval+1].int=0)and(mem[curval+2].int=0)and(mem[curval+3].
int=0)then begin incr(mem[membot].hh.rh);deleteglueref(curval);
curval:=membot;end;end;
{:1408}{1415:}procedure doregistercommand(a:smallnumber);label 40,10;
var l,q,r,s:halfword;p:0..3;e:boolean;w:integer;begin q:=curcmd;
e:=false;{1416:}begin if q<>89 then begin getxtoken;
if(curcmd>=73)and(curcmd<=76)then begin l:=curchr;p:=curcmd-73;goto 40;
end;if curcmd<>89 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(787);
end;printcmdchr(curcmd,curchr);print(788);printcmdchr(q,0);
begin helpptr:=1;helpline[0]:=1633;end;error;goto 10;end;end;
if(curchr<membot)or(curchr>membot+19)then begin l:=curchr;
p:=(mem[l].hh.b0 div 16);e:=true;end else begin p:=curchr-membot;
scanregisternum;if curval>255 then begin findsaelement(p,curval,true);
l:=curptr;e:=true;end else case p of 0:l:=curval+27281;
1:l:=curval+27827;2:l:=curval+24546;3:l:=curval+24802;end;end;end;
40:if p<2 then if e then w:=mem[l+2].int else w:=eqtb[l].int else if e
then s:=mem[l+1].hh.rh else s:=eqtb[l].hh.rh{:1416};
if q=89 then scanoptionalequals else if scankeyword(1629)then;
aritherror:=false;
if q<91 then{1417:}if p<2 then begin if p=0 then scanint else scandimen(
false,false,false);if q=90 then curval:=curval+w;
end else begin scanglue(p);if q=90 then{1418:}begin q:=newspec(curval);
r:=s;deleteglueref(curval);mem[q+1].int:=mem[q+1].int+mem[r+1].int;
if mem[q+2].int=0 then mem[q].hh.b0:=0;
if mem[q].hh.b0=mem[r].hh.b0 then mem[q+2].int:=mem[q+2].int+mem[r+2].
int else if(mem[q].hh.b0<mem[r].hh.b0)and(mem[r+2].int<>0)then begin mem
[q+2].int:=mem[r+2].int;mem[q].hh.b0:=mem[r].hh.b0;end;
if mem[q+3].int=0 then mem[q].hh.b1:=0;
if mem[q].hh.b1=mem[r].hh.b1 then mem[q+3].int:=mem[q+3].int+mem[r+3].
int else if(mem[q].hh.b1<mem[r].hh.b1)and(mem[r+3].int<>0)then begin mem
[q+3].int:=mem[r+3].int;mem[q].hh.b1:=mem[r].hh.b1;end;curval:=q;
end{:1418};end{:1417}else{1419:}begin scanint;
if p<2 then if q=91 then if p=0 then curval:=multandadd(w,curval,0,
2147483647)else curval:=multandadd(w,curval,0,1073741823)else curval:=
xovern(w,curval)else begin r:=newspec(s);
if q=91 then begin mem[r+1].int:=multandadd(mem[s+1].int,curval,0,
1073741823);mem[r+2].int:=multandadd(mem[s+2].int,curval,0,1073741823);
mem[r+3].int:=multandadd(mem[s+3].int,curval,0,1073741823);
end else begin mem[r+1].int:=xovern(mem[s+1].int,curval);
mem[r+2].int:=xovern(mem[s+2].int,curval);
mem[r+3].int:=xovern(mem[s+3].int,curval);end;curval:=r;end;end{:1419};
if aritherror then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1630);
end;begin helpptr:=2;helpline[1]:=1631;helpline[0]:=1632;end;
if p>=2 then deleteglueref(curval);error;goto 10;end;
if p<2 then if e then if(a>=4)then gsawdef(l,curval)else sawdef(l,curval
)else if(a>=4)then geqworddefine(l,curval)else eqworddefine(l,curval)
else begin trapzeroglue;
if e then if(a>=4)then gsadef(l,curval)else sadef(l,curval)else if(a>=4)
then geqdefine(l,119,curval)else eqdefine(l,119,curval);end;10:end;
{:1415}{1422:}procedure alteraux;var c:halfword;
begin if curchr<>abs(curlist.modefield)then reportillegalcase else begin
c:=curchr;scanoptionalequals;
if c=1 then begin scandimen(false,false,false);
curlist.auxfield.int:=curval;end else begin scanint;
if(curval<=0)or(curval>32767)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1636);
end;begin helpptr:=1;helpline[0]:=1637;end;interror(curval);
end else curlist.auxfield.hh.lh:=curval;end;end;end;
{:1422}{1423:}procedure alterprevgraf;var p:0..nestsize;
begin nest[nestptr]:=curlist;p:=nestptr;
while abs(nest[p].modefield)<>1 do decr(p);scanoptionalequals;scanint;
if curval<0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1358);
end;printesc(610);begin helpptr:=1;helpline[0]:=1638;end;
interror(curval);end else begin nest[p].pgfield:=curval;
curlist:=nest[nestptr];end;end;{:1423}{1424:}procedure alterpagesofar;
var c:0..7;begin c:=curchr;scanoptionalequals;
scandimen(false,false,false);pagesofar[c]:=curval;end;
{:1424}{1425:}procedure alterinteger;var c:smallnumber;begin c:=curchr;
scanoptionalequals;scanint;
if c=0 then deadcycles:=curval{1694:}else if c=2 then begin if(curval<0)
or(curval>3)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(2006);
end;begin helpptr:=2;helpline[1]:=2007;helpline[0]:=2008;end;
interror(curval);end else begin curchr:=curval;newinteraction;end;
end{:1694}else insertpenalties:=curval;end;
{:1425}{1426:}procedure alterboxdimen;var c:smallnumber;b:halfword;
begin c:=curchr;scanregisternum;
if curval<256 then b:=eqtb[25333+curval].hh.rh else begin findsaelement(
4,curval,false);
if curptr=-268435455 then b:=-268435455 else b:=mem[curptr+1].hh.rh;end;
scanoptionalequals;scandimen(false,false,false);
if b<>-268435455 then mem[b+c].int:=curval;end;
{:1426}{1436:}procedure newfont(a:smallnumber);label 50;var u:halfword;
s:scaled;f:internalfontnumber;t:strnumber;oldsetting:0..21;
begin if jobname=0 then openlogfile;getrtoken;u:=curcs;
if u>=514 then t:=hash[u].rh else if u>=257 then if u=513 then t:=1090
else t:=u-257 else begin oldsetting:=selector;selector:=21;print(1090);
print(u-1);selector:=oldsetting;
begin if poolptr+1>poolsize then overflow(259,poolsize-initpoolptr);end;
t:=makestring;end;if(a>=4)then geqdefine(u,87,0)else eqdefine(u,87,0);
scanoptionalequals;scanfilename;{1437:}nameinprogress:=true;
if scankeyword(1652)then{1438:}begin scandimen(false,false,false);
s:=curval;
if(s<=0)or(s>=134217728)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1654);
end;printscaled(s);print(1655);begin helpptr:=2;helpline[1]:=1656;
helpline[0]:=1657;end;error;s:=10*65536;end;
end{:1438}else if scankeyword(1653)then begin scanint;s:=-curval;
if(curval<=0)or(curval>32768)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(634);
end;begin helpptr:=1;helpline[0]:=635;end;interror(curval);s:=-1000;end;
end else s:=-1000;nameinprogress:=false{:1437};
{1439:}for f:=1 to fontptr do if streqstr(fontname[f],curname)and
streqstr(fontarea[f],curarea)then begin if pdffontstep[f]=0 then begin
if s>0 then begin if s=fontsize[f]then goto 50;
end else if fontsize[f]=xnoverd(fontdsize[f],-s,1000)then goto 50;
end end{:1439};f:=readfontinfo(u,curname,curarea,s);
50:if(a>=4)then geqdefine(u,87,f)else eqdefine(u,87,f);
eqtb[15526+f]:=eqtb[u];hash[15526+f].rh:=t;end;
{:1436}{1444:}procedure newinteraction;begin println;
interaction:=curchr;
if interaction=0 then kpsemaketexdiscarderrors:=1 else
kpsemaketexdiscarderrors:=0;
{75:}if interaction=0 then selector:=16 else selector:=17{:75};
if logopened then selector:=selector+2;end;
{:1444}procedure prefixedcommand;label 30,10;var a:smallnumber;
f:internalfontnumber;j:halfword;k:fontindex;p,q,r:halfword;n:integer;
e:boolean;begin a:=0;
while curcmd=93 do begin if not odd(a div curchr)then a:=a+curchr;
{433:}repeat getxtoken;until(curcmd<>10)and(curcmd<>0){:433};
if curcmd<=70 then{1391:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1586);
end;printcmdchr(curcmd,curchr);printchar(39);begin helpptr:=1;
helpline[0]:=1587;end;if(eTeXmode=1)then helpline[0]:=1588;backerror;
goto 10;end{:1391};
if eqtb[27213].int>2 then if(eTeXmode=1)then showcurcmdchr;end;
{1392:}if a>=8 then begin j:=3585;a:=a-8;end else j:=0;
if(curcmd<>97)and((a mod 4<>0)or(j<>0))then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(264);
print(787);end;printesc(1578);print(1589);printesc(1579);
begin helpptr:=1;helpline[0]:=1590;end;
if(eTeXmode=1)then begin helpline[0]:=1591;print(1589);printesc(1592);
end;print(1593);printcmdchr(curcmd,curchr);printchar(39);error;
end{:1392};
{1393:}if eqtb[27220].int<>0 then if eqtb[27220].int<0 then begin if(a>=
4)then a:=a-4;end else begin if not(a>=4)then a:=a+4;end{:1393};
case curcmd of{1396:}87:if(a>=4)then geqdefine(25589,122,curchr)else
eqdefine(25589,122,curchr);
{:1396}{1397:}97:begin if odd(curchr)and not(a>=4)and(eqtb[27220].int>=0
)then a:=a+4;e:=(curchr>=2);getrtoken;p:=curcs;q:=scantoks(true,e);
if j<>0 then begin q:=getavail;mem[q].hh.lh:=j;
mem[q].hh.rh:=mem[defref].hh.rh;mem[defref].hh.rh:=q;end;
if(a>=4)then geqdefine(p,113+(a mod 4),defref)else eqdefine(p,113+(a mod
4),defref);end;
{:1397}{1400:}94:if curchr=11 then else if curchr=10 then begin selector
:=19;gettoken;mubytestoken:=curtok;
if curtok<=4095 then mubytestoken:=curtok mod 256;mubyteprefix:=60;
mubyterelax:=false;mubytetablein:=true;mubytetableout:=true;getxtoken;
if curcmd=10 then getxtoken;
if curcmd=8 then begin mubytetableout:=false;getxtoken;
if curcmd=8 then begin mubytetableout:=true;mubytetablein:=false;
getxtoken;end;
end else if(mubytestoken>4095)and(curcmd=6)then begin mubytetableout:=
false;scanint;mubyteprefix:=curval;getxtoken;
if mubyteprefix>50 then mubyteprefix:=52;
if mubyteprefix<=0 then mubyteprefix:=51;
end else if(mubytestoken>4095)and(curcmd=0)then begin mubytetableout:=
true;mubytetablein:=false;mubyterelax:=true;getxtoken;end;r:=getavail;
p:=r;while curcs=0 do begin begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=curtok;p:=q;end;getxtoken;end;
if(curcmd<>67)or(curchr<>10)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(713);
end;printesc(590);print(714);begin helpptr:=2;helpline[1]:=715;
helpline[0]:=1605;end;backerror;end;p:=mem[r].hh.rh;
if(p=-268435455)and mubytetablein then begin begin if interaction=3 then
;if filelineerrorstylep then printfileline else printnl(264);
print(1606);end;printesc(1603);print(1607);begin helpptr:=2;
helpline[1]:=1608;helpline[0]:=1609;end;error;
end else begin while p<>-268435455 do begin begin strpool[poolptr]:=mem[
p].hh.lh mod 256;incr(poolptr);end;p:=mem[p].hh.rh;end;flushlist(r);
if(strstart[strptr]+1=poolptr)and(strpool[poolptr-1]=mubytestoken)then
begin if mubyteread[mubytestoken]<>-268435455 and mubytetablein then
disposemunode(mubyteread[mubytestoken]);
if mubytetablein then mubyteread[mubytestoken]:=-268435455;
if mubytetableout then mubytewrite[mubytestoken]:=0;
poolptr:=strstart[strptr];
end else begin if mubytetablein then mubyteupdate;
if mubytetableout then begin if mubytestoken>4095 then begin
disposemutableout(mubytestoken-4095);
if(strstart[strptr]<poolptr)or mubyterelax then begin r:=mubytecswrite[(
mubytestoken-4095)mod 128];p:=getavail;
mubytecswrite[(mubytestoken-4095)mod 128]:=p;
mem[p].hh.lh:=mubytestoken-4095;mem[p].hh.rh:=getavail;p:=mem[p].hh.rh;
if mubyterelax then begin mem[p].hh.lh:=0;poolptr:=strstart[strptr];
end else mem[p].hh.lh:=slowmakestring;mem[p].hh.rh:=r;end;
end else begin if strstart[strptr]=poolptr then mubytewrite[mubytestoken
]:=0 else mubytewrite[mubytestoken]:=slowmakestring;end;
end else poolptr:=strstart[strptr];end;end;end else begin n:=curchr;
getrtoken;p:=curcs;if n=0 then begin repeat gettoken;until curcmd<>10;
if curtok=3133 then begin gettoken;if curcmd=10 then gettoken;end;
end else begin gettoken;q:=curtok;gettoken;backinput;curtok:=q;
backinput;end;
if curcmd>=113 then incr(mem[curchr].hh.lh)else if(curcmd=89)or(curcmd=
71)then if(curchr<membot)or(curchr>membot+19)then incr(mem[curchr+1].hh.
lh);
if(a>=4)then geqdefine(p,curcmd,curchr)else eqdefine(p,curcmd,curchr);
end;{:1400}{1403:}95:if curchr=7 then begin scancharnum;p:=26921+curval;
scanoptionalequals;scancharnum;n:=curval;scancharnum;
if(eqtb[27234].int>0)then begin begindiagnostic;printnl(1618);
print(p-26921);print(1619);print(n);printchar(32);print(curval);
enddiagnostic(false);end;n:=n*256+curval;
if(a>=4)then geqdefine(p,122,n)else eqdefine(p,122,n);
if(p-26921)<eqtb[27232].int then if(a>=4)then geqworddefine(27232,p
-26921)else eqworddefine(27232,p-26921);
if(p-26921)>eqtb[27233].int then if(a>=4)then geqworddefine(27233,p
-26921)else eqworddefine(27233,p-26921);end else begin n:=curchr;
getrtoken;p:=curcs;
if(a>=4)then geqdefine(p,0,256)else eqdefine(p,0,256);
scanoptionalequals;case n of 0:begin scancharnum;
if(a>=4)then geqdefine(p,68,curval)else eqdefine(p,68,curval);end;
1:begin scanfifteenbitint;
if(a>=4)then geqdefine(p,69,curval)else eqdefine(p,69,curval);end;
others:begin scanregisternum;if curval>255 then begin j:=n-2;
if j>3 then j:=5;findsaelement(j,curval,true);incr(mem[curptr+1].hh.lh);
if j=5 then j:=71 else j:=89;
if(a>=4)then geqdefine(p,j,curptr)else eqdefine(p,j,curptr);
end else case n of 2:if(a>=4)then geqdefine(p,73,27281+curval)else
eqdefine(p,73,27281+curval);
3:if(a>=4)then geqdefine(p,74,27827+curval)else eqdefine(p,74,27827+
curval);
4:if(a>=4)then geqdefine(p,75,24546+curval)else eqdefine(p,75,24546+
curval);
5:if(a>=4)then geqdefine(p,76,24802+curval)else eqdefine(p,76,24802+
curval);
6:if(a>=4)then geqdefine(p,72,25073+curval)else eqdefine(p,72,25073+
curval);end;end end;end;{:1403}{1404:}96:begin j:=curchr;scanint;
n:=curval;
if not scankeyword(1234)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1476);
end;begin helpptr:=2;helpline[1]:=1620;helpline[0]:=1621;end;error;end;
getrtoken;p:=curcs;readtoks(n,p,j);
if(a>=4)then geqdefine(p,113,curval)else eqdefine(p,113,curval);end;
{:1404}{1405:}71,72:begin q:=curcs;e:=false;
if curcmd=71 then if curchr=membot then begin scanregisternum;
if curval>255 then begin findsaelement(5,curval,true);curchr:=curptr;
e:=true;end else curchr:=25073+curval;end else e:=true;p:=curchr;
scanoptionalequals;{433:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:433};
if curcmd<>1 then{1406:}if(curcmd=71)or(curcmd=72)then begin if curcmd=
71 then if curchr=membot then begin scanregisternum;
if curval<256 then q:=eqtb[25073+curval].hh.rh else begin findsaelement(
5,curval,false);
if curptr=-268435455 then q:=-268435455 else q:=mem[curptr+1].hh.rh;end;
end else q:=mem[curchr+1].hh.rh else q:=eqtb[curchr].hh.rh;
if q=-268435455 then if e then if(a>=4)then gsadef(p,-268435455)else
sadef(p,-268435455)else if(a>=4)then geqdefine(p,103,-268435455)else
eqdefine(p,103,-268435455)else begin incr(mem[q].hh.lh);
if e then if(a>=4)then gsadef(p,q)else sadef(p,q)else if(a>=4)then
geqdefine(p,113,q)else eqdefine(p,113,q);end;goto 30;end{:1406};
backinput;curcs:=q;q:=scantoks(false,false);
if mem[defref].hh.rh=-268435455 then begin if e then if(a>=4)then gsadef
(p,-268435455)else sadef(p,-268435455)else if(a>=4)then geqdefine(p,103,
-268435455)else eqdefine(p,103,-268435455);
begin mem[defref].hh.rh:=avail;avail:=defref;ifdef('STAT')decr(dynused);
endif('STAT')end;
end else begin if(p=25059)and not e then begin mem[q].hh.rh:=getavail;
q:=mem[q].hh.rh;mem[q].hh.lh:=637;q:=getavail;mem[q].hh.lh:=379;
mem[q].hh.rh:=mem[defref].hh.rh;mem[defref].hh.rh:=q;end;
if e then if(a>=4)then gsadef(p,defref)else sadef(p,defref)else if(a>=4)
then geqdefine(p,113,defref)else eqdefine(p,113,defref);end;end;
{:1405}{1407:}73:begin p:=curchr;scanoptionalequals;scanint;
if(a>=4)then geqworddefine(p,curval)else eqworddefine(p,curval);end;
74:begin p:=curchr;scanoptionalequals;scandimen(false,false,false);
if(a>=4)then geqworddefine(p,curval)else eqworddefine(p,curval);end;
75,76:begin p:=curchr;n:=curcmd;scanoptionalequals;
if n=76 then scanglue(3)else scanglue(2);trapzeroglue;
if(a>=4)then geqdefine(p,119,curval)else eqdefine(p,119,curval);end;
{:1407}{1411:}85:begin{1412:}if curchr=25641 then n:=15 else if curchr=
26665 then n:=32768 else if curchr=26409 then n:=32767 else if curchr=
27537 then n:=16777215 else n:=255{:1412};p:=curchr;scancharnum;
if p=25590 then p:=curval else if p=25591 then p:=curval+256 else if p=
25592 then p:=curval+512 else p:=p+curval;scanoptionalequals;scanint;
if((curval<0)and(p<27537))or(curval>n)then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(264);
print(1625);end;printint(curval);
if p<27537 then print(1626)else print(1627);printint(n);
begin helpptr:=1;helpline[0]:=1628;end;error;curval:=0;end;
if p<256 then xord[p]:=curval else if p<512 then xchr[p-256]:=curval
else if p<768 then xprn[p-512]:=curval else if p<26665 then if(a>=4)then
geqdefine(p,122,curval)else eqdefine(p,122,curval)else if p<27537 then
if(a>=4)then geqdefine(p,122,curval)else eqdefine(p,122,curval)else if(a
>=4)then geqworddefine(p,curval)else eqworddefine(p,curval);end;
{:1411}{1413:}86:begin p:=curchr;scanfourbitint;p:=p+curval;
scanoptionalequals;scanfontident;
if(a>=4)then geqdefine(p,122,curval)else eqdefine(p,122,curval);end;
{:1413}{1414:}89,90,91,92:doregistercommand(a);
{:1414}{1420:}98:begin scanregisternum;
if(a>=4)then n:=1073774592+curval else n:=1073741824+curval;
scanoptionalequals;
if setboxallowed then scanbox(n)else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(782);
end;printesc(614);begin helpptr:=2;helpline[1]:=1634;helpline[0]:=1635;
end;error;end;end;{:1420}{1421:}79:alteraux;80:alterprevgraf;
81:alterpagesofar;82:alterinteger;83:alterboxdimen;
{:1421}{1427:}84:begin q:=curchr;scanoptionalequals;scanint;n:=curval;
if n<=0 then p:=-268435455 else if q>25058 then begin n:=(curval div 2)
+1;p:=getnode(2*n+1);mem[p].hh.lh:=n;n:=curval;mem[p+1].int:=n;
for j:=p+2 to p+n+1 do begin scanint;mem[j].int:=curval;end;
if not odd(n)then mem[p+n+2].int:=0;end else begin p:=getnode(2*n+1);
mem[p].hh.lh:=n;for j:=1 to n do begin scandimen(false,false,false);
mem[p+2*j-1].int:=curval;scandimen(false,false,false);
mem[p+2*j].int:=curval;end;end;
if(a>=4)then geqdefine(q,120,p)else eqdefine(q,120,p);end;
{:1427}{1431:}99:if curchr=1 then begin ifdef('INITEX')if iniversion
then begin newpatterns;goto 30;end;
endif('INITEX')begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1639);
end;helpptr:=0;error;repeat gettoken;until curcmd=2;goto 10;
end else begin newhyphexceptions;goto 30;end;
{:1431}{1432:}77:begin findfontdimen(true);k:=curval;scanoptionalequals;
scandimen(false,false,false);fontinfo[k].int:=curval;end;
78:begin n:=curchr;scanfontident;f:=curval;
if n=6 then setnoligatures(f)else if n<2 then begin scanoptionalequals;
scanint;if n=0 then hyphenchar[f]:=curval else skewchar[f]:=curval;
end else begin scancharnum;p:=curval;scanoptionalequals;scanint;
case n of 2:setlpcode(f,p,curval);3:setrpcode(f,p,curval);
4:setefcode(f,p,curval);5:settagcode(f,p,curval);
7:setknbscode(f,p,curval);8:setstbscode(f,p,curval);
9:setshbscode(f,p,curval);10:setknbccode(f,p,curval);
11:setknaccode(f,p,curval);end;end;end;{:1432}{1435:}88:newfont(a);
101:newletterspacedfont(a);102:makefontcopy(a);
{:1435}{1443:}100:newinteraction;{:1443}others:confusion(1585)end;
30:{1448:}if aftertoken<>0 then begin curtok:=aftertoken;backinput;
aftertoken:=0;end{:1448};10:end;{:1390}{1449:}procedure doassignments;
label 10;begin while true do begin{433:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:433};if curcmd<=70 then goto 10;
setboxallowed:=false;prefixedcommand;setboxallowed:=true;end;10:end;
{:1449}{1454:}procedure openorclosein;var c:0..1;n:0..15;
begin c:=curchr;scanfourbitint;n:=curval;
if readopen[n]<>2 then begin aclose(readfile[n]);readopen[n]:=2;end;
if c<>0 then begin scanoptionalequals;scanfilename;
packfilename(curname,curarea,curext);texinputtype:=0;
if kpseinnameok(stringcast(nameoffile+1))and aopenin(readfile[n],
kpsetexformat)then readopen[n]:=1;end;end;
{:1454}{1458:}procedure issuemessage;var oldsetting:0..21;c:0..1;
s:strnumber;begin c:=curchr;mem[memtop-12].hh.rh:=scantoks(false,true);
oldsetting:=selector;selector:=21;messageprinting:=true;
activenoconvert:=true;tokenshow(defref);messageprinting:=false;
activenoconvert:=false;selector:=oldsetting;flushlist(defref);
begin if poolptr+1>poolsize then overflow(259,poolsize-initpoolptr);end;
s:=makestring;
if c=0 then{1459:}begin if termoffset+(strstart[s+1]-strstart[s])>
maxprintline-2 then println else if(termoffset>0)or(fileoffset>0)then
printchar(32);print(s);fflush(stdout);
end{:1459}else{1462:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(345);
end;print(s);
if eqtb[25067].hh.rh<>-268435455 then useerrhelp:=true else if
longhelpseen then begin helpptr:=1;helpline[0]:=1664;
end else begin if interaction<3 then longhelpseen:=true;
begin helpptr:=4;helpline[3]:=1665;helpline[2]:=1666;helpline[1]:=1667;
helpline[0]:=1668;end;end;error;useerrhelp:=false;end{:1462};
begin decr(strptr);poolptr:=strstart[strptr];end;end;
{:1458}{1467:}procedure shiftcase;var b:halfword;p:halfword;t:halfword;
c:eightbits;begin b:=curchr;p:=scantoks(false,false);
p:=mem[defref].hh.rh;while p<>-268435455 do begin{1468:}t:=mem[p].hh.lh;
if t<4352 then begin c:=t mod 256;
if eqtb[b+c].hh.rh<>0 then mem[p].hh.lh:=t-c+eqtb[b+c].hh.rh;end{:1468};
p:=mem[p].hh.rh;end;begintokenlist(mem[defref].hh.rh,3);
begin mem[defref].hh.rh:=avail;avail:=defref;ifdef('STAT')decr(dynused);
endif('STAT')end;end;{:1467}{1472:}procedure showwhatever;label 50;
var p:halfword;t:smallnumber;m:0..4;l:integer;n:integer;
begin case curchr of 3:begin begindiagnostic;showactivities;end;
1:{1475:}begin scanregisternum;
if curval<256 then p:=eqtb[25333+curval].hh.rh else begin findsaelement(
4,curval,false);
if curptr=-268435455 then p:=-268435455 else p:=mem[curptr+1].hh.rh;end;
begindiagnostic;printnl(1684);printint(curval);printchar(61);
if p=-268435455 then print(430)else showbox(p);end{:1475};
0:{1473:}begin gettoken;if interaction=3 then;printnl(1680);
if curcs<>0 then begin sprintcs(curcs);printchar(61);end;printmeaning;
goto 50;end{:1473};{1675:}4:begin begindiagnostic;showsavegroups;end;
{:1675}{1689:}6:begin begindiagnostic;printnl(345);println;
if condptr=-268435455 then begin printnl(379);print(2003);
end else begin p:=condptr;n:=0;repeat incr(n);p:=mem[p].hh.rh;
until p=-268435455;p:=condptr;t:=curif;l:=ifline;m:=iflimit;
repeat printnl(2004);printint(n);print(649);printcmdchr(107,t);
if m=2 then printesc(931);if l<>0 then begin print(2002);printint(l);
end;decr(n);t:=mem[p].hh.b1;l:=mem[p+1].int;m:=mem[p].hh.b0;
p:=mem[p].hh.rh;until p=-268435455;end;end;
{:1689}others:{1476:}begin p:=thetoks;if interaction=3 then;
printnl(1680);tokenshow(memtop-3);flushlist(mem[memtop-3].hh.rh);
goto 50;end{:1476}end;{1477:}enddiagnostic(true);
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1685);
end;if selector=19 then if eqtb[27206].int<=0 then begin selector:=17;
print(1686);selector:=19;end{:1477};
50:if interaction<3 then begin helpptr:=0;decr(errorcount);
end else if eqtb[27206].int>0 then begin begin helpptr:=3;
helpline[2]:=1675;helpline[1]:=1676;helpline[0]:=1677;end;
end else begin begin helpptr:=5;helpline[4]:=1675;helpline[3]:=1676;
helpline[2]:=1677;helpline[1]:=1678;helpline[0]:=1679;end;end;error;end;
{:1472}{1481:}ifdef('INITEX')procedure storefmtfile;label 41,42,31,32;
var j,k,l:integer;p,q:halfword;x:integer;formatengine:^ASCIIcode;
begin{1483:}if saveptr<>0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1688);
end;begin helpptr:=1;helpline[0]:=1689;end;
begin if interaction=3 then interaction:=2;if logopened then error;
ifdef('TEXMF_DEBUG')if interaction>0 then debughelp;
endif('TEXMF_DEBUG')history:=3;jumpout;end;end{:1483};
{1509:}selector:=21;print(1707);print(jobname);printchar(32);
printint(eqtb[27200].int);printchar(46);printint(eqtb[27199].int);
printchar(46);printint(eqtb[27198].int);printchar(41);
if interaction=0 then selector:=18 else selector:=19;
begin if poolptr+1>poolsize then overflow(259,poolsize-initpoolptr);end;
formatident:=makestring;packjobname(939);
while not wopenout(fmtfile)do promptfilename(1708,939);printnl(1709);
slowprint(wmakenamestring(fmtfile));begin decr(strptr);
poolptr:=strstart[strptr];end;printnl(345);
slowprint(formatident){:1509};{1486:}dumpint(1462916184);
x:=strlen(enginename);formatengine:=xmallocarray(ASCIIcode,x+4);
strcpy(stringcast(formatengine),enginename);
for k:=x to x+3 do formatengine[k]:=0;x:=x+4-(x mod 4);dumpint(x);
dumpthings(formatengine[0],x);libcfree(formatengine);dumpint(490236648);
{1872:}dumpthings(xord[0],256);dumpthings(xchr[0],256);
dumpthings(xprn[0],256);{:1872};dumpint(268435455);dumpint(hashhigh);
{1652:}dumpint(eTeXmode);for j:=0 to-0 do eqtb[27279+j].int:=0;
{:1652}{1756:}while pseudofiles<>-268435455 do pseudoclose;
{:1756}dumpint(membot);dumpint(memtop);dumpint(28082);dumpint(8501);
dumpint(607){:1486};{1886:}dumpint(1296847960);
if mltexp then dumpint(1)else dumpint(0);{:1886};
{1895:}dumpint(1162040408);
if not enctexp then dumpint(0)else begin dumpint(1);
dumpthings(mubyteread[0],256);dumpthings(mubytewrite[0],256);
dumpthings(mubytecswrite[0],128);end;{:1895};{1488:}dumpint(poolptr);
dumpint(strptr);dumpthings(strstart[0],strptr+1);
dumpthings(strpool[0],poolptr);println;printint(strptr);print(1690);
printint(poolptr){:1488};{1490:}sortavail;varused:=0;dumpint(lomemmax);
dumpint(rover);if(eTeXmode=1)then for k:=0 to 5 do dumpint(saroot[k]);
p:=membot;q:=rover;x:=0;repeat dumpthings(mem[p],q+2-p);x:=x+q+2-p;
varused:=varused+q-p;p:=q+mem[q].hh.lh;q:=mem[q+1].hh.rh;until q=rover;
varused:=varused+lomemmax-p;dynused:=memend+1-himemmin;
dumpthings(mem[p],lomemmax+1-p);x:=x+lomemmax+1-p;dumpint(himemmin);
dumpint(avail);dumpthings(mem[himemmin],memend+1-himemmin);
x:=x+memend+1-himemmin;p:=avail;
while p<>-268435455 do begin decr(dynused);p:=mem[p].hh.rh;end;
dumpint(varused);dumpint(dynused);println;printint(x);print(1691);
printint(varused);printchar(38);printint(dynused){:1490};
{1492:}{1494:}k:=1;repeat j:=k;
while j<27176 do begin if(eqtb[j].hh.rh=eqtb[j+1].hh.rh)and(eqtb[j].hh.
b0=eqtb[j+1].hh.b0)and(eqtb[j].hh.b1=eqtb[j+1].hh.b1)then goto 41;
incr(j);end;l:=27177;goto 31;41:incr(j);l:=j;
while j<27176 do begin if(eqtb[j].hh.rh<>eqtb[j+1].hh.rh)or(eqtb[j].hh.
b0<>eqtb[j+1].hh.b0)or(eqtb[j].hh.b1<>eqtb[j+1].hh.b1)then goto 31;
incr(j);end;31:dumpint(l-k);dumpthings(eqtb[k],l-k);k:=j+1;dumpint(k-l);
until k=27177{:1494};{1495:}repeat j:=k;
while j<28082 do begin if eqtb[j].int=eqtb[j+1].int then goto 42;
incr(j);end;l:=28083;goto 32;42:incr(j);l:=j;
while j<28082 do begin if eqtb[j].int<>eqtb[j+1].int then goto 32;
incr(j);end;32:dumpint(l-k);dumpthings(eqtb[k],l-k);k:=j+1;dumpint(k-l);
until k>28082;if hashhigh>0 then dumpthings(eqtb[28083],hashhigh);
{:1495};dumpint(parloc);dumpint(writeloc);
{1497:}for p:=0 to 2100 do dumphh(prim[p]);
for p:=0 to 2100 do dumpwd(primeqtb[p]);dumpint(hashused);
cscount:=15513-hashused+hashhigh;
for p:=514 to hashused do if hash[p].rh<>0 then begin dumpint(p);
dumphh(hash[p]);incr(cscount);end;
dumpthings(hash[hashused+1],24526-hashused);
if hashhigh>0 then dumpthings(hash[28083],hashhigh);dumpint(cscount);
println;printint(cscount);print(1692){:1497}{:1492};
{1499:}dumpint(fmemptr);dumpthings(fontinfo[0],fmemptr);
dumpint(fontptr);{1501:}begin dumpthings(fontcheck[0],fontptr+1);
dumpthings(fontsize[0],fontptr+1);dumpthings(fontdsize[0],fontptr+1);
dumpthings(fontparams[0],fontptr+1);dumpthings(hyphenchar[0],fontptr+1);
dumpthings(skewchar[0],fontptr+1);dumpthings(fontname[0],fontptr+1);
dumpthings(fontarea[0],fontptr+1);dumpthings(fontbc[0],fontptr+1);
dumpthings(fontec[0],fontptr+1);dumpthings(charbase[0],fontptr+1);
dumpthings(widthbase[0],fontptr+1);dumpthings(heightbase[0],fontptr+1);
dumpthings(depthbase[0],fontptr+1);dumpthings(italicbase[0],fontptr+1);
dumpthings(ligkernbase[0],fontptr+1);dumpthings(kernbase[0],fontptr+1);
dumpthings(extenbase[0],fontptr+1);dumpthings(parambase[0],fontptr+1);
dumpthings(fontglue[0],fontptr+1);dumpthings(bcharlabel[0],fontptr+1);
dumpthings(fontbchar[0],fontptr+1);
dumpthings(fontfalsebchar[0],fontptr+1);
for k:=0 to fontptr do begin printnl(1696);printesc(hash[15526+k].rh);
printchar(61);printfilename(fontname[k],fontarea[k],345);
if fontsize[k]<>fontdsize[k]then begin print(895);
printscaled(fontsize[k]);print(312);end;end;end{:1501};println;
printint(fmemptr-7);print(1693);printint(fontptr-0);
if fontptr<>1 then print(1694)else print(1695){:1499};
{1503:}dumpint(hyphcount);if hyphnext<=607 then hyphnext:=hyphsize;
dumpint(hyphnext);
for k:=0 to hyphsize do if hyphword[k]<>0 then begin dumpint(k+65536*
hyphlink[k]);dumpint(hyphword[k]);dumpint(hyphlist[k]);end;println;
printint(hyphcount);if hyphcount<>1 then print(1697)else print(1698);
if trienotready then inittrie;dumpint(triemax);dumpint(hyphstart);
dumpthings(trietrl[0],triemax+1);dumpthings(trietro[0],triemax+1);
dumpthings(trietrc[0],triemax+1);dumpint(trieopptr);
dumpthings(hyfdistance[1],trieopptr);dumpthings(hyfnum[1],trieopptr);
dumpthings(hyfnext[1],trieopptr);printnl(1699);printint(triemax);
print(1700);printint(trieopptr);
if trieopptr<>1 then print(1701)else print(1702);print(1703);
printint(trieopsize);
for k:=255 downto 0 do if trieused[k]>0 then begin printnl(955);
printint(trieused[k]);print(1704);printint(k);dumpint(k);
dumpint(trieused[k]);end{:1503};{1505:}begin dumpimagemeta;
dumpint(pdfmemsize);dumpint(pdfmemptr);
for k:=1 to pdfmemptr-1 do begin dumpint(pdfmem[k]);end;println;
printint(pdfmemptr-1);print(1705);dumpint(objtabsize);dumpint(objptr);
dumpint(sysobjptr);
for k:=1 to sysobjptr do begin dumpint(objtab[k].int0);
dumpint(objtab[k].int1);dumpint(objtab[k].int3);dumpint(objtab[k].int4);
end;println;printint(sysobjptr);print(1706);dumpint(pdfobjcount);
dumpint(pdfxformcount);dumpint(pdfximagecount);dumpint(headtab[6]);
dumpint(headtab[7]);dumpint(headtab[8]);dumpint(pdflastobj);
dumpint(pdflastxform);dumpint(pdflastximage);end{:1505};
{1507:}dumpint(interaction);dumpint(formatident);dumpint(69069);
eqtb[27208].int:=0{:1507};{1510:}wclose(fmtfile){:1510};end;
endif('INITEX'){:1481}{1529:}{1530:}procedure newwhatsit(s:smallnumber;
w:smallnumber);var p:halfword;begin p:=getnode(w);mem[p].hh.b0:=8;
mem[p].hh.b1:=s;mem[curlist.tailfield].hh.rh:=p;curlist.tailfield:=p;
end;{:1530}{1531:}procedure newwritewhatsit(w:smallnumber);
begin newwhatsit(curchr,w);
if w<>2 then scanfourbitint else begin scanint;
if curval<0 then curval:=17 else if(curval>15)and(curval<>18)then curval
:=16;end;mem[curlist.tailfield+1].hh.b0:=curval;
if eqtb[27236].int+64<0 then mem[curlist.tailfield+1].hh.b1:=0 else if
eqtb[27236].int+64>=2*64 then mem[curlist.tailfield+1].hh.b1:=2*64-1
else mem[curlist.tailfield+1].hh.b1:=eqtb[27236].int+64;end;
{:1531}{1538:}procedure checkpdfoutput(s:strnumber;iserror:boolean);
begin if eqtb[27239].int<=0 then begin if iserror then pdferror(s,1767)
else pdfwarning(s,1768,true,true);end end;procedure scanpdfexttoks;
begin begin if scantoks(false,true)<>0 then end;end;
procedure comparestrings;label 30;var s1,s2:strnumber;
i1,i2,j1,j2:poolpointer;begin begin if scantoks(false,true)<>0 then end;
s1:=tokenstostring(defref);deletetokenref(defref);
begin if scantoks(false,true)<>0 then end;s2:=tokenstostring(defref);
deletetokenref(defref);i1:=strstart[s1];j1:=strstart[s1+1];
i2:=strstart[s2];j2:=strstart[s2+1];
while(i1<j1)and(i2<j2)do begin if strpool[i1]<strpool[i2]then begin
curval:=-1;goto 30;end;if strpool[i1]>strpool[i2]then begin curval:=1;
goto 30;end;incr(i1);incr(i2);end;
if(i1=j1)and(i2=j2)then curval:=0 else if i1<j1 then curval:=1 else
curval:=-1;30:flushstr(s2);flushstr(s1);curvallevel:=0;end;
{:1538}{1553:}procedure scaleimage(n:integer);var x,y,xr,yr:integer;
w,h:scaled;defaultres:integer;image:integer;
begin image:=pdfmem[objtab[n].int4+4];
if(imagerotate(image)=90)or(imagerotate(image)=270)then begin y:=
imagewidth(image);x:=imageheight(image);yr:=imagexres(image);
xr:=imageyres(image);end else begin x:=imagewidth(image);
y:=imageheight(image);xr:=imagexres(image);yr:=imageyres(image);end;
if(xr>65535)or(yr>65535)then begin xr:=0;yr:=0;
pdfwarning(1766,1798,true,true);end;
if(x<=0)or(y<=0)or(xr<0)or(yr<0)then pdferror(1766,1799);
if ispdfimage(image)then begin w:=x;h:=y;
end else begin defaultres:=fixint(eqtb[27243].int,0,65535);
if(defaultres>0)and((xr=0)or(yr=0))then begin xr:=defaultres;
yr:=defaultres;end;
if(pdfmem[objtab[n].int4+0]=-1073741824)and(pdfmem[objtab[n].int4+1]=
-1073741824)then begin if(xr>0)and(yr>0)then begin w:=extxnoverd(
onehundredinch,x,100*xr);h:=extxnoverd(onehundredinch,y,100*yr);
end else begin w:=extxnoverd(onehundredinch,x,7200);
h:=extxnoverd(onehundredinch,y,7200);end;end;end;
if(pdfmem[objtab[n].int4+0]=-1073741824)and(pdfmem[objtab[n].int4+1]=
-1073741824)and(pdfmem[objtab[n].int4+2]=-1073741824)then begin pdfmem[
objtab[n].int4+0]:=w;pdfmem[objtab[n].int4+1]:=h;
pdfmem[objtab[n].int4+2]:=0;
end else if(pdfmem[objtab[n].int4+0]=-1073741824)then begin if(pdfmem[
objtab[n].int4+1]=-1073741824)then begin pdfmem[objtab[n].int4+0]:=
extxnoverd(h,x,y);pdfmem[objtab[n].int4+1]:=h-pdfmem[objtab[n].int4+2];
end else if(pdfmem[objtab[n].int4+2]=-1073741824)then begin pdfmem[
objtab[n].int4+0]:=extxnoverd(pdfmem[objtab[n].int4+1],x,y);
pdfmem[objtab[n].int4+2]:=0;
end else begin pdfmem[objtab[n].int4+0]:=extxnoverd(pdfmem[objtab[n].
int4+1]+pdfmem[objtab[n].int4+2],x,y);end;
end else begin if(pdfmem[objtab[n].int4+1]=-1073741824)and(pdfmem[objtab
[n].int4+2]=-1073741824)then begin pdfmem[objtab[n].int4+1]:=extxnoverd(
pdfmem[objtab[n].int4+0],y,x);pdfmem[objtab[n].int4+2]:=0;
end else if(pdfmem[objtab[n].int4+1]=-1073741824)then begin pdfmem[
objtab[n].int4+1]:=extxnoverd(pdfmem[objtab[n].int4+0],y,x)-pdfmem[
objtab[n].int4+2];
end else if(pdfmem[objtab[n].int4+2]=-1073741824)then begin pdfmem[
objtab[n].int4+2]:=0;end else;end;end;function scanpdfboxspec:integer;
begin scanpdfboxspec:=0;
if scankeyword(1800)then scanpdfboxspec:=pdfboxspecmedia else if
scankeyword(1801)then scanpdfboxspec:=pdfboxspeccrop else if scankeyword
(1802)then scanpdfboxspec:=pdfboxspecbleed else if scankeyword(1803)then
scanpdfboxspec:=pdfboxspectrim else if scankeyword(1804)then
scanpdfboxspec:=pdfboxspecart end;procedure scanaltrule;label 21;
begin if altrule=-268435455 then altrule:=newrule;
mem[altrule+1].int:=-1073741824;mem[altrule+3].int:=-1073741824;
mem[altrule+2].int:=-1073741824;
21:if scankeyword(837)then begin scandimen(false,false,false);
mem[altrule+1].int:=curval;goto 21;end;
if scankeyword(838)then begin scandimen(false,false,false);
mem[altrule+3].int:=curval;goto 21;end;
if scankeyword(839)then begin scandimen(false,false,false);
mem[altrule+2].int:=curval;goto 21;end;end;procedure scanimage;label 21;
var k:integer;named:strnumber;s:strnumber;
page,pagebox,colorspace:integer;begin incr(pdfximagecount);
pdfcreateobj(8,pdfximagecount);k:=objptr;objtab[k].int4:=pdfgetmem(5);
scanaltrule;pdfmem[objtab[k].int4+0]:=mem[altrule+1].int;
pdfmem[objtab[k].int4+1]:=mem[altrule+3].int;
pdfmem[objtab[k].int4+2]:=mem[altrule+2].int;
if scankeyword(1791)then begin scanpdfexttoks;
pdfmem[objtab[k].int4+3]:=defref;
end else pdfmem[objtab[k].int4+3]:=-268435455;named:=0;
if scankeyword(1805)then begin scanpdfexttoks;
named:=tokenstostring(defref);deletetokenref(defref);
end else if scankeyword(889)then begin scanint;page:=curval;
end else page:=1;if scankeyword(1806)then begin scanint;
colorspace:=curval;end else colorspace:=0;pagebox:=scanpdfboxspec;
if pagebox=0 then pagebox:=eqtb[27250].int;scanpdfexttoks;
s:=tokenstostring(defref);deletetokenref(defref);
if eqtb[27246].int<>0 then begin pdfwarning(1807,1808,true,true);
eqtb[27249].int:=eqtb[27246].int;eqtb[27246].int:=0;
warnpdfpagebox:=false;end;
if eqtb[27247].int<>0 then begin pdfwarning(1807,1809,true,true);
eqtb[27251].int:=eqtb[27247].int;eqtb[27247].int:=0;end;
if eqtb[27249].int>0 then begin if warnpdfpagebox then begin pdfwarning(
1807,1810,true,true);warnpdfpagebox:=false;end;pagebox:=eqtb[27249].int;
end;if pagebox=0 then pagebox:=pdfboxspeccrop;
pdfmem[objtab[k].int4+4]:=readimage(s,page,named,colorspace,pagebox,eqtb
[27248].int,eqtb[27251].int);if named<>0 then flushstr(named);
flushstr(s);scaleimage(k);pdflastximage:=k;
pdflastximagepages:=imagepages(pdfmem[objtab[k].int4+4]);
pdflastximagecolordepth:=imagecolordepth(pdfmem[objtab[k].int4+4]);end;
{:1553}{1557:}function scanaction:halfword;var p:integer;
begin p:=getnode(3);scanaction:=p;mem[p+1].hh.lh:=-268435455;
mem[p+2].hh.rh:=-268435455;
if scankeyword(1813)then mem[p].hh.b0:=3 else if scankeyword(1814)then
mem[p].hh.b0:=1 else if scankeyword(1815)then mem[p].hh.b0:=2 else
pdferror(1766,1816);if mem[p].hh.b0=3 then begin scanpdfexttoks;
mem[p+2].hh.lh:=defref;goto 10;end;
if scankeyword(878)then begin scanpdfexttoks;mem[p+1].hh.lh:=defref;end;
if scankeyword(889)then begin if mem[p].hh.b0<>1 then pdferror(1766,1817
);mem[p].hh.b0:=0;scanint;if curval<=0 then pdferror(1766,1818);
mem[p].hh.rh:=curval;mem[p].hh.b1:=0;scanpdfexttoks;
mem[p+2].hh.lh:=defref;
end else if scankeyword(1819)then begin scanpdfexttoks;mem[p].hh.b1:=1;
mem[p].hh.rh:=defref;
end else if scankeyword(1187)then begin if(mem[p].hh.b0=1)and(mem[p+1].
hh.lh<>-268435455)then pdferror(1766,1820);scanint;
if curval<=0 then pdferror(1766,1821);mem[p].hh.b1:=0;
mem[p].hh.rh:=curval;end else pdferror(1766,1822);
if scankeyword(1823)then begin mem[p+1].hh.rh:=1;{472:}begin getxtoken;
if curcmd<>10 then backinput;end{:472};
end else if scankeyword(1824)then begin mem[p+1].hh.rh:=2;
{472:}begin getxtoken;if curcmd<>10 then backinput;end{:472};
end else mem[p+1].hh.rh:=0;
if(mem[p+1].hh.rh>0)and(((mem[p].hh.b0<>1)and(mem[p].hh.b0<>0))or(mem[p
+1].hh.lh=-268435455))then pdferror(1766,1825);end;
procedure newannotwhatsit(w,s:smallnumber);begin newwhatsit(w,s);
scanaltrule;mem[curlist.tailfield+1].int:=mem[altrule+1].int;
mem[curlist.tailfield+2].int:=mem[altrule+3].int;
mem[curlist.tailfield+3].int:=mem[altrule+2].int;
if(w=14)then begin if scankeyword(1791)then begin scanpdfexttoks;
mem[curlist.tailfield+5].hh.lh:=defref;
end else mem[curlist.tailfield+5].hh.lh:=-268435455;end;
if(w=18)or(w=19)then begin if scankeyword(1791)then begin scanpdfexttoks
;mem[curlist.tailfield+6].hh.lh:=defref;
end else mem[curlist.tailfield+6].hh.lh:=-268435455;end;end;
{:1557}{1563:}function outlinelistcount(p:halfword):integer;
var k:integer;begin k:=1;
while pdfmem[objtab[p].int4+2]<>0 do begin incr(k);
p:=pdfmem[objtab[p].int4+2];end;outlinelistcount:=k;end;
{:1563}{1567:}procedure scanthreadid;
begin if scankeyword(1187)then begin scanint;
if curval<=0 then pdferror(1766,1821);
if curval>268435455 then pdferror(1766,1028);
mem[curlist.tailfield+5].hh.rh:=curval;
mem[curlist.tailfield+5].hh.b1:=0;
end else if scankeyword(1819)then begin scanpdfexttoks;
mem[curlist.tailfield+5].hh.rh:=defref;
mem[curlist.tailfield+5].hh.b1:=1;end else pdferror(1766,1822);end;
{:1567}{1574:}function newsnapnode(s:smallnumber):halfword;
var p:halfword;begin scanglue(2);
if mem[curval+1].int<0 then pdferror(1766,1852);p:=getnode(3);
mem[p].hh.b0:=8;mem[p].hh.b1:=s;mem[p].hh.rh:=-268435455;
mem[p+1].hh.lh:=curval;mem[p+2].int:=0;newsnapnode:=p;end;
{:1574}{1578:}function concattokens(q,r:halfword):halfword;
var p:halfword;begin if q=-268435455 then begin concattokens:=r;goto 10;
end;p:=q;while mem[p].hh.rh<>-268435455 do p:=mem[p].hh.rh;
mem[p].hh.rh:=mem[r].hh.rh;begin mem[r].hh.rh:=avail;avail:=r;
ifdef('STAT')decr(dynused);endif('STAT')end;concattokens:=q;end;
{:1578}{1588:}procedure pdfincludechars;var s:strnumber;k:poolpointer;
f:internalfontnumber;begin scanfontident;f:=curval;
if f=0 then pdferror(593,873);pdfcheckvfcurval;
if not fontused[f]then pdfinitfont(f);scanpdfexttoks;
s:=tokenstostring(defref);deletetokenref(defref);k:=strstart[s];
while k<strstart[s+1]do begin pdfmarkchar(f,strpool[k]);incr(k);end;
flushstr(s);end;procedure glyphtounicode;var s1,s2:strnumber;
begin scanpdfexttoks;s1:=tokenstostring(defref);deletetokenref(defref);
scanpdfexttoks;s2:=tokenstostring(defref);deletetokenref(defref);
deftounicode(s1,s2);flushstr(s2);flushstr(s1);end;
{:1588}{1598:}procedure threadtitle(thread:integer);
begin pdfprint(1869);
if objtab[thread].int0<0 then pdfprint(-objtab[thread].int0)else
pdfprintint(objtab[thread].int0);begin pdfprint(41);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
procedure pdffixthread(thread:integer);var a:halfword;
begin pdfwarning(1815,1870,false,false);
if objtab[thread].int0<0 then begin print(1186);
print(-objtab[thread].int0);print(125);end else begin print(1187);
printint(objtab[thread].int0);end;print(1188);println;println;
pdfnewdict(0,0,0);a:=objptr;pdfindirectln(84,thread);
pdfindirectln(86,a);pdfindirectln(78,a);pdfindirectln(80,headtab[1]);
pdfprint(1871);pdfprintbp(eqtb[27816].int);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintbp(eqtb[27817].int);begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfenddict;
pdfbegindict(thread,1);begin pdfprint(1872);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;threadtitle(thread);
begin pdfprint(1018);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfindirectln(70,a);
pdfenddict;end;procedure outthread(thread:integer);var a,b:halfword;
lastattr:integer;
begin if objtab[thread].int4=0 then begin pdffixthread(thread);goto 10;
end;pdfbegindict(thread,1);a:=objtab[thread].int4;b:=a;lastattr:=0;
repeat if pdfmem[objtab[a].int4+4]<>0 then lastattr:=pdfmem[objtab[a].
int4+4];a:=pdfmem[objtab[a].int4+2];until a=b;
if lastattr<>0 then begin pdfprint(lastattr);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;
end else begin begin pdfprint(1872);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;threadtitle(thread);
begin pdfprint(1018);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
pdfindirectln(70,a);pdfenddict;repeat pdfbegindict(a,1);
if a=b then pdfindirectln(84,thread);
pdfindirectln(86,pdfmem[objtab[a].int4+3]);
pdfindirectln(78,pdfmem[objtab[a].int4+2]);
pdfindirectln(80,pdfmem[objtab[a].int4+1]);
pdfindirectln(82,pdfmem[objtab[a].int4]);pdfenddict;
a:=pdfmem[objtab[a].int4+2];until a=b;end;{:1598}procedure doextension;
var i,j,k:integer;p,q,r:halfword;
begin case curchr of 0:{1532:}begin newwritewhatsit(3);
scanoptionalequals;scanfilename;mem[curlist.tailfield+1].hh.rh:=curname;
mem[curlist.tailfield+2].hh.lh:=curarea;
mem[curlist.tailfield+2].hh.rh:=curext;end{:1532};
1:{1533:}begin k:=curcs;newwritewhatsit(2);curcs:=k;
p:=scantoks(false,false);mem[curlist.tailfield+1].hh.rh:=defref;
end{:1533};2:{1534:}begin newwritewhatsit(2);
mem[curlist.tailfield+1].hh.rh:=-268435455;end{:1534};
3:{1535:}begin newwhatsit(3,2);
if eqtb[27238].int+64<0 then mem[curlist.tailfield+1].hh.b0:=0 else if
eqtb[27238].int+64>=2*64 then mem[curlist.tailfield+1].hh.b0:=2*64-1
else mem[curlist.tailfield+1].hh.b0:=eqtb[27238].int+64;
if eqtb[27236].int+64<0 then mem[curlist.tailfield+1].hh.b1:=0 else if
eqtb[27236].int+64>=2*64 then mem[curlist.tailfield+1].hh.b1:=2*64-1
else mem[curlist.tailfield+1].hh.b1:=eqtb[27236].int+64;
if(eqtb[27238].int=2)or(eqtb[27238].int=3)then if(eqtb[27236].int>2)or(
eqtb[27236].int=-1)or(eqtb[27236].int=-2)then writenoexpanding:=true;
p:=scantoks(false,true);mem[curlist.tailfield+1].hh.rh:=defref;
writenoexpanding:=false;end{:1535};4:{1621:}begin getxtoken;
if curcmd=59 then begin if curchr<=2 then begin p:=curlist.tailfield;
doextension;outwhat(curlist.tailfield);flushnodelist(curlist.tailfield);
curlist.tailfield:=p;mem[p].hh.rh:=-268435455;
end else case curchr of 7:begin doextension;
if objtab[pdflastobj].int4=0 then pdferror(1766,1914);
pdfwriteobj(pdflastobj);end;9:begin doextension;
pdfcurform:=pdflastxform;
pdfshipout(pdfmem[objtab[pdflastxform].int4+3],false);end;
11:begin doextension;pdfwriteimage(pdflastximage);end;
others:backinput end;end else backinput;end{:1621};
5:{1623:}if abs(curlist.modefield)<>104 then reportillegalcase else
begin newwhatsit(4,2);scanint;
if curval<=0 then curlist.auxfield.hh.rh:=0 else if curval>255 then
curlist.auxfield.hh.rh:=0 else curlist.auxfield.hh.rh:=curval;
mem[curlist.tailfield+1].hh.rh:=curlist.auxfield.hh.rh;
mem[curlist.tailfield+1].hh.b0:=normmin(eqtb[27228].int);
mem[curlist.tailfield+1].hh.b1:=normmin(eqtb[27229].int);end{:1623};
13:{1559:}begin checkpdfoutput(1826,true);
if scankeyword(1788)then begin pdflastannot:=pdfnewobjnum;
{472:}begin getxtoken;if curcmd<>10 then backinput;end{:472};
end else begin if scankeyword(1789)then begin scanint;k:=curval;
if(k<=0)or(k>objptr)or(objtab[k].int4<>0)then pdferror(1766,1827);
end else k:=pdfnewobjnum;newannotwhatsit(13,7);
mem[curlist.tailfield+6].int:=k;scanpdfexttoks;
mem[curlist.tailfield+5].hh.lh:=defref;pdflastannot:=k;end end{:1559};
23:{1580:}begin checkpdfoutput(1856,false);scanpdfexttoks;
if eqtb[27239].int>0 then pdfcatalogtoks:=concattokens(pdfcatalogtoks,
defref);
if scankeyword(1857)then begin if pdfcatalogopenaction<>0 then pdferror(
1766,1858)else begin p:=scanaction;pdfnewobj(0,0,1);
if eqtb[27239].int>0 then pdfcatalogopenaction:=objptr;writeaction(p);
pdfendobj;
begin if mem[p+2].hh.rh=-268435455 then begin if mem[p].hh.b0=3 then
deletetokenref(mem[p+2].hh.lh)else begin if mem[p+1].hh.lh<>-268435455
then deletetokenref(mem[p+1].hh.lh);
if mem[p].hh.b0=0 then deletetokenref(mem[p+2].hh.lh)else if mem[p].hh.
b1>0 then deletetokenref(mem[p].hh.rh);end;freenode(p,3);
end else decr(mem[p+2].hh.rh);end;end;end end{:1580};
17:{1566:}begin checkpdfoutput(1835,true);q:=curlist.tailfield;
newwhatsit(17,7);if scankeyword(1187)then begin scanint;
if curval<=0 then pdferror(1766,1821);
if curval>268435455 then pdferror(1766,1028);
mem[curlist.tailfield+5].hh.rh:=curval;
mem[curlist.tailfield+5].hh.b1:=0;
end else if scankeyword(1819)then begin scanpdfexttoks;
mem[curlist.tailfield+5].hh.rh:=defref;
mem[curlist.tailfield+5].hh.b1:=1;end else pdferror(1766,1822);
if scankeyword(1836)then begin mem[curlist.tailfield+5].hh.b0:=0;
if scankeyword(1837)then begin scanint;
if curval>268435455 then pdferror(1766,1028);
mem[curlist.tailfield+6].hh.lh:=curval;
end else mem[curlist.tailfield+6].hh.lh:=-268435455;
end else if scankeyword(1838)then mem[curlist.tailfield+5].hh.b0:=5 else
if scankeyword(1839)then mem[curlist.tailfield+5].hh.b0:=6 else if
scankeyword(1840)then mem[curlist.tailfield+5].hh.b0:=4 else if
scankeyword(1841)then mem[curlist.tailfield+5].hh.b0:=2 else if
scankeyword(1842)then mem[curlist.tailfield+5].hh.b0:=3 else if
scankeyword(1843)then mem[curlist.tailfield+5].hh.b0:=7 else if
scankeyword(1844)then mem[curlist.tailfield+5].hh.b0:=1 else pdferror(
1766,1845);{472:}begin getxtoken;if curcmd<>10 then backinput;end{:472};
if mem[curlist.tailfield+5].hh.b0=7 then begin scanaltrule;
mem[curlist.tailfield+1].int:=mem[altrule+1].int;
mem[curlist.tailfield+2].int:=mem[altrule+3].int;
mem[curlist.tailfield+3].int:=mem[altrule+2].int;end;
if mem[curlist.tailfield+5].hh.b1<>0 then begin i:=tokenstostring(mem[
curlist.tailfield+5].hh.rh);k:=findobj(5,i,true);flushstr(i);
end else k:=findobj(5,mem[curlist.tailfield+5].hh.rh,false);
if(k<>0)and(objtab[k].int4<>-268435455)then begin warndestdup(mem[
curlist.tailfield+5].hh.rh,mem[curlist.tailfield+5].hh.b1,1846,1847);
flushnodelist(curlist.tailfield);curlist.tailfield:=q;
mem[q].hh.rh:=-268435455;end;end{:1566};
15:{1562:}begin checkpdfoutput(1830,true);
if abs(curlist.modefield)=1 then pdferror(1766,1831);newwhatsit(15,2);
end{:1562};20:{1570:}begin checkpdfoutput(1850,true);newwhatsit(20,2);
end{:1570};25:{1590:}begin checkpdfoutput(1192,true);scanfontident;
k:=curval;if k=0 then pdferror(593,873);scanpdfexttoks;
pdffontattr[k]:=tokenstostring(defref);end{:1590};
32:{1536:}readexpandfont{:1536};
26:{1589:}begin checkpdfoutput(1862,true);pdfincludechars;end{:1589};
22:{1579:}begin checkpdfoutput(1855,false);scanpdfexttoks;
if eqtb[27239].int>0 then pdfinfotoks:=concattokens(pdfinfotoks,defref);
end{:1579};6:{1539:}begin checkpdfoutput(1769,true);newwhatsit(6,2);
if scankeyword(890)then mem[curlist.tailfield+1].hh.lh:=2 else if
scankeyword(889)then mem[curlist.tailfield+1].hh.lh:=1 else mem[curlist.
tailfield+1].hh.lh:=0;scanpdfexttoks;
mem[curlist.tailfield+1].hh.rh:=defref;end{:1539};
38:{1540:}begin checkpdfoutput(1770,true);scanint;
if curval>=colorstackused then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1771);
end;printint(curval);begin helpptr:=3;helpline[2]:=1772;
helpline[1]:=1773;helpline[0]:=1774;end;error;curval:=0;end;
if curval<0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1775);
end;begin helpptr:=2;helpline[1]:=1773;helpline[0]:=1776;end;error;
curval:=0;end;if scankeyword(1777)then begin i:=0;j:=3;
end else if scankeyword(1778)then begin i:=1;j:=3;
end else if scankeyword(1779)then begin i:=2;j:=2;
end else if scankeyword(1780)then begin i:=3;j:=2;end else begin i:=-1;
end;if i>=0 then begin newwhatsit(38,j);
mem[curlist.tailfield+1].hh.rh:=curval;
mem[curlist.tailfield+1].hh.lh:=i;if i<=1 then begin scanpdfexttoks;
mem[curlist.tailfield+2].hh.rh:=defref;end;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1781);
end;begin helpptr:=3;helpline[2]:=1782;helpline[1]:=1783;
helpline[0]:=1784;end;error;end end{:1540};
39:{1541:}begin checkpdfoutput(1127,true);newwhatsit(39,2);
scanpdfexttoks;mem[curlist.tailfield+1].hh.rh:=defref;end{:1541};
40:{1542:}begin checkpdfoutput(1785,true);newwhatsit(40,2);end{:1542};
41:{1543:}begin checkpdfoutput(1786,true);newwhatsit(41,2);end{:1543};
27:{1591:}begin checkpdfoutput(1863,true);scanpdfexttoks;
pdfmapfile(defref);deletetokenref(defref);end{:1591};
28:{1592:}begin checkpdfoutput(1864,true);scanpdfexttoks;
pdfmapline(defref);deletetokenref(defref);end{:1592};
24:{1581:}begin checkpdfoutput(1859,true);scanpdfexttoks;
pdfnamestoks:=concattokens(pdfnamestoks,defref);end{:1581};
7:{1545:}begin checkpdfoutput(1787,true);
if scankeyword(1788)then begin{472:}begin getxtoken;
if curcmd<>10 then backinput;end{:472};incr(pdfobjcount);
pdfcreateobj(6,pdfobjcount);pdflastobj:=objptr;end else begin k:=-1;
if scankeyword(1789)then begin scanint;k:=curval;
if(k<=0)or(k>objptr)or(objtab[k].int4<>0)then begin pdfwarning(1787,1790
,true,true);pdfretval:=-1;k:=-1;end;end;
if k<0 then begin incr(pdfobjcount);pdfcreateobj(6,pdfobjcount);
k:=objptr;end;objtab[k].int4:=pdfgetmem(4);
if scankeyword(1019)then begin pdfmem[objtab[k].int4+1]:=1;
if scankeyword(1791)then begin scanpdfexttoks;
pdfmem[objtab[k].int4+2]:=defref;
end else pdfmem[objtab[k].int4+2]:=-268435455;
end else pdfmem[objtab[k].int4+1]:=0;
if scankeyword(878)then pdfmem[objtab[k].int4+3]:=1 else pdfmem[objtab[k
].int4+3]:=0;scanpdfexttoks;pdfmem[objtab[k].int4+0]:=defref;
pdflastobj:=k;end;end{:1545};16:{1564:}begin checkpdfoutput(1832,true);
if scankeyword(1791)then begin scanpdfexttoks;r:=defref;end else r:=0;
p:=scanaction;if scankeyword(535)then begin scanint;i:=curval;
end else i:=0;scanpdfexttoks;q:=defref;pdfnewobj(0,0,1);j:=objptr;
writeaction(p);pdfendobj;
begin if mem[p+2].hh.rh=-268435455 then begin if mem[p].hh.b0=3 then
deletetokenref(mem[p+2].hh.lh)else begin if mem[p+1].hh.lh<>-268435455
then deletetokenref(mem[p+1].hh.lh);
if mem[p].hh.b0=0 then deletetokenref(mem[p+2].hh.lh)else if mem[p].hh.
b1>0 then deletetokenref(mem[p].hh.rh);end;freenode(p,3);
end else decr(mem[p+2].hh.rh);end;pdfcreateobj(4,0);k:=objptr;
objtab[k].int4:=pdfgetmem(8);pdfmem[objtab[k].int4+6]:=j;
objtab[k].int0:=i;pdfnewobj(0,0,1);pdfprintstrln(tokenstostring(q));
flushstr(lasttokensstring);deletetokenref(q);pdfendobj;
pdfmem[objtab[k].int4]:=objptr;pdfmem[objtab[k].int4+2]:=0;
pdfmem[objtab[k].int4+3]:=0;pdfmem[objtab[k].int4+4]:=0;
pdfmem[objtab[k].int4+5]:=0;pdfmem[objtab[k].int4+1]:=pdfparentoutline;
pdfmem[objtab[k].int4+7]:=r;
if pdffirstoutline=0 then pdffirstoutline:=k;
if pdflastoutline=0 then begin if pdfparentoutline<>0 then pdfmem[objtab
[pdfparentoutline].int4+4]:=k;
end else begin pdfmem[objtab[pdflastoutline].int4+3]:=k;
pdfmem[objtab[k].int4+2]:=pdflastoutline;end;pdflastoutline:=k;
if objtab[k].int0<>0 then begin pdfparentoutline:=k;pdflastoutline:=0;
end else if(pdfparentoutline<>0)and(outlinelistcount(k)=abs(objtab[
pdfparentoutline].int0))then begin j:=pdflastoutline;
repeat pdfmem[objtab[pdfparentoutline].int4+5]:=j;j:=pdfparentoutline;
pdfparentoutline:=pdfmem[objtab[pdfparentoutline].int4+1];
until(pdfparentoutline=0)or(outlinelistcount(j)<abs(objtab[
pdfparentoutline].int0));
if pdfparentoutline=0 then pdflastoutline:=pdffirstoutline else
pdflastoutline:=pdfmem[objtab[pdfparentoutline].int4+4];
while pdfmem[objtab[pdflastoutline].int4+3]<>0 do pdflastoutline:=pdfmem
[objtab[pdflastoutline].int4+3];end;end{:1564};
8:{1547:}begin checkpdfoutput(1793,true);scanint;pdfcheckobj(6,curval);
newwhatsit(8,2);mem[curlist.tailfield+1].hh.lh:=curval;end{:1547};
10:{1550:}begin checkpdfoutput(1797,true);scanint;pdfcheckobj(7,curval);
newwhatsit(10,5);mem[curlist.tailfield+4].hh.lh:=curval;
mem[curlist.tailfield+1].int:=pdfmem[objtab[curval].int4+0];
mem[curlist.tailfield+2].int:=pdfmem[objtab[curval].int4+1];
mem[curlist.tailfield+3].int:=pdfmem[objtab[curval].int4+2];end{:1550};
12:{1555:}begin checkpdfoutput(1812,true);scanint;pdfcheckobj(8,curval);
newwhatsit(12,5);mem[curlist.tailfield+4].hh.lh:=curval;
mem[curlist.tailfield+1].int:=pdfmem[objtab[curval].int4+0];
mem[curlist.tailfield+2].int:=pdfmem[objtab[curval].int4+1];
mem[curlist.tailfield+3].int:=pdfmem[objtab[curval].int4+2];end{:1555};
21:{1577:}begin newwhatsit(21,2);end{:1577};
34:{1573:}begin checkpdfoutput(1851,true);newwhatsit(34,2);end{:1573};
36:{1576:}begin checkpdfoutput(1854,true);newwhatsit(36,2);scanint;
mem[curlist.tailfield+1].int:=fixint(curval,0,1000);end{:1576};
35:{1575:}begin checkpdfoutput(1853,true);
begin mem[curlist.tailfield].hh.rh:=newsnapnode(35);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;end{:1575};
14:{1561:}begin checkpdfoutput(1828,true);
if abs(curlist.modefield)=1 then pdferror(1766,1829);k:=pdfnewobjnum;
newannotwhatsit(14,7);mem[curlist.tailfield+5].hh.rh:=scanaction;
mem[curlist.tailfield+6].int:=k;pdflastlink:=k;end{:1561};
19:{1569:}begin checkpdfoutput(1849,true);newannotwhatsit(19,7);
scanthreadid;end{:1569};18:{1568:}begin checkpdfoutput(1848,true);
newannotwhatsit(18,7);scanthreadid;end{:1568};
29:{1582:}begin checkpdfoutput(1860,false);scanpdfexttoks;
if eqtb[27239].int>0 then pdftrailertoks:=concattokens(pdftrailertoks,
defref);end{:1582};30:{1583:}begin checkpdfoutput(1861,false);
scanpdfexttoks;if eqtb[27239].int>0 then pdftraileridtoks:=concattokens(
pdftraileridtoks,defref);end{:1583};
9:{1549:}begin checkpdfoutput(1794,true);incr(pdfxformcount);
pdfcreateobj(7,pdfxformcount);k:=objptr;objtab[k].int4:=pdfgetmem(6);
if scankeyword(1791)then begin scanpdfexttoks;
pdfmem[objtab[k].int4+4]:=defref;
end else pdfmem[objtab[k].int4+4]:=-268435455;
if scankeyword(1795)then begin scanpdfexttoks;
pdfmem[objtab[k].int4+5]:=defref;
end else pdfmem[objtab[k].int4+5]:=-268435455;scanregisternum;
if curval<256 then p:=eqtb[25333+curval].hh.rh else begin findsaelement(
4,curval,false);
if curptr=-268435455 then p:=-268435455 else p:=mem[curptr+1].hh.rh;end;
if p=-268435455 then pdferror(1766,1796);
pdfmem[objtab[k].int4+0]:=mem[p+1].int;
pdfmem[objtab[k].int4+1]:=mem[p+3].int;
pdfmem[objtab[k].int4+2]:=mem[p+2].int;pdfmem[objtab[k].int4+3]:=p;
if curval<256 then eqtb[25333+curval].hh.rh:=-268435455 else begin
findsaelement(4,curval,false);
if curptr<>-268435455 then begin mem[curptr+1].hh.rh:=-268435455;
incr(mem[curptr+1].hh.lh);deletesaref(curptr);end;end;pdflastxform:=k;
end{:1549};11:{1554:}begin checkpdfoutput(1811,true);
checkpdfminorversion;scanimage;end{:1554};
31:{1587:}begin secondsandmicros(epochseconds,microseconds);end{:1587};
33:{1586:}begin scanint;if curval<0 then curval:=-curval;
randomseed:=curval;initrandoms(randomseed);end{:1586};
37:{1593:}begin glyphtounicode;end{:1593};
42:{1594:}begin checkpdfoutput(1865,true);scanfontident;k:=curval;
if k=0 then pdferror(593,873);pdffontnobuiltintounicode[k]:=true;
end{:1594};43:{1595:}begin checkpdfoutput(1866,true);newwhatsit(43,2);
end{:1595};44:{1596:}begin checkpdfoutput(1867,true);newwhatsit(44,2);
end{:1596};45:{1597:}begin checkpdfoutput(1868,true);newwhatsit(45,2);
end{:1597};others:confusion(1766)end;end;
{:1529}{1622:}procedure fixlanguage;var l:ASCIIcode;
begin if eqtb[27227].int<=0 then l:=0 else if eqtb[27227].int>255 then l
:=0 else l:=eqtb[27227].int;
if l<>curlist.auxfield.hh.rh then begin newwhatsit(4,2);
mem[curlist.tailfield+1].hh.rh:=l;curlist.auxfield.hh.rh:=l;
mem[curlist.tailfield+1].hh.b0:=normmin(eqtb[27228].int);
mem[curlist.tailfield+1].hh.b1:=normmin(eqtb[27229].int);end;end;
{:1622}{1933:}procedure insertsrcspecial;var toklist,p,q:halfword;
begin if(sourcefilenamestack[inopen]>0 and isnewsource(
sourcefilenamestack[inopen],line))then begin toklist:=getavail;
p:=toklist;mem[p].hh.lh:=19619;mem[p].hh.rh:=getavail;p:=mem[p].hh.rh;
mem[p].hh.lh:=379;
q:=strtoks(makesrcspecial(sourcefilenamestack[inopen],line));
mem[p].hh.rh:=mem[memtop-3].hh.rh;p:=q;mem[p].hh.rh:=getavail;
p:=mem[p].hh.rh;mem[p].hh.lh:=637;begintokenlist(toklist,4);
remembersourceinfo(sourcefilenamestack[inopen],line);end;end;
procedure appendsrcspecial;var q:halfword;
begin if(sourcefilenamestack[inopen]>0 and isnewsource(
sourcefilenamestack[inopen],line))then begin newwhatsit(3,2);
mem[curlist.tailfield+1].hh.b0:=0;defref:=getavail;
mem[defref].hh.lh:=-268435455;
q:=strtoks(makesrcspecial(sourcefilenamestack[inopen],line));
mem[defref].hh.rh:=mem[memtop-3].hh.rh;
mem[curlist.tailfield+1].hh.rh:=defref;
remembersourceinfo(sourcefilenamestack[inopen],line);end;end;
{:1933}{1247:}procedure handlerightbrace;var p,q:halfword;d:scaled;
f:integer;begin case curgroup of 1:unsave;
0:begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1446);
end;begin helpptr:=2;helpline[1]:=1447;helpline[0]:=1448;end;error;end;
14,15,16:extrarightbrace;{1264:}2:package(0);
3:begin adjusttail:=memtop-5;preadjusttail:=memtop-14;package(0);end;
4:begin endgraf;package(0);end;5:begin endgraf;package(4);end;
{:1264}{1279:}11:begin endgraf;q:=eqtb[24538].hh.rh;incr(mem[q].hh.rh);
d:=eqtb[27799].int;f:=eqtb[27219].int;unsave;saveptr:=saveptr-2;
p:=vpackage(mem[curlist.headfield].hh.rh,0,1,1073741823);popnest;
if savestack[saveptr+0].int<255 then begin begin mem[curlist.tailfield].
hh.rh:=getnode(5);curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=3;
mem[curlist.tailfield].hh.b1:=savestack[saveptr+0].int;
mem[curlist.tailfield+3].int:=mem[p+3].int+mem[p+2].int;
mem[curlist.tailfield+4].hh.lh:=mem[p+5].hh.rh;
mem[curlist.tailfield+4].hh.rh:=q;mem[curlist.tailfield+2].int:=d;
mem[curlist.tailfield+1].int:=f;
end else begin begin mem[curlist.tailfield].hh.rh:=getnode(2);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=5;
mem[curlist.tailfield].hh.b1:=savestack[saveptr+1].int;
mem[curlist.tailfield+1].int:=mem[p+5].hh.rh;deleteglueref(q);end;
freenode(p,9);if nestptr=0 then buildpage;end;
8:{1204:}begin if(curinput.locfield<>-268435455)or((curinput.indexfield
<>6)and(curinput.indexfield<>3))then{1205:}begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(264);
print(1414);end;begin helpptr:=2;helpline[1]:=1415;helpline[0]:=1416;
end;error;repeat gettoken;until curinput.locfield=-268435455;end{:1205};
endtokenlist;endgraf;unsave;outputactive:=false;insertpenalties:=0;
{1206:}if eqtb[25588].hh.rh<>-268435455 then begin begin if interaction=
3 then;if filelineerrorstylep then printfileline else printnl(264);
print(1417);end;printesc(429);printint(255);begin helpptr:=3;
helpline[2]:=1418;helpline[1]:=1419;helpline[0]:=1420;end;boxerror(255);
end{:1206};
if curlist.tailfield<>curlist.headfield then begin mem[pagetail].hh.rh:=
mem[curlist.headfield].hh.rh;pagetail:=curlist.tailfield;end;
if mem[memtop-2].hh.rh<>-268435455 then begin if mem[memtop-1].hh.rh=
-268435455 then nest[0].tailfield:=pagetail;
mem[pagetail].hh.rh:=mem[memtop-1].hh.rh;
mem[memtop-1].hh.rh:=mem[memtop-2].hh.rh;
mem[memtop-2].hh.rh:=-268435455;pagetail:=memtop-2;end;
flushnodelist(discptr[2]);discptr[2]:=-268435455;popnest;buildpage;
end{:1204};{:1279}{1297:}10:builddiscretionary;
{:1297}{1311:}6:begin backinput;curtok:=19610;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(713);
end;printesc(1298);print(714);begin helpptr:=1;helpline[0]:=1530;end;
inserror;end;{:1311}{1312:}7:begin endgraf;unsave;alignpeek;end;
{:1312}{1347:}12:begin endgraf;unsave;saveptr:=saveptr-2;
p:=vpackage(mem[curlist.headfield].hh.rh,savestack[saveptr+1].int,
savestack[saveptr+0].int,1073741823);popnest;
begin mem[curlist.tailfield].hh.rh:=newnoad;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=29;mem[curlist.tailfield+1].hh.rh:=2;
mem[curlist.tailfield+1].hh.lh:=p;end;{:1347}{1352:}13:buildchoices;
{:1352}{1365:}9:begin unsave;decr(saveptr);
mem[savestack[saveptr+0].int].hh.rh:=3;p:=finmlist(-268435455);
mem[savestack[saveptr+0].int].hh.lh:=p;
if p<>-268435455 then if mem[p].hh.rh=-268435455 then if mem[p].hh.b0=16
then begin if mem[p+3].hh.rh=0 then if mem[p+2].hh.rh=0 then begin mem[
savestack[saveptr+0].int].hh:=mem[p+1].hh;freenode(p,4);end;
end else if mem[p].hh.b0=28 then if savestack[saveptr+0].int=curlist.
tailfield+1 then if mem[curlist.tailfield].hh.b0=16 then{1366:}begin q:=
curlist.headfield;
while mem[q].hh.rh<>curlist.tailfield do q:=mem[q].hh.rh;
mem[q].hh.rh:=p;freenode(curlist.tailfield,4);curlist.tailfield:=p;
end{:1366};end;{:1365}others:confusion(1449)end;end;
{:1247}procedure maincontrol;
label 60,21,70,80,90,91,92,95,100,101,110,111,112,120,10;var t:integer;
tmpk1,tmpk2:halfword;
begin if eqtb[25065].hh.rh<>-268435455 then begintokenlist(eqtb[25065].
hh.rh,12);60:getxtoken;
21:{1209:}if interrupt<>0 then if OKtointerrupt then begin backinput;
begin if interrupt<>0 then pauseforinstructions;end;goto 60;end;
ifdef('TEXMF_DEBUG')if panicking then checkmem(false);
endif('TEXMF_DEBUG')if eqtb[27213].int>0 then showcurcmdchr{:1209};
case abs(curlist.modefield)+curcmd of 115,116,172:goto 70;
120:begin scancharnum;curchr:=curval;goto 70;end;169:begin getxtoken;
if(curcmd=11)or(curcmd=12)or(curcmd=68)or(curcmd=16)then cancelboundary
:=true;goto 21;end;
114:if(curlist.auxfield.hh.lh=1000)or(eqtb[27260].int>0)then goto 120
else appspace;168,271:goto 120;{1224:}1,104,207,11,217,272:;
40,143,246:begin if curchr=0 then begin{435:}repeat getxtoken;
until curcmd<>10{:435};goto 21;end else begin t:=scannerstatus;
scannerstatus:=0;getnext;scannerstatus:=t;
if curcs<514 then curcs:=primlookup(curcs-257)else curcs:=primlookup(
hash[curcs].rh);if curcs<>0 then begin curcmd:=primeqtb[curcs].hh.b0;
curchr:=primeqtb[curcs].hh.rh;goto 21;end;end;end;
15:if itsallover then goto 10;
{1227:}23,125,228,71,174,277,{:1227}{1277:}39,{:1277}{1290:}45,{:1290}
{1323:}49,152,{:1323}7,110,213:reportillegalcase;
{1225:}8,111,9,112,18,121,70,173,51,154,16,119,50,153,53,156,67,170,54,
157,55,158,57,160,56,159,31,134,52,155,29,132,47,150,216,220,221,234,231
,240,243{:1225}:insertdollarsign;
{1235:}37,139,242:begin begin mem[curlist.tailfield].hh.rh:=scanrulespec
;curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if abs(curlist.modefield)=1 then curlist.auxfield.int:=eqtb[27825].int
else if abs(curlist.modefield)=104 then curlist.auxfield.hh.lh:=1000;
end;{:1235}{1236:}28,130,233,235:appendglue;30,133,236,237:appendkern;
{:1236}{1242:}2,105:newsavelevel(1);62,165,268:newsavelevel(14);
63,166,269:if curgroup=14 then unsave else offsave;
{:1242}{1246:}3,106,209:handlerightbrace;
{:1246}{1252:}22,126,229:begin t:=curchr;scandimen(false,false,false);
if t=0 then scanbox(curval)else scanbox(-curval);end;
32,135,238:scanbox(1073807261+curchr);21,124,227:beginbox(0);
{:1252}{1269:}44:newgraf(curchr>0);
12,13,17,69,4,24,36,46,48,27,34,65,66:begin backinput;newgraf(true);end;
{:1269}{1271:}147,250:if curchr<>2 then indentinhmode;
{:1271}{1273:}14:begin normalparagraph;
if curlist.modefield>0 then buildpage;end;
117:begin if alignstate<0 then offsave;endgraf;
if curlist.modefield=1 then buildpage;end;
118,131,140,128,136:headforvmode;
{:1273}{1276:}38,141,244,142,245:begininsertoradjust;
19,122,225:makemark;{:1276}{1281:}43,146,249:appendpenalty;
{:1281}{1283:}26,129,232:deletelast;{:1283}{1288:}25,127,230:unpackage;
{:1288}{1291:}148:appenditaliccorrection;
251:begin mem[curlist.tailfield].hh.rh:=newkern(0);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
{:1291}{1295:}151,254:appenddiscretionary;{:1295}{1301:}149:makeaccent;
{:1301}{1305:}6,109,212,5,108,211:alignerror;35,138,241:noalignerror;
64,167,270:omiterror;{:1305}{1309:}33:initalign;
137:{1701:}if curchr>0 then begin if eTeXenabled((eqtb[27279].int>0),
curcmd,curchr)then begin mem[curlist.tailfield].hh.rh:=newmath(0,curchr)
;curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
end else{:1701}initalign;
239:if privileged then if curgroup=15 then initalign else offsave;
10,113:doendv;{:1309}{1313:}68,171,274:cserror;
{:1313}{1316:}107:initmath;
{:1316}{1319:}255:if privileged then if curgroup=15 then starteqno else
offsave;
{:1319}{1329:}208:begin begin mem[curlist.tailfield].hh.rh:=newnoad;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;backinput;
scanmath(curlist.tailfield+1);end;
{:1329}{1333:}218,219,275:setmathchar(eqtb[26665+curchr].hh.rh);
223:begin scancharnum;curchr:=curval;
setmathchar(eqtb[26665+curchr].hh.rh);end;224:begin scanfifteenbitint;
setmathchar(curval);end;276:setmathchar(curchr);
222:begin scantwentysevenbitint;setmathchar(curval div 4096);end;
{:1333}{1337:}257:begin begin mem[curlist.tailfield].hh.rh:=newnoad;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=curchr;scanmath(curlist.tailfield+1);end;
258:mathlimitswitch;{:1337}{1341:}273:mathradical;
{:1341}{1343:}252,253:mathac;{:1343}{1346:}263:begin scanspec(12,false);
normalparagraph;pushnest;curlist.modefield:=-1;
curlist.auxfield.int:=eqtb[27825].int;
if(insertsrcspecialeveryvbox)then insertsrcspecial;
if eqtb[25064].hh.rh<>-268435455 then begintokenlist(eqtb[25064].hh.rh,
11);end;
{:1346}{1350:}260:begin mem[curlist.tailfield].hh.rh:=newstyle(curchr);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
262:begin begin mem[curlist.tailfield].hh.rh:=newglue(membot);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b1:=98;end;261:appendchoices;
{:1350}{1354:}215,214:subsup;{:1354}{1359:}259:mathfraction;
{:1359}{1369:}256:mathleftright;
{:1369}{1372:}210:if curgroup=15 then aftermath else offsave;
{:1372}{1389:}72,175,278,73,176,279,74,177,280,75,178,281,76,179,282,77,
180,283,78,181,284,79,182,285,80,183,286,81,184,287,82,185,288,83,186,
289,84,187,290,85,188,291,86,189,292,87,190,293,88,191,294,89,192,295,
102,205,308,103,206,309,90,193,296,91,194,297,92,195,298,93,196,299,94,
197,300,95,198,301,96,199,302,97,200,303,98,201,304,99,202,305,100,203,
306,101,204,307:prefixedcommand;{:1389}{1447:}41,144,247:begin gettoken;
aftertoken:=curtok;end;{:1447}{1450:}42,145,248:begin gettoken;
saveforafter(curtok);end;{:1450}{1453:}61,164,267:openorclosein;
{:1453}{1455:}59,162,265:issuemessage;
{:1455}{1464:}58,161,264:shiftcase;
{:1464}{1469:}20,123,226:showwhatever;
{:1469}{1528:}60,163,266:doextension;{:1528}{:1224}end;goto 60;
70:{1212:}if((curlist.headfield=curlist.tailfield)and(curlist.modefield>
0))then begin if(insertsrcspecialauto)then appendsrcspecial;end;
mains:=eqtb[26409+curchr].hh.rh;
if mains=1000 then curlist.auxfield.hh.lh:=1000 else if mains<1000 then
begin if mains>0 then curlist.auxfield.hh.lh:=mains;
end else if curlist.auxfield.hh.lh<1000 then curlist.auxfield.hh.lh:=
1000 else curlist.auxfield.hh.lh:=mains;savetail:=-268435455;
mainf:=eqtb[25589].hh.rh;bchar:=fontbchar[mainf];
falsebchar:=fontfalsebchar[mainf];
if curlist.modefield>0 then if eqtb[27227].int<>curlist.auxfield.hh.rh
then fixlanguage;begin ligstack:=avail;
if ligstack=-268435455 then ligstack:=getavail else begin avail:=mem[
ligstack].hh.rh;mem[ligstack].hh.rh:=-268435455;
ifdef('STAT')incr(dynused);endif('STAT')end;end;
mem[ligstack].hh.b0:=mainf;curl:=curchr;mem[ligstack].hh.b1:=curl;
curq:=curlist.tailfield;tmpk1:=getautokern(mainf,256,curl);
{1218:}if tmpk1<>-268435455 then begin if curl<256 then begin if mem[
curq].hh.rh>-268435455 then if mem[curlist.tailfield].hh.b1=hyphenchar[
mainf]then insdisc:=true;
if ligaturepresent then begin mainp:=newligature(mainf,curl,mem[curq].hh
.rh);if lfthit then begin mem[mainp].hh.b1:=2;lfthit:=false;end;
if rthit then if ligstack=-268435455 then begin incr(mem[mainp].hh.b1);
rthit:=false;end;
if eqtb[27261].int>0 then tmpk2:=getautokern(mainf,256,curl)else tmpk2:=
-268435455;if tmpk2=-268435455 then begin mem[curq].hh.rh:=mainp;
curlist.tailfield:=mainp;ligaturepresent:=false;
end else begin mem[curq].hh.rh:=tmpk2;mem[tmpk2].hh.rh:=mainp;
curlist.tailfield:=mainp;ligaturepresent:=false;end end;
if insdisc then begin insdisc:=false;
if curlist.modefield>0 then begin mem[curlist.tailfield].hh.rh:=newdisc;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;end;end;
savetail:=curlist.tailfield;begin mem[curlist.tailfield].hh.rh:=tmpk1;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;goto 90;end{:1218};
if cancelboundary then begin cancelboundary:=false;maink:=0;
end else maink:=bcharlabel[mainf];if maink=0 then goto 92;curr:=curl;
curl:=256;goto 111;
80:{1213:}if curl<256 then begin if mem[curq].hh.rh>-268435455 then if
mem[curlist.tailfield].hh.b1=hyphenchar[mainf]then insdisc:=true;
if ligaturepresent then begin mainp:=newligature(mainf,curl,mem[curq].hh
.rh);if lfthit then begin mem[mainp].hh.b1:=2;lfthit:=false;end;
if rthit then if ligstack=-268435455 then begin incr(mem[mainp].hh.b1);
rthit:=false;end;
if eqtb[27261].int>0 then tmpk2:=getautokern(mainf,256,curl)else tmpk2:=
-268435455;if tmpk2=-268435455 then begin mem[curq].hh.rh:=mainp;
curlist.tailfield:=mainp;ligaturepresent:=false;
end else begin mem[curq].hh.rh:=tmpk2;mem[tmpk2].hh.rh:=mainp;
curlist.tailfield:=mainp;ligaturepresent:=false;end end;
if insdisc then begin insdisc:=false;
if curlist.modefield>0 then begin mem[curlist.tailfield].hh.rh:=newdisc;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;end;end{:1213};
90:{1214:}if ligstack=-268435455 then goto 21;curq:=curlist.tailfield;
curl:=mem[ligstack].hh.b1;91:if not(ligstack>=himemmin)then goto 95;
92:if(effectivechar(false,mainf,curchr)>fontec[mainf])or(effectivechar(
false,mainf,curchr)<fontbc[mainf])then begin charwarning(mainf,curchr);
begin mem[ligstack].hh.rh:=avail;avail:=ligstack;
ifdef('STAT')decr(dynused);endif('STAT')end;goto 60;end;
maini:=effectivecharinfo(mainf,curl);
if not(maini.b0>0)then begin charwarning(mainf,curchr);
begin mem[ligstack].hh.rh:=avail;avail:=ligstack;
ifdef('STAT')decr(dynused);endif('STAT')end;goto 60;end;
mem[curlist.tailfield].hh.rh:=ligstack;
curlist.tailfield:=ligstack{:1214};100:{1216:}getnext;
if curcmd=11 then goto 101;if curcmd=12 then goto 101;
if curcmd=68 then goto 101;xtoken;if curcmd=11 then goto 101;
if curcmd=12 then goto 101;if curcmd=68 then goto 101;
if curcmd=16 then begin scancharnum;curchr:=curval;goto 101;end;
if curcmd=65 then bchar:=256;curr:=bchar;ligstack:=-268435455;goto 110;
101:mains:=eqtb[26409+curchr].hh.rh;
if mains=1000 then curlist.auxfield.hh.lh:=1000 else if mains<1000 then
begin if mains>0 then curlist.auxfield.hh.lh:=mains;
end else if curlist.auxfield.hh.lh<1000 then curlist.auxfield.hh.lh:=
1000 else curlist.auxfield.hh.lh:=mains;begin ligstack:=avail;
if ligstack=-268435455 then ligstack:=getavail else begin avail:=mem[
ligstack].hh.rh;mem[ligstack].hh.rh:=-268435455;
ifdef('STAT')incr(dynused);endif('STAT')end;end;
mem[ligstack].hh.b0:=mainf;curr:=curchr;mem[ligstack].hh.b1:=curr;
if curr=falsebchar then curr:=256{:1216};
110:{1217:}tmpk1:=getautokern(mainf,curl,curr);
{1218:}if tmpk1<>-268435455 then begin if curl<256 then begin if mem[
curq].hh.rh>-268435455 then if mem[curlist.tailfield].hh.b1=hyphenchar[
mainf]then insdisc:=true;
if ligaturepresent then begin mainp:=newligature(mainf,curl,mem[curq].hh
.rh);if lfthit then begin mem[mainp].hh.b1:=2;lfthit:=false;end;
if rthit then if ligstack=-268435455 then begin incr(mem[mainp].hh.b1);
rthit:=false;end;
if eqtb[27261].int>0 then tmpk2:=getautokern(mainf,256,curl)else tmpk2:=
-268435455;if tmpk2=-268435455 then begin mem[curq].hh.rh:=mainp;
curlist.tailfield:=mainp;ligaturepresent:=false;
end else begin mem[curq].hh.rh:=tmpk2;mem[tmpk2].hh.rh:=mainp;
curlist.tailfield:=mainp;ligaturepresent:=false;end end;
if insdisc then begin insdisc:=false;
if curlist.modefield>0 then begin mem[curlist.tailfield].hh.rh:=newdisc;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;end;end;
savetail:=curlist.tailfield;begin mem[curlist.tailfield].hh.rh:=tmpk1;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;goto 90;end{:1218};
if((maini.b2)mod 4)<>1 then goto 80;if curr=256 then goto 80;
maink:=ligkernbase[mainf]+maini.b3;mainj:=fontinfo[maink].qqqq;
if mainj.b0<=128 then goto 112;
maink:=ligkernbase[mainf]+256*mainj.b2+mainj.b3+32768-256*(128);
111:mainj:=fontinfo[maink].qqqq;
112:if mainj.b1=curr then if mainj.b0<=128 then{1219:}begin if mainj.b2
>=128 then begin if curl<256 then begin if mem[curq].hh.rh>-268435455
then if mem[curlist.tailfield].hh.b1=hyphenchar[mainf]then insdisc:=true
;
if ligaturepresent then begin mainp:=newligature(mainf,curl,mem[curq].hh
.rh);if lfthit then begin mem[mainp].hh.b1:=2;lfthit:=false;end;
if rthit then if ligstack=-268435455 then begin incr(mem[mainp].hh.b1);
rthit:=false;end;
if eqtb[27261].int>0 then tmpk2:=getautokern(mainf,256,curl)else tmpk2:=
-268435455;if tmpk2=-268435455 then begin mem[curq].hh.rh:=mainp;
curlist.tailfield:=mainp;ligaturepresent:=false;
end else begin mem[curq].hh.rh:=tmpk2;mem[tmpk2].hh.rh:=mainp;
curlist.tailfield:=mainp;ligaturepresent:=false;end end;
if insdisc then begin insdisc:=false;
if curlist.modefield>0 then begin mem[curlist.tailfield].hh.rh:=newdisc;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;end;end;
begin mem[curlist.tailfield].hh.rh:=newkern(fontinfo[kernbase[mainf]+256
*mainj.b2+mainj.b3].int);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;goto 90;end;
if curl=256 then lfthit:=true else if ligstack=-268435455 then rthit:=
true;begin if interrupt<>0 then pauseforinstructions;end;
case mainj.b2 of 1,5:begin curl:=mainj.b3;
maini:=fontinfo[charbase[mainf]+effectivechar(true,mainf,curl)].qqqq;
ligaturepresent:=true;end;2,6:begin curr:=mainj.b3;
if ligstack=-268435455 then begin ligstack:=newligitem(curr);bchar:=256;
end else if(ligstack>=himemmin)then begin mainp:=ligstack;
ligstack:=newligitem(curr);mem[ligstack+1].hh.rh:=mainp;
end else mem[ligstack].hh.b1:=curr;end;3:begin curr:=mainj.b3;
mainp:=ligstack;ligstack:=newligitem(curr);mem[ligstack].hh.rh:=mainp;
end;
7,11:begin if curl<256 then begin if mem[curq].hh.rh>-268435455 then if
mem[curlist.tailfield].hh.b1=hyphenchar[mainf]then insdisc:=true;
if ligaturepresent then begin mainp:=newligature(mainf,curl,mem[curq].hh
.rh);if lfthit then begin mem[mainp].hh.b1:=2;lfthit:=false;end;
if false then if ligstack=-268435455 then begin incr(mem[mainp].hh.b1);
rthit:=false;end;
if eqtb[27261].int>0 then tmpk2:=getautokern(mainf,256,curl)else tmpk2:=
-268435455;if tmpk2=-268435455 then begin mem[curq].hh.rh:=mainp;
curlist.tailfield:=mainp;ligaturepresent:=false;
end else begin mem[curq].hh.rh:=tmpk2;mem[tmpk2].hh.rh:=mainp;
curlist.tailfield:=mainp;ligaturepresent:=false;end end;
if insdisc then begin insdisc:=false;
if curlist.modefield>0 then begin mem[curlist.tailfield].hh.rh:=newdisc;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;end;end;
curq:=curlist.tailfield;curl:=mainj.b3;
maini:=fontinfo[charbase[mainf]+effectivechar(true,mainf,curl)].qqqq;
ligaturepresent:=true;end;others:begin curl:=mainj.b3;
ligaturepresent:=true;if ligstack=-268435455 then goto 80 else goto 91;
end end;if mainj.b2>4 then if mainj.b2<>7 then goto 80;
if curl<256 then goto 110;maink:=bcharlabel[mainf];goto 111;end{:1219};
if mainj.b0=0 then incr(maink)else begin if mainj.b0>=128 then goto 80;
maink:=maink+mainj.b0+1;end;goto 111{:1217};
95:{1215:}mainp:=mem[ligstack+1].hh.rh;
if mainp>-268435455 then begin mem[curlist.tailfield].hh.rh:=mainp;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;tempptr:=ligstack;
ligstack:=mem[tempptr].hh.rh;freenode(tempptr,2);
maini:=fontinfo[charbase[mainf]+effectivechar(true,mainf,curl)].qqqq;
ligaturepresent:=true;
if ligstack=-268435455 then if mainp>-268435455 then goto 100 else curr
:=bchar else curr:=mem[ligstack].hh.b1;goto 110{:1215}{:1212};
120:{1220:}if eqtb[24540].hh.rh=membot then begin{1221:}begin mainp:=
fontglue[eqtb[25589].hh.rh];
if mainp=-268435455 then begin mainp:=newspec(membot);
maink:=parambase[eqtb[25589].hh.rh]+2;
mem[mainp+1].int:=fontinfo[maink].int;
mem[mainp+2].int:=fontinfo[maink+1].int;
mem[mainp+3].int:=fontinfo[maink+2].int;
fontglue[eqtb[25589].hh.rh]:=mainp;end;end{:1221};
tempptr:=newglue(mainp);end else tempptr:=newparamglue(12);
if eqtb[27260].int>0 then adjustinterwordglue(curlist.tailfield,tempptr)
;mem[curlist.tailfield].hh.rh:=tempptr;curlist.tailfield:=tempptr;
goto 60{:1220};10:end;{:1208}{1463:}procedure giveerrhelp;
begin tokenshow(eqtb[25067].hh.rh);end;
{:1463}{1482:}{553:}function openfmtfile:boolean;label 40,10;
var j:0..bufsize;begin j:=curinput.locfield;
if buffer[curinput.locfield]=38 then begin incr(curinput.locfield);
j:=curinput.locfield;buffer[last]:=32;while buffer[j]<>32 do incr(j);
packbufferedname(0,curinput.locfield,j-1);
if wopenin(fmtfile)then goto 40;;
write(stdout,'Sorry, I can''t find the format `');
fputs(stringcast(nameoffile+1),stdout);write(stdout,'''; will try `');
fputs(TEXformatdefault+1,stdout);writeln(stdout,'''.');fflush(stdout);
end;packbufferedname(formatdefaultlength-4,1,0);
if not wopenin(fmtfile)then begin;
write(stdout,'I can''t find the format file `');
fputs(TEXformatdefault+1,stdout);writeln(stdout,'''!');
openfmtfile:=false;goto 10;end;40:curinput.locfield:=j;
openfmtfile:=true;10:end;{:553}function loadfmtfile:boolean;
label 6666,10;var j,k:integer;p,q:halfword;x:integer;
formatengine:^ASCIIcode;dummyxord:ASCIIcode;dummyxchr:ASCIIcode;
dummyxprn:ASCIIcode;
begin{1487:}ifdef('INITEX')if iniversion then begin libcfree(fontinfo);
libcfree(strpool);libcfree(strstart);libcfree(yhash);libcfree(zeqtb);
libcfree(yzmem);end;endif('INITEX')undumpint(x);
if debugformatfile then begin write(stderr,'fmtdebug:',
'format magic number');writeln(stderr,' = ',x);end;;
if x<>1462916184 then goto 6666;undumpint(x);
if debugformatfile then begin write(stderr,'fmtdebug:',
'engine name size');writeln(stderr,' = ',x);end;;
if(x<0)or(x>256)then goto 6666;formatengine:=xmallocarray(ASCIIcode,x);
undumpthings(formatengine[0],x);formatengine[x-1]:=0;
if strcmp(enginename,stringcast(formatengine))then begin;
writeln(stdout,'---! ',stringcast(nameoffile+1),' was written by ',
formatengine);libcfree(formatengine);goto 6666;end;
libcfree(formatengine);undumpint(x);
if debugformatfile then begin write(stderr,'fmtdebug:',
'string pool checksum');writeln(stderr,' = ',x);end;;
if x<>490236648 then begin;
writeln(stdout,'---! ',stringcast(nameoffile+1),' doesn''t match ',
poolname);goto 6666;end;
{1873:}if translatefilename then begin for k:=0 to 255 do undumpthings(
dummyxord,1);for k:=0 to 255 do undumpthings(dummyxchr,1);
for k:=0 to 255 do undumpthings(dummyxprn,1);
end else begin undumpthings(xord[0],256);undumpthings(xchr[0],256);
undumpthings(xprn[0],256);
if eightbitp then for k:=0 to 255 do xprn[k]:=1;end;{:1873};
undumpint(x);if x<>268435455 then goto 6666;undumpint(hashhigh);
if(hashhigh<0)or(hashhigh>suphashextra)then goto 6666;
if hashextra<hashhigh then hashextra:=hashhigh;eqtbtop:=28082+hashextra;
if hashextra=0 then hashtop:=24527 else hashtop:=eqtbtop;
yhash:=xmallocarray(twohalves,1+hashtop-hashoffset);
hash:=yhash-hashoffset;hash[514].lh:=0;hash[514].rh:=0;
for x:=515 to hashtop do hash[x]:=hash[514];
zeqtb:=xmallocarray(memoryword,eqtbtop+1);eqtb:=zeqtb;
eqtb[24527].hh.b0:=103;eqtb[24527].hh.rh:=-268435455;
eqtb[24527].hh.b1:=0;for x:=28083 to eqtbtop do eqtb[x]:=eqtb[24527];
{1653:}begin undumpint(x);if(x<0)or(x>1)then goto 6666 else eTeXmode:=x;
end;if(eTeXmode=1)then begin{1811:}maxregnum:=32767;
maxreghelpline:=2055;{:1811}end else begin{1810:}maxregnum:=255;
maxreghelpline:=790;{:1810}end;{:1653}undumpint(x);
if debugformatfile then begin write(stderr,'fmtdebug:','mem_bot');
writeln(stderr,' = ',x);end;;if x<>membot then goto 6666;
undumpint(memtop);
if debugformatfile then begin write(stderr,'fmtdebug:','mem_top');
writeln(stderr,' = ',memtop);end;;if membot+1100>memtop then goto 6666;
curlist.headfield:=memtop-1;curlist.tailfield:=memtop-1;
pagetail:=memtop-2;memmin:=membot-extramembot;
memmax:=memtop+extramemtop;
yzmem:=xmallocarray(memoryword,memmax-memmin+1);zmem:=yzmem-memmin;
mem:=zmem;undumpint(x);if x<>28082 then goto 6666;undumpint(x);
if x<>8501 then goto 6666;undumpint(x);if x<>607 then goto 6666{:1487};
{1887:}undumpint(x);if x<>1296847960 then goto 6666;undumpint(x);
if x=1 then mltexenabledp:=true else if x<>0 then goto 6666;{:1887};
{1896:}undumpint(x);if x<>1162040408 then goto 6666;undumpint(x);
if x=0 then enctexenabledp:=false else if x<>1 then goto 6666 else begin
enctexenabledp:=true;undumpthings(mubyteread[0],256);
undumpthings(mubytewrite[0],256);undumpthings(mubytecswrite[0],128);end;
{:1896};{1489:}begin undumpint(x);if x<0 then goto 6666;
if x>suppoolsize-poolfree then begin;
writeln(stdout,'---! Must increase the ','string pool size');goto 6666;
end else if debugformatfile then begin write(stderr,'fmtdebug:',
'string pool size');writeln(stderr,' = ',x);end;;poolptr:=x;end;
if poolsize<poolptr+poolfree then poolsize:=poolptr+poolfree;
begin undumpint(x);if x<0 then goto 6666;
if x>supmaxstrings-stringsfree then begin;
writeln(stdout,'---! Must increase the ','sup strings');goto 6666;
end else if debugformatfile then begin write(stderr,'fmtdebug:',
'sup strings');writeln(stderr,' = ',x);end;;strptr:=x;end;
if maxstrings<strptr+stringsfree then maxstrings:=strptr+stringsfree;
strstart:=xmallocarray(poolpointer,maxstrings);
undumpcheckedthings(0,poolptr,strstart[0],strptr+1);
strpool:=xmallocarray(packedASCIIcode,poolsize);
undumpthings(strpool[0],poolptr);initstrptr:=strptr;
initpoolptr:=poolptr{:1489};{1491:}begin undumpint(x);
if(x<membot+1019)or(x>memtop-15)then goto 6666 else lomemmax:=x;end;
begin undumpint(x);
if(x<membot+20)or(x>lomemmax)then goto 6666 else rover:=x;end;
if(eTeXmode=1)then for k:=0 to 5 do begin undumpint(x);
if(x<-268435455)or(x>lomemmax)then goto 6666 else saroot[k]:=x;end;
p:=membot;q:=rover;repeat undumpthings(mem[p],q+2-p);p:=q+mem[q].hh.lh;
if(p>lomemmax)or((q>=mem[q+1].hh.rh)and(mem[q+1].hh.rh<>rover))then goto
6666;q:=mem[q+1].hh.rh;until q=rover;undumpthings(mem[p],lomemmax+1-p);
if memmin<membot-2 then begin p:=mem[rover+1].hh.lh;q:=memmin+1;
mem[memmin].hh.rh:=-268435455;mem[memmin].hh.lh:=-268435455;
mem[p+1].hh.rh:=q;mem[rover+1].hh.lh:=q;mem[q+1].hh.rh:=rover;
mem[q+1].hh.lh:=p;mem[q].hh.rh:=268435455;mem[q].hh.lh:=membot-q;end;
begin undumpint(x);
if(x<lomemmax+1)or(x>memtop-14)then goto 6666 else himemmin:=x;end;
begin undumpint(x);
if(x<-268435455)or(x>memtop)then goto 6666 else avail:=x;end;
memend:=memtop;undumpthings(mem[himemmin],memend+1-himemmin);
undumpint(varused);undumpint(dynused){:1491};{1493:}{1496:}k:=1;
repeat undumpint(x);if(x<1)or(k+x>28083)then goto 6666;
undumpthings(eqtb[k],x);k:=k+x;undumpint(x);
if(x<0)or(k+x>28083)then goto 6666;
for j:=k to k+x-1 do eqtb[j]:=eqtb[k-1];k:=k+x;until k>28082;
if hashhigh>0 then undumpthings(eqtb[28083],hashhigh);{:1496};
begin undumpint(x);if(x<514)or(x>hashtop)then goto 6666 else parloc:=x;
end;partoken:=4095+parloc;begin undumpint(x);
if(x<514)or(x>hashtop)then goto 6666 else writeloc:=x;end;
{1498:}for p:=0 to 2100 do undumphh(prim[p]);
for p:=0 to 2100 do undumpwd(primeqtb[p]);begin undumpint(x);
if(x<514)or(x>15514)then goto 6666 else hashused:=x;end;p:=513;
repeat begin undumpint(x);
if(x<p+1)or(x>hashused)then goto 6666 else p:=x;end;undumphh(hash[p]);
until p=hashused;undumpthings(hash[hashused+1],24526-hashused);
if debugformatfile then begin printcsnames(514,24526);end;
if hashhigh>0 then begin undumpthings(hash[28083],hashhigh);
if debugformatfile then begin printcsnames(28083,hashhigh-(28083));end;
end;undumpint(cscount){:1498}{:1493};{1500:}begin undumpint(x);
if x<7 then goto 6666;if x>supfontmemsize then begin;
writeln(stdout,'---! Must increase the ','font mem size');goto 6666;
end else if debugformatfile then begin write(stderr,'fmtdebug:',
'font mem size');writeln(stderr,' = ',x);end;;fmemptr:=x;end;
if fmemptr>fontmemsize then fontmemsize:=fmemptr;
fontinfo:=xmallocarray(fmemoryword,fontmemsize);
undumpthings(fontinfo[0],fmemptr);begin undumpint(x);
if x<0 then goto 6666;if x>9000 then begin;
writeln(stdout,'---! Must increase the ','font max');goto 6666;
end else if debugformatfile then begin write(stderr,'fmtdebug:',
'font max');writeln(stderr,' = ',x);end;;fontptr:=x;end;
{1502:}begin fontcheck:=xmallocarray(fourquarters,fontmax);
fontsize:=xmallocarray(scaled,fontmax);
fontdsize:=xmallocarray(scaled,fontmax);
fontparams:=xmallocarray(fontindex,fontmax);
fontname:=xmallocarray(strnumber,fontmax);
fontarea:=xmallocarray(strnumber,fontmax);
fontbc:=xmallocarray(eightbits,fontmax);
fontec:=xmallocarray(eightbits,fontmax);
fontglue:=xmallocarray(halfword,fontmax);
hyphenchar:=xmallocarray(integer,fontmax);
skewchar:=xmallocarray(integer,fontmax);
bcharlabel:=xmallocarray(fontindex,fontmax);
fontbchar:=xmallocarray(ninebits,fontmax);
fontfalsebchar:=xmallocarray(ninebits,fontmax);
charbase:=xmallocarray(integer,fontmax);
widthbase:=xmallocarray(integer,fontmax);
heightbase:=xmallocarray(integer,fontmax);
depthbase:=xmallocarray(integer,fontmax);
italicbase:=xmallocarray(integer,fontmax);
ligkernbase:=xmallocarray(integer,fontmax);
kernbase:=xmallocarray(integer,fontmax);
extenbase:=xmallocarray(integer,fontmax);
parambase:=xmallocarray(integer,fontmax);
pdfcharused:=xmallocarray(charusedarray,fontmax);
pdffontsize:=xmallocarray(scaled,fontmax);
pdffontnum:=xmallocarray(integer,fontmax);
pdffontmap:=xmallocarray(fmentryptr,fontmax);
pdffonttype:=xmallocarray(eightbits,fontmax);
pdffontattr:=xmallocarray(strnumber,fontmax);
pdffontblink:=xmallocarray(internalfontnumber,fontmax);
pdffontelink:=xmallocarray(internalfontnumber,fontmax);
pdffontstretch:=xmallocarray(integer,fontmax);
pdffontshrink:=xmallocarray(integer,fontmax);
pdffontstep:=xmallocarray(integer,fontmax);
pdffontexpandratio:=xmallocarray(integer,fontmax);
pdffontautoexpand:=xmallocarray(boolean,fontmax);
pdffontlpbase:=xmallocarray(integer,fontmax);
pdffontrpbase:=xmallocarray(integer,fontmax);
pdffontefbase:=xmallocarray(integer,fontmax);
pdffontknbsbase:=xmallocarray(integer,fontmax);
pdffontstbsbase:=xmallocarray(integer,fontmax);
pdffontshbsbase:=xmallocarray(integer,fontmax);
pdffontknbcbase:=xmallocarray(integer,fontmax);
pdffontknacbase:=xmallocarray(integer,fontmax);
vfpacketbase:=xmallocarray(integer,fontmax);
vfdefaultfont:=xmallocarray(internalfontnumber,fontmax);
vflocalfontnum:=xmallocarray(internalfontnumber,fontmax);
vfefnts:=xmallocarray(integer,fontmax);
vfifnts:=xmallocarray(internalfontnumber,fontmax);
pdffontnobuiltintounicode:=xmallocarray(boolean,fontmax);
for fontk:=0 to fontmax do begin for k:=0 to 31 do pdfcharused[fontk,k]
:=0;pdffontsize[fontk]:=0;pdffontnum[fontk]:=0;pdffontmap[fontk]:=0;
pdffonttype[fontk]:=0;pdffontattr[fontk]:=345;pdffontblink[fontk]:=0;
pdffontelink[fontk]:=0;pdffontstretch[fontk]:=0;pdffontshrink[fontk]:=0;
pdffontstep[fontk]:=0;pdffontexpandratio[fontk]:=0;
pdffontautoexpand[fontk]:=false;pdffontlpbase[fontk]:=0;
pdffontrpbase[fontk]:=0;pdffontefbase[fontk]:=0;
pdffontknbsbase[fontk]:=0;pdffontstbsbase[fontk]:=0;
pdffontshbsbase[fontk]:=0;pdffontknbcbase[fontk]:=0;
pdffontknacbase[fontk]:=0;pdffontnobuiltintounicode[fontk]:=false;end;
makepdftexbanner;undumpthings(fontcheck[0],fontptr+1);
undumpthings(fontsize[0],fontptr+1);
undumpthings(fontdsize[0],fontptr+1);
undumpcheckedthings(-268435455,268435455,fontparams[0],fontptr+1);
undumpthings(hyphenchar[0],fontptr+1);
undumpthings(skewchar[0],fontptr+1);
undumpuppercheckthings(strptr,fontname[0],fontptr+1);
undumpuppercheckthings(strptr,fontarea[0],fontptr+1);
undumpthings(fontbc[0],fontptr+1);undumpthings(fontec[0],fontptr+1);
undumpthings(charbase[0],fontptr+1);
undumpthings(widthbase[0],fontptr+1);
undumpthings(heightbase[0],fontptr+1);
undumpthings(depthbase[0],fontptr+1);
undumpthings(italicbase[0],fontptr+1);
undumpthings(ligkernbase[0],fontptr+1);
undumpthings(kernbase[0],fontptr+1);
undumpthings(extenbase[0],fontptr+1);
undumpthings(parambase[0],fontptr+1);
undumpcheckedthings(-268435455,lomemmax,fontglue[0],fontptr+1);
undumpcheckedthings(0,fmemptr-1,bcharlabel[0],fontptr+1);
undumpcheckedthings(0,256,fontbchar[0],fontptr+1);
undumpcheckedthings(0,256,fontfalsebchar[0],fontptr+1);end{:1502};
{:1500};{1504:}begin undumpint(x);if x<0 then goto 6666;
if x>hyphsize then begin;
writeln(stdout,'---! Must increase the ','hyph_size');goto 6666;
end else if debugformatfile then begin write(stderr,'fmtdebug:',
'hyph_size');writeln(stderr,' = ',x);end;;hyphcount:=x;end;
begin undumpint(x);if x<607 then goto 6666;if x>hyphsize then begin;
writeln(stdout,'---! Must increase the ','hyph_size');goto 6666;
end else if debugformatfile then begin write(stderr,'fmtdebug:',
'hyph_size');writeln(stderr,' = ',x);end;;hyphnext:=x;end;j:=0;
for k:=1 to hyphcount do begin undumpint(j);if j<0 then goto 6666;
if j>65535 then begin hyphnext:=j div 65536;j:=j-hyphnext*65536;
end else hyphnext:=0;if(j>=hyphsize)or(hyphnext>hyphsize)then goto 6666;
hyphlink[j]:=hyphnext;begin undumpint(x);
if(x<0)or(x>strptr)then goto 6666 else hyphword[j]:=x;end;
begin undumpint(x);
if(x<-268435455)or(x>268435455)then goto 6666 else hyphlist[j]:=x;end;
end;incr(j);if j<607 then j:=607;hyphnext:=j;
if hyphnext>=hyphsize then hyphnext:=607 else if hyphnext>=607 then incr
(hyphnext);begin undumpint(x);if x<0 then goto 6666;
if x>triesize then begin;
writeln(stdout,'---! Must increase the ','trie size');goto 6666;
end else if debugformatfile then begin write(stderr,'fmtdebug:',
'trie size');writeln(stderr,' = ',x);end;;j:=x;end;
ifdef('INITEX')triemax:=j;endif('INITEX')begin undumpint(x);
if(x<0)or(x>j)then goto 6666 else hyphstart:=x;end;
if not trietrl then trietrl:=xmallocarray(triepointer,j+1);
undumpthings(trietrl[0],j+1);
if not trietro then trietro:=xmallocarray(triepointer,j+1);
undumpthings(trietro[0],j+1);
if not trietrc then trietrc:=xmallocarray(quarterword,j+1);
undumpthings(trietrc[0],j+1);begin undumpint(x);if x<0 then goto 6666;
if x>trieopsize then begin;
writeln(stdout,'---! Must increase the ','trie op size');goto 6666;
end else if debugformatfile then begin write(stderr,'fmtdebug:',
'trie op size');writeln(stderr,' = ',x);end;;j:=x;end;
ifdef('INITEX')trieopptr:=j;
endif('INITEX')undumpthings(hyfdistance[1],j);undumpthings(hyfnum[1],j);
undumpuppercheckthings(maxtrieop,hyfnext[1],j);
ifdef('INITEX')for k:=0 to 255 do trieused[k]:=0;endif('INITEX')k:=256;
while j>0 do begin begin undumpint(x);
if(x<0)or(x>k-1)then goto 6666 else k:=x;end;begin undumpint(x);
if(x<1)or(x>j)then goto 6666 else x:=x;end;
ifdef('INITEX')trieused[k]:=x;endif('INITEX')j:=j-x;opstart[k]:=j;end;
ifdef('INITEX')trienotready:=false endif('INITEX'){:1504};
{1506:}begin undumpimagemeta(eqtb[27248].int,eqtb[27251].int);
undumpint(pdfmemsize);pdfmem:=xreallocarray(pdfmem,integer,pdfmemsize);
undumpint(pdfmemptr);
for k:=1 to pdfmemptr-1 do begin undumpint(pdfmem[k]);end;
undumpint(objtabsize);undumpint(objptr);undumpint(sysobjptr);
for k:=1 to sysobjptr do begin undumpint(objtab[k].int0);
undumpint(objtab[k].int1);objtab[k].int2:=-1;undumpint(objtab[k].int3);
undumpint(objtab[k].int4);end;undumpint(pdfobjcount);
undumpint(pdfxformcount);undumpint(pdfximagecount);
undumpint(headtab[6]);undumpint(headtab[7]);undumpint(headtab[8]);
undumpint(pdflastobj);undumpint(pdflastxform);undumpint(pdflastximage);
end{:1506};{1508:}begin undumpint(x);
if(x<0)or(x>3)then goto 6666 else interaction:=x;end;
if interactionoption<>4 then interaction:=interactionoption;
begin undumpint(x);
if(x<0)or(x>strptr)then goto 6666 else formatident:=x;end;undumpint(x);
if x<>69069 then goto 6666{:1508};curlist.auxfield.int:=eqtb[27825].int;
loadfmtfile:=true;goto 10;6666:;
writeln(stdout,'(Fatal format file error; I''m stymied)');
loadfmtfile:=false;10:end;
{:1482}{1511:}{1514:}procedure closefilesandterminate;label 30,31;
var a,b,c,i,j,k,l:integer;isroot:boolean;isnames:boolean;
root,outlines,threads,namestree,dests:integer;
xrefoffsetwidth,nameshead,namestail:integer;
begin{1624:}for k:=0 to 15 do if writeopen[k]then aclose(writefile[k])
{:1624};
ifdef('STAT')if eqtb[27208].int>0 then{1515:}if logopened then begin
writeln(logfile,' ');
writeln(logfile,'Here is how much of TeX''s memory',' you used:');
write(logfile,' ',strptr-initstrptr:1,' string');
if strptr<>initstrptr+1 then write(logfile,'s');
writeln(logfile,' out of ',maxstrings-initstrptr:1);
writeln(logfile,' ',poolptr-initpoolptr:1,' string characters out of ',
poolsize-initpoolptr:1);
writeln(logfile,' ',lomemmax-memmin+memend-himemmin+2:1,
' words of memory out of ',memend+1-memmin:1);
writeln(logfile,' ',cscount:1,' multiletter control sequences out of ',
15000:1,'+',hashextra:1);
write(logfile,' ',fmemptr:1,' words of font info for ',fontptr-0:1,
' font');if fontptr<>1 then write(logfile,'s');
writeln(logfile,', out of ',fontmemsize:1,' for ',fontmax-0:1);
write(logfile,' ',hyphcount:1,' hyphenation exception');
if hyphcount<>1 then write(logfile,'s');
writeln(logfile,' out of ',hyphsize:1);
writeln(logfile,' ',maxinstack:1,'i,',maxneststack:1,'n,',maxparamstack:
1,'p,',maxbufstack+1:1,'b,',maxsavestack+6:1,'s stack positions out of '
,stacksize:1,'i,',nestsize:1,'n,',paramsize:1,'p,',bufsize:1,'b,',
savesize:1,'s');end{:1515};endif('STAT');
if not fixedpdfoutputset then fixpdfoutput;
if fixedpdfoutput>0 then begin if history=3 then begin removepdffile;
synctexabort(logopened);begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(264);print(1710);
end end else begin{797:}if totalpages=0 then begin printnl(996);
if pdfgone>0 then garbagewarning;
end else begin if fixedpdfdraftmode=0 then begin pdfflush;
if totalpages mod 6<>0 then objtab[pdflastpages].int0:=totalpages mod 6;
flushjbig2page0objects;{800:}k:=headtab[1];
while objtab[k].int4=0 do begin pdfwarning(1185,1190,false,false);
printint(objtab[k].int0);print(1191);println;println;k:=objtab[k].int1;
end;headtab[1]:=k{:800};{801:}k:=headtab[1];l:=0;
repeat i:=objtab[k].int1;objtab[k].int1:=l;l:=k;k:=i;until k=0;
headtab[1]:=l;k:=headtab[2];pagestail:=k;l:=0;repeat i:=objtab[k].int1;
objtab[k].int1:=l;l:=k;k:=i;until k=0;headtab[2]:=l{:801};
{799:}k:=headtab[5];while k<>0 do begin pdffixdest(k);k:=objtab[k].int1;
end{:799};
{802:}for k:=1 to fontptr do if fontused[k]and hasfmentry(k)and(
pdffontnum[k]<0)then begin i:=-pdffontnum[k];pdfassert(pdffontnum[i]>0);
for j:=0 to 255 do if pdfcharmarked(k,j)then pdfmarkchar(i,j);
if((strstart[pdffontattr[i]+1]-strstart[pdffontattr[i]])=0)and((strstart
[pdffontattr[k]+1]-strstart[pdffontattr[k]])<>0)then pdffontattr[i]:=
pdffontattr[k]else if((strstart[pdffontattr[k]+1]-strstart[pdffontattr[k
]])=0)and((strstart[pdffontattr[i]+1]-strstart[pdffontattr[i]])<>0)then
pdffontattr[k]:=pdffontattr[i]else if((strstart[pdffontattr[i]+1]-
strstart[pdffontattr[i]])<>0)and((strstart[pdffontattr[k]+1]-strstart[
pdffontattr[k]])<>0)and not streqstr(pdffontattr[i],pdffontattr[k])then
begin pdfwarning(1192,1193,false,false);printfontidentifier(i);
print(1194);printfontidentifier(k);print(1195);printfontidentifier(i);
println;println;end;end;fixedgentounicode:=eqtb[27263].int;
k:=headtab[3];while k<>0 do begin f:=objtab[k].int0;
pdfassert(pdffontnum[f]>0);dopdffont(k,f);k:=objtab[k].int1;end;
writefontstuff{:802};{803:}a:=sysobjptr+1;l:=headtab[2];k:=headtab[1];
b:=0;repeat i:=0;c:=0;
if objtab[l].int1=0 then isroot:=true else isroot:=false;
repeat if not isroot then begin if i mod 6=0 then begin pdflastpages:=
pdfnewobjnum;if c=0 then c:=pdflastpages;
objtab[pagestail].int1:=pdflastpages;pagestail:=pdflastpages;
objtab[pdflastpages].int1:=0;objtab[pdflastpages].int0:=objtab[l].int0;
end else objtab[pdflastpages].int0:=objtab[pdflastpages].int0+objtab[l].
int0;end;{804:}pdfbegindict(l,1);begin pdfprint(1196);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfintentryln(1180,objtab[l].int0);
if not isroot then pdfindirectln(1155,pdflastpages);pdfprint(1197);j:=0;
repeat pdfprintint(k);pdfprint(1141);k:=objtab[k].int1;incr(j);
until((l<a)and(j=objtab[l].int0))or(k=0)or((k=b)and(b<>0))or(j=6);
removelastspace;begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if k=0 then begin k:=headtab[2];headtab[2]:=0;end;
if isroot and(eqtb[25068].hh.rh<>-268435455)then pdfprinttoksln(eqtb[
25068].hh.rh);pdfenddict;{:804};incr(i);l:=objtab[l].int1;until(l=c);
b:=c;if l=0 then goto 30;until false;30:{:803};
{791:}if pdffirstoutline<>0 then begin pdfnewdict(0,0,1);
outlines:=objptr;l:=pdffirstoutline;k:=0;repeat incr(k);
a:=opensubentries(l);if objtab[l].int0>0 then k:=k+a;
pdfmem[objtab[l].int4+1]:=objptr;l:=pdfmem[objtab[l].int4+3];until l=0;
begin pdfprint(1177);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfindirectln(1178,pdffirstoutline);pdfindirectln(1179,pdflastoutline);
pdfintentryln(1180,k);pdfenddict;{792:}k:=headtab[4];
while k<>0 do begin if pdfmem[objtab[k].int4+1]=pdfparentoutline then
begin if pdfmem[objtab[k].int4+2]=0 then pdffirstoutline:=k;
if pdfmem[objtab[k].int4+3]=0 then pdflastoutline:=k;end;
pdfbegindict(k,1);pdfindirectln(1181,pdfmem[objtab[k].int4]);
pdfindirectln(65,pdfmem[objtab[k].int4+6]);
if pdfmem[objtab[k].int4+1]<>0 then pdfindirectln(1155,pdfmem[objtab[k].
int4+1]);
if pdfmem[objtab[k].int4+2]<>0 then pdfindirectln(1182,pdfmem[objtab[k].
int4+2]);
if pdfmem[objtab[k].int4+3]<>0 then pdfindirectln(1183,pdfmem[objtab[k].
int4+3]);
if pdfmem[objtab[k].int4+4]<>0 then pdfindirectln(1178,pdfmem[objtab[k].
int4+4]);
if pdfmem[objtab[k].int4+5]<>0 then pdfindirectln(1179,pdfmem[objtab[k].
int4+5]);if objtab[k].int0<>0 then pdfintentryln(1180,objtab[k].int0);
if pdfmem[objtab[k].int4+7]<>0 then begin pdfprinttoksln(pdfmem[objtab[k
].int4+7]);begin deletetokenref(pdfmem[objtab[k].int4+7]);
pdfmem[objtab[k].int4+7]:=-268435455;end;end;pdfenddict;
k:=objtab[k].int1;end{:792};end else outlines:=0{:791};
{805:}if pdfdestnamesptr=0 then begin dests:=0;goto 31;end;
sortdestnames(0,pdfdestnamesptr-1);nameshead:=0;namestail:=0;k:=0;
isnames:=true;b:=0;repeat repeat pdfcreateobj(0,0);l:=objptr;
if b=0 then b:=l;if nameshead=0 then begin nameshead:=l;namestail:=l;
end else begin objtab[namestail].int1:=l;namestail:=l;end;
objtab[namestail].int1:=0;{806:}pdfbegindict(l,1);j:=0;
if isnames then begin objtab[l].int0:=destnames[k].objname;
pdfprint(1199);repeat pdfprintstr(destnames[k].objname);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintint(destnames[k].objnum);pdfprint(1141);incr(j);incr(k);
until(j=6)or(k=pdfdestnamesptr);removelastspace;begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
objtab[l].int4:=destnames[k-1].objname;
if k=pdfdestnamesptr then begin isnames:=false;k:=nameshead;b:=0;end;
end else begin objtab[l].int0:=objtab[k].int0;pdfprint(1197);
repeat pdfprintint(k);pdfprint(1141);incr(j);
objtab[l].int4:=objtab[k].int4;k:=objtab[k].int1;
until(j=6)or(k=b)or(objtab[k].int1=0);removelastspace;
begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;if k=b then b:=0;end;
pdfprint(1200);pdfprintstr(objtab[l].int0);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=32;incr(pdfptr);end;end;
pdfprintstr(objtab[l].int4);begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfenddict;{:806};
until b=0;if k=l then begin dests:=l;goto 31;end;until false;
31:if(dests<>0)or(pdfnamestoks<>-268435455)then begin pdfnewdict(0,0,1);
if(dests<>0)then pdfindirectln(1198,dests);
if pdfnamestoks<>-268435455 then begin pdfprinttoksln(pdfnamestoks);
begin deletetokenref(pdfnamestoks);pdfnamestoks:=-268435455;end;end;
pdfenddict;namestree:=objptr;end else namestree:=0{:805};
{793:}if headtab[9]<>0 then begin pdfnewobj(0,0,1);threads:=objptr;
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=91;incr(pdfptr);end;end;k:=headtab[9];
while k<>0 do begin pdfprintint(k);pdfprint(1141);k:=objtab[k].int1;end;
removelastspace;begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfendobj;
k:=headtab[9];while k<>0 do begin outthread(k);k:=objtab[k].int1;end;
end else threads:=0{:793};{807:}pdfnewdict(0,0,1);root:=objptr;
begin pdfprint(1201);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfindirectln(1202,pdflastpages);
if threads<>0 then pdfindirectln(1203,threads);
if outlines<>0 then pdfindirectln(1204,outlines);
if namestree<>0 then pdfindirectln(1205,namestree);
if pdfcatalogtoks<>-268435455 then begin pdfprinttoksln(pdfcatalogtoks);
begin deletetokenref(pdfcatalogtoks);pdfcatalogtoks:=-268435455;end;end;
if pdfcatalogopenaction<>0 then pdfindirectln(1206,pdfcatalogopenaction)
;pdfenddict{:807};pdfprintinfo;
if pdfosenable then begin pdfosswitch(true);pdfoswriteobjstream;
pdfflush;pdfosswitch(false);{815:}pdfnewdict(0,0,0);
if((objtab[sysobjptr].int2/256)>16777215)then xrefoffsetwidth:=5 else if
objtab[sysobjptr].int2>16777215 then xrefoffsetwidth:=4 else if objtab[
sysobjptr].int2>65535 then xrefoffsetwidth:=3 else xrefoffsetwidth:=2;
{813:}l:=0;objtab[l].int2:=-2;
for k:=1 to sysobjptr do if not(objtab[k].int2>-1)then begin objtab[l].
int1:=k;l:=k;end;objtab[l].int1:=0{:813};begin pdfprint(1222);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfprint(1223);
pdfprintint(objptr+1);begin pdfprint(93);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfintentryln(1224,objptr+1);pdfprint(1225);
pdfprintint(xrefoffsetwidth);begin pdfprint(1226);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfindirectln(1227,root);pdfindirectln(1228,objptr-1);
if pdftrailertoks<>-268435455 then begin pdfprinttoksln(pdftrailertoks);
begin deletetokenref(pdftrailertoks);pdftrailertoks:=-268435455;end;end;
if pdftraileridtoks<>-268435455 then printIDalt(pdftraileridtoks)else
printID(outputfilename);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;pdfbeginstream;
for k:=0 to sysobjptr do begin if not(objtab[k].int2>-1)then begin begin
begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)else if
not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)else if
not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=0;incr(pdfptr);end;end;
pdfoutbytes(objtab[k].int1,xrefoffsetwidth);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=255;incr(pdfptr);end;end;
end else begin if objtab[k].int3=-1 then begin begin begin if pdfosmode
and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)else if not pdfosmode and(1
>pdfbufsize)then overflow(1004,pdfopbufsize)else if not pdfosmode and(1+
pdfptr>pdfbufsize)then pdfflush;end;begin pdfbuf[pdfptr]:=1;
incr(pdfptr);end;end;pdfoutbytes(objtab[k].int2,xrefoffsetwidth);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=0;incr(pdfptr);end;end;
end else begin begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then
pdfosgetosbuf(1)else if not pdfosmode and(1>pdfbufsize)then overflow(
1004,pdfopbufsize)else if not pdfosmode and(1+pdfptr>pdfbufsize)then
pdfflush;end;begin pdfbuf[pdfptr]:=2;incr(pdfptr);end;end;
pdfoutbytes(objtab[k].int2,xrefoffsetwidth);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=objtab[k].int3;incr(pdfptr);end;end;end;end;end;
pdfendstream;{:815};pdfflush;end else begin{814:}{813:}l:=0;
objtab[l].int2:=-2;
for k:=1 to sysobjptr do if not(objtab[k].int2>-1)then begin objtab[l].
int1:=k;l:=k;end;objtab[l].int1:=0{:813};
pdfsaveoffset:=(pdfgone+pdfptr);begin pdfprint(1217);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfprint(1218);
begin pdfprintint(objptr+1);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
pdfprintfwint(objtab[0].int1,10);begin pdfprint(1219);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
for k:=1 to objptr do begin if not(objtab[k].int2>-1)then begin
pdfprintfwint(objtab[k].int1,10);begin pdfprint(1220);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
end else begin pdfprintfwint(objtab[k].int2,10);begin pdfprint(1221);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;end{:814};end;
{816:}if not pdfosenable then begin begin pdfprint(1229);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;pdfprint(1230);
pdfintentryln(1224,sysobjptr+1);pdfindirectln(1227,root);
pdfindirectln(1228,sysobjptr);
if pdftrailertoks<>-268435455 then begin pdfprinttoksln(pdftrailertoks);
begin deletetokenref(pdftrailertoks);pdftrailertoks:=-268435455;end;end;
if pdftraileridtoks<>-268435455 then printIDalt(pdftraileridtoks)else
printID(outputfilename);begin pdfprint(1231);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;end;
begin pdfprint(1232);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;
if pdfosenable then begin pdfprintint(objtab[sysobjptr].int2);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;
end else begin pdfprintint(pdfsaveoffset);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end;begin pdfprint(1233);
begin begin if pdfosmode and(1+pdfptr>pdfbufsize)then pdfosgetosbuf(1)
else if not pdfosmode and(1>pdfbufsize)then overflow(1004,pdfopbufsize)
else if not pdfosmode and(1+pdfptr>pdfbufsize)then pdfflush;end;
begin pdfbuf[pdfptr]:=10;incr(pdfptr);end;end;end{:816};pdfflush;
printnl(997);printfilename(0,outputfilename,0);print(286);
printint(totalpages);print(999);if totalpages<>1 then printchar(115);
print(1000);printint((pdfgone+pdfptr));print(1001);end;libpdffinish;
if fixedpdfdraftmode=0 then bclose(pdffile)else pdfwarning(0,1184,true,
true)end{:797};if logopened then begin writeln(logfile);
writeln(logfile,'PDF statistics:');
writeln(logfile,' ',objptr:1,' PDF objects out of ',objtabsize:1,
' (max. ',supobjtabsize:1,')');
if pdfoscntr>0 then begin write(logfile,' ',((pdfoscntr-1)*pdfosmaxobjs+
pdfosobjidx+1):1,' compressed objects within ',pdfoscntr:1,
' object stream');if pdfoscntr>1 then write(logfile,'s');
writeln(logfile);end;
writeln(logfile,' ',pdfdestnamesptr:1,' named destinations out of ',
destnamessize:1,' (max. ',supdestnamessize:1,')');
writeln(logfile,' ',pdfmemptr:1,
' words of extra memory for PDF output out of ',pdfmemsize:1,' (max. ',
suppdfmemsize:1,')');end;end;
end else begin{673:}while curs>-1 do begin if curs>0 then begin dvibuf[
dviptr]:=142;incr(dviptr);if dviptr=dvilimit then dviswap;
end else begin begin dvibuf[dviptr]:=140;incr(dviptr);
if dviptr=dvilimit then dviswap;end;incr(totalpages);end;decr(curs);end;
if totalpages=0 then printnl(996)else if curs<>-2 then begin begin
dvibuf[dviptr]:=248;incr(dviptr);if dviptr=dvilimit then dviswap;end;
dvifour(lastbop);lastbop:=dvioffset+dviptr-5;dvifour(25400000);
dvifour(473628672);preparemag;dvifour(eqtb[27194].int);dvifour(maxv);
dvifour(maxh);begin dvibuf[dviptr]:=maxpush div 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=maxpush mod 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=(totalpages div 256)mod 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=totalpages mod 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
{674:}while fontptr>0 do begin if fontused[fontptr]then dvifontdef(
fontptr);decr(fontptr);end{:674};begin dvibuf[dviptr]:=249;incr(dviptr);
if dviptr=dvilimit then dviswap;end;dvifour(lastbop);
begin dvibuf[dviptr]:=2;incr(dviptr);if dviptr=dvilimit then dviswap;
end;ifdef('IPC')k:=7-((3+dvioffset+dviptr)mod 4);
endif('IPC')ifndef('IPC')k:=4+((dvibufsize-dviptr)mod 4);
endifn('IPC')while k>0 do begin begin dvibuf[dviptr]:=223;incr(dviptr);
if dviptr=dvilimit then dviswap;end;decr(k);end;
{629:}if dvilimit=halfbuf then writedvi(halfbuf,dvibufsize-1);
if dviptr>(2147483647-dvioffset)then begin curs:=-2;fatalerror(985);end;
if dviptr>0 then writedvi(0,dviptr-1){:629};printnl(997);
printfilename(0,outputfilename,0);print(286);printint(totalpages);
if totalpages<>1 then print(998)else print(999);print(1000);
printint(dvioffset+dviptr);print(1001);bclose(dvifile);end{:673};end;
{1914:}synctexterminate(logopened);{:1914};
if logopened then begin writeln(logfile);aclose(logfile);
selector:=selector-2;if selector=17 then begin printnl(1711);
printfilename(0,texmflogname,0);printchar(46);end;end;println;
if(editnamestart<>0)and(interaction>0)then calledit(strpool,
editnamestart,editnamelength,editline);end;
{:1514}{1516:}procedure finalcleanup;label 10;var c:smallnumber;
begin c:=curchr;if jobname=0 then openlogfile;
while inputptr>0 do if curinput.statefield=0 then endtokenlist else
endfilereading;while openparens>0 do begin print(1712);decr(openparens);
end;if curlevel>1 then begin printnl(40);printesc(1713);print(1714);
printint(curlevel-1);printchar(41);if(eTeXmode=1)then showsavegroups;
end;while condptr<>-268435455 do begin printnl(40);printesc(1713);
print(1715);printcmdchr(107,curif);if ifline<>0 then begin print(1716);
printint(ifline);end;print(1717);ifline:=mem[condptr+1].int;
curif:=mem[condptr].hh.b1;tempptr:=condptr;condptr:=mem[condptr].hh.rh;
freenode(tempptr,2);end;
if history<>0 then if((history=1)or(interaction<3))then if selector=19
then begin selector:=17;printnl(1718);selector:=19;end;
if c=1 then begin ifdef('INITEX')if iniversion then begin for c:=0 to 4
do if curmark[c]<>-268435455 then deletetokenref(curmark[c]);
if saroot[6]<>-268435455 then if domarks(3,0,saroot[6])then saroot[6]:=
-268435455;for c:=2 to 3 do flushnodelist(discptr[c]);
if lastglue<>268435455 then deleteglueref(lastglue);storefmtfile;
goto 10;end;endif('INITEX')printnl(1719);goto 10;end;10:end;
{:1516}{1517:}ifdef('INITEX')procedure initprim;
begin nonewcontrolsequence:=false;first:=0;
{244:}primitive(393,75,24528);primitive(394,75,24529);
primitive(395,75,24530);primitive(396,75,24531);primitive(397,75,24532);
primitive(398,75,24533);primitive(399,75,24534);primitive(400,75,24535);
primitive(401,75,24536);primitive(402,75,24537);primitive(403,75,24538);
primitive(404,75,24539);primitive(405,75,24540);primitive(406,75,24541);
primitive(407,75,24542);primitive(408,76,24543);primitive(409,76,24544);
primitive(410,76,24545);{:244}{248:}primitive(414,72,25059);
primitive(415,72,25060);primitive(416,72,25061);primitive(417,72,25062);
primitive(418,72,25063);primitive(419,72,25064);primitive(420,72,25065);
primitive(421,72,25066);primitive(422,72,25067);primitive(423,72,25068);
primitive(424,72,25069);primitive(425,72,25070);primitive(426,72,25071);
{:248}{256:}primitive(440,73,27177);primitive(441,73,27178);
primitive(442,73,27179);primitive(443,73,27180);primitive(444,73,27181);
primitive(445,73,27182);primitive(446,73,27183);primitive(447,73,27184);
primitive(448,73,27185);primitive(449,73,27186);primitive(450,73,27187);
primitive(451,73,27188);primitive(452,73,27189);primitive(453,73,27190);
primitive(454,73,27191);primitive(455,73,27192);primitive(456,73,27193);
primitive(457,73,27194);primitive(458,73,27195);primitive(459,73,27196);
primitive(460,73,27197);primitive(461,73,27198);primitive(462,73,27199);
primitive(463,73,27200);primitive(464,73,27201);primitive(465,73,27202);
primitive(466,73,27203);primitive(467,73,27204);primitive(468,73,27205);
primitive(469,73,27206);primitive(470,73,27207);primitive(471,73,27208);
primitive(472,73,27209);primitive(473,73,27210);primitive(474,73,27211);
primitive(475,73,27212);primitive(476,73,27213);primitive(477,73,27214);
primitive(478,73,27215);primitive(479,73,27216);primitive(480,73,27217);
primitive(481,73,27218);primitive(482,73,27219);primitive(483,73,27220);
primitive(484,73,27221);primitive(485,73,27222);primitive(486,73,27223);
primitive(487,73,27224);primitive(488,73,27225);primitive(489,73,27226);
primitive(490,73,27227);primitive(491,73,27228);primitive(492,73,27229);
primitive(493,73,27230);primitive(494,73,27231);
if mltexp then begin mltexenabledp:=true;
if false then primitive(495,73,27232);primitive(496,73,27233);
primitive(497,73,27234);end;if enctexp then begin enctexenabledp:=true;
primitive(498,73,27235);primitive(499,73,27236);primitive(500,73,27237);
primitive(501,73,27238);end;primitive(502,73,27239);
primitive(503,73,27240);primitive(504,73,27259);primitive(505,73,27241);
primitive(506,73,27242);primitive(507,73,27243);primitive(508,73,27244);
primitive(509,73,27245);primitive(534,73,27248);primitive(510,73,27246);
primitive(511,73,27247);primitive(512,73,27248);primitive(513,73,27249);
primitive(514,73,27250);primitive(515,73,27251);primitive(516,73,27252);
primitive(517,73,27253);primitive(518,73,27254);primitive(519,73,27255);
primitive(520,73,27256);primitive(521,73,27257);primitive(522,73,27258);
primitive(523,73,27260);primitive(524,73,27261);primitive(525,73,27262);
primitive(526,73,27263);primitive(527,73,27264);primitive(528,73,27265);
primitive(529,73,27266);primitive(530,73,27267);primitive(531,73,27268);
primitive(532,73,27269);{:256}{266:}primitive(537,74,27793);
primitive(538,74,27794);primitive(539,74,27795);primitive(540,74,27796);
primitive(541,74,27797);primitive(542,74,27798);primitive(543,74,27799);
primitive(544,74,27800);primitive(545,74,27801);primitive(546,74,27802);
primitive(547,74,27803);primitive(548,74,27804);primitive(549,74,27805);
primitive(550,74,27806);primitive(551,74,27807);primitive(552,74,27808);
primitive(553,74,27809);primitive(554,74,27810);primitive(555,74,27811);
primitive(556,74,27812);primitive(557,74,27813);primitive(558,74,27814);
primitive(559,74,27815);primitive(560,74,27816);primitive(561,74,27817);
primitive(562,74,27818);primitive(563,74,27819);primitive(564,74,27820);
primitive(565,74,27821);primitive(566,74,27822);primitive(567,74,27823);
primitive(568,74,27824);primitive(569,74,27825);primitive(570,74,27826);
{:266}{287:}primitive(32,64,0);primitive(47,44,0);primitive(582,45,0);
primitive(583,90,0);primitive(584,40,0);primitive(585,41,0);
primitive(586,61,0);primitive(587,16,0);primitive(578,109,0);
primitive(588,15,0);primitive(589,92,0);primitive(579,67,0);
if enctexp then begin primitive(590,67,10);end;primitive(591,62,0);
hash[15516].rh:=591;eqtb[15516]:=eqtb[curval];primitive(592,104,0);
primitive(593,88,0);primitive(594,101,0);primitive(595,102,0);
primitive(596,77,0);primitive(597,32,0);primitive(598,36,0);
primitive(599,39,0);primitive(337,37,0);primitive(359,18,0);
primitive(600,46,0);primitive(601,17,0);primitive(602,54,0);
primitive(603,91,0);primitive(604,34,0);primitive(605,65,0);
primitive(606,105,0);primitive(575,105,1);primitive(342,55,0);
primitive(607,63,0);primitive(608,84,25058);primitive(609,42,0);
primitive(610,80,0);primitive(611,66,0);primitive(612,96,0);
primitive(613,0,256);hash[15521].rh:=613;eqtb[15521]:=eqtb[curval];
primitive(614,98,0);primitive(615,111,0);primitive(427,71,membot);
primitive(360,38,0);primitive(616,33,0);primitive(617,56,0);
primitive(618,35,0);{:287}{356:}primitive(679,13,256);parloc:=curval;
partoken:=4095+parloc;{:356}{405:}primitive(717,106,0);
primitive(718,106,1);{:405}{413:}primitive(719,112,0);
primitive(720,112,1);primitive(721,112,2);primitive(722,112,3);
primitive(723,112,4);{:413}{440:}primitive(535,89,membot+0);
primitive(572,89,membot+1);primitive(412,89,membot+2);
primitive(413,89,membot+3);{:440}{445:}primitive(756,79,104);
primitive(757,79,1);primitive(758,82,0);primitive(759,82,1);
primitive(760,83,1);primitive(761,83,3);primitive(762,83,2);
primitive(763,70,0);primitive(764,70,1);primitive(765,70,2);
primitive(766,70,4);primitive(767,70,5);primitive(768,70,6);
primitive(769,70,7);primitive(770,70,8);primitive(771,70,9);
primitive(772,70,10);primitive(773,70,11);primitive(774,70,12);
primitive(775,70,13);primitive(776,70,14);primitive(777,70,15);
primitive(778,70,16);primitive(779,70,17);primitive(780,70,18);
primitive(781,70,19);{:445}{497:}primitive(840,110,0);
primitive(841,110,1);primitive(842,110,2);primitive(843,110,3);
primitive(844,110,4);primitive(845,110,6);primitive(846,110,7);
primitive(847,110,8);primitive(848,110,9);primitive(849,110,10);
primitive(850,110,11);primitive(851,110,15);primitive(852,110,16);
primitive(853,110,12);primitive(854,110,13);primitive(855,110,14);
primitive(856,110,19);primitive(857,110,20);primitive(858,110,21);
primitive(859,110,22);primitive(860,110,23);primitive(861,110,24);
primitive(862,110,25);primitive(863,110,26);primitive(864,110,27);
primitive(865,110,17);primitive(866,110,18);primitive(867,110,28);
primitive(868,110,29);primitive(869,110,32);primitive(870,110,30);
primitive(871,110,31);{:497}{516:}primitive(910,107,0);
primitive(911,107,1);primitive(912,107,2);primitive(913,107,3);
primitive(914,107,4);primitive(915,107,5);primitive(916,107,6);
primitive(917,107,7);primitive(918,107,8);primitive(919,107,9);
primitive(920,107,10);primitive(921,107,11);primitive(922,107,12);
primitive(923,107,13);primitive(924,107,14);primitive(925,107,15);
primitive(926,107,16);primitive(927,107,21);
{:516}{520:}primitive(929,108,2);hash[15518].rh:=929;
eqtb[15518]:=eqtb[curval];primitive(930,108,4);primitive(931,108,3);
{:520}{582:}primitive(956,87,0);hash[15526].rh:=956;
eqtb[15526]:=eqtb[curval];{:582}{957:}primitive(1297,4,256);
primitive(1298,5,257);hash[15515].rh:=1298;eqtb[15515]:=eqtb[curval];
primitive(1299,5,258);hash[15519].rh:=1300;hash[15520].rh:=1300;
eqtb[15520].hh.b0:=9;eqtb[15520].hh.rh:=memtop-11;eqtb[15520].hh.b1:=1;
eqtb[15519]:=eqtb[15520];eqtb[15519].hh.b0:=117;
{:957}{1161:}primitive(1375,81,0);primitive(1376,81,1);
primitive(1377,81,2);primitive(1378,81,3);primitive(1379,81,4);
primitive(1380,81,5);primitive(1381,81,6);primitive(1382,81,7);
{:1161}{1231:}primitive(349,14,0);primitive(1428,14,1);
{:1231}{1237:}primitive(1429,26,4);primitive(1430,26,0);
primitive(1431,26,1);primitive(1432,26,2);primitive(1433,26,3);
primitive(1434,27,4);primitive(1435,27,0);primitive(1436,27,1);
primitive(1437,27,2);primitive(1438,27,3);primitive(343,28,5);
primitive(322,29,1);primitive(348,30,99);
{:1237}{1250:}primitive(1456,21,1);primitive(1457,21,0);
primitive(1458,22,1);primitive(1459,22,0);primitive(429,20,0);
primitive(1460,20,1);primitive(1461,20,2);primitive(1370,20,3);
primitive(1462,20,4);primitive(1372,20,5);primitive(1463,20,108);
primitive(1464,31,99);primitive(1465,31,100);primitive(1466,31,101);
primitive(1467,31,102);{:1250}{1267:}primitive(1483,43,1);
primitive(1484,43,0);primitive(1485,43,2);
{:1267}{1286:}primitive(1495,25,12);primitive(1496,25,11);
primitive(1497,25,10);primitive(1498,23,0);primitive(1499,23,1);
primitive(1500,24,0);primitive(1501,24,1);
{:1286}{1293:}primitive(45,47,1);primitive(357,47,0);
{:1293}{1320:}primitive(1533,48,0);primitive(1534,48,1);
{:1320}{1335:}primitive(1264,50,16);primitive(1265,50,17);
primitive(1266,50,18);primitive(1267,50,19);primitive(1268,50,20);
primitive(1269,50,21);primitive(1270,50,22);primitive(1271,50,23);
primitive(1273,50,26);primitive(1272,50,27);primitive(1535,51,0);
primitive(1277,51,1);primitive(1278,51,2);
{:1335}{1348:}primitive(1259,53,0);primitive(1260,53,2);
primitive(1261,53,4);primitive(1262,53,6);
{:1348}{1357:}primitive(1553,52,0);primitive(1554,52,1);
primitive(1555,52,2);primitive(1556,52,3);primitive(1557,52,4);
primitive(1558,52,5);{:1357}{1367:}primitive(1274,49,30);
primitive(1275,49,31);hash[15517].rh:=1275;eqtb[15517]:=eqtb[curval];
{:1367}{1387:}primitive(1578,93,1);primitive(1579,93,2);
primitive(1580,93,4);primitive(1581,97,0);primitive(1582,97,1);
primitive(1583,97,2);primitive(1584,97,3);
{:1387}{1398:}primitive(1601,94,0);primitive(1602,94,1);
if enctexp then begin primitive(1603,94,10);primitive(1604,94,11);end;
{:1398}{1401:}primitive(1610,95,0);primitive(1611,95,1);
primitive(1612,95,2);primitive(1613,95,3);primitive(1614,95,4);
primitive(1615,95,5);primitive(1616,95,6);
if mltexp then begin primitive(1617,95,7);end;
{:1401}{1409:}primitive(435,85,25641);
if enctexp then begin primitive(1622,85,25590);primitive(1623,85,25591);
primitive(1624,85,25592);end;primitive(439,85,26665);
primitive(436,85,25897);primitive(437,85,26153);primitive(438,85,26409);
primitive(536,85,27537);primitive(432,86,25593);primitive(433,86,25609);
primitive(434,86,25625);{:1409}{1429:}primitive(1344,99,0);
primitive(1356,99,1);{:1429}{1433:}primitive(1640,78,0);
primitive(1641,78,1);primitive(1642,78,2);primitive(1643,78,3);
primitive(1644,78,4);primitive(1645,78,5);primitive(1646,78,7);
primitive(1647,78,8);primitive(1648,78,9);primitive(1649,78,10);
primitive(1650,78,11);primitive(1651,78,6);
{:1433}{1441:}primitive(274,100,0);primitive(275,100,1);
primitive(276,100,2);primitive(1659,100,3);
{:1441}{1451:}primitive(1660,60,1);primitive(1661,60,0);
{:1451}{1456:}primitive(1662,58,0);primitive(1663,58,1);
{:1456}{1465:}primitive(1669,57,25897);primitive(1670,57,26153);
{:1465}{1470:}primitive(1671,19,0);primitive(1672,19,1);
primitive(1673,19,2);primitive(1674,19,3);
{:1470}{1525:}primitive(1721,59,0);primitive(676,59,1);writeloc:=curval;
primitive(1722,59,2);primitive(1723,59,3);hash[15524].rh:=1723;
eqtb[15524]:=eqtb[curval];primitive(1724,59,4);primitive(1725,59,5);
primitive(1726,59,6);primitive(1126,59,38);primitive(1727,59,39);
primitive(1728,59,40);primitive(1729,59,41);primitive(1730,59,7);
primitive(1731,59,8);primitive(1732,59,9);primitive(1733,59,10);
primitive(1734,59,11);primitive(1735,59,12);primitive(1736,59,13);
primitive(1737,59,14);primitive(1738,59,15);primitive(1739,59,16);
primitive(1740,59,17);primitive(1741,59,18);primitive(1742,59,19);
primitive(1743,59,20);primitive(1744,59,21);primitive(1745,59,34);
primitive(1746,59,35);primitive(1747,59,36);primitive(1748,59,22);
primitive(1749,59,23);primitive(1750,59,24);primitive(1751,59,26);
primitive(1752,59,25);primitive(1753,59,27);primitive(1754,59,28);
primitive(1755,59,29);primitive(1756,59,30);primitive(1757,59,31);
primitive(1758,59,33);primitive(1759,59,32);primitive(1760,59,37);
primitive(1761,59,42);primitive(1762,59,43);primitive(1763,59,44);
primitive(1764,59,45);{:1525}{1901:}primitive(2067,73,27280);{:1901};
nonewcontrolsequence:=true;end;
endif('INITEX'){:1517}{1519:}ifdef('TEXMF_DEBUG')procedure debughelp;
label 888,10;var k,l,m,n:integer;begin while true do begin;
printnl(1720);fflush(stdout);read(stdin,m);
if m<0 then goto 10 else if m=0 then dumpcore else begin read(stdin,n);
case m of{1520:}1:printword(mem[n]);2:printint(mem[n].hh.lh);
3:printint(mem[n].hh.rh);4:printword(eqtb[n]);
5:begin printscaled(fontinfo[n].int);printchar(32);
printint(fontinfo[n].qqqq.b0);printchar(58);
printint(fontinfo[n].qqqq.b1);printchar(58);
printint(fontinfo[n].qqqq.b2);printchar(58);
printint(fontinfo[n].qqqq.b3);end;6:printword(savestack[n]);
7:showbox(n);8:begin breadthmax:=10000;
depththreshold:=poolsize-poolptr-10;shownodelist(n);end;
9:showtokenlist(n,-268435455,1000);10:slowprint(n);11:checkmem(n>0);
12:searchmem(n);13:begin read(stdin,l);printcmdchr(n,l);end;
14:for k:=0 to n do print(buffer[k]);15:begin fontinshortdisplay:=0;
shortdisplay(n);end;16:panicking:=not panicking;
{:1520}others:print(63)end;end;end;10:end;
endif('TEXMF_DEBUG'){:1519}{:1511}{1513:}procedure mainbody;
begin bounddefault:=0;boundname:='mem_bot';
setupboundvariable(addressof(membot),boundname,bounddefault);
bounddefault:=250000;boundname:='main_memory';
setupboundvariable(addressof(mainmemory),boundname,bounddefault);
bounddefault:=0;boundname:='extra_mem_top';
setupboundvariable(addressof(extramemtop),boundname,bounddefault);
bounddefault:=0;boundname:='extra_mem_bot';
setupboundvariable(addressof(extramembot),boundname,bounddefault);
bounddefault:=200000;boundname:='pool_size';
setupboundvariable(addressof(poolsize),boundname,bounddefault);
bounddefault:=75000;boundname:='string_vacancies';
setupboundvariable(addressof(stringvacancies),boundname,bounddefault);
bounddefault:=5000;boundname:='pool_free';
setupboundvariable(addressof(poolfree),boundname,bounddefault);
bounddefault:=15000;boundname:='max_strings';
setupboundvariable(addressof(maxstrings),boundname,bounddefault);
bounddefault:=100;boundname:='strings_free';
setupboundvariable(addressof(stringsfree),boundname,bounddefault);
bounddefault:=100000;boundname:='font_mem_size';
setupboundvariable(addressof(fontmemsize),boundname,bounddefault);
bounddefault:=500;boundname:='font_max';
setupboundvariable(addressof(fontmax),boundname,bounddefault);
bounddefault:=20000;boundname:='trie_size';
setupboundvariable(addressof(triesize),boundname,bounddefault);
bounddefault:=659;boundname:='hyph_size';
setupboundvariable(addressof(hyphsize),boundname,bounddefault);
bounddefault:=3000;boundname:='buf_size';
setupboundvariable(addressof(bufsize),boundname,bounddefault);
bounddefault:=50;boundname:='nest_size';
setupboundvariable(addressof(nestsize),boundname,bounddefault);
bounddefault:=15;boundname:='max_in_open';
setupboundvariable(addressof(maxinopen),boundname,bounddefault);
bounddefault:=60;boundname:='param_size';
setupboundvariable(addressof(paramsize),boundname,bounddefault);
bounddefault:=4000;boundname:='save_size';
setupboundvariable(addressof(savesize),boundname,bounddefault);
bounddefault:=300;boundname:='stack_size';
setupboundvariable(addressof(stacksize),boundname,bounddefault);
bounddefault:=16384;boundname:='dvi_buf_size';
setupboundvariable(addressof(dvibufsize),boundname,bounddefault);
bounddefault:=79;boundname:='error_line';
setupboundvariable(addressof(errorline),boundname,bounddefault);
bounddefault:=50;boundname:='half_error_line';
setupboundvariable(addressof(halferrorline),boundname,bounddefault);
bounddefault:=79;boundname:='max_print_line';
setupboundvariable(addressof(maxprintline),boundname,bounddefault);
bounddefault:=0;boundname:='hash_extra';
setupboundvariable(addressof(hashextra),boundname,bounddefault);
bounddefault:=10000;boundname:='expand_depth';
setupboundvariable(addressof(expanddepth),boundname,bounddefault);
bounddefault:=72;boundname:='pk_dpi';
setupboundvariable(addressof(pkdpi),boundname,bounddefault);
begin if membot<infmembot then membot:=infmembot else if membot>
supmembot then membot:=supmembot end;
begin if mainmemory<infmainmemory then mainmemory:=infmainmemory else if
mainmemory>supmainmemory then mainmemory:=supmainmemory end;
ifdef('INITEX')if iniversion then begin extramemtop:=0;extramembot:=0;
end;endif('INITEX')if extramembot>supmainmemory then extramembot:=
supmainmemory;
if extramemtop>supmainmemory then extramemtop:=supmainmemory;
memtop:=membot+mainmemory-1;memmin:=membot;memmax:=memtop;
begin if triesize<inftriesize then triesize:=inftriesize else if
triesize>suptriesize then triesize:=suptriesize end;
begin if hyphsize<infhyphsize then hyphsize:=infhyphsize else if
hyphsize>suphyphsize then hyphsize:=suphyphsize end;
begin if bufsize<infbufsize then bufsize:=infbufsize else if bufsize>
supbufsize then bufsize:=supbufsize end;
begin if nestsize<infnestsize then nestsize:=infnestsize else if
nestsize>supnestsize then nestsize:=supnestsize end;
begin if maxinopen<infmaxinopen then maxinopen:=infmaxinopen else if
maxinopen>supmaxinopen then maxinopen:=supmaxinopen end;
begin if paramsize<infparamsize then paramsize:=infparamsize else if
paramsize>supparamsize then paramsize:=supparamsize end;
begin if savesize<infsavesize then savesize:=infsavesize else if
savesize>supsavesize then savesize:=supsavesize end;
begin if stacksize<infstacksize then stacksize:=infstacksize else if
stacksize>supstacksize then stacksize:=supstacksize end;
begin if dvibufsize<infdvibufsize then dvibufsize:=infdvibufsize else if
dvibufsize>supdvibufsize then dvibufsize:=supdvibufsize end;
begin if poolsize<infpoolsize then poolsize:=infpoolsize else if
poolsize>suppoolsize then poolsize:=suppoolsize end;
begin if stringvacancies<infstringvacancies then stringvacancies:=
infstringvacancies else if stringvacancies>supstringvacancies then
stringvacancies:=supstringvacancies end;
begin if poolfree<infpoolfree then poolfree:=infpoolfree else if
poolfree>suppoolfree then poolfree:=suppoolfree end;
begin if maxstrings<infmaxstrings then maxstrings:=infmaxstrings else if
maxstrings>supmaxstrings then maxstrings:=supmaxstrings end;
begin if stringsfree<infstringsfree then stringsfree:=infstringsfree
else if stringsfree>supstringsfree then stringsfree:=supstringsfree end;
begin if fontmemsize<inffontmemsize then fontmemsize:=inffontmemsize
else if fontmemsize>supfontmemsize then fontmemsize:=supfontmemsize end;
begin if fontmax<inffontmax then fontmax:=inffontmax else if fontmax>
supfontmax then fontmax:=supfontmax end;
begin if hashextra<infhashextra then hashextra:=infhashextra else if
hashextra>suphashextra then hashextra:=suphashextra end;
begin if objtabsize<infobjtabsize then objtabsize:=infobjtabsize else if
objtabsize>supobjtabsize then objtabsize:=supobjtabsize end;
begin if pdfmemsize<infpdfmemsize then pdfmemsize:=infpdfmemsize else if
pdfmemsize>suppdfmemsize then pdfmemsize:=suppdfmemsize end;
begin if destnamessize<infdestnamessize then destnamessize:=
infdestnamessize else if destnamessize>supdestnamessize then
destnamessize:=supdestnamessize end;
begin if pkdpi<infpkdpi then pkdpi:=infpkdpi else if pkdpi>suppkdpi then
pkdpi:=suppkdpi end;if errorline>255 then errorline:=255;
buffer:=xmallocarray(ASCIIcode,bufsize);
nest:=xmallocarray(liststaterecord,nestsize);
savestack:=xmallocarray(memoryword,savesize);
inputstack:=xmallocarray(instaterecord,stacksize);
inputfile:=xmallocarray(alphafile,maxinopen);
linestack:=xmallocarray(integer,maxinopen);
eofseen:=xmallocarray(boolean,maxinopen);
grpstack:=xmallocarray(savepointer,maxinopen);
ifstack:=xmallocarray(halfword,maxinopen);
sourcefilenamestack:=xmallocarray(strnumber,maxinopen);
fullsourcefilenamestack:=xmallocarray(strnumber,maxinopen);
paramstack:=xmallocarray(halfword,paramsize);
dvibuf:=xmallocarray(eightbits,dvibufsize);
hyphword:=xmallocarray(strnumber,hyphsize);
hyphlist:=xmallocarray(halfword,hyphsize);
hyphlink:=xmallocarray(hyphpointer,hyphsize);
objtab:=xmallocarray(objentry,infobjtabsize);
pdfmem:=xmallocarray(integer,infpdfmemsize);
destnames:=xmallocarray(destnameentry,infdestnamessize);
pdfopbuf:=xmallocarray(eightbits,pdfopbufsize);
pdfosbuf:=xmallocarray(eightbits,infpdfosbufsize);
pdfosobjnum:=xmallocarray(integer,pdfosmaxobjs);
pdfosobjoff:=xmallocarray(integer,pdfosmaxobjs);
ifdef('INITEX')if iniversion then begin yzmem:=xmallocarray(memoryword,
memtop-membot+1);zmem:=yzmem-membot;eqtbtop:=28082+hashextra;
if hashextra=0 then hashtop:=24527 else hashtop:=eqtbtop;
yhash:=xmallocarray(twohalves,1+hashtop-hashoffset);
hash:=yhash-hashoffset;hash[514].lh:=0;hash[514].rh:=0;
for hashused:=515 to hashtop do hash[hashused]:=hash[514];
zeqtb:=xmallocarray(memoryword,eqtbtop);eqtb:=zeqtb;
strstart:=xmallocarray(poolpointer,maxstrings);
strpool:=xmallocarray(packedASCIIcode,poolsize);
fontinfo:=xmallocarray(fmemoryword,fontmemsize);end;
endif('INITEX')history:=3;;if readyalready=314159 then goto 1;
{14:}bad:=0;
if(halferrorline<30)or(halferrorline>errorline-15)then bad:=1;
if maxprintline<60 then bad:=2;if dvibufsize mod 8<>0 then bad:=3;
if membot+1100>memtop then bad:=4;if 8501>15000 then bad:=5;
if maxinopen>=128 then bad:=6;if memtop<267 then bad:=7;
{:14}{129:}ifdef('INITEX')if(memmin<>membot)or(memmax<>memtop)then bad:=
10;endif('INITEX')if(memmin>membot)or(memmax<memtop)then bad:=10;
if(0>0)or(255<127)then bad:=11;
if(-268435455>0)or(268435455<32767)then bad:=12;
if(0<-268435455)or(255>268435455)then bad:=13;
if(membot-supmainmemory<-268435455)or(memtop+supmainmemory>=268435455)
then bad:=14;if(9000<-268435455)or(9000>268435455)then bad:=15;
if fontmax>9000 then bad:=16;
if(savesize>268435455)or(maxstrings>268435455)then bad:=17;
if bufsize>268435455 then bad:=18;if 255<255 then bad:=19;
{:129}{312:}if 32177+hashextra>268435455 then bad:=21;
if(hashoffset<0)or(hashoffset>514)then bad:=42;
{:312}{551:}if formatdefaultlength>maxint then bad:=31;
{:551}{1428:}if 2*268435455<memtop-memmin then bad:=41;
{:1428}if bad>0 then begin writeln(stdout,
'Ouch---my internal constants have been clobbered!','---case ',bad:1);
goto 9999;end;initialize;
ifdef('INITEX')if iniversion then begin if not getstringsstarted then
goto 9999;initprim;initstrptr:=strptr;initpoolptr:=poolptr;
dateandtime(eqtb[27197].int,eqtb[27198].int,eqtb[27199].int,eqtb[27200].
int);end;endif('INITEX')readyalready:=314159;1:{55:}selector:=17;
tally:=0;termoffset:=0;fileoffset:=0;
{:55}{61:}if srcspecialsp or filelineerrorstylep or parsefirstlinep then
write(stdout,'This is pdfTeX, Version 3.14159265','-2.6','-1.40.16')else
write(stdout,'This is pdfTeX, Version 3.14159265','-2.6','-1.40.16');
write(stdout,versionstring);
if formatident=0 then writeln(stdout,' (preloaded format=',dumpname,')')
else begin slowprint(formatident);println;end;
if shellenabledp then begin write(stdout,' ');
if restrictedshell then begin write(stdout,'restricted ');end;
writeln(stdout,'\write18 enabled.');end;
if srcspecialsp then begin writeln(stdout,' Source specials enabled.')
end;if translatefilename then begin write(stdout,' (');
fputs(translatefilename,stdout);writeln(stdout,')');end;fflush(stdout);
{:61}{557:}jobname:=0;nameinprogress:=false;logopened:=false;
{:557}{562:}outputfilename:=0;{:562};
{1518:}begin{353:}begin inputptr:=0;maxinstack:=0;
sourcefilenamestack[0]:=0;fullsourcefilenamestack[0]:=0;inopen:=0;
openparens:=0;maxbufstack:=0;grpstack[0]:=0;ifstack[0]:=-268435455;
paramptr:=0;maxparamstack:=0;first:=bufsize;repeat buffer[first]:=0;
decr(first);until first=0;scannerstatus:=0;warningindex:=-268435455;
first:=1;curinput.statefield:=33;curinput.startfield:=1;
curinput.indexfield:=0;line:=0;curinput.namefield:=0;forceeof:=false;
alignstate:=1000000;if not initterminal then goto 9999;
curinput.limitfield:=last;first:=last+1;end{:353};
{1646:}ifdef('INITEX')if(etexp or(buffer[curinput.locfield]=42))and(
formatident=1687)then begin nonewcontrolsequence:=false;
{1647:}primitive(1957,70,3);primitive(1958,70,20);primitive(872,110,5);
{:1647}{1655:}primitive(1960,72,25072);primitive(1961,73,27270);
primitive(1962,73,27271);primitive(1963,73,27272);
primitive(1964,73,27273);primitive(1965,73,27274);
primitive(1966,73,27275);primitive(1967,73,27276);
primitive(1968,73,27277);primitive(1969,73,27278);
{:1655}{1661:}primitive(1984,70,21);primitive(1985,70,22);
{:1661}{1664:}primitive(1986,70,23);primitive(1987,70,24);
primitive(1988,70,25);{:1664}{1667:}primitive(1989,70,28);
primitive(1990,70,29);primitive(1991,70,30);primitive(1992,70,31);
{:1667}{1670:}primitive(1993,70,32);primitive(1994,70,33);
primitive(1995,70,34);{:1670}{1673:}primitive(1996,19,4);
{:1673}{1682:}primitive(1998,19,5);{:1682}{1684:}primitive(1999,111,1);
primitive(2000,111,5);{:1684}{1687:}primitive(2001,19,6);
{:1687}{1690:}primitive(2005,82,2);{:1690}{1695:}primitive(1276,49,1);
{:1695}{1699:}primitive(2009,73,27279);primitive(2010,33,6);
primitive(2011,33,7);primitive(2012,33,10);primitive(2013,33,11);
{:1699}{1745:}primitive(2022,106,2);{:1745}{1757:}primitive(2024,96,1);
{:1757}{1760:}primitive(928,104,1);primitive(2025,107,17);
primitive(2026,107,18);primitive(2027,107,19);primitive(2028,107,20);
primitive(2029,107,22);primitive(2030,107,23);
{:1760}{1768:}primitive(1592,93,8);{:1768}{1776:}primitive(2036,70,39);
primitive(2037,70,40);primitive(2038,70,41);primitive(2039,70,42);
{:1776}{1799:}primitive(2043,70,26);primitive(2044,70,27);
primitive(2045,70,35);primitive(2046,70,36);
{:1799}{1803:}primitive(2047,70,37);primitive(2048,70,38);
{:1803}{1807:}primitive(2049,18,5);primitive(2050,112,5);
primitive(2051,112,6);primitive(2052,112,7);primitive(2053,112,8);
primitive(2054,112,9);{:1807}{1859:}primitive(2058,24,2);
primitive(2059,24,3);{:1859}{1862:}primitive(2060,84,25329);
primitive(2061,84,25330);primitive(2062,84,25331);
primitive(2063,84,25332);
{:1862}if(buffer[curinput.locfield]=42)then incr(curinput.locfield);
eTeXmode:=1;{1811:}maxregnum:=32767;maxreghelpline:=2055;{:1811}end;
endif('INITEX')if not nonewcontrolsequence then nonewcontrolsequence:=
true else{:1646}if(formatident=0)or(buffer[curinput.locfield]=38)or
dumpline then begin if formatident<>0 then initialize;
if not openfmtfile then goto 9999;
if not loadfmtfile then begin wclose(fmtfile);goto 9999;end;
wclose(fmtfile);eqtb:=zeqtb;
while(curinput.locfield<curinput.limitfield)and(buffer[curinput.locfield
]=32)do incr(curinput.locfield);end;
if(pdfoutputoption<>0)then eqtb[27239].int:=pdfoutputvalue;
if(pdfdraftmodeoption<>0)then eqtb[27264].int:=pdfdraftmodevalue;
pdfinitmapfile('pdftex.map');
if(eTeXmode=1)then writeln(stdout,'entering extended mode');
if(eqtb[27225].int<0)or(eqtb[27225].int>255)then decr(curinput.
limitfield)else buffer[curinput.limitfield]:=eqtb[27225].int;
if mltexenabledp then begin writeln(stdout,'MLTeX v2.2 enabled');end;
if enctexenabledp then begin write(stdout,' encTeX v. Jun. 2004');
writeln(stdout,', reencoding enabled.');
if translatefilename then begin writeln(stdout,
' (\xordcode, \xchrcode, \xprncode overridden by TCX)');end;end;
dateandtime(eqtb[27197].int,eqtb[27198].int,eqtb[27199].int,eqtb[27200].
int);ifdef('INITEX')if trienotready then begin trietrl:=xmallocarray(
triepointer,triesize);trietro:=xmallocarray(triepointer,triesize);
trietrc:=xmallocarray(quarterword,triesize);
triec:=xmallocarray(packedASCIIcode,triesize);
trieo:=xmallocarray(trieopcode,triesize);
triel:=xmallocarray(triepointer,triesize);
trier:=xmallocarray(triepointer,triesize);
triehash:=xmallocarray(triepointer,triesize);
trietaken:=xmallocarray(boolean,triesize);triel[0]:=0;triec[0]:=0;
trieptr:=0;trier[0]:=0;hyphstart:=0;
fontcheck:=xmallocarray(fourquarters,fontmax);
fontsize:=xmallocarray(scaled,fontmax);
fontdsize:=xmallocarray(scaled,fontmax);
fontparams:=xmallocarray(fontindex,fontmax);
fontname:=xmallocarray(strnumber,fontmax);
fontarea:=xmallocarray(strnumber,fontmax);
fontbc:=xmallocarray(eightbits,fontmax);
fontec:=xmallocarray(eightbits,fontmax);
fontglue:=xmallocarray(halfword,fontmax);
hyphenchar:=xmallocarray(integer,fontmax);
skewchar:=xmallocarray(integer,fontmax);
bcharlabel:=xmallocarray(fontindex,fontmax);
fontbchar:=xmallocarray(ninebits,fontmax);
fontfalsebchar:=xmallocarray(ninebits,fontmax);
charbase:=xmallocarray(integer,fontmax);
widthbase:=xmallocarray(integer,fontmax);
heightbase:=xmallocarray(integer,fontmax);
depthbase:=xmallocarray(integer,fontmax);
italicbase:=xmallocarray(integer,fontmax);
ligkernbase:=xmallocarray(integer,fontmax);
kernbase:=xmallocarray(integer,fontmax);
extenbase:=xmallocarray(integer,fontmax);
parambase:=xmallocarray(integer,fontmax);
pdfcharused:=xmallocarray(charusedarray,fontmax);
pdffontsize:=xmallocarray(scaled,fontmax);
pdffontnum:=xmallocarray(integer,fontmax);
pdffontmap:=xmallocarray(fmentryptr,fontmax);
pdffonttype:=xmallocarray(eightbits,fontmax);
pdffontattr:=xmallocarray(strnumber,fontmax);
pdffontblink:=xmallocarray(internalfontnumber,fontmax);
pdffontelink:=xmallocarray(internalfontnumber,fontmax);
pdffontstretch:=xmallocarray(integer,fontmax);
pdffontshrink:=xmallocarray(integer,fontmax);
pdffontstep:=xmallocarray(integer,fontmax);
pdffontexpandratio:=xmallocarray(integer,fontmax);
pdffontautoexpand:=xmallocarray(boolean,fontmax);
pdffontlpbase:=xmallocarray(integer,fontmax);
pdffontrpbase:=xmallocarray(integer,fontmax);
pdffontefbase:=xmallocarray(integer,fontmax);
pdffontknbsbase:=xmallocarray(integer,fontmax);
pdffontstbsbase:=xmallocarray(integer,fontmax);
pdffontshbsbase:=xmallocarray(integer,fontmax);
pdffontknbcbase:=xmallocarray(integer,fontmax);
pdffontknacbase:=xmallocarray(integer,fontmax);
vfpacketbase:=xmallocarray(integer,fontmax);
vfdefaultfont:=xmallocarray(internalfontnumber,fontmax);
vflocalfontnum:=xmallocarray(internalfontnumber,fontmax);
vfefnts:=xmallocarray(integer,fontmax);
vfifnts:=xmallocarray(internalfontnumber,fontmax);
pdffontnobuiltintounicode:=xmallocarray(boolean,fontmax);
for fontk:=0 to fontmax do begin for k:=0 to 31 do pdfcharused[fontk,k]
:=0;pdffontsize[fontk]:=0;pdffontnum[fontk]:=0;pdffontmap[fontk]:=0;
pdffonttype[fontk]:=0;pdffontattr[fontk]:=345;pdffontblink[fontk]:=0;
pdffontelink[fontk]:=0;pdffontstretch[fontk]:=0;pdffontshrink[fontk]:=0;
pdffontstep[fontk]:=0;pdffontexpandratio[fontk]:=0;
pdffontautoexpand[fontk]:=false;pdffontlpbase[fontk]:=0;
pdffontrpbase[fontk]:=0;pdffontefbase[fontk]:=0;
pdffontknbsbase[fontk]:=0;pdffontstbsbase[fontk]:=0;
pdffontshbsbase[fontk]:=0;pdffontknbcbase[fontk]:=0;
pdffontknacbase[fontk]:=0;pdffontnobuiltintounicode[fontk]:=false;end;
fontptr:=0;fmemptr:=7;makepdftexbanner;fontname[0]:=956;
fontarea[0]:=345;hyphenchar[0]:=45;skewchar[0]:=-1;bcharlabel[0]:=0;
fontbchar[0]:=256;fontfalsebchar[0]:=256;fontbc[0]:=1;fontec[0]:=0;
fontsize[0]:=0;fontdsize[0]:=0;charbase[0]:=0;widthbase[0]:=0;
heightbase[0]:=0;depthbase[0]:=0;italicbase[0]:=0;ligkernbase[0]:=0;
kernbase[0]:=0;extenbase[0]:=0;fontglue[0]:=-268435455;fontparams[0]:=7;
parambase[0]:=-1;for fontk:=0 to 6 do fontinfo[fontk].int:=0;end;
endif('INITEX')fontused:=xmallocarray(boolean,fontmax);
for fontk:=0 to fontmax do fontused[fontk]:=false;
randomseed:=(microseconds*1000)+(epochseconds mod 1000000);
initrandoms(randomseed);{942:}magicoffset:=strstart[1291]-9*16{:942};
{75:}if interaction=0 then selector:=16 else selector:=17{:75};
if(curinput.locfield<curinput.limitfield)and(eqtb[25641+buffer[curinput.
locfield]].hh.rh<>0)then startinput;end{:1518};history:=0;
{1906:}synctexinitcommand;{:1906}maincontrol;finalcleanup;
closefilesandterminate;9999:begin fflush(stdout);readyalready:=0;
if(history<>0)and(history<>1)then uexit(1)else uexit(0);end;end;
{:1513}{1934:}function getnullstr:strnumber;begin getnullstr:=345;end;
{:1934}
