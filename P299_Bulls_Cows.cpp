class Solution {
public:
    string getHint(string secret, string guess) {
        int counterA = 0;
        int counterB = 0;
        unordered_map<char,int> myMap;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) 
                ++counterA;
            else 
                ++myMap[secret[i]];
        }

        for (int i = 0; i < guess.size(); ++i)
            if (guess[i] != secret[i] && myMap.count(guess[i]) > 0) {
                if (--myMap[guess[i]] == 0) 
                    myMap.erase(guess[i]);
                
                ++counterB;
            }

        string result = "";
        result += to_string(counterA) + "A" + to_string(counterB) + "B";
        
        return result;
    }
};
