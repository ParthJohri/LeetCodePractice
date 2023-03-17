class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        priority_queue<int,vector<int>,greater<int>> p,q,pq;
        for(int i=0;i<candidates;i++){
            p.push(costs[i]);
        }
        int j=costs.size()-1, i=candidates;;
        for(int i=0;i<candidates;i++){
            q.push(costs[j--]);
        }
        if(costs.size()<2*candidates){
            sort(costs.begin(),costs.end());
            int x=0;
            while(k--){
                ans+=costs[x++];
            }
            return ans;
        }
        while(k and i<=j){
            int sz=p.size(),s=q.size();
            if(p.top()>q.top()){
                ans+=q.top();
                q.pop();
                q.push(costs[j--]);
            }
            else{
                ans+=p.top();
                p.pop();
                p.push(costs[i++]);
            }
            k--;
        }
        // 1 2 3 4 5 6
        // k = 3
        // c = 6 
        while(!p.empty()){
            pq.push(p.top());
            p.pop();
        }
        while(!q.empty()){
            pq.push(q.top());
            q.pop();
        }
        while(k--){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};