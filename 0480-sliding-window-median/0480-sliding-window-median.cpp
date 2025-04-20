class Solution {
    private:
        priority_queue<int> max_heap; // Max-heap for the smaller half
        priority_queue<int, vector<int>, greater<int>> min_heap; // Min-heap for the larger half

        // Map because there could be duplicates and this is lazy deletion because
        // priority queue does not support arbitrary deletion.
        unordered_map<int, int> toberemoved;

        void remove(priority_queue<int>& heap){
            while(!heap.empty() and toberemoved[heap.top()]){
                toberemoved[heap.top()]--;
                heap.pop();
            }
        }

        void remove(priority_queue<int, vector<int>, greater<int>>& heap){
            while(!heap.empty() and toberemoved[heap.top()]){
                toberemoved[heap.top()]--;
                heap.pop();
            }
        }

    public:
        vector<double> medianSlidingWindow(vector<int>& nums, int k) {
            vector<double> medians;

            // Initialize heaps with k elements
            int i=0;
            while(i<k)
                max_heap.push(nums[i++]);
            for(int j=0; j<k/2; j++){
                min_heap.push(max_heap.top());
                max_heap.pop();
            }

            while(true){
                // Get median for current window
                if(k%2==1)
                    medians.push_back(max_heap.top());
                else
                    medians.push_back(((double)max_heap.top()+min_heap.top())/2.0);

                // All elements are processed!
                if(i>=nums.size())
                    break;

                int out_num = nums[i-k];
                int in_num = nums[i++];
                int balance = 0;

                // out_num exits window
                balance += ((out_num<=max_heap.top()) ? -1:1);
                toberemoved[out_num]++;

                // in_num enters window
                if (max_heap.empty() || in_num <= max_heap.top()) {
                    max_heap.push(in_num);
                    balance++;
                }
                else {
                    min_heap.push(in_num);
                    balance--;
                }

                // Rebalance the heaps
                if(balance<0){
                    max_heap.push(min_heap.top());
                    min_heap.pop();
                    balance++;
                }
                if(balance>0){
                    min_heap.push(max_heap.top());
                    max_heap.pop();
                    balance--;
                }

                // Remove outgoing number
                remove(max_heap);
                remove(min_heap);
            }

        return medians;
        }
    };