class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> nums;
    MedianFinder() {
        nums.clear();
    }
    
    void addNum(int num) {
        nums.insert(num);
    }
    
    double findMedian() {
        int n = nums.size(), i = 0, f, g;
        for(auto &e : nums){
            if (n % 2 == 1 && i == n/2) {
                return e;
            }
            if (n % 2 == 0 && i == n/2-1) {
                f = e;
            } else if (n % 2 == 0 && i == n/2) {
                g = e;
                break;
            }
            i++;
        }
        return (double)(g+f)/2;
    }
};
