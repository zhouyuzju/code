/*
 * try.cpp
 *
 *  Created on: 2009-8-1
 *      Author: Administrator
 */

#include<iostream>
using namespace std;
//increase order
void InsertSort(int* array,int size)
{
	int tmp;
	for(int i = 1;i < size;i++)
	{
		tmp = array[i];
		int j = i;
		for(;j > 0 && tmp < array[j - 1];j--)
			array[j] = array[j - 1];
		array[j] = tmp;
	}

}

int main()
{
	int array[10] = {9,9,7,6,5,8,3,2,1,0};
	InsertSort(array,10);
	for(int i = 0;i < 10;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
}
