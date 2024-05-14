class Solution {
public:
    int minimumOperationsToMakeKPeriodic(string word, int k) {
        unordered_map<string, int> mp;
        int mx = 0;
        string str;
        for (int i = 0; i < word.size(); i++) {
            str.push_back(word[i]);
            if (str.size() == k) {
                mp[str]++;
                mx = max(mp[str], mx);
                str.clear();
            }
        }

        /* remove most frequent substr of size (k) from word string then the remaining string 
           is changed with the most frequent substr of size (k);
        */
        return (word.size() - (mx * k)) / k;
    }
};
