#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	if(n < 4)
		cout << "NO" << endl;
	else if(n % 2 == 0)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}
