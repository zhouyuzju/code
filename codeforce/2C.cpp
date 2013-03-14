/**
 *Local Search actually not SAA(Ä£ÄâÍË»ð) because move step is't random choose.
 *Pay attention to (double == double) equation,this cause problems.
 *Be careful when using it.
 *2013/3/14
 */
#include <iostream>
#include <cmath>
#include <cstdio>
#define END 1e-6
#define RATE 0.7
using namespace std;
double sx[3],sy[3],r[3],d[3];
/*
 *cost function
 */
double f(double x,double y){
	for(int i = 0;i < 3;i++)
		d[i] = sqrt(pow(x - sx[i],2) + pow(y - sy[i],2)) / r[i];
	double cost = 0.0;
	for(int i = 0;i < 3;i++)
		cost += pow(d[i] - d[(i + 1) % 3],2);	//l2-norm instead of l1-norm
	return cost;
}
int main(){
	double x = 0.0,y = 0.0,d = 1.0;
	for(int i = 0;i < 3;i++){
		cin >> sx[i] >> sy[i] >> r[i];
		x += sx[i];
		y += sy[i];
	}
	x /= 3,y /=3;
	double mvx[4] = {-1,0,1,0};	//stands for left,right,up,down move of coordinate x and y
	double mvy[4] = {0,-1,0,1};
	while(d > END){
		//printf("%.6f %.6f\n",x,y);
		double lx,ly,localCost = f(x,y);
		bool flag = false;
		//search for local optimal
		for(int i = 0;i < 4;i++){
			double tmpCost = f(x + mvx[i] * d,y + mvy[i] * d);
			if(tmpCost < localCost){
				flag = true;
				localCost = tmpCost;
				lx = x + mvx[i] * d;
				ly = y + mvy[i] * d;
			}
		}
		if(!flag)	//when current precision no longer work,change the precision to d*0.7
			d *= RATE;
		else{
			x = lx,y = ly;	//change current point to local optimal point
		}
		if(f(x,y) < END){	//break when cost less than 1e-6
			printf("%.5f %.5f\n",x,y);
			return 0;
		}
	}
	return 0;
}
