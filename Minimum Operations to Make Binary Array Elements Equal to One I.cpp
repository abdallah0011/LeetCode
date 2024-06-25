class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int ones = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                int j = i;
                int k = 3;
                if(j+3 <= n){
                    while(k--){
                        nums[j] = !nums[j];
                        j++;
                    }
                    ones += (nums[i] == 1);
                    ans++;
                }
                else break;
            }
            else ones++;
        }

        return ones == n ? ans : -1;
    }
};
---------------------------------------------------------
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0, n = nums.size();
        for(int i = 0; i < n-2; i++){
            if(nums[i] == 0) {
                ans++;
                nums[i+1] = !nums[i+1];
                nums[i+2] = !nums[i+2];
            }
        }
        return nums[n-1] && nums[n-2] ? ans : -1;
    }
};
