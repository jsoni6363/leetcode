class MinStack {
public:
    stack<int> s;
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        int ans=INT_MAX;

        stack<int> temp;
        while(!s.empty()){
             ans=min(ans,s.top());
             temp.push(s.top());
             s.pop();
        }

        while(!temp.empty()){
          s.push(temp.top());
          temp.pop();
        }
        return ans;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */