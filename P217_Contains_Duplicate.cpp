class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) == m.end()) m[nums[i]] = true;
            else return true;
        }
        return false;
    }
};
