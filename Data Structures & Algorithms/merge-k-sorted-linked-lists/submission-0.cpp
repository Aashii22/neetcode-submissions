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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        ListNode* ans = new ListNode();
        ListNode* tmp = ans;

        auto cmp = [](ListNode* a, ListNode* b) { 
            return a->val > b->val; 
        };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq;
        for(auto *x: lists){
            if(x)
            pq.push(x);
        }

        while(!pq.empty()){

            ListNode* curr = pq.top();
            pq.pop();

            tmp->next = curr;
            tmp = tmp->next;

            if(curr->next)
            pq.push(curr->next);
        }

        return ans->next;
    }
};
