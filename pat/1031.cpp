#include <iostream>
#include <cstdio>
#include <cstring>
#define PR(x) cout << #x << " = " << x << endl 
using namespace std;

int main(){
	char str[81];
	scanf("%s",str);
	int N = strlen(str);
	int column,whiteNum;
	if((N + 2) % 3 == 0){
		column = (N + 2) / 3 - 1;
		whiteNum = column - 1;
	}
	else{
		if((N - (N + 2) / 3 - 1) % 2 == 0){
			column = (N - (N + 2) / 3 - 1) / 2;
			whiteNum = N - 2 * column - 2;
		}
		else{
			column = (N - (N + 2) / 3 - 1) / 2;
			whiteNum = N - 2 * column - 2;
		}
	}
	//PR(column);PR(whiteNum);
	int i = 0,j = N - 1;
		for(;i < column;){
			printf("%c",str[i++]);
			for(int k = 0;k < whiteNum;k++)
				printf("%c",' ');
			printf("%c\n",str[j--]);
		}
	while(i <= j)
		printf("%c",str[i++]);
	printf("\n");
	return 0;
}
