#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int x;
	int y;
	int cout;
	int action;
}dogpoint[51];
typedef struct node *type;
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
int direction[5][2]={-1,0,0,1,1,0,0,-1,0,0};
int array[51][51][51];
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
	dogpoint[0].x=x3;
	dogpoint[0].y=y3;
	dogpoint[0].action=0;
	for(i=1;i<=D;i++)
	{
		scanf("%c",&c);
		if( c=='G' ) 
   {
    dogpoint[i].x=dogpoint[i-1].x+direction[ dogpoint[i-1].action ][0];
    dogpoint[i].y=dogpoint[i-1].y+direction[ dogpoint[i-1].action ][1];
    dogpoint[i].action=dogpoint[i-1].action;
   } else if( c=='L' ) {
    dogpoint[i].x=dogpoint[i-1].x;
	dogpoint[i].y=dogpoint[i-1].y;
    dogpoint[i].action=( dogpoint[i-1].action-1+4) %4;
   } else if( c=='R' ) {
    dogpoint[i].x=dogpoint[i-1].x;
	dogpoint[i].y=dogpoint[i-1].y;
    dogpoint[i].action=(dogpoint[i-1].action+1)%4;
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
int legal(int x,int y,int action)
{
int i=dogpoint[action].x;
int j=dogpoint[action].y;
int result=0;
while(1)
{

   if( i<0 || i>=m || j<0 || j>=n ){
    result=1;
    break;
   }
   if( i==x && j==y ) {
    result=0;
    break;
   }
   if( map[i][j]=='*' ) {
    result=1;
    break;
   }
   i+=direction[ dogpoint[action].action ][0];
   j+=direction[ dogpoint[action].action ][1];
}
return result;
}
int search(void)
{
	int x0,y0,cout,action,i;
	type p,t;
	memset(array,0,sizeof(array));
	p=malloc(sizeof(struct node));
	p->x=x1;
	p->y=y1; 
	p->cout=0;
	p->action=0;
	array[p->x][p->y][p->action]=1;
	createqueue(1000);
	makeempty(Q);
	enqueue(p,Q);
	while( !isempty(Q) )
	{
   		p=dequeue(Q);
   		if( p->x==x2&&p->y==y2)
    		return p->cout;
   		for(i=0;i<5;++i)
   		{
    		x0=p->x+direction[i][0];
    		y0=p->y+direction[i][1];
    		cout=p->cout+1;
    		action=p->action+1;
    		if(legal(x0,y0,action)&&map[x0][y0]!='*'&&x0>=0&&x0<m&&y0>=0&&y0<n)
    		{
     			if(!array[x0][y0][action]&&!(x0==dogpoint[action].x&&y0==dogpoint[action].y))
     			{
      				array[x0][y0][action]=1;
			   		t=malloc(sizeof(struct node));
      				t->x=x0;
				    t->y=y0;
      				if(action==D) 
					  action=0;
      				t->action=action;
      				t->cout=cout;
      				enqueue(t,Q);
     			}
    		}
  		}
	}
return -1;
}	
main()
{
	int testcase,min;
	testcase=1;
	while(scanf("%d%d",&m,&n))
	{
		if(!m&&!n)
		break;
		if(testcase!=1)
		printf("\n");
		initialize();
		min=search();	      
		printf("Case %d:\n",testcase++);
		if(min<0)
		printf("No way out\n");
		else
		printf("Minimal time is: %d\n",min);
		disposequeue(Q);
	}
}