/*
ID: jwjzy10201
PROG: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;
#define MAX 21
int A,B,C;
bool flag[MAX][MAX] = {false};
bool cap[MAX] = {false};
ofstream fout ("milk3.out");
ifstream fin ("milk3.in");

void dfs(int a,int b)
{
	//cout << "a: " << a << ",b: " << b << endl;
	int c = C - b - a;
	if(flag[a][b])
		return;
	if(a == 0)
		cap[c] = true;
	flag[a][b] = true;
	//case: a-->b
	if(a + b > B)
		dfs(a + b - B,B);
	else
		dfs(0,a + b);
	//case: a-->c
	dfs(0,b);
	//case: b-->a
	if(a + b > A)
		dfs(A,a + b - A);
	else
		dfs(a + b,0);
	//case: b-->c
	dfs(a,0);
	//case: c-->a
	if(a + c > A)
		dfs(A,b);
	else
		dfs(a + c,b);
	//case: c-->b
	if(b + c > B)
		dfs(a,B);
	else
		dfs(a,b + c);
	return;
}

int main()
{
	fin >> A >> B >> C;
	dfs(0,0);
	bool f = false;
	for(int i = 0;i < MAX;i++)
	{
		if(cap[i])
		{
			if(f)
				fout << " ";
			fout << i;
			f = true;
		}
	}
	fout << endl;
	return 0;
}
