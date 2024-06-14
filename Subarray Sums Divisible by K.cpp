class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int prefix = 0, ans = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i] % k + k) % k;
            ans += mp[prefix];
            mp[prefix]++;
        }
        return ans;
    }
};
