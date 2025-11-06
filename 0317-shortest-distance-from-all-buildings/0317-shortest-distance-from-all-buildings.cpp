// SC- O(mn for distances + mn for queue) = O(mn)
// TC- O(m^2n^2)

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        // bfs is needed because we need to find shortest dist. you can do empty cells to houses or houses to empty cells. since houses are far less in number than empty cells, I choose that here.
        int rows = grid.size();
        int cols = grid[0].size();

        // for each empty cell, you need to keep track of all houses that can be reached from it and the distances to it. if it is possible to get to all houses from a cell, i will decrement the empty cell value directly in grid. thus i do not have to even consider those cells while traversal from other houses.
        vector<vector<int>> distances(rows, vector<int> (cols, 0));
        int emptyland_val = 0;

        int min_dist = INT_MAX;
        vector<int> directions = {-1, 0, 1, 0, -1};

        // do a bfs from every house 
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(grid[i][j]==1){
                    queue<pair<int,int>> q;
                    q.push({i, j});

                    int steps = 0;

                    while(!q.empty()){
                        steps++;
                        for(int k=q.size(); k>0; k--){
                            auto curr = q.front();
                            q.pop();
                            int row = curr.first;
                            int col = curr.second;

                            // if cell with val=emptyland_val, add dist and dec cell value by 1
                            for(int d=0; d<directions.size()-1; d++){
                                int nextrow = row+directions[d];
                                int nextcol = col+directions[d+1];
                                if(nextrow>=0 and nextcol>=0 and nextrow<rows and nextcol<cols and grid[nextrow][nextcol]==emptyland_val){
                                    grid[nextrow][nextcol]--;
                                    distances[nextrow][nextcol] +=steps;
                                    q.push({nextrow, nextcol});
                                }
                            }
                        }
                    }

                    emptyland_val--;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                
                // A cell is reached by all houses only if its grid value is equal to the final emptyLandValue.
                // The final emptyLandValue is -(number of houses).
                if (grid[i][j] == emptyland_val) { 
                    min_dist = min(min_dist, distances[i][j]);
                }
            }
        }
        return min_dist==INT_MAX ? -1:min_dist;
    }
};


// // SC- O(mn for cell_stats + mn for queue+ mn for visited) = O(mn)
// // TC- O(m^2n^2)

// class Solution {
// private:
//     void bfs(vector<vector<int>>& grid, int row, int col, vector<vector<pair<int, int>>>& cell_stats){
//         int rows = grid.size();
//         int cols = grid[0].size();
//         vector<int> directions = {-1, 0, 1, 0, -1};

//         queue<pair<int,int>> q;
//         q.push({row, col});

//         vector<vector<bool>> visited (rows, vector<bool> (cols, false));
//         visited[row][col] = true;

//         int steps = 0;

//         while(!q.empty()){
//             for(int i=q.size(); i>0; i--){
//                 auto curr = q.front();
//                 q.pop();
//                 row = curr.first;
//                 col = curr.second;

//                 // if empty cell, add dist and inc count of houses reached at this cell
//                 if(grid[row][col]==0){
//                     cell_stats[row][col].first += steps;
//                     cell_stats[row][col].second++;
//                 }

//                 // else traverse
//                 for(int d=0; d<directions.size()-1; d++){
//                     int nextrow = row+directions[d];
//                     int nextcol = col+directions[d+1];
//                     if(nextrow>=0 and nextcol>=0 and nextrow<rows and nextcol<cols and grid[nextrow][nextcol]==0 and !visited[nextrow][nextcol]){
//                         visited[nextrow][nextcol] = true;
//                         q.push({nextrow, nextcol});
//                     }
//                 }
//             }

//             steps++;
//         }
//     }
// public:
//     int shortestDistance(vector<vector<int>>& grid) {
//         // bfs is needed because we need to find shortest dist. you can do empty cells to houses or houses to empty cells. since houses are far less in number than empty cells, I choose that here.
//         int rows = grid.size();
//         int cols = grid[0].size();

//         // you need to be able to move to all the houses in the grid, so you should keep a count of int
//         // for each empty cell, you need to keep track of all houses that can be reached from it and the distances to it.
//         int total_houses = 0;
//         vector<vector<pair<int, int>>> cell_stats(rows, vector<pair<int,int>> (cols, {0,0}));
        
//         // do a bfs from every house 
//         for(int i=0; i<rows; i++){
//             for(int j=0; j<cols; j++){
//                 if(grid[i][j]==1){
//                     total_houses++;
//                     bfs(grid, i, j, cell_stats);
//                 }
//             }
//         }

//         // check through cell_stats and see if any empty land has all houses covered, then update min_dist. if not at all, return -1
//         int min_dist = INT_MAX;
//         for(int i=0; i<rows; i++){
//             for(int j=0; j<cols; j++){
//                 if(cell_stats[i][j].second==total_houses)
//                     min_dist = min(min_dist, cell_stats[i][j].first);
//             }
//         }

//         if(min_dist==INT_MAX)
//             return -1;
//         return min_dist;
//     }
// };