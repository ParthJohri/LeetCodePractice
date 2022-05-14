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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* curr=head;
        ListNode* temp=head;
        vector<int> od,ev;
        int count=1,c=0,e=0,x=0,y=0;
        while(curr!=NULL)
        {
            if(count&1)
                {c++;od.push_back(curr->val);}
            else
                {e++;ev.push_back(curr->val);}
            curr=curr->next;
            count++;
        }
         while(temp!=NULL)
        {
             if(c>0)
                 {temp->val=od[x++];c--;}
             else if(e>0)
                 {temp->val=ev[y++];e--;}
            temp=temp->next;
        }
        return head;
    }
};