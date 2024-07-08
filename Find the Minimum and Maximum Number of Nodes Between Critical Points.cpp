class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head) {
        ListNode *prev = head;
        ListNode *cur = head->next;
        vector<int> points;
        int idx = 1;
        while (cur) {
            if (cur->next && (min(cur->next->val, prev->val) > cur->val ||
                              max(cur->next->val, prev->val) < cur->val)) {
                points.emplace_back(idx);
            }
            prev = cur;
            cur = cur->next;
            idx++;
        }
        if (points.size() < 2) return vector<int>{-1, -1};

        int mx = points.back() - *points.begin(), mn = INT_MAX;
        for (int i = 1; i < points.size(); i++) {
            mn = min(mn, points[i] - points[i - 1]);
        }

        return vector<int>{mn, mx};
    }
};
