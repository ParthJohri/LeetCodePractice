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
    void dfs(TreeNode* root, vector<int> &v){
        if(root==NULL) return;
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        dfs(root,v);
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        int n=v.size()-1;
        return bst(0,n,v);
    }
    TreeNode* bst(int i,int e,vector<int> &v){
        if(i>e) return NULL;
        int mid=i+(e-i)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=bst(i,mid-1,v);
        root->right=bst(mid+1,e,v);
        return root;
    }
};