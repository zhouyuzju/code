#include <cstdio>
#include <iostream>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	char foot[n + 1];
	int nl = 0,nr = 0;
	getchar();
	gets(foot);
	for(int i = 0;i < n;i++){
		if(foot[i] == 'L')
			nl++;
		else if(foot[i] == 'R')
			nr++;
	}
	if(nl == 0 || nr == 0){
		char c;
		//PR(nl);PR(nr);
		if(nl == 0)
			c = 'R';
		else
			c = 'L';	
		int s,t;
		//PR(c);
		bool flag = true;
		for(int i = 0;i < n;i++){
			//PR(foot[i]);
			if(foot[i] == c){
				//PR(s);
				//PR(t);
				if(flag)	
					s = i;
				t = i;
				flag = false;
			}
		}
		if(nl == 0)
			printf("%d %d\n",s + 1,t + 2);
		else
			printf("%d %d\n",t + 1,s);
	}
	else{
		int s,t;
		for(int i = 0;i < n;i++){
			//PR(foot[i]);
			if(foot[i] == 'R'){
				t = i;
				//PR(t);
			}
			else if(foot[i] == 'L'){
				s = i;
				//PR(s);
			}
		}
		printf("%d %d\n",s + 1,t + 2);
	}
	return 0;
}
