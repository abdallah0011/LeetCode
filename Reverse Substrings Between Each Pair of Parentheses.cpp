class Solution {
public:
    string reverseParentheses(string s) {
        string stk{};
        for (auto &c: s) {
            if (c == ')') {
                string reversed{};
                while (stk.back() != '(') {
                    reversed.push_back(stk.back());
                    stk.pop_back();
                }
                stk.pop_back();
                stk += reversed;
            } else stk.push_back(c);
        }
        return stk;
    }
};
