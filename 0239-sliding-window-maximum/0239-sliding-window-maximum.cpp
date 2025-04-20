// SC- O(k)
// TC- O(n)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> maximums;

        // In sliding window, one elem moves out and one elem moves in. So deque is a good DS.
        // The deque is structured in a way that the front of the deque always contains the index
        // of the maximum element in the current window.
        deque<int> dq;
        int n = nums.size();
        
        for(int i=0; i<n; i++){
            // Check if front is still valid in the current window, if not pop it
            if(!dq.empty() && dq.front()<i-k+1){
                dq.pop_front();
            }

            // Remove from back until it is greater than or equal to current element
            while(!dq.empty() && nums[dq.back()]<nums[i]){
                dq.pop_back();
            }

            // Add current element index to deque
            dq.push_back(i);

            // Push maximum to ans if window size is reached
            if(i>=k-1){
                maximums.push_back(nums[dq.front()]);
            }
        }
        return maximums;

    }
};