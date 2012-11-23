#include<iostream>
#include<cmath>
using namespace std;

bool judge(double d1,double d2,double d3,double d4,double d5,double d6)
{
	if(d1 == d2 && d2 == d3 && d3 == d4)
		return true;
	else if(d1 == d2 && d2 == d3 && d3 == d5)
		return true;
	else if(d1 == d2 && d2 == d3 && d3 == d6)
		return true;
	else if(d1 == d2 && d2 == d4 && d4 == d5)
		return true;
	else if(d1 == d2 && d2 == d4 && d4 == d6)
		return true;
	else if(d1 == d2 && d2 == d5 && d5 == d6)
		return true;
	else if(d1 == d3 && d3 == d4 && d4 == d5)
		return true;
	else if(d1 == d3 && d3 == d4 && d4 == d6)
		return true;
	else if(d1 == d3 && d3 == d5 && d5 == d6)
		return true;
	else if(d1 == d3 && d3 == d4 && d4 == d5)
		return true;
	else if(d2 == d3 && d3 == d4 && d4 == d5)
		return true;
	else if(d2 == d3 && d3 == d4 && d4 == d6)
		return true;
	else if(d2 == d3 && d3 == d5 && d5 == d6)
		return true;
	else if(d2 == d4 && d4 == d5 && d5 == d6)
		return true;
	else if(d3 == d4 && d4 == d5 && d5 == d6)
		return true;
	else 
		return false;
}

int main()
{
	int num = 0;
	cin>>num;
	for(int i = 0;i < num;i++)
	{
		cin.get();
		int x1,y1,x2,y2,x3,y3,x4,y4;
		cin>>x1>>y1;
		cin>>x2>>y2;
		cin>>x3>>y3;
		cin>>x4>>y4;
		double distance1,distance2,distance3,distance4,distance5,distance6;
		distance1 = sqrt(pow(double(x1 - x2),2) + pow(double(y1 - y2),2));
		distance2 = sqrt(pow(double(x1 - x3),2) + pow(double(y1 - y3),2));
		distance3 = sqrt(pow(double(x1 - x4),2) + pow(double(y1 - y4),2));
		distance4 = sqrt(pow(double(x2 - x3),2) + pow(double(y2 - y3),2));
		distance5 = sqrt(pow(double(x2 - x4),2) + pow(double(y2 - y4),2));
		distance6 = sqrt(pow(double(x3 - x4),2) + pow(double(y3 - y4),2));	
		cout<<"Case "<<i + 1<<":"<<endl;
		if(judge(distance1,distance2,distance3,distance4,distance5,distance6))
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
		if(i + 1< num)
			cout<<endl;
	}
	return 0;
}