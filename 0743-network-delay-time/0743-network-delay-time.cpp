class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
        vector<int> dist(n+1,INT_MAX);
        vector<bool> vis(n+1,false);
        p.push({0,k});
        dist[k]=0;
        int ans=0;
        while(!p.empty()){
            pair<int,int> pr=p.top();
            p.pop();
            int u=pr.second;
            for(auto i=adj[u].begin();i!=adj[u].end();i++){
                int v=(*i).first;
                int weight=(*i).second;
                if(dist[v]>dist[u]+weight){
                    dist[v]=dist[u]+weight;
                    p.push({dist[v],v});
                }
            }
        }
        ans=*max_element(dist.begin()+1,dist.end());
        if(ans==INT_MAX) return -1;
        return ans;
    }
};