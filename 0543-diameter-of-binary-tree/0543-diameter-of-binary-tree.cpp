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
    int recur(TreeNode* root,int &res){
        if(root==NULL) return 0;
        int l=recur(root->left,res);
        int r=recur(root->right,res);
        int temp=1+max(l,r);
        int ans=max(temp,1+r+l);
        res=max(ans,res);
        return temp;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=INT_MIN;
        recur(root,res);
        return res-1;
    }
};