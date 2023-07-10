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
    void dfs(TreeNode* root,int count, int &mn){
        if(root==NULL){
            return;
        }
        count++;
        if(root->left==NULL&&root->right==NULL){
            if(count<mn)
            mn=count;
        }
        dfs(root->left,count,mn);
        dfs(root->right,count,mn);
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int count=0,mn=INT_MAX;
        dfs(root,count,mn);
        return mn;
    }
};