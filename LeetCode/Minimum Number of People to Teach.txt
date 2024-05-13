class Solution {
public:
    int check(vector<vector<int>>& languages, int f1, int f2) {
        set<int> lang;
        for (int i : languages[f1]) {
            lang.insert(i);
        }
        for (int i : languages[f2]) {
            if (lang.count(i) > 0) return true;
        }
        return false;
    }
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        set<int> ans;
        for(auto &v : friendships){
            int a = v[0];
            int b = v[1];
            if(check(languages, a-1,b-1)) continue;
            cout << a  << " "  << b << '\n';
            ans.insert(a-1);
            ans.insert(b-1);
        }
        vector<int> freq(n);
        int mx = 0;
        for (auto& it : ans) {
            for (auto& lang : languages[it]) {
                freq[lang - 1]++;
                mx = max(mx, freq[lang - 1]);
            }
        }
        cout << ans.size() << ' ' << mx << '\n';
        return ans.size() - mx; 
    }
};
