class Solution {
public:
    int compress(vector<char>& chars) {
        int ans = 0;
        for (int i = 0; i < chars.size();) {
            int cnt = 0;
            char curLetter = chars[i];
            while (i < chars.size() && chars[i] == curLetter) {
                cnt++, i++;
            }
            chars[ans++] = curLetter;
            if (cnt > 1) {
                for (const auto& it : to_string(cnt))
                    chars[ans++] = it;
            }
        }

        return ans;
    }
};
