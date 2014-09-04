use 5.010;
use strict;
use warnings;

my $str = "HeLlo";

say lc $str;
say uc $str;
say length $str;

$str = "The black cat jumped from the green tree";

say index $str, "cat";
