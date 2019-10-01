class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 1 && citations[0] <= 1) return citations[0];
        for(int i = 0; i < citations.size(); ++i) {
            if(citations.size() - i <= citations[i]) return citations.size() - i;
        }
        return 0;
    }
};
