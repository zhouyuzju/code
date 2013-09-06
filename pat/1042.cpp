#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int N;
	int* card = new int[54];
	int* swap = new int[54];
	int* tmp = new int[54];
	scanf("%d",&N);
	for(int i = 0;i < 54;i++)
		scanf("%d",swap + i);
	for(int i = 0;i < 54;i++)
		card[i] = i + 1;
	for(int i = 0;i < N;i++){
		for(int j = 0;j < 54;j++)
			tmp[swap[j] - 1] = card[j];
		int* p = card;
		card = tmp;
		tmp = p;
	}
	for(int i = 0;i < 54;i++){
		int color = (card[i] - 1) / 13;
		int num = (card[i] - 1) % 13 + 1;
		if(color == 0)
			printf("S");
		else if(color == 1)
			printf("H");
		else if(color == 2)
			printf("C");
		else if(color == 3)
			printf("D");
		else
			printf("J");
		printf("%d%c",num,i == 53 ? '\n' : ' ');
	}
	return 0;
}
