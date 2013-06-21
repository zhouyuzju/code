/**
 * Print the matrix in circle clockwise
 */

#include <iostream>
#include <cstdio>
#include <exception>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

void Print(int n){
	printf("%d ",n);
}

void PrintMatrixInCircle(int** num, int columns, int rows, int start){
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;
	for(int i = start; i <= endX; i++)
		Print(num[start][i]);
	if(start < endY){
		for(int i = start + 1; i <= endY; i++)
			Print(num[i][endX]);
	}
	if(start < endX && start < endY){
		for(int i = endX - 1;i >= start;i--)
			Print(num[endY][i]);
	}
	if(start < endX && start < endY - 1){
		for(int i = endY - 1;i >= start + 1;i--)
			Print(num[i][start]);
	}
}

void PrintMatrix(int** num, int columns,int rows){
	int start = 0;
	while(2 * start < columns && 2 * start < rows){
		PrintMatrixInCircle(num, columns, rows, start);
		start++;
	}
}



void Test(int columns, int rows)
{
    printf("Test Begin: %d columns, %d rows.\n", columns, rows);

    if(columns < 1 || rows < 1)
        return;

    int** numbers = new int*[rows];
    for(int i = 0; i < rows; ++i)
    {
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; ++j)
        {
            numbers[i][j] = i * columns + j + 1;
        }
    }

    PrintMatrix(numbers, columns, rows);
    printf("\n");

    for(int i = 0; i < rows; ++i)
        delete[] (int*)numbers[i];

    delete[] numbers;
}


int main(){
   /*
    1    
    */
    Test(1, 1);

    /*
    1    2
    3    4
    */
    Test(2, 2);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    Test(4, 4);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    21   22   23   24   25
    */
    Test(5, 5);

    /*
    1
    2
    3
    4
    5
    */
    Test(1, 5);

    /*
    1    2
    3    4
    5    6
    7    8
    9    10
    */
    Test(2, 5);

    /*
    1    2    3
    4    5    6
    7    8    9
    10   11   12
    13   14   15
    */
    Test(3, 5);

    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    17   18   19   20
    */
    Test(4, 5);

    /*
    1    2    3    4    5
    */
    Test(5, 1);

    /*
    1    2    3    4    5
    6    7    8    9    10
    */
    Test(5, 2);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14    15
    */
    Test(5, 3);

    /*
    1    2    3    4    5
    6    7    8    9    10
    11   12   13   14   15
    16   17   18   19   20
    */
    Test(5, 4);
	return 0;
}
