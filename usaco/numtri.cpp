/*
ID: jwjzy10201
PROG: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;
#define MAX 1001
int input[MAX][MAX] = {0};
int result[MAX][MAX] = {0};
ofstream fout ("numtri.out");
ifstream fin ("numtri.in");


int max(int a,int b)
{
	if(a > b)
		return a;
	else
		return b;
}

int main()
{
	int R;
	fin >> R;
	for(int i = 1;i <= R;i++)
		for(int j = 1;j <= i;j++)
			fin >> input[i][j];
	for(int i = R;i >= 1;i--)
		for(int j = 1;j <= i;j++)
			result[i][j] = input[i][j] + max(result[i + 1][j],result[i + 1][j + 1]);
	fout << result[1][1] << endl;
	
	return 0;
}
