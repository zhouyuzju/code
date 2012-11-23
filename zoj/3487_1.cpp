#include<iostream>
using namespace std;

int main()
{
	int N;
	while(cin>>N)
	{
		int* digits = new int[N];
		for(int i = 0;i < N;i++)
			cin>>digits[i];
		for(int i = 0;i < N;i++)
		{
			if(digits[i] / 10 % 10 == 1)
				cout << digits[i] << "th" <<endl;
			else
			{
				if(digits[i] % 10 == 1)
					cout << digits[i] << "st" <<endl;
				else if(digits[i] % 10 == 2)
					cout << digits[i] << "nd" <<endl;
				else if(digits[i] % 10 == 3)
					cout << digits[i] << "rd" <<endl;
				else
					cout << digits[i] << "th" <<endl;
			}
		}
		delete digits;
	}
}