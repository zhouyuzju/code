/*
 * try.cpp
 *
 *  Created on: 2009-8-1
 *      Author: Administrator
 */

#include<iostream>
using namespace std;
//increase order
void swap(int &a,int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void BubbleSort(int* array,int size)
{
	for(int i = 0;i < size;i++)
	{
		for(int j = size - 1;j > i;j--)
			if(array[j - 1] > array[j])
				swap(array[j - 1],array[j]);
	}
}

int main()
{
	int array[10] = {9,9,7,6,5,8,3,2,1,0};
	BubbleSort(array,10);
	for(int i = 0;i < 10;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
}
