class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& edges, int src, int dst, int k) {
        vector<int> d(n,INT_MAX);
        d[src]=0;
        while(k-->=0){
            vector<int> temp(n);
            copy(d.begin(),d.end(),temp.begin());
            for(auto i:edges){
                if(d[i[0]]==INT_MAX) continue;
                if(temp[i[1]]>d[i[0]]+i[2])
                    temp[i[1]]=d[i[0]]+i[2];
            }
            copy(temp.begin(),temp.end(),d.begin());
        }
        if(d[dst]==INT_MAX) return -1;
        return d[dst];
    }
};