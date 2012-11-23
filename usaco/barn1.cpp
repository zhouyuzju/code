/*
ID: jwjzy10201
PROG: barn1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ofstream fout ("barn1.out");
    	ifstream fin ("barn1.in");
	int M,S,C;
	fin >> M >> S >> C;
	int occupy[C];
	for(int i = 0;i < C;i++)
	{
		fin >> occupy[i];
	}
	sort(occupy,occupy + C);
	int distance[C - 1];
	bool flag[C - 1];
	for(int i = 0;i < C - 1;i++)
	{
		distance[i] = occupy[i + 1] - occupy[i];
		flag[i] = false;
	}
	int cutNum = M - 1 > C - 1 ? C - 1 : M - 1;
	int cut[cutNum];
	int max = 0;
	int index = -1;
	for(int i = 0;i < cutNum;i++)
	{
		for(int j = 0;j < C - 1;j++)
		{
			if(max < distance[j] && !flag[j])
			{
				max = distance[j];
				index = j;
			}
		}
		cut[i] = max;
		flag[index] = true;
		index = -1;
		max = 0;

	}
	
	int cost = occupy[C - 1] - occupy[0] + 1;
	for(int i = 0;i < cutNum;i++)
		cost -= (cut[i] - 1);
	fout << cost << endl;
	
	return 0;
}
