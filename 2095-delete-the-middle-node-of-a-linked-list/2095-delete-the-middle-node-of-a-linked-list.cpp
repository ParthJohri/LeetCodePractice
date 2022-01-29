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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        int count=0,move=0;
        while(temp!=NULL)
        {++count;
        temp=temp->next;}
        if(count==1||head==NULL)
            return NULL;
        if(count&1)
            move=(count+1)/2;
        else
            move=count/2+1;
        move-=2;
        ListNode* curr=head;
        ListNode* prev;
        while(move-->0)
        {
            curr=curr->next;
        }
        curr->next=curr->next->next;
        return head;
    }
};