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
        if(head== NULL or k==0 or head->next==NULL)
            return head;
        
        //find len of list
        ListNode* curr= head;
        int len=0;
        while(curr!=NULL)
        {
            len++;
            curr= curr->next;
        }
        
        // find node that will become tail
        int count=0;
        curr= head;
        k= k%len;
        if(k==0)
            return head;
        cout<<k<<endl;
        while(count<(len-k-1))
        {
            curr= curr->next;
            count++;
        }
        
        // make that as tail and add second half to head
        ListNode* temp=curr->next;
        curr->next= NULL;
        if(temp)
        {
            ListNode* new_head= temp;
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next= head;
            head= new_head;
        }
        return head;
    }
};