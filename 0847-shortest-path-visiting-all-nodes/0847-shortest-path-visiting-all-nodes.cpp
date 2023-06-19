
class Solution {
public:
    class tuple{
      public:
        int node,mask,dist;
        tuple(int node,int mask,int dist){
            this->node=node;
            this->mask=mask;
            this->dist=dist;
        }
    };
    int shortestPathLength(vector<vector<int>>& graph) {
        int n=graph.size(),allVisitMask=(1<<n)-1;
        set<pair<int,int>> visited;
        queue<tuple>q;
        for(int i=0;i<n;i++){
            tuple t(i,(1<<i),1);
            q.push(t);
            visited.insert({i,(1<<i)});
        }
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            if(curr.mask==allVisitMask) return curr.dist-1;
            for(auto node:graph[curr.node]){
                auto newMaskValue=curr.mask|(1<<node);
                tuple t(node,newMaskValue,curr.dist+1);
                if(visited.find({node,newMaskValue})==visited.end()){
                    q.push(t);
                    visited.insert({node,newMaskValue});
                }
            }
        }
        return -1;
    }
};