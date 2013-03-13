/**
 *This problem is about equiangular polygon.
 *Giving three point p1,p2,p3, 
 *compute the minimum squre equiangular polygon which all three points are on the border.
 *The most challenging thing is calculating the center of the Circumscribed triangle.
 *2013/3/12
 **/
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

struct Point{
	double x;
	double y;
};

Point getCenter(Point p1,Point p2,Point p3){
	Point result;
	double a12 = p1.x - p2.x;
	double a13 = p1.x - p3.x;
	double a23 = p2.x - p3.x;
	double b12 = p1.x + p2.x;
	double b13 = p1.x + p3.x;
	double b23 = p2.x + p3.x;
	double c12 = p1.y - p2.y;
	double c13 = p1.y - p3.y;
	double c23 = p2.y - p3.y;
	double d12 = p1.y + p2.y;
	double d13 = p1.y + p3.y;
	double d23 = p2.y + p3.y;
	// magic and whiny formular
	result.x = ((a12 * b12 + c12 * d12) * c13 - (a13 * b13 + c13 * d13) * c12 )/ (2 * (c13 * a12 - c12 * a13));
	result.y = ((a12 * b12 + c12 * d12) * a13 - (a13 * b13 + c13 * d13) * a12) / (2 * (c12 * a13 - c13 * a12));

	return result;
}

bool feq(double a,double b){
	return a - b < 1E-2;
}

double fgcd(double a,double b){
	if(feq(a,0))
		return b;
	if(feq(b,0))
		return a;
	return fgcd(b,fmod(a,b));
}

int main(){
	Point p1,p2,p3,o;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
	o = getCenter(p1,p2,p3);
	//cout << o.x << "," << o.y << endl;
	double r = sqrt((p1.x - o.x) * (p1.x - o.x) + (p1.y - o.y) * (p1.y - o.y));
	double a = sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
	double b = sqrt((p3.x - p1.x) * (p3.x - p1.x) + (p3.y - p1.y) * (p3.y - p1.y));
	double c = sqrt((p3.x - p2.x) * (p3.x - p2.x) + (p3.y - p2.y) * (p3.y - p2.y));
	//cout << r << "," << a << "," << b << "," << c << endl;
	double angle1 = acos((2 * r * r - a * a) / 2 / r / r) * 180 / acos(-1);
	double angle2 = acos((2 * r * r - b * b) / 2 / r / r) * 180 / acos(-1);
	double angle3 = 360.0 - angle1 - angle2;
	//cout << angle1 << "," << angle2 << "," << angle3 << endl;
	double e = fgcd(angle1,fgcd(angle2,angle3));
	printf("%.6f",sin(e * acos(-1) / 180) * r * r / 2 * 360 / e);	
}
