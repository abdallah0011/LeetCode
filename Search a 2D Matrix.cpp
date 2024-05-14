class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(auto & row : matrix){
            auto it = lower_bound(row.begin(),row.end(),target ) - row.begin();
            if (it < row.size() && row[it] == target) return true;
        }

        return false;
    }
};
