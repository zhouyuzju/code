#include <cstdio>
#include <algorithm>
#include <vector>
#define MAX 1000000000
using namespace std;
int main(){
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	int matrix[n][m];
	int sum = 0;
	vector<int> middle;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			scanf("%d",&matrix[i][j]);
			sum += matrix[i][j];
			middle.push_back(matrix[i][j]);
		}
	sort(middle.begin(),middle.end());
	int median1 = middle[m * n / 2 - 1];
	int median2 = middle[m * n / 2];
	int last = matrix[0][0],cost1 = 0,cost2 = 0;
	for(int i = 0;i < n;i++)
		for(int j = 0;j < m;j++){
			if(abs(matrix[i][j] - last) % d != 0){
				printf("-1\n");
				return 0;
			}
			last = matrix[i][j];
			cost1 += abs(matrix[i][j] - median1);
			cost2 += abs(matrix[i][j] - median2);
		}
	if(cost1 / d > cost2 / d)
		printf("%d\n",cost2 / d);
	else
		printf("%d\n",cost1 / d);
	return 0;
}
