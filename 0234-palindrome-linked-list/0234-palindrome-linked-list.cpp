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
    bool isPalindrome(ListNode* head) {
        // find middle node if odd or middle-1 if even
        // reverse first half and compre

        // find length of list
        int list_len = 0;
        ListNode* curr = head;
        while(curr){
            list_len++;
            curr = curr->next;
        }

        // reverse second half
        int second_start_pos = ((list_len+1)/2)+1;
        int curr_len = 1;
        curr = head;
        while(curr_len<second_start_pos){
            curr = curr->next;
            curr_len++;
        }
        curr = reverse_list(curr);
        ListNode* test = curr;
        while(test){
            cout<<test->val<<" ";
            test = test->next;
        }

        // compare
        curr_len = 1;
        ListNode* curr2 = head;
        int compare_till_pos = (list_len%2==0) ? second_start_pos-1: second_start_pos-2;
        while(curr_len<=compare_till_pos){
            if(curr2->val!=curr->val)
                return false;
            curr = curr->next;
            curr2 = curr2->next;
            curr_len++;
        }
        return true;
    }
};