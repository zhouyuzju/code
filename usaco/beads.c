/*
ID: jwjzy10201
LANG: C
TASK: beads
*/

#include<stdio.h>

int main()
{
	int N;
	char necklace[400];
	int i,j,k;
	int max = -1;
	int count = 0;
	char flag = 0;
	FILE *fin = fopen("beads.in","r");
	FILE *fout = fopen("beads.out","w");

	fscanf(fin,"%d",&N);
	fscanf(fin,"%s",necklace);
	
	for(i = 0,count=0;i < N;i++)
	{
		for(j = i,flag = 0;;j++)
		{
			if(j == N)
				j = 0;
			if(j == i && count != 0)
				break;
			if(necklace[j] == 'w')
				count ++;
			else if(flag == 0)
			{
				count ++;
				flag = necklace[j];
			}
			else if(flag == necklace[j])
				count++;
			else
				break;
		}
		
		for(k = i - 1,flag = 0;k != j - 1;k--)
		{
			if(k == -1)
				k = N - 1;
			if(necklace[k] == 'w')
				count++;
			else if(flag == 0)
			{
				count++;
				flag = necklace[k];
			}
			else if(flag == necklace[k])
				count++;
			else
				break;
		}
		if(max  < count)
			max = count;
		count = 0;
	}
		
	fprintf(fout,"%d\n",max);
	return 0;
}

