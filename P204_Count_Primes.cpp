class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
    
        vector<bool> vec(n, false);
        int sum = 1;
        for (int i = 3; i < n; i += 2) {       //省去2
	        if (!vec[i]) {
		        sum++;
                for(int j = 3; i * j < n; j += 2)  vec[i*j] = 1;
	        }
        }
    return sum;
    }
};
