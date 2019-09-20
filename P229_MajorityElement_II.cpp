class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.size() <= 1) return nums;
        vector<int> ans;
        unordered_map<int,int> m;
        int times = nums.size()/3;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 1;
                if(m[nums[i]] > times) {
                    ans.push_back(nums[i]);
                    m[nums[i]] = -INT_MAX;
                }
            }
            else{
                m[nums[i]]++;
                if(m[nums[i]] > times) {
                    ans.push_back(nums[i]);
                    m[nums[i]] = -INT_MAX;
                }
            }
        }
        return ans;
    }
};
