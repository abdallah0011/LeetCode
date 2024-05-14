class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mp;
        vector<int> ans;
        for (int i = 0; i < s.size(); i++)
            mp[s[i]] = i;
        for (int i = 0, j = 0, mx = 0; i < s.size(); i++) {
            mx = max(mx, mp[s[i]]); // expand the size of current partiton 
            if (mx == i)
                ans.push_back(i - j + 1), j = i + 1;
        }
        return ans;
    }
};
