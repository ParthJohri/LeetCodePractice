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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *curr1=list1,*curr2=list2,*ptr;
        if(curr1==NULL&&curr2==NULL) return NULL;
        if(curr1==NULL&&curr2!=NULL) return curr2;
        if(curr1!=NULL&&curr2==NULL) return curr1;
        ListNode* head=new ListNode(0);
        ptr=head;
        while(curr1!=NULL&&curr2!=NULL)
        {
            if(curr1->val<=curr2->val)
            {
                ptr->next=curr1;
                curr1=curr1->next;
            }
            else
            {
                ptr->next=curr2;
                curr2=curr2->next;
            }
            ptr=ptr->next;
        }
        if(curr1!=NULL)
        {
            ptr->next=curr1;
        }
        if(curr2!=NULL)
        {
            ptr->next=curr2;
        }
        return head->next;
    }
};