#include<stdio.h>
main()
{
	int n,i,j;
	long d;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%ld",&d);
		for(j=0;d>0;j++)
		{
			if(d%2==1)
			{
				printf("%d",j);
				d/=2;
			    if(d>0)
					printf(" ");
			}
			else
				d/=2;
		}
		printf("\n");
	}
}