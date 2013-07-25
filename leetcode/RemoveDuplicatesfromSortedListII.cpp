class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* newHead = new ListNode(0);
        newHead->next = head;
        ListNode* pre = newHead, *cur = head;
        while(cur){
            int val = cur->val;
            if(cur->next && val == cur->next->val){
                while(cur && cur->val == val){
                    pre->next = cur->next;
                    delete cur;
                    cur = pre->next;
                }
            }
            else{
                pre = cur;
                cur = cur->next;
            }
        }
        return newHead->next;
    }
};

