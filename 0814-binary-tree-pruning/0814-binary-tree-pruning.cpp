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
    bool prune(TreeNode* root){
        if(root==NULL) return false;
        if(root->val==1) return true;
        return prune(root->left) or prune(root->right);
    }
    void dfs(TreeNode* root){
        if(root==NULL) return;
        if(!prune(root->left)) root->left=NULL;
        if(!prune(root->right)) root->right=NULL;
        dfs(root->left); 
        dfs(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL) return NULL;
        dfs(root);
        if(root->left==NULL and root->right==NULL and root->val==0) return NULL;
        return root;
    }
};