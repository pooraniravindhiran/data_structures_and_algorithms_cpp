
//SC- O(N)
//TC- O(1)

class ProductOfNumbers {
    vector<int> list;
public:
    ProductOfNumbers() {
        list = {1};
    }
    
    void add(int num) {
        if(num==0)
            list = {1};
        else
            list.push_back(list.back()*num);
    }
    
    int getProduct(int k) {
        int n = list.size();
        if(k>=n)
            return 0;
        return list.back()/list[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */