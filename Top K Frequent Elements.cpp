
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (auto& it : nums)
            mp[it]++;

        vector<pair<int, int>> v;
        for (auto& it : mp)
            v.push_back({it.first, it.second});

        sort(v.begin(), v.end(), [](pair<int, int>& a, pair<int, int>& b){
            return a.second > b.second;
        });
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    static bool sort_by_freq(pair<int, int>& a, pair<int, int>& b) {
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (auto& it : nums)
            mp[it]++;

        vector<pair<int, int>> v(mp.begin(), mp.end());
        sort(v.begin(), v.end(), sort_by_freq);

        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].first);
        }

        return ans;
    }
};
