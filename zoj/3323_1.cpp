#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		getchar();
		char pwd[21] = {0};
		for(int i = 0;i < n;i++)
		{
			gets(pwd);
			char result[21] = {0};
			for(int j = 0,k = 0;pwd[j] != 0;j++)
			{
				if(pwd[j] > 57)
					result[k++] = pwd[j];
			}
			puts(result);
		}
	}
	return 0;
}