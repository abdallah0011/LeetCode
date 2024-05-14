class Solution {
public:
    int partitionString(string s) {
        set<char> st;
        int ans = 0;
        for(auto &it : s){
            if(st.find(it) != st.end()){
                st.clear();
                ans++;
            }
            st.insert(it);
        }
        return ++ans;
    }
};

-------------------------------------------------------------------------------------------------------------
class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> st;
        int ans = 1;
        for(auto &it : s){
            if(st.find(it) != st.end()){
                st.clear();
                ans++;
            }
            st.insert(it);
        }
        return ans;
    }
};
