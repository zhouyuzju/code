#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int last = 0,total = 0;
	for(int i = 0;i < n;i++){
		int c;
		scanf("%d",&c);
		if(c > last)
			total += (c - last) * 6 + 5;
		else if(c < last)
			total += (last - c) * 4 + 5;
		else
			total += 5;
		last = c;
	}
	printf("%d\n",total);
	return 0;
}
