class Solution {
public:
int findPermutationDifference(string s, string t) {
    map<int, int> mp;
    for (int i = 0; i < s.length(); i++) {
        mp[s[i]] = i;
    }

    int ans = 0;
    for (int i = 0; i < t.length(); i++) {
        ans += abs(mp[t[i]] - i);
    }
    return ans;
}
};
