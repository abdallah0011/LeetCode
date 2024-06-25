class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, ans = 0;
        int n = nums.size(), prefixZeros = 0;
        for(int i = 0, j = 0; i < n; i++){
            sum +=nums[i];
            while(j < i && (sum > goal || nums[j] == 0)){
                if(nums[j] == 0) prefixZeros++;
                else prefixZeros = 0;
                sum -= nums[j++];
            }
            if(sum == goal) ans += 1 + prefixZeros;
        }
        return ans;
    }
};
