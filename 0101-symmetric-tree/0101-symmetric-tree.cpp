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
    bool isSymmetricHelper(TreeNode* leftnode, TreeNode* rightnode){
        if(leftnode==NULL and rightnode==NULL) return true;
        else if(leftnode==NULL or rightnode==NULL) return false;
        else if(leftnode->val!=rightnode->val) return false;
        return isSymmetricHelper(leftnode->right,rightnode->left) and isSymmetricHelper(leftnode->left,rightnode->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(root!=NULL){
            return isSymmetricHelper(root->left,root->right);
        }
        return false;
    }
};