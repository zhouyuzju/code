class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        int carry = 0;
        ListNode* i = l1, *j = l2;
        ListNode* head = new ListNode(0);
        ListNode* next = head;
        while(i && j){
            int digit = (i->val + j->val + carry) % 10;
            carry = (i->val + j->val + carry) / 10;
            ListNode* node = new ListNode(digit);
            next->next = node;
            next = node;
            i = i->next;
            j = j->next;
        }
        ListNode* rest = i ? i : j;
        while(rest){
            int digit = (rest->val + carry) % 10;
            carry = (rest->val + carry) / 10;
            ListNode* node = new ListNode(digit);
            next->next = node;
            next = node;
            rest = rest->next;
        }
        if(carry == 1){
            ListNode* node = new ListNode(1);
            next->next = node;
        }
        return head->next;
    }
};

