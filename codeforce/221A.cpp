#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int array[n];
	for(int i = 1;i < n;i++)
		array[i] = i;
	array[0] = n;
	for(int i = 0;i < n;i++)
	{
		if(i != n - 1)
			cout << array[i] << " ";
		else
			cout << array[i] << endl;
	}
	return 0;
}
