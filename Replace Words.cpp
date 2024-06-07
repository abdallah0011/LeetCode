class Solution {
public:
    string fun(unordered_set<string>& dict, string& word) {
        for (int i = 1; i <= word.length(); i++) {
            string str = word.substr(0, i);
            if (dict.contains(str)) {
                return str;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        string word{}, ans{};
        unordered_set<string> dict{dictionary.begin(), dictionary.end()};
        istringstream stream(sentence);

        while (getline(stream, word, ' ')) {
            ans += fun(dict, word) + ' ';
        }
        ans.pop_back();
        return ans;
    }
};
