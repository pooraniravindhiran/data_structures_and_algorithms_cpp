// TC- O(n)
// SC- O(n)

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
        // if not circular array
        // stack<int> st; // monotonically dec
        // vector<int> res(nums.size(), -1);
        // for(int i=nums.size()-1; i>=0; i--){
        //     while(!st.empty() and nums[i]>=st.top())
        //         st.pop();
            
        //     if(!st.empty())
        //         res[i] = st.top();

        //     st.push(nums[i]);
        // }
        // return res;

        stack<int> st; // monotonically dec
        vector<int> res(nums.size(), -1);
        for(int i=2*nums.size()-1; i>=0; i--){
            int idx = i%nums.size();
            while(!st.empty() and nums[idx]>=st.top())
                st.pop();
            
            if(!st.empty())
                res[idx] = st.top();

            st.push(nums[idx]);
        }
        return res;
    }
};