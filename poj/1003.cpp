#include <iostream>

int countCards(double dis)
{
	int count = 0;
	double sum = 0.0;
	while(true)
	{
		if(sum >= dis)
			break;
		count++;
		sum += 1.0 / (count + 1);	
	}
	return count;
}

using namespace std;
int main()
{
	while(true)
	{
		double N;
		cin >> N;
		if(N == 0.0)
			break;
		cout << countCards(N) << " card(s)" << endl;	
	}
	return 0;
}
