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
    int dfs(int node, vector<int>*adj,int* visit){
        visit[node]=1;
        int ans=0;
        for(auto i:adj[node]){
            if(visit[i]!=1){
                ans=max(ans,1+dfs(i,adj,visit));
            }
        }
        return ans;
    }
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> adj[100005];
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                TreeNode* t=q.front();
                q.pop();
                vector<int> edges;
                if(t->left) {
                    edges.push_back(t->left->val);
                    adj[t->left->val].push_back(t->val);
                    adj[t->val].push_back(t->left->val);
                    q.push(t->left);
                }
                if(t->right) {
                    edges.push_back(t->right->val);
                    adj[t->right->val].push_back(t->val);
                    adj[t->val].push_back(t->right->val);
                    q.push(t->right);
                }
            } 
        }
        for(int i=0;i<=242;i++){
            for(auto j:adj[i]){
                cout<<i<<"->"<<j<<endl;
            }
        }
        int visit[100005]={0},ans=0;
        visit[start]=1;
        ans=dfs(start,adj,visit);
        return ans;
    }
};