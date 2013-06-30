/**
 * Count the inverse pair in an array.
 */
#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int InverseRecursive(int* data, int* copy, int start, int end);
int InversePair(int* data, int length){
	if(data == NULL || length <= 0)
		return 0;
	int* copy = new int[length];
	for(int i = 0;i < length;i++)
		copy[i] = data[i];
	int result = InverseRecursive(data, copy, 0, length - 1);
	delete[] copy;
	return result;
}

int InverseRecursive(int* data, int*copy, int start, int end){
	if(start == end){
		copy[start] = data[start];
		return 0;
	}
	int mid = start + ((end - start) >> 1);
	int left = InverseRecursive(copy,data,start,mid);
	int right = InverseRecursive(copy,data,mid + 1,end);
	int p1 = mid, p2 = end, index = end;
	int count = 0;
	while(p1 >= start && p2 >= mid + 1){
		if(data[p1] > data[p2]){
			count += p2 - mid;
			copy[index--] = data[p1--];	
		}
		else
			copy[index--] = data[p2--];
	}
	for(;p1 >= start;p1--)
		copy[index--] = data[p1];
	for(;p2 >= mid + 1;p2--)
		copy[index--] = data[p2];
	return left + right + count;
}

int main(){
	int a[] = {7,5,6,4};
	int b[] = {1,2,3,4,5,6,7,8,9,10};
	int c[] = {10,9,8,7,6,5,4,3,2,1};
	int d[] = {5,5,4,4,1};
	PR(InversePair(a,4));
	PR(InversePair(b,10));
	PR(InversePair(c,10));
	PR(InversePair(d,5));
	return 0;
}
