/**
 *Calculus! Remember yet?
 *2013/3/30
 */

#include <cstdio>
using namespace std;
double a, ans, b, x0, y0, k;
double cal(double x){
    return (a*x*x*x/3 - x*x*(2*a*x0+k)/2 + (a*x0*x0 + y0 - b)*x);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int i = 0;i < T;i++){
		double x1,y1,x2,y2;
		scanf("%lf%lf%lf%lf%lf%lf",&x0,&y0,&x1,&y1,&x2,&y2);
		a = (y2-y0)/( (x2-x0)*(x2-x0) );
        	k = (y2-y1)/(x2-x1);
        	b = y2 - k*x2;
		ans = cal(x2) - cal(x1);
		printf("%.2f\n",ans);
	}
}
