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
    int recur(TreeNode* root,vector<int>&nums){
        if(root==NULL) return 0;
        if(root->left==NULL and root->right==NULL){
            int odd=0;
            nums[root->val]++;
            for(auto i:nums){
                if(i%2) odd++;
            }
            nums[root->val]--;
            return odd<=1;
        }
        nums[root->val]++;
        int l=0,r=0;
        l=recur(root->left,nums);
        r=recur(root->right,nums);
        nums[root->val]--;
        return l+r;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> nums(10,0);
        return recur(root,nums);
    }
};