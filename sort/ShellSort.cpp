/*
 * try.cpp
 *
 *  Created on: 2009-8-1
 *      Author: Administrator
 */

#include<iostream>
using namespace std;
//increase order
void ShellSort(int* array,int size)
{
	for(int Increment = size / 2;Increment > 0;Increment /= 2)
		for(int i = Increment;i < size;i++)
		{
			int tmp = array[i];
			int j;
			for(j = i;j >= Increment;j -= Increment )
				if(tmp < array[j - Increment])
					array[j] = array[j - Increment];
				else
					break;
			array[j] = tmp;
		}
}

int main()
{
	int array[10] = {9,9,7,6,5,8,3,2,1,0};
	ShellSort(array,10);
	for(int i = 0;i < 10;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	return 0;
}
