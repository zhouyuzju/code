class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if(head == NULL)
            return NULL;
        int n = 0;
        ListNode* node = head;
        ListNode* turn;
        while(node){
            n++;
            if(node)
                turn = node;
            node = node->next;
        }
        k = k % n;
        if(k == 0)
            return head;
        int cnt = 0;
        node = head;
        ListNode* last;
        while(node){
            cnt++;
            if(cnt == n - k)
                last = node;
            node = node->next;
        }
        ListNode* newHead = last->next;
        last->next = NULL;
        turn->next = head;
        return newHead;
    }
};

