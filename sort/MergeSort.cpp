/*
 * try.cpp
 *
 *  Created on: 2009-8-1
 *      Author: Administrator
 */

#include<iostream>
using namespace std;
//increase order
void Merge(int *array,int *tmp,int left,int center,int right)
{
	int leftend = center - 1,tmppos = left,size = right - left + 1;
	while(left <= leftend && center <= right)
		if(array[left] <= array[center])
			tmp[tmppos++] = array[left++];
		else
			tmp[tmppos++] = array[center++];
	while(left <= leftend)
		tmp[tmppos++] = array[left++];
	while(center <= right)
		tmp[tmppos++] = array[center++];
	for(int i = 0;i < size;i++,right--)
		array[right] = tmp[right];
}

void MSort(int *array,int *tmp,int left,int right)
{
	int center = (left + right) / 2;
	if(left < right)
	{
		MSort(array,tmp,left,center);
		MSort(array,tmp,center + 1,right);
		Merge(array,tmp,left,center + 1,right);
	}
}


void MergeSort(int* array,int size)
{
	int *tmp = new int[size];
	if(tmp != NULL)
	{
		MSort(array,tmp,0,size - 1);
		delete tmp;
	}
	else
		cout<<"No space for tmp array!!"<<endl;
}

int main()
{
	int array[10] = {9,9,7,6,5,8,3,2,1,0};
	MergeSort(array,10);
	for(int i = 0;i < 10;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
}
