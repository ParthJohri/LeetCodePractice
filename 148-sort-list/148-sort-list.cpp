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
    ListNode* sortList(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* curr=head;
        vector<int> v;
        while(curr!=NULL){
            v.push_back(curr->val);
            curr=curr->next;
        }
        sort(v.begin(),v.end());
        ListNode* nhead=new ListNode(v[0]);
        curr=nhead;
        for(int i=1;i<v.size();i++){
            ListNode* temp=new ListNode(v[i]);
            curr->next=temp;
            curr=curr->next;
        }
        return nhead;
    }
};