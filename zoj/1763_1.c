#include<stdio.h>
main()
{
	float x,y;
	scanf("%f",&x);
	while(x!=999)
	{
		y=x;
		scanf("%f",&x);
		if(x==999)
		break;
		else
		printf("%.2f\n",x-y);
	}
	printf("End of Output\n");
}