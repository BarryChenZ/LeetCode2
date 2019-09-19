class Solution {
public:
    int calculate(string s) {
        stack<char> operation;
        stack<int>  number;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ' ') continue;
            else if(isdigit(s[i])){
                long num = 0;
                
                while(i<s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                number.push(num);
                --i;
            }
            else{
                while(!operation.empty() && precedence(operation.top()) >= precedence(s[i])) {
                    calculate(number, operation.top());
                    operation.pop();
                }
                operation.push(s[i]);
            }
        }
        
        while(!operation.empty()){
            calculate(number, operation.top());
            operation.pop();
        }
        return number.top();
    }
    long findInteger(string s, int& i){
        long ans = 0;
        while(i < s.size() && isdigit(s[i])) {
                    ans = ans* 10 + s[i] - '0';
                    ++i;
        }
        return ans;
    }
    void calculate(stack<int>& number, char s){
        int a = number.top(); number.pop();
        int b = number.top(); number.pop();
        switch (s){
            case '+':
                b = b + a;
                break;
            case '-':
                b = b - a;
                break;
            case '*':
                b = b * a;
                break;
            case '/':
                b = b / a;
                break;
        }
        number.push(b);
    }
    int precedence(char op) {
        if(op == '+' || op == '-') return 1;
        else if (op == '*' || op == '/') return 2;
        else return 0;
    }
};
