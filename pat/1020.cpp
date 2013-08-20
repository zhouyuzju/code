#include <iostream>
#include <cstdio>
#include <queue>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* construct(int* postorder, int* inorder,int lo,int hi,int k){
	if(lo > hi)
		return NULL;
	int mid;
	for(int i = lo;i <= hi;i++)
		if(inorder[i] == postorder[k]){
			mid = i;
			break;
		}
	TreeNode* node = new TreeNode(inorder[mid]);
	if(mid > lo)
		node->left = construct(postorder,inorder,lo,mid - 1,k - (hi - mid) - 1);
	if(mid < hi)
		node->right = construct(postorder,inorder,mid + 1,hi,k - 1);
	return node;
}

int main(){
	int n;
	scanf("%d",&n);
	int postorder[n],inorder[n],levelorder[n];
	for(int i = 0;i < n;i++)
		scanf("%d",&postorder[i]);
	for(int i = 0;i < n;i++)
		scanf("%d",&inorder[i]);
	TreeNode* root = construct(postorder,inorder,0,n - 1,n - 1);
	queue<TreeNode*> aqueue;
	int idx = 0;
	aqueue.push(root);
	while(aqueue.size() > 0){
		TreeNode* node = aqueue.front();
		aqueue.pop();
		levelorder[idx++] = node->val;
		if(node->left)
			aqueue.push(node->left);
		if(node->right)
			aqueue.push(node->right);
	}
	for(int i = 0;i < n;i++)
		printf("%d%c",levelorder[i],i == n - 1 ? '\n' : ' ');
	return 0;
}
