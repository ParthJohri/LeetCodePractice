class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<pair<int,int>> adj[n];
        int ans=0,minimum_cities=INT_MAX;
        for(auto i:edges){
            adj[i[0]].push_back({i[2],i[1]});
            adj[i[1]].push_back({i[2],i[0]});
        }
        for(int i=0;i<n;i++){
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
            vector<long long int> dist(n,INT_MAX);
            p.push({0,i});  
            dist[i]=0;
            while(!p.empty()){
                auto [u_cost,u_node]=p.top();p.pop();
                if(u_cost>dist[u_node]) continue;
                for(auto [v_cost,v_node]:adj[u_node]){
                    if(dist[v_node]>dist[u_node]+v_cost){
                        dist[v_node]=dist[u_node]+v_cost;
                        p.push({dist[v_node],v_node});
                    }
                }
            }
            int count=0;
            for(auto i:dist){
                if(i<=distanceThreshold){
                    ++count;
                }
            }
            if(minimum_cities>=count){
                minimum_cities=count;
                ans=i;
            }
        }
        return ans;
    }
};