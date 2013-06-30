#include <iostream>
using namespace std;
int main(){
	int n,m;
	while(true){
		cin >> n >> m;
		if(n == - 1 && m == -1)
			break;
		int r = 0;
		while( m != 0){
			r = n % m;
			n = m;
			m = r;
		}
		if(n == 1)
			cout << "YES" << endl;
		else
			cout << "POOR Haha" << endl;
	}
	return 0;
}
