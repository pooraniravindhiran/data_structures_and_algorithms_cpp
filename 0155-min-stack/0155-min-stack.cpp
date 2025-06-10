// SC- O(n)

class MinStack {
private:
    stack<pair<int, int>> st;
public:
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty())
            st.push({val, val});
        else{
            int minimum = min(getMin(), val);
            st.push({val, minimum});
        }
    }
    
    void pop() {
        if(st.empty())
            throw runtime_error("Stack is empty, so cannot pop");
        st.pop();
    }
    
    int top() {
        if(st.empty())
            throw runtime_error("Stack is empty, so cannot get top element");
        return st.top().first;
    }
    
    int getMin() {
        if(st.empty())
            throw runtime_error("Stack is empty, so cannot get minimum");
        return st.top().second;
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