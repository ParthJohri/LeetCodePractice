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
    int pairSum(ListNode* head) {
      ListNode* curr=head;
        stack<int> s,s1;
        int ans=INT_MIN;
        while(curr!=NULL)
        {
            s.push(curr->val);
            curr=curr->next;
        }
        int n=s.size()/2;
        int m=n;
        while(n--!=0)
        {
            s1.push(s.top());
            s.pop();
        }
        while(m--!=0)
        {
            if(ans<=s.top()+s1.top())
            {
                ans=s.top()+s1.top();
            }
            s.pop();
            s1.pop();
        }
        return ans;
    }
};