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
    int lc=0,rc=0;
    int recur(TreeNode* root,int x){
        if(root==NULL) return 0;
        int count=1;
        int l=recur(root->left,x);
        int r=recur(root->right,x);
        count+=l+r;
        if(root->val==x) {
            lc=l;
            rc=r;
        }
        return count;
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        recur(root,x);
        cout<<lc<<" "<<rc<<endl;
        if(lc+rc+1<=n/2 or lc>n/2 or rc>n/2) return true;
        return false;
    }
};