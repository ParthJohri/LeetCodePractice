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
    vector<string> v;
    string trav(TreeNode* root,string s)
    {
        if(root->left!=NULL||root->right!=NULL)
        {
            s+=to_string(root->val);
            if(root->left!=NULL)
            trav(root->left,s);
            if(root->right!=NULL)
            trav(root->right,s);
        }
        else
        {
            s+=to_string(root->val);
            v.push_back(s);
        }
        s="";
        return "";
    }
    int val(string &s,int l)
    {
        int v=0,x=0;
        for(auto i:s)
        {
            v+=(i-'0')*(int)pow(2,--l);
        }
        return v;
    }
    int sumRootToLeaf(TreeNode* root) {
        string s="";
        trav(root, s);
        int sum=0;
        for(auto i:v)
            sum+=val(i,i.length());
        return sum;
    }
};