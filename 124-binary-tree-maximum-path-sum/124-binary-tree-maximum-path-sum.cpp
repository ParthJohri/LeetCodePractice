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
    int maxPathSum(TreeNode* root) {
        int maxpathsum=INT_MIN;
        sum(root,maxpathsum);
        return maxpathsum;
    }
    int sum(TreeNode* root,int &s)
    {
        if(root==NULL) return 0;
        int ls=max(0,sum(root->left,s));
        int rs=max(0,sum(root->right,s));
        s=max(s,ls+rs+root->val);
        return root->val+max(ls,rs);
    }
};