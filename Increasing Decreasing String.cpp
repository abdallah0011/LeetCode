class Solution {
public:
    string sortString(string s) {
        unordered_map<char, int> mp;
        int cnt = 0;
        for (auto& it : s)
            mp[it]++, cnt++;

        string ans;
        while (cnt) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (mp[c]){
                    ans.push_back(c);
                    cnt--, mp[c]--;
                }
            }
            for (char c = 'z'; c >= 'a'; c--) {
                if (mp[c]){
                    ans.push_back(c);
                    cnt--, mp[c]--;
                }
            }
        }
        return ans;
    }
};
