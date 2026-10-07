// SC- O(n)

class MovingAverage {
private:
    int num;
    int sum;
    queue<int> q;
public:
    MovingAverage(int size) {
        // TC- O(1)
        this->num = size;
        this->sum = 0;
    }
    
    double next(int val) {
        // TC- O(1)
        q.push(val);

        while (!q.empty() and q.size()>num){
            sum -= q.front();
            q.pop();
        }

        sum += val;
        return (double) sum/q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */