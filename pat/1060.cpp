#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

int main(){
	int N;
	char A[105],B[105];
	scanf("%d%s%s",&N,A,B);
	int la,lb;
	char* tmp1 = strstr(A,".");
	int ii = 0,jj = 0;
	while(A[ii] == '0' || A[ii] == '.')
		ii++;
	while(B[jj] == '0' || B[jj] == '.')
		jj++;
	if(tmp1 == NULL)
		la = strlen(A) - ii;
	else{
		if(ii >= strlen(A))
			la = 0;
		else if(*(tmp1 - 1) == '0'){
			int cnt = 0;
			while(*(++tmp1) == '0')
				cnt++;
			la = -cnt;
		}
		else
			la = tmp1 - A - ii;
	}
	char* tmp2 = strstr(B,".");
	if(tmp2 == NULL)
		lb = strlen(B) - jj;
	else{
		if(jj >= strlen(B))
			lb = 0;
		else if(*(tmp2 - 1) == '0'){
			int cnt = 0;
			while(*(++tmp2) == '0')
				cnt++;
			lb = -cnt;

		}
		else
			lb = tmp2 - B - jj;
	}
	vector<int> d1,d2;
	int cnt = 0;
	for(int i = 0;cnt < N;i++){
		if(ii + i >= strlen(A)){
			d1.push_back(0);
			cnt++;
		}
		else{
			if(A[ii + i] == '.')
				continue;
			d1.push_back(A[ii + i] - '0');
			cnt++;
		}
	}
	cnt = 0;
	for(int i = 0;cnt < N;i++){
		if(jj + i >= strlen(B)){
			d2.push_back(0);
			cnt++;
		}
		else{
			if(B[jj + i] == '.')
				continue;
			d2.push_back(B[jj + i] - '0');
			cnt++;
		}
	}
	bool equal = true;
	if(d1.size() != d2.size())
		equal = false;
	else{
		for(int i = 0;i < d1.size();i++)
			if(d1[i] != d2[i]){
				equal = false;
				break;
			}
	}
	if(equal && la == lb){
		printf("YES 0.");
		for(int i = 0;i < d1.size();i++)
			printf("%d",d1[i]);
		printf("*10^%d\n",la);
	}
	else{
		printf("NO 0.");
		for(int i = 0;i < d1.size();i++)
			printf("%d",d1[i]);
		printf("*10^%d 0.",la);
		for(int i = 0;i < d2.size();i++)
			printf("%d",d2[i]);
		printf("*10^%d\n",lb);
	}
	return 0;
}
//000001 000.000001
//00000.00000 0001
