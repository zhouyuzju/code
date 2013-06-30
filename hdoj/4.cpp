#include <iostream>
using namespace std;
int main(){
	int n,u,d;
	while(true){
		cin >> n >> u >> d;
		if(n == 0)
			break;
		int count = 0;
		while(n > 0){
			n -= u;
			count++;
			if(n <= 0)
				break;
			n += d;
			count++;
		}
		cout << count << endl;
	}
	return 0;
}
