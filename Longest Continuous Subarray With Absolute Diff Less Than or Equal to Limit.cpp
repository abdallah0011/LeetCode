class Solution {
public: 
    int longestSubarray(vector<int> &arr, int limit) {
        int ans = 0 , cnt = 0;
        int n = arr.size();
        multiset<int> st;
        for(int i = 0, j = 0; i < n; i++){
            st.insert(arr[i]); // O(logn)
            while(*st.rbegin() - *st.begin() > limit){
                st.extract(arr[j++]); // O(logn)
            } 
            ans = max(ans, (int)st.size());
        }
        return ans;
    }
};
