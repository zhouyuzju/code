/*
ID: jwjzy10201
PROG: transform
LANG: C++
*/

#include<iostream>
#include <fstream>
using namespace std;

bool equal(char** orig,char** dest,int N)
{
	bool flag = true;
	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
		{
			if(orig[i][j] != dest[i][j])
				flag = false;
		}
	return flag;
}

char** rotation(char** orig,int N)
{
	char** result = new char*[N];
	for(int i = 0;i < N;i++)
		result[i] = new char[N];

	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
		{
			result[j][N - 1 - i] = orig[i][j];
		}
	return result;
}

char** reflection(char** orig,int N)
{
	char** result = new char*[N];
	for(int i = 0;i < N;i++)
		result[i] = new char[N];

	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
		{
			result[i][N - 1 - j] = orig[i][j];
		}
	return result;
}

int transform(char** orig,char** dest,int N)
{
	char** tmp1 = rotation(orig,N);
	if(equal(tmp1,dest,N))
		return 1;
	char** tmp2 = rotation(tmp1,N);
	if(equal(tmp2,dest,N))
		return 2;
	char** tmp3 = rotation(tmp2,N);
	if(equal(tmp3,dest,N))
		return 3;
	char** ref = reflection(orig,N);
	if(equal(ref,dest,N))
		return 4;
	char** tmpref1 = rotation(ref,N);
	if(equal(tmpref1,dest,N))
		return 5;
	char** tmpref2 = rotation(tmpref1,N);
	if(equal(tmpref2,dest,N))
		return 5;
	char** tmpref3 = rotation(tmpref2,N);
	if(equal(tmpref3,dest,N))
		return 5;
	
	if(equal(orig,dest,N))
		return 6;
	
	return 7;
}

int main()
{
	int N;
	ofstream fout ("transform.out");
    	ifstream fin ("transform.in");
	
	fin >> N;
	char** orig = new char*[N];
	for(int i = 0;i < N;i++)
		orig[i] = new char[N];
	char** dest = new char*[N];
	for(int i = 0;i < N;i++)
		dest[i] = new char[N];

	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
			fin >> orig[i][j];
	
	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
			fin >> dest[i][j];

	fout << transform(orig,dest,N) << endl;
	return 0;

}
