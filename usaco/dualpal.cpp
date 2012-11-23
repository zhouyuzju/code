/*
ID: jwjzy10201
PROG: dualpal
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char intToChar(int n)
{
	char c;
	if(n < 10)
		c = n + 48;
	else
		c = n + 55;
	return c;
}

string convert(int base,int n)
{
	string result = "";
	string tmpResult = "";
	int num = n;
	while(num >= base)
	{
		tmpResult += intToChar(num % base);
		num /= base;
	}
	tmpResult += intToChar(num);
	for(int i = tmpResult.length() - 1;i >= 0;i--)
		result += tmpResult[i];
	return result;
}

bool palindrome(string square)
{
	string tmp = "";
	for(int i = square.length() - 1;i >= 0;i--)
		tmp += square[i];
	return tmp == square;
}

bool dualpal(int n)
{
	int count = 0;
	for(int b = 2;b <= 10 && count < 2;b++)
	{
		if(palindrome(convert(b,n)))
			count++;
	}
	if(count >= 2)
		return true;
	else
		return false;
}

int main()
{
	int N,S;
	ofstream fout ("dualpal.out");
    	ifstream fin ("dualpal.in");
	
	fin >> N >> S;
	int k = 0;
	for(int i = S + 1;k < N;i++)
	{
		if(dualpal(i))
		{
			fout << i << endl;
			k++;
		}
	}

	return 0;
}
