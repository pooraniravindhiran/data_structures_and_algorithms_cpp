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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* firstNode= head;
        ListNode* secondNode= head->next;

        firstNode->next= swapPairs(secondNode->next);
        secondNode->next= firstNode;
 
        return secondNode;
    }
};

// class Solution {
//     ListNode* recursiveSwap(ListNode* prev, ListNode* curr){
//         cout<<prev->val<<"\t"<<curr->val<<endl;
//         ListNode* temp= curr->next;
//         curr->next= temp->next;
//         temp->next= curr;
//         prev->next= temp;
        
//         if(curr->next and curr->next->next)
//             recursiveSwap(curr, curr->next);
//         return prev->next;
//     }
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if(head==NULL or head->next==NULL)
//             return head;
//         ListNode* prev= new ListNode();
//         prev->next= head;
//         ListNode* curr= head;
//         return recursiveSwap(prev, curr);
//     }
// };