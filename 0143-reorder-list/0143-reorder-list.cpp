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
    void reorderList(ListNode* head) {
        ListNode* curr=head;
        vector<pair<int,ListNode*>> v;
        while(curr){
            v.push_back({curr->val,curr});
            curr=curr->next;
        }
        int start=0,end=v.size()-1;
        ListNode* prev=NULL;
        while(start<end){
            if(prev!=NULL){
                prev->next=v[start].second;
            }
            v[start++].second->next=v[end].second;
            prev=v[end--].second;
            if(start>=end){
                prev->next=NULL;
            }
        }
        if(v.size()%2 and prev!=NULL){
            prev->next=v[start].second;
            v[start].second->next=NULL;
        }
    }
};