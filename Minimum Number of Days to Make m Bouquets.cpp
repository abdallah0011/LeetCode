class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(((long)k*m) > bloomDay.size()) return -1;
        
        int l = 0, r = 1e9, ans = INT_MAX;
        while(l<=r){
            int mid = l+(r-l)/2;
            int cnt = 0, flower = 0;
            for(auto day : bloomDay){
                if(day <= mid) flower++;
                else flower = 0;
                if(flower == k) cnt++, flower =0; 
            }
            if(cnt < m) l = mid +1;
            else{
                r = mid -1;
                ans = min(ans, mid);
            }
        }

        return ans;
    }
};
