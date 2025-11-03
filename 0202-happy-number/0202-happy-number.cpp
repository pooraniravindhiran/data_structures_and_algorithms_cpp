// TC- O(logn)
// SC- O(1)

class Solution {
private:
    int sum;
    int getNext(int n){
        sum = 0;
        while(n){
            sum += ((n%10) * (n%10));
            n = n/10;
            // cout<<n<<" ";
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slowptr = n;
        int fastptr = getNext(n);
        while(fastptr!=1 and slowptr!=fastptr){
            slowptr = getNext(slowptr);
            fastptr = getNext(getNext(fastptr));
        }
        return fastptr==1;
    }
};

// // TC- O(logn)
// // SC- O(logn)

// class Solution {
// private:
//     int sum;
//     int getNext(int n){
//         sum = 0;
//         while(n){
//             sum += ((n%10) * (n%10));
//             n = n/10;
//             // cout<<n<<" ";
//         }
//         return sum;
//     }
// public:
//     bool isHappy(int n) {
//         unordered_set<int> mem;
//         while(n!=1){
//             if(mem.count(n)!=0)
//                 return false;
//             mem.insert(n);
//             n = getNext(n);
//             // cout<<n<<" ";
//         }
//         return true;
//     }
// };