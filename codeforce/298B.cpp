#include <cstdio>
#include <iostream>
#define PR(x) cout << #x << " = " << x <<endl
using namespace std;

int main(){
	int n,sx,sy,ex,ey;
	scanf("%d%d%d%d%d",&n,&sx,&sy,&ex,&ey);
	int nh = ex - sx,nv = ey - sy;
	char ch,cv,wind[n + 1];
	if(nh > 0)
		ch = 'E';
	else
		ch = 'W';
	if(nv > 0)
		cv = 'N';
	else
		cv = 'S';
	nh = nh > 0 ? nh : -nh;
	nv = nv > 0 ? nv : -nv;
	int count = 0;
	getchar();
	gets(wind);
	for(int i = 0;i < n;i++){
		//PR(nh);PR(nv);PR(wind[i]);
		if(nh == 0 && nv == 0)
			break;
		else if(nh > 0 && wind[i] == ch){
			nh--;
			count++;
		}
		else if(nv > 0 && wind[i] == cv){
			nv--;
			count++;
		}
		else if(nv > 0 || nh > 0){
			count++;
		}
	}
	if(nh > 0 || nv > 0)
		printf("-1\n");
	else 
		printf("%d\n",count);

}
