/**
 * Find the minimum number in a rotated array.
 * O(log n) average, O(n) worse([1,1,1,1,1])
 */
#include <iostream>
#include <cstdio>
#include <exception>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int searchInOrder(int* num, int s, int e){
	int result = num[s];
	for(int i = s;i <= e;i++)
		if(result > num[i])
			result = num[i];
	return result;
}

int min(int* num, int length){
	if(num == NULL || length <= 0)
		throw new exception();
	int lt = 0, gt = length - 1, mid = 0;
	while(num[lt] >= num[gt]){
		if(gt - lt == 1){
			mid = gt;
			break;
		}
		mid = lt + ((gt - lt) >> 1); //移位的优先级低于加
		if(num[mid] == num[lt] && num[mid] == num[gt])
			return searchInOrder(num, lt, gt);
		if(num[lt] <= num[mid])
			lt = mid;
		else if(num[gt] >= num[mid])
			gt = mid;
	}
	return num[mid];
}

int main(){
	int a[10] = {5,6,7,8,9,0,1,2,3,4};
	int* b = NULL;
	int c[5] = {1,2,3,4,5};
	int d[5] = {1,0,1,1,1};
	int e[5] = {1,1,1,0,1};
	printf("%d\n",min(a,10));
	printf("%d\n",min(c,5));
	printf("%d\n",min(d,5));
	printf("%d\n",min(e,10));
	printf("%d\n",min(b,1));
	printf("%d\n",min(a,0));
	return 0;
}
