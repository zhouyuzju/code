/*
ID: jwjzy10201
PROG: milk
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	ofstream fout ("milk.out");
    	ifstream fin ("milk.in");
	int N,M;
	fin >> N >> M;
	pair<int,int> farms[M];
	for(int i = 0;i < M;i++)
	{
		int per,total;
		fin >> per >> total;
		farms[i].first = per;
		farms[i].second = total;
	}	
	sort(farms,farms + M);
	int cost = 0;
	for(int i = 0;i < M && N > 0;i++)
	{
		int per = farms[i].first;
		int amount = farms[i].second;
		if(amount <= N)
		{
			cost += (per * amount);
			N -= amount;
		}
		else
		{
			cost += (per * N);
			N = 0;
		}
	}
	fout << cost << endl;
	return 0;
}
