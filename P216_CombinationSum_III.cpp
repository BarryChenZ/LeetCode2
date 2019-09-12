class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        Backtracking(ans, k, n, 0, 1, tmp);
        return ans;
    }
    void Backtracking(vector<vector<int>>& ans, int k, int n, int i, int x,  vector<int>& tmp){
        if(i == k && n == 0){
            ans.push_back(tmp);
            return;
        }
        if(i == k && n != 0) return;
        
        for(int j = x; j <= 9; j++){
            tmp.push_back(j);
            Backtracking(ans, k, n - j, i + 1, j + 1, tmp);
            tmp.pop_back();
        }
        return;
    }
};
