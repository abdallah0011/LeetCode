class Solution {
public:
    int minOperations(vector<string>& logs) {
        int moves = 0;
        for(string operation : logs){
            if(isalpha(operation[0]) || isdigit(operation[0])) moves++;
            else if(operation[1] == '.' && moves > 0) {  // "../"
                moves--;
           }
        }
        return moves;
    }
};
----------------------------------------------------------------------------
class Solution {
public:
    int minOperations(vector<string>& logs) {
        int moves = 0;
        for(string operation : logs){
            if(operation[1] == '.') moves = max(--moves, 0);
            else if(operation != "./") moves++;
        }
        return moves;
    }
};
