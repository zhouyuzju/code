/*
ID: jwjzy10201
LANG: C
TASK: ride
*/
#include <stdio.h>
main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    long proda, prodb;
    char comet[7];
    char group[7];
    int idxa,idxb;
    
    fscanf(fin,"%s%s",comet,group);

    for(idxa = 0,proda = 1;comet[idxa] != '\0';idxa++)
	    proda *= (int)(comet[idxa] - 'A' + 1);
    for(idxb = 0,prodb = 1;group[idxb] != '\0';idxb++)
	    prodb *= (int)(group[idxb] - 'A' + 1);
    if(proda % 47 == prodb % 47)
	    fprintf(fout,"GO\n");
    else
	    fprintf(fout,"STAY\n");
   

    exit (0);
}

