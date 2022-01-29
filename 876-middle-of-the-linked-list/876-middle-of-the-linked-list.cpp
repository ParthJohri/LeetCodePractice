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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        int count=0,move=0;
        while(temp!=NULL)
            {++count;
            temp=temp->next;}
        if(count&1)
            move=(count+1)/2;
        else
            move=count/2+1;
        ListNode* ans=head;
        while(--move>0)
            ans=ans->next;
        return ans;
    }
};