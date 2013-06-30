#include <cstdio>
using namespace std;
int main(){
	char c;
	bool b[4][4];
	for(int i = 0;i < 4;i++)
		for(int j = 0;j < 5;j++){
			scanf("%c",&c);
			if(c == '#')
				b[i][j] = false;
			else
				b[i][j] = true;
		}
	/*for(int i = 0;i < 4;i++)
		for(int j = 0;j < 4;j++)
			printf("%d\n",board[i][j]);*/
	for(int i = 0;i < 3;i++)
		for(int j = 0;j < 3;j++){
			if(!((b[i][j] + b[i + 1][j] + b[i][j + 1] + b[i + 1][j + 1]) % 4 == 2)){
				printf("YES\n");
				return 0;
			}

		}
	printf("NO\n");
	return 0;
}
