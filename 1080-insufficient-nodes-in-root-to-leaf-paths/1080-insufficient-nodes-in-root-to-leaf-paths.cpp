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
    int recur(TreeNode* root,int limit,int sum){
        if(root==NULL) return 0;
        if(root->left == root->right and root->left==NULL){
            if(sum+root->val<limit) return false;
            return true;
        }
        int l=recur(root->left,limit,sum+root->val);
        int r=recur(root->right,limit,sum+root->val);
        if(l==0) root->left=NULL;
        if(r==0) root->right=NULL;
        return l or r;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        TreeNode* r=new TreeNode(0);
        r->left=root;
        r->right=NULL;
        recur(r,limit,0);
        return r->left;
    }
};