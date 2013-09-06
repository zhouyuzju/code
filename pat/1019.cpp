#include <iostream>
#include <cstdio>
#include <vector>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int N,B;
	scanf("%d%d",&N,&B);
	vector<int> digit;
	while(N > 0){
		digit.push_back(N % B);
		N /= B;
	}
	bool isP = true;
	int i = 0,j = digit.size() - 1;
	while(i <= j){
		if(digit[i++] != digit[j--]){
			printf("No\n");
			for(int k = digit.size() - 1;k >= 0;k--)
				printf("%d%c",digit[k],k == 0 ? '\n' : ' ');
			return 0;
		}
	}
	printf("Yes\n");
	if(digit.size() == 0)
		digit.push_back(0);
	for(int k = digit.size() - 1;k >= 0;k--)
		printf("%d%c",digit[k],k == 0 ? '\n' : ' ');
	return 0;
}
