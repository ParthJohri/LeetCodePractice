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
    // TreeNode* constructBST(int start,int end,vector<int> v){
    //     if(start>end) return NULL;
    //     int mid=start+(end-start)/2;
    //     TreeNode* root=new TreeNode(v[mid]);
    //     root->left=constructBST(start,mid-1,v);
    //     root->right=constructBST(mid+1,end,v);
    //     return root;
    // }
    // void dfs(TreeNode* root,vector<int> &v,int low,int high){
    //     if(root==NULL) return;
    //     dfs(root->left,v,low,high);
    //     if(root->val<low || root->val>high)
    //     v.push_back(root->val);
    //     dfs(root->right,v,low,high);
    // }
    // TreeNode* successor(TreeNode* root){
    //     root=root->right;
    //     while(root!=NULL && root->left!=NULL){
    //         root=root->left;
    //     }
    //     return root;
    // }
    // TreeNode* deleteNode(TreeNode* root, int key) {
    //     if(root==NULL) return NULL;
    //     if(root->val>key)
    //         root->left=deleteNode(root->left,key);
    //     else if(root->val<key)
    //         root->right=deleteNode(root->right,key);
    //     else{
    //         if(root->left==NULL){
    //             TreeNode* temp=root->right;
    //             // delete(root);
    //             return temp;
    //         }
    //         else if(root->right==NULL){
    //             TreeNode* temp=root->left;
    //             // delete(root);
    //             return temp;
    //         }
    //         else{
    //             TreeNode* temp=successor(root);
    //             root->val=temp->val;
    //             root->right=deleteNode(root->right,temp->val);
    //         }
    //     }
    //     return root;
    // }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // vector<int> v;
        // dfs(root,v,low,high);
        // for(int i=0;i<v.size();i++){
        //     root=deleteNode(root,v[i]);
        // }
        // return root;
        if(root==NULL) return NULL;
        if(root->val>=low && root->val<=high){
            root->left=trimBST(root->left,low,high);
            root->right=trimBST(root->right,low,high);
            return root;
        }
        if(root->val>high)
            return trimBST(root->left,low,high);
        return trimBST(root->right,low,high);
    }
};