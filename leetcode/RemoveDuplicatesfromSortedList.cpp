class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode* i = head;
        ListNode* j = head->next;
        while(j){
            if(i->val == j->val){
                ListNode* next = j->next;
                i->next = next;
                j->next = NULL;
                delete j;
                j = next;
            }
            else{
                i = j;
                j = j->next;
            }
        }
        return head;
    }
};

