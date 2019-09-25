class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0) return 0;
        long base = 1, ans = 1;
        while((base *= 10) <= n) {
            long oldAns = ans;
            if(n / base < 10) ans += countDigitOne(n % base);
            ans += (n / base >= 10 ? 8 : max(int(n / base) - 2, 0)) * oldAns;//let first not be one
            ans += n / base == 1 ? n % base + 1 : base + oldAns; //let first be one
        }
        return ans;
    }
    
};
