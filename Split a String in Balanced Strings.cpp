class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0, ans = 0;
        for(auto &it : s){
            if(it == 'R') cnt++;
            else if (it == 'L') cnt--;
            if(!cnt) ans++;
        }
        return ans;
    }
};
