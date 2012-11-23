#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#define B 16

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

void dualpal(int n,bool* flag)
{
	for(int b = 2;b <= B;b++)
	{
		flag[b - 2] = false;
		if(palindrome(convert(b,n)))
			flag[b - 2] = true;
	}
}

int main()
{
	int N;
	
	while(cin >> N && N != 0)
	{
		bool flag[B - 1];
		dualpal(N,flag);
		char result[100];
		for(int i = 0;i < 100;i++)
			result[i] = '\0';
		for(int i = 0;i < B - 1;i++)
		{
			if(flag[i])
				sprintf(result + strlen(result)," %d",i + 2);
		}
		if(strlen(result) != 0)
			cout << "Number " << N << " is palindrom in basis" << result << endl;
		else
			cout << "Number " << N << " is not a palindrom" << endl;		
	}

	return 0;
}
