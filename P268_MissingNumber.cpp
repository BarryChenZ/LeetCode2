class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0, size = nums.size(), add = 0;   
        for(int i = 0; i < size; i++){
             sum += nums[i]; 
             add = size*(size + 1)/2;
        }
        return add - sum;
    }
};
