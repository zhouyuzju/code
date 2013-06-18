/**
 * print the reverse order of given linked list
 */

#include <cstdio>
#include <iostream>
#include <stack>
#define PR(x) cout << #x << " = " << x << endl
using namespace std;
struct ListNode{
	int value;
	ListNode* next;
};


void printRec(ListNode* head){
	if(head != NULL){
		if(head->next != NULL)
			printRec(head->next);
		PR(head->value);
	}
}

void printStack(ListNode* head){
	stack<ListNode*> nodes;
	ListNode* node = head;
	while(node != NULL){
		nodes.push(node);
		node = node->next;
	}
	while(!nodes.empty()){
		node = nodes.top();
		PR(node->value);
		nodes.pop();
	}
}

int main(){
	ListNode* head = new ListNode();
	head->value = 1;
	head->next = new ListNode();
	head->next->value = 2;
	head->next->next = NULL;
	printRec(head->next);
	printStack(head->next);
	return 0;
}
