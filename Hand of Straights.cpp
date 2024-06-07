class Solution {
public:
    bool isNStraightHand(vector<int> &hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        
        map<int, int> mp;
        for (auto &val: hand) {
            mp[val]++;
        }

        while (!mp.empty()) {
            int curCard = mp.begin()->first;
            for (int i = 0; i < groupSize; i++) {
                if (mp[curCard + i] == 0) return false;
                mp[curCard + i]--;
                if (mp[curCard + i] == 0) mp.erase(curCard + i);
            }
        }
        return true;
    }
};
