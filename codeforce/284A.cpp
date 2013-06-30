#include <iostream>
using namespace std;

bool powbig(int base,int n,int p){
	int result = 1;
	for(int i = 0;i < n;i++){
		result *= base;
		if(result > p)
			return true;
	}
	return false;
}

bool root(int x,int p){
	int mod = x;
	if(p == 2)
		return true;
	for(int i = 1;i <= p - 2;i++){
		mod %= p;
		if(mod == 1 && powbig(x,i,p))
			return false;
		mod *= x;
	}
	if(powbig(x,p - 1,p) && mod % p == 1)
		return true;
	else
		return false;
}

int main(){
	int p,count = 0;
	cin >> p;
	for(int i = 1;i < p;i++)
		if(root(i,p))
			count++;
	cout << count << endl;
}
