#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
int main(){
	char str[10002];
	while(scanf("%s",str) != EOF){
		vector<int> c(256,0);
		int maxVal = 0;
		int cnt = 0, s = 1;
		for(int i = 0;str[i] != '\0';i++){
			if(c[str[i]] < s)
				cnt++;
			else{
				cnt = i + 1 - c[str[i]];
				s = c[str[i]];
			}
			c[str[i]] = i + 1;
			maxVal = max(maxVal,cnt);
		}
		printf("%d\n",maxVal);
	}
	return 0;
}
