class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int>m;
        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) == m.end()){
                m[nums[i]] = 0;
            }
            m[nums[i]]++;
            if(m[nums[i]] == 1) ans.push_back(nums[i]);
            if(m[nums[i]] >  1) ans.erase(find(ans.begin(), ans.end(), nums[i]));
        }
        return ans;
    }
};
