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
        int count=0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            ++count;
            if(count>10e4)
                break;
            curr=curr->next;
        }
        return count>10e4;
    }
};