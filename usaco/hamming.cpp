/*
ID: jwjzy10201
PROG: hamming
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <set>

using namespace std;

int hamming(int a,int b)
{
	int tmp = a ^ b;
	int result = 0;
	while(tmp > 0)
	{
		tmp &= tmp - 1;
		result++;
	}
	return result;
}

int main()
{
	int N,B,D;
	set<int> hammingSet;
	ofstream fout ("hamming.out");
    	ifstream fin ("hamming.in");

	fin >> N >> B >> D;
	int count = 0;
	for(int i = 0;i < pow(2,B) && count < N;i++)
	{
		bool flag = true;
		for(set<int>::iterator it = hammingSet.begin();it != hammingSet.end();it++)
			if(hamming(*it,i) < D)
			{
				flag = false;
				break;
			}
		if(flag)
		{
			hammingSet.insert(i);
			count++;
		}
	}
	
	int countLine = 0;
	int countElement = hammingSet.size();
	for(set<int>::iterator it = hammingSet.begin();it != hammingSet.end();it++)
	{
		if(countLine == 9)
		{
			fout << *it << endl;
			countLine = 0;
		}
		else
		{
			fout << *it;
			if(countElement != 1)
				fout << " ";
			else
				fout << endl;
			countLine++;
		}
		countElement--;
	}
	return 0;
}
