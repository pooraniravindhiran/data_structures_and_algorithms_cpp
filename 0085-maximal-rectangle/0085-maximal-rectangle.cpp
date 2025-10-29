// TC- O(m*n) as time for one row is creating histogram and largestrectangle func = O(n) +O(n)
// SC- O(n) n+n where n is for stack and histogram

class Solution {
private:
    int largestRectangleArea(vector<int> heights) {
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int maxArea = 0;
        vector<int> heights(cols, 0);

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++)
                heights[j] = matrix[i][j]=='1' ? heights[j]+1:0;
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }
};