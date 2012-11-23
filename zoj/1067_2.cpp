#include<iostream>
#include<cmath>
using namespace std;

struct color
{
int R;
int G;
int B;
}set[16];
int f(int r,int g,int b)
{
	int pos = 17;
	int i;
	double d;
	for( i = 0, d = 1000.0;i < 16;i++)
	{
		double cur =sqrt( (set[i].R-r)*(set[i].R-r)+(set[i].G-g)*(set[i].G-g)+(set[i].B-b)*(set[i].B-b));
		if(d>cur)
		{
			pos = i;
			d = cur;
		}
	}
	return pos;
}
int main()
{
	for(int i = 0;i < 16;i++)
	{
		cin>>set[i].R;
		cin>>set[i].G;
		cin>>set[i].B;
	}
	int R,G,B;
	cin>>R;
	while(R != -1)
	{
		cin>>G;
		cin>>B;
		int closest = f(R,G,B);
		cout<<"("<<R<<","<<G<<","<<B<<") "<<"maps to ("<<set[closest].R<<","<<set[closest].G<<","<<set[closest].B<<")"<<endl;
		cin>>R;
	}
}