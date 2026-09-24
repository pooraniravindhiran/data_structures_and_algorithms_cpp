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

class NestedIterator {
private:
    // SC- O(n)
    stack<NestedInteger> st;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        // TC- O(n)
        for(int j=nestedList.size()-1; j>=0; j--)
            st.push(nestedList[j]);
    }
    
    int next() {
        // TC- O(1)
        int val = st.top().getInteger();
        st.pop();
        return val;
    }
    
    bool hasNext() {
        // TC- amortized O(1)
        while(!st.empty()){
            if (st.top().isInteger())
                return true;
            
            auto l = st.top().getList();
            st.pop();
            for(int i=l.size()-1; i>=0; i--)
                st.push(l[i]);
        }

        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */