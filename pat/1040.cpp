#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	char line[1001];
	gets(line);
	int len = strlen(line);
	int max = 0;
	for(int i = 0;i < len;i++)
	{
		int j,k,tmp1,tmp2,tmp;
		for(j = i - 1,k = i + 1,tmp1 = 1;j >= 0 && k < len;j--,k++)
		{
			if(line[j] == line[k])
				tmp1 += 2;
			else
				break;
		}
		for(j = i,k = i + 1,tmp2 = 0;j >= 0 && k < len;j--,k++)
		{
			if(line[j] == line[k])
				tmp2 += 2;
			else
				break;
		}
		tmp = tmp1 > tmp2 ? tmp1 : tmp2;
		max = max > tmp ? max : tmp;

	}
	printf("%d\n",max);
	return 0;
}
