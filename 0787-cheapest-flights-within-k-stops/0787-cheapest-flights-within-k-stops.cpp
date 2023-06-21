#define pii pair<int,pair<int,int>>
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int m=flights.size();
        vector<vector<int>> grid[n];
        for(int i=0;i<m;i++){
            grid[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dist(n+1,INT_MAX);
        dist[src]=0;
        queue<pii>p;
        p.push({0,{src,0}});
        while(!p.empty()){
            int stops=p.front().first;
            int node=p.front().second.first;
            int dis=p.front().second.second;
            p.pop();
            if(stops>K) break;
            for(auto adjnode:grid[node]){
                int nod=adjnode[0];
                int weight=adjnode[1];
                if(stops<=K and dis+weight<dist[nod]){
                    dist[nod]=dis+weight;
                    p.push({stops+1,{nod,dist[nod]}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};