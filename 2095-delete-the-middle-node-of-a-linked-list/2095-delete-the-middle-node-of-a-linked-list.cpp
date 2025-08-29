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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return NULL;
        ListNode* slowptr= new ListNode();
        slowptr->next= head;
        ListNode* fastptr= head;
        while(fastptr and fastptr->next){
            fastptr=fastptr->next->next;
            slowptr= slowptr->next;
        }
        slowptr->next= slowptr->next->next;
        return head;
    }
};