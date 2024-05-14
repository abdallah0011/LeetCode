class Solution {
public:
    long long maximumHappinessSum(vector<int>& v, int k) {
        sort(v.rbegin(), v.rend());
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            ans += (v[i] - i) > 0 ? v[i] - i : 0;
        }
        return ans;
    }
};
