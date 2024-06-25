class Solution {
public:
    void GST(TreeNode *root, int& sum){
        if(root == nullptr) return;
        GST(root->right, sum);
        root->val += sum;
        sum = root->val;
        GST(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        GST(root, sum);
        return root;
    }
};
