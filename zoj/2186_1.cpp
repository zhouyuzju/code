#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	while(cin >> a >> b >> c)
	{
		if(a < 168)
		{
			cout << "CRASH " << a << endl;
			continue;
		}
		else if(b < 168)
		{
			cout << "CRASH " << b << endl;
			continue;
		}
		else if(c < 168)
		{
			cout << "CRASH " << c << endl;
			continue;
		}
		else
			cout << "NO CRASH" << endl;
	}
	return 0;
}