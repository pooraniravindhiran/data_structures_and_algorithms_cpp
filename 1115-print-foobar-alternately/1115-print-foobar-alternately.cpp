// TC- O(n)
// SC- O(1)

class FooBar {
private:
    int n;
    bool foo_turn;
    mutex m;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        foo_turn = true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this](){
                return foo_turn;
            });
        	printFoo();
            foo_turn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this](){
                return !foo_turn;
            });

        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();

            foo_turn = true;

            cv.notify_one();
        }
    }
};