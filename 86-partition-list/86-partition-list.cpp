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
    ListNode* partition(ListNode* head, int x) {
        vector<int> v;
        ListNode* curr=head;
        ListNode* ncurr=head;
        while(curr!=NULL)
        {
            if(curr->val<x)
                v.push_back(curr->val);
            curr=curr->next;
        }
        while(ncurr!=NULL)
        {
            if(ncurr->val>=x)
                v.push_back(ncurr->val);
            ncurr=ncurr->next;
        }
        int y=0;
        ListNode* ans=head;
        while(ans!=NULL)
        {
            ans->val=v[y++];
            ans=ans->next;
        }
        return head;
    }
};