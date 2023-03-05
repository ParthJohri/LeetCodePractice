class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return 0;
        vector<int> adj[n+1];
        unordered_map<int,vector<int>> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        int ans=0;
        queue<int> q;
        q.push(0);
        bool visit[n+10];
        visit[0]=true;
        memset(visit,false,sizeof visit);
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                int index=q.front();
                q.pop();
                if(index==n-1) return ans;
                if(index<n-1 and !visit[index+1]){
                    visit[index+1]=true;
                    q.push(index+1);
                }
                if(index>=1 and !visit[index-1]){
                    visit[index-1]=true;
                    q.push(index-1);
                }
                for(auto j:m[arr[index]]){
                    if(j!=index and !visit[j]){
                        visit[j]=true;
                        q.push(j);
                    }
                }
                m[arr[index]].clear();
            }
            ans++;
        }
        return -1;
    }
};