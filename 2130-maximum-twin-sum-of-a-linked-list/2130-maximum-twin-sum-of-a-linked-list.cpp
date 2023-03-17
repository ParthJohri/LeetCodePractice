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
        int sum=INT_MIN;
        // 16
        // 2->3->.,,,,,,->19
        //  1 2 3 4 5 6 7 8
        // {1,8 2,7, 3,6, 4,5}
        vector<int> v;
        ListNode* temp=head;
        while(temp!=NULL){
            v.push_back(temp->val);
            temp=temp->next;
        }
        int i=0,j=v.size()-1;
        while(i<j){
            sum=max(sum,v[i]+v[j]);
            i++;
            j--;
        }
        return sum;
    }
};