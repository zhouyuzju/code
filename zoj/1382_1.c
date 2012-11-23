#include<stdio.h>
main()
{
	int d,n,i,j;
	scanf("%d",&d);
	for(i=1;i<=d;i++)
	{
		scanf("%d",&n);
		for(j=0;n%2==0;j++)
			n/=2;
		printf("%d %d\n",n,j);
	}
}
