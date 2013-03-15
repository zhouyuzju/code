
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
	int N,K,sum;
	cin >> N >> K;
	if(N % 2 == 0)		//even node is impossible
		sum = 0;
	else if(K > (N + 1) / 2 || K < ceil(log10(N + 1) * 1.0 / log10(2)))
	// K satisfy[ceil(log2 (N + 1)),(N + 1) / 2]
		sum = 0;
	else{
			
	}
	cout << sum << endl;
	return 0;
}
