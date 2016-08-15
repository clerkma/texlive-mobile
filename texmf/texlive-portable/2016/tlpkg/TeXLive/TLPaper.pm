# $Id: TLPaper.pm 40600 2016-04-18 21:56:02Z karl $
# TeXLive::TLPaper.pm - query/modify paper sizes for our various programs
# Copyright 2008-2016 Norbert Preining
# This file is licensed under the GNU General Public License version 2
# or any later version.

package TeXLive::TLPaper;

my $svnrev = '$Revision: 40600 $';
my $_modulerevision;
if ($svnrev =~ m/: ([0-9]+) /) {
  $_modulerevision = $1;
} else {
  $_modulerevision = "unknown";
}
sub module_revision {
  return $_modulerevision;
}

BEGIN {
  use Exporter ();
  use vars qw( @ISA @EXPORT_OK @EXPORT );
  @ISA = qw(Exporter);
  @EXPORT_OK = qw(
    %paper_config_path_component
    %paper_config_name
  );
  @EXPORT = @EXPORT_OK;
}

=pod

=head1 NAME

C<TeXLive::TLPaper> -- TeX Live paper size setting module

=head1 SYNOPSIS

  use TeXLive::TLPaper;

=head1 DESCRIPTION

=over 4

=cut

use TeXLive::TLUtils qw(:DEFAULT dirname merge_into mkdirhier);
use TeXLive::TLConfig;


#
# paper data
# 
our %paper = (
  "xdvi"     => {
    sub => \&paper_xdvi,
    default_component => "xdvi",
    default_file      => "XDvi",
    pkg => "xdvi",
  },
  "pdftex"   => {
    sub => \&paper_pdftex,
    default_component => "tex/generic/config",
    default_file      => "pdftexconfig.tex",
    pkg => "pdftex",
  },
  "dvips"    => {
    sub => \&paper_dvips,
    default_component => "dvips/config",
    default_file      => "config.ps",
    pkg => "dvips",
  },
  "dvipdfmx" => {
    sub => \&paper_dvipdfmx,
    default_component => "dvipdfmx",
    default_file      => "dvipdfmx.cfg",
    pkg => "dvipdfmx",
  },
  "context"  => {
    sub => \&paper_context,
    default_component => "tex/context/user",
    default_file      => "cont-sys.tex",
    pkg => "context",
  },
  "psutils"  => {
    sub => \&paper_psutils,
    default_component => "psutils",
    default_file      => "paper.cfg",
    pkg => "psutils",
  },
);
  
# Output is done to the components in this hash.
# If a value is undefined, we take the one from %default_...
#
our %paper_config_path_component;
our %paper_config_name;


my %xdvi_papersize = (
  "a1"       => "59.4x84.0cm",
  "a1r"      => "84.0x59.4cm",
  "a2"       => "42.0x59.4cm",
  "a2r"      => "59.4x42.0cm",
  "a3"       => "29.7x42.0cm",
  "a3r"      => "42.0x29.7cm",
  "a4"       => "21.0x29.7cm",
  "a4r"      => "29.7x21.0cm",
  "a5"       => "14.85x21.0cm",
  "a5r"      => "21.0x14.85cm",
  "a6"       => "10.5x14.85cm",
  "a6r"      => "14.85x10.5cm",
  "a7"       => "7.42x10.5cm",
  "a7r"      => "10.5x7.42cm",
  "b1"       => "70.6x100.0cm",
  "b1r"      => "100.0x70.6cm",
  "b2"       => "50.0x70.6cm",
  "b2r"      => "70.6x50.0cm",
  "b3"       => "35.3x50.0cm",
  "b3r"      => "50.0x35.3cm",
  "b4"       => "25.0x35.3cm",
  "b4r"      => "35.3x25.0cm",
  "b5"       => "17.6x25.0cm",
  "b5r"      => "25.0x17.6cm",
  "b6"       => "13.5x17.6cm",
  "b6r"      => "17.6x13.5cm",
  "b7"       => "8.8x13.5cm",
  "b7r"      => "13.5x8.8cm",
  "c1"       => "64.8x91.6cm",
  "c1r"      => "91.6x64.8cm",
  "c2"       => "45.8x64.8cm",
  "c2r"      => "64.8x45.8cm",
  "c3"       => "32.4x45.8cm",
  "c3r"      => "45.8x32.4cm",
  "c4"       => "22.9x32.4cm",
  "c4r"      => "32.4x22.9cm",
  "c5"       => "16.2x22.9cm",
  "c5r"      => "22.9x16.2cm",
  "c6"       => "11.46x16.2cm",
  "c6r"      => "16.2x11.46cm",
  "c7"       => "8.1x11.46cm",
  "c7r"      => "11.46x8.1cm",
  "foolscap" => "13.5x17.0",
  "ledger"   => "17.0x11.0",
  "legal"    => "8.5x14",
  "letter"   => "8.5x11",
  "tabloid"  => "11.0x17.0",
  "us"       => "8.5x11",
  "usr"      => "11x8.5",
);

my %pdftex_papersize = (
  "a4"     => [ '210 true mm', '297 true mm' ],
  "letter" => [ '8.5 true in', '11 true in' ],
);

my %dvipdfm_papersize = (
  "a3" => 1,
  "a4" => 1,
  "ledger" => 1, 
  "legal" => 1,
  "letter" => 1,
  "tabloid" => 1,
);

my %psutils_papersize = ( "a4" => 1, "letter" => 1, );




=item C<get_paper_list($prog)>

Returns the list of supported paper sizes with the first entry being
the currently selected one.

=cut

sub get_paper_list {
  my $prog = shift;
  return ( &{$paper{$prog}{'sub'}} ( "/dummy", "--returnlist" ) );
}

=item C<get_paper($prog)>

Returns the currently selected paper size for program C<$prog>.

=cut

sub get_paper {
  my $pps = get_paper_list(shift);
  return $pps->[0];
}

=item C<do_paper($prog,$texmfsysconfig,@args)>

Call the paper subroutine for C<$prog>, passing args.

Returns a reference to a list of papers if called with C<--returnlist>, 
otherwise one of the standard flags (see TeXLive::TLConfig).

=cut

sub do_paper {
  my ($prog,$texmfsysconfig,@args) = @_;
  if (exists $paper{$prog}{'sub'}) {
    my $sub = $paper{$prog}{'sub'};
    return(&$sub($texmfsysconfig, @args));
  } else {
    tlwarn("$0: unknown paper program $prog ($texmfsysconfig,@args)\n");
    return($F_ERROR);
  }
  return ($F_OK); # not reached
}


=item C<paper_all($texmfsysconfig, $newpaper)>

Pass all C<@args> to each paper subroutine in turn, thus setting the
paper size for all supported programs. Returns the bit-mapped return
values of the single subroutine returns.

=cut

sub paper_all {
  my $ret = $F_OK;
  for my $p (sort keys %paper) {
    $ret |= &{$paper{$p}{'sub'}} (@_);
  }
  return($ret);
}


# return the config file to look in by running kpsewhich with the
# specified PROGNAME, FORMAT, and @FILENAMES.  If no result, give a
# warning and return the empty string.
# 
sub find_paper_file {
  my ($progname, $format, @filenames) = @_;
  my $ret = "";
  
  my $cmd;
  for my $filename (@filenames) {
    $cmd = qq!kpsewhich --progname=$progname --format="$format" $filename!;
    chomp($ret = `$cmd`);
    if ($ret) {
      debug("paper file for $progname ($format) $filename: $ret\n");
      last;
    }
  }

  debug("$0: found no paper file for $progname (from $cmd)\n") if ! $ret;
  return $ret;
}

sub setup_names {
  my $prog = shift;
  my $outcomp = $paper_config_path_component{$prog}
                || $paper{$prog}{'default_component'};
  my $filecomp = $paper_config_name{$prog}
                 || $paper{$prog}{'default_file'};
  return ($outcomp, $filecomp);
}


# xdvi format:
# /--- XDvi ---
# |...
# |*paper: <NAME>
# |...
# \------------
#
# Reading is done via --progname=xdvi --format='other text files' XDvi
# Writing is done to TEXMFSYSCONFIG/xdvi/XDvi
#
sub paper_xdvi {
  my $outtree = shift;
  my $newpaper = shift;

  my ($outcomp, $filecomp) = setup_names("xdvi");
  my $dftfile = $paper{'xdvi'}{'default_file'};
  my $outfile = "$outtree/$outcomp/$filecomp";
  my $inp = &find_paper_file("xdvi", "other text files", $filecomp, $dftfile);

  return($F_ERROR) unless $inp; 
  

  my @sizes = keys %xdvi_papersize;
  return &paper_do_simple($inp, "xdvi", '^\*paper: ', '^\*paper:\s+(\w+)\s*$',
            sub {
              my ($ll,$np) = @_;
              $ll =~ s/^\*paper:\s+(\w+)\s*$/\*paper: $np\n/;
              return($ll);
            }, $outfile, \@sizes, '(undefined)', '*paper: a4', $newpaper);
}


# pdftex pdftexconfig.dat format
# /--- pdftexconfig.tex ---
# |...
# |\pdfpageheight       = 297 true mm
# |\pdfpagewidth        = 210 true mm
# |...
# \------------------------
#
# Reading is done via --progname=pdftex --format='tex' pdftexconfig.tex
# Writing is done to TEXMFSYSCONFIG/tex/generic/config/pdftexconfig.tex
#
sub paper_pdftex {
  my $outtree = shift;
  my $newpaper = shift;
  my ($outcomp, $filecomp) = setup_names("pdftex");
  my $dftfile = $paper{'pdftex'}{'default_file'};
  my $outfile = "$outtree/$outcomp/$filecomp";
  my $inp = &find_paper_file("pdftex", "tex", $filecomp, $dftfile);

  return($F_ERROR) unless $inp; 

  open(FOO, "<$inp") || die "$0: open($inp) failed: $!";
  my @lines = <FOO>;
  close(FOO);

  my @cpwidx;
  my @cphidx;
  my ($cpw, $cph);
  my $endinputidx;
  # read the lines and the last pdfpageswidth/height wins
  for my $idx (0..$#lines) {
    my $l = $lines[$idx];
    if ($l =~ m/^\s*\\pdfpagewidth\s*=\s*([0-9.,]+\s*true\s*[^\s]*)/) {
      if (defined($cpw) && $cpw ne $1) {
        tl_warn("TLPaper: inconsistent paper sizes in $inp for page width! Please fix that.\n");
        return $F_ERROR;
      }
      $cpw = $1;
      push @cpwidx, $idx;
      next;
    }
    if ($l =~ m/^\s*\\pdfpageheight\s*=\s*([0-9.,]+\s*true\s*[^\s]*)/) {
      if (defined($cph) && $cph ne $1) {
        tl_warn("TLPaper: inconsistent paper sizes in $inp for page height! Please fix that.\n");
        return $F_ERROR;
      }
      $cph = $1;
      push @cphidx, $idx;
      next;
    }
    if ($l =~ m/^\s*\\endinput\s*/) {
      $endinputidx = $idx;
      next;
    }
  }
  # trying to find the right papersize
  #
  my $currentpaper;
  if (defined($cpw) && defined($cph)) {
    for my $pname (keys %pdftex_papersize) {
      my ($w, $h) = @{$pdftex_papersize{$pname}};
      if (($w eq $cpw) && ($h eq $cph)) {
        $currentpaper = $pname;
        last;
      }
    }
  } else {
    $currentpaper = "(undefined)";
  }
  $currentpaper || ($currentpaper = "$cpw x $cph");
  if (defined($newpaper)) {
    if ($newpaper eq "--list") {
      info("$currentpaper\n");
      for my $p (keys %pdftex_papersize) {
        info("$p\n") unless ($p eq $currentpaper);
      }
    } elsif ($newpaper eq "--returnlist") {
      my @ret = ();
      push @ret, "$currentpaper";
      for my $p (keys %pdftex_papersize) {
        push @ret, $p unless ($p eq $currentpaper);
      }
      return \@ret;
    } else {
      my $found = 0;
      for my $p (keys %pdftex_papersize) {
        if ($p eq $newpaper) {
          $found = 1;
          last;
        }
      }
      if ($found) {
        my $newwidth = ${$pdftex_papersize{$newpaper}}[0];
        my $newheight = ${$pdftex_papersize{$newpaper}}[1];
        if (@cpwidx) {
          for my $idx (@cpwidx) {
            ddebug("TLPaper: before line: $lines[$idx]");
            ddebug("TLPaper: replacement: $newwidth\n");
            $lines[$idx] =~ s/^\s*\\pdfpagewidth\s*=\s*[0-9.,]+\s*true\s*[^\s]*/\\pdfpagewidth        = $newwidth/;
            ddebug("TLPaper: after line : $lines[$idx]");
          }
        } else {
          my $addlines = "\\pdfpagewidth        = $newwidth\n";
          if (defined($endinputidx)) {
            $lines[$endinputidx] = $addlines . $lines[$endinputidx];
          } else {
            $lines[$#lines] = $addlines;
          }
        }
        if (@cphidx) {
          for my $idx (@cphidx) {
            ddebug("TLPaper: before line: $lines[$idx]");
            ddebug("TLPaper: replacement: $newheight\n");
            $lines[$idx] =~ s/^\s*\\pdfpageheight\s*=\s*[0-9.,]+\s*true\s*[^\s]*/\\pdfpageheight       = $newheight/;
            ddebug("TLPaper: after line : $lines[$idx]");
          }
        } else {
          my $addlines = "\\pdfpageheight       = $newheight";
          if (defined($endinputidx)) {
            $lines[$endinputidx] = $addlines . $lines[$endinputidx];
          } else {
            $lines[$#lines] = $addlines;
          }
        }
        info("$0: setting paper size for pdftex to $newpaper.\n");
        mkdirhier(dirname($outfile));
        # if we create the outfile we have to call mktexlsr
        TeXLive::TLUtils::announce_execute_actions("files-changed")
          unless (-r $outfile);
        if (!open(TMP, ">$outfile")) {
          tlwarn("$0: Cannot write to $outfile: $!\n");
          tlwarn("Not setting paper size for pdftex.\n");
          return($F_ERROR);
        }
        for (@lines) { print TMP; }
        close(TMP) || warn "$0: close(>$outfile) failed: $!";
        TeXLive::TLUtils::announce_execute_actions("regenerate-formats");
        # TODO should we return the value of announce_execute action?
        return($F_OK);
      } else {
        tlwarn("$0: Not a valid paper size for pdftex: $newpaper\n");
        return($F_WARNING);
      }
    }
  } else {
    info("Current pdftex paper size (from $inp): $currentpaper\n");
  }
  return($F_OK);
}


# dvips config.ps format:
# /--- config.ps ---
# |...
# |stuff not related to paper sizes
# |...
# | <empty line>
# |% some comments
# |% more comments
# |@ <NAME> <WIDTH> <HEIGHT>
# |@+ ...definition line
# |@+ ...definition line
# |... more definition lines
# |@+ %%EndPaperSize
# |
# |@ <NAME> <WIDTH> <HEIGHT>
# |...
# \------------
#
# the first paper definition is the default
# selecting paper is done like with texconfig which used ed to move the
# selected part between @ $selected_paper .... @ /-1 (the line before the
# next @ line) to the line before the first @  line.
# (what a tricky ed invocation te created there, impressive!!!)
#
# Reading is done via --progname=dvips --format='dvips config' config.ps
# Writing is done to TEXMFSYSCONFIG/dvips/config/config.ps
#
sub paper_dvips {
  my $outtree = shift;
  my $newpaper = shift;

  my ($outcomp, $filecomp) = setup_names("dvips");
  my $dftfile = $paper{'dvips'}{'default_file'};
  my $outfile = "$outtree/$outcomp/$filecomp";
  my $inp = &find_paper_file("dvips", "dvips config", $filecomp, $dftfile);

  return($F_ERROR) unless $inp; 
  
  open(FOO, "<$inp") || die "$0: open($inp) failed: $!";
  my @lines = <FOO>;
  close(FOO);

  my @papersizes;
  my $firstpaperidx;
  my %startidx;
  my %endidx;
  my $in_block = "";
  my $idx = 0;
  for my $idx (0 .. $#lines) {
    if ($lines[$idx] =~ m/^@ (\w+)/) {
      $startidx{$1} = $idx;
      $firstpaperidx || ($firstpaperidx = $idx-1);
      $in_block = $1;
      push @papersizes, $1;
      next;
    }
    # empty lines or comments stop a block
    if ($in_block) {
      if ($lines[$idx] =~ m/^\s*(%.*)?\s*$/) {
        $endidx{$in_block} = $idx-1;
        $in_block = "";
      }
      next;
    }
  }

  if (defined($newpaper)) {
    if ($newpaper eq "--list") {
      for my $p (@papersizes) {
        info("$p\n"); # first is already the selected one
      }
    } elsif ($newpaper eq "--returnlist") {
      return(\@papersizes);
    } else {
      my $found = 0;
      for my $p (@papersizes) {
        if ($p eq $newpaper) {
          $found = 1;
          last;
        }
      }
      if ($found) {
        my @newlines;
        for my $idx (0..$#lines) {
          if ($idx < $firstpaperidx) {
            push @newlines, $lines[$idx];
            next;
          }
          if ($idx == $firstpaperidx) { 
            # insert the selected paper definition
            push @newlines, @lines[$startidx{$newpaper}..$endidx{$newpaper}];
            push @newlines, $lines[$idx];
            next;
          }
          if ($idx >= $startidx{$newpaper} && $idx <= $endidx{$newpaper}) {
            next;
          }
          push @newlines, $lines[$idx];
        }
        info("$0: setting paper size for dvips to $newpaper.\n");
        mkdirhier(dirname($outfile));
        # if we create the outfile we have to call mktexlsr
        TeXLive::TLUtils::announce_execute_actions("files-changed")
          unless (-r $outfile);
        if (!open(TMP, ">$outfile")) {
          tlwarn("$0: Cannot write to $outfile: $!\n");
          tlwarn("Not setting paper size for dvips.\n");
          return ($F_ERROR);
        }
        for (@newlines) { print TMP; }
        close(TMP) || warn "$0: close(>$outfile) failed: $!";
      } else {
        tlwarn("$0: Not a valid paper size for dvips: $newpaper\n");
        return($F_WARNING);
      }
    }
  } else {
    info("Current dvips paper size (from $inp): $papersizes[0]\n");
  }
  return($F_OK);
}


# dvipdfm(x) format:
# /--- dvipdfm/config, dvipdfmx/dvipdfmx.cfg ---
# |...
# |p <NAME>
# |...
# \------------
#
# Reading is done
#  for dvipdfm via --progname=dvipdfm --format='other text files' config
#  for dvipdfmx via --progname=dvipdfmx --format='other text files' dvipdfmx.cfg
# Writing is done to TEXMFSYSCONFIG/dvipdfm/config/config 
# and /dvipdfmx/dvipdfmx.cfg
#
#
sub do_dvipdfm_and_x {
  my ($inp,$prog,$outtree,$paplist,$newpaper) = @_;

  my ($outcomp, $filecomp) = setup_names($prog);
  my $outfile = "$outtree/$outcomp/$filecomp";

  return &paper_do_simple($inp, $prog, '^p\s+', '^p\s+(\w+)\s*$',
            sub {
              my ($ll,$np) = @_;
              $ll =~ s/^p\s+(\w+)\s*$/p $np\n/;
              return($ll);
            }, $outfile, $paplist, '(undefined)', 'p a4', $newpaper);
}

sub paper_dvipdfm {
  my $outtree = shift;
  my $newpaper = shift;

  my ($outcomp, $filecomp) = setup_names("dvipdfm");
  my $dftfile = $paper{'dvipdfm'}{'default_file'};
  my $inp = &find_paper_file("dvipdfm", "other text files", $filecomp, $dftfile);
  return ($F_ERROR) unless $inp; 

  my @sizes = keys %dvipdfm_papersize;
  return &do_dvipdfm_and_x($inp, "dvipdfm", $outtree, \@sizes, $newpaper);
}

sub paper_dvipdfmx {
  my $outtree = shift;
  my $newpaper = shift;

  my ($outcomp, $filecomp) = setup_names("dvipdfmx");
  my $dftfile = $paper{'dvipdfmx'}{'default_file'};

  my $inp = &find_paper_file("dvipdfmx", "other text files", $filecomp, $dftfile);
  return ($F_ERROR) unless $inp; 

  my @sizes = keys %dvipdfm_papersize;
  return &do_dvipdfm_and_x($inp, "dvipdfmx", $outtree, \@sizes, $newpaper);
}


# context format:
# /--- cont-sys.{tex,rme}
# |...
# |\setuppapersize[letter][letter]
# |...
# \------------
# 
sub paper_context {
  my $outtree = shift;
  my $newpaper = shift;
  my ($outcomp, $filecomp) = setup_names("context");
  my $dftfile = $paper{'context'}{'default_file'};
  my $outfile = "$outtree/$outcomp/$filecomp";
  my $inp = &find_paper_file("context", "tex", $filecomp, "cont-sys.rme", $dftfile);

  return($F_ERROR) unless $inp; 

  open(FOO, "<$inp") || die "$0: open($inp) failed: $!";
  my @lines = <FOO>;
  close(FOO);

  my @idx;
  my $idxlast;
  my $endinputidx = -1;
  my $currentpaper;
  # read the lines and the last setuppapersize before the endinput wins
  for my $idx (0..$#lines) {
    my $l = $lines[$idx];
    if ($l =~ m/^[^%]*\\endinput/) {
      $endinputidx = $idx;
      last;
    }
    if ($l =~ m/^\s*\\setuppapersize\s*\[([^][]*)\].*$/) {
      if (defined($currentpaper) && $currentpaper ne $1) {
        tl_warn("TLPaper: inconsistent paper sizes in $inp! Please fix that.\n");
        return $F_ERROR;
      }
      $currentpaper = $1;
      $idxlast = $idx;
      push @idx, $idx;
      next;
    }
  }
  # if we haven't found a paper line, assume a4
  $currentpaper || ($currentpaper = "a4");
  # trying to find the right papersize
  #
  if (defined($newpaper)) {
    if ($newpaper eq "--list") {
      info("$currentpaper\n");
      for my $p (keys %pdftex_papersize) {
        info("$p\n") unless ($p eq $currentpaper);
      }
    } elsif ($newpaper eq "--returnlist") {
      my @ret = ();
      push @ret, "$currentpaper";
      for my $p (keys %pdftex_papersize) {
        push @ret, $p unless ($p eq $currentpaper);
      }
      return \@ret;
    } else {
      my $found = 0;
      for my $p (keys %pdftex_papersize) {
        if ($p eq $newpaper) {
          $found = 1;
          last;
        }
      }
      if ($found) {
        if (@idx) {
          for my $idx (@idx) {
            ddebug("TLPaper: before line: $lines[$idx]");
            ddebug("TLPaper: replacement: $newpaper\n");
            $lines[$idx] =~ s/setuppapersize\s*\[([^][]*)\]\[([^][]*)\]/setuppapersize[$newpaper][$newpaper]/;
            ddebug("TLPaper: after line : $lines[$idx]");
          }
        } else {
          my $addlines = "\\setuppapersize[$newpaper][$newpaper]\n";
          if (defined($endinputidx)) {
            $lines[$endinputidx] = $addlines . $lines[$endinputidx];
          } else {
            $lines[$#lines] = $addlines;
          }
        }
        info("$0: setting paper size for context to $newpaper.\n");
        mkdirhier(dirname($outfile));
        # if we create the outfile we have to call mktexlsr
        TeXLive::TLUtils::announce_execute_actions("files-changed")
          unless (-r $outfile);
        if (!open(TMP, ">$outfile")) {
          tlwarn("$0: Cannot write to $outfile: $!\n");
          tlwarn("Not setting paper size for context.\n");
          return($F_ERROR);
        }
        for (@lines) { print TMP; }
        close(TMP) || warn "$0: close(>$outfile) failed: $!";
        TeXLive::TLUtils::announce_execute_actions("regenerate-formats");
        # TODO should we return the value of announce_execute action?
        return($F_OK);
      } else {
        tlwarn("$0: Not a valid paper size for context: $newpaper\n");
        return($F_WARNING);
      }
    }
  } else {
    info("Current context paper size (from $inp): $currentpaper\n");
  }
  return($F_OK);
}

sub paper_context_old {
  my $outtree = shift;
  my $newpaper = shift;

  my ($outcomp, $filecomp) = setup_names("context");
  my $dftfile = $paper{'context'}{'default_file'};
  my $outfile = "$outtree/$outcomp/$filecomp";
  my $inp = &find_paper_file("context", "tex", $filecomp, "cont-sys.rme", $dftfile);
  return ($F_ERROR) unless $inp; 

  my @sizes = keys %pdftex_papersize;
  # take care here, the \\\\ are necessary in some places and not in 
  # some others because there is no intermediate evaluation
  return &paper_do_simple($inp, "context", '^\s*%?\s*\\\\setuppapersize\s*', 
            '^\s*%?\s*\\\\setuppapersize\s*\[([^][]*)\].*$',
            sub {
              my ($ll,$np) = @_;
              if ($ll =~ m/^\s*%?\s*\\setuppapersize\s*/) {
                return("\\setuppapersize[$np][$np]\n");
              } else {
                return($ll);
              }
            }, 
            $outfile, \@sizes, 'a4', '\setuppapersize[a4][a4]', $newpaper);
}


# psutils
# config file "psutils/paper.cfg" only contains two words:
#    p <papersize>
#
sub paper_psutils {
  my $outtree = shift;
  my $newpaper = shift;

  my ($outcomp, $filecomp) = setup_names("psutils");
  my $dftfile = $paper{'psutils'}{'default_file'};
  my $outfile = "$outtree/$outcomp/$filecomp";
  my $inp = &find_paper_file("psutils", "other text files", $filecomp, $dftfile);

  return ($F_ERROR) unless $inp; 
  

  my @sizes = keys %psutils_papersize;
  return &paper_do_simple($inp, "psutils", '^\s*p', '^\s*p\s+(\w+)\s*$', 
             sub {
               my ($ll,$np) = @_;
               $ll =~ s/^\s*p\s+(\w+)\s*$/p $np\n/;
               return($ll);
             },
             $outfile, \@sizes, '(undefined)', 'p a4', $newpaper);
}


# paper_do_simple does the work for single line config files
# (xdvi, dvipdfm, ...)
# arguments:
#   $inp, $prog, $firstre, $secondre, $bl, $outp, $paplist, $newpaper
# with
# $inp .. input file location
# $prog .. program name
# $firstre .. re that searches for paper lines
# $secondre .. re that extracts the paper from a paper line
# $bl .. block/sub taking two args, one paper line and the new paper, and
#        returns the line with the paper configured, only lines mathing
#        $firstre are shipped over to $bl
# $outp .. location of the output file
# $paplist .. ref to an array with the list of admissible paper sizes
# $defaultpaper .. default papersize (arbitrary string) if the $firstre is
#        not found in the config file
# $defaultline .. the line to be added at the bottom of the file if
#        no line has been found
# $newpaper .. --list, new paper, or undef
sub paper_do_simple {
  my ($inp, $prog, $firstre, $secondre, $bl, $outp, $paplist, $defaultpaper, $defaultline, $newpaper) = @_;

  debug("file used for $prog: $inp\n");

  open(FOO, "<$inp") or die("cannot open file $inp: $!");
  my @lines = <FOO>;
  close(FOO);

  my $currentpaper;
  my @paperlines = grep (m/$firstre/,@lines);
  if (!@paperlines) {
    $currentpaper = $defaultpaper;
  } else {
    if ($#paperlines > 0) {
      warn "Strange, more than one paper definition, using the first one in\n$inp\n";
    }
    $currentpaper = $paperlines[0];
    chomp($currentpaper);
    $currentpaper =~ s/$secondre/$1/;
  }

  # change value
  if (defined($newpaper)) {
    if ($newpaper eq "--list") {
      info("$currentpaper\n");
      for my $p (@$paplist) {
        info("$p\n") unless ($p eq $currentpaper);
      }
    } elsif ($newpaper eq "--returnlist") {
      my @ret = ();
      push @ret, $currentpaper;
      for my $p (@$paplist) {
        push @ret, $p unless ($p eq $currentpaper);
      }
      return(\@ret);
    } else {
      my $found = 0;
      for my $p (@$paplist) {
        if ($p eq $newpaper) {
          $found = 1;
          last;
        }
      }
      if ($found) {
        my @newlines;
        my $foundcfg = 0;
        for my $l (@lines) {
          if ($l =~ m/$firstre/) {
            push @newlines, &$bl($l, $newpaper);
            $foundcfg = 1;
          } else {
            push @newlines, $l;
          }
        }
        # what to do if no default line found???
        if (!$foundcfg) {
          push @newlines, &$bl($defaultline, $newpaper);
        }
        info("$0: setting paper size for $prog to $newpaper.\n");
        mkdirhier(dirname($outp));
        # if we create the outfile we have to call mktexlsr
        TeXLive::TLUtils::announce_execute_actions("files-changed")
          unless (-r $outp);
        if (!open(TMP, ">$outp")) {
          tlwarn("$0: Cannot write to $outp: $!\n");
          tlwarn("Not setting paper size for $prog.\n");
          return ($F_ERROR);
        }
        for (@newlines) { print TMP; }
        close(TMP) || warn "$0: close(>$outp) failed: $!";
        TeXLive::TLUtils::announce_execute_actions("regenerate-formats")
          if ($prog eq "context");
        return($F_OK);
      } else {
        tlwarn("$0: Not a valid paper size for $prog: $newpaper\n");
        return($F_WARNING);
      }
    }
  } else {
    # return the current value
    info("Current $prog paper size (from $inp): $currentpaper\n");
  }
  return($F_OK);
}

=back
=cut
1;

### Local Variables:
### perl-indent-level: 2
### tab-width: 2
### indent-tabs-mode: nil
### End:
# vim:set tabstop=2 expandtab: #
