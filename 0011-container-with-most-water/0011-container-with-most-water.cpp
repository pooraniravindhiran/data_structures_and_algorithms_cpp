class Solution {
private:
    int maxarea = 0;

public:
    int maxArea(vector<int>& height) {
        // we need to find two lines that have max water between them
        // this is basically width between them* minimum height
        // so we start with max width possible using two ptr approach
        // we update area
        // we move inward towards the end that has the smallest height because now width is decreasing and the only way area can still be maximised is by getting taller height
        for(int i=0, j=height.size()-1; i<j;){
            int w = j-i;
            int h = min(height[i], height[j]);
            maxarea = max(maxarea, h*w);
            if(height[i]<=height[j])
                i++;
            else
                j--;
        }
        return maxarea;
    }
};