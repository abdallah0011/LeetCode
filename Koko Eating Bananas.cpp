class Solution {
public:
    bool check(vector<int> &piles, int h, int mid){
        long long sum = 0;
        for(auto &pile : piles){
            sum += (pile + mid - 1)/mid;
            //sum += 1 + ((pile-1)/mid);
        }
        return h >= sum; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9, ans = INT_MAX;
        while(l<=r){
            int mid = l +(r-l)/2;
            if(check(piles,h,mid)){
                ans = min(ans,mid);
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return ans;
    }
};
