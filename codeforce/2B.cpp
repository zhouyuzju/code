/**
 *Do initialize when dp.
 *memset(array,init_value,num_of_bytes)
 *2013/3/14
 */

#include <iostream>
#include <cstring>
#include <cmath>
#define INF 1 << 30
using namespace std;
int main(){
	int n;
	cin >> n;
	int matrix[n + 1][n + 1],two[n + 1][n + 1],five[n + 1][n + 1],dptwo[n + 1][n + 1],dpfive[n + 1][n + 1];

	bool flag = false;
	int zerox,zeroy;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++){
			cin >> matrix[i][j];
			if(matrix[i][j] == 0){
				flag = true;
				zerox = i;
				zeroy = j;
			}
			int cout2 = 0,cout5 = 0,tmp = matrix[i][j];
			while(tmp > 0){
				if(tmp % 2 != 0 && tmp % 5 != 0)
					break;
				else if(tmp % 2 == 0){
					cout2++;
					tmp /= 2;
				}
				else if(tmp % 5 == 0){
					cout5++;
					tmp /= 5;
				}
			}
			two[i][j] = cout2;
			five[i][j] = cout5;
		}
	for(int i = 0;i <= n;i++){
		dptwo[0][i] = INF;
		dpfive[0][i] = INF;
		dptwo[i][0] = INF;
		dpfive[i][0] = INF;
	}
	dptwo[0][1] = 0;dpfive[0][1] = 0;

	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++){
			dptwo[i][j] = min(dptwo[i - 1][j],dptwo[i][j - 1]) + two[i][j];
			dpfive[i][j] = min(dpfive[i - 1][j],dpfive[i][j - 1]) + five[i][j];
		}
	/*for(int i = 0;i <= n;i++){
		for(int j = 0;j <= n;j++)
			cout << dptwo[i][j] << " ";
		cout << endl;
	}
	cout << dptwo[n][n] << "," << dpfive[n][n] << endl;*/
	string steps = "";
	int(*dp) [n + 1];
	int(*tp) [n + 1];
	if(dptwo[n][n] < dpfive[n][n]){
		dp = dptwo;
		tp = two;
	}
	else{
		dp = dpfive;
		tp = five;
	}
	if(!flag || dp[n][n] == 0){
		int i = n,j = n;
		while(true){
			if(i == 1 && j == 1)
				break;
			if(i != 1 && dp[i][j] == dp[i - 1][j] + tp[i][j]){  
            			i--;  
				steps += 'D';
        		}  
        		else{  
           	 		j--;  
				steps += 'R';
        		}  
		}
	}
	else{
		dp[n][n] = 1;
		int j = n;
		for(j = n;j > zeroy;j--) steps += 'R';
		int tmpJ = j;
		for(j = n;j > 1;j--) steps += 'D';
		for(j = tmpJ;j > 1;j--) steps += 'R';
	}
	cout << dp[n][n] << endl;
	for(int i = steps.length() - 1;i >= 0;i--)
		cout << steps[i];
	cout << endl;
}
