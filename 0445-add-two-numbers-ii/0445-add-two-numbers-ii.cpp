// TC- O(m+n)
// SC- O(m+n)

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
private:
    stack<int> s1, s2;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* result = nullptr;

        while(!s1.empty() or !s2.empty() or carry){
            int sum = carry;
            if(!s1.empty()){
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                sum += s2.top();
                s2.pop();
            }
            int digit = sum%10;
            carry = sum/10;
            ListNode* curr = new ListNode(digit);
            curr->next = result;
            result = curr;
        }
        return result;
    }
};