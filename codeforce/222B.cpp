#include <iostream>
using namespace std;

int main()
{
	int n,m,k;
	cin >> n >> m >> k;
	int table[n][m];
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++)
			cin >> table[i][j];
	int r[n];
	for(int i = 0;i < n;i++)
		r[i] = i;
	int c[m];
	for(int i = 0;i < m;i++)
		c[i] = i;
	for(int i = 0;i < k;i++)
	{
		string s;
		int x,y;
		cin >> s >> x >> y;
	//	cout << s << "," << x << "," << y << endl;
		if(s == "c")
		{
			int tmp = c[x - 1];
			c[x - 1] = c[y - 1];
			c[y - 1] = tmp;
		}
		else if(s == "r")
		{
			int tmp = r[x - 1];
			r[x - 1] = r[y - 1];
			r[y - 1] = tmp;
		}
		else if(s == "g")
		{
		//	cout << r[x - 1] << "," << c[y - 1];
			cout << table[r[x - 1]][c[y - 1]] << endl;
		}
	}
	return 0;
}
