#include<stdio.h>
main()
{
	int m,n,i,cout,sum,j;
	int a[20000];
	scanf("%d%d",&n,&m);
	while(!(n==0&&m==0))
	{
		for(i=0;i<m;i++)
			scanf("%d",&a[i]);
		for(j=1,sum=0;j<=n;j++)
		{
			for(i=0,cout=0;i<m;i++)
				if(a[i]==j)
				cout++;
				if(cout>1)
			sum+=1;
		}
		printf("%d\n",sum);
		scanf("%d%d",&n,&m);		
	}
}