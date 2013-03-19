#include <iostream>
using namespace std;
int main(){
	int n,x = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		string line;
		cin >> line;
		if(line[0] == 'X' &&  line[1] == '+')
			x++;
		else if(line[0] == 'X' && line[1] == '-')
			x--;
		else if(line[0] == '+')
			x++;
		else if(line[0] == '-')
			x--;
	}
	cout << x << endl;
}
