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
    int getDecimalValue(ListNode* head) {
       int count=0,sum=0;
        ListNode* temp=head;
        while(temp!=NULL)
            {++count;
            temp=temp->next;}
        while(head!=NULL)
        {
            sum=sum+head->val*pow(2,--count);
            head=head->next;
        }
        return sum;
    }
};