// TC- O(n)
// SC- O(n)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<int> st;

        for(int i=0; i<temperatures.size();  i++){
            while(!st.empty() and temperatures[st.top()]<temperatures[i]){
                int top_i = st.top();
                st.pop();
                ans[top_i] = i-top_i;
            }

            st.push(i);
        }
        return ans;
    }
};
