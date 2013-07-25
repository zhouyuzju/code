#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

char* thirteen(int a){
	char* digit = new char[3];
	if(a < 13)
		digit[0] = '0';
	else{
		if(a / 13 >= 10)
			digit[0] = 'A' + a / 13 - 10;
		else
			digit[0] = a / 13 + '0';
		a %= 13;
	}
	if(a >= 10)
		digit[1] = 'A' + a - 10;
	else
		digit[1] = a + '0';
	digit[2] = '\0';
	return digit;
}

int main(){
	int r,g,b;
	scanf("%d%d%d",&r,&g,&b);
	printf("#%s%s%s\n",thirteen(r),thirteen(g),thirteen(b));
	return 0;
}
