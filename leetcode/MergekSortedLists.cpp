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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode* head = new ListNode(0);
        ListNode* next = head;
        while(true){
            bool flag = false;
            int val = INT_MAX,idx;
            ListNode* minNode;
            for(int i = 0;i < lists.size();i++){
                if(lists[i] != NULL && lists[i]->val <= val){
                    minNode = lists[i];
                    flag = true;
                    val = lists[i]->val;
                    idx = i;
                }
            }
            if(!flag)
                break;
            next->next = minNode;
            next = minNode;
            lists[idx] = lists[idx]->next;
        }
        return head->next;
    }
};

