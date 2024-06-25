class Solution {
public:
    bool check(vector<int> &position, int m, int mid){
        int prev = position[0];
        m--; // place first ball
        for(int i = 1; i < position.size() && m > 0; i++){
            if(position[i] - prev >= mid){
                m--;
                prev = position[i];
            }
        }
        return m == 0;
    }
    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(),position.end());
        int l = 1 , r = 1e9, ans = 0;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(check(position, m, mid)){
                ans = mid;
                l = mid + 1;
            }else{
                r= mid -1;
            }
        }
        return ans;
    }
};
