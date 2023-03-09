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
    int dfs(TreeNode* root, int par){
        if(root==NULL) return 0;
        bool val=root->val>=par;
        int left=dfs(root->left,max(root->val,par));
        int right=dfs(root->right,max(root->val,par));
        return val+left+right;
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL) return 0;
        return dfs(root,INT_MIN);
    }
};