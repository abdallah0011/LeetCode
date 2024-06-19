class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        vector<pair<int, int>> p;
        for (int i = 0; i < difficulty.size(); i++) {
            p.emplace_back(difficulty[i], profit[i]);
        }
        sort(p.begin(), p.end());
        sort(worker.begin(), worker.end());

        int i = 0, ans = 0, mx = 0;
        for(auto &w : worker){
            while(i < profit.size() && w>= p[i].first){
                mx = max(p[i++].second, mx);
            }
            ans += mx;
        }
        return ans;
    }
};

----------------------------------------------------------------------------------------------------------
class Solution {
public:
    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker) {
        vector<pair<int, int>> p;
        for (int i = 0; i < difficulty.size(); i++) {
            p.emplace_back(difficulty[i], profit[i]);
        }

        sort(p.begin(), p.end());
        for (int i = 1; i < p.size(); i++) {
            p[i].second = max(p[i].second, p[i - 1].second);
        }
        int ans = 0;
        for (auto &w: worker) {
            auto it = upper_bound(p.begin(), p.end(), make_pair(w,INT_MAX)) - p.begin();
            ans += (it>0) ? p[it-1].second : 0;
        }
        return ans;
    }
};
