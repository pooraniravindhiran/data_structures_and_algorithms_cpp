// TC - O(m+n)
// SC - O(m+n)
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
    stack<int> s1;
    stack<int> s2;
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
        int sum = 0;
        ListNode* ans = NULL;
        while(!s1.empty() or !s2.empty() or carry==1){
            int a = 0;
            int b = 0;
            if(!s1.empty()){
                a = s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                b = s2.top();
                s2.pop();
            }
            sum = a+b+carry;
            carry = sum/10;
            sum = sum%10;
            ListNode* newNode = new ListNode(sum);
            newNode->next = ans;
            ans = newNode;
        }
        return ans;
    }
};