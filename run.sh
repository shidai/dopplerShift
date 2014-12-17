#!/bin/sh

gcc -lm -L/usr/local/lib/cfitsio -I/usr/include/cfitsio/ -lcfitsio dopplerShift.c readfits.c -o dopplerShift 
