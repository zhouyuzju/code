/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
            return;
        lr(root);
        r(root);
    }
private:
    void lr(TreeLinkNode* root) {
        if(root->left == NULL || root->right == NULL)
            return;
        root->left->next = root->right;
        TreeLinkNode* ll = root->left->right;
        TreeLinkNode* rr = root->right->left;
        while(ll){
            ll->next = rr;
            ll = ll->right;
            rr = rr->left;
        }
        lr(root->left);
        lr(root->right);
    }
    void r(TreeLinkNode* root) {
        if(root == NULL)
            return;
        root->next = NULL;
        r(root->right);
    }
};

