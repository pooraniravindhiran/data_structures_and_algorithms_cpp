// TC- O(p*a(mn))
// SC- O(mn)

class UnionFind{
public:
    vector<int> parent, rank;
    int components;

    UnionFind(int n){
        components = 0;
        parent.resize(n, -1);
        rank.resize(n, 0);
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
        
        if(rank[px]<rank[py])
            parent[px] = py;
        else if(rank[px]>rank[py])
            parent[py] = px;
        else{
            parent[px] = py;
            rank[py]++;
        }
        components--;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        UnionFind uf(m*n);
        vector<int> res(positions.size(), 0);

        vector<int> dirs = {-1, 0, 1, 0, -1};

        for(int i=0; i<positions.size(); i++){
            auto position = positions[i];
            int idx = position[0]*n+position[1];
            if(uf.parent[idx]!=-1){
                res[i] = uf.components;
                continue;
            }

            uf.parent[idx] = idx;
            uf.components++;
            for(int d=0; d<dirs.size()-1; d++){
                int next_r = position[0]+dirs[d];
                int next_c = position[1]+dirs[d+1];
                if(next_r>=0 and next_r<m and next_c>=0 and next_c<n){
                    int next_idx = next_r*n+next_c;
                    if(uf.parent[next_idx]!=-1)
                        uf.unite(idx, next_idx);
                }
            }
            res[i] = uf.components;
        }
        return res;
    }
};