#include <cstdio>
using namespace std;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	char line[n + 1];
	scanf("%s",line);
	if(k == 2)
	{
		char tmp1[n],tmp2[n];
		for(int i = 0;i < n;i++)
		{
			tmp1[i] = (i % 2 == 0 ? 'A' : 'B');
			tmp2[i] = (i % 2 == 0 ? 'B' : 'A');
		}
		tmp1[n] = '\0';
		tmp2[n] = '\0';
		int dis1 = 0;
		int dis2 = 0;
		for(int i = 0;i < n;i++)
		{
			if(tmp1[i] != line[i])
				dis1++;
			if(tmp2[i] != line[i])
				dis2++;
		}
		if(dis1 >= dis2)
			printf("%d\n%s",dis2,tmp2);
		else 
			printf("%d\n%s",dis1,tmp1);
	}
	else
	{
		int total = 0;
		for(int i = 0;i < n;)
		{
			int len = 1;
			for(int j = i + 1;j < n;j++)
			{
				if(line[i] == line[j])
					len++;
				else
					break;
			}
			total += len / 2;
			if(len > 1)
			{
				char c;
				for(int k = 0;k < 25;k++)
				{
					if('A' + k != line[i] && 'A' + k != line[i + len])
					{
						c = 'A' + k;
						break;
					}
				}
				for(int k = 0;k < len;k++)
				{
					if(k % 2 == 1)
						line[i + k] = c;
				}
			}
			i += len;
		}
		printf("%d\n%s",total,line);
	}

	return 0;
}
