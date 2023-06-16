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

    public:
    Node* root;
    
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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans(queries.size(),-1);
        Trie t;
        vector<pair<int,pair<int,int>>> q;
        sort(nums.begin(),nums.end());
        for(int i=0;i<queries.size();i++) {
            q.push_back({
                queries[i][1],{
                    queries[i][0],i
                }
            });
        }
        int j=0;
        sort(q.begin(),q.end());
        for(auto it:q){
            int x=it.second.first,n=it.first,index=it.second.second;
            while(j<nums.size() and nums[j]<=n){
                t.insert(nums[j]);
                j++;
            }
            if(j!=0)
            ans[index]=t.getMax(x);
        }
        return ans;
    }
};