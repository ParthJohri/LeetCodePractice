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
    int gcd(int a, int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr=head;
        while(curr!=NULL and curr->next!=NULL){
           int val = gcd(curr->val,curr->next->val);
           ListNode* g = new ListNode(val);      
           ListNode* temp=curr->next;
           curr->next = g;
           g->next = temp;
           curr=temp;
        }
        return head;
    }
};