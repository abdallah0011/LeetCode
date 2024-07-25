class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> mp;
        int n = names.size();
        for(int i = 0 ; i < n; i++){
            mp[heights[i]] = names[i];
        }
        vector<string> ans(n);
        int idx = n-1;
        for(auto &[height, name]: mp){
            ans[idx--] = name;
        }
        return ans;
    }
};
