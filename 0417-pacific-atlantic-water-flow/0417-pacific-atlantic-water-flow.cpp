// TC- O(mn)
// SC- O(mn)

class Solution {
private:
    vector<int> dirs = {-1, 0, 1, 0, -1};
    void dfs(int r, int c, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        if(visited[r][c]==true)
            return;
        
        visited[r][c] = true;

        for(int d=0; d<dirs.size()-1; d++){
            int next_r = r+dirs[d];
            int next_c = c+dirs[d+1];

            if(next_r>=0 and next_r<visited.size() and next_c>=0 and next_c<visited[0].size() and visited[next_r][next_c]==false and heights[next_r][next_c]>=heights[r][c])
                dfs(next_r, next_c, visited, heights);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool> (n, false));
        vector<vector<bool>> atlantic(m, vector<bool> (n, false));

        vector<vector<int>> ans;

        for(int c=0; c<n; c++)
            dfs(0, c, pacific, heights);
        for(int r=0; r<m; r++)
            dfs(r, 0, pacific, heights);

        for(int c=0; c<n; c++)
            dfs(m-1, c, atlantic, heights);
        for(int r=0; r<m; r++)
            dfs(r, n-1, atlantic, heights);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(pacific[i][j]==true and atlantic[i][j]==true)
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};