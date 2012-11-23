#include <iostream>
#include <string>
using namespace std;
#define ALPHABET 26
#define LINE 72

bool isLast(int * his,int idx,int N)
{
	for(int i = idx + 1;i < ALPHABET;i++)
		if(his[i] == N)
		{
			return false;
		}
	return true;
}

int main()
{
	int histogram[ALPHABET] = {0};
	char s[LINE];
	while(cin.getline(s,LINE))
	{
		for(int i = 0;s[i] != '\0';i++)
			if(s[i] >= 'A' && s[i] <= 'Z')
				histogram[s[i] - 'A']++;
	}
	int max = 0;
	for(int i = 0;i < ALPHABET;i++)
		if(max < histogram[i])
			max = histogram[i];
/*
	for(int i = 0;i < ALPHABET;i++)
	{
		if(histogram[i] == 0)
			continue;
		cout << char('A' + i);
		for(int j =0;j < histogram[i];j++)
			cout << " " << "*";
		cout << endl;
	}
*/
	for(int i = max;i > 0;i--)
	{
		for(int j = 0;j < ALPHABET;j++)
		{
			if(histogram[j] == i)
			{
				histogram[j]--;
				cout << "*";
				if(isLast(histogram,j,i))
				{
					cout << endl;
					break;
				}
				else if(j != ALPHABET - 1)
					cout << " ";
				else
					cout << endl;
			}
			else
				cout << "  ";
		}
	}
	for(int i = 0;i < ALPHABET;i++)
	{
		cout << char('A' + i);
	       	if(i != ALPHABET - 1)
			cout << " ";
		else
			cout << endl;
	}
	return 0;
}
