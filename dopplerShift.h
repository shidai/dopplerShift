#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "fitsio.h"

long int stt_imjd ( char *name );
long int stt_smjd ( char *name );
double stt_offs ( char *name );

int get_nchan ( char *name );
int get_npol ( char *name );
int get_nphase ( char *name );
int get_subint ( char *name );

int read_prof ( char *name, int subint, double *profile, int phase );

int print_t2pred ( char *name );
double read_offs ( char *name, int subint);
int read_freq ( char *name, int subint, double *freq, int nchan );
int read_wts ( char *name, int subint, double *wts, int nchan );

double read_psrfreq ( char *name );
double readDm ( char *name );

int readNchn0 (char *name, int *nchn);
int readFreqSSB (char *name, double *freqSSB);
int correctFreqSSB (double *freqSSB, char *name, int subint, int nchan);
