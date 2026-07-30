// TC- O(m^2*n^2)
// SC- O(mn)

class Solution {
private:
    vector<vector<int>> dist;
    int m=0, n =0;
    vector<int> dirs = {-1, 0, 1, 0, -1};
    int emptylandval = 0;
    int shortest_dist = INT_MAX;
    
public:
    int shortestDistance(vector<vector<int>>& grid) {
        this->m = grid.size();
        this->n = grid[0].size();
        this->dist = vector<vector<int>> (m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    shortest_dist = INT_MAX;
                    queue<vector<int>> q;
                    q.push({i, j, 0});
                    
                    while(!q.empty()){
                        auto curr = q.front();
                        q.pop();
                        int r= curr[0], c= curr[1], level= curr[2];
                        for(int d=0; d<dirs.size()-1; d++){
                            int next_r = r+dirs[d], next_c = c+dirs[d+1];
                            if(next_r>=0 and next_r<m and next_c>=0 and next_c<n and grid[next_r][next_c]==emptylandval){
                                grid[next_r][next_c] --;
                                q.push({next_r, next_c, level+1});
                                dist[next_r][next_c] += level+1;
                                shortest_dist = min(shortest_dist, dist[next_r][next_c]);
                            }
                        }
                    }  
                    
                    emptylandval--;
                }
            }
        }
        if(shortest_dist==INT_MAX)
            return -1;
        return shortest_dist;       
    }
};