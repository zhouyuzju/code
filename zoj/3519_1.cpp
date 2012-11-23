#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int num,ip;
	while(cin>>num>>ip)
	{
		int* ips = new int[num];
		for(int i = 0;i < num;i++)
		{
			cin >> ips[i];
		}
		sort(ips,ips + num);
		int count = 0;
		for(int i = 0;i < num;i++)
		{
			if(ip < ips[i])
			{
				ip += 2;
				count++;
			}
		}
		ip += num - count;
		cout << ip << endl;
		delete ips;
	}
}