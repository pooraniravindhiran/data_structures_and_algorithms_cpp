// TC- O(n)
// SC- O(n)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nums1_map;
        for(int i=0; i<nums1.size(); i++)
            nums1_map[nums1[i]] = i;
        
        stack<int> st;
        vector<int> res(nums1.size(), -1);

        // can go right to elft or otherwise, but stack meaning and code differs
        for(int i=nums2.size()-1; i>=0; i--){
            while(!st.empty() and nums2[i]>st.top())
                st.pop();
            
            if(nums1_map.find(nums2[i])!=nums1_map.end() and !st.empty())
                res[nums1_map[nums2[i]]] = st.top();

            st.push(nums2[i]);
        }

        return res;
    }
};