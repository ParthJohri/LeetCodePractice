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
    map<int,int> m;
    TreeNode* build(vector<int>&postorder,int instart, int inend,int& index){
        if(instart>inend) return NULL;
        TreeNode* temp=new TreeNode(postorder[index]);
        int lb=m[postorder[index]];
        index++;
        temp->right=build(postorder,lb+1,inend,index);
        temp->left=build(postorder,instart,lb-1,index);
        return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]]=i;
        }
        reverse(postorder.begin(),postorder.end());
        int index=0;
        return build(postorder,0,inorder.size()-1,index);
    }
};