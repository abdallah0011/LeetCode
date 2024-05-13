class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0, total = 0;
        unordered_set<int> st;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            if (st.find(nums[i]) != st.end()) {
                while (nums[j] != nums[i]) {
                    st.erase(nums[j]);
                    total -= nums[j++];
                }
                total -= nums[j++];
            }
            st.insert(nums[i]);
            total += nums[i];
            ans = max(ans, total);
        }
        return ans;
    }
};
