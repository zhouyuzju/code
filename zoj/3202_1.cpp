#include <iostream>
using namespace std;

int main()
{
	int T;
	while(cin >> T)
	{
		int N;
		for(int i = 0;i < T;i++)
		{
			cin >> N;
			int p;
			int index = -1;
			int first = -1;
			int second = -2;
			for(int j = 0;j < N;j++)
			{
				cin >> p;
				if(p > first)
				{
					second = first;
					first = p;
					index = j + 1;
				}
				else if( p < first && p > second)
				{
					second = p;
				}
			}
			cout << index << " " << second << endl;
		}
	}
	return 0;
}