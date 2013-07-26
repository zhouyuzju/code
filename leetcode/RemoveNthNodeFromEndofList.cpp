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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(n <= 0 || head == NULL)
            return head;
        ListNode*i = head, *j = head, *before = NULL;
        int cnt = n - 1;
        while(cnt > 0 && i){
            i = i->next;
            cnt--;
        }
        if(i == NULL)
            return head;
        while(i->next){
            before = j;
            i = i->next;
            j = j->next;
        }
        if(before == NULL)
            head = j->next;
        else
            before->next = j->next;
        return head;
    }
};

