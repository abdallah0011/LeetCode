class Solution {
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load) {
        set<int> freeServers;
        map<int, int> mp;
        for (int i = 0; i < k; i++) {
            freeServers.insert(i);
        }

        set<pair<int, int>> busyServers;
        for (int i = 0; i < arrival.size(); i++) {
            while (!busyServers.empty() && busyServers.begin()->first <= arrival[i]) {
                auto server = *busyServers.begin();
                busyServers.erase(server);
                freeServers.insert(server.second);
            }
            if (freeServers.empty()) continue;

            int idx = -1;
            auto it = freeServers.lower_bound(i%k);
            if (it == freeServers.end()) {
                idx = *freeServers.begin();
                freeServers.erase(freeServers.begin());
            } else {
                idx = *it;
                freeServers.erase(it);
            }
            busyServers.insert({arrival[i] + load[i], idx});
            mp[idx]++;
        }

        int mx = INT_MIN;
        vector<int> ans;
        for (auto &[val, busy]: mp) {
            mx = max(mx, busy);
        }
        for (auto &[val, busy]: mp) {
            if (busy == mx) ans.emplace_back(val);
        }

        return ans;
    }
};
