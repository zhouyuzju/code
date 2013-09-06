#include <iostream>
#include <cstdio>
using namespace std;

int findKthElem(int A[],int aBeg,int aEnd,int B[],int bBeg,int bEnd,int k){
	if(aBeg > aEnd)
		return B[bBeg + k - 1];
	if(bBeg > bEnd)
		return A[aBeg + k - 1];
	int aMid = (aBeg + aEnd) / 2, bMid = (bBeg + bEnd) / 2;
	int len = aMid - aBeg + bMid - bBeg + 2;
	if(len > k){
		if(A[aMid] < B[bMid])
			return findKthElem(A,aBeg,aEnd,B,bBeg,bMid - 1,k);
		else
			return findKthElem(A,aBeg,aMid - 1,B,bBeg,bEnd,k);
	}
	else{
		if(A[aMid] < B[bMid])
			return findKthElem(A,aMid + 1,aEnd,B,bBeg,bEnd,k - (aMid - aBeg + 1));
		else
			return findKthElem(A,aBeg,aEnd,B,bMid + 1,bEnd,k - (bMid - bBeg + 1));
	}
}

int main(){
	int la,lb;
	scanf("%d",&la);
	int A[la];
	for(int i = 0;i < la;i++)
		scanf("%d",&A[i]);
	scanf("%d",&lb);
	int B[lb];
	for(int i = 0;i < lb;i++)
		scanf("%d",&B[i]);
	printf("%d\n",findKthElem(A,0,la - 1,B,0,lb - 1,(la + lb - 1) / 2 + 1));
	return 0;
}
