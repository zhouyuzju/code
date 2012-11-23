#include <cstdio>

#define MONTH 12
using namespace std;
int main()
{
	double slary[MONTH];
	double sum = 0.0;
	for(int i = 0;i < MONTH;i++)
	{
		scanf("%lf",&slary[i]);
		sum += slary[i];
	}
	printf("$%.2f\n",sum / MONTH);
}

