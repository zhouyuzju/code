class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1 == NULL && l2 == NULL)
            return NULL;
        else if(l1 == NULL && l2 != NULL)
            return l2;
        else if(l1 != NULL && l2 == NULL)
            return l1;
        ListNode* head;
        ListNode* last;
        if(l1->val < l2->val){
            head = l1;
            last = l1;
            l1 = l1->next;
        }
        else{
            head = l2;
            last = l2;
            l2 = l2->next;
        }
        while(l1 != NULL && l2 != NULL){
            if(l1->val < l2->val){
                last->next = l1;
                last = l1;
                l1 = l1->next;
            
            }
            else{
                last->next = l2;
                last = l2;
                l2 = l2->next;
            }
            
        }
        if(l1 != NULL)
            last->next = l1;
        if(l2 != NULL)
            last->next = l2;
        return head;
    }
};

