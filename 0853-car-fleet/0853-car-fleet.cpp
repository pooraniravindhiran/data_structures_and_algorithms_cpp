// TC- O(nlogn)
// SC- O(n)

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // create a vector of cars
        vector<pair<int, double>> cars;
        for(int i=0; i<position.size(); i++){
            double time_to_target = (double)(target-position[i])/ speed[i];
            cars.push_back({position[i], time_to_target});
        }

        // sort cars by position in descending order
        sort(cars.begin(),  cars.end(), [](pair<int, double>& a, pair<int, double>& b){return a.first>b.first;});

        // if a car is leading, then the next car whose time_to_target is greater than the curr_car will start a new care fleet. Else, it will join current fleet
        double current_time = 0.0;
        int num_fleets = 0;
        for(auto &car:cars){
            if(car.second > current_time){
                current_time = car.second;
                num_fleets++;
            }
        }

        return num_fleets;
    }
};