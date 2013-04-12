#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int t[101],w[101];
vector<int> one,two;

bool myfunc(int a,int b){
	return a > b;
}

int cal(int a,int b){
	int total = a + 2 * b;
	int cost = 0;
	for(int i = a;i < one.size();i++)
		cost += one[i];
	for(int i = b;i < two.size();i++)
		cost += two[i];
	if(total >= cost)
		return total;
	else
		return -1;
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d%d",&t[i],&w[i]);
		if(t[i] == 1)
			one.push_back(w[i]);
		else
			two.push_back(w[i]);
	}
	sort(one.begin(),one.end(),myfunc);
	sort(two.begin(),two.end(),myfunc);
	int total = 10000000;
	for(int i = 0;i <= one.size();i++)
		for(int j = 0; j <= two.size();j++){
			int tmptotal = cal(i,j);
			if(tmptotal > 0 && total > tmptotal)
				total = tmptotal;
		}
	printf("%d\n",total);
	return 0;
}
