class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> ans;
        if(size == 0) return {};
        int l = 0;
        int r = 0 + k - 1;
        int max_pos = 0;
        max_pos = max_position(l, r, nums);
        while(r < size){
            if(max_pos < l) max_pos = max_position(l, r, nums);
            if(nums[max_pos] < nums[r]) max_pos = r;
            ans.push_back(nums[max_pos]);
            l++;
            r++;
        }
        return ans;
    }
    int max_position(int l, int r, vector<int>& nums){
        int i = l;
        for(int j = l; j < r; j++){
            if(nums[j] > nums[i]) i = j;
        }
        return i;
    }
};
