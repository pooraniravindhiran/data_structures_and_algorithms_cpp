// SC- O(k) where k is num of unique pts

class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> points;
public:
    DetectSquares() {
    }
    
    void add(vector<int> point) {
        // TC- O(1)
        points[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        // TC- O(k)
        int x1 = point[0];
        int y1 = point[1];
        int ans = 0;

        // check for x2, y2 with same x value
        for(const auto& [y2, freq]: points[x1]){
            int d = y1-y2;

            if(d==0)
                continue;
            
            // check for right square
            ans += freq * points[x1+d][y1] * points[x1+d][y2];

            // check for left square
            ans += freq * points[x1-d][y1] * points[x1-d][y2];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */