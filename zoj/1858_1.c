#include<stdio.h>
#include<string.h>
main()
{
	int i,j;
	int k[21];
	char s[21];
	int change(char c);
	while(gets(s))
	{
		for(i=0,j=0;s[i]!='\0';i++,j++)
		k[j]=change(s[i]);
		k[j]=-1;
		for(j=0;k[j]!=-1;j++)
		{
			if(j>0&&k[j]!=0&&k[j]!=k[j-1])
			printf("%d",k[j]);
			if(j==0&&k[j]!=0)
			printf("%d",k[j]);
		}
		printf("\n");
	}
}
int change(char c)
{
	int i;
	switch(c)
	{
	case 'B':
	case 'F':
	case 'P':
	case 'V':i=1;break;
	case 'C':
	case 'G':
	case 'J':
	case 'K':
	case 'Q':
	case 'S': 
	case 'X':
	case 'Z':i=2; break;
	case 'D':
	case 'T':i=3; break;
	case 'L':i=4; break;
	case 'M':
	case 'N':i=5; break;
	case 'R':i=6; break;
	default:i=0;break;
	}
	return i;
}