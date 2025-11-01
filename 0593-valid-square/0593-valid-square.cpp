// TC- O(1)
// SC- O(1)

class Solution {
private:
    int dist(vector<int>& a, vector<int>& b){
        return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]);
    }
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        // equal sides and equal diagonals is enough criteria
        
        vector<int> dists{dist(p1,p2), dist(p1,p3), dist(p1,p4), dist(p2,p3), dist(p2,p4), dist(p3,p4)};

        sort(dists.begin(), dists.end());

        // check if side len > 0
        if(dists[0]==0) return false;

        // check if all 4 sides are equal
        if(!(dists[0]==dists[1] && dists[0]==dists[2] && dists[0]==dists[3])) return false;

        // check if 2 diagonals are equal in len and greater than sides
        if(dists[4]!=dists[5] or dists[4]<=dists[0]) return false;

        return true;
    }
};
