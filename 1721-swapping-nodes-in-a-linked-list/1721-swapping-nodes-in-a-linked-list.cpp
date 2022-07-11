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
    ListNode* swapNodes(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        ListNode* curr=head;
        ListNode* first,*second;
        int count=0,c=0,d=0;
        while(curr!=NULL) {
            c++;
            if(c==k) {
                first=curr;
            }
            count++;
            curr=curr->next;
        }
        cout<<first->val<<" "<<c<<endl;
        d=count-k+1;
        curr=head;
        while(curr!=NULL) {
            d--;
            if(d==0) {
                second=curr;
            }
            curr=curr->next;
        }
        cout<<second->val<<" "<<d<<endl;
        swap(first->val,second->val);
        return head;
    }
};