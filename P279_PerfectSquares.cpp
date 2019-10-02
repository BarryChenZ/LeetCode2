class Solution {
public:
    int numSquares(int n) {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; i++){
            int least_num = INT_MAX;
            int k = int(sqrt(i));
            for(int j = 1; j <= k; j++){
                //if(j * j > i) break;
                least_num = min(dp[i - j * j] + 1, least_num);
            }
            dp[i] = least_num;
        }
        return dp[n];
    }
};
