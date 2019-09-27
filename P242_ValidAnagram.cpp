class Solution {
public:
    bool isAnagram(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        if(ns != nt) return false;
        unordered_map<char, int> m;
        for(int i = 0; i < ns; i++){
            if(m.find(s[i]) == m.end()){
                m[s[i]] = 0;
            }
            m[s[i]]++;
        }
        for(int i = 0; i < nt; i++){
            if(m.find(t[i]) == m.end()) return false;
            else{
                m[t[i]]--;
                if(m[t[i]] < 0) return false;
            }
        }
        return true;
    }
};
