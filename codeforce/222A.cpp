#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> seq;	
	for(int i = 0;i < n;i++)
	{
		int tmp;
		cin >> tmp;
		seq.push_back(tmp);
	}
	bool flag = true;
	int cmp = seq[k - 1];
	for(int i = k;i < n;i++)
	{
		if(cmp != seq[i])
		{
			flag = false;
			break;
		}
	}
	if(flag)
	{
		int idx = -1;
		if(k > 1)
		{
			for(int i = k - 2;i >= 0;i--)
			{
				if(seq[i] != cmp)
				{
					idx = i;
					break;
				}
			}
		}
		cout << idx + 1 << endl;
	}
	else
		cout << "-1" << endl;	
	return 0;
}
