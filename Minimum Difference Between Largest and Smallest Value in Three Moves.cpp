class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());

        int a = nums[n-4] - nums[0]; // big 3
        int b = nums[n-1] - nums[3]; // small 3
        int c = nums[n-2] - nums[2]; // 2 left, 1 right
        int d = nums[n-3] - nums[1]; // 2 right, 1 left

        return min({a, b, c, d});
    }
};
