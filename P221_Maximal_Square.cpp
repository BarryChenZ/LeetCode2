class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int aWidth = matrix.size();
        if (aWidth <= 0) return 0;
        
        int aHeight = matrix[0].size();
        if (aHeight <= 0) return 0;
        
        int aDynamic[aWidth][aHeight];
        memset(aDynamic, 0, sizeof(aDynamic));
        
        int aResult = 0;
        for (int aX = 0; aX < aWidth; aX++) {
            if (matrix[aX][0] == '1') {
                aDynamic[aX][0] = 1;
                aResult = 1;
            }
        }
        
        for (int aY = 0; aY < aHeight;aY++) {
            if (matrix[0][aY] == '1') {
                aDynamic[0][aY] = 1;
                aResult = 1;
            }
        }
        
        int aPos1, aPos2, aPos3, aValue;
        
        for(int i = 1; i < aWidth; i++){
            for(int j = 1; j < aHeight; j++){
                if(matrix[i][j] == '1'){
                    aPos1 = aDynamic[i - 1][j];
                    aPos2 = aDynamic[i][j - 1];
                    aPos3 = aDynamic[i - 1][j - 1];
                    
                    aValue = aPos1;
                    if(aValue > aPos2) aValue = aPos2;
                    if(aValue > aPos3) aValue = aPos3;
                    
                    aValue++;
                    
                    aDynamic[i][j] = aValue;
                
                    if (aValue > aResult) {
                        aResult = aValue; 
                    }
                }
            }
        }
        return aResult * aResult;
    }
};
