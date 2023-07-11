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
    map<Node*,Node*> m;
    Node* recur(Node* n){
        Node* newnode=new Node(n->val);
        vector<Node*> newneighbours;
        m[n]=newnode;
        for(auto i:n->neighbors){
            Node* temp;
            if(m.count(i)) temp=m[i];
            else temp=recur(i);
            newneighbours.push_back(temp);
        }
        newnode->neighbors=newneighbours;
        return newnode;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        Node* ans=recur(node);
        return ans;
    }
};