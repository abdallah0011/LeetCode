class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int ans = 0, mx = 0;
        int n = customers.size();

        for (int i = 0, j = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                ans += customers[i];
            } else {
                j = i;
                int cnt = 0 , sum = 0;
                while (cnt < minutes && j < n) {
                    if (grumpy[j] == 1) sum += customers[j];
                    j++, cnt++;
                }
                mx = max(mx, sum);
            }
        }

        return ans + mx;
    }
};

---------------------------------------------------------------------------------------------

class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int ans = 0, mx = 0, sum = 0;
        int n = customers.size();

        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) ans += customers[i];
            else sum+= customers[i];
            if(i >= minutes && grumpy[i-minutes] == 1) sum-= customers[i-minutes];
            mx = max(mx, sum);
        }
        return ans + mx;
    }
};
