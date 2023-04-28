class Solution {
public:
    int parent[100000],size[100000];

    void make(int v){
        parent[v]=v;
        size[v]=1;
    }

    int find(int v){
        if(parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }

    void Union(int a,int b){
        a=find(parent[a]);
        b=find(parent[b]);
        if(a!=b){
            if(size[a]<size[b]){
            swap(a,b);
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }
    void dfs(int i,vector<string>&strs,vector<bool>&vis){
        vis[i]=true;
        for(int j=0;j<strs.size();j++){
            if(vis[j]) continue;
            if(anagram(strs[i],strs[j]))
                dfs(j,strs,vis);
        }
    }
    bool anagram(string&s, string&t){
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=t[i]) ++count;
        }
        return count==2 or count==0;
    }
    int numSimilarGroups(vector<string>& strs) {
        int groups=0,n=strs.size(),ans=0;
        vector<bool> vis(strs.size(),false);
        for(int i=0;i<strs.size();i++){
            if(vis[i]) continue;
            dfs(i,strs,vis);
            groups++;
        }
        for(int i=1;i<=n;i++){
            make(i);
        }
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                if(anagram(strs[i],strs[j]))
                    Union(i+1,j+1);
            }
        }
        for(int i=1;i<=n;i++){
            if(parent[i]==i) ans++;
        }
        return ans;
    }
};