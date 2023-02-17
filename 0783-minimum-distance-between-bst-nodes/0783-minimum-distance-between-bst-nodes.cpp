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
    int recur(TreeNode* root,int& ans1,int& ans2){
        if(root->left) recur(root->left,ans1,ans2);
        if(ans2>=0)
        ans1=min(ans1,root->val-ans2);
        ans2=root->val;
        if(root->right) recur(root->right,ans1,ans2);
        return ans1;
    }
    int minDiffInBST(TreeNode* root) {
        int ans1=INT_MAX,ans2=-1;
        recur(root,ans1,ans2);
        return ans1;
    }
};