/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

// SC- O(n) where n is the num of nestedint objects in input

class NestedIterator {
private:
    stack<NestedInteger> st; // store nestedint instead of int in stack because otherwise in nested lists, you will have to remember indices like when doing it without stack
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // TC- O(n)
        for(auto it=nestedList.rbegin(); it!=nestedList.rend(); it++)
            st.push(*it);
    }
    
    int next() {
        // TC- O(1)
        int ans = st.top().getInteger();
        st.pop();
        return ans;
    }
    
    bool hasNext() {
        // TC- amortized O(1) because some calls might have to process nested lists but if there are p integers in total, then there will be p pushes and pops onto stack in total
        while(!st.empty()){
            if(st.top().isInteger())
                return true;

            auto curr = st.top().getList();
            st.pop();
            for(auto it=curr.rbegin(); it!=curr.rend(); it++)
                st.push(*it);
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */