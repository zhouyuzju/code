#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
	int n;
	
	while(cin >> n)
	{
		string line;
		for(int i = 0;i < n;i++)
		{
			cin >> line;
			string newline;
			for(int j = 0;j < line.length();j++)
			{
				int count = 1;
				for(int k = j + 1;k < line.length() && line[j] == line[k];k++,j++)
					count++;
				if(count == 1)
					newline += line[j];
				else
				{
					char buf[100];
					sprintf (buf, "%d",count);
					newline += buf;
					newline += line[j];
				}
			}
			cout << newline << endl;
		}
	}
	return 0;
}