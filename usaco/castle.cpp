/*
ID: jwjzy10201
PROG: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;
int M,N;
int map[105][105] = {0};
bool flag[105][105] = {0};
bool wall[105][105][4] = {0};
int nRoom = 0,mCap = 0,mMax = 0,mX = -1,mY = -1;
int c[10010] = {0};
char dir = 'E';

void dfs(int i,int j,int &cap)
{
	flag[i][j] = true;
	map[i][j] = nRoom;
//	cout << i << "," << j << "," << map[i][j] << endl;
	if(!wall[i][j][0] && !flag[i][j - 1])
		dfs(i,j - 1,++cap);
	if(!wall[i][j][1] && !flag[i - 1][j])
		dfs(i - 1,j,++cap);
	if(!wall[i][j][2] && !flag[i][j + 1])
		dfs(i,j + 1,++cap);
	if(!wall[i][j][3] && !flag[i + 1][j])
		dfs(i + 1,j,++cap);
}

int main()
{
	ifstream fin ("castle.in");
	ofstream fout ("castle.out");
	fin >> M >> N;
	for(int i = 0;i < N;i++)
		for(int j = 0;j < M;j++)
		{
			int tmp;
			fin >> tmp;
			if(tmp & 1) wall[i][j][0] = 1;
		       	if(tmp & 2) wall[i][j][1] = 1;
		       	if(tmp & 4) wall[i][j][2] = 1;
		       	if(tmp & 8) wall[i][j][3] = 1;
			flag[i][j] = false;
		}
	for(int i = 0;i < N;i++)
		for(int j = 0;j < M;j++)
			if(!flag[i][j])
			{
				nRoom++;
				int cap = 1;			
				dfs(i,j,cap);
				if(cap > mCap)
					mCap = cap;
				c[nRoom] = cap;
			}
	fout << nRoom << endl << mCap << endl;
	for(int j = 0; j < M; j++) 
    		for(int i = N - 1; i >= 0; i--)
		{
			if(wall[i][j][1] && map[i][j] != map[i - 1][j])
			{
				int a = map[i][j],b = map[i - 1][j];
				if(c[a] + c[b] > mMax)
				{
					mMax = c[a] + c[b];
					mX = i + 1;
					mY = j + 1;
					dir = 'N';
				}
			}
			if(wall[i][j][2] && map[i][j] != map[i][j + 1])
			{
				int a = map[i][j],b = map[i][j + 1];
				if(c[a] + c[b] > mMax)
				{
					mMax = c[a] + c[b];
					mX = i + 1;
					mY = j + 1;
					dir = 'E';
				}

			}
		}
	fout << mMax << endl << mX << " " << mY << " " << dir << endl;
	return 0;
}
