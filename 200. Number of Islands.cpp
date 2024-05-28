class Solution {
public:
    void BFS(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> q;
        vector<int> offsets{0, 1, 0, -1, 0};
        q.push({i, j});
        while (!q.empty()) {
          auto [r,c] = q.front();
          q.pop();
          for(int k = 0; k <4;k++){
            int x = r + offsets[k];
            int y = c + offsets[k+1];
            if(x >=0 && x < grid.size() && y >=0 && y < grid[0].size() && grid[x][y] == '1'){
                grid[x][y] = '0';
                q.push({x,y});
            }
          }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid[0].size(), m = grid.size();
        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    grid[i][j] = 0;
                    BFS(grid, i, j);
                }
            }
        }
        return ans;
    }
};
-------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;

        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }
        return ans;
    }

private:
    void dfs(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() ||  grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '0';    // visited
        dfs(grid, i + 1, j); // up
        dfs(grid, i - 1, j); // down
        dfs(grid, i, j + 1); // right
        dfs(grid, i, j - 1); // left
    }
};
