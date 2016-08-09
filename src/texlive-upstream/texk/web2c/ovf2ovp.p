{2:}
 @define var tfm;
program OVF2OVP(vffile,tfmfile,vplfile,output);label{3:}9999;{:3}
const{4:}vfsize=600000;maxfonts=300;vcsize=150000;ligsize=800000;
hashsize=130003;hashmult=16007;maxchar=1114111;xmaxchar=1114112;
xxmaxchar=1114113;xmaxlabel=80001;maxstack=50;{:4}{164:}charcodeascii=0;
charcodehex=1;charcodedefault=2;{:164}type{5:}byte=0..255;{:5}{23:}
indextype=integer;chartype=0..1114111;xchartype=0..1114112;
xxchartype=0..1114113;xxxchartype=0..1114114;{:23}{163:}
charcodeformattype=charcodeascii..charcodedefault;{:163}var{7:}
vffile:packed file of byte;{:7}{10:}tfmfile:packed file of byte;{:10}
{12:}
ofmlevel,nco,ncw,npc,nki,nwi,nkf,nwf,nkr,nwr,nkg,nwg,nkp,nwp,nkm,nwm,
reallf,nlw,neew,lf,lh,bc,ec,nw,nh,nd,ni,nl,nk,ne,np,fontdir:integer;
ofmon:boolean;{:12}{21:}vplfile:text;{:21}{24:}
#define tfm (tfmfilearray + 1001);
tfmfilearray:^byte;
topchar,topwidth,topheight,topdepth,topitalic:integer;
startptr,checksum,designsize,scheme,family,randomword:integer;
headerlength,charptr,copies,j:integer;{:24}{27:}
ivaluesstart,fvaluesstart,mvaluesstart,rulesstart,gluesstart,
penaltiesstart:integer;
ivaluesbase,fvaluesbase,mvaluesbase,rulesbase,gluesbase,penaltiesbase:
integer;charbase,widthbase,heightbase,depthbase,italicbase:integer;
ligkernbase,kernbase,extenbase,parambase:integer;
charstart:array[0..maxchar]of integer;bytesperentry:integer;{:27}{30:}
fonttype:0..2;{:30}{31:}vf:array[0..vfsize]of byte;
vc:array[0..vcsize]of chartype;fontnumber:array[0..maxfonts]of integer;
fontstart:array[0..maxfonts]of 0..vfsize;
fontchars:array[0..maxfonts]of 0..vcsize;fontptr:0..maxfonts;
packetstart,packetend:array[chartype]of 0..vfsize;packetfound:boolean;
tempbyte:byte;regcount:integer;realdsize:real;pl:integer;
vfptr:0..vfsize;vcptr:0..vcsize;vfcount:integer;{:31}{38:}a:integer;
l:integer;curname:^char;b0,b1,b2,b3:byte;fontlh:integer;
fontbc,fontec:integer;fontofmlevel,fontextrawords:integer;
fontkprime,fontj,fontwd:integer;{:38}{45:}
defaultdirectory:packed array[1..9]of char;{:45}{53:}
ASCII04,ASCII10,ASCII14:constcstring;
ASCIIall:packed array[0..256]of char;xchr:packed array[0..255]of char;
MBLstring,RIstring,RCEstring:constcstring;HEX:constcstring;{:53}{55:}
dig:array[0..11]of integer;{:55}{58:}level:0..5;{:58}{71:}
charsonline:0..8;perfect:boolean;{:71}{73:}i:integer;c:xchartype;d:0..3;
k:indextype;r:0..maxchar;count:0..127;{:73}{88:}
startcounter,basecounter,numberentries:integer;value:integer;{:88}{98:}
gluesubtype,glueargumentkind,gluestretchorder,glueshrinkorder,
glueargument:integer;{:98}{103:}
labeltable:array[xxxchartype]of record cc:xchartype;rr:0..ligsize;
ischar:boolean;end;labelptr:xxchartype;sortptr:xxchartype;
boundarychar:xchartype;bcharlabel:0..xmaxlabel;{:103}{105:}
activity:array[0..ligsize]of 0..2;ai,acti:0..ligsize;{:105}{112:}
outputclabels:array[0..256]of boolean;clabelrunner:integer;
cprime:integer;{:112}{128:}extenchar:integer;{:128}{132:}
hash:array[0..hashsize]of integer64;classvar:array[0..hashsize]of 0..4;
ligz:array[0..hashsize]of xxchartype;hashptr:0..hashsize;
hashlist:array[0..hashsize]of 0..hashsize;h,hh:0..hashsize;
xligcycle,yligcycle:xchartype;{:132}{144:}top:0..maxstack;
wstack,xstack,ystack,zstack:array[0..maxstack]of integer;
vflimit:0..vfsize;o:byte;{:144}{160:}verbose:cinttype;{:160}{165:}
charcodeformat:charcodeformattype;{:165}{168:}tfmname:cstring;
vfname,vplname:constcstring;{:168}{156:}procedure parsearguments;
const noptions=4;var longoptions:array[0..noptions]of getoptstruct;
getoptreturnval:integer;optionindex:cinttype;currentoption:0..noptions;
begin{161:}verbose:=false;{:161}{166:}charcodeformat:=charcodedefault;
{:166};{157:}currentoption:=0;longoptions[currentoption].name:='help';
longoptions[currentoption].hasarg:=0;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;currentoption:=currentoption+1;{:157}
{158:}longoptions[currentoption].name:='version';
longoptions[currentoption].hasarg:=0;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;currentoption:=currentoption+1;{:158}
{159:}longoptions[currentoption].name:='verbose';
longoptions[currentoption].hasarg:=0;
longoptions[currentoption].flag:=addressof(verbose);
longoptions[currentoption].val:=1;currentoption:=currentoption+1;{:159}
{162:}longoptions[currentoption].name:='charcode-format';
longoptions[currentoption].hasarg:=1;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;currentoption:=currentoption+1;{:162}
{167:}longoptions[currentoption].name:=0;
longoptions[currentoption].hasarg:=0;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;{:167};
repeat getoptreturnval:=getoptlongonly(argc,argv,'',longoptions,
addressof(optionindex));if getoptreturnval=-1 then begin;
end else if getoptreturnval=63 then begin usage('ovf2ovp');
end else if(strcmp(longoptions[optionindex].name,'help')=0)then begin
usagehelp(OVF2OVPHELP,nil);
end else if(strcmp(longoptions[optionindex].name,'version')=0)then begin
printversionandexit('This is OVF2OVP, Version 1.13',nil,
'J. Plaice, Y. Haralambous, D.E. Knuth',nil);
end else if(strcmp(longoptions[optionindex].name,'charcode-format')=0)
then begin if strcmp(optarg,'ascii')=0 then charcodeformat:=
charcodeascii else if strcmp(optarg,'hex')=0 then charcodeformat:=
charcodehex else writeln(stderr,'Bad character code format ',stringcast(
optarg),'.');end;until getoptreturnval=-1;
if(optind+1<>argc)and(optind+2<>argc)and(optind+3<>argc)then begin
writeln(stderr,'ovf2ovp',': Need one to three file arguments.');
usage('ovf2ovp');end;vfname:=cmdline(optind);
if optind+2<=argc then begin tfmname:=cmdline(optind+1);
end else begin tfmname:=basenamechangesuffix(vfname,'.ovf','.ofm');end;
end;{:156}procedure initialize;var k:integer;
begin kpsesetprogramname(argv[0],'ovf2ovp');
kpseinitprog('VFTOVP',0,nil,nil);tfmfilearray:=xmallocarray(byte,1008);
parsearguments;{11:}vffile:=kpseopenfile(vfname,kpseovfformat);
tfmfile:=kpseopenfile(tfmname,kpseofmformat);
if verbose then begin write(stderr,'This is OVF2OVP, Version 1.13');
writeln(stderr,versionstring);end;{:11}{13:}ofmon:=false;ofmlevel:=-1;
lf:=0;lh:=0;nco:=0;ncw:=0;npc:=0;bc:=0;ec:=0;nw:=0;nh:=0;nd:=0;ni:=0;
nl:=0;nk:=0;ne:=0;np:=0;nki:=0;nwi:=0;nkf:=0;nwf:=0;nkm:=0;nwm:=0;
reallf:=0;nkr:=0;nwr:=0;nkg:=0;nwg:=0;nkp:=0;nwp:=0;fontdir:=0;{:13}
{22:}if optind+3>argc then begin vplfile:=stdout;
end else begin vplname:=extendfilename(cmdline(optind+2),'ovp');
rewrite(vplfile,vplname);end;{:22}{54:}
ASCII04:='  !"#$%&''()*+,-./0123456789:;<=>?';
ASCII10:=' @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_';
ASCII14:=' `abcdefghijklmnopqrstuvwxyz{|}~?';strcpy(ASCIIall,ASCII04);
strcat(ASCIIall,'@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_');
strcat(ASCIIall,'`abcdefghijklmnopqrstuvwxyz{|}~');
for k:=0 to 255 do xchr[k]:='?';
for k:=0 to 31 do begin xchr[k+32]:=ASCII04[k+1];
xchr[k+64]:=ASCII10[k+1];xchr[k+96]:=ASCII14[k+1];end;MBLstring:=' MBL';
RIstring:=' RI ';RCEstring:=' RCE';HEX:=' 0123456789ABCDEF';{:54}{59:}
level:=0;{:59}{72:}charsonline:=0;perfect:=true;{:72}{104:}
boundarychar:=xmaxchar;bcharlabel:=xmaxlabel;labelptr:=0;
labeltable[0].rr:=0;{:104}{113:}
for clabelrunner:=0 to 256 do outputclabels[clabelrunner]:=false;{:113}
end;{:2}{29:}function widthindex(c:chartype):integer;
begin if not ofmon then widthindex:=tfm[charstart[c]]else widthindex:=
256*tfm[charstart[c]]+tfm[charstart[c]+1];end;
function heightindex(c:chartype):integer;
begin if not ofmon then heightindex:=tfm[charstart[c]+1]div 16 else
heightindex:=tfm[charstart[c]+2];end;
function depthindex(c:chartype):integer;
begin if not ofmon then depthindex:=tfm[charstart[c]+1]mod 16 else
depthindex:=tfm[charstart[c]+3];end;
function italicindex(c:chartype):integer;
begin if not ofmon then italicindex:=tfm[charstart[c]+2]div 4 else
italicindex:=tfm[charstart[c]+4];end;function tag(c:chartype):integer;
begin if not ofmon then tag:=tfm[charstart[c]+2]mod 4 else tag:=tfm[
charstart[c]+5]mod 4;end;procedure setnotag(c:chartype);
begin if not ofmon then tfm[charstart[c]+2]:=(tfm[charstart[c]+2]div 64)
*64+0 else tfm[charstart[c]+5]:=(tfm[charstart[c]+5]div 64)*64+0;end;
procedure checkunused(c:chartype);var x:integer;
begin if ofmlevel=1 then x:=tfm[charstart[c]+5]div 8 else x:=tfm[
charstart[c]+5]div 4;
if x<>0 then begin if ofmlevel=1 then x:=tfm[charstart[c]+5]mod 8 else x
:=tfm[charstart[c]+5]mod 4;tfm[charstart[c]+5]:=x;perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Ignoring non-zero unused char info bits');end;end;
function ctag(c:chartype):boolean;
begin if not(ofmlevel=1)then ctag:=false else ctag:=tfm[charstart[c]+5]
div 4 mod 2;end;procedure setnoctag(c:chartype);
begin if not(ofmlevel=1)then tfm[charstart[c]+5]:=tfm[charstart[c]+5]div
8*8+tfm[charstart[c]+5]mod 4;end;function norepeats(c:chartype):integer;
begin if ofmlevel<=0 then norepeats:=0 else norepeats:=256*tfm[charstart
[c]+8]+tfm[charstart[c]+9];end;function charparam(c:chartype;
i:integer):integer;
begin charparam:=256*tfm[charstart[c]+2*i+10]+tfm[charstart[c]+2*i+11];
end;function rremainder(c:chartype):integer;
begin if not ofmon then rremainder:=tfm[charstart[c]+3]else rremainder:=
256*tfm[charstart[c]+6]+tfm[charstart[c]+7];end;
function ligstep(c:chartype):integer;
begin if not ofmon then ligstep:=4*(ligkernbase+c)else ligstep:=4*(
ligkernbase+2*c);end;function exten(c:chartype):integer;
begin if not ofmon then exten:=4*(extenbase+rremainder(c))else exten:=4*
(extenbase+2*rremainder(c));end;function lskipbyte(c:integer):integer;
begin if not ofmon then lskipbyte:=tfm[c]else lskipbyte:=256*tfm[c]+tfm[
c+1];end;procedure setlskipbyte(c:integer;newc:integer);
begin if not ofmon then tfm[c]:=newc else begin tfm[c]:=newc div 256;
tfm[c+1]:=newc mod 256 end end;function lnextchar(c:integer):integer;
begin if not ofmon then lnextchar:=tfm[c+1]else lnextchar:=256*tfm[c+2]+
tfm[c+3];end;procedure setlnextchar(c:integer;newc:chartype);
begin if not ofmon then tfm[c+1]:=newc else begin tfm[c+2]:=newc div 256
;tfm[c+3]:=newc mod 256 end end;function lopbyte(c:integer):integer;
begin if not ofmon then lopbyte:=tfm[c+2]else lopbyte:=256*tfm[c+4]+tfm[
c+5];end;procedure setlopbyte(c:integer;newc:integer);
begin if not ofmon then tfm[c+2]:=newc else begin tfm[c+2]:=newc div 256
;tfm[c+3]:=newc mod 256 end end;function lremainder(c:integer):integer;
begin if not ofmon then lremainder:=tfm[c+3]else lremainder:=256*tfm[c+6
]+tfm[c+7];end;procedure setlremainder(c:integer;newc:chartype);
begin if not ofmon then tfm[c+3]:=newc else begin tfm[c+6]:=newc div 256
;tfm[c+7]:=newc mod 256 end end;{:29}{39:}procedure readtfmword;
begin if eof(tfmfile)then b0:=0 else read(tfmfile,b0);
if eof(tfmfile)then b1:=0 else read(tfmfile,b1);
if eof(tfmfile)then b2:=0 else read(tfmfile,b2);
if eof(tfmfile)then b3:=0 else read(tfmfile,b3);end;{:39}{49:}
function vfread(k:integer):integer;var b:byte;a:integer;
begin vfcount:=vfcount+k;if eof(vffile)then b:=0 else read(vffile,b);
a:=b;if k=4 then if b>=128 then a:=a-256;
while k>1 do begin if eof(vffile)then b:=0 else read(vffile,b);
a:=256*a+b;k:=k-1;end;vfread:=a;end;{:49}{51:}
function tfmwidth(c:integer):integer;var a:integer;k:indextype;
begin k:=4*(widthbase+widthindex(c));a:=tfm[k];if a>=128 then a:=a-256;
tfmwidth:=((256*a+tfm[k+1])*256+tfm[k+2])*256+tfm[k+3];end;{:51}{56:}
procedure outdigs(j:integer);begin repeat j:=j-1;
write(vplfile,HEX[1+dig[j]]);until j=0;end;
procedure printdigs(j:integer);begin repeat j:=j-1;
write(stderr,HEX[1+dig[j]]);until j=0;end;{:56}{57:}
procedure printnumber(c:integer;form:integer);var j:0..32;begin j:=0;
if(c<0)then begin writeln(stderr,
'Internal error: print_number (negative value)');c:=0;end;
if form=8 then write(stderr,'''')else if form=16 then write(stderr,'"')
else if form<>10 then begin writeln(stderr,
'Internal error: print_number (form)');form:=16;end;
while(c>0)or(j=0)do begin dig[j]:=c mod form;c:=c div form;j:=j+1;end;
printdigs(j);end;{:57}{60:}procedure outln;var l:0..5;
begin writeln(vplfile);for l:=1 to level do write(vplfile,'   ');end;
procedure left;begin level:=level+1;write(vplfile,'(');end;
procedure right;begin level:=level-1;write(vplfile,')');outln;end;{:60}
{61:}procedure outBCPL(k:indextype);var l:0..39;
begin write(vplfile,' ');l:=tfm[k];while l>0 do begin k:=k+1;l:=l-1;
write(vplfile,xchr[tfm[k]]);end;end;{:61}{62:}
procedure outnumber(c:integer;form:integer);var j:0..32;begin j:=0;
if(c<0)then begin writeln(stderr,
'Internal error: print_number (negative value)');c:=0;end;
if form=8 then write(vplfile,' O ')else if form=10 then write(vplfile,
' D ')else if form=16 then write(vplfile,' H ')else begin writeln(stderr
,'Internal error: print_number (form)');form:=16;
write(vplfile,' H ')end;while(c>0)or(j=0)do begin dig[j]:=c mod form;
c:=c div form;j:=j+1;end;outdigs(j);end;procedure outhex(k,l:indextype);
var a:0..2147483647;b:0..32;j:0..11;begin write(vplfile,' H ');a:=0;
b:=0;j:=0;while l>0 do{63:}begin l:=l-1;
if tfm[k+l]<>0 then begin while b>2 do begin dig[j]:=a mod 16;
a:=a div 16;b:=b-4;j:=j+1;end;case b of 0:a:=tfm[k+l];1:a:=a+2*tfm[k+l];
2:a:=a+4*tfm[k+l];3:a:=a+8*tfm[k+l];end;end;b:=b+8;end{:63};
while(a>0)or(j=0)do begin dig[j]:=a mod 16;a:=a div 16;j:=j+1;end;
outdigs(j);end;{:62}{64:}procedure outchar(c:integer);
begin if(fonttype>0)or(charcodeformat=charcodehex)then outnumber(c,16)
else if(charcodeformat=charcodeascii)and(c>32)and(c<=126)and(c<>40)and(c
<>41)then write(vplfile,' C ',ASCIIall[c-31])else outnumber(c,16);end;
{:64}{65:}procedure outface(k:indextype);var s:0..1;b:0..8;
begin if tfm[k]>=18 then outhex(k,1)else begin write(vplfile,' F ');
s:=tfm[k]mod 2;b:=tfm[k]div 2;putbyte(MBLstring[1+(b mod 3)],vplfile);
putbyte(RIstring[1+s],vplfile);putbyte(RCEstring[1+(b div 3)],vplfile);
end;end;{:65}{66:}procedure outfix(k:indextype);var a:0..4095;f:integer;
j:0..12;delta:integer;begin write(vplfile,' R ');
a:=(tfm[k]*16)+(tfm[k+1]div 16);
f:=((tfm[k+1]mod 16)*256+tfm[k+2])*256+tfm[k+3];if a>2047 then{69:}
begin write(vplfile,'-');a:=4096-a;if f>0 then begin f:=1048576-f;
a:=a-1;end;end{:69};{67:}begin j:=0;repeat dig[j]:=a mod 10;a:=a div 10;
j:=j+1;until a=0;outdigs(j);end{:67};{68:}begin write(vplfile,'.');
f:=10*f+5;delta:=10;
repeat if delta>1048576 then f:=f+524288-(delta div 2);
write(vplfile,f div 1048576:1);f:=10*(f mod 1048576);delta:=delta*10;
until f<=delta;end;{:68};end;{:66}{78:}
procedure checkBCPL(k,l:indextype);var j:indextype;c:integer;
begin if tfm[k]>=l then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ',
'String is too long; I''ve shortened it drastically.');end;tfm[k]:=1;
end;for j:=k+1 to k+tfm[k]do begin c:=tfm[j];
if(c=40)or(c=41)then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ',
'Parenthesis in string has been changed to slash.');end;tfm[j]:=47;
end else if(c<32)or(c>126)then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ',
'Nonstandard ASCII code has been blotted out.');end;tfm[j]:=63;
end else if(c>=97)and(c<=122)then tfm[j]:=c-32;end;end;{:78}{135:}
procedure hashinput;label 10;var cc:0..3;zz:chartype;y:chartype;
key:integer64;t64:integer64;t:integer;
begin if hashptr=hashsize then goto 10;{136:}k:=ligstep(i);
y:=lnextchar(k);t:=lopbyte(k);cc:=0;zz:=lremainder(k);
if t>=128 then zz:=y else begin case t of 0,6:;5,11:zz:=y;1,7:cc:=1;
2:cc:=2;3:cc:=3;end;end{:136};key:=int64cast(xmaxchar)*c+y+1;
h:=(hashmult*key)mod hashsize;
while hash[h]>0 do begin if hash[h]<=key then begin if hash[h]=key then
goto 10;t64:=hash[h];hash[h]:=key;key:=t64;t:=classvar[h];
classvar[h]:=cc;cc:=t;t:=ligz[h];ligz[h]:=zz;zz:=t;end;
if h>0 then h:=h-1 else h:=hashsize;end;hash[h]:=key;classvar[h]:=cc;
ligz[h]:=zz;hashptr:=hashptr+1;hashlist[hashptr]:=h;10:end;{:135}{137:}
ifdef('notdef')function ligf(h,x,y:indextype):indextype;begin end;
endif('notdef')function eval(x,y:indextype):indextype;var key:integer64;
begin key:=int64cast(xmaxchar)*x+y+1;h:=(hashmult*key)mod hashsize;
while hash[h]>key do if h>0 then h:=h-1 else h:=hashsize;
if hash[h]<key then eval:=y else eval:=ligf(h,x,y);end;{:137}{138:}
function ligf(h,x,y:indextype):indextype;begin case classvar[h]of 0:;
1:begin classvar[h]:=4;ligz[h]:=eval(ligz[h],y);classvar[h]:=0;end;
2:begin classvar[h]:=4;ligz[h]:=eval(x,ligz[h]);classvar[h]:=0;end;
3:begin classvar[h]:=4;ligz[h]:=eval(eval(x,ligz[h]),y);classvar[h]:=0;
end;4:begin xligcycle:=x;yligcycle:=y;ligz[h]:=xxmaxchar;classvar[h]:=0;
end;end;ligf:=ligz[h];end;{:138}{139:}
function stringbalance(k,l:integer):boolean;label 45,10;
var j,bal:integer;begin if l>0 then if vf[k]=32 then goto 45;bal:=0;
for j:=k to k+l-1 do begin if(vf[j]<32)or(vf[j]>=127)then goto 45;
if vf[j]=40 then bal:=bal+1 else if vf[j]=41 then if bal=0 then goto 45
else bal:=bal-1;end;if bal>0 then goto 45;stringbalance:=true;goto 10;
45:stringbalance:=false;10:end;{:139}{141:}
procedure outasfix(x:integer);var k:1..3;
begin if abs(x)>=16777216 then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ',
'Oversize dimension has been reset to zero.');end;x:=0;end;
if x>=0 then tfm[designsize]:=0 else begin tfm[designsize]:=255;
x:=x+16777216;end;
for k:=3 downto 1 do begin tfm[designsize+k]:=x mod 256;x:=x div 256;
end;outfix(designsize);end;{:141}{146:}function getbytes(k:integer;
issigned:boolean):integer;var a:integer;
begin if vfptr+k>vflimit then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','Packet ended prematurely');end;
k:=vflimit-vfptr;end;a:=vf[vfptr];
if(k=4)or issigned then if a>=128 then a:=a-256;vfptr:=vfptr+1;
while k>1 do begin a:=a*256+vf[vfptr];vfptr:=vfptr+1;k:=k-1;end;
getbytes:=a;end;{:146}{152:}function vfinput:boolean;
var vfptr:0..vfsize;k:integer;c:integer;begin{32:}read(vffile,tempbyte);
if tempbyte<>247 then begin writeln(stderr,
'The first byte isn''t `pre''!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;{33:}if eof(vffile)then begin writeln(stderr,
'The input file is only one byte long!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;read(vffile,tempbyte);
if tempbyte<>202 then begin writeln(stderr,
'Wrong OVF version number in second byte!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;if eof(vffile)then begin writeln(stderr,
'The input file is only two bytes long!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;read(vffile,tempbyte);vfcount:=11;vfptr:=0;
if vfptr+tempbyte>=vfsize then begin writeln(stderr,
'The file is bigger than I can handle!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;
for k:=vfptr to vfptr+tempbyte-1 do begin if eof(vffile)then begin
writeln(stderr,'The file ended prematurely!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;read(vffile,vf[k]);end;vfcount:=vfcount+tempbyte;
vfptr:=vfptr+tempbyte;
if verbose then begin for k:=0 to vfptr-1 do write(stderr,xchr[vf[k]]);
writeln(stderr,' ');end;regcount:=0;
for k:=0 to 7 do begin if eof(vffile)then begin writeln(stderr,
'The file ended prematurely!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;read(vffile,tempbyte);
if tempbyte=tfm[checksum+k]then regcount:=regcount+1;end;
realdsize:=(((tfm[designsize]*256+tfm[designsize+1])*256+tfm[designsize
+2])*256+tfm[designsize+3])/1048576;
if regcount<>8 then begin writeln(stderr,
'Check sum and/or design size mismatch.');
writeln(stderr,'Data from OFM file will be assumed correct.');end{:33};
{34:}for k:=0 to 1114111 do packetstart[k]:=vfsize;fontptr:=0;
packetfound:=false;fontstart[0]:=vfptr;vcptr:=0;fontchars[0]:=vcptr;
repeat if eof(vffile)then begin writeln(stderr,
'File ended without a postamble!');tempbyte:=248;
end else begin read(vffile,tempbyte);vfcount:=vfcount+1;
if tempbyte<>248 then if tempbyte>242 then{36:}
begin if packetfound or(tempbyte>=247)then begin writeln(stderr,
'Illegal byte ',tempbyte:1,' at beginning of character packet!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;fontnumber[fontptr]:=vfread(tempbyte-242);
if fontptr=maxfonts then begin writeln(stderr,
'I can''t handle that many fonts!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;if vfptr+14>=vfsize then begin writeln(stderr,
'The file is bigger than I can handle!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;
for k:=vfptr to vfptr+13 do begin if eof(vffile)then begin writeln(
stderr,'The file ended prematurely!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;read(vffile,vf[k]);end;vfcount:=vfcount+14;
vfptr:=vfptr+14;if vf[vfptr-10]>0 then begin writeln(stderr,
'Mapped font size is too big!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;a:=vf[vfptr-2];l:=vf[vfptr-1];
if vfptr+a+l>=vfsize then begin writeln(stderr,
'The file is bigger than I can handle!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;
for k:=vfptr to vfptr+a+l-1 do begin if eof(vffile)then begin writeln(
stderr,'The file ended prematurely!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;read(vffile,vf[k]);end;vfcount:=vfcount+a+l;
vfptr:=vfptr+a+l;if verbose then begin{37:}
write(stderr,'MAPFONT ',fontptr:1,': ');
for k:=fontstart[fontptr]+14 to vfptr-1 do write(stderr,xchr[vf[k]]);
k:=fontstart[fontptr]+5;write(stderr,' at ');
fprintreal(stderr,(((vf[k]*256+vf[k+1])*256+vf[k+2])/1048576)*realdsize,
2,2);writeln(stderr,'pt'){:37};end;{40:}{47:}{:47}{48:}
r:=vfptr-(fontstart[fontptr]+14);curname:=xmalloc(r+1);
for k:=(fontstart[fontptr]+14)to vfptr do begin curname[k-(fontstart[
fontptr]+14)]:=xchr[vf[k]];end;curname[r]:=0;{:48};
tfmfile:=kpseopenfile(curname,kpseofmformat);
if eof(tfmfile)then writeln(stderr,
'---not loaded, font metric file can''t be opened!')else begin fontbc:=0
;fontec:=1114112;{41:}readtfmword;
if(b0*256+b1)<>0 then begin fontofmlevel:=-1;fontlh:=b2*256+b3;
readtfmword;fontbc:=b0*256+b1;fontec:=b2*256+b3;
if fontec<fontbc then fontbc:=fontec+1;readtfmword;
for k:=1 to 3+fontlh do begin readtfmword;if k=4 then{43:}
if b0+b1+b2+b3>0 then if(b0<>vf[fontstart[fontptr]])or(b1<>vf[fontstart[
fontptr]+1])or(b2<>vf[fontstart[fontptr]+2])or(b3<>vf[fontstart[fontptr]
+3])then begin if verbose then writeln(stderr,
'Check sum in OVF file being replaced by font metric check sum');
vf[fontstart[fontptr]]:=b0;vf[fontstart[fontptr]+1]:=b1;
vf[fontstart[fontptr]+2]:=b2;vf[fontstart[fontptr]+3]:=b3;end{:43};
if k=5 then{44:}
if(b0<>vf[fontstart[fontptr]+8])or(b1<>vf[fontstart[fontptr]+9])or(b2<>
vf[fontstart[fontptr]+10])or(b3<>vf[fontstart[fontptr]+11])then begin
writeln(stderr,
'Design size in OVF file being replaced by font metric design size');
vf[fontstart[fontptr]+8]:=b0;vf[fontstart[fontptr]+9]:=b1;
vf[fontstart[fontptr]+10]:=b2;vf[fontstart[fontptr]+11]:=b3;end{:44};
end;end else begin fontofmlevel:=b2*256+b3;readtfmword;readtfmword;
fontlh:=((b0*256+b1)*256+b2)*256+b3;readtfmword;
fontbc:=((b0*256+b1)*256+b2)*256+b3;readtfmword;
fontec:=((b0*256+b1)*256+b2)*256+b3;
if fontec<fontbc then fontbc:=fontec+1;readtfmword;
for k:=1 to 8 do begin readtfmword;end;
if fontofmlevel=1 then begin readtfmword;
fontlh:=((b0*256+b1)*256+b2)*256+b3-29;readtfmword;readtfmword;
fontextrawords:=(((b0*256+b1)*256+b2)*256+b3)div 2;
for k:=1 to 12 do begin readtfmword;end;end;
for k:=1 to fontlh do begin readtfmword;if k=1 then{43:}
if b0+b1+b2+b3>0 then if(b0<>vf[fontstart[fontptr]])or(b1<>vf[fontstart[
fontptr]+1])or(b2<>vf[fontstart[fontptr]+2])or(b3<>vf[fontstart[fontptr]
+3])then begin if verbose then writeln(stderr,
'Check sum in OVF file being replaced by font metric check sum');
vf[fontstart[fontptr]]:=b0;vf[fontstart[fontptr]+1]:=b1;
vf[fontstart[fontptr]+2]:=b2;vf[fontstart[fontptr]+3]:=b3;end{:43};
if k=2 then{44:}
if(b0<>vf[fontstart[fontptr]+8])or(b1<>vf[fontstart[fontptr]+9])or(b2<>
vf[fontstart[fontptr]+10])or(b3<>vf[fontstart[fontptr]+11])then begin
writeln(stderr,
'Design size in OVF file being replaced by font metric design size');
vf[fontstart[fontptr]+8]:=b0;vf[fontstart[fontptr]+9]:=b1;
vf[fontstart[fontptr]+10]:=b2;vf[fontstart[fontptr]+11]:=b3;end{:44};
end;end{:41};
if fontbc<=fontec then if fontec>1114111 then writeln(stderr,
'---not loaded, bad font metric file!')else{42:}
case fontofmlevel of-1:begin for k:=fontbc to fontec do begin
readtfmword;if b0>0 then begin vc[vcptr]:=k;vcptr:=vcptr+1;
if vcptr=vcsize then begin writeln(stderr,'I''m out of OVF memory!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;end;end;end;
0:begin for k:=fontbc to fontec do begin readtfmword;
if(b0*256+b1)>0 then begin vc[vcptr]:=k;vcptr:=vcptr+1;
if vcptr=vcsize then begin writeln(stderr,'I''m out of OVF memory!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;end;readtfmword;end;end;1:begin k:=fontbc;
while k<=fontec do begin readtfmword;fontwd:=b0*256+b1;readtfmword;
readtfmword;fontkprime:=k+(b0*256+b1);
if fontwd>0 then for fontj:=k to fontkprime do begin vc[vcptr]:=fontj;
vcptr:=vcptr+1;
if vcptr=vcsize then begin writeln(stderr,'I''m out of OVF memory!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;end;k:=fontkprime+1;
for fontj:=1 to fontextrawords do readtfmword;end end;end;{:42};
if eof(tfmfile)then writeln(stderr,
'---trouble is brewing, font metric file ended too soon!');end;
vcptr:=vcptr+1{:40};fontptr:=fontptr+1;fontstart[fontptr]:=vfptr;
fontchars[fontptr]:=vcptr;end{:36}else{50:}
begin if tempbyte=242 then begin pl:=vfread(4);c:=vfread(4);
regcount:=vfread(4);end else begin pl:=tempbyte;c:=vfread(1);
regcount:=vfread(3);end;
if((c<bc)or(c>ec)or(widthindex(c)=0))then begin writeln(stderr,
'Character ',c:1,' does not exist!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;if packetstart[c]<vfsize then writeln(stderr,
'Discarding earlier packet for character ',c:1);
if regcount<>tfmwidth(c)then writeln(stderr,
'Incorrect OFM width for character ',c:1,' in OVF file');
if pl<0 then begin writeln(stderr,'Negative packet length!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;packetstart[c]:=vfptr;
if vfptr+pl>=vfsize then begin writeln(stderr,
'The file is bigger than I can handle!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;
for k:=vfptr to vfptr+pl-1 do begin if eof(vffile)then begin writeln(
stderr,'The file ended prematurely!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OVF?')
;uexit(1);end;read(vffile,vf[k]);end;vfcount:=vfcount+pl;
vfptr:=vfptr+pl;packetend[c]:=vfptr-1;packetfound:=true;end{:50};end;
until tempbyte=248{:34};{35:}
while(tempbyte=248)and not eof(vffile)do begin read(vffile,tempbyte);
vfcount:=vfcount+1;end;
if not eof(vffile)then begin writeln(stderr,
'There''s some extra junk at the end of the OVF file.');
writeln(stderr,'I''ll proceed as if it weren''t there.');end;
if vfcount mod 4<>0 then writeln(stderr,
'VF data not a multiple of 4 bytes'){:35}{:32};vfinput:=true;end;
function organize:boolean;var tfmptr:indextype;begin{25:}
read(tfmfile,tfm[0]);if tfm[0]>127 then begin writeln(stderr,
'The first byte of the input file exceeds 127!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if eof(tfmfile)then begin writeln(stderr,
'The input file is only one byte long!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;read(tfmfile,tfm[1]);lf:=tfm[0]*256+tfm[1];
if lf=0 then begin for i:=2 to 7 do begin if eof(tfmfile)then begin
writeln(stderr,'The input file is too short to designate its length!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;read(tfmfile,tfm[i]);end;ofmon:=true;
ofmlevel:=tfm[2]*256+tfm[3];
if ofmlevel>1 then begin writeln(stderr,'OFMLEVEL ',ofmlevel:1,
' not supported, must be 0 or 1!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if tfm[4]>127 then begin writeln(stderr,
'The fifth byte of the input file exceeds 127!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;lf:=tfm[4]*16777216+tfm[5]*65536+tfm[6]*256+tfm[7];
end else begin ofmon:=false;end;case ofmlevel of-1:begin startptr:=2;
checksum:=24;end;0:begin startptr:=8;checksum:=56;end;
1:begin startptr:=8;checksum:=116;end;end;designsize:=checksum+4;
scheme:=designsize+4;family:=scheme+40;randomword:=family+20;
if lf=0 then begin writeln(stderr,
'The file claims to have length zero, but that''s impossible!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;tfmfilearray:=xreallocarray(tfmfilearray,byte,4*lf+1000);
for tfmptr:=startptr to 4*lf-1 do begin if eof(tfmfile)then begin
writeln(stderr,'The file has fewer bytes than it claims!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;read(tfmfile,tfm[tfmptr]);end;
if not eof(tfmfile)then begin writeln(stderr,
'There''s some extra junk at the end of the OFM file,');
writeln(stderr,'but I''ll proceed as if it weren''t there.');end{:25};
{26:}begin if not ofmon then begin tfmptr:=2;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;lh:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;bc:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;ec:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;nw:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;nh:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;nd:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;ni:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;nl:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;nk:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;ne:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;np:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
ncw:=(ec-bc+1);nlw:=nl;neew:=ne;headerlength:=6;topchar:=255;
topwidth:=255;topheight:=15;topdepth:=15;topitalic:=63;
end else begin tfmptr:=8;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
lh:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
bc:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
ec:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nw:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nh:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nd:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
ni:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nl:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nk:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
ne:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
np:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
fontdir:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;nlw:=2*nl;neew:=2*ne;topchar:=1114111;
topwidth:=1114111;topheight:=255;topdepth:=255;topitalic:=255;
if ofmlevel=0 then begin headerlength:=14;ncw:=2*(ec-bc+1);
end else begin headerlength:=29;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nco:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
ncw:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
npc:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nki:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwi:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nkf:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwf:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nkm:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwm:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nkr:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwr:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nkg:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwg:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nkp:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
nwp:=tfm[tfmptr]*16777216+tfm[tfmptr+1]*65536+tfm[tfmptr+2]*256+tfm[
tfmptr+3];tfmptr:=tfmptr+4;end;end;end;
if lf<>(headerlength+lh+ncw+nw+nh+nd+ni+nlw+nk+neew+np+nki+nwi+nkf+nwf+
nkm+nwm+nkr+nwr+nkg+nwg+nkp+nwp)then begin writeln(stderr,
'Subfile sizes don''t add up to the stated total!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
if lh<2 then begin writeln(stderr,'The header length is only ',lh:1,'!')
;
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if nl>ligsize then begin writeln(stderr,
'The lig/kern program is longer than I can handle!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if(bc>ec+1)or(ec>topchar)then begin writeln(stderr,
'The character code range ',bc:1,'..',ec:1,' is illegal!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if ec>maxchar then begin writeln(stderr,'Character ',ec:1,
'is too large.  Ask a wizard to enlarge me.');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;if(nw=0)or(nh=0)or(nd=0)or(ni=0)then begin writeln(stderr,
'Incomplete subfiles for character dimensions!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;
if ne>(topchar+1)then begin writeln(stderr,'There are ',ne:1,
' extensible recipes!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;end{:26};{28:}begin ivaluesstart:=headerlength+lh;
fvaluesstart:=ivaluesstart+nki;mvaluesstart:=fvaluesstart+nkf;
rulesstart:=mvaluesstart+nkm;gluesstart:=rulesstart+nkr;
penaltiesstart:=gluesstart+nkg;ivaluesbase:=penaltiesstart+nkp;
fvaluesbase:=ivaluesbase+nwi;mvaluesbase:=fvaluesbase+nwf;
rulesbase:=mvaluesbase+nwm;gluesbase:=rulesbase+nwr;
penaltiesbase:=gluesbase+nwg;charbase:=penaltiesbase+nwp;
bytesperentry:=(12+2*npc)div 4*4;
if not ofmon then begin for i:=bc to ec do begin charstart[i]:=4*
charbase+4*(i-bc);end;
end else if ofmlevel=0 then begin for i:=bc to ec do begin charstart[i]
:=4*charbase+8*(i-bc);end;end else begin charptr:=4*charbase;i:=bc;
while i<=ec do begin copies:=1+256*tfm[charptr+8]+tfm[charptr+9];
for j:=1 to copies do begin charstart[i]:=charptr;i:=i+1;end;
charptr:=charptr+bytesperentry;end;
if charptr<>(4*(charbase+ncw))then begin writeln(stderr,
'Length of char info table does not correspond to specification');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a OFM?')
;uexit(1);end;end;widthbase:=charbase+ncw;heightbase:=widthbase+nw;
depthbase:=heightbase+nh;italicbase:=depthbase+nd;
ligkernbase:=italicbase+ni;kernbase:=ligkernbase+nlw;
extenbase:=kernbase+nk;parambase:=extenbase+neew-1;end{:28};
organize:=vfinput;end;{:152}{153:}procedure dosimplethings;
var i:0..32767;f:0..vfsize;k:integer;begin{140:}
if stringbalance(0,fontstart[0])then begin left;
write(vplfile,'VTITLE ');
for k:=0 to fontstart[0]-1 do write(vplfile,xchr[vf[k]]);right;
end else begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad OVF file: ','Title is not a balanced ASCII string');
end{:140};{74:}
begin case ofmlevel of 0:begin write(vplfile,'(OFMLEVEL H 0)');outln;
end;1:begin write(vplfile,'(OFMLEVEL H 1)');outln;end;end;
if ofmon then begin left;
if fontdir<=7 then write(vplfile,'FONTDIR')else write(vplfile,'NFONTDIR'
);case fontdir mod 8 of 0:write(vplfile,' TL');1:write(vplfile,' LT');
2:write(vplfile,' TR');3:write(vplfile,' LB');4:write(vplfile,' BL');
5:write(vplfile,' RT');6:write(vplfile,' BR');7:write(vplfile,' RB');
end;right end;fonttype:=0;if lh>=12 then begin{79:}
begin checkBCPL(scheme,40);
if(tfm[scheme]>=11)and(tfm[scheme+1]=84)and(tfm[scheme+2]=69)and(tfm[
scheme+3]=88)and(tfm[scheme+4]=32)and(tfm[scheme+5]=77)and(tfm[scheme+6]
=65)and(tfm[scheme+7]=84)and(tfm[scheme+8]=72)and(tfm[scheme+9]=32)then
begin if(tfm[scheme+10]=83)and(tfm[scheme+11]=89)then fonttype:=1 else
if(tfm[scheme+10]=69)and(tfm[scheme+11]=88)then fonttype:=2;end;end{:79}
;if lh>=17 then begin{81:}left;write(vplfile,'FAMILY');
checkBCPL(family,20);outBCPL(family);right{:81};if lh>=18 then{82:}
begin left;write(vplfile,'FACE');outface(randomword+3);right;
for i:=18 to lh-1 do begin left;write(vplfile,'HEADER D ',i:1);
outhex(checksum+4*i,4);right;end;end{:82};end;{80:}left;
write(vplfile,'CODINGSCHEME');outBCPL(scheme);right{:80};end;{77:}left;
write(vplfile,'DESIGNSIZE');
if tfm[designsize]>127 then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Design size ','negative','!');end;
writeln(stderr,'I''ve set it to 10 points.');write(vplfile,' D 10');
end else if(tfm[designsize]=0)and(tfm[designsize+1]<16)then begin begin
perfect:=false;if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Design size ','too small','!');end;
writeln(stderr,'I''ve set it to 10 points.');write(vplfile,' D 10');
end else outfix(designsize);right;
write(vplfile,'(COMMENT DESIGNSIZE IS IN POINTS)');outln;
write(vplfile,'(COMMENT OTHER SIZES ARE MULTIPLES OF DESIGNSIZE)');
outln{:77};{75:}left;write(vplfile,'CHECKSUM');outhex(checksum,4);
right{:75};{83:}if ofmon then begin left;
write(vplfile,'SEVENBITSAFEFLAG FALSE');right;
end else if(lh>17)and(tfm[randomword]>127)then begin left;
write(vplfile,'SEVENBITSAFEFLAG TRUE');right;end{:83};end{:74};{84:}
if np>0 then begin left;write(vplfile,'FONTDIMEN');outln;
for i:=1 to np do{86:}begin left;
if i=1 then write(vplfile,'SLANT')else begin if(tfm[4*(parambase+i)]>0)
and(tfm[4*(parambase+i)]<255)then begin tfm[4*(parambase+i)]:=0;
tfm[(4*(parambase+i))+1]:=0;tfm[(4*(parambase+i))+2]:=0;
tfm[(4*(parambase+i))+3]:=0;begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Parameter',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;{87:}
if i<=7 then case i of 2:write(vplfile,'SPACE');
3:write(vplfile,'STRETCH');4:write(vplfile,'SHRINK');
5:write(vplfile,'XHEIGHT');6:write(vplfile,'QUAD');
7:write(vplfile,'EXTRASPACE')end else if(i<=22)and(fonttype=1)then case
i of 8:write(vplfile,'NUM1');9:write(vplfile,'NUM2');
10:write(vplfile,'NUM3');11:write(vplfile,'DENOM1');
12:write(vplfile,'DENOM2');13:write(vplfile,'SUP1');
14:write(vplfile,'SUP2');15:write(vplfile,'SUP3');
16:write(vplfile,'SUB1');17:write(vplfile,'SUB2');
18:write(vplfile,'SUPDROP');19:write(vplfile,'SUBDROP');
20:write(vplfile,'DELIM1');21:write(vplfile,'DELIM2');
22:write(vplfile,'AXISHEIGHT')end else if(i<=13)and(fonttype=2)then if i
=8 then write(vplfile,'DEFAULTRULETHICKNESS')else write(vplfile,
'BIGOPSPACING',i-8:1)else write(vplfile,'PARAMETER D ',i:1){:87};end;
outfix(4*(parambase+i));right;end{:86};right;end;{85:}
if(fonttype=1)and(np<>22)then writeln(stderr,
'Unusual number of fontdimen parameters for a math symbols font (',np:1,
' not 22).')else if(fonttype=2)and(np<>13)then writeln(stderr,
'Unusual number of fontdimen parameters for an extension font (',np:1,
' not 13).'){:85};{:84};{89:}
if nki>0 then begin startcounter:=ivaluesstart*4;
basecounter:=ivaluesbase*4;for i:=0 to nki-1 do{90:}begin left;
write(vplfile,'FONTIVALUE');outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(vplfile,'IVALUE');
outnumber(j,16);outln;value:=256*tfm[basecounter+2]+tfm[basecounter+3];
left;write(vplfile,'IVALUEVAL');outnumber(value,16);right;right;
basecounter:=basecounter+4;end;right;startcounter:=startcounter+4;end;
{:90};end;{:89};{91:}if nkf>0 then begin startcounter:=fvaluesstart*4;
basecounter:=fvaluesbase*4;for i:=0 to nkf-1 do{92:}begin left;
write(vplfile,'FONTFVALUE');outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(vplfile,'FVALUE');
outnumber(j,16);outln;left;write(vplfile,'FVALUEVAL');
outfix(basecounter);right;right;basecounter:=basecounter+4;end;right;
startcounter:=startcounter+4;end;{:92};end;{:91};{93:}
if nkm>0 then begin startcounter:=mvaluesstart*4;
basecounter:=mvaluesbase*4;for i:=0 to nkm-1 do{94:}begin left;
write(vplfile,'FONTMVALUE');outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(vplfile,'MVALUE');
outnumber(j,16);outln;left;write(vplfile,'MVALUEVAL');
outfix(basecounter);right;right;basecounter:=basecounter+4;end;right;
startcounter:=startcounter+4;end;{:94};end;{:93};{95:}
if nkr>0 then begin startcounter:=rulesstart*4;basecounter:=rulesbase*4;
for i:=0 to nkr-1 do{96:}begin left;write(vplfile,'FONTRULE');
outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(vplfile,'RULE');
outnumber(j,16);outln;left;write(vplfile,'RULEWD');outfix(basecounter);
right;left;write(vplfile,'RULEHT');outfix(basecounter+4);right;left;
write(vplfile,'RULEDP');outfix(basecounter+8);right;right;
basecounter:=basecounter+12;end;right;startcounter:=startcounter+4;end;
{:96};end{:95};{97:}if nkg>0 then begin startcounter:=gluesstart*4;
basecounter:=gluesbase*4;for i:=0 to nkg-1 do{99:}begin left;
write(vplfile,'FONTGLUE');outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(vplfile,'GLUE');
outnumber(j,16);outln;gluesubtype:=tfm[basecounter]div 16;
glueargumentkind:=tfm[basecounter]mod 16;
gluestretchorder:=tfm[basecounter+1]div 16;
glueshrinkorder:=tfm[basecounter+1]mod 16;
glueargument:=tfm[basecounter+2]*256+tfm[basecounter+3];left;
write(vplfile,'GLUETYPE');case gluesubtype of 0:write(vplfile,' H 0');
1:write(vplfile,' H 1');2:write(vplfile,' H 2');3:write(vplfile,' H 3');
end;right;case glueargumentkind of 1:begin left;
write(vplfile,'GLUERULE');outnumber(glueargument,16);right;end;
2:begin left;write(vplfile,'GLUECHAR');outnumber(glueargument,16);right;
end;end;left;write(vplfile,'GLUESTRETCHORDER');
case gluestretchorder of 0:write(vplfile,' H 0');
1:write(vplfile,' H 1');2:write(vplfile,' H 2');3:write(vplfile,' H 3');
4:write(vplfile,' H 4');end;right;left;write(vplfile,'GLUESHRINKORDER');
case glueshrinkorder of 0:write(vplfile,' H 0');1:write(vplfile,' H 1');
2:write(vplfile,' H 2');3:write(vplfile,' H 3');4:write(vplfile,' H 4');
end;right;left;write(vplfile,'GLUEWD');outfix(basecounter+4);right;left;
write(vplfile,'GLUESTRETCH');outfix(basecounter+8);right;left;
write(vplfile,'GLUESHRINK');outfix(basecounter+12);right;right;
basecounter:=basecounter+16;end;right;startcounter:=startcounter+4;end;
{:99};end;{:97};{100:}
if nkp>0 then begin startcounter:=penaltiesstart*4;
basecounter:=penaltiesbase*4;for i:=0 to nkp-1 do{101:}begin left;
write(vplfile,'FONTPENALTY');outnumber(i,16);outln;
numberentries:=256*tfm[startcounter+2]+tfm[startcounter+3];
for j:=0 to numberentries-1 do begin left;write(vplfile,'PENALTY');
outnumber(j,16);outln;value:=256*tfm[basecounter+2]+tfm[basecounter+3];
left;write(vplfile,'PENALTYVAL');outnumber(value,16);right;right;
basecounter:=basecounter+4;end;right;startcounter:=startcounter+4;end;
{:101};end;{:100};{142:}for f:=0 to fontptr-1 do begin left;
write(vplfile,'MAPFONT D ',f:1);outln;{143:}a:=vf[fontstart[f]+12];
l:=vf[fontstart[f]+13];
if a>0 then if not stringbalance(fontstart[f]+14,a)then begin perfect:=
false;if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','Improper font area will be ignored');
end else begin left;write(vplfile,'FONTAREA ');
for k:=fontstart[f]+14 to fontstart[f]+a+13 do write(vplfile,xchr[vf[k]]
);right;end;
if(l=0)or not stringbalance(fontstart[f]+14+a,l)then begin perfect:=
false;if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','Improper font name will be ignored');
end else begin left;write(vplfile,'FONTNAME ');
for k:=fontstart[f]+14+a to fontstart[f]+a+l+13 do write(vplfile,xchr[vf
[k]]);right;end{:143};for k:=0 to 11 do tfm[k]:=vf[fontstart[f]+k];
if tfm[0]+tfm[1]+tfm[2]+tfm[3]>0 then begin left;
write(vplfile,'FONTCHECKSUM');outhex(0,4);right;end;left;
write(vplfile,'FONTAT');outfix(4);right;left;write(vplfile,'FONTDSIZE');
outfix(8);right;right;end{:142};{102:}
if(tfm[4*widthbase]>0)or(tfm[4*widthbase+1]>0)or(tfm[4*widthbase+2]>0)or
(tfm[4*widthbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','width[0] should be zero.');end;
if(tfm[4*heightbase]>0)or(tfm[4*heightbase+1]>0)or(tfm[4*heightbase+2]>0
)or(tfm[4*heightbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','height[0] should be zero.');end;
if(tfm[4*depthbase]>0)or(tfm[4*depthbase+1]>0)or(tfm[4*depthbase+2]>0)or
(tfm[4*depthbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','depth[0] should be zero.');end;
if(tfm[4*italicbase]>0)or(tfm[4*italicbase+1]>0)or(tfm[4*italicbase+2]>0
)or(tfm[4*italicbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','italic[0] should be zero.');end;
for i:=0 to nw-1 do if(tfm[4*(widthbase+i)]>0)and(tfm[4*(widthbase+i)]<
255)then begin tfm[4*(widthbase+i)]:=0;tfm[(4*(widthbase+i))+1]:=0;
tfm[(4*(widthbase+i))+2]:=0;tfm[(4*(widthbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad OFM file: ','Width',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
for i:=0 to nh-1 do if(tfm[4*(heightbase+i)]>0)and(tfm[4*(heightbase+i)]
<255)then begin tfm[4*(heightbase+i)]:=0;tfm[(4*(heightbase+i))+1]:=0;
tfm[(4*(heightbase+i))+2]:=0;tfm[(4*(heightbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad OFM file: ','Height',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
for i:=0 to nd-1 do if(tfm[4*(depthbase+i)]>0)and(tfm[4*(depthbase+i)]<
255)then begin tfm[4*(depthbase+i)]:=0;tfm[(4*(depthbase+i))+1]:=0;
tfm[(4*(depthbase+i))+2]:=0;tfm[(4*(depthbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad OFM file: ','Depth',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
for i:=0 to ni-1 do if(tfm[4*(italicbase+i)]>0)and(tfm[4*(italicbase+i)]
<255)then begin tfm[4*(italicbase+i)]:=0;tfm[(4*(italicbase+i))+1]:=0;
tfm[(4*(italicbase+i))+2]:=0;tfm[(4*(italicbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad OFM file: ','Italic correction',' ',i:1,
' is too big;');end;writeln(stderr,'I have set it to zero.');end;
if nk>0 then for i:=0 to nk-1 do if(tfm[4*(kernbase+i)]>0)and(tfm[4*(
kernbase+i)]<255)then begin tfm[4*(kernbase+i)]:=0;
tfm[(4*(kernbase+i))+1]:=0;tfm[(4*(kernbase+i))+2]:=0;
tfm[(4*(kernbase+i))+3]:=0;begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Kern',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;{:102};end;{:153}{154:}
function domap(c:integer):boolean;var k:integer;f:0..vfsize;begin{145:}
if packetstart[c]=vfsize then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','Missing packet for character ',c:1);
end else begin left;write(vplfile,'MAP');outln;top:=0;wstack[0]:=0;
xstack[0]:=0;ystack[0]:=0;zstack[0]:=0;vfptr:=packetstart[c];
vflimit:=packetend[c]+1;f:=0;while vfptr<vflimit do begin o:=vf[vfptr];
vfptr:=vfptr+1;if(o<=131)or((o>=133)and(o<=136))then{150:}
begin if o>=128 then if o>=133 then c:=getbytes(o-132,false)else c:=
getbytes(o-127,false)else c:=o;
if(c<0)or(c>1114111)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','Character ',c:1,
' is out of range and will be ignored');
end else if f=fontptr then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','Character ',c:1,
' in undeclared font will be ignored');
end else begin vc[fontchars[f+1]-1]:=c;k:=fontchars[f];
while vc[k]<>c do k:=k+1;
if k=fontchars[f+1]-1 then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','Character ',c:1,' in font ',f:1,
' will be ignored');
end else begin if o>=133 then write(vplfile,'(PUSH)');left;
write(vplfile,'SETCHAR');outchar(c);
if o>=133 then write(vplfile,')(POP');right;end;end;end{:150}
else case o of{147:}138:;
141:begin if top=maxstack then begin writeln(stderr,'Stack overflow!');
uexit(1);end;top:=top+1;wstack[top]:=wstack[top-1];
xstack[top]:=xstack[top-1];ystack[top]:=ystack[top-1];
zstack[top]:=zstack[top-1];write(vplfile,'(PUSH)');outln;end;
142:if top=0 then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','More pops than pushes!');
end else begin top:=top-1;write(vplfile,'(POP)');outln;end;
132,137:begin if o=137 then write(vplfile,'(PUSH)');left;
write(vplfile,'SETRULE');outasfix(getbytes(4,true));
outasfix(getbytes(4,true));if o=137 then write(vplfile,')(POP');right;
end;{:147}{148:}143,144,145,146:begin write(vplfile,'(MOVERIGHT');
outasfix(getbytes(o-142,true));write(vplfile,')');outln;end;
147,148,149,150,151:begin if o<>147 then wstack[top]:=getbytes(o-147,
true);write(vplfile,'(MOVERIGHT');outasfix(wstack[top]);
write(vplfile,')');outln;end;
152,153,154,155,156:begin if o<>152 then xstack[top]:=getbytes(o-152,
true);write(vplfile,'(MOVERIGHT');outasfix(xstack[top]);
write(vplfile,')');outln;end;
157,158,159,160:begin write(vplfile,'(MOVEDOWN');
outasfix(getbytes(o-156,true));write(vplfile,')');outln;end;
161,162,163,164,165:begin if o<>161 then ystack[top]:=getbytes(o-161,
true);write(vplfile,'(MOVEDOWN');outasfix(ystack[top]);
write(vplfile,')');outln;end;
166,167,168,169,170:begin if o<>166 then zstack[top]:=getbytes(o-166,
true);write(vplfile,'(MOVEDOWN');outasfix(zstack[top]);
write(vplfile,')');outln;end;{:148}{149:}
171,172,173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,
189,190,191,192,193,194,195,196,197,198,199,200,201,202,203,204,205,206,
207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,223,224,
225,226,227,228,229,230,231,232,233,234,235,236,237,238:begin f:=0;
if o>=235 then fontnumber[fontptr]:=getbytes(o-234,false)else fontnumber
[fontptr]:=o-171;while fontnumber[f]<>fontnumber[fontptr]do f:=f+1;
if f=fontptr then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','Undeclared font selected');
end else begin write(vplfile,'(SELECTFONT D ',f:1,')');outln;end;end;
{:149}{151:}239,240,241,242:begin k:=getbytes(o-238,false);
if k<0 then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','String of negative length!');
end else begin left;if k+vfptr>vflimit then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ',
'Special command truncated to packet length');end;k:=vflimit-vfptr;end;
if(k>64)or not stringbalance(vfptr,k)then begin write(vplfile,
'SPECIALHEX ');
while k>0 do begin if k mod 32=0 then outln else if k mod 4=0 then write
(vplfile,' ');begin a:=vf[vfptr]div 16;
if a<10 then write(vplfile,a:1)else write(vplfile,xchr[a+55]);end;
begin a:=vf[vfptr]mod 16;
if a<10 then write(vplfile,a:1)else write(vplfile,xchr[a+55]);end;
vfptr:=vfptr+1;k:=k-1;end;end else begin write(vplfile,'SPECIAL ');
while k>0 do begin write(vplfile,xchr[vf[vfptr]]);vfptr:=vfptr+1;k:=k-1;
end;end;right;end;end;{:151}
139,140,243,244,245,246,247,248,249,250,251,252,253,254,255:begin
perfect:=false;if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','Illegal DVI code ',o:1,
' will be ignored');end;end;end;
if top>0 then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OVF file: ','More pushes than pops!');end;
repeat write(vplfile,'(POP)');top:=top-1;until top=0;end;right;end{:145}
;domap:=true;end;function docharacters:boolean;label 9999,10;
var c:integer;k:indextype;ai:0..ligsize;begin{120:}sortptr:=0;c:=bc;
while(c<=ec)do begin if widthindex(c)>0 then for cprime:=c to(c+
norepeats(c))do begin if verbose then begin if charsonline=8 then begin
writeln(stderr,' ');charsonline:=1;
end else begin if charsonline>0 then write(stderr,' ');
charsonline:=charsonline+1;end;printnumber(cprime,16);end;left;
write(vplfile,'CHARACTER');outchar(cprime);outln;
if ofmon then checkunused(c);{121:}
if widthindex(c)>=nw then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Width',' index for character ');printnumber(c,16);
writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(vplfile,'CHARWD');outfix(4*(widthbase+widthindex(c)));right;
end{:121};if heightindex(c)>0 then{122:}
if heightindex(c)>=nh then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Height',' index for character ');printnumber(c,16);
writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(vplfile,'CHARHT');outfix(4*(heightbase+heightindex(c)));right;
end{:122};if depthindex(c)>0 then{123:}
if depthindex(c)>=nd then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Depth',' index for character ');printnumber(c,16);
writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(vplfile,'CHARDP');outfix(4*(depthbase+depthindex(c)));right;
end{:123};if italicindex(c)>0 then{124:}
if italicindex(c)>=ni then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Italic correction',' index for character ');
printnumber(c,16);writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(vplfile,'CHARIC');outfix(4*(italicbase+italicindex(c)));right;
end{:124};case tag(c)of 0:;1:{125:}begin left;write(vplfile,'COMMENT');
outln;i:=rremainder(c);r:=ligstep(i);
if(lskipbyte(r)mod 256)>128 then i:=256*lopbyte(r)+lremainder(r);
repeat{116:}begin k:=ligstep(i);
if(lskipbyte(k)div 256)=1 then begin case lopbyte(k)of 17:begin left;
write(vplfile,'CPEN');outnumber(lnextchar(k),16);
outnumber(lremainder(k),16);right;end;18:begin left;
write(vplfile,'CGLUE');outnumber(lnextchar(k),16);
outnumber(lremainder(k),16);right;end;19:begin left;
write(vplfile,'CPENGLUE');outnumber(lnextchar(k),16);
outnumber(lremainder(k)div 256,16);outnumber(lremainder(k)mod 256,16);
right;end;20:begin left;write(vplfile,'CKRN');
outnumber(lnextchar(k),16);r:=lremainder(k);
if r>=nk then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Kern index too large.');end;
write(vplfile,' R 0.0');end else outfix(4*(kernbase+r));right;end;end;
end else if lskipbyte(k)>128 then begin if(256*lopbyte(k)+lremainder(k))
>=nl then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ',
'Ligature unconditional stop command address is too big.');end;
end else if lopbyte(k)>=128 then{118:}
begin if((lnextchar(k)<bc)or(lnextchar(k)>ec)or(widthindex(lnextchar(k))
=0))then if lnextchar(k)<>boundarychar then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Kern step for',' nonexistent character ')
;printnumber(lnextchar(k),16);writeln(stderr,'.');setlnextchar(k,0)end;
left;write(vplfile,'KRN');outchar(lnextchar(k));
r:=256*(lopbyte(k)-128)+lremainder(k);
if r>=nk then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Kern index too large.');end;
write(vplfile,' R 0.0');end else outfix(4*(kernbase+r));right;end{:118}
else{119:}
begin if((lnextchar(k)<bc)or(lnextchar(k)>ec)or(widthindex(lnextchar(k))
=0))then if lnextchar(k)<>boundarychar then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Ligature step for',
' nonexistent character ');printnumber(lnextchar(k),16);
writeln(stderr,'.');setlnextchar(k,0)end;
if((lremainder(k)<bc)or(lremainder(k)>ec)or(widthindex(lremainder(k))=0)
)then begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
write(stderr,'Bad OFM file: ','Ligature step produces the',
' nonexistent character ');printnumber(lremainder(k),16);
writeln(stderr,'.');setlremainder(k,0)end;left;r:=lopbyte(k);
if(r=4)or((r>7)and(r<>11))then begin writeln(stderr,
'Ligature step with nonstandard code changed to LIG');r:=0;
setlopbyte(k,0);end;if r mod 4>1 then write(vplfile,'/');
write(vplfile,'LIG');if odd(r)then write(vplfile,'/');
while r>3 do begin write(vplfile,'>');r:=r-4;end;outchar(lnextchar(k));
outchar(lremainder(k));right;end{:119};
if(lskipbyte(k)mod 256)>0 then if level=1 then{117:}
begin if(lskipbyte(k)mod 256)>=128 then write(vplfile,'(STOP)')else
begin count:=0;
for ai:=i+1 to(i+(lskipbyte(k)mod 256))do if activity[ai]=2 then count:=
count+1;write(vplfile,'(SKIP D ',count:1,')');end;outln;end{:117};
end{:116};
if(lskipbyte(k)mod 256)>=128 then i:=nl else i:=i+1+(lskipbyte(k)mod 256
);until i>=nl;right;end{:125};2:{126:}begin r:=rremainder(c);
if((r<bc)or(r>ec)or(widthindex(r)=0))then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Character list link to',
' nonexistent character ');printnumber(r,16);writeln(stderr,'.');end;
setnotag(c);end else begin while(r<c)and(tag(r)=2)do r:=rremainder(r);
if r=c then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Cycle in a character list!');end;
write(stderr,'Character ');printnumber(c,16);
writeln(stderr,' now ends the list.');setnotag(c);end else begin left;
write(vplfile,'NEXTLARGER');outchar(rremainder(c));right;end;end;
end{:126};3:{127:}if rremainder(c)>=ne then begin begin perfect:=false;
writeln(stderr,' ');write(stderr,'Extensible',' index for character ');
printnumber(c,16);writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end;setnotag(c);
end else begin left;write(vplfile,'VARCHAR');outln;{129:}
for d:=0 to 3 do begin if not ofmon then begin k:=exten(c)+d;
extenchar:=tfm[k];end else begin k:=exten(c)+2*d;
extenchar:=256*tfm[k]+tfm[k+1];end;
if(d=3)or(extenchar>0)then begin left;case d of 0:write(vplfile,'TOP');
1:write(vplfile,'MID');2:write(vplfile,'BOT');3:write(vplfile,'REP')end;
if((extenchar<bc)or(extenchar>ec)or(widthindex(extenchar)=0))then
outchar(c)else outchar(extenchar);right;end end{:129};right;end{:127};
end;for i:=0 to npc-1 do begin if charparam(c,i)<>0 then begin left;
if i<nki then begin write(vplfile,'CHARIVALUE');outnumber(i,16);
end else if i<(nki+nkf)then begin write(vplfile,'CHARFVALUE');
outnumber(i-nki,16);
end else if i<(nki+nkf+nkm)then begin write(vplfile,'CHARMVALUE');
outnumber(i-nki-nkf,16);
end else if i<(nki+nkf+nkm+nkr)then begin write(vplfile,'CHARRULE');
outnumber(i-nki-nkf-nkm,16);
end else if i<(nki+nkf+nkm+nkr+nkg)then begin write(vplfile,'CHARGLUE');
outnumber(i-nki-nkf-nkm-nkr,16);
end else if i<(nki+nkf+nkm+nkr+nkg+nkp)then begin write(vplfile,
'CHARPENALTY');outnumber(i-nki-nkf-nkm-nkr-nkg,16);end;
outnumber(charparam(c,i),16);right;end;end;
if not domap(cprime)then goto 9999;right;end;c:=c+1+norepeats(c);
end{:120};docharacters:=true;goto 10;9999:docharacters:=false;10:end;
{:154}{155:}begin initialize;if not organize then goto 9999;
dosimplethings;{106:}
if nl>0 then begin for ai:=0 to(nl-1)do activity[ai]:=0;{109:}
if lskipbyte(ligstep(0))=255 then begin left;
write(vplfile,'BOUNDARYCHAR');boundarychar:=lnextchar(ligstep(0));
outchar(boundarychar);right;activity[0]:=1;end;
if lskipbyte(ligstep(nl-1))=255 then begin r:=256*lopbyte(ligstep(nl-1))
+lremainder(ligstep(nl-1));if r>=nl then begin perfect:=false;
writeln(stderr,' ');write(stderr,
'Ligature/kern starting index for boundarychar is too large;');
writeln(stderr,'so I removed it.');end else begin labelptr:=1;
labeltable[1].cc:=xmaxchar;labeltable[1].rr:=r;bcharlabel:=r;
activity[r]:=2;end;activity[nl-1]:=1;end{:109};end;{107:}
for c:=bc to ec do if(tag(c)=1)or(ctag(c))then begin r:=rremainder(c);
if(lskipbyte(ligstep(r))div 256)=0 then begin if r<nl then begin if
lskipbyte(ligstep(r))>128 then begin r:=256*lopbyte(ligstep(r))+
lremainder(ligstep(r));
if r<nl then if activity[rremainder(c)]=0 then activity[rremainder(c)]:=
1;end;end;end;if r>=nl then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Ligature/kern starting index for character ');
printnumber(c,16);writeln(stderr,' is too large;');
writeln(stderr,'so I removed it.');setnotag(c);setnoctag(c);
end else{108:}begin sortptr:=labelptr;
while labeltable[sortptr].rr>r do begin labeltable[sortptr+1]:=
labeltable[sortptr];sortptr:=sortptr-1;end;
labeltable[sortptr+1].ischar:=not ctag(c);
if ctag(c)then labeltable[sortptr+1].cc:=charparam(c,0)else labeltable[
sortptr+1].cc:=c;labeltable[sortptr+1].rr:=r;labelptr:=labelptr+1;
activity[r]:=2;end{:108};end;labeltable[labelptr+1].rr:=ligsize;{:107};
if nl>0 then begin left;write(vplfile,'LIGTABLE');outln;{110:}
for ai:=0 to(nl-1)do if(lskipbyte(ligstep(ai))div 256)=1 then activity[
ai]:=2 else if activity[ai]=2 then begin r:=lskipbyte(ligstep(ai));
if r<128 then begin r:=r+ai+1;if r>=nl then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Ligature/kern step ',ai:1,
' skips too far;');end;writeln(stderr,'I made it stop.');
setlskipbyte(ligstep(ai),128);end else activity[r]:=2;end;end{:110};
{111:}sortptr:=1;
for acti:=0 to nl-1 do if activity[acti]<>1 then begin i:=acti;{115:}
if activity[i]=0 then begin if level=1 then begin left;
write(vplfile,'COMMENT THIS PART OF THE PROGRAM IS NEVER USED!');outln;
end end else if level=2 then right{:115};{114:}
while i=labeltable[sortptr].rr do begin if labeltable[sortptr].cc<>
xmaxchar and not labeltable[sortptr].ischar then begin if not
outputclabels[labeltable[sortptr].cc]then begin outputclabels[labeltable
[sortptr].cc]:=true;left;write(vplfile,'CLABEL');
outchar(labeltable[sortptr].cc);right;end end else begin left;
write(vplfile,'LABEL');
if labeltable[sortptr].cc=xmaxchar then write(vplfile,' BOUNDARYCHAR')
else outchar(labeltable[sortptr].cc);right;end;sortptr:=sortptr+1;
end{:114};{116:}begin k:=ligstep(i);
if(lskipbyte(k)div 256)=1 then begin case lopbyte(k)of 17:begin left;
write(vplfile,'CPEN');outnumber(lnextchar(k),16);
outnumber(lremainder(k),16);right;end;18:begin left;
write(vplfile,'CGLUE');outnumber(lnextchar(k),16);
outnumber(lremainder(k),16);right;end;19:begin left;
write(vplfile,'CPENGLUE');outnumber(lnextchar(k),16);
outnumber(lremainder(k)div 256,16);outnumber(lremainder(k)mod 256,16);
right;end;20:begin left;write(vplfile,'CKRN');
outnumber(lnextchar(k),16);r:=lremainder(k);
if r>=nk then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Kern index too large.');end;
write(vplfile,' R 0.0');end else outfix(4*(kernbase+r));right;end;end;
end else if lskipbyte(k)>128 then begin if(256*lopbyte(k)+lremainder(k))
>=nl then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ',
'Ligature unconditional stop command address is too big.');end;
end else if lopbyte(k)>=128 then{118:}
begin if((lnextchar(k)<bc)or(lnextchar(k)>ec)or(widthindex(lnextchar(k))
=0))then if lnextchar(k)<>boundarychar then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Kern step for',' nonexistent character ')
;printnumber(lnextchar(k),16);writeln(stderr,'.');setlnextchar(k,0)end;
left;write(vplfile,'KRN');outchar(lnextchar(k));
r:=256*(lopbyte(k)-128)+lremainder(k);
if r>=nk then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad OFM file: ','Kern index too large.');end;
write(vplfile,' R 0.0');end else outfix(4*(kernbase+r));right;end{:118}
else{119:}
begin if((lnextchar(k)<bc)or(lnextchar(k)>ec)or(widthindex(lnextchar(k))
=0))then if lnextchar(k)<>boundarychar then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Ligature step for',
' nonexistent character ');printnumber(lnextchar(k),16);
writeln(stderr,'.');setlnextchar(k,0)end;
if((lremainder(k)<bc)or(lremainder(k)>ec)or(widthindex(lremainder(k))=0)
)then begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
write(stderr,'Bad OFM file: ','Ligature step produces the',
' nonexistent character ');printnumber(lremainder(k),16);
writeln(stderr,'.');setlremainder(k,0)end;left;r:=lopbyte(k);
if(r=4)or((r>7)and(r<>11))then begin writeln(stderr,
'Ligature step with nonstandard code changed to LIG');r:=0;
setlopbyte(k,0);end;if r mod 4>1 then write(vplfile,'/');
write(vplfile,'LIG');if odd(r)then write(vplfile,'/');
while r>3 do begin write(vplfile,'>');r:=r-4;end;outchar(lnextchar(k));
outchar(lremainder(k));right;end{:119};
if(lskipbyte(k)mod 256)>0 then if level=1 then{117:}
begin if(lskipbyte(k)mod 256)>=128 then write(vplfile,'(STOP)')else
begin count:=0;
for ai:=i+1 to(i+(lskipbyte(k)mod 256))do if activity[ai]=2 then count:=
count+1;write(vplfile,'(SKIP D ',count:1,')');end;outln;end{:117};
end{:116};end;if level=2 then right{:111};right;{133:}hashptr:=0;
yligcycle:=xmaxchar;for hh:=0 to hashsize do hash[hh]:=0;
for c:=bc to ec do if tag(c)=1 then begin i:=rremainder(c);
if(lskipbyte(ligstep(i))mod 256)>128 then i:=256*lopbyte(ligstep(i))+
lremainder(ligstep(i));{134:}repeat hashinput;k:=lskipbyte(ligstep(i));
if k>=128 then i:=nl else i:=i+1+k;until i>=nl{:134};end;
if bcharlabel<nl then begin c:=xmaxchar;i:=bcharlabel;{134:}
repeat hashinput;k:=lskipbyte(ligstep(i));
if k>=128 then i:=nl else i:=i+1+k;until i>=nl{:134};end;
if hashptr=hashsize then begin writeln(stderr,
'Sorry, I haven''t room for so many ligature/kern pairs!');uexit(1);end;
for hh:=1 to hashptr do begin r:=hashlist[hh];
if classvar[r]>0 then r:=ligf(r,(hash[r]-1)div xmaxchar,(hash[r]-1)mod
xmaxchar);end;if yligcycle<xmaxchar then begin write(stderr,
'Infinite ligature loop starting with ');
if xligcycle=xmaxchar then write(stderr,'boundary')else printnumber(
xligcycle,16);write(stderr,' and ');printnumber(yligcycle,16);
writeln(stderr,'!');
write(vplfile,'(INFINITE LIGATURE LOOP MUST BE BROKEN!)');outln;
perfect:=false;;end{:133};end{:106};{130:}
if ne>0 then for c:=0 to ne-1 do for d:=0 to 3 do begin if not ofmon
then begin k:=4*(extenbase+c)+d;extenchar:=tfm[k];
end else begin k:=4*(extenbase+c)+2*d;extenchar:=256*tfm[k]+tfm[k+1];
end;
if(extenchar>0)or(d=3)then begin if((extenchar<bc)or(extenchar>ec)or(
widthindex(extenchar)=0))then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad OFM file: ','Extensible recipe involves the',
' nonexistent character ');printnumber(extenchar,16);
writeln(stderr,'.');end;
if d<3 then begin if not ofmon then begin tfm[k]:=0;
end else begin tfm[k]:=0;tfm[k+1]:=0;end;end;end;end;end{:130};
if not docharacters then goto 9999;if verbose then writeln(stderr,'.');
if level<>0 then writeln(stderr,'This program isn''t working!');
if not perfect then begin write(vplfile,
'(COMMENT THE OFM AND/OR OVF FILE WAS BAD, ');
write(vplfile,'SO THE DATA HAS BEEN CHANGED!)');writeln(vplfile);end;
9999:end.{:155}
