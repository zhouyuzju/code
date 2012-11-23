#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		int p,pa,pb;
		for(int i = 0;i < n;i++)
		{
			cin >> p >> pa >> pb;
			if(p - pa < p - pb)
				cout << "A" << endl;
			else
				cout << "B" << endl;
		}
	}
	return 0;
}