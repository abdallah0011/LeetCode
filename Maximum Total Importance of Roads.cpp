class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>> &roads) {
        map<int, int> mp;
        vector<int> v(n);
        priority_queue<pair<int, int>, vector<pair<int, int>> > pq;
        for (auto &row: roads) {
            mp[row[1]]++;
            mp[row[0]]++;
        }

        for(auto &[road,cnt]: mp){
            pq.push({cnt, road});
        }

        while(!pq.empty()){
            auto [cnt, road] = pq.top();
            v[road] = n--;
            pq.pop();
        }
        long long ans = 0;
        for (auto &row: roads) {
            ans += v[row[0]] + v[row[1]];
        }
        return ans;
    }
};

------------------------------------------------------------------------------------
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>> &roads) {
        vector<long long> freq(n, 0);
        for (auto &road: roads) {
            freq[road[0]]++;
            freq[road[1]]++;
        }

        sort(freq.rbegin(), freq.rend());
        long long ans = 0;
        for (auto road: freq) {
            ans += road * n--;
        }
        return ans;
    }
};
