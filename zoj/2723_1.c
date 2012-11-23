#include<stdio.h>
#include<math.h>
main()
{
	long n,i;
	int isprime(long x);
	while(scanf("%ld",&n)!=EOF)
	{
		for(i=2;i<=sqrt(n);i++)
		if(n%i==0&&isprime(i)&&isprime(n/i))
			break;
		if(i>sqrt(n))
		printf("No\n");
		else
		printf("Yes\n");
	}
}
int isprime(long x)
{
	long i;
	for(i=2;i<=sqrt(x);i++)
	if(x%i==0)
	break;
	if(i>sqrt(x))
	return 1;
	else
	return 0;
}