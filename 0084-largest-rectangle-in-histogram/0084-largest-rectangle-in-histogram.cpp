// TC- O(n)
// SC- O(n)

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        heights.push_back(0);

        for(int i=0; i<heights.size(); i++){
            while(!st.empty() and heights[i]<=heights[st.top()]){
                // rect upto that pt including it
                int top = st.top();
                st.pop();
                int height = heights[top];
                int rb = i-1;
                int lb = (st.empty()) ? 0:st.top()+1;
                int width = rb-lb+1;
                int area = height*width;
                max_area = max(max_area, area);
            }
            st.push(i);
        }

        return max_area;
    }
};