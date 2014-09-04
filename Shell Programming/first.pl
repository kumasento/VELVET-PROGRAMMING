#!/usr/bin/perl

use 5.010;
use strict;
use warnings;

@one_to_ten = (1 .. 10);

print "@one_to_ten\n";

for $i (@one_to_ten, 15, 20 .. 25) {
    print "$i\n";
}

my $greeting = "Welcome to Perl!\n";
print $greeting;

substr($greeting, 0,0) = 'Hello. ';

my @words = split(//, $greeting, 2);
my $join_words = join('||', @words);
print @words;
print $join_words;

open my $shell_file, 'Colorfull.sh' or die "I couldn't get at Colorfull.sh: $!";

my $title = <$shell_file>;
print $title;

#print while <$shell_file>;
close $shell_file;

sub multiply {
    my (@ops) = @_;
    return $ops[0] * $ops[1];
}

for my $i (1 .. 10) {
    print "$i squared is ", multiply($i, $i), "\n";
}



