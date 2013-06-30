#include <iostream>
using namespace std;
int n, k;
int main()
{
	int n, k, mod = 1000000007;
	cin >> n >> k;
	long long ans = 1, ans2 = 1;
	for (int i = 1; i < k; ++i)
	{
		ans *= k;
		ans %= mod;
	}
	for (int i = 0; i < n - k; ++i)
	{
		ans2 *= (n - k);
		ans2 %= mod;
	}
	ans = (ans * ans2) % mod;
	cout << ans << endl;
	return 0;
}

