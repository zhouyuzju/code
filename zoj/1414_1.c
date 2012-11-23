#include<stdio.h>
main()
{
	int x,y,d;
	int f(int x,int y);
	scanf("%d",&d);
	while(d-->0)
	{
		scanf("%d%d",&x,&y);
		if(f(x,y)!=-1)
			printf("%d\n",f(x,y));
		else
			printf("No Number\n");
	}
}

int f(int x,int y)
{
	int x0,y0,i;
	if(x==0&&y==0)
		return 0;
	else
	{
	for(i=0,x0=0,y0=0;!(x0>x||y0>y);)
	{
		x0+=1;
		y0+=1;
		i++;
		if(x==x0&&y==y0)
			break;
			else
			{
				x0+=1;		
				y0-=1;
				i++;
					if(x==x0&&y==y0)
						break;
							else
								{
									x0+=1;
									y0+=1;
									i++;
									if(x==x0&&y==y0)
										break;
										else
										{
											x0-=1;
											y0+=1;
											i++;
											if(x==x0&&y==y0)
												break;
										}
								}
				}
		}
		if(x==x0&&y==y0)
		return i;
		else
		return -1;
	}
	}