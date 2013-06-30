/**
 * Modified binary search.
 */
#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
/*
 * Traditional binary search
 */
int GetK(int* num, int length, int k){
	if(num == NULL || length <= 0)
		return -1;
	int start = 0;
	int end = length - 1;
	int mid;
	while(start <= end){
		mid = start + ((end - start) >> 1);
		if(num[mid] > k)
			end = mid - 1;
		else if(num[mid] < k)
			start = mid + 1;
		else
			return mid;	
	}
	return -1;
}

int GetFirstK(int* num, int length, int k){
	if(num == NULL || length <= 0)
		return -1;
	int start = 0;
	int end = length - 1;
	int mid;
	while(start <= end){
		mid = start + ((end - start) >> 1);
		if(num[mid] > k)
			end = mid - 1;
		else if(num[mid] < k)
			start = mid + 1;
		else{
			if(mid > 0 && num[mid - 1] != k || mid == 0)
				return mid;
			else
				end = mid - 1;
		}
	}
	return -1;
}

int GetLastK(int* num, int length, int k){
	if(num == NULL || length <= 0)
		return -1;
	int start = 0;
	int end = length - 1;
	int mid;
	while(start <= end){
		mid = start + ((end - start) >> 1);
		if(num[mid] > k)
			end = mid - 1;
		else if(num[mid] < k)
			start = mid + 1;
		else{
			if(mid < length - 1 && num[mid + 1] != k || mid == length - 1)
				return mid;
			else
				start = mid + 1;
		}
	}
	return -1;
}

int GetNumberOfK(int* num, int length, int k){
	int result = 0;
	if(num != NULL && length > 0){
		int first = GetFirstK(num,length,k);
		int last = GetLastK(num,length,k);
		if(first > -1 && last > -1)
			result = last - first + 1;
	}
	return result;
}
void Test(char* testName, int data[], int length, int k, int expected)
{
    if(testName != NULL)
        printf("%s begins: ", testName);

    int result = GetNumberOfK(data, length, k);
    if(result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 查找的数字出现在数组的中间
void Test1()
{
    int data[] = {1, 2, 3, 3, 3, 3, 4, 5};
    Test("Test1", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的开头
void Test2()
{
    int data[] = {3, 3, 3, 3, 4, 5};
    Test("Test2", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数组出现在数组的结尾
void Test3()
{
    int data[] = {1, 2, 3, 3, 3, 3};
    Test("Test3", data, sizeof(data) / sizeof(int), 3, 4);
}

// 查找的数字不存在
void Test4()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test4", data, sizeof(data) / sizeof(int), 2, 0);
}

// 查找的数字比第一个数字还小，不存在
void Test5()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test5", data, sizeof(data) / sizeof(int), 0, 0);
}

// 查找的数字比最后一个数字还大，不存在
void Test6()
{
    int data[] = {1, 3, 3, 3, 3, 4, 5};
    Test("Test6", data, sizeof(data) / sizeof(int), 6, 0);
}

// 数组中的数字从头到尾都是查找的数字
void Test7()
{
    int data[] = {3, 3, 3, 3};
    Test("Test7", data, sizeof(data) / sizeof(int), 3, 4);
}

// 数组中的数字从头到尾只有一个重复的数字，不是查找的数字
void Test8()
{
    int data[] = {3, 3, 3, 3};
    Test("Test8", data, sizeof(data) / sizeof(int), 4, 0);
}

// 数组中只有一个数字，是查找的数字
void Test9()
{
    int data[] = {3};
    Test("Test9", data, sizeof(data) / sizeof(int), 3, 1);
}

// 数组中只有一个数字，不是查找的数字
void Test10()
{
    int data[] = {3};
    Test("Test10", data, sizeof(data) / sizeof(int), 4, 0);
}

// 鲁棒性测试，数组空指针
void Test11()
{
    Test("Test11", NULL, 0, 0, 0);
}



int main(){
	Test1();
    	Test2();
    	Test3();
   	Test4();
   	Test5();
    	Test6();
    	Test7();
    	Test8();
    	Test9();
   	Test10();
    	Test11();

	return 0;
}
