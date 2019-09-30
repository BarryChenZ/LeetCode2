class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
		set<long long> s;
		s.insert(1);
		for (auto it = s.begin(); s.size() < 1800 && it != s.end(); it++) {
			s.insert((*it) * 2);
			s.insert((*it) * 3);
			s.insert((*it) * 5);
		}
		auto it = s.begin();
		advance(it, n-1);
		return *it;
		return 1;
    }
};
