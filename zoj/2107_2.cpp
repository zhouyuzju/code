#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct 
{ 
	double x, y;
} pttype;
const long maxsize = 100000;
long arr[maxsize], arrl;
pttype pt[maxsize];
int sortcmp(const void *a, const void *b) 
{ 
	if (((pttype*)a)->x < ((pttype*)b)->x)   
	return -1;   
	else return 1; 
}
double dist(pttype a, pttype b) 
{ 
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)); 
}
double getmin(double a, double b) 
{ 
	if (a > b) return b;   else return a; 
}
int arrcmp(const void *a, const void *b) 
{ 
	if (pt[*(int*)a].y < pt[*(int*)b].y)    
	return -1;   
	else return 1; 
}
double shortest(long l, long r) 
{ 
	if (r - l == 1) 
	return dist(pt[l], pt[r]);   
	if (r - l == 2)    
	return getmin(getmin(dist(pt[l], pt[l+1]), dist(pt[l], pt[r])), dist(pt[l+1], pt[r]));
	long i, j, mid = (l + r) >> 1;   
	double curmin = getmin(shortest(l, mid), shortest(mid + 1, r));   
	arrl = 0;   
	for (i = mid; i >= l && pt[mid+1].x - pt[i].x <= curmin; i --)    
	arr[arrl++] = i;   
	for (i = mid + 1; i <= r && pt[i].x - pt[mid].x <= curmin; i ++)    
	arr[arrl++] = i;   
	qsort(arr, arrl, sizeof(arr[0]), arrcmp);   
	for (i = 0; i < arrl; i ++)    
	for (j = i + 1; j < arrl && pt[arr[j]].y - pt[arr[i]].y <= curmin; j ++)     
	curmin = getmin(curmin, dist(pt[arr[i]], pt[arr[j]]));   
	return curmin; 
}
main() 
{ 
	long n, i;  
	while (1)   
	{
		scanf("%d", &n);      
		if (!n) 
		break;      
		for (i = 0; i < n; i ++)       
		scanf("%lf%lf", &pt[i].x, &pt[i].y);      
		qsort(pt, n, sizeof(pt[0]), sortcmp);      
		printf("%.2lf\n", shortest(0, n - 1) / 2);    
	} 
}