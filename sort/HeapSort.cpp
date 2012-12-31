#include<iostream>
using namespace std;
//increase order
void Swap(int *a,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void PercDown(int *array,int i,int N)
{
	int Child;
	int tmp;
	for(tmp = array[i];(2 * i) < N;i = Child)
	{
		Child = 2 * i;
		if(Child != N - 1&&array[Child + 1] > array[Child])
			Child++;
		if(tmp < array[Child])
			array[i] = array[Child];
		else
			break;
	}
	array[i] = tmp;
}

void HeapSort(int *array,int N)
{
	for(int i = N / 2;i >= 0;i--)
		PercDown(array,i,N);
	for(int i = N - 1;i > 0;i--)
	{
		Swap(&array[0],&array[i]);
		PercDown(array,0,i);
	}
}

int main()
{
	int array[10] = {9,9,7,6,5,8,3,2,1,0};
	HeapSort(array,10);
	for(int i = 0;i < 10;i++)
		cout<<array[i]<<" ";
	cout<<endl;
	cin.get();
	return 0;
}
