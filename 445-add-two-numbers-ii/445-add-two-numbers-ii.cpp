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
    int countNodes(ListNode* head)
    {
        int count=0;
        while(head!=NULL)
        {
            ++count;
            head=head->next;
        }
        return count;
    }
    ListNode* rev(ListNode* head)
    {
        ListNode *curr,*prev;
        curr=head;
        prev=NULL;
        if(head==NULL)
            return NULL;
        while(curr!=NULL)
        {
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int n1,n2,s=0,carry=0;
        
        n1=countNodes(l1);
        
        n2=countNodes(l2);
        
        ListNode* curr1=rev(l1);
        
        ListNode* curr2=rev(l2);
        
        ListNode* ans=new ListNode(0);
        
        s=(curr1->val+curr2->val+carry)%10;
        
        carry=(curr1->val+curr2->val+carry)/10;
        
        ans->val=s;
        
        ListNode* curr=ans;
        
        curr1=curr1->next;
        
        curr2=curr2->next;
        
        cout<<curr->val<<" ";

        while(curr1!=NULL&&curr2!=NULL)
        {
            s=(curr1->val+curr2->val+carry)%10;
            
            carry=(curr1->val+curr2->val+carry)/10;
            
            ListNode* temp=new ListNode(0);
            
            temp->val=s;
            
            curr->next=temp;
            
            curr=curr->next;
                    
            curr1=curr1->next;
            
            curr2=curr2->next;
        }            
        
        if(curr1!=NULL)
        {
        
        while(curr1!=NULL)
            
       { s=(curr1->val+carry)%10;
            
        carry=(curr1->val+carry)/10;
        
        ListNode* temp=new ListNode(0);

        temp->val=s;

        curr->next=temp;
        
        curr1=curr1->next;
        
        curr=curr->next;}
        
        }
        
        else if(curr2!=NULL)
        {
        
        while(curr2!=NULL)
                
        { s=(curr2->val+carry)%10;
            
        carry=(curr2->val+carry)/10;
        
        ListNode* temp=new ListNode(0);

        temp->val=s;

        curr->next=temp;
    
         curr2=curr2->next;
         
        curr=curr->next;
        }
        }
            
        if(carry!=0)
        {
        
        ListNode* temp=new ListNode(0);

        temp->val=carry;

        curr->next=temp;

        curr=curr->next;
            
        }
        ans=rev(ans);
        
        return ans;
    }
};