class Solution {
public:
vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq) {
    vector<long long> ans;
    unordered_map<int, long long> mp;
    priority_queue<pair<long long, int>> maxHeap;

    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]] += freq[i];
        maxHeap.emplace(mp[nums[i]], nums[i]);
        while (!maxHeap.empty() && mp[maxHeap.top().second] != maxHeap.top().first) maxHeap.pop();
        ans.push_back(maxHeap.top().first);
    }
    return ans;
}
};
