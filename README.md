# Running with Scissors

Executes programs as regular user but with extra capabilities.

Typical usage:

$ sudo rws -c CAP_NET_ADMIN iw monitor0 set channel 5

## What about setcap(8)?

This grants capabilities to an executable. RWS grants it to a process.

## What about capsh(1)?

I'm sure you can do exactly what RWS does with capsh, but it was
faster for me to write this tool than to figure out how.
