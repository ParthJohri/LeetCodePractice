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
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int l=dfs(root->left);
        int r=dfs(root->right);
        return 1+max(l,r);
    }
    vector<TreeNode*> bfs(TreeNode* root){
        int level=dfs(root);
        cout<<level<<endl;
        queue<TreeNode*> q;
        vector<TreeNode*> ans;
        q.push(root);
        level-=1;
        while(!q.empty() and level){
            if(level==0) break;
            int sz=q.size();
            while(sz--){
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            level--;
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    } 
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL or root==p or root==q) return root;
        auto left=lowestCommonAncestor(root->left,p,q);
        auto right=lowestCommonAncestor(root->right,p,q);
        if(left==NULL) return right;
        else if(right==NULL) return left;
        else return root;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        vector<TreeNode*> node=bfs(root);
        TreeNode* ans=node[0];
        for(int i=1;i<node.size();i++){
            ans=lowestCommonAncestor(root,ans,node[i]);
        }
        return ans;
    }
};