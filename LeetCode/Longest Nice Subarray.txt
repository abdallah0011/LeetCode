class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 0, num = 0;
        for(int i = 0, j = 0; i < nums.size(); i++){
            while((num&nums[i]) != 0){
                num ^= nums[j++]; // remove bits of prev num
            }
            num |= nums[i]; // add current number bits 
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};

