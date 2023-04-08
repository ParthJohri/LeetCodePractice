/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* dfs(Node* node,map<Node*,Node*>&clone){
        Node* newClone=new Node(node->val);
        clone[node]=newClone;
        vector<Node*> temp; 
        for(auto i:node->neighbors){
            Node* tmp;
            if(clone.count(i)) tmp=clone[i];
            else tmp=dfs(i,clone);
            temp.push_back(tmp);
        }
        newClone->neighbors=temp;
        return newClone;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* ans=new Node(node->val);
        map<Node*,Node*> clone;
        clone[node]=ans;
        ans=dfs(node,clone);
        return ans;
    }
};