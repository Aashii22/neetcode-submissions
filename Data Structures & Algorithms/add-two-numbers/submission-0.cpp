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
        ListNode* ans = new ListNode(-1);

        ListNode* tmp = ans;
        int sum, carry=0;
        while(l1 || l2){

            if(l1 && l2){
                sum = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1){
                sum = l1->val;
                l1 = l1->next;
            }
            else{
                sum = l2->val;
                l2 = l2->next;
            }

            tmp->next = new ListNode((sum+carry)%10);
            tmp = tmp->next;
            carry = (sum+carry)/10;
        }

        while(carry>0){
            tmp->next = new ListNode((carry)%10);
            tmp = tmp->next;
            carry = (carry)/10;
        }

        return ans->next;
    }
};
