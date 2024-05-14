class Solution {
public:
    int minimumSum(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        int sz = s.size();
        string v1, v2;
        v1.push_back(s[0]), v1.push_back(s[sz - 1]);
        v2.push_back(s[1]), v2.push_back(s[sz - 2]);
        return stoi(v1) + stoi(v2);
    }
};
