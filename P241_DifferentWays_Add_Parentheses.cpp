class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        return helper(0, input.size() - 1, input);
    }
    vector<int> helper(int l, int r, string inp){
        string sub = inp.substr(l, r - l + 1);
        if(sub.find_first_of("+-*") == string::npos) return vector<int>(1, stoi(sub));
        vector<int> res;
        int i = l;
        while(i != string::npos && i < r){
            i = inp.find_first_of("+-*", i + 1);
            if (i == string::npos || i > r) break;
            
            vector<int> left  = helper(l, i - 1, inp);
            vector<int> right = helper(i + 1, r, inp);
            
            if(inp[i] == '+'){
                for (int li: left) {
                    for (int ri: right) {
                        res.push_back(li + ri);
                    }
                }
            }
            else if(inp[i] == '-'){
                for (int li: left) {
                    for (int ri: right) {
                        res.push_back(li - ri);
                    }
                }
            }
            else if (inp[i] == '*') {
                for (int li: left) {
                    for (int ri: right) {
                        res.push_back(li * ri);
                    }
                }
            }
        }
        return res;
    }
};
