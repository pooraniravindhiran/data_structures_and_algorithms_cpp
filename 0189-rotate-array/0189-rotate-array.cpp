// TC- O(n)
// SC- O(1)

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // split into 2 halves- one half is len%k elements
        k = k%nums.size();

        // reverse both halves
        for(int i = 0, j = nums.size() - k -1; i<j; i++, j--)
            swap(nums[i], nums[j]);
        for(int i = nums.size()-k, j = nums.size()-1; i<j; i++, j--)
            swap(nums[i], nums[j]);

        // swap till middle
        for(int i=0, j=nums.size()-1; i<j; i++, j--)
            swap(nums[i], nums[j]);
    }
};