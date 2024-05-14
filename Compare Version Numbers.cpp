class Solution {
public:
    int compareVersion(string v1, string v2) {

        int i = 0, j = 0;
        while (i < v1.size() || j < v2.size()) {
            string s1 = "0", s2 = "0";
            while(i < v1.size() && v1[i] != '.') s1.push_back(v1[i++]);
            while(j < v2.size() && v2[j] != '.') s2.push_back(v2[j++]);
            int a = stoi(s1);
            int b = stoi(s2);
            if(a > b) return 1;
            if(a < b) return -1;
            i++,j++;
        }

        return 0;
    }
};
