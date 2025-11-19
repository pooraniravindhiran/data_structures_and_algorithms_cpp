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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        while(l1 or l2 or carry){
            int a = l1 ? l1->val: 0;
            int b = l2 ? l2->val:0;
            sum = a+b+carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* node = new ListNode(sum);
            curr->next = node;
            curr = curr->next;
            if(l1)
                l1=l1->next;
            if(l2)
                l2= l2->next;
        }
        return dummy->next;
    }
};