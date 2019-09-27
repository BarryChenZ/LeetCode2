class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long num = 1;
        int NumOfZero = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) NumOfZero++;
            else             num *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(NumOfZero > 1) nums[i] = 0;
                else              nums[i] = num;
            }
            else{
                if(NumOfZero >= 1) nums[i] = 0;
                else               nums[i] = num/nums[i];
            }
        }
        return nums;
    }
};
