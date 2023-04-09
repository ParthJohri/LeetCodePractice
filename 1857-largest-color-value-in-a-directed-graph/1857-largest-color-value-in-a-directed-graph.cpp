class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<int> indegree(n,0);
        vector<int> adj[n];
        int mx=INT_MIN;
        for(auto i:edges){
            indegree[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
            vector<vector<int>> colorsDP(n,vector<int>(28,0));
        while(!q.empty()){
            int val=q.front();
            colorsDP[val][colors[val]-'a']++;
            q.pop();
            for(auto i:adj[val]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
                for(int j=0;j<26;j++){
                    colorsDP[i][j]=max(colorsDP[i][j],colorsDP[val][j]);}
            }
            count++;
        }
        cout<<count<<endl;
        if(count!=n) return -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                mx=max(mx,colorsDP[i][j]);
            }
        }
        return mx;
    }
};