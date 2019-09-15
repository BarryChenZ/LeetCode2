class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() <= 1) return false;
        multiset<long long> aSet;
        multiset<long long>::iterator aIter;
        
        for(int i = 0; i < nums.size(); i++){
            if (i > k) aSet.erase(nums[i - k - 1]);//k以外的距離刪除
            aIter = aSet.lower_bound((long long)nums[i] - (long long)t);
            if (aIter != aSet.end()){
                if (abs((long long)nums[i] - *aIter) <= (long long)t) {
                    return true;
                }
            }
            aSet.insert((long long)nums[i]);
        }
        return false;
    }
};
/*
map<string, int>::iterator iter;
	for(iter=dict.begin();iter!=dict.end();iter++)
		cout<<iter->first<<ends<<iter->second<<endl;
*/
