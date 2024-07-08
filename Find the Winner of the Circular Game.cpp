class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        int idx = 0;
        while (v.size() > 1) {
            int out = (idx + k - 1) % v.size();
            v.erase(v.begin() + out);
            idx = out;
        }
        return v.back();
    }
};
------------------------------------------------------------

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i = 1; i <= n; i++) q.push(i);

        while(q.size() > 1){
            int c = k;
            while(c-- > 1){
                int f = q.front();
                q.pop(), q.push(f);
            }
            q.pop();
        }
        return q.front();
    }
};
