#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

bool inGrid(int x,int y)
{
	if(x >= 0 && x < 8 && y >= 0 && y < 8)
		return true;
	else
		return false;
}

int main()
{
	string a,b;
	while(cin >> a >> b)
	{
		pair<int,int> pointa(a[0] - 'a',a[1] - '1');
		pair<int,int> pointb(b[0] - 'a',b[1] - '1');
		int allStep[8][8];
		
		for(int i = 0; i < 8;i++)
			for(int j = 0;j < 8;j++)
				allStep[i][j] = 65534;

		allStep[pointa.first][pointa.second] = 0;
		queue<pair<int,int> > aqueue;
		aqueue.push(pointa);
		while(aqueue.size() > 0)
		{
			pair<int,int> apoint = aqueue.front();
			aqueue.pop();
			int x = apoint.first;
			int y = apoint.second;
			//cout << "point:" << x << "," << y << ",step:" << allStep[x][y] << endl;
			if(apoint.first == pointb.first && apoint.second == pointb.second)
				break;
			else
			{
				int nextStep = allStep[x][y] + 1;
				if(inGrid(x - 2,y - 1))
				{
					aqueue.push(pair<int,int>(x - 2,y - 1));
					allStep[x - 2][y - 1] = nextStep;		
				}	
				if(inGrid(x - 2,y + 1))
				{
					aqueue.push(pair<int,int>(x - 2,y + 1));
					allStep[x - 2][y + 1] = nextStep;		
				}	
				if(inGrid(x + 2,y - 1))
				{
					aqueue.push(pair<int,int>(x + 2,y - 1));
					allStep[x + 2][y - 1] = nextStep;		
				}	
				if(inGrid(x + 2,y + 1))
				{
					aqueue.push(pair<int,int>(x + 2,y + 1));
					allStep[x + 2][y + 1] = nextStep;		
				}	
				if(inGrid(x - 1,y - 2))
				{
					aqueue.push(pair<int,int>(x - 1,y - 2));
					allStep[x - 1][y - 2] = nextStep;		
				}	
				if(inGrid(x - 1,y + 2))
				{
					aqueue.push(pair<int,int>(x - 1,y + 2));
					allStep[x - 1][y + 2] = nextStep;		
				}	
				if(inGrid(x + 1,y - 2))
				{
					aqueue.push(pair<int,int>(x + 1,y - 2));
					allStep[x + 1][y - 2] = nextStep;		
				}	
				if(inGrid(x + 1,y + 2))
				{
					aqueue.push(pair<int,int>(x + 1,y + 2));
					allStep[x + 1][y + 2] = nextStep;		
				}
			}
		}
		cout << "To get from " << a << " to " << b << " takes " << allStep[pointb.first][pointb.second] << " knight moves." << endl;
	}
	return 0;
}
