#include <iostream>
#include <string>
using namespace std;

const string zodiacs[12] = {"Pig","Dog","Rooster","Monkey","Ram","Horse","Snake","Dragon","Rabbit","Tiger","Ox","Rat"};

string Zodiac(int age)
{
	return zodiacs[(age % 12 + 7) % 12];
}


int main()
{
	int n;
	while(cin >> n)
	{
		for(int i = 0;i < n;i++)
		{	
			int age;
			cin >> age;
			cout << Zodiac(age) << endl;
		}
	}
	return 0;
}