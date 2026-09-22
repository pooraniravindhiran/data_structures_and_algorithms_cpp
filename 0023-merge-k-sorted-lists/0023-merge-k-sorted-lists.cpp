// TC- O(nlogk)
// SC- O(k)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        auto cmp = [& lists](const auto& a, const auto& b){return a->val>b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> min_heap(cmp);

        for(auto& curr_list:lists){
            if(curr_list)
                min_heap.push(curr_list);
        }
        
        while(!min_heap.empty()){
            ListNode* top = min_heap.top();
            min_heap.pop();
            curr->next = top;
            if(top->next)
                min_heap.push(top->next);
            curr = curr->next;
        }
        return dummy->next;
    }
};