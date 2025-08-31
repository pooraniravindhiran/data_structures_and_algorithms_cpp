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

// TC - O(n)
// SC - O(n)
class Solution {
private:
    ListNode* reverse_list(ListNode* head){
        if(!head or !head->next)
            return head;
        ListNode* newhead = reverse_list(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
public:
    int pairSum(ListNode* head) {

        // find middle ListNode
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while(fastptr and fastptr->next){
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
        }

        // reverse second half
        slowptr = reverse_list(slowptr);

        // find max twin pairSum
        int maxsum = 0;
        fastptr=head;
        while(slowptr){
            maxsum = max(maxsum, slowptr->val+fastptr->val);
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }

        return maxsum;
    }
};