/*
 * 1350.cpp
 *
 *  Created on: 2009-8-1
 *      Author: Administrator
 */

#include<iostream>
using namespace std;

int main()
{
	int repeat;
	cin>>repeat;
	for(int i=0;i<repeat;i++)
	{
		int num;
		cin>>num;
		int *prison = new int[num+1];
		for(int j=1;j<=num;j++)
			prison[j]=0;
		for(int j=1;j<=num;j++)
			for(int k=1;j*k<=num;k++)
				prison[j*k]++;
		int count=0;
		for(int j=1;j<=num;j++)
			if(prison[j]%2==1)
				count++;
		cout<<count<<endl;
		delete prison;
	}
	return 0;
}
