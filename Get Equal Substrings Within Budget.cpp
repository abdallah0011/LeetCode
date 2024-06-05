class Solution {
public:
int equalSubstring(string s, string t, int maxCost) {
    int cur = 0, cnt = 0, ans = 0;
    queue<int> q;
    for (int i = 0, j = 0; i < s.length(); i++) {
        int dif = abs(s[i] - t[i]);
        cur += dif;
        q.push(dif);
        if (cur > maxCost) {
            while (cur > maxCost) {
                cur -= q.front();
                q.pop();
            }
        } 
        ans = max(ans, (int)q.size());
    }
    return ans;
}
};
------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0 , j =0;
        for (; i < s.length(); i++) {
            maxCost -= abs(s[i] - t[i]);
            if(maxCost < 0) maxCost += abs(s[j]- t[j++]);
        }
        return i - j;
    }
};
