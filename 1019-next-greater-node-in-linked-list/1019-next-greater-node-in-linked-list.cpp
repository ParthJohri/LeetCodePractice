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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans,arr;
        ListNode* temp=head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        for(auto i:arr){
            cout<<i<<" ";
        }
        stack<int> s;
        ans=arr;
        s.push(arr[arr.size()-1]);
        int x=arr.size()-1;
        ans[x--]=0;
        for(int i=arr.size()-2;i>=0;i--){
            if(s.empty()) 
                ans[x--]=0;
            else if(s.top()>arr[i]){
                ans[x--]=s.top();
            }
            else{
                s.pop();
                while(!s.empty() and s.top()<=arr[i]){
                    s.pop();
                }
                if(!s.empty())
                    ans[x--]=s.top();
                else
                    ans[x--]=0;
            }
            s.push(arr[i]);
        }
        return ans;
    }
};