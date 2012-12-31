/*
ID: jwjzy10201
PROG: runround
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <set>
using namespace std;

ifstream fin("runround.in");
ofstream fout("runround.out");

int ll(int N)
{
	int result = 0;
	while(N > 0)
	{
		result++;
		N /= 10;
	}
	return result;
}

bool round(int N)
{
	int length = ll(N);
	int digits[length];
	int tmpN = N;
	set<int> dd;
	for(int i = length - 1;i >= 0;i--)
	{
		digits[i] = tmpN % 10;
		tmpN /= 10;
		dd.insert(digits[i]);
	}
	if(dd.size() != length)
		return false;
	int idx = 0;
	set<int> tmp;
	while(true)
	{
		int move = digits[idx];
		if(move == 0)
			return false;
		else if(tmp.size() == dd.size())
		{
			if(idx == 0)
				return true;
			else 
				return false;
		}
		else if(tmp.size() != dd.size() && tmp.find(move) != tmp.end())
			return false;
		tmp.insert(move);
		idx = (idx + move) % length;
	}	
}

int main()
{
	int M;
	fin >> M;
	int result = -1;
	for(int i = M + 1;;i++)
		if(round(i))
		{
			result = i;
			break;
		}
	fout << result << endl;
	return 0;
}
