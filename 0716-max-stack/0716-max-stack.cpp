// SC- O(n)
class MaxStack {
private:
    priority_queue<pair<int,int>> max_heap;
    stack<pair<int, int>> st;
    int cnt; // to assign unique id to each new elem
    unordered_set<int> removed;

public:
    MaxStack() {
        cnt = 0;
    }
    
    void push(int x) {
        // TC- O(logx)
        max_heap.emplace(x, cnt);
        st.emplace(x, cnt);
        cnt++;
    }
    
    int pop() {
        // TC- amortized O(1) since one elem can be removed only once from stack

        // lazy update
        while(removed.count(st.top().second))
            st.pop();
        
        // add to removal list and remove from stack
        pair<int,int> toremove = st.top();
        st.pop();
        removed.insert(toremove.second);
        return toremove.first;
    }
    
    int top() {
        // TC- O(1)
        // lazy update
        while(removed.count(st.top().second))
            st.pop();

        return st.top().first;
    }
    
    int peekMax() {
        // TC- O(1)
        // lazy update
        while (removed.count(max_heap.top().second))
            max_heap.pop();
        return max_heap.top().first;
    }
    
    int popMax() {
        // TC- amortized O(1) since one elem can be removed only once from stack

        // lazy update
        while (removed.count(max_heap.top().second))
            max_heap.pop();

        pair<int, int> toremove = max_heap.top();
        max_heap.pop();
        removed.insert(toremove.second);
        return toremove.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */