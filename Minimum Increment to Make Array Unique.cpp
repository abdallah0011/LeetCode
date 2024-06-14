class Solution {
public:
    int minIncrementForUnique(vector<int> &nums) {
        int ans{0};
        sort(begin(nums), end(nums));
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) nums[i]++, ans++;
            else if (nums[i] < nums[i - 1]) {
                ans += nums[i-1] - nums[i] + 1;
                nums[i] += nums[i-1] - nums[i] + 1;
            }
        }

        return ans;
    }
};
