class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
  	    vector<int> dp;
  	    dp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            int pos = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            cout << pos;
  		    if(pos == dp.size()) dp.push_back(nums[i]);
  		    else dp[pos] = nums[i];
        }
        return dp.size();
    }
};
