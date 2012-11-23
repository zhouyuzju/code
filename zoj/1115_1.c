#include<stdio.h>
int main()
{
  char c;
  int x,i,j,k;
  int n[1000],a[1000];
  int digit(int x);
  for(i=0;;i++)
  {
	  j=0;
	while((c=getchar())!='\n')
	{
		a[j]=c-48;
		j++;
	}
	n[i]=0;
	for(k=0;k<j;k++)
	n[i]+=a[k];
	if(n[i]==0)
		break;
  }
  for(i=0;n[i]!=0;i++)
  {
	 x=n[i];
    while(x>=10)
   {
	 x=digit(x);
   }
   printf("%d\n",x);
  }
}
int digit(int x)
{
 int y=0;
 while(x>0)
 {
   y=y+x%10;
   x=x/10;
 }
return y;
}