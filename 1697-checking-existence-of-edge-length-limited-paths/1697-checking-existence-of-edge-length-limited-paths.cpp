class Solution {
public:
    int parent[100005],size[100005];

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
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<bool> ans(queries.size(),false);
        for(int i=0;i<=n;i++){
            make(i);
        }
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(edgeList.begin(),edgeList.end(),[&](vector<int>&a,vector<int>&b){
            return a.back()<=b.back();
        });
        sort(queries.begin(),queries.end(),[&](vector<int>&a,vector<int>&b){
           return a[2]<=b[2]; 
        });
        int i=0;
        for(auto& q:queries){
            while(i<edgeList.size() and edgeList[i][2]<q[2]){
                Union(edgeList[i][0],edgeList[i][1]);
                i++;
            }
            ans[q.back()]=find(q[0])==find(q[1]);
        }
        return ans;
    }
};