class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if(head == NULL)
            return NULL;
        ListNode* node = head;
        ListNode* before = NULL;
        while(node && node->val < x){
            before = node;
            node = node->next;
        }
        ListNode* small = new ListNode(-1);
        ListNode* next = small;
        ListNode* ori = before;
        ListNode* begin = node;
        if(node == NULL)
            return head;
        while(node){
            while(node && node->val >= x){
                before = node;
                node = node->next;
            }
            if(!node)
                break;
            before->next = node->next;
            node->next = NULL;
            next->next = node;
            next = node;
            node = before->next;
        }
        if(ori == NULL){
            next->next = head;
            return small->next;
        }
        else{
            if(small->next){
                ori->next = small->next;
                next->next = begin;
            }
            return head;
        }
    }
};

