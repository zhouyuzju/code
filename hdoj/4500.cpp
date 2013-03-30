#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n,m;
	int sit[21][21];
	while(true){
	cin >> n >> m;
	if(n == 0 && m == 0)
		break;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> sit[i][j];
	int si,sj,point = -100000; 
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			int tmpPoint = 0;
			int flag = 1;
			if(i - 1 >= 0){
				if(sit[i][j] * sit[i - 1][j] < 0)
					flag = 1;
				else
					flag = -1;
				tmpPoint += flag * abs(sit[i - 1][j]);
			}
			if(i + 1 < n){
				if(sit[i][j] * sit[i + 1][j] < 0)
					flag = 1;
				else
					flag = -1;

				tmpPoint += flag * abs(sit[i + 1][j]);
			}
			if(j - 1 >= 0){
				if(sit[i][j] * sit[i][j - 1] < 0)
					flag = 1;
				else
					flag = -1;

				tmpPoint += flag * abs(sit[i][j - 1]);
			}
			if(j + 1 < m){
				if(sit[i][j] * sit[i][j + 1] < 0)
					flag = 1;
				else
					flag = -1;

				tmpPoint += flag * abs(sit[i][j + 1]);
			}
			//cout << i << "," << j << "," << tmpPoint << endl;
			if(point < tmpPoint){
				si = i,sj = j,point = tmpPoint;
			}
			else if(point == tmpPoint){
				if(si > i){
					si = i;
					sj = j;
				}
				else if(si == i){
					si = i;
					sj = j;
				}
			}
		}
	cout << si + 1 << " " << sj + 1<< " " << point << endl;
	}
	return 0;
}
