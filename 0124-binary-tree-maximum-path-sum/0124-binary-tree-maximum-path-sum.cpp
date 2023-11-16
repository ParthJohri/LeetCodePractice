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
    int recur(TreeNode* root,int& result){
        if(root==NULL) return 0;
        int l=recur(root->left,result);
        int r=recur(root->right,result);
        int temp=max(root->val,root->val+max(l,r));
        int ans=max(temp,root->val+l+r);
        result=max(result,ans);
        return temp;
    }
    int maxPathSum(TreeNode* root) {
        int result=INT_MIN;
        recur(root,result);
        return result;
    }
};