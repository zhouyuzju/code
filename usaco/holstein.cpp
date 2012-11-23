/*
ID: jwjzy10201
PROG: holstein
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#define MAX 16
using namespace std;

int allones(int n)
{
	int result = 0;
	while(n > 0)
	{
		n &= (n - 1);
		result++;
	}
	return result;
}



int main()
{
	ifstream fin ("holstein.in");
	ofstream fout ("holstein.out");
	int V,G;
	fin >> V;
	int min[V];
	for(int i = 0;i < V;i++)
		fin >> min[i];
	fin >> G;
	int feeds[G][V];
	for(int i = 0;i < G;i++)
		for(int j = 0;j < V;j++)
			fin >> feeds[i][j];
	int num = MAX;
	int pick = 0;
	for(int i = 1;i < pow(2,G);i++)
	{
		int tmp[V];
		for(int j = 0;j < V;j++)
			tmp[j] = 0;
		for(int j = 0;j < G;j++)
			if(i & int(pow(2,j)))
			{
				for(int k = 0;k < V;k++)
				       tmp[k] += feeds[j][k];
			}
		bool enough = true;
		for(int j = 0;j < V;j++)
			if(tmp[j] < min[j])
			{
				enough = false;
				break;
			}

		if(enough && num > allones(i))
		{
			num = allones(i);
			pick = i;
		}
	}	
	fout << num;
	for(int i = 0;i < G;i++)
		if(pick & int(pow(2,i)))	
			fout << " " << i + 1;
	fout << endl;
	return 0;
}
