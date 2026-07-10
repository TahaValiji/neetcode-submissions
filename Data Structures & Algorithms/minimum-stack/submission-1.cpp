class MinStack {
private:
    int currmin;
    stack<int> s;
    stack<int> t;
public:
    MinStack() {
        currmin = INT_MAX;
    }
    
    void push(int val) {
        s.push(val);
        if (t.empty()) t.push(val);
        else t.push(min(val, t.top()));
    }
    
    void pop() {
        s.pop();
        t.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return t.top();
    }
};
