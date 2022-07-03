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
            int v1=curr1->val;
            int v2=curr2->val;
            ListNode* tmp=new ListNode(0);
            if(v1<=v2)
            {
                tmp->val=v1;
                curr1=curr1->next;
            }
            else
            {
                tmp->val=v2;
                curr2=curr2->next;
            }
            ptr->next=tmp;
            ptr=ptr->next;
        }
        while(curr1!=NULL)
        {
            ListNode* tmp=new ListNode(0);
            tmp->val=curr1->val;
            ptr->next=tmp;
            ptr=ptr->next;
            curr1=curr1->next;
        }
        while(curr2!=NULL)
        {
            ListNode* tmp=new ListNode(0);
            tmp->val=curr2->val;
            ptr->next=tmp;
            ptr=ptr->next;
            curr2=curr2->next;
        }
        return head->next;
    }
};