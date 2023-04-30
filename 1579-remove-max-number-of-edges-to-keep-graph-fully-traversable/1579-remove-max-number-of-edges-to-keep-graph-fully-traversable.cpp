struct dsu{
    vector<int> parent,size;
    
    dsu(int n){
        parent=vector<int>(n);
        size=vector<int>(n,1);
        for(int i=0;i<n;i++){
            make(i);
        }
    }
    
    void make(int v){
        parent[v]=v;
        size[v]=1;
    }   

    int find(int v){
        if(parent[v]==v) return v;
        return parent[v]=find(parent[v]);
    }

    bool Union(int a,int b){
        a=find(parent[a]);
        b=find(parent[b]);
        if(a==b) return false;
        if(a!=b){
            if(size[a]<size[b]){
            swap(a,b);
            }
            parent[b]=a;
            size[a]+=size[b];
        }
        return true;
    }
    int count(int node){
        return size[find(node)];
    }
};
class Solution {
public:

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int count=0;
        dsu a(n+1);
        dsu b(n+1);
        sort(edges.begin(),edges.end(),[](vector<int>&a,vector<int>&b){
            return a[0]>b[0];
        });
        for(auto i:edges){
            int type=i[0],u=i[1]-1,v=i[2]-1;
            switch(type){
                case 3: 
                    count+=a.Union(u,v);
                    b.Union(u,v);
                    break;
                case 2:
                    count+=b.Union(u,v);
                    break;
                case 1:
                    count+=a.Union(u,v);
                    break;
            }
        }
        if(b.count(b.find(0))<n or a.count(a.find(0))<n) return -1;
        return (int)edges.size()-count;
    }
};