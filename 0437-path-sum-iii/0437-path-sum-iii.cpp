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
    int ans = 0;
    void check(TreeNode* root,long long int t){
        if(root==NULL) return ;
        if(root->val==t) ans++;
        check(root->left,t-root->val);
        check(root->right,t-root->val);
    }
    void recur(TreeNode* root,long long int t){
        if(root==NULL) return ;
        check(root,t);
        recur(root->left,t);
        recur(root->right,t);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL) return 0;
        recur(root,targetSum);
        return ans;
    }
};