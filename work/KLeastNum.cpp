/**
 * Print the k least number in the given array
 */
#include <iostream>
#include <cstdio>
#include <exception>
#include <queue>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

void swap(int* num, int i, int j){
	int tmp = num[i];
	num[i] = num[j];
	num[j] = tmp;
}

int partition(int* num, int length, int start, int end){
	if(num == NULL || length <= 0 || start < 0 || end < 0 || start > end || end >= length || start >= length)
		throw new exception();
	int pivot = start, i = start + 1, j = end;
	while(true){
		while(num[i] < num[pivot])
			if(i >= end) break;
			else i++;
		while(num[j] > num[pivot])
			if(j <= start) break;
			else j--;
		if(i >= j)
			break;
		swap(num,i,j);
	}
	swap(num,pivot,j);
	return j;
}

void printKLeastNum(int* num, int length, int k){
	if(num == NULL || length <= 0 || k <= 0 || k > length)
		throw new exception();
	int start = 0;
	int end = length - 1;
	int index = partition(num, length, start, end);
	while(index != k - 1){
		if(index > k - 1){
			end = index - 1;
			index = partition(num,length,start,end);
		}
		else{
			start = index + 1;
			index = partition(num,length,start,end);
		}
	}
	for(int i = 0;i < k;i++)
		printf("%d%c",num[i],i == k - 1 ? '\n' : ' ');
}

void printKLeastNumPQ(int* num, int length, int k){
	if(num == NULL || length <= 0 || k <= 0 || k > length)
		throw new exception();
	priority_queue<int> pq;
	for(int i = 0;i < length;i++){
		if(pq.size() < k)
			pq.push(num[i]);
		else if(pq.top() > num[i]){
			pq.pop();
			pq.push(num[i]);
		}
	}
	while(pq.size() > 0){
		printf("%d%c",pq.top(),pq.size() == 1 ? '\n':' ');
		pq.pop();
	}
}

int main(){
	int num[] = {4,5,1,6,2,7,3,8};
	printKLeastNum(num,8,4);
	printKLeastNum(num,8,8);
	printKLeastNum(num,8,1);
	printKLeastNumPQ(num,8,4);
	printKLeastNumPQ(num,8,8);
	printKLeastNumPQ(num,8,1);
	int num2[] = {5,4,4,3,3,2,1};
	printKLeastNum(num2,7,3);
	printKLeastNum(num2,7,4);
	printKLeastNum(num2,7,5);
	printKLeastNumPQ(num2,7,3);
	printKLeastNumPQ(num2,7,4);
	printKLeastNumPQ(num2,7,5);

	return 0;
}
