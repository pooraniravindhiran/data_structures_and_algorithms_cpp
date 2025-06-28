// TC- O(n)
// SC- O(1)
class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool foundx=false, foundy=false, foundz=false;

        for(auto& triplet:triplets){
            int x=triplet[0], y=triplet[1], z=triplet[2];

            // if even one value overshoots target, skip it
            if(x>target[0] or y>target[1] or z>target[2])
                continue;
            
            // we need atleast one triplet with same value as in target
            if(x==target[0]) foundx=true;
            if(y==target[1]) foundy=true;
            if(z==target[2]) foundz=true;
        }
        return foundx&foundy&foundz;
    }
};