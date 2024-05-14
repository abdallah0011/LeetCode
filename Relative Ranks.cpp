class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> v(score.begin(), score.end());
        sort(v.rbegin(),v.rend());
        map<int, string> mp;
        vector<string> ans;
        for(int i = 0; i < v.size(); i++){
            if(i == 0) mp[v[i]] = "Gold Medal";
            else if(i == 1) mp[v[i]] = "Silver Medal";
            else if(i == 2) mp[v[i]] = "Bronze Medal";
            else mp[v[i]] = to_string(i+1);
        }

        for(auto &it : score){
            ans.push_back(mp[it]);
        }
        return ans;
    }
};
