class Solution {
public:
    int dfs(int curr,vector<int>*arr,vector<bool>&v,string &s,int& ans){
        v[curr]=false;
        int mx=0,smx=0;
        for(auto node:arr[curr]){
            if(!v[node]){
                int temp=dfs(node,arr,v,s,ans);
                if(s[node]==s[curr]) continue;
                if(temp>mx){
                    smx=mx;
                    mx=temp;
                }
                else
                    smx=max(smx,temp);
            }
        }
        ans=max(ans,mx+smx+1);
        return mx+1;
    }
    int longestPath(vector<int>& parent, string s) {
        vector<int> arr[parent.size()];
        vector<bool> v(parent.size(),false);
        for(int i=1;i<parent.size();i++){
            arr[parent[i]].push_back(i);
            // arr[i].push_back(parent[i]);
        }
        int ans=1;
        dfs(0,arr,v,s,ans);
        return ans;
    }
};