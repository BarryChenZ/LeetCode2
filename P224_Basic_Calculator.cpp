class Solution {
public:
    int calculate(string s) {
        stack<char> operation;
        stack<int>  number;
        for(int i = 0; i < s.size(); i++){
            cout << i;
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
            else if(s[i] == '('){
                operation.push(s[i]);
            }
            else if(s[i] == ')'){
                while(!operation.empty() && operation.top() != '(') {
                    calculate(number, operation.top());
                    operation.pop();
                }
                 operation.pop();
            }
            else{
                while(!operation.empty() && precedence_in(operation.top()) >= precedence_out(s[i])) {
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
        }
        number.push(b);
    }
    int precedence_in(char op) {
        if (op == '+' || op == '-') return 1;
        else return 0;
    }
    
    int precedence_out(char op) {
        if (op == '+' || op == '-') return 1;
        else return 0; 
    }
};
