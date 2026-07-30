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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int m = 0;
        ListNode* tmp = head;

        while(tmp){
            tmp = tmp->next;
            m++;
        }

        m = m-n-1; tmp = head;

        if(m<0)
        return head->next;

        while(m--){
            tmp = tmp->next;
        }

        if(tmp->next){
            tmp->next = tmp->next->next;
        }

        return head;
    }
};
