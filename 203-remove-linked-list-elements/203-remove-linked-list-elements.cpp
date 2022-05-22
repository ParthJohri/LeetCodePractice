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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        ListNode* curr=head;
        vector<int> v;
        while(curr!=NULL)
        {
            if(curr->val!=val)
                v.push_back(curr->val);
            curr=curr->next;
        }
        if(v.size()==0)
            return NULL;
        ListNode* temp=new ListNode(v[0]);
        ListNode* cur=temp;
        for(int i=1;i<v.size();i++)
        {
            ListNode* t=new ListNode(v[i]);
            cur->next=t;
            cur=cur->next;
        }
        return temp;
    }
};