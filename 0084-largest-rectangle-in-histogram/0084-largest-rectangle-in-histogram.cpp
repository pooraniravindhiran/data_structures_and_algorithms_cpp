// TC- O(n)
// SC- O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> st; // stores indices
        heights.push_back(0); // to flush out stack at the end

        for(int i=0; i<heights.size(); i++){
            while(not st.empty() and heights[st.top()]>heights[i]){
                int height = heights[st.top()];
                st.pop();
                int width;
                int right_boundary = i-1;
                int left_boundary = st.empty() ? 0:st.top()+1;
                width = right_boundary-left_boundary+1;
                maxArea = max(maxArea, height*width);
            }
            st.push(i);
        }
        return maxArea;
    }
};