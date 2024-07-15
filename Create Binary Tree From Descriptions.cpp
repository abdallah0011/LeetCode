class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp; // {node (parent - child), val}
        int xr = 0; // taking xor of all nodes

        for(auto &node: descriptions){
            if(!mp.count(node[0])){
                TreeNode* parent = new TreeNode(node[0]);
                mp[node[0]] = parent;
                xr ^= node[0];
            }
            if(!mp.count(node[1])){
                TreeNode* child = new TreeNode(node[1]);
                mp[node[1]] = child;
                xr ^= node[1];
            }
            if(node[2] == 1) mp[node[0]]->left = mp[node[1]];
            else mp[node[0]]->right = mp[node[1]];
        }
        
        TreeNode* ans{};
        // remove all childs so the parent is left in xor variable
        for(auto &node : descriptions){
            xr ^= node[1];
        }
        ans = mp[xr];
        return ans;
    }
};
------------------------------------------------------------------------------------------------------
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp; // {node (parent - child), val}
        unordered_map<int, bool> isChild; // set descriptions[1] as a child

        for(auto &node: descriptions){
            if(!mp.count(node[0])){
                TreeNode* parent = new TreeNode(node[0]);
                mp[node[0]] = parent;
            }
            if(!mp.count(node[1])){
                TreeNode* child = new TreeNode(node[1]);
                mp[node[1]] = child;
            }
            if(node[2] == 1) mp[node[0]]->left = mp[node[1]];
            else mp[node[0]]->right = mp[node[1]];
            isChild[node[1]] = 1;
        }

        TreeNode* ans{};
        for(auto &node : descriptions){
            if(!isChild[node[0]]){
            ans = mp[node[0]]; 
            break;
            }
        }
        return ans;
    }
};
