#include<stdio.h>
main()
{
	int a[15];
	int d,i,cout,j,k;
	scanf("%d",&d);
	while(d!=-1)
	{
		for(i=0;d!=0;i++)
		{
			a[i]=d;
			scanf("%d",&d);
		}
		for(j=0,cout=0;j<i;j++)
		   for(k=j+1;k<i;k++)
 			if(2*a[j]==a[k]||a[j]==2*a[k])
 			cout++;
 			printf("%d\n",cout);
 			scanf("%d",&d);
	}
}