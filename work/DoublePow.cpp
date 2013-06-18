/**
 * implement double pow(double base,int exp).
 * Be careful with base 0 and negative exp
 */
#include <iostream>
#include <cstdio>
#include <exception>
#define PR(x) cout << #x << " = " << x << endl;
#define EPS 1e-10
using namespace std;

bool equal(double a, double b){
	if(a - b >= -EPS && a - b <= EPS)
		return true;
	else
		return false;
}

double cal(double base, unsigned int exp){
	if(exp == 0)
		return 1.0;
	else if(exp == 1)
		return base;
	double result = cal(base,exp >> 1);
	result *= result;
	if(exp & 0x1 == 1)
		result *= base;
	return result;
}

double power(double base, int exp){
	if(equal(base, 0.0) && exp <= 0)
		throw new exception();
	if(exp < 0)
		return 1.0 / cal(base, (unsigned int)-exp);
	else
		return cal(base, exp);
}

int main(){
	printf("%f\n",power(2,3));
	printf("%f\n",power(-2,3));
	printf("%f\n",power(2,-3));
	printf("%f\n",power(2,0));
	printf("%f\n",power(0,4));
	printf("%f\n",power(0,-4));
	printf("%f\n",power(0,0));
	return 0;
}
