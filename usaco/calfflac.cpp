/*
ID: jwjzy10201
PROG: calfflac
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;
#define N 20000
#define LENGTH 82

bool isChar(char a)
{
	if((a >= 'A' && a <= 'Z') || (a >= 'a' && a <= 'z'))
		return true;
	else
		return false;
}

bool equal(char a,char b)
{
	if(tolower(a) == tolower(b))
		return true;
	else
		return false;
}

int main()
{
	ofstream fout ("calfflac.out");
    	ifstream fin ("calfflac.in");
	
	string content = "";
	char line[LENGTH];
	while(fin.getline(line,LENGTH))
	{
		content += line;
		content += "\n";
	}
	int len = content.length();
	int max = 0,left,right;
	left = 0,right = len;
	for(int i = 0;i < len;i++)
	{
		int j,k,tmp1,tmp2,tmp,left1,right1,left2,right2;
		if(!isChar(content[i]))
			tmp1 = 0;
		else
			tmp1 = 1;
		for(j = i - 1,k = i + 1;j >= 0 && k < len;)
		{
			if(!isChar(content[j]))
			{
				j--;
				continue;
			}
			if(!isChar(content[k]))
			{
				k++;
				continue;
			}
			if(equal(content[j],content[k]))
			{
				left1 = j;
				right1 = k;
				tmp1 += 2;
			}
			else
				break;
			j--;k++;
		}
		for(j = i,k = i + 1,tmp2 = 0;j >= 0 && k < len;)
		{
			if(!isChar(content[j]))
			{
				j--;	
				continue;
			}
			if(!isChar(content[k]))
			{
				k++;
				continue;
			}
			if(equal(content[j],content[k]))
			{
				left2 = j;
				right2 = k;
				tmp2 += 2;
			}
			else
				break;
			j--;k++;
		}
		
		if(tmp1 < tmp2)
		{
			left1 = left2;
			right1 = right2;
			tmp = tmp2;
		}
		else
			tmp = tmp1;
		if(max < tmp)
		{
			left = left1;
			right = right1;
			max = tmp;
		}

	}
	fout << max << endl;
	for(int i = left;i <= right;i++)
		fout << content[i];
	fout << endl;
	return 0;
}

