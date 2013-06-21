/**
 * Sort the array so that the ordered print sequence is hte min number.
 */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define PR(x) cout << #x << " = " << x << endl
#define MAXDIGITS 10
using namespace std;

bool mycmp(int a, int b){
	char AB[MAXDIGITS * 2 + 1];
	char BA[MAXDIGITS * 2 + 1];
	sprintf(AB,"%d%d",a,b);
	sprintf(BA,"%d%d",b,a);
	if(strcmp(AB, BA) > 0)
		return false;
	else
		return true;
}

void PrintMinArray(int* num, int length){
	if(num == NULL || length <= 0)
		return;
	sort(num, num + length, mycmp);
	for(int i = 0;i < length;i++)
		printf("%d",num[i]);
	printf("\n");
}

void Test(char* testName, int* numbers, int length, char* expectedResult)
{
    if(testName != NULL)
        printf("%s begins:\n", testName);

    if(expectedResult != NULL)
        printf("Expected result is: \t%s\n", expectedResult);

    printf("Actual result is: \t");
    PrintMinArray(numbers, length);

    printf("\n");
}

void Test1()
{
    int numbers[] = {3, 5, 1, 4, 2};
    Test("Test1", numbers, sizeof(numbers)/sizeof(int), "12345");
}

void Test2()
{
    int numbers[] = {3, 32, 321};
    Test("Test2", numbers, sizeof(numbers)/sizeof(int), "321323");
}

void Test3()
{
    int numbers[] = {3, 323, 32123};
    Test("Test3", numbers, sizeof(numbers)/sizeof(int), "321233233");
}

void Test4()
{
    int numbers[] = {1, 11, 111};
    Test("Test4", numbers, sizeof(numbers)/sizeof(int), "111111");
}

// 数组中只有一个数字
void Test5()
{
    int numbers[] = {321};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int), "321");
}

void Test6()
{
    Test("Test6", NULL, 0, "Don't print anything.");
}

void Test7()
{
    int numbers[] = {10,1,100};
    Test("Test5", numbers, sizeof(numbers)/sizeof(int), "100101");
}

int main(){
	Test1();
    	Test2();
    	Test3();
    	Test4();
    	Test5();
	Test6();
	Test7();
	return 0;
}
