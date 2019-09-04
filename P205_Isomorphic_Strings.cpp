class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        bool ans = true;
        unordered_map<char, char> mfront;
        unordered_map<char, char> mback;
        for(int i = 0; i < n; i++){
            if(mfront.find(s[i]) != mfront.end()){
                if(mfront[s[i]] != t[i]){
                    ans = false;
                    break;
                }
            }
            else{
                mfront[s[i]] = t[i];
            }
            if(mback.find(t[i]) != mback.end()){
                if(mback[t[i]] != s[i]){
                    ans = false;
                    break;
                }
            }
            else{
                mback[t[i]] = s[i];
            }
        }
        return ans;
    }
};
