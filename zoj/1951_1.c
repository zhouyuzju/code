#include<stdio.h>
#include<math.h>
main()
{
	long n,i;
	int judge(long x);
	scanf("%ld",&n);
	while(n!=0)
	{
		for(i=3;i<=n/2;i++)
		if(judge(i)&&judge(n-i))
		{
			printf("%ld = %ld + %ld\n",n,i,n-i);
			break;
		}
		if(i>=n/2+1)
		printf("Goldbach's conjecture is wrong.\n");
		scanf("%ld",&n);
	}
}
int judge(long x)
{
	long i;
	long k;
	k=sqrt(x);
	for(i=2;i<=k;i++)
	if(x%i==0)
	break;
	if(i>=k+1)
	return 1;
	else
	return 0;
}