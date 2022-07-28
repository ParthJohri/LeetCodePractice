/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // 1st Solution TC: O(M*N) SC:O(1)
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     if(headA==NULL || headB==NULL) return NULL;
    //     ListNode* curr1=headA,*curr2=headB;
    //     while(curr1!=NULL){
    //         curr2=headB;
    //         while(curr2!=NULL){
    //             if(curr2->next==curr1||curr2==curr1){
    //                 return curr1;
    //             }
    //             curr2=curr2->next;
    //         }
    //         curr1=curr1->next;
    //     }
    //     return NULL;
    // }
    // 2nd Solution TC:O(M+N) SC:O(M)
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     if(headA==NULL || headB==NULL) return NULL;
    //     ListNode* curr1=headA,*curr2=headB;
    //     map<ListNode*,int> m;
    //     while(curr1!=NULL){
    //         m[curr1]++;
    //         curr1=curr1->next;
    //     }
    //     while(curr2!=NULL){
    //         if(m[curr2]) return curr2;
    //         curr2=curr2->next;
    //     }
    //     return NULL;
    // }
    // 3rd Solution TC:O(M+N) SC:O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL || headB==NULL) return NULL;
        ListNode* curr1=headA,*curr2=headB;
        int lenA=0,lenB=0;
        while(curr1!=NULL){
            lenA++;
            curr1=curr1->next;
        }
        while(curr2!=NULL){
            lenB++;
            curr2=curr2->next;
        }
        int diff=abs(lenA-lenB);
        curr1=headA,curr2=headB;
        if(lenA>lenB){
            while(diff--){
            curr1=curr1->next;
            }
        }
        else{
            while(diff--){
            curr2=curr2->next;
            }
        }
        while(curr1!=NULL && curr2!=NULL){
            if(curr1==curr2)
                return curr1;
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
    }
};