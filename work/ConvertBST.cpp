/**
 * Convert a BST into double linked list.
 */
#include <iostream>
#include <cstdio>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;

struct BSTNode{
	int value;
	BSTNode* left;
	BSTNode* right;
};

void Convert(BSTNode* root, BSTNode** lastNode){
	if(root == NULL)
		return;
	BSTNode* node = root;
	if(node->left != NULL)
		Convert(node->left, lastNode);
	node->left = (*lastNode);
	if((*lastNode) != NULL)
		(*lastNode)->right = node;
	(*lastNode) = node;
	if(node->right != NULL)
		Convert(node->right,lastNode);
}

BSTNode* ConvertBST(BSTNode* root){
	BSTNode* lastNode = NULL;
	Convert(root,&lastNode);
	BSTNode* node = lastNode;
	while(node != NULL && node->left != NULL)
		node = node->left;
	return node;
}



int main(){

	return 0;
}
