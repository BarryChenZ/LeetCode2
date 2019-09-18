class MyStack {
public:
    queue<int> q;
    MyStack() {
        q = queue<int>();
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
        for(int i = 0; i < q.size() - 1; i++){
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int a = q.front();
        q.pop();
        return a;
    }
    
    /** Get the top element. */
    int top() {
        return q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(q.empty()) return true;
        else return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
