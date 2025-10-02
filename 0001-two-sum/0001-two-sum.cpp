// TC- O(n)
// SC- O(n)

class Solution {
    unordered_map<int, int> visited;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int n=0; n<nums.size(); n++){
            if(visited.count(nums[n])){
                result.push_back(n);
                result.push_back(visited[nums[n]]);
                break;
            }
            visited[target-nums[n]]=n;
        }
        return result;
    }
};