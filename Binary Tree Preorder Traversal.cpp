class Solution {
public:
    void preorder(TreeNode *node, vector<int>& ans){
        if(!node) return;
        ans.push_back(node->val);
        preorder(node->left, ans);
        preorder(node->right, ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }
};
-------------------------------------------------------------
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (!stk.empty() || cur) {
            if (cur) {
                ans.emplace_back(cur->val);
                if (cur->right) stk.push(cur->right);
                cur = cur->left;
            }
            else {
                cur = stk.top();
                stk.pop();
            }
        }
        return ans;
    }
};
