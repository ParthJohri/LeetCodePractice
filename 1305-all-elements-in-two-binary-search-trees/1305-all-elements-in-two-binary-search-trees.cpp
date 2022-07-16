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
    
    void dfs(vector<int> &v,TreeNode* root){
        if(root==NULL) return;
        if(root->left) dfs(v,root->left);
        v.push_back(root->val);
        if(root->right) dfs(v,root->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1,v2;

        dfs(v1,root1);
        dfs(v2,root2);
        
        int i=0,j=0,m=v1.size(),n=v2.size(),x=0;
        vector<int> ans(m+n,0);
        while(i<m && j<n){
            if(v1[i]<=v2[j]){
                ans[x++]=v1[i++];
            }
            else
                ans[x++]=v2[j++];
        }
        while(i<m){
            ans[x++]=v1[i++];
        }
        while(j<n){
            ans[x++]=v2[j++];
        }
        return ans;
    }
};