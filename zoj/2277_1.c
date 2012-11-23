#include<stdio.h>
#include<math.h>
main()
{
	long A,M,N;
	while(scanf("%ld",&N)!=EOF)
	{
		M=(long)(N*log10(N));
		A=pow(10,(N*log10(N)-M));
		printf("%ld\n",A);
	}
}