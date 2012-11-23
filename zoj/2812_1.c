#include<stdio.h>
#include<string.h>
main()
{
	char s[256];
	int i;
	long sum;
	gets(s);
	while(strcmp(s,"#")!=0)
	{
		for(i=0,sum=0;s[i]!='\0';i++)
		{
		if(s[i]==' ')
		sum+=0;
		else 
		sum+=(i+1)*(s[i]-64);
		}
		printf("%ld\n",sum);
		gets(s);
	}
}