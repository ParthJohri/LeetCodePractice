class Solution {
public:
    int dfs(vector<int> *arr,vector<bool> visit,int curr,vector<bool>&m){
        int fans=0,t=0;
        visit[curr]=true;
        for(auto i:arr[curr]){
            if(!visit[i]){
                t=dfs(arr,visit,i,m);
                if(t>0 or m[i]){
                    fans+=t+2;
                }   
            }
        }
        return fans;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<int> arr[n];
        vector<bool> visit(n,false);
        for(auto i:edges){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        return dfs(arr,visit,0,hasApple);
    }
};