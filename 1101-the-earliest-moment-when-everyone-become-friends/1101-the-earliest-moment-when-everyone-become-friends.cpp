// TC- O(eloge)
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
    int earliestAcq(vector<vector<int>>& logs, int n) {
        UnionFind uf(n);

        sort(logs.begin(), logs.end());
        for(auto& log:logs){
            uf.unite(log[1], log[2]);
            if(uf.components==1)
                return log[0];
        }
        return -1;
    }
};