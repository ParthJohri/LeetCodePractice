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
    int dfs(Node* root){
        if(root==NULL) return 0;
        int depth=0;
        for(auto i:root->children){
           depth=max(depth,dfs(i));
        }
        return 1+depth;
    }
    int maxDepth(Node* root) {
        return dfs(root);
    }
};