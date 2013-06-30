/**
 * Construct a binary tree by two given sequences each represents the pre-order and in-order traverse of that tree
 * Input:
 * 	PreOrder: {1,2,4,7,3,5,6,8}
 * 	InOrder: {4,7,2,1,5,3,8,6}
 * Output:
 *	the root of that tree
 */
#include <cstdio>
#include <iostream>
#include <exception>
#define PR(x) cout << #x << " = " x << endl
using namespace std;
struct BinaryTreeNode{
	int value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

struct illegalArgumentExeption : exception { 
	char const* what() const throw(); 
};

BinaryTreeNode* recursive(int* preOrderStart, int* preOrderEnd, int* inOrderStart, int* inOrderEnd){
	BinaryTreeNode* root = new BinaryTreeNode();
	int rootValue = preOrderStart[0];
	root->value = rootValue;
	root->left = NULL;
	root->right = NULL;
	
	if(preOrderStart == preOrderEnd){
		if(inOrderStart == inOrderEnd && *preOrderEnd == *inOrderStart)
			return root;
		else
			printf("Illegal input.\n");
	}
	//find the value in the in-order sequence
	int* rootInOrder = inOrderStart;
	while(rootInOrder <= inOrderEnd && *rootInOrder != rootValue)
		rootInOrder++;
	if(rootInOrder == inOrderEnd && *rootInOrder != *inOrderEnd)
		printf("Illegal input.\n");

	int length = rootInOrder - inOrderStart;
	if(length > 0){
	//construct left sub tree
		root->left = recursive(preOrderStart + 1, preOrderStart + length, inOrderStart, rootInOrder - 1);
	}
	if(inOrderEnd - rootInOrder > 0){
	//construct right sub tree
		root->right = recursive(preOrderStart + length + 1, preOrderEnd, rootInOrder + 1,inOrderEnd);
	}
	return root;
}

BinaryTreeNode* construct(int* preOrder, int* inOrder, int length){
	if(preOrder == NULL || inOrder == NULL || length <= 0)
		printf("Illegal input.\n");
	return recursive(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}

void printPostOrder(BinaryTreeNode* root){
	if(root == NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	printf("%d ",root->value);
}

int main(){
	int preOrder[8] = {1,2,3,4,5,6,7,8};
	int inOrder[8] = {1,2,3,4,5,6,7,8};
	int preOrder1[1] = {1};
	int inOrder1[1] = {1};
	printPostOrder(construct(preOrder1, inOrder1,1));
	return 0;
}
