// TC- O(n)
// SC- O(n)

class UnionFind{
private:
    vector<int> parent, rank;
public:
    int components;
    UnionFind(int n){
        components = n;

        parent.resize(n);
        for(int i=0; i<n; i++)
            parent[i] = i;
        
        rank.resize(n, 0);
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

        components--;
        return true;
    }
};


class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        UnionFind uf(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(isConnected[i][j]==1 or isConnected[j][i]==1)
                    uf.unite(i, j);
            }
        }
        return uf.components;
    }
};