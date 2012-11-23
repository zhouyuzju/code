#include<stdio.h>
#include<malloc.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	double x,y,distance;
}quiot[100000];
typedef struct node *dd;
void shellsort(struct node quiot[100000],long N)
{
	long i,j,inc;
	dd tmp;
	tmp=malloc(sizeof(struct node));
	for(inc=N/2;inc>0;inc/=2)
		for(i=inc;i<N;i++)
		{
			tmp->distance=quiot[i].distance;
			tmp->x=quiot[i].x;
			tmp->y=quiot[i].y;
			for(j=i;j>=inc;j-=inc)
			{
				if(tmp->distance<quiot[j-inc].distance)
				{
					quiot[j].distance=quiot[j-inc].distance;
					quiot[j].x=quiot[j-inc].x;
					quiot[j].y=quiot[j-inc].y;
				}
				else
					break;
			}
				quiot[j].distance=tmp->distance;
				quiot[j].x=tmp->x;
				quiot[j].y=tmp->y;
		}
}
void main()
{
	long i,j,N;
	double dis,mindis,curdis;
	scanf("%ld",&N);
	while(N!=0)
	{
		for(i=0;i<N;i++)
		{
			scanf("%lf%lf",&quiot[i].x,&quiot[i].y);
			quiot[i].distance=sqrt(quiot[i].x*quiot[i].x+quiot[i].y*quiot[i].y);
		}
		shellsort(quiot,N);
		mindis=sqrt((quiot[0].x-quiot[1].x)*(quiot[0].x-quiot[1].x)+(quiot[0].y-quiot[1].y)*(quiot[0].y-quiot[1].y));
		dis=mindis;
		for(i=0;i<N;i++)
		{
			for(j=i+1;j<N;j++)
			{
			if(dis<fabs(quiot[j].x-quiot[i].x)||dis<fabs(quiot[j].y-quiot[i].y))
			break;
			curdis=sqrt((quiot[i].x-quiot[j].x)*(quiot[i].x-quiot[j].x)+(quiot[i].y-quiot[j].y)*(quiot[i].y-quiot[j].y));
			if(curdis<dis)
			dis=curdis;
			}
			if(mindis>dis);
			mindis=dis;
		}
		printf("%.2f\n",mindis/2);
		scanf("%ld",&N);
	}
}