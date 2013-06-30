#include <iostream>
#include <cmath>
using namespace std;
int main(){
	char a;
	int b;
	int x1,y1,x2,y2;
	cin >> a >> b;
	x1 = a - 'a' + 1,y1 = b;
	cin >> a >> b;
	x2 = a - 'a' + 1,y2 = b;
	int dx = x1 - x2,dy = y1 - y2;
	int step = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	cout << step << endl;
	int diag = abs(dx) > abs(dy) ? abs(dy) : abs(dx);
	for(int i = 0;i < diag;i++)
		if(dx > 0 && dy > 0)
			cout << "LD" << endl;
		else if(dx > 0 && dy < 0)
			cout << "LU" << endl;
		else if(dx < 0 && dy > 0)
			cout << "RD" << endl;
		else
			cout << "RU" << endl;
	dx = dx < 0 ? dx + diag : dx - diag;
	dy = dy < 0 ? dy + diag : dy - diag;
	while(dx != 0){
		if(dx < 0){
			cout << "R" << endl;
			dx++;
		}
		else{
			cout << "L" << endl;
			dx--;
		}
	}
	while(dy != 0){
		if(dy < 0){
			cout << "U" << endl;
			dy++;
		}
		else{
			cout << "D" << endl;
			dy--;
		}
	}	
	return 0;
}
