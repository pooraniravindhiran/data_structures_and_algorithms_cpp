// TC- O(nlog(max(piles)))
// SC- O(1)

class Solution {
public:
    bool canEat(const int speed, const int h, const vector<int>& piles){
        int total_h = 0;
        for(int pile:piles){
            total_h += pile/speed;
            if(pile%speed!=0)
                total_h ++;
        }
        return total_h<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        for(int pile:piles)
            right = max(right, pile);
        
        while(left<right){
            int mid = left+(right-left)/2;
            if(canEat(mid, h, piles))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
};