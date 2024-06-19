class Solution {
public:
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        long long ans = INT_MIN, sum = 0;

        vector<pair<int, int>> v;
        for (int i = 0; i < nums1.size(); i++) {
            v.emplace_back(nums2[i], nums1[i]);
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto [n2, n1]: v) {
            sum += n1;
            pq.emplace(n1);
            if (pq.size() > k) sum -= pq.top(), pq.pop();
            if (pq.size() == k) ans = max(ans, sum * n2);
        }
        return ans;
    }
};
