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
    int numComponents(ListNode* head, vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int count=m.size();
        ListNode* temp=head;
        while(temp->next!=NULL){
            if(m[temp->val]>0 and m[temp->next->val]>0){
                --count;
            }
            temp=temp->next;
        }
        return count;
    }
};