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
    vector<int> ans;
    int mxlevel=0;
    void rightTree(TreeNode* root, int level)
    {
        if(root==NULL)
            return ;
        if(mxlevel<level)
        {
            ans.push_back(root->val);
            mxlevel=level;
        }
        rightTree(root->right,level+1);
        rightTree(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
       rightTree(root,1);
       return ans;
    }
};