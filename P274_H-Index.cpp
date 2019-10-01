class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        sort(citations.begin(), citations.end());
        int h = 0;
        for(int i = 0; i < citations.size(); i++){
            if(citations.size() - i < citations[i]){
                if(citations.size() - i > h) h = citations.size() - i;
            }
            if(citations.size() - i == citations[i]){
                if(citations[i] > h) h = citations[i];
            }
        }
        return h;
    }
};
