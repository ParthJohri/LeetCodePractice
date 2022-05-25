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
    void inorder(TreeNode* root1,vector<int> &v1)
    {
        if(root1!=NULL)
        {
            inorder(root1->left,v1);
            if(root1->left==NULL&&root1->right==NULL)
                v1.push_back(root1->val);
            inorder(root1->right,v1);
        }
        return ;
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> v,v2;
        inorder(root1,v);
        inorder(root2,v2);
        if(v.size()==v2.size())
        {
            for(int i=0;i<v.size();i++)
            {
                if(v[i]!=v2[i])
                    return false;
            }
        }
        else
            return false;
        return true;
    }
};