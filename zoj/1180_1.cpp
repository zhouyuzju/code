#include<iostream>
using namespace std;

bool IsSelf(int i);
int main()
{
	int num = 1000000;
	for(int i = 0;i <= num; i++)
		if(!IsSelf(i))
			cout<<i<<endl;
	getchar();
	getchar();
}
bool IsSelf(int num)
{
	for(int i = num - 100 > 0 ? num - 100 : 0;i <= num;i++ )
	{
		int temp = i;
		int sumbit = 0;
		while(temp > 0)
		{
			sumbit += temp % 10;
			temp /= 10;
		}
		if(sumbit + i == num)
			return true;
	}
	return false;
}
