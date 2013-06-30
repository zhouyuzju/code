/**
 * Reorder the array by some functionality
 */
#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

bool isEven(int a){
	return (a & 0x1) == 0;	//位与的优先级低于==
}

void reorder(int* num, int length, bool (*func)(int)){
	if(num == NULL || length <= 0)
		return;
	int* head = num;
	int* tail = num + length - 1;
	while(head < tail){
		while(head < tail && !func(*head))
			head++;
		while(head < tail && func(*tail))
			tail--;
		if(head < tail){
			int tmp = *head;
			*head = *tail;
			*tail = tmp;
		}
	}
}

void ReorderOddEven(int* num, int length){
	reorder(num,length,isEven);
}

void printArray(int* num,int length){
	for(int i = 0;i < length;i++)
		printf("%d%c",num[i],i == length - 1 ? '\n' : ' ');
}

int main(){
	int a[] = {1,2,3,4,5};
	printArray(a,sizeof(a) / sizeof(int));
	ReorderOddEven(a,sizeof(a) / sizeof(int));
	printArray(a,sizeof(a) / sizeof(int));
	return 0;
}
