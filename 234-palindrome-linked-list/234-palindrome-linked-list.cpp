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
    bool isPalindrome(ListNode* head) {
        ListNode* curr=head;
        stack<int> s,s1;
        while(curr!=NULL)
        {
            s.push(curr->val);
            curr=curr->next;
        }
        int num=s.size();
        int n=s.size()/2;
        int m=n;
        while(n--)
        {
            s1.push(s.top());
            s.pop();
        }
        if(num%2!=0)
            s.pop();
        while(m--)
        {
            if(s.top()!=s1.top())
                return false;
            s.pop();
            s1.pop();
        }
        return true;
    }
};