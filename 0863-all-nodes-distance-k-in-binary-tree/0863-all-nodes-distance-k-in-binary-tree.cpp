/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
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
        int visit[100005]={0};
        queue<int> p;
        int dist=0;
        p.push(target->val);
        vector<int> ans;
        visit[target->val]=1;
        while(!p.empty()){
            int sz=p.size();
            dist++;
            while(sz--){
                int val=p.front();
                p.pop();
                for(auto i:adj[val]){
                    if(visit[i]!=1){
                        visit[i]=1;
                        p.push(i);
                    }   
                }
            }
            if(dist==k) break;
        }
        while(!p.empty()){
            ans.push_back(p.front());
            p.pop();
        }
        if(k==0) ans.push_back(target->val);
        return ans;
    }
};