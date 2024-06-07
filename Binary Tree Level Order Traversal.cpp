class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto node = q.front();
                q.pop();
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                v.emplace_back(node->val);
            }
        ans.emplace_back(v);
        }
        return ans;
    }
};
