class Solution {
public:
    void solve(string& word, int idx) {
        for (int i = 0; i <= idx/2; i++) {
            swap(word[i], word[idx - i]);
        }
    }
    string reversePrefix(string word, char ch) {
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                solve(word, i);
                return word;
            }
        }
        return word;
    }
};
