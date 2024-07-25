class Solution {
public:
    int help(vector<int> &mapping, int num) {
        string s = to_string(num);
        string tmp{};
        for (auto &c: s) {
            tmp += mapping[c - '0'] + '0';
        }
        return stoi(tmp);
    }

    vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
        vector<pair<int, int>> mappedValues;
        for (int i = 0; i < nums.size(); i++) {
            mappedValues.push_back({help(mapping, nums[i]), i});
        }
        sort(mappedValues.begin(), mappedValues.end());
        vector<int> ans;
        for (auto &[num, idx]: mappedValues) {
            ans.emplace_back(nums[idx]);
        }

        return ans;
    }
};
