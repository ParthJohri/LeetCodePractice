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
    int sumNode(TreeNode* root){
        if(root==NULL) return 0;
        return root->val+sumNode(root->left)+sumNode(root->right);
    }
    int findTilt(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=0,rh=0;
        if(root->left)
        lh=sumNode(root->left);
        if(root->right)
        rh=sumNode(root->right);
        return abs(lh-rh)+findTilt(root->left)+findTilt(root->right);
    }
};