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
    void inorder(TreeNode* root,vector<int> &v)
    {
        
        if(root==NULL)
            return ;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        if(root==NULL) return NULL; 
        TreeNode* head=new TreeNode(ans[0]);
        TreeNode* curr=head;
        for(int i=1;i<ans.size();i++)
        {
            TreeNode* temp=new TreeNode(ans[i]);
            curr->right=temp;
            curr=curr->right;
        }
        return head;
    }
};