{4:}{9:}{$C-,A+,D-}ifdef('TEXMF_DEBUG'){$C+,D+}
endif('TEXMF_DEBUG'){:9}program TEX;const{11:}hashoffset=514;
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
supexpanddepth=10000000;{:11}type{18:}ASCIIcode=0..255;
{:18}{25:}eightbits=0..255;alphafile=packed file of ASCIIcode;
bytefile=packed file of eightbits;{:25}{38:}poolpointer=integer;
strnumber=0..2097151;packedASCIIcode=0..255;{:38}{101:}scaled=integer;
nonnegativeinteger=0..2147483647;smallnumber=0..63;
{:101}{109:}{:109}{113:}quarterword=0..255;
halfword=-268435455..268435455;twochoices=1..2;fourchoices=1..4;
#include "texmfmem.h";wordfile=file of memoryword;
{:113}{150:}glueord=0..3;
{:150}{212:}liststaterecord=record modefield:-203..203;
headfield,tailfield:halfword;pgfield,mlfield:integer;
auxfield:memoryword;end;{:212}{269:}groupcode=0..16;
{:269}{300:}instaterecord=record statefield,indexfield:quarterword;
startfield,locfield,limitfield,namefield:halfword;end;
{:300}{551:}internalfontnumber=integer;fontindex=integer;
ninebits=0..256;{:551}{597:}dviindex=0..dvibufsize;
{:597}{923:}triepointer=0..4194303;trieopcode=0..65535;
{:923}{928:}hyphpointer=0..65535;{:928}var{13:}bad:integer;
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
{:104}{115:}tempptr:halfword;{:115}{116:}yzmem:^memoryword;
zmem:^memoryword;lomemmax:halfword;himemmin:halfword;
{:116}{117:}varused,dynused:integer;{:117}{118:}avail:halfword;
memend:halfword;{:118}{124:}rover:halfword;
{:124}{165:}ifdef('TEXMF_DEBUG')freearr:packed array[0..9]of boolean;
wasfree:packed array[0..9]of boolean;
wasmemend,waslomax,washimin:halfword;panicking:boolean;
endif('TEXMF_DEBUG'){:165}{173:}fontinshortdisplay:integer;
{:173}{181:}depththreshold:integer;breadthmax:integer;
{:181}{213:}nest:^liststaterecord;nestptr:0..nestsize;
maxneststack:0..nestsize;curlist:liststaterecord;shownmode:-203..203;
{:213}{246:}oldsetting:0..21;{:246}{253:}zeqtb:^memoryword;
xeqlevel:array[27167..28017]of quarterword;{:253}{256:}hash:^twohalves;
yhash:^twohalves;hashused:halfword;hashextra:halfword;hashtop:halfword;
eqtbtop:halfword;hashhigh:halfword;nonewcontrolsequence:boolean;
cscount:integer;{:256}{271:}savestack:^memoryword;saveptr:0..savesize;
maxsavestack:0..savesize;curlevel:quarterword;curgroup:groupcode;
curboundary:0..savesize;{:271}{286:}magset:integer;
{:286}{297:}curcmd:eightbits;curchr:halfword;curcs:halfword;
curtok:halfword;{:297}{301:}inputstack:^instaterecord;
inputptr:0..stacksize;maxinstack:0..stacksize;curinput:instaterecord;
{:301}{304:}inopen:0..maxinopen;openparens:0..maxinopen;
inputfile:^alphafile;line:integer;linestack:^integer;
sourcefilenamestack:^strnumber;fullsourcefilenamestack:^strnumber;
{:304}{305:}scannerstatus:0..5;warningindex:halfword;defref:halfword;
{:305}{308:}paramstack:^halfword;paramptr:0..paramsize;
maxparamstack:integer;{:308}{309:}alignstate:integer;
{:309}{310:}baseptr:0..stacksize;{:310}{333:}parloc:halfword;
partoken:halfword;{:333}{361:}forceeof:boolean;
{:361}{367:}expanddepthcount:integer;
{:367}{385:}curmark:array[0..4]of halfword;
{:385}{390:}longstate:111..114;
{:390}{391:}pstack:array[0..8]of halfword;{:391}{413:}curval:integer;
curvallevel:0..5;{:413}{441:}radix:smallnumber;
{:441}{450:}curorder:glueord;
{:450}{483:}readfile:array[0..15]of alphafile;
readopen:array[0..16]of 0..2;{:483}{492:}condptr:halfword;iflimit:0..4;
curif:smallnumber;ifline:integer;{:492}{496:}skipline:integer;
{:496}{515:}curname:strnumber;curarea:strnumber;curext:strnumber;
{:515}{516:}areadelimiter:poolpointer;extdelimiter:poolpointer;
{:516}{523:}formatdefaultlength:integer;TEXformatdefault:cstring;
{:523}{530:}nameinprogress:boolean;jobname:strnumber;logopened:boolean;
{:530}{535:}dvifile:bytefile;outputfilename:strnumber;
texmflogname:strnumber;{:535}{542:}tfmfile:bytefile;
{:542}{552:}fontinfo:^fmemoryword;fmemptr:fontindex;
fontptr:internalfontnumber;fontcheck:^fourquarters;fontsize:^scaled;
fontdsize:^scaled;fontparams:^fontindex;fontname:^strnumber;
fontarea:^strnumber;fontbc:^eightbits;fontec:^eightbits;
fontglue:^halfword;fontused:^boolean;hyphenchar:^integer;
skewchar:^integer;bcharlabel:^fontindex;fontbchar:^ninebits;
fontfalsebchar:^ninebits;{:552}{553:}charbase:^integer;
widthbase:^integer;heightbase:^integer;depthbase:^integer;
italicbase:^integer;ligkernbase:^integer;kernbase:^integer;
extenbase:^integer;parambase:^integer;
{:553}{558:}nullcharacter:fourquarters;{:558}{595:}totalpages:integer;
maxv:scaled;maxh:scaled;maxpush:integer;lastbop:integer;
deadcycles:integer;doingleaders:boolean;c:quarterword;
f:internalfontnumber;ruleht,ruledp,rulewd:scaled;g:halfword;
lq,lr:integer;{:595}{598:}dvibuf:^eightbits;halfbuf:integer;
dvilimit:integer;dviptr:integer;dvioffset:integer;dvigone:integer;
{:598}{608:}downptr,rightptr:halfword;{:608}{619:}dvih,dviv:scaled;
curh,curv:scaled;dvif:internalfontnumber;curs:integer;
{:619}{649:}totalstretch,totalshrink:array[glueord]of scaled;
lastbadness:integer;{:649}{650:}adjusttail:halfword;
{:650}{664:}packbeginline:integer;{:664}{687:}emptyfield:twohalves;
nulldelimiter:fourquarters;{:687}{722:}curmlist:halfword;
curstyle:smallnumber;cursize:smallnumber;curmu:scaled;
mlistpenalties:boolean;{:722}{727:}curf:internalfontnumber;
curc:quarterword;curi:fourquarters;{:727}{767:}magicoffset:integer;
{:767}{773:}curalign:halfword;curspan:halfword;curloop:halfword;
alignptr:halfword;curhead,curtail:halfword;{:773}{817:}justbox:halfword;
{:817}{824:}passive:halfword;printednode:halfword;passnumber:halfword;
{:824}{826:}activewidth:array[1..6]of scaled;
curactivewidth:array[1..6]of scaled;background:array[1..6]of scaled;
breakwidth:array[1..6]of scaled;{:826}{828:}noshrinkerroryet:boolean;
{:828}{831:}curp:halfword;secondpass:boolean;finalpass:boolean;
threshold:integer;{:831}{836:}minimaldemerits:array[0..3]of integer;
minimumdemerits:integer;bestplace:array[0..3]of halfword;
bestplline:array[0..3]of halfword;{:836}{842:}discwidth:scaled;
{:842}{850:}easyline:halfword;lastspecialline:halfword;
firstwidth:scaled;secondwidth:scaled;firstindent:scaled;
secondindent:scaled;{:850}{875:}bestbet:halfword;fewestdemerits:integer;
bestline:halfword;actuallooseness:integer;linediff:integer;
{:875}{895:}hc:array[0..65]of 0..256;hn:smallnumber;ha,hb:halfword;
hf:internalfontnumber;hu:array[0..63]of 0..256;hyfchar:integer;
curlang,initcurlang:ASCIIcode;lhyf,rhyf,initlhyf,initrhyf:integer;
hyfbchar:halfword;{:895}{903:}hyf:array[0..64]of 0..9;initlist:halfword;
initlig:boolean;initlft:boolean;{:903}{908:}hyphenpassed:smallnumber;
{:908}{910:}curl,curr:halfword;curq:halfword;ligstack:halfword;
ligaturepresent:boolean;lfthit,rthit:boolean;
{:910}{924:}trietrl:^triepointer;trietro:^triepointer;
trietrc:^quarterword;hyfdistance:array[1..trieopsize]of smallnumber;
hyfnum:array[1..trieopsize]of smallnumber;
hyfnext:array[1..trieopsize]of trieopcode;
opstart:array[ASCIIcode]of 0..trieopsize;
{:924}{929:}hyphword:^strnumber;hyphlist:^halfword;
hyphlink:^hyphpointer;hyphcount:integer;hyphnext:integer;
{:929}{946:}ifdef('INITEX')trieophash:array[negtrieopsize..trieopsize]of
0..trieopsize;trieused:array[ASCIIcode]of trieopcode;
trieoplang:array[1..trieopsize]of ASCIIcode;
trieopval:array[1..trieopsize]of trieopcode;trieopptr:0..trieopsize;
endif('INITEX')maxopused:trieopcode;smallop:boolean;
{:946}{950:}ifdef('INITEX')triec:^packedASCIIcode;trieo:^trieopcode;
triel:^triepointer;trier:^triepointer;trieptr:triepointer;
triehash:^triepointer;
endif('INITEX'){:950}{953:}ifdef('INITEX')trietaken:^boolean;
triemin:array[ASCIIcode]of triepointer;triemax:triepointer;
trienotready:boolean;
endif('INITEX'){:953}{974:}bestheightplusdepth:scaled;
{:974}{983:}pagetail:halfword;pagecontents:0..2;pagemaxdepth:scaled;
bestpagebreak:halfword;leastpagecost:integer;bestsize:scaled;
{:983}{985:}pagesofar:array[0..7]of scaled;lastglue:halfword;
lastpenalty:integer;lastkern:scaled;insertpenalties:integer;
{:985}{992:}outputactive:boolean;{:992}{1035:}mainf:internalfontnumber;
maini:fourquarters;mainj:fourquarters;maink:fontindex;mainp:halfword;
mains:integer;bchar:halfword;falsebchar:halfword;cancelboundary:boolean;
insdisc:boolean;{:1035}{1077:}curbox:halfword;
{:1077}{1269:}aftertoken:halfword;{:1269}{1284:}longhelpseen:boolean;
{:1284}{1302:}formatident:strnumber;{:1302}{1308:}fmtfile:wordfile;
{:1308}{1334:}readyalready:integer;
{:1334}{1345:}writefile:array[0..15]of alphafile;
writeopen:array[0..17]of boolean;{:1345}{1348:}writeloc:halfword;
{:1348}{1382:}editnamestart:poolpointer;editnamelength,editline:integer;
ipcon:cinttype;stopatspace:boolean;{:1382}{1384:}savestrptr:strnumber;
savepoolptr:poolpointer;shellenabledp:cinttype;restrictedshell:cinttype;
outputcomment:^char;k,l:0..255;{:1384}{1386:}debugformatfile:boolean;
{:1386}{1393:}mltexp:boolean;{:1393}{1394:}mltexenabledp:boolean;
{:1394}{1399:}accentc,basec,replacec:integer;iac,ibc:fourquarters;
baseslant,accentslant:real;basexheight:scaled;
basewidth,baseheight:scaled;accentwidth,accentheight:scaled;
delta:scaled;{:1399}{1406:}enctexp:boolean;
{:1406}{1407:}enctexenabledp:boolean;{:1407}procedure initialize;
var{19:}i:integer;{:19}{163:}k:integer;{:163}{930:}z:hyphpointer;
{:930}begin{8:}{21:}xchr[32]:=' ';xchr[33]:='!';xchr[34]:='"';
xchr[35]:='#';xchr[36]:='$';xchr[37]:='%';xchr[38]:='&';xchr[39]:='''';
xchr[40]:='(';xchr[41]:=')';xchr[42]:='*';xchr[43]:='+';xchr[44]:=',';
xchr[45]:='-';xchr[46]:='.';xchr[47]:='/';xchr[48]:='0';xchr[49]:='1';
xchr[50]:='2';xchr[51]:='3';xchr[52]:='4';xchr[53]:='5';xchr[54]:='6';
xchr[55]:='7';xchr[56]:='8';xchr[57]:='9';xchr[58]:=':';xchr[59]:=';';
xchr[60]:='<';xchr[61]:='=';xchr[62]:='>';xchr[63]:='?';xchr[64]:='@';
xchr[65]:='A';xchr[66]:='B';xchr[67]:='C';xchr[68]:='D';xchr[69]:='E';
xchr[70]:='F';xchr[71]:='G';xchr[72]:='H';xchr[73]:='I';xchr[74]:='J';
xchr[75]:='K';xchr[76]:='L';xchr[77]:='M';xchr[78]:='N';xchr[79]:='O';
xchr[80]:='P';xchr[81]:='Q';xchr[82]:='R';xchr[83]:='S';xchr[84]:='T';
xchr[85]:='U';xchr[86]:='V';xchr[87]:='W';xchr[88]:='X';xchr[89]:='Y';
xchr[90]:='Z';xchr[91]:='[';xchr[92]:='\';xchr[93]:=']';xchr[94]:='^';
xchr[95]:='_';xchr[96]:='`';xchr[97]:='a';xchr[98]:='b';xchr[99]:='c';
xchr[100]:='d';xchr[101]:='e';xchr[102]:='f';xchr[103]:='g';
xchr[104]:='h';xchr[105]:='i';xchr[106]:='j';xchr[107]:='k';
xchr[108]:='l';xchr[109]:='m';xchr[110]:='n';xchr[111]:='o';
xchr[112]:='p';xchr[113]:='q';xchr[114]:='r';xchr[115]:='s';
xchr[116]:='t';xchr[117]:='u';xchr[118]:='v';xchr[119]:='w';
xchr[120]:='x';xchr[121]:='y';xchr[122]:='z';xchr[123]:='{';
xchr[124]:='|';xchr[125]:='}';xchr[126]:='~';
{:21}{23:}for i:=0 to 31 do xchr[i]:=i;for i:=127 to 255 do xchr[i]:=i;
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
{:80}{97:}interrupt:=0;OKtointerrupt:=true;
{:97}{166:}ifdef('TEXMF_DEBUG')wasmemend:=memmin;waslomax:=memmin;
washimin:=memmax;panicking:=false;
endif('TEXMF_DEBUG'){:166}{215:}nestptr:=0;maxneststack:=0;
curlist.modefield:=1;curlist.headfield:=memtop-1;
curlist.tailfield:=memtop-1;curlist.auxfield.int:=-65536000;
curlist.mlfield:=0;curlist.pgfield:=0;shownmode:=0;pagecontents:=0;
pagetail:=memtop-2;lastglue:=268435455;lastpenalty:=0;lastkern:=0;
pagesofar[7]:=0;pagemaxdepth:=0;
{:215}{254:}for k:=27167 to 28017 do xeqlevel[k]:=1;
{:254}{257:}nonewcontrolsequence:=true;{:257}{272:}saveptr:=0;
curlevel:=1;curgroup:=0;curboundary:=0;maxsavestack:=0;
{:272}{287:}magset:=0;{:287}{368:}expanddepthcount:=0;
{:368}{386:}curmark[0]:=-268435455;curmark[1]:=-268435455;
curmark[2]:=-268435455;curmark[3]:=-268435455;curmark[4]:=-268435455;
{:386}{442:}curval:=0;curvallevel:=0;radix:=0;curorder:=0;
{:442}{484:}for k:=0 to 16 do readopen[k]:=2;
{:484}{493:}condptr:=-268435455;iflimit:=0;curif:=0;ifline:=0;
{:493}{554:}{:554}{559:}nullcharacter.b0:=0;nullcharacter.b1:=0;
nullcharacter.b2:=0;nullcharacter.b3:=0;{:559}{596:}totalpages:=0;
maxv:=0;maxh:=0;maxpush:=0;lastbop:=-1;doingleaders:=false;
deadcycles:=0;curs:=-1;{:596}{599:}halfbuf:=dvibufsize div 2;
dvilimit:=dvibufsize;dviptr:=0;dvioffset:=0;dvigone:=0;
{:599}{609:}downptr:=-268435455;rightptr:=-268435455;
{:609}{651:}adjusttail:=-268435455;lastbadness:=0;
{:651}{665:}packbeginline:=0;{:665}{688:}emptyfield.rh:=0;
emptyfield.lh:=-268435455;nulldelimiter.b0:=0;nulldelimiter.b1:=0;
nulldelimiter.b2:=0;nulldelimiter.b3:=0;
{:688}{774:}alignptr:=-268435455;curalign:=-268435455;
curspan:=-268435455;curloop:=-268435455;curhead:=-268435455;
curtail:=-268435455;
{:774}{931:}for z:=0 to hyphsize do begin hyphword[z]:=0;
hyphlist[z]:=-268435455;hyphlink[z]:=0;end;hyphcount:=0;hyphnext:=608;
if hyphnext>hyphsize then hyphnext:=607;{:931}{993:}outputactive:=false;
insertpenalties:=0;{:993}{1036:}ligaturepresent:=false;
cancelboundary:=false;lfthit:=false;rthit:=false;insdisc:=false;
{:1036}{1270:}aftertoken:=0;{:1270}{1285:}longhelpseen:=false;
{:1285}{1303:}formatident:=0;
{:1303}{1346:}for k:=0 to 17 do writeopen[k]:=false;
{:1346}{1383:}editnamestart:=0;stopatspace:=true;
{:1383}{1395:}mltexenabledp:=false;{:1395}{1408:}enctexenabledp:=false;
{:1408}ifdef('INITEX')if iniversion then begin{164:}for k:=membot+1 to
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
for k:=memtop-13 to memtop do mem[k]:=mem[lomemmax];
{793:}mem[memtop-10].hh.lh:=19614;{:793}{800:}mem[memtop-9].hh.rh:=256;
mem[memtop-9].hh.lh:=-268435455;{:800}{823:}mem[memtop-7].hh.b0:=1;
mem[memtop-6].hh.lh:=268435455;mem[memtop-7].hh.b1:=0;
{:823}{984:}mem[memtop].hh.b1:=255;mem[memtop].hh.b0:=1;
mem[memtop].hh.rh:=memtop;{:984}{991:}mem[memtop-2].hh.b0:=10;
mem[memtop-2].hh.b1:=0;{:991};avail:=-268435455;memend:=memtop;
himemmin:=memtop-13;varused:=membot+20-membot;dynused:=14;
{:164}{222:}eqtb[24526].hh.b0:=101;eqtb[24526].hh.rh:=-268435455;
eqtb[24526].hh.b1:=0;for k:=1 to eqtbtop do eqtb[k]:=eqtb[24526];
{:222}{228:}eqtb[24527].hh.rh:=membot;eqtb[24527].hh.b1:=1;
eqtb[24527].hh.b0:=117;for k:=24528 to 25056 do eqtb[k]:=eqtb[24527];
mem[membot].hh.rh:=mem[membot].hh.rh+530;
{:228}{232:}eqtb[25057].hh.rh:=-268435455;eqtb[25057].hh.b0:=118;
eqtb[25057].hh.b1:=1;for k:=25058 to 25322 do eqtb[k]:=eqtb[24526];
eqtb[25323].hh.rh:=-268435455;eqtb[25323].hh.b0:=119;
eqtb[25323].hh.b1:=1;for k:=25324 to 25578 do eqtb[k]:=eqtb[25323];
eqtb[25579].hh.rh:=0;eqtb[25579].hh.b0:=120;eqtb[25579].hh.b1:=1;
for k:=25583 to 25630 do eqtb[k]:=eqtb[25579];eqtb[25631].hh.rh:=0;
eqtb[25631].hh.b0:=120;eqtb[25631].hh.b1:=1;
for k:=25632 to 27166 do eqtb[k]:=eqtb[25631];
for k:=0 to 255 do begin eqtb[25631+k].hh.rh:=12;eqtb[26655+k].hh.rh:=k;
eqtb[26399+k].hh.rh:=1000;end;eqtb[25644].hh.rh:=5;
eqtb[25663].hh.rh:=10;eqtb[25723].hh.rh:=0;eqtb[25668].hh.rh:=14;
eqtb[25758].hh.rh:=15;eqtb[25631].hh.rh:=9;
for k:=48 to 57 do eqtb[26655+k].hh.rh:=k+28672;
for k:=65 to 90 do begin eqtb[25631+k].hh.rh:=11;
eqtb[25631+k+32].hh.rh:=11;eqtb[26655+k].hh.rh:=k+28928;
eqtb[26655+k+32].hh.rh:=k+28960;eqtb[25887+k].hh.rh:=k+32;
eqtb[25887+k+32].hh.rh:=k+32;eqtb[26143+k].hh.rh:=k;
eqtb[26143+k+32].hh.rh:=k;eqtb[26399+k].hh.rh:=999;end;
{:232}{240:}for k:=27167 to 27484 do eqtb[k].int:=0;
eqtb[27222].int:=256;eqtb[27223].int:=-1;eqtb[27184].int:=1000;
eqtb[27168].int:=10000;eqtb[27208].int:=1;eqtb[27207].int:=25;
eqtb[27212].int:=92;eqtb[27215].int:=13;
for k:=0 to 255 do eqtb[27485+k].int:=-1;eqtb[27531].int:=0;
{:240}{250:}for k:=27741 to 28017 do eqtb[k].int:=0;
{:250}{258:}hashused:=15514;hashhigh:=0;cscount:=0;
eqtb[15523].hh.b0:=116;hash[15523].rh:=514;
{:258}{555:}{:555}{949:}for k:=-trieopsize to trieopsize do trieophash[k
]:=0;for k:=0 to 255 do trieused[k]:=mintrieop;maxopused:=mintrieop;
trieopptr:=0;{:949}{954:}trienotready:=true;
{:954}{1219:}hash[15514].rh:=1206;
{:1219}{1304:}if iniversion then formatident:=1286;
{:1304}{1372:}hash[15522].rh:=1328;eqtb[15522].hh.b1:=1;
eqtb[15522].hh.b0:=113;eqtb[15522].hh.rh:=-268435455;{:1372}end;
endif('INITEX'){:8}end;{57:}procedure println;
begin case selector of 19:begin writeln(stdout);writeln(logfile);
termoffset:=0;fileoffset:=0;end;18:begin writeln(logfile);fileoffset:=0;
end;17:begin writeln(stdout);termoffset:=0;end;16,20,21:;
others:writeln(writefile[selector])end;end;
{:57}{58:}procedure printchar(s:ASCIIcode);label 10;
begin if{244:}s=eqtb[27216].int{:244}then if selector<20 then begin
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
begin if s>=strptr then s:=259 else if s<256 then if s<0 then s:=259
else begin if(selector>20)and(not specialprinting)and(not
messageprinting)then begin printchar(s);goto 10;end;
if({244:}s=eqtb[27216].int{:244})then if selector<20 then begin println;
noconvert:=false;goto 10;
end else if messageprinting then begin printchar(s);noconvert:=false;
goto 10;end;
if(eqtb[27227].int>0)and(not noconvert)and(mubytewrite[s]>0)then s:=
mubytewrite[s]else if xprn[s]or specialprinting then begin printchar(s);
noconvert:=false;goto 10;end;noconvert:=false;nl:=eqtb[27216].int;
eqtb[27216].int:=-1;j:=strstart[s];
while j<strstart[s+1]do begin printchar(strpool[j]);incr(j);end;
eqtb[27216].int:=nl;goto 10;end;j:=strstart[s];
while j<strstart[s+1]do begin printchar(strpool[j]);incr(j);end;10:end;
{:59}{60:}procedure slowprint(s:integer);var j:poolpointer;
begin if(s>=strptr)or(s<256)then print(s)else begin j:=strstart[s];
while j<strstart[s+1]do begin print(strpool[j]);incr(j);end;end;end;
{:60}{62:}procedure printnl(s:strnumber);
begin if((termoffset>0)and(odd(selector)))or((fileoffset>0)and(selector
>=18))then println;print(s);end;
{:62}{63:}procedure printesc(s:strnumber);var c:integer;
begin{243:}c:=eqtb[27212].int{:243};if c>=0 then if c<256 then print(c);
slowprint(s);end;{:63}{64:}procedure printthedigs(k:eightbits);
begin while k>0 do begin decr(k);
if dig[k]<10 then printchar(48+dig[k])else printchar(55+dig[k]);end;end;
{:64}{65:}procedure printint(n:integer);var k:0..23;m:integer;
begin k:=0;if n<0 then begin printchar(45);
if n>-100000000 then n:=-n else begin m:=-1-n;n:=m div 10;
m:=(m mod 10)+1;k:=1;if m<10 then dig[0]:=m else begin dig[0]:=0;
incr(n);end;end;end;repeat dig[k]:=n mod 10;n:=n div 10;incr(k);
until n=0;printthedigs(k);end;{:65}{262:}procedure printcs(p:integer);
var q:halfword;s:strnumber;
begin if activenoconvert and(not noconvert)and(eqtb[p].hh.b0=94)and(eqtb
[p].hh.rh=11)then begin noconvert:=true;goto 10;end;s:=0;
if csconverting and(not noconvert)then begin q:=mubytecswrite[p mod 128]
;
while q<>-268435455 do if mem[q].hh.lh=p then begin s:=mem[mem[q].hh.rh]
.hh.lh;q:=-268435455;end else q:=mem[mem[q].hh.rh].hh.rh;end;
noconvert:=false;
if s>0 then print(s)else if p<514 then if p>=257 then if p=513 then
begin printesc(516);printesc(517);printchar(32);
end else begin printesc(p-257);
if eqtb[25631+p-257].hh.rh=11 then printchar(32);
end else if p<1 then printesc(518)else print(p-1)else if((p>=24526)and(p
<=28017))or(p>eqtbtop)then printesc(518)else if(hash[p].rh>=strptr)then
printesc(519)else begin printesc(hash[p].rh);printchar(32);end;10:end;
{:262}{263:}procedure sprintcs(p:halfword);
begin if p<514 then if p<257 then print(p-1)else if p<513 then printesc(
p-257)else begin printesc(516);printesc(517);
end else printesc(hash[p].rh);end;
{:263}{521:}procedure printfilename(n,a,e:integer);
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
{:521}{702:}procedure printsize(s:integer);
begin if s=0 then printesc(417)else if s=16 then printesc(418)else
printesc(419);end;{:702}{1358:}procedure printwritewhatsit(s:strnumber;
p:halfword);begin printesc(s);
if mem[p+1].hh.b0<16 then printint(mem[p+1].hh.b0)else if mem[p+1].hh.b0
=16 then printchar(42)else printchar(45);
if(s=606)and(mem[p+1].hh.b1<>64)then begin printchar(60);
printint(mem[p+1].hh.b1-64);printchar(62);end;end;
{:1358}{1385:}procedure printcsnames(hstart:integer;hfinish:integer);
var c,h:integer;
begin writeln(stderr,'fmtdebug:csnames from ',hstart,' to ',hfinish,':')
;for h:=hstart to hfinish do begin if hash[h].rh>0 then begin for c:=
strstart[hash[h].rh]to strstart[hash[h].rh+1]-1 do begin putbyte(strpool
[c],stderr);end;writeln(stderr,'|');end;end;end;
{:1385}{1387:}procedure printfileline;var level:0..maxinopen;
begin level:=inopen;
while(level>0)and(fullsourcefilenamestack[level]=0)do decr(level);
if level=0 then printnl(262)else begin printnl(335);
print(fullsourcefilenamestack[level]);print(58);
if level=inopen then printint(line)else printint(linestack[level+1]);
print(581);end;end;
{:1387}{1409:}function readbuffer(var i:integer):ASCIIcode;
var p:halfword;lastfound:integer;lasttype:integer;begin mubyteskip:=0;
mubytetoken:=0;readbuffer:=buffer[i];
if eqtb[27225].int=0 then begin if mubytekeep>0 then mubytekeep:=0;
goto 10;end;lastfound:=-2;
if(i=curinput.startfield)and(not mubytestart)then begin mubytekeep:=0;
if(eqtb[27215].int>=0)and(eqtb[27215].int<256)then if mubyteread[eqtb[
27215].int]<>-268435455 then begin mubytestart:=true;mubyteskip:=-1;
p:=mubyteread[eqtb[27215].int];goto 22;end;end;20:mubytestart:=false;
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
goto 10;end;10:end;{:1409}{1411:}procedure printbuffer(var i:integer);
var c:ASCIIcode;
begin if eqtb[27225].int=0 then print(buffer[i])else if eqtb[27227].int>
0 then printchar(buffer[i])else begin c:=readbuffer(i);
if mubytetoken>0 then printcs(mubytetoken-4095)else print(c);end;
incr(i);end;{:1411}{78:}procedure normalizeselector;forward;
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
begin;print(264);terminput;end;if last=first then goto 10;
c:=buffer[first];if c>=97 then c:=c-32;
{84:}case c of 48,49,50,51,52,53,54,55,56,57:if deletionsallowed then
{88:}begin s1:=curtok;s2:=curcmd;s3:=curchr;s4:=alignstate;
alignstate:=1000000;OKtointerrupt:=false;
if(last>first+1)and(buffer[first+1]>=48)and(buffer[first+1]<=57)then c:=
c*10+buffer[first+1]-48*11 else c:=c-48;while c>0 do begin gettoken;
decr(c);end;curtok:=s1;curcmd:=s2;curchr:=s3;alignstate:=s4;
OKtointerrupt:=true;begin helpptr:=2;helpline[1]:=277;helpline[0]:=278;
end;showcontext;goto 22;end{:88};ifdef('TEXMF_DEBUG')68:begin debughelp;
goto 22;end;
endif('TEXMF_DEBUG')69:if baseptr>0 then begin editnamestart:=strstart[
inputstack[baseptr].namefield];
editnamelength:=strstart[inputstack[baseptr].namefield+1]-strstart[
inputstack[baseptr].namefield];editline:=line;jumpout;end;
72:{89:}begin if useerrhelp then begin giveerrhelp;useerrhelp:=false;
end else begin if helpptr=0 then begin helpptr:=2;helpline[1]:=279;
helpline[0]:=280;end;repeat decr(helpptr);print(helpline[helpptr]);
println;until helpptr=0;end;begin helpptr:=4;helpline[3]:=281;
helpline[2]:=280;helpline[1]:=282;helpline[0]:=283;end;goto 22;end{:89};
73:{87:}begin beginfilereading;
if last>first+1 then begin curinput.locfield:=first+1;buffer[first]:=32;
end else begin begin;print(276);terminput;end;curinput.locfield:=first;
end;first:=last;curinput.limitfield:=last-1;goto 10;end{:87};
81,82,83:{86:}begin errorcount:=0;interaction:=0+c-81;print(271);
case c of 81:begin printesc(272);decr(selector);end;82:printesc(273);
83:printesc(274);end;print(275);println;fflush(stdout);goto 10;end{:86};
88:begin interaction:=2;jumpout;end;others:end;{85:}begin print(265);
printnl(266);printnl(267);if baseptr>0 then print(268);
if deletionsallowed then printnl(269);printnl(270);end{:85}{:84};
end{:83};incr(errorcount);if errorcount=100 then begin printnl(263);
history:=3;jumpout;end;{90:}if interaction>0 then decr(selector);
if useerrhelp then begin println;giveerrhelp;
end else while helpptr>0 do begin decr(helpptr);
printnl(helpline[helpptr]);end;println;
if interaction>0 then incr(selector);println{:90};10:end;
{:82}{93:}noreturn procedure fatalerror(s:strnumber);
begin normalizeselector;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(285);
end;begin helpptr:=1;helpline[0]:=s;end;
begin if interaction=3 then interaction:=2;if logopened then error;
ifdef('TEXMF_DEBUG')if interaction>0 then debughelp;
endif('TEXMF_DEBUG')history:=3;jumpout;end;end;
{:93}{94:}noreturn procedure overflow(s:strnumber;n:integer);
begin normalizeselector;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(286);
end;print(s);printchar(61);printint(n);printchar(93);begin helpptr:=2;
helpline[1]:=287;helpline[0]:=288;end;
begin if interaction=3 then interaction:=2;if logopened then error;
ifdef('TEXMF_DEBUG')if interaction>0 then debughelp;
endif('TEXMF_DEBUG')history:=3;jumpout;end;end;
{:94}{95:}noreturn procedure confusion(s:strnumber);
begin normalizeselector;
if history<2 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(289);
end;print(s);printchar(41);begin helpptr:=1;helpline[0]:=290;end;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(291);
end;begin helpptr:=2;helpline[1]:=292;helpline[0]:=293;end;end;
begin if interaction=3 then interaction:=2;if logopened then error;
ifdef('TEXMF_DEBUG')if interaction>0 then debughelp;
endif('TEXMF_DEBUG')history:=3;jumpout;end;end;
{:95}{:4}{31:}{[35:]begin curinput.locfield:=first;
curinput.limitfield:=last-1;overflow(256,bufsize);end[:35]}
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
begin if strptr=maxstrings then overflow(258,maxstrings-initstrptr);
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
{:46}{47:}{1391:}function searchstring(search:strnumber):strnumber;
label 40;var result:strnumber;s:strnumber;len:integer;begin result:=0;
len:=(strstart[search+1]-strstart[search]);
if len=0 then begin result:=335;goto 40;end else begin s:=search-1;
while s>255 do begin if(strstart[s+1]-strstart[s])=len then if streqstr(
s,search)then begin result:=s;goto 40;end;decr(s);end;end;
40:searchstring:=result;end;
{:1391}{1392:}function slowmakestring:strnumber;label 10;
var s:strnumber;t:strnumber;begin t:=makestring;s:=searchstring(t);
if s>0 then begin begin decr(strptr);poolptr:=strstart[strptr];end;
slowmakestring:=s;goto 10;end;slowmakestring:=t;10:end;
{:1392}ifdef('INITEX')function getstringsstarted:boolean;label 30,10;
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
var j,k:poolpointer;u,v:nonnegativeinteger;begin j:=strstart[260];
v:=1000;while true do begin while n>=v do begin printchar(strpool[j]);
n:=n-v;end;if n<=0 then goto 10;k:=j+2;u:=v div(strpool[k-1]-48);
if strpool[k-1]=50 then begin k:=k+2;u:=u div(strpool[k-1]-48);end;
if n+u>=v then begin printchar(strpool[k]);n:=n+u;end else begin j:=j+2;
v:=v div(strpool[j-1]-48);end;end;10:end;
{:69}{70:}procedure printcurrentstring;var j:poolpointer;
begin j:=strstart[strptr];
while j<poolptr do begin printchar(strpool[j]);incr(j);end;end;
{:70}{71:}procedure terminput;var k:0..bufsize;begin fflush(stdout);
if not inputln(stdin,true)then fatalerror(261);termoffset:=0;
decr(selector);k:=first;while k<last do begin printbuffer(k)end;println;
incr(selector);end;{:71}{91:}procedure interror(n:integer);
begin print(284);printint(n);printchar(41);error;end;
{:91}{92:}procedure normalizeselector;
begin if logopened then selector:=19 else selector:=17;
if jobname=0 then openlogfile;if interaction=0 then decr(selector);end;
{:92}{98:}procedure pauseforinstructions;
begin if OKtointerrupt then begin interaction:=3;
if(selector=18)or(selector=16)then incr(selector);
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(294);
end;begin helpptr:=3;helpline[2]:=295;helpline[1]:=296;helpline[0]:=297;
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
end;end;
{:108}{114:}ifdef('TEXMF_DEBUG')procedure printword(w:memoryword);
begin printint(w.int);printchar(32);printscaled(w.int);printchar(32);
printscaled(round(65536*w.gr));println;printint(w.hh.lh);printchar(61);
printint(w.hh.b0);printchar(58);printint(w.hh.b1);printchar(59);
printint(w.hh.rh);printchar(32);printint(w.qqqq.b0);printchar(58);
printint(w.qqqq.b1);printchar(58);printint(w.qqqq.b2);printchar(58);
printint(w.qqqq.b3);end;
endif('TEXMF_DEBUG'){:114}{119:}{292:}procedure showtokenlist(p,q:
integer;l:integer);label 10;var m,c:integer;matchchr:ASCIIcode;
n:ASCIIcode;begin matchchr:=35;n:=48;tally:=0;
while(p<>-268435455)and(tally<l)do begin if p=q then{320:}begin
firstcount:=tally;trickcount:=tally+1+errorline-halferrorline;
if trickcount<errorline then trickcount:=errorline;end{:320};
{293:}if(p<himemmin)or(p>memend)then begin printesc(307);goto 10;end;
if mem[p].hh.lh>=4095 then printcs(mem[p].hh.lh-4095)else begin m:=mem[p
].hh.lh div 256;c:=mem[p].hh.lh mod 256;
if mem[p].hh.lh<0 then printesc(568)else{294:}case m of 1,2,3,4,7,8,10,
11,12:print(c);6:begin print(c);print(c);end;5:begin print(matchchr);
if c<=9 then printchar(c+48)else begin printchar(33);goto 10;end;end;
13:begin matchchr:=c;print(c);incr(n);printchar(n);if n>57 then goto 10;
end;14:print(569);others:printesc(568)end{:294};end{:293};
p:=mem[p].hh.rh;end;if p<>-268435455 then printesc(567);10:end;
{:292}{306:}procedure runaway;var p:halfword;
begin if scannerstatus>1 then begin case scannerstatus of 2:begin
printnl(582);p:=defref;end;3:begin printnl(583);p:=memtop-3;end;
4:begin printnl(584);p:=memtop-4;end;5:begin printnl(585);p:=defref;end;
end;printchar(63);println;
showtokenlist(mem[p].hh.rh,-268435455,errorline-10);end;end;
{:306}{:119}{120:}function getavail:halfword;var p:halfword;
begin p:=avail;
if p<>-268435455 then avail:=mem[avail].hh.rh else if memend<memmax then
begin incr(memend);p:=memend;end else begin decr(himemmin);p:=himemmin;
if himemmin<=lomemmax then begin runaway;overflow(298,memmax+1-memmin);
end;end;mem[p].hh.rh:=-268435455;ifdef('STAT')incr(dynused);
endif('STAT')getavail:=p;end;
{:120}{123:}procedure flushlist(p:halfword);var q,r:halfword;
begin if p<>-268435455 then begin r:=p;repeat q:=r;r:=mem[r].hh.rh;
ifdef('STAT')decr(dynused);endif('STAT')until r=-268435455;
mem[q].hh.rh:=avail;avail:=p;end;end;
{:123}{125:}function getnode(s:integer):halfword;label 40,10,20;
var p:halfword;q:halfword;r:integer;t:integer;begin 20:p:=rover;
repeat{127:}q:=p+mem[p].hh.lh;
while(mem[q].hh.rh=268435455)do begin t:=mem[q+1].hh.rh;
if q=rover then rover:=t;mem[t+1].hh.lh:=mem[q+1].hh.lh;
mem[mem[q+1].hh.lh+1].hh.rh:=t;q:=q+mem[q].hh.lh;end;r:=q-s;
if r>p+1 then{128:}begin mem[p].hh.lh:=r-p;rover:=p;goto 40;end{:128};
if r=p then if mem[p+1].hh.rh<>p then{129:}begin rover:=mem[p+1].hh.rh;
t:=mem[p+1].hh.lh;mem[rover+1].hh.lh:=t;mem[t+1].hh.rh:=rover;goto 40;
end{:129};mem[p].hh.lh:=q-p{:127};p:=mem[p+1].hh.rh;until p=rover;
if s=1073741824 then begin getnode:=268435455;goto 10;end;
if lomemmax+2<himemmin then if lomemmax+2<=membot+268435455 then{126:}
begin if himemmin-lomemmax>=1998 then t:=lomemmax+1000 else t:=lomemmax
+1+(himemmin-lomemmax)div 2;p:=mem[rover+1].hh.lh;q:=lomemmax;
mem[p+1].hh.rh:=q;mem[rover+1].hh.lh:=q;
if t>membot+268435455 then t:=membot+268435455;mem[q+1].hh.rh:=rover;
mem[q+1].hh.lh:=p;mem[q].hh.rh:=268435455;mem[q].hh.lh:=t-lomemmax;
lomemmax:=t;mem[lomemmax].hh.rh:=-268435455;
mem[lomemmax].hh.lh:=-268435455;rover:=q;goto 20;end{:126};
overflow(298,memmax+1-memmin);40:mem[r].hh.rh:=-268435455;
ifdef('STAT')varused:=varused+s;endif('STAT')getnode:=r;10:end;
{:125}{130:}procedure freenode(p:halfword;s:halfword);var q:halfword;
begin mem[p].hh.lh:=s;mem[p].hh.rh:=268435455;q:=mem[rover+1].hh.lh;
mem[p+1].hh.lh:=q;mem[p+1].hh.rh:=rover;mem[rover+1].hh.lh:=p;
mem[q+1].hh.rh:=p;ifdef('STAT')varused:=varused-s;endif('STAT')end;
{:130}{131:}ifdef('INITEX')procedure sortavail;var p,q,r:halfword;
oldrover:halfword;begin p:=getnode(1073741824);p:=mem[rover+1].hh.rh;
mem[rover+1].hh.rh:=268435455;oldrover:=rover;
while p<>oldrover do{132:}if p<rover then begin q:=p;p:=mem[q+1].hh.rh;
mem[q+1].hh.rh:=rover;rover:=q;end else begin q:=rover;
while mem[q+1].hh.rh<p do q:=mem[q+1].hh.rh;r:=mem[p+1].hh.rh;
mem[p+1].hh.rh:=mem[q+1].hh.rh;mem[q+1].hh.rh:=p;p:=r;end{:132};
p:=rover;
while mem[p+1].hh.rh<>268435455 do begin mem[mem[p+1].hh.rh+1].hh.lh:=p;
p:=mem[p+1].hh.rh;end;mem[p+1].hh.rh:=rover;mem[rover+1].hh.lh:=p;end;
endif('INITEX'){:131}{136:}function newnullbox:halfword;var p:halfword;
begin p:=getnode(7);mem[p].hh.b0:=0;mem[p].hh.b1:=0;mem[p+1].int:=0;
mem[p+2].int:=0;mem[p+3].int:=0;mem[p+4].int:=0;
mem[p+5].hh.rh:=-268435455;mem[p+5].hh.b0:=0;mem[p+5].hh.b1:=0;
mem[p+6].gr:=0.0;newnullbox:=p;end;
{:136}{139:}function newrule:halfword;var p:halfword;
begin p:=getnode(4);mem[p].hh.b0:=2;mem[p].hh.b1:=0;
mem[p+1].int:=-1073741824;mem[p+2].int:=-1073741824;
mem[p+3].int:=-1073741824;newrule:=p;end;
{:139}{144:}function newligature(f:internalfontnumber;c:quarterword;
q:halfword):halfword;var p:halfword;begin p:=getnode(2);mem[p].hh.b0:=6;
mem[p+1].hh.b0:=f;mem[p+1].hh.b1:=c;mem[p+1].hh.rh:=q;mem[p].hh.b1:=0;
newligature:=p;end;function newligitem(c:quarterword):halfword;
var p:halfword;begin p:=getnode(2);mem[p].hh.b1:=c;
mem[p+1].hh.rh:=-268435455;newligitem:=p;end;
{:144}{145:}function newdisc:halfword;var p:halfword;
begin p:=getnode(2);mem[p].hh.b0:=7;mem[p].hh.b1:=0;
mem[p+1].hh.lh:=-268435455;mem[p+1].hh.rh:=-268435455;newdisc:=p;end;
{:145}{147:}function newmath(w:scaled;s:smallnumber):halfword;
var p:halfword;begin p:=getnode(2);mem[p].hh.b0:=9;mem[p].hh.b1:=s;
mem[p+1].int:=w;newmath:=p;end;
{:147}{151:}function newspec(p:halfword):halfword;var q:halfword;
begin q:=getnode(4);mem[q]:=mem[p];mem[q].hh.rh:=-268435455;
mem[q+1].int:=mem[p+1].int;mem[q+2].int:=mem[p+2].int;
mem[q+3].int:=mem[p+3].int;newspec:=q;end;
{:151}{152:}function newparamglue(n:smallnumber):halfword;
var p:halfword;q:halfword;begin p:=getnode(2);mem[p].hh.b0:=10;
mem[p].hh.b1:=n+1;mem[p+1].hh.rh:=-268435455;
q:={224:}eqtb[24527+n].hh.rh{:224};mem[p+1].hh.lh:=q;incr(mem[q].hh.rh);
newparamglue:=p;end;{:152}{153:}function newglue(q:halfword):halfword;
var p:halfword;begin p:=getnode(2);mem[p].hh.b0:=10;mem[p].hh.b1:=0;
mem[p+1].hh.rh:=-268435455;mem[p+1].hh.lh:=q;incr(mem[q].hh.rh);
newglue:=p;end;
{:153}{154:}function newskipparam(n:smallnumber):halfword;
var p:halfword;begin tempptr:=newspec({224:}eqtb[24527+n].hh.rh{:224});
p:=newglue(tempptr);mem[tempptr].hh.rh:=-268435455;mem[p].hh.b1:=n+1;
newskipparam:=p;end;{:154}{156:}function newkern(w:scaled):halfword;
var p:halfword;begin p:=getnode(2);mem[p].hh.b0:=11;mem[p].hh.b1:=0;
mem[p+1].int:=w;newkern:=p;end;
{:156}{158:}function newpenalty(m:integer):halfword;var p:halfword;
begin p:=getnode(2);mem[p].hh.b0:=12;mem[p].hh.b1:=0;mem[p+1].int:=m;
newpenalty:=p;end;
{:158}{167:}ifdef('TEXMF_DEBUG')procedure checkmem(printlocs:boolean);
label 31,32;var p,q:halfword;clobbered:boolean;
begin for p:=memmin to lomemmax do freearr[p]:=false;
for p:=himemmin to memend do freearr[p]:=false;{168:}p:=avail;
q:=-268435455;clobbered:=false;
while p<>-268435455 do begin if(p>memend)or(p<himemmin)then clobbered:=
true else if freearr[p]then clobbered:=true;
if clobbered then begin printnl(299);printint(q);goto 31;end;
freearr[p]:=true;q:=p;p:=mem[q].hh.rh;end;31:{:168};{169:}p:=rover;
q:=-268435455;clobbered:=false;
repeat if(p>=lomemmax)or(p<memmin)then clobbered:=true else if(mem[p+1].
hh.rh>=lomemmax)or(mem[p+1].hh.rh<memmin)then clobbered:=true else if
not((mem[p].hh.rh=268435455))or(mem[p].hh.lh<2)or(p+mem[p].hh.lh>
lomemmax)or(mem[mem[p+1].hh.rh+1].hh.lh<>p)then clobbered:=true;
if clobbered then begin printnl(300);printint(q);goto 32;end;
for q:=p to p+mem[p].hh.lh-1 do begin if freearr[q]then begin printnl(
301);printint(q);goto 32;end;freearr[q]:=true;end;q:=p;
p:=mem[p+1].hh.rh;until p=rover;32:{:169};{170:}p:=memmin;
while p<=lomemmax do begin if(mem[p].hh.rh=268435455)then begin printnl(
302);printint(p);end;while(p<=lomemmax)and not freearr[p]do incr(p);
while(p<=lomemmax)and freearr[p]do incr(p);end{:170};
if printlocs then{171:}begin printnl(303);
for p:=memmin to lomemmax do if not freearr[p]and((p>waslomax)or wasfree
[p])then begin printchar(32);printint(p);end;
for p:=himemmin to memend do if not freearr[p]and((p<washimin)or(p>
wasmemend)or wasfree[p])then begin printchar(32);printint(p);end;
end{:171};for p:=memmin to lomemmax do wasfree[p]:=freearr[p];
for p:=himemmin to memend do wasfree[p]:=freearr[p];wasmemend:=memend;
waslomax:=lomemmax;washimin:=himemmin;end;
endif('TEXMF_DEBUG'){:167}{172:}ifdef('TEXMF_DEBUG')procedure searchmem(
p:halfword);var q:integer;
begin for q:=memmin to lomemmax do begin if mem[q].hh.rh=p then begin
printnl(304);printint(q);printchar(41);end;
if mem[q].hh.lh=p then begin printnl(305);printint(q);printchar(41);end;
end;
for q:=himemmin to memend do begin if mem[q].hh.rh=p then begin printnl(
304);printint(q);printchar(41);end;
if mem[q].hh.lh=p then begin printnl(305);printint(q);printchar(41);end;
end;
{255:}for q:=1 to 25578 do begin if eqtb[q].hh.rh=p then begin printnl(
513);printint(q);printchar(41);end;end{:255};
{285:}if saveptr>0 then for q:=0 to saveptr-1 do begin if savestack[q].
hh.rh=p then begin printnl(559);printint(q);printchar(41);end;end{:285};
{936:}for q:=0 to hyphsize do begin if hyphlist[q]=p then begin printnl(
956);printint(q);printchar(41);end;end{:936};end;
endif('TEXMF_DEBUG'){:172}{174:}procedure shortdisplay(p:integer);
var n:integer;
begin while p>memmin do begin if(p>=himemmin)then begin if p<=memend
then begin if mem[p].hh.b0<>fontinshortdisplay then begin if(mem[p].hh.
b0>fontmax)then printchar(42)else{267:}printesc(hash[15525+mem[p].hh.b0]
.rh){:267};printchar(32);fontinshortdisplay:=mem[p].hh.b0;end;
print(mem[p].hh.b1);end;
end else{175:}case mem[p].hh.b0 of 0,1,3,8,4,5,13:print(306);
2:printchar(124);10:if mem[p+1].hh.lh<>membot then printchar(32);
9:printchar(36);6:shortdisplay(mem[p+1].hh.rh);
7:begin shortdisplay(mem[p+1].hh.lh);shortdisplay(mem[p+1].hh.rh);
n:=mem[p].hh.b1;
while n>0 do begin if mem[p].hh.rh<>-268435455 then p:=mem[p].hh.rh;
decr(n);end;end;others:end{:175};p:=mem[p].hh.rh;end;end;
{:174}{176:}procedure printfontandchar(p:integer);
begin if p>memend then printesc(307)else begin if(mem[p].hh.b0>fontmax)
then printchar(42)else{267:}printesc(hash[15525+mem[p].hh.b0].rh){:267};
printchar(32);print(mem[p].hh.b1);end;end;
procedure printmark(p:integer);begin printchar(123);
if(p<himemmin)or(p>memend)then printesc(307)else showtokenlist(mem[p].hh
.rh,-268435455,maxprintline-10);printchar(125);end;
procedure printruledimen(d:scaled);
begin if(d=-1073741824)then printchar(42)else printscaled(d);end;
{:176}{177:}procedure printglue(d:scaled;order:integer;s:strnumber);
begin printscaled(d);
if(order<0)or(order>3)then print(308)else if order>0 then begin print(
309);while order>1 do begin printchar(108);decr(order);end;
end else if s<>0 then print(s);end;
{:177}{178:}procedure printspec(p:integer;s:strnumber);
begin if(p<memmin)or(p>=lomemmax)then printchar(42)else begin
printscaled(mem[p+1].int);if s<>0 then print(s);
if mem[p+2].int<>0 then begin print(310);
printglue(mem[p+2].int,mem[p].hh.b0,s);end;
if mem[p+3].int<>0 then begin print(311);
printglue(mem[p+3].int,mem[p].hh.b1,s);end;end;end;
{:178}{179:}{694:}procedure printfamandchar(p:halfword);
begin printesc(469);printint(mem[p].hh.b0);printchar(32);
print(mem[p].hh.b1);end;procedure printdelimiter(p:halfword);
var a:integer;begin a:=mem[p].qqqq.b0*256+mem[p].qqqq.b1;
a:=a*4096+mem[p].qqqq.b2*256+mem[p].qqqq.b3;
if a<0 then printint(a)else printhex(a);end;
{:694}{695:}procedure showinfo;forward;
procedure printsubsidiarydata(p:halfword;c:ASCIIcode);
begin if(poolptr-strstart[strptr])>=depththreshold then begin if mem[p].
hh.rh<>0 then print(312);end else begin begin strpool[poolptr]:=c;
incr(poolptr);end;tempptr:=p;case mem[p].hh.rh of 1:begin println;
printcurrentstring;printfamandchar(p);end;2:showinfo;
3:if mem[p].hh.lh=-268435455 then begin println;printcurrentstring;
print(876);end else showinfo;others:end;decr(poolptr);end;end;
{:695}{697:}procedure printstyle(c:integer);
begin case c div 2 of 0:printesc(877);1:printesc(878);2:printesc(879);
3:printesc(880);others:print(881)end;end;
{:697}{225:}procedure printskipparam(n:integer);
begin case n of 0:printesc(381);1:printesc(382);2:printesc(383);
3:printesc(384);4:printesc(385);5:printesc(386);6:printesc(387);
7:printesc(388);8:printesc(389);9:printesc(390);10:printesc(391);
11:printesc(392);12:printesc(393);13:printesc(394);14:printesc(395);
15:printesc(396);16:printesc(397);17:printesc(398);others:print(399)end;
end;{:225}{:179}{182:}procedure shownodelist(p:integer);label 10;
var n:integer;g:real;
begin if(poolptr-strstart[strptr])>depththreshold then begin if p>
-268435455 then print(312);goto 10;end;n:=0;
while p>memmin do begin println;printcurrentstring;
if p>memend then begin print(313);goto 10;end;incr(n);
if n>breadthmax then begin print(314);goto 10;end;
{183:}if(p>=himemmin)then printfontandchar(p)else case mem[p].hh.b0 of 0
,1,13:{184:}begin if mem[p].hh.b0=0 then printesc(104)else if mem[p].hh.
b0=1 then printesc(118)else printesc(316);print(317);
printscaled(mem[p+3].int);printchar(43);printscaled(mem[p+2].int);
print(318);printscaled(mem[p+1].int);
if mem[p].hh.b0=13 then{185:}begin if mem[p].hh.b1<>0 then begin print(
284);printint(mem[p].hh.b1+1);print(320);end;
if mem[p+6].int<>0 then begin print(321);
printglue(mem[p+6].int,mem[p+5].hh.b1,0);end;
if mem[p+4].int<>0 then begin print(322);
printglue(mem[p+4].int,mem[p+5].hh.b0,0);end;
end{:185}else begin{186:}g:=mem[p+6].gr;
if(g<>0.0)and(mem[p+5].hh.b0<>0)then begin print(323);
if mem[p+5].hh.b0=2 then print(324);
if fabs(g)>20000.0 then begin if g>0.0 then printchar(62)else print(325)
;printglue(20000*65536,mem[p+5].hh.b1,0);
end else printglue(round(65536*g),mem[p+5].hh.b1,0);end{:186};
if mem[p+4].int<>0 then begin print(319);printscaled(mem[p+4].int);end;
end;begin begin strpool[poolptr]:=46;incr(poolptr);end;
shownodelist(mem[p+5].hh.rh);decr(poolptr);end;end{:184};
2:{187:}begin printesc(326);printruledimen(mem[p+3].int);printchar(43);
printruledimen(mem[p+2].int);print(318);printruledimen(mem[p+1].int);
end{:187};3:{188:}begin printesc(327);printint(mem[p].hh.b1);print(328);
printscaled(mem[p+3].int);print(329);printspec(mem[p+4].hh.rh,0);
printchar(44);printscaled(mem[p+2].int);print(330);
printint(mem[p+1].int);begin begin strpool[poolptr]:=46;incr(poolptr);
end;shownodelist(mem[p+4].hh.lh);decr(poolptr);end;end{:188};
8:{1359:}case mem[p].hh.b1 of 0:begin printwritewhatsit(1317,p);
printchar(61);
printfilename(mem[p+1].hh.rh,mem[p+2].hh.lh,mem[p+2].hh.rh);end;
1:begin printwritewhatsit(606,p);printmark(mem[p+1].hh.rh);end;
2:printwritewhatsit(1318,p);3:begin printesc(1319);
if mem[p+1].hh.b0<>64 then begin printchar(60);
printint(mem[p+1].hh.b0-64);
if(mem[p+1].hh.b0-64=2)or(mem[p+1].hh.b0-64=3)then begin printchar(58);
printint(mem[p+1].hh.b1-64);end;printchar(62);end;
printmark(mem[p+1].hh.rh);end;4:begin printesc(1321);
printint(mem[p+1].hh.rh);print(1324);printint(mem[p+1].hh.b0);
printchar(44);printint(mem[p+1].hh.b1);printchar(41);end;
others:print(1325)end{:1359};
10:{189:}if mem[p].hh.b1>=100 then{190:}begin printesc(335);
if mem[p].hh.b1=101 then printchar(99)else if mem[p].hh.b1=102 then
printchar(120);print(336);printspec(mem[p+1].hh.lh,0);
begin begin strpool[poolptr]:=46;incr(poolptr);end;
shownodelist(mem[p+1].hh.rh);decr(poolptr);end;
end{:190}else begin printesc(331);
if mem[p].hh.b1<>0 then begin printchar(40);
if mem[p].hh.b1<98 then printskipparam(mem[p].hh.b1-1)else if mem[p].hh.
b1=98 then printesc(332)else printesc(333);printchar(41);end;
if mem[p].hh.b1<>98 then begin printchar(32);
if mem[p].hh.b1<98 then printspec(mem[p+1].hh.lh,0)else printspec(mem[p
+1].hh.lh,334);end;end{:189};
11:{191:}if mem[p].hh.b1<>99 then begin printesc(337);
if mem[p].hh.b1<>0 then printchar(32);printscaled(mem[p+1].int);
if mem[p].hh.b1=2 then print(338);end else begin printesc(339);
printscaled(mem[p+1].int);print(334);end{:191};
9:{192:}begin printesc(340);
if mem[p].hh.b1=0 then print(341)else print(342);
if mem[p+1].int<>0 then begin print(343);printscaled(mem[p+1].int);end;
end{:192};6:{193:}begin printfontandchar(p+1);print(344);
if mem[p].hh.b1>1 then printchar(124);
fontinshortdisplay:=mem[p+1].hh.b0;shortdisplay(mem[p+1].hh.rh);
if odd(mem[p].hh.b1)then printchar(124);printchar(41);end{:193};
12:{194:}begin printesc(345);printint(mem[p+1].int);end{:194};
7:{195:}begin printesc(346);if mem[p].hh.b1>0 then begin print(347);
printint(mem[p].hh.b1);end;begin begin strpool[poolptr]:=46;
incr(poolptr);end;shownodelist(mem[p+1].hh.lh);decr(poolptr);end;
begin strpool[poolptr]:=124;incr(poolptr);end;
shownodelist(mem[p+1].hh.rh);decr(poolptr);end{:195};
4:{196:}begin printesc(348);printmark(mem[p+1].int);end{:196};
5:{197:}begin printesc(349);begin begin strpool[poolptr]:=46;
incr(poolptr);end;shownodelist(mem[p+1].int);decr(poolptr);end;
end{:197};{693:}14:printstyle(mem[p].hh.b1);
15:{698:}begin printesc(538);begin strpool[poolptr]:=68;incr(poolptr);
end;shownodelist(mem[p+1].hh.lh);decr(poolptr);
begin strpool[poolptr]:=84;incr(poolptr);end;
shownodelist(mem[p+1].hh.rh);decr(poolptr);begin strpool[poolptr]:=83;
incr(poolptr);end;shownodelist(mem[p+2].hh.lh);decr(poolptr);
begin strpool[poolptr]:=115;incr(poolptr);end;
shownodelist(mem[p+2].hh.rh);decr(poolptr);end{:698};
16,17,18,19,20,21,22,23,24,27,26,29,28,30,31:{699:}begin case mem[p].hh.
b0 of 16:printesc(882);17:printesc(883);18:printesc(884);
19:printesc(885);20:printesc(886);21:printesc(887);22:printesc(888);
23:printesc(889);27:printesc(890);26:printesc(891);29:printesc(552);
24:begin printesc(546);printdelimiter(p+4);end;28:begin printesc(520);
printfamandchar(p+4);end;30:begin printesc(892);printdelimiter(p+1);end;
31:begin printesc(893);printdelimiter(p+1);end;end;
if mem[p].hh.b1<>0 then if mem[p].hh.b1=1 then printesc(894)else
printesc(895);if mem[p].hh.b0<30 then printsubsidiarydata(p+1,46);
printsubsidiarydata(p+2,94);printsubsidiarydata(p+3,95);end{:699};
25:{700:}begin printesc(896);
if mem[p+1].int=1073741824 then print(897)else printscaled(mem[p+1].int)
;
if(mem[p+4].qqqq.b0<>0)or(mem[p+4].qqqq.b1<>0)or(mem[p+4].qqqq.b2<>0)or(
mem[p+4].qqqq.b3<>0)then begin print(898);printdelimiter(p+4);end;
if(mem[p+5].qqqq.b0<>0)or(mem[p+5].qqqq.b1<>0)or(mem[p+5].qqqq.b2<>0)or(
mem[p+5].qqqq.b3<>0)then begin print(899);printdelimiter(p+5);end;
printsubsidiarydata(p+2,92);printsubsidiarydata(p+3,47);end{:700};
{:693}others:print(315)end{:183};p:=mem[p].hh.rh;end;10:end;
{:182}{198:}procedure showbox(p:halfword);
begin{236:}depththreshold:=eqtb[27192].int;
breadthmax:=eqtb[27191].int{:236};if breadthmax<=0 then breadthmax:=5;
if poolptr+depththreshold>=poolsize then depththreshold:=poolsize-
poolptr-1;shownodelist(p);println;end;
{:198}{200:}procedure deletetokenref(p:halfword);
begin if mem[p].hh.lh=-268435455 then flushlist(p)else decr(mem[p].hh.lh
);end;{:200}{201:}procedure deleteglueref(p:halfword);
begin if mem[p].hh.rh=-268435455 then freenode(p,4)else decr(mem[p].hh.
rh);end;{:201}{202:}procedure flushnodelist(p:halfword);label 30;
var q:halfword;begin while p<>-268435455 do begin q:=mem[p].hh.rh;
if(p>=himemmin)then begin mem[p].hh.rh:=avail;avail:=p;
ifdef('STAT')decr(dynused);
endif('STAT')end else begin case mem[p].hh.b0 of 0,1,13:begin
flushnodelist(mem[p+5].hh.rh);freenode(p,7);goto 30;end;
2:begin freenode(p,4);goto 30;end;3:begin flushnodelist(mem[p+4].hh.lh);
deleteglueref(mem[p+4].hh.rh);freenode(p,5);goto 30;end;
8:{1361:}begin case mem[p].hh.b1 of 0:freenode(p,3);
1,3:begin deletetokenref(mem[p+1].hh.rh);freenode(p,2);goto 30;end;
2,4:freenode(p,2);others:confusion(1327)end;goto 30;end{:1361};
10:begin begin if mem[mem[p+1].hh.lh].hh.rh=-268435455 then freenode(mem
[p+1].hh.lh,4)else decr(mem[mem[p+1].hh.lh].hh.rh);end;
if mem[p+1].hh.rh<>-268435455 then flushnodelist(mem[p+1].hh.rh);end;
11,9,12:;6:flushnodelist(mem[p+1].hh.rh);4:deletetokenref(mem[p+1].int);
7:begin flushnodelist(mem[p+1].hh.lh);flushnodelist(mem[p+1].hh.rh);end;
5:flushnodelist(mem[p+1].int);{701:}14:begin freenode(p,3);goto 30;end;
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
{:701}others:confusion(350)end;freenode(p,2);30:end;p:=q;end;end;
{:202}{204:}function copynodelist(p:halfword):halfword;var h:halfword;
q:halfword;r:halfword;words:0..5;begin h:=getavail;q:=h;
while p<>-268435455 do begin{205:}words:=1;
if(p>=himemmin)then r:=getavail else{206:}case mem[p].hh.b0 of 0,1,13:
begin r:=getnode(7);mem[r+6]:=mem[p+6];mem[r+5]:=mem[p+5];
mem[r+5].hh.rh:=copynodelist(mem[p+5].hh.rh);words:=5;end;
2:begin r:=getnode(4);words:=4;end;3:begin r:=getnode(5);
mem[r+4]:=mem[p+4];incr(mem[mem[p+4].hh.rh].hh.rh);
mem[r+4].hh.lh:=copynodelist(mem[p+4].hh.lh);words:=4;end;
8:{1360:}case mem[p].hh.b1 of 0:begin r:=getnode(3);words:=3;end;
1,3:begin r:=getnode(2);incr(mem[mem[p+1].hh.rh].hh.lh);words:=2;end;
2,4:begin r:=getnode(2);words:=2;end;others:confusion(1326)end{:1360};
10:begin r:=getnode(2);incr(mem[mem[p+1].hh.lh].hh.rh);
mem[r+1].hh.lh:=mem[p+1].hh.lh;
mem[r+1].hh.rh:=copynodelist(mem[p+1].hh.rh);end;
11,9,12:begin r:=getnode(2);words:=2;end;6:begin r:=getnode(2);
mem[r+1]:=mem[p+1];mem[r+1].hh.rh:=copynodelist(mem[p+1].hh.rh);end;
7:begin r:=getnode(2);mem[r+1].hh.lh:=copynodelist(mem[p+1].hh.lh);
mem[r+1].hh.rh:=copynodelist(mem[p+1].hh.rh);end;4:begin r:=getnode(2);
incr(mem[mem[p+1].int].hh.lh);words:=2;end;5:begin r:=getnode(2);
mem[r+1].int:=copynodelist(mem[p+1].int);end;
others:confusion(351)end{:206};while words>0 do begin decr(words);
mem[r+words]:=mem[p+words];end{:205};mem[q].hh.rh:=r;q:=r;
p:=mem[p].hh.rh;end;mem[q].hh.rh:=-268435455;q:=mem[h].hh.rh;
begin mem[h].hh.rh:=avail;avail:=h;ifdef('STAT')decr(dynused);
endif('STAT')end;copynodelist:=q;end;
{:204}{211:}procedure printmode(m:integer);
begin if m>0 then case m div(101)of 0:print(352);1:print(353);
2:print(354);
end else if m=0 then print(355)else case(-m)div(101)of 0:print(356);
1:print(357);2:print(358);end;end;procedure printinmode(m:integer);
begin if m>0 then case m div(101)of 0:print(359);1:print(360);
2:print(361);
end else if m=0 then print(362)else case(-m)div(101)of 0:print(363);
1:print(364);2:print(365);end;end;{:211}{216:}procedure pushnest;
begin if nestptr>maxneststack then begin maxneststack:=nestptr;
if nestptr=nestsize then overflow(366,nestsize);end;
nest[nestptr]:=curlist;incr(nestptr);curlist.headfield:=getavail;
curlist.tailfield:=curlist.headfield;curlist.pgfield:=0;
curlist.mlfield:=line;end;{:216}{217:}procedure popnest;
begin begin mem[curlist.headfield].hh.rh:=avail;
avail:=curlist.headfield;ifdef('STAT')decr(dynused);endif('STAT')end;
decr(nestptr);curlist:=nest[nestptr];end;
{:217}{218:}procedure printtotals;forward;procedure showactivities;
var p:0..nestsize;m:-203..203;a:memoryword;q,r:halfword;t:integer;
begin nest[nestptr]:=curlist;printnl(335);println;
for p:=nestptr downto 0 do begin m:=nest[p].modefield;
a:=nest[p].auxfield;printnl(367);printmode(m);print(368);
printint(abs(nest[p].mlfield));
if m=102 then if nest[p].pgfield<>8585216 then begin print(369);
printint(nest[p].pgfield mod 65536);print(370);
printint(nest[p].pgfield div 4194304);printchar(44);
printint((nest[p].pgfield div 65536)mod 64);printchar(41);end;
if nest[p].mlfield<0 then print(371);
if p=0 then begin{989:}if memtop-2<>pagetail then begin printnl(996);
if outputactive then print(997);showbox(mem[memtop-2].hh.rh);
if pagecontents>0 then begin printnl(998);printtotals;printnl(999);
printscaled(pagesofar[0]);r:=mem[memtop].hh.rh;
while r<>memtop do begin println;printesc(327);t:=mem[r].hh.b1;
printint(t);print(1000);
if eqtb[27229+t].int=1000 then t:=mem[r+3].int else t:=xovern(mem[r+3].
int,1000)*eqtb[27229+t].int;printscaled(t);
if mem[r].hh.b0=1 then begin q:=memtop-2;t:=0;repeat q:=mem[q].hh.rh;
if(mem[q].hh.b0=3)and(mem[q].hh.b1=mem[r].hh.b1)then incr(t);
until q=mem[r+1].hh.lh;print(1001);printint(t);print(1002);end;
r:=mem[r].hh.rh;end;end;end{:989};
if mem[memtop-1].hh.rh<>-268435455 then printnl(372);end;
showbox(mem[nest[p].headfield].hh.rh);
{219:}case abs(m)div(101)of 0:begin printnl(373);
if a.int<=-65536000 then print(374)else printscaled(a.int);
if nest[p].pgfield<>0 then begin print(375);printint(nest[p].pgfield);
if nest[p].pgfield<>1 then print(376)else print(377);end;end;
1:begin printnl(378);printint(a.hh.lh);
if m>0 then if a.hh.rh>0 then begin print(379);printint(a.hh.rh);end;
end;2:if a.int<>-268435455 then begin print(380);showbox(a.int);end;
end{:219};end;end;{:218}{237:}procedure printparam(n:integer);
begin case n of 0:printesc(425);1:printesc(426);2:printesc(427);
3:printesc(428);4:printesc(429);5:printesc(430);6:printesc(431);
7:printesc(432);8:printesc(433);9:printesc(434);10:printesc(435);
11:printesc(436);12:printesc(437);13:printesc(438);14:printesc(439);
15:printesc(440);16:printesc(441);17:printesc(442);18:printesc(443);
19:printesc(444);20:printesc(445);21:printesc(446);22:printesc(447);
23:printesc(448);24:printesc(449);25:printesc(450);26:printesc(451);
27:printesc(452);28:printesc(453);29:printesc(454);30:printesc(455);
31:printesc(456);32:printesc(457);33:printesc(458);34:printesc(459);
35:printesc(460);36:printesc(461);37:printesc(462);38:printesc(463);
39:printesc(464);40:printesc(465);41:printesc(466);42:printesc(467);
43:printesc(468);44:printesc(469);45:printesc(470);46:printesc(471);
47:printesc(472);48:printesc(473);49:printesc(474);50:printesc(475);
51:printesc(476);52:printesc(477);53:printesc(478);54:printesc(479);
55:printesc(480);56:printesc(481);57:printesc(482);58:printesc(483);
59:printesc(484);60:printesc(485);61:printesc(486);others:print(487)end;
end;{:237}{245:}procedure begindiagnostic;begin oldsetting:=selector;
if(eqtb[27196].int<=0)and(selector=19)then begin decr(selector);
if history=0 then history:=1;end;end;
procedure enddiagnostic(blankline:boolean);begin printnl(335);
if blankline then println;selector:=oldsetting;end;
{:245}{247:}procedure printlengthparam(n:integer);
begin case n of 0:printesc(490);1:printesc(491);2:printesc(492);
3:printesc(493);4:printesc(494);5:printesc(495);6:printesc(496);
7:printesc(497);8:printesc(498);9:printesc(499);10:printesc(500);
11:printesc(501);12:printesc(502);13:printesc(503);14:printesc(504);
15:printesc(505);16:printesc(506);17:printesc(507);18:printesc(508);
19:printesc(509);20:printesc(510);others:print(511)end;end;
{:247}{252:}{298:}procedure printcmdchr(cmd:quarterword;
chrcode:halfword);begin case cmd of 1:begin print(570);print(chrcode);
end;2:begin print(571);print(chrcode);end;3:begin print(572);
print(chrcode);end;6:begin print(573);print(chrcode);end;
7:begin print(574);print(chrcode);end;8:begin print(575);print(chrcode);
end;9:print(576);10:begin print(577);print(chrcode);end;
11:begin print(578);print(chrcode);end;12:begin print(579);
print(chrcode);end;
{227:}75,76:if chrcode<24545 then printskipparam(chrcode-24527)else if
chrcode<24801 then begin printesc(400);printint(chrcode-24545);
end else begin printesc(401);printint(chrcode-24801);end;
{:227}{231:}72:if chrcode>=25067 then begin printesc(412);
printint(chrcode-25067);end else case chrcode of 25058:printesc(403);
25059:printesc(404);25060:printesc(405);25061:printesc(406);
25062:printesc(407);25063:printesc(408);25064:printesc(409);
25065:printesc(410);others:printesc(411)end;
{:231}{239:}73:if chrcode<27229 then printparam(chrcode-27167)else begin
printesc(488);printint(chrcode-27229);end;
{:239}{249:}74:if chrcode<27762 then printlengthparam(chrcode-27741)else
begin printesc(512);printint(chrcode-27762);end;
{:249}{266:}45:printesc(520);90:printesc(521);40:printesc(522);
41:printesc(523);77:printesc(532);61:printesc(524);42:printesc(544);
16:printesc(525);107:printesc(516);88:printesc(531);15:printesc(526);
92:printesc(527);67:if chrcode=10 then printesc(528)else printesc(517);
62:printesc(529);64:printesc(32);102:printesc(530);32:printesc(533);
36:printesc(534);39:printesc(535);37:printesc(327);44:printesc(47);
18:printesc(348);46:printesc(536);17:printesc(537);54:printesc(538);
91:printesc(539);34:printesc(540);65:printesc(541);103:printesc(542);
55:printesc(332);63:printesc(543);66:printesc(546);96:printesc(547);
0:printesc(548);98:printesc(549);80:printesc(545);84:printesc(413);
109:printesc(550);71:printesc(412);38:printesc(349);33:printesc(551);
56:printesc(552);35:printesc(553);{:266}{335:}13:printesc(609);
{:335}{380:}104:if chrcode=0 then printesc(644)else printesc(645);
{:380}{388:}110:case chrcode of 1:printesc(647);2:printesc(648);
3:printesc(649);4:printesc(650);others:printesc(646)end;
{:388}{415:}89:if chrcode=0 then printesc(488)else if chrcode=1 then
printesc(512)else if chrcode=2 then printesc(400)else printesc(401);
{:415}{420:}79:if chrcode=1 then printesc(684)else printesc(683);
82:if chrcode=0 then printesc(685)else printesc(686);
83:if chrcode=1 then printesc(687)else if chrcode=3 then printesc(688)
else printesc(689);70:case chrcode of 0:printesc(690);1:printesc(691);
2:printesc(692);3:printesc(693);others:printesc(694)end;
{:420}{472:}108:case chrcode of 0:printesc(750);1:printesc(751);
2:printesc(752);3:printesc(753);4:printesc(754);others:printesc(755)end;
{:472}{491:}105:case chrcode of 1:printesc(772);2:printesc(773);
3:printesc(774);4:printesc(775);5:printesc(776);6:printesc(777);
7:printesc(778);8:printesc(779);9:printesc(780);10:printesc(781);
11:printesc(782);12:printesc(783);13:printesc(784);14:printesc(785);
15:printesc(786);16:printesc(787);others:printesc(771)end;
{:491}{495:}106:if chrcode=2 then printesc(788)else if chrcode=4 then
printesc(789)else printesc(790);
{:495}{784:}4:if chrcode=256 then printesc(914)else begin print(918);
print(chrcode);end;
5:if chrcode=257 then printesc(915)else printesc(916);
{:784}{987:}81:case chrcode of 0:printesc(986);1:printesc(987);
2:printesc(988);3:printesc(989);4:printesc(990);5:printesc(991);
6:printesc(992);others:printesc(993)end;
{:987}{1056:}14:if chrcode=1 then printesc(1041)else printesc(1040);
{:1056}{1062:}26:case chrcode of 4:printesc(1042);0:printesc(1043);
1:printesc(1044);2:printesc(1045);others:printesc(1046)end;
27:case chrcode of 4:printesc(1047);0:printesc(1048);1:printesc(1049);
2:printesc(1050);others:printesc(1051)end;28:printesc(333);
29:printesc(337);30:printesc(339);
{:1062}{1075:}21:if chrcode=1 then printesc(1069)else printesc(1070);
22:if chrcode=1 then printesc(1071)else printesc(1072);
20:case chrcode of 0:printesc(414);1:printesc(1073);2:printesc(1074);
3:printesc(981);4:printesc(1075);5:printesc(983);
others:printesc(1076)end;
31:if chrcode=100 then printesc(1078)else if chrcode=101 then printesc(
1079)else if chrcode=102 then printesc(1080)else printesc(1077);
{:1075}{1092:}43:if chrcode=0 then printesc(1096)else printesc(1095);
{:1092}{1111:}25:if chrcode=10 then printesc(1107)else if chrcode=11
then printesc(1106)else printesc(1105);
23:if chrcode=1 then printesc(1109)else printesc(1108);
24:if chrcode=1 then printesc(1111)else printesc(1110);
{:1111}{1118:}47:if chrcode=1 then printesc(45)else printesc(346);
{:1118}{1146:}48:if chrcode=1 then printesc(1144)else printesc(1143);
{:1146}{1160:}50:case chrcode of 16:printesc(882);17:printesc(883);
18:printesc(884);19:printesc(885);20:printesc(886);21:printesc(887);
22:printesc(888);23:printesc(889);26:printesc(891);
others:printesc(890)end;
51:if chrcode=1 then printesc(894)else if chrcode=2 then printesc(895)
else printesc(1145);{:1160}{1173:}53:printstyle(chrcode);
{:1173}{1182:}52:case chrcode of 1:printesc(1164);2:printesc(1165);
3:printesc(1166);4:printesc(1167);5:printesc(1168);
others:printesc(1163)end;
{:1182}{1192:}49:if chrcode=30 then printesc(892)else printesc(893);
{:1192}{1212:}93:if chrcode=1 then printesc(1187)else if chrcode=2 then
printesc(1188)else printesc(1189);
97:if chrcode=0 then printesc(1190)else if chrcode=1 then printesc(1191)
else if chrcode=2 then printesc(1192)else printesc(1193);
{:1212}{1223:}94:if chrcode<>0 then if chrcode=10 then printesc(1209)
else if chrcode=11 then printesc(1210)else printesc(1208)else printesc(
1207);{:1223}{1226:}95:case chrcode of 0:printesc(1216);
1:printesc(1217);2:printesc(1218);3:printesc(1219);4:printesc(1220);
5:printesc(1221);7:printesc(1223);others:printesc(1222)end;
68:begin printesc(525);printhex(chrcode);end;69:begin printesc(537);
printhex(chrcode);end;
{:1226}{1234:}85:if chrcode=25580 then printesc(1228)else if chrcode=
25581 then printesc(1229)else if chrcode=25582 then printesc(1230)else
if chrcode=25631 then printesc(420)else if chrcode=26655 then printesc(
424)else if chrcode=25887 then printesc(421)else if chrcode=26143 then
printesc(422)else if chrcode=26399 then printesc(423)else printesc(489);
86:printsize(chrcode-25583);
{:1234}{1254:}99:if chrcode=1 then printesc(969)else printesc(957);
{:1254}{1258:}78:if chrcode=0 then printesc(1246)else printesc(1247);
{:1258}{1264:}87:begin print(1255);slowprint(fontname[chrcode]);
if fontsize[chrcode]<>fontdsize[chrcode]then begin print(756);
printscaled(fontsize[chrcode]);print(402);end;end;
{:1264}{1266:}100:case chrcode of 0:printesc(272);1:printesc(273);
2:printesc(274);others:printesc(1256)end;
{:1266}{1276:}60:if chrcode=0 then printesc(1258)else printesc(1257);
{:1276}{1281:}58:if chrcode=0 then printesc(1259)else printesc(1260);
{:1281}{1290:}57:if chrcode=25887 then printesc(1266)else printesc(1267)
;{:1290}{1295:}19:case chrcode of 1:printesc(1269);2:printesc(1270);
3:printesc(1271);others:printesc(1268)end;{:1295}{1298:}101:print(1278);
111:print(1279);112:printesc(1280);113:printesc(1281);
114:begin printesc(1187);printesc(1281);end;115:printesc(1282);
{:1298}{1349:}59:case chrcode of 0:printesc(1317);1:printesc(606);
2:printesc(1318);3:printesc(1319);4:printesc(1320);5:printesc(1321);
others:print(1322)end;{:1349}others:print(580)end;end;
{:298}ifdef('STAT')procedure showeqtb(n:halfword);
begin if n<1 then printchar(63)else if(n<24527)or((n>28017)and(n<=
eqtbtop))then{223:}begin sprintcs(n);printchar(61);
printcmdchr(eqtb[n].hh.b0,eqtb[n].hh.rh);
if eqtb[n].hh.b0>=111 then begin printchar(58);
showtokenlist(mem[eqtb[n].hh.rh].hh.rh,-268435455,32);end;
end{:223}else if n<25057 then{229:}if n<24545 then begin printskipparam(
n-24527);printchar(61);
if n<24542 then printspec(eqtb[n].hh.rh,402)else printspec(eqtb[n].hh.rh
,334);end else if n<24801 then begin printesc(400);printint(n-24545);
printchar(61);printspec(eqtb[n].hh.rh,402);end else begin printesc(401);
printint(n-24801);printchar(61);printspec(eqtb[n].hh.rh,334);
end{:229}else if n<27167 then{233:}if n=25057 then begin printesc(413);
printchar(61);
if eqtb[25057].hh.rh=-268435455 then printchar(48)else printint(mem[eqtb
[25057].hh.rh].hh.lh);end else if n<25067 then begin printcmdchr(72,n);
printchar(61);
if eqtb[n].hh.rh<>-268435455 then showtokenlist(mem[eqtb[n].hh.rh].hh.rh
,-268435455,32);end else if n<25323 then begin printesc(412);
printint(n-25067);printchar(61);
if eqtb[n].hh.rh<>-268435455 then showtokenlist(mem[eqtb[n].hh.rh].hh.rh
,-268435455,32);end else if n<25579 then begin printesc(414);
printint(n-25323);printchar(61);
if eqtb[n].hh.rh=-268435455 then print(415)else begin depththreshold:=0;
breadthmax:=1;shownodelist(eqtb[n].hh.rh);end;
end else if n<25631 then{234:}begin if n=25579 then print(416)else if n<
25599 then begin printesc(417);printint(n-25583);
end else if n<25615 then begin printesc(418);printint(n-25599);
end else begin printesc(419);printint(n-25615);end;printchar(61);
printesc(hash[15525+eqtb[n].hh.rh].rh);
end{:234}else{235:}if n<26655 then begin if n<25887 then begin printesc(
420);printint(n-25631);end else if n<26143 then begin printesc(421);
printint(n-25887);end else if n<26399 then begin printesc(422);
printint(n-26143);end else begin printesc(423);printint(n-26399);end;
printchar(61);printint(eqtb[n].hh.rh);end else begin printesc(424);
printint(n-26655);printchar(61);printint(eqtb[n].hh.rh);
end{:235}{:233}else if n<27741 then{242:}begin if n<27229 then
printparam(n-27167)else if n<27485 then begin printesc(488);
printint(n-27229);end else begin printesc(489);printint(n-27485);end;
printchar(61);printint(eqtb[n].int);
end{:242}else if n<=28017 then{251:}begin if n<27762 then
printlengthparam(n-27741)else begin printesc(512);printint(n-27762);end;
printchar(61);printscaled(eqtb[n].int);print(402);
end{:251}else printchar(63);end;
endif('STAT'){:252}{259:}function idlookup(j,l:integer):halfword;
label 40;var h:integer;d:integer;p:halfword;k:halfword;
begin{261:}h:=buffer[j];for k:=j+1 to j+l-1 do begin h:=h+h+buffer[k];
while h>=8501 do h:=h-8501;end{:261};p:=h+514;
while true do begin if hash[p].rh>0 then if(strstart[hash[p].rh+1]-
strstart[hash[p].rh])=l then if streqbuf(hash[p].rh,j)then goto 40;
if hash[p].lh=0 then begin if nonewcontrolsequence then p:=24526 else
{260:}begin if hash[p].rh>0 then begin if hashhigh<hashextra then begin
incr(hashhigh);hash[p].lh:=hashhigh+28017;p:=hashhigh+28017;
end else begin repeat if(hashused=514)then overflow(515,15000+hashextra)
;decr(hashused);until hash[hashused].rh=0;hash[p].lh:=hashused;
p:=hashused;end;end;
begin if poolptr+l>poolsize then overflow(257,poolsize-initpoolptr);end;
d:=(poolptr-strstart[strptr]);
while poolptr>strstart[strptr]do begin decr(poolptr);
strpool[poolptr+l]:=strpool[poolptr];end;
for k:=j to j+l-1 do begin strpool[poolptr]:=buffer[k];incr(poolptr);
end;hash[p].rh:=makestring;poolptr:=poolptr+d;
ifdef('STAT')incr(cscount);endif('STAT')end{:260};goto 40;end;
p:=hash[p].lh;end;40:idlookup:=p;end;
{:259}{264:}ifdef('INITEX')procedure primitive(s:strnumber;
c:quarterword;o:halfword);var k:poolpointer;j:smallnumber;l:smallnumber;
begin if s<256 then curval:=s+257 else begin k:=strstart[s];
l:=strstart[s+1]-k;for j:=0 to l-1 do buffer[j]:=strpool[k+j];
curval:=idlookup(0,l);begin decr(strptr);poolptr:=strstart[strptr];end;
hash[curval].rh:=s;end;eqtb[curval].hh.b1:=1;eqtb[curval].hh.b0:=c;
eqtb[curval].hh.rh:=o;end;
endif('INITEX'){:264}{274:}procedure newsavelevel(c:groupcode);
begin if saveptr>maxsavestack then begin maxsavestack:=saveptr;
if maxsavestack>savesize-6 then overflow(554,savesize);end;
savestack[saveptr].hh.b0:=3;savestack[saveptr].hh.b1:=curgroup;
savestack[saveptr].hh.rh:=curboundary;
if curlevel=255 then overflow(555,255);curboundary:=saveptr;
incr(curlevel);incr(saveptr);curgroup:=c;end;
{:274}{275:}procedure eqdestroy(w:memoryword);var q:halfword;
begin case w.hh.b0 of 111,112,113,114:deletetokenref(w.hh.rh);
117:deleteglueref(w.hh.rh);118:begin q:=w.hh.rh;
if q<>-268435455 then freenode(q,mem[q].hh.lh+mem[q].hh.lh+1);end;
119:flushnodelist(w.hh.rh);others:end;end;
{:275}{276:}procedure eqsave(p:halfword;l:quarterword);
begin if saveptr>maxsavestack then begin maxsavestack:=saveptr;
if maxsavestack>savesize-6 then overflow(554,savesize);end;
if l=0 then savestack[saveptr].hh.b0:=1 else begin savestack[saveptr]:=
eqtb[p];incr(saveptr);savestack[saveptr].hh.b0:=0;end;
savestack[saveptr].hh.b1:=l;savestack[saveptr].hh.rh:=p;incr(saveptr);
end;{:276}{277:}procedure eqdefine(p:halfword;t:quarterword;e:halfword);
begin if eqtb[p].hh.b1=curlevel then eqdestroy(eqtb[p])else if curlevel>
1 then eqsave(p,eqtb[p].hh.b1);eqtb[p].hh.b1:=curlevel;eqtb[p].hh.b0:=t;
eqtb[p].hh.rh:=e;end;{:277}{278:}procedure eqworddefine(p:halfword;
w:integer);
begin if xeqlevel[p]<>curlevel then begin eqsave(p,xeqlevel[p]);
xeqlevel[p]:=curlevel;end;eqtb[p].int:=w;end;
{:278}{279:}procedure geqdefine(p:halfword;t:quarterword;e:halfword);
begin eqdestroy(eqtb[p]);eqtb[p].hh.b1:=1;eqtb[p].hh.b0:=t;
eqtb[p].hh.rh:=e;end;procedure geqworddefine(p:halfword;w:integer);
begin eqtb[p].int:=w;xeqlevel[p]:=1;end;
{:279}{280:}procedure saveforafter(t:halfword);
begin if curlevel>1 then begin if saveptr>maxsavestack then begin
maxsavestack:=saveptr;
if maxsavestack>savesize-6 then overflow(554,savesize);end;
savestack[saveptr].hh.b0:=2;savestack[saveptr].hh.b1:=0;
savestack[saveptr].hh.rh:=t;incr(saveptr);end;end;
{:280}{281:}{284:}ifdef('STAT')procedure restoretrace(p:halfword;
s:strnumber);begin begindiagnostic;printchar(123);print(s);
printchar(32);showeqtb(p);printchar(125);enddiagnostic(false);end;
endif('STAT'){:284}procedure backinput;forward;procedure unsave;
label 30;var p:halfword;l:quarterword;t:halfword;
begin if curlevel>1 then begin decr(curlevel);
{282:}while true do begin decr(saveptr);
if savestack[saveptr].hh.b0=3 then goto 30;p:=savestack[saveptr].hh.rh;
if savestack[saveptr].hh.b0=2 then{326:}begin t:=curtok;curtok:=p;
backinput;curtok:=t;
end{:326}else begin if savestack[saveptr].hh.b0=0 then begin l:=
savestack[saveptr].hh.b1;decr(saveptr);
end else savestack[saveptr]:=eqtb[24526];
{283:}if(p<27167)or(p>28017)then if eqtb[p].hh.b1=1 then begin eqdestroy
(savestack[saveptr]);
ifdef('STAT')if eqtb[27204].int>0 then restoretrace(p,557);
endif('STAT')end else begin eqdestroy(eqtb[p]);
eqtb[p]:=savestack[saveptr];
ifdef('STAT')if eqtb[27204].int>0 then restoretrace(p,558);
endif('STAT')end else if xeqlevel[p]<>1 then begin eqtb[p]:=savestack[
saveptr];xeqlevel[p]:=l;
ifdef('STAT')if eqtb[27204].int>0 then restoretrace(p,558);
endif('STAT')end else begin ifdef('STAT')if eqtb[27204].int>0 then
restoretrace(p,557);endif('STAT')end{:283};end;end;
30:curgroup:=savestack[saveptr].hh.b1;
curboundary:=savestack[saveptr].hh.rh{:282};end else confusion(556);end;
{:281}{288:}procedure preparemag;
begin if(magset>0)and(eqtb[27184].int<>magset)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(560);
end;printint(eqtb[27184].int);print(561);printnl(562);begin helpptr:=2;
helpline[1]:=563;helpline[0]:=564;end;interror(magset);
geqworddefine(27184,magset);end;
if(eqtb[27184].int<=0)or(eqtb[27184].int>32768)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(565);
end;begin helpptr:=1;helpline[0]:=566;end;interror(eqtb[27184].int);
geqworddefine(27184,1000);end;magset:=eqtb[27184].int;end;
{:288}{295:}procedure tokenshow(p:halfword);
begin if p<>-268435455 then showtokenlist(mem[p].hh.rh,-268435455,
10000000);end;{:295}{296:}procedure printmeaning;
begin printcmdchr(curcmd,curchr);
if curcmd>=111 then begin printchar(58);println;tokenshow(curchr);
end else if curcmd=110 then begin printchar(58);println;
tokenshow(curmark[curchr]);end;end;{:296}{299:}procedure showcurcmdchr;
begin begindiagnostic;printnl(123);
if curlist.modefield<>shownmode then begin printmode(curlist.modefield);
print(581);shownmode:=curlist.modefield;end;printcmdchr(curcmd,curchr);
printchar(125);enddiagnostic(false);end;
{:299}{311:}procedure showcontext;label 30;var oldsetting:0..21;
nn:integer;bottomline:boolean;{315:}i:0..bufsize;j:0..bufsize;
l:0..halferrorline;m:integer;n:0..errorline;p:integer;q:integer;
{:315}begin baseptr:=inputptr;inputstack[baseptr]:=curinput;nn:=-1;
bottomline:=false;while true do begin curinput:=inputstack[baseptr];
if(curinput.statefield<>0)then if(curinput.namefield>17)or(baseptr=0)
then bottomline:=true;
if(baseptr=inputptr)or bottomline or(nn<eqtb[27221].int)then{312:}begin
if(baseptr=inputptr)or(curinput.statefield<>0)or(curinput.indexfield<>3)
or(curinput.locfield<>-268435455)then begin tally:=0;
oldsetting:=selector;
if curinput.statefield<>0 then begin{313:}if curinput.namefield<=17 then
if(curinput.namefield=0)then if baseptr=0 then printnl(586)else printnl(
587)else begin printnl(588);
if curinput.namefield=17 then printchar(42)else printint(curinput.
namefield-1);printchar(62);end else begin printnl(589);printint(line);
end;printchar(32){:313};{318:}begin l:=tally;tally:=0;selector:=20;
trickcount:=1000000;end;
if buffer[curinput.limitfield]=eqtb[27215].int then j:=curinput.
limitfield else j:=curinput.limitfield+1;i:=curinput.startfield;
mubyteskeep:=mubytekeep;mubytesstart:=mubytestart;mubytestart:=false;
if j>0 then while i<j do begin if i=curinput.locfield then begin
firstcount:=tally;trickcount:=tally+1+errorline-halferrorline;
if trickcount<errorline then trickcount:=errorline;end;printbuffer(i);
end;mubytekeep:=mubyteskeep;mubytestart:=mubytesstart{:318};
end else begin{314:}case curinput.indexfield of 0:printnl(590);
1,2:printnl(591);
3:if curinput.locfield=-268435455 then printnl(592)else printnl(593);
4:printnl(594);5:begin println;printcs(curinput.namefield);end;
6:printnl(595);7:printnl(596);8:printnl(597);9:printnl(598);
10:printnl(599);11:printnl(600);12:printnl(601);13:printnl(602);
14:printnl(603);15:printnl(604);others:printnl(63)end{:314};
{319:}begin l:=tally;tally:=0;selector:=20;trickcount:=1000000;end;
if curinput.indexfield<5 then showtokenlist(curinput.startfield,curinput
.locfield,100000)else showtokenlist(mem[curinput.startfield].hh.rh,
curinput.locfield,100000){:319};end;selector:=oldsetting;
{317:}if trickcount=1000000 then begin firstcount:=tally;
trickcount:=tally+1+errorline-halferrorline;
if trickcount<errorline then trickcount:=errorline;end;
if tally<trickcount then m:=tally-firstcount else m:=trickcount-
firstcount;if l+firstcount<=halferrorline then begin p:=0;
n:=l+firstcount;end else begin print(275);
p:=l+firstcount-halferrorline+3;n:=halferrorline;end;
for q:=p to firstcount-1 do printchar(trickbuf[q mod errorline]);
println;for q:=1 to n do printchar(32);
if m+n<=errorline then p:=firstcount+m else p:=firstcount+(errorline-n-3
);for q:=firstcount to p-1 do printchar(trickbuf[q mod errorline]);
if m+n>errorline then print(275){:317};incr(nn);end;
end{:312}else if nn=eqtb[27221].int then begin printnl(275);incr(nn);
end;if bottomline then goto 30;decr(baseptr);end;
30:curinput:=inputstack[inputptr];end;
{:311}{323:}procedure begintokenlist(p:halfword;t:quarterword);
begin begin if inputptr>maxinstack then begin maxinstack:=inputptr;
if inputptr=stacksize then overflow(605,stacksize);end;
inputstack[inputptr]:=curinput;incr(inputptr);end;
curinput.statefield:=0;curinput.startfield:=p;curinput.indexfield:=t;
if t>=5 then begin incr(mem[p].hh.lh);
if t=5 then curinput.limitfield:=paramptr else begin curinput.locfield:=
mem[p].hh.rh;if eqtb[27197].int>1 then begin begindiagnostic;
printnl(335);case t of 14:printesc(348);15:printesc(606);
others:printcmdchr(72,t+25052)end;print(569);tokenshow(p);
enddiagnostic(false);end;end;end else curinput.locfield:=p;end;
{:323}{324:}procedure endtokenlist;
begin if curinput.indexfield>=3 then begin if curinput.indexfield<=4
then flushlist(curinput.startfield)else begin deletetokenref(curinput.
startfield);
if curinput.indexfield=5 then while paramptr>curinput.limitfield do
begin decr(paramptr);flushlist(paramstack[paramptr]);end;end;
end else if curinput.indexfield=1 then if alignstate>500000 then
alignstate:=0 else fatalerror(607);begin decr(inputptr);
curinput:=inputstack[inputptr];end;
begin if interrupt<>0 then pauseforinstructions;end;end;
{:324}{325:}procedure backinput;var p:halfword;
begin while(curinput.statefield=0)and(curinput.locfield=-268435455)and(
curinput.indexfield<>2)do endtokenlist;p:=getavail;mem[p].hh.lh:=curtok;
if curtok<768 then if curtok<512 then decr(alignstate)else incr(
alignstate);
begin if inputptr>maxinstack then begin maxinstack:=inputptr;
if inputptr=stacksize then overflow(605,stacksize);end;
inputstack[inputptr]:=curinput;incr(inputptr);end;
curinput.statefield:=0;curinput.startfield:=p;curinput.indexfield:=3;
curinput.locfield:=p;end;{:325}{327:}procedure backerror;
begin OKtointerrupt:=false;backinput;OKtointerrupt:=true;error;end;
procedure inserror;begin OKtointerrupt:=false;backinput;
curinput.indexfield:=4;OKtointerrupt:=true;error;end;
{:327}{328:}procedure beginfilereading;
begin if inopen=maxinopen then overflow(608,maxinopen);
if first=bufsize then overflow(256,bufsize);incr(inopen);
begin if inputptr>maxinstack then begin maxinstack:=inputptr;
if inputptr=stacksize then overflow(605,stacksize);end;
inputstack[inputptr]:=curinput;incr(inputptr);end;
curinput.indexfield:=inopen;sourcefilenamestack[curinput.indexfield]:=0;
fullsourcefilenamestack[curinput.indexfield]:=0;
linestack[curinput.indexfield]:=line;curinput.startfield:=first;
curinput.statefield:=1;curinput.namefield:=0;end;
{:328}{329:}procedure endfilereading;begin first:=curinput.startfield;
line:=linestack[curinput.indexfield];
if curinput.namefield>17 then aclose(inputfile[curinput.indexfield]);
begin decr(inputptr);curinput:=inputstack[inputptr];end;decr(inopen);
end;{:329}{330:}procedure clearforerrorprompt;
begin while(curinput.statefield<>0)and(curinput.namefield=0)and(inputptr
>0)and(curinput.locfield>curinput.limitfield)do endfilereading;println;;
end;{:330}{332:}{1410:}procedure mubyteupdate;var j:poolpointer;
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
{:1410}{:332}{336:}procedure checkoutervalidity;var p:halfword;
q:halfword;begin if scannerstatus<>0 then begin deletionsallowed:=false;
{337:}if curcs<>0 then begin if(curinput.statefield=0)or(curinput.
namefield<1)or(curinput.namefield>17)then begin p:=getavail;
mem[p].hh.lh:=4095+curcs;begintokenlist(p,3);end;curcmd:=10;curchr:=32;
end{:337};if scannerstatus>1 then{338:}begin runaway;
if curcs=0 then begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(616);
end else begin curcs:=0;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(617);
end;end;{339:}p:=getavail;case scannerstatus of 2:begin print(623);
mem[p].hh.lh:=637;end;3:begin print(624);mem[p].hh.lh:=partoken;
longstate:=113;end;4:begin print(625);mem[p].hh.lh:=637;q:=p;
p:=getavail;mem[p].hh.rh:=q;mem[p].hh.lh:=19610;alignstate:=-1000000;
end;5:begin print(626);mem[p].hh.lh:=637;end;end;
begintokenlist(p,4){:339};print(618);sprintcs(warningindex);
begin helpptr:=4;helpline[3]:=619;helpline[2]:=620;helpline[1]:=621;
helpline[0]:=622;end;error;
end{:338}else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(610);
end;printcmdchr(105,curif);print(611);printint(skipline);
begin helpptr:=3;helpline[2]:=612;helpline[1]:=613;helpline[0]:=614;end;
if curcs<>0 then curcs:=0 else helpline[2]:=615;curtok:=19613;inserror;
end;deletionsallowed:=true;end;end;{:336}{340:}procedure firmuptheline;
forward;{:340}{341:}procedure getnext;label 20,25,21,26,40,10;
var k:0..bufsize;t:halfword;i,j:0..bufsize;mubyteincs:boolean;
p:halfword;cat:0..15;c,cc:ASCIIcode;d:2..3;begin 20:curcs:=0;
if curinput.statefield<>0 then{343:}begin 25:if curinput.locfield<=
curinput.limitfield then begin k:=curinput.locfield;
curchr:=readbuffer(k);curinput.locfield:=k;incr(curinput.locfield);
if(mubytetoken>0)then begin curinput.statefield:=1;
curcs:=mubytetoken-4095;goto 40;end;21:curcmd:=eqtb[25631+curchr].hh.rh;
{344:}case curinput.statefield+curcmd of{345:}10,26,42,27,43{:345}:goto
25;
1,17,33:{354:}begin if curinput.locfield>curinput.limitfield then curcs
:=513 else begin 26:mubyteincs:=false;k:=curinput.locfield;
mubyteskeep:=mubytekeep;curchr:=readbuffer(k);
cat:=eqtb[25631+curchr].hh.rh;
if(eqtb[27225].int>0)and(not mubyteincs)and((mubyteskip>0)or(curchr<>
buffer[k]))then mubyteincs:=true;incr(k);
if mubytetoken>0 then begin curinput.statefield:=1;
curcs:=mubytetoken-4095;goto 40;end;
if cat=11 then curinput.statefield:=17 else if cat=10 then curinput.
statefield:=17 else curinput.statefield:=1;
if(cat=11)and(k<=curinput.limitfield)then{356:}begin repeat curchr:=
readbuffer(k);cat:=eqtb[25631+curchr].hh.rh;
if mubytetoken>0 then cat:=0;
if(eqtb[27225].int>0)and(not mubyteincs)and(cat=11)and((mubyteskip>0)or(
curchr<>buffer[k]))then mubyteincs:=true;incr(k);
until(cat<>11)or(k>curinput.limitfield);
{355:}begin if buffer[k]=curchr then if cat=7 then if k<curinput.
limitfield then begin c:=buffer[k+1];if c<128 then begin d:=2;
if(((c>=48)and(c<=57))or((c>=97)and(c<=102)))then if k+2<=curinput.
limitfield then begin cc:=buffer[k+2];
if(((cc>=48)and(cc<=57))or((cc>=97)and(cc<=102)))then incr(d);end;
if d>2 then begin if c<=57 then curchr:=c-48 else curchr:=c-87;
if cc<=57 then curchr:=16*curchr+cc-48 else curchr:=16*curchr+cc-87;
buffer[k-1]:=curchr;
end else if c<64 then buffer[k-1]:=c+64 else buffer[k-1]:=c-64;
curinput.limitfield:=curinput.limitfield-d;first:=first-d;
if eqtb[27225].int>0 then mubytekeep:=k-curinput.locfield;
while k<=curinput.limitfield do begin buffer[k]:=buffer[k+d];incr(k);
end;goto 26;end;end;end{:355};if cat<>11 then begin decr(k);
k:=k-mubyteskip;end;
if k>curinput.locfield+1 then begin if mubyteincs then begin i:=curinput
.locfield;j:=first;mubytekeep:=mubyteskeep;
if j-curinput.locfield+k>maxbufstack then begin maxbufstack:=j-curinput.
locfield+k;if maxbufstack>=bufsize then begin maxbufstack:=bufsize;
overflow(256,bufsize);end;end;
while i<k do begin buffer[j]:=readbuffer(i);incr(i);incr(j);end;
if j=first+1 then curcs:=257+buffer[first]else curcs:=idlookup(first,j-
first);end else curcs:=idlookup(curinput.locfield,k-curinput.locfield);
curinput.locfield:=k;goto 40;end;
end{:356}else{355:}begin if buffer[k]=curchr then if cat=7 then if k<
curinput.limitfield then begin c:=buffer[k+1];if c<128 then begin d:=2;
if(((c>=48)and(c<=57))or((c>=97)and(c<=102)))then if k+2<=curinput.
limitfield then begin cc:=buffer[k+2];
if(((cc>=48)and(cc<=57))or((cc>=97)and(cc<=102)))then incr(d);end;
if d>2 then begin if c<=57 then curchr:=c-48 else curchr:=c-87;
if cc<=57 then curchr:=16*curchr+cc-48 else curchr:=16*curchr+cc-87;
buffer[k-1]:=curchr;
end else if c<64 then buffer[k-1]:=c+64 else buffer[k-1]:=c-64;
curinput.limitfield:=curinput.limitfield-d;first:=first-d;
if eqtb[27225].int>0 then mubytekeep:=k-curinput.locfield;
while k<=curinput.limitfield do begin buffer[k]:=buffer[k+d];incr(k);
end;goto 26;end;end;end{:355};mubytekeep:=mubyteskeep;
curcs:=257+readbuffer(curinput.locfield);incr(curinput.locfield);end;
40:curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;
if curcmd>=113 then checkoutervalidity;
if writenoexpanding then begin p:=mubytecswrite[curcs mod 128];
while p<>-268435455 do if mem[p].hh.lh=curcs then begin curcmd:=0;
curchr:=256;p:=-268435455;end else p:=mem[mem[p].hh.rh].hh.rh;end;
end{:354};14,30,46:{353:}begin curcs:=curchr+1;
curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;
curinput.statefield:=1;if curcmd>=113 then checkoutervalidity;end{:353};
8,24,40:{352:}begin if curchr=buffer[curinput.locfield]then if curinput.
locfield<curinput.limitfield then begin c:=buffer[curinput.locfield+1];
if c<128 then begin curinput.locfield:=curinput.locfield+2;
if(((c>=48)and(c<=57))or((c>=97)and(c<=102)))then if curinput.locfield<=
curinput.limitfield then begin cc:=buffer[curinput.locfield];
if(((cc>=48)and(cc<=57))or((cc>=97)and(cc<=102)))then begin incr(
curinput.locfield);if c<=57 then curchr:=c-48 else curchr:=c-87;
if cc<=57 then curchr:=16*curchr+cc-48 else curchr:=16*curchr+cc-87;
goto 21;end;end;if c<64 then curchr:=c+64 else curchr:=c-64;goto 21;end;
end;curinput.statefield:=1;end{:352};
16,32,48:{346:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(627);
end;begin helpptr:=2;helpline[1]:=628;helpline[0]:=629;end;
deletionsallowed:=false;error;deletionsallowed:=true;goto 20;end{:346};
{347:}11:{349:}begin curinput.statefield:=17;curchr:=32;end{:349};
6:{348:}begin curinput.locfield:=curinput.limitfield+1;curcmd:=10;
curchr:=32;end{:348};
22,15,31,47:{350:}begin curinput.locfield:=curinput.limitfield+1;
goto 25;end{:350};
38:{351:}begin curinput.locfield:=curinput.limitfield+1;curcs:=parloc;
curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;
if curcmd>=113 then checkoutervalidity;end{:351};2:incr(alignstate);
18,34:begin curinput.statefield:=1;incr(alignstate);end;
3:decr(alignstate);19,35:begin curinput.statefield:=1;decr(alignstate);
end;20,21,23,25,28,29,36,37,39,41,44,45:curinput.statefield:=1;
{:347}others:end{:344};end else begin curinput.statefield:=33;
{360:}if curinput.namefield>17 then{362:}begin incr(line);
first:=curinput.startfield;
if not forceeof then begin if inputln(inputfile[curinput.indexfield],
true)then firmuptheline else forceeof:=true;end;
if forceeof then begin printchar(41);decr(openparens);fflush(stdout);
forceeof:=false;endfilereading;checkoutervalidity;goto 20;end;
if(eqtb[27215].int<0)or(eqtb[27215].int>255)then decr(curinput.
limitfield)else buffer[curinput.limitfield]:=eqtb[27215].int;
first:=curinput.limitfield+1;curinput.locfield:=curinput.startfield;
end{:362}else begin if not(curinput.namefield=0)then begin curcmd:=0;
curchr:=0;goto 10;end;if inputptr>0 then begin endfilereading;goto 20;
end;if selector<18 then openlogfile;
if interaction>1 then begin if(eqtb[27215].int<0)or(eqtb[27215].int>255)
then incr(curinput.limitfield);
if curinput.limitfield=curinput.startfield then printnl(630);println;
first:=curinput.startfield;begin;print(42);terminput;end;
curinput.limitfield:=last;
if(eqtb[27215].int<0)or(eqtb[27215].int>255)then decr(curinput.
limitfield)else buffer[curinput.limitfield]:=eqtb[27215].int;
first:=curinput.limitfield+1;curinput.locfield:=curinput.startfield;
end else fatalerror(631);end{:360};
begin if interrupt<>0 then pauseforinstructions;end;goto 25;end;
end{:343}else{357:}if curinput.locfield<>-268435455 then begin t:=mem[
curinput.locfield].hh.lh;
curinput.locfield:=mem[curinput.locfield].hh.rh;
if t>=4095 then begin curcs:=t-4095;curcmd:=eqtb[curcs].hh.b0;
curchr:=eqtb[curcs].hh.rh;
if curcmd>=113 then if curcmd=116 then{358:}begin curcs:=mem[curinput.
locfield].hh.lh-4095;curinput.locfield:=-268435455;
curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;
if curcmd>100 then begin curcmd:=0;curchr:=257;end;
end{:358}else checkoutervalidity;
if writenoexpanding then begin p:=mubytecswrite[curcs mod 128];
while p<>-268435455 do if mem[p].hh.lh=curcs then begin curcmd:=0;
curchr:=256;p:=-268435455;end else p:=mem[mem[p].hh.rh].hh.rh;end;
end else begin curcmd:=t div 256;curchr:=t mod 256;
case curcmd of 1:incr(alignstate);2:decr(alignstate);
5:{359:}begin begintokenlist(paramstack[curinput.limitfield+curchr-1],0)
;goto 20;end{:359};others:end;end;end else begin endtokenlist;goto 20;
end{:357};
{342:}if curcmd<=5 then if curcmd>=4 then if alignstate=0 then{792:}
begin if(scannerstatus=4)or(curalign=-268435455)then fatalerror(607);
curcmd:=mem[curalign+5].hh.lh;mem[curalign+5].hh.lh:=curchr;
if curcmd=63 then begintokenlist(memtop-10,2)else begintokenlist(mem[
curalign+2].int,2);alignstate:=1000000;goto 20;end{:792}{:342};10:end;
{:341}{363:}procedure firmuptheline;var k:0..bufsize;
begin curinput.limitfield:=last;
if eqtb[27195].int>0 then if interaction>1 then begin;println;
k:=curinput.startfield;
while k<curinput.limitfield do begin printbuffer(k)end;
first:=curinput.limitfield;begin;print(632);terminput;end;
if last>first then begin for k:=first to last-1 do buffer[k+curinput.
startfield-first]:=buffer[k];
curinput.limitfield:=curinput.startfield+last-first;end;end;end;
{:363}{365:}procedure gettoken;begin nonewcontrolsequence:=false;
getnext;nonewcontrolsequence:=true;
if curcs=0 then curtok:=(curcmd*256)+curchr else curtok:=4095+curcs;end;
{:365}{369:}{392:}procedure macrocall;label 10,22,30,31,40;
var r:halfword;p:halfword;q:halfword;s:halfword;t:halfword;u,v:halfword;
rbraceptr:halfword;n:smallnumber;unbalance:halfword;m:halfword;
refcount:halfword;savescannerstatus:smallnumber;
savewarningindex:halfword;matchchr:ASCIIcode;
begin savescannerstatus:=scannerstatus;savewarningindex:=warningindex;
warningindex:=curcs;refcount:=curchr;r:=mem[refcount].hh.rh;n:=0;
if eqtb[27197].int>0 then{404:}begin begindiagnostic;println;
printcs(warningindex);tokenshow(refcount);enddiagnostic(false);
end{:404};if mem[r].hh.lh<>3584 then{394:}begin scannerstatus:=3;
unbalance:=0;longstate:=eqtb[curcs].hh.b0;
if longstate>=113 then longstate:=longstate-2;
repeat mem[memtop-3].hh.rh:=-268435455;
if(mem[r].hh.lh>3583)or(mem[r].hh.lh<3328)then s:=-268435455 else begin
matchchr:=mem[r].hh.lh-3328;s:=mem[r].hh.rh;r:=s;p:=memtop-3;m:=0;end;
{395:}22:gettoken;
if curtok=mem[r].hh.lh then{397:}begin r:=mem[r].hh.rh;
if(mem[r].hh.lh>=3328)and(mem[r].hh.lh<=3584)then begin if curtok<512
then decr(alignstate);goto 40;end else goto 22;end{:397};
{400:}if s<>r then if s=-268435455 then{401:}begin begin if interaction=
3 then;if filelineerrorstylep then printfileline else printnl(262);
print(665);end;sprintcs(warningindex);print(666);begin helpptr:=4;
helpline[3]:=667;helpline[2]:=668;helpline[1]:=669;helpline[0]:=670;end;
error;goto 10;end{:401}else begin t:=s;repeat begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=mem[t].hh.lh;p:=q;end;incr(m);
u:=mem[t].hh.rh;v:=s;
while true do begin if u=r then if curtok<>mem[v].hh.lh then goto 30
else begin r:=mem[v].hh.rh;goto 22;end;
if mem[u].hh.lh<>mem[v].hh.lh then goto 30;u:=mem[u].hh.rh;
v:=mem[v].hh.rh;end;30:t:=mem[t].hh.rh;until t=r;r:=s;end{:400};
if curtok=partoken then if longstate<>112 then{399:}begin if longstate=
111 then begin runaway;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(660);
end;sprintcs(warningindex);print(661);begin helpptr:=3;helpline[2]:=662;
helpline[1]:=663;helpline[0]:=664;end;backerror;end;
pstack[n]:=mem[memtop-3].hh.rh;alignstate:=alignstate-unbalance;
for m:=0 to n do flushlist(pstack[m]);goto 10;end{:399};
if curtok<768 then if curtok<512 then{402:}begin unbalance:=1;
while true do begin begin begin q:=avail;
if q=-268435455 then q:=getavail else begin avail:=mem[q].hh.rh;
mem[q].hh.rh:=-268435455;ifdef('STAT')incr(dynused);endif('STAT')end;
end;mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;gettoken;
if curtok=partoken then if longstate<>112 then{399:}begin if longstate=
111 then begin runaway;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(660);
end;sprintcs(warningindex);print(661);begin helpptr:=3;helpline[2]:=662;
helpline[1]:=663;helpline[0]:=664;end;backerror;end;
pstack[n]:=mem[memtop-3].hh.rh;alignstate:=alignstate-unbalance;
for m:=0 to n do flushlist(pstack[m]);goto 10;end{:399};
if curtok<768 then if curtok<512 then incr(unbalance)else begin decr(
unbalance);if unbalance=0 then goto 31;end;end;31:rbraceptr:=p;
begin q:=getavail;mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;
end{:402}else{398:}begin backinput;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(652);
end;sprintcs(warningindex);print(653);begin helpptr:=6;helpline[5]:=654;
helpline[4]:=655;helpline[3]:=656;helpline[2]:=657;helpline[1]:=658;
helpline[0]:=659;end;incr(alignstate);longstate:=111;curtok:=partoken;
inserror;goto 22;
end{:398}else{396:}begin if curtok=2592 then if mem[r].hh.lh<=3584 then
if mem[r].hh.lh>=3328 then goto 22;begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=curtok;p:=q;end;end{:396};incr(m);
if mem[r].hh.lh>3584 then goto 22;if mem[r].hh.lh<3328 then goto 22;
40:if s<>-268435455 then{403:}begin if(m=1)and(mem[p].hh.lh<768)and(p<>
memtop-3)then begin mem[rbraceptr].hh.rh:=-268435455;
begin mem[p].hh.rh:=avail;avail:=p;ifdef('STAT')decr(dynused);
endif('STAT')end;p:=mem[memtop-3].hh.rh;pstack[n]:=mem[p].hh.rh;
begin mem[p].hh.rh:=avail;avail:=p;ifdef('STAT')decr(dynused);
endif('STAT')end;end else pstack[n]:=mem[memtop-3].hh.rh;incr(n);
if eqtb[27197].int>0 then begin begindiagnostic;printnl(matchchr);
printint(n);print(671);showtokenlist(pstack[n-1],-268435455,1000);
enddiagnostic(false);end;end{:403}{:395};until mem[r].hh.lh=3584;
end{:394};
{393:}while(curinput.statefield=0)and(curinput.locfield=-268435455)and(
curinput.indexfield<>2)do endtokenlist;begintokenlist(refcount,5);
curinput.namefield:=warningindex;curinput.locfield:=mem[r].hh.rh;
if n>0 then begin if paramptr+n>maxparamstack then begin maxparamstack:=
paramptr+n;if maxparamstack>paramsize then overflow(651,paramsize);end;
for m:=0 to n-1 do paramstack[paramptr+m]:=pstack[m];
paramptr:=paramptr+n;end{:393};10:scannerstatus:=savescannerstatus;
warningindex:=savewarningindex;end;{:392}{382:}procedure insertrelax;
begin curtok:=4095+curcs;backinput;curtok:=19616;backinput;
curinput.indexfield:=4;end;{:382}procedure passtext;forward;
procedure startinput;forward;procedure conditional;forward;
procedure getxtoken;forward;procedure convtoks;forward;
procedure insthetoks;forward;procedure expand;var t:halfword;
p,q,r:halfword;j:0..bufsize;cvbackup:integer;
cvlbackup,radixbackup,cobackup:smallnumber;backupbackup:halfword;
savescannerstatus:smallnumber;begin incr(expanddepthcount);
if expanddepthcount>=expanddepth then overflow(633,expanddepth);
cvbackup:=curval;cvlbackup:=curvallevel;radixbackup:=radix;
cobackup:=curorder;backupbackup:=mem[memtop-13].hh.rh;
if curcmd<111 then{370:}begin if eqtb[27203].int>1 then showcurcmdchr;
case curcmd of 110:{389:}begin if curmark[curchr]<>-268435455 then
begintokenlist(curmark[curchr],14);end{:389};102:{371:}begin gettoken;
t:=curtok;gettoken;if curcmd>100 then expand else backinput;curtok:=t;
backinput;end{:371};103:{372:}begin savescannerstatus:=scannerstatus;
scannerstatus:=0;gettoken;scannerstatus:=savescannerstatus;t:=curtok;
backinput;if t>=4095 then begin p:=getavail;mem[p].hh.lh:=19618;
mem[p].hh.rh:=curinput.locfield;curinput.startfield:=p;
curinput.locfield:=p;end;end{:372};107:{375:}begin r:=getavail;p:=r;
repeat getxtoken;if curcs=0 then begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=curtok;p:=q;end;until curcs<>0;
if(curcmd<>67)or(curchr<>0)then{376:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(640);
end;printesc(517);print(641);begin helpptr:=2;helpline[1]:=642;
helpline[0]:=643;end;backerror;end{:376};{377:}j:=first;p:=mem[r].hh.rh;
while p<>-268435455 do begin if j>=maxbufstack then begin maxbufstack:=j
+1;if maxbufstack=bufsize then overflow(256,bufsize);end;
buffer[j]:=mem[p].hh.lh mod 256;incr(j);p:=mem[p].hh.rh;end;
if j>first+1 then begin nonewcontrolsequence:=false;
curcs:=idlookup(first,j-first);nonewcontrolsequence:=true;
end else if j=first then curcs:=513 else curcs:=257+buffer[first]{:377};
flushlist(r);if eqtb[curcs].hh.b0=101 then begin eqdefine(curcs,0,256);
end;curtok:=curcs+4095;backinput;end{:375};108:convtoks;109:insthetoks;
105:conditional;
106:{513:}if curchr>iflimit then if iflimit=1 then insertrelax else
begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(791);
end;printcmdchr(106,curchr);begin helpptr:=1;helpline[0]:=792;end;error;
end else begin while curchr<>2 do passtext;{499:}begin p:=condptr;
ifline:=mem[p+1].int;curif:=mem[p].hh.b1;iflimit:=mem[p].hh.b0;
condptr:=mem[p].hh.rh;freenode(p,2);end{:499};end{:513};
104:{381:}if curchr>0 then forceeof:=true else if nameinprogress then
insertrelax else startinput{:381};
others:{373:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(634);
end;begin helpptr:=5;helpline[4]:=635;helpline[3]:=636;helpline[2]:=637;
helpline[1]:=638;helpline[0]:=639;end;error;end{:373}end;
end{:370}else if curcmd<115 then macrocall else{378:}begin curtok:=19615
;backinput;end{:378};curval:=cvbackup;curvallevel:=cvlbackup;
radix:=radixbackup;curorder:=cobackup;
mem[memtop-13].hh.rh:=backupbackup;decr(expanddepthcount);end;
{:369}{383:}procedure getxtoken;label 20,30;begin 20:getnext;
if curcmd<=100 then goto 30;
if curcmd>=111 then if curcmd<115 then macrocall else begin curcs:=15520
;curcmd:=9;goto 30;end else expand;goto 20;
30:if curcs=0 then curtok:=(curcmd*256)+curchr else curtok:=4095+curcs;
end;{:383}{384:}procedure xtoken;begin while curcmd>100 do begin expand;
getnext;end;
if curcs=0 then curtok:=(curcmd*256)+curchr else curtok:=4095+curcs;end;
{:384}{406:}procedure scanleftbrace;begin{407:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:407};
if curcmd<>1 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(672);
end;begin helpptr:=4;helpline[3]:=673;helpline[2]:=674;helpline[1]:=675;
helpline[0]:=676;end;backerror;curtok:=379;curcmd:=1;curchr:=123;
incr(alignstate);end;end;{:406}{408:}procedure scanoptionalequals;
begin{409:}repeat getxtoken;until curcmd<>10{:409};
if curtok<>3133 then backinput;end;
{:408}{410:}function scankeyword(s:strnumber):boolean;label 10;
var p:halfword;q:halfword;k:poolpointer;begin p:=memtop-13;
mem[p].hh.rh:=-268435455;k:=strstart[s];
while k<strstart[s+1]do begin getxtoken;
if(curcs=0)and((curchr=strpool[k])or(curchr=strpool[k]-32))then begin
begin q:=getavail;mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;incr(k);
end else if(curcmd<>10)or(p<>memtop-13)then begin backinput;
if p<>memtop-13 then begintokenlist(mem[memtop-13].hh.rh,3);
scankeyword:=false;goto 10;end;end;flushlist(mem[memtop-13].hh.rh);
scankeyword:=true;10:end;{:410}{411:}procedure muerror;
begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(677);
end;begin helpptr:=1;helpline[0]:=678;end;error;end;
{:411}{412:}procedure scanint;forward;{436:}procedure scaneightbitint;
begin scanint;
if(curval<0)or(curval>255)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(702);
end;begin helpptr:=2;helpline[1]:=703;helpline[0]:=704;end;
interror(curval);curval:=0;end;end;{:436}{437:}procedure scancharnum;
begin scanint;
if(curval<0)or(curval>255)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(705);
end;begin helpptr:=2;helpline[1]:=706;helpline[0]:=704;end;
interror(curval);curval:=0;end;end;{:437}{438:}procedure scanfourbitint;
begin scanint;
if(curval<0)or(curval>15)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(707);
end;begin helpptr:=2;helpline[1]:=708;helpline[0]:=704;end;
interror(curval);curval:=0;end;end;
{:438}{439:}procedure scanfifteenbitint;begin scanint;
if(curval<0)or(curval>32767)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(709);
end;begin helpptr:=2;helpline[1]:=710;helpline[0]:=704;end;
interror(curval);curval:=0;end;end;
{:439}{440:}procedure scantwentysevenbitint;begin scanint;
if(curval<0)or(curval>134217727)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(711);
end;begin helpptr:=2;helpline[1]:=712;helpline[0]:=704;end;
interror(curval);curval:=0;end;end;
{:440}{1388:}procedure scanfourbitintor18;begin scanint;
if(curval<0)or((curval>15)and(curval<>18))then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(707);
end;begin helpptr:=2;helpline[1]:=708;helpline[0]:=704;end;
interror(curval);curval:=0;end;end;{:1388}{580:}procedure scanfontident;
var f:internalfontnumber;m:halfword;begin{409:}repeat getxtoken;
until curcmd<>10{:409};
if curcmd=88 then f:=eqtb[25579].hh.rh else if curcmd=87 then f:=curchr
else if curcmd=86 then begin m:=curchr;scanfourbitint;
f:=eqtb[m+curval].hh.rh;end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(831);
end;begin helpptr:=2;helpline[1]:=832;helpline[0]:=833;end;backerror;
f:=0;end;curval:=f;end;
{:580}{581:}procedure findfontdimen(writing:boolean);
var f:internalfontnumber;n:integer;begin scanint;n:=curval;
scanfontident;f:=curval;
if n<=0 then curval:=fmemptr else begin if writing and(n<=4)and(n>=2)and
(fontglue[f]<>-268435455)then begin deleteglueref(fontglue[f]);
fontglue[f]:=-268435455;end;
if n>fontparams[f]then if f<fontptr then curval:=fmemptr else{583:}begin
repeat if fmemptr=fontmemsize then overflow(838,fontmemsize);
fontinfo[fmemptr].int:=0;incr(fmemptr);incr(fontparams[f]);
until n=fontparams[f];curval:=fmemptr-1;
end{:583}else curval:=n+parambase[f];end;
{582:}if curval=fmemptr then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(816);
end;printesc(hash[15525+f].rh);print(834);printint(fontparams[f]);
print(835);begin helpptr:=2;helpline[1]:=836;helpline[0]:=837;end;error;
end{:582};end;
{:581}{:412}{416:}procedure scansomethinginternal(level:smallnumber;
negative:boolean);var m:halfword;p:0..nestsize;begin m:=curchr;
case curcmd of 85:{417:}begin scancharnum;
if m=25580 then begin curval:=xord[curval];curvallevel:=0;
end else if m=25581 then begin curval:=xchr[curval];curvallevel:=0;
end else if m=25582 then begin curval:=xprn[curval];curvallevel:=0;
end else if m=26655 then begin curval:=eqtb[26655+curval].hh.rh;
curvallevel:=0;
end else if m<26655 then begin curval:=eqtb[m+curval].hh.rh;
curvallevel:=0;end else begin curval:=eqtb[m+curval].int;curvallevel:=0;
end;end{:417};
71,72,86,87,88:{418:}if level<>5 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(679);
end;begin helpptr:=3;helpline[2]:=680;helpline[1]:=681;helpline[0]:=682;
end;backerror;begin curval:=0;curvallevel:=1;end;
end else if curcmd<=72 then begin if curcmd<72 then begin
scaneightbitint;m:=25067+curval;end;begin curval:=eqtb[m].hh.rh;
curvallevel:=5;end;end else begin backinput;scanfontident;
begin curval:=15525+curval;curvallevel:=4;end;end{:418};
73:begin curval:=eqtb[m].int;curvallevel:=0;end;
74:begin curval:=eqtb[m].int;curvallevel:=1;end;
75:begin curval:=eqtb[m].hh.rh;curvallevel:=2;end;
76:begin curval:=eqtb[m].hh.rh;curvallevel:=3;end;
79:{421:}if abs(curlist.modefield)<>m then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(262);
print(695);end;printcmdchr(79,m);begin helpptr:=4;helpline[3]:=696;
helpline[2]:=697;helpline[1]:=698;helpline[0]:=699;end;error;
if level<>5 then begin curval:=0;curvallevel:=1;
end else begin curval:=0;curvallevel:=0;end;
end else if m=1 then begin curval:=curlist.auxfield.int;curvallevel:=1;
end else begin curval:=curlist.auxfield.hh.lh;curvallevel:=0;end{:421};
80:{425:}if curlist.modefield=0 then begin curval:=0;curvallevel:=0;
end else begin nest[nestptr]:=curlist;p:=nestptr;
while abs(nest[p].modefield)<>1 do decr(p);
begin curval:=nest[p].pgfield;curvallevel:=0;end;end{:425};
82:{422:}begin if m=0 then curval:=deadcycles else curval:=
insertpenalties;curvallevel:=0;end{:422};
81:{424:}begin if(pagecontents=0)and(not outputactive)then if m=0 then
curval:=1073741823 else curval:=0 else curval:=pagesofar[m];
curvallevel:=1;end{:424};
84:{426:}begin if eqtb[25057].hh.rh=-268435455 then curval:=0 else
curval:=mem[eqtb[25057].hh.rh].hh.lh;curvallevel:=0;end{:426};
83:{423:}begin scaneightbitint;
if eqtb[25323+curval].hh.rh=-268435455 then curval:=0 else curval:=mem[
eqtb[25323+curval].hh.rh+m].int;curvallevel:=1;end{:423};
68,69:begin curval:=curchr;curvallevel:=0;end;
77:{428:}begin findfontdimen(false);fontinfo[fmemptr].int:=0;
begin curval:=fontinfo[curval].int;curvallevel:=1;end;end{:428};
78:{429:}begin scanfontident;
if m=0 then begin curval:=hyphenchar[curval];curvallevel:=0;
end else begin curval:=skewchar[curval];curvallevel:=0;end;end{:429};
89:{430:}begin scaneightbitint;
case m of 0:curval:=eqtb[27229+curval].int;
1:curval:=eqtb[27762+curval].int;2:curval:=eqtb[24545+curval].hh.rh;
3:curval:=eqtb[24801+curval].hh.rh;end;curvallevel:=m;end{:430};
70:{427:}if curchr>2 then begin if curchr=3 then curval:=line else
curval:=lastbadness;curvallevel:=0;
end else begin if curchr=2 then curval:=membot else curval:=0;
curvallevel:=curchr;
if not(curlist.tailfield>=himemmin)and(curlist.modefield<>0)then case
curchr of 0:if mem[curlist.tailfield].hh.b0=12 then curval:=mem[curlist.
tailfield+1].int;
1:if mem[curlist.tailfield].hh.b0=11 then curval:=mem[curlist.tailfield
+1].int;
2:if mem[curlist.tailfield].hh.b0=10 then begin curval:=mem[curlist.
tailfield+1].hh.lh;
if mem[curlist.tailfield].hh.b1=99 then curvallevel:=3;end;
end else if(curlist.modefield=1)and(curlist.tailfield=curlist.headfield)
then case curchr of 0:curval:=lastpenalty;1:curval:=lastkern;
2:if lastglue<>268435455 then curval:=lastglue;end;end{:427};
others:{431:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(700);
end;printcmdchr(curcmd,curchr);print(701);printesc(550);
begin helpptr:=1;helpline[0]:=699;end;error;
if level<>5 then begin curval:=0;curvallevel:=1;
end else begin curval:=0;curvallevel:=0;end;end{:431}end;
while curvallevel>level do{432:}begin if curvallevel=2 then curval:=mem[
curval+1].int else if curvallevel=3 then muerror;decr(curvallevel);
end{:432};
{433:}if negative then if curvallevel>=2 then begin curval:=newspec(
curval);{434:}begin mem[curval+1].int:=-mem[curval+1].int;
mem[curval+2].int:=-mem[curval+2].int;
mem[curval+3].int:=-mem[curval+3].int;end{:434};
end else curval:=-curval else if(curvallevel>=2)and(curvallevel<=3)then
incr(mem[curval].hh.rh){:433};end;{:416}{443:}procedure scanint;
label 30;var negative:boolean;m:integer;d:smallnumber;vacuous:boolean;
OKsofar:boolean;begin radix:=0;OKsofar:=true;{444:}negative:=false;
repeat{409:}repeat getxtoken;until curcmd<>10{:409};
if curtok=3117 then begin negative:=not negative;curtok:=3115;end;
until curtok<>3115{:444};if curtok=3168 then{445:}begin gettoken;
if curtok<4095 then begin curval:=curchr;
if curcmd<=2 then if curcmd=2 then incr(alignstate)else decr(alignstate)
;end else if curtok<4352 then curval:=curtok-4096 else curval:=curtok
-4352;if curval>255 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(713);
end;begin helpptr:=2;helpline[1]:=714;helpline[0]:=715;end;curval:=48;
backerror;end else{446:}begin getxtoken;if curcmd<>10 then backinput;
end{:446};
end{:445}else if(curcmd>=68)and(curcmd<=89)then scansomethinginternal(0,
false)else{447:}begin radix:=10;m:=214748364;
if curtok=3111 then begin radix:=8;m:=268435456;getxtoken;
end else if curtok=3106 then begin radix:=16;m:=134217728;getxtoken;end;
vacuous:=true;curval:=0;
{448:}while true do begin if(curtok<3120+radix)and(curtok>=3120)and(
curtok<=3129)then d:=curtok-3120 else if radix=16 then if(curtok<=2886)
and(curtok>=2881)then d:=curtok-2871 else if(curtok<=3142)and(curtok>=
3137)then d:=curtok-3127 else goto 30 else goto 30;vacuous:=false;
if(curval>=m)and((curval>m)or(d>7)or(radix<>10))then begin if OKsofar
then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(716);
end;begin helpptr:=2;helpline[1]:=717;helpline[0]:=718;end;error;
curval:=2147483647;OKsofar:=false;end;end else curval:=curval*radix+d;
getxtoken;end;30:{:448};
if vacuous then{449:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(679);
end;begin helpptr:=3;helpline[2]:=680;helpline[1]:=681;helpline[0]:=682;
end;backerror;end{:449}else if curcmd<>10 then backinput;end{:447};
if negative then curval:=-curval;end;
{:443}{451:}procedure scandimen(mu,inf,shortcut:boolean);
label 30,31,32,40,45,88,89;var negative:boolean;f:integer;
{453:}num,denom:1..65536;k,kk:smallnumber;p,q:halfword;v:scaled;
savecurval:integer;{:453}begin f:=0;aritherror:=false;curorder:=0;
negative:=false;if not shortcut then begin{444:}negative:=false;
repeat{409:}repeat getxtoken;until curcmd<>10{:409};
if curtok=3117 then begin negative:=not negative;curtok:=3115;end;
until curtok<>3115{:444};
if(curcmd>=68)and(curcmd<=89)then{452:}if mu then begin
scansomethinginternal(3,false);
{454:}if curvallevel>=2 then begin v:=mem[curval+1].int;
deleteglueref(curval);curval:=v;end{:454};if curvallevel=3 then goto 89;
if curvallevel<>0 then muerror;
end else begin scansomethinginternal(1,false);
if curvallevel=1 then goto 89;end{:452}else begin backinput;
if curtok=3116 then curtok:=3118;
if curtok<>3118 then scanint else begin radix:=10;curval:=0;end;
if curtok=3116 then curtok:=3118;
if(radix=10)and(curtok=3118)then{455:}begin k:=0;p:=-268435455;gettoken;
while true do begin getxtoken;
if(curtok>3129)or(curtok<3120)then goto 31;
if k<17 then begin q:=getavail;mem[q].hh.rh:=p;
mem[q].hh.lh:=curtok-3120;p:=q;incr(k);end;end;
31:for kk:=k downto 1 do begin dig[kk-1]:=mem[p].hh.lh;q:=p;
p:=mem[p].hh.rh;begin mem[q].hh.rh:=avail;avail:=q;
ifdef('STAT')decr(dynused);endif('STAT')end;end;f:=rounddecimals(k);
if curcmd<>10 then backinput;end{:455};end;end;
if curval<0 then begin negative:=not negative;curval:=-curval;end;
{456:}if inf then{457:}if scankeyword(309)then begin curorder:=1;
while scankeyword(108)do begin if curorder=3 then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(720);
end;print(721);begin helpptr:=1;helpline[0]:=722;end;error;
end else incr(curorder);end;goto 88;end{:457};{458:}savecurval:=curval;
{409:}repeat getxtoken;until curcmd<>10{:409};
if(curcmd<68)or(curcmd>89)then backinput else begin if mu then begin
scansomethinginternal(3,false);
{454:}if curvallevel>=2 then begin v:=mem[curval+1].int;
deleteglueref(curval);curval:=v;end{:454};
if curvallevel<>3 then muerror;end else scansomethinginternal(1,false);
v:=curval;goto 40;end;if mu then goto 45;
if scankeyword(723)then v:=({561:}fontinfo[6+parambase[eqtb[25579].hh.rh
]].int{:561})else if scankeyword(724)then v:=({562:}fontinfo[5+parambase
[eqtb[25579].hh.rh]].int{:562})else goto 45;{446:}begin getxtoken;
if curcmd<>10 then backinput;end{:446};
40:curval:=multandadd(savecurval,v,xnoverd(v,f,65536),1073741823);
goto 89;45:{:458};
if mu then{459:}if scankeyword(334)then goto 88 else begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(720);
end;print(725);begin helpptr:=4;helpline[3]:=726;helpline[2]:=727;
helpline[1]:=728;helpline[0]:=729;end;error;goto 88;end{:459};
if scankeyword(719)then{460:}begin preparemag;
if eqtb[27184].int<>1000 then begin curval:=xnoverd(curval,1000,eqtb[
27184].int);f:=(1000*f+65536*texremainder)div eqtb[27184].int;
curval:=curval+(f div 65536);f:=f mod 65536;end;end{:460};
if scankeyword(402)then goto 88;
{461:}if scankeyword(730)then begin num:=7227;denom:=100;
end else if scankeyword(731)then begin num:=12;denom:=1;
end else if scankeyword(732)then begin num:=7227;denom:=254;
end else if scankeyword(733)then begin num:=7227;denom:=2540;
end else if scankeyword(734)then begin num:=7227;denom:=7200;
end else if scankeyword(735)then begin num:=1238;denom:=1157;
end else if scankeyword(736)then begin num:=14856;denom:=1157;
end else if scankeyword(737)then goto 30 else{462:}begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(720);
end;print(738);begin helpptr:=6;helpline[5]:=739;helpline[4]:=740;
helpline[3]:=741;helpline[2]:=727;helpline[1]:=728;helpline[0]:=729;end;
error;goto 32;end{:462};curval:=xnoverd(curval,num,denom);
f:=(num*f+65536*texremainder)div denom;curval:=curval+(f div 65536);
f:=f mod 65536;32:{:461};
88:if curval>=16384 then aritherror:=true else curval:=curval*65536+f;
30:{:456};{446:}begin getxtoken;if curcmd<>10 then backinput;end{:446};
89:if aritherror or(abs(curval)>=1073741824)then{463:}begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(742);
end;begin helpptr:=2;helpline[1]:=743;helpline[0]:=744;end;error;
curval:=1073741823;aritherror:=false;end{:463};
if negative then curval:=-curval;end;
{:451}{464:}procedure scanglue(level:smallnumber);label 10;
var negative:boolean;q:halfword;mu:boolean;begin mu:=(level=3);
{444:}negative:=false;repeat{409:}repeat getxtoken;
until curcmd<>10{:409};if curtok=3117 then begin negative:=not negative;
curtok:=3115;end;until curtok<>3115{:444};
if(curcmd>=68)and(curcmd<=89)then begin scansomethinginternal(level,
negative);
if curvallevel>=2 then begin if curvallevel<>level then muerror;goto 10;
end;if curvallevel=0 then scandimen(mu,false,true)else if level=3 then
muerror;end else begin backinput;scandimen(mu,false,false);
if negative then curval:=-curval;end;{465:}q:=newspec(membot);
mem[q+1].int:=curval;
if scankeyword(745)then begin scandimen(mu,true,false);
mem[q+2].int:=curval;mem[q].hh.b0:=curorder;end;
if scankeyword(746)then begin scandimen(mu,true,false);
mem[q+3].int:=curval;mem[q].hh.b1:=curorder;end;curval:=q{:465};10:end;
{:464}{466:}function scanrulespec:halfword;label 21;var q:halfword;
begin q:=newrule;
if curcmd=35 then mem[q+1].int:=26214 else begin mem[q+3].int:=26214;
mem[q+2].int:=0;end;
21:if scankeyword(747)then begin scandimen(false,false,false);
mem[q+1].int:=curval;goto 21;end;
if scankeyword(748)then begin scandimen(false,false,false);
mem[q+3].int:=curval;goto 21;end;
if scankeyword(749)then begin scandimen(false,false,false);
mem[q+2].int:=curval;goto 21;end;scanrulespec:=q;end;
{:466}{467:}function strtoks(b:poolpointer):halfword;var p:halfword;
q:halfword;t:halfword;k:poolpointer;
begin begin if poolptr+1>poolsize then overflow(257,poolsize-initpoolptr
);end;p:=memtop-3;mem[p].hh.rh:=-268435455;k:=b;
while k<poolptr do begin t:=strpool[k];
if t=32 then t:=2592 else t:=3072+t;begin begin q:=avail;
if q=-268435455 then q:=getavail else begin avail:=mem[q].hh.rh;
mem[q].hh.rh:=-268435455;ifdef('STAT')incr(dynused);endif('STAT')end;
end;mem[p].hh.rh:=q;mem[q].hh.lh:=t;p:=q;end;incr(k);end;poolptr:=b;
strtoks:=p;end;{:467}{468:}function thetoks:halfword;
var oldsetting:0..21;p,q,r:halfword;b:poolpointer;begin getxtoken;
scansomethinginternal(5,false);
if curvallevel>=4 then{469:}begin p:=memtop-3;mem[p].hh.rh:=-268435455;
if curvallevel=4 then begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=4095+curval;p:=q;
end else if curval<>-268435455 then begin r:=mem[curval].hh.rh;
while r<>-268435455 do begin begin begin q:=avail;
if q=-268435455 then q:=getavail else begin avail:=mem[q].hh.rh;
mem[q].hh.rh:=-268435455;ifdef('STAT')incr(dynused);endif('STAT')end;
end;mem[p].hh.rh:=q;mem[q].hh.lh:=mem[r].hh.lh;p:=q;end;r:=mem[r].hh.rh;
end;end;thetoks:=p;end{:469}else begin oldsetting:=selector;
selector:=21;b:=poolptr;case curvallevel of 0:printint(curval);
1:begin printscaled(curval);print(402);end;
2:begin printspec(curval,402);deleteglueref(curval);end;
3:begin printspec(curval,334);deleteglueref(curval);end;end;
selector:=oldsetting;thetoks:=strtoks(b);end;end;
{:468}{470:}procedure insthetoks;begin mem[memtop-12].hh.rh:=thetoks;
begintokenlist(mem[memtop-3].hh.rh,4);end;
{:470}{473:}procedure convtoks;var oldsetting:0..21;c:0..5;
savescannerstatus:smallnumber;b:poolpointer;begin c:=curchr;
{474:}case c of 0,1:scanint;2,3:begin savescannerstatus:=scannerstatus;
scannerstatus:=0;gettoken;scannerstatus:=savescannerstatus;end;
4:scanfontident;5:if jobname=0 then openlogfile;end{:474};
oldsetting:=selector;selector:=21;b:=poolptr;
{475:}case c of 0:printint(curval);1:printromanint(curval);
2:if curcs<>0 then sprintcs(curcs)else printchar(curchr);3:printmeaning;
4:begin print(fontname[curval]);
if fontsize[curval]<>fontdsize[curval]then begin print(756);
printscaled(fontsize[curval]);print(402);end;end;5:print(jobname);
end{:475};selector:=oldsetting;mem[memtop-12].hh.rh:=strtoks(b);
begintokenlist(mem[memtop-3].hh.rh,4);end;
{:473}{476:}function scantoks(macrodef,xpand:boolean):halfword;
label 40,30,31,32;var t:halfword;s:halfword;p:halfword;q:halfword;
unbalance:halfword;hashbrace:halfword;
begin if macrodef then scannerstatus:=2 else scannerstatus:=5;
warningindex:=curcs;defref:=getavail;mem[defref].hh.lh:=-268435455;
p:=defref;hashbrace:=0;t:=3120;
if macrodef then{477:}begin while true do begin gettoken;
if curtok<768 then goto 31;if curcmd=6 then{479:}begin s:=3328+curchr;
gettoken;if curcmd=1 then begin hashbrace:=curtok;begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=3584;p:=q;end;goto 30;end;
if t=3129 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(759);
end;begin helpptr:=1;helpline[0]:=760;end;error;end else begin incr(t);
if curtok<>t then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(761);
end;begin helpptr:=2;helpline[1]:=762;helpline[0]:=763;end;backerror;
end;curtok:=s;end;end{:479};begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=curtok;p:=q;end;end;31:begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=3584;p:=q;end;
if curcmd=2 then{478:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(672);
end;incr(alignstate);begin helpptr:=2;helpline[1]:=757;helpline[0]:=758;
end;error;goto 40;end{:478};30:end{:477}else scanleftbrace;
{480:}unbalance:=1;
while true do begin if xpand then{481:}begin while true do begin getnext
;if curcmd<=100 then goto 32;
if curcmd<>109 then expand else begin q:=thetoks;
if mem[memtop-3].hh.rh<>-268435455 then begin mem[p].hh.rh:=mem[memtop-3
].hh.rh;p:=q;end;end;end;32:xtoken end{:481}else gettoken;
if curtok<768 then if curcmd<2 then incr(unbalance)else begin decr(
unbalance);if unbalance=0 then goto 40;
end else if curcmd=6 then if macrodef then{482:}begin s:=curtok;
if xpand then getxtoken else gettoken;
if curcmd<>6 then if(curtok<=3120)or(curtok>t)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(764);
end;sprintcs(warningindex);begin helpptr:=3;helpline[2]:=765;
helpline[1]:=766;helpline[0]:=767;end;backerror;curtok:=s;
end else curtok:=1232+curchr;end{:482};begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=curtok;p:=q;end;end{:480};
40:scannerstatus:=0;if hashbrace<>0 then begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=hashbrace;p:=q;end;scantoks:=p;end;
{:476}{485:}procedure readtoks(n:integer;r:halfword);label 30;
var p:halfword;q:halfword;s:integer;m:smallnumber;
begin scannerstatus:=2;warningindex:=r;defref:=getavail;
mem[defref].hh.lh:=-268435455;p:=defref;begin q:=getavail;
mem[p].hh.rh:=q;mem[q].hh.lh:=3584;p:=q;end;
if(n<0)or(n>15)then m:=16 else m:=n;s:=alignstate;alignstate:=1000000;
repeat{486:}beginfilereading;curinput.namefield:=m+1;
if readopen[m]=2 then{487:}if interaction>1 then if n<0 then begin;
print(335);terminput;end else begin;println;sprintcs(r);begin;print(61);
terminput;end;n:=-1;
end else fatalerror(768){:487}else if readopen[m]=1 then{488:}if inputln
(readfile[m],false)then readopen[m]:=0 else begin aclose(readfile[m]);
readopen[m]:=2;
end{:488}else{489:}begin if not inputln(readfile[m],true)then begin
aclose(readfile[m]);readopen[m]:=2;
if alignstate<>1000000 then begin runaway;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(769);
end;printesc(547);begin helpptr:=1;helpline[0]:=770;end;
alignstate:=1000000;error;end;end;end{:489};curinput.limitfield:=last;
if(eqtb[27215].int<0)or(eqtb[27215].int>255)then decr(curinput.
limitfield)else buffer[curinput.limitfield]:=eqtb[27215].int;
first:=curinput.limitfield+1;curinput.locfield:=curinput.startfield;
curinput.statefield:=33;while true do begin gettoken;
if curtok=0 then goto 30;
if alignstate<1000000 then begin repeat gettoken;until curtok=0;
alignstate:=1000000;goto 30;end;begin q:=getavail;mem[p].hh.rh:=q;
mem[q].hh.lh:=curtok;p:=q;end;end;30:endfilereading{:486};
until alignstate=1000000;curval:=defref;scannerstatus:=0;alignstate:=s;
end;{:485}{497:}procedure passtext;label 30;var l:integer;
savescannerstatus:smallnumber;begin savescannerstatus:=scannerstatus;
scannerstatus:=1;l:=0;skipline:=line;while true do begin getnext;
if curcmd=106 then begin if l=0 then goto 30;if curchr=2 then decr(l);
end else if curcmd=105 then incr(l);end;
30:scannerstatus:=savescannerstatus;end;
{:497}{500:}procedure changeiflimit(l:smallnumber;p:halfword);label 10;
var q:halfword;begin if p=condptr then iflimit:=l else begin q:=condptr;
while true do begin if q=-268435455 then confusion(771);
if mem[q].hh.rh=p then begin mem[q].hh.b0:=l;goto 10;end;
q:=mem[q].hh.rh;end;end;10:end;{:500}{501:}procedure conditional;
label 10,50;var b:boolean;r:60..62;m,n:integer;p,q:halfword;
savescannerstatus:smallnumber;savecondptr:halfword;thisif:smallnumber;
begin{498:}begin p:=getnode(2);mem[p].hh.rh:=condptr;
mem[p].hh.b0:=iflimit;mem[p].hh.b1:=curif;mem[p+1].int:=ifline;
condptr:=p;curif:=curchr;iflimit:=1;ifline:=line;end{:498};
savecondptr:=condptr;thisif:=curchr;
{504:}case thisif of 0,1:{509:}begin begin getxtoken;
if curcmd=0 then if curchr=257 then begin curcmd:=13;
curchr:=curtok-4096;end;end;if(curcmd>13)or(curchr>255)then begin m:=0;
n:=256;end else begin m:=curcmd;n:=curchr;end;begin getxtoken;
if curcmd=0 then if curchr=257 then begin curcmd:=13;
curchr:=curtok-4096;end;end;
if(curcmd>13)or(curchr>255)then begin curcmd:=0;curchr:=256;end;
if thisif=0 then b:=(n=curchr)else b:=(m=curcmd);end{:509};
2,3:{506:}begin if thisif=2 then scanint else scandimen(false,false,
false);n:=curval;{409:}repeat getxtoken;until curcmd<>10{:409};
if(curtok>=3132)and(curtok<=3134)then r:=curtok-3072 else begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(795);
end;printcmdchr(105,thisif);begin helpptr:=1;helpline[0]:=796;end;
backerror;r:=61;end;
if thisif=2 then scanint else scandimen(false,false,false);
case r of 60:b:=(n<curval);61:b:=(n=curval);62:b:=(n>curval);end;
end{:506};4:{507:}begin scanint;b:=odd(curval);end{:507};
5:b:=(abs(curlist.modefield)=1);6:b:=(abs(curlist.modefield)=102);
7:b:=(abs(curlist.modefield)=203);8:b:=(curlist.modefield<0);
9,10,11:{508:}begin scaneightbitint;p:=eqtb[25323+curval].hh.rh;
if thisif=9 then b:=(p=-268435455)else if p=-268435455 then b:=false
else if thisif=10 then b:=(mem[p].hh.b0=0)else b:=(mem[p].hh.b0=1);
end{:508};12:{510:}begin savescannerstatus:=scannerstatus;
scannerstatus:=0;getnext;n:=curcs;p:=curcmd;q:=curchr;getnext;
if curcmd<>p then b:=false else if curcmd<111 then b:=(curchr=q)else
{511:}begin p:=mem[curchr].hh.rh;q:=mem[eqtb[n].hh.rh].hh.rh;
if p=q then b:=true else begin while(p<>-268435455)and(q<>-268435455)do
if mem[p].hh.lh<>mem[q].hh.lh then p:=-268435455 else begin p:=mem[p].hh
.rh;q:=mem[q].hh.rh;end;b:=((p=-268435455)and(q=-268435455));end;
end{:511};scannerstatus:=savescannerstatus;end{:510};
13:begin scanfourbitintor18;
if curval=18 then b:=not shellenabledp else b:=(readopen[curval]=2);end;
14:b:=true;15:b:=false;16:{512:}begin scanint;n:=curval;
if eqtb[27203].int>1 then begin begindiagnostic;print(797);printint(n);
printchar(125);enddiagnostic(false);end;while n<>0 do begin passtext;
if condptr=savecondptr then if curchr=4 then decr(n)else goto 50 else if
curchr=2 then{499:}begin p:=condptr;ifline:=mem[p+1].int;
curif:=mem[p].hh.b1;iflimit:=mem[p].hh.b0;condptr:=mem[p].hh.rh;
freenode(p,2);end{:499};end;changeiflimit(4,savecondptr);goto 10;
end{:512};end{:504};
if eqtb[27203].int>1 then{505:}begin begindiagnostic;
if b then print(793)else print(794);enddiagnostic(false);end{:505};
if b then begin changeiflimit(3,savecondptr);goto 10;end;
{503:}while true do begin passtext;
if condptr=savecondptr then begin if curchr<>4 then goto 50;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(791);
end;printesc(789);begin helpptr:=1;helpline[0]:=792;end;error;
end else if curchr=2 then{499:}begin p:=condptr;ifline:=mem[p+1].int;
curif:=mem[p].hh.b1;iflimit:=mem[p].hh.b0;condptr:=mem[p].hh.rh;
freenode(p,2);end{:499};end{:503};
50:if curchr=2 then{499:}begin p:=condptr;ifline:=mem[p+1].int;
curif:=mem[p].hh.b1;iflimit:=mem[p].hh.b0;condptr:=mem[p].hh.rh;
freenode(p,2);end{:499}else iflimit:=2;10:end;
{:501}{518:}procedure beginname;begin areadelimiter:=0;extdelimiter:=0;
quotedfilename:=false;end;
{:518}{519:}function morename(c:ASCIIcode):boolean;
begin if(c=32)and stopatspace and(not quotedfilename)then morename:=
false else if c=34 then begin quotedfilename:=not quotedfilename;
morename:=true;
end else begin begin if poolptr+1>poolsize then overflow(257,poolsize-
initpoolptr);end;begin strpool[poolptr]:=c;incr(poolptr);end;
if ISDIRSEP(c)then begin areadelimiter:=(poolptr-strstart[strptr]);
extdelimiter:=0;
end else if c=46 then extdelimiter:=(poolptr-strstart[strptr]);
morename:=true;end;end;{:519}{520:}procedure endname;
var tempstr:strnumber;j,s,t:poolpointer;mustquote:boolean;
begin if strptr+3>maxstrings then overflow(258,maxstrings-initstrptr);
begin if poolptr+6>poolsize then overflow(257,poolsize-initpoolptr);end;
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
if areadelimiter=0 then curarea:=335 else begin curarea:=strptr;
strstart[strptr+1]:=strstart[strptr]+areadelimiter;incr(strptr);
tempstr:=searchstring(curarea);if tempstr>0 then begin curarea:=tempstr;
decr(strptr);
for j:=strstart[strptr+1]to poolptr-1 do begin strpool[j-areadelimiter]
:=strpool[j];end;poolptr:=poolptr-areadelimiter;end;end;
if extdelimiter=0 then begin curext:=335;curname:=slowmakestring;
end else begin curname:=strptr;
strstart[strptr+1]:=strstart[strptr]+extdelimiter-areadelimiter-1;
incr(strptr);curext:=makestring;decr(strptr);
tempstr:=searchstring(curname);if tempstr>0 then begin curname:=tempstr;
decr(strptr);
for j:=strstart[strptr+1]to poolptr-1 do begin strpool[j-extdelimiter+
areadelimiter+1]:=strpool[j];end;
poolptr:=poolptr-extdelimiter+areadelimiter+1;end;
curext:=slowmakestring;end;end;
{:520}{522:}procedure packfilename(n,a,e:strnumber);var k:integer;
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
{:522}{526:}procedure packbufferedname(n:smallnumber;a,b:integer);
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
{:526}{528:}function makenamestring:strnumber;var k:1..maxint;
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
{:528}{529:}procedure scanfilename;label 30;begin nameinprogress:=true;
beginname;{409:}repeat getxtoken;until curcmd<>10{:409};
while true do begin if(curcmd>12)or(curchr>255)then begin backinput;
goto 30;end;
if(curchr=32)and(curinput.statefield<>0)and(curinput.locfield>curinput.
limitfield)then goto 30;if not morename(curchr)then goto 30;getxtoken;
end;30:endname;nameinprogress:=false;end;
{:529}{532:}procedure packjobname(s:strnumber);begin curarea:=335;
curext:=s;curname:=jobname;packfilename(curname,curarea,curext);end;
{:532}{533:}procedure promptfilename(s,e:strnumber);label 30;
var k:0..bufsize;savedcurname:strnumber;savedcurext:strnumber;
savedcurarea:strnumber;begin if interaction=2 then;
if s=799 then begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(800);
end else begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(801);
end;printfilename(curname,curarea,curext);print(802);
if(e=803)or(e=335)then showcontext;println;
printcstring(promptfilenamehelpmsg);if(e<>335)then begin print(804);
print(e);print(39);end;print(41);println;printnl(805);print(s);
if interaction<2 then fatalerror(806);savedcurname:=curname;
savedcurext:=curext;savedcurarea:=curarea;;begin;print(581);terminput;
end;{534:}begin beginname;k:=first;
while(buffer[k]=32)and(k<last)do incr(k);
while true do begin if k=last then goto 30;
if not morename(buffer[k])then goto 30;incr(k);end;30:endname;end{:534};
if((strstart[curname+1]-strstart[curname])=0)and(curext=335)and(curarea=
335)then begin curname:=savedcurname;curext:=savedcurext;
curarea:=savedcurarea;end else if curext=335 then curext:=e;
packfilename(curname,curarea,curext);end;
{:533}{537:}procedure openlogfile;var oldsetting:0..21;k:0..bufsize;
l:0..bufsize;months:constcstring;begin oldsetting:=selector;
if jobname=0 then jobname:=getjobname(809);packjobname(810);
recorderchangefilename(stringcast(nameoffile+1));packjobname(811);
while not aopenout(logfile)do{538:}begin selector:=17;
promptfilename(813,811);end{:538};
texmflogname:=amakenamestring(logfile);selector:=18;logopened:=true;
{539:}begin if srcspecialsp or filelineerrorstylep or parsefirstlinep
then write(logfile,'This is TeXk, Version 3.14159265')else write(logfile
,'This is TeX, Version 3.14159265');write(logfile,versionstring);
slowprint(formatident);print(814);printint(eqtb[27188].int);
printchar(32);months:=' JANFEBMARAPRMAYJUNJULAUGSEPOCTNOVDEC';
for k:=3*eqtb[27189].int-2 to 3*eqtb[27189].int do write(logfile,months[
k]);printchar(32);printint(eqtb[27190].int);printchar(32);
printtwo(eqtb[27187].int div 60);printchar(58);
printtwo(eqtb[27187].int mod 60);
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
fputs(translatefilename,logfile);write(logfile,')');end;end{:539};
if mltexenabledp then begin writeln(logfile);
write(logfile,'MLTeX v2.2 enabled');end;
if enctexenabledp then begin writeln(logfile);
write(logfile,' encTeX v. Jun. 2004');
write(logfile,', reencoding enabled');
if translatefilename then begin writeln(logfile);
write(logfile,' (\xordcode, \xchrcode, \xprncode overridden by TCX)');
end;end;inputstack[inputptr]:=curinput;printnl(812);
l:=inputstack[0].limitfield;if buffer[l]=eqtb[27215].int then decr(l);
for k:=1 to l do print(buffer[k]);println;selector:=oldsetting+2;end;
{:537}{540:}procedure startinput;label 30;var tempstr:strnumber;
begin scanfilename;packfilename(curname,curarea,curext);
while true do begin beginfilereading;texinputtype:=1;
if kpseinnameok(stringcast(nameoffile+1))and aopenin(inputfile[curinput.
indexfield],kpsetexformat)then goto 30;endfilereading;
promptfilename(799,335);end;
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
fflush(stdout);curinput.statefield:=33;{541:}begin line:=1;
if inputln(inputfile[curinput.indexfield],false)then;firmuptheline;
if(eqtb[27215].int<0)or(eqtb[27215].int>255)then decr(curinput.
limitfield)else buffer[curinput.limitfield]:=eqtb[27215].int;
first:=curinput.limitfield+1;curinput.locfield:=curinput.startfield;
end{:541};end;{:540}{563:}{1396:}function effectivechar(errp:boolean;
f:internalfontnumber;c:quarterword):integer;label 40;var basec:integer;
result:integer;begin result:=c;if not mltexenabledp then goto 40;
if fontec[f]>=c then if fontbc[f]<=c then if(fontinfo[charbase[f]+c].
qqqq.b0>0)then goto 40;
if c>=eqtb[27222].int then if c<=eqtb[27223].int then if(eqtb[26911+c].
hh.rh>0)then begin basec:=(eqtb[26911+c].hh.rh mod 256);result:=basec;
if not errp then goto 40;
if fontec[f]>=basec then if fontbc[f]<=basec then if(fontinfo[charbase[f
]+basec].qqqq.b0>0)then goto 40;end;if errp then begin begindiagnostic;
printnl(839);print(1343);print(c);print(840);slowprint(fontname[f]);
printchar(33);enddiagnostic(false);result:=fontbc[f];end;
40:effectivechar:=result;end;
{:1396}{1397:}function effectivecharinfo(f:internalfontnumber;
c:quarterword):fourquarters;label 10;var ci:fourquarters;basec:integer;
begin if not mltexenabledp then begin effectivecharinfo:=fontinfo[
charbase[f]+c].qqqq;goto 10;end;
if fontec[f]>=c then if fontbc[f]<=c then begin ci:=fontinfo[charbase[f]
+c].qqqq;if(ci.b0>0)then begin effectivecharinfo:=ci;goto 10;end;end;
if c>=eqtb[27222].int then if c<=eqtb[27223].int then if(eqtb[26911+c].
hh.rh>0)then begin basec:=(eqtb[26911+c].hh.rh mod 256);
if fontec[f]>=basec then if fontbc[f]<=basec then begin ci:=fontinfo[
charbase[f]+basec].qqqq;if(ci.b0>0)then begin effectivecharinfo:=ci;
goto 10;end;end;end;effectivecharinfo:=nullcharacter;10:end;
{:1397}function readfontinfo(u:halfword;nom,aire:strnumber;
s:scaled):internalfontnumber;label 30,11,45;var k:fontindex;
nametoolong:boolean;fileopened:boolean;
lf,lh,bc,ec,nw,nh,nd,ni,nl,nk,ne,np:halfword;f:internalfontnumber;
g:internalfontnumber;a,b,c,d:eightbits;qw:fourquarters;sw:scaled;
bchlabel:integer;bchar:0..256;z:scaled;alpha:integer;beta:1..16;
begin g:=0;{565:}{566:}fileopened:=false;
nametoolong:=((strstart[nom+1]-strstart[nom])>255)or((strstart[aire+1]-
strstart[aire])>255);if nametoolong then goto 11;
packfilename(nom,aire,335);if not bopenin(tfmfile)then goto 11;
fileopened:=true{:566};{568:}begin begin lf:=tfmtemp;
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
if(nw=0)or(nh=0)or(nd=0)or(ni=0)then goto 11;end{:568};
{569:}lf:=lf-6-lh;if np<7 then lf:=lf+7-np;
if(fontptr=fontmax)or(fmemptr+lf>fontmemsize)then{570:}begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(816);
end;sprintcs(u);printchar(61);printfilename(nom,aire,335);
if s>=0 then begin print(756);printscaled(s);print(402);
end else if s<>-1000 then begin print(817);printint(-s);end;print(826);
begin helpptr:=4;helpline[3]:=827;helpline[2]:=828;helpline[1]:=829;
helpline[0]:=830;end;error;goto 30;end{:570};f:=fontptr+1;
charbase[f]:=fmemptr-bc;widthbase[f]:=charbase[f]+ec+1;
heightbase[f]:=widthbase[f]+nw;depthbase[f]:=heightbase[f]+nh;
italicbase[f]:=depthbase[f]+nd;ligkernbase[f]:=italicbase[f]+ni;
kernbase[f]:=ligkernbase[f]+nl-256*(128);
extenbase[f]:=kernbase[f]+256*(128)+nk;
parambase[f]:=extenbase[f]+ne{:569};{571:}begin if lh<2 then goto 11;
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
fontsize[f]:=z;end{:571};
{572:}for k:=fmemptr to widthbase[f]-1 do begin begin tfmtemp:=getc(
tfmfile);a:=tfmtemp;qw.b0:=a;tfmtemp:=getc(tfmfile);b:=tfmtemp;qw.b1:=b;
tfmtemp:=getc(tfmfile);c:=tfmtemp;qw.b2:=c;tfmtemp:=getc(tfmfile);
d:=tfmtemp;qw.b3:=d;fontinfo[k].qqqq:=qw;end;
if(a>=nw)or(b div 16>=nh)or(b mod 16>=nd)or(c div 4>=ni)then goto 11;
case c mod 4 of 1:if d>=nl then goto 11;3:if d>=ne then goto 11;
2:{573:}begin begin if(d<bc)or(d>ec)then goto 11 end;
while d<k+bc-fmemptr do begin qw:=fontinfo[charbase[f]+d].qqqq;
if((qw.b2)mod 4)<>2 then goto 45;d:=qw.b3;end;
if d=k+bc-fmemptr then goto 11;45:end{:573};others:end;end{:572};
{574:}begin{575:}begin alpha:=16;while z>=8388608 do begin z:=z div 2;
alpha:=alpha+alpha;end;beta:=256 div alpha;alpha:=alpha*z;end{:575};
for k:=widthbase[f]to ligkernbase[f]-1 do begin tfmtemp:=getc(tfmfile);
a:=tfmtemp;tfmtemp:=getc(tfmfile);b:=tfmtemp;tfmtemp:=getc(tfmfile);
c:=tfmtemp;tfmtemp:=getc(tfmfile);d:=tfmtemp;
sw:=(((((d*z)div 256)+(c*z))div 256)+(b*z))div beta;
if a=0 then fontinfo[k].int:=sw else if a=255 then fontinfo[k].int:=sw-
alpha else goto 11;end;if fontinfo[widthbase[f]].int<>0 then goto 11;
if fontinfo[heightbase[f]].int<>0 then goto 11;
if fontinfo[depthbase[f]].int<>0 then goto 11;
if fontinfo[italicbase[f]].int<>0 then goto 11;end{:574};
{576:}bchlabel:=32767;bchar:=256;
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
alpha else goto 11;end;{:576};
{577:}for k:=extenbase[f]to parambase[f]-1 do begin begin tfmtemp:=getc(
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
end{:577};
{578:}begin for k:=1 to np do if k=1 then begin tfmtemp:=getc(tfmfile);
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
for k:=np+1 to 7 do fontinfo[parambase[f]+k-1].int:=0;end{:578};
{579:}if np>=7 then fontparams[f]:=np else fontparams[f]:=7;
hyphenchar[f]:=eqtb[27213].int;skewchar[f]:=eqtb[27214].int;
if bchlabel<nl then bcharlabel[f]:=bchlabel+ligkernbase[f]else
bcharlabel[f]:=0;fontbchar[f]:=bchar;fontfalsebchar[f]:=bchar;
if bchar<=ec then if bchar>=bc then begin qw:=fontinfo[charbase[f]+bchar
].qqqq;if(qw.b0>0)then fontfalsebchar[f]:=256;end;fontname[f]:=nom;
fontarea[f]:=aire;fontbc[f]:=bc;fontec[f]:=ec;fontglue[f]:=-268435455;
charbase[f]:=charbase[f];widthbase[f]:=widthbase[f];
ligkernbase[f]:=ligkernbase[f];kernbase[f]:=kernbase[f];
extenbase[f]:=extenbase[f];decr(parambase[f]);fmemptr:=fmemptr+lf;
fontptr:=f;g:=f;goto 30{:579}{:565};
11:{564:}begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(816);
end;sprintcs(u);printchar(61);printfilename(nom,aire,335);
if s>=0 then begin print(756);printscaled(s);print(402);
end else if s<>-1000 then begin print(817);printint(-s);end;
if fileopened then print(818)else if nametoolong then print(819)else
print(820);begin helpptr:=5;helpline[4]:=821;helpline[3]:=822;
helpline[2]:=823;helpline[1]:=824;helpline[0]:=825;end;error{:564};
30:if fileopened then bclose(tfmfile);readfontinfo:=g;end;
{:563}{584:}procedure charwarning(f:internalfontnumber;c:eightbits);
begin if eqtb[27202].int>0 then begin begindiagnostic;printnl(839);
print(c);print(840);slowprint(fontname[f]);printchar(33);
enddiagnostic(false);end;end;
{:584}{585:}function newcharacter(f:internalfontnumber;
c:eightbits):halfword;label 10;var p:halfword;ec:quarterword;
begin ec:=effectivechar(false,f,c);
if fontbc[f]<=ec then if fontec[f]>=ec then if(fontinfo[charbase[f]+ec].
qqqq.b0>0)then begin p:=getavail;mem[p].hh.b0:=f;mem[p].hh.b1:=c;
newcharacter:=p;goto 10;end;charwarning(f,c);newcharacter:=-268435455;
10:end;{:585}{601:}procedure dviswap;
begin if dviptr>(2147483647-dvioffset)then begin curs:=-2;
fatalerror(841);end;
if dvilimit=dvibufsize then begin writedvi(0,halfbuf-1);
dvilimit:=halfbuf;dvioffset:=dvioffset+dvibufsize;dviptr:=0;
end else begin writedvi(halfbuf,dvibufsize-1);dvilimit:=dvibufsize;end;
dvigone:=dvigone+halfbuf;end;{:601}{603:}procedure dvifour(x:integer);
begin if x>=0 then begin dvibuf[dviptr]:=x div 16777216;incr(dviptr);
if dviptr=dvilimit then dviswap;end else begin x:=x+1073741824;
x:=x+1073741824;begin dvibuf[dviptr]:=(x div 16777216)+128;incr(dviptr);
if dviptr=dvilimit then dviswap;end;end;x:=x mod 16777216;
begin dvibuf[dviptr]:=x div 65536;incr(dviptr);
if dviptr=dvilimit then dviswap;end;x:=x mod 65536;
begin dvibuf[dviptr]:=x div 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=x mod 256;
incr(dviptr);if dviptr=dvilimit then dviswap;end;end;
{:603}{604:}procedure dvipop(l:integer);
begin if(l=dvioffset+dviptr)and(dviptr>0)then decr(dviptr)else begin
dvibuf[dviptr]:=142;incr(dviptr);if dviptr=dvilimit then dviswap;end;
end;{:604}{605:}procedure dvifontdef(f:internalfontnumber);
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
{606:}for k:=strstart[fontarea[f]]to strstart[fontarea[f]+1]-1 do begin
dvibuf[dviptr]:=strpool[k];incr(dviptr);if dviptr=dvilimit then dviswap;
end;
for k:=strstart[fontname[f]]to strstart[fontname[f]+1]-1 do begin dvibuf
[dviptr]:=strpool[k];incr(dviptr);if dviptr=dvilimit then dviswap;
end{:606};end;{:605}{610:}procedure movement(w:scaled;o:eightbits);
label 10,40,45,2,1;var mstate:smallnumber;p,q:halfword;k:integer;
begin q:=getnode(3);mem[q+1].int:=w;mem[q+2].int:=dvioffset+dviptr;
if o=157 then begin mem[q].hh.rh:=downptr;downptr:=q;
end else begin mem[q].hh.rh:=rightptr;rightptr:=q;end;
{614:}p:=mem[q].hh.rh;mstate:=0;
while p<>-268435455 do begin if mem[p+1].int=w then{615:}case mstate+mem
[p].hh.lh of 3,4,15,16:if mem[p+2].int<dvigone then goto 45 else{616:}
begin k:=mem[p+2].int-dvioffset;if k<0 then k:=k+dvibufsize;
dvibuf[k]:=dvibuf[k]+5;mem[p].hh.lh:=1;goto 40;end{:616};
5,9,11:if mem[p+2].int<dvigone then goto 45 else{617:}begin k:=mem[p+2].
int-dvioffset;if k<0 then k:=k+dvibufsize;dvibuf[k]:=dvibuf[k]+10;
mem[p].hh.lh:=2;goto 40;end{:617};1,2,8,13:goto 40;
others:end{:615}else case mstate+mem[p].hh.lh of 1:mstate:=6;
2:mstate:=12;8,13:goto 45;others:end;p:=mem[p].hh.rh;end;45:{:614};
{613:}mem[q].hh.lh:=3;
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
if dviptr=dvilimit then dviswap;end;goto 10{:613};
40:{612:}mem[q].hh.lh:=mem[p].hh.lh;
if mem[q].hh.lh=1 then begin begin dvibuf[dviptr]:=o+4;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
while mem[q].hh.rh<>p do begin q:=mem[q].hh.rh;
case mem[q].hh.lh of 3:mem[q].hh.lh:=5;4:mem[q].hh.lh:=6;others:end;end;
end else begin begin dvibuf[dviptr]:=o+9;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
while mem[q].hh.rh<>p do begin q:=mem[q].hh.rh;
case mem[q].hh.lh of 3:mem[q].hh.lh:=4;5:mem[q].hh.lh:=6;others:end;end;
end{:612};10:end;{:610}{618:}procedure prunemovements(l:integer);
label 30,10;var p:halfword;
begin while downptr<>-268435455 do begin if mem[downptr+2].int<l then
goto 30;p:=downptr;downptr:=mem[p].hh.rh;freenode(p,3);end;
30:while rightptr<>-268435455 do begin if mem[rightptr+2].int<l then
goto 10;p:=rightptr;rightptr:=mem[p].hh.rh;freenode(p,3);end;10:end;
{:618}{621:}procedure vlistout;forward;
{:621}{622:}{1371:}procedure specialout(p:halfword);
var oldsetting:0..21;k:poolpointer;
begin if curh<>dvih then begin movement(curh-dvih,143);dvih:=curh;end;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
oldsetting:=selector;selector:=21;specsout:=eqtb[27228].int;
eqtb[27228].int:=mem[p+1].hh.b0-64;mubytesout:=eqtb[27226].int;
eqtb[27226].int:=mem[p+1].hh.b1-64;activenoconvert:=true;
mubyteslog:=eqtb[27227].int;eqtb[27227].int:=0;
if(eqtb[27226].int>0)or(eqtb[27226].int=-1)then eqtb[27227].int:=1;
if(eqtb[27228].int=2)or(eqtb[27228].int=3)then begin if(eqtb[27226].int>
0)or(eqtb[27226].int=-1)then begin specialprinting:=true;
eqtb[27227].int:=1;end;if eqtb[27226].int>1 then csconverting:=true;end;
showtokenlist(mem[mem[p+1].hh.rh].hh.rh,-268435455,poolsize-poolptr);
selector:=oldsetting;
begin if poolptr+1>poolsize then overflow(257,poolsize-initpoolptr);end;
if(poolptr-strstart[strptr])<256 then begin begin dvibuf[dviptr]:=239;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=(poolptr-strstart[strptr]);incr(dviptr);
if dviptr=dvilimit then dviswap;end;
end else begin begin dvibuf[dviptr]:=242;incr(dviptr);
if dviptr=dvilimit then dviswap;end;dvifour((poolptr-strstart[strptr]));
end;
if(eqtb[27228].int=1)or(eqtb[27228].int=3)then for k:=strstart[strptr]to
poolptr-1 do strpool[k]:=xchr[strpool[k]];
for k:=strstart[strptr]to poolptr-1 do begin dvibuf[dviptr]:=strpool[k];
incr(dviptr);if dviptr=dvilimit then dviswap;end;
eqtb[27228].int:=specsout;eqtb[27226].int:=mubytesout;
eqtb[27227].int:=mubyteslog;specialprinting:=false;csconverting:=false;
activenoconvert:=false;poolptr:=strstart[strptr];end;
{:1371}{1373:}procedure writeout(p:halfword);var oldsetting:0..21;
oldmode:integer;j:smallnumber;q,r:halfword;d:integer;clobbered:boolean;
runsystemret:integer;begin mubytesout:=eqtb[27226].int;
eqtb[27226].int:=mem[p+1].hh.b1-64;
if(eqtb[27226].int>2)or(eqtb[27226].int=-1)or(eqtb[27226].int=-2)then
writenoexpanding:=true;{1374:}q:=getavail;mem[q].hh.lh:=637;r:=getavail;
mem[q].hh.rh:=r;mem[r].hh.lh:=19617;begintokenlist(q,4);
begintokenlist(mem[p+1].hh.rh,15);q:=getavail;mem[q].hh.lh:=379;
begintokenlist(q,4);oldmode:=curlist.modefield;curlist.modefield:=0;
curcs:=writeloc;q:=scantoks(false,true);gettoken;
if curtok<>19617 then{1375:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1337);
end;begin helpptr:=2;helpline[1]:=1338;helpline[0]:=1028;end;error;
repeat gettoken;until curtok=19617;end{:1375};
curlist.modefield:=oldmode;endtokenlist{:1374};oldsetting:=selector;
j:=mem[p+1].hh.b0;
if j=18 then selector:=21 else if writeopen[j]then selector:=j else
begin if(j=17)and(selector=19)then selector:=18;printnl(335);end;
activenoconvert:=true;if eqtb[27226].int>1 then csconverting:=true;
mubyteslog:=eqtb[27227].int;
if(eqtb[27226].int>0)or(eqtb[27226].int=-1)then eqtb[27227].int:=1 else
eqtb[27227].int:=0;tokenshow(defref);println;csconverting:=false;
writenoexpanding:=false;activenoconvert:=false;
eqtb[27226].int:=mubytesout;eqtb[27227].int:=mubyteslog;
flushlist(defref);
if j=18 then begin if(eqtb[27196].int<=0)then selector:=18 else selector
:=19;if not logopened then selector:=17;printnl(1329);
for d:=0 to(poolptr-strstart[strptr])-1 do begin print(strpool[strstart[
strptr]+d]);end;print(1330);
if shellenabledp then begin begin if poolptr+1>poolsize then overflow(
257,poolsize-initpoolptr);end;begin strpool[poolptr]:=0;incr(poolptr);
end;clobbered:=false;
for d:=0 to(poolptr-strstart[strptr])-1 do begin strpool[strstart[strptr
]+d]:=xchr[strpool[strstart[strptr]+d]];
if(strpool[strstart[strptr]+d]=0)and(d<(poolptr-strstart[strptr])-1)then
clobbered:=true;end;
if clobbered then print(1331)else begin runsystemret:=runsystem(
conststringcast(addressof(strpool[strstart[strptr]])));
if runsystemret=-1 then print(1332)else if runsystemret=0 then print(
1333)else if runsystemret=1 then print(1334)else if runsystemret=2 then
print(1335)end;end else begin print(1336);end;printchar(46);
printnl(335);println;poolptr:=strstart[strptr];end;selector:=oldsetting;
end;{:1373}{1376:}procedure outwhat(p:halfword);var j:smallnumber;
oldsetting:0..21;
begin case mem[p].hh.b1 of 0,1,2:{1377:}if not doingleaders then begin j
:=mem[p+1].hh.b0;
if mem[p].hh.b1=1 then writeout(p)else begin if writeopen[j]then aclose(
writefile[j]);
if mem[p].hh.b1=2 then writeopen[j]:=false else if j<16 then begin
curname:=mem[p+1].hh.rh;curarea:=mem[p+2].hh.lh;curext:=mem[p+2].hh.rh;
if curext=335 then curext:=803;packfilename(curname,curarea,curext);
while not kpseoutnameok(stringcast(nameoffile+1))or not aopenout(
writefile[j])do promptfilename(1340,803);writeopen[j]:=true;
if logopened then begin oldsetting:=selector;
if(eqtb[27196].int<=0)then selector:=18 else selector:=19;printnl(1341);
printint(j);print(1342);printfilename(curname,curarea,curext);
print(802);printnl(335);println;selector:=oldsetting;end;end;end;
end{:1377};3:specialout(p);4:;others:confusion(1339)end;end;
{:1376}procedure hlistout;label 21,13,14,15,22,40;var baseline:scaled;
leftedge:scaled;saveh,savev:scaled;thisbox:halfword;gorder:glueord;
gsign:0..2;p:halfword;saveloc:integer;leaderbox:halfword;
leaderwd:scaled;lx:scaled;outerdoingleaders:boolean;edge:scaled;
gluetemp:real;curglue:real;curg:scaled;begin curg:=0;curglue:=0.0;
thisbox:=tempptr;gorder:=mem[thisbox+5].hh.b1;
gsign:=mem[thisbox+5].hh.b0;p:=mem[thisbox+5].hh.rh;incr(curs);
if curs>0 then begin dvibuf[dviptr]:=141;incr(dviptr);
if dviptr=dvilimit then dviswap;end;if curs>maxpush then maxpush:=curs;
saveloc:=dvioffset+dviptr;baseline:=curv;leftedge:=curh;
while p<>-268435455 do{623:}21:if(p>=himemmin)then begin if curh<>dvih
then begin movement(curh-dvih,143);dvih:=curh;end;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
repeat f:=mem[p].hh.b0;c:=mem[p].hh.b1;
if f<>dvif then{624:}begin if not fontused[f]then begin dvifontdef(f);
fontused[f]:=true;end;if f<=64 then begin dvibuf[dviptr]:=f+170;
incr(dviptr);if dviptr=dvilimit then dviswap;
end else if f<=256 then begin begin dvibuf[dviptr]:=235;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=f-1;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
end else begin begin dvibuf[dviptr]:=236;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=(f-1)div 256;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=(f-1)mod 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;end;dvif:=f;end{:624};
if fontec[f]>=c then if fontbc[f]<=c then if(fontinfo[charbase[f]+c].
qqqq.b0>0)then begin if c>=128 then begin dvibuf[dviptr]:=128;
incr(dviptr);if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=c;incr(dviptr);if dviptr=dvilimit then dviswap;
end;
curh:=curh+fontinfo[widthbase[f]+fontinfo[charbase[f]+c].qqqq.b0].int;
goto 22;end;
if mltexenabledp then{1398:}begin{1400:}if c>=eqtb[27222].int then if c
<=eqtb[27223].int then if(eqtb[26911+c].hh.rh>0)then begin basec:=(eqtb[
26911+c].hh.rh mod 256);accentc:=(eqtb[26911+c].hh.rh div 256);
if(fontec[f]>=basec)then if(fontbc[f]<=basec)then if(fontec[f]>=accentc)
then if(fontbc[f]<=accentc)then begin iac:=fontinfo[charbase[f]+
effectivechar(true,f,accentc)].qqqq;
ibc:=fontinfo[charbase[f]+effectivechar(true,f,basec)].qqqq;
if(ibc.b0>0)then if(iac.b0>0)then goto 40;end;begindiagnostic;
printnl(1344);print(c);print(1225);print(accentc);print(32);
print(basec);print(840);slowprint(fontname[f]);printchar(33);
enddiagnostic(false);goto 22;end;begindiagnostic;printnl(839);
print(1343);print(c);print(840);slowprint(fontname[f]);printchar(33);
enddiagnostic(false);goto 22{:1400};
40:{1401:}if eqtb[27202].int>99 then begin begindiagnostic;
printnl(1345);print(c);print(1225);print(accentc);print(32);
print(basec);print(840);slowprint(fontname[f]);printchar(46);
enddiagnostic(false);end{:1401};
{1402:}basexheight:=fontinfo[5+parambase[f]].int;
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
dvih:=curh{:1402};end{:1398};22:p:=mem[p].hh.rh;until not(p>=himemmin);
dvih:=curh;
end else{625:}begin case mem[p].hh.b0 of 0,1:{626:}if mem[p+5].hh.rh=
-268435455 then curh:=curh+mem[p+1].int else begin saveh:=dvih;
savev:=dviv;curv:=baseline+mem[p+4].int;tempptr:=p;edge:=curh;
if mem[p].hh.b0=1 then vlistout else hlistout;dvih:=saveh;dviv:=savev;
curh:=edge+mem[p+1].int;curv:=baseline;end{:626};
2:begin ruleht:=mem[p+3].int;ruledp:=mem[p+2].int;rulewd:=mem[p+1].int;
goto 14;end;8:{1370:}outwhat(p){:1370};10:{628:}begin g:=mem[p+1].hh.lh;
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
if mem[p].hh.b1>=100 then{629:}begin leaderbox:=mem[p+1].hh.rh;
if mem[leaderbox].hh.b0=2 then begin ruleht:=mem[leaderbox+3].int;
ruledp:=mem[leaderbox+2].int;goto 14;end;leaderwd:=mem[leaderbox+1].int;
if(leaderwd>0)and(rulewd>0)then begin rulewd:=rulewd+10;
edge:=curh+rulewd;lx:=0;
{630:}if mem[p].hh.b1=100 then begin saveh:=curh;
curh:=leftedge+leaderwd*((curh-leftedge)div leaderwd);
if curh<saveh then curh:=curh+leaderwd;
end else begin lq:=rulewd div leaderwd;lr:=rulewd mod leaderwd;
if mem[p].hh.b1=101 then curh:=curh+(lr div 2)else begin lx:=lr div(lq+1
);curh:=curh+((lr-(lq-1)*lx)div 2);end;end{:630};
while curh+leaderwd<=edge do{631:}begin curv:=baseline+mem[leaderbox+4].
int;if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
savev:=dviv;if curh<>dvih then begin movement(curh-dvih,143);dvih:=curh;
end;saveh:=dvih;tempptr:=leaderbox;outerdoingleaders:=doingleaders;
doingleaders:=true;
if mem[leaderbox].hh.b0=1 then vlistout else hlistout;
doingleaders:=outerdoingleaders;dviv:=savev;dvih:=saveh;curv:=baseline;
curh:=saveh+leaderwd+lx;end{:631};curh:=edge-10;goto 15;end;end{:629};
goto 13;end{:628};11,9:curh:=curh+mem[p+1].int;
6:{655:}begin mem[memtop-12]:=mem[p+1];
mem[memtop-12].hh.rh:=mem[p].hh.rh;p:=memtop-12;goto 21;end{:655};
others:end;goto 15;
14:{627:}if(ruleht=-1073741824)then ruleht:=mem[thisbox+3].int;
if(ruledp=-1073741824)then ruledp:=mem[thisbox+2].int;
ruleht:=ruleht+ruledp;
if(ruleht>0)and(rulewd>0)then begin if curh<>dvih then begin movement(
curh-dvih,143);dvih:=curh;end;curv:=baseline+ruledp;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
begin dvibuf[dviptr]:=132;incr(dviptr);if dviptr=dvilimit then dviswap;
end;dvifour(ruleht);dvifour(rulewd);curv:=baseline;dvih:=dvih+rulewd;
end{:627};13:curh:=curh+rulewd;15:p:=mem[p].hh.rh;end{:625}{:623};
prunemovements(saveloc);if curs>0 then dvipop(saveloc);decr(curs);end;
{:622}{632:}procedure vlistout;label 13,14,15;var leftedge:scaled;
topedge:scaled;saveh,savev:scaled;thisbox:halfword;gorder:glueord;
gsign:0..2;p:halfword;saveloc:integer;leaderbox:halfword;
leaderht:scaled;lx:scaled;outerdoingleaders:boolean;edge:scaled;
gluetemp:real;curglue:real;curg:scaled;begin curg:=0;curglue:=0.0;
thisbox:=tempptr;gorder:=mem[thisbox+5].hh.b1;
gsign:=mem[thisbox+5].hh.b0;p:=mem[thisbox+5].hh.rh;incr(curs);
if curs>0 then begin dvibuf[dviptr]:=141;incr(dviptr);
if dviptr=dvilimit then dviswap;end;if curs>maxpush then maxpush:=curs;
saveloc:=dvioffset+dviptr;leftedge:=curh;curv:=curv-mem[thisbox+3].int;
topedge:=curv;
while p<>-268435455 do{633:}begin if(p>=himemmin)then confusion(843)else
{634:}begin case mem[p].hh.b0 of 0,1:{635:}if mem[p+5].hh.rh=-268435455
then curv:=curv+mem[p+3].int+mem[p+2].int else begin curv:=curv+mem[p+3]
.int;if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
saveh:=dvih;savev:=dviv;curh:=leftedge+mem[p+4].int;tempptr:=p;
if mem[p].hh.b0=1 then vlistout else hlistout;dvih:=saveh;dviv:=savev;
curv:=savev+mem[p+2].int;curh:=leftedge;end{:635};
2:begin ruleht:=mem[p+3].int;ruledp:=mem[p+2].int;rulewd:=mem[p+1].int;
goto 14;end;8:{1369:}outwhat(p){:1369};10:{637:}begin g:=mem[p+1].hh.lh;
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
if mem[p].hh.b1>=100 then{638:}begin leaderbox:=mem[p+1].hh.rh;
if mem[leaderbox].hh.b0=2 then begin rulewd:=mem[leaderbox+1].int;
ruledp:=0;goto 14;end;
leaderht:=mem[leaderbox+3].int+mem[leaderbox+2].int;
if(leaderht>0)and(ruleht>0)then begin ruleht:=ruleht+10;
edge:=curv+ruleht;lx:=0;
{639:}if mem[p].hh.b1=100 then begin savev:=curv;
curv:=topedge+leaderht*((curv-topedge)div leaderht);
if curv<savev then curv:=curv+leaderht;
end else begin lq:=ruleht div leaderht;lr:=ruleht mod leaderht;
if mem[p].hh.b1=101 then curv:=curv+(lr div 2)else begin lx:=lr div(lq+1
);curv:=curv+((lr-(lq-1)*lx)div 2);end;end{:639};
while curv+leaderht<=edge do{640:}begin curh:=leftedge+mem[leaderbox+4].
int;if curh<>dvih then begin movement(curh-dvih,143);dvih:=curh;end;
saveh:=dvih;curv:=curv+mem[leaderbox+3].int;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
savev:=dviv;tempptr:=leaderbox;outerdoingleaders:=doingleaders;
doingleaders:=true;
if mem[leaderbox].hh.b0=1 then vlistout else hlistout;
doingleaders:=outerdoingleaders;dviv:=savev;dvih:=saveh;curh:=leftedge;
curv:=savev-mem[leaderbox+3].int+leaderht+lx;end{:640};curv:=edge-10;
goto 15;end;end{:638};goto 13;end{:637};11:curv:=curv+mem[p+1].int;
others:end;goto 15;
14:{636:}if(rulewd=-1073741824)then rulewd:=mem[thisbox+1].int;
ruleht:=ruleht+ruledp;curv:=curv+ruleht;
if(ruleht>0)and(rulewd>0)then begin if curh<>dvih then begin movement(
curh-dvih,143);dvih:=curh;end;
if curv<>dviv then begin movement(curv-dviv,157);dviv:=curv;end;
begin dvibuf[dviptr]:=137;incr(dviptr);if dviptr=dvilimit then dviswap;
end;dvifour(ruleht);dvifour(rulewd);end;goto 15{:636};
13:curv:=curv+ruleht;end{:634};15:p:=mem[p].hh.rh;end{:633};
prunemovements(saveloc);if curs>0 then dvipop(saveloc);decr(curs);end;
{:632}{641:}procedure shipout(p:halfword);label 30;var pageloc:integer;
j,k:0..9;s:poolpointer;oldsetting:0..21;
begin if eqtb[27201].int>0 then begin printnl(335);println;print(844);
end;if termoffset>maxprintline-9 then println else if(termoffset>0)or(
fileoffset>0)then printchar(32);printchar(91);j:=9;
while(eqtb[27229+j].int=0)and(j>0)do decr(j);
for k:=0 to j do begin printint(eqtb[27229+k].int);
if k<j then printchar(46);end;fflush(stdout);
if eqtb[27201].int>0 then begin printchar(93);begindiagnostic;
showbox(p);enddiagnostic(true);end;
{643:}{644:}if(mem[p+3].int>1073741823)or(mem[p+2].int>1073741823)or(mem
[p+3].int+mem[p+2].int+eqtb[27760].int>1073741823)or(mem[p+1].int+eqtb[
27759].int>1073741823)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(848);
end;begin helpptr:=2;helpline[1]:=849;helpline[0]:=850;end;error;
if eqtb[27201].int<=0 then begin begindiagnostic;printnl(851);
showbox(p);enddiagnostic(true);end;goto 30;end;
if mem[p+3].int+mem[p+2].int+eqtb[27760].int>maxv then maxv:=mem[p+3].
int+mem[p+2].int+eqtb[27760].int;
if mem[p+1].int+eqtb[27759].int>maxh then maxh:=mem[p+1].int+eqtb[27759]
.int{:644};{620:}dvih:=0;dviv:=0;curh:=eqtb[27759].int;dvif:=0;
if outputfilename=0 then begin if jobname=0 then openlogfile;
packjobname(807);while not bopenout(dvifile)do promptfilename(808,807);
outputfilename:=bmakenamestring(dvifile);end;
if totalpages=0 then begin begin dvibuf[dviptr]:=247;incr(dviptr);
if dviptr=dvilimit then dviswap;end;begin dvibuf[dviptr]:=2;
incr(dviptr);if dviptr=dvilimit then dviswap;end;dvifour(25400000);
dvifour(473628672);preparemag;dvifour(eqtb[27184].int);
if outputcomment then begin l:=strlen(outputcomment);
begin dvibuf[dviptr]:=l;incr(dviptr);if dviptr=dvilimit then dviswap;
end;for s:=0 to l-1 do begin dvibuf[dviptr]:=outputcomment[s];
incr(dviptr);if dviptr=dvilimit then dviswap;end;
end else begin oldsetting:=selector;selector:=21;print(842);
printint(eqtb[27190].int);printchar(46);printtwo(eqtb[27189].int);
printchar(46);printtwo(eqtb[27188].int);printchar(58);
printtwo(eqtb[27187].int div 60);printtwo(eqtb[27187].int mod 60);
selector:=oldsetting;begin dvibuf[dviptr]:=(poolptr-strstart[strptr]);
incr(dviptr);if dviptr=dvilimit then dviswap;end;
for s:=strstart[strptr]to poolptr-1 do begin dvibuf[dviptr]:=strpool[s];
incr(dviptr);if dviptr=dvilimit then dviswap;end;
poolptr:=strstart[strptr];end;end{:620};pageloc:=dvioffset+dviptr;
begin dvibuf[dviptr]:=139;incr(dviptr);if dviptr=dvilimit then dviswap;
end;for k:=0 to 9 do dvifour(eqtb[27229+k].int);dvifour(lastbop);
lastbop:=pageloc;curv:=mem[p+3].int+eqtb[27760].int;tempptr:=p;
if mem[p].hh.b0=1 then vlistout else hlistout;begin dvibuf[dviptr]:=140;
incr(dviptr);if dviptr=dvilimit then dviswap;end;incr(totalpages);
curs:=-1;
ifdef('IPC')if ipcon>0 then begin if dvilimit=halfbuf then begin
writedvi(halfbuf,dvibufsize-1);flushdvi;dvigone:=dvigone+halfbuf;end;
if dviptr>(2147483647-dvioffset)then begin curs:=-2;fatalerror(841);end;
if dviptr>0 then begin writedvi(0,dviptr-1);flushdvi;
dvioffset:=dvioffset+dviptr;dvigone:=dvigone+dviptr;end;dviptr:=0;
dvilimit:=dvibufsize;ipcpage(dvigone);end;endif('IPC');30:{:643};
if eqtb[27201].int<=0 then printchar(93);deadcycles:=0;fflush(stdout);
{642:}ifdef('STAT')if eqtb[27198].int>1 then begin printnl(845);
printint(varused);printchar(38);printint(dynused);printchar(59);end;
endif('STAT')flushnodelist(p);
ifdef('STAT')if eqtb[27198].int>1 then begin print(846);
printint(varused);printchar(38);printint(dynused);print(847);
printint(himemmin-lomemmax-1);println;end;endif('STAT'){:642};end;
{:641}{648:}procedure scanspec(c:groupcode;threecodes:boolean);label 40;
var s:integer;speccode:0..1;
begin if threecodes then s:=savestack[saveptr+0].int;
if scankeyword(858)then speccode:=0 else if scankeyword(859)then
speccode:=1 else begin speccode:=1;curval:=0;goto 40;end;
scandimen(false,false,false);
40:if threecodes then begin savestack[saveptr+0].int:=s;incr(saveptr);
end;savestack[saveptr+0].int:=speccode;savestack[saveptr+1].int:=curval;
saveptr:=saveptr+2;newsavelevel(c);scanleftbrace;end;
{:648}{652:}function hpack(p:halfword;w:scaled;m:smallnumber):halfword;
label 21,50,10;var r:halfword;q:halfword;h,d,x:scaled;s:scaled;
g:halfword;o:glueord;f:internalfontnumber;i:fourquarters;hd:eightbits;
begin lastbadness:=0;r:=getnode(7);mem[r].hh.b0:=0;mem[r].hh.b1:=0;
mem[r+4].int:=0;q:=r+5;mem[q].hh.rh:=p;h:=0;{653:}d:=0;x:=0;
totalstretch[0]:=0;totalshrink[0]:=0;totalstretch[1]:=0;
totalshrink[1]:=0;totalstretch[2]:=0;totalshrink[2]:=0;
totalstretch[3]:=0;totalshrink[3]:=0{:653};
while p<>-268435455 do{654:}begin 21:while(p>=himemmin)do{657:}begin f:=
mem[p].hh.b0;
i:=fontinfo[charbase[f]+effectivechar(true,f,mem[p].hh.b1)].qqqq;
hd:=i.b1;x:=x+fontinfo[widthbase[f]+i.b0].int;
s:=fontinfo[heightbase[f]+(hd)div 16].int;if s>h then h:=s;
s:=fontinfo[depthbase[f]+(hd)mod 16].int;if s>d then d:=s;
p:=mem[p].hh.rh;end{:657};
if p<>-268435455 then begin case mem[p].hh.b0 of 0,1,2,13:{656:}begin x
:=x+mem[p+1].int;if mem[p].hh.b0>=2 then s:=0 else s:=mem[p+4].int;
if mem[p+3].int-s>h then h:=mem[p+3].int-s;
if mem[p+2].int+s>d then d:=mem[p+2].int+s;end{:656};
3,4,5:if adjusttail<>-268435455 then{658:}begin while mem[q].hh.rh<>p do
q:=mem[q].hh.rh;
if mem[p].hh.b0=5 then begin mem[adjusttail].hh.rh:=mem[p+1].int;
while mem[adjusttail].hh.rh<>-268435455 do adjusttail:=mem[adjusttail].
hh.rh;p:=mem[p].hh.rh;freenode(mem[q].hh.rh,2);
end else begin mem[adjusttail].hh.rh:=p;adjusttail:=p;p:=mem[p].hh.rh;
end;mem[q].hh.rh:=p;p:=q;end{:658};8:{1363:}{:1363};
10:{659:}begin g:=mem[p+1].hh.lh;x:=x+mem[g+1].int;o:=mem[g].hh.b0;
totalstretch[o]:=totalstretch[o]+mem[g+2].int;o:=mem[g].hh.b1;
totalshrink[o]:=totalshrink[o]+mem[g+3].int;
if mem[p].hh.b1>=100 then begin g:=mem[p+1].hh.rh;
if mem[g+3].int>h then h:=mem[g+3].int;
if mem[g+2].int>d then d:=mem[g+2].int;end;end{:659};
11,9:x:=x+mem[p+1].int;6:{655:}begin mem[memtop-12]:=mem[p+1];
mem[memtop-12].hh.rh:=mem[p].hh.rh;p:=memtop-12;goto 21;end{:655};
others:end;p:=mem[p].hh.rh;end;end{:654};
if adjusttail<>-268435455 then mem[adjusttail].hh.rh:=-268435455;
mem[r+3].int:=h;mem[r+2].int:=d;{660:}if m=1 then w:=x+w;
mem[r+1].int:=w;x:=w-x;if x=0 then begin mem[r+5].hh.b0:=0;
mem[r+5].hh.b1:=0;mem[r+6].gr:=0.0;goto 10;
end else if x>0 then{661:}begin{662:}if totalstretch[3]<>0 then o:=3
else if totalstretch[2]<>0 then o:=2 else if totalstretch[1]<>0 then o:=
1 else o:=0{:662};mem[r+5].hh.b1:=o;mem[r+5].hh.b0:=1;
if totalstretch[o]<>0 then mem[r+6].gr:=x/totalstretch[o]else begin mem[
r+5].hh.b0:=0;mem[r+6].gr:=0.0;end;
if o=0 then if mem[r+5].hh.rh<>-268435455 then{663:}begin lastbadness:=
badness(x,totalstretch[0]);
if lastbadness>eqtb[27193].int then begin println;
if lastbadness>100 then printnl(860)else printnl(861);print(862);
printint(lastbadness);goto 50;end;end{:663};goto 10;
end{:661}else{667:}begin{668:}if totalshrink[3]<>0 then o:=3 else if
totalshrink[2]<>0 then o:=2 else if totalshrink[1]<>0 then o:=1 else o:=
0{:668};mem[r+5].hh.b1:=o;mem[r+5].hh.b0:=2;
if totalshrink[o]<>0 then mem[r+6].gr:=(-x)/totalshrink[o]else begin mem
[r+5].hh.b0:=0;mem[r+6].gr:=0.0;end;
if(totalshrink[o]<-x)and(o=0)and(mem[r+5].hh.rh<>-268435455)then begin
lastbadness:=1000000;mem[r+6].gr:=1.0;
{669:}if(-x-totalshrink[0]>eqtb[27749].int)or(eqtb[27193].int<100)then
begin if(eqtb[27757].int>0)and(-x-totalshrink[0]>eqtb[27749].int)then
begin while mem[q].hh.rh<>-268435455 do q:=mem[q].hh.rh;
mem[q].hh.rh:=newrule;mem[mem[q].hh.rh+1].int:=eqtb[27757].int;end;
println;printnl(868);printscaled(-x-totalshrink[0]);print(869);goto 50;
end{:669};
end else if o=0 then if mem[r+5].hh.rh<>-268435455 then{670:}begin
lastbadness:=badness(-x,totalshrink[0]);
if lastbadness>eqtb[27193].int then begin println;printnl(870);
printint(lastbadness);goto 50;end;end{:670};goto 10;end{:667}{:660};
50:{666:}if outputactive then print(863)else begin if packbeginline<>0
then begin if packbeginline>0 then print(864)else print(865);
printint(abs(packbeginline));print(866);end else print(867);
printint(line);end;println;fontinshortdisplay:=0;
shortdisplay(mem[r+5].hh.rh);println;begindiagnostic;showbox(r);
enddiagnostic(true){:666};10:hpack:=r;end;
{:652}{671:}function vpackage(p:halfword;h:scaled;m:smallnumber;
l:scaled):halfword;label 50,10;var r:halfword;w,d,x:scaled;s:scaled;
g:halfword;o:glueord;begin lastbadness:=0;r:=getnode(7);mem[r].hh.b0:=1;
mem[r].hh.b1:=0;mem[r+4].int:=0;mem[r+5].hh.rh:=p;w:=0;{653:}d:=0;x:=0;
totalstretch[0]:=0;totalshrink[0]:=0;totalstretch[1]:=0;
totalshrink[1]:=0;totalstretch[2]:=0;totalshrink[2]:=0;
totalstretch[3]:=0;totalshrink[3]:=0{:653};
while p<>-268435455 do{672:}begin if(p>=himemmin)then confusion(871)else
case mem[p].hh.b0 of 0,1,2,13:{673:}begin x:=x+d+mem[p+3].int;
d:=mem[p+2].int;if mem[p].hh.b0>=2 then s:=0 else s:=mem[p+4].int;
if mem[p+1].int+s>w then w:=mem[p+1].int+s;end{:673};8:{1362:}{:1362};
10:{674:}begin x:=x+d;d:=0;g:=mem[p+1].hh.lh;x:=x+mem[g+1].int;
o:=mem[g].hh.b0;totalstretch[o]:=totalstretch[o]+mem[g+2].int;
o:=mem[g].hh.b1;totalshrink[o]:=totalshrink[o]+mem[g+3].int;
if mem[p].hh.b1>=100 then begin g:=mem[p+1].hh.rh;
if mem[g+1].int>w then w:=mem[g+1].int;end;end{:674};
11:begin x:=x+d+mem[p+1].int;d:=0;end;others:end;p:=mem[p].hh.rh;
end{:672};mem[r+1].int:=w;if d>l then begin x:=x+d-l;mem[r+2].int:=l;
end else mem[r+2].int:=d;{675:}if m=1 then h:=x+h;mem[r+3].int:=h;
x:=h-x;if x=0 then begin mem[r+5].hh.b0:=0;mem[r+5].hh.b1:=0;
mem[r+6].gr:=0.0;goto 10;
end else if x>0 then{676:}begin{662:}if totalstretch[3]<>0 then o:=3
else if totalstretch[2]<>0 then o:=2 else if totalstretch[1]<>0 then o:=
1 else o:=0{:662};mem[r+5].hh.b1:=o;mem[r+5].hh.b0:=1;
if totalstretch[o]<>0 then mem[r+6].gr:=x/totalstretch[o]else begin mem[
r+5].hh.b0:=0;mem[r+6].gr:=0.0;end;
if o=0 then if mem[r+5].hh.rh<>-268435455 then{677:}begin lastbadness:=
badness(x,totalstretch[0]);
if lastbadness>eqtb[27194].int then begin println;
if lastbadness>100 then printnl(860)else printnl(861);print(872);
printint(lastbadness);goto 50;end;end{:677};goto 10;
end{:676}else{679:}begin{668:}if totalshrink[3]<>0 then o:=3 else if
totalshrink[2]<>0 then o:=2 else if totalshrink[1]<>0 then o:=1 else o:=
0{:668};mem[r+5].hh.b1:=o;mem[r+5].hh.b0:=2;
if totalshrink[o]<>0 then mem[r+6].gr:=(-x)/totalshrink[o]else begin mem
[r+5].hh.b0:=0;mem[r+6].gr:=0.0;end;
if(totalshrink[o]<-x)and(o=0)and(mem[r+5].hh.rh<>-268435455)then begin
lastbadness:=1000000;mem[r+6].gr:=1.0;
{680:}if(-x-totalshrink[0]>eqtb[27750].int)or(eqtb[27194].int<100)then
begin println;printnl(873);printscaled(-x-totalshrink[0]);print(874);
goto 50;end{:680};
end else if o=0 then if mem[r+5].hh.rh<>-268435455 then{681:}begin
lastbadness:=badness(-x,totalshrink[0]);
if lastbadness>eqtb[27194].int then begin println;printnl(875);
printint(lastbadness);goto 50;end;end{:681};goto 10;end{:679}{:675};
50:{678:}if outputactive then print(863)else begin if packbeginline<>0
then begin print(865);printint(abs(packbeginline));print(866);
end else print(867);printint(line);println;end;begindiagnostic;
showbox(r);enddiagnostic(true){:678};10:vpackage:=r;end;
{:671}{682:}procedure appendtovlist(b:halfword);var d:scaled;p:halfword;
begin if curlist.auxfield.int>-65536000 then begin d:=mem[eqtb[24528].hh
.rh+1].int-curlist.auxfield.int-mem[b+3].int;
if d<eqtb[27743].int then p:=newparamglue(0)else begin p:=newskipparam(1
);mem[tempptr+1].int:=d;end;mem[curlist.tailfield].hh.rh:=p;
curlist.tailfield:=p;end;mem[curlist.tailfield].hh.rh:=b;
curlist.tailfield:=b;curlist.auxfield.int:=mem[b+2].int;end;
{:682}{689:}function newnoad:halfword;var p:halfword;
begin p:=getnode(4);mem[p].hh.b0:=16;mem[p].hh.b1:=0;
mem[p+1].hh:=emptyfield;mem[p+3].hh:=emptyfield;mem[p+2].hh:=emptyfield;
newnoad:=p;end;{:689}{691:}function newstyle(s:smallnumber):halfword;
var p:halfword;begin p:=getnode(3);mem[p].hh.b0:=14;mem[p].hh.b1:=s;
mem[p+1].int:=0;mem[p+2].int:=0;newstyle:=p;end;
{:691}{692:}function newchoice:halfword;var p:halfword;
begin p:=getnode(3);mem[p].hh.b0:=15;mem[p].hh.b1:=0;
mem[p+1].hh.lh:=-268435455;mem[p+1].hh.rh:=-268435455;
mem[p+2].hh.lh:=-268435455;mem[p+2].hh.rh:=-268435455;newchoice:=p;end;
{:692}{696:}procedure showinfo;begin shownodelist(mem[tempptr].hh.lh);
end;{:696}{707:}function fractionrule(t:scaled):halfword;var p:halfword;
begin p:=newrule;mem[p+3].int:=t;mem[p+2].int:=0;fractionrule:=p;end;
{:707}{708:}function overbar(b:halfword;k,t:scaled):halfword;
var p,q:halfword;begin p:=newkern(k);mem[p].hh.rh:=b;q:=fractionrule(t);
mem[q].hh.rh:=p;p:=newkern(t);mem[p].hh.rh:=q;
overbar:=vpackage(p,0,1,1073741823);end;
{:708}{709:}{712:}function charbox(f:internalfontnumber;
c:quarterword):halfword;var q:fourquarters;hd:eightbits;b,p:halfword;
begin q:=fontinfo[charbase[f]+effectivechar(true,f,c)].qqqq;hd:=q.b1;
b:=newnullbox;
mem[b+1].int:=fontinfo[widthbase[f]+q.b0].int+fontinfo[italicbase[f]+(q.
b2)div 4].int;mem[b+3].int:=fontinfo[heightbase[f]+(hd)div 16].int;
mem[b+2].int:=fontinfo[depthbase[f]+(hd)mod 16].int;p:=getavail;
mem[p].hh.b1:=c;mem[p].hh.b0:=f;mem[b+5].hh.rh:=p;charbox:=b;end;
{:712}{714:}procedure stackintobox(b:halfword;f:internalfontnumber;
c:quarterword);var p:halfword;begin p:=charbox(f,c);
mem[p].hh.rh:=mem[b+5].hh.rh;mem[b+5].hh.rh:=p;
mem[b+3].int:=mem[p+3].int;end;
{:714}{715:}function heightplusdepth(f:internalfontnumber;
c:quarterword):scaled;var q:fourquarters;hd:eightbits;
begin q:=fontinfo[charbase[f]+effectivechar(true,f,c)].qqqq;hd:=q.b1;
heightplusdepth:=fontinfo[heightbase[f]+(hd)div 16].int+fontinfo[
depthbase[f]+(hd)mod 16].int;end;{:715}function vardelimiter(d:halfword;
s:smallnumber;v:scaled):halfword;label 40,22;var b:halfword;
f,g:internalfontnumber;c,x,y:quarterword;m,n:integer;u:scaled;w:scaled;
q:fourquarters;hd:eightbits;r:fourquarters;z:smallnumber;
largeattempt:boolean;begin f:=0;w:=0;largeattempt:=false;
z:=mem[d].qqqq.b0;x:=mem[d].qqqq.b1;
while true do begin{710:}if(z<>0)or(x<>0)then begin z:=z+s+16;
repeat z:=z-16;g:=eqtb[25583+z].hh.rh;if g<>0 then{711:}begin y:=x;
if(y>=fontbc[g])and(y<=fontec[g])then begin 22:q:=fontinfo[charbase[g]+y
].qqqq;if(q.b0>0)then begin if((q.b2)mod 4)=3 then begin f:=g;c:=y;
goto 40;end;hd:=q.b1;
u:=fontinfo[heightbase[g]+(hd)div 16].int+fontinfo[depthbase[g]+(hd)mod
16].int;if u>w then begin f:=g;c:=y;w:=u;if u>=v then goto 40;end;
if((q.b2)mod 4)=2 then begin y:=q.b3;goto 22;end;end;end;end{:711};
until z<16;end{:710};if largeattempt then goto 40;largeattempt:=true;
z:=mem[d].qqqq.b2;x:=mem[d].qqqq.b3;end;
40:if f<>0 then{713:}if((q.b2)mod 4)=3 then{716:}begin b:=newnullbox;
mem[b].hh.b0:=1;r:=fontinfo[extenbase[f]+q.b3].qqqq;{717:}c:=r.b3;
u:=heightplusdepth(f,c);w:=0;
q:=fontinfo[charbase[f]+effectivechar(true,f,c)].qqqq;
mem[b+1].int:=fontinfo[widthbase[f]+q.b0].int+fontinfo[italicbase[f]+(q.
b2)div 4].int;c:=r.b2;if c<>0 then w:=w+heightplusdepth(f,c);c:=r.b1;
if c<>0 then w:=w+heightplusdepth(f,c);c:=r.b0;
if c<>0 then w:=w+heightplusdepth(f,c);n:=0;
if u>0 then while w<v do begin w:=w+u;incr(n);if r.b1<>0 then w:=w+u;
end{:717};c:=r.b2;if c<>0 then stackintobox(b,f,c);c:=r.b3;
for m:=1 to n do stackintobox(b,f,c);c:=r.b1;
if c<>0 then begin stackintobox(b,f,c);c:=r.b3;
for m:=1 to n do stackintobox(b,f,c);end;c:=r.b0;
if c<>0 then stackintobox(b,f,c);mem[b+2].int:=w-mem[b+3].int;
end{:716}else b:=charbox(f,c){:713}else begin b:=newnullbox;
mem[b+1].int:=eqtb[27752].int;end;
mem[b+4].int:=half(mem[b+3].int-mem[b+2].int)-fontinfo[22+parambase[eqtb
[25585+s].hh.rh]].int;vardelimiter:=b;end;
{:709}{718:}function rebox(b:halfword;w:scaled):halfword;var p:halfword;
f:internalfontnumber;v:scaled;
begin if(mem[b+1].int<>w)and(mem[b+5].hh.rh<>-268435455)then begin if
mem[b].hh.b0=1 then b:=hpack(b,0,1);p:=mem[b+5].hh.rh;
if((p>=himemmin))and(mem[p].hh.rh=-268435455)then begin f:=mem[p].hh.b0;
v:=fontinfo[widthbase[f]+fontinfo[charbase[f]+effectivechar(true,f,mem[p
].hh.b1)].qqqq.b0].int;
if v<>mem[b+1].int then mem[p].hh.rh:=newkern(mem[b+1].int-v);end;
freenode(b,7);b:=newglue(membot+12);mem[b].hh.rh:=p;
while mem[p].hh.rh<>-268435455 do p:=mem[p].hh.rh;
mem[p].hh.rh:=newglue(membot+12);rebox:=hpack(b,w,0);
end else begin mem[b+1].int:=w;rebox:=b;end;end;
{:718}{719:}function mathglue(g:halfword;m:scaled):halfword;
var p:halfword;n:integer;f:scaled;begin n:=xovern(m,65536);
f:=texremainder;if f<0 then begin decr(n);f:=f+65536;end;p:=getnode(4);
mem[p+1].int:=multandadd(n,mem[g+1].int,xnoverd(mem[g+1].int,f,65536),
1073741823);mem[p].hh.b0:=mem[g].hh.b0;
if mem[p].hh.b0=0 then mem[p+2].int:=multandadd(n,mem[g+2].int,xnoverd(
mem[g+2].int,f,65536),1073741823)else mem[p+2].int:=mem[g+2].int;
mem[p].hh.b1:=mem[g].hh.b1;
if mem[p].hh.b1=0 then mem[p+3].int:=multandadd(n,mem[g+3].int,xnoverd(
mem[g+3].int,f,65536),1073741823)else mem[p+3].int:=mem[g+3].int;
mathglue:=p;end;{:719}{720:}procedure mathkern(p:halfword;m:scaled);
var n:integer;f:scaled;
begin if mem[p].hh.b1=99 then begin n:=xovern(m,65536);f:=texremainder;
if f<0 then begin decr(n);f:=f+65536;end;
mem[p+1].int:=multandadd(n,mem[p+1].int,xnoverd(mem[p+1].int,f,65536),
1073741823);mem[p].hh.b1:=1;end;end;{:720}{721:}procedure flushmath;
begin flushnodelist(mem[curlist.headfield].hh.rh);
flushnodelist(curlist.auxfield.int);
mem[curlist.headfield].hh.rh:=-268435455;
curlist.tailfield:=curlist.headfield;curlist.auxfield.int:=-268435455;
end;{:721}{723:}procedure mlisttohlist;forward;
function cleanbox(p:halfword;s:smallnumber):halfword;label 40;
var q:halfword;savestyle:smallnumber;x:halfword;r:halfword;
begin case mem[p].hh.rh of 1:begin curmlist:=newnoad;
mem[curmlist+1]:=mem[p];end;2:begin q:=mem[p].hh.lh;goto 40;end;
3:curmlist:=mem[p].hh.lh;others:begin q:=newnullbox;goto 40;end end;
savestyle:=curstyle;curstyle:=s;mlistpenalties:=false;mlisttohlist;
q:=mem[memtop-3].hh.rh;curstyle:=savestyle;
{706:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25585+cursize].hh.rh]].int,18);
end{:706};
40:if(q>=himemmin)or(q=-268435455)then x:=hpack(q,0,1)else if(mem[q].hh.
rh=-268435455)and(mem[q].hh.b0<=1)and(mem[q+4].int=0)then x:=q else x:=
hpack(q,0,1);{724:}q:=mem[x+5].hh.rh;
if(q>=himemmin)then begin r:=mem[q].hh.rh;
if r<>-268435455 then if mem[r].hh.rh=-268435455 then if not(r>=himemmin
)then if mem[r].hh.b0=11 then begin freenode(r,2);
mem[q].hh.rh:=-268435455;end;end{:724};cleanbox:=x;end;
{:723}{725:}procedure fetch(a:halfword);begin curc:=mem[a].hh.b1;
curf:=eqtb[25583+mem[a].hh.b0+cursize].hh.rh;
if curf=0 then{726:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(335);
end;printsize(cursize);printchar(32);printint(mem[a].hh.b0);print(900);
print(curc);printchar(41);begin helpptr:=4;helpline[3]:=901;
helpline[2]:=902;helpline[1]:=903;helpline[0]:=904;end;error;
curi:=nullcharacter;mem[a].hh.rh:=0;
end{:726}else begin if(curc>=fontbc[curf])and(curc<=fontec[curf])then
curi:=fontinfo[charbase[curf]+curc].qqqq else curi:=nullcharacter;
if not((curi.b0>0))then begin charwarning(curf,curc);mem[a].hh.rh:=0;
end;end;end;{:725}{729:}{737:}procedure makeover(q:halfword);
begin mem[q+1].hh.lh:=overbar(cleanbox(q+1,2*(curstyle div 2)+1),3*
fontinfo[8+parambase[eqtb[25586+cursize].hh.rh]].int,fontinfo[8+
parambase[eqtb[25586+cursize].hh.rh]].int);mem[q+1].hh.rh:=2;end;
{:737}{738:}procedure makeunder(q:halfword);var p,x,y:halfword;
delta:scaled;begin x:=cleanbox(q+1,curstyle);
p:=newkern(3*fontinfo[8+parambase[eqtb[25586+cursize].hh.rh]].int);
mem[x].hh.rh:=p;
mem[p].hh.rh:=fractionrule(fontinfo[8+parambase[eqtb[25586+cursize].hh.
rh]].int);y:=vpackage(x,0,1,1073741823);
delta:=mem[y+3].int+mem[y+2].int+fontinfo[8+parambase[eqtb[25586+cursize
].hh.rh]].int;mem[y+3].int:=mem[x+3].int;
mem[y+2].int:=delta-mem[y+3].int;mem[q+1].hh.lh:=y;mem[q+1].hh.rh:=2;
end;{:738}{739:}procedure makevcenter(q:halfword);var v:halfword;
delta:scaled;begin v:=mem[q+1].hh.lh;
if mem[v].hh.b0<>1 then confusion(552);delta:=mem[v+3].int+mem[v+2].int;
mem[v+3].int:=fontinfo[22+parambase[eqtb[25585+cursize].hh.rh]].int+half
(delta);mem[v+2].int:=delta-mem[v+3].int;end;
{:739}{740:}procedure makeradical(q:halfword);var x,y:halfword;
delta,clr:scaled;begin x:=cleanbox(q+1,2*(curstyle div 2)+1);
if curstyle<2 then clr:=fontinfo[8+parambase[eqtb[25586+cursize].hh.rh]]
.int+(abs(fontinfo[5+parambase[eqtb[25585+cursize].hh.rh]].int)div 4)
else begin clr:=fontinfo[8+parambase[eqtb[25586+cursize].hh.rh]].int;
clr:=clr+(abs(clr)div 4);end;
y:=vardelimiter(q+4,cursize,mem[x+3].int+mem[x+2].int+clr+fontinfo[8+
parambase[eqtb[25586+cursize].hh.rh]].int);
delta:=mem[y+2].int-(mem[x+3].int+mem[x+2].int+clr);
if delta>0 then clr:=clr+half(delta);mem[y+4].int:=-(mem[x+3].int+clr);
mem[y].hh.rh:=overbar(x,clr,mem[y+3].int);mem[q+1].hh.lh:=hpack(y,0,1);
mem[q+1].hh.rh:=2;end;{:740}{741:}procedure makemathaccent(q:halfword);
label 30,31;var p,x,y:halfword;a:integer;c:quarterword;
f:internalfontnumber;i:fourquarters;s:scaled;h:scaled;delta:scaled;
w:scaled;begin fetch(q+4);if(curi.b0>0)then begin i:=curi;c:=curc;
f:=curf;{744:}s:=0;if mem[q+1].hh.rh=1 then begin fetch(q+1);
if((curi.b2)mod 4)=1 then begin a:=ligkernbase[curf]+curi.b3;
curi:=fontinfo[a].qqqq;
if curi.b0>128 then begin a:=ligkernbase[curf]+256*curi.b2+curi.b3
+32768-256*(128);curi:=fontinfo[a].qqqq;end;
while true do begin if curi.b1=skewchar[curf]then begin if curi.b2>=128
then if curi.b0<=128 then s:=fontinfo[kernbase[curf]+256*curi.b2+curi.b3
].int;goto 31;end;if curi.b0>=128 then goto 31;a:=a+curi.b0+1;
curi:=fontinfo[a].qqqq;end;end;end;31:{:744};
x:=cleanbox(q+1,2*(curstyle div 2)+1);w:=mem[x+1].int;h:=mem[x+3].int;
{743:}while true do begin if((i.b2)mod 4)<>2 then goto 30;y:=i.b3;
i:=fontinfo[charbase[f]+y].qqqq;if not(i.b0>0)then goto 30;
if fontinfo[widthbase[f]+i.b0].int>w then goto 30;c:=y;end;30:{:743};
if h<fontinfo[5+parambase[f]].int then delta:=h else delta:=fontinfo[5+
parambase[f]].int;
if(mem[q+2].hh.rh<>0)or(mem[q+3].hh.rh<>0)then if mem[q+1].hh.rh=1 then
{745:}begin flushnodelist(x);x:=newnoad;mem[x+1]:=mem[q+1];
mem[x+2]:=mem[q+2];mem[x+3]:=mem[q+3];mem[q+2].hh:=emptyfield;
mem[q+3].hh:=emptyfield;mem[q+1].hh.rh:=3;mem[q+1].hh.lh:=x;
x:=cleanbox(q+1,curstyle);delta:=delta+mem[x+3].int-h;h:=mem[x+3].int;
end{:745};y:=charbox(f,c);mem[y+4].int:=s+half(w-mem[y+1].int);
mem[y+1].int:=0;p:=newkern(-delta);mem[p].hh.rh:=x;mem[y].hh.rh:=p;
y:=vpackage(y,0,1,1073741823);mem[y+1].int:=mem[x+1].int;
if mem[y+3].int<h then{742:}begin p:=newkern(h-mem[y+3].int);
mem[p].hh.rh:=mem[y+5].hh.rh;mem[y+5].hh.rh:=p;mem[y+3].int:=h;
end{:742};mem[q+1].hh.lh:=y;mem[q+1].hh.rh:=2;end;end;
{:741}{746:}procedure makefraction(q:halfword);var p,v,x,y,z:halfword;
delta,delta1,delta2,shiftup,shiftdown,clr:scaled;
begin if mem[q+1].int=1073741824 then mem[q+1].int:=fontinfo[8+parambase
[eqtb[25586+cursize].hh.rh]].int;
{747:}x:=cleanbox(q+2,curstyle+2-2*(curstyle div 6));
z:=cleanbox(q+3,2*(curstyle div 2)+3-2*(curstyle div 6));
if mem[x+1].int<mem[z+1].int then x:=rebox(x,mem[z+1].int)else z:=rebox(
z,mem[x+1].int);
if curstyle<2 then begin shiftup:=fontinfo[8+parambase[eqtb[25585+
cursize].hh.rh]].int;
shiftdown:=fontinfo[11+parambase[eqtb[25585+cursize].hh.rh]].int;
end else begin shiftdown:=fontinfo[12+parambase[eqtb[25585+cursize].hh.
rh]].int;
if mem[q+1].int<>0 then shiftup:=fontinfo[9+parambase[eqtb[25585+cursize
].hh.rh]].int else shiftup:=fontinfo[10+parambase[eqtb[25585+cursize].hh
.rh]].int;end{:747};
if mem[q+1].int=0 then{748:}begin if curstyle<2 then clr:=7*fontinfo[8+
parambase[eqtb[25586+cursize].hh.rh]].int else clr:=3*fontinfo[8+
parambase[eqtb[25586+cursize].hh.rh]].int;
delta:=half(clr-((shiftup-mem[x+2].int)-(mem[z+3].int-shiftdown)));
if delta>0 then begin shiftup:=shiftup+delta;shiftdown:=shiftdown+delta;
end;
end{:748}else{749:}begin if curstyle<2 then clr:=3*mem[q+1].int else clr
:=mem[q+1].int;delta:=half(mem[q+1].int);
delta1:=clr-((shiftup-mem[x+2].int)-(fontinfo[22+parambase[eqtb[25585+
cursize].hh.rh]].int+delta));
delta2:=clr-((fontinfo[22+parambase[eqtb[25585+cursize].hh.rh]].int-
delta)-(mem[z+3].int-shiftdown));
if delta1>0 then shiftup:=shiftup+delta1;
if delta2>0 then shiftdown:=shiftdown+delta2;end{:749};
{750:}v:=newnullbox;mem[v].hh.b0:=1;mem[v+3].int:=shiftup+mem[x+3].int;
mem[v+2].int:=mem[z+2].int+shiftdown;mem[v+1].int:=mem[x+1].int;
if mem[q+1].int=0 then begin p:=newkern((shiftup-mem[x+2].int)-(mem[z+3]
.int-shiftdown));mem[p].hh.rh:=z;
end else begin y:=fractionrule(mem[q+1].int);
p:=newkern((fontinfo[22+parambase[eqtb[25585+cursize].hh.rh]].int-delta)
-(mem[z+3].int-shiftdown));mem[y].hh.rh:=p;mem[p].hh.rh:=z;
p:=newkern((shiftup-mem[x+2].int)-(fontinfo[22+parambase[eqtb[25585+
cursize].hh.rh]].int+delta));mem[p].hh.rh:=y;end;mem[x].hh.rh:=p;
mem[v+5].hh.rh:=x{:750};
{751:}if curstyle<2 then delta:=fontinfo[20+parambase[eqtb[25585+cursize
].hh.rh]].int else delta:=fontinfo[21+parambase[eqtb[25585+cursize].hh.
rh]].int;x:=vardelimiter(q+4,cursize,delta);mem[x].hh.rh:=v;
z:=vardelimiter(q+5,cursize,delta);mem[v].hh.rh:=z;
mem[q+1].int:=hpack(x,0,1){:751};end;
{:746}{752:}function makeop(q:halfword):scaled;var delta:scaled;
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
[25585+cursize].hh.rh]].int;mem[q+1].hh.rh:=2;mem[q+1].hh.lh:=x;
end else delta:=0;
if mem[q].hh.b1=1 then{753:}begin x:=cleanbox(q+2,2*(curstyle div 4)+4+(
curstyle mod 2));y:=cleanbox(q+1,curstyle);
z:=cleanbox(q+3,2*(curstyle div 4)+5);v:=newnullbox;mem[v].hh.b0:=1;
mem[v+1].int:=mem[y+1].int;
if mem[x+1].int>mem[v+1].int then mem[v+1].int:=mem[x+1].int;
if mem[z+1].int>mem[v+1].int then mem[v+1].int:=mem[z+1].int;
x:=rebox(x,mem[v+1].int);y:=rebox(y,mem[v+1].int);
z:=rebox(z,mem[v+1].int);mem[x+4].int:=half(delta);
mem[z+4].int:=-mem[x+4].int;mem[v+3].int:=mem[y+3].int;
mem[v+2].int:=mem[y+2].int;
{754:}if mem[q+2].hh.rh=0 then begin freenode(x,7);mem[v+5].hh.rh:=y;
end else begin shiftup:=fontinfo[11+parambase[eqtb[25586+cursize].hh.rh]
].int-mem[x+2].int;
if shiftup<fontinfo[9+parambase[eqtb[25586+cursize].hh.rh]].int then
shiftup:=fontinfo[9+parambase[eqtb[25586+cursize].hh.rh]].int;
p:=newkern(shiftup);mem[p].hh.rh:=y;mem[x].hh.rh:=p;
p:=newkern(fontinfo[13+parambase[eqtb[25586+cursize].hh.rh]].int);
mem[p].hh.rh:=x;mem[v+5].hh.rh:=p;
mem[v+3].int:=mem[v+3].int+fontinfo[13+parambase[eqtb[25586+cursize].hh.
rh]].int+mem[x+3].int+mem[x+2].int+shiftup;end;
if mem[q+3].hh.rh=0 then freenode(z,7)else begin shiftdown:=fontinfo[12+
parambase[eqtb[25586+cursize].hh.rh]].int-mem[z+3].int;
if shiftdown<fontinfo[10+parambase[eqtb[25586+cursize].hh.rh]].int then
shiftdown:=fontinfo[10+parambase[eqtb[25586+cursize].hh.rh]].int;
p:=newkern(shiftdown);mem[y].hh.rh:=p;mem[p].hh.rh:=z;
p:=newkern(fontinfo[13+parambase[eqtb[25586+cursize].hh.rh]].int);
mem[z].hh.rh:=p;
mem[v+2].int:=mem[v+2].int+fontinfo[13+parambase[eqtb[25586+cursize].hh.
rh]].int+mem[z+3].int+mem[z+2].int+shiftdown;end{:754};mem[q+1].int:=v;
end{:753};makeop:=delta;end;{:752}{755:}procedure makeord(q:halfword);
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
while true do begin{756:}if curi.b1=curc then if curi.b0<=128 then if
curi.b2>=128 then begin p:=newkern(fontinfo[kernbase[curf]+256*curi.b2+
curi.b3].int);mem[p].hh.rh:=mem[q].hh.rh;mem[q].hh.rh:=p;goto 10;
end else begin begin if interrupt<>0 then pauseforinstructions;end;
case curi.b2 of 1,5:mem[q+1].hh.b1:=curi.b3;2,6:mem[p+1].hh.b1:=curi.b3;
3,7,11:begin r:=newnoad;mem[r+1].hh.b1:=curi.b3;
mem[r+1].hh.b0:=mem[q+1].hh.b0;mem[q].hh.rh:=r;mem[r].hh.rh:=p;
if curi.b2<11 then mem[r+1].hh.rh:=1 else mem[r+1].hh.rh:=4;end;
others:begin mem[q].hh.rh:=mem[p].hh.rh;mem[q+1].hh.b1:=curi.b3;
mem[q+3]:=mem[p+3];mem[q+2]:=mem[p+2];freenode(p,4);end end;
if curi.b2>3 then goto 10;mem[q+1].hh.rh:=1;goto 20;end{:756};
if curi.b0>=128 then goto 10;a:=a+curi.b0+1;curi:=fontinfo[a].qqqq;end;
end;end;end;10:end;{:755}{759:}procedure makescripts(q:halfword;
delta:scaled);var p,x,y,z:halfword;shiftup,shiftdown,clr:scaled;
t:smallnumber;begin p:=mem[q+1].int;
if(p>=himemmin)then begin shiftup:=0;shiftdown:=0;
end else begin z:=hpack(p,0,1);if curstyle<4 then t:=16 else t:=32;
shiftup:=mem[z+3].int-fontinfo[18+parambase[eqtb[25585+t].hh.rh]].int;
shiftdown:=mem[z+2].int+fontinfo[19+parambase[eqtb[25585+t].hh.rh]].int;
freenode(z,7);end;
if mem[q+2].hh.rh=0 then{760:}begin x:=cleanbox(q+3,2*(curstyle div 4)+5
);mem[x+1].int:=mem[x+1].int+eqtb[27753].int;
if shiftdown<fontinfo[16+parambase[eqtb[25585+cursize].hh.rh]].int then
shiftdown:=fontinfo[16+parambase[eqtb[25585+cursize].hh.rh]].int;
clr:=mem[x+3].int-(abs(fontinfo[5+parambase[eqtb[25585+cursize].hh.rh]].
int*4)div 5);if shiftdown<clr then shiftdown:=clr;
mem[x+4].int:=shiftdown;
end{:760}else begin{761:}begin x:=cleanbox(q+2,2*(curstyle div 4)+4+(
curstyle mod 2));mem[x+1].int:=mem[x+1].int+eqtb[27753].int;
if odd(curstyle)then clr:=fontinfo[15+parambase[eqtb[25585+cursize].hh.
rh]].int else if curstyle<2 then clr:=fontinfo[13+parambase[eqtb[25585+
cursize].hh.rh]].int else clr:=fontinfo[14+parambase[eqtb[25585+cursize]
.hh.rh]].int;if shiftup<clr then shiftup:=clr;
clr:=mem[x+2].int+(abs(fontinfo[5+parambase[eqtb[25585+cursize].hh.rh]].
int)div 4);if shiftup<clr then shiftup:=clr;end{:761};
if mem[q+3].hh.rh=0 then mem[x+4].int:=-shiftup else{762:}begin y:=
cleanbox(q+3,2*(curstyle div 4)+5);
mem[y+1].int:=mem[y+1].int+eqtb[27753].int;
if shiftdown<fontinfo[17+parambase[eqtb[25585+cursize].hh.rh]].int then
shiftdown:=fontinfo[17+parambase[eqtb[25585+cursize].hh.rh]].int;
clr:=4*fontinfo[8+parambase[eqtb[25586+cursize].hh.rh]].int-((shiftup-
mem[x+2].int)-(mem[y+3].int-shiftdown));
if clr>0 then begin shiftdown:=shiftdown+clr;
clr:=(abs(fontinfo[5+parambase[eqtb[25585+cursize].hh.rh]].int*4)div 5)-
(shiftup-mem[x+2].int);if clr>0 then begin shiftup:=shiftup+clr;
shiftdown:=shiftdown-clr;end;end;mem[x+4].int:=delta;
p:=newkern((shiftup-mem[x+2].int)-(mem[y+3].int-shiftdown));
mem[x].hh.rh:=p;mem[p].hh.rh:=y;x:=vpackage(x,0,1,1073741823);
mem[x+4].int:=shiftdown;end{:762};end;
if mem[q+1].int=-268435455 then mem[q+1].int:=x else begin p:=mem[q+1].
int;while mem[p].hh.rh<>-268435455 do p:=mem[p].hh.rh;mem[p].hh.rh:=x;
end;end;{:759}{765:}function makeleftright(q:halfword;style:smallnumber;
maxd,maxh:scaled):smallnumber;var delta,delta1,delta2:scaled;
begin if style<4 then cursize:=0 else cursize:=16*((style-2)div 2);
delta2:=maxd+fontinfo[22+parambase[eqtb[25585+cursize].hh.rh]].int;
delta1:=maxh+maxd-delta2;if delta2>delta1 then delta1:=delta2;
delta:=(delta1 div 500)*eqtb[27185].int;
delta2:=delta1+delta1-eqtb[27751].int;
if delta<delta2 then delta:=delta2;
mem[q+1].int:=vardelimiter(q+1,cursize,delta);
makeleftright:=mem[q].hh.b0-(10);end;{:765}procedure mlisttohlist;
label 21,82,80,81,83,30;var mlist:halfword;penalties:boolean;
style:smallnumber;savestyle:smallnumber;q:halfword;r:halfword;
rtype:smallnumber;t:smallnumber;p,x,y,z:halfword;pen:integer;
s:smallnumber;maxh,maxd:scaled;delta:scaled;begin mlist:=curmlist;
penalties:=mlistpenalties;style:=curstyle;q:=mlist;r:=-268435455;
rtype:=17;maxh:=0;maxd:=0;
{706:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25585+cursize].hh.rh]].int,18);
end{:706};while q<>-268435455 do{730:}begin{731:}21:delta:=0;
case mem[q].hh.b0 of 18:case rtype of 18,17,19,20,22,30:begin mem[q].hh.
b0:=16;goto 21;end;others:end;
19,21,22,31:begin{732:}if rtype=18 then mem[r].hh.b0:=16{:732};
if mem[q].hh.b0=31 then goto 80;end;{736:}30:goto 80;
25:begin makefraction(q);goto 82;end;17:begin delta:=makeop(q);
if mem[q].hh.b1=1 then goto 82;end;16:makeord(q);20,23:;
24:makeradical(q);27:makeover(q);26:makeunder(q);28:makemathaccent(q);
29:makevcenter(q);{:736}{733:}14:begin curstyle:=mem[q].hh.b1;
{706:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25585+cursize].hh.rh]].int,18);
end{:706};goto 81;end;
15:{734:}begin case curstyle div 2 of 0:begin p:=mem[q+1].hh.lh;
mem[q+1].hh.lh:=-268435455;end;1:begin p:=mem[q+1].hh.rh;
mem[q+1].hh.rh:=-268435455;end;2:begin p:=mem[q+2].hh.lh;
mem[q+2].hh.lh:=-268435455;end;3:begin p:=mem[q+2].hh.rh;
mem[q+2].hh.rh:=-268435455;end;end;flushnodelist(mem[q+1].hh.lh);
flushnodelist(mem[q+1].hh.rh);flushnodelist(mem[q+2].hh.lh);
flushnodelist(mem[q+2].hh.rh);mem[q].hh.b0:=14;mem[q].hh.b1:=curstyle;
mem[q+1].int:=0;mem[q+2].int:=0;
if p<>-268435455 then begin z:=mem[q].hh.rh;mem[q].hh.rh:=p;
while mem[p].hh.rh<>-268435455 do p:=mem[p].hh.rh;mem[p].hh.rh:=z;end;
goto 81;end{:734};3,4,5,8,12,7:goto 81;
2:begin if mem[q+3].int>maxh then maxh:=mem[q+3].int;
if mem[q+2].int>maxd then maxd:=mem[q+2].int;goto 81;end;
10:begin{735:}if mem[q].hh.b1=99 then begin x:=mem[q+1].hh.lh;
y:=mathglue(x,curmu);deleteglueref(x);mem[q+1].hh.lh:=y;mem[q].hh.b1:=0;
end else if(cursize<>0)and(mem[q].hh.b1=98)then begin p:=mem[q].hh.rh;
if p<>-268435455 then if(mem[p].hh.b0=10)or(mem[p].hh.b0=11)then begin
mem[q].hh.rh:=mem[p].hh.rh;mem[p].hh.rh:=-268435455;flushnodelist(p);
end;end{:735};goto 81;end;11:begin mathkern(q,curmu);goto 81;end;
{:733}others:confusion(905)end;
{757:}case mem[q+1].hh.rh of 1,4:{758:}begin fetch(q+1);
if(curi.b0>0)then begin delta:=fontinfo[italicbase[curf]+(curi.b2)div 4]
.int;p:=newcharacter(curf,curc);
if(mem[q+1].hh.rh=4)and(fontinfo[2+parambase[curf]].int<>0)then delta:=0
;
if(mem[q+3].hh.rh=0)and(delta<>0)then begin mem[p].hh.rh:=newkern(delta)
;delta:=0;end;end else p:=-268435455;end{:758};0:p:=-268435455;
2:p:=mem[q+1].hh.lh;3:begin curmlist:=mem[q+1].hh.lh;
savestyle:=curstyle;mlistpenalties:=false;mlisttohlist;
curstyle:=savestyle;
{706:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25585+cursize].hh.rh]].int,18);
end{:706};p:=hpack(mem[memtop-3].hh.rh,0,1);end;
others:confusion(906)end;mem[q+1].int:=p;
if(mem[q+3].hh.rh=0)and(mem[q+2].hh.rh=0)then goto 82;
makescripts(q,delta){:757}{:731};82:z:=hpack(mem[q+1].int,0,1);
if mem[z+3].int>maxh then maxh:=mem[z+3].int;
if mem[z+2].int>maxd then maxd:=mem[z+2].int;freenode(z,7);80:r:=q;
rtype:=mem[r].hh.b0;81:q:=mem[q].hh.rh;end{:730};
{732:}if rtype=18 then mem[r].hh.b0:=16{:732};{763:}p:=memtop-3;
mem[p].hh.rh:=-268435455;q:=mlist;rtype:=0;curstyle:=style;
{706:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25585+cursize].hh.rh]].int,18);
end{:706};while q<>-268435455 do begin{764:}t:=16;s:=4;pen:=10000;
case mem[q].hh.b0 of 17,20,21,22,23:t:=mem[q].hh.b0;18:begin t:=18;
pen:=eqtb[27176].int;end;19:begin t:=19;pen:=eqtb[27177].int;end;
16,29,27,26:;24:s:=5;28:s:=5;25:begin t:=23;s:=6;end;
30,31:t:=makeleftright(q,style,maxd,maxh);
14:{766:}begin curstyle:=mem[q].hh.b1;s:=3;
{706:}begin if curstyle<4 then cursize:=0 else cursize:=16*((curstyle-2)
div 2);
curmu:=xovern(fontinfo[6+parambase[eqtb[25585+cursize].hh.rh]].int,18);
end{:706};goto 83;end{:766};8,12,2,7,5,3,4,10,11:begin mem[p].hh.rh:=q;
p:=q;q:=mem[q].hh.rh;mem[p].hh.rh:=-268435455;goto 30;end;
others:confusion(907)end{:764};
{769:}if rtype>0 then begin case strpool[rtype*8+t+magicoffset]of 48:x:=
0;49:if curstyle<4 then x:=15 else x:=0;50:x:=15;
51:if curstyle<4 then x:=16 else x:=0;
52:if curstyle<4 then x:=17 else x:=0;others:confusion(909)end;
if x<>0 then begin y:=mathglue(eqtb[24527+x].hh.rh,curmu);z:=newglue(y);
mem[y].hh.rh:=-268435455;mem[p].hh.rh:=z;p:=z;mem[z].hh.b1:=x+1;end;
end{:769};
{770:}if mem[q+1].int<>-268435455 then begin mem[p].hh.rh:=mem[q+1].int;
repeat p:=mem[p].hh.rh;until mem[p].hh.rh=-268435455;end;
if penalties then if mem[q].hh.rh<>-268435455 then if pen<10000 then
begin rtype:=mem[mem[q].hh.rh].hh.b0;
if rtype<>12 then if rtype<>19 then begin z:=newpenalty(pen);
mem[p].hh.rh:=z;p:=z;end;end{:770};rtype:=t;83:r:=q;q:=mem[q].hh.rh;
freenode(r,s);30:end{:763};end;{:729}{775:}procedure pushalignment;
var p:halfword;begin p:=getnode(5);mem[p].hh.rh:=alignptr;
mem[p].hh.lh:=curalign;mem[p+1].hh.lh:=mem[memtop-8].hh.rh;
mem[p+1].hh.rh:=curspan;mem[p+2].int:=curloop;mem[p+3].int:=alignstate;
mem[p+4].hh.lh:=curhead;mem[p+4].hh.rh:=curtail;alignptr:=p;
curhead:=getavail;end;procedure popalignment;var p:halfword;
begin begin mem[curhead].hh.rh:=avail;avail:=curhead;
ifdef('STAT')decr(dynused);endif('STAT')end;p:=alignptr;
curtail:=mem[p+4].hh.rh;curhead:=mem[p+4].hh.lh;
alignstate:=mem[p+3].int;curloop:=mem[p+2].int;curspan:=mem[p+1].hh.rh;
mem[memtop-8].hh.rh:=mem[p+1].hh.lh;curalign:=mem[p].hh.lh;
alignptr:=mem[p].hh.rh;freenode(p,5);end;
{:775}{777:}{785:}procedure getpreambletoken;label 20;begin 20:gettoken;
while(curchr=256)and(curcmd=4)do begin gettoken;
if curcmd>100 then begin expand;gettoken;end;end;
if curcmd=9 then fatalerror(607);
if(curcmd=75)and(curchr=24538)then begin scanoptionalequals;scanglue(2);
if eqtb[27210].int>0 then geqdefine(24538,117,curval)else eqdefine(24538
,117,curval);goto 20;end;end;{:785}procedure alignpeek;forward;
procedure normalparagraph;forward;procedure initalign;label 30,31,32,22;
var savecsptr:halfword;p:halfword;begin savecsptr:=curcs;pushalignment;
alignstate:=-1000000;
{779:}if(curlist.modefield=203)and((curlist.tailfield<>curlist.headfield
)or(curlist.auxfield.int<>-268435455))then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(262);
print(695);end;printesc(533);print(910);begin helpptr:=3;
helpline[2]:=911;helpline[1]:=912;helpline[0]:=913;end;error;flushmath;
end{:779};pushnest;
{778:}if curlist.modefield=203 then begin curlist.modefield:=-1;
curlist.auxfield.int:=nest[nestptr-2].auxfield.int;
end else if curlist.modefield>0 then curlist.modefield:=-curlist.
modefield{:778};scanspec(6,false);{780:}mem[memtop-8].hh.rh:=-268435455;
curalign:=memtop-8;curloop:=-268435455;scannerstatus:=4;
warningindex:=savecsptr;alignstate:=-1000000;
while true do begin{781:}mem[curalign].hh.rh:=newparamglue(11);
curalign:=mem[curalign].hh.rh{:781};if curcmd=5 then goto 30;
{782:}{786:}p:=memtop-4;mem[p].hh.rh:=-268435455;
while true do begin getpreambletoken;if curcmd=6 then goto 31;
if(curcmd<=5)and(curcmd>=4)and(alignstate=-1000000)then if(p=memtop-4)
and(curloop=-268435455)and(curcmd=4)then curloop:=curalign else begin
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(919);
end;begin helpptr:=3;helpline[2]:=920;helpline[1]:=921;helpline[0]:=922;
end;backerror;goto 31;
end else if(curcmd<>10)or(p<>memtop-4)then begin mem[p].hh.rh:=getavail;
p:=mem[p].hh.rh;mem[p].hh.lh:=curtok;end;end;31:{:786};
mem[curalign].hh.rh:=newnullbox;curalign:=mem[curalign].hh.rh;
mem[curalign].hh.lh:=memtop-9;mem[curalign+1].int:=-1073741824;
mem[curalign+3].int:=mem[memtop-4].hh.rh;{787:}p:=memtop-4;
mem[p].hh.rh:=-268435455;while true do begin 22:getpreambletoken;
if(curcmd<=5)and(curcmd>=4)and(alignstate=-1000000)then goto 32;
if curcmd=6 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(923);
end;begin helpptr:=3;helpline[2]:=920;helpline[1]:=921;helpline[0]:=924;
end;error;goto 22;end;mem[p].hh.rh:=getavail;p:=mem[p].hh.rh;
mem[p].hh.lh:=curtok;end;32:mem[p].hh.rh:=getavail;p:=mem[p].hh.rh;
mem[p].hh.lh:=19614{:787};
mem[curalign+2].int:=mem[memtop-4].hh.rh{:782};end;
30:scannerstatus:=0{:780};newsavelevel(6);
if eqtb[25065].hh.rh<>-268435455 then begintokenlist(eqtb[25065].hh.rh,
13);alignpeek;end;{:777}{789:}{790:}procedure initspan(p:halfword);
begin pushnest;
if curlist.modefield=-102 then curlist.auxfield.hh.lh:=1000 else begin
curlist.auxfield.int:=-65536000;normalparagraph;end;curspan:=p;end;
{:790}procedure initrow;begin pushnest;
curlist.modefield:=(-103)-curlist.modefield;
if curlist.modefield=-102 then curlist.auxfield.hh.lh:=0 else curlist.
auxfield.int:=0;
begin mem[curlist.tailfield].hh.rh:=newglue(mem[mem[memtop-8].hh.rh+1].
hh.lh);curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b1:=12;
curalign:=mem[mem[memtop-8].hh.rh].hh.rh;curtail:=curhead;
initspan(curalign);end;{:789}{791:}procedure initcol;
begin mem[curalign+5].hh.lh:=curcmd;
if curcmd=63 then alignstate:=0 else begin backinput;
begintokenlist(mem[curalign+3].int,1);end;end;
{:791}{794:}function fincol:boolean;label 10;var p:halfword;
q,r:halfword;s:halfword;u:halfword;w:scaled;o:glueord;n:halfword;
begin if curalign=-268435455 then confusion(925);q:=mem[curalign].hh.rh;
if q=-268435455 then confusion(925);
if alignstate<500000 then fatalerror(607);p:=mem[q].hh.rh;
{795:}if(p=-268435455)and(mem[curalign+5].hh.lh<257)then if curloop<>
-268435455 then{796:}begin mem[q].hh.rh:=newnullbox;p:=mem[q].hh.rh;
mem[p].hh.lh:=memtop-9;mem[p+1].int:=-1073741824;
curloop:=mem[curloop].hh.rh;{797:}q:=memtop-4;r:=mem[curloop+3].int;
while r<>-268435455 do begin mem[q].hh.rh:=getavail;q:=mem[q].hh.rh;
mem[q].hh.lh:=mem[r].hh.lh;r:=mem[r].hh.rh;end;mem[q].hh.rh:=-268435455;
mem[p+3].int:=mem[memtop-4].hh.rh;q:=memtop-4;r:=mem[curloop+2].int;
while r<>-268435455 do begin mem[q].hh.rh:=getavail;q:=mem[q].hh.rh;
mem[q].hh.lh:=mem[r].hh.lh;r:=mem[r].hh.rh;end;mem[q].hh.rh:=-268435455;
mem[p+2].int:=mem[memtop-4].hh.rh{:797};curloop:=mem[curloop].hh.rh;
mem[p].hh.rh:=newglue(mem[curloop+1].hh.lh);
end{:796}else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(926);
end;printesc(915);begin helpptr:=3;helpline[2]:=927;helpline[1]:=928;
helpline[0]:=929;end;mem[curalign+5].hh.lh:=257;error;end{:795};
if mem[curalign+5].hh.lh<>256 then begin unsave;newsavelevel(6);
{799:}begin if curlist.modefield=-102 then begin adjusttail:=curtail;
u:=hpack(mem[curlist.headfield].hh.rh,0,1);w:=mem[u+1].int;
curtail:=adjusttail;adjusttail:=-268435455;
end else begin u:=vpackage(mem[curlist.headfield].hh.rh,0,1,0);
w:=mem[u+3].int;end;n:=0;
if curspan<>curalign then{801:}begin q:=curspan;repeat incr(n);
q:=mem[mem[q].hh.rh].hh.rh;until q=curalign;
if n>255 then confusion(930);q:=curspan;
while mem[mem[q].hh.lh].hh.rh<n do q:=mem[q].hh.lh;
if mem[mem[q].hh.lh].hh.rh>n then begin s:=getnode(2);
mem[s].hh.lh:=mem[q].hh.lh;mem[s].hh.rh:=n;mem[q].hh.lh:=s;
mem[s+1].int:=w;
end else if mem[mem[q].hh.lh+1].int<w then mem[mem[q].hh.lh+1].int:=w;
end{:801}else if w>mem[curalign+1].int then mem[curalign+1].int:=w;
mem[u].hh.b0:=13;mem[u].hh.b1:=n;
{662:}if totalstretch[3]<>0 then o:=3 else if totalstretch[2]<>0 then o
:=2 else if totalstretch[1]<>0 then o:=1 else o:=0{:662};
mem[u+5].hh.b1:=o;mem[u+6].int:=totalstretch[o];
{668:}if totalshrink[3]<>0 then o:=3 else if totalshrink[2]<>0 then o:=2
else if totalshrink[1]<>0 then o:=1 else o:=0{:668};mem[u+5].hh.b0:=o;
mem[u+4].int:=totalshrink[o];popnest;mem[curlist.tailfield].hh.rh:=u;
curlist.tailfield:=u;end{:799};
{798:}begin mem[curlist.tailfield].hh.rh:=newglue(mem[mem[curalign].hh.
rh+1].hh.lh);curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b1:=12{:798};
if mem[curalign+5].hh.lh>=257 then begin fincol:=true;goto 10;end;
initspan(p);end;alignstate:=1000000;{409:}repeat getxtoken;
until curcmd<>10{:409};curalign:=p;initcol;fincol:=false;10:end;
{:794}{802:}procedure finrow;var p:halfword;
begin if curlist.modefield=-102 then begin p:=hpack(mem[curlist.
headfield].hh.rh,0,1);popnest;appendtovlist(p);
if curhead<>curtail then begin mem[curlist.tailfield].hh.rh:=mem[curhead
].hh.rh;curlist.tailfield:=curtail;end;
end else begin p:=vpackage(mem[curlist.headfield].hh.rh,0,1,1073741823);
popnest;mem[curlist.tailfield].hh.rh:=p;curlist.tailfield:=p;
curlist.auxfield.hh.lh:=1000;end;mem[p].hh.b0:=13;mem[p+6].int:=0;
if eqtb[25065].hh.rh<>-268435455 then begintokenlist(eqtb[25065].hh.rh,
13);alignpeek;end;{:802}{803:}procedure doassignments;forward;
procedure resumeafterdisplay;forward;procedure buildpage;forward;
procedure finalign;var p,q,r,s,u,v:halfword;t,w:scaled;o:scaled;
n:halfword;rulesave:scaled;auxsave:memoryword;
begin if curgroup<>6 then confusion(931);unsave;
if curgroup<>6 then confusion(932);unsave;
if nest[nestptr-1].modefield=203 then o:=eqtb[27756].int else o:=0;
{804:}q:=mem[mem[memtop-8].hh.rh].hh.rh;repeat flushlist(mem[q+3].int);
flushlist(mem[q+2].int);p:=mem[mem[q].hh.rh].hh.rh;
if mem[q+1].int=-1073741824 then{805:}begin mem[q+1].int:=0;
r:=mem[q].hh.rh;s:=mem[r+1].hh.lh;
if s<>membot then begin incr(mem[membot].hh.rh);deleteglueref(s);
mem[r+1].hh.lh:=membot;end;end{:805};
if mem[q].hh.lh<>memtop-9 then{806:}begin t:=mem[q+1].int+mem[mem[mem[q]
.hh.rh+1].hh.lh+1].int;r:=mem[q].hh.lh;s:=memtop-9;mem[s].hh.lh:=p;n:=1;
repeat mem[r+1].int:=mem[r+1].int-t;u:=mem[r].hh.lh;
while mem[r].hh.rh>n do begin s:=mem[s].hh.lh;
n:=mem[mem[s].hh.lh].hh.rh+1;end;
if mem[r].hh.rh<n then begin mem[r].hh.lh:=mem[s].hh.lh;mem[s].hh.lh:=r;
decr(mem[r].hh.rh);s:=r;
end else begin if mem[r+1].int>mem[mem[s].hh.lh+1].int then mem[mem[s].
hh.lh+1].int:=mem[r+1].int;freenode(r,2);end;r:=u;until r=memtop-9;
end{:806};mem[q].hh.b0:=13;mem[q].hh.b1:=0;mem[q+3].int:=0;
mem[q+2].int:=0;mem[q+5].hh.b1:=0;mem[q+5].hh.b0:=0;mem[q+6].int:=0;
mem[q+4].int:=0;q:=p;until q=-268435455{:804};{807:}saveptr:=saveptr-2;
packbeginline:=-curlist.mlfield;
if curlist.modefield=-1 then begin rulesave:=eqtb[27757].int;
eqtb[27757].int:=0;
p:=hpack(mem[memtop-8].hh.rh,savestack[saveptr+1].int,savestack[saveptr
+0].int);eqtb[27757].int:=rulesave;
end else begin q:=mem[mem[memtop-8].hh.rh].hh.rh;
repeat mem[q+3].int:=mem[q+1].int;mem[q+1].int:=0;
q:=mem[mem[q].hh.rh].hh.rh;until q=-268435455;
p:=vpackage(mem[memtop-8].hh.rh,savestack[saveptr+1].int,savestack[
saveptr+0].int,1073741823);q:=mem[mem[memtop-8].hh.rh].hh.rh;
repeat mem[q+1].int:=mem[q+3].int;mem[q+3].int:=0;
q:=mem[mem[q].hh.rh].hh.rh;until q=-268435455;end;
packbeginline:=0{:807};{808:}q:=mem[curlist.headfield].hh.rh;
s:=curlist.headfield;
while q<>-268435455 do begin if not(q>=himemmin)then if mem[q].hh.b0=13
then{810:}begin if curlist.modefield=-1 then begin mem[q].hh.b0:=0;
mem[q+1].int:=mem[p+1].int;end else begin mem[q].hh.b0:=1;
mem[q+3].int:=mem[p+3].int;end;mem[q+5].hh.b1:=mem[p+5].hh.b1;
mem[q+5].hh.b0:=mem[p+5].hh.b0;mem[q+6].gr:=mem[p+6].gr;mem[q+4].int:=o;
r:=mem[mem[q+5].hh.rh].hh.rh;s:=mem[mem[p+5].hh.rh].hh.rh;
repeat{811:}n:=mem[r].hh.b1;t:=mem[s+1].int;w:=t;u:=memtop-4;
while n>0 do begin decr(n);{812:}s:=mem[s].hh.rh;v:=mem[s+1].hh.lh;
mem[u].hh.rh:=newglue(v);u:=mem[u].hh.rh;mem[u].hh.b1:=12;
t:=t+mem[v+1].int;
if mem[p+5].hh.b0=1 then begin if mem[v].hh.b0=mem[p+5].hh.b1 then t:=t+
round(mem[p+6].gr*mem[v+2].int);
end else if mem[p+5].hh.b0=2 then begin if mem[v].hh.b1=mem[p+5].hh.b1
then t:=t-round(mem[p+6].gr*mem[v+3].int);end;s:=mem[s].hh.rh;
mem[u].hh.rh:=newnullbox;u:=mem[u].hh.rh;t:=t+mem[s+1].int;
if curlist.modefield=-1 then mem[u+1].int:=mem[s+1].int else begin mem[u
].hh.b0:=1;mem[u+3].int:=mem[s+1].int;end{:812};end;
if curlist.modefield=-1 then{813:}begin mem[r+3].int:=mem[q+3].int;
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
end{:813}else{814:}begin mem[r+1].int:=mem[q+1].int;
if t=mem[r+3].int then begin mem[r+5].hh.b0:=0;mem[r+5].hh.b1:=0;
mem[r+6].gr:=0.0;
end else if t>mem[r+3].int then begin mem[r+5].hh.b0:=1;
if mem[r+6].int=0 then mem[r+6].gr:=0.0 else mem[r+6].gr:=(t-mem[r+3].
int)/mem[r+6].int;end else begin mem[r+5].hh.b1:=mem[r+5].hh.b0;
mem[r+5].hh.b0:=2;
if mem[r+4].int=0 then mem[r+6].gr:=0.0 else if(mem[r+5].hh.b1=0)and(mem
[r+3].int-t>mem[r+4].int)then mem[r+6].gr:=1.0 else mem[r+6].gr:=(mem[r
+3].int-t)/mem[r+4].int;end;mem[r+3].int:=w;mem[r].hh.b0:=1;end{:814};
mem[r+4].int:=0;if u<>memtop-4 then begin mem[u].hh.rh:=mem[r].hh.rh;
mem[r].hh.rh:=mem[memtop-4].hh.rh;r:=u;end{:811};
r:=mem[mem[r].hh.rh].hh.rh;s:=mem[mem[s].hh.rh].hh.rh;
until r=-268435455;
end{:810}else if mem[q].hh.b0=2 then{809:}begin if(mem[q+1].int=
-1073741824)then mem[q+1].int:=mem[p+1].int;
if(mem[q+3].int=-1073741824)then mem[q+3].int:=mem[p+3].int;
if(mem[q+2].int=-1073741824)then mem[q+2].int:=mem[p+2].int;
if o<>0 then begin r:=mem[q].hh.rh;mem[q].hh.rh:=-268435455;
q:=hpack(q,0,1);mem[q+4].int:=o;mem[q].hh.rh:=r;mem[s].hh.rh:=q;end;
end{:809};s:=q;q:=mem[q].hh.rh;end{:808};flushnodelist(p);popalignment;
{815:}auxsave:=curlist.auxfield;p:=mem[curlist.headfield].hh.rh;
q:=curlist.tailfield;popnest;
if curlist.modefield=203 then{1209:}begin doassignments;
if curcmd<>3 then{1210:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1186);
end;begin helpptr:=2;helpline[1]:=911;helpline[0]:=912;end;backerror;
end{:1210}else{1200:}begin getxtoken;
if curcmd<>3 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1182);
end;begin helpptr:=2;helpline[1]:=1183;helpline[0]:=1184;end;backerror;
end;end{:1200};popnest;
begin mem[curlist.tailfield].hh.rh:=newpenalty(eqtb[27178].int);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
begin mem[curlist.tailfield].hh.rh:=newparamglue(3);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.rh:=p;
if p<>-268435455 then curlist.tailfield:=q;
begin mem[curlist.tailfield].hh.rh:=newpenalty(eqtb[27179].int);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
begin mem[curlist.tailfield].hh.rh:=newparamglue(4);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
curlist.auxfield.int:=auxsave.int;resumeafterdisplay;
end{:1209}else begin curlist.auxfield:=auxsave;
mem[curlist.tailfield].hh.rh:=p;
if p<>-268435455 then curlist.tailfield:=q;
if curlist.modefield=1 then buildpage;end{:815};end;
{788:}procedure alignpeek;label 20;begin 20:alignstate:=1000000;
{409:}repeat getxtoken;until curcmd<>10{:409};
if curcmd=34 then begin scanleftbrace;newsavelevel(7);
if curlist.modefield=-1 then normalparagraph;
end else if curcmd=2 then finalign else if(curcmd=5)and(curchr=258)then
goto 20 else begin initrow;initcol;end;end;
{:788}{:803}{818:}{829:}function finiteshrink(p:halfword):halfword;
var q:halfword;
begin if noshrinkerroryet then begin noshrinkerroryet:=false;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(933);
end;begin helpptr:=5;helpline[4]:=934;helpline[3]:=935;helpline[2]:=936;
helpline[1]:=937;helpline[0]:=938;end;error;end;q:=newspec(p);
mem[q].hh.b1:=0;deleteglueref(p);finiteshrink:=q;end;
{:829}{832:}procedure trybreak(pi:integer;breaktype:smallnumber);
label 10,30,31,22,60;var r:halfword;prevr:halfword;oldl:halfword;
nobreakyet:boolean;{833:}prevprevr:halfword;s:halfword;q:halfword;
v:halfword;t:integer;f:internalfontnumber;l:halfword;
noderstaysactive:boolean;linewidth:scaled;fitclass:0..3;b:halfword;
d:integer;artificialdemerits:boolean;savelink:halfword;shortfall:scaled;
{:833}begin{834:}if abs(pi)>=10000 then if pi>0 then goto 10 else pi:=
-10000{:834};nobreakyet:=true;prevr:=memtop-7;oldl:=0;
curactivewidth[1]:=activewidth[1];curactivewidth[2]:=activewidth[2];
curactivewidth[3]:=activewidth[3];curactivewidth[4]:=activewidth[4];
curactivewidth[5]:=activewidth[5];curactivewidth[6]:=activewidth[6];
while true do begin 22:r:=mem[prevr].hh.rh;
{835:}if mem[r].hh.b0=2 then begin curactivewidth[1]:=curactivewidth[1]+
mem[r+1].int;curactivewidth[2]:=curactivewidth[2]+mem[r+2].int;
curactivewidth[3]:=curactivewidth[3]+mem[r+3].int;
curactivewidth[4]:=curactivewidth[4]+mem[r+4].int;
curactivewidth[5]:=curactivewidth[5]+mem[r+5].int;
curactivewidth[6]:=curactivewidth[6]+mem[r+6].int;prevprevr:=prevr;
prevr:=r;goto 22;end{:835};{838:}begin l:=mem[r+1].hh.lh;
if l>oldl then begin if(minimumdemerits<1073741823)and((oldl<>easyline)
or(r=memtop-7))then{839:}begin if nobreakyet then{840:}begin nobreakyet
:=false;breakwidth[1]:=background[1];breakwidth[2]:=background[2];
breakwidth[3]:=background[3];breakwidth[4]:=background[4];
breakwidth[5]:=background[5];breakwidth[6]:=background[6];s:=curp;
if breaktype>0 then if curp<>-268435455 then{843:}begin t:=mem[curp].hh.
b1;v:=curp;s:=mem[curp+1].hh.rh;while t>0 do begin decr(t);
v:=mem[v].hh.rh;{844:}if(v>=himemmin)then begin f:=mem[v].hh.b0;
breakwidth[1]:=breakwidth[1]-fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[v].hh.b1)].qqqq.b0].int;
end else case mem[v].hh.b0 of 6:begin f:=mem[v+1].hh.b0;
breakwidth[1]:=breakwidth[1]-fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[v+1].hh.b1)].qqqq.b0].int;end;
0,1,2,11:breakwidth[1]:=breakwidth[1]-mem[v+1].int;
others:confusion(939)end{:844};end;
while s<>-268435455 do begin{845:}if(s>=himemmin)then begin f:=mem[s].hh
.b0;
breakwidth[1]:=breakwidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[s].hh.b1)].qqqq.b0].int;
end else case mem[s].hh.b0 of 6:begin f:=mem[s+1].hh.b0;
breakwidth[1]:=breakwidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[s+1].hh.b1)].qqqq.b0].int;end;
0,1,2,11:breakwidth[1]:=breakwidth[1]+mem[s+1].int;
others:confusion(940)end{:845};s:=mem[s].hh.rh;end;
breakwidth[1]:=breakwidth[1]+discwidth;
if mem[curp+1].hh.rh=-268435455 then s:=mem[v].hh.rh;end{:843};
while s<>-268435455 do begin if(s>=himemmin)then goto 30;
case mem[s].hh.b0 of 10:{841:}begin v:=mem[s+1].hh.lh;
breakwidth[1]:=breakwidth[1]-mem[v+1].int;
breakwidth[2+mem[v].hh.b0]:=breakwidth[2+mem[v].hh.b0]-mem[v+2].int;
breakwidth[6]:=breakwidth[6]-mem[v+3].int;end{:841};12:;
9:breakwidth[1]:=breakwidth[1]-mem[s+1].int;
11:if mem[s].hh.b1<>1 then goto 30 else breakwidth[1]:=breakwidth[1]-mem
[s+1].int;others:goto 30 end;s:=mem[s].hh.rh;end;30:end{:840};
{846:}if mem[prevr].hh.b0=2 then begin mem[prevr+1].int:=mem[prevr+1].
int-curactivewidth[1]+breakwidth[1];
mem[prevr+2].int:=mem[prevr+2].int-curactivewidth[2]+breakwidth[2];
mem[prevr+3].int:=mem[prevr+3].int-curactivewidth[3]+breakwidth[3];
mem[prevr+4].int:=mem[prevr+4].int-curactivewidth[4]+breakwidth[4];
mem[prevr+5].int:=mem[prevr+5].int-curactivewidth[5]+breakwidth[5];
mem[prevr+6].int:=mem[prevr+6].int-curactivewidth[6]+breakwidth[6];
end else if prevr=memtop-7 then begin activewidth[1]:=breakwidth[1];
activewidth[2]:=breakwidth[2];activewidth[3]:=breakwidth[3];
activewidth[4]:=breakwidth[4];activewidth[5]:=breakwidth[5];
activewidth[6]:=breakwidth[6];end else begin q:=getnode(7);
mem[q].hh.rh:=r;mem[q].hh.b0:=2;mem[q].hh.b1:=0;
mem[q+1].int:=breakwidth[1]-curactivewidth[1];
mem[q+2].int:=breakwidth[2]-curactivewidth[2];
mem[q+3].int:=breakwidth[3]-curactivewidth[3];
mem[q+4].int:=breakwidth[4]-curactivewidth[4];
mem[q+5].int:=breakwidth[5]-curactivewidth[5];
mem[q+6].int:=breakwidth[6]-curactivewidth[6];mem[prevr].hh.rh:=q;
prevprevr:=prevr;prevr:=q;end{:846};
if abs(eqtb[27183].int)>=1073741823-minimumdemerits then minimumdemerits
:=1073741822 else minimumdemerits:=minimumdemerits+abs(eqtb[27183].int);
for fitclass:=0 to 3 do begin if minimaldemerits[fitclass]<=
minimumdemerits then{848:}begin q:=getnode(2);mem[q].hh.rh:=passive;
passive:=q;mem[q+1].hh.rh:=curp;ifdef('STAT')incr(passnumber);
mem[q].hh.lh:=passnumber;
endif('STAT')mem[q+1].hh.lh:=bestplace[fitclass];q:=getnode(3);
mem[q+1].hh.rh:=passive;mem[q+1].hh.lh:=bestplline[fitclass]+1;
mem[q].hh.b1:=fitclass;mem[q].hh.b0:=breaktype;
mem[q+2].int:=minimaldemerits[fitclass];mem[q].hh.rh:=r;
mem[prevr].hh.rh:=q;prevr:=q;
ifdef('STAT')if eqtb[27199].int>0 then{849:}begin printnl(941);
printint(mem[passive].hh.lh);print(942);printint(mem[q+1].hh.lh-1);
printchar(46);printint(fitclass);if breaktype=1 then printchar(45);
print(943);printint(mem[q+2].int);print(944);
if mem[passive+1].hh.lh=-268435455 then printchar(48)else printint(mem[
mem[passive+1].hh.lh].hh.lh);end{:849};endif('STAT')end{:848};
minimaldemerits[fitclass]:=1073741823;end;minimumdemerits:=1073741823;
{847:}if r<>memtop-7 then begin q:=getnode(7);mem[q].hh.rh:=r;
mem[q].hh.b0:=2;mem[q].hh.b1:=0;
mem[q+1].int:=curactivewidth[1]-breakwidth[1];
mem[q+2].int:=curactivewidth[2]-breakwidth[2];
mem[q+3].int:=curactivewidth[3]-breakwidth[3];
mem[q+4].int:=curactivewidth[4]-breakwidth[4];
mem[q+5].int:=curactivewidth[5]-breakwidth[5];
mem[q+6].int:=curactivewidth[6]-breakwidth[6];mem[prevr].hh.rh:=q;
prevprevr:=prevr;prevr:=q;end{:847};end{:839};
if r=memtop-7 then goto 10;
{853:}if l>easyline then begin linewidth:=secondwidth;oldl:=268435454;
end else begin oldl:=l;
if l>lastspecialline then linewidth:=secondwidth else if eqtb[25057].hh.
rh=-268435455 then linewidth:=firstwidth else linewidth:=mem[eqtb[25057]
.hh.rh+2*l].int;end{:853};end;end{:838};
{854:}begin artificialdemerits:=false;
shortfall:=linewidth-curactivewidth[1];
if shortfall>0 then{855:}if(curactivewidth[3]<>0)or(curactivewidth[4]<>0
)or(curactivewidth[5]<>0)then begin b:=0;fitclass:=2;
end else begin if shortfall>7230584 then if curactivewidth[2]<1663497
then begin b:=10000;fitclass:=0;goto 31;end;
b:=badness(shortfall,curactivewidth[2]);
if b>12 then if b>99 then fitclass:=0 else fitclass:=1 else fitclass:=2;
31:end{:855}else{856:}begin if-shortfall>curactivewidth[6]then b:=10001
else b:=badness(-shortfall,curactivewidth[6]);
if b>12 then fitclass:=3 else fitclass:=2;end{:856};
if(b>10000)or(pi=-10000)then{857:}begin if finalpass and(minimumdemerits
=1073741823)and(mem[r].hh.rh=memtop-7)and(prevr=memtop-7)then
artificialdemerits:=true else if b>threshold then goto 60;
noderstaysactive:=false;end{:857}else begin prevr:=r;
if b>threshold then goto 22;noderstaysactive:=true;end;
{858:}if artificialdemerits then d:=0 else{862:}begin d:=eqtb[27169].int
+b;if abs(d)>=10000 then d:=100000000 else d:=d*d;
if pi<>0 then if pi>0 then d:=d+pi*pi else if pi>-10000 then d:=d-pi*pi;
if(breaktype=1)and(mem[r].hh.b0=1)then if curp<>-268435455 then d:=d+
eqtb[27181].int else d:=d+eqtb[27182].int;
if abs(fitclass-mem[r].hh.b1)>1 then d:=d+eqtb[27183].int;end{:862};
ifdef('STAT')if eqtb[27199].int>0 then{859:}begin if printednode<>curp
then{860:}begin printnl(335);
if curp=-268435455 then shortdisplay(mem[printednode].hh.rh)else begin
savelink:=mem[curp].hh.rh;mem[curp].hh.rh:=-268435455;printnl(335);
shortdisplay(mem[printednode].hh.rh);mem[curp].hh.rh:=savelink;end;
printednode:=curp;end{:860};printnl(64);
if curp=-268435455 then printesc(609)else if mem[curp].hh.b0<>10 then
begin if mem[curp].hh.b0=12 then printesc(544)else if mem[curp].hh.b0=7
then printesc(346)else if mem[curp].hh.b0=11 then printesc(337)else
printesc(340);end;print(945);
if mem[r+1].hh.rh=-268435455 then printchar(48)else printint(mem[mem[r+1
].hh.rh].hh.lh);print(946);
if b>10000 then printchar(42)else printint(b);print(947);printint(pi);
print(948);if artificialdemerits then printchar(42)else printint(d);
end{:859};endif('STAT')d:=d+mem[r+2].int;
if d<=minimaldemerits[fitclass]then begin minimaldemerits[fitclass]:=d;
bestplace[fitclass]:=mem[r+1].hh.rh;bestplline[fitclass]:=l;
if d<minimumdemerits then minimumdemerits:=d;end{:858};
if noderstaysactive then goto 22;
60:{863:}mem[prevr].hh.rh:=mem[r].hh.rh;freenode(r,3);
if prevr=memtop-7 then{864:}begin r:=mem[memtop-7].hh.rh;
if mem[r].hh.b0=2 then begin activewidth[1]:=activewidth[1]+mem[r+1].int
;activewidth[2]:=activewidth[2]+mem[r+2].int;
activewidth[3]:=activewidth[3]+mem[r+3].int;
activewidth[4]:=activewidth[4]+mem[r+4].int;
activewidth[5]:=activewidth[5]+mem[r+5].int;
activewidth[6]:=activewidth[6]+mem[r+6].int;
curactivewidth[1]:=activewidth[1];curactivewidth[2]:=activewidth[2];
curactivewidth[3]:=activewidth[3];curactivewidth[4]:=activewidth[4];
curactivewidth[5]:=activewidth[5];curactivewidth[6]:=activewidth[6];
mem[memtop-7].hh.rh:=mem[r].hh.rh;freenode(r,7);end;
end{:864}else if mem[prevr].hh.b0=2 then begin r:=mem[prevr].hh.rh;
if r=memtop-7 then begin curactivewidth[1]:=curactivewidth[1]-mem[prevr
+1].int;curactivewidth[2]:=curactivewidth[2]-mem[prevr+2].int;
curactivewidth[3]:=curactivewidth[3]-mem[prevr+3].int;
curactivewidth[4]:=curactivewidth[4]-mem[prevr+4].int;
curactivewidth[5]:=curactivewidth[5]-mem[prevr+5].int;
curactivewidth[6]:=curactivewidth[6]-mem[prevr+6].int;
mem[prevprevr].hh.rh:=memtop-7;freenode(prevr,7);prevr:=prevprevr;
end else if mem[r].hh.b0=2 then begin curactivewidth[1]:=curactivewidth[
1]+mem[r+1].int;curactivewidth[2]:=curactivewidth[2]+mem[r+2].int;
curactivewidth[3]:=curactivewidth[3]+mem[r+3].int;
curactivewidth[4]:=curactivewidth[4]+mem[r+4].int;
curactivewidth[5]:=curactivewidth[5]+mem[r+5].int;
curactivewidth[6]:=curactivewidth[6]+mem[r+6].int;
mem[prevr+1].int:=mem[prevr+1].int+mem[r+1].int;
mem[prevr+2].int:=mem[prevr+2].int+mem[r+2].int;
mem[prevr+3].int:=mem[prevr+3].int+mem[r+3].int;
mem[prevr+4].int:=mem[prevr+4].int+mem[r+4].int;
mem[prevr+5].int:=mem[prevr+5].int+mem[r+5].int;
mem[prevr+6].int:=mem[prevr+6].int+mem[r+6].int;
mem[prevr].hh.rh:=mem[r].hh.rh;freenode(r,7);end;end{:863};end{:854};
end;
10:ifdef('STAT'){861:}if curp=printednode then if curp<>-268435455 then
if mem[curp].hh.b0=7 then begin t:=mem[curp].hh.b1;
while t>0 do begin decr(t);printednode:=mem[printednode].hh.rh;end;
end{:861}endif('STAT')end;
{:832}{880:}procedure postlinebreak(finalwidowpenalty:integer);
label 30,31;var q,r,s:halfword;discbreak:boolean;postdiscbreak:boolean;
curwidth:scaled;curindent:scaled;t:quarterword;pen:integer;
curline:halfword;begin{881:}q:=mem[bestbet+1].hh.rh;curp:=-268435455;
repeat r:=q;q:=mem[q+1].hh.lh;mem[r+1].hh.lh:=curp;curp:=r;
until q=-268435455{:881};curline:=curlist.pgfield+1;
repeat{883:}{884:}q:=mem[curp+1].hh.rh;discbreak:=false;
postdiscbreak:=false;
if q<>-268435455 then if mem[q].hh.b0=10 then begin deleteglueref(mem[q
+1].hh.lh);mem[q+1].hh.lh:=eqtb[24535].hh.rh;mem[q].hh.b1:=9;
incr(mem[eqtb[24535].hh.rh].hh.rh);goto 30;
end else begin if mem[q].hh.b0=7 then{885:}begin t:=mem[q].hh.b1;
{886:}if t=0 then r:=mem[q].hh.rh else begin r:=q;
while t>1 do begin r:=mem[r].hh.rh;decr(t);end;s:=mem[r].hh.rh;
r:=mem[s].hh.rh;mem[s].hh.rh:=-268435455;flushnodelist(mem[q].hh.rh);
mem[q].hh.b1:=0;end{:886};
if mem[q+1].hh.rh<>-268435455 then{887:}begin s:=mem[q+1].hh.rh;
while mem[s].hh.rh<>-268435455 do s:=mem[s].hh.rh;mem[s].hh.rh:=r;
r:=mem[q+1].hh.rh;mem[q+1].hh.rh:=-268435455;postdiscbreak:=true;
end{:887};
if mem[q+1].hh.lh<>-268435455 then{888:}begin s:=mem[q+1].hh.lh;
mem[q].hh.rh:=s;while mem[s].hh.rh<>-268435455 do s:=mem[s].hh.rh;
mem[q+1].hh.lh:=-268435455;q:=s;end{:888};mem[q].hh.rh:=r;
discbreak:=true;
end{:885}else if(mem[q].hh.b0=9)or(mem[q].hh.b0=11)then mem[q+1].int:=0;
end else begin q:=memtop-3;
while mem[q].hh.rh<>-268435455 do q:=mem[q].hh.rh;end;
{889:}r:=newparamglue(8);mem[r].hh.rh:=mem[q].hh.rh;mem[q].hh.rh:=r;
q:=r{:889};30:{:884};{890:}r:=mem[q].hh.rh;mem[q].hh.rh:=-268435455;
q:=mem[memtop-3].hh.rh;mem[memtop-3].hh.rh:=r;
if eqtb[24534].hh.rh<>membot then begin r:=newparamglue(7);
mem[r].hh.rh:=q;q:=r;end{:890};
{892:}if curline>lastspecialline then begin curwidth:=secondwidth;
curindent:=secondindent;
end else if eqtb[25057].hh.rh=-268435455 then begin curwidth:=firstwidth
;curindent:=firstindent;
end else begin curwidth:=mem[eqtb[25057].hh.rh+2*curline].int;
curindent:=mem[eqtb[25057].hh.rh+2*curline-1].int;end;
adjusttail:=memtop-5;justbox:=hpack(q,curwidth,0);
mem[justbox+4].int:=curindent{:892};{891:}appendtovlist(justbox);
if memtop-5<>adjusttail then begin mem[curlist.tailfield].hh.rh:=mem[
memtop-5].hh.rh;curlist.tailfield:=adjusttail;end;
adjusttail:=-268435455{:891};
{893:}if curline+1<>bestline then begin pen:=eqtb[27180].int;
if curline=curlist.pgfield+1 then pen:=pen+eqtb[27172].int;
if curline+2=bestline then pen:=pen+finalwidowpenalty;
if discbreak then pen:=pen+eqtb[27175].int;
if pen<>0 then begin r:=newpenalty(pen);mem[curlist.tailfield].hh.rh:=r;
curlist.tailfield:=r;end;end{:893}{:883};incr(curline);
curp:=mem[curp+1].hh.lh;
if curp<>-268435455 then if not postdiscbreak then{882:}begin r:=memtop
-3;while true do begin q:=mem[r].hh.rh;
if q=mem[curp+1].hh.rh then goto 31;if(q>=himemmin)then goto 31;
if(mem[q].hh.b0<9)then goto 31;
if mem[q].hh.b0=11 then if mem[q].hh.b1<>1 then goto 31;r:=q;end;
31:if r<>memtop-3 then begin mem[r].hh.rh:=-268435455;
flushnodelist(mem[memtop-3].hh.rh);mem[memtop-3].hh.rh:=q;end;end{:882};
until curp=-268435455;
if(curline<>bestline)or(mem[memtop-3].hh.rh<>-268435455)then confusion(
955);curlist.pgfield:=bestline-1;end;
{:880}{898:}{909:}function reconstitute(j,n:smallnumber;
bchar,hchar:halfword):smallnumber;label 22,30;var p:halfword;t:halfword;
q:fourquarters;currh:halfword;testchar:halfword;w:scaled;k:fontindex;
begin hyphenpassed:=0;t:=memtop-4;w:=0;mem[memtop-4].hh.rh:=-268435455;
{911:}curl:=hu[j];curq:=t;if j=0 then begin ligaturepresent:=initlig;
p:=initlist;if ligaturepresent then lfthit:=initlft;
while p>-268435455 do begin begin mem[t].hh.rh:=getavail;
t:=mem[t].hh.rh;mem[t].hh.b0:=hf;mem[t].hh.b1:=mem[p].hh.b1;end;
p:=mem[p].hh.rh;end;
end else if curl<256 then begin mem[t].hh.rh:=getavail;t:=mem[t].hh.rh;
mem[t].hh.b0:=hf;mem[t].hh.b1:=curl;end;ligstack:=-268435455;
begin if j<n then curr:=hu[j+1]else curr:=bchar;
if odd(hyf[j])then currh:=hchar else currh:=256;end{:911};
22:{912:}if curl=256 then begin k:=bcharlabel[hf];
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
if q.b2<128 then{914:}begin if curl=256 then lfthit:=true;
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
if q.b2>4 then if q.b2<>7 then goto 30;goto 22;end{:914};
w:=fontinfo[kernbase[hf]+256*q.b2+q.b3].int;goto 30;end;
if q.b0>=128 then if currh=256 then goto 30 else begin currh:=256;
goto 22;end;k:=k+q.b0+1;q:=fontinfo[k].qqqq;end;30:{:912};
{913:}if ligaturepresent then begin p:=newligature(hf,curl,mem[curq].hh.
rh);if lfthit then begin mem[p].hh.b1:=2;lfthit:=false;end;
if rthit then if ligstack=-268435455 then begin incr(mem[p].hh.b1);
rthit:=false;end;mem[curq].hh.rh:=p;t:=p;ligaturepresent:=false;end;
if w<>0 then begin mem[t].hh.rh:=newkern(w);t:=mem[t].hh.rh;w:=0;end;
if ligstack>-268435455 then begin curq:=t;curl:=mem[ligstack].hh.b1;
ligaturepresent:=true;
begin if mem[ligstack+1].hh.rh>-268435455 then begin mem[t].hh.rh:=mem[
ligstack+1].hh.rh;t:=mem[t].hh.rh;incr(j);end;p:=ligstack;
ligstack:=mem[p].hh.rh;freenode(p,2);
if ligstack=-268435455 then begin if j<n then curr:=hu[j+1]else curr:=
bchar;if odd(hyf[j])then currh:=hchar else currh:=256;
end else curr:=mem[ligstack].hh.b1;end;goto 22;end{:913};
reconstitute:=j;end;{:909}procedure hyphenate;
label 50,30,40,41,42,45,10;var{904:}i,j,l:0..65;q,r,s:halfword;
bchar:halfword;{:904}{915:}majortail,minortail:halfword;c:ASCIIcode;
cloc:0..63;rcount:integer;hyfnode:halfword;{:915}{925:}z:triepointer;
v:integer;{:925}{932:}h:hyphpointer;k:strnumber;u:poolpointer;
{:932}begin{926:}for j:=0 to hn do hyf[j]:=0;{933:}h:=hc[1];incr(hn);
hc[hn]:=curlang;for j:=2 to hn do h:=(h+h+hc[j])mod 607;
while true do begin{934:}k:=hyphword[h];if k=0 then goto 45;
if(strstart[k+1]-strstart[k])=hn then begin j:=1;u:=strstart[k];
repeat if strpool[u]<>hc[j]then goto 30;incr(j);incr(u);until j>hn;
{935:}s:=hyphlist[h];while s<>-268435455 do begin hyf[mem[s].hh.lh]:=1;
s:=mem[s].hh.rh;end{:935};decr(hn);goto 40;end;30:{:934};h:=hyphlink[h];
if h=0 then goto 45;decr(h);end;45:decr(hn){:933};
if trietrc[curlang+1]<>curlang then goto 10;hc[0]:=0;hc[hn+1]:=0;
hc[hn+2]:=256;
for j:=0 to hn-rhyf+1 do begin z:=trietrl[curlang+1]+hc[j];l:=j;
while hc[l]=trietrc[z]do begin if trietro[z]<>mintrieop then{927:}begin
v:=trietro[z];repeat v:=v+opstart[curlang];i:=l-hyfdistance[v];
if hyfnum[v]>hyf[i]then hyf[i]:=hyfnum[v];v:=hyfnext[v];
until v=mintrieop;end{:927};incr(l);z:=trietrl[z]+hc[l];end;end;
40:for j:=0 to lhyf-1 do hyf[j]:=0;
for j:=0 to rhyf-1 do hyf[hn-j]:=0{:926};
{905:}for j:=lhyf to hn-rhyf do if odd(hyf[j])then goto 41;goto 10;
41:{:905};{906:}q:=mem[hb].hh.rh;mem[hb].hh.rh:=-268435455;
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
{916:}repeat l:=j;j:=reconstitute(j,hn,bchar,hyfchar)+1;
if hyphenpassed=0 then begin mem[s].hh.rh:=mem[memtop-4].hh.rh;
while mem[s].hh.rh>-268435455 do s:=mem[s].hh.rh;
if odd(hyf[j-1])then begin l:=j;hyphenpassed:=j-1;
mem[memtop-4].hh.rh:=-268435455;end;end;
if hyphenpassed>0 then{917:}repeat r:=getnode(2);
mem[r].hh.rh:=mem[memtop-4].hh.rh;mem[r].hh.b0:=7;majortail:=r;
rcount:=0;
while mem[majortail].hh.rh>-268435455 do begin majortail:=mem[majortail]
.hh.rh;incr(rcount);end;i:=hyphenpassed;hyf[i]:=0;
{918:}minortail:=-268435455;mem[r+1].hh.lh:=-268435455;
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
end{:918};{919:}minortail:=-268435455;mem[r+1].hh.rh:=-268435455;
cloc:=0;if bcharlabel[hf]<>0 then begin decr(l);c:=hu[l];cloc:=l;
hu[l]:=256;end;
while l<j do begin repeat l:=reconstitute(l,hn,bchar,256)+1;
if cloc>0 then begin hu[cloc]:=c;cloc:=0;end;
if mem[memtop-4].hh.rh>-268435455 then begin if minortail=-268435455
then mem[r+1].hh.rh:=mem[memtop-4].hh.rh else mem[minortail].hh.rh:=mem[
memtop-4].hh.rh;minortail:=mem[memtop-4].hh.rh;
while mem[minortail].hh.rh>-268435455 do minortail:=mem[minortail].hh.rh
;end;until l>=j;
while l>j do{920:}begin j:=reconstitute(j,hn,bchar,256)+1;
mem[majortail].hh.rh:=mem[memtop-4].hh.rh;
while mem[majortail].hh.rh>-268435455 do begin majortail:=mem[majortail]
.hh.rh;incr(rcount);end;end{:920};end{:919};
{921:}if rcount>127 then begin mem[s].hh.rh:=mem[r].hh.rh;
mem[r].hh.rh:=-268435455;flushnodelist(r);
end else begin mem[s].hh.rh:=r;mem[r].hh.b1:=rcount;end;
s:=majortail{:921};hyphenpassed:=j-1;mem[memtop-4].hh.rh:=-268435455;
until not odd(hyf[j-1]){:917};until j>hn;mem[s].hh.rh:=q{:916};
flushlist(initlist){:906};10:end;
{:898}{945:}ifdef('INITEX'){947:}function newtrieop(d,n:smallnumber;
v:trieopcode):trieopcode;label 10;var h:negtrieopsize..trieopsize;
u:trieopcode;l:0..trieopsize;
begin h:=abs(n+313*d+361*v+1009*curlang)mod(trieopsize-negtrieopsize)+
negtrieopsize;while true do begin l:=trieophash[h];
if l=0 then begin if trieopptr=trieopsize then overflow(965,trieopsize);
u:=trieused[curlang];
if u=maxtrieop then overflow(966,maxtrieop-mintrieop);incr(trieopptr);
incr(u);trieused[curlang]:=u;if u>maxopused then maxopused:=u;
hyfdistance[trieopptr]:=d;hyfnum[trieopptr]:=n;hyfnext[trieopptr]:=v;
trieoplang[trieopptr]:=curlang;trieophash[h]:=trieopptr;
trieopval[trieopptr]:=u;newtrieop:=u;goto 10;end;
if(hyfdistance[l]=d)and(hyfnum[l]=n)and(hyfnext[l]=v)and(trieoplang[l]=
curlang)then begin newtrieop:=trieopval[l];goto 10;end;
if h>-trieopsize then decr(h)else h:=trieopsize;end;10:end;
{:947}{951:}function trienode(p:triepointer):triepointer;label 10;
var h:triepointer;q:triepointer;
begin h:=abs(triec[p]+1009*trieo[p]+2718*triel[p]+3142*trier[p])mod
triesize;while true do begin q:=triehash[h];
if q=0 then begin triehash[h]:=p;trienode:=p;goto 10;end;
if(triec[q]=triec[p])and(trieo[q]=trieo[p])and(triel[q]=triel[p])and(
trier[q]=trier[p])then begin trienode:=q;goto 10;end;
if h>0 then decr(h)else h:=triesize;end;10:end;
{:951}{952:}function compresstrie(p:triepointer):triepointer;
begin if p=0 then compresstrie:=0 else begin triel[p]:=compresstrie(
triel[p]);trier[p]:=compresstrie(trier[p]);compresstrie:=trienode(p);
end;end;{:952}{956:}procedure firstfit(p:triepointer);label 45,40;
var h:triepointer;z:triepointer;q:triepointer;c:ASCIIcode;
l,r:triepointer;ll:1..256;begin c:=triec[p];z:=triemin[c];
while true do begin h:=z-c;
{957:}if triemax<h+256 then begin if triesize<=h+256 then overflow(967,
triesize);repeat incr(triemax);trietaken[triemax]:=false;
trietrl[triemax]:=triemax+1;trietro[triemax]:=triemax-1;
until triemax=h+256;end{:957};if trietaken[h]then goto 45;
{958:}q:=trier[p];
while q>0 do begin if trietrl[h+triec[q]]=0 then goto 45;q:=trier[q];
end;goto 40{:958};45:z:=trietrl[z];end;40:{959:}trietaken[h]:=true;
triehash[p]:=h;q:=p;repeat z:=h+triec[q];l:=trietro[z];r:=trietrl[z];
trietro[r]:=l;trietrl[l]:=r;trietrl[z]:=0;
if l<256 then begin if z<256 then ll:=z else ll:=256;
repeat triemin[l]:=r;incr(l);until l=ll;end;q:=trier[q];until q=0{:959};
end;{:956}{960:}procedure triepack(p:triepointer);var q:triepointer;
begin repeat q:=triel[p];
if(q>0)and(triehash[q]=0)then begin firstfit(q);triepack(q);end;
p:=trier[p];until p=0;end;{:960}{962:}procedure triefix(p:triepointer);
var q:triepointer;c:ASCIIcode;z:triepointer;begin z:=triehash[p];
repeat q:=triel[p];c:=triec[p];trietrl[z+c]:=triehash[q];
trietrc[z+c]:=c;trietro[z+c]:=trieo[p];if q>0 then triefix(q);
p:=trier[p];until p=0;end;{:962}{963:}procedure newpatterns;label 30,31;
var k,l:0..64;digitsensed:boolean;v:trieopcode;p,q:triepointer;
firstchild:boolean;c:ASCIIcode;
begin if trienotready then begin if eqtb[27217].int<=0 then curlang:=0
else if eqtb[27217].int>255 then curlang:=0 else curlang:=eqtb[27217].
int;scanleftbrace;{964:}k:=0;hyf[0]:=0;digitsensed:=false;
while true do begin getxtoken;
case curcmd of 11,12:{965:}if digitsensed or(curchr<48)or(curchr>57)then
begin if curchr=46 then curchr:=0 else begin curchr:=eqtb[25887+curchr].
hh.rh;if curchr=0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(973);
end;begin helpptr:=1;helpline[0]:=972;end;error;end;end;
if k<63 then begin incr(k);hc[k]:=curchr;hyf[k]:=0;digitsensed:=false;
end;end else if k<63 then begin hyf[k]:=curchr-48;digitsensed:=true;
end{:965};
10,2:begin if k>0 then{966:}begin{968:}if hc[1]=0 then hyf[0]:=0;
if hc[k]=0 then hyf[k]:=0;l:=k;v:=mintrieop;
while true do begin if hyf[l]<>0 then v:=newtrieop(k-l,hyf[l],v);
if l>0 then decr(l)else goto 31;end;31:{:968};q:=0;hc[0]:=curlang;
while l<=k do begin c:=hc[l];incr(l);p:=triel[q];firstchild:=true;
while(p>0)and(c>triec[p])do begin q:=p;p:=trier[q];firstchild:=false;
end;
if(p=0)or(c<triec[p])then{967:}begin if trieptr=triesize then overflow(
967,triesize);incr(trieptr);trier[trieptr]:=p;p:=trieptr;triel[p]:=0;
if firstchild then triel[q]:=p else trier[q]:=p;triec[p]:=c;
trieo[p]:=mintrieop;end{:967};q:=p;end;
if trieo[q]<>mintrieop then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(974);
end;begin helpptr:=1;helpline[0]:=972;end;error;end;trieo[q]:=v;
end{:966};if curcmd=2 then goto 30;k:=0;hyf[0]:=0;digitsensed:=false;
end;others:begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(971);
end;printesc(969);begin helpptr:=1;helpline[0]:=972;end;error;end end;
end;30:{:964};end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(968);
end;printesc(969);begin helpptr:=1;helpline[0]:=970;end;error;
mem[memtop-12].hh.rh:=scantoks(false,false);flushlist(defref);end;end;
{:963}{969:}procedure inittrie;var p:triepointer;j,k,t:integer;
r,s:triepointer;begin{955:}{948:}opstart[0]:=-mintrieop;
for j:=1 to 255 do opstart[j]:=opstart[j-1]+trieused[j-1];
for j:=1 to trieopptr do trieophash[j]:=opstart[trieoplang[j]]+trieopval
[j];
for j:=1 to trieopptr do while trieophash[j]>j do begin k:=trieophash[j]
;t:=hyfdistance[k];hyfdistance[k]:=hyfdistance[j];hyfdistance[j]:=t;
t:=hyfnum[k];hyfnum[k]:=hyfnum[j];hyfnum[j]:=t;t:=hyfnext[k];
hyfnext[k]:=hyfnext[j];hyfnext[j]:=t;trieophash[j]:=trieophash[k];
trieophash[k]:=k;end{:948};for p:=0 to triesize do triehash[p]:=0;
triel[0]:=compresstrie(triel[0]);for p:=0 to trieptr do triehash[p]:=0;
for p:=0 to 255 do triemin[p]:=p+1;trietrl[0]:=1;triemax:=0{:955};
if triel[0]<>0 then begin firstfit(triel[0]);triepack(triel[0]);end;
{961:}if triel[0]=0 then begin for r:=0 to 256 do begin trietrl[r]:=0;
trietro[r]:=mintrieop;trietrc[r]:=0;end;triemax:=256;
end else begin triefix(triel[0]);r:=0;repeat s:=trietrl[r];
begin trietrl[r]:=0;trietro[r]:=mintrieop;trietrc[r]:=0;end;r:=s;
until r>triemax;end;trietrc[0]:=63;{:961};trienotready:=false;end;
{:969}endif('INITEX'){:945}procedure linebreak(finalwidowpenalty:integer
);label 30,31,32,33,34,35,22;var{865:}autobreaking:boolean;
prevp:halfword;q,r,s,prevs:halfword;f:internalfontnumber;
{:865}{896:}j:smallnumber;c:0..255;
{:896}begin packbeginline:=curlist.mlfield;
{819:}mem[memtop-3].hh.rh:=mem[curlist.headfield].hh.rh;
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
initcurlang:=curlist.pgfield mod 65536;
initlhyf:=curlist.pgfield div 4194304;
initrhyf:=(curlist.pgfield div 65536)mod 64;popnest;
{:819}{830:}noshrinkerroryet:=true;
if(mem[eqtb[24534].hh.rh].hh.b1<>0)and(mem[eqtb[24534].hh.rh+3].int<>0)
then begin eqtb[24534].hh.rh:=finiteshrink(eqtb[24534].hh.rh);end;
if(mem[eqtb[24535].hh.rh].hh.b1<>0)and(mem[eqtb[24535].hh.rh+3].int<>0)
then begin eqtb[24535].hh.rh:=finiteshrink(eqtb[24535].hh.rh);end;
q:=eqtb[24534].hh.rh;r:=eqtb[24535].hh.rh;
background[1]:=mem[q+1].int+mem[r+1].int;background[2]:=0;
background[3]:=0;background[4]:=0;background[5]:=0;
background[2+mem[q].hh.b0]:=mem[q+2].int;
background[2+mem[r].hh.b0]:=background[2+mem[r].hh.b0]+mem[r+2].int;
background[6]:=mem[q+3].int+mem[r+3].int;
{:830}{837:}minimumdemerits:=1073741823;minimaldemerits[3]:=1073741823;
minimaldemerits[2]:=1073741823;minimaldemerits[1]:=1073741823;
minimaldemerits[0]:=1073741823;
{:837}{851:}if eqtb[25057].hh.rh=-268435455 then if eqtb[27758].int=0
then begin lastspecialline:=0;secondwidth:=eqtb[27744].int;
secondindent:=0;
end else{852:}begin lastspecialline:=abs(eqtb[27208].int);
if eqtb[27208].int<0 then begin firstwidth:=eqtb[27744].int-abs(eqtb[
27758].int);
if eqtb[27758].int>=0 then firstindent:=eqtb[27758].int else firstindent
:=0;secondwidth:=eqtb[27744].int;secondindent:=0;
end else begin firstwidth:=eqtb[27744].int;firstindent:=0;
secondwidth:=eqtb[27744].int-abs(eqtb[27758].int);
if eqtb[27758].int>=0 then secondindent:=eqtb[27758].int else
secondindent:=0;end;
end{:852}else begin lastspecialline:=mem[eqtb[25057].hh.rh].hh.lh-1;
secondwidth:=mem[eqtb[25057].hh.rh+2*(lastspecialline+1)].int;
secondindent:=mem[eqtb[25057].hh.rh+2*lastspecialline+1].int;end;
if eqtb[27186].int=0 then easyline:=lastspecialline else easyline:=
268435455{:851};{866:}threshold:=eqtb[27167].int;
if threshold>=0 then begin ifdef('STAT')if eqtb[27199].int>0 then begin
begindiagnostic;printnl(949);end;endif('STAT')secondpass:=false;
finalpass:=false;end else begin threshold:=eqtb[27168].int;
secondpass:=true;finalpass:=(eqtb[27761].int<=0);
ifdef('STAT')if eqtb[27199].int>0 then begindiagnostic;endif('STAT')end;
while true do begin if threshold>10000 then threshold:=10000;
if secondpass then{894:}begin ifdef('INITEX')if trienotready then
inittrie;endif('INITEX')curlang:=initcurlang;lhyf:=initlhyf;
rhyf:=initrhyf;end{:894};{867:}q:=getnode(3);mem[q].hh.b0:=0;
mem[q].hh.b1:=2;mem[q].hh.rh:=memtop-7;mem[q+1].hh.rh:=-268435455;
mem[q+1].hh.lh:=curlist.pgfield+1;mem[q+2].int:=0;
mem[memtop-7].hh.rh:=q;activewidth[1]:=background[1];
activewidth[2]:=background[2];activewidth[3]:=background[3];
activewidth[4]:=background[4];activewidth[5]:=background[5];
activewidth[6]:=background[6];passive:=-268435455;printednode:=memtop-3;
passnumber:=0;fontinshortdisplay:=0{:867};curp:=mem[memtop-3].hh.rh;
autobreaking:=true;prevp:=curp;
while(curp<>-268435455)and(mem[memtop-7].hh.rh<>memtop-7)do{869:}begin
if(curp>=himemmin)then{870:}begin prevp:=curp;repeat f:=mem[curp].hh.b0;
activewidth[1]:=activewidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f
]+effectivechar(true,f,mem[curp].hh.b1)].qqqq.b0].int;
curp:=mem[curp].hh.rh;until not(curp>=himemmin);end{:870};
case mem[curp].hh.b0 of 0,1,2:activewidth[1]:=activewidth[1]+mem[curp+1]
.int;
8:{1365:}if mem[curp].hh.b1=4 then begin curlang:=mem[curp+1].hh.rh;
lhyf:=mem[curp+1].hh.b0;rhyf:=mem[curp+1].hh.b1;end{:1365};
10:begin{871:}if autobreaking then begin if(prevp>=himemmin)then
trybreak(0,0)else if(mem[prevp].hh.b0<9)then trybreak(0,0)else if(mem[
prevp].hh.b0=11)and(mem[prevp].hh.b1<>1)then trybreak(0,0);end;
if(mem[mem[curp+1].hh.lh].hh.b1<>0)and(mem[mem[curp+1].hh.lh+3].int<>0)
then begin mem[curp+1].hh.lh:=finiteshrink(mem[curp+1].hh.lh);end;
q:=mem[curp+1].hh.lh;activewidth[1]:=activewidth[1]+mem[q+1].int;
activewidth[2+mem[q].hh.b0]:=activewidth[2+mem[q].hh.b0]+mem[q+2].int;
activewidth[6]:=activewidth[6]+mem[q+3].int{:871};
if secondpass and autobreaking then{897:}begin prevs:=curp;
s:=mem[prevs].hh.rh;
if s<>-268435455 then begin{899:}while true do begin if(s>=himemmin)then
begin c:=mem[s].hh.b1;hf:=mem[s].hh.b0;
end else if mem[s].hh.b0=6 then if mem[s+1].hh.rh=-268435455 then goto
22 else begin q:=mem[s+1].hh.rh;c:=mem[q].hh.b1;hf:=mem[q].hh.b0;
end else if(mem[s].hh.b0=11)and(mem[s].hh.b1=0)then goto 22 else if mem[
s].hh.b0=8 then begin{1366:}if mem[s].hh.b1=4 then begin curlang:=mem[s
+1].hh.rh;lhyf:=mem[s+1].hh.b0;rhyf:=mem[s+1].hh.b1;end{:1366};goto 22;
end else goto 31;
if eqtb[25887+c].hh.rh<>0 then if(eqtb[25887+c].hh.rh=c)or(eqtb[27205].
int>0)then goto 32 else goto 31;22:prevs:=s;s:=mem[prevs].hh.rh;end;
32:hyfchar:=hyphenchar[hf];if hyfchar<0 then goto 31;
if hyfchar>255 then goto 31;ha:=prevs{:899};
if lhyf+rhyf>63 then goto 31;{900:}hn:=0;
while true do begin if(s>=himemmin)then begin if mem[s].hh.b0<>hf then
goto 33;hyfbchar:=mem[s].hh.b1;c:=hyfbchar;
if eqtb[25887+c].hh.rh=0 then goto 33;if hn=63 then goto 33;hb:=s;
incr(hn);hu[hn]:=c;hc[hn]:=eqtb[25887+c].hh.rh;hyfbchar:=256;
end else if mem[s].hh.b0=6 then{901:}begin if mem[s+1].hh.b0<>hf then
goto 33;j:=hn;q:=mem[s+1].hh.rh;
if q>-268435455 then hyfbchar:=mem[q].hh.b1;
while q>-268435455 do begin c:=mem[q].hh.b1;
if eqtb[25887+c].hh.rh=0 then goto 33;if j=63 then goto 33;incr(j);
hu[j]:=c;hc[j]:=eqtb[25887+c].hh.rh;q:=mem[q].hh.rh;end;hb:=s;hn:=j;
if odd(mem[s].hh.b1)then hyfbchar:=fontbchar[hf]else hyfbchar:=256;
end{:901}else if(mem[s].hh.b0=11)and(mem[s].hh.b1=0)then begin hb:=s;
hyfbchar:=fontbchar[hf];end else goto 33;s:=mem[s].hh.rh;end;33:{:900};
{902:}if hn<lhyf+rhyf then goto 31;
while true do begin if not((s>=himemmin))then case mem[s].hh.b0 of 6:;
11:if mem[s].hh.b1<>0 then goto 34;8,10,12,3,5,4:goto 34;
others:goto 31 end;s:=mem[s].hh.rh;end;34:{:902};hyphenate;end;
31:end{:897};end;
11:if mem[curp].hh.b1=1 then begin if not(mem[curp].hh.rh>=himemmin)and
autobreaking then if mem[mem[curp].hh.rh].hh.b0=10 then trybreak(0,0);
activewidth[1]:=activewidth[1]+mem[curp+1].int;
end else activewidth[1]:=activewidth[1]+mem[curp+1].int;
6:begin f:=mem[curp+1].hh.b0;
activewidth[1]:=activewidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f
]+effectivechar(true,f,mem[curp+1].hh.b1)].qqqq.b0].int;end;
7:{872:}begin s:=mem[curp+1].hh.lh;discwidth:=0;
if s=-268435455 then trybreak(eqtb[27171].int,1)else begin repeat{873:}
if(s>=himemmin)then begin f:=mem[s].hh.b0;
discwidth:=discwidth+fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[s].hh.b1)].qqqq.b0].int;
end else case mem[s].hh.b0 of 6:begin f:=mem[s+1].hh.b0;
discwidth:=discwidth+fontinfo[widthbase[f]+fontinfo[charbase[f]+
effectivechar(true,f,mem[s+1].hh.b1)].qqqq.b0].int;end;
0,1,2,11:discwidth:=discwidth+mem[s+1].int;
others:confusion(953)end{:873};s:=mem[s].hh.rh;until s=-268435455;
activewidth[1]:=activewidth[1]+discwidth;trybreak(eqtb[27170].int,1);
activewidth[1]:=activewidth[1]-discwidth;end;r:=mem[curp].hh.b1;
s:=mem[curp].hh.rh;
while r>0 do begin{874:}if(s>=himemmin)then begin f:=mem[s].hh.b0;
activewidth[1]:=activewidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f
]+effectivechar(true,f,mem[s].hh.b1)].qqqq.b0].int;
end else case mem[s].hh.b0 of 6:begin f:=mem[s+1].hh.b0;
activewidth[1]:=activewidth[1]+fontinfo[widthbase[f]+fontinfo[charbase[f
]+effectivechar(true,f,mem[s+1].hh.b1)].qqqq.b0].int;end;
0,1,2,11:activewidth[1]:=activewidth[1]+mem[s+1].int;
others:confusion(954)end{:874};decr(r);s:=mem[s].hh.rh;end;prevp:=curp;
curp:=s;goto 35;end{:872};9:begin autobreaking:=(mem[curp].hh.b1=1);
begin if not(mem[curp].hh.rh>=himemmin)and autobreaking then if mem[mem[
curp].hh.rh].hh.b0=10 then trybreak(0,0);
activewidth[1]:=activewidth[1]+mem[curp+1].int;end;end;
12:trybreak(mem[curp+1].int,0);4,3,5:;others:confusion(952)end;
prevp:=curp;curp:=mem[curp].hh.rh;35:end{:869};
if curp=-268435455 then{876:}begin trybreak(-10000,1);
if mem[memtop-7].hh.rh<>memtop-7 then begin{877:}r:=mem[memtop-7].hh.rh;
fewestdemerits:=1073741823;
repeat if mem[r].hh.b0<>2 then if mem[r+2].int<fewestdemerits then begin
fewestdemerits:=mem[r+2].int;bestbet:=r;end;r:=mem[r].hh.rh;
until r=memtop-7;bestline:=mem[bestbet+1].hh.lh{:877};
if eqtb[27186].int=0 then goto 30;{878:}begin r:=mem[memtop-7].hh.rh;
actuallooseness:=0;
repeat if mem[r].hh.b0<>2 then begin linediff:=mem[r+1].hh.lh-bestline;
if((linediff<actuallooseness)and(eqtb[27186].int<=linediff))or((linediff
>actuallooseness)and(eqtb[27186].int>=linediff))then begin bestbet:=r;
actuallooseness:=linediff;fewestdemerits:=mem[r+2].int;
end else if(linediff=actuallooseness)and(mem[r+2].int<fewestdemerits)
then begin bestbet:=r;fewestdemerits:=mem[r+2].int;end;end;
r:=mem[r].hh.rh;until r=memtop-7;bestline:=mem[bestbet+1].hh.lh;
end{:878};if(actuallooseness=eqtb[27186].int)or finalpass then goto 30;
end;end{:876};{868:}q:=mem[memtop-7].hh.rh;
while q<>memtop-7 do begin curp:=mem[q].hh.rh;
if mem[q].hh.b0=2 then freenode(q,7)else freenode(q,3);q:=curp;end;
q:=passive;while q<>-268435455 do begin curp:=mem[q].hh.rh;
freenode(q,2);q:=curp;end{:868};
if not secondpass then begin ifdef('STAT')if eqtb[27199].int>0 then
printnl(950);endif('STAT')threshold:=eqtb[27168].int;secondpass:=true;
finalpass:=(eqtb[27761].int<=0);
end else begin ifdef('STAT')if eqtb[27199].int>0 then printnl(951);
endif('STAT')background[2]:=background[2]+eqtb[27761].int;
finalpass:=true;end;end;
30:ifdef('STAT')if eqtb[27199].int>0 then begin enddiagnostic(true);
normalizeselector;end;endif('STAT'){:866};
{879:}postlinebreak(finalwidowpenalty){:879};
{868:}q:=mem[memtop-7].hh.rh;
while q<>memtop-7 do begin curp:=mem[q].hh.rh;
if mem[q].hh.b0=2 then freenode(q,7)else freenode(q,3);q:=curp;end;
q:=passive;while q<>-268435455 do begin curp:=mem[q].hh.rh;
freenode(q,2);q:=curp;end{:868};packbeginline:=0;end;
{:818}{937:}procedure newhyphexceptions;label 21,10,40,45;var n:0..64;
j:0..64;h:hyphpointer;k:strnumber;p:halfword;q:halfword;s:strnumber;
u,v:poolpointer;begin scanleftbrace;
if eqtb[27217].int<=0 then curlang:=0 else if eqtb[27217].int>255 then
curlang:=0 else curlang:=eqtb[27217].int;{938:}n:=0;p:=-268435455;
while true do begin getxtoken;
21:case curcmd of 11,12,68:{940:}if curchr=45 then{941:}begin if n<63
then begin q:=getavail;mem[q].hh.rh:=p;mem[q].hh.lh:=n;p:=q;end;
end{:941}else begin if eqtb[25887+curchr].hh.rh=0 then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(961);
end;begin helpptr:=2;helpline[1]:=962;helpline[0]:=963;end;error;
end else if n<63 then begin incr(n);hc[n]:=eqtb[25887+curchr].hh.rh;end;
end{:940};16:begin scancharnum;curchr:=curval;curcmd:=68;goto 21;end;
10,2:begin if n>1 then{942:}begin incr(n);hc[n]:=curlang;
begin if poolptr+n>poolsize then overflow(257,poolsize-initpoolptr);end;
h:=0;for j:=1 to n do begin h:=(h+h+hc[j])mod 607;
begin strpool[poolptr]:=hc[j];incr(poolptr);end;end;s:=makestring;
{943:}if hyphnext<=607 then while(hyphnext>0)and(hyphword[hyphnext-1]>0)
do decr(hyphnext);
if(hyphcount=hyphsize)or(hyphnext=0)then overflow(964,hyphsize);
incr(hyphcount);while hyphword[h]<>0 do begin{944:}k:=hyphword[h];
if(strstart[k+1]-strstart[k])<>(strstart[s+1]-strstart[s])then goto 45;
u:=strstart[k];v:=strstart[s];
repeat if strpool[u]<>strpool[v]then goto 45;incr(u);incr(v);
until u=strstart[k+1];begin decr(strptr);poolptr:=strstart[strptr];end;
s:=hyphword[h];decr(hyphcount);goto 40;45:{:944};
if hyphlink[h]=0 then begin hyphlink[h]:=hyphnext;
if hyphnext>=hyphsize then hyphnext:=607;
if hyphnext>607 then incr(hyphnext);end;h:=hyphlink[h]-1;end;
40:hyphword[h]:=s;hyphlist[h]:=p{:943};end{:942};
if curcmd=2 then goto 10;n:=0;p:=-268435455;end;
others:{939:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(695);
end;printesc(957);print(958);begin helpptr:=2;helpline[1]:=959;
helpline[0]:=960;end;error;end{:939}end;end{:938};10:end;
{:937}{971:}function prunepagetop(p:halfword):halfword;
var prevp:halfword;q:halfword;begin prevp:=memtop-3;
mem[memtop-3].hh.rh:=p;
while p<>-268435455 do case mem[p].hh.b0 of 0,1,2:{972:}begin q:=
newskipparam(10);mem[prevp].hh.rh:=q;mem[q].hh.rh:=p;
if mem[tempptr+1].int>mem[p+3].int then mem[tempptr+1].int:=mem[tempptr
+1].int-mem[p+3].int else mem[tempptr+1].int:=0;p:=-268435455;end{:972};
8,4,3:begin prevp:=p;p:=mem[prevp].hh.rh;end;10,11,12:begin q:=p;
p:=mem[q].hh.rh;mem[q].hh.rh:=-268435455;mem[prevp].hh.rh:=p;
flushnodelist(q);end;others:confusion(975)end;
prunepagetop:=mem[memtop-3].hh.rh;end;
{:971}{973:}function vertbreak(p:halfword;h,d:scaled):halfword;
label 30,45,90;var prevp:halfword;q,r:halfword;pi:integer;b:integer;
leastcost:integer;bestplace:halfword;prevdp:scaled;t:smallnumber;
begin prevp:=p;leastcost:=1073741823;activewidth[1]:=0;
activewidth[2]:=0;activewidth[3]:=0;activewidth[4]:=0;activewidth[5]:=0;
activewidth[6]:=0;prevdp:=0;
while true do begin{975:}if p=-268435455 then pi:=-10000 else{976:}case
mem[p].hh.b0 of 0,1,2:begin activewidth[1]:=activewidth[1]+prevdp+mem[p
+3].int;prevdp:=mem[p+2].int;goto 45;end;8:{1368:}goto 45{:1368};
10:if(mem[prevp].hh.b0<9)then pi:=0 else goto 90;
11:begin if mem[p].hh.rh=-268435455 then t:=12 else t:=mem[mem[p].hh.rh]
.hh.b0;if t=10 then pi:=0 else goto 90;end;12:pi:=mem[p+1].int;
4,3:goto 45;others:confusion(976)end{:976};
{977:}if pi<10000 then begin{978:}if activewidth[1]<h then if(
activewidth[3]<>0)or(activewidth[4]<>0)or(activewidth[5]<>0)then b:=0
else b:=badness(h-activewidth[1],activewidth[2])else if activewidth[1]-h
>activewidth[6]then b:=1073741823 else b:=badness(activewidth[1]-h,
activewidth[6]){:978};
if b<1073741823 then if pi<=-10000 then b:=pi else if b<10000 then b:=b+
pi else b:=100000;if b<=leastcost then begin bestplace:=p;leastcost:=b;
bestheightplusdepth:=activewidth[1]+prevdp;end;
if(b=1073741823)or(pi<=-10000)then goto 30;end{:977};
if(mem[p].hh.b0<10)or(mem[p].hh.b0>11)then goto 45;
90:{979:}if mem[p].hh.b0=11 then q:=p else begin q:=mem[p+1].hh.lh;
activewidth[2+mem[q].hh.b0]:=activewidth[2+mem[q].hh.b0]+mem[q+2].int;
activewidth[6]:=activewidth[6]+mem[q+3].int;
if(mem[q].hh.b1<>0)and(mem[q+3].int<>0)then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(262);
print(977);end;begin helpptr:=4;helpline[3]:=978;helpline[2]:=979;
helpline[1]:=980;helpline[0]:=938;end;error;r:=newspec(q);
mem[r].hh.b1:=0;deleteglueref(q);mem[p+1].hh.lh:=r;q:=r;end;end;
activewidth[1]:=activewidth[1]+prevdp+mem[q+1].int;prevdp:=0{:979};
45:if prevdp>d then begin activewidth[1]:=activewidth[1]+prevdp-d;
prevdp:=d;end;{:975};prevp:=p;p:=mem[prevp].hh.rh;end;
30:vertbreak:=bestplace;end;{:973}{980:}function vsplit(n:eightbits;
h:scaled):halfword;label 10,30;var v:halfword;p:halfword;q:halfword;
begin v:=eqtb[25323+n].hh.rh;
if curmark[3]<>-268435455 then begin deletetokenref(curmark[3]);
curmark[3]:=-268435455;deletetokenref(curmark[4]);
curmark[4]:=-268435455;end;
{981:}if v=-268435455 then begin vsplit:=-268435455;goto 10;end;
if mem[v].hh.b0<>1 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(335);
end;printesc(981);print(982);printesc(983);begin helpptr:=2;
helpline[1]:=984;helpline[0]:=985;end;error;vsplit:=-268435455;goto 10;
end{:981};q:=vertbreak(mem[v+5].hh.rh,h,eqtb[27747].int);
{982:}p:=mem[v+5].hh.rh;
if p=q then mem[v+5].hh.rh:=-268435455 else while true do begin if mem[p
].hh.b0=4 then if curmark[3]=-268435455 then begin curmark[3]:=mem[p+1].
int;curmark[4]:=curmark[3];
mem[curmark[3]].hh.lh:=mem[curmark[3]].hh.lh+2;
end else begin deletetokenref(curmark[4]);curmark[4]:=mem[p+1].int;
incr(mem[curmark[4]].hh.lh);end;
if mem[p].hh.rh=q then begin mem[p].hh.rh:=-268435455;goto 30;end;
p:=mem[p].hh.rh;end;30:{:982};q:=prunepagetop(q);p:=mem[v+5].hh.rh;
freenode(v,7);
if q=-268435455 then eqtb[25323+n].hh.rh:=-268435455 else eqtb[25323+n].
hh.rh:=vpackage(q,0,1,1073741823);
vsplit:=vpackage(p,h,0,eqtb[27747].int);10:end;
{:980}{988:}procedure printtotals;begin printscaled(pagesofar[1]);
if pagesofar[2]<>0 then begin print(310);printscaled(pagesofar[2]);
print(335);end;if pagesofar[3]<>0 then begin print(310);
printscaled(pagesofar[3]);print(309);end;
if pagesofar[4]<>0 then begin print(310);printscaled(pagesofar[4]);
print(994);end;if pagesofar[5]<>0 then begin print(310);
printscaled(pagesofar[5]);print(995);end;
if pagesofar[6]<>0 then begin print(311);printscaled(pagesofar[6]);end;
end;{:988}{990:}procedure freezepagespecs(s:smallnumber);
begin pagecontents:=s;pagesofar[0]:=eqtb[27745].int;
pagemaxdepth:=eqtb[27746].int;pagesofar[7]:=0;pagesofar[1]:=0;
pagesofar[2]:=0;pagesofar[3]:=0;pagesofar[4]:=0;pagesofar[5]:=0;
pagesofar[6]:=0;leastpagecost:=1073741823;
ifdef('STAT')if eqtb[27200].int>0 then begin begindiagnostic;
printnl(1003);printscaled(pagesofar[0]);print(1004);
printscaled(pagemaxdepth);enddiagnostic(false);end;endif('STAT')end;
{:990}{995:}procedure boxerror(n:eightbits);begin error;begindiagnostic;
printnl(851);showbox(eqtb[25323+n].hh.rh);enddiagnostic(true);
flushnodelist(eqtb[25323+n].hh.rh);eqtb[25323+n].hh.rh:=-268435455;end;
{:995}{996:}procedure ensurevbox(n:eightbits);var p:halfword;
begin p:=eqtb[25323+n].hh.rh;
if p<>-268435455 then if mem[p].hh.b0=0 then begin begin if interaction=
3 then;if filelineerrorstylep then printfileline else printnl(262);
print(1005);end;begin helpptr:=3;helpline[2]:=1006;helpline[1]:=1007;
helpline[0]:=1008;end;boxerror(n);end;end;
{:996}{997:}{1015:}procedure fireup(c:halfword);label 10;
var p,q,r,s:halfword;prevp:halfword;n:0..255;wait:boolean;
savevbadness:integer;savevfuzz:scaled;savesplittopskip:halfword;
begin{1016:}if mem[bestpagebreak].hh.b0=12 then begin geqworddefine(
27206,mem[bestpagebreak+1].int);mem[bestpagebreak+1].int:=10000;
end else geqworddefine(27206,10000){:1016};
if curmark[2]<>-268435455 then begin if curmark[0]<>-268435455 then
deletetokenref(curmark[0]);curmark[0]:=curmark[2];
incr(mem[curmark[0]].hh.lh);deletetokenref(curmark[1]);
curmark[1]:=-268435455;end;
{1017:}if c=bestpagebreak then bestpagebreak:=-268435455;
{1018:}if eqtb[25578].hh.rh<>-268435455 then begin begin if interaction=
3 then;if filelineerrorstylep then printfileline else printnl(262);
print(335);end;printesc(414);print(1019);begin helpptr:=2;
helpline[1]:=1020;helpline[0]:=1008;end;boxerror(255);end{:1018};
insertpenalties:=0;savesplittopskip:=eqtb[24537].hh.rh;
if eqtb[27220].int<=0 then{1021:}begin r:=mem[memtop].hh.rh;
while r<>memtop do begin if mem[r+2].hh.lh<>-268435455 then begin n:=mem
[r].hh.b1;ensurevbox(n);
if eqtb[25323+n].hh.rh=-268435455 then eqtb[25323+n].hh.rh:=newnullbox;
p:=eqtb[25323+n].hh.rh+5;
while mem[p].hh.rh<>-268435455 do p:=mem[p].hh.rh;mem[r+2].hh.rh:=p;end;
r:=mem[r].hh.rh;end;end{:1021};q:=memtop-4;mem[q].hh.rh:=-268435455;
prevp:=memtop-2;p:=mem[prevp].hh.rh;
while p<>bestpagebreak do begin if mem[p].hh.b0=3 then begin if eqtb[
27220].int<=0 then{1023:}begin r:=mem[memtop].hh.rh;
while mem[r].hh.b1<>mem[p].hh.b1 do r:=mem[r].hh.rh;
if mem[r+2].hh.lh=-268435455 then wait:=true else begin wait:=false;
s:=mem[r+2].hh.rh;mem[s].hh.rh:=mem[p+4].hh.lh;
if mem[r+2].hh.lh=p then{1024:}begin if mem[r].hh.b0=1 then if(mem[r+1].
hh.lh=p)and(mem[r+1].hh.rh<>-268435455)then begin while mem[s].hh.rh<>
mem[r+1].hh.rh do s:=mem[s].hh.rh;mem[s].hh.rh:=-268435455;
eqtb[24537].hh.rh:=mem[p+4].hh.rh;
mem[p+4].hh.lh:=prunepagetop(mem[r+1].hh.rh);
if mem[p+4].hh.lh<>-268435455 then begin tempptr:=vpackage(mem[p+4].hh.
lh,0,1,1073741823);mem[p+3].int:=mem[tempptr+3].int+mem[tempptr+2].int;
freenode(tempptr,7);wait:=true;end;end;mem[r+2].hh.lh:=-268435455;
n:=mem[r].hh.b1;tempptr:=mem[eqtb[25323+n].hh.rh+5].hh.rh;
freenode(eqtb[25323+n].hh.rh,7);
eqtb[25323+n].hh.rh:=vpackage(tempptr,0,1,1073741823);
end{:1024}else begin while mem[s].hh.rh<>-268435455 do s:=mem[s].hh.rh;
mem[r+2].hh.rh:=s;end;end;{1025:}mem[prevp].hh.rh:=mem[p].hh.rh;
mem[p].hh.rh:=-268435455;if wait then begin mem[q].hh.rh:=p;q:=p;
incr(insertpenalties);end else begin deleteglueref(mem[p+4].hh.rh);
freenode(p,5);end;p:=prevp{:1025};end{:1023};
end else if mem[p].hh.b0=4 then{1019:}begin if curmark[1]=-268435455
then begin curmark[1]:=mem[p+1].int;incr(mem[curmark[1]].hh.lh);end;
if curmark[2]<>-268435455 then deletetokenref(curmark[2]);
curmark[2]:=mem[p+1].int;incr(mem[curmark[2]].hh.lh);end{:1019};
prevp:=p;p:=mem[prevp].hh.rh;end;eqtb[24537].hh.rh:=savesplittopskip;
{1020:}if p<>-268435455 then begin if mem[memtop-1].hh.rh=-268435455
then if nestptr=0 then curlist.tailfield:=pagetail else nest[0].
tailfield:=pagetail;mem[pagetail].hh.rh:=mem[memtop-1].hh.rh;
mem[memtop-1].hh.rh:=p;mem[prevp].hh.rh:=-268435455;end;
savevbadness:=eqtb[27194].int;eqtb[27194].int:=10000;
savevfuzz:=eqtb[27750].int;eqtb[27750].int:=1073741823;
eqtb[25578].hh.rh:=vpackage(mem[memtop-2].hh.rh,bestsize,0,pagemaxdepth)
;eqtb[27194].int:=savevbadness;eqtb[27750].int:=savevfuzz;
if lastglue<>268435455 then deleteglueref(lastglue);
{994:}pagecontents:=0;pagetail:=memtop-2;
mem[memtop-2].hh.rh:=-268435455;lastglue:=268435455;lastpenalty:=0;
lastkern:=0;pagesofar[7]:=0;pagemaxdepth:=0{:994};
if q<>memtop-4 then begin mem[memtop-2].hh.rh:=mem[memtop-4].hh.rh;
pagetail:=q;end{:1020};{1022:}r:=mem[memtop].hh.rh;
while r<>memtop do begin q:=mem[r].hh.rh;freenode(r,4);r:=q;end;
mem[memtop].hh.rh:=memtop{:1022}{:1017};
if(curmark[0]<>-268435455)and(curmark[1]=-268435455)then begin curmark[1
]:=curmark[0];incr(mem[curmark[0]].hh.lh);end;
if eqtb[25058].hh.rh<>-268435455 then if deadcycles>=eqtb[27207].int
then{1027:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1021);
end;printint(deadcycles);print(1022);begin helpptr:=3;helpline[2]:=1023;
helpline[1]:=1024;helpline[0]:=1025;end;error;
end{:1027}else{1028:}begin outputactive:=true;incr(deadcycles);pushnest;
curlist.modefield:=-1;curlist.auxfield.int:=-65536000;
curlist.mlfield:=-line;begintokenlist(eqtb[25058].hh.rh,6);
newsavelevel(8);normalparagraph;scanleftbrace;goto 10;end{:1028};
{1026:}begin if mem[memtop-2].hh.rh<>-268435455 then begin if mem[memtop
-1].hh.rh=-268435455 then if nestptr=0 then curlist.tailfield:=pagetail
else nest[0].tailfield:=pagetail else mem[pagetail].hh.rh:=mem[memtop-1]
.hh.rh;mem[memtop-1].hh.rh:=mem[memtop-2].hh.rh;
mem[memtop-2].hh.rh:=-268435455;pagetail:=memtop-2;end;
shipout(eqtb[25578].hh.rh);eqtb[25578].hh.rh:=-268435455;end{:1026};
10:end;{:1015}procedure buildpage;label 10,30,31,22,80,90;
var p:halfword;q,r:halfword;b,c:integer;pi:integer;n:0..255;
delta,h,w:scaled;
begin if(mem[memtop-1].hh.rh=-268435455)or outputactive then goto 10;
repeat 22:p:=mem[memtop-1].hh.rh;
{999:}if lastglue<>268435455 then deleteglueref(lastglue);
lastpenalty:=0;lastkern:=0;
if mem[p].hh.b0=10 then begin lastglue:=mem[p+1].hh.lh;
incr(mem[lastglue].hh.rh);end else begin lastglue:=268435455;
if mem[p].hh.b0=12 then lastpenalty:=mem[p+1].int else if mem[p].hh.b0=
11 then lastkern:=mem[p+1].int;end{:999};
{1000:}{1003:}case mem[p].hh.b0 of 0,1,2:if pagecontents<2 then{1004:}
begin if pagecontents=0 then freezepagespecs(2)else pagecontents:=2;
q:=newskipparam(9);
if mem[tempptr+1].int>mem[p+3].int then mem[tempptr+1].int:=mem[tempptr
+1].int-mem[p+3].int else mem[tempptr+1].int:=0;mem[q].hh.rh:=p;
mem[memtop-1].hh.rh:=q;goto 22;
end{:1004}else{1005:}begin pagesofar[1]:=pagesofar[1]+pagesofar[7]+mem[p
+3].int;pagesofar[7]:=mem[p+2].int;goto 80;end{:1005};
8:{1367:}goto 80{:1367};
10:if pagecontents<2 then goto 31 else if(mem[pagetail].hh.b0<9)then pi
:=0 else goto 90;
11:if pagecontents<2 then goto 31 else if mem[p].hh.rh=-268435455 then
goto 10 else if mem[mem[p].hh.rh].hh.b0=10 then pi:=0 else goto 90;
12:if pagecontents<2 then goto 31 else pi:=mem[p+1].int;4:goto 80;
3:{1011:}begin if pagecontents=0 then freezepagespecs(1);
n:=mem[p].hh.b1;r:=memtop;
while n>=mem[mem[r].hh.rh].hh.b1 do r:=mem[r].hh.rh;n:=n;
if mem[r].hh.b1<>n then{1012:}begin q:=getnode(4);
mem[q].hh.rh:=mem[r].hh.rh;mem[r].hh.rh:=q;r:=q;mem[r].hh.b1:=n;
mem[r].hh.b0:=0;ensurevbox(n);
if eqtb[25323+n].hh.rh=-268435455 then mem[r+3].int:=0 else mem[r+3].int
:=mem[eqtb[25323+n].hh.rh+3].int+mem[eqtb[25323+n].hh.rh+2].int;
mem[r+2].hh.lh:=-268435455;q:=eqtb[24545+n].hh.rh;
if eqtb[27229+n].int=1000 then h:=mem[r+3].int else h:=xovern(mem[r+3].
int,1000)*eqtb[27229+n].int;pagesofar[0]:=pagesofar[0]-h-mem[q+1].int;
pagesofar[2+mem[q].hh.b0]:=pagesofar[2+mem[q].hh.b0]+mem[q+2].int;
pagesofar[6]:=pagesofar[6]+mem[q+3].int;
if(mem[q].hh.b1<>0)and(mem[q+3].int<>0)then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(262);
print(1014);end;printesc(400);printint(n);begin helpptr:=3;
helpline[2]:=1015;helpline[1]:=1016;helpline[0]:=938;end;error;end;
end{:1012};
if mem[r].hh.b0=1 then insertpenalties:=insertpenalties+mem[p+1].int
else begin mem[r+2].hh.rh:=p;
delta:=pagesofar[0]-pagesofar[1]-pagesofar[7]+pagesofar[6];
if eqtb[27229+n].int=1000 then h:=mem[p+3].int else h:=xovern(mem[p+3].
int,1000)*eqtb[27229+n].int;
if((h<=0)or(h<=delta))and(mem[p+3].int+mem[r+3].int<=eqtb[27762+n].int)
then begin pagesofar[0]:=pagesofar[0]-h;
mem[r+3].int:=mem[r+3].int+mem[p+3].int;
end else{1013:}begin if eqtb[27229+n].int<=0 then w:=1073741823 else
begin w:=pagesofar[0]-pagesofar[1]-pagesofar[7];
if eqtb[27229+n].int<>1000 then w:=xovern(w,eqtb[27229+n].int)*1000;end;
if w>eqtb[27762+n].int-mem[r+3].int then w:=eqtb[27762+n].int-mem[r+3].
int;q:=vertbreak(mem[p+4].hh.lh,w,mem[p+2].int);
mem[r+3].int:=mem[r+3].int+bestheightplusdepth;
ifdef('STAT')if eqtb[27200].int>0 then{1014:}begin begindiagnostic;
printnl(1017);printint(n);print(1018);printscaled(w);printchar(44);
printscaled(bestheightplusdepth);print(947);
if q=-268435455 then printint(-10000)else if mem[q].hh.b0=12 then
printint(mem[q+1].int)else printchar(48);enddiagnostic(false);
end{:1014};
endif('STAT')if eqtb[27229+n].int<>1000 then bestheightplusdepth:=xovern
(bestheightplusdepth,1000)*eqtb[27229+n].int;
pagesofar[0]:=pagesofar[0]-bestheightplusdepth;mem[r].hh.b0:=1;
mem[r+1].hh.rh:=q;mem[r+1].hh.lh:=p;
if q=-268435455 then insertpenalties:=insertpenalties-10000 else if mem[
q].hh.b0=12 then insertpenalties:=insertpenalties+mem[q+1].int;
end{:1013};end;goto 80;end{:1011};others:confusion(1009)end{:1003};
{1008:}if pi<10000 then begin{1010:}if pagesofar[1]<pagesofar[0]then if(
pagesofar[3]<>0)or(pagesofar[4]<>0)or(pagesofar[5]<>0)then b:=0 else b:=
badness(pagesofar[0]-pagesofar[1],pagesofar[2])else if pagesofar[1]-
pagesofar[0]>pagesofar[6]then b:=1073741823 else b:=badness(pagesofar[1]
-pagesofar[0],pagesofar[6]){:1010};
if b<1073741823 then if pi<=-10000 then c:=pi else if b<10000 then c:=b+
pi+insertpenalties else c:=100000 else c:=b;
if insertpenalties>=10000 then c:=1073741823;
ifdef('STAT')if eqtb[27200].int>0 then{1009:}begin begindiagnostic;
printnl(37);print(943);printtotals;print(1012);
printscaled(pagesofar[0]);print(946);
if b=1073741823 then printchar(42)else printint(b);print(947);
printint(pi);print(1013);
if c=1073741823 then printchar(42)else printint(c);
if c<=leastpagecost then printchar(35);enddiagnostic(false);end{:1009};
endif('STAT')if c<=leastpagecost then begin bestpagebreak:=p;
bestsize:=pagesofar[0];leastpagecost:=c;r:=mem[memtop].hh.rh;
while r<>memtop do begin mem[r+2].hh.lh:=mem[r+2].hh.rh;r:=mem[r].hh.rh;
end;end;if(c=1073741823)or(pi<=-10000)then begin fireup(p);
if outputactive then goto 10;goto 30;end;end{:1008};
if(mem[p].hh.b0<10)or(mem[p].hh.b0>11)then goto 80;
90:{1007:}if mem[p].hh.b0=11 then q:=p else begin q:=mem[p+1].hh.lh;
pagesofar[2+mem[q].hh.b0]:=pagesofar[2+mem[q].hh.b0]+mem[q+2].int;
pagesofar[6]:=pagesofar[6]+mem[q+3].int;
if(mem[q].hh.b1<>0)and(mem[q+3].int<>0)then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(262);
print(1010);end;begin helpptr:=4;helpline[3]:=1011;helpline[2]:=979;
helpline[1]:=980;helpline[0]:=938;end;error;r:=newspec(q);
mem[r].hh.b1:=0;deleteglueref(q);mem[p+1].hh.lh:=r;q:=r;end;end;
pagesofar[1]:=pagesofar[1]+pagesofar[7]+mem[q+1].int;
pagesofar[7]:=0{:1007};
80:{1006:}if pagesofar[7]>pagemaxdepth then begin pagesofar[1]:=
pagesofar[1]+pagesofar[7]-pagemaxdepth;pagesofar[7]:=pagemaxdepth;end;
{:1006};{1001:}mem[pagetail].hh.rh:=p;pagetail:=p;
mem[memtop-1].hh.rh:=mem[p].hh.rh;mem[p].hh.rh:=-268435455;
goto 30{:1001};31:{1002:}mem[memtop-1].hh.rh:=mem[p].hh.rh;
mem[p].hh.rh:=-268435455;flushnodelist(p){:1002};30:{:1000};
until mem[memtop-1].hh.rh=-268435455;
{998:}if nestptr=0 then curlist.tailfield:=memtop-1 else nest[0].
tailfield:=memtop-1{:998};10:end;{:997}{1033:}{1046:}procedure appspace;
var q:halfword;
begin if(curlist.auxfield.hh.lh>=2000)and(eqtb[24540].hh.rh<>membot)then
q:=newparamglue(13)else begin if eqtb[24539].hh.rh<>membot then mainp:=
eqtb[24539].hh.rh else{1045:}begin mainp:=fontglue[eqtb[25579].hh.rh];
if mainp=-268435455 then begin mainp:=newspec(membot);
maink:=parambase[eqtb[25579].hh.rh]+2;
mem[mainp+1].int:=fontinfo[maink].int;
mem[mainp+2].int:=fontinfo[maink+1].int;
mem[mainp+3].int:=fontinfo[maink+2].int;
fontglue[eqtb[25579].hh.rh]:=mainp;end;end{:1045};mainp:=newspec(mainp);
{1047:}if curlist.auxfield.hh.lh>=2000 then mem[mainp+1].int:=mem[mainp
+1].int+fontinfo[7+parambase[eqtb[25579].hh.rh]].int;
mem[mainp+2].int:=xnoverd(mem[mainp+2].int,curlist.auxfield.hh.lh,1000);
mem[mainp+3].int:=xnoverd(mem[mainp+3].int,1000,curlist.auxfield.hh.lh)
{:1047};q:=newglue(mainp);mem[mainp].hh.rh:=-268435455;end;
mem[curlist.tailfield].hh.rh:=q;curlist.tailfield:=q;end;
{:1046}{1050:}procedure insertdollarsign;begin backinput;curtok:=804;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1033);
end;begin helpptr:=2;helpline[1]:=1034;helpline[0]:=1035;end;inserror;
end;{:1050}{1052:}procedure youcant;begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(700);
end;printcmdchr(curcmd,curchr);printinmode(curlist.modefield);end;
{:1052}{1053:}procedure reportillegalcase;begin youcant;
begin helpptr:=4;helpline[3]:=1036;helpline[2]:=1037;helpline[1]:=1038;
helpline[0]:=1039;end;error;end;
{:1053}{1054:}function privileged:boolean;
begin if curlist.modefield>0 then privileged:=true else begin
reportillegalcase;privileged:=false;end;end;
{:1054}{1057:}function itsallover:boolean;label 10;
begin if privileged then begin if(memtop-2=pagetail)and(curlist.
headfield=curlist.tailfield)and(deadcycles=0)then begin itsallover:=true
;goto 10;end;backinput;begin mem[curlist.tailfield].hh.rh:=newnullbox;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield+1].int:=eqtb[27744].int;
begin mem[curlist.tailfield].hh.rh:=newglue(membot+8);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
begin mem[curlist.tailfield].hh.rh:=newpenalty(-1073741824);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;buildpage;end;
itsallover:=false;10:end;{:1057}{1063:}procedure appendglue;
var s:smallnumber;begin s:=curchr;case s of 0:curval:=membot+4;
1:curval:=membot+8;2:curval:=membot+12;3:curval:=membot+16;
4:scanglue(2);5:scanglue(3);end;
begin mem[curlist.tailfield].hh.rh:=newglue(curval);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if s>=4 then begin decr(mem[curval].hh.rh);
if s>4 then mem[curlist.tailfield].hh.b1:=99;end;end;
{:1063}{1064:}procedure appendkern;var s:quarterword;begin s:=curchr;
scandimen(s=99,false,false);
begin mem[curlist.tailfield].hh.rh:=newkern(curval);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b1:=s;end;{:1064}{1067:}procedure offsave;
var p:halfword;
begin if curgroup=0 then{1069:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(791);
end;printcmdchr(curcmd,curchr);begin helpptr:=1;helpline[0]:=1058;end;
error;end{:1069}else begin backinput;p:=getavail;mem[memtop-3].hh.rh:=p;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(640);
end;{1068:}case curgroup of 14:begin mem[p].hh.lh:=19611;printesc(529);
end;15:begin mem[p].hh.lh:=804;printchar(36);end;
16:begin mem[p].hh.lh:=19612;mem[p].hh.rh:=getavail;p:=mem[p].hh.rh;
mem[p].hh.lh:=3118;printesc(1057);end;others:begin mem[p].hh.lh:=637;
printchar(125);end end{:1068};print(641);
begintokenlist(mem[memtop-3].hh.rh,4);begin helpptr:=5;
helpline[4]:=1052;helpline[3]:=1053;helpline[2]:=1054;helpline[1]:=1055;
helpline[0]:=1056;end;error;end;end;
{:1067}{1072:}procedure extrarightbrace;
begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1063);
end;case curgroup of 14:printesc(529);15:printchar(36);16:printesc(893);
end;begin helpptr:=5;helpline[4]:=1064;helpline[3]:=1065;
helpline[2]:=1066;helpline[1]:=1067;helpline[0]:=1068;end;error;
incr(alignstate);end;{:1072}{1073:}procedure normalparagraph;
begin if eqtb[27186].int<>0 then eqworddefine(27186,0);
if eqtb[27758].int<>0 then eqworddefine(27758,0);
if eqtb[27208].int<>1 then eqworddefine(27208,1);
if eqtb[25057].hh.rh<>-268435455 then eqdefine(25057,118,-268435455);
end;{:1073}{1078:}procedure boxend(boxcontext:integer);var p:halfword;
begin if boxcontext<1073741824 then{1079:}begin if curbox<>-268435455
then begin mem[curbox+4].int:=boxcontext;
if abs(curlist.modefield)=1 then begin appendtovlist(curbox);
if adjusttail<>-268435455 then begin if memtop-5<>adjusttail then begin
mem[curlist.tailfield].hh.rh:=mem[memtop-5].hh.rh;
curlist.tailfield:=adjusttail;end;adjusttail:=-268435455;end;
if curlist.modefield>0 then buildpage;
end else begin if abs(curlist.modefield)=102 then curlist.auxfield.hh.lh
:=1000 else begin p:=newnoad;mem[p+1].hh.rh:=2;mem[p+1].hh.lh:=curbox;
curbox:=p;end;mem[curlist.tailfield].hh.rh:=curbox;
curlist.tailfield:=curbox;end;end;
end{:1079}else if boxcontext<1073742336 then{1080:}if boxcontext<
1073742080 then eqdefine(-1073716501+boxcontext,119,curbox)else
geqdefine(-1073716757+boxcontext,119,curbox){:1080}else if curbox<>
-268435455 then if boxcontext>1073742336 then{1081:}begin{407:}repeat
getxtoken;until(curcmd<>10)and(curcmd<>0){:407};
if((curcmd=26)and(abs(curlist.modefield)<>1))or((curcmd=27)and(abs(
curlist.modefield)=1))then begin appendglue;
mem[curlist.tailfield].hh.b1:=boxcontext-(1073742237);
mem[curlist.tailfield+1].hh.rh:=curbox;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1081);
end;begin helpptr:=3;helpline[2]:=1082;helpline[1]:=1083;
helpline[0]:=1084;end;backerror;flushnodelist(curbox);end;
end{:1081}else shipout(curbox);end;
{:1078}{1082:}procedure beginbox(boxcontext:integer);label 10,30;
var p,q:halfword;m:quarterword;k:halfword;n:eightbits;
begin case curchr of 0:begin scaneightbitint;
curbox:=eqtb[25323+curval].hh.rh;eqtb[25323+curval].hh.rh:=-268435455;
end;1:begin scaneightbitint;
curbox:=copynodelist(eqtb[25323+curval].hh.rh);end;
2:{1083:}begin curbox:=-268435455;
if abs(curlist.modefield)=203 then begin youcant;begin helpptr:=1;
helpline[0]:=1085;end;error;
end else if(curlist.modefield=1)and(curlist.headfield=curlist.tailfield)
then begin youcant;begin helpptr:=2;helpline[1]:=1086;helpline[0]:=1087;
end;error;
end else begin if not(curlist.tailfield>=himemmin)then if(mem[curlist.
tailfield].hh.b0=0)or(mem[curlist.tailfield].hh.b0=1)then{1084:}begin q
:=curlist.headfield;repeat p:=q;
if not(q>=himemmin)then if mem[q].hh.b0=7 then begin for m:=1 to mem[q].
hh.b1 do p:=mem[p].hh.rh;if p=curlist.tailfield then goto 30;end;
q:=mem[p].hh.rh;until q=curlist.tailfield;curbox:=curlist.tailfield;
mem[curbox+4].int:=0;curlist.tailfield:=p;mem[p].hh.rh:=-268435455;
30:end{:1084};end;end{:1083};3:{1085:}begin scaneightbitint;n:=curval;
if not scankeyword(858)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1088);
end;begin helpptr:=2;helpline[1]:=1089;helpline[0]:=1090;end;error;end;
scandimen(false,false,false);curbox:=vsplit(n,curval);end{:1085};
others:{1086:}begin k:=curchr-4;savestack[saveptr+0].int:=boxcontext;
if k=102 then if(boxcontext<1073741824)and(abs(curlist.modefield)=1)then
scanspec(3,true)else scanspec(2,true)else begin if k=1 then scanspec(4,
true)else begin scanspec(5,true);k:=1;end;normalparagraph;end;pushnest;
curlist.modefield:=-k;if k=1 then begin curlist.auxfield.int:=-65536000;
if eqtb[25063].hh.rh<>-268435455 then begintokenlist(eqtb[25063].hh.rh,
11);end else begin curlist.auxfield.hh.lh:=1000;
if eqtb[25062].hh.rh<>-268435455 then begintokenlist(eqtb[25062].hh.rh,
10);end;goto 10;end{:1086}end;boxend(boxcontext);10:end;
{:1082}{1087:}procedure scanbox(boxcontext:integer);
begin{407:}repeat getxtoken;until(curcmd<>10)and(curcmd<>0){:407};
if curcmd=20 then beginbox(boxcontext)else if(boxcontext>=1073742337)and
((curcmd=36)or(curcmd=35))then begin curbox:=scanrulespec;
boxend(boxcontext);end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1091);
end;begin helpptr:=3;helpline[2]:=1092;helpline[1]:=1093;
helpline[0]:=1094;end;backerror;end;end;
{:1087}{1089:}procedure package(c:smallnumber);var h:scaled;p:halfword;
d:scaled;begin d:=eqtb[27748].int;unsave;saveptr:=saveptr-3;
if curlist.modefield=-102 then curbox:=hpack(mem[curlist.headfield].hh.
rh,savestack[saveptr+2].int,savestack[saveptr+1].int)else begin curbox:=
vpackage(mem[curlist.headfield].hh.rh,savestack[saveptr+2].int,savestack
[saveptr+1].int,d);if c=4 then{1090:}begin h:=0;p:=mem[curbox+5].hh.rh;
if p<>-268435455 then if mem[p].hh.b0<=2 then h:=mem[p+3].int;
mem[curbox+2].int:=mem[curbox+2].int-h+mem[curbox+3].int;
mem[curbox+3].int:=h;end{:1090};end;popnest;
boxend(savestack[saveptr+0].int);end;
{:1089}{1094:}function normmin(h:integer):smallnumber;
begin if h<=0 then normmin:=1 else if h>=63 then normmin:=63 else
normmin:=h;end;procedure newgraf(indented:boolean);
begin curlist.pgfield:=0;
if(curlist.modefield=1)or(curlist.headfield<>curlist.tailfield)then
begin mem[curlist.tailfield].hh.rh:=newparamglue(2);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;pushnest;
curlist.modefield:=102;curlist.auxfield.hh.lh:=1000;
if eqtb[27217].int<=0 then curlang:=0 else if eqtb[27217].int>255 then
curlang:=0 else curlang:=eqtb[27217].int;
curlist.auxfield.hh.rh:=curlang;
curlist.pgfield:=(normmin(eqtb[27218].int)*64+normmin(eqtb[27219].int))
*65536+curlang;if indented then begin curlist.tailfield:=newnullbox;
mem[curlist.headfield].hh.rh:=curlist.tailfield;
mem[curlist.tailfield+1].int:=eqtb[27741].int;
if(insertsrcspecialeverypar)then insertsrcspecial;end;
if eqtb[25059].hh.rh<>-268435455 then begintokenlist(eqtb[25059].hh.rh,7
);if nestptr=1 then buildpage;end;{:1094}{1096:}procedure indentinhmode;
var p,q:halfword;begin if curchr>0 then begin p:=newnullbox;
mem[p+1].int:=eqtb[27741].int;
if abs(curlist.modefield)=102 then curlist.auxfield.hh.lh:=1000 else
begin q:=newnoad;mem[q+1].hh.rh:=2;mem[q+1].hh.lh:=p;p:=q;end;
begin mem[curlist.tailfield].hh.rh:=p;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;end;end;
{:1096}{1098:}procedure headforvmode;
begin if curlist.modefield<0 then if curcmd<>36 then offsave else begin
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(700);
end;printesc(534);print(1097);begin helpptr:=2;helpline[1]:=1098;
helpline[0]:=1099;end;error;end else begin backinput;curtok:=partoken;
backinput;curinput.indexfield:=4;end;end;
{:1098}{1099:}procedure endgraf;
begin if curlist.modefield=102 then begin if curlist.headfield=curlist.
tailfield then popnest else linebreak(eqtb[27173].int);normalparagraph;
errorcount:=0;end;end;{:1099}{1102:}procedure begininsertoradjust;
begin if curcmd=38 then curval:=255 else begin scaneightbitint;
if curval=255 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1100);
end;printesc(327);printint(255);begin helpptr:=1;helpline[0]:=1101;end;
error;curval:=0;end;end;savestack[saveptr+0].int:=curval;incr(saveptr);
newsavelevel(11);scanleftbrace;normalparagraph;pushnest;
curlist.modefield:=-1;curlist.auxfield.int:=-65536000;end;
{:1102}{1104:}procedure makemark;var p:halfword;
begin p:=scantoks(false,true);p:=getnode(2);mem[p].hh.b0:=4;
mem[p].hh.b1:=0;mem[p+1].int:=defref;mem[curlist.tailfield].hh.rh:=p;
curlist.tailfield:=p;end;{:1104}{1106:}procedure appendpenalty;
begin scanint;begin mem[curlist.tailfield].hh.rh:=newpenalty(curval);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if curlist.modefield=1 then buildpage;end;
{:1106}{1108:}procedure deletelast;label 10;var p,q:halfword;
m:quarterword;
begin if(curlist.modefield=1)and(curlist.tailfield=curlist.headfield)
then{1109:}begin if(curchr<>10)or(lastglue<>268435455)then begin youcant
;begin helpptr:=2;helpline[1]:=1086;helpline[0]:=1102;end;
if curchr=11 then helpline[0]:=(1103)else if curchr<>10 then helpline[0]
:=(1104);error;end;
end{:1109}else begin if not(curlist.tailfield>=himemmin)then if mem[
curlist.tailfield].hh.b0=curchr then begin q:=curlist.headfield;
repeat p:=q;
if not(q>=himemmin)then if mem[q].hh.b0=7 then begin for m:=1 to mem[q].
hh.b1 do p:=mem[p].hh.rh;if p=curlist.tailfield then goto 10;end;
q:=mem[p].hh.rh;until q=curlist.tailfield;mem[p].hh.rh:=-268435455;
flushnodelist(curlist.tailfield);curlist.tailfield:=p;end;end;10:end;
{:1108}{1113:}procedure unpackage;label 10;var p:halfword;c:0..1;
begin c:=curchr;scaneightbitint;p:=eqtb[25323+curval].hh.rh;
if p=-268435455 then goto 10;
if(abs(curlist.modefield)=203)or((abs(curlist.modefield)=1)and(mem[p].hh
.b0<>1))or((abs(curlist.modefield)=102)and(mem[p].hh.b0<>0))then begin
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1112);
end;begin helpptr:=3;helpline[2]:=1113;helpline[1]:=1114;
helpline[0]:=1115;end;error;goto 10;end;
if c=1 then mem[curlist.tailfield].hh.rh:=copynodelist(mem[p+5].hh.rh)
else begin mem[curlist.tailfield].hh.rh:=mem[p+5].hh.rh;
eqtb[25323+curval].hh.rh:=-268435455;freenode(p,7);end;
while mem[curlist.tailfield].hh.rh<>-268435455 do curlist.tailfield:=mem
[curlist.tailfield].hh.rh;10:end;
{:1113}{1116:}procedure appenditaliccorrection;label 10;var p:halfword;
f:internalfontnumber;
begin if curlist.tailfield<>curlist.headfield then begin if(curlist.
tailfield>=himemmin)then p:=curlist.tailfield else if mem[curlist.
tailfield].hh.b0=6 then p:=curlist.tailfield+1 else goto 10;
f:=mem[p].hh.b0;
begin mem[curlist.tailfield].hh.rh:=newkern(fontinfo[italicbase[f]+(
fontinfo[charbase[f]+effectivechar(true,f,mem[p].hh.b1)].qqqq.b2)div 4].
int);curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b1:=1;end;10:end;
{:1116}{1120:}procedure appenddiscretionary;var c:integer;
begin begin mem[curlist.tailfield].hh.rh:=newdisc;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if curchr=1 then begin c:=hyphenchar[eqtb[25579].hh.rh];
if c>=0 then if c<256 then mem[curlist.tailfield+1].hh.lh:=newcharacter(
eqtb[25579].hh.rh,c);end else begin incr(saveptr);
savestack[saveptr-1].int:=0;newsavelevel(10);scanleftbrace;pushnest;
curlist.modefield:=-102;curlist.auxfield.hh.lh:=1000;end;end;
{:1120}{1122:}procedure builddiscretionary;label 30,10;var p,q:halfword;
n:integer;begin unsave;{1124:}q:=curlist.headfield;p:=mem[q].hh.rh;n:=0;
while p<>-268435455 do begin if not(p>=himemmin)then if mem[p].hh.b0>2
then if mem[p].hh.b0<>11 then if mem[p].hh.b0<>6 then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1122);
end;begin helpptr:=1;helpline[0]:=1123;end;error;begindiagnostic;
printnl(1124);showbox(p);enddiagnostic(true);flushnodelist(p);
mem[q].hh.rh:=-268435455;goto 30;end;q:=p;p:=mem[q].hh.rh;incr(n);end;
30:{:1124};p:=mem[curlist.headfield].hh.rh;popnest;
case savestack[saveptr-1].int of 0:mem[curlist.tailfield+1].hh.lh:=p;
1:mem[curlist.tailfield+1].hh.rh:=p;
2:{1123:}begin if(n>0)and(abs(curlist.modefield)=203)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1116);
end;printesc(346);begin helpptr:=2;helpline[1]:=1117;helpline[0]:=1118;
end;flushnodelist(p);n:=0;error;
end else mem[curlist.tailfield].hh.rh:=p;
if n<=255 then mem[curlist.tailfield].hh.b1:=n else begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1119);
end;begin helpptr:=2;helpline[1]:=1120;helpline[0]:=1121;end;error;end;
if n>0 then curlist.tailfield:=q;decr(saveptr);goto 10;end{:1123};end;
incr(savestack[saveptr-1].int);newsavelevel(10);scanleftbrace;pushnest;
curlist.modefield:=-102;curlist.auxfield.hh.lh:=1000;10:end;
{:1122}{1126:}procedure makeaccent;var s,t:real;p,q,r:halfword;
f:internalfontnumber;a,h,x,w,delta:scaled;i:fourquarters;
begin scancharnum;f:=eqtb[25579].hh.rh;p:=newcharacter(f,curval);
if p<>-268435455 then begin x:=fontinfo[5+parambase[f]].int;
s:=fontinfo[1+parambase[f]].int/65536.0;
a:=fontinfo[widthbase[f]+fontinfo[charbase[f]+effectivechar(true,f,mem[p
].hh.b1)].qqqq.b0].int;doassignments;{1127:}q:=-268435455;
f:=eqtb[25579].hh.rh;
if(curcmd=11)or(curcmd=12)or(curcmd=68)then q:=newcharacter(f,curchr)
else if curcmd=16 then begin scancharnum;q:=newcharacter(f,curval);
end else backinput{:1127};
if q<>-268435455 then{1128:}begin t:=fontinfo[1+parambase[f]].int
/65536.0;
i:=fontinfo[charbase[f]+effectivechar(true,f,mem[q].hh.b1)].qqqq;
w:=fontinfo[widthbase[f]+i.b0].int;
h:=fontinfo[heightbase[f]+(i.b1)div 16].int;
if h<>x then begin p:=hpack(p,0,1);mem[p+4].int:=x-h;end;
delta:=round((w-a)/2.0+h*t-x*s);r:=newkern(delta);mem[r].hh.b1:=2;
mem[curlist.tailfield].hh.rh:=r;mem[r].hh.rh:=p;
curlist.tailfield:=newkern(-a-delta);mem[curlist.tailfield].hh.b1:=2;
mem[p].hh.rh:=curlist.tailfield;p:=q;end{:1128};
mem[curlist.tailfield].hh.rh:=p;curlist.tailfield:=p;
curlist.auxfield.hh.lh:=1000;end;end;{:1126}{1130:}procedure alignerror;
begin if abs(alignstate)>2 then{1131:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1129);
end;printcmdchr(curcmd,curchr);
if curtok=1062 then begin begin helpptr:=6;helpline[5]:=1130;
helpline[4]:=1131;helpline[3]:=1132;helpline[2]:=1133;helpline[1]:=1134;
helpline[0]:=1135;end;end else begin begin helpptr:=5;helpline[4]:=1130;
helpline[3]:=1136;helpline[2]:=1133;helpline[1]:=1134;helpline[0]:=1135;
end;end;error;end{:1131}else begin backinput;
if alignstate<0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(672);
end;incr(alignstate);curtok:=379;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1125);
end;decr(alignstate);curtok:=637;end;begin helpptr:=3;helpline[2]:=1126;
helpline[1]:=1127;helpline[0]:=1128;end;inserror;end;end;
{:1130}{1132:}procedure noalignerror;begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1129);
end;printesc(540);begin helpptr:=2;helpline[1]:=1137;helpline[0]:=1138;
end;error;end;procedure omiterror;begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1129);
end;printesc(543);begin helpptr:=2;helpline[1]:=1139;helpline[0]:=1138;
end;error;end;{:1132}{1134:}procedure doendv;begin baseptr:=inputptr;
inputstack[baseptr]:=curinput;
while(inputstack[baseptr].indexfield<>2)and(inputstack[baseptr].locfield
=-268435455)and(inputstack[baseptr].statefield=0)do decr(baseptr);
if(inputstack[baseptr].indexfield<>2)or(inputstack[baseptr].locfield<>
-268435455)or(inputstack[baseptr].statefield<>0)then fatalerror(607);
if curgroup=6 then begin endgraf;if fincol then finrow;end else offsave;
end;{:1134}{1138:}procedure cserror;
begin if curchr=10 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(791);
end;printesc(528);begin helpptr:=1;helpline[0]:=1141;end;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(791);
end;printesc(517);begin helpptr:=1;helpline[0]:=1142;end;end;error;end;
{:1138}{1139:}procedure pushmath(c:groupcode);begin pushnest;
curlist.modefield:=-203;curlist.auxfield.int:=-268435455;
newsavelevel(c);end;{:1139}{1141:}procedure initmath;label 21,40,45,30;
var w:scaled;l:scaled;s:scaled;p:halfword;q:halfword;
f:internalfontnumber;n:integer;v:scaled;d:scaled;begin gettoken;
if(curcmd=3)and(curlist.modefield>0)then{1148:}begin if curlist.
headfield=curlist.tailfield then begin popnest;w:=-1073741823;
end else begin linebreak(eqtb[27174].int);
{1149:}v:=mem[justbox+4].int+2*fontinfo[6+parambase[eqtb[25579].hh.rh]].
int;w:=-1073741823;p:=mem[justbox+5].hh.rh;
while p<>-268435455 do begin{1150:}21:if(p>=himemmin)then begin f:=mem[p
].hh.b0;
d:=fontinfo[widthbase[f]+fontinfo[charbase[f]+effectivechar(true,f,mem[p
].hh.b1)].qqqq.b0].int;goto 40;end;
case mem[p].hh.b0 of 0,1,2:begin d:=mem[p+1].int;goto 40;end;
6:{655:}begin mem[memtop-12]:=mem[p+1];
mem[memtop-12].hh.rh:=mem[p].hh.rh;p:=memtop-12;goto 21;end{:655};
11,9:d:=mem[p+1].int;10:{1151:}begin q:=mem[p+1].hh.lh;d:=mem[q+1].int;
if mem[justbox+5].hh.b0=1 then begin if(mem[justbox+5].hh.b1=mem[q].hh.
b0)and(mem[q+2].int<>0)then v:=1073741823;
end else if mem[justbox+5].hh.b0=2 then begin if(mem[justbox+5].hh.b1=
mem[q].hh.b1)and(mem[q+3].int<>0)then v:=1073741823;end;
if mem[p].hh.b1>=100 then goto 40;end{:1151};8:{1364:}d:=0{:1364};
others:d:=0 end{:1150};if v<1073741823 then v:=v+d;goto 45;
40:if v<1073741823 then begin v:=v+d;w:=v;end else begin w:=1073741823;
goto 30;end;45:p:=mem[p].hh.rh;end;30:{:1149};end;
{1152:}if eqtb[25057].hh.rh=-268435455 then if(eqtb[27758].int<>0)and(((
eqtb[27208].int>=0)and(curlist.pgfield+2>eqtb[27208].int))or(curlist.
pgfield+1<-eqtb[27208].int))then begin l:=eqtb[27744].int-abs(eqtb[27758
].int);if eqtb[27758].int>0 then s:=eqtb[27758].int else s:=0;
end else begin l:=eqtb[27744].int;s:=0;
end else begin n:=mem[eqtb[25057].hh.rh].hh.lh;
if curlist.pgfield+2>=n then p:=eqtb[25057].hh.rh+2*n else p:=eqtb[25057
].hh.rh+2*(curlist.pgfield+2);s:=mem[p-1].int;l:=mem[p].int;end{:1152};
pushmath(15);curlist.modefield:=203;eqworddefine(27211,-1);
eqworddefine(27754,w);eqworddefine(27755,l);eqworddefine(27756,s);
if eqtb[25061].hh.rh<>-268435455 then begintokenlist(eqtb[25061].hh.rh,9
);if nestptr=1 then buildpage;end{:1148}else begin backinput;
{1142:}begin pushmath(15);eqworddefine(27211,-1);
if(insertsrcspecialeverymath)then insertsrcspecial;
if eqtb[25060].hh.rh<>-268435455 then begintokenlist(eqtb[25060].hh.rh,8
);end{:1142};end;end;{:1141}{1145:}procedure starteqno;
begin savestack[saveptr+0].int:=curchr;incr(saveptr);
{1142:}begin pushmath(15);eqworddefine(27211,-1);
if(insertsrcspecialeverymath)then insertsrcspecial;
if eqtb[25060].hh.rh<>-268435455 then begintokenlist(eqtb[25060].hh.rh,8
);end{:1142};end;{:1145}{1154:}procedure scanmath(p:halfword);
label 20,21,10;var c:integer;begin 20:{407:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:407};
21:case curcmd of 11,12,68:begin c:=eqtb[26655+curchr].hh.rh;
if c=32768 then begin{1155:}begin curcs:=curchr+1;
curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;xtoken;backinput;
end{:1155};goto 20;end;end;16:begin scancharnum;curchr:=curval;
curcmd:=68;goto 21;end;17:begin scanfifteenbitint;c:=curval;end;
69:c:=curchr;15:begin scantwentysevenbitint;c:=curval div 4096;end;
others:{1156:}begin backinput;scanleftbrace;savestack[saveptr+0].int:=p;
incr(saveptr);pushmath(9);goto 10;end{:1156}end;mem[p].hh.rh:=1;
mem[p].hh.b1:=c mod 256;
if(c>=28672)and((eqtb[27211].int>=0)and(eqtb[27211].int<16))then mem[p].
hh.b0:=eqtb[27211].int else mem[p].hh.b0:=(c div 256)mod 16;10:end;
{:1154}{1158:}procedure setmathchar(c:integer);var p:halfword;
begin if c>=32768 then{1155:}begin curcs:=curchr+1;
curcmd:=eqtb[curcs].hh.b0;curchr:=eqtb[curcs].hh.rh;xtoken;backinput;
end{:1155}else begin p:=newnoad;mem[p+1].hh.rh:=1;
mem[p+1].hh.b1:=c mod 256;mem[p+1].hh.b0:=(c div 256)mod 16;
if c>=28672 then begin if((eqtb[27211].int>=0)and(eqtb[27211].int<16))
then mem[p+1].hh.b0:=eqtb[27211].int;mem[p].hh.b0:=16;
end else mem[p].hh.b0:=16+(c div 4096);mem[curlist.tailfield].hh.rh:=p;
curlist.tailfield:=p;end;end;{:1158}{1162:}procedure mathlimitswitch;
label 10;
begin if curlist.headfield<>curlist.tailfield then if mem[curlist.
tailfield].hh.b0=17 then begin mem[curlist.tailfield].hh.b1:=curchr;
goto 10;end;begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1146);
end;begin helpptr:=1;helpline[0]:=1147;end;error;10:end;
{:1162}{1163:}procedure scandelimiter(p:halfword;r:boolean);
begin if r then scantwentysevenbitint else begin{407:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:407};
case curcmd of 11,12:curval:=eqtb[27485+curchr].int;
15:scantwentysevenbitint;others:curval:=-1 end;end;
if curval<0 then{1164:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1148);
end;begin helpptr:=6;helpline[5]:=1149;helpline[4]:=1150;
helpline[3]:=1151;helpline[2]:=1152;helpline[1]:=1153;helpline[0]:=1154;
end;backerror;curval:=0;end{:1164};
mem[p].qqqq.b0:=(curval div 1048576)mod 16;
mem[p].qqqq.b1:=(curval div 4096)mod 256;
mem[p].qqqq.b2:=(curval div 256)mod 16;mem[p].qqqq.b3:=curval mod 256;
end;{:1163}{1166:}procedure mathradical;
begin begin mem[curlist.tailfield].hh.rh:=getnode(5);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=24;mem[curlist.tailfield].hh.b1:=0;
mem[curlist.tailfield+1].hh:=emptyfield;
mem[curlist.tailfield+3].hh:=emptyfield;
mem[curlist.tailfield+2].hh:=emptyfield;
scandelimiter(curlist.tailfield+4,true);scanmath(curlist.tailfield+1);
end;{:1166}{1168:}procedure mathac;
begin if curcmd=45 then{1169:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1155);
end;printesc(536);print(1156);begin helpptr:=2;helpline[1]:=1157;
helpline[0]:=1158;end;error;end{:1169};
begin mem[curlist.tailfield].hh.rh:=getnode(5);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=28;mem[curlist.tailfield].hh.b1:=0;
mem[curlist.tailfield+1].hh:=emptyfield;
mem[curlist.tailfield+3].hh:=emptyfield;
mem[curlist.tailfield+2].hh:=emptyfield;
mem[curlist.tailfield+4].hh.rh:=1;scanfifteenbitint;
mem[curlist.tailfield+4].hh.b1:=curval mod 256;
if(curval>=28672)and((eqtb[27211].int>=0)and(eqtb[27211].int<16))then
mem[curlist.tailfield+4].hh.b0:=eqtb[27211].int else mem[curlist.
tailfield+4].hh.b0:=(curval div 256)mod 16;
scanmath(curlist.tailfield+1);end;{:1168}{1175:}procedure appendchoices;
begin begin mem[curlist.tailfield].hh.rh:=newchoice;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;incr(saveptr);
savestack[saveptr-1].int:=0;pushmath(13);scanleftbrace;end;
{:1175}{1177:}{1187:}function finmlist(p:halfword):halfword;
var q:halfword;
begin if curlist.auxfield.int<>-268435455 then{1188:}begin mem[curlist.
auxfield.int+3].hh.rh:=3;
mem[curlist.auxfield.int+3].hh.lh:=mem[curlist.headfield].hh.rh;
if p=-268435455 then q:=curlist.auxfield.int else begin q:=mem[curlist.
auxfield.int+2].hh.lh;if mem[q].hh.b0<>30 then confusion(893);
mem[curlist.auxfield.int+2].hh.lh:=mem[q].hh.rh;
mem[q].hh.rh:=curlist.auxfield.int;mem[curlist.auxfield.int].hh.rh:=p;
end;end{:1188}else begin mem[curlist.tailfield].hh.rh:=p;
q:=mem[curlist.headfield].hh.rh;end;popnest;finmlist:=q;end;
{:1187}procedure buildchoices;label 10;var p:halfword;begin unsave;
p:=finmlist(-268435455);
case savestack[saveptr-1].int of 0:mem[curlist.tailfield+1].hh.lh:=p;
1:mem[curlist.tailfield+1].hh.rh:=p;2:mem[curlist.tailfield+2].hh.lh:=p;
3:begin mem[curlist.tailfield+2].hh.rh:=p;decr(saveptr);goto 10;end;end;
incr(savestack[saveptr-1].int);pushmath(13);scanleftbrace;10:end;
{:1177}{1179:}procedure subsup;var t:smallnumber;p:halfword;begin t:=0;
p:=-268435455;
if curlist.tailfield<>curlist.headfield then if(mem[curlist.tailfield].
hh.b0>=16)and(mem[curlist.tailfield].hh.b0<30)then begin p:=curlist.
tailfield+2+curcmd-7;t:=mem[p].hh.rh;end;
if(p=-268435455)or(t<>0)then{1180:}begin begin mem[curlist.tailfield].hh
.rh:=newnoad;curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
p:=curlist.tailfield+2+curcmd-7;
if t<>0 then begin if curcmd=7 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1159);
end;begin helpptr:=1;helpline[0]:=1160;end;
end else begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1161);
end;begin helpptr:=1;helpline[0]:=1162;end;end;error;end;end{:1180};
scanmath(p);end;{:1179}{1184:}procedure mathfraction;var c:smallnumber;
begin c:=curchr;
if curlist.auxfield.int<>-268435455 then{1186:}begin if c>=3 then begin
scandelimiter(memtop-12,false);scandelimiter(memtop-12,false);end;
if c mod 3=0 then scandimen(false,false,false);
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1169);
end;begin helpptr:=3;helpline[2]:=1170;helpline[1]:=1171;
helpline[0]:=1172;end;error;
end{:1186}else begin curlist.auxfield.int:=getnode(6);
mem[curlist.auxfield.int].hh.b0:=25;mem[curlist.auxfield.int].hh.b1:=0;
mem[curlist.auxfield.int+2].hh.rh:=3;
mem[curlist.auxfield.int+2].hh.lh:=mem[curlist.headfield].hh.rh;
mem[curlist.auxfield.int+3].hh:=emptyfield;
mem[curlist.auxfield.int+4].qqqq:=nulldelimiter;
mem[curlist.auxfield.int+5].qqqq:=nulldelimiter;
mem[curlist.headfield].hh.rh:=-268435455;
curlist.tailfield:=curlist.headfield;
{1185:}if c>=3 then begin scandelimiter(curlist.auxfield.int+4,false);
scandelimiter(curlist.auxfield.int+5,false);end;
case c mod 3 of 0:begin scandimen(false,false,false);
mem[curlist.auxfield.int+1].int:=curval;end;
1:mem[curlist.auxfield.int+1].int:=1073741824;
2:mem[curlist.auxfield.int+1].int:=0;end{:1185};end;end;
{:1184}{1194:}procedure mathleftright;var t:smallnumber;p:halfword;
begin t:=curchr;
if(t=31)and(curgroup<>16)then{1195:}begin if curgroup=15 then begin
scandelimiter(memtop-12,false);begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(791);
end;printesc(893);begin helpptr:=1;helpline[0]:=1173;end;error;
end else offsave;end{:1195}else begin p:=newnoad;mem[p].hh.b0:=t;
scandelimiter(p+1,false);if t=30 then begin pushmath(16);
mem[curlist.headfield].hh.rh:=p;curlist.tailfield:=p;
end else begin p:=finmlist(p);unsave;
begin mem[curlist.tailfield].hh.rh:=newnoad;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=23;mem[curlist.tailfield+1].hh.rh:=3;
mem[curlist.tailfield+1].hh.lh:=p;end;end;end;
{:1194}{1197:}procedure aftermath;var l:boolean;danger:boolean;
m:integer;p:halfword;a:halfword;{1201:}b:halfword;w:scaled;z:scaled;
e:scaled;q:scaled;d:scaled;s:scaled;g1,g2:smallnumber;r:halfword;
t:halfword;{:1201}begin danger:=false;
{1198:}if(fontparams[eqtb[25585].hh.rh]<22)or(fontparams[eqtb[25601].hh.
rh]<22)or(fontparams[eqtb[25617].hh.rh]<22)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1174);
end;begin helpptr:=3;helpline[2]:=1175;helpline[1]:=1176;
helpline[0]:=1177;end;error;flushmath;danger:=true;
end else if(fontparams[eqtb[25586].hh.rh]<13)or(fontparams[eqtb[25602].
hh.rh]<13)or(fontparams[eqtb[25618].hh.rh]<13)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1178);
end;begin helpptr:=3;helpline[2]:=1179;helpline[1]:=1180;
helpline[0]:=1181;end;error;flushmath;danger:=true;end{:1198};
m:=curlist.modefield;l:=false;p:=finmlist(-268435455);
if curlist.modefield=-m then begin{1200:}begin getxtoken;
if curcmd<>3 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1182);
end;begin helpptr:=2;helpline[1]:=1183;helpline[0]:=1184;end;backerror;
end;end{:1200};curmlist:=p;curstyle:=2;mlistpenalties:=false;
mlisttohlist;a:=hpack(mem[memtop-3].hh.rh,0,1);unsave;decr(saveptr);
if savestack[saveptr+0].int=1 then l:=true;danger:=false;
{1198:}if(fontparams[eqtb[25585].hh.rh]<22)or(fontparams[eqtb[25601].hh.
rh]<22)or(fontparams[eqtb[25617].hh.rh]<22)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1174);
end;begin helpptr:=3;helpline[2]:=1175;helpline[1]:=1176;
helpline[0]:=1177;end;error;flushmath;danger:=true;
end else if(fontparams[eqtb[25586].hh.rh]<13)or(fontparams[eqtb[25602].
hh.rh]<13)or(fontparams[eqtb[25618].hh.rh]<13)then begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1178);
end;begin helpptr:=3;helpline[2]:=1179;helpline[1]:=1180;
helpline[0]:=1181;end;error;flushmath;danger:=true;end{:1198};
m:=curlist.modefield;p:=finmlist(-268435455);end else a:=-268435455;
if m<0 then{1199:}begin begin mem[curlist.tailfield].hh.rh:=newmath(eqtb
[27742].int,0);curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
curmlist:=p;curstyle:=2;mlistpenalties:=(curlist.modefield>0);
mlisttohlist;mem[curlist.tailfield].hh.rh:=mem[memtop-3].hh.rh;
while mem[curlist.tailfield].hh.rh<>-268435455 do curlist.tailfield:=mem
[curlist.tailfield].hh.rh;
begin mem[curlist.tailfield].hh.rh:=newmath(eqtb[27742].int,1);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
curlist.auxfield.hh.lh:=1000;unsave;
end{:1199}else begin if a=-268435455 then{1200:}begin getxtoken;
if curcmd<>3 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1182);
end;begin helpptr:=2;helpline[1]:=1183;helpline[0]:=1184;end;backerror;
end;end{:1200};{1202:}curmlist:=p;curstyle:=0;mlistpenalties:=false;
mlisttohlist;p:=mem[memtop-3].hh.rh;adjusttail:=memtop-5;
b:=hpack(p,0,1);p:=mem[b+5].hh.rh;t:=adjusttail;adjusttail:=-268435455;
w:=mem[b+1].int;z:=eqtb[27755].int;s:=eqtb[27756].int;
if(a=-268435455)or danger then begin e:=0;q:=0;
end else begin e:=mem[a+1].int;
q:=e+fontinfo[6+parambase[eqtb[25585].hh.rh]].int;end;
if w+q>z then{1204:}begin if(e<>0)and((w-totalshrink[0]+q<=z)or(
totalshrink[1]<>0)or(totalshrink[2]<>0)or(totalshrink[3]<>0))then begin
freenode(b,7);b:=hpack(p,z-q,0);end else begin e:=0;
if w>z then begin freenode(b,7);b:=hpack(p,z,0);end;end;w:=mem[b+1].int;
end{:1204};{1205:}d:=half(z-w);
if(e>0)and(d<2*e)then begin d:=half(z-w-e);
if p<>-268435455 then if not(p>=himemmin)then if mem[p].hh.b0=10 then d
:=0;end{:1205};
{1206:}begin mem[curlist.tailfield].hh.rh:=newpenalty(eqtb[27178].int);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if(d+s<=eqtb[27754].int)or l then begin g1:=3;g2:=4;
end else begin g1:=5;g2:=6;end;if l and(e=0)then begin mem[a+4].int:=s;
appendtovlist(a);begin mem[curlist.tailfield].hh.rh:=newpenalty(10000);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
end else begin mem[curlist.tailfield].hh.rh:=newparamglue(g1);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end{:1206};
{1207:}if e<>0 then begin r:=newkern(z-w-e-d);
if l then begin mem[a].hh.rh:=r;mem[r].hh.rh:=b;b:=a;d:=0;
end else begin mem[b].hh.rh:=r;mem[r].hh.rh:=a;end;b:=hpack(b,0,1);end;
mem[b+4].int:=s+d;appendtovlist(b){:1207};
{1208:}if(a<>-268435455)and(e=0)and not l then begin begin mem[curlist.
tailfield].hh.rh:=newpenalty(10000);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[a+4].int:=s+z-mem[a+1].int;appendtovlist(a);g2:=0;end;
if t<>memtop-5 then begin mem[curlist.tailfield].hh.rh:=mem[memtop-5].hh
.rh;curlist.tailfield:=t;end;
begin mem[curlist.tailfield].hh.rh:=newpenalty(eqtb[27179].int);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if g2>0 then begin mem[curlist.tailfield].hh.rh:=newparamglue(g2);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end{:1208};
resumeafterdisplay{:1202};end;end;
{:1197}{1203:}procedure resumeafterdisplay;
begin if curgroup<>15 then confusion(1185);unsave;
curlist.pgfield:=curlist.pgfield+3;pushnest;curlist.modefield:=102;
curlist.auxfield.hh.lh:=1000;
if eqtb[27217].int<=0 then curlang:=0 else if eqtb[27217].int>255 then
curlang:=0 else curlang:=eqtb[27217].int;
curlist.auxfield.hh.rh:=curlang;
curlist.pgfield:=(normmin(eqtb[27218].int)*64+normmin(eqtb[27219].int))
*65536+curlang;{446:}begin getxtoken;if curcmd<>10 then backinput;
end{:446};if nestptr=1 then buildpage;end;
{:1203}{1214:}{1218:}procedure getrtoken;label 20;
begin 20:repeat gettoken;until curtok<>2592;
if(curcs=0)or(curcs>eqtbtop)or((curcs>15514)and(curcs<=28017))then begin
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1200);
end;begin helpptr:=5;helpline[4]:=1201;helpline[3]:=1202;
helpline[2]:=1203;helpline[1]:=1204;helpline[0]:=1205;end;
if curcs=0 then backinput;curtok:=19609;inserror;goto 20;end;end;
{:1218}{1232:}procedure trapzeroglue;
begin if(mem[curval+1].int=0)and(mem[curval+2].int=0)and(mem[curval+3].
int=0)then begin incr(mem[membot].hh.rh);deleteglueref(curval);
curval:=membot;end;end;
{:1232}{1239:}procedure doregistercommand(a:smallnumber);label 40,10;
var l,q,r,s:halfword;p:0..3;begin q:=curcmd;
{1240:}begin if q<>89 then begin getxtoken;
if(curcmd>=73)and(curcmd<=76)then begin l:=curchr;p:=curcmd-73;goto 40;
end;if curcmd<>89 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(700);
end;printcmdchr(curcmd,curchr);print(701);printcmdchr(q,0);
begin helpptr:=1;helpline[0]:=1239;end;error;goto 10;end;end;p:=curchr;
scaneightbitint;case p of 0:l:=curval+27229;1:l:=curval+27762;
2:l:=curval+24545;3:l:=curval+24801;end;end;40:{:1240};
if q=89 then scanoptionalequals else if scankeyword(1235)then;
aritherror:=false;
if q<91 then{1241:}if p<2 then begin if p=0 then scanint else scandimen(
false,false,false);if q=90 then curval:=curval+eqtb[l].int;
end else begin scanglue(p);if q=90 then{1242:}begin q:=newspec(curval);
r:=eqtb[l].hh.rh;deleteglueref(curval);
mem[q+1].int:=mem[q+1].int+mem[r+1].int;
if mem[q+2].int=0 then mem[q].hh.b0:=0;
if mem[q].hh.b0=mem[r].hh.b0 then mem[q+2].int:=mem[q+2].int+mem[r+2].
int else if(mem[q].hh.b0<mem[r].hh.b0)and(mem[r+2].int<>0)then begin mem
[q+2].int:=mem[r+2].int;mem[q].hh.b0:=mem[r].hh.b0;end;
if mem[q+3].int=0 then mem[q].hh.b1:=0;
if mem[q].hh.b1=mem[r].hh.b1 then mem[q+3].int:=mem[q+3].int+mem[r+3].
int else if(mem[q].hh.b1<mem[r].hh.b1)and(mem[r+3].int<>0)then begin mem
[q+3].int:=mem[r+3].int;mem[q].hh.b1:=mem[r].hh.b1;end;curval:=q;
end{:1242};end{:1241}else{1243:}begin scanint;
if p<2 then if q=91 then if p=0 then curval:=multandadd(eqtb[l].int,
curval,0,2147483647)else curval:=multandadd(eqtb[l].int,curval,0,
1073741823)else curval:=xovern(eqtb[l].int,curval)else begin s:=eqtb[l].
hh.rh;r:=newspec(s);
if q=91 then begin mem[r+1].int:=multandadd(mem[s+1].int,curval,0,
1073741823);mem[r+2].int:=multandadd(mem[s+2].int,curval,0,1073741823);
mem[r+3].int:=multandadd(mem[s+3].int,curval,0,1073741823);
end else begin mem[r+1].int:=xovern(mem[s+1].int,curval);
mem[r+2].int:=xovern(mem[s+2].int,curval);
mem[r+3].int:=xovern(mem[s+3].int,curval);end;curval:=r;end;end{:1243};
if aritherror then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1236);
end;begin helpptr:=2;helpline[1]:=1237;helpline[0]:=1238;end;
if p>=2 then deleteglueref(curval);error;goto 10;end;
if p<2 then if(a>=4)then geqworddefine(l,curval)else eqworddefine(l,
curval)else begin trapzeroglue;
if(a>=4)then geqdefine(l,117,curval)else eqdefine(l,117,curval);end;
10:end;{:1239}{1246:}procedure alteraux;var c:halfword;
begin if curchr<>abs(curlist.modefield)then reportillegalcase else begin
c:=curchr;scanoptionalequals;
if c=1 then begin scandimen(false,false,false);
curlist.auxfield.int:=curval;end else begin scanint;
if(curval<=0)or(curval>32767)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1242);
end;begin helpptr:=1;helpline[0]:=1243;end;interror(curval);
end else curlist.auxfield.hh.lh:=curval;end;end;end;
{:1246}{1247:}procedure alterprevgraf;var p:0..nestsize;
begin nest[nestptr]:=curlist;p:=nestptr;
while abs(nest[p].modefield)<>1 do decr(p);scanoptionalequals;scanint;
if curval<0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(971);
end;printesc(545);begin helpptr:=1;helpline[0]:=1244;end;
interror(curval);end else begin nest[p].pgfield:=curval;
curlist:=nest[nestptr];end;end;{:1247}{1248:}procedure alterpagesofar;
var c:0..7;begin c:=curchr;scanoptionalequals;
scandimen(false,false,false);pagesofar[c]:=curval;end;
{:1248}{1249:}procedure alterinteger;var c:0..1;begin c:=curchr;
scanoptionalequals;scanint;
if c=0 then deadcycles:=curval else insertpenalties:=curval;end;
{:1249}{1250:}procedure alterboxdimen;var c:smallnumber;b:eightbits;
begin c:=curchr;scaneightbitint;b:=curval;scanoptionalequals;
scandimen(false,false,false);
if eqtb[25323+b].hh.rh<>-268435455 then mem[eqtb[25323+b].hh.rh+c].int:=
curval;end;{:1250}{1260:}procedure newfont(a:smallnumber);label 50;
var u:halfword;s:scaled;f:internalfontnumber;t:strnumber;
oldsetting:0..21;begin if jobname=0 then openlogfile;getrtoken;u:=curcs;
if u>=514 then t:=hash[u].rh else if u>=257 then if u=513 then t:=1248
else t:=u-257 else begin oldsetting:=selector;selector:=21;print(1248);
print(u-1);selector:=oldsetting;
begin if poolptr+1>poolsize then overflow(257,poolsize-initpoolptr);end;
t:=makestring;end;if(a>=4)then geqdefine(u,87,0)else eqdefine(u,87,0);
scanoptionalequals;scanfilename;{1261:}nameinprogress:=true;
if scankeyword(1249)then{1262:}begin scandimen(false,false,false);
s:=curval;
if(s<=0)or(s>=134217728)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1251);
end;printscaled(s);print(1252);begin helpptr:=2;helpline[1]:=1253;
helpline[0]:=1254;end;error;s:=10*65536;end;
end{:1262}else if scankeyword(1250)then begin scanint;s:=-curval;
if(curval<=0)or(curval>32768)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(565);
end;begin helpptr:=1;helpline[0]:=566;end;interror(curval);s:=-1000;end;
end else s:=-1000;nameinprogress:=false{:1261};
{1263:}for f:=1 to fontptr do if streqstr(fontname[f],curname)and
streqstr(fontarea[f],curarea)then begin if s>0 then begin if s=fontsize[
f]then goto 50;
end else if fontsize[f]=xnoverd(fontdsize[f],-s,1000)then goto 50;
end{:1263};f:=readfontinfo(u,curname,curarea,s);50:eqtb[u].hh.rh:=f;
eqtb[15525+f]:=eqtb[u];hash[15525+f].rh:=t;end;
{:1260}{1268:}procedure newinteraction;begin println;
interaction:=curchr;
if interaction=0 then kpsemaketexdiscarderrors:=1 else
kpsemaketexdiscarderrors:=0;
{75:}if interaction=0 then selector:=16 else selector:=17{:75};
if logopened then selector:=selector+2;end;
{:1268}procedure prefixedcommand;label 30,10;var a:smallnumber;
f:internalfontnumber;j:halfword;k:fontindex;p,q,r:halfword;n:integer;
e:boolean;begin a:=0;
while curcmd=93 do begin if not odd(a div curchr)then a:=a+curchr;
{407:}repeat getxtoken;until(curcmd<>10)and(curcmd<>0){:407};
if curcmd<=70 then{1215:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1195);
end;printcmdchr(curcmd,curchr);printchar(39);begin helpptr:=1;
helpline[0]:=1196;end;backerror;goto 10;end{:1215};end;
{1216:}if(curcmd<>97)and(a mod 4<>0)then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(262);
print(700);end;printesc(1187);print(1197);printesc(1188);print(1198);
printcmdchr(curcmd,curchr);printchar(39);begin helpptr:=1;
helpline[0]:=1199;end;error;end{:1216};
{1217:}if eqtb[27210].int<>0 then if eqtb[27210].int<0 then begin if(a>=
4)then a:=a-4;end else begin if not(a>=4)then a:=a+4;end{:1217};
case curcmd of{1220:}87:if(a>=4)then geqdefine(25579,120,curchr)else
eqdefine(25579,120,curchr);
{:1220}{1221:}97:begin if odd(curchr)and not(a>=4)and(eqtb[27210].int>=0
)then a:=a+4;e:=(curchr>=2);getrtoken;p:=curcs;q:=scantoks(true,e);
if(a>=4)then geqdefine(p,111+(a mod 4),defref)else eqdefine(p,111+(a mod
4),defref);end;
{:1221}{1224:}94:if curchr=11 then else if curchr=10 then begin selector
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
if filelineerrorstylep then printfileline else printnl(262);print(640);
end;printesc(528);print(641);begin helpptr:=2;helpline[1]:=642;
helpline[0]:=1211;end;backerror;end;p:=mem[r].hh.rh;
if(p=-268435455)and mubytetablein then begin begin if interaction=3 then
;if filelineerrorstylep then printfileline else printnl(262);
print(1212);end;printesc(1209);print(1213);begin helpptr:=2;
helpline[1]:=1214;helpline[0]:=1215;end;error;
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
backinput;end;if curcmd>=111 then incr(mem[curchr].hh.lh);
if(a>=4)then geqdefine(p,curcmd,curchr)else eqdefine(p,curcmd,curchr);
end;{:1224}{1227:}95:if curchr=7 then begin scancharnum;p:=26911+curval;
scanoptionalequals;scancharnum;n:=curval;scancharnum;
if(eqtb[27224].int>0)then begin begindiagnostic;printnl(1224);
print(p-26911);print(1225);print(n);printchar(32);print(curval);
enddiagnostic(false);end;n:=n*256+curval;
if(a>=4)then geqdefine(p,120,n)else eqdefine(p,120,n);
if(p-26911)<eqtb[27222].int then if(a>=4)then geqworddefine(27222,p
-26911)else eqworddefine(27222,p-26911);
if(p-26911)>eqtb[27223].int then if(a>=4)then geqworddefine(27223,p
-26911)else eqworddefine(27223,p-26911);end else begin n:=curchr;
getrtoken;p:=curcs;
if(a>=4)then geqdefine(p,0,256)else eqdefine(p,0,256);
scanoptionalequals;case n of 0:begin scancharnum;
if(a>=4)then geqdefine(p,68,curval)else eqdefine(p,68,curval);end;
1:begin scanfifteenbitint;
if(a>=4)then geqdefine(p,69,curval)else eqdefine(p,69,curval);end;
others:begin scaneightbitint;
case n of 2:if(a>=4)then geqdefine(p,73,27229+curval)else eqdefine(p,73,
27229+curval);
3:if(a>=4)then geqdefine(p,74,27762+curval)else eqdefine(p,74,27762+
curval);
4:if(a>=4)then geqdefine(p,75,24545+curval)else eqdefine(p,75,24545+
curval);
5:if(a>=4)then geqdefine(p,76,24801+curval)else eqdefine(p,76,24801+
curval);
6:if(a>=4)then geqdefine(p,72,25067+curval)else eqdefine(p,72,25067+
curval);end;end end;end;{:1227}{1228:}96:begin scanint;n:=curval;
if not scankeyword(858)then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1088);
end;begin helpptr:=2;helpline[1]:=1226;helpline[0]:=1227;end;error;end;
getrtoken;p:=curcs;readtoks(n,p);
if(a>=4)then geqdefine(p,111,curval)else eqdefine(p,111,curval);end;
{:1228}{1229:}71,72:begin q:=curcs;
if curcmd=71 then begin scaneightbitint;p:=25067+curval;
end else p:=curchr;scanoptionalequals;{407:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:407};
if curcmd<>1 then{1230:}begin if curcmd=71 then begin scaneightbitint;
curcmd:=72;curchr:=25067+curval;end;
if curcmd=72 then begin q:=eqtb[curchr].hh.rh;
if q=-268435455 then if(a>=4)then geqdefine(p,101,-268435455)else
eqdefine(p,101,-268435455)else begin incr(mem[q].hh.lh);
if(a>=4)then geqdefine(p,111,q)else eqdefine(p,111,q);end;goto 30;end;
end{:1230};backinput;curcs:=q;q:=scantoks(false,false);
if mem[defref].hh.rh=-268435455 then begin if(a>=4)then geqdefine(p,101,
-268435455)else eqdefine(p,101,-268435455);
begin mem[defref].hh.rh:=avail;avail:=defref;ifdef('STAT')decr(dynused);
endif('STAT')end;
end else begin if p=25058 then begin mem[q].hh.rh:=getavail;
q:=mem[q].hh.rh;mem[q].hh.lh:=637;q:=getavail;mem[q].hh.lh:=379;
mem[q].hh.rh:=mem[defref].hh.rh;mem[defref].hh.rh:=q;end;
if(a>=4)then geqdefine(p,111,defref)else eqdefine(p,111,defref);end;end;
{:1229}{1231:}73:begin p:=curchr;scanoptionalequals;scanint;
if(a>=4)then geqworddefine(p,curval)else eqworddefine(p,curval);end;
74:begin p:=curchr;scanoptionalequals;scandimen(false,false,false);
if(a>=4)then geqworddefine(p,curval)else eqworddefine(p,curval);end;
75,76:begin p:=curchr;n:=curcmd;scanoptionalequals;
if n=76 then scanglue(3)else scanglue(2);trapzeroglue;
if(a>=4)then geqdefine(p,117,curval)else eqdefine(p,117,curval);end;
{:1231}{1235:}85:begin{1236:}if curchr=25631 then n:=15 else if curchr=
26655 then n:=32768 else if curchr=26399 then n:=32767 else if curchr=
27485 then n:=16777215 else n:=255{:1236};p:=curchr;scancharnum;
if p=25580 then p:=curval else if p=25581 then p:=curval+256 else if p=
25582 then p:=curval+512 else p:=p+curval;scanoptionalequals;scanint;
if((curval<0)and(p<27485))or(curval>n)then begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(262);
print(1231);end;printint(curval);
if p<27485 then print(1232)else print(1233);printint(n);
begin helpptr:=1;helpline[0]:=1234;end;error;curval:=0;end;
if p<256 then xord[p]:=curval else if p<512 then xchr[p-256]:=curval
else if p<768 then xprn[p-512]:=curval else if p<26655 then if(a>=4)then
geqdefine(p,120,curval)else eqdefine(p,120,curval)else if p<27485 then
if(a>=4)then geqdefine(p,120,curval)else eqdefine(p,120,curval)else if(a
>=4)then geqworddefine(p,curval)else eqworddefine(p,curval);end;
{:1235}{1237:}86:begin p:=curchr;scanfourbitint;p:=p+curval;
scanoptionalequals;scanfontident;
if(a>=4)then geqdefine(p,120,curval)else eqdefine(p,120,curval);end;
{:1237}{1238:}89,90,91,92:doregistercommand(a);
{:1238}{1244:}98:begin scaneightbitint;
if(a>=4)then n:=256+curval else n:=curval;scanoptionalequals;
if setboxallowed then scanbox(1073741824+n)else begin begin if
interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(695);
end;printesc(549);begin helpptr:=2;helpline[1]:=1240;helpline[0]:=1241;
end;error;end;end;{:1244}{1245:}79:alteraux;80:alterprevgraf;
81:alterpagesofar;82:alterinteger;83:alterboxdimen;
{:1245}{1251:}84:begin scanoptionalequals;scanint;n:=curval;
if n<=0 then p:=-268435455 else begin p:=getnode(2*n+1);mem[p].hh.lh:=n;
for j:=1 to n do begin scandimen(false,false,false);
mem[p+2*j-1].int:=curval;scandimen(false,false,false);
mem[p+2*j].int:=curval;end;end;
if(a>=4)then geqdefine(25057,118,p)else eqdefine(25057,118,p);end;
{:1251}{1255:}99:if curchr=1 then begin ifdef('INITEX')if iniversion
then begin newpatterns;goto 30;end;
endif('INITEX')begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1245);
end;helpptr:=0;error;repeat gettoken;until curcmd=2;goto 10;
end else begin newhyphexceptions;goto 30;end;
{:1255}{1256:}77:begin findfontdimen(true);k:=curval;scanoptionalequals;
scandimen(false,false,false);fontinfo[k].int:=curval;end;
78:begin n:=curchr;scanfontident;f:=curval;scanoptionalequals;scanint;
if n=0 then hyphenchar[f]:=curval else skewchar[f]:=curval;end;
{:1256}{1259:}88:newfont(a);{:1259}{1267:}100:newinteraction;
{:1267}others:confusion(1194)end;
30:{1272:}if aftertoken<>0 then begin curtok:=aftertoken;backinput;
aftertoken:=0;end{:1272};10:end;{:1214}{1273:}procedure doassignments;
label 10;begin while true do begin{407:}repeat getxtoken;
until(curcmd<>10)and(curcmd<>0){:407};if curcmd<=70 then goto 10;
setboxallowed:=false;prefixedcommand;setboxallowed:=true;end;10:end;
{:1273}{1278:}procedure openorclosein;var c:0..1;n:0..15;
begin c:=curchr;scanfourbitint;n:=curval;
if readopen[n]<>2 then begin aclose(readfile[n]);readopen[n]:=2;end;
if c<>0 then begin scanoptionalequals;scanfilename;
packfilename(curname,curarea,curext);texinputtype:=0;
if kpseinnameok(stringcast(nameoffile+1))and aopenin(readfile[n],
kpsetexformat)then readopen[n]:=1;end;end;
{:1278}{1282:}procedure issuemessage;var oldsetting:0..21;c:0..1;
s:strnumber;begin c:=curchr;mem[memtop-12].hh.rh:=scantoks(false,true);
oldsetting:=selector;selector:=21;messageprinting:=true;
activenoconvert:=true;tokenshow(defref);messageprinting:=false;
activenoconvert:=false;selector:=oldsetting;flushlist(defref);
begin if poolptr+1>poolsize then overflow(257,poolsize-initpoolptr);end;
s:=makestring;
if c=0 then{1283:}begin if termoffset+(strstart[s+1]-strstart[s])>
maxprintline-2 then println else if(termoffset>0)or(fileoffset>0)then
printchar(32);print(s);fflush(stdout);
end{:1283}else{1286:}begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(335);
end;print(s);
if eqtb[25066].hh.rh<>-268435455 then useerrhelp:=true else if
longhelpseen then begin helpptr:=1;helpline[0]:=1261;
end else begin if interaction<3 then longhelpseen:=true;
begin helpptr:=4;helpline[3]:=1262;helpline[2]:=1263;helpline[1]:=1264;
helpline[0]:=1265;end;end;error;useerrhelp:=false;end{:1286};
begin decr(strptr);poolptr:=strstart[strptr];end;end;
{:1282}{1291:}procedure shiftcase;var b:halfword;p:halfword;t:halfword;
c:eightbits;begin b:=curchr;p:=scantoks(false,false);
p:=mem[defref].hh.rh;while p<>-268435455 do begin{1292:}t:=mem[p].hh.lh;
if t<4352 then begin c:=t mod 256;
if eqtb[b+c].hh.rh<>0 then mem[p].hh.lh:=t-c+eqtb[b+c].hh.rh;end{:1292};
p:=mem[p].hh.rh;end;begintokenlist(mem[defref].hh.rh,3);
begin mem[defref].hh.rh:=avail;avail:=defref;ifdef('STAT')decr(dynused);
endif('STAT')end;end;{:1291}{1296:}procedure showwhatever;label 50;
var p:halfword;begin case curchr of 3:begin begindiagnostic;
showactivities;end;1:{1299:}begin scaneightbitint;begindiagnostic;
printnl(1283);printint(curval);printchar(61);
if eqtb[25323+curval].hh.rh=-268435455 then print(415)else showbox(eqtb[
25323+curval].hh.rh);end{:1299};0:{1297:}begin gettoken;
if interaction=3 then;printnl(1277);
if curcs<>0 then begin sprintcs(curcs);printchar(61);end;printmeaning;
goto 50;end{:1297};others:{1300:}begin p:=thetoks;if interaction=3 then;
printnl(1277);tokenshow(memtop-3);flushlist(mem[memtop-3].hh.rh);
goto 50;end{:1300}end;{1301:}enddiagnostic(true);
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1284);
end;if selector=19 then if eqtb[27196].int<=0 then begin selector:=17;
print(1285);selector:=19;end{:1301};
50:if interaction<3 then begin helpptr:=0;decr(errorcount);
end else if eqtb[27196].int>0 then begin begin helpptr:=3;
helpline[2]:=1272;helpline[1]:=1273;helpline[0]:=1274;end;
end else begin begin helpptr:=5;helpline[4]:=1272;helpline[3]:=1273;
helpline[2]:=1274;helpline[1]:=1275;helpline[0]:=1276;end;end;error;end;
{:1296}{1305:}ifdef('INITEX')procedure storefmtfile;label 41,42,31,32;
var j,k,l:integer;p,q:halfword;x:integer;formatengine:^ASCIIcode;
begin{1307:}if saveptr<>0 then begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1287);
end;begin helpptr:=1;helpline[0]:=1288;end;
begin if interaction=3 then interaction:=2;if logopened then error;
ifdef('TEXMF_DEBUG')if interaction>0 then debughelp;
endif('TEXMF_DEBUG')history:=3;jumpout;end;end{:1307};
{1331:}selector:=21;print(1304);print(jobname);printchar(32);
printint(eqtb[27190].int);printchar(46);printint(eqtb[27189].int);
printchar(46);printint(eqtb[27188].int);printchar(41);
if interaction=0 then selector:=18 else selector:=19;
begin if poolptr+1>poolsize then overflow(257,poolsize-initpoolptr);end;
formatident:=makestring;packjobname(798);
while not wopenout(fmtfile)do promptfilename(1305,798);printnl(1306);
slowprint(wmakenamestring(fmtfile));begin decr(strptr);
poolptr:=strstart[strptr];end;printnl(335);
slowprint(formatident){:1331};{1310:}dumpint(1462916184);
x:=strlen(enginename);formatengine:=xmallocarray(ASCIIcode,x+4);
strcpy(stringcast(formatengine),enginename);
for k:=x to x+3 do formatengine[k]:=0;x:=x+4-(x mod 4);dumpint(x);
dumpthings(formatengine[0],x);libcfree(formatengine);dumpint(250953736);
{1389:}dumpthings(xord[0],256);dumpthings(xchr[0],256);
dumpthings(xprn[0],256);{:1389};dumpint(268435455);dumpint(hashhigh);
dumpint(membot);dumpint(memtop);dumpint(28017);dumpint(8501);
dumpint(607){:1310};{1403:}dumpint(1296847960);
if mltexp then dumpint(1)else dumpint(0);{:1403};
{1412:}dumpint(1162040408);
if not enctexp then dumpint(0)else begin dumpint(1);
dumpthings(mubyteread[0],256);dumpthings(mubytewrite[0],256);
dumpthings(mubytecswrite[0],128);end;{:1412};{1312:}dumpint(poolptr);
dumpint(strptr);dumpthings(strstart[0],strptr+1);
dumpthings(strpool[0],poolptr);println;printint(strptr);print(1289);
printint(poolptr){:1312};{1314:}sortavail;varused:=0;dumpint(lomemmax);
dumpint(rover);p:=membot;q:=rover;x:=0;repeat dumpthings(mem[p],q+2-p);
x:=x+q+2-p;varused:=varused+q-p;p:=q+mem[q].hh.lh;q:=mem[q+1].hh.rh;
until q=rover;varused:=varused+lomemmax-p;dynused:=memend+1-himemmin;
dumpthings(mem[p],lomemmax+1-p);x:=x+lomemmax+1-p;dumpint(himemmin);
dumpint(avail);dumpthings(mem[himemmin],memend+1-himemmin);
x:=x+memend+1-himemmin;p:=avail;
while p<>-268435455 do begin decr(dynused);p:=mem[p].hh.rh;end;
dumpint(varused);dumpint(dynused);println;printint(x);print(1290);
printint(varused);printchar(38);printint(dynused){:1314};
{1316:}{1318:}k:=1;repeat j:=k;
while j<27166 do begin if(eqtb[j].hh.rh=eqtb[j+1].hh.rh)and(eqtb[j].hh.
b0=eqtb[j+1].hh.b0)and(eqtb[j].hh.b1=eqtb[j+1].hh.b1)then goto 41;
incr(j);end;l:=27167;goto 31;41:incr(j);l:=j;
while j<27166 do begin if(eqtb[j].hh.rh<>eqtb[j+1].hh.rh)or(eqtb[j].hh.
b0<>eqtb[j+1].hh.b0)or(eqtb[j].hh.b1<>eqtb[j+1].hh.b1)then goto 31;
incr(j);end;31:dumpint(l-k);dumpthings(eqtb[k],l-k);k:=j+1;dumpint(k-l);
until k=27167{:1318};{1319:}repeat j:=k;
while j<28017 do begin if eqtb[j].int=eqtb[j+1].int then goto 42;
incr(j);end;l:=28018;goto 32;42:incr(j);l:=j;
while j<28017 do begin if eqtb[j].int<>eqtb[j+1].int then goto 32;
incr(j);end;32:dumpint(l-k);dumpthings(eqtb[k],l-k);k:=j+1;dumpint(k-l);
until k>28017;if hashhigh>0 then dumpthings(eqtb[28018],hashhigh);
{:1319};dumpint(parloc);dumpint(writeloc);{1321:}dumpint(hashused);
cscount:=15513-hashused+hashhigh;
for p:=514 to hashused do if hash[p].rh<>0 then begin dumpint(p);
dumphh(hash[p]);incr(cscount);end;
dumpthings(hash[hashused+1],24525-hashused);
if hashhigh>0 then dumpthings(hash[28018],hashhigh);dumpint(cscount);
println;printint(cscount);print(1291){:1321}{:1316};
{1323:}dumpint(fmemptr);dumpthings(fontinfo[0],fmemptr);
dumpint(fontptr);{1325:}begin dumpthings(fontcheck[0],fontptr+1);
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
for k:=0 to fontptr do begin printnl(1295);printesc(hash[15525+k].rh);
printchar(61);printfilename(fontname[k],fontarea[k],335);
if fontsize[k]<>fontdsize[k]then begin print(756);
printscaled(fontsize[k]);print(402);end;end;end{:1325};println;
printint(fmemptr-7);print(1292);printint(fontptr-0);
if fontptr<>1 then print(1293)else print(1294){:1323};
{1327:}dumpint(hyphcount);if hyphnext<=607 then hyphnext:=hyphsize;
dumpint(hyphnext);
for k:=0 to hyphsize do if hyphword[k]<>0 then begin dumpint(k+65536*
hyphlink[k]);dumpint(hyphword[k]);dumpint(hyphlist[k]);end;println;
printint(hyphcount);if hyphcount<>1 then print(1296)else print(1297);
if trienotready then inittrie;dumpint(triemax);
dumpthings(trietrl[0],triemax+1);dumpthings(trietro[0],triemax+1);
dumpthings(trietrc[0],triemax+1);dumpint(trieopptr);
dumpthings(hyfdistance[1],trieopptr);dumpthings(hyfnum[1],trieopptr);
dumpthings(hyfnext[1],trieopptr);printnl(1298);printint(triemax);
print(1299);printint(trieopptr);
if trieopptr<>1 then print(1300)else print(1301);print(1302);
printint(trieopsize);
for k:=255 downto 0 do if trieused[k]>0 then begin printnl(814);
printint(trieused[k]);print(1303);printint(k);dumpint(k);
dumpint(trieused[k]);end{:1327};{1329:}dumpint(interaction);
dumpint(formatident);dumpint(69069);eqtb[27198].int:=0{:1329};
{1332:}wclose(fmtfile){:1332};end;
endif('INITEX'){:1305}{1351:}{1352:}procedure newwhatsit(s:smallnumber;
w:smallnumber);var p:halfword;begin p:=getnode(w);mem[p].hh.b0:=8;
mem[p].hh.b1:=s;mem[curlist.tailfield].hh.rh:=p;curlist.tailfield:=p;
end;{:1352}{1353:}procedure newwritewhatsit(w:smallnumber);
begin newwhatsit(curchr,w);
if w<>2 then scanfourbitint else begin scanint;
if curval<0 then curval:=17 else if(curval>15)and(curval<>18)then curval
:=16;end;mem[curlist.tailfield+1].hh.b0:=curval;
if eqtb[27226].int+64<0 then mem[curlist.tailfield+1].hh.b1:=0 else if
eqtb[27226].int+64>=2*64 then mem[curlist.tailfield+1].hh.b1:=2*64-1
else mem[curlist.tailfield+1].hh.b1:=eqtb[27226].int+64;end;
{:1353}procedure doextension;var k:integer;p:halfword;
begin case curchr of 0:{1354:}begin newwritewhatsit(3);
scanoptionalequals;scanfilename;mem[curlist.tailfield+1].hh.rh:=curname;
mem[curlist.tailfield+2].hh.lh:=curarea;
mem[curlist.tailfield+2].hh.rh:=curext;end{:1354};
1:{1355:}begin k:=curcs;newwritewhatsit(2);curcs:=k;
p:=scantoks(false,false);mem[curlist.tailfield+1].hh.rh:=defref;
end{:1355};2:{1356:}begin newwritewhatsit(2);
mem[curlist.tailfield+1].hh.rh:=-268435455;end{:1356};
3:{1357:}begin newwhatsit(3,2);
if eqtb[27228].int+64<0 then mem[curlist.tailfield+1].hh.b0:=0 else if
eqtb[27228].int+64>=2*64 then mem[curlist.tailfield+1].hh.b0:=2*64-1
else mem[curlist.tailfield+1].hh.b0:=eqtb[27228].int+64;
if eqtb[27226].int+64<0 then mem[curlist.tailfield+1].hh.b1:=0 else if
eqtb[27226].int+64>=2*64 then mem[curlist.tailfield+1].hh.b1:=2*64-1
else mem[curlist.tailfield+1].hh.b1:=eqtb[27226].int+64;
if(eqtb[27228].int=2)or(eqtb[27228].int=3)then if(eqtb[27226].int>2)or(
eqtb[27226].int=-1)or(eqtb[27226].int=-2)then writenoexpanding:=true;
p:=scantoks(false,true);mem[curlist.tailfield+1].hh.rh:=defref;
writenoexpanding:=false;end{:1357};4:{1378:}begin getxtoken;
if(curcmd=59)and(curchr<=2)then begin p:=curlist.tailfield;doextension;
outwhat(curlist.tailfield);flushnodelist(curlist.tailfield);
curlist.tailfield:=p;mem[p].hh.rh:=-268435455;end else backinput;
end{:1378};
5:{1380:}if abs(curlist.modefield)<>102 then reportillegalcase else
begin newwhatsit(4,2);scanint;
if curval<=0 then curlist.auxfield.hh.rh:=0 else if curval>255 then
curlist.auxfield.hh.rh:=0 else curlist.auxfield.hh.rh:=curval;
mem[curlist.tailfield+1].hh.rh:=curlist.auxfield.hh.rh;
mem[curlist.tailfield+1].hh.b0:=normmin(eqtb[27218].int);
mem[curlist.tailfield+1].hh.b1:=normmin(eqtb[27219].int);end{:1380};
others:confusion(1323)end;end;{:1351}{1379:}procedure fixlanguage;
var l:ASCIIcode;
begin if eqtb[27217].int<=0 then l:=0 else if eqtb[27217].int>255 then l
:=0 else l:=eqtb[27217].int;
if l<>curlist.auxfield.hh.rh then begin newwhatsit(4,2);
mem[curlist.tailfield+1].hh.rh:=l;curlist.auxfield.hh.rh:=l;
mem[curlist.tailfield+1].hh.b0:=normmin(eqtb[27218].int);
mem[curlist.tailfield+1].hh.b1:=normmin(eqtb[27219].int);end;end;
{:1379}{1415:}procedure insertsrcspecial;var toklist,p,q:halfword;
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
{:1415}{1071:}procedure handlerightbrace;var p,q:halfword;d:scaled;
f:integer;begin case curgroup of 1:unsave;
0:begin begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(1059);
end;begin helpptr:=2;helpline[1]:=1060;helpline[0]:=1061;end;error;end;
14,15,16:extrarightbrace;{1088:}2:package(0);
3:begin adjusttail:=memtop-5;package(0);end;4:begin endgraf;package(0);
end;5:begin endgraf;package(4);end;{:1088}{1103:}11:begin endgraf;
q:=eqtb[24537].hh.rh;incr(mem[q].hh.rh);d:=eqtb[27747].int;
f:=eqtb[27209].int;unsave;decr(saveptr);
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
mem[curlist.tailfield].hh.b0:=5;mem[curlist.tailfield].hh.b1:=0;
mem[curlist.tailfield+1].int:=mem[p+5].hh.rh;deleteglueref(q);end;
freenode(p,7);if nestptr=0 then buildpage;end;
8:{1029:}begin if(curinput.locfield<>-268435455)or((curinput.indexfield
<>6)and(curinput.indexfield<>3))then{1030:}begin begin if interaction=3
then;if filelineerrorstylep then printfileline else printnl(262);
print(1026);end;begin helpptr:=2;helpline[1]:=1027;helpline[0]:=1028;
end;error;repeat gettoken;until curinput.locfield=-268435455;end{:1030};
endtokenlist;endgraf;unsave;outputactive:=false;insertpenalties:=0;
{1031:}if eqtb[25578].hh.rh<>-268435455 then begin begin if interaction=
3 then;if filelineerrorstylep then printfileline else printnl(262);
print(1029);end;printesc(414);printint(255);begin helpptr:=3;
helpline[2]:=1030;helpline[1]:=1031;helpline[0]:=1032;end;boxerror(255);
end{:1031};
if curlist.tailfield<>curlist.headfield then begin mem[pagetail].hh.rh:=
mem[curlist.headfield].hh.rh;pagetail:=curlist.tailfield;end;
if mem[memtop-2].hh.rh<>-268435455 then begin if mem[memtop-1].hh.rh=
-268435455 then nest[0].tailfield:=pagetail;
mem[pagetail].hh.rh:=mem[memtop-1].hh.rh;
mem[memtop-1].hh.rh:=mem[memtop-2].hh.rh;
mem[memtop-2].hh.rh:=-268435455;pagetail:=memtop-2;end;popnest;
buildpage;end{:1029};{:1103}{1121:}10:builddiscretionary;
{:1121}{1135:}6:begin backinput;curtok:=19610;
begin if interaction=3 then;
if filelineerrorstylep then printfileline else printnl(262);print(640);
end;printesc(915);print(641);begin helpptr:=1;helpline[0]:=1140;end;
inserror;end;{:1135}{1136:}7:begin endgraf;unsave;alignpeek;end;
{:1136}{1171:}12:begin endgraf;unsave;saveptr:=saveptr-2;
p:=vpackage(mem[curlist.headfield].hh.rh,savestack[saveptr+1].int,
savestack[saveptr+0].int,1073741823);popnest;
begin mem[curlist.tailfield].hh.rh:=newnoad;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=29;mem[curlist.tailfield+1].hh.rh:=2;
mem[curlist.tailfield+1].hh.lh:=p;end;{:1171}{1176:}13:buildchoices;
{:1176}{1189:}9:begin unsave;decr(saveptr);
mem[savestack[saveptr+0].int].hh.rh:=3;p:=finmlist(-268435455);
mem[savestack[saveptr+0].int].hh.lh:=p;
if p<>-268435455 then if mem[p].hh.rh=-268435455 then if mem[p].hh.b0=16
then begin if mem[p+3].hh.rh=0 then if mem[p+2].hh.rh=0 then begin mem[
savestack[saveptr+0].int].hh:=mem[p+1].hh;freenode(p,4);end;
end else if mem[p].hh.b0=28 then if savestack[saveptr+0].int=curlist.
tailfield+1 then if mem[curlist.tailfield].hh.b0=16 then{1190:}begin q:=
curlist.headfield;
while mem[q].hh.rh<>curlist.tailfield do q:=mem[q].hh.rh;
mem[q].hh.rh:=p;freenode(curlist.tailfield,4);curlist.tailfield:=p;
end{:1190};end;{:1189}others:confusion(1062)end;end;
{:1071}procedure maincontrol;
label 60,21,70,80,90,91,92,95,100,101,110,111,112,120,10;var t:integer;
begin if eqtb[25064].hh.rh<>-268435455 then begintokenlist(eqtb[25064].
hh.rh,12);60:getxtoken;
21:{1034:}if interrupt<>0 then if OKtointerrupt then begin backinput;
begin if interrupt<>0 then pauseforinstructions;end;goto 60;end;
ifdef('TEXMF_DEBUG')if panicking then checkmem(false);
endif('TEXMF_DEBUG')if eqtb[27203].int>0 then showcurcmdchr{:1034};
case abs(curlist.modefield)+curcmd of 113,114,170:goto 70;
118:begin scancharnum;curchr:=curval;goto 70;end;167:begin getxtoken;
if(curcmd=11)or(curcmd=12)or(curcmd=68)or(curcmd=16)then cancelboundary
:=true;goto 21;end;
112:if curlist.auxfield.hh.lh=1000 then goto 120 else appspace;
166,267:goto 120;{1048:}1,102,203,11,213,268:;
40,141,242:begin{409:}repeat getxtoken;until curcmd<>10{:409};goto 21;
end;15:if itsallover then goto 10;
{1051:}23,123,224,71,172,273,{:1051}{1101:}39,{:1101}{1114:}45,{:1114}
{1147:}49,150,{:1147}7,108,209:reportillegalcase;
{1049:}8,109,9,110,18,119,70,171,51,152,16,117,50,151,53,154,67,168,54,
155,55,156,57,158,56,157,31,132,52,153,29,130,47,148,212,216,217,230,227
,236,239{:1049}:insertdollarsign;
{1059:}37,137,238:begin begin mem[curlist.tailfield].hh.rh:=scanrulespec
;curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
if abs(curlist.modefield)=1 then curlist.auxfield.int:=-65536000 else if
abs(curlist.modefield)=102 then curlist.auxfield.hh.lh:=1000;end;
{:1059}{1060:}28,128,229,231:appendglue;30,131,232,233:appendkern;
{:1060}{1066:}2,103:newsavelevel(1);62,163,264:newsavelevel(14);
63,164,265:if curgroup=14 then unsave else offsave;
{:1066}{1070:}3,104,205:handlerightbrace;
{:1070}{1076:}22,124,225:begin t:=curchr;scandimen(false,false,false);
if t=0 then scanbox(curval)else scanbox(-curval);end;
32,133,234:scanbox(1073742237+curchr);21,122,223:beginbox(0);
{:1076}{1093:}44:newgraf(curchr>0);
12,13,17,69,4,24,36,46,48,27,34,65,66:begin backinput;newgraf(true);end;
{:1093}{1095:}145,246:indentinhmode;
{:1095}{1097:}14:begin normalparagraph;
if curlist.modefield>0 then buildpage;end;
115:begin if alignstate<0 then offsave;endgraf;
if curlist.modefield=1 then buildpage;end;
116,129,138,126,134:headforvmode;
{:1097}{1100:}38,139,240,140,241:begininsertoradjust;
19,120,221:makemark;{:1100}{1105:}43,144,245:appendpenalty;
{:1105}{1107:}26,127,228:deletelast;{:1107}{1112:}25,125,226:unpackage;
{:1112}{1115:}146:appenditaliccorrection;
247:begin mem[curlist.tailfield].hh.rh:=newkern(0);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
{:1115}{1119:}149,250:appenddiscretionary;{:1119}{1125:}147:makeaccent;
{:1125}{1129:}6,107,208,5,106,207:alignerror;35,136,237:noalignerror;
64,165,266:omiterror;{:1129}{1133:}33,135:initalign;
235:if privileged then if curgroup=15 then initalign else offsave;
10,111:doendv;{:1133}{1137:}68,169,270:cserror;
{:1137}{1140:}105:initmath;
{:1140}{1143:}251:if privileged then if curgroup=15 then starteqno else
offsave;
{:1143}{1153:}204:begin begin mem[curlist.tailfield].hh.rh:=newnoad;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;backinput;
scanmath(curlist.tailfield+1);end;
{:1153}{1157:}214,215,271:setmathchar(eqtb[26655+curchr].hh.rh);
219:begin scancharnum;curchr:=curval;
setmathchar(eqtb[26655+curchr].hh.rh);end;220:begin scanfifteenbitint;
setmathchar(curval);end;272:setmathchar(curchr);
218:begin scantwentysevenbitint;setmathchar(curval div 4096);end;
{:1157}{1161:}253:begin begin mem[curlist.tailfield].hh.rh:=newnoad;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b0:=curchr;scanmath(curlist.tailfield+1);end;
254:mathlimitswitch;{:1161}{1165:}269:mathradical;
{:1165}{1167:}248,249:mathac;{:1167}{1170:}259:begin scanspec(12,false);
normalparagraph;pushnest;curlist.modefield:=-1;
curlist.auxfield.int:=-65536000;
if(insertsrcspecialeveryvbox)then insertsrcspecial;
if eqtb[25063].hh.rh<>-268435455 then begintokenlist(eqtb[25063].hh.rh,
11);end;
{:1170}{1174:}256:begin mem[curlist.tailfield].hh.rh:=newstyle(curchr);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
258:begin begin mem[curlist.tailfield].hh.rh:=newglue(membot);
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;
mem[curlist.tailfield].hh.b1:=98;end;257:appendchoices;
{:1174}{1178:}211,210:subsup;{:1178}{1183:}255:mathfraction;
{:1183}{1193:}252:mathleftright;
{:1193}{1196:}206:if curgroup=15 then aftermath else offsave;
{:1196}{1213:}72,173,274,73,174,275,74,175,276,75,176,277,76,177,278,77,
178,279,78,179,280,79,180,281,80,181,282,81,182,283,82,183,284,83,184,
285,84,185,286,85,186,287,86,187,288,87,188,289,88,189,290,89,190,291,90
,191,292,91,192,293,92,193,294,93,194,295,94,195,296,95,196,297,96,197,
298,97,198,299,98,199,300,99,200,301,100,201,302,101,202,303:
prefixedcommand;{:1213}{1271:}41,142,243:begin gettoken;
aftertoken:=curtok;end;{:1271}{1274:}42,143,244:begin gettoken;
saveforafter(curtok);end;{:1274}{1277:}61,162,263:openorclosein;
{:1277}{1279:}59,160,261:issuemessage;
{:1279}{1288:}58,159,260:shiftcase;
{:1288}{1293:}20,121,222:showwhatever;
{:1293}{1350:}60,161,262:doextension;{:1350}{:1048}end;goto 60;
70:{1037:}if((curlist.headfield=curlist.tailfield)and(curlist.modefield>
0))then begin if(insertsrcspecialauto)then appendsrcspecial;end;
mains:=eqtb[26399+curchr].hh.rh;
if mains=1000 then curlist.auxfield.hh.lh:=1000 else if mains<1000 then
begin if mains>0 then curlist.auxfield.hh.lh:=mains;
end else if curlist.auxfield.hh.lh<1000 then curlist.auxfield.hh.lh:=
1000 else curlist.auxfield.hh.lh:=mains;mainf:=eqtb[25579].hh.rh;
bchar:=fontbchar[mainf];falsebchar:=fontfalsebchar[mainf];
if curlist.modefield>0 then if eqtb[27217].int<>curlist.auxfield.hh.rh
then fixlanguage;begin ligstack:=avail;
if ligstack=-268435455 then ligstack:=getavail else begin avail:=mem[
ligstack].hh.rh;mem[ligstack].hh.rh:=-268435455;
ifdef('STAT')incr(dynused);endif('STAT')end;end;
mem[ligstack].hh.b0:=mainf;curl:=curchr;mem[ligstack].hh.b1:=curl;
curq:=curlist.tailfield;
if cancelboundary then begin cancelboundary:=false;maink:=0;
end else maink:=bcharlabel[mainf];if maink=0 then goto 92;curr:=curl;
curl:=256;goto 111;
80:{1038:}if curl<256 then begin if mem[curq].hh.rh>-268435455 then if
mem[curlist.tailfield].hh.b1=hyphenchar[mainf]then insdisc:=true;
if ligaturepresent then begin mainp:=newligature(mainf,curl,mem[curq].hh
.rh);if lfthit then begin mem[mainp].hh.b1:=2;lfthit:=false;end;
if rthit then if ligstack=-268435455 then begin incr(mem[mainp].hh.b1);
rthit:=false;end;mem[curq].hh.rh:=mainp;curlist.tailfield:=mainp;
ligaturepresent:=false;end;if insdisc then begin insdisc:=false;
if curlist.modefield>0 then begin mem[curlist.tailfield].hh.rh:=newdisc;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;end;end{:1038};
90:{1039:}if ligstack=-268435455 then goto 21;curq:=curlist.tailfield;
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
curlist.tailfield:=ligstack{:1039};100:{1041:}getnext;
if curcmd=11 then goto 101;if curcmd=12 then goto 101;
if curcmd=68 then goto 101;xtoken;if curcmd=11 then goto 101;
if curcmd=12 then goto 101;if curcmd=68 then goto 101;
if curcmd=16 then begin scancharnum;curchr:=curval;goto 101;end;
if curcmd=65 then bchar:=256;curr:=bchar;ligstack:=-268435455;goto 110;
101:mains:=eqtb[26399+curchr].hh.rh;
if mains=1000 then curlist.auxfield.hh.lh:=1000 else if mains<1000 then
begin if mains>0 then curlist.auxfield.hh.lh:=mains;
end else if curlist.auxfield.hh.lh<1000 then curlist.auxfield.hh.lh:=
1000 else curlist.auxfield.hh.lh:=mains;begin ligstack:=avail;
if ligstack=-268435455 then ligstack:=getavail else begin avail:=mem[
ligstack].hh.rh;mem[ligstack].hh.rh:=-268435455;
ifdef('STAT')incr(dynused);endif('STAT')end;end;
mem[ligstack].hh.b0:=mainf;curr:=curchr;mem[ligstack].hh.b1:=curr;
if curr=falsebchar then curr:=256{:1041};
110:{1042:}if((maini.b2)mod 4)<>1 then goto 80;if curr=256 then goto 80;
maink:=ligkernbase[mainf]+maini.b3;mainj:=fontinfo[maink].qqqq;
if mainj.b0<=128 then goto 112;
maink:=ligkernbase[mainf]+256*mainj.b2+mainj.b3+32768-256*(128);
111:mainj:=fontinfo[maink].qqqq;
112:if mainj.b1=curr then if mainj.b0<=128 then{1043:}begin if mainj.b2
>=128 then begin if curl<256 then begin if mem[curq].hh.rh>-268435455
then if mem[curlist.tailfield].hh.b1=hyphenchar[mainf]then insdisc:=true
;
if ligaturepresent then begin mainp:=newligature(mainf,curl,mem[curq].hh
.rh);if lfthit then begin mem[mainp].hh.b1:=2;lfthit:=false;end;
if rthit then if ligstack=-268435455 then begin incr(mem[mainp].hh.b1);
rthit:=false;end;mem[curq].hh.rh:=mainp;curlist.tailfield:=mainp;
ligaturepresent:=false;end;if insdisc then begin insdisc:=false;
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
rthit:=false;end;mem[curq].hh.rh:=mainp;curlist.tailfield:=mainp;
ligaturepresent:=false;end;if insdisc then begin insdisc:=false;
if curlist.modefield>0 then begin mem[curlist.tailfield].hh.rh:=newdisc;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;end;end;
curq:=curlist.tailfield;curl:=mainj.b3;
maini:=fontinfo[charbase[mainf]+effectivechar(true,mainf,curl)].qqqq;
ligaturepresent:=true;end;others:begin curl:=mainj.b3;
ligaturepresent:=true;if ligstack=-268435455 then goto 80 else goto 91;
end end;if mainj.b2>4 then if mainj.b2<>7 then goto 80;
if curl<256 then goto 110;maink:=bcharlabel[mainf];goto 111;end{:1043};
if mainj.b0=0 then incr(maink)else begin if mainj.b0>=128 then goto 80;
maink:=maink+mainj.b0+1;end;goto 111{:1042};
95:{1040:}mainp:=mem[ligstack+1].hh.rh;
if mainp>-268435455 then begin mem[curlist.tailfield].hh.rh:=mainp;
curlist.tailfield:=mem[curlist.tailfield].hh.rh;end;tempptr:=ligstack;
ligstack:=mem[tempptr].hh.rh;freenode(tempptr,2);
maini:=fontinfo[charbase[mainf]+effectivechar(true,mainf,curl)].qqqq;
ligaturepresent:=true;
if ligstack=-268435455 then if mainp>-268435455 then goto 100 else curr
:=bchar else curr:=mem[ligstack].hh.b1;goto 110{:1040}{:1037};
120:{1044:}if eqtb[24539].hh.rh=membot then begin{1045:}begin mainp:=
fontglue[eqtb[25579].hh.rh];
if mainp=-268435455 then begin mainp:=newspec(membot);
maink:=parambase[eqtb[25579].hh.rh]+2;
mem[mainp+1].int:=fontinfo[maink].int;
mem[mainp+2].int:=fontinfo[maink+1].int;
mem[mainp+3].int:=fontinfo[maink+2].int;
fontglue[eqtb[25579].hh.rh]:=mainp;end;end{:1045};
tempptr:=newglue(mainp);end else tempptr:=newparamglue(12);
mem[curlist.tailfield].hh.rh:=tempptr;curlist.tailfield:=tempptr;
goto 60{:1044};10:end;{:1033}{1287:}procedure giveerrhelp;
begin tokenshow(eqtb[25066].hh.rh);end;
{:1287}{1306:}{527:}function openfmtfile:boolean;label 40,10;
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
openfmtfile:=true;10:end;{:527}function loadfmtfile:boolean;
label 6666,10;var j,k:integer;p,q:halfword;x:integer;
formatengine:^ASCIIcode;dummyxord:ASCIIcode;dummyxchr:ASCIIcode;
dummyxprn:ASCIIcode;
begin{1311:}ifdef('INITEX')if iniversion then begin libcfree(fontinfo);
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
if x<>250953736 then begin;
writeln(stdout,'---! ',stringcast(nameoffile+1),' doesn''t match ',
poolname);goto 6666;end;
{1390:}if translatefilename then begin for k:=0 to 255 do undumpthings(
dummyxord,1);for k:=0 to 255 do undumpthings(dummyxchr,1);
for k:=0 to 255 do undumpthings(dummyxprn,1);
end else begin undumpthings(xord[0],256);undumpthings(xchr[0],256);
undumpthings(xprn[0],256);
if eightbitp then for k:=0 to 255 do xprn[k]:=1;end;{:1390};
undumpint(x);if x<>268435455 then goto 6666;undumpint(hashhigh);
if(hashhigh<0)or(hashhigh>suphashextra)then goto 6666;
if hashextra<hashhigh then hashextra:=hashhigh;eqtbtop:=28017+hashextra;
if hashextra=0 then hashtop:=24526 else hashtop:=eqtbtop;
yhash:=xmallocarray(twohalves,1+hashtop-hashoffset);
hash:=yhash-hashoffset;hash[514].lh:=0;hash[514].rh:=0;
for x:=515 to hashtop do hash[x]:=hash[514];
zeqtb:=xmallocarray(memoryword,eqtbtop+1);eqtb:=zeqtb;
eqtb[24526].hh.b0:=101;eqtb[24526].hh.rh:=-268435455;
eqtb[24526].hh.b1:=0;for x:=28018 to eqtbtop do eqtb[x]:=eqtb[24526];
undumpint(x);
if debugformatfile then begin write(stderr,'fmtdebug:','mem_bot');
writeln(stderr,' = ',x);end;;if x<>membot then goto 6666;
undumpint(memtop);
if debugformatfile then begin write(stderr,'fmtdebug:','mem_top');
writeln(stderr,' = ',memtop);end;;if membot+1100>memtop then goto 6666;
curlist.headfield:=memtop-1;curlist.tailfield:=memtop-1;
pagetail:=memtop-2;memmin:=membot-extramembot;
memmax:=memtop+extramemtop;
yzmem:=xmallocarray(memoryword,memmax-memmin+1);zmem:=yzmem-memmin;
mem:=zmem;undumpint(x);if x<>28017 then goto 6666;undumpint(x);
if x<>8501 then goto 6666;undumpint(x);if x<>607 then goto 6666{:1311};
{1404:}undumpint(x);if x<>1296847960 then goto 6666;undumpint(x);
if x=1 then mltexenabledp:=true else if x<>0 then goto 6666;{:1404};
{1413:}undumpint(x);if x<>1162040408 then goto 6666;undumpint(x);
if x=0 then enctexenabledp:=false else if x<>1 then goto 6666 else begin
enctexenabledp:=true;undumpthings(mubyteread[0],256);
undumpthings(mubytewrite[0],256);undumpthings(mubytecswrite[0],128);end;
{:1413};{1313:}begin undumpint(x);if x<0 then goto 6666;
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
initpoolptr:=poolptr{:1313};{1315:}begin undumpint(x);
if(x<membot+1019)or(x>memtop-14)then goto 6666 else lomemmax:=x;end;
begin undumpint(x);
if(x<membot+20)or(x>lomemmax)then goto 6666 else rover:=x;end;p:=membot;
q:=rover;repeat undumpthings(mem[p],q+2-p);p:=q+mem[q].hh.lh;
if(p>lomemmax)or((q>=mem[q+1].hh.rh)and(mem[q+1].hh.rh<>rover))then goto
6666;q:=mem[q+1].hh.rh;until q=rover;undumpthings(mem[p],lomemmax+1-p);
if memmin<membot-2 then begin p:=mem[rover+1].hh.lh;q:=memmin+1;
mem[memmin].hh.rh:=-268435455;mem[memmin].hh.lh:=-268435455;
mem[p+1].hh.rh:=q;mem[rover+1].hh.lh:=q;mem[q+1].hh.rh:=rover;
mem[q+1].hh.lh:=p;mem[q].hh.rh:=268435455;mem[q].hh.lh:=membot-q;end;
begin undumpint(x);
if(x<lomemmax+1)or(x>memtop-13)then goto 6666 else himemmin:=x;end;
begin undumpint(x);
if(x<-268435455)or(x>memtop)then goto 6666 else avail:=x;end;
memend:=memtop;undumpthings(mem[himemmin],memend+1-himemmin);
undumpint(varused);undumpint(dynused){:1315};{1317:}{1320:}k:=1;
repeat undumpint(x);if(x<1)or(k+x>28018)then goto 6666;
undumpthings(eqtb[k],x);k:=k+x;undumpint(x);
if(x<0)or(k+x>28018)then goto 6666;
for j:=k to k+x-1 do eqtb[j]:=eqtb[k-1];k:=k+x;until k>28017;
if hashhigh>0 then undumpthings(eqtb[28018],hashhigh);{:1320};
begin undumpint(x);if(x<514)or(x>hashtop)then goto 6666 else parloc:=x;
end;partoken:=4095+parloc;begin undumpint(x);
if(x<514)or(x>hashtop)then goto 6666 else writeloc:=x;end;
{1322:}begin undumpint(x);
if(x<514)or(x>15514)then goto 6666 else hashused:=x;end;p:=513;
repeat begin undumpint(x);
if(x<p+1)or(x>hashused)then goto 6666 else p:=x;end;undumphh(hash[p]);
until p=hashused;undumpthings(hash[hashused+1],24525-hashused);
if debugformatfile then begin printcsnames(514,24525);end;
if hashhigh>0 then begin undumpthings(hash[28018],hashhigh);
if debugformatfile then begin printcsnames(28018,hashhigh-(28018));end;
end;undumpint(cscount){:1322}{:1317};{1324:}begin undumpint(x);
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
{1326:}begin fontcheck:=xmallocarray(fourquarters,fontmax);
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
undumpthings(fontcheck[0],fontptr+1);
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
undumpcheckedthings(0,256,fontfalsebchar[0],fontptr+1);end{:1326};
{:1324};{1328:}begin undumpint(x);if x<0 then goto 6666;
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
ifdef('INITEX')triemax:=j;
endif('INITEX')if not trietrl then trietrl:=xmallocarray(triepointer,j+1
);undumpthings(trietrl[0],j+1);
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
ifdef('INITEX')trienotready:=false endif('INITEX'){:1328};
{1330:}begin undumpint(x);
if(x<0)or(x>3)then goto 6666 else interaction:=x;end;
if interactionoption<>4 then interaction:=interactionoption;
begin undumpint(x);
if(x<0)or(x>strptr)then goto 6666 else formatident:=x;end;undumpint(x);
if x<>69069 then goto 6666{:1330};loadfmtfile:=true;goto 10;6666:;
writeln(stdout,'(Fatal format file error; I''m stymied)');
loadfmtfile:=false;10:end;
{:1306}{1333:}{1336:}procedure closefilesandterminate;var k:integer;
begin{1381:}for k:=0 to 15 do if writeopen[k]then aclose(writefile[k])
{:1381};
ifdef('STAT')if eqtb[27198].int>0 then{1337:}if logopened then begin
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
savesize:1,'s');end{:1337};endif('STAT');
{645:}while curs>-1 do begin if curs>0 then begin dvibuf[dviptr]:=142;
incr(dviptr);if dviptr=dvilimit then dviswap;
end else begin begin dvibuf[dviptr]:=140;incr(dviptr);
if dviptr=dvilimit then dviswap;end;incr(totalpages);end;decr(curs);end;
if totalpages=0 then printnl(852)else if curs<>-2 then begin begin
dvibuf[dviptr]:=248;incr(dviptr);if dviptr=dvilimit then dviswap;end;
dvifour(lastbop);lastbop:=dvioffset+dviptr-5;dvifour(25400000);
dvifour(473628672);preparemag;dvifour(eqtb[27184].int);dvifour(maxv);
dvifour(maxh);begin dvibuf[dviptr]:=maxpush div 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=maxpush mod 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=(totalpages div 256)mod 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
begin dvibuf[dviptr]:=totalpages mod 256;incr(dviptr);
if dviptr=dvilimit then dviswap;end;
{646:}while fontptr>0 do begin if fontused[fontptr]then dvifontdef(
fontptr);decr(fontptr);end{:646};begin dvibuf[dviptr]:=249;incr(dviptr);
if dviptr=dvilimit then dviswap;end;dvifour(lastbop);
begin dvibuf[dviptr]:=2;incr(dviptr);if dviptr=dvilimit then dviswap;
end;ifdef('IPC')k:=7-((3+dvioffset+dviptr)mod 4);
endif('IPC')ifndef('IPC')k:=4+((dvibufsize-dviptr)mod 4);
endifn('IPC')while k>0 do begin begin dvibuf[dviptr]:=223;incr(dviptr);
if dviptr=dvilimit then dviswap;end;decr(k);end;
{602:}if dvilimit=halfbuf then writedvi(halfbuf,dvibufsize-1);
if dviptr>(2147483647-dvioffset)then begin curs:=-2;fatalerror(841);end;
if dviptr>0 then writedvi(0,dviptr-1){:602};printnl(853);
printfilename(0,outputfilename,0);print(284);printint(totalpages);
if totalpages<>1 then print(854)else print(855);print(856);
printint(dvioffset+dviptr);print(857);bclose(dvifile);end{:645};
if logopened then begin writeln(logfile);aclose(logfile);
selector:=selector-2;if selector=17 then begin printnl(1307);
printfilename(0,texmflogname,0);printchar(46);end;end;println;
if(editnamestart<>0)and(interaction>0)then calledit(strpool,
editnamestart,editnamelength,editline);end;
{:1336}{1338:}procedure finalcleanup;label 10;var c:smallnumber;
begin c:=curchr;if jobname=0 then openlogfile;
while inputptr>0 do if curinput.statefield=0 then endtokenlist else
endfilereading;while openparens>0 do begin print(1308);decr(openparens);
end;if curlevel>1 then begin printnl(40);printesc(1309);print(1310);
printint(curlevel-1);printchar(41);end;
while condptr<>-268435455 do begin printnl(40);printesc(1309);
print(1311);printcmdchr(105,curif);if ifline<>0 then begin print(1312);
printint(ifline);end;print(1313);ifline:=mem[condptr+1].int;
curif:=mem[condptr].hh.b1;tempptr:=condptr;condptr:=mem[condptr].hh.rh;
freenode(tempptr,2);end;
if history<>0 then if((history=1)or(interaction<3))then if selector=19
then begin selector:=17;printnl(1314);selector:=19;end;
if c=1 then begin ifdef('INITEX')if iniversion then begin for c:=0 to 4
do if curmark[c]<>-268435455 then deletetokenref(curmark[c]);
if lastglue<>268435455 then deleteglueref(lastglue);storefmtfile;
goto 10;end;endif('INITEX')printnl(1315);goto 10;end;10:end;
{:1338}{1339:}ifdef('INITEX')procedure initprim;
begin nonewcontrolsequence:=false;{226:}primitive(381,75,24527);
primitive(382,75,24528);primitive(383,75,24529);primitive(384,75,24530);
primitive(385,75,24531);primitive(386,75,24532);primitive(387,75,24533);
primitive(388,75,24534);primitive(389,75,24535);primitive(390,75,24536);
primitive(391,75,24537);primitive(392,75,24538);primitive(393,75,24539);
primitive(394,75,24540);primitive(395,75,24541);primitive(396,76,24542);
primitive(397,76,24543);primitive(398,76,24544);
{:226}{230:}primitive(403,72,25058);primitive(404,72,25059);
primitive(405,72,25060);primitive(406,72,25061);primitive(407,72,25062);
primitive(408,72,25063);primitive(409,72,25064);primitive(410,72,25065);
primitive(411,72,25066);{:230}{238:}primitive(425,73,27167);
primitive(426,73,27168);primitive(427,73,27169);primitive(428,73,27170);
primitive(429,73,27171);primitive(430,73,27172);primitive(431,73,27173);
primitive(432,73,27174);primitive(433,73,27175);primitive(434,73,27176);
primitive(435,73,27177);primitive(436,73,27178);primitive(437,73,27179);
primitive(438,73,27180);primitive(439,73,27181);primitive(440,73,27182);
primitive(441,73,27183);primitive(442,73,27184);primitive(443,73,27185);
primitive(444,73,27186);primitive(445,73,27187);primitive(446,73,27188);
primitive(447,73,27189);primitive(448,73,27190);primitive(449,73,27191);
primitive(450,73,27192);primitive(451,73,27193);primitive(452,73,27194);
primitive(453,73,27195);primitive(454,73,27196);primitive(455,73,27197);
primitive(456,73,27198);primitive(457,73,27199);primitive(458,73,27200);
primitive(459,73,27201);primitive(460,73,27202);primitive(461,73,27203);
primitive(462,73,27204);primitive(463,73,27205);primitive(464,73,27206);
primitive(465,73,27207);primitive(466,73,27208);primitive(467,73,27209);
primitive(468,73,27210);primitive(469,73,27211);primitive(470,73,27212);
primitive(471,73,27213);primitive(472,73,27214);primitive(473,73,27215);
primitive(474,73,27216);primitive(475,73,27217);primitive(476,73,27218);
primitive(477,73,27219);primitive(478,73,27220);primitive(479,73,27221);
if mltexp then begin mltexenabledp:=true;
if false then primitive(480,73,27222);primitive(481,73,27223);
primitive(482,73,27224);end;if enctexp then begin enctexenabledp:=true;
primitive(483,73,27225);primitive(484,73,27226);primitive(485,73,27227);
primitive(486,73,27228);end;{:238}{248:}primitive(490,74,27741);
primitive(491,74,27742);primitive(492,74,27743);primitive(493,74,27744);
primitive(494,74,27745);primitive(495,74,27746);primitive(496,74,27747);
primitive(497,74,27748);primitive(498,74,27749);primitive(499,74,27750);
primitive(500,74,27751);primitive(501,74,27752);primitive(502,74,27753);
primitive(503,74,27754);primitive(504,74,27755);primitive(505,74,27756);
primitive(506,74,27757);primitive(507,74,27758);primitive(508,74,27759);
primitive(509,74,27760);primitive(510,74,27761);
{:248}{265:}primitive(32,64,0);primitive(47,44,0);primitive(520,45,0);
primitive(521,90,0);primitive(522,40,0);primitive(523,41,0);
primitive(524,61,0);primitive(525,16,0);primitive(516,107,0);
primitive(526,15,0);primitive(527,92,0);primitive(517,67,0);
if enctexp then begin primitive(528,67,10);end;primitive(529,62,0);
hash[15516].rh:=529;eqtb[15516]:=eqtb[curval];primitive(530,102,0);
primitive(531,88,0);primitive(532,77,0);primitive(533,32,0);
primitive(534,36,0);primitive(535,39,0);primitive(327,37,0);
primitive(348,18,0);primitive(536,46,0);primitive(537,17,0);
primitive(538,54,0);primitive(539,91,0);primitive(540,34,0);
primitive(541,65,0);primitive(542,103,0);primitive(332,55,0);
primitive(543,63,0);primitive(413,84,0);primitive(544,42,0);
primitive(545,80,0);primitive(546,66,0);primitive(547,96,0);
primitive(548,0,256);hash[15521].rh:=548;eqtb[15521]:=eqtb[curval];
primitive(549,98,0);primitive(550,109,0);primitive(412,71,0);
primitive(349,38,0);primitive(551,33,0);primitive(552,56,0);
primitive(553,35,0);{:265}{334:}primitive(609,13,256);parloc:=curval;
partoken:=4095+parloc;{:334}{379:}primitive(644,104,0);
primitive(645,104,1);{:379}{387:}primitive(646,110,0);
primitive(647,110,1);primitive(648,110,2);primitive(649,110,3);
primitive(650,110,4);{:387}{414:}primitive(488,89,0);
primitive(512,89,1);primitive(400,89,2);primitive(401,89,3);
{:414}{419:}primitive(683,79,102);primitive(684,79,1);
primitive(685,82,0);primitive(686,82,1);primitive(687,83,1);
primitive(688,83,3);primitive(689,83,2);primitive(690,70,0);
primitive(691,70,1);primitive(692,70,2);primitive(693,70,3);
primitive(694,70,4);{:419}{471:}primitive(750,108,0);
primitive(751,108,1);primitive(752,108,2);primitive(753,108,3);
primitive(754,108,4);primitive(755,108,5);
{:471}{490:}primitive(771,105,0);primitive(772,105,1);
primitive(773,105,2);primitive(774,105,3);primitive(775,105,4);
primitive(776,105,5);primitive(777,105,6);primitive(778,105,7);
primitive(779,105,8);primitive(780,105,9);primitive(781,105,10);
primitive(782,105,11);primitive(783,105,12);primitive(784,105,13);
primitive(785,105,14);primitive(786,105,15);primitive(787,105,16);
{:490}{494:}primitive(788,106,2);hash[15518].rh:=788;
eqtb[15518]:=eqtb[curval];primitive(789,106,4);primitive(790,106,3);
{:494}{556:}primitive(815,87,0);hash[15525].rh:=815;
eqtb[15525]:=eqtb[curval];{:556}{783:}primitive(914,4,256);
primitive(915,5,257);hash[15515].rh:=915;eqtb[15515]:=eqtb[curval];
primitive(916,5,258);hash[15519].rh:=917;hash[15520].rh:=917;
eqtb[15520].hh.b0:=9;eqtb[15520].hh.rh:=memtop-11;eqtb[15520].hh.b1:=1;
eqtb[15519]:=eqtb[15520];eqtb[15519].hh.b0:=115;
{:783}{986:}primitive(986,81,0);primitive(987,81,1);primitive(988,81,2);
primitive(989,81,3);primitive(990,81,4);primitive(991,81,5);
primitive(992,81,6);primitive(993,81,7);
{:986}{1055:}primitive(1040,14,0);primitive(1041,14,1);
{:1055}{1061:}primitive(1042,26,4);primitive(1043,26,0);
primitive(1044,26,1);primitive(1045,26,2);primitive(1046,26,3);
primitive(1047,27,4);primitive(1048,27,0);primitive(1049,27,1);
primitive(1050,27,2);primitive(1051,27,3);primitive(333,28,5);
primitive(337,29,1);primitive(339,30,99);
{:1061}{1074:}primitive(1069,21,1);primitive(1070,21,0);
primitive(1071,22,1);primitive(1072,22,0);primitive(414,20,0);
primitive(1073,20,1);primitive(1074,20,2);primitive(981,20,3);
primitive(1075,20,4);primitive(983,20,5);primitive(1076,20,106);
primitive(1077,31,99);primitive(1078,31,100);primitive(1079,31,101);
primitive(1080,31,102);{:1074}{1091:}primitive(1095,43,1);
primitive(1096,43,0);{:1091}{1110:}primitive(1105,25,12);
primitive(1106,25,11);primitive(1107,25,10);primitive(1108,23,0);
primitive(1109,23,1);primitive(1110,24,0);primitive(1111,24,1);
{:1110}{1117:}primitive(45,47,1);primitive(346,47,0);
{:1117}{1144:}primitive(1143,48,0);primitive(1144,48,1);
{:1144}{1159:}primitive(882,50,16);primitive(883,50,17);
primitive(884,50,18);primitive(885,50,19);primitive(886,50,20);
primitive(887,50,21);primitive(888,50,22);primitive(889,50,23);
primitive(891,50,26);primitive(890,50,27);primitive(1145,51,0);
primitive(894,51,1);primitive(895,51,2);
{:1159}{1172:}primitive(877,53,0);primitive(878,53,2);
primitive(879,53,4);primitive(880,53,6);
{:1172}{1181:}primitive(1163,52,0);primitive(1164,52,1);
primitive(1165,52,2);primitive(1166,52,3);primitive(1167,52,4);
primitive(1168,52,5);{:1181}{1191:}primitive(892,49,30);
primitive(893,49,31);hash[15517].rh:=893;eqtb[15517]:=eqtb[curval];
{:1191}{1211:}primitive(1187,93,1);primitive(1188,93,2);
primitive(1189,93,4);primitive(1190,97,0);primitive(1191,97,1);
primitive(1192,97,2);primitive(1193,97,3);
{:1211}{1222:}primitive(1207,94,0);primitive(1208,94,1);
if enctexp then begin primitive(1209,94,10);primitive(1210,94,11);end;
{:1222}{1225:}primitive(1216,95,0);primitive(1217,95,1);
primitive(1218,95,2);primitive(1219,95,3);primitive(1220,95,4);
primitive(1221,95,5);primitive(1222,95,6);
if mltexp then begin primitive(1223,95,7);end;
{:1225}{1233:}primitive(420,85,25631);
if enctexp then begin primitive(1228,85,25580);primitive(1229,85,25581);
primitive(1230,85,25582);end;primitive(424,85,26655);
primitive(421,85,25887);primitive(422,85,26143);primitive(423,85,26399);
primitive(489,85,27485);primitive(417,86,25583);primitive(418,86,25599);
primitive(419,86,25615);{:1233}{1253:}primitive(957,99,0);
primitive(969,99,1);{:1253}{1257:}primitive(1246,78,0);
primitive(1247,78,1);{:1257}{1265:}primitive(272,100,0);
primitive(273,100,1);primitive(274,100,2);primitive(1256,100,3);
{:1265}{1275:}primitive(1257,60,1);primitive(1258,60,0);
{:1275}{1280:}primitive(1259,58,0);primitive(1260,58,1);
{:1280}{1289:}primitive(1266,57,25887);primitive(1267,57,26143);
{:1289}{1294:}primitive(1268,19,0);primitive(1269,19,1);
primitive(1270,19,2);primitive(1271,19,3);
{:1294}{1347:}primitive(1317,59,0);primitive(606,59,1);writeloc:=curval;
primitive(1318,59,2);primitive(1319,59,3);hash[15524].rh:=1319;
eqtb[15524]:=eqtb[curval];primitive(1320,59,4);primitive(1321,59,5);
{:1347};nonewcontrolsequence:=true;end;
endif('INITEX'){:1339}{1341:}ifdef('TEXMF_DEBUG')procedure debughelp;
label 888,10;var k,l,m,n:integer;begin while true do begin;
printnl(1316);fflush(stdout);read(stdin,m);
if m<0 then goto 10 else if m=0 then dumpcore else begin read(stdin,n);
case m of{1342:}1:printword(mem[n]);2:printint(mem[n].hh.lh);
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
{:1342}others:print(63)end;end;end;10:end;
endif('TEXMF_DEBUG'){:1341}{:1333}{1335:}procedure mainbody;
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
if errorline>255 then errorline:=255;
buffer:=xmallocarray(ASCIIcode,bufsize);
nest:=xmallocarray(liststaterecord,nestsize);
savestack:=xmallocarray(memoryword,savesize);
inputstack:=xmallocarray(instaterecord,stacksize);
inputfile:=xmallocarray(alphafile,maxinopen);
linestack:=xmallocarray(integer,maxinopen);
sourcefilenamestack:=xmallocarray(strnumber,maxinopen);
fullsourcefilenamestack:=xmallocarray(strnumber,maxinopen);
paramstack:=xmallocarray(halfword,paramsize);
dvibuf:=xmallocarray(eightbits,dvibufsize);
hyphword:=xmallocarray(strnumber,hyphsize);
hyphlist:=xmallocarray(halfword,hyphsize);
hyphlink:=xmallocarray(hyphpointer,hyphsize);
ifdef('INITEX')if iniversion then begin yzmem:=xmallocarray(memoryword,
memtop-membot+1);zmem:=yzmem-membot;eqtbtop:=28017+hashextra;
if hashextra=0 then hashtop:=24526 else hashtop:=eqtbtop;
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
{:14}{111:}ifdef('INITEX')if(memmin<>membot)or(memmax<>memtop)then bad:=
10;endif('INITEX')if(memmin>membot)or(memmax<memtop)then bad:=10;
if(0>0)or(255<127)then bad:=11;
if(-268435455>0)or(268435455<32767)then bad:=12;
if(0<-268435455)or(255>268435455)then bad:=13;
if(membot-supmainmemory<-268435455)or(memtop+supmainmemory>=268435455)
then bad:=14;if(9000<-268435455)or(9000>268435455)then bad:=15;
if fontmax>9000 then bad:=16;
if(savesize>268435455)or(maxstrings>268435455)then bad:=17;
if bufsize>268435455 then bad:=18;if 255<255 then bad:=19;
{:111}{290:}if 32112+hashextra>268435455 then bad:=21;
if(hashoffset<0)or(hashoffset>514)then bad:=42;
{:290}{525:}if formatdefaultlength>maxint then bad:=31;
{:525}{1252:}if 2*268435455<memtop-memmin then bad:=41;
{:1252}if bad>0 then begin writeln(stdout,
'Ouch---my internal constants have been clobbered!','---case ',bad:1);
goto 9999;end;initialize;
ifdef('INITEX')if iniversion then begin if not getstringsstarted then
goto 9999;initprim;initstrptr:=strptr;initpoolptr:=poolptr;
dateandtime(eqtb[27187].int,eqtb[27188].int,eqtb[27189].int,eqtb[27190].
int);end;endif('INITEX')readyalready:=314159;1:{55:}selector:=17;
tally:=0;termoffset:=0;fileoffset:=0;
{:55}{61:}if srcspecialsp or filelineerrorstylep or parsefirstlinep then
write(stdout,'This is TeXk, Version 3.14159265')else write(stdout,
'This is TeX, Version 3.14159265');write(stdout,versionstring);
if formatident=0 then writeln(stdout,' (preloaded format=',dumpname,')')
else begin slowprint(formatident);println;end;
if shellenabledp then begin write(stdout,' ');
if restrictedshell then begin write(stdout,'restricted ');end;
writeln(stdout,'\write18 enabled.');end;
if srcspecialsp then begin writeln(stdout,' Source specials enabled.')
end;if translatefilename then begin write(stdout,' (');
fputs(translatefilename,stdout);writeln(stdout,')');end;fflush(stdout);
{:61}{531:}jobname:=0;nameinprogress:=false;logopened:=false;
{:531}{536:}outputfilename:=0;{:536};
{1340:}begin{331:}begin inputptr:=0;maxinstack:=0;
sourcefilenamestack[0]:=0;fullsourcefilenamestack[0]:=0;inopen:=0;
openparens:=0;maxbufstack:=0;paramptr:=0;maxparamstack:=0;
first:=bufsize;repeat buffer[first]:=0;decr(first);until first=0;
scannerstatus:=0;warningindex:=-268435455;first:=1;
curinput.statefield:=33;curinput.startfield:=1;curinput.indexfield:=0;
line:=0;curinput.namefield:=0;forceeof:=false;alignstate:=1000000;
if not initterminal then goto 9999;curinput.limitfield:=last;
first:=last+1;end{:331};
if(formatident=0)or(buffer[curinput.locfield]=38)or dumpline then begin
if formatident<>0 then initialize;if not openfmtfile then goto 9999;
if not loadfmtfile then begin wclose(fmtfile);goto 9999;end;
wclose(fmtfile);eqtb:=zeqtb;
while(curinput.locfield<curinput.limitfield)and(buffer[curinput.locfield
]=32)do incr(curinput.locfield);end;
if(eqtb[27215].int<0)or(eqtb[27215].int>255)then decr(curinput.
limitfield)else buffer[curinput.limitfield]:=eqtb[27215].int;
if mltexenabledp then begin writeln(stdout,'MLTeX v2.2 enabled');end;
if enctexenabledp then begin write(stdout,' encTeX v. Jun. 2004');
writeln(stdout,', reencoding enabled.');
if translatefilename then begin writeln(stdout,
' (\xordcode, \xchrcode, \xprncode overridden by TCX)');end;end;
dateandtime(eqtb[27187].int,eqtb[27188].int,eqtb[27189].int,eqtb[27190].
int);ifdef('INITEX')if trienotready then begin trietrl:=xmallocarray(
triepointer,triesize);trietro:=xmallocarray(triepointer,triesize);
trietrc:=xmallocarray(quarterword,triesize);
triec:=xmallocarray(packedASCIIcode,triesize);
trieo:=xmallocarray(trieopcode,triesize);
triel:=xmallocarray(triepointer,triesize);
trier:=xmallocarray(triepointer,triesize);
triehash:=xmallocarray(triepointer,triesize);
trietaken:=xmallocarray(boolean,triesize);triel[0]:=0;triec[0]:=0;
trieptr:=0;fontcheck:=xmallocarray(fourquarters,fontmax);
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
parambase:=xmallocarray(integer,fontmax);fontptr:=0;fmemptr:=7;
fontname[0]:=815;fontarea[0]:=335;hyphenchar[0]:=45;skewchar[0]:=-1;
bcharlabel[0]:=0;fontbchar[0]:=256;fontfalsebchar[0]:=256;fontbc[0]:=1;
fontec[0]:=0;fontsize[0]:=0;fontdsize[0]:=0;charbase[0]:=0;
widthbase[0]:=0;heightbase[0]:=0;depthbase[0]:=0;italicbase[0]:=0;
ligkernbase[0]:=0;kernbase[0]:=0;extenbase[0]:=0;
fontglue[0]:=-268435455;fontparams[0]:=7;parambase[0]:=-1;
for fontk:=0 to 6 do fontinfo[fontk].int:=0;end;
endif('INITEX')fontused:=xmallocarray(boolean,fontmax);
for fontk:=0 to fontmax do fontused[fontk]:=false;
{768:}magicoffset:=strstart[908]-9*16{:768};
{75:}if interaction=0 then selector:=16 else selector:=17{:75};
if(curinput.locfield<curinput.limitfield)and(eqtb[25631+buffer[curinput.
locfield]].hh.rh<>0)then startinput;end{:1340};history:=0;maincontrol;
finalcleanup;closefilesandterminate;9999:begin fflush(stdout);
readyalready:=0;if(history<>0)and(history<>1)then uexit(1)else uexit(0);
end;end;{:1335}{1416:}function getnullstr:strnumber;
begin getnullstr:=335;end;{:1416}
