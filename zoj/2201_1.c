#include<stdio.h>
main()
{
	int x,y,i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		if(x>=y)
		printf("MMM BRAINS\n");
		else
		printf("NO BRAINS\n");
	}
}