class Solution {
public:
    string lt20(int n) {
        static const char* _w[20] = {"",
            "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", 
            "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", 
            "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" 
        };
        return _w[n%20];
    }
    
    string lt100(int n) {
        static const char* _w[8] = {
            "Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"
        };
        n %= 100;
        if (n < 20) return lt20(n);
        int m = n % 10;
        string s = lt20(m), tmp = _w[(n/10)%10 - 2];
        return s.empty() ? tmp : tmp + " " + s;
    } 
    
    string lt1000(int n) {
        n %= 1000;
        int m = n/100;
        string s = lt100(n-m*100);
        if (m > 0)
            return lt20(m) + (s.empty() ? " Hundred" : " Hundred " + s);
        else 
            return lt100(n);
    }
     
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        const int B=1000*1000*1000, M=1000*1000, T=1000;
        string result;
        if (num >= B) {
            result.append(lt1000(num/B) + " Billion"); 
            num -= (num/B)*B;
        }
        
        if (num >= M) {
            if (!result.empty()) result.append(" ");
            result.append(lt1000(num/M) + " Million");
            num -= (num/M)*M;
        }
        
        if (num >= T) {
            if (!result.empty()) result.append(" ");
            result.append(lt1000(num/T) + " Thousand");
            num -= (num/T)*T;
        }
        
        if (num > 0) {
            if (!result.empty()) result.append(" ");
            result.append(lt1000(num));
        }
        
        return result;
    }
};
