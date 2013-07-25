class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(num.size() == 0)
            return NULL;
        return constructTree(num,0,num.size() - 1);   
    }
private:
    TreeNode* constructTree(vector<int> &num,int start,int end){
        if(start == end)
            return new TreeNode(num[start]);
        else if(end - start == 1){
            TreeNode* root = new TreeNode(num[start]);
            TreeNode* right = new TreeNode(num[end]);
            root->right = right;
            return root;
        }
        int mid = (start + end) / 2;
        TreeNode* node = new TreeNode(num[mid]);
        node->left = constructTree(num,start,mid - 1);
        node->right = constructTree(num,mid + 1,end);
        return node;
    }
};

