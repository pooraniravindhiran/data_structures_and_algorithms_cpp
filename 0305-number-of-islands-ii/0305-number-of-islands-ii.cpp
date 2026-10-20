// SC- O(mn)
// TC- O(mn+ p*a(mn))

class UnionFind{
private:
    vector<int> rank;
public:

    int components;
    vector<int> parent;
    UnionFind(int n){
        parent.resize(n, -1);
        rank.resize(n, 0);
        components = 0;
    }

    int find(int x){
        if(parent[x]!=x)
            parent[x] = find(parent[x]);

        return parent[x];
    }

    void unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px==py)
            return;

        components--;

        if(rank[px]>rank[py])
            parent[py] = px;
        else if(rank[py]>rank[px])
            parent[px] = py;
        else{
            parent[px] = py;
            rank[py]++;
        }
    }


};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int total = m*n;
        UnionFind uf(total);

        vector<int> ans;
        vector<int> dirs = {-1, 0, 1, 0, -1};

        for(int i=0; i<positions.size(); i++){
            int x = positions[i][0];
            int y = positions[i][1];
            int idx = (x*n) + y;

            if(uf.parent[idx]!=-1){
                // if the cell is already land, do nothing and append the current island count.
                ans.push_back(uf.components);
                continue;
            }

            // if cell is water, inc count and make it land
            uf.components++;
            uf.parent[idx] = idx;

            // check 4 neighbors and if they are land but diff idx, unite and dec count
            for(int d=0; d<dirs.size()-1; d++){
                int next_x = x+dirs[d];
                int next_y = y+dirs[d+1];

                if(next_x>=0 and next_x<m and next_y>=0 and next_y<n){
                    int next_idx = (next_x*n)+next_y;
                    if(uf.parent[next_idx]!=-1)
                        uf.unite(idx, next_idx);
                }
            }
            ans.push_back(uf.components);

        }
        return ans;
    }
};