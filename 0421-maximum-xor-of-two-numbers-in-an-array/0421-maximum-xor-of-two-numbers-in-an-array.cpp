struct Node{
    Node* links[2];
    bool containsKey(int bit){
        return (links[bit]!=NULL);
    }
    void put(int bit,Node* node){
        links[bit]=node;
    }
    Node* get(int bit){
        return links[bit];
    }
};
class Trie{
    private: 
    Node* root;
    public:
    Trie(){
        root=new Node();
    }
    void insert(int n){
        Node* node=root;
        for(int i=31;i>=0;i--){
            int bit=((n>>i)&1);
            if(!node->containsKey(bit)){
                node->put(bit,new Node());
            }
            node=node->get(bit);
        }
    }
    int getMax(int n){
        Node* node=root;
        int maxSum=0;
        for(int i=31;i>=0;i--){
            int bit=((n>>i)&1);
            if (node->containsKey(!bit)) {
                maxSum|=(1<<i);
                node=node->get(!bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxSum;
    }
};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int ans=0;
        for(auto i:nums) t.insert(i);
        for(auto i:nums){
            ans=max(ans,t.getMax(i));
        }
        return ans;
    }
};