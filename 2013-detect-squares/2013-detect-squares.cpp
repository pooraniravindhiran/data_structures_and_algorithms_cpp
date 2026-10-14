class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> points;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];

        points[x][y]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;

        int x1 = point[0];
        int y1 = point[1];

        for(auto& x2:points){
            int dx = abs(x2.first-x1);
            if(dx==0)
                continue;
            
            for(auto& [y2, freq]:points[x2.first]){
                int dy = abs(y2-y1);
                if(dx!=dy)
                    continue;
                
                ans += freq* points[x1][y2] * points[x2.first][y1];
            }
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