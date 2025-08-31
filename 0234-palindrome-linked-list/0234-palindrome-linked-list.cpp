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
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return true;
        
        // Find end of first half i.e mid point
        ListNode* slow_ptr= new ListNode;
        ListNode* fast_ptr= new ListNode;
        slow_ptr->next=head;
        fast_ptr->next=head;
        while(slow_ptr!=NULL and fast_ptr!=NULL and fast_ptr->next!=NULL)
        {
            slow_ptr=slow_ptr->next;
            fast_ptr=fast_ptr->next->next;
        }
        ListNode* end_of_first_half= slow_ptr;
        // cout<<"End of first"<<end_of_first_half->val<<endl;
        
        // Reverse second half
        ListNode* curr=end_of_first_half->next;
        ListNode* prev=curr;
        curr=curr->next;
        while(curr!=NULL)
        {
            // cout<<"Loop"<<curr->val<<endl;
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        end_of_first_half->next->next=NULL;
        end_of_first_half->next=prev;
        // while(head!=NULL)
        // {
        //     cout<<head->val<<endl;
        //     head=head->next;
        // }
        
        // Check if palindrome
        ListNode* curr1=head;
        ListNode* curr2=end_of_first_half->next;
        bool flag=true;
        while(curr2!=NULL)
        {
            if(curr1->val!=curr2->val)
                flag= false;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        
        // Reverse second half back to normal
        curr=end_of_first_half->next;
        prev=curr;
        curr=curr->next;
        while(curr!=NULL)
        {
            // cout<<"Loop"<<curr->val<<endl;
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        end_of_first_half->next->next=NULL;
        end_of_first_half->next=prev;
        
        // Return result
        return flag;
    }
};