// TC- O(n)
// SC- O(1)

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        if(target.size()==0)
            return 0;
        int ans = target[0];
        for(int i=1; i<target.size(); i++){
            if(target[i]>target[i-1])
                ans += target[i]-target[i-1];
        }
        return ans;
    }
};