// TC- O(nlogn)
// SC- O(n)

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // pair up position and time to target
        vector<pair<int, double>> car_stats;
        for(int i=0; i<position.size(); i++)
            car_stats.push_back({position[i], (double)(target-position[i])/speed[i]});

        // sort vector in descending order wrt position
        sort(car_stats.begin(), car_stats.end(), [](pair<int, double> x, pair<int,double> y){return x.first>y.first;});

        // Iterate. Add a new fleet if time_taken is greater than curr
        double curr_fleet_time = 0.0;
        int num_fleets = 0;
        for(auto& [pos, time]: car_stats){
            if(time>curr_fleet_time){
                curr_fleet_time = time;
                num_fleets++;
            }
        }
        return num_fleets;

    }
};
