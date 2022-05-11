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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root!=NULL)
        {
            rangeSumBST(root->left,low,high); 
            if(((root->val)>=low)&&((root->val)<=high))
            {cout<<root->val<<"\t";
             sum+=root->val;}
            rangeSumBST(root->right,low,high); 
        }
        return sum;
    }
};