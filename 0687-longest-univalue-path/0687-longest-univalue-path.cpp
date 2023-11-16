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
    int recur(TreeNode* root,int& res,TreeNode* prev){
        if(root==NULL) return 0;
        int l=recur(root->left,res,root);
        int r=recur(root->right,res,root);
        
        int temp=0;
        if(prev!=NULL and prev->val==root->val)
            temp=1+max(l,r);

        int ans = max(temp,1+l+r);
        res = max(res,ans);
        
        return temp;
    }
    int longestUnivaluePath(TreeNode* root) {
        int res=0;
        TreeNode* ptr=NULL;
        if(root==NULL) return 0;
        recur(root,res,ptr);
        return res-1;
    }
};