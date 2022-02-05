/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
         ListNode *slow,*fast;
         slow=fast=head;
         if(head==NULL)
             return NULL;
        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast)
                return true;
        }
        return false;
        // My Solution
        // int count=0;
        // ListNode* curr=head;
        // while(curr!=NULL)
        // {
        //     ++count;
        //     if(count>10e4)
        //         break;
        //     curr=curr->next;
        // }
        // return count>10e4;
    }
};