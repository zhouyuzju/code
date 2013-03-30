#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	int n,num = 1;
	while(true){
		cin >> n;
		if(n == 0)
			break;
		int ni[n];
		int sum = 0;
		for(int i = 0;i < n;i++){
			cin >> ni[i];
			sum += ni[i];
		}
		int avg = sum / n;
		sort(ni,ni + n);
		int i = 0,j = n - 1,count = 0;
		while(true){
			if(i >= j)
				break;
			if(ni[i] == avg)
				i++;
			if(ni[j] == avg)
				j--;
			int m1 = avg - ni[i];
			int m2 = ni[j] - avg;
			int m = m1 > m2 ? m2 : m1;
			count += m;
			ni[j] -= m;
			ni[i] += m;
		}
		cout << "Set #" << num++ << endl;
	        cout << "The minimum number of moves is " << count << "." << endl << endl;	
	}
}
