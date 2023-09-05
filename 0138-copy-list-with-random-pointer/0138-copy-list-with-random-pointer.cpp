/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp=head,*curr;
        if(head==NULL) return NULL;
        curr=new Node(head->val);
        curr->random=head->random;

        map<Node*,Node*> old_new;
        
        Node* h=curr;
        old_new[head]=curr;
        old_new[NULL]=NULL;
        temp=head->next;
        while(temp!=NULL){
            Node* ntemp=new Node(temp->val);
            ntemp->random=temp->random;
            old_new[temp]=ntemp;
            h->next=ntemp;
            h=h->next;
            temp=temp->next;
        }
        
        Node* t=curr,*s=head;
        while(s!=NULL){      
            t->random=old_new[s->random];
            s=s->next;
            t=t->next;
        }
        return curr;
    }
};