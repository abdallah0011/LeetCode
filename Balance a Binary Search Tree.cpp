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
    vector<int> nodes;
    void inorder(TreeNode * root){
        if(root == nullptr) return;
        inorder(root->left);
        nodes.emplace_back(root->val);
        inorder(root->right);
    }

    TreeNode* createBST(int start, int end){
        if(start > end) return NULL;
        int mid = (start+end)/2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = createBST(start, mid-1);
        root->right = createBST(mid+1, end);
        return root; 
    }
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root); // sorted vector  
        root = createBST(0, nodes.size()-1); // build the binary tree
        return root;
    }
};
