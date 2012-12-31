/*
ID: jwjzy10201
PROG: lamps
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;
ifstream fin("lamps.in");
ofstream fout("lamps.out");
int C0[1] = {63};	//0
int C1[4] = {0,21,27,42};	//1,2,3,4
int C2[7] = {0,14,31,36,42,49,63};	//0,1,2,3,14,24,34
int C3[8] = {0,14,21,27,36,42,49,63};	//0,1,2,3,4,14,24,34
int lights[8][6] = {	{0,0,0,0,0,0},
			{0,0,1,1,1,0},
                       	{0,1,0,1,0,1},
                       	{0,1,1,0,1,1},
                       	{1,0,0,1,0,0},
                       	{1,0,1,0,1,0},
                       	{1,1,0,0,0,1},
                       	{1,1,1,1,1,1}};
void print(int n[],int N)
{
	int count = 0;
	while(count < N)
	{
		fout << n[count % 6];
		count++;
	}
	fout << endl;
}
int main()
{
	int N,C,x;
	map<int,int*> mapping;
	for(int i = 0;i < 8;i++)
		mapping[C3[i]] = lights[i];
	fin >> N >> C;
	vector<int> ON,OFF;
	while((fin >> x) && x != -1)
		ON.push_back(x);
	while((fin >> x) && x != -1)
		OFF.push_back(x);
	bool count = false;
	int * tmpC;
	int K = -1;
	if(C == 0)
	{
		K = 1;
		tmpC = C0;
	}
	else if(C == 1)
	{
		K = 4;
		tmpC = C1;
	}
	else if(C == 2)
	{
		K = 7;
		tmpC = C2;
	}
	else
	{
		K = 8;
		tmpC = C3;
	}
	for(int i = 0;i < K;i++)
	{
		bool result = true;
		for(int j = 0;j < ON.size();j++)
			if(mapping[tmpC[i]][(ON[j] - 1) % 6] != 1)
			{
				result = false;
				break;
			}
		for(int j = 0;j < OFF.size();j++)
			if(mapping[tmpC[i]][(OFF[j] - 1) % 6] != 0)
			{
				result = false;
				break;
			}
		if(result)
		{
			print(mapping[tmpC[i]],N);
			count = true;
		}
	}

	if(!count)
		fout << "IMPOSSIBLE" << endl;
	return 0;
}
