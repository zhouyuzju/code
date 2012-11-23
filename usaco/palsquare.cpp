/*
ID: jwjzy10201
PROG: palsquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
#define N 300

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

int main()
{
	int B;
	ofstream fout ("palsquare.out");
    	ifstream fin ("palsquare.in");
	
	fin >> B;
	for(int i = 1;i <= N;i++)
	{
		string a = convert(B,i);
		string b = convert(B,i * i);
		if(palindrome(b))
			fout << a << " " << b << endl;

	}

	return 0;
}
