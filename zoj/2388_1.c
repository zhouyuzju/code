#include<stdio.h>
main()
{
	int s,d,i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&s,&d);
		if(s<d||(s+d)%2!=0)
		printf("impossible\n");
		else
		printf("%d %d\n",(s+d)/2,(s-d)/2);
	}
}