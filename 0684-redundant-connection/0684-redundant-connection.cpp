// TC- O(n*a(n))
// SC- O(n)

class UnionFind{
public:
    vector<int> parent, rank;

    UnionFind(int n){
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

    bool unite(int x, int y){
        int px = find(x);
        int py = find(y);

        if(px==py)
            return false;
        
        if(rank[px]<rank[py])
            parent[px] = py;
        else if(rank[px]>rank[py])
            parent[py] = px;
        else{
            parent[px] = py;
            rank[py]++;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        UnionFind uf(n+1);

        for(auto& edge:edges){
            if(uf.unite(edge[0], edge[1])==false){
                return edge;
            }
        }
        return {};
    }
};