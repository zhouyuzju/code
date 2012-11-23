#include <iostream>
using namespace std;

int main()
{
	int n;
	while(cin >> n)
	{
		int ay,am,ad,by,bm,bd;
		for(int i = 0;i < n;i++)
		{
			cin >> ay >> am >> ad >> by >> bm >> bd;
			if(ay < by)
				cout << "javaman" << endl;
			else if(ay > by)
				cout << "cpcs" << endl;
			else
			{
				if(am < bm)
					cout << "javaman" << endl;
				else if(am > bm)
					cout << "cpcs" << endl;
				else
				{
					if(ad < bd)
						cout << "javaman" << endl;
					else if(ad > bd)
						cout << "cpcs" << endl;
					else
						cout << "same" << endl;
				}
			}
		}
	}
	return 0;
}