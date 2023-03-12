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
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* head=new ListNode(-1);
        ListNode* d=head;
        while(left!=NULL and right!=NULL){
            if(left->val<=right->val){
                d->next=left;
                left=left->next;
            }
            else{
                d->next=right;
                right=right->next;
            }
            d=d->next;
        }
        if(left!=NULL){
            d->next=left;
        }
        if(right!=NULL){
            d->next=right;
        }
        return head->next;
    }
    ListNode* mergeSort(int start, int end, vector<ListNode*>& lists){
        if(start==end) return lists[start];
        int mid=start+(end-start)/2;
        ListNode* left=mergeSort(start,mid,lists);
        ListNode* right=mergeSort(mid+1,end,lists);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        return mergeSort(0,lists.size()-1,lists);
    }
};