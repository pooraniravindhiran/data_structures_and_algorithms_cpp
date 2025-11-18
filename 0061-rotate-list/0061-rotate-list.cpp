// TC- O(n)
// SC- O(1)
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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(k==0 or head==NULL or head->next==NULL)
            return head;
            
        // Connect last node to head to make a cycle
        int len = 1; 
        ListNode* curr = head;
        while(curr->next){
            curr= curr->next;
            len++;
        }
        curr->next = head;

        // Find new tail
        k = k%len;
        int tailpos = len-k-1;

        // Break cycle at new tail
        curr = head;
        while(tailpos--)
            curr= curr->next;
        
        ListNode* newhead = curr->next;
        curr->next = NULL;
        return newhead;

    }
};