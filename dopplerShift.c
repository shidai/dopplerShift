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
	int i;

	//////////////////////////////////////////////////////
	char fname[128];   // name of freqSSB file
	char dname[128];   // name of data file

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
	}

	// read freqSSB
	int nchn0;
	readNchn0 (fname, &nchn0);

	double freqSSB[nchn0];
	readFreqSSB (fname, freqSSB);

	// name of different extension of data files
	char name_data[50]; 
	char data[] = "[SUBINT]";
	strcpy(name_data, dname);
	strcat(name_data, data);

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

	if (nchn == nchn0)
	{
		for (i = 1; i <= nsub; i++)
		{
			correctFreqSSB (freqSSB, name_data, i, nchn);
		}
	}
	else
	{
		printf ("nchn != nchn0\n");
	}

	return 0;
}
