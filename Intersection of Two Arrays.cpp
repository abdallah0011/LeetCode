class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        if (nums2.size() > nums1.size())
            swap(nums1, nums2);

        vector<int> ans;
        map<int, int> mp;
        for (int i = 0, j = 0; i < nums1.size(); i++) {
            if (j < nums2.size() && nums2[j] < nums1[i]) {
                while (j < nums2.size() && nums2[j] < nums1[i])
                    j++;
            }
            if (j < nums2.size() && nums1[i] == nums2[j] && !mp[nums1[i]]) {
                ans.push_back(nums1[i]), j++;
                mp[nums1[i]]++;
            }
        }
        return ans;
    }
};
-----------------------------------------------------------------------------------------------------------------------------------
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(),nums1.end());
        vector<int> ans;
        for(auto &val: nums2){
            if(st.count(val)){
                ans.emplace_back(val);
                st.erase(val);
            }
        }
        return ans;
    }
};
