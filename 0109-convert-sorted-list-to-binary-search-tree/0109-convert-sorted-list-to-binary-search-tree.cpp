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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* curr=head;
        vector<int> nums;
        while(curr!=NULL){
            nums.push_back(curr->val);
            curr=curr->next;
        }
        return binarySearchAlgo(0,nums.size()-1,nums);
    }
    TreeNode* binarySearchAlgo(int l,int h,vector<int> &nums){
        if(l>h) return NULL;
        int mid=l+(h-l)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=binarySearchAlgo(l,mid-1,nums);
        root->right=binarySearchAlgo(mid+1,h,nums);
        return root;
    }
};