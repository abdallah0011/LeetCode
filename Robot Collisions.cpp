class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions) {
        int n = positions.size();
        vector<int> ind(n), stk;
        iota(ind.begin(), ind.end(), 0);
        sort(ind.begin(), ind.end(), [&](int lhs, int rhs) {
            return positions[lhs] < positions[rhs];
        });

        for (auto &idx: ind) {
            if (directions[idx] == 'R') {
                stk.emplace_back(idx);
                continue;
            }
            while (!stk.empty() && healths[idx] > 0) { // 'L' remove all 'R' in stack while having health
                if (healths[stk.back()] == healths[idx]) {
                    healths[stk.back()] = 0, stk.pop_back();
                    healths[idx] = 0;
                } else if (healths[stk.back()] > healths[idx]) {
                    healths[stk.back()] -= 1;
                    healths[idx] = 0;
                } else {
                    healths[stk.back()] = 0, stk.pop_back();
                    healths[idx] -= 1;
                }
            }
        }

        vector<int> ans;
        for (auto &robot: healths) {
            if (robot > 0) ans.emplace_back(robot);
        }
        return ans;
    }
};
