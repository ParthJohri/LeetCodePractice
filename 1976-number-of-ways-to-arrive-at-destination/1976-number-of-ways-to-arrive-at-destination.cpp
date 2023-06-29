#define pii pair<long long,long long> 
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pii> adj[n];
        for(auto i:roads){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        
        long long mod=1e9+7;
        vector<long long> ways(n,0);
        ways[0]=1;// 1 way to reach 0 node
        
        vector<long long> time(n,LLONG_MAX);
        priority_queue<pii,vector<pii>,greater<pii>>q;
        q.push({0,0});
        time[0]=0;
        
        while(!q.empty()){
            auto curr=q.top().second;
            auto timeTaken=q.top().first;
            q.pop();
            for(auto near:adj[curr]){
                long long node=near.first;
                long long tim=near.second;
                if(time[node]==tim+timeTaken){
                    ways[node]=(ways[curr]%mod+ways[node]%mod)%mod;
                }
                if(time[node]>tim+timeTaken){
                    time[node]=tim+timeTaken;
                    ways[node]=ways[curr]%mod;
                    q.push({time[node],node});
                }
            }
        }
        
        return ways[n-1];
    }
};