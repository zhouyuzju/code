#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define MAX 1000
#define N 26
int main()
{
	int k;
	char orig[MAX] = {'\0'};
	int count[N] = {0};
	string result = "";
	scanf("%d",&k);
	scanf("%s",orig);

	int len = strlen(orig);
	for(int i = 0;i < len;i++)
		count[orig[i] - 'a']++;
	bool flag = true;
	for(int i = 0;i < k;i++)
	{
		for(int j = 0;j < N;j++)
		{
			if(count[j] % k != 0)
			{
				flag = false;
				break;
			}	
			else if(count[j] != 0)
			{
				int charNum = count[j] / k;
				for(int xi = 0;xi < charNum;xi++)
					result += (j + 'a');
			}
		}
		if(!flag)
			break;
	}
	if(!flag)
		cout << -1 << endl;
	else
		cout << result << endl;

	return 0;
}
