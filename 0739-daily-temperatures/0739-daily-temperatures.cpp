// TC- O(n)
// SC- O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // monotonically decreasing array
        vector<int> res(temperatures.size(), 0);
        stack<int> st;

        for(int t=0; t<temperatures.size(); t++){
            while(!st.empty() and temperatures[st.top()]<temperatures[t]){
                res[st.top()] = t-st.top();
                st.pop();
            }
            st.push(t);
        }
        return res;
    }
};