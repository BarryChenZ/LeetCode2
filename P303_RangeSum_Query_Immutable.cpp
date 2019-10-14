class NumArray {
public:
    vector<int> num;
    NumArray(vector<int>& nums) {
        num.assign(nums.begin(), nums.end());
    }
    
    int sumRange(int i, int j) {
        int ans = 0;
        for(int k = i; k <= j; k++){
            ans += num[k];
        }
        return ans;
    }
};
