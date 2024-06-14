class Solution {
public:
    void solve(TreeNode* root, int& ans, int depth) {
        if (!root) {
            ans = max(ans, depth);
            return;
        }
        solve(root->right, ans, depth + 1);
        solve(root->left, ans, depth + 1);
    }
    int maxDepth(TreeNode* root) {
        int ans = 0, depth = 0;
        solve(root, ans, depth);
        return ans;
    }
};
