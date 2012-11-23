/*
ID: jwjzy10201
PROG: namenum
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<map>

using namespace std;

char form[8][3] = {{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};

long power(int base,int exp)
{
	long result = 1;
	for(int i = 0; i < exp;i++)
		result *= base;
	return result;
}

string stringToNum(string name)
{
	string result = "";
	for(int i = 0;i < name.length();i++)
	{
		if(name[i] >= 'A' && name[i] <= 'C')
			result += '2';
		else if(name[i] >= 'D' && name[i] <= 'F')
			result += '3';
		else if(name[i] >= 'G' && name[i] <= 'I')
			result += '4';
		else if(name[i] >= 'J' && name[i] <= 'L')
			result += '5';
		else if(name[i] >= 'M' && name[i] <= 'O')
			result += '6';
		else if(name[i] >= 'P' && name[i] <= 'S' && name[i] != 'Q')
			result += '7';
		else if(name[i] >= 'T' && name[i] <= 'V')
			result += '8';
		else if(name[i] >= 'W' && name[i] <= 'Y')
			result += '9';
	}	
	return result;
}

int main()
{
	ofstream fout ("namenum.out");
    	ifstream fin ("namenum.in");
	ifstream fdic ("dict.txt");
	string numstr,dicname;
	map<string,set<string> > dict;

	fin >> numstr;
	while(fdic >> dicname)
	{
		string tmpNum = stringToNum(dicname);
		dict[tmpNum].insert(dicname);
	}
	
	if(dict[numstr].size() == 0)
		fout << "NONE" << endl;
	else
	{
		set<string> ::iterator it = dict[numstr].begin();
		for(;it != dict[numstr].end();it++)
			fout << (*it) << endl;
	}

	return 0;
}
