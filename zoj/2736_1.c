#include<stdio.h>
#include<math.h>
main()
{
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		if(x==pow(x/100,3)+pow(x/10-x/100*10,3)+pow(x%10,3))
		printf("Yes\n");
		else
		printf("No\n");
	}
}