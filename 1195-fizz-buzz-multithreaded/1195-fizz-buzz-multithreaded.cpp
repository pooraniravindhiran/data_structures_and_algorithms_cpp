// TC: O(n)
// SC: O(1)
class FizzBuzz {
private:
    int n;
    mutex m;
    condition_variable cv;
    int i;

public:
    FizzBuzz(int n) {
        this->n = n;
        i = 1;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while(true){
            unique_lock<mutex> lock(m);

            cv.wait(lock, [this](){
                return i>n or (i%3==0 and i%5!=0);
            });

            if(i>n)
                return;

            printFizz();
            i++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while(true){
            unique_lock<mutex> lock(m);

            cv.wait(lock, [this](){
                return i>n or (i%3!=0 and i%5==0);
            });

            if(i>n)
                return;
                
            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while(true){
            unique_lock<mutex> lock(m);

            cv.wait(lock, [this](){
                return i>n or (i%3==0 and i%5==0);
            });

            if(i>n)
                return;
                
            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while(true){
            unique_lock<mutex> lock(m);

            cv.wait(lock, [this](){
                return i>n or (i%3!=0 and i%5!=0);
            });

            if(i>n)
                return;
                
            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};