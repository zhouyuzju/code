#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,c,i;
	float s;
	scanf("%d%d%d",&a,&b,&c);
	i=1;
	while(a||b||c)
	{
		if(a==-1)
		{
			if(a==0||b==0||c==0||c<=b||c==-1||b==-1)
				printf("Triangle #%d\nImpossible.\n\n",i);
			else
			{
			s=sqrt(c*c-b*b);
			printf("Triangle #%d\na = %.3f\n\n",i,s);
			}
		}
		else 
		if(b==-1)
		{
			if(a==0||b==0||c==0||c<=a||c==-1||a==-1)
				printf("Triangle #%d\nImpossible.\n\n",i);
			else
			{
			s=sqrt(c*c-a*a);
			printf("Triangle #%d\nb = %.3f\n\n",i,s);
			}
		}
		else 
		if(c==-1)
		{
			
			if(a==0||b==0||c==0||a==-1||b==-1)
				printf("Triangle #%d\nImpossible.\n\n",i);
			else
			{
				s=sqrt(a*a+b*b);
				printf("Triangle #%d\nc = %.3f\n\n",i,s);
			}	
		}
		else
				printf("Triangle #%d\nImpossible.\n\n",i);

		i++;
		scanf("%d%d%d",&a,&b,&c);
	}
	return 0;
}