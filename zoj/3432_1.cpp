#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	long n;
	while(cin >> n)
	{
		getchar();
		long pair = 2 * n - 1;
		char sockname[10];
		int rest[8] = {0};
		gets(sockname);
		for(int i = 0;i < 7;i++)
			rest[i] ^=sockname[i];
		for(long i = 0;i < pair - 1;i++)
		{	
			gets(sockname);
			for(int j = 0; j < 7;j++)
				rest[j] ^= sockname[j];
		}
		for(int i = 0;i < 7;i++)
			printf("%c",rest[i]);
		printf("\n");
	}
	return 0;
}