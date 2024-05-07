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
    ListNode* doubleIt(ListNode* head) {
        ListNode*curr=head;
        vector<int> v;
        while(curr){
            v.push_back(curr->val);
            curr=curr->next;
        }
        int carry=0;
        vector<int> temp;
        for(int i=v.size()-1;i>=0;i--){
            int val=(v[i]*2+carry)%10;
            carry = (v[i]*2+carry)/10;
            temp.push_back(val);
        }
        if(carry!=0) temp.push_back(carry);
        // for(auto i:temp) cout<<i<<" ";
        ListNode* nhead=new ListNode(temp[temp.size()-1]);
        ListNode* cur=nhead;
        for(int i=temp.size()-2;i>=0;i--){
            ListNode* t=new ListNode(temp[i]);
            cur->next=t;
            cur=cur->next;
        }
        return nhead;
    }
};