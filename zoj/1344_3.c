#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
struct point
{
	int x;
	int y;
	long step;
	int flag;
}dog[51];
typedef struct point *type;
struct Queuenode
{
	int capacity;
	int front;
	int rear;
	int size;
	type *array;
};
typedef struct Queuenode *Queue;
Queue Q;
int m,n,D,x1,y1,x2,y2,x3,y3;
char map[51][51];
int loop[5][2]={-1,0,0,1,1,0,0,-1,0,0};
int mark[51][51][51];
void createqueue(int N)
{
	Q=malloc(sizeof(struct Queuenode));
	if(Q==NULL)
		printf("error in creating new space\n");
	Q->array=malloc(sizeof(type)*N);
    if(Q->array==NULL)
    	printf("out of space\n");
   	Q->capacity=N;
}
int isempty(Queue Q)
{
	return Q->size==0;
}
static int succ(int value,Queue Q)
{
	if(++value==Q->capacity)
	value=0;
	return value;
}
void enqueue(type x,Queue Q)
{
		Q->size++;
		Q->rear=succ(Q->rear,Q);
		Q->array[Q->rear]=x;
}
type dequeue(Queue Q)
{
	int i;
	Q->size--;
	i=Q->front;
	Q->front=succ(Q->front,Q);
	return Q->array[i];
}
void disposequeue(Queue Q)
{
	free(Q->array);
	free(Q);
}
void makeempty(Queue Q)
{
	Q->size=0;
	Q->front=1;
	Q->rear=0;
}
void initialize(void)
{
	int i,j;
	char c;
	scanf("%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&D);
	getchar();
	x1--;
	x2--;
	x3--;
	y1--;
	y2--;
	y3--;
	dog[0].x=x3;
	dog[0].y=y3;
	dog[0].flag=0;
	for(i=1;i<=D;i++)
	{
		scanf("%c",&c);
		if( c=='G' ) 
   {
    dog[i].x=dog[i-1].x+loop[ dog[i-1].flag ][0];
    dog[i].y=dog[i-1].y+loop[ dog[i-1].flag ][1];
    dog[i].flag=dog[i-1].flag;
   } else if( c=='L' ) {
    dog[i].x=dog[i-1].x;
	dog[i].y=dog[i-1].y;
    dog[i].flag=( dog[i-1].flag-1+4) %4;
   } else if( c=='R' ) {
    dog[i].x=dog[i-1].x;
	dog[i].y=dog[i-1].y;
    dog[i].flag=(dog[i-1].flag+1)%4;
   }
	}
	for(i=0;i<m;i++)
    for(j=0;j<n;)
    {
    	c=getchar();
    	if(c=='*'||c=='.')
    	map[i][j++]=c;
    }
return;
}
int legal(int x,int y,int flag)
{
int tx=dog[flag].x;
int ty=dog[flag].y;
int ok=0;
while(1)
{

   if( tx<0 || tx>=m || ty<0 || ty>=n ){
    ok=1;
    break;
   }
   if( tx==x && ty==y ) {
    ok=0;
    break;
   }
   if( map[tx][ty]=='*' ) {
    ok=1;
    break;
   }
   tx+=loop[ dog[flag].flag ][0];
   ty+=loop[ dog[flag].flag ][1];
}
return ok;
}
int search(void)
{
	int x0,y0,step,flag,i;
	type p,t;
	memset(mark,0,sizeof(mark));
	p=malloc(sizeof(struct point));
	p->x=x1;
	p->y=y1; 
	p->step=0;
	p->flag=0;
	mark[p->x][p->y][p->flag]=1;
	createqueue(1000);
	makeempty(Q);
	enqueue(p,Q);
	while( !isempty(Q) )
	{
   		p=dequeue(Q);
   		if( p->x==x2&&p->y==y2)
    		return p->step;
   		for(i=0;i<5;++i)
   		{
    		x0=p->x+loop[i][0];
    		y0=p->y+loop[i][1];
    		step=p->step+1;
    		flag=p->flag+1;
    		if(legal(x0,y0,flag)&&map[x0][y0]!='*'&&x0>=0&&x0<m&&y0>=0&&y0<n)
    		{
     			if(!mark[x0][y0][flag]&&!(x0==dog[flag].x&&y0==dog[flag].y))
     			{
      				mark[x0][y0][flag]=1;
			   		t=malloc(sizeof(struct point));
      				t->x=x0;
				    t->y=y0;
      				if(flag==D) 
					  flag=0;
      				t->flag=flag;
      				t->step=step;
      				enqueue(t,Q);
     			}
    		}
  		}
	}
return -1;
}	
main()
{
	int test,minstep;
	test=1;
	while(scanf("%d%d",&m,&n))
	{
		if(!m&&!n)
		break;
		if(test!=1)
		printf("\n");
		initialize();
		minstep=search();	      
		printf("Case %d:\n",test++);
		if(minstep<0)
		printf("No way out\n");
		else
		printf("Minimal time is: %d\n",minstep);
		disposequeue(Q);
	}
}