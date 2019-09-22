class Solution {
public:
    bool isPowerOfTwo(int n) {
        int tmp = n;
        if(n == 0) return false;
        if(n == 1) return true;
        while(tmp != 1){
            if(tmp%2 != 0) return false;
            tmp = tmp/2;
        }
        return true;
    }
};
