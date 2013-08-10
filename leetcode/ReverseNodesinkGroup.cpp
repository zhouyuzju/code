/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <cstdio>
using namespace std;
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        if(head == NULL || k <= 1)
            return head;
        ListNode* newHead = new ListNode(0);
        ListNode* next = newHead;
        ListNode* node = head;
        while(node){
            int cnt = 0;
            ListNode* start = node;
            ListNode* end = node;
            while(end){
                cnt++;
                if(cnt == k)
                    break;
                end = end->next;
            }
            if(cnt == k){
                ListNode* first = start;
                ListNode* second = first->next;
		ListNode* nextGroup = end->next;
                while(first != end){
                    ListNode* tmp = second->next;
                    second->next = first;
                    first = second;
                    second = tmp;
                }
                next->next = end;
                next = start;
                start->next = nextGroup;
                node = nextGroup;
            }
            else
                break;
        }
	if(newHead->next == NULL)
		newHead->next = head;
        return newHead->next;
    }
};
int main(){
	ListNode* head = new ListNode(1);
	ListNode* tail = new ListNode(2);
	head->next = tail;
	Solution* s = new Solution();
	ListNode* newHead = s->reverseKGroup(head,2);
	while(newHead){
		printf("%d\n",newHead->val);
		newHead = newHead->next;
	}
	return 0;
}
