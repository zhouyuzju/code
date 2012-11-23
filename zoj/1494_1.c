#include<stdio.h>
main()
{
	int n,u,d,sum,m;
	scanf("%d%d%d",&n,&u,&d);
	while(!(n==0&&u==0&&d==0))
	{
		for(sum=0,m=0;;)
		{
			m++;
			sum+=u;
			if(sum<n)
			{
				sum-=d;
				m++;
			}
			else
				break;
		}
		printf("%d\n",m);
		scanf("%d%d%d",&n,&u,&d);
	}
}