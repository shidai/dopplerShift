// correct the doppler shift because of the motion of the Earth around the Sun
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "dopplerShift.h"
//#include "T2toolkit.h"
//#include "tempo2pred.h"

int main (int argc, char *argv[])
{
	int i,j;

	//////////////////////////////////////////////////////
	char fname[128];   // name of freqSSB file
	char dname[128];   // name of data file
	double cfreq;  // central frequency at SSB

	for (i=0;i<argc;i++)
	{
		if (strcmp(argv[i],"-f") == 0)
		{
			strcpy(fname,argv[++i]);
		}
		else if (strcmp(argv[i],"-d")==0)
		{
			strcpy(dname,argv[++i]);
		}
		else if (strcmp(argv[i],"-c")==0)
		{
			cfreq = atof(argv[++i]);
		}
	}

	// name of different extension of data files
	char name_data[50]; 
	char data[] = "[SUBINT]";
	strcpy(name_data, dname);
	strcat(name_data, data);

	correctCfreq(dname,cfreq);
	// get the data file name

	// name of different extension
	////////////////////////////////////////////////
	//long int imjd, smjd;
	//double offs;
	//int nphase;
	int nchn;
	int nsub;
	//int npol;
	
	//imjd = stt_imjd(fname);
	//smjd = stt_smjd(fname);
	//offs = stt_offs(fname);

	nchn = get_nchan(name_data);	
	//npol = get_npol(name_data);	
	nsub = get_subint(name_data);	
	//nphase = get_nphase(name_data);	

	//printf ("%d\n", nchn);
	////////////////////////////////////////////////

	// read freqSSB correction
	int nchn0;
	readNchn0 (fname, &nchn0);

	double freqSSB[nchn0];
	double freq[nchn];
	read_freq (name_data, 1, freq, nchn);
	readFreqSSB (fname, freqSSB);
	////////////////////////////////////////////////
	
	//double freqSSB[nchn];
	//double freqC;
	//readFreqSSB (fname, &freqC);

	if (nchn0 == nchn)
	{
		for (i = 1; i <= nsub; i++)
		{
			//read_freq (name_data, i, freqSSB, nchn);
			//for (j = 0; j < nchn; j++)
			//{
			//	freqSSB[j] = freqSSB[j]*(freqC);
			//}
			correctFreqSSB (freqSSB, name_data, i, nchn);
		}
	}
	else
	{
		printf ("nchn0 != nchn\n");
	}

	return 0;
}
