class Solution {
public:
    void inorder(TreeNode *root, vector<int>& ans){
        if(!root) return;
        inorder(root->left, ans);
        ans.emplace_back(root->val);
        inorder(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};

------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode *> stk;
        vector<int> ans;
        TreeNode* cur = root;
        while(cur || !stk.empty()){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            ans.push_back(cur->val);
            stk.pop();
            cur = cur->right;
        }
        return ans;
    }
};
