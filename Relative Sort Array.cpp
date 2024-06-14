class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        int j = 0;
        for (int i = 0; i < arr2.size(); i++) {
            mp[arr2[i]] = i;
            j=i;
        }
        vector<int> remaining;
        for(auto &it : arr1){
            if(!mp.count(it)){
                remaining.emplace_back(it);
            }
        }

        sort(remaining.begin(),remaining.end());
        for(auto &it :remaining){
            mp[it] = ++j;
        }
        sort(arr1.begin(),arr1.end(),[&](int a , int b){
            return mp[a] < mp[b];
        });

        return arr1;
    }
};
-----------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int> mp;
        for(auto &it : arr1){
            mp[it]++;
        }

        int idx = 0;
        vector<int> ans;
        while(idx < arr2.size()){
            if(mp[arr2[idx]]){
                ans.emplace_back(arr2[idx]);
                mp[arr2[idx]]--;
            }
            else idx++;
        }

        for(auto &[val,cnt] : mp){
            for(int i = 0; i< cnt;i++){
                ans.emplace_back(val);
            }
        }
        return ans;
    }
};
