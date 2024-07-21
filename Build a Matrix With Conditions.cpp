class Solution {
public:
    vector<int> toplogicalSort(int k, vector<vector<int>>& list){
        vector<vector<int>> adj(k+1);
        vector<int> indegree(k+1);
        for(auto &edge: list){
            adj[edge[0]].emplace_back(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i = 1; i <= k; i++){
            if(indegree[i] == 0) q.push(i);
        }   

        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.emplace_back(node);

            for(auto &it : adj[node]){
                if(--indegree[it] == 0) q.push(it);
            }
        }
        return ans.size() == k ? ans : vector<int>{};
    }

    vector<vector<int>> help(int k, vector<int>& rows, vector<int>& cols){
        vector<vector<int>> matrix(k, vector<int>(k,0));
        for(int i = 0; i < k; i++){
            for(int j = 0; j < k; j++){
                if(rows[i] == cols[j]) matrix[i][j] = rows[i];
            }
        }
        return matrix;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rows = toplogicalSort(k, rowConditions);
        vector<int> cols = toplogicalSort(k, colConditions);

        if(rows.empty() || cols.empty()) return {};
        vector<vector<int>> ans = help(k, rows, cols);
        return ans;
    }
};
