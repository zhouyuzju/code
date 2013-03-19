/**
 * DP and pay attention to Nim
 * 2013/3/19
 */
#include <iostream>
#define MAX 301
using namespace std;
int n;
int a[MAX] = {0};
int dp[MAX][MAX] = {0};

int main(){
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	if(n == 1){
		if(a[1] != 0)
			cout << "BitLGM" << endl;
		else
			cout << "BitAryo" << endl;
	}
	else if(n == 3){			//Nim strategy
		int result = a[1] ^ a[2] ^ a[3];
		if(result)
			cout << "BitLGM" << endl;
		else
			cout << "BitAryo" << endl;
	}
	else{
		for(int i = 0;i <= 300;i++)
			for(int j = 0;j <= 300;j++)
				for(int k = 1;k <= 300;k++){
					if(i >= k && dp[i - k][j] == 0)
						dp[i][j] = 1;
					if(j >= k && dp[i][j - k] == 0)
						dp[i][j] = 1;
					if(i >= k && j >= k && dp[i - k][j - k] == 0)
						dp[i][j] = 1;
				}
		if(dp[a[1]][a[2]])
			cout << "BitLGM" << endl;
		else
			cout << "BitAryo" << endl; 
	}

	return 0;
}
