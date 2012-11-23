#include<stdio.h>
main()
{
	float c=1.0;
	int d;
	int f(float c);
	while(scanf("%f",&c)&&c!=0.00)
	{
		d=f(c);
		printf("%d card(s)\n",d);
	}
}
int f(float c)
{
	int i;
	float sum,tmp;
	sum=0.00;
	tmp=0.00;
	for(i=2;sum<c;i++)
	{
		tmp=1.0/i;
		sum+=tmp;
	}
	return i-2;
}