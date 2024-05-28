class Solution {
public:
    int specialArray(vector<int>& nums) {
        int i = 0, j = nums.size();
        while(i<=j){
            int md = i+ (j-i)/2;
            int cnt = 0;
            for(auto &val : nums){
                if(val >= md) cnt++;
            }
            if(cnt == md) return md;
            else if(md < cnt) i = md+1;
            else j = md -1;
        }
        return -1;
    }
};
--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int specialArray(vector<int>& nums) {
        for(int i = 1; i <= 1000;i++){
            int cnt = 0;
            for(auto &val : nums){
                if(i <= val) cnt++;
            }
            if(cnt == i) return i;
        }
        return -1;
    }
};

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int arr[1001]{};
        for(int num: nums) arr[num]++;
        int total = nums.size();
        for(int i = 0; i <= 1000;i++){
            if(i == total) return i;
            total -=arr[i];
        }
        return -1;
    }
};
