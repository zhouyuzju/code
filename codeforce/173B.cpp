#include <iostream>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	long long diff = 0;
	for(int i = 0;i < n;i++){
		int ai,gi;
		cin >> ai >> gi;
		diff += ai;
	}
	int nb = 0;
	while(abs(diff) > 500){
		nb++;
		diff -= 1000;
	}
	for(int i = 0;i < nb;i++)
		cout << 'G';
	for(int i = 0;i < n - nb;i++)
		cout << 'A';
	cout << endl;
	return 0;
}
