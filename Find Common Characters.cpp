class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;
        for(auto &c :words[0]){
            int exist = 1;
            for(int i = 1; i < words.size();i++){
                auto it = words[i].find(c);
                if(it == string::npos){
                    exist = 0;
                    break;
                }
                else{
                    words[i].erase(it, 1);
                }
            }
            if(exist) ans.emplace_back(string(1,c));
        }
        return ans;
    }
};
