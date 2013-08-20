#include <iostream>
#include <cstdio>
#include <vector>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

bool isBST(vector<int>&post,int* node,int rootIdx,int length,bool isMirror){
	if(length == 0)
		return true;
	else if(length == 1){
		post.push_back(node[rootIdx]);
		return true;
	}
	int leftLength = 0;
	for(int i = rootIdx + 1;i < rootIdx + length;i++,leftLength++)
		if(!isMirror && node[i] >= node[rootIdx])
			break;
		else if(isMirror && node[i] < node[rootIdx])
			break;
	for(int i = rootIdx + leftLength + 1;i < rootIdx + length;i++)
		if(!isMirror && node[i] < node[rootIdx])
			return false;
		else if(isMirror && node[i] >= node[rootIdx])
			return false;
	bool result = isBST(post,node,rootIdx + 1,leftLength,isMirror) && isBST(post,node,rootIdx + leftLength + 1,length - 1 - leftLength,isMirror);
	post.push_back(node[rootIdx]);
	return result;
}



int main(){
	int N;
	scanf("%d",&N);
	int preOrder[N];
	vector<int> postOrder;
	for(int i = 0;i < N;i++)
		scanf("%d",&preOrder[i]);
	bool result = isBST(postOrder,preOrder,0,N,false);
	if(!result){
		postOrder.clear();
		result = isBST(postOrder,preOrder,0,N,true);
	}
	if(result){
		printf("YES\n");
		for(int i = 0;i < postOrder.size();i++)
			printf("%d%c",postOrder[i],i == postOrder.size() - 1 ? '\n' : ' ');
	}
	else
		printf("NO\n");
	return 0;
}
