class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL)
            return NULL;
        ListNode* node = head;
        int l = 0;
        while(node->next){
            node = node->next;
            l++;
        }
        construct(head,0,l);
    }
private:
    TreeNode* construct(ListNode* &head,int start,int end){
        if(start > end)
            return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* left = construct(head,start,mid - 1);
        TreeNode* node = new TreeNode(head->val);
        node->left = left;
        head = head->next;
        TreeNode* right = construct(head,mid + 1,end);
        node->right = right;
        return node;
    }
};

