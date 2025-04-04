// TC- O(nlogk)
// SC - O(k)

// class Solution {
// public:
//     vector<int> findClosestElements(vector<int>& arr, int k, int x) {

//         // result needs to be sorted and it should have k findClosestElements and time should be in one single pass - so priority queue is a good data structure here
//         // min or max? - we need to have k closest elements. top element is only removable, and hence it should be farthest element possible. so max heap.
//         auto cmp = [&x](int a, int b){
//             if(abs(a-x) == abs(b-x))
//                 return a<b;
//             return abs(a-x)<abs(b-x);
//         };
//         priority_queue<int, vector<int>, decltype(cmp)> max_heap(cmp);

//         for(int i=0; i<arr.size(); i++){
//             max_heap.push(arr[i]);
//             if(max_heap.size()>k)
//                 max_heap.pop();
//         }

//         vector<int> result;
//         while(!max_heap.empty()){
//             result.push_back(max_heap.top());
//             max_heap.pop();
//         }
//         sort(result.begin(), result.end());
//         return result;
//     }
// };

// binary search method
// SC- O(1)
// TC- O(k+log(n-k))
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size()-k;

        // since array is sorted, all you need to do is find leftmost index. and this index can be anywhere between left and right.
        while(left<right){
            int mid = left+(right-left)/2;

            // if(abs(arr[mid]-x)>abs(arr[mid+k]-x))
            if (x - arr[mid] > arr[mid + k] - x)
                left = mid + 1;
            else
                right = mid;
        }

        
        vector<int> result(arr.begin()+left, arr.begin()+left+k);
        return result;
    }
};