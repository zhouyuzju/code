#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int num[N];
	int counts[10001] = {0};
	for(int i = 0;i < N;i++)
	{
		cin >> num[i];
		counts[num[i]]++;
	}
	bool found = false;
	for(int i = 0;i < N;i++)
	{
		if(counts[num[i]] == 1)
		{
			found = true;
			cout << num[i] << endl;
			break;
		}
	}
	if(!found)
		cout << "None" << endl;
	return 0;
}
