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
    void dfs(TreeNode* root,vector<int> &v){
        if(root==NULL) return;
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    // bool dfs(TreeNode* root,long min,long max){
    //     if(root==NULL) return true;
    //     return root->val>min && root->val<max && dfs(root->left,min,root->val) && dfs(root->right,root->val,max);
    // }
    bool dfs(TreeNode* root, long min, long max){
        if(root==NULL) return true;
        return root->val>min and root->val<max and dfs(root->left,min,root->val) and dfs(root->right,root->val,max);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        // Recursive Stack and min, max variables
        return dfs(root,LONG_MIN,LONG_MAX);
        // Inorder + Vector
        // vector<int> v;
        // dfs(root,v);
        // for(int i=0;i<v.size()-1;i++){
        //     if(v[i]>=v[i+1])
        //         return false;
        // }
        // return true;
    }
};