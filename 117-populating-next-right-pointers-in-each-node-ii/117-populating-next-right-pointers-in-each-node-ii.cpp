/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
        Node* temp=root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr=NULL;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                Node* temp=q.front();
                q.pop();
                temp->next=curr;
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
                curr=temp;
            }
        }
        return root;
    }
};