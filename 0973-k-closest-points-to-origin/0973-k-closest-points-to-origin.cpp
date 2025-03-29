class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](pair<int,int> p1, pair<int, int> p2){
            double dist1 = sqrt(pow(p1.first, 2)+pow(p1.second, 2));
            double dist2 = sqrt(pow(p2.first, 2)+pow(p2.second, 2));
            return dist1<dist2;
        };

        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> max_heap(comp);
        for(int i=0; i<points.size(); i++){
            max_heap.push({points[i][0], points[i][1]});
            if(max_heap.size()>k)
                max_heap.pop();
        }

        vector<vector<int>> result;
        while(!max_heap.empty()){
            auto p = max_heap.top();
            result.push_back({p.first, p.second});
            max_heap.pop();
        }
        return result;
    }
};