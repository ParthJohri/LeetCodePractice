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
    vector<int> ans;
    vector<int> porder(Node* root){
        if(root==NULL) return ans;
        vector<Node*> child=root->children;
        for(int i=0;i<child.size();i++){
            Node* temp=child[i];
            porder(temp);
            ans.push_back(temp->val);
        }
        return ans;
    }
    vector<int> postorder(Node* root) {
       porder(root);
       if(root!=NULL)
       ans.push_back(root->val);
       return ans;
    }
};