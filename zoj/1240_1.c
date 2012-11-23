#include<stdio.h>
main()
{
	int i,d,j,k;
	char b[50];
	char c;
	scanf("%d",&d);
	getchar();
	for(i=1;i<=d;i++)
	{
		
		for(j=0;(c=getchar())!='\n';j++)
		{
			if(c==90)
			b[j]=65;
			else
			b[j]=c+1;
		}
		printf("String #%d\n",i);
		for(k=0;k<j;k++)
		printf("%c",b[k]);
		printf("\n\n");
	}
}