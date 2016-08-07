{2:}
 @define var tfm;
program TFtoPL(tfmfile,plfile,output);const{4:}ligsize=32510;
hashsize=32579;{:4}{108:}charcodeascii=0;charcodeoctal=1;
charcodedefault=2;{:108}type{18:}byte=0..255;indextype=integer;
{:18}{107:}charcodeformattype=charcodeascii..charcodedefault;
{:107}var{6:}tfmfile:packed file of 0..255;
{:6}{8:}lf,lh,bc,ec,nw,nh,nd,ni,nl,nk,ne,np:0..32767;
{:8}{16:}plfile:text;
{:16}{19:}#define tfm (tfmfilearray + 1001);
tfmfilearray:^byte;fileformat:1..3;nt:0..32767;ng:0..32767;
{:19}{22:}charbase,widthbase,heightbase,depthbase,italicbase,ligkernbase
,kernbase,extenbase,parambase:integer;typebase,gluebase:integer;
checksumvalue:integer;{:22}{25:}fonttype:0..2;
{:25}{27:}ASCII04,ASCII10,ASCII14:constcstring;
ASCIIall:packed array[0..256]of char;
MBLstring,RIstring,RCEstring:constcstring;
{:27}{29:}dig:array[0..11]of 0..9;{:29}{32:}level:0..5;
{:32}{45:}charsonline:0..8;perfect:boolean;{:45}{47:}i:0..32767;
c:0..256;d:0..3;k:indextype;r:0..65535;count:0..127;
{:47}{63:}labeltable:array[0..258]of record cc:0..256;rr:0..ligsize;end;
labelptr:0..257;sortptr:0..257;boundarychar:0..256;bcharlabel:0..32767;
{:63}{65:}activity:array[0..ligsize]of 0..2;ai,acti:0..ligsize;
{:65}{89:}hash:array[0..hashsize]of 0..66048;
classvar:array[0..hashsize]of 0..4;ligz:array[0..hashsize]of 0..257;
hashptr:0..hashsize;hashlist:array[0..hashsize]of 0..hashsize;
h,hh:0..hashsize;xligcycle,yligcycle:0..256;{:89}{104:}verbose:cinttype;
{:104}{109:}charcodeformat:charcodeformattype;
{:109}{114:}tfmname,plname:constcstring;{:114}{115:}thiscode:integer;
thistype:integer;typeindex:integer;typenum:integer;typecount:integer;
kanjiindex:integer;kanjitype:array[0..65535]of-1..255;
{:115}{118:}xchr:array[char]of byte;
{:118}{100:}procedure parsearguments;const noptions=6;
var longoptions:array[0..noptions]of getoptstruct;
getoptreturnval:integer;optionindex:cinttype;currentoption:0..noptions;
begin{105:}verbose:=false;{:105}{110:}charcodeformat:=charcodedefault;
{:110};{101:}currentoption:=0;longoptions[currentoption].name:='help';
longoptions[currentoption].hasarg:=0;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;currentoption:=currentoption+1;
{:101}{102:}longoptions[currentoption].name:='version';
longoptions[currentoption].hasarg:=0;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;currentoption:=currentoption+1;
{:102}{103:}longoptions[currentoption].name:='verbose';
longoptions[currentoption].hasarg:=0;
longoptions[currentoption].flag:=addressof(verbose);
longoptions[currentoption].val:=1;currentoption:=currentoption+1;
{:103}{106:}longoptions[currentoption].name:='charcode-format';
longoptions[currentoption].hasarg:=1;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;currentoption:=currentoption+1;
{:106}{111:}longoptions[currentoption].name:='sjis-terminal';
longoptions[currentoption].hasarg:=0;
longoptions[currentoption].flag:=addressof(sjisterminal);
longoptions[currentoption].val:=1;currentoption:=currentoption+1;
{:111}{112:}longoptions[currentoption].name:='kanji';
longoptions[currentoption].hasarg:=1;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;currentoption:=currentoption+1;
{:112}{113:}longoptions[currentoption].name:=0;
longoptions[currentoption].hasarg:=0;longoptions[currentoption].flag:=0;
longoptions[currentoption].val:=0;{:113};
repeat getoptreturnval:=getoptlongonly(argc,argv,'',longoptions,
addressof(optionindex));if getoptreturnval=-1 then begin;
end else if getoptreturnval=63 then begin usage('uptftopl');
end else if(strcmp(longoptions[optionindex].name,'help')=0)then begin
usagehelp(UPTFTOPLHELP,nil);
end else if(strcmp(longoptions[optionindex].name,'version')=0)then begin
printversionandexit('This is upTFtoPL, Version 3.3-p1.7-u1.20',nil,
'D.E. Knuth',nil);
end else if(strcmp(longoptions[optionindex].name,'charcode-format')=0)
then begin if strcmp(optarg,'ascii')=0 then charcodeformat:=
charcodeascii else if strcmp(optarg,'octal')=0 then charcodeformat:=
charcodeoctal else writeln(stderr,'Bad character code format ',
stringcast(optarg),'.');
end else if(strcmp(longoptions[optionindex].name,'kanji')=0)then begin
if(not setencstring(optarg,optarg))then writeln(stderr,
'Bad kanji encoding "',stringcast(optarg),'".');end;
until getoptreturnval=-1;
if(optind+1<>argc)and(optind+2<>argc)then begin writeln(stderr,
'uptftopl',': Need one or two file arguments.');usage('uptftopl');end;
tfmname:=cmdline(optind);end;{:100}procedure initialize;var k:integer;
begin kpsesetprogramname(argv[0],'uptftopl');
kpseinitprog('TFTOPL',0,nil,nil);tfmfilearray:=xmallocarray(byte,1006);
initkanji;parsearguments;
{7:}tfmfile:=kpseopenfile(tfmname,kpsetfmformat);
if verbose then begin write(stderr,
'This is upTFtoPL, Version 3.3-p1.7-u1.20');
writeln(stderr,versionstring);
writeln(stderr,'process kanji code is ',conststringcast(getencstring),
'.');end;{:7}{17:}if optind+1=argc then begin plfile:=stdout;
end else begin plname:=extendfilename(cmdline(optind+1),'pl');
rewrite(plfile,plname);end;
{:17}{28:}ASCII04:='  !"#$%&''()*+,-./0123456789:;<=>?';
ASCII10:=' @ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_';
ASCII14:=' `abcdefghijklmnopqrstuvwxyz{|}~ ';strcpy(ASCIIall,ASCII04);
strcat(ASCIIall,'@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_');
strcat(ASCIIall,'`abcdefghijklmnopqrstuvwxyz{|}~');MBLstring:=' MBL';
RIstring:=' RI ';RCEstring:=' RCE';{:28}{33:}level:=0;
{:33}{46:}charsonline:=0;perfect:=true;{:46}{64:}boundarychar:=256;
bcharlabel:=32767;labelptr:=0;labeltable[0].rr:=0;
{:64}{119:}for k:=0 to 31 do xchr[k]:='?';
for k:=32 to 255 do xchr[k]:=k;{:119}end;
{:2}{30:}procedure outdigs(j:integer);begin repeat j:=j-1;
write(plfile,dig[j]:1);until j=0;end;procedure printdigs(j:integer);
begin repeat j:=j-1;write(stderr,dig[j]:1);until j=0;end;
{:30}{31:}procedure printoctal(c:byte);var j:0..2;
begin write(stderr,'''');for j:=0 to 2 do begin dig[j]:=c mod 8;
c:=c div 8;end;printdigs(3);end;{:31}{34:}procedure outln;var l:0..5;
begin writeln(plfile);for l:=1 to level do write(plfile,'   ');end;
procedure left;begin level:=level+1;write(plfile,'(');end;
procedure right;begin level:=level-1;write(plfile,')');outln;end;
{:34}{35:}procedure outBCPL(k:indextype);var l:0..39;
begin write(plfile,' ');l:=tfm[k];while l>0 do begin k:=k+1;l:=l-1;
case tfm[k]div 32 of 1:write(plfile,ASCII04[1+(tfm[k]mod 32)]);
2:write(plfile,ASCII10[1+(tfm[k]mod 32)]);
3:write(plfile,ASCII14[1+(tfm[k]mod 32)]);end;end;end;
{:35}{36:}procedure outoctal(k,l:indextype);var a:0..1023;b:0..32;
j:0..11;begin write(plfile,' O ');a:=0;b:=0;j:=0;
while l>0 do{37:}begin l:=l-1;
if tfm[k+l]<>0 then begin while b>2 do begin dig[j]:=a mod 8;a:=a div 8;
b:=b-3;j:=j+1;end;case b of 0:a:=tfm[k+l];1:a:=a+2*tfm[k+l];
2:a:=a+4*tfm[k+l];end;end;b:=b+8;end{:37};
while(a>0)or(j=0)do begin dig[j]:=a mod 8;a:=a div 8;j:=j+1;end;
outdigs(j);end;{:36}{38:}procedure outchar(c:byte);
begin if(fonttype>0)or(charcodeformat=charcodeoctal)then begin tfm[0]:=c
;outoctal(0,1)end else if(charcodeformat=charcodeascii)and(c>32)and(c<=
126)and(c<>40)and(c<>41)then write(plfile,' C ',ASCIIall[c-31])else if(c
>=48)and(c<=57)then write(plfile,' C ',c-48:1)else if(c>=65)and(c<=90)
then write(plfile,' C ',ASCII10[c-63])else if(c>=97)and(c<=122)then
write(plfile,' C ',ASCII14[c-95])else begin tfm[0]:=c;outoctal(0,1);end;
end;{:38}{39:}procedure outface(k:indextype);var s:0..1;b:0..8;
begin if tfm[k]>=18 then outoctal(k,1)else begin write(plfile,' F ');
s:=tfm[k]mod 2;b:=tfm[k]div 2;putbyte(MBLstring[1+(b mod 3)],plfile);
putbyte(RIstring[1+s],plfile);putbyte(RCEstring[1+(b div 3)],plfile);
end;end;{:39}{40:}procedure outfix(k:indextype);var a:0..4095;f:integer;
j:0..12;delta:integer;begin write(plfile,' R ');
a:=(tfm[k]*16)+(tfm[k+1]div 16);
f:=((tfm[k+1]mod 16)*256+tfm[k+2])*256+tfm[k+3];
if a>2047 then{43:}begin write(plfile,'-');a:=4096-a;
if f>0 then begin f:=1048576-f;a:=a-1;end;end{:43};{41:}begin j:=0;
repeat dig[j]:=a mod 10;a:=a div 10;j:=j+1;until a=0;outdigs(j);
end{:41};{42:}begin write(plfile,'.');f:=10*f+5;delta:=10;
repeat if delta>1048576 then f:=f+524288-(delta div 2);
write(plfile,f div 1048576:1);f:=10*(f mod 1048576);delta:=delta*10;
until f<=delta;end;{:42};end;
{:40}{52:}procedure checkBCPL(k,l:indextype);var j:indextype;c:byte;
begin if tfm[k]>=l then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ',
'String is too long; I''ve shortened it drastically.');end;tfm[k]:=1;
end;for j:=k+1 to k+tfm[k]do begin c:=tfm[j];
if(c=40)or(c=41)then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ',
'Parenthesis in string has been changed to slash.');end;tfm[j]:=47;
end else if(c<32)or(c>126)then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ',
'Nonstandard ASCII code has been blotted out.');end;tfm[j]:=63;
end else if(c>=97)and(c<=122)then tfm[j]:=c-32;end;end;
{:52}{92:}procedure hashinput;label 30;var cc:0..3;zz:0..255;y:0..255;
key:integer;t:integer;begin if hashptr=hashsize then goto 30;
{93:}k:=4*(ligkernbase+(i));y:=tfm[k+1];t:=tfm[k+2];cc:=0;zz:=tfm[k+3];
if t>=128 then zz:=y else begin case t of 0,6:;5,11:zz:=y;1,7:cc:=1;
2:cc:=2;3:cc:=3;end;end{:93};key:=256*c+y+1;h:=(1009*key)mod hashsize;
while hash[h]>0 do begin if hash[h]<=key then begin if hash[h]=key then
goto 30;t:=hash[h];hash[h]:=key;key:=t;t:=classvar[h];classvar[h]:=cc;
cc:=t;t:=ligz[h];ligz[h]:=zz;zz:=t;end;
if h>0 then h:=h-1 else h:=hashsize;end;hash[h]:=key;classvar[h]:=cc;
ligz[h]:=zz;hashptr:=hashptr+1;hashlist[hashptr]:=h;30:end;
{:92}{94:}ifdef('notdef')function ffn(h,x,y:indextype):indextype;
begin end;endif('notdef')function eval(x,y:indextype):indextype;
var key:integer;begin key:=256*x+y+1;h:=(1009*key)mod hashsize;
while hash[h]>key do if h>0 then h:=h-1 else h:=hashsize;
if hash[h]<key then eval:=y else eval:=ffn(h,x,y);end;
{:94}{95:}function ffn(h,x,y:indextype):indextype;
begin case classvar[h]of 0:;1:begin classvar[h]:=4;
ligz[h]:=eval(ligz[h],y);classvar[h]:=0;end;2:begin classvar[h]:=4;
ligz[h]:=eval(x,ligz[h]);classvar[h]:=0;end;3:begin classvar[h]:=4;
ligz[h]:=eval(eval(x,ligz[h]),y);classvar[h]:=0;end;
4:begin xligcycle:=x;yligcycle:=y;ligz[h]:=257;classvar[h]:=0;end;end;
ffn:=ligz[h];end;{:95}{96:}function organize:boolean;label 9999,30;
var tfmptr,tmpptr:indextype;begin{20:}read(tfmfile,tfm[0]);
if tfm[0]>127 then begin writeln(stderr,
'The first byte of the input file exceeds 127!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;if eof(tfmfile)then begin writeln(stderr,
'The input file is only one byte long!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;read(tfmfile,tfm[1]);lf:=tfm[0]*256+tfm[1];
if lf=11 then begin fileformat:=2;
writeln(stderr,'Input file is in YOKO-kumi kanji tfm format.');
writeln(plfile,'(COMMENT THIS IS A KANJI FORMAT FILE)');
end else if lf=9 then begin fileformat:=3;
writeln(stderr,'Input file is in TATE-kumi kanji tfm format.');
writeln(plfile,'(COMMENT THIS IS A KANJI FORMAT FILE)');
writeln(plfile,'(DIRECTION TATE)');end else fileformat:=1;
if fileformat=1 then begin nt:=0;tmpptr:=2;
end else begin if eof(tfmfile)then begin writeln(stderr,
'The input file is only two bytes long!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;read(tfmfile,tfm[2]);
if eof(tfmfile)then begin writeln(stderr,
'The input file is only three bytes long!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;read(tfmfile,tfm[3]);nt:=tfm[2]*256+tfm[3];
if eof(tfmfile)then begin writeln(stderr,
'The input file is only four bytes long!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;read(tfmfile,tfm[4]);
if eof(tfmfile)then begin writeln(stderr,
'The input file is only five bytes long!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;read(tfmfile,tfm[5]);lf:=tfm[4]*256+tfm[5];tmpptr:=6;end;
if lf=0 then begin writeln(stderr,
'The file claims to have length zero, but that''s impossible!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;tfmfilearray:=xreallocarray(tfmfilearray,byte,4*lf+1000);
for tfmptr:=tmpptr to 4*lf-1 do begin if eof(tfmfile)then begin writeln(
stderr,'The file has fewer bytes than it claims!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;read(tfmfile,tfm[tfmptr]);end;
if not eof(tfmfile)then begin writeln(stderr,
'There''s some extra junk at the end of the TFM file,');
writeln(stderr,'but I''ll proceed as if it weren''t there.');end{:20};
{21:}begin if fileformat<>1 then begin tfmptr:=6;checksumvalue:=28;
end else begin tfmptr:=2;checksumvalue:=24;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;lh:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;bc:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;ec:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;nw:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;nh:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;nd:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;ni:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;nl:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;nk:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;ne:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
begin if tfm[tfmptr]>127 then begin writeln(stderr,
'One of the subfile sizes is negative!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;np:=tfm[tfmptr]*256+tfm[tfmptr+1];tfmptr:=tfmptr+2;end;
if lh<2 then begin writeln(stderr,'The header length is only ',lh:1,'!')
;
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;if nl>ligsize then begin writeln(stderr,
'The lig/kern program is longer than I can handle!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;
case fileformat of 1:begin if(bc>ec+1)or(ec>255)then begin writeln(
stderr,'The character code range ',bc:1,'..',ec:1,' is illegal!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;
if(nw=0)or(nh=0)or(nd=0)or(ni=0)then begin writeln(stderr,
'Incomplete subfiles for character dimensions!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;if ne>256 then begin writeln(stderr,'There are ',ne:1,
' extensible recipes!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;
if lf<>6+lh+(ec-bc+1)+nw+nh+nd+ni+nl+nk+ne+np then begin writeln(stderr,
'Subfile sizes don''t add up to the stated total!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;end;2,3:begin ng:=ne;
if(bc>ec+1)or(ec>255)or(bc<>0)then begin writeln(stderr,
'The character code range ',bc:1,'..',ec:1,' is illegal!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;
if(nw=0)or(nh=0)or(nd=0)or(ni=0)then begin writeln(stderr,
'Incomplete subfiles for character dimensions!');
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;
if lf<>7+nt+lh+(ec-bc+1)+nw+nh+nd+ni+nl+nk+ng+np then begin writeln(
stderr,'Sum of subfile sizes (',7+nt+lh+(ec-bc+1)+nw+nh+nd+ni+nl+nk+ng+
np:1,') is not equal to the stated total ',lf:1);
writeln(stderr,'Sorry, but I can''t go on; are you sure this is a TFM?')
;goto 9999;end;end;end;end{:21};
{23:}begin if fileformat<>1 then begin typebase:=7+lh;
charbase:=typebase+nt-bc;end else charbase:=6+lh-bc;
widthbase:=charbase+ec+1;heightbase:=widthbase+nw;
depthbase:=heightbase+nh;italicbase:=depthbase+nd;
ligkernbase:=italicbase+ni;kernbase:=ligkernbase+nl;
extenbase:=kernbase+nk;gluebase:=extenbase;parambase:=extenbase+ne-1;
end{:23};organize:=true;goto 30;9999:organize:=false;30:end;
{:96}{97:}procedure dosimplethings;var i:0..32767;
begin{48:}begin fonttype:=0;
if lh>=12 then begin{53:}begin checkBCPL(checksumvalue+8,40);
if(tfm[checksumvalue+8]>=11)and(tfm[checksumvalue+9]=84)and(tfm[
checksumvalue+10]=69)and(tfm[checksumvalue+11]=88)and(tfm[checksumvalue
+12]=32)and(tfm[checksumvalue+13]=77)and(tfm[checksumvalue+14]=65)and(
tfm[checksumvalue+15]=84)and(tfm[checksumvalue+16]=72)and(tfm[
checksumvalue+17]=32)then begin if(tfm[checksumvalue+18]=83)and(tfm[
checksumvalue+19]=89)then fonttype:=1 else if(tfm[checksumvalue+18]=69)
and(tfm[checksumvalue+19]=88)then fonttype:=2;end;end{:53};
if lh>=17 then begin{55:}left;write(plfile,'FAMILY');
checkBCPL(checksumvalue+48,20);outBCPL(checksumvalue+48);right{:55};
if lh>=18 then{56:}begin left;write(plfile,'FACE');
outface(checksumvalue+71);right;for i:=18 to lh-1 do begin left;
write(plfile,'HEADER D ',i:1);outoctal(checksumvalue+4*i,4);right;end;
end{:56};end;{54:}left;write(plfile,'CODINGSCHEME');
outBCPL(checksumvalue+8);right{:54};end;{51:}left;
write(plfile,'DESIGNSIZE');
if tfm[checksumvalue+4]>127 then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','Design size ','negative','!');end;
writeln(stderr,'I''ve set it to 10 points.');write(plfile,' D 10');
end else if(tfm[checksumvalue+4]=0)and(tfm[checksumvalue+5]<16)then
begin begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad TFM file: ','Design size ','too small','!');end;
writeln(stderr,'I''ve set it to 10 points.');write(plfile,' D 10');
end else outfix(checksumvalue+4);right;
write(plfile,'(COMMENT DESIGNSIZE IS IN POINTS)');outln;
write(plfile,'(COMMENT OTHER SIZES ARE MULTIPLES OF DESIGNSIZE)');
outln{:51};{49:}left;write(plfile,'CHECKSUM');outoctal(checksumvalue,4);
right{:49};
{57:}if(lh>17)and(tfm[checksumvalue+68]>127)and(fileformat=1)then begin
left;write(plfile,'SEVENBITSAFEFLAG TRUE');right;end{:57};end{:48};
{58:}if np>0 then begin left;write(plfile,'FONTDIMEN');outln;
for i:=1 to np do{60:}begin left;
if i=1 then write(plfile,'SLANT')else begin if(tfm[4*(parambase+i)]>0)
and(tfm[4*(parambase+i)]<255)then begin tfm[4*(parambase+i)]:=0;
tfm[(4*(parambase+i))+1]:=0;tfm[(4*(parambase+i))+2]:=0;
tfm[(4*(parambase+i))+3]:=0;begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','Parameter',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
{61:}if i<=7 then case i of 2:write(plfile,'SPACE');
3:write(plfile,'STRETCH');4:write(plfile,'SHRINK');
5:write(plfile,'XHEIGHT');6:write(plfile,'QUAD');
7:write(plfile,'EXTRASPACE')end else if(i<=22)and(fonttype=1)then case i
of 8:write(plfile,'NUM1');9:write(plfile,'NUM2');
10:write(plfile,'NUM3');11:write(plfile,'DENOM1');
12:write(plfile,'DENOM2');13:write(plfile,'SUP1');
14:write(plfile,'SUP2');15:write(plfile,'SUP3');16:write(plfile,'SUB1');
17:write(plfile,'SUB2');18:write(plfile,'SUPDROP');
19:write(plfile,'SUBDROP');20:write(plfile,'DELIM1');
21:write(plfile,'DELIM2');
22:write(plfile,'AXISHEIGHT')end else if(i<=13)and(fonttype=2)then if i=
8 then write(plfile,'DEFAULTRULETHICKNESS')else write(plfile,
'BIGOPSPACING',i-8:1)else if(i<=9)and(fileformat<>1)then if i=8 then
write(plfile,'EXTRASTRETCH')else write(plfile,'EXTRASHRINK')else write(
plfile,'PARAMETER D ',i:1){:61};end;outfix(4*(parambase+i));right;
end{:60};right;end;{59:}if(fonttype=1)and(np<>22)then writeln(stderr,
'Unusual number of fontdimen parameters for a math symbols font (',np:1,
' not 22).')else if(fonttype=2)and(np<>13)then writeln(stderr,
'Unusual number of fontdimen parameters for an extension font (',np:1,
' not 13).'){:59};{:58};
{62:}if(tfm[4*widthbase]>0)or(tfm[4*widthbase+1]>0)or(tfm[4*widthbase+2]
>0)or(tfm[4*widthbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','width[0] should be zero.');end;
if(tfm[4*heightbase]>0)or(tfm[4*heightbase+1]>0)or(tfm[4*heightbase+2]>0
)or(tfm[4*heightbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','height[0] should be zero.');end;
if(tfm[4*depthbase]>0)or(tfm[4*depthbase+1]>0)or(tfm[4*depthbase+2]>0)or
(tfm[4*depthbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','depth[0] should be zero.');end;
if(tfm[4*italicbase]>0)or(tfm[4*italicbase+1]>0)or(tfm[4*italicbase+2]>0
)or(tfm[4*italicbase+3]>0)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','italic[0] should be zero.');end;
for i:=0 to nw-1 do if(tfm[4*(widthbase+i)]>0)and(tfm[4*(widthbase+i)]<
255)then begin tfm[4*(widthbase+i)]:=0;tfm[(4*(widthbase+i))+1]:=0;
tfm[(4*(widthbase+i))+2]:=0;tfm[(4*(widthbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad TFM file: ','Width',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
for i:=0 to nh-1 do if(tfm[4*(heightbase+i)]>0)and(tfm[4*(heightbase+i)]
<255)then begin tfm[4*(heightbase+i)]:=0;tfm[(4*(heightbase+i))+1]:=0;
tfm[(4*(heightbase+i))+2]:=0;tfm[(4*(heightbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad TFM file: ','Height',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
for i:=0 to nd-1 do if(tfm[4*(depthbase+i)]>0)and(tfm[4*(depthbase+i)]<
255)then begin tfm[4*(depthbase+i)]:=0;tfm[(4*(depthbase+i))+1]:=0;
tfm[(4*(depthbase+i))+2]:=0;tfm[(4*(depthbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad TFM file: ','Depth',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
for i:=0 to ni-1 do if(tfm[4*(italicbase+i)]>0)and(tfm[4*(italicbase+i)]
<255)then begin tfm[4*(italicbase+i)]:=0;tfm[(4*(italicbase+i))+1]:=0;
tfm[(4*(italicbase+i))+2]:=0;tfm[(4*(italicbase+i))+3]:=0;
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad TFM file: ','Italic correction',' ',i:1,
' is too big;');end;writeln(stderr,'I have set it to zero.');end;
if nk>0 then for i:=0 to nk-1 do if(tfm[4*(kernbase+i)]>0)and(tfm[4*(
kernbase+i)]<255)then begin tfm[4*(kernbase+i)]:=0;
tfm[(4*(kernbase+i))+1]:=0;tfm[(4*(kernbase+i))+2]:=0;
tfm[(4*(kernbase+i))+3]:=0;begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','Kern',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;
if fileformat<>1 then begin if ng>0 then for i:=0 to ng-1 do if(tfm[4*(
gluebase+i)]>0)and(tfm[4*(gluebase+i)]<255)then begin tfm[4*(gluebase+i)
]:=0;tfm[(4*(gluebase+i))+1]:=0;tfm[(4*(gluebase+i))+2]:=0;
tfm[(4*(gluebase+i))+3]:=0;begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','Glue',' ',i:1,' is too big;');end;
writeln(stderr,'I have set it to zero.');end;end;{:62}end;
{:97}{98:}procedure docharacters;var c:byte;k:indextype;ai:0..ligsize;
begin{78:}sortptr:=0;
for c:=bc to ec do if tfm[4*(charbase+c)]=0 then begin if fileformat<>1
then begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
writeln(stderr,'Bad TFM file: ','width index of type ',c:1,' is zero!!')
;end end else if tfm[4*(charbase+c)]>0 then begin if charsonline=8 then
begin writeln(stderr,' ');charsonline:=1;
end else begin if charsonline>0 then write(stderr,' ');
if verbose then charsonline:=charsonline+1;end;
if verbose then printoctal(c);left;
if fileformat<>1 then begin write(plfile,'TYPE');tfm[0]:=c;
outoctal(0,1);end else begin write(plfile,'CHARACTER');outchar(c);end;
outln;{79:}begin left;write(plfile,'CHARWD');
if tfm[4*(charbase+c)]>=nw then begin perfect:=false;
writeln(stderr,' ');write(stderr,'Width',' index for character ');
printoctal(c);writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');
end else outfix(4*(widthbase+tfm[4*(charbase+c)]));right;end{:79};
if(tfm[4*(charbase+c)+1]div 16)>0 then{80:}if(tfm[4*(charbase+c)+1]div
16)>=nh then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Height',' index for character ');printoctal(c);
writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(plfile,'CHARHT');
outfix(4*(heightbase+(tfm[4*(charbase+c)+1]div 16)));right;end{:80};
if(tfm[4*(charbase+c)+1]mod 16)>0 then{81:}if(tfm[4*(charbase+c)+1]mod
16)>=nd then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Depth',' index for character ');printoctal(c);
writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(plfile,'CHARDP');
outfix(4*(depthbase+(tfm[4*(charbase+c)+1]mod 16)));right;end{:81};
if(tfm[4*(charbase+c)+2]div 4)>0 then{82:}if(tfm[4*(charbase+c)+2]div 4)
>=ni then begin perfect:=false;writeln(stderr,' ');
write(stderr,'Italic correction',' index for character ');printoctal(c);
writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end else begin left;
write(plfile,'CHARIC');
outfix(4*(italicbase+(tfm[4*(charbase+c)+2]div 4)));right;end{:82};
case(tfm[4*(charbase+c)+2]mod 4)of 0:;1:{83:}begin left;
write(plfile,'COMMENT');outln;i:=tfm[4*(charbase+c)+3];
r:=4*(ligkernbase+(i));if tfm[r]>128 then i:=256*tfm[r+2]+tfm[r+3];
repeat{74:}begin k:=4*(ligkernbase+(i));
if tfm[k]>128 then begin if 256*tfm[k+2]+tfm[k+3]>=nl then begin perfect
:=false;if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ',
'Ligature unconditional stop command address is too big.');end;
end else if tfm[k+2]>=128 then{76:}begin if((tfm[k+1]<bc)or(tfm[k+1]>ec)
or(tfm[4*(charbase+tfm[k+1])]=0))then if tfm[k+1]<>boundarychar then
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
write(stderr,'Bad TFM file: ','Kern step for',' nonexistent character ')
;printoctal(tfm[k+1]);writeln(stderr,'.');tfm[k+1]:=bc;end;left;
write(plfile,'KRN');outchar(tfm[k+1]);r:=256*(tfm[k+2]-128)+tfm[k+3];
if r>=nk then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','Kern index too large.');end;
write(plfile,' R 0.0');end else outfix(4*(kernbase+r));right;
end{:76}else if fileformat<>1 then{116:}begin if((tfm[k+1]<bc)or(tfm[k+1
]>ec)or(tfm[4*(charbase+tfm[k+1])]=0))then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad TFM file: ','Glue step for',' nonexistent character ')
;printoctal(tfm[k+1]);writeln(stderr,'.');tfm[k+1]:=bc;
end else begin left;write(plfile,'GLUE');outchar(tfm[k+1]);
if 3*tfm[k+3]>=ng then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','Glue index too large.');end;
write(plfile,' R 0.0 R 0.0 R 0.0');
end else begin outfix(4*(gluebase+3*tfm[k+3]));
outfix(4*(gluebase+3*tfm[k+3]+1));outfix(4*(gluebase+3*tfm[k+3]+2));end;
right;end;
end{:116}else{77:}begin if((tfm[k+1]<bc)or(tfm[k+1]>ec)or(tfm[4*(
charbase+tfm[k+1])]=0))then if tfm[k+1]<>boundarychar then begin perfect
:=false;if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad TFM file: ','Ligature step for',
' nonexistent character ');printoctal(tfm[k+1]);writeln(stderr,'.');
tfm[k+1]:=bc;end;
if((tfm[k+3]<bc)or(tfm[k+3]>ec)or(tfm[4*(charbase+tfm[k+3])]=0))then
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
write(stderr,'Bad TFM file: ','Ligature step produces the',
' nonexistent character ');printoctal(tfm[k+3]);writeln(stderr,'.');
tfm[k+3]:=bc;end;left;r:=tfm[k+2];
if(r=4)or((r>7)and(r<>11))then begin writeln(stderr,
'Ligature step with nonstandard code changed to LIG');r:=0;tfm[k+2]:=0;
end;if r mod 4>1 then write(plfile,'/');write(plfile,'LIG');
if odd(r)then write(plfile,'/');while r>3 do begin write(plfile,'>');
r:=r-4;end;outchar(tfm[k+1]);outchar(tfm[k+3]);right;end{:77};
if tfm[k]>0 then if level=1 then{75:}begin if tfm[k]>=128 then write(
plfile,'(STOP)')else begin count:=0;
for ai:=i+1 to i+tfm[k]do if activity[ai]=2 then count:=count+1;
write(plfile,'(SKIP D ',count:1,')');end;outln;end{:75};end{:74};
if tfm[k]>=128 then i:=nl else i:=i+1+tfm[k];until i>=nl;right;end{:83};
2:if fileformat<>1 then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','the tag of type ',c:1,' must be 0 or 1'
);end else{84:}begin r:=tfm[4*(charbase+c)+3];
if((r<bc)or(r>ec)or(tfm[4*(charbase+r)]=0))then begin begin perfect:=
false;if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad TFM file: ','Character list link to',
' nonexistent character ');printoctal(r);writeln(stderr,'.');end;
tfm[4*(charbase+c)+2]:=4*(tfm[4*(charbase+c)+2]div 4)+0;
end else begin while(r<c)and((tfm[4*(charbase+r)+2]mod 4)=2)do r:=tfm[4*
(charbase+r)+3];if r=c then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','Cycle in a character list!');end;
write(stderr,'Character ');printoctal(c);
writeln(stderr,' now ends the list.');
tfm[4*(charbase+c)+2]:=4*(tfm[4*(charbase+c)+2]div 4)+0;
end else begin left;write(plfile,'NEXTLARGER');
outchar(tfm[4*(charbase+c)+3]);right;end;end;end{:84};
3:if fileformat<>1 then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','the tag of type ',c:1,' must be 0 or 1'
);end else{85:}if tfm[4*(charbase+c)+3]>=ne then begin begin perfect:=
false;writeln(stderr,' ');
write(stderr,'Extensible',' index for character ');printoctal(c);
writeln(stderr,' is too large;');
writeln(stderr,'so I reset it to zero.');end;
tfm[4*(charbase+c)+2]:=4*(tfm[4*(charbase+c)+2]div 4)+0;
end else begin left;write(plfile,'VARCHAR');outln;
{86:}for k:=0 to 3 do if(k=3)or(tfm[4*(extenbase+tfm[4*(charbase+c)+3])+
k]>0)then begin left;case k of 0:write(plfile,'TOP');
1:write(plfile,'MID');2:write(plfile,'BOT');3:write(plfile,'REP')end;
if((tfm[4*(extenbase+tfm[4*(charbase+c)+3])+k]<bc)or(tfm[4*(extenbase+
tfm[4*(charbase+c)+3])+k]>ec)or(tfm[4*(charbase+tfm[4*(extenbase+tfm[4*(
charbase+c)+3])+k])]=0))then outchar(c)else outchar(tfm[4*(extenbase+tfm
[4*(charbase+c)+3])+k]);right;end{:86};right;end{:85};end;right;
end{:78};end;{:98}{99:}{120:}procedure outkanji(jiscode:integer);
var cx:integer;i:0..4;
begin if charcodeformat=charcodeoctal then begin cx:=jiscode;
if(isinternalUPTEX)then write(plfile,'U ')else write(plfile,'J ');
dig[0]:=Hi(cx)div 16;dig[1]:=Hi(cx)mod 16;dig[2]:=Lo(cx)div 16;
dig[3]:=Lo(cx)mod 16;
for i:=0 to 3 do if dig[i]<10 then write(plfile,dig[i])else case dig[i]
of 10:write(plfile,'A');11:write(plfile,'B');12:write(plfile,'C');
13:write(plfile,'D');14:write(plfile,'E');15:write(plfile,'F');end;
end else begin cx:=toBUFF(fromDVI(jiscode));
if BYTE1(cx)<>0 then write(plfile,xchr[BYTE1(cx)]);
if BYTE2(cx)<>0 then write(plfile,xchr[BYTE2(cx)]);
if BYTE3(cx)<>0 then write(plfile,xchr[BYTE3(cx)]);
write(plfile,xchr[BYTE4(cx)]);end;end;
{:120}{121:}function validjiscode(cx:integer):boolean;
begin validjiscode:=true;
if(cx>65535)or(not ischarkanji(fromDVI(cx)))or(toDVI(fromDVI(cx))<>cx)
then validjiscode:=false;end;
{:121}{122:}function indextojis(ix:integer):integer;
begin indextojis:=ix;end;
{:122}{123:}function jistoindex(cx:integer):integer;
begin jistoindex:=cx;end{:123};begin initialize;
if not organize then uexit(1);dosimplethings;
{66:}if nl>0 then begin for ai:=0 to nl-1 do activity[ai]:=0;
{69:}if tfm[4*(ligkernbase+(0))]=255 then begin left;
write(plfile,'BOUNDARYCHAR');boundarychar:=tfm[4*(ligkernbase+(0))+1];
outchar(boundarychar);right;activity[0]:=1;end;
if tfm[4*(ligkernbase+(nl-1))]=255 then begin r:=256*tfm[4*(ligkernbase+
(nl-1))+2]+tfm[4*(ligkernbase+(nl-1))+3];
if r>=nl then begin perfect:=false;writeln(stderr,' ');write(stderr,
'Ligature/kern starting index for boundarychar is too large;');
writeln(stderr,'so I removed it.');end else begin labelptr:=1;
labeltable[1].cc:=256;labeltable[1].rr:=r;bcharlabel:=r;activity[r]:=2;
end;activity[nl-1]:=1;end{:69};end;
{67:}for c:=bc to ec do if(tfm[4*(charbase+c)+2]mod 4)=1 then begin r:=
tfm[4*(charbase+c)+3];
if r<nl then begin if tfm[4*(ligkernbase+(r))]>128 then begin r:=256*tfm
[4*(ligkernbase+(r))+2]+tfm[4*(ligkernbase+(r))+3];
if r<nl then if activity[tfm[4*(charbase+c)+3]]=0 then activity[tfm[4*(
charbase+c)+3]]:=1;end;end;if r>=nl then begin perfect:=false;
writeln(stderr,' ');case fileformat of 1:write(stderr,'Ligature/kern ');
2,3:write(stderr,'Glue/kern ');end;
write(stderr,'starting index for character ');printoctal(c);
writeln(stderr,' is too large;');writeln(stderr,'so I removed it.');
tfm[4*(charbase+c)+2]:=4*(tfm[4*(charbase+c)+2]div 4)+0;
end else{68:}begin sortptr:=labelptr;
while labeltable[sortptr].rr>r do begin labeltable[sortptr+1]:=
labeltable[sortptr];sortptr:=sortptr-1;end;labeltable[sortptr+1].cc:=c;
labeltable[sortptr+1].rr:=r;labelptr:=labelptr+1;activity[r]:=2;
end{:68};end;labeltable[labelptr+1].rr:=ligsize;{:67};
if nl>0 then begin left;
if fileformat<>1 then write(plfile,'GLUEKERN')else write(plfile,
'LIGTABLE');outln;
{70:}for ai:=0 to nl-1 do if activity[ai]=2 then begin r:=tfm[4*(
ligkernbase+(ai))];if r<128 then begin r:=r+ai+1;
if r>=nl then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','Ligature/kern step ',ai:1,
' skips too far;');end;writeln(stderr,'I made it stop.');
tfm[4*(ligkernbase+(ai))]:=128;end else activity[r]:=2;end;end{:70};
{71:}sortptr:=1;
for acti:=0 to nl-1 do if activity[acti]<>1 then begin i:=acti;
{73:}if activity[i]=0 then begin if level=1 then begin left;
write(plfile,'COMMENT THIS PART OF THE PROGRAM IS NEVER USED!');outln;
end end else if level=2 then right{:73};
{72:}while i=labeltable[sortptr].rr do begin left;write(plfile,'LABEL');
if labeltable[sortptr].cc=256 then write(plfile,' BOUNDARYCHAR')else
outchar(labeltable[sortptr].cc);right;sortptr:=sortptr+1;end{:72};
{74:}begin k:=4*(ligkernbase+(i));
if tfm[k]>128 then begin if 256*tfm[k+2]+tfm[k+3]>=nl then begin perfect
:=false;if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ',
'Ligature unconditional stop command address is too big.');end;
end else if tfm[k+2]>=128 then{76:}begin if((tfm[k+1]<bc)or(tfm[k+1]>ec)
or(tfm[4*(charbase+tfm[k+1])]=0))then if tfm[k+1]<>boundarychar then
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
write(stderr,'Bad TFM file: ','Kern step for',' nonexistent character ')
;printoctal(tfm[k+1]);writeln(stderr,'.');tfm[k+1]:=bc;end;left;
write(plfile,'KRN');outchar(tfm[k+1]);r:=256*(tfm[k+2]-128)+tfm[k+3];
if r>=nk then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','Kern index too large.');end;
write(plfile,' R 0.0');end else outfix(4*(kernbase+r));right;
end{:76}else if fileformat<>1 then{116:}begin if((tfm[k+1]<bc)or(tfm[k+1
]>ec)or(tfm[4*(charbase+tfm[k+1])]=0))then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad TFM file: ','Glue step for',' nonexistent character ')
;printoctal(tfm[k+1]);writeln(stderr,'.');tfm[k+1]:=bc;
end else begin left;write(plfile,'GLUE');outchar(tfm[k+1]);
if 3*tfm[k+3]>=ng then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','Glue index too large.');end;
write(plfile,' R 0.0 R 0.0 R 0.0');
end else begin outfix(4*(gluebase+3*tfm[k+3]));
outfix(4*(gluebase+3*tfm[k+3]+1));outfix(4*(gluebase+3*tfm[k+3]+2));end;
right;end;
end{:116}else{77:}begin if((tfm[k+1]<bc)or(tfm[k+1]>ec)or(tfm[4*(
charbase+tfm[k+1])]=0))then if tfm[k+1]<>boundarychar then begin perfect
:=false;if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad TFM file: ','Ligature step for',
' nonexistent character ');printoctal(tfm[k+1]);writeln(stderr,'.');
tfm[k+1]:=bc;end;
if((tfm[k+3]<bc)or(tfm[k+3]>ec)or(tfm[4*(charbase+tfm[k+3])]=0))then
begin perfect:=false;if charsonline>0 then writeln(stderr,' ');
charsonline:=0;
write(stderr,'Bad TFM file: ','Ligature step produces the',
' nonexistent character ');printoctal(tfm[k+3]);writeln(stderr,'.');
tfm[k+3]:=bc;end;left;r:=tfm[k+2];
if(r=4)or((r>7)and(r<>11))then begin writeln(stderr,
'Ligature step with nonstandard code changed to LIG');r:=0;tfm[k+2]:=0;
end;if r mod 4>1 then write(plfile,'/');write(plfile,'LIG');
if odd(r)then write(plfile,'/');while r>3 do begin write(plfile,'>');
r:=r-4;end;outchar(tfm[k+1]);outchar(tfm[k+3]);right;end{:77};
if tfm[k]>0 then if level=1 then{75:}begin if tfm[k]>=128 then write(
plfile,'(STOP)')else begin count:=0;
for ai:=i+1 to i+tfm[k]do if activity[ai]=2 then count:=count+1;
write(plfile,'(SKIP D ',count:1,')');end;outln;end{:75};end{:74};end;
if level=2 then right{:71};right;{90:}hashptr:=0;yligcycle:=256;
for hh:=0 to hashsize do hash[hh]:=0;
for c:=bc to ec do if(tfm[4*(charbase+c)+2]mod 4)=1 then begin i:=tfm[4*
(charbase+c)+3];
if tfm[4*(ligkernbase+(i))]>128 then i:=256*tfm[4*(ligkernbase+(i))+2]+
tfm[4*(ligkernbase+(i))+3];{91:}repeat hashinput;
k:=tfm[4*(ligkernbase+(i))];if k>=128 then i:=nl else i:=i+1+k;
until i>=nl{:91};end;if bcharlabel<nl then begin c:=256;i:=bcharlabel;
{91:}repeat hashinput;k:=tfm[4*(ligkernbase+(i))];
if k>=128 then i:=nl else i:=i+1+k;until i>=nl{:91};end;
if hashptr=hashsize then begin writeln(stderr,
'Sorry, I haven''t room for so many ligature/kern pairs!');uexit(1);;
end;for hh:=1 to hashptr do begin r:=hashlist[hh];
if classvar[r]>0 then r:=ffn(r,(hash[r]-1)div 256,(hash[r]-1)mod 256);
end;if yligcycle<256 then begin write(stderr,
'Infinite ligature loop starting with ');
if xligcycle=256 then write(stderr,'boundary')else printoctal(xligcycle)
;write(stderr,' and ');printoctal(yligcycle);writeln(stderr,'!');
write(plfile,'(INFINITE LIGATURE LOOP MUST BE BROKEN!)');uexit(1);
end{:90};end{:66};
if fileformat<>1 then begin{117:}thiscode:=tfm[4*(typebase+0)+0]*256+tfm
[4*(typebase+0)+1];
thistype:=tfm[4*(typebase+0)+2]*256+tfm[4*(typebase+0)+3];
if(thiscode<>0)or(thistype<>0)then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ',
'the first entry in char_type is not zero. I''ll zero it.');end;
writeln(stderr,'JIS code is ',thiscode:1,'. Type is ',thistype:1,'.');
end;for kanjiindex:=0 to 65535 do kanjitype[kanjiindex]:=-1;
for typeindex:=1 to nt-1 do begin thiscode:=tfm[4*(typebase+typeindex)+0
]*256+tfm[4*(typebase+typeindex)+1];
thistype:=tfm[4*(typebase+typeindex)+2]*256+tfm[4*(typebase+typeindex)+3
];if not validjiscode(thiscode)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','jis code ',thiscode:1,
' in char_type table entry ',typeindex:1,' is not valid. Ignoring it.');
end else if(thistype<=0)or(thistype>ec)then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','type ',thistype:1,' of jis code ',
thiscode:1,' in char_type table is not valid. Ignoring character.');
end else kanjitype[jistoindex(thiscode)]:=thistype;end;
for typenum:=1 to ec do begin left;write(plfile,'CHARSINTYPE');
tfm[0]:=typenum;outoctal(0,1);typecount:=0;
for kanjiindex:=0 to 65535 do if kanjitype[kanjiindex]=typenum then
begin if(typecount mod 10)=0 then outln else write(plfile,' ');
typecount:=typecount+1;outkanji(indextojis(kanjiindex));end;
if typecount=0 then begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
writeln(stderr,'Bad TFM file: ','type ',typenum:1,
'has no characters in it!');end;outln;right;end;{:117};
end else begin{87:}if ne>0 then for c:=0 to ne-1 do for d:=0 to 3 do
begin k:=4*(extenbase+c)+d;
if(tfm[k]>0)or(d=3)then begin if((tfm[k]<bc)or(tfm[k]>ec)or(tfm[4*(
charbase+tfm[k])]=0))then begin begin perfect:=false;
if charsonline>0 then writeln(stderr,' ');charsonline:=0;
write(stderr,'Bad TFM file: ','Extensible recipe involves the',
' nonexistent character ');printoctal(tfm[k]);writeln(stderr,'.');end;
if d<3 then tfm[k]:=0;end;end;end{:87};end;docharacters;
if verbose then writeln(stderr,'.');
if level<>0 then writeln(stderr,'This program isn''t working!');
if not perfect then begin write(plfile,
'(COMMENT THE TFM FILE WAS BAD, SO THE DATA HAS BEEN CHANGED!)');
writeln(plfile);end;end.{:99}
