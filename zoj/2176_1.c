#include<stdio.h>
main()
{
	int n,i;
	int speed[11],hour[11];
	long distance;
	scanf("%d",&n);
	while(n!=-1)
	{
		speed[0]=0;
		hour[0]=0;
		for(i=1;i<=n;i++)
		scanf("%d%d",&speed[i],&hour[i]);
		for(i=1,distance=0;i<=n;i++)
		distance+=speed[i]*(hour[i]-hour[i-1]);
		printf("%ld miles\n",distance);
		scanf("%d",&n);
	}
}