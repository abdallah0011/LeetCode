class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix) {
        vector<int> ans;
        int mn = INT_MIN;
        for(auto &row: matrix){
            int tmp = *min_element(row.begin(),row.end());
            mn = max(mn,tmp);
        }

        int mx = INT_MAX;
        for(int j = 0; j < matrix[0].size(); j++){
            int tmp = INT_MIN;
            for(int i = 0; i < matrix.size(); i++){
                tmp = max(tmp, matrix[i][j]);
            }
            mx = min(mx, tmp);
        }
        return mn == mx ? vector<int>{mn} : vector<int>{};
    }
};
