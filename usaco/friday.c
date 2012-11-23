/*
ID: jwjzy10201
LANG: C
TASK: friday
*/

#include<stdio.h>
#define MONTH 12
#define STARTYEAR 1900
#define STARTDAY 6

int isLeapYear(int year)
{
	if(year % 100 == 0 && year % 400 == 0)
		return 1;
	else if(year % 100 != 0 && year % 4 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int N;
	int counts[7] = {0};
	int dayMonth[13] = {31,28,31,30,31,30,31,31,30,31,30,31,29};
	int i,j;
	int tmpDays = STARTDAY;
	FILE *fin  = fopen ("friday.in", "r");
    	FILE *fout = fopen ("friday.out", "w");
	
	fscanf(fin,"%d",&N);
	
	for(i = 0;i < N;i++)
	{
		for(j = 0;j < MONTH;j++)
		{
			tmpDays %= 7;
			counts[tmpDays] ++;
			if(j == 1 && isLeapYear(STARTYEAR + i) == 1)
				tmpDays += dayMonth[12];
			else
				tmpDays += dayMonth[j];
		}
	}
	
	fprintf(fout,"%d ",counts[6]);
	for(i = 0;i < 6;i++)
	{
		fprintf(fout,"%d",counts[i]);
		if(i != 5)
			fprintf(fout," ");
	}
	fprintf(fout,"\n");	
	return 0;
}
