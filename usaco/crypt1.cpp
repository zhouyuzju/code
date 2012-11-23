/*
ID: jwjzy10201
PROG: crypt1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <set>

using namespace std;

set<int> numSet;

bool crypt(int n,int bits)
{
	bool flag = true;
	int div = 0;
	if(bits == 3)
		div = 100;
	else
		div = 1000;
	if(n / div <= 0 || n / div > 10)
	{
		flag = false;
		return flag;
	}
	while(n > 0)
	{
		if(numSet.find(n % 10) == numSet.end())
		{
			flag = false;
			break;
		}
		n /= 10;
	}
	return flag;	
}

int main()
{
	ofstream fout ("crypt1.out");
    	ifstream fin ("crypt1.in");
	int N;
	fin >> N;
	int numArray[N];
	for(int i = 0;i < N;i++)
	{
		fin >> numArray[i];
		numSet.insert(numArray[i]);
	}
	int count = 0;
	for(int a1 = 0;a1 < N;a1++)
		for(int a2 = 0;a2 < N;a2++)
			for(int a3 = 0;a3 < N;a3++)
				for(int b1 = 0;b1 < N;b1++)
					for(int b2 = 0;b2 < N;b2++)
					{
						int a = numArray[a3] * 100 + numArray[a2] * 10 + numArray[a1];
					       	int b = numArray[b2] * 10 + numArray[b1];
						int result = a * b;
						if(crypt(a * numArray[b2],3) && crypt(a * numArray[b1],3) && crypt(result,4))
							count++;
					}
	fout << count << endl;
	return 0;
}
