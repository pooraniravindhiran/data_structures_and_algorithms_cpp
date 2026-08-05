// TC- O(n+(e*a(n)))
// SC- O(n)

class UnionFind{
public:
    // SC- O(n)
    vector<int> parent, rank;
    int components;

    UnionFind(int n){
        // TC- O(n)
        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i]=i;
        rank.resize(n, 0);
        components = n;
    }

    int find(int x){
        // TC- O(a(n)) amortized where a is the inverse Auckermann function- grows slowly with n
        // with path compression
        if(parent[x]!=x)
            parent[x] = find(parent[x]);
        
        return parent[x];
    }

    void unite(int x, int y){
        // TC- O(a(n)) amortized where a is the inverse Auckermann function- grows slowly with n
        // union by rank
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
    int countComponents(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for(auto& edge:edges){
            uf.unite(edge[0], edge[1]);
        }

        return uf.components;
    }
};