class Solution {
public:

    int minPartitions(string n) {
        char ans = '0';
        for(auto &it : n) if (it > ans) ans = it;

        return ans - '0';
    }
};

-----------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
    int minPartitions(string n) { 
        return *max_element(begin(n), end(n)) - '0'; 
    }
};
