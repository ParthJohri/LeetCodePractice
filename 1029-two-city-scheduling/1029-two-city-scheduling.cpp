class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        priority_queue<pair<int,int>> p;
        int ans=0,n=costs.size()/2;
        for(int i=0;i<costs.size();i++){
            ans+=costs[i][0];
            p.push({costs[i][0]-costs[i][1],i});
        }
        while(n!=0){
            ans+=costs[p.top().second][1];
            ans-=costs[p.top().second][0];
            p.pop();
            n--;
        }
        return ans;
    }
};