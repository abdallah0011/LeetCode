/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* postOrder(TreeNode* root, unordered_set<int>& st, vector<TreeNode*>& ans){
        if(!root) return nullptr;
        root->left = postOrder(root->left, st, ans);
        root->right = postOrder(root->right, st, ans);
        if(st.find(root->val) != st.end()){
            if(root->left) ans.emplace_back(root->left);
            if(root->right) ans.emplace_back(root->right);
            
            delete root;
            return nullptr;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        root = postOrder(root, st, ans);
        if(root) ans.emplace_back(root);
        
        return ans;
    }
};
------------------------------------------------------------------------------------------------
class Solution {
public:
    void postOrder(TreeNode* &root, unordered_set<int>& st, vector<TreeNode*>& ans){
        if(!root) return;
        postOrder(root->left, st, ans);
        postOrder(root->right, st, ans);
        if(st.find(root->val) != st.end()){
            if(root->left) ans.emplace_back(root->left);
            if(root->right) ans.emplace_back(root->right);
            root = nullptr;
            delete root;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> st(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        postOrder(root, st, ans);
        if(root) ans.emplace_back(root);
        
        return ans;
    }
};
