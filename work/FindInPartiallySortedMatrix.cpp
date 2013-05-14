#include <cstdio>
#include <iostream>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
int matrix[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};

bool find(int rows,int columns,int num){
	bool result = false;
	if(matrix != NULL && rows > 0 && columns > 0){
		int row = 0;
		int column = columns - 1;
		while(row < rows && column > 0){
			if(matrix[row][column] == num){
				result = true;
				break;
			}
			else if(matrix[row][column] > num)
				column--;
			else
				row++;
		}
	}
	return result;
}

int main(){
	PR(find(4,4,5));
	return 0;
}
