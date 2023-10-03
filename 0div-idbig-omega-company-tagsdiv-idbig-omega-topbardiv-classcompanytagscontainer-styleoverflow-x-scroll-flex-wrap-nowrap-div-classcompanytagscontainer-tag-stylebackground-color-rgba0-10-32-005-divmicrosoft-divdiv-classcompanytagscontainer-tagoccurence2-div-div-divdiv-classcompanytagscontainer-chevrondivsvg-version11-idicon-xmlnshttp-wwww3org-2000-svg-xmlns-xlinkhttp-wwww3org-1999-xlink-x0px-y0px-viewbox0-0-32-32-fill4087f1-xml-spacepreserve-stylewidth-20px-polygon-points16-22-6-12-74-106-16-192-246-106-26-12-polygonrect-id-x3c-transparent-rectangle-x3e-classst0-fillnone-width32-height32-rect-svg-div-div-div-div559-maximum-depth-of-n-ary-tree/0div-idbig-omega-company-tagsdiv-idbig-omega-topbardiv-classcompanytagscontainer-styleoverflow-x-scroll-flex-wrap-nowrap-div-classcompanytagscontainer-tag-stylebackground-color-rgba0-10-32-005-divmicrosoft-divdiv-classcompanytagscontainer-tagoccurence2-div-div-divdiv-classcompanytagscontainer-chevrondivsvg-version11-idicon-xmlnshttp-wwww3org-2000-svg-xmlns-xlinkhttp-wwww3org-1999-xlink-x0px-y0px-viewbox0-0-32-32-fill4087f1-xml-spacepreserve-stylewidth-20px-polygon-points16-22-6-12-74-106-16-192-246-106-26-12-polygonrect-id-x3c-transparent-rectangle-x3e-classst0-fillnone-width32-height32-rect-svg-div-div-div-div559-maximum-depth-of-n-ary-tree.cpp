/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans=0;
    int dfs(Node*root){
        int dist=0;
        if(root==NULL) return 0;
        for(auto j:root->children){
            dist=max(dist,dfs(j)+1);
        }
        ans=max(ans,dist);
        return dist;
    }
    int maxDepth(Node* root) {
        dfs(root);
        if(root==NULL) return 0;
        return ans+1;
    }
};