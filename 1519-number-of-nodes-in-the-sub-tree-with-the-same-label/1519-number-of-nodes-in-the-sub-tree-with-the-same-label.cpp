class Solution {
public:
    vector<int> dfs(int curr,vector<int> *arr,vector<int>& ans,vector<bool>&v,string &labels){
        v[curr]=true;
        vector<int> map(26,0);
        map[labels[curr]-'a']++;
        for(auto node:arr[curr]){
            if(!v[node]){
                vector<int> temp=dfs(node,arr,ans,v,labels);
                for(int i=0;i<26;i++){
                    map[i]+=temp[i];
                }
            }
        }
        ans[curr]=map[labels[curr]-'a'];
        return map;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> arr[n];
        vector<int> ans(n,1);
        vector<bool> v(n,false);
        for(auto i:edges){
            arr[i[0]].push_back(i[1]);
            arr[i[1]].push_back(i[0]);
        }
        dfs(0,arr,ans,v,labels);
        return ans;
    }
};