// TC- O(l)
// SC- O(1)

class Solution {
private:
    int l;
    bool withinBounds(int idx){
        return (idx>=0 and idx<l);
    }
public:

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        l = flowerbed.size();
        for(int i=0; i<flowerbed.size(); i++){
            if(flowerbed[i]==0){
                bool leftEmpty = !withinBounds(i-1) || flowerbed[i-1]!=1;
                bool rightEmpty = !withinBounds(i+1) || flowerbed[i+1]!=1;
                if(leftEmpty && rightEmpty){
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }
        if(n>0)
            return false;
        return true;
    }
};