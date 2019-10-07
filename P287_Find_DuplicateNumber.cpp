class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int tmp = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == tmp) return nums[i];
            tmp = nums[i];
        }
        return tmp;
    }
};
