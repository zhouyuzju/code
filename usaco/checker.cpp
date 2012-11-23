/*
ID: jwjzy10201
PROG: checker
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;
ofstream fout ("checker.out");
ifstream fin ("checker.in");
int upperlim,sum,N;
int a[13] = {0};

void dfs(int row,int ld,int rd,int depth)
{
	int pos,p;
	if(row != upperlim)
	{
		pos = upperlim & ~ (row | ld | rd);
		while(pos)
		{
			p = pos & -pos;
			pos -= p;
			
			if(sum < 3)
			{
				int l = 1;
				int k = p;
				while (k >>= 1) 
					++l;
				a[depth] = l;
			}

			dfs(row + p,(ld + p) << 1,(rd + p) >> 1,depth + 1);
		}
	}
	else
	{
		sum++;
		if(sum <= 3)
		{
			for(int i = 0;i < N;i++)
			{
				fout << a[i];
				if(i != N - 1)
					fout << " ";
				else
					fout << endl;
			}
		}
	}
}

int main()
{
	fin >> N;
	sum = 0;
	upperlim = (int)pow(2.0,N) - 1;
	dfs(0,0,0,0);
	fout << sum << endl;
	return 0;
}
