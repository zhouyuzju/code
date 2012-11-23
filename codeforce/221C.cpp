#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	long long array[n];
	long long cmp[n];
	for(int i = 0;i < n;i++)
	{
		cin >> array[i];
		cmp[i] = array[i];
	}
	sort(array,array + n);
	int count = 0;
	for(int i = 0;i < n;i++)
	{
		if(cmp[i] != array[i])
			count++;
		if(count > 2)
			break;
	}
	if(count > 2)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;
}
