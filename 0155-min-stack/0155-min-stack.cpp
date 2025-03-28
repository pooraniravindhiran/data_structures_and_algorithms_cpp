#include <stack>
#include <stdexcept> // For exception handling

class MinStack {
    std::stack<std::pair<int, int>> st;
public:
    MinStack() {}

    void push(int val) {
        if (st.empty()) 
            st.push({val, val});
        else 
            st.push({val, std::min(val, st.top().second)});
    }

    void pop() {
        if (st.empty()) 
            throw std::runtime_error("Stack is empty, cannot pop");
        st.pop();
    }

    int top() {
        if (st.empty()) 
            throw std::runtime_error("Stack is empty, no top element");
        return st.top().first;
    }

    int getMin() {
        if (st.empty()) 
            throw std::runtime_error("Stack is empty, no minimum element");
        return st.top().second;
    }
};
