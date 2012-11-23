 #include<stdio.h>
 #include<math.h>
 main()
 {
	int n,i,sum,ave,step,j;
	int d[50];
	scanf("%d",&n);
	j=1;
	while(n!=0)
	{
		for(i=0,sum=0,step=0;i<n;i++)
		{
			scanf("%d",&d[i]);
			sum+=d[i];
		}
		ave=sum/n;
		for(i=0;i<n;i++)
		step+=fabs(ave-d[i]);
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",j++,step/2);
		scanf("%d",&n);
	}
}