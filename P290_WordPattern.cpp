class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> pat;
        vector<string> s;
        string word;
        stringstream iss(str);
        while(iss >> word)
            s.push_back(word);
        if(pattern.size() != s.size())
            return false;
        set<string> seen;
        for(int i = 0; i < pattern.size(); i++)
        {
            if(pat.count(pattern[i]) == 0)
            {
                pat[pattern[i]] = s[i];
                if(seen.find(s[i]) == seen.end())
                    seen.insert(s[i]);
                else return false;
            }
           else if(pat[pattern[i]] != s[i])
                return false;
           
        }
        return true;
    }
};
