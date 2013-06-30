/**
 * DFS & memorize problem. Just memorize the jump state of x and the crossponding value
 * 2013/3/19
 */
#include <iostream>
#include <set>
#define MAX 200001
using namespace std;
int a[MAX] = {0},state[MAX][2] = {0};
long long m[MAX][2] = {0};
int n;

long long dfs(int x,int f,int i){
	long long result;
	//cout << x << "," << f << endl;
	if(x <= 0 || x > n)
		return 0;		//exit 0
	if(state[x][f] == i || state[x][f] == -1)	//dead loop or may loop in future according to early state exit -1
		return -1;
	if(state[x][f])			//cache the value of current state
		return m[x][f];
	state[x][f] = i;		//mark the current state
	if(f)
		result = dfs(x - a[x], 1 - f,i);
	else
		result = dfs(x + a[x], 1 - f,i);
	if(result == -1)
		return state[x][f] = -1;
	else
		return m[x][f] = result + a[x];
}

int main(){
	cin >> n;
	for(int i = 2;i <= n;i++)
		cin >> a[i];
	for(int i = 1;i < n;i++){
		a[1] = i, state[1][0] = 0;		//init
		cout << dfs(1,0,i) << endl;
	}
	return 0;
}
