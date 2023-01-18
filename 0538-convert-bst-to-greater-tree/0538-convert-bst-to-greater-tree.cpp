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
    void inorder(TreeNode* root,int& sum,vector<int>& nums){
        if(root==NULL) return;
        inorder(root->left,sum,nums);
        sum+=root->val;
        nums.push_back(root->val);
        inorder(root->right,sum,nums);
    }
    void inorder(TreeNode* root,map<int,int>&m){
        if(root==NULL) return;
        inorder(root->left,m);
        root->val=m[root->val];
        inorder(root->right,m);
    }
    TreeNode* convertBST(TreeNode* root) {
        vector<int> nums;
        int sum=0;
        inorder(root,sum,nums);
        int prevsum=0;
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]=sum-prevsum;
            prevsum+=nums[i];
        }
        inorder(root,m);
        return root;
    }
};