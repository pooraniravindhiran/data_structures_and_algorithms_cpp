// TC - O(m*n)
// SC - O(m*n)

class Solution {
    void dfs_helper(vector<vector<int>>& image, pair<int, int> index, int old_color, int new_color){
        // assign new color
        image[index.first][index.second] = new_color;

        vector<int> directions = {-1, 0, 1, 0, -1};
        for(int d=0; d<directions.size()-1; d++){
            int new_r = index.first+directions[d];
            int new_c = index.second+directions[d+1];
            if(new_r>=0 and new_c>=0 and new_r<image.size() and new_c<image[0].size() and image[new_r][new_c]==old_color)
                dfs_helper(image, make_pair(new_r, new_c), old_color, new_color);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)
            return image;
        dfs_helper(image, {sr, sc}, image[sr][sc], color);
        return image;
    }
};