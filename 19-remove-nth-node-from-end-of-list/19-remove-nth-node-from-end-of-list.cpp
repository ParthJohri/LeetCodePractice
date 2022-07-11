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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head, *right=head, *prev=head;
        if(head==NULL) return NULL;
        if(head->next==NULL && n==1) return NULL;
        int c=0,count=0;
        while(curr!=NULL) {
            c++;
            if(c>n) {
                prev=right;
                right=right->next;
            }
            curr=curr->next;
            ++count;
        }
        prev->next=right->next;
        if(count==n) {
            return head->next;
        }
        return head;
    }
};