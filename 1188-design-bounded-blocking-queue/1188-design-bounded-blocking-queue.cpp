class BoundedBlockingQueue {
private:
    queue<int> q;
    mutex m;
    condition_variable cv_notfull;
    condition_variable cv_notempty;
    int capacity;
public:
    BoundedBlockingQueue(int capacity) {
        this->capacity = capacity;
    }
    
    void enqueue(int element) {
        unique_lock<mutex> lock(m);

        cv_notfull.wait(lock, [this](){
            return q.size()<capacity;
        });

        q.push(element);
        cv_notempty.notify_all();
    }
    
    int dequeue() {
        unique_lock<mutex> lock(m);

        cv_notempty.wait(lock, [this](){
            return !q.empty();
        });

        int element = q.front();
        q.pop();
        cv_notfull.notify_all();

        return element;
    }
    
    int size() {
        return q.size();
    }
};