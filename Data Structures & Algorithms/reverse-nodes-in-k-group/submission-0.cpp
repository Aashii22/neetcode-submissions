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
    ListNode* reverse(ListNode* &head, int k){
        ListNode* tmp = head;

        ListNode* prev = NULL, *curr = head;
        while(k>0){
            tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
            k--;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* prev = new ListNode(), *tmp = head;

        ListNode* ans = prev;
        while(tmp){

            ListNode* curr = tmp;
            for(int i=0; i<k-1; i++){
                if(tmp)
                tmp = tmp->next;
                else
                break;
            }
            if(!tmp){
                prev->next = curr;
                break;
            }

            ListNode* knext = tmp->next;
            ListNode* revhead = reverse(curr, k);
            prev->next = revhead;
            curr->next = knext;
            prev = curr;

            tmp = knext;
        }

        return ans->next;
    }
};
