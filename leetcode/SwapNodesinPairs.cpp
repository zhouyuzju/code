/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* next = newHead, *first = head, *second = head->next;
        while(true){
            next->next = first;
            if(first == NULL)
                break;
            second = first->next;
            if(second){
                ListNode* tmp = second->next;
                next->next = second;
                second->next = first;
                next = first;
                first = tmp;
            }
            else
                break;
        }
        return newHead->next;
    }
};

