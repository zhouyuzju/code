/*
ID: jwjzy10201
PROG: frac1
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;
int N;
ifstream fin ("frac1.in");
ofstream fout ("frac1.out");
void rec(pair<int,int> a,pair<int,int> b)
{
	int numerator = a.first + b.first;
	int denominator = a.second + b.second;
	if(denominator > N)
	{
		fout << a.first << "/" << a.second << endl;
		return;
	}
	rec(a,make_pair(numerator,denominator));
	rec(make_pair(numerator,denominator),b);
}

int main()
{
	fin >> N;
	rec(make_pair(0,1),make_pair(1,1));
	fout << "1/1" << endl;	
	return 0;
}
