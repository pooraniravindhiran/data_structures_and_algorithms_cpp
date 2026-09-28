// TC- O(n^2logn)
// SC- O(n^2)

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
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        // {cost, point1, point2}
        vector<tuple<int, int, int>> edges;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int cost = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({cost, i, j});
            }
        }

        // sort edges
        sort(edges.begin(), edges.end());

        // iterate
        int total_cost = 0;
        UnionFind uf(n);
        for(auto& [cost, u, v]:edges){
            if(uf.unite(u, v))
                total_cost += cost;
            
            if(uf.components==1)
                return total_cost;
        }
        return total_cost;
    }
};