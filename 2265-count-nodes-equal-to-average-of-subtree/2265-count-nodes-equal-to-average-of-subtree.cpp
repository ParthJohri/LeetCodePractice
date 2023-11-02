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
    int ans=0;
    pair<int,int> recur(TreeNode* root){
        if(root==NULL) return {0,0};
        int sum=root->val,count=1;
        pair<int,int> l=recur(root->left);
        pair<int,int> r=recur(root->right);
        count+=l.second+r.second;
        sum+=l.first+r.first;
        int v=floor(sum/(count*1.0));
        if(v==root->val) ++ans;
        return {sum,count};
    }
    int averageOfSubtree(TreeNode* root) {
        recur(root);
        return ans;
    }
};