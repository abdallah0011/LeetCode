class Solution {
public:
    void dfs(vector<vector<int>> &adj, set<int> &tmp, int node) {
        for (auto &edge: adj[node]) {
            if (tmp.count(edge)) continue;
            tmp.insert(edge);
            dfs(adj, tmp, edge);
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n, vector<int>());
        set<int> tmp{};
        vector<vector<int>> ans{};

        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][1]].emplace_back(edges[i][0]);
        }

        for (int i = 0; i < n; i++) {
            dfs(adj, tmp, i);
            ans.push_back(vector(tmp.begin(), tmp.end()));
            tmp.clear();
        }
        return ans;
    }
};
---------------------------------------------------------------------------------
class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<vector<int>> &ans, int ancestor, int curNode) {
        for (auto &edge: adj[curNode]) {
            if (ans[edge].empty() || ans[edge].back() != ancestor) {
                ans[edge].emplace_back(ancestor);
                dfs(adj, ans, ancestor, edge);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n), ans(n);

        for (auto &edge: edges) {
            adj[edge[0]].emplace_back(edge[1]);
        }

        for (int i = 0; i < n; i++) {
            dfs(adj, ans, i, i);
        }

        return ans;
    }
};
