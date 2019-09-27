class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        int i = 0;
        while(matrix[i][0] <= target){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == target) return true;
                if(matrix[i][j] > target) break;
            }
            i++;
            if(i >= m) break;
        }
        return false;
    }
};
