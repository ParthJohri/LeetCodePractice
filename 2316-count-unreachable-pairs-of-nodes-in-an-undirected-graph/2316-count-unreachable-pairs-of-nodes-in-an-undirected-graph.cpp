class Solution {
public:
    static const int N=1000010;
    int parent[N],size[N];
    
    void make(int v){
        parent[v]=v;
        size[v]=1;
    }
    int find(int v){
        if(parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }
    void Union(int a,int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            if(size[a]<size[b]) swap(a,b);
            parent[b]=a;
            size[a]+=size[b];
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        if(edges.size()==0) return (n*1ll*(n-1)/2);
        for(int i=0;i<n;i++){
            make(i);
        }
        for(auto i:edges){
            int a=i[0],b=i[1];
            Union(a,b);
        }
        vector<int> d,c;
        for(int i=0;i<n;i++){
            if(parent[i]==i) d.push_back(i);
        }
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[find(i)]++;
        }
        for(auto i:m){
            c.push_back(i.second);
        }
        vector<int> su(c.size(),0);
        su[c.size()-1]=c[c.size()-1];
        for(int i=c.size()-2;i>=0;i--){
            su[i]+=su[i+1]+c[i];
        }        
        long long ans=0;
        for(int i=0;i<c.size()-1;i++){
            ans+=c[i]*1ll*su[i+1];
        }
        return ans;
    }
};