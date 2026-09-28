// TC- O((mn)^2)
// SC- O(mn)

class Solution {
private:
    vector<vector<int>> dist;
    vector<vector<int>> num_buildings;
    int m, n, total_buildings;
    vector<int> dirs = {-1, 0, 1, 0, -1};

public:
    int shortestDistance(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        dist = vector<vector<int>>(m, vector<int>(n, 0));
        num_buildings = vector<vector<int>>(m, vector<int>(n, 0));
        total_buildings = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    total_buildings++;
                    queue<pair<int, int>> q;
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    q.push({i, j});
                    visited[i][j]= true;
                    int level = 1;
                    while(!q.empty()){
                        int q_size = q.size();
                        for(int k =0; k<q_size; k++){
                            auto curr = q.front();
                            q.pop();
                            for(int d=0;d<dirs.size()-1; d++){
                                int next_i = curr.first+dirs[d];
                                int next_j = curr.second+dirs[d+1];
                                if(next_i>=0 and next_i<m and next_j>=0 and next_j<n and visited[next_i][next_j]==false and grid[next_i][next_j]==0){
                                    visited[next_i][next_j] = true;
                                    q.push({next_i, next_j});
                                    num_buildings[next_i][next_j]++;
                                    dist[next_i][next_j] += level;
                                }
                            }
                        }
                        level++;
                    }
                }
            }
        }

        int shortest_dist = INT_MAX;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(num_buildings[i][j]==total_buildings)
                    shortest_dist = min(shortest_dist, dist[i][j]);
            }
        }
    
        return (shortest_dist==INT_MAX) ? -1:shortest_dist;
    }
};