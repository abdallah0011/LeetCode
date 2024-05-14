class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size() - 2;
        vector<vector<int>> ans(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int row = i; row < i + 3; row++) {
                    for (int col = j; col < j + 3; col++) {
                        ans[i][j] = max(ans[i][j], grid[row][col]);
                    }
                }
            }
        }
        return ans;
    }
};
