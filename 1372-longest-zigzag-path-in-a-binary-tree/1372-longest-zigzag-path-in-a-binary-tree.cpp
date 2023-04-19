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
    int ans=0;
    void dfs(TreeNode* root,bool b,int cur){
        if(!root) return ;
        ans=max(ans,cur);
        dfs(root->left,true,(!b?cur+1:1));
        dfs(root->right,false,(b?cur+1:1));
    }
    int longestZigZag(TreeNode* root) {
        if(root->left==NULL and root->right==NULL) return 0;
        dfs(root,true,0);
        dfs(root,false,0);
        return ans;
    }
};