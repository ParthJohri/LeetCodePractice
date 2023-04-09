class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<int> adj[numCourses];
        for(auto i:prerequisites){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        int count=0;
        while(!q.empty()){
            int val=q.front();
            q.pop();
            for(auto i:adj[val]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
            count++;
        }
        return count==numCourses;
    }
};