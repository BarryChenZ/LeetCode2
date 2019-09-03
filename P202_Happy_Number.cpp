class Solution {
public:
    bool isHappy(int n) {
        // 非 0 只有 1 個
        if(n == 0) return false;
        int loop = n; //重複
        int tmp = n;
        bool res = 0;
        unordered_map<int, bool> m;
        while(true){
            //拆開
            //cout << tmp << endl;
            vector<int> digital;
            count(tmp, digital);
            //計算結果
            int result = calculate(digital);
            //cout << result << endl;
            if(m.find(result) == m.end()){
                m[result] = true;
            }
            else{
                break;
            }
            //計算只有1個1 break;
            digital.clear();
            count(result, digital);
            if(only1(digital)) return true;
            digital.clear();
            tmp = result;
        }
        return 0;
    }
    void count(int tmp, vector<int>& digital){
        while(tmp != 0){
            digital.push_back(tmp%10);
            tmp = tmp/10;
        }
    }
    int calculate(vector<int>& digital){
        int temp = 0;
        for(int i = 0; i < digital.size(); i++){
            temp += pow(digital[i], 2);
        }
        return temp;
    }
    bool only1(vector<int>& digital){
        int counter_1 = 0;
        int counter_no01 = 0;
        for(int i = 0; i < digital.size(); i++){
            if(digital[i] == 1) counter_1++;
            else if(digital[i] != 0) counter_no01++;
            else{
                
            }
        }
        if(counter_1 == 1 && counter_no01 == 0) return true;
        return false;
    }
};
