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
    // Reversing the Linked List
    ListNode* reverse(ListNode* &l)
    {
        ListNode* curr=l,*prev=NULL;
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    // Counting Number Of Nodes
    int countLL(ListNode* &l1)
    {
        ListNode* curr=l1;
        int count=0;
        while(curr!=NULL)
        {
            ++count;
            curr=curr->next;
        }
        return count;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* ans=new ListNode(0);
        
        ListNode *curr1=l1,*curr2=l2, *curr=ans;
        int sum=0,carry=0;
        
        int n1=countLL(l1);
        int n2=countLL(l2);
        
        ans->val=(curr1->val+curr2->val+carry)%10;
        carry=(curr1->val+curr2->val+carry)/10;
        
        curr1=curr1->next;
        curr2=curr2->next;
        
        while(curr1!=NULL&&curr2!=NULL)
        {
            sum=(curr1->val+curr2->val+carry)%10;
            carry=(curr1->val+curr2->val+carry)/10;
            ListNode *temp=new ListNode(sum);
            curr->next=temp;
            curr=curr->next;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        if(n1>n2)
        {
            while(curr1!=NULL)
            {
                sum=(curr1->val+carry)%10;
                carry=(curr1->val+carry)/10;
                ListNode* temp=new ListNode(sum);
                curr->next=temp;
                curr=curr->next;
                curr1=curr1->next;
            }
            
        }
        else
        {
            while(curr2!=NULL)
            {
                sum=(curr2->val+carry)%10;
                carry=(curr2->val+carry)/10;
                ListNode* temp=new ListNode(sum);
                curr->next=temp;
                curr=curr->next;
                curr2=curr2->next;
            }
        }
        if(carry!=0)
        {
            ListNode* temp=new ListNode(carry);
            curr->next=temp;
            curr=curr->next;
        }
        return ans;
 
    }
};