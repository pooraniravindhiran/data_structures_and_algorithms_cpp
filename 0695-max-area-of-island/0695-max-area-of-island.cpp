class Solution {
private:
    vector<int> directions = {-1, 0, 1, 0, -1};
    void dfs(vector<vector<int>>& grid, int i, int j, int& area){
        grid[i][j] = 0;
        area++;
        for(int d=0; d<directions.size()-1; d++){
            int new_i = i+directions[d];
            int new_j = j+directions[d+1];
            if(new_i>=0 and new_i<grid.size() and new_j>=0 and new_j<grid[0].size() and grid[new_i][new_j]==1)
                dfs(grid, new_i, new_j, area);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    int area = 0;
                    dfs(grid, i, j, area);
                    max_area = max(max_area, area);
                }
            }
        }
        return max_area;
    }
};

// TC- O(m*n)
// SC- O(m*n)