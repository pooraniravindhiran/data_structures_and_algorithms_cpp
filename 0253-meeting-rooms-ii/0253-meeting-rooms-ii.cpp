// TC - O(nlogn)
// SC - O(n)

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if(intervals.size()==0)
            return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b){return a[0]<b[0];});
        // why min heap and not max heap? because we wanna find the earliest available room
        priority_queue<int, vector<int>, greater<int>> min_heap;

        for(int i=0; i<intervals.size(); i++){
            if(min_heap.empty() or intervals[i][0]<min_heap.top())
                min_heap.push(intervals[i][1]);
            else{
                min_heap.pop();
                min_heap.push(intervals[i][1]);
            }
        }

        return min_heap.size();
    }
};