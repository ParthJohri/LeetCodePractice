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
    bool dfs(TreeNode* root,int x){
        if(root==NULL) return true;
        return root->val==x && dfs(root->left,x) && dfs(root->right,x);
    }
    bool isUnivalTree(TreeNode* root) {
        return dfs(root,root->val);
    }
};