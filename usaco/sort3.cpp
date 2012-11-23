/*
ID: jwjzy10201
PROG: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	ifstream fin ("sort3.in");
	ofstream fout ("sort3.out");
	int N;
	fin >> N;
	int a[N];
	int b[N];
	int dif[4][4];
	for(int i = 0;i < N;i++)
	{
		fin >> a[i];
		b[i] = a[i];
	}

	memset(dif,0,sizeof(dif));
	sort(b,b + N);
	int count = 0;
	int ans = 0;
	for(int i = 0;i < N;i++)
		if(a[i] != b[i])
		{
			dif[b[i]][a[i]]++;
			count++;
		}
	for(int i = 1;i < 4;i++)
		for(int j = i + 1;j < 4;j++)
	{
			int com = min(dif[i][j],dif[j][i]);
			dif[i][j] -= com;
			dif[j][i] -= com;
			count -= 2 * com;
			ans += com;
		}
	ans += count / 3 * 2;
	fout << ans << endl;
	return 0;
}
