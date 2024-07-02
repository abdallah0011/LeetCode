class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        for(int i = 0; i < n; i++){
            if(arr[i] & 1 && i + 2 < n){
                if ((arr[i+1] & 1) && (arr[i+2] & 1)) return true;
            }
        }
        return false;
    }
};
-----------------------------------------------------------------------

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int odds = 0;
        for(int i = 0; i < arr.size() && odds < 3; i++){
            odds = arr[i] & 1 ? odds + 1 : 0;
        }
        return odds == 3;
    }
};
