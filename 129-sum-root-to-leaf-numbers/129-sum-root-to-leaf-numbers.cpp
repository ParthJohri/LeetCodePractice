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
    bool leaf(TreeNode* root){
        return root->left==NULL && root->right==NULL;
    }
    string sum(TreeNode* root,vector<string> &s,string str){
        if(root==NULL) return "";
        str+=to_string(root->val);
        if(leaf(root)){
            s.push_back(str);
        }
        return str+sum(root->left,s,str)+sum(root->right,s,str);
    }
    int sumNumbers(TreeNode* root) {
        vector<string> s;
        int ans=0;
        if(root==NULL) return ans;
        sum(root,s,"");
        for(auto i:s){
            ans+=stoi(i);
        }
        return ans;
    }
};