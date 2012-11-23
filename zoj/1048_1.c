#include<stdio.h>
main(){
 int i;
 float a,sum=0,ave;
   for(i=1;i<=12;i++){
     scanf("%f",&a);
     sum+=a;
}
	ave=sum/12;
	printf("$%.2f\n",ave);
	}
