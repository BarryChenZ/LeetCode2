class MyQueue {
public:
    /** Initialize your data structure here. */
    vector<int> stack;
    MyQueue() {
        stack.clear();
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stack.push_back(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int tmp = stack.front();
        stack.erase(stack.begin());
        return tmp;
    }
    
    /** Get the front element. */
    int peek() {
        int tmp = stack.front();
        return tmp;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(stack.empty()) return true;
        return false;
    }
};
