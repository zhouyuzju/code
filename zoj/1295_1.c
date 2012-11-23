#include<stdio.h>
#include<string.h>
main()
{
	int d,i;
	char c[70];
	void reverse(char c[]);
	scanf("%d",&d);
	getchar();
	for(i=0;i<d;i++)
	{
		gets(c);
		reverse(c);
	}
}
void reverse(char c[])
{
	int s,i,j;
	for(i=0,j=strlen(c)-1;i<j;i++,j--)
	{
		s=c[i];
		c[i]=c[j];
		c[j]=s;
	}
	puts(c);
}