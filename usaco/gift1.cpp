/*
ID: jwjzy10201
PROG: gift1
LANG: C++
*/

#include<cstdio>
#include<iostream>
#include<fstream>
#include<map>
#include<string>

//#define fin cin
//#define fout cout
using namespace std;

int main()
{
	ofstream fout ("gift1.out");
   	ifstream fin ("gift1.in");
	
	int NP;
	fin >> NP;
	map<string,int> groups;
	string names[NP];
	for(int i = 0;i < NP;i++)
	{
		string tmpName;
		fin >> tmpName;
		groups[tmpName] = 0;
		names[i] = tmpName;
	}
	string givenorName;
	while(fin >> givenorName)
	{
		int money,num;
		fin >> money >> num;
		if(num != 0)
		{
			int per = money / num;
			int ret = money % num;
			for(int i = 0;i < num;i++)
			{
				string givingName;
				fin >> givingName;
				groups[givingName] += per;
			}
			groups[givenorName] -= (money - ret);
		}

	}

	for(int i = 0;i < NP;i++)
		fout << names[i] << " " << groups[names[i]] << endl; 

	return 0;
}
