// TC- O(n)
// SC- O(n)

class Solution {
private:
    unordered_set<int> present;
public:
    bool containsDuplicate(vector<int>& nums) {
        for(int n:nums){
            if(present.find(n)!=present.end())
                return true;
            present.insert(n);
        }
        return false;
    }
};