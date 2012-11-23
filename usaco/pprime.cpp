/*
ID: jwjzy10201
PROG: pprime
LANG: C++
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
char A[10],B[10];
int en[]={1,10,100,1000,10000,100000};
int a,b;
int opp[100005];
FILE*in,*out;
void opposit()
{
	int num,temp,i;
	for(i=1;i<=10000;i++)
	{
		num=i;
		temp=0;
		while(num)
		{
			temp=temp*10+num%10;
			num/=10;
		}
		opp[i]=temp;
	}
}
void isprim(int x)
{
	if(x<a||x>b)
		return;
	if((x%5==0&&x!=5)||x%3==0)
		return;
	if(x%11==0&&x!=11)
		return;
	if(x%2==0)
		return;
	int m=sqrt(x);
	for(int i=2;i<=m;i++)
		if(x%i==0)
			return;
	fprintf(out,"%d\n",x);
}
void odd(int len)
{
	len=(len-1)/2;
	int i,m,prim;
	for(i=en[len-1];i<en[len];i++)
		for(m=0;m<=9;m++)
		{
			prim=i*en[len+1]+m*en[len]+opp[i];
			isprim(prim);
		}
}
void even(int len)
{
	len/=2;
	int i,prim;
	for(i=en[len-1];i<en[len];i++)
	{
		prim=i*en[len]+opp[i];
		isprim(prim);
	}
}
int main()
{
	in=fopen("pprime.in","r");
	out=fopen("pprime.out","w");
	fscanf(in,"%s %s",A,B);
	int a1=strlen(A);
	int b1=strlen(B);
	a=atoi(A);
	b=atoi(B);
	int len;
	opposit();
	for(len=a1;len<=b1;len++)
	{
		if(len&1)
			odd(len);
		else
			even(len);
	}
	return 0;
}

