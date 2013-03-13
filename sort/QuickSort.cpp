#include<iostream>
using namespace std;
//increase order
void Swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void InsertSort(int* array,int size)
{
	int tmp;
	for(int i = 1;i < size;i++)
	{
		tmp = array[i];
		int j = i;
		for(;j > 0 && tmp < array[j - 1];j--)
			array[j] = array[j - 1];
		array[j] = tmp;
	}

}

int Median3(int *array,int left,int right)
{
	int center = (left + right) / 2;
	if(array[left] > array[center])
		Swap(&array[left],&array[center]);
	if(array[left] > array[right])
		Swap(&array[left],&array[right]);
	if(array[center] > array[right])
		Swap(&array[center],&array[right]);
	Swap(&array[center],&array[right - 1]);
	return array[right - 1];
}

void Qsort(int *array,int left,int right)
{
	int i,j;
	int pivot;
	if(left + 3 <= right)
	{
		pivot = Median3(array,left,right);
		i = left;
		j = right - 1;
		for(;;)
		{
			while(array[++i] < pivot){}
			while(array[--j] > pivot){}
			if(i < j)
				Swap(&array[i],&array[j]);
			else
				break;
		}
		Swap(&array[i],&array[right - 1]);
		Qsort(array,left,i - 1);
		Qsort(array,i + 1,right);
	}
	else
		InsertSort(array + left,right - left + 1);
}

void QuickSort(int *array,int N)
{
	Qsort(array,0,N - 1);
}

int main()
{
	int array[10] = {9,9,7,6,5,8,3,2,1,0};
	QuickSort(array,10);
	for(int i = 0;i < 10;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	cin.get();
	return 0;
}
