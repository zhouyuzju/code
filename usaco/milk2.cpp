/*
ID: jwjzy10201
PROG: milk2
LANG: C++
*/

#include<iostream>
#include<vector>
#include <fstream>
#include<algorithm>
using namespace std;

int main()
{
	int N;
	int continuous = 0;
	int idle = 0;
	ofstream fout ("milk2.out");
    	ifstream fin ("milk2.in");
	
	fin >> N;
	pair<int,int> periods[N];
	for(int i = 0;i < N;i++)
	{
		int a,b;
		fin >> a >> b;
		periods[i].first = a;
		periods[i].second =b;
	}
	sort(periods,periods + N);
//	for(int i = 0;i < N;i++)
//		cout << periods[i].first << "," << periods[i].second << endl;
	
	int f,s;
	f = periods[0].first;
	s = periods[0].second;
	continuous = s - f;
	for(int i = 1;i < N;i++)
	{
		if(s >= periods[i].first)
		{
			if(s < periods[i].second)
				s = periods[i].second;
		}
		else
		{
			int tmp = s - f;
			if(tmp > continuous)
				continuous = tmp;
			tmp = periods[i].first - s;
			if(tmp > idle)
				idle = tmp;
			
			f = periods[i].first;
			if(s < periods[i].second)
				s = periods[i].second;
		}
	}

	fout << continuous << " " << idle << endl;
	return 0;
}
