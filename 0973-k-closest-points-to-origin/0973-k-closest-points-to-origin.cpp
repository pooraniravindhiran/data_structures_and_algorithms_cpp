// TC- nlogk
// SC- k

class Solution {
public:
    // auto cmp = [](pair<int, int> a, pair<int, int> b){
    //     return a<b;
    // };
    priority_queue<pair<int, int>> max_heap;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(int i=0; i<points.size(); i++){
            auto point = points[i];
            int dist = (point[0]*point[0])+(point[1]*point[1]);
            max_heap.emplace(dist, i);
            if(max_heap.size()>k)
                max_heap.pop();
        }

        vector<vector<int>> res;
        while(!max_heap.empty()){
            res.push_back(points[max_heap.top().second]);
            max_heap.pop();
        }
        return res;
    }
};