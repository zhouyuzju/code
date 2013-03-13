#include <iostream>
using namespace std;

int main()
{
	int N,M;
	cin >> N;
	int nodes[N + 1];
	long nodeSum[N + 1];
	long sum = 0;
	nodeSum[0] = 0;
	for(int i = 1;i <= N;i++)
	{
		cin >> nodes[i];
		sum += nodes[i];
		nodeSum[i] = sum;
	}
	cin >> M;
	for(int i = 0;i < M;i++)
	{
		int x,y;
		cin >> x >> y;
		if(x > y)
		{
			int tmp = x;
			x = y;
			y = tmp;
		}
		long a = nodeSum[y - 1] - nodeSum[x - 1];
		long b = nodeSum[N] - nodeSum[y - 1] + nodeSum[x - 1];
		long result = a > b ? b : a; 
		cout << result << endl;
	}
	return 0;
}
