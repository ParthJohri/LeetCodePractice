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
        ListNode* ans=new ListNode();
        ListNode* t=ans;
        int s=0;
        bool b=false;
        while(curr!=NULL)
        {
            if(curr->val==0 && b)
            {
                cout<<s;
                ListNode* temp=new ListNode(s);
                    if(ans->val==0)
                        ans->val=s;
                    else
                        {
                            t->next=temp; 
                            t=t->next;
                        }
                s=0;
            }
            else
            {
                b=true;
                s+=curr->val;
            }
            curr=curr->next;
        }
        return ans;
    }
};