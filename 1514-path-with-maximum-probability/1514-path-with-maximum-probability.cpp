class Solution {
public:
    unordered_map<int,double> m;
    unordered_map<int,bool> b;
    double recur(vector<pair<double,double>>*adj,int s,int e){
        if(e==s) return 1.0;
        if(m.count(s)>0) m[s];
        b[s]=true;
        double val=1.0,mxval=0.0;
        for(auto n:adj[s]){
            if(!b[n.first]){
            val=n.second*recur(adj,n.first,e);
            mxval=max(mxval,val);
            }
        }
        b[s]=false;
        return m[s]=mxval;
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n+1];
        int index=0;
        for(auto i:edges){
            adj[i[0]].push_back({i[1],succProb[index]});
            adj[i[1]].push_back({i[0],succProb[index]});
            index++; 
        }
        vector<double> dist(n+1,0.0);
        dist[start]=1.0;
        queue<int> q;
        q.push(start);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr]){
                double node=it.first;
                double prob=it.second;
                if(prob*dist[curr]>dist[node]){
                    dist[node]=dist[curr]*prob;
                    q.push(node);
                }
            }
        }
        return dist[end];
    }
};