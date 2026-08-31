class MinStack {
public:
    stack<int> st;
    stack<int> st2;

    int mini=INT_MAX;
    
    MinStack() {
        st2.push(mini);
    }
    
    void push(int value) {
        st.push(value);
        int curr_min=min(st2.top(),value);
        st2.push(curr_min);
    }
    
    void pop() {
        st.pop();
        st2.pop();
    }
    
    int top() {
        int tp=st.top();
        return tp;
    }
    
    int getMin() {
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */