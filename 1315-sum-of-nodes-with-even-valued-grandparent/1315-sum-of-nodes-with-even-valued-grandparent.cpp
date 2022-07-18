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
    int sum=0;
    // Using GrandParents
    int helper(TreeNode* root,int p,int gp){
        if(root==NULL) return 0;
        sum+=gp%2==0?root->val:0;
        helper(root->left,root->val,p);
        helper(root->right,root->val,p);
        return sum;
    }
    // int sumEvenGrandparent(TreeNode* root) {
    //     if(root==NULL) return 0;
    //     return helper(root,1,1);
    // }
    
    // Using GrandChildren
    int sumEvenGrandparent(TreeNode* root) {
        if(root==NULL) return 0;
        if(root->val%2==0){
            if(root->left){
                if(root->left->left){
                    sum+=root->left->left->val;
                }
                if(root->left->right){
                    sum+=root->left->right->val;
                }
            }
            if(root->right){
                if(root->right->left){
                    sum+=root->right->left->val;
                }
                if(root->right->right){
                    sum+=root->right->right->val;
                }
            }
        }
        sumEvenGrandparent(root->left);
        sumEvenGrandparent(root->right);
        return sum;
    }
};