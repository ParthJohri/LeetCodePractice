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
        int zero=0,sum=0;
        if(head==NULL or head->next==NULL) return NULL;
        ListNode* temp=head,*nhead=new ListNode(0),*temp2;
        temp2=nhead;
        bool flag=true;
        while(temp!=NULL){
            if(temp->val==0){
                ++zero;
            }
            sum+=temp->val;
            if(zero%2==0){
                if(flag){
                    nhead->val=sum;
                    flag=false;
                }
                else{
                    ListNode* ntemp=new ListNode(sum);
                    temp2->next=ntemp;
                    temp2=temp2->next;
                }
                sum=0;
                zero=1;
            }
            temp=temp->next;
        }
        if(nhead->next==NULL and nhead->val==0)
            return NULL;
        return nhead;
    }
};