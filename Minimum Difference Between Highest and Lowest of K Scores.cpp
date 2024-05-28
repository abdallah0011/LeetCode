class Solution {
public:
int minimumDifference(vector<int> &nums, int k) {
    if (k == 1) return 0;
    int ans = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i <= nums.size() - k; i++) {
        int dif = nums[i+k-1] - nums[i];
        ans = min(ans, dif);
    }

    return ans;
}
};
