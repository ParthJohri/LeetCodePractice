class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long mx=0,mn=0,temp=k-1,t=k-1;
        priority_queue<int> p;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<weights.size()-1;i++){
            p.push(weights[i]+weights[i+1]);
            q.push(weights[i]+weights[i+1]);
        }
        while(temp--){
            mx+=p.top();
            p.pop();
        }
        while(t--){
            mn+=q.top();
            q.pop();
        }
        return mx-mn;
    }
};