class Solution {
public:
    int ans = 0;
    string greedy(string s, char a, char b, int x) {
        string stk{};
        for (auto ch : s) {
            if (!stk.empty() && stk.back() == a && ch == b) {
                stk.pop_back(), ans += x;
            } else
                stk.push_back(ch);
        }
        return stk;
    }
    int maximumGain(string s, int x, int y, char a = 'a', char b = 'b') {
        if (y > x) {
            swap(x, y);
            swap(a, b);
        }
        auto s1 = greedy(s, a, b, x), s2 = greedy(s1, b, a, y);
        return ans;
    }
};

----------------------------------------------------------------------------
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans{}, firstScore{}, secondScore{};
        string stk{}, first{}, second{};

        if (x < y) {
            first = "ba", second = "ab";
            firstScore = y, secondScore = x;
        } else {
            first = "ab", second = "ba";
            firstScore = x, secondScore = y;
        }

        for (auto &c: s) {
            if (!stk.empty() && stk.back() == first[0] && c == first[1]) {
                ans += firstScore, stk.pop_back();
            } else {
                stk.push_back(c);
            }
        }

        string stk2{};
        for (char c : stk) {
            if (!stk2.empty() && stk2.back() == second[0] && c == second[1]) {
                ans += secondScore;
                stk2.pop_back();
            } else {
                stk2.push_back(c);
            }
        }
        return ans;
    }
};
---------------------------------------------------------------------------------
