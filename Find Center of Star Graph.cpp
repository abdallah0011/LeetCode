class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int> mp;
        int ans = INT_MIN;
        for(auto edge : edges){
            mp[edge[0]]++, mp[edge[1]]++;
            ans = mp[edge[0]] > mp[edge[1]] ? edge[0] : edge[1];
        }
        return ans;
    }
};

---------------------------------------------------------------------------
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n1{edges[0][0]}, n2{edges[0][1]};
        int ans{};
        for(int i = 1; i < edges.size(); i++){
            if(n1 == edges[i][0] || n1 == edges[i][1]) ans = n1;
            else if(n2 == edges[i][0] || n2 == edges[i][1]) ans = n2;
        }
        return ans;
    }
};
---------------------------------------------------------------------------
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
    }
};

