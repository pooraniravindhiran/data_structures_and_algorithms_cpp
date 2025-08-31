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

// TC- O(n)
// SC- O(1)

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // base case: if no list, or if there is only one node, or if left==right
        if(!head or left==right)
            return head;

        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;

        // move prev to node before left
        for(int i=1; i<left; i++)
            prev = prev->next;

        // reverse iteratively
        ListNode* curr = prev->next;
        for(int i=0; i<right-left; i++){
            ListNode* temp = curr->next;
            curr->next = temp->next; // remove temp
            temp->next = prev->next; // put temp before front of reversed list
            prev->next = temp;
            
        }

        return dummy->next;
    }
};