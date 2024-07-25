class Solution {
public:
    void merge_sort(auto l, auto r, vector<int> &cnt, vector<pair<int, int>> &v) {
        if (r - l <= 1) return;
        auto mid = l + (r - l) / 2;
        merge_sort(l, mid, cnt, v);
        merge_sort(mid, r, cnt, v);
        for (auto i = l, j = mid; i < mid; i++) {
            while (j < r && i->first > j->first) j++; // find inversions v[i] > v[j]  
            cnt[i->second] += j - mid;
        }
        inplace_merge(l, mid, r); // array [begin, middle) is merged with array [middle, end)
    }

    vector<int> countSmaller(vector<int> &nums) {
        vector<pair<int, int>> v;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            v.emplace_back(make_pair(nums[i], i));
        }
        vector<int> cnt(n, 0);
        merge_sort(v.begin(), v.end(), cnt, v);
        return cnt;
    }
};
