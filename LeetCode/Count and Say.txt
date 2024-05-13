class Solution {
public:
    string solve(string s) {
        string ans;
        for (int i = 0, j = 0; i < s.size(); i++) {
            int cnt = 0;
            while (s[j] == s[i]) {
                j++, cnt++;
            }
            ans.push_back(cnt + '0');
            ans.push_back(s[i]);
            i = j - 1;
        }

        return ans;
    }

    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string s = "1";
        for (int i = 2; i <= n; i++) {
            s = solve(s);
        }
        return s;
    }
};
