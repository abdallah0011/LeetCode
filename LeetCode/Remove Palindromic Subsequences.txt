class Solution {
public:
    bool check(string s) {
        int n = s.length();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - i - 1])
                return false;
        }
        return true;
    }
    int removePalindromeSub(string s) {
        if (check(s))
            return 1;
        else
            return 2;
    }
};
