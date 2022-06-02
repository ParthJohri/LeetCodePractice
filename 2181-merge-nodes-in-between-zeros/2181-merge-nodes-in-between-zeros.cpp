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
    ListNode* mergeNodes(ListNode* head) {
        if(head==NULL) return nullptr;
        ListNode* curr=head;
        ListNode* ans=head;
        int s=0,x=0;
        curr=curr->next;
        while(curr!=NULL)
        {
            if(curr->val!=0)
            {
                s+=curr->val;
            }
            else
            {
                if(curr->next==NULL)
                    ans->next=NULL;
                ans->val=s;
                ans=ans->next;
                s=0;
            }
            curr=curr->next;
        }
        return head;
    }
};