class Solution {
    int ans = 0;
public:
    void dfs(vector<vector<char>>& board, string word, int i, int j,
             int word_idx) {
        // cout << board[i][j] << " " << word[word_idx] << '\n';
        if (i < 0 || i == board.size() || j < 0 || j == board[0].size() ||
            board[i][j] != word[word_idx]) {
            return;
        }

        
        if (word[word_idx] == board[i][j] && word_idx + 1 == word.size()) {
            ans = 1; // true
            return;
        }

        board[i][j] = '0';
        dfs(board, word, i + 1, j, word_idx + 1);
        dfs(board, word, i - 1, j, word_idx + 1);
        dfs(board, word, i, j - 1, word_idx + 1);
        dfs(board, word, i, j + 1, word_idx + 1);
        board[i][j] = word[word_idx];
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0, word_idx = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    dfs(board, word, i, j, word_idx);
                }
            }
        }

        return ans;
    }
};
