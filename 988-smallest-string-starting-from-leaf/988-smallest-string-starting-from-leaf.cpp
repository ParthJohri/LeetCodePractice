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
    string smallStrings(TreeNode* root, vector<string> &s, string str){
        if(root==NULL) return "";
        str+=root->val+'a';
        if(leaf(root)){
            reverse(str.begin(),str.end());
            s.push_back(str);
        }
        return str+smallStrings(root->left,s,str)+smallStrings(root->right,s,str);
    }
    string smallestFromLeaf(TreeNode* root) {
        vector<string> s;
        if(root==NULL) return "";
        smallStrings(root,s,"");
        string ans=s[0];
        for(auto i:s){
            if(i.compare(ans)<0){
                ans=i;
            }
        }
        return ans;
    }
};