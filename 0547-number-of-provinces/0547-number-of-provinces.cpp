// TC- O(n^2*a(n))
// SC- O(n)

class UnionFind{
public:
    vector<int> parent, rank;
    int components;

    UnionFind(int n){
        components = n;
        parent.resize(n);
        rank.resize(n, 0);
        for(int i=0; i<n; i++)
            parent[i] = i;
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(isConnected[i][j]==1)
                    uf.unite(i, j);
            }
        }
        return uf.components;
    }
};