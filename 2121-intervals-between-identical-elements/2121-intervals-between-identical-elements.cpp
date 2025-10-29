// TC- O(n)
// SC- O(n)

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        // comparing every pair is brute force O(n^2), but we need only positions with same value, so store them first
        unordered_map<int, vector<int>> groups;
        int n = arr.size();
        for(int i=0; i<n; i++)
            groups[arr[i]].push_back(i);

        // result
        vector<long long> intervals(n, 0);

        // process each group
        for(auto& [value, indices]:groups){
            int k = indices.size();

            // if only present once, sum is 0, already initialized
            if(k==1)
                continue;

            long long sum_total = 0;
            for(int i=0; i<k; i++)
                sum_total += indices[i];
            long long sum_left_pos = 0;
            
            // sum = sum of intervals with left elements + sum of intervals with right elements
            // sum of intervals with left elem = (num_left_elem*curr_pos) - sum of left pos
            for(int i=0; i<k; i++){
                long long num_left_pos = i;
                long long num_right_pos = k-i-1;

                long long sum_right_pos = sum_total - sum_left_pos - indices[i];

                long long left_sum = (num_left_pos*indices[i]) - sum_left_pos;
                long long right_sum = (sum_right_pos) - (num_right_pos*indices[i]);
                intervals[indices[i]] = left_sum+right_sum;

                sum_left_pos += indices[i];
            }
        }
        return intervals;
    }
};