#include<stdio.h>
#include<math.h>
main(){
int i,j,n;
float x,y,l;
float f(int year);
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {scanf("%f%f",&x,&y);
  l=sqrt(x*x+y*y);
  for(j=1;f(j)<=l;j++)
  ;

  printf("Property %d: This property will begin eroding in year %d.\n",i,j);
  }
  printf("END OF OUTPUT.\n");
  }
  float f(int j){
  float r;
  r=sqrt(100*j/3.14);
  return r;
  }
