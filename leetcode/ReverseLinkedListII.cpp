class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if(head == NULL)
            return NULL;
        ListNode* node = head;
        ListNode* start;
        ListNode* end;
        ListNode* next;
        ListNode* startbefore = NULL;
        for(int i = 1;i <= n;i++){
            if(i == m - 1)
                startbefore = node;
            if(i == m)
                start = node;
            if(i == n)
                end = node;
            node = node->next;
        }
        next = end->next;
        ListNode* i = start;
        ListNode* j = start->next;
        while(j && i != end){
            ListNode* tmp = j->next;
            j->next = i;
            i = j;
            j = tmp;
        }
        if(startbefore)
            startbefore->next = end;
        else
            head = end;
        start->next = next;
        return head;
    }
};

