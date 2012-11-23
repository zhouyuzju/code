/*
ID:jwjzy10201
TASK:sprime
LANG:C++
*/
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int base[6] = {1,2,3,5,7,9};
ofstream fout ("sprime.out");
ifstream fin ("sprime.in");

bool isPrime(long n)
{
	if(n == 0 || n == 1)
		return false;
	for(long i = 2;i <= sqrt(n);i++)
		if(n % i == 0)
		{
			return false;
		}
	return true;
}

void DFS(long n,int w)
{
	//cout << "DFS: " << n << endl;
	if(w == 0)
	{
		fout << n << endl;
		return;
	}
	w--;
	for(int i = 0;i < 6;i++)
		if(isPrime(n * 10 + base[i]))
			DFS(n * 10 + base[i],w);
	return;
}

int main()
{
	int N;
	fin  >> N;
	DFS(0,N);
	return 0;
}
