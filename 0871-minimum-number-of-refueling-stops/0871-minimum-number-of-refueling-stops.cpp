// SC- O(n)
// TC- O(nlogn)

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int currpos = 0;
        int currfuel = startFuel;
        stations.push_back({target, 0});
        priority_queue<int> max_heap;

        int ans = 0;

        for(int i=0; i<stations.size(); i++){
            currfuel = currfuel - (stations[i][0]-currpos);
            currpos = stations[i][0];

            while(currfuel<0){
                if(max_heap.empty())
                    return -1;
                currfuel += max_heap.top();
                max_heap.pop();
                ans++;
            }
            max_heap.push(stations[i][1]);
        }
        return ans;
    }
};