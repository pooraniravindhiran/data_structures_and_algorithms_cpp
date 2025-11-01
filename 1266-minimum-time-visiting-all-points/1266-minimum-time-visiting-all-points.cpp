// tc- o(n)
// sc- o(1)

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int mintime = 0;
        for(int i=1; i<points.size(); i++){
            vector<int> start = points[i-1];
            vector<int> end = points[i];

            int dx = abs(end[0]-start[0]);
            int dy = abs(end[1]-start[1]);
            // mintime += min(dx, dy) + abs(dx-dy); // max diag moves possible + straight moves
            mintime += max(dx, dy);
        }
        return mintime;
    }
};