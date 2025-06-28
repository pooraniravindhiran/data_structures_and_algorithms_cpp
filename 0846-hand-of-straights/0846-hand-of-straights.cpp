// TC- O(nlogn)
// SC- O(n)

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0)
            return false;
        
        // cards need to be grouped consecutively, so I need them in sorted order and I need to make sure duplicates are also used up, so use map
        map<int, int> count;
        for(auto& card:hand)
            count[card]++;

        while(!count.empty()){
            int card = count.begin()->first;
            int freq = count.begin()->second;
            if(freq==0){
                count.erase(card);
                continue;
            }

            for(int i=0; i<groupSize; i++){
                int curr = card+i;
                if(!count.count(curr) or count[curr]<freq)
                    return false;
                count[curr] -=freq;
            }
        }

        return true;
    }
};