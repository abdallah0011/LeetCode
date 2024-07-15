class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string,int>> stk;
        stk.push(unordered_map<string,int>());

        int idx = 0;
        while(idx < formula.length()){
            if(formula[idx] == '('){
                stk.push(unordered_map<string,int>());
                idx++;
            } else if(formula[idx] == ')'){ // add nested formula to newMap 
                unordered_map<string, int> currMap = stk.top();
                stk.pop();
                idx++;
                string multiplier{}; 
                // find the multiplier of nested formula
                while(idx < formula.length() && isdigit(formula[idx])){
                    multiplier += formula[idx++];
                }
                // multiply nested formula by multiplier
                if(!multiplier.empty()){
                    int m = stoi(multiplier);
                    for(auto &[atom, freq]: currMap) currMap[atom] *= m;
                }
                // add atoms to ansMap
                for(auto &[atom, freq]: currMap){
                    stk.top()[atom] += freq;
                }
            }else{ // UPPERCASE letter
                string curAtom{};
                curAtom += formula[idx++];
                while(idx < formula.length() && islower(formula[idx])){
                    curAtom += formula[idx++];
                }
                
                string curCount{};
                while(idx < formula.length() && isdigit(formula[idx])){
                    curCount += formula[idx++];
                }
                int c = curCount.empty() ? 1 : stoi(curCount);
                stk.top()[curAtom] += c;
            }
        }

        // sort finalMap
        map<string,int> ansMap(stk.top().begin(),stk.top().end());
        string ans{};
        
        for(auto &[atom, freq]: ansMap){
            ans += atom;
            if(freq > 1) ans += to_string(freq);
        }
        return ans;
    }
};
