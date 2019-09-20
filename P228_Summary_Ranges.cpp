class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) { 
        vector<string> ans;
        if(nums.size() == 0) return ans; 
        vector<int> temp;
        temp.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            if((long)nums[i] - (long)nums[i - 1] > 1){
                input(ans, temp);
                temp.clear();
            }
            temp.push_back(nums[i]);
        }
        if(!temp.empty()) input(ans, temp);
        return ans;
    }
    void input(vector<string>& ans, vector<int>& temp){
        int n = temp.size();
        if(n == 1){
            ans.push_back(to_string(temp[0]));
        }
        else{
                ans.push_back( to_string(temp.front()) + "->" + to_string(temp.back()) );
        }
    }
};
