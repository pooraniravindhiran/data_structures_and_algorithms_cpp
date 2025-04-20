class MedianFinder {
private:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        // TC- O(logn)
        // SC- O(n)
        if(max_heap.empty() or num<max_heap.top())
            max_heap.push(num);
        else    
            min_heap.push(num);
        
        // balance the heaps
        if(min_heap.size()>max_heap.size()){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
        else if(min_heap.size()+1<max_heap.size()){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
    }
    
    double findMedian() {
        // TC- O(1)
        // SC- O(1)
        if(min_heap.size()==max_heap.size())
            return (double)(min_heap.top()+max_heap.top())/2.0;
        else
            return max_heap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */