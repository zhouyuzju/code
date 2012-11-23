#include<stdio.h>
main()
{
	int n,k,i,j,sum,cout;
	int d[1000];
	double ave;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&k);
		for(j=0,sum=0;j<k;j++)
		{
			scanf("%d",&d[j]);
			sum+=d[j];
		}
		ave=sum*1.0/k;
		for(j=0,cout=0;j<k;j++)
		if(d[j]>ave)
		cout++;
		printf("%.3f%%\n",cout*1.0/k*100);
	}
}