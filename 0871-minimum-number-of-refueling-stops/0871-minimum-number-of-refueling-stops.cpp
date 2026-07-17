// TC- O(slogs)
// SC- O(s)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        stations.push_back({target, 0});
        int currfuel = startFuel;
        int currpos = 0;
        priority_queue<int> max_heap;
        int min_stops = 0;

        for(int i=0; i<stations.size(); i++){
            int loc = stations[i][0], fuel = stations[i][1];
            currfuel = currfuel - (loc-currpos);
            while(currfuel<0){
                if(max_heap.empty())
                    return -1;
                currfuel += max_heap.top();
                max_heap.pop();
                min_stops ++;
            }
            max_heap.push(fuel);
            currpos = loc;
        }
        return min_stops;
    }
};