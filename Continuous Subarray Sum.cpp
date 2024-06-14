class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int prefix = 0;
        mp[0] = -1;
        for (int i = 0; i < nums.size(); i++) {
            prefix = (prefix + nums[i]) % k;
            // if(prefix == 0 && i>=1) return true; // instead of mp[0] = -1
            if (mp.count(prefix)) {
                if (i - mp[prefix] > 1) return true;
            } else {
                mp[prefix] = i;
            }
        }
        return false;
    }
};
